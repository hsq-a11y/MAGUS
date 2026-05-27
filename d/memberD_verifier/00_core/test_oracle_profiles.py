import unittest

import oracle_profiles


class OracleProfileSelectionTests(unittest.TestCase):
    def test_selects_library_load_without_cwe(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "parse_config -> LoadLibraryA",
                "claim": "user controlled relative DLL path reaches dynamic library loading",
                "evidence_slice": "LoadLibraryA(dllName);",
            }
        )

        self.assertEqual(profile["profile_id"], "process.untrusted_library_load")
        self.assertTrue(profile["supported"])
        self.assertIn("LoadLibraryA", profile["matched_apis"])
        self.assertIn("MAGUS_ORACLE_FLAW name=LoadLibraryA reason=relative_library_path", profile["confirm_patterns"])

    def test_selects_generic_cwe114_wrapper_without_expanded_sink(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "recv -> dataVector -> case0Sink",
                "claim": "network data reaches a CWE114 process-control sink through a container wrapper",
                "cwe_candidates": ["CWE-114"],
                "evidence_slice": "case0Sink(dataVector);",
            }
        )

        self.assertEqual(profile["profile_id"], "process.untrusted_library_load")
        self.assertTrue(profile["supported"])
        self.assertEqual(profile["matched_apis"], [])
        self.assertIn("MAGUS_ORACLE_FLAW name=LoadLibraryA reason=relative_library_path", profile["confirm_patterns"])

    def test_selects_command_execution_without_cwe(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "handle_request -> system",
                "claim": "external input can reach shell command execution",
                "evidence_slice": "system(user_command);",
            }
        )

        self.assertEqual(profile["profile_id"], "process.command_execution")
        self.assertTrue(profile["supported"])
        self.assertIn("MAGUS_ORACLE_SINK name=system tainted=1", profile["confirm_patterns"])

    def test_selects_generic_command_execution_without_expanded_sink(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "recv -> command_wrapper",
                "claim": "CWE-78 command injection through an indirect sink wrapper",
                "cwe_candidates": ["CWE-78"],
                "evidence_slice": "command_wrapper(data);",
            }
        )

        self.assertEqual(profile["profile_id"], "process.command_execution")
        self.assertTrue(profile["supported"])
        self.assertEqual(profile["matched_apis"], [])
        self.assertIn("MAGUS_ORACLE_SINK name=system tainted=1", profile["confirm_patterns"])

    def test_selects_memory_oob_write_for_cwe122(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "recv -> atoi -> buffer[data]",
                "claim": "network input is used as an array index without an upper bound check",
                "cwe_candidates": ["CWE-122", "CWE-129"],
                "evidence_slice": "if (data >= 0) { buffer[data] = 1; }",
            }
        )

        self.assertEqual(profile["profile_id"], "memory.out_of_bounds_write")
        self.assertTrue(profile["supported"])
        self.assertIn("heap-buffer-overflow", profile["confirm_patterns"])
        self.assertEqual(profile["semantic_model"]["bug_class"], "out_of_bounds_write")

    def test_selects_memory_oob_read_for_cwe126(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "recv -> index -> buffer[data]",
                "claim": "network input can cause an out-of-bounds read",
                "cwe_candidates": ["CWE-126"],
                "evidence_slice": "printIntLine(buffer[data]);",
            }
        )

        self.assertEqual(profile["profile_id"], "memory.out_of_bounds_read")
        self.assertTrue(profile["supported"])
        self.assertIn("heap-buffer-overflow", profile["confirm_patterns"])

    def test_selects_use_after_free_for_cwe416(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "free -> reuse",
                "claim": "freed memory can be used again",
                "cwe_candidates": ["CWE-416"],
                "evidence_slice": "free(data); data[0] = 'x';",
            }
        )

        self.assertEqual(profile["profile_id"], "memory.use_after_free")
        self.assertIn("heap-use-after-free", profile["confirm_patterns"])

    def test_selects_integer_overflow_for_cwe190(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "recv -> atoi -> multiply",
                "claim": "input can trigger signed integer overflow",
                "cwe_candidates": ["CWE-190"],
                "evidence_slice": "data = data * 2;",
            }
        )

        self.assertEqual(profile["profile_id"], "integer.overflow")
        self.assertIn("runtime error: signed integer overflow", profile["confirm_patterns"])

    def test_selects_path_environment_update_without_cwe(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "read_config -> _putenv",
                "claim": "user controlled data updates the PATH search path environment",
                "evidence_slice": '_putenv(path_value); /* path_value begins with "PATH=" */',
            }
        )

        self.assertEqual(profile["profile_id"], "path.untrusted_search_path")
        self.assertTrue(profile["supported"])
        self.assertIn("_putenv", profile["matched_apis"])
        self.assertIn(
            "MAGUS_ORACLE_FLAW name=_putenv reason=tainted_search_path_environment",
            profile["confirm_patterns"],
        )

    def test_selects_set_environment_variable_path_update(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "apply_setting -> SetEnvironmentVariableA",
                "claim": "attacker controlled path text is assigned to PATH",
                "evidence_slice": 'SetEnvironmentVariableA("PATH", user_path);',
            }
        )

        self.assertEqual(profile["profile_id"], "path.untrusted_search_path")
        self.assertTrue(profile["supported"])
        self.assertIn("SetEnvironmentVariableA", profile["matched_apis"])
        self.assertIn(
            "MAGUS_ORACLE_FLAW name=SetEnvironmentVariableA reason=tainted_search_path_environment",
            profile["confirm_patterns"],
        )

    def test_selects_search_path_api_without_cwe(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "resolve_tool -> SearchPathW",
                "claim": "attacker controlled directory participates in search path resolution",
                "evidence_slice": "SearchPathW(user_path, tool_name, NULL, cap, out, &part);",
            }
        )

        self.assertEqual(profile["profile_id"], "path.untrusted_search_path")
        self.assertTrue(profile["supported"])
        self.assertIn("SearchPathW", profile["matched_apis"])
        self.assertIn(
            "MAGUS_ORACLE_FLAW name=SearchPathW reason=tainted_search_path_api",
            profile["confirm_patterns"],
        )

    def test_selects_dll_search_directory_api_without_cwe(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "load_plugin -> SetDllDirectoryW",
                "claim": "user supplied plugin directory changes the DLL search directory",
                "evidence_slice": "SetDllDirectoryW(plugin_dir);",
            }
        )

        self.assertEqual(profile["profile_id"], "path.untrusted_search_path")
        self.assertTrue(profile["supported"])
        self.assertIn("SetDllDirectoryW", profile["matched_apis"])
        self.assertIn(
            "MAGUS_ORACLE_FLAW name=SetDllDirectoryW reason=tainted_dll_search_directory",
            profile["confirm_patterns"],
        )

    def test_selects_cwe426_system_as_untrusted_search_path(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "CWE426_Untrusted_Search_Path__char_system_21_bad -> system",
                "claim": "CWE-426 untrusted search path through an unqualified command name",
                "cwe_candidates": ["CWE-426"],
                "evidence_slice": 'strcpy(data, "cmd.exe /c dir"); system(data);',
            }
        )

        self.assertEqual(profile["profile_id"], "path.untrusted_search_path")
        self.assertTrue(profile["supported"])
        self.assertIn("system", profile["matched_apis"])
        self.assertIn(
            "MAGUS_ORACLE_FLAW name=system reason=unqualified_command_search_path",
            profile["confirm_patterns"],
        )

    def test_selects_cwe426_wpopen_as_untrusted_search_path(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "CWE426_Untrusted_Search_Path__wchar_t_popen_21_bad -> _wpopen",
                "claim": "CWE-426 untrusted search path through a wide popen command",
                "cwe_candidates": ["CWE-426"],
                "evidence_slice": 'wcscpy(data, L"ls -la"); _wpopen(data, L"wb");',
            }
        )

        self.assertEqual(profile["profile_id"], "path.untrusted_search_path")
        self.assertTrue(profile["supported"])
        self.assertIn("_wpopen", profile["matched_apis"])
        self.assertIn(
            "MAGUS_ORACLE_FLAW name=_wpopen reason=unqualified_command_search_path",
            profile["confirm_patterns"],
        )

    def test_search_path_profile_has_generic_runtime_markers(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "case route without expanded sink wrapper",
                "claim": "uncontrolled search path element can be reached from external input",
                "cwe_candidates": ["CWE-427"],
                "evidence_slice": "data flows through a wrapper before the sink call",
            }
        )

        self.assertEqual(profile["profile_id"], "path.untrusted_search_path")
        self.assertTrue(profile["supported"])
        self.assertEqual(profile["matched_apis"], [])
        self.assertIn(
            "MAGUS_ORACLE_FLAW name=_putenv reason=tainted_search_path_environment",
            profile["confirm_patterns"],
        )

    def test_search_path_profile_keeps_runtime_equivalents_when_api_is_matched(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "entry -> PUTENV",
                "claim": "CWE-427 uncontrolled search path element through PATH",
                "evidence_slice": "PUTENV(data);",
            }
        )

        self.assertEqual(profile["profile_id"], "path.untrusted_search_path")
        self.assertTrue(profile["supported"])
        self.assertIn("putenv", profile["matched_apis"])
        self.assertIn(
            "MAGUS_ORACLE_FLAW name=putenv reason=tainted_search_path_environment",
            profile["confirm_patterns"],
        )
        self.assertIn(
            "MAGUS_ORACLE_FLAW name=_wputenv reason=tainted_search_path_environment",
            profile["confirm_patterns"],
        )

    def test_unclassified_profile_is_explicitly_unsupported(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "parse -> custom_wrapper",
                "claim": "unknown source/API misuse pattern",
                "evidence_slice": "custom_wrapper(x);",
            }
        )

        self.assertEqual(profile["profile_id"], "unsupported.unclassified_source_api")
        self.assertFalse(profile["supported"])
        self.assertEqual(profile["confirm_patterns"], [])

    def test_cwe_disambiguates_multi_semantic_api_families(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "crypto_flow -> CryptHashData",
                "claim": "CryptoAPI operation misses a required cryptographic step",
                "cwe_candidates": ["CWE-325"],
                "evidence_slice": "CryptHashData(hHash, data, data_len, 0) without CryptCreateHash first;",
            }
        )

        self.assertEqual(profile["profile_id"], "crypto.missing_required_step")
        self.assertTrue(profile["supported"])
        self.assertEqual(profile["matched_apis"], ["CryptHashData"])

    def test_does_not_infer_api_from_substring(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "filesystem_policy_check",
                "claim": "unsupported filesystem policy behavior",
                "evidence_slice": "filesystem state controls behavior",
            }
        )

        self.assertEqual(profile["profile_id"], "unsupported.unclassified_source_api")
        self.assertFalse(profile["supported"])
        self.assertNotIn("system", profile["inferred_apis"])

    def test_cwe_tokens_match_exactly(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "crypto_flow -> CryptEncrypt",
                "claim": "RSA operation without OAEP",
                "cwe_candidates": ["CWE-780"],
                "evidence_slice": "CryptEncrypt(hKey, 0, TRUE, 0, data, &len, cap);",
            }
        )

        self.assertEqual(profile["profile_id"], "crypto.broken_algorithm")
        self.assertTrue(profile["supported"])

    def test_cwe325_unsupported_subtype_is_preserved(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "crypto_flow -> CryptDeriveKey",
                "claim": "CryptoAPI operation misses a required cryptographic step",
                "cwe_candidates": ["CWE-325"],
                "evidence_slice": "CryptDeriveKey(hCryptProv, CALG_AES_256, hHash, 0, &hKey);",
            }
        )

        self.assertEqual(profile["profile_id"], "unsupported.unclassified_source_api")
        self.assertFalse(profile["supported"])
        self.assertEqual(profile["matched_apis"], [])
        self.assertIn("CryptDeriveKey", profile["inferred_apis"])

    def test_selects_rpc_impersonation_without_cwe(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "rpc_server -> RpcImpersonateClient",
                "claim": "RpcImpersonateClient failure return is not checked before continuing",
                "evidence_slice": "RpcImpersonateClient(0);",
            }
        )

        self.assertEqual(profile["profile_id"], "return_value.unchecked_failure")
        self.assertTrue(profile["supported"])
        self.assertIn("RpcImpersonateClient", profile["matched_apis"])
        self.assertIn(
            "MAGUS_ORACLE_FLAW name=RpcImpersonateClient reason=forced_non_ok_return_not_propagated",
            profile["confirm_patterns"],
        )

    def test_named_pipe_impersonation_requires_post_failure_use(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "pipe_server -> ImpersonateNamedPipeClient",
                "claim": "ImpersonateNamedPipeClient failure is ignored",
                "evidence_slice": "ImpersonateNamedPipeClient(hPipe); RevertToSelf();",
            }
        )

        self.assertEqual(profile["profile_id"], "return_value.unchecked_failure")
        self.assertIn(
            "MAGUS_ORACLE_FLAW name=RevertToSelf reason=called_after_failed_impersonation",
            profile["confirm_patterns"],
        )
        self.assertNotIn(
            "MAGUS_ORACLE_FLAW name=ImpersonateNamedPipeClient reason=forced_false_return_for_privilege_drop_check",
            profile["confirm_patterns"],
        )

    def test_selects_user_posix_fd_lifecycle_without_cwe(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "load_config -> open -> parse_config",
                "claim": "the user-space file descriptor returned by open can miss close on an error path",
                "evidence_slice": "fd = open(path, O_RDONLY); if (parse(fd) < 0) return -1;",
            }
        )

        self.assertEqual(profile["profile_id"], "resource.fd_lifecycle.user_posix")
        self.assertTrue(profile["supported"])
        self.assertIn("open", profile["matched_apis"])
        self.assertEqual(profile["semantic_model"]["resource_kind"], "file_descriptor")
        self.assertEqual(profile["semantic_model"]["execution_environment"], "user_space")
        self.assertIn(
            "MAGUS_ORACLE_FLAW profile=resource.fd_lifecycle.user_posix reason=missing_release",
            profile["confirm_patterns"],
        )

    def test_selects_multi_resource_fd_acquire(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "spawn_worker -> pipe2",
                "claim": "one descriptor from pipe2 is released but the paired descriptor leaks",
                "evidence_slice": "int fds[2]; pipe2(fds, O_CLOEXEC); close(fds[0]);",
            }
        )

        self.assertEqual(profile["profile_id"], "resource.fd_lifecycle.user_posix")
        self.assertEqual(profile["semantic_model"]["state_semantics"]["multi_resource_acquire"]["pipe2"], 2)

    def test_selects_c_stdio_lifecycle_without_cwe(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "load_template -> fopen",
                "claim": "the FILE stream opened by fopen can miss fclose on a parse error",
                "evidence_slice": "FILE *fp = fopen(path, \"r\"); if (parse(fp) < 0) return;",
            }
        )

        self.assertEqual(profile["profile_id"], "resource.stream_lifecycle.c_stdio")
        self.assertTrue(profile["supported"])
        self.assertIn("fopen", profile["matched_apis"])
        self.assertEqual(profile["semantic_model"]["resource_kind"], "FILE_stream")
        self.assertEqual(
            profile["semantic_model"]["state_semantics"]["release_compatibility"]["fopen"],
            ["fclose"],
        )

    def test_selects_win32_handle_lifecycle(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "read_state -> CreateFileW",
                "claim": "Win32 HANDLE returned by CreateFileW can miss CloseHandle",
                "evidence_slice": "HANDLE h = CreateFileW(path, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);",
            }
        )

        self.assertEqual(profile["profile_id"], "resource.handle_lifecycle.win32")
        self.assertTrue(profile["supported"])
        self.assertIn("CreateFileW", profile["matched_apis"])
        self.assertEqual(profile["semantic_model"]["execution_environment"], "user_space_windows")
        self.assertIn("INVALID_HANDLE_VALUE", profile["semantic_model"]["state_semantics"]["sentinel_values"])
        self.assertIn(
            "MAGUS_ORACLE_FLAW name=CreateFileW reason=missing_closehandle",
            profile["confirm_patterns"],
        )

    def test_win32_handle_profile_accepts_closehandle_duplicate_runtime_marker(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "file": (
                    "juliet-api-misuse/testcases/CWE675_Duplicate_Operations_on_Resource/"
                    "CWE675_Duplicate_Operations_on_Resource__w32CreateFile_84a.cpp"
                ),
                "route": "CWE675_Duplicate_Operations_on_Resource__w32CreateFile_84::case0",
                "claim": "CWE-675 duplicate CloseHandle on a CreateFile handle",
                "cwe_candidates": ["CWE-675"],
                "evidence_slice": "case0 object action closes the same HANDLE twice",
            }
        )

        self.assertEqual(profile["profile_id"], "resource.handle_lifecycle.win32")
        self.assertIn(
            "MAGUS_ORACLE_FLAW name=CloseHandle reason=duplicate_close",
            profile["confirm_patterns"],
        )

    def test_selects_juliet_cwe404_profile_by_acquired_resource_family(self):
        cases = [
            (
                "juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/"
                "CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_01.c",
                "fopen -> CloseHandle",
                "resource.stream_lifecycle.c_stdio",
            ),
            (
                "juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/"
                "CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_01.c",
                "freopen -> CloseHandle",
                "resource.stream_lifecycle.c_stdio",
            ),
            (
                "juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/"
                "CWE404_Improper_Resource_Shutdown__open_fclose_01.c",
                "open -> fclose",
                "resource.fd_lifecycle.user_posix",
            ),
            (
                "juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/"
                "CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_01.c",
                "CreateFile -> fclose",
                "resource.handle_lifecycle.win32",
            ),
        ]

        for file_name, route, expected_profile_id in cases:
            with self.subTest(file_name=file_name):
                profile = oracle_profiles.build_oracle_profile(
                    {
                        "file": file_name,
                        "route": route,
                        "cwe_candidates": ["CWE-404"],
                        "claim": "Juliet improper resource shutdown route closes with the wrong API family",
                    }
                )

                self.assertEqual(profile["profile_id"], expected_profile_id)
                self.assertTrue(profile["supported"])
                self.assertIn(
                    f"MAGUS_ORACLE_FLAW profile={expected_profile_id} reason=wrong_release_api",
                    profile["confirm_patterns"],
                )

    def test_selects_juliet_cwe675_profile_by_acquired_resource_family(self):
        cases = [
            (
                "juliet-api-misuse/testcases/CWE675_Duplicate_Operations_on_Resource/"
                "CWE675_Duplicate_Operations_on_Resource__freopen_21.c",
                "freopen -> fclose -> fclose",
                "resource.stream_lifecycle.c_stdio",
            ),
            (
                "juliet-api-misuse/testcases/CWE675_Duplicate_Operations_on_Resource/"
                "CWE675_Duplicate_Operations_on_Resource__open_21.c",
                "open -> close -> close",
                "resource.fd_lifecycle.user_posix",
            ),
            (
                "juliet-api-misuse/testcases/CWE675_Duplicate_Operations_on_Resource/"
                "CWE675_Duplicate_Operations_on_Resource__w32CreateFile_21.c",
                "CreateFile -> CloseHandle -> CloseHandle",
                "resource.handle_lifecycle.win32",
            ),
        ]

        for file_name, route, expected_profile_id in cases:
            with self.subTest(file_name=file_name):
                profile = oracle_profiles.build_oracle_profile(
                    {
                        "file": file_name,
                        "route": route,
                        "cwe_candidates": ["CWE-675"],
                        "claim": "Juliet duplicate operation route releases the same resource twice",
                    }
                )

                self.assertEqual(profile["profile_id"], expected_profile_id)
                self.assertTrue(profile["supported"])
                self.assertIn(
                    f"MAGUS_ORACLE_FLAW profile={expected_profile_id} reason=duplicate_release",
                    profile["confirm_patterns"],
                )

    def test_selects_juliet_cwe775_profile_by_acquired_resource_family(self):
        cases = [
            (
                "juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/"
                "CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_21.c",
                "fopen -> no close",
                "resource.stream_lifecycle.c_stdio",
            ),
            (
                "juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/"
                "CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_21.c",
                "open -> no close",
                "resource.fd_lifecycle.user_posix",
            ),
            (
                "juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/"
                "CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_21.c",
                "CreateFile -> no close",
                "resource.handle_lifecycle.win32",
            ),
        ]

        for file_name, route, expected_profile_id in cases:
            with self.subTest(file_name=file_name):
                profile = oracle_profiles.build_oracle_profile(
                    {
                        "file": file_name,
                        "route": route,
                        "cwe_candidates": ["CWE-775"],
                        "claim": "Juliet missing release route leaks the acquired resource",
                    }
                )

                self.assertEqual(profile["profile_id"], expected_profile_id)
                self.assertTrue(profile["supported"])
                self.assertIn(
                    f"MAGUS_ORACLE_FLAW profile={expected_profile_id} reason=missing_release",
                    profile["confirm_patterns"],
                )

    def test_cwe672_container_lifetime_selects_cpp_iterator_profile(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "file": (
                    "juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/"
                    "CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_21.cpp"
                ),
                "route": "std::list<int>::iterator -> data.clear() -> *iterator",
                "cwe_candidates": ["CWE-672"],
                "claim": "Iterator is used after the std::list resource is invalidated by clear().",
                "evidence_slice": "list<int>::iterator i = data.begin(); data.clear(); printIntLine(*i);",
            }
        )

        self.assertEqual(profile["profile_id"], "resource.cpp_iterator_lifecycle")
        self.assertTrue(profile["supported"])
        self.assertNotEqual(profile["profile_id"], "resource.fd_lifecycle.user_posix")
        self.assertIn("attempt to dereference a singular iterator", profile["confirm_patterns"])

    def test_selects_linux_kernel_lifecycle_separately_from_user_space_open(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "driver_ioctl -> filp_open",
                "claim": "Linux kernel route leaks a file reference returned by filp_open without fput",
                "evidence_slice": "struct file *f = filp_open(path, O_RDONLY, 0); return PTR_ERR_OR_ZERO(f);",
            }
        )

        self.assertEqual(profile["profile_id"], "resource.lifecycle.linux_kernel")
        self.assertTrue(profile["supported"])
        self.assertIn("filp_open", profile["matched_apis"])
        self.assertNotIn("open", profile["inferred_apis"])
        self.assertEqual(profile["semantic_model"]["execution_environment"], "linux_kernel")
        self.assertIn("KUnit", profile["semantic_model"]["execution_contexts"])

    def test_kernel_refcount_api_does_not_select_user_fd_lifecycle(self):
        profile = oracle_profiles.build_oracle_profile(
            {
                "route": "driver_probe -> get_file",
                "claim": "kernel refcount acquire with get_file is not paired with fput",
                "evidence_slice": "get_file(file); if (fail) return -EINVAL;",
            }
        )

        self.assertEqual(profile["profile_id"], "resource.lifecycle.linux_kernel")
        self.assertNotEqual(profile["profile_id"], "resource.fd_lifecycle.user_posix")

    def test_profile_markers_are_project_agnostic(self):
        for profile in oracle_profiles.PROFILES:
            for marker_group in profile.api_markers.values():
                for marker in marker_group:
                    self.assertNotIn("JULIET", marker.upper())
            for marker in profile.generic_markers:
                self.assertNotIn("JULIET", marker.upper())


if __name__ == "__main__":
    unittest.main()
