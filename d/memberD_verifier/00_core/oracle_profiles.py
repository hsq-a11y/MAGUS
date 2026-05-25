#!/usr/bin/env python3
"""
Reusable Stage D oracle profiles.

Profiles are selected from hypothesis semantics: APIs, routes, evidence text,
and claim wording. CWE identifiers are optional tie-breakers, not required
inputs.
"""

from __future__ import annotations

import json
import re
from dataclasses import dataclass
from typing import Any, Dict, Iterable, List, Tuple


def as_text(value: Any) -> str:
    if value is None:
        return ""
    if isinstance(value, list):
        return " ".join(as_text(item) for item in value)
    if isinstance(value, dict):
        return " ".join(f"{key} {as_text(item)}" for key, item in value.items())
    return str(value)


def hypothesis_text(hypothesis: Dict[str, Any]) -> str:
    parts = [
        hypothesis.get("route"),
        hypothesis.get("file"),
        hypothesis.get("claim"),
        hypothesis.get("preconditions"),
        hypothesis.get("attack_path"),
        hypothesis.get("api_sequence"),
        hypothesis.get("evidence_slice"),
        hypothesis.get("cwe_candidates") or hypothesis.get("CWE_candidates") or hypothesis.get("cwe_list"),
    ]
    return as_text(parts)


@dataclass(frozen=True)
class OracleProfile:
    profile_id: str
    description: str
    api_markers: Dict[str, Tuple[str, ...]]
    keywords: Tuple[str, ...] = ()
    cwe_tokens: Tuple[str, ...] = ()
    accepted_evidence: Tuple[str, ...] = ()
    generic_markers: Tuple[str, ...] = ()
    semantic_model: Dict[str, Any] | None = None

    @property
    def api_names(self) -> Tuple[str, ...]:
        return tuple(self.api_markers.keys())


LIFECYCLE_FAILURE_REASONS: Tuple[str, ...] = (
    "missing_release",
    "duplicate_release",
    "wrong_release_api",
    "use_after_release",
    "failed_acquire_used",
    "ownership_transfer_lost",
)


def lifecycle_generic_markers(profile_id: str) -> Tuple[str, ...]:
    return tuple(f"MAGUS_ORACLE_FLAW profile={profile_id} reason={reason}" for reason in LIFECYCLE_FAILURE_REASONS)


def lifecycle_api_markers(profile_id: str, api_name: str, reasons: Tuple[str, ...]) -> Tuple[str, ...]:
    markers: List[str] = []
    for reason in reasons:
        markers.append(f"MAGUS_ORACLE_FLAW profile={profile_id} name={api_name} reason={reason}")
        markers.append(f"MAGUS_ORACLE_FLAW name={api_name} reason={reason}")
    return tuple(markers)


def lifecycle_semantic_model(
    *,
    family: str,
    resource_kind: str,
    execution_environment: str,
    acquire: Tuple[str, ...],
    release: Tuple[str, ...],
    sentinel_values: Tuple[str, ...],
    transfer: Tuple[str, ...] = (),
    duplicate: Tuple[str, ...] = (),
    multi_resource_acquire: Dict[str, int] | None = None,
    release_compatibility: Dict[str, Tuple[str, ...]] | None = None,
    execution_contexts: Tuple[str, ...] = (),
) -> Dict[str, Any]:
    model: Dict[str, Any] = {
        "kind": "resource_lifecycle",
        "family": family,
        "resource_kind": resource_kind,
        "execution_environment": execution_environment,
        "state_semantics": {
            "acquire": list(acquire),
            "release": list(release),
            "transfer": list(transfer),
            "duplicate": list(duplicate),
            "sentinel_values": list(sentinel_values),
            "multi_resource_acquire": multi_resource_acquire or {},
            "release_compatibility": {
                key: list(value) for key, value in (release_compatibility or {}).items()
            },
        },
        "oracle_obligations": [
            "prove MAGUS_ROUTE_EXECUTED for the selected route or source/API sequence",
            "prove the acquire/release state transition on the same logical resource",
            "distinguish failed acquisition sentinels from live resources before reporting lifecycle misuse",
            "treat ownership transfer and duplicate handles/descriptors as new ownership facts",
            "return MAGUS_ORACLE_UNSUPPORTED instead of NOT_EXPLOITABLE when the harness cannot observe the lifecycle state",
        ],
    }
    if execution_contexts:
        model["execution_contexts"] = list(execution_contexts)
    return model


POSIX_FD_PROFILE_ID = "resource.fd_lifecycle.user_posix"
POSIX_FD_ACQUIRE_APIS: Tuple[str, ...] = (
    "open",
    "openat",
    "openat2",
    "creat",
    "_open",
    "_wopen",
    "_sopen",
    "_wsopen",
    "socket",
    "socketpair",
    "accept",
    "accept4",
    "pipe",
    "pipe2",
    "eventfd",
    "eventfd2",
    "timerfd_create",
    "signalfd",
    "signalfd4",
    "epoll_create",
    "epoll_create1",
    "inotify_init",
    "inotify_init1",
)
POSIX_FD_RELEASE_APIS: Tuple[str, ...] = ("close", "_close")
POSIX_FD_TRANSFER_APIS: Tuple[str, ...] = ("fdopen",)
POSIX_FD_DUP_APIS: Tuple[str, ...] = ("dup", "dup2", "dup3", "fcntl")

STDIO_PROFILE_ID = "resource.stream_lifecycle.c_stdio"
STDIO_ACQUIRE_APIS: Tuple[str, ...] = ("fopen", "_wfopen", "fdopen", "freopen", "tmpfile", "popen")
STDIO_RELEASE_APIS: Tuple[str, ...] = ("fclose", "pclose")

WIN32_HANDLE_PROFILE_ID = "resource.handle_lifecycle.win32"
WIN32_HANDLE_ACQUIRE_APIS: Tuple[str, ...] = (
    "CreateFile",
    "CreateFileA",
    "CreateFileW",
    "CreateEventA",
    "CreateEventW",
    "CreateMutexA",
    "CreateMutexW",
    "CreateNamedPipeA",
    "CreateNamedPipeW",
)
WIN32_HANDLE_RELEASE_APIS: Tuple[str, ...] = ("CloseHandle",)
WIN32_HANDLE_DUP_APIS: Tuple[str, ...] = ("DuplicateHandle",)

LINUX_KERNEL_PROFILE_ID = "resource.lifecycle.linux_kernel"
LINUX_KERNEL_ACQUIRE_APIS: Tuple[str, ...] = ("filp_open", "get_file", "kmalloc", "kzalloc", "kobject_get")
LINUX_KERNEL_RELEASE_APIS: Tuple[str, ...] = ("filp_close", "fput", "kfree", "kobject_put")


def lifecycle_profile_api_markers(
    profile_id: str,
    acquire: Tuple[str, ...],
    release: Tuple[str, ...],
    transfer: Tuple[str, ...] = (),
    duplicate: Tuple[str, ...] = (),
) -> Dict[str, Tuple[str, ...]]:
    markers: Dict[str, Tuple[str, ...]] = {}
    acquire_reasons = ("missing_release", "failed_acquire_used", "ownership_transfer_lost")
    release_reasons = ("duplicate_release", "wrong_release_api", "use_after_release")
    transfer_reasons = ("ownership_transfer_lost", "wrong_release_api")
    duplicate_reasons = ("missing_release", "duplicate_release", "ownership_transfer_lost")
    for api in acquire:
        markers[api] = lifecycle_api_markers(profile_id, api, acquire_reasons)
    for api in release:
        markers[api] = lifecycle_api_markers(profile_id, api, release_reasons)
    for api in transfer:
        markers[api] = lifecycle_api_markers(profile_id, api, transfer_reasons)
    for api in duplicate:
        markers[api] = lifecycle_api_markers(profile_id, api, duplicate_reasons)
    return markers


def extend_marker_map(
    markers: Dict[str, Tuple[str, ...]],
    extras: Dict[str, Tuple[str, ...]],
) -> Dict[str, Tuple[str, ...]]:
    merged = dict(markers)
    for api, extra_markers in extras.items():
        merged[api] = tuple(dict.fromkeys((*merged.get(api, ()), *extra_markers)))
    return merged


PROFILES: Tuple[OracleProfile, ...] = (
    OracleProfile(
        profile_id="process.untrusted_library_load",
        description="Untrusted or relative path reaches dynamic library loading.",
        cwe_tokens=("cwe-114", "cwe114"),
        keywords=("loadlibrary", "library load", "dll", "relative_library_path", "process control"),
        api_markers={
            "LoadLibraryA": (
                "MAGUS_ORACLE_FLAW name=LoadLibraryA reason=relative_library_path",
                "MAGUS_ORACLE_SINK name=LoadLibraryA tainted=1",
            ),
            "LoadLibraryW": (
                "MAGUS_ORACLE_FLAW name=LoadLibraryW reason=relative_library_path",
                "MAGUS_ORACLE_SINK name=LoadLibraryW tainted=1",
            ),
        },
        generic_markers=(
            "MAGUS_ORACLE_FLAW name=LoadLibraryA reason=relative_library_path",
            "MAGUS_ORACLE_FLAW name=LoadLibraryW reason=relative_library_path",
            "MAGUS_ORACLE_SINK name=LoadLibraryA tainted=1",
            "MAGUS_ORACLE_SINK name=LoadLibraryW tainted=1",
        ),
        accepted_evidence=(
            "route-bound dynamic library load used an attacker-controlled or relative path",
        ),
    ),
    OracleProfile(
        profile_id="process.command_execution",
        description="Attacker-controlled data reaches process or shell execution.",
        cwe_tokens=("cwe-78", "cwe78"),
        keywords=("command injection", "shell", "process execution", "execute command", "os command"),
        api_markers={
            "system": ("MAGUS_ORACLE_SINK name=system tainted=1",),
            "_wsystem": ("MAGUS_ORACLE_SINK name=_wsystem tainted=1",),
            "popen": ("MAGUS_ORACLE_SINK name=popen tainted=1",),
            "_spawnl": ("MAGUS_ORACLE_SINK name=_spawnl tainted=1",),
            "_spawnlp": ("MAGUS_ORACLE_SINK name=_spawnlp tainted=1",),
            "_spawnv": ("MAGUS_ORACLE_SINK name=_spawnv tainted=1",),
            "_spawnvp": ("MAGUS_ORACLE_SINK name=_spawnvp tainted=1",),
            "_execl": ("MAGUS_ORACLE_SINK name=_execl tainted=1",),
            "_execlp": ("MAGUS_ORACLE_SINK name=_execlp tainted=1",),
            "_execv": ("MAGUS_ORACLE_SINK name=_execv tainted=1",),
            "_execvp": ("MAGUS_ORACLE_SINK name=_execvp tainted=1",),
            "CreateProcessA": ("MAGUS_ORACLE_SINK name=CreateProcessA tainted=1",),
            "CreateProcessW": ("MAGUS_ORACLE_SINK name=CreateProcessW tainted=1",),
        },
        generic_markers=(
            "MAGUS_ORACLE_SINK name=system tainted=1",
            "MAGUS_ORACLE_SINK name=_wsystem tainted=1",
            "MAGUS_ORACLE_SINK name=popen tainted=1",
            "MAGUS_ORACLE_SINK name=CreateProcessA tainted=1",
            "MAGUS_ORACLE_SINK name=CreateProcessW tainted=1",
        ),
        accepted_evidence=("route-bound process execution consumed attacker-controlled command text",),
    ),
    OracleProfile(
        profile_id="memory.out_of_bounds_write",
        description="Attacker-controlled index, length, or buffer content reaches an out-of-bounds write.",
        cwe_tokens=(
            "cwe-120",
            "cwe120",
            "cwe-121",
            "cwe121",
            "cwe-122",
            "cwe122",
            "cwe-129",
            "cwe129",
            "cwe-787",
            "cwe787",
        ),
        keywords=(
            "buffer overflow",
            "heap based buffer overflow",
            "stack based buffer overflow",
            "out of bounds",
            "out-of-bounds",
            "array index",
            "upper bound",
            "bounds check",
            "buffer overrun",
        ),
        api_markers={},
        generic_markers=(
            "heap-buffer-overflow",
            "stack-buffer-overflow",
            "global-buffer-overflow",
            "dynamic-stack-buffer-overflow",
            "MAGUS_ORACLE_FLAW profile=memory.out_of_bounds_write reason=out_of_bounds_write",
        ),
        accepted_evidence=(
            "route-bound sanitizer or memory oracle observed an out-of-bounds write",
        ),
        semantic_model={
            "kind": "memory_safety",
            "bug_class": "out_of_bounds_write",
            "execution_environment": "sanitizer_or_harness",
        },
    ),
    OracleProfile(
        profile_id="memory.out_of_bounds_read",
        description="Attacker-controlled index, length, or buffer content reaches an out-of-bounds read.",
        cwe_tokens=("cwe-125", "cwe125", "cwe-126", "cwe126"),
        keywords=(
            "buffer over-read",
            "buffer overread",
            "out of bounds read",
            "out-of-bounds read",
            "read past",
            "array index",
            "upper bound",
        ),
        api_markers={},
        generic_markers=(
            "heap-buffer-overflow",
            "stack-buffer-overflow",
            "global-buffer-overflow",
            "dynamic-stack-buffer-overflow",
            "MAGUS_ORACLE_FLAW profile=memory.out_of_bounds_read reason=out_of_bounds_read",
        ),
        accepted_evidence=("route-bound sanitizer observed an out-of-bounds read",),
        semantic_model={
            "kind": "memory_safety",
            "bug_class": "out_of_bounds_read",
            "execution_environment": "sanitizer_or_harness",
        },
    ),
    OracleProfile(
        profile_id="memory.use_after_free",
        description="Freed memory is later reused on the selected route.",
        cwe_tokens=("cwe-416", "cwe416"),
        keywords=("use after free", "use-after-free", "dangling pointer", "freed memory"),
        api_markers={},
        generic_markers=("heap-use-after-free", "stack-use-after-return", "stack-use-after-scope"),
        accepted_evidence=("route-bound sanitizer observed a use-after-free",),
        semantic_model={
            "kind": "memory_safety",
            "bug_class": "use_after_free",
            "execution_environment": "sanitizer_or_harness",
        },
    ),
    OracleProfile(
        profile_id="integer.overflow",
        description="Arithmetic on the selected route triggers sanitizer-visible integer overflow.",
        cwe_tokens=("cwe-190", "cwe190", "cwe-191", "cwe191", "cwe-680", "cwe680"),
        keywords=("integer overflow", "integer underflow", "signed overflow", "wraparound"),
        api_markers={},
        generic_markers=(
            "runtime error: signed integer overflow",
            "runtime error: unsigned integer overflow",
            "UndefinedBehaviorSanitizer",
        ),
        accepted_evidence=("route-bound sanitizer observed integer overflow or underflow",),
        semantic_model={
            "kind": "integer_safety",
            "bug_class": "integer_overflow",
            "execution_environment": "ubsan_or_harness",
        },
    ),
    OracleProfile(
        profile_id="ldap.injection",
        description="Attacker-controlled LDAP filter reaches search API.",
        cwe_tokens=("cwe-90", "cwe90"),
        keywords=("ldap injection", "ldap_search", "ldap filter"),
        api_markers={
            "ldap_search_ext_sA": ("MAGUS_ORACLE_SINK name=ldap_search_ext_sA tainted=1",),
            "ldap_search_ext_sW": ("MAGUS_ORACLE_SINK name=ldap_search_ext_sW tainted=1",),
            "ldap_search_sA": ("MAGUS_ORACLE_SINK name=ldap_search_sA tainted=1",),
            "ldap_search_sW": ("MAGUS_ORACLE_SINK name=ldap_search_sW tainted=1",),
        },
        accepted_evidence=("route-bound LDAP search used attacker-controlled filter text",),
    ),
    OracleProfile(
        profile_id="config.external_control",
        description="External input controls security-sensitive configuration API.",
        cwe_tokens=("cwe-15", "cwe15"),
        keywords=("external control", "configuration setting", "computer name", "registry"),
        api_markers={
            "SetComputerNameA": ("MAGUS_ORACLE_SINK name=SetComputerNameA tainted=1",),
            "SetComputerNameW": ("MAGUS_ORACLE_SINK name=SetComputerNameW tainted=1",),
            "RegSetValueExA": ("MAGUS_ORACLE_SINK name=RegSetValueExA tainted=1",),
            "RegSetValueExW": ("MAGUS_ORACLE_SINK name=RegSetValueExW tainted=1",),
        },
        accepted_evidence=("route-bound configuration API consumed attacker-controlled data",),
    ),
    OracleProfile(
        profile_id="crypto.broken_algorithm",
        description="Cryptographic API selected a broken primitive or mode.",
        cwe_tokens=("cwe-327", "cwe327", "cwe-328", "cwe328", "cwe-780", "cwe780"),
        keywords=(
            "broken crypto",
            "broken cipher",
            "broken hash",
            "weak hash",
            "rsa without oaep",
            "des",
            "3des",
            "rc5",
            "md5",
            "sha1",
            "sha-1",
        ),
        api_markers={
            "CryptCreateHash": ("MAGUS_ORACLE_FLAW name=CryptCreateHash reason=broken_hash_algorithm",),
            "CryptDeriveKey": ("MAGUS_ORACLE_FLAW name=CryptDeriveKey reason=broken_cipher_algorithm",),
            "CryptEncrypt": ("MAGUS_ORACLE_FLAW name=CryptEncrypt reason=rsa_without_oaep",),
        },
        accepted_evidence=("route-bound crypto API selected a broken algorithm or missing padding mode",),
    ),
    OracleProfile(
        profile_id="crypto.missing_required_step",
        description="Cryptographic operation skipped a required setup step.",
        cwe_tokens=("cwe-325", "cwe325"),
        keywords=("missing required cryptographic step", "missing required step", "without create hash"),
        api_markers={
            "CryptHashData": ("MAGUS_ORACLE_FLAW name=CryptHashData reason=hash_used_without_create_hash",),
        },
        accepted_evidence=("route-bound cryptographic API was used before the required setup step",),
    ),
    OracleProfile(
        profile_id="crypto.weak_prng",
        description="Security-sensitive code used a predictable PRNG.",
        cwe_tokens=("cwe-338", "cwe338"),
        keywords=("weak prng", "predictable random", "rand(", "cryptographically weak"),
        api_markers={
            "rand": ("MAGUS_ORACLE_FLAW name=rand reason=cryptographically_weak_prng",),
        },
        accepted_evidence=("route-bound random generation used a predictable PRNG",),
    ),
    OracleProfile(
        profile_id="tempfile.insecure_name",
        description="Temporary file name was created before exclusive open or creation.",
        cwe_tokens=("cwe-377", "cwe377"),
        keywords=("insecure temporary file", "temporary_name_created_before_open", "tmpnam", "mktemp", "tempnam"),
        api_markers={
            "mktemp": ("MAGUS_ORACLE_FLAW name=mktemp reason=temporary_name_created_before_open",),
            "tempnam": ("MAGUS_ORACLE_FLAW name=tempnam reason=temporary_name_created_before_open",),
            "tmpnam": ("MAGUS_ORACLE_FLAW name=tmpnam reason=temporary_name_created_before_open",),
            "_wmktemp": ("MAGUS_ORACLE_FLAW name=_wmktemp reason=temporary_name_created_before_open",),
            "_wtmpnam": ("MAGUS_ORACLE_FLAW name=_wtmpnam reason=temporary_name_created_before_open",),
            "_wtempnam": ("MAGUS_ORACLE_FLAW name=_wtempnam reason=temporary_name_created_before_open",),
            "GetTempFileNameA": ("MAGUS_ORACLE_FLAW name=GetTempFileNameA reason=uUnique_zero_creates_then_closes_file",),
            "GetTempFileNameW": ("MAGUS_ORACLE_FLAW name=GetTempFileNameW reason=uUnique_zero_creates_then_closes_file",),
        },
        accepted_evidence=("route-bound temporary-file primitive exposed a predictable or pre-created name",),
    ),
    OracleProfile(
        profile_id="path.fixed_buffer_append",
        description="Path append API requires a MAX_PATH-sized destination buffer.",
        cwe_tokens=("cwe-785", "cwe785"),
        keywords=("path manipulation", "pathappend", "without max sized buffer", "max_path"),
        api_markers={
            "PathAppendA": ("MAGUS_ORACLE_FLAW name=PathAppendA reason=pathappend_requires_max_path_sized_buffer",),
            "PathAppendW": ("MAGUS_ORACLE_FLAW name=PathAppendW reason=pathappend_requires_max_path_sized_buffer",),
        },
        accepted_evidence=("route-bound PathAppend call used the fixed-buffer API contract",),
    ),
    OracleProfile(
        profile_id="dns.security_decision",
        description="Reverse DNS lookup influences a security decision.",
        cwe_tokens=("cwe-247", "cwe247"),
        keywords=("dns lookup", "security decision", "reverse dns", "gethostbyaddr"),
        api_markers={
            "gethostbyaddr": ("MAGUS_ORACLE_FLAW name=gethostbyaddr reason=reverse_dns_used_for_security_decision",),
        },
        accepted_evidence=("route-bound reverse DNS lookup was used in the decision path",),
    ),
    OracleProfile(
        profile_id="return_value.unchecked_failure",
        description="Failure return from an API was not handled before use.",
        cwe_tokens=("cwe-252", "cwe252", "cwe-253", "cwe253", "cwe-273", "cwe273", "cwe-690", "cwe690"),
        keywords=("unchecked return", "incorrect check", "dropped privileges", "null deref", "forced_null_return"),
        api_markers={
            "CreateMutexA": ("MAGUS_ORACLE_FLAW name=CreateMutexA reason=forced_null_return_for_return_value_check",),
            "CreateMutexW": ("MAGUS_ORACLE_FLAW name=CreateMutexW reason=forced_null_return_for_return_value_check",),
            "CreateNamedPipeA": ("MAGUS_ORACLE_FLAW name=CreateNamedPipeA reason=forced_invalid_handle_for_return_value_check",),
            "CreateNamedPipeW": ("MAGUS_ORACLE_FLAW name=CreateNamedPipeW reason=forced_invalid_handle_for_return_value_check",),
            "ConnectNamedPipe": ("MAGUS_ORACLE_FLAW name=ConnectNamedPipe reason=invalid_or_failed_handle_used",),
            "ImpersonateNamedPipeClient": (
                "MAGUS_ORACLE_FLAW name=RevertToSelf reason=called_after_failed_impersonation",
            ),
            "RpcImpersonateClient": (
                "MAGUS_ORACLE_FLAW name=RpcImpersonateClient reason=forced_non_ok_return_not_propagated",
            ),
            "_wfopen": ("MAGUS_ORACLE_FLAW name=_wfopen reason=forced_null_return_for_null_deref_check",),
            "fclose": ("MAGUS_ORACLE_FLAW name=fclose reason=null_file_pointer_used",),
        },
        accepted_evidence=("route-bound API failure was forced and later used without a valid check",),
    ),
    OracleProfile(
        profile_id=POSIX_FD_PROFILE_ID,
        description="User-space file descriptor lifecycle is invalid, duplicated, transferred, or missing release.",
        cwe_tokens=("cwe-404", "cwe404", "cwe-672", "cwe672", "cwe-675", "cwe675", "cwe-773", "cwe773", "cwe-775", "cwe775"),
        keywords=(
            "file descriptor",
            "fd leak",
            "descriptor leak",
            "socket leak",
            "missing close",
            "missing release",
            "duplicate close",
            "wrong close",
            "ownership transfer",
        ),
        api_markers=lifecycle_profile_api_markers(
            POSIX_FD_PROFILE_ID,
            POSIX_FD_ACQUIRE_APIS,
            POSIX_FD_RELEASE_APIS,
            POSIX_FD_TRANSFER_APIS,
            POSIX_FD_DUP_APIS,
        ),
        generic_markers=lifecycle_generic_markers(POSIX_FD_PROFILE_ID),
        accepted_evidence=(
            "route-bound user-space fd lifecycle oracle observed acquire/release/transfer state on the same descriptor",
        ),
        semantic_model=lifecycle_semantic_model(
            family="user_posix_fd",
            resource_kind="file_descriptor",
            execution_environment="user_space",
            acquire=POSIX_FD_ACQUIRE_APIS,
            release=POSIX_FD_RELEASE_APIS,
            transfer=POSIX_FD_TRANSFER_APIS,
            duplicate=POSIX_FD_DUP_APIS,
            sentinel_values=("-1",),
            multi_resource_acquire={"pipe": 2, "pipe2": 2, "socketpair": 2},
            release_compatibility={
                "open": ("close", "_close"),
                "_open": ("close", "_close"),
                "_wopen": ("close", "_close"),
                "socket": ("close", "_close"),
                "pipe": ("close", "_close"),
                "eventfd": ("close", "_close"),
            },
        ),
    ),
    OracleProfile(
        profile_id=STDIO_PROFILE_ID,
        description="C stdio stream lifecycle is invalid, transferred, or missing the matching close operation.",
        cwe_tokens=("cwe-404", "cwe404", "cwe-672", "cwe672", "cwe-675", "cwe675", "cwe-773", "cwe773", "cwe-775", "cwe775"),
        keywords=(
            "stdio",
            "file stream",
            "stream leak",
            "missing fclose",
            "missing pclose",
            "missing release",
            "wrong close",
            "ownership transfer",
        ),
        api_markers=lifecycle_profile_api_markers(
            STDIO_PROFILE_ID,
            STDIO_ACQUIRE_APIS,
            STDIO_RELEASE_APIS,
        ),
        generic_markers=lifecycle_generic_markers(STDIO_PROFILE_ID),
        accepted_evidence=(
            "route-bound C stdio lifecycle oracle observed acquire/release/transfer state on the same FILE stream",
        ),
        semantic_model=lifecycle_semantic_model(
            family="c_stdio_stream",
            resource_kind="FILE_stream",
            execution_environment="user_space",
            acquire=STDIO_ACQUIRE_APIS,
            release=STDIO_RELEASE_APIS,
            transfer=("fdopen",),
            sentinel_values=("NULL",),
            release_compatibility={
                "fopen": ("fclose",),
                "_wfopen": ("fclose",),
                "fdopen": ("fclose",),
                "freopen": ("fclose",),
                "tmpfile": ("fclose",),
                "popen": ("pclose",),
            },
        ),
    ),
    OracleProfile(
        profile_id=WIN32_HANDLE_PROFILE_ID,
        description="Win32 HANDLE lifecycle is invalid, duplicated, or missing the matching CloseHandle operation.",
        cwe_tokens=("cwe-404", "cwe404", "cwe-672", "cwe672", "cwe-675", "cwe675", "cwe-773", "cwe773", "cwe-775", "cwe775"),
        keywords=(
            "win32 handle",
            "handle leak",
            "missing closehandle",
            "missing close handle",
            "duplicate closehandle",
            "invalid handle",
            "wrong close api",
        ),
        api_markers=extend_marker_map(
            lifecycle_profile_api_markers(
                WIN32_HANDLE_PROFILE_ID,
                WIN32_HANDLE_ACQUIRE_APIS,
                WIN32_HANDLE_RELEASE_APIS,
                duplicate=WIN32_HANDLE_DUP_APIS,
            ),
            {
                "CloseHandle": (
                    "MAGUS_ORACLE_FLAW name=CloseHandle reason=invalid_or_failed_handle_used",
                    "MAGUS_ORACLE_FLAW name=CloseHandle reason=duplicate_close",
                    "MAGUS_ORACLE_FLAW name=CloseHandle reason=unrecognized_handle_or_wrong_close_api",
                ),
                "CreateFile": ("MAGUS_ORACLE_FLAW name=CreateFile reason=missing_closehandle",),
                "CreateFileA": ("MAGUS_ORACLE_FLAW name=CreateFileA reason=missing_closehandle",),
                "CreateFileW": ("MAGUS_ORACLE_FLAW name=CreateFileW reason=missing_closehandle",),
            },
        ),
        generic_markers=lifecycle_generic_markers(WIN32_HANDLE_PROFILE_ID),
        accepted_evidence=(
            "route-bound Win32 HANDLE lifecycle oracle observed acquire/release/duplicate state on the same HANDLE",
        ),
        semantic_model=lifecycle_semantic_model(
            family="win32_handle",
            resource_kind="HANDLE",
            execution_environment="user_space_windows",
            acquire=WIN32_HANDLE_ACQUIRE_APIS,
            release=WIN32_HANDLE_RELEASE_APIS,
            duplicate=WIN32_HANDLE_DUP_APIS,
            sentinel_values=("NULL", "INVALID_HANDLE_VALUE"),
            release_compatibility={
                "CreateFile": ("CloseHandle",),
                "CreateFileA": ("CloseHandle",),
                "CreateFileW": ("CloseHandle",),
                "CreateEventA": ("CloseHandle",),
                "CreateEventW": ("CloseHandle",),
                "CreateMutexA": ("CloseHandle",),
                "CreateMutexW": ("CloseHandle",),
                "CreateNamedPipeA": ("CloseHandle",),
                "CreateNamedPipeW": ("CloseHandle",),
            },
        ),
    ),
    OracleProfile(
        profile_id=LINUX_KERNEL_PROFILE_ID,
        description="Linux kernel resource lifecycle is invalid, leaked, or released with the wrong kernel API family.",
        cwe_tokens=("cwe-404", "cwe404", "cwe-672", "cwe672", "cwe-675", "cwe675", "cwe-773", "cwe773", "cwe-775", "cwe775"),
        keywords=(
            "linux kernel",
            "kernel resource",
            "kernel refcount",
            "file reference",
            "missing fput",
            "missing kfree",
            "missing kobject_put",
            "reference leak",
        ),
        api_markers=lifecycle_profile_api_markers(
            LINUX_KERNEL_PROFILE_ID,
            LINUX_KERNEL_ACQUIRE_APIS,
            LINUX_KERNEL_RELEASE_APIS,
        ),
        generic_markers=lifecycle_generic_markers(LINUX_KERNEL_PROFILE_ID),
        accepted_evidence=(
            "route-bound Linux kernel lifecycle oracle observed acquire/release/refcount state in a kernel execution context",
        ),
        semantic_model=lifecycle_semantic_model(
            family="linux_kernel_resource",
            resource_kind="kernel_resource_or_reference",
            execution_environment="linux_kernel",
            acquire=LINUX_KERNEL_ACQUIRE_APIS,
            release=LINUX_KERNEL_RELEASE_APIS,
            sentinel_values=("NULL", "ERR_PTR", "IS_ERR", "IS_ERR_OR_NULL"),
            release_compatibility={
                "filp_open": ("filp_close", "fput"),
                "get_file": ("fput",),
                "kmalloc": ("kfree",),
                "kzalloc": ("kfree",),
                "kobject_get": ("kobject_put",),
            },
            execution_contexts=("KUnit", "kselftest", "QEMU", "syzkaller_repro", "module_harness"),
        ),
    ),
    OracleProfile(
        profile_id="memory.sensitive_without_lock",
        description="Sensitive data was used without memory locking.",
        cwe_tokens=("cwe-591", "cwe591"),
        keywords=("sensitive data", "virtuallock", "locked memory", "improperly locked memory"),
        api_markers={
            "LogonUserA": ("MAGUS_ORACLE_FLAW name=LogonUserA reason=sensitive_password_not_virtually_locked",),
            "LogonUserW": ("MAGUS_ORACLE_FLAW name=LogonUserW reason=sensitive_password_not_virtually_locked",),
        },
        accepted_evidence=("route-bound credential API observed sensitive data without VirtualLock protection",),
    ),
    OracleProfile(
        profile_id="path.untrusted_search_path",
        description="Search path state or API uses attacker-influenced path resolution.",
        cwe_tokens=("cwe-426", "cwe426", "cwe-427", "cwe427"),
        keywords=(
            "untrusted search path",
            "uncontrolled search path",
            "search path",
            "searchpath",
            "path environment",
            "path=",
            "dll search directory",
            "setdll",
            "putenv",
        ),
        api_markers={
            "SearchPathA": (
                "MAGUS_ORACLE_FLAW name=SearchPathA reason=tainted_search_path_api",
                "MAGUS_ORACLE_SINK name=SearchPathA tainted=1",
            ),
            "SearchPathW": (
                "MAGUS_ORACLE_FLAW name=SearchPathW reason=tainted_search_path_api",
                "MAGUS_ORACLE_SINK name=SearchPathW tainted=1",
            ),
            "putenv": (
                "MAGUS_ORACLE_FLAW name=putenv reason=tainted_search_path_environment",
                "MAGUS_ORACLE_SINK name=putenv key=PATH tainted=1",
            ),
            "_putenv": (
                "MAGUS_ORACLE_FLAW name=_putenv reason=tainted_search_path_environment",
                "MAGUS_ORACLE_SINK name=_putenv key=PATH tainted=1",
            ),
            "_wputenv": (
                "MAGUS_ORACLE_FLAW name=_wputenv reason=tainted_search_path_environment",
                "MAGUS_ORACLE_SINK name=_wputenv key=PATH tainted=1",
            ),
            "SetEnvironmentVariableA": (
                "MAGUS_ORACLE_FLAW name=SetEnvironmentVariableA reason=tainted_search_path_environment",
                "MAGUS_ORACLE_SINK name=SetEnvironmentVariableA key=PATH tainted=1",
            ),
            "SetEnvironmentVariableW": (
                "MAGUS_ORACLE_FLAW name=SetEnvironmentVariableW reason=tainted_search_path_environment",
                "MAGUS_ORACLE_SINK name=SetEnvironmentVariableW key=PATH tainted=1",
            ),
            "SetDllDirectoryA": (
                "MAGUS_ORACLE_FLAW name=SetDllDirectoryA reason=tainted_dll_search_directory",
                "MAGUS_ORACLE_SINK name=SetDllDirectoryA tainted=1",
            ),
            "SetDllDirectoryW": (
                "MAGUS_ORACLE_FLAW name=SetDllDirectoryW reason=tainted_dll_search_directory",
                "MAGUS_ORACLE_SINK name=SetDllDirectoryW tainted=1",
            ),
            "AddDllDirectory": (
                "MAGUS_ORACLE_FLAW name=AddDllDirectory reason=tainted_dll_search_directory",
                "MAGUS_ORACLE_SINK name=AddDllDirectory tainted=1",
            ),
        },
        generic_markers=(
            "MAGUS_ORACLE_FLAW name=SearchPathA reason=tainted_search_path_api",
            "MAGUS_ORACLE_FLAW name=SearchPathW reason=tainted_search_path_api",
            "MAGUS_ORACLE_FLAW name=putenv reason=tainted_search_path_environment",
            "MAGUS_ORACLE_FLAW name=_putenv reason=tainted_search_path_environment",
            "MAGUS_ORACLE_FLAW name=_wputenv reason=tainted_search_path_environment",
            "MAGUS_ORACLE_FLAW name=SetEnvironmentVariableA reason=tainted_search_path_environment",
            "MAGUS_ORACLE_FLAW name=SetEnvironmentVariableW reason=tainted_search_path_environment",
            "MAGUS_ORACLE_FLAW name=SetDllDirectoryA reason=tainted_dll_search_directory",
            "MAGUS_ORACLE_FLAW name=SetDllDirectoryW reason=tainted_dll_search_directory",
            "MAGUS_ORACLE_FLAW name=AddDllDirectory reason=tainted_dll_search_directory",
        ),
        accepted_evidence=(
            "route-bound search path API or PATH update consumed attacker-controlled path text",
        ),
    ),
)


API_NAMES = tuple(sorted({api for profile in PROFILES for api in profile.api_names}, key=len, reverse=True))


def _token_words(value: str) -> List[str]:
    return re.findall(r"[a-z0-9]+", value.lower())


def _contains_token(haystack_lower: str, token: str) -> bool:
    token_words = _token_words(token)
    if not token_words:
        return False
    haystack_words = _token_words(haystack_lower)
    width = len(token_words)
    return any(haystack_words[index : index + width] == token_words for index in range(len(haystack_words) - width + 1))


def _contains_api_name(haystack_lower: str, api_name: str) -> bool:
    api_lower = api_name.lower()
    pattern = rf"(?<![a-z0-9_]){re.escape(api_lower)}(?![a-z0-9_])"
    return re.search(pattern, haystack_lower) is not None


def infer_api_names(hypothesis: Dict[str, Any]) -> List[str]:
    haystack_lower = hypothesis_text(hypothesis).lower()
    found = [api for api in API_NAMES if _contains_api_name(haystack_lower, api)]
    return sorted(set(found), key=lambda item: API_NAMES.index(item))


def _score_profile(profile: OracleProfile, haystack_lower: str, api_names: Iterable[str]) -> int:
    score = 0
    api_set = set(api_names)
    score += 6 * sum(1 for api in profile.api_names if api in api_set)
    score += 3 * sum(1 for keyword in profile.keywords if _contains_token(haystack_lower, keyword))
    score += 8 * sum(1 for cwe in profile.cwe_tokens if _contains_token(haystack_lower, cwe))
    return score


def select_profile(hypothesis: Dict[str, Any]) -> Tuple[OracleProfile | None, List[str], int]:
    haystack_lower = hypothesis_text(hypothesis).lower()
    api_names = infer_api_names(hypothesis)
    best: Tuple[OracleProfile | None, int] = (None, 0)
    for profile in PROFILES:
        score = _score_profile(profile, haystack_lower, api_names)
        if score > best[1]:
            best = (profile, score)
    profile = best[0]
    if profile is None or best[1] <= 0:
        return None, api_names, 0
    matched = [api for api in api_names if api in profile.api_markers]
    if not matched and not profile.generic_markers:
        return None, api_names, best[1]
    return profile, matched, best[1]


def _confirm_patterns(profile: OracleProfile, matched_apis: List[str]) -> List[str]:
    patterns: List[str] = list(profile.generic_markers)
    if matched_apis:
        for api in matched_apis:
            patterns.extend(profile.api_markers.get(api, ()))
        return sorted(set(patterns))

    return sorted(set(patterns))


def build_oracle_profile(hypothesis: Dict[str, Any]) -> Dict[str, Any]:
    profile, matched_apis, score = select_profile(hypothesis)
    inferred_apis = infer_api_names(hypothesis)
    if profile is None:
        return {
            "profile_id": "unsupported.unclassified_source_api",
            "supported": False,
            "selection_score": score,
            "matched_apis": [],
            "inferred_apis": inferred_apis,
            "confirm_patterns": [],
            "accepted_evidence": [
                "route execution can be observed, but Stage D has no semantic oracle profile for this hypothesis",
            ],
        }

    capability_patterns: List[str] = []
    if (profile.semantic_model or {}).get("kind") == "resource_lifecycle":
        capability_patterns.append(f"MAGUS_ORACLE_RAN profile={profile.profile_id}")

    return {
        "profile_id": profile.profile_id,
        "supported": True,
        "selection_score": score,
        "description": profile.description,
        "matched_apis": matched_apis,
        "inferred_apis": inferred_apis,
        "confirm_patterns": _confirm_patterns(profile, matched_apis),
        "capability_patterns": capability_patterns,
        "accepted_evidence": list(profile.accepted_evidence),
        "semantic_model": profile.semantic_model or {},
    }


def compact_profile_for_json(profile: Dict[str, Any]) -> Dict[str, Any]:
    return json.loads(json.dumps(profile, ensure_ascii=False))
