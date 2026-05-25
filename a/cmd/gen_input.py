#!/usr/bin/env python3
from __future__ import annotations

import argparse
import hashlib
import json
import os
import shlex
from pathlib import Path
from typing import Any

# 这个脚本从 compile_commands.json 生成一个 projects.in.jsonl 记录，供 Stage A 使用。
CANONICAL_ANALYSIS_BACKEND = "llvm_api_dfa"
DEFAULT_ANALYZER_JOBS = 2
DEFAULT_ANALYSIS_TIMEOUT = 1800
SUPPORTED_SOURCE_SUFFIXES = {".c", ".cc", ".cpp", ".cxx"}
KNOWN_COMPILER_NAMES = {
    "cc",
    "gcc",
    "clang",
    "c++",
    "g++",
    "clang++",
}
COMPILER_WRAPPER_NAMES = {
    "ccache",
    "sccache",
    "distcc",
}


def parse_args() -> argparse.Namespace:
    # 解析命令行参数
    parser = argparse.ArgumentParser(
        description="Generate a Stage A projects.in.jsonl record from compile_commands.json"
    )
    parser.add_argument("--repo-path", default="srcs", help="source repository root")
    parser.add_argument(
        "--compile-commands",
        default="",
        help="compile_commands.json path; defaults to <repo-path>/compile_commands.json",
    )
    parser.add_argument("--output", default="a/input/srcs.in.jsonl", help="output projects.in.jsonl path")
    parser.add_argument("--project-id", default="", help="project_id; defaults to repo directory name")
    parser.add_argument("--language", default="c", help="Stage A language field: c/cpp")
    parser.add_argument("--framework", default="generic", help="Stage A framework field")
    parser.add_argument("--default-branch", default="", help="Stage A default_branch field")
    parser.add_argument("--analyzer-jobs", type=int, default=DEFAULT_ANALYZER_JOBS)
    parser.add_argument("--analysis-timeout", type=int, default=DEFAULT_ANALYSIS_TIMEOUT)
    parser.add_argument("--clang", default="clang", help="C compiler used for bitcode generation")
    parser.add_argument("--clangxx", default="clang++", help="C++ compiler used for bitcode generation")
    parser.add_argument(
        "--bc-dir",
        default="",
        help="bitcode output directory under repo root; defaults to bc.<project_id>",
    )
    parser.add_argument(
        "--source-glob",
        action="append",
        default=[],
        help="source_globs entry; can be repeated; defaults from compile_commands source suffixes",
    )
    parser.add_argument(
        "--force",
        action="store_true",
        help="overwrite output file if it already exists",
    )
    return parser.parse_args()

def resolve_path(raw: str) -> Path:
    return Path(raw).expanduser().resolve()

def relative_or_absolute(path: Path, base_dir: Path) -> str:
    try:
        return path.relative_to(base_dir).as_posix()
    except ValueError:
        return shell_path(path)


def shell_path(path: Path | str) -> str:
    return str(path).replace("\\", "/")


def shell_quote(value: Path | str) -> str:
    return shlex.quote(shell_path(value))


def unquote_compile_token(token: str) -> str:
    if len(token) >= 2 and token[0] == token[-1] and token[0] in {"'", '"'}:
        return token[1:-1]
    return token


def output_path_for_source(repo_path: Path, source_path: Path, bc_dir: str, variant: str) -> Path:
    try:
        relative = source_path.relative_to(repo_path)
    except ValueError as exc:
        raise ValueError(f"compile command source is outside repo_path: {source_path}") from exc
    output_relative = relative.with_suffix(".bc")
    if variant:
        output_relative = output_relative.with_name(f"{output_relative.stem}.{variant}{output_relative.suffix}")
    return repo_path / bc_dir / output_relative


def load_compile_commands(path: Path) -> list[dict[str, Any]]:
    try:
        payload = json.loads(path.read_text(encoding="utf-8"))
    except FileNotFoundError as exc:
        raise ValueError(f"compile_commands.json not found: {path}") from exc
    except json.JSONDecodeError as exc:
        raise ValueError(f"compile_commands.json is not valid JSON: {path}: {exc}") from exc
    if not isinstance(payload, list):
        raise ValueError("compile_commands.json root must be a list")
    return payload


def command_tokens(record: dict[str, Any], index: int) -> list[str]:
    if "arguments" in record:
        arguments = record["arguments"]
        if not isinstance(arguments, list) or not all(isinstance(item, str) for item in arguments):
            raise ValueError(f"compile command #{index} arguments must be a list of strings")
        return list(arguments)
    command = record.get("command")
    if not isinstance(command, str) or not command.strip():
        raise ValueError(f"compile command #{index} must contain command or arguments")
    return [unquote_compile_token(token) for token in shlex.split(command, posix=(os.name != "nt"))]


def record_directory(record: dict[str, Any], index: int) -> Path:
    raw_directory = record.get("directory")
    if not isinstance(raw_directory, str) or not raw_directory.strip():
        raise ValueError(f"compile command #{index} is missing directory")
    return resolve_path(raw_directory)


def record_source(record: dict[str, Any], directory: Path, index: int) -> Path:
    raw_file = record.get("file")
    if not isinstance(raw_file, str) or not raw_file.strip():
        raise ValueError(f"compile command #{index} is missing file")
    path = Path(raw_file)
    return (path if path.is_absolute() else directory / path).resolve()


def is_source_path(path: Path) -> bool:
    return path.suffix.lower() in SUPPORTED_SOURCE_SUFFIXES


def strip_output_option(tokens: list[str]) -> list[str]:
    result: list[str] = []
    index = 0
    while index < len(tokens):
        token = tokens[index]
        if token == "-o":
            index += 2
            continue
        if token.startswith("-o") and token != "-o":
            index += 1
            continue
        result.append(token)
        index += 1
    return result


def strip_dependency_options(tokens: list[str]) -> list[str]:
    result: list[str] = []
    index = 0
    options_with_value = {
        "-MF",
        "-MT",
        "-MQ",
        "-MJ",
    }
    standalone_options = {
        "-M",
        "-MM",
        "-MD",
        "-MMD",
        "-MP",
        "-MG",
    }
    while index < len(tokens):
        token = tokens[index]
        if token in options_with_value:
            index += 2
            continue
        if any(token.startswith(option) and token != option for option in options_with_value):
            index += 1
            continue
        if token in standalone_options:
            index += 1
            continue
        result.append(token)
        index += 1
    return result


def compiler_name_matches(name: str) -> bool:
    if name in KNOWN_COMPILER_NAMES:
        return True
    return name.endswith("-gcc") or name.endswith("-g++") or name.endswith("-clang") or name.endswith("-clang++")


def compiler_index(tokens: list[str], source_path: Path) -> int:
    for index, token in enumerate(tokens):
        name = Path(token).name
        if name in COMPILER_WRAPPER_NAMES:
            continue
        if compiler_name_matches(name):
            return index
    raise ValueError(f"cannot identify compiler in compile command for {source_path}")


def normalize_compile_tokens(tokens: list[str], source_path: Path, output_path: Path, clang: str, clangxx: str) -> list[str]:
    if not tokens:
        raise ValueError(f"empty compile command for {source_path}")
    compiler = clang if source_path.suffix.lower() == ".c" else clangxx
    index = compiler_index(tokens, source_path)
    rest = strip_output_option(tokens[index + 1 :])
    rest = strip_dependency_options(rest)
    rest = [token for token in rest if token not in {"-c", "-S", "-E"}]
    return [
        compiler,
        "-emit-llvm",
        "-c",
        "-g",
        *rest,
        "-o",
        shell_path(output_path),
    ]


def source_globs_for(sources: list[Path], repo_path: Path, explicit_globs: list[str]) -> list[str]:
    if explicit_globs:
        return [item for item in explicit_globs if item.strip()]
    suffixes = sorted({source.suffix.lower() for source in sources})
    globs: list[str] = []
    if ".c" in suffixes:
        globs.append("**/*.c")
    if any(suffix in suffixes for suffix in (".cc", ".cpp", ".cxx")):
        globs.extend(["**/*.cc", "**/*.cpp", "**/*.cxx"])
    if not globs:
        raise ValueError(f"compile_commands.json contains no supported C/C++ sources under {repo_path}")
    return globs


def build_project_record(
    args: argparse.Namespace,
    repo_path: Path,
    compile_commands_path: Path,
    input_jsonl_path: Path,
) -> dict[str, Any]:
    records = load_compile_commands(compile_commands_path)
    commands: list[str] = []
    seen_shell_commands: set[str] = set()
    sources: list[Path] = []
    source_counts: dict[Path, int] = {}
    input_jsonl_dir = input_jsonl_path.parent
    project_id = args.project_id.strip() or repo_path.name
    if not project_id:
        raise ValueError("project_id is empty")

    bc_dir = (args.bc_dir.strip() or f"bc.{project_id}").strip("/")
    if not bc_dir:
        raise ValueError("--bc-dir must be a non-empty relative directory")
    if Path(bc_dir).is_absolute() or ".." in Path(bc_dir).parts:
        raise ValueError("--bc-dir must stay under repo_path")

    def append_shell_command(command: str) -> None:
        if command in seen_shell_commands:
            return
        seen_shell_commands.add(command)
        commands.append(command)

    append_shell_command(f"mkdir -p {shell_quote(bc_dir)}")
    for index, record in enumerate(records, start=1):
        if not isinstance(record, dict):
            raise ValueError(f"compile command #{index} must be an object")
        directory = record_directory(record, index)
        source_path = record_source(record, directory, index)
        if not is_source_path(source_path):
            continue
        source_count = source_counts.get(source_path, 0)
        source_counts[source_path] = source_count + 1
        variant = ""
        if source_count > 0:
            digest = hashlib.sha1(json.dumps(record, sort_keys=True).encode("utf-8")).hexdigest()[:10]
            variant = f"variant{source_count}-{digest}"
        bitcode_output_path = output_path_for_source(repo_path, source_path, bc_dir, variant)
        relative_output = bitcode_output_path.relative_to(repo_path)
        relative_output_parent = relative_output.parent.as_posix()
        if relative_output_parent:
            append_shell_command(f"mkdir -p {shell_quote(relative_output_parent)}")

        tokens = command_tokens(record, index)
        bitcode_tokens = normalize_compile_tokens(
            tokens,
            source_path,
            bitcode_output_path,
            args.clang,
            args.clangxx,
        )
        bitcode_command = " ".join(shell_quote(token) for token in bitcode_tokens)
        append_shell_command(f"( cd {shell_quote(directory)} && {bitcode_command} )")
        sources.append(source_path)

    if not sources:
        raise ValueError(f"compile_commands.json contains no supported C/C++ sources under {repo_path}")

    return {
        "project_id": project_id,
        "repo_path": relative_or_absolute(repo_path, input_jsonl_dir),
        "language": args.language.strip().lower(),
        "framework": args.framework.strip().lower(),
        "default_branch": args.default_branch,
        "extensions": {
            "analysis_backend": CANONICAL_ANALYSIS_BACKEND,
            "build_cmd": " && ".join(commands),
            "analyzer_jobs": args.analyzer_jobs,
            "analysis_timeout": args.analysis_timeout,
            "bitcode_globs": [f"{bc_dir}/**/*.bc"],
            "source_globs": source_globs_for(sources, repo_path, args.source_glob),
        },
    }


def write_output(path: Path, record: dict[str, Any], force: bool) -> None:
    if path.exists() and not force:
        raise ValueError(f"output already exists: {path}; pass --force to overwrite")
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8") as handle:
        handle.write(json.dumps(record, ensure_ascii=False))
        handle.write("\n")


def main() -> int:
    args = parse_args()
    repo_path = resolve_path(args.repo_path)
    if not repo_path.exists() or not repo_path.is_dir():
        raise ValueError(f"repo_path must be an existing directory: {repo_path}")
    compile_commands_path = (
        resolve_path(args.compile_commands)
        if args.compile_commands
        else repo_path / "compile_commands.json"
    )
    output_path = resolve_path(args.output)
    record = build_project_record(args, repo_path, compile_commands_path, output_path)
    write_output(output_path, record, args.force)
    print(f"wrote Stage A input to {output_path}")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except Exception as exc:
        print(f"gen input failed: {exc}")
        raise SystemExit(1) from exc
