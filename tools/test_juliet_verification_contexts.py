#!/usr/bin/env python3
from __future__ import annotations

import importlib.util
import json
import shutil
import subprocess
import sys
import tempfile
import textwrap
import unittest
from pathlib import Path
from types import SimpleNamespace


def load_module(name: str, path: Path):
    spec = importlib.util.spec_from_file_location(name, path)
    assert spec is not None and spec.loader is not None
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    return module


class JulietContextToolTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        root = Path(__file__).resolve().parents[1]
        cls.tool = load_module("gen_juliet_verification_contexts", root / "tools" / "gen_juliet_verification_contexts.py")

    def test_project_sidecar_uses_template_context_without_oracle_markers(self):
        rows = self.tool.context_rows(["cwe114"], Path("/workspace"))

        self.assertEqual(len(rows), 1)
        row = rows[0]
        self.assertEqual(row["project_id"], "cwe114")
        self.assertEqual(row["repo_path"], "/workspace")
        self.assertIn("tools/juliet_win_shim/run_juliet_win_case.py", row["test_cmd"])
        self.assertIn("${source_file}", row["test_cmd"])
        self.assertIn("${entry_symbol}", row["test_cmd"])
        self.assertIn("${route}", row["test_cmd"])
        oracle_text = json.dumps(row["oracle"], ensure_ascii=False)
        self.assertIn("MAGUS_ROUTE_CONFIRMED", oracle_text)
        self.assertIn("MAGUS_ORACLE_UNSUPPORTED", oracle_text)
        self.assertNotIn("MAGUS_JULIET", oracle_text)


class JulietHelperOutputTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        root = Path(__file__).resolve().parents[1]
        cls.runner = load_module(
            "run_juliet_win_case",
            root / "tools" / "juliet_win_shim" / "run_juliet_win_case.py",
        )

    def test_runtime_markers_are_project_agnostic_for_oracle_matching(self):
        stdout = "\n".join(
            [
                "MAGUS_JULIET_FLAW name=CryptDeriveKey reason=broken_cipher_algorithm value=",
                "MAGUS_JULIET_SINK name=system tainted=1 value=payload",
            ]
        )

        generic = self.runner.generic_oracle_output(stdout)

        self.assertIn("MAGUS_ORACLE_FLAW name=CryptDeriveKey reason=broken_cipher_algorithm", generic)
        self.assertIn("MAGUS_ORACLE_SINK name=system tainted=1", generic)
        self.assertNotIn("MAGUS_JULIET", generic)

    def test_rpc_failure_semantic_marker_is_generic(self):
        stdout = "MAGUS_JULIET_FLAW name=RpcImpersonateClient reason=forced_non_ok_return_for_privilege_drop_check value="

        self.assertEqual(self.runner.route_bound_semantic_markers(stdout, False), [])
        self.assertEqual(
            self.runner.route_bound_semantic_markers(stdout, True),
            ["MAGUS_ORACLE_FLAW name=RpcImpersonateClient reason=forced_non_ok_return_not_propagated value="],
        )

    def test_network_cleartext_marker_requires_selected_profile(self):
        stdout = "\n".join(
            [
                "MAGUS_JULIET_SINK name=recv tainted=1 value=secret",
                "MAGUS_JULIET_SINK name=LogonUserA tainted=1 value=secret",
                "MAGUS_JULIET_FLAW name=LogonUserA reason=sensitive_password_not_virtually_locked value=secret",
            ]
        )

        self.assertEqual(
            self.runner.network_cleartext_semantic_markers(stdout, True, "memory.sensitive_without_lock"),
            [],
        )
        markers = self.runner.network_cleartext_semantic_markers(
            stdout,
            True,
            "network.cleartext_sensitive_transmission",
        )
        self.assertIn(
            "MAGUS_ORACLE_FLAW profile=network.cleartext_sensitive_transmission reason=cleartext_sensitive_transmission",
            markers,
        )
        self.assertIn("MAGUS_ORACLE_SENSITIVE_PROOF name=LogonUserA", markers)

    def test_network_cleartext_marker_reports_protection_instead_of_flaw_after_decrypt(self):
        stdout = "\n".join(
            [
                "MAGUS_JULIET_SINK name=recv tainted=1 value=secret",
                "MAGUS_JULIET_SINK name=CryptDecrypt tainted=0 value=",
                "MAGUS_JULIET_SINK name=LogonUserA tainted=1 value=secret",
            ]
        )

        markers = self.runner.network_cleartext_semantic_markers(
            stdout,
            True,
            "network.cleartext_sensitive_transmission",
        )

        self.assertIn(
            "MAGUS_ORACLE_PROTECTION name=CryptDecrypt reason=ciphertext_to_plaintext_before_sensitive_use",
            markers,
        )
        self.assertNotIn(
            "MAGUS_ORACLE_FLAW profile=network.cleartext_sensitive_transmission reason=cleartext_sensitive_transmission",
            markers,
        )

    def test_lifecycle_capability_markers_cover_fd_stdio_and_win32_profiles(self):
        env = {
            "MAGUS_JULIET_REPORT_FD_LEAKS": "1",
            "MAGUS_JULIET_REPORT_STREAM_LEAKS": "1",
            "MAGUS_JULIET_REPORT_HANDLE_LEAKS": "1",
        }

        self.assertEqual(
            self.runner.oracle_capability_markers("resource.fd_lifecycle.user_posix", env),
            ["MAGUS_ORACLE_RAN profile=resource.fd_lifecycle.user_posix"],
        )
        self.assertEqual(
            self.runner.oracle_capability_markers("resource.stream_lifecycle.c_stdio", env),
            ["MAGUS_ORACLE_RAN profile=resource.stream_lifecycle.c_stdio"],
        )
        self.assertEqual(
            self.runner.oracle_capability_markers("resource.handle_lifecycle.win32", env),
            ["MAGUS_ORACLE_RAN profile=resource.handle_lifecycle.win32"],
        )

    def test_sanitizer_crash_after_bad_entry_counts_as_route_bound(self):
        stdout = "Calling bad()...\n"
        stderr = "ERROR: AddressSanitizer: heap-buffer-overflow on address 0x1"

        self.assertTrue(
            self.runner.route_was_executed(
                stdout,
                Path("CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_21.cpp"),
                "bad",
                stderr,
            )
        )

    def test_lifecycle_flaw_after_bad_entry_counts_as_route_bound(self):
        stdout = "Calling case0()...\n"
        oracle_output = "MAGUS_ORACLE_FLAW profile=resource.fd_lifecycle.user_posix reason=wrong_release_api"

        self.assertTrue(
            self.runner.route_was_executed(
                stdout,
                Path("CWE404_Improper_Resource_Shutdown__open_fclose_72a.cpp"),
                "bad",
                oracle_output,
            )
        )

    def test_lifecycle_flaw_does_not_bind_wrong_scenario(self):
        stdout = "Calling case1()...\n"
        oracle_output = "MAGUS_ORACLE_FLAW profile=resource.fd_lifecycle.user_posix reason=wrong_release_api"

        self.assertFalse(
            self.runner.route_was_executed(
                stdout,
                Path("CWE404_Improper_Resource_Shutdown__open_fclose_72a.cpp"),
                "bad",
                oracle_output,
            )
        )

    def test_search_path_flaw_after_bad_entry_counts_as_route_bound(self):
        stdout = "Calling bad()...\n"
        oracle_output = "MAGUS_ORACLE_FLAW name=system reason=unqualified_command_search_path value=cmd.exe /c dir"

        self.assertTrue(
            self.runner.route_was_executed(
                stdout,
                Path("CWE426_Untrusted_Search_Path__char_system_21.c"),
                "bad",
                oracle_output,
            )
        )

    def test_scenario_detection_prefers_bad_route_when_good_sink_text_is_present(self):
        args = SimpleNamespace(
            route="bad -> CreateFile -> _close /* GoodSink: CloseHandle */",
            entry_symbol="CWE404_Improper_Resource_Shutdown__w32CreateFile_close_01_bad",
        )

        self.assertEqual(
            self.runner.scenario_for(
                args,
                Path("CWE404_Improper_Resource_Shutdown__w32CreateFile_close_01.c"),
            ),
            "bad",
        )

    def test_memory_profile_enables_asan_flags(self):
        self.assertIn(
            "-fsanitize=address",
            self.runner.sanitizer_flags_for("memory.out_of_bounds_write"),
        )
        self.assertIn(
            "-fsanitize=address",
            self.runner.sanitizer_flags_for("memory.out_of_bounds_read"),
        )
        self.assertIn(
            "-fsanitize=address",
            self.runner.sanitizer_flags_for("memory.use_after_free"),
        )
        self.assertEqual(self.runner.sanitizer_flags_for("process.untrusted_library_load"), [])

    def test_integer_profile_enables_ubsan_flags(self):
        flags = self.runner.sanitizer_flags_for("integer.overflow")

        self.assertIn("-fsanitize=undefined,signed-integer-overflow", flags)
        self.assertNotIn("-fsanitize=address", flags)

    def test_cpp_iterator_profile_enables_libstdcxx_debug_mode(self):
        flags = self.runner.sanitizer_flags_for("resource.cpp_iterator_lifecycle")

        self.assertIn("-D_GLIBCXX_DEBUG", flags)
        self.assertIn("-D_GLIBCXX_DEBUG_PEDANTIC", flags)

    def test_cpp_iterator_debug_error_counts_as_route_bound(self):
        stdout = "Calling bad()...\n"
        stderr = "Error: attempt to dereference a singular iterator."

        self.assertTrue(
            self.runner.route_was_executed(
                stdout,
                Path("CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_21.cpp"),
                "bad",
                stderr,
            )
        )

    def test_cpp_iterator_rejects_compiler_generated_route_without_scenario(self):
        args = SimpleNamespace(
            route="CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_68a.cpp::__cxx_global_var_init.2",
            entry_symbol="__cxx_global_var_init.2",
            oracle_profile_id="resource.cpp_iterator_lifecycle",
        )

        self.assertTrue(self.runner.route_is_compiler_generated(args))
        self.assertFalse(self.runner.route_has_scenario_token(args))
        self.assertTrue(self.runner.route_requires_explicit_scenario(args))

    def test_cpp_iterator_rejects_implicit_cpp_destructor_route_without_scenario(self):
        args = SimpleNamespace(
            route=(
                "CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_67a.cpp::"
                "_ZN69CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_6711_structTypeD2Ev"
            ),
            entry_symbol="_ZN69CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_6711_structTypeD2Ev",
            oracle_profile_id="resource.cpp_iterator_lifecycle",
        )

        self.assertTrue(self.runner.route_is_compiler_generated(args))
        self.assertFalse(self.runner.route_has_scenario_token(args))

    def test_cpp_iterator_accepts_case0_route_even_when_mangled(self):
        args = SimpleNamespace(
            route=(
                "CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_62b.cpp::"
                "_ZN69CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_6211case0SourceEv"
            ),
            entry_symbol="_ZN69CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_6211case0SourceEv",
            oracle_profile_id="resource.cpp_iterator_lifecycle",
        )

        self.assertFalse(self.runner.route_is_compiler_generated(args))
        self.assertTrue(self.runner.route_has_scenario_token(args))

    def test_cpp_juliet_compat_flags_allow_windows_pointer_truncation_cases(self):
        flags = self.runner.juliet_compat_compile_flags_for(Path("CWE404_example.cpp"))

        self.assertIn("-fms-extensions", flags)
        self.assertIn("-Wno-pointer-to-int-cast", flags)
        self.assertEqual(self.runner.juliet_compat_compile_flags_for(Path("CWE404_example.c")), [])

    def test_process_shim_declares_wsystem_for_wchar_t_system_cases(self):
        process_header = Path(__file__).resolve().parents[1] / "tools" / "juliet_win_shim" / "process.h"
        text = process_header.read_text(encoding="utf-8")

        self.assertIn("int _wsystem(const wchar_t *command);", text)

    def test_snwprintf_uses_msvc_wide_string_semantics(self):
        compiler = shutil.which("clang-20") or shutil.which("clang") or shutil.which("cc")
        if compiler is None:
            self.skipTest("no C compiler available")
        root = Path(__file__).resolve().parents[1]
        shim_dir = root / "tools" / "juliet_win_shim"
        source = textwrap.dedent(
            r'''
            #include "windows.h"
            #include <stdio.h>

            int main(void)
            {
                wchar_t data[64] = L"memberD_source_api_probe";
                wchar_t filter[128];
                wchar_t *cursor;
                _snwprintf(filter, 128, L"(cn=%s)", data);
                for (cursor = filter; *cursor != L'\0'; cursor++)
                {
                    putchar(*cursor >= 0 && *cursor < 128 ? (char)*cursor : '?');
                }
                putchar('\n');
                return 0;
            }
            '''
        )
        with tempfile.TemporaryDirectory(prefix="magus-snwprintf-test-") as tmp:
            tmp_path = Path(tmp)
            probe = tmp_path / "probe.c"
            binary = tmp_path / "probe"
            probe.write_text(source, encoding="utf-8")
            build = subprocess.run(
                [
                    compiler,
                    "-D_WIN32",
                    "-I",
                    str(shim_dir),
                    str(probe),
                    str(shim_dir / "winapi_runtime_stubs.c"),
                    "-o",
                    str(binary),
                ],
                cwd=str(root),
                text=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                check=False,
            )
            self.assertEqual(build.returncode, 0, build.stdout + build.stderr)
            run = subprocess.run(
                [str(binary)],
                text=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                check=False,
            )
        self.assertEqual(run.returncode, 0, run.stdout + run.stderr)
        self.assertEqual(run.stdout.strip(), "(cn=memberD_source_api_probe)")

    def test_payload_candidates_use_runtime_inputs_json_once_each(self):
        old_value = self.runner.os.environ.get("MAGUS_D_RUNTIME_INPUTS_JSON")
        self.runner.os.environ["MAGUS_D_RUNTIME_INPUTS_JSON"] = '["11", "10", "11"]'
        try:
            self.assertEqual(self.runner.payload_candidates("10"), ["11", "10"])
        finally:
            if old_value is None:
                self.runner.os.environ.pop("MAGUS_D_RUNTIME_INPUTS_JSON", None)
            else:
                self.runner.os.environ["MAGUS_D_RUNTIME_INPUTS_JSON"] = old_value


if __name__ == "__main__":
    unittest.main()
