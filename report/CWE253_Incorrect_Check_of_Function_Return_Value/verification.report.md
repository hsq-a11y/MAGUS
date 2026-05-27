# MAGUS Final Vulnerability Report

- generated_at: 2026-05-25T15:32:55Z
- reportable_vulnerabilities: 909
- d_confirmed_vulnerabilities: 90
- stage_c_preserved_vulnerabilities: 819
- failed_verifications: 188
- source_confirmed: /home/sq_hu/MAGUS/d/memberD_verifier/02_run_with_C/output/CWE253_Incorrect_Check_of_Function_Return_Value/verification.jsonl
- source_failed: /home/sq_hu/MAGUS/d/memberD_verifier/02_run_with_C/output/CWE253_Incorrect_Check_of_Function_Return_Value/verification.failed.jsonl

## Confirmed Vulnerabilities

### 1. hyp_path_f9a844d83b6d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_17.c:56
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 无攻击者输入要求；CreateNamedPipeW因系统资源等原因失败即可
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; hPipe = CreateNamedPipeW(...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_17.c:34-38; if (hPipe == NULL) { exit(1); } // 错误检查，应为INVALID_HANDLE_VALUE @ 同文件行51; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); // 使用无效句柄 @ 同文件行53; CloseHandle(hPipe); // 使用无效句柄 @ 同文件行56
- 结论: 函数CreateNamedPipeW的返回值检查错误：代码使用hPipe == NULL判断失败，但API返回INVALID_HANDLE_VALUE表示失败，而非NULL。这导致在CreateNamedPipeW失败时，程序未正确退出，继续使用无效句柄调用ConnectNamedPipe和CloseHandle，可能引发未定义行为或程序崩溃。
- D验证: confirmed / ver_fe9bf43a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 2. hyp_path_44af2b70067c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_12.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeA调用失败，且globalReturnsTrueOrFalse()返回true
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; BOOL fConnected = FALSE; hPipe = CreateNamedPipeA( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_12.c:33-37; if (hPipe == NULL) { exit(1); } @ CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_12.c:55
- 结论: CreateNamedPipeA的返回值检查不正确：在globalReturnsTrueOrFalse()返回true的分支中，代码将返回值与NULL比较，但根据Windows API规范，失败时返回INVALID_HANDLE_VALUE，导致错误处理分支（exit(1)）不会执行，程序继续使用无效句柄调用ConnectNamedPipe，可能引发未定义行为。另一个分支正确检查了INVALID_HANDLE_VALUE，因此漏洞仅存在于特定分支。
- D验证: confirmed / ver_8139360e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 3. hyp_path_2ffd601ec0fb

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_17.c:56
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够控制pipeName输入，使CreateNamedPipeA失败，返回INVALID_HANDLE_VALUE而不是NULL，导致错误检查失效，后续操作在无效句柄上执行。
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; hPipe = CreateNamedPipeA(pipeName, ...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_17.c:34-37; if (hPipe == NULL) { exit(1); } fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_17.c:51-54; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_17.c:56-58
- 结论: 函数CreateNamedPipeA的返回值检查错误：使用hPipe == NULL而非INVALID_HANDLE_VALUE比较，导致创建管道失败时无法正确检测，后续ConnectNamedPipe和CloseHandle使用无效句柄，可能引发未定义行为。
- D验证: confirmed / ver_24eec83f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 4. hyp_path_22eae35eccd6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_12.c:83
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeW调用失败（例如管道名冲突或实例数超限）; globalReturnsTrueOrFalse() 返回真
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeW( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_12.c:62-66; if (hPipe == NULL) { exit(1); } fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_12.c:78-82
- 结论: 在CreateNamedPipeW调用后，代码使用hPipe == NULL进行错误检查，但CreateNamedPipeW失败时返回INVALID_HANDLE_VALUE，而非NULL。这导致错误状态被忽略，后续可能使用无效句柄调用ConnectNamedPipe，违反CWE-253。
- D验证: confirmed / ver_45036f61
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 5. hyp_path_53754694e2f7

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_08.c:68
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeA失败（例如管道名称冲突或系统资源不足），返回INVALID_HANDLE_VALUE
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeA( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_08.c:46-50; if (hPipe == NULL) { exit(1); } // 错误检查：应该检查INVALID_HANDLE_VALUE @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_08.c:63-67; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); // 使用可能无效的hPipe @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_08.c:68
- 结论: CreateNamedPipeA的返回值检查错误：使用了NULL检查而不是INVALID_HANDLE_VALUE检查，可能导致使用无效句柄，违反CWE-253。
- D验证: confirmed / ver_7867ec6e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 6. hyp_path_84aedc55c416

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_11.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够触发 CreateNamedPipeA 失败，例如耗尽管道实例或提供无效参数。
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; hPipe = CreateNamedPipeA(...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_11.c:33-37; if (hPipe == NULL) { exit(1); } fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_11.c:50-54; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_11.c:55
- 结论: CreateNamedPipeA 的返回值检查不正确：代码将返回值与 NULL 比较，但 Windows API 失败时返回 INVALID_HANDLE_VALUE。若管道创建失败，程序不会退出，而是继续执行 ConnectNamedPipe 和 CloseHandle，可能导致未定义行为或崩溃。
- D验证: confirmed / ver_8f5adac8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 7. hyp_path_e5d1c0bd2a3d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_08.c:68
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者可能通过控制管道名称或系统状态导致 CreateNamedPipeW 失败
- 触发路径: void CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_08_case0() { if(staticReturnsTrue()) { @ L40-44; HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeW( pipeName, ...); @ L46-50; if (hPipe == NULL) { exit(1); } // 错误检查：应为 INVALID_HANDLE_VALUE @ L63-67; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); // 使用无效句柄 @ L68
- 结论: CreateNamedPipeW 失败时返回 INVALID_HANDLE_VALUE，但代码检查 hPipe == NULL，导致无效句柄未被检测，后续 ConnectNamedPipe 使用无效句柄，可能引发未定义行为或拒绝服务。
- D验证: confirmed / ver_6eb155f1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 8. hyp_path_10a2f8374a3d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_11.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeW因资源不足或其他原因失败返回INVALID_HANDLE_VALUE
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeW(...); @ line 33-37; if (hPipe == NULL) { exit(1); } fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ line 50-54
- 结论: 对CreateNamedPipeW的返回值检查错误：该API失败时返回INVALID_HANDLE_VALUE，但代码中检查是否为NULL，导致无法正确检测失败，可能后续操作使用无效句柄。
- D验证: confirmed / ver_4476abc1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 9. hyp_path_953979de23d4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_01.c:53
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeA函数返回失败状态（例如管道创建失败）。
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; BOOL fConnected = FALSE; hPipe = CreateNamedPipeA( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_01.c:31-35; if (hPipe == NULL) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_01.c:48
- 结论: CreateNamedPipeA函数返回INVALID_HANDLE_VALUE表示失败，但代码错误地检查hPipe == NULL，导致错误无法被检测到，后续使用无效句柄可能引发未定义行为。
- D验证: confirmed / ver_1d41edf3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 10. hyp_path_651a5014322c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_02.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 调用CreateNamedPipeA时失败（例如管道名称冲突或系统资源不足）
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeA(...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_02.c:33-37; if (hPipe == NULL) { exit(1); } // 错误检查，应检查INVALID_HANDLE_VALUE @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_02.c:50-54; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); // 使用无效句柄 @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_02.c:50-54
- 结论: 函数CreateNamedPipeA返回INVALID_HANDLE_VALUE表示失败，但代码使用hPipe == NULL进行错误检查，这是不正确的。如果CreateNamedPipeA失败返回INVALID_HANDLE_VALUE，则检查跳过，导致后续使用无效句柄调用ConnectNamedPipe，违反API契约。
- D验证: confirmed / ver_086a2627
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 11. hyp_path_c0f2eed1b944

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_03.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够使CreateNamedPipeA调用失败，例如通过耗尽系统管道资源或使管道名称已存在且未被正确配置。
- 触发路径: hPipe = CreateNamedPipeA( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_03.c:55; if (hPipe == NULL) { exit(1); } @ CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_03.c:50; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_03.c:53-54; CloseHandle(hPipe); @ CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_03.c:56
- 结论: CreateNamedPipeA返回值的检查使用了NULL而不是INVALID_HANDLE_VALUE，导致函数失败后句柄被误认为有效，后续ConnectNamedPipe和CloseHandle调用可能使用无效句柄，违反CWE-253。
- D验证: confirmed / ver_fa70de36
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 12. hyp_path_b705b64709ed

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_04.c:61
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 无外部输入控制，缺陷源于程序员对返回值 sentinel 的错误认知
- 触发路径: hPipe = CreateNamedPipeA( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ... ); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_04.c:61; if (hPipe == NULL) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_04.c:56
- 结论: 函数 CreateNamedPipeA 返回 INVALID_HANDLE_VALUE 表示失败，但代码中错误地检查 hPipe == NULL，导致无法捕获失败情况，后续可能使用无效句柄调用 ConnectNamedPipe 或 CloseHandle，违反 CWE-253。
- D验证: confirmed / ver_0039e8f0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 13. hyp_path_46fb07de0d6c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_05.c:61
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够导致CreateNamedPipeA失败，例如通过耗尽系统管道资源或竞争条件
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeA(...); @ L39-43; if (hPipe == NULL) { exit(1); } @ L?（检查点，位于ConnectNamedPipe前）; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ L56-60
- 结论: CreateNamedPipeA失败返回INVALID_HANDLE_VALUE，代码仅检查NULL，导致未捕获错误，后续ConnectNamedPipe使用无效句柄，违反CWE-253。
- D验证: confirmed / ver_fbfd581d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 14. hyp_path_abe477060274

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_06.c:60
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeA调用失败（例如权限不足、管道名称冲突等），导致返回INVALID_HANDLE_VALUE。
- 触发路径: hPipe = CreateNamedPipeA(pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_06.c:38-42; if (hPipe == NULL) { exit(1); } @ CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_06.c:55-59; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_06.c:55-59; CloseHandle(hPipe); @ CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_06.c:58-62
- 结论: CreateNamedPipeA返回INVALID_HANDLE_VALUE表示失败，但代码仅检查hPipe == NULL，这是错误的sentinel检查。如果CreateNamedPipeA失败，后续ConnectNamedPipe和CloseHandle将在无效句柄上操作，导致未定义行为或崩溃。
- D验证: confirmed / ver_687d861f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 15. hyp_path_3c89a3d46da5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_07.c:60
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够导致CreateNamedPipeA失败，例如通过创建同名管道耗尽实例或占用资源
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeA(pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ 38-42; if (hPipe == NULL) { exit(1); } // 错误检查，应为INVALID_HANDLE_VALUE @ 55; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); // 使用无效句柄 @ 60; CloseHandle(hPipe); // 关闭无效句柄 @ 58-62
- 结论: 函数CreateNamedPipeA的返回值检查错误：代码检查hPipe是否等于NULL，但Windows API CreateNamedPipe失败时返回INVALID_HANDLE_VALUE而不是NULL。这导致错误无法被捕获，程序可能使用无效句柄调用ConnectNamedPipe和CloseHandle，造成未定义行为或拒绝服务。
- D验证: confirmed / ver_33d729c3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 16. hyp_path_d4c99d901f83

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_09.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeA在系统资源不足或其他原因下失败，返回INVALID_HANDLE_VALUE。
- 触发路径: hPipe = CreateNamedPipeA(pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_09.c:55; if (hPipe == NULL) { exit(1); } // 错误检查：应检查INVALID_HANDLE_VALUE @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_09.c:55; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); // 使用无效句柄 @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_09.c:55; CloseHandle(hPipe); // 关闭无效句柄 @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_09.c:55
- 结论: 对CreateNamedPipeA的返回值检查错误：使用NULL而非INVALID_HANDLE_VALUE进行判断，导致句柄可能无效时未被检测，进而使用无效句柄调用ConnectNamedPipe和CloseHandle，可能引发未定义行为或安全风险。
- D验证: confirmed / ver_15df6c39
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 17. hyp_path_142b6adc5a65

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_10.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeA函数调用可能失败（如权限不足、管道名冲突等）
- 触发路径: hPipe = CreateNamedPipeA(pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ path:55行; if (hPipe == NULL) { exit(1); } @ path:50行
- 结论: 创建命名管道时使用了不正确的返回值检查：CreateNamedPipeA返回INVALID_HANDLE_VALUE表示失败，但代码检查hPipe == NULL，导致无法正确检测管道创建失败。
- D验证: confirmed / ver_92cab33c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 18. hyp_path_5a895dd951a4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_13.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeA 因系统资源不足或其他原因失败
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeA(...); @ 33-37; if (hPipe == NULL) { exit(1); } // 错误检查，应检查 INVALID_HANDLE_VALUE @ 50; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : ...; // 使用无效句柄 @ 51-54; CloseHandle(hPipe); // 使用无效句柄 @ 55
- 结论: CreateNamedPipeA 返回 INVALID_HANDLE_VALUE (即 (HANDLE)-1) 时，代码仅检查 hPipe == NULL，而 INVALID_HANDLE_VALUE 不等于 NULL，导致错误返回值未被正确检测，后续使用无效句柄可能导致未定义行为。
- D验证: confirmed / ver_aa745b4f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 19. hyp_path_f842ab3258eb

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_14.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeA调用失败，例如由于系统资源不足或命名管道已存在
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeA(...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_14.c:33-37; if (hPipe == NULL) { exit(1); } // 错误检查：应检查 INVALID_HANDLE_VALUE @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_14.c:50; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_14.c:55; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_14.c:55
- 结论: 在CreateNamedPipeA调用失败时，函数返回INVALID_HANDLE_VALUE，但代码将返回值与NULL比较（而非INVALID_HANDLE_VALUE），导致错误检查遗漏。后续使用无效句柄调用ConnectNamedPipe和CloseHandle，可能导致未定义行为或拒绝服务。
- D验证: confirmed / ver_bfc09e22
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 20. hyp_path_f5eb0b1dee35

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_15.c:56
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够影响CreateNamedPipeA的失败条件，例如通过耗尽系统资源或竞争条件导致管道创建失败
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; BOOL fConnected = FALSE; hPipe = CreateNamedPipeA( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_15.c:34-38; if (hPipe == NULL) { exit(1); } fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_15.c:51-55; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_15.c:54-58
- 结论: CreateNamedPipeA的返回值被错误地检查为NULL，实际上失败时返回INVALID_HANDLE_VALUE。如果CreateNamedPipeA失败，hPipe将被设置为INVALID_HANDLE_VALUE，但检查条件(hPipe == NULL)为假，导致程序继续执行并可能对无效句柄进行ConnectNamedPipe和CloseHandle操作，引发未定义行为或崩溃。
- D验证: confirmed / ver_1e86d741
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 21. hyp_path_cf5225e0f2d0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_16.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeA 调用失败（返回 INVALID_HANDLE_VALUE）
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeA(...); @ 33-37; if (hPipe == NULL) { exit(1); } @ 55; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ 55; CloseHandle(hPipe); @ 55 (after)
- 结论: CreateNamedPipeA 返回 INVALID_HANDLE_VALUE 表示失败，但代码使用 hPipe == NULL 检查，无法检测到错误，导致后续 ConnectNamedPipe 可能使用无效句柄，违反 CWE-253。
- D验证: confirmed / ver_efd483c1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 22. hyp_path_2fca2ecbb38c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_01.c:53
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够通过资源耗尽（如管道名称冲突或系统限制）导致CreateNamedPipeW失败
- 触发路径: hPipe = CreateNamedPipeW( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_01.c:33-34; if (hPipe == NULL) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_01.c:47-48; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); ... CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_01.c:50-53
- 结论: 在CreateNamedPipeW调用后，程序错误地检查了返回值是否为NULL，而CreateNamedPipeW失败时返回INVALID_HANDLE_VALUE，导致后续使用无效句柄的ConnectNamedPipe和CloseHandle操作可能引发未定义行为或拒绝服务。
- D验证: confirmed / ver_8d5c0580
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 23. hyp_path_a58ad13e1e30

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_18.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeA 调用失败（如管道名无效、系统资源不足等）
- 触发路径: hPipe = CreateNamedPipeA( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ... ); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_18.c:33-37; if (hPipe == NULL) { exit(1); } @ 同一文件约行40; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ 同一文件:50-54; CloseHandle(hPipe); @ 同一文件:53-57
- 结论: CreateNamedPipeA 返回 INVALID_HANDLE_VALUE 表示失败，但代码错误地检查 hPipe == NULL 而非 INVALID_HANDLE_VALUE，导致未检测到失败，后续可能使用无效句柄调用 ConnectNamedPipe 或 CloseHandle，造成未定义行为或拒绝服务。
- D验证: confirmed / ver_0c1d9ad6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 24. hyp_path_bbc3cc2ce3b9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_02.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeW 调用可能失败（例如管道实例数达到上限，或系统资源不足）
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeW(...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_02.c:33-37; if (hPipe == NULL) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_02.c:50; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_02.c:50-54
- 结论: CreateNamedPipeW 函数失败时返回 INVALID_HANDLE_VALUE，而非 NULL，但代码中错误地使用 `if (hPipe == NULL)` 进行检查，导致失败未被正确处理。随后使用无效的句柄调用 ConnectNamedPipe，可能导致未定义行为或安全漏洞。
- D验证: confirmed / ver_c66f70e2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 25. hyp_path_4d77c10a659d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_03.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeW函数因权限不足、管道名冲突或其他原因返回INVALID_HANDLE_VALUE
- 触发路径: hPipe = CreateNamedPipeW(...); if (hPipe == NULL) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_03.c:50-51
- 结论: 函数CreateNamedPipeW的返回值检查错误：使用NULL与句柄比较，但实际失败时应返回INVALID_HANDLE_VALUE（即((HANDLE)(LONG_PTR)-1)），导致无法正确检测失败情况，可能使程序在管道创建失败时未正确处理而继续执行后续操作（如ConnectNamedPipe和CloseHandle），造成逻辑错误或未定义行为。
- D验证: confirmed / ver_671aef1d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 26. hyp_path_f60893e385c5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_04.c:61
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 无需攻击者控制，CreateNamedPipeW失败即可
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeW(...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_04.c:39-43; if (hPipe == NULL) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_04.c:55-56; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_04.c:59-60; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_04.c:61
- 结论: 对CreateNamedPipeW的返回值检查使用了NULL而不是INVALID_HANDLE_VALUE，违反API契约，导致未能检测到错误，后续使用无效句柄。
- D验证: confirmed / ver_6f5aae26
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 27. hyp_path_ced673f571dd

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_05.c:61
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeW失败，例如命名管道资源耗尽或权限不足（如已存在同名管道实例）
- 触发路径: hPipe = CreateNamedPipeW( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_05.c:39-43; if (hPipe == NULL) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_05.c:56; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_05.c:61
- 结论: 在CWE253样本中，CreateNamedPipeW的返回值被错误地检查为NULL（第56行），而实际失败时返回INVALID_HANDLE_VALUE。这种不正确的检查可能导致在CreateNamedPipeW失败后，程序继续使用无效句柄调用ConnectNamedPipe和CloseHandle，引发未定义行为或安全风险。
- D验证: confirmed / ver_144f86a8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 28. hyp_path_06148929e15e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_06.c:60
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeW调用失败，例如由于系统资源不足或权限问题，导致返回INVALID_HANDLE_VALUE
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeW(...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_06.c:38-42; if (hPipe == NULL) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_06.c:55-56; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_06.c:57-59; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_06.c:60
- 结论: CreateNamedPipeW的返回值检查错误：代码使用`if (hPipe == NULL)`检查失败，但CreateNamedPipeW失败时返回INVALID_HANDLE_VALUE（-1），而非NULL。这导致即使管道创建失败，程序也不会退出，后续使用无效句柄（如ConnectNamedPipe、CloseHandle）可能导致未定义行为。
- D验证: confirmed / ver_6fa82e30
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 29. hyp_path_9e228a1d2077

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_07.c:60
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeW 调用失败，返回 INVALID_HANDLE_VALUE（非 NULL）
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; BOOL fConnected = FALSE; hPipe = CreateNamedPipeW( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_07.c:38-42; if (hPipe == NULL) { exit(1); } fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_07.c:55-59; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_07.c:58-62
- 结论: CreateNamedPipeW 返回 INVALID_HANDLE_VALUE 时，代码错误地使用 hPipe == NULL 进行检查，导致无法正确处理失败情况，从而使用无效句柄进行后续操作（ConnectNamedPipe、CloseHandle），可能引发未定义行为或拒绝服务。
- D验证: confirmed / ver_3c34a8f9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 30. hyp_path_83307d0988c0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_09.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeW调用失败（如管道名称冲突、权限不足等）。
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeW(...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_09.c:33-37; if (hPipe == NULL) { exit(1); } // 错误检查，应为INVALID_HANDLE_VALUE @ 同上文件:50; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); // 若hPipe无效则风险持续 @ 同上文件:55
- 结论: 调用CreateNamedPipeW后，使用hPipe == NULL检查返回值，但实际失败返回INVALID_HANDLE_VALUE，导致错误处理缺失，后续可能使用无效句柄。
- D验证: confirmed / ver_722f6087
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 31. hyp_path_3078d2d5ff35

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_10.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeW调用失败（例如资源不足或名称冲突）
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; hPipe = CreateNamedPipeW(...); @ line 35-37; if (hPipe == NULL) { exit(1); } fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); ... CloseHandle(hPipe); @ line 50-55
- 结论: 对CreateNamedPipeW的返回值检查错误：成功时返回有效句柄，失败时返回INVALID_HANDLE_VALUE，但代码检查hPipe == NULL，导致失败时无法正确退出，后续可能使用无效句柄。
- D验证: confirmed / ver_5488f573
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 32. hyp_path_b792151db293

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_14.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够影响系统资源或权限，使CreateNamedPipeW调用失败。
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeW(...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_14.c:33-37; if (hPipe == NULL) { exit(1); } fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_14.c:50-54
- 结论: 函数CreateNamedPipeW返回INVALID_HANDLE_VALUE表示失败，但代码错误地使用hPipe == NULL进行检查，导致无法正确检测管道创建失败，可能使用无效句柄继续执行，违反了CWE-253（函数返回值错误检查）。
- D验证: confirmed / ver_4616028d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 33. hyp_path_2cee824ec36e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_13.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够影响管道创建环境，使得CreateNamedPipeW失败（例如，通过资源耗尽或权限不足）
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; BOOL fConnected = FALSE; hPipe = CreateNamedPipeW( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_13.c:33-37; if (hPipe == NULL) { exit(1); } fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_13.c:50-54
- 结论: CreateNamedPipeW函数返回INVALID_HANDLE_VALUE表示失败，但代码错误地使用hPipe == NULL进行检查，导致无法正确检测管道创建失败。如果CreateNamedPipeW失败，程序可能继续执行并使用无效的管道句柄，导致未定义行为或拒绝服务。
- D验证: confirmed / ver_1dc407a9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 34. hyp_path_f88f07947b85

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_15.c:56
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeW 调用失败并返回 INVALID_HANDLE_VALUE。
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; BOOL fConnected = FALSE; hPipe = CreateNamedPipeW( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_15.c:34-38; if (hPipe == NULL) { exit(1); } fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_15.c:51-55; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_15.c:54-58
- 结论: CreateNamedPipeW 函数在失败时返回 INVALID_HANDLE_VALUE，但代码使用 hPipe == NULL 进行检查，错误地忽略了 INVALID_HANDLE_VALUE，导致在创建失败后继续调用 ConnectNamedPipe 和 CloseHandle 操作无效句柄，违反 CWE-253 正确检查函数返回值的要求。
- D验证: confirmed / ver_1a8e48f5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 35. hyp_path_0b256cdffb47

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_16.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateNamedPipeW 调用失败返回 INVALID_HANDLE_VALUE
- 触发路径: if (hPipe == NULL) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_16.c:51
- 结论: 对 CreateNamedPipeW 的返回值检查使用了 NULL 而不是 INVALID_HANDLE_VALUE，导致管道创建失败时无法正确处理，后续使用无效句柄调用 ConnectNamedPipe 和 CloseHandle。
- D验证: confirmed / ver_6ddb8e61
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 36. hyp_path_39099b0f74da

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_18.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够导致管道创建失败（如通过耗尽系统资源或创建同名管道）
- 触发路径: hPipe = CreateNamedPipeW(pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_18.c:55; if (hPipe == NULL) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_18.c:50; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_18.c:55
- 结论: CreateNamedPipeW 返回 INVALID_HANDLE_VALUE 时错误地检查 NULL 而非 INVALID_HANDLE_VALUE，导致后续使用无效句柄，违反 API contract。
- D验证: confirmed / ver_a171c890
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 37. hyp_path_44cb18914bd5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_17.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fgets(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_17.c:37
- 结论: fgets函数返回值检查错误：fgets失败时返回NULL，但代码使用<0比较，导致错误处理逻辑永远无法触发。后续printLine(data)使用空字符串，影响较低，但仍违反API contract。
- D验证: stage_c_preserved / ver_c41716a3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 38. hyp_path_123a20e7a4c8

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_12.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使fgets调用失败（如关闭stdin或提供EOF）; globalReturnsTrueOrFalse() 返回 true
- 触发路径: if(globalReturnsTrueOrFalse()) { @ 24; if (fgets(data, 100, stdin) < 0) { printLine("fgets failed!"); exit(1); } @ 35-37
- 结论: 存在对fgets返回值的错误检查：fgets失败时返回NULL，但代码中检查返回值<0，导致无法正确检测失败。虽然data已初始化为空字符串，不会导致未初始化数据使用，但违反了CWE-253的API契约。
- D验证: stage_c_preserved / ver_21ec52bb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 39. hyp_path_03d5e041c883

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_08.c:49
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使fgets失败（例如关闭stdin或触发输入错误）
- 触发路径: if (fgets(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_08.c:49
- 结论: 对fgets返回值的检查不正确：fgets失败时返回NULL，但代码检查是否小于0，这无法捕获失败情况，导致未处理的错误（data保持空字符串）。
- D验证: stage_c_preserved / ver_a6890497
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 40. hyp_path_7797c9725aef

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_11.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致fgets失败（如关闭标准输入或引发读取错误），但不需要控制输入内容。
- 触发路径: if (fgets(data, 100, stdin) < 0) { printLine("fgets failed!"); exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_11.c:36
- 结论: 代码对fgets返回值进行了错误检查：fgets返回NULL表示失败，但代码却检查返回值是否小于0，这导致fgets失败时无法正确检测，程序可能继续使用未正确初始化的缓冲区（虽然缓冲区初始化为空字符串，但违反API契约）。
- D验证: stage_c_preserved / ver_a3addae4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 41. hyp_path_7765d2cf9f91

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_01.c:34
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致fgets失败（例如关闭标准输入或触发读取错误）
- 触发路径: if (fgets(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_01.c:34; fgets返回NULL时，比较结果假，绕过错误处理 @ 同上; printLine(data); // 使用空字符串，信息泄露或逻辑错误 @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_01.c:39
- 结论: fgets返回值的检查错误，使用了与0比较而不是与NULL比较，违反了API contract，可能导致在fgets失败时未正确处理，进而使用未修改的缓冲区数据。
- D验证: stage_c_preserved / ver_4c2abdde
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 42. hyp_path_962295208cda

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_02.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使得fgets失败（如关闭标准输入或发送EOF）
- 触发路径: if (fgets(data, 100, stdin) < 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_02.c:36; printLine(data); // 即使fgets失败也执行 @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_02.c:41
- 结论: fgets返回值检查错误：成功返回指向缓冲区的指针，失败返回NULL。代码中使用 if (fgets(data, 100, stdin) < 0) 进行检查，该条件永远不会为真（因为指针非负，NULL通常为0），导致fgets失败时不会进入错误处理分支，程序可能使用未正确填充的数据。尽管dataBuffer初始化为空字符串，但此行为违背了API契约（CWE-253）。
- D验证: stage_c_preserved / ver_d96bd3fd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 43. hyp_path_d24468ed11de

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_03.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可能导致fgets失败（如关闭stdin流或提供无效输入），但无需直接控制fgets的返回值。
- 触发路径: if (fgets(data, 100, stdin) < 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_03.c:36; printLine(data); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_03.c:41
- 结论: fgets返回值检查错误：将fgets返回值与0比较，但fgets失败时返回NULL，正确的检查应为与NULL比较。代码注释也明确指出这是错误的检查方式。
- D验证: stage_c_preserved / ver_1a0aa88f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 44. hyp_path_edc69fa062a7

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_04.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致fgets失败，例如关闭stdin或提供错误输入，使得返回值不为NULL但条件仍不满足。
- 触发路径: if (fgets(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_04.c:42; printLine(data); // 当fgets失败时仍然执行 @ 同一文件:47
- 结论: 函数fgets的正确返回值检查失败时返回NULL，但代码错误地检查是否小于0，导致fgets失败时不会触发错误处理。虽然dataBuffer已初始化为空字符串，fgets失败时printLine输出空字符串，不存在未初始化未定义行为，但违反了API contract，属于CWE-253漏洞。
- D验证: stage_c_preserved / ver_2db381a4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 45. hyp_path_c5ab68ef6078

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_06.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致 fgets 失败，例如关闭标准输入流或提供无效输入
- 触发路径: if (fgets(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_06.c:41; printLine(data); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_06.c:46
- 结论: 在 fgets 返回值检查中，使用了不正确的条件 `fgets(data, 100, stdin) < 0` 来判断失败。根据 API contract，fgets 失败时返回 NULL，而非负值。因此当 fgets 失败时，错误处理分支不会被执行，程序继续使用 data 缓冲区（虽然初始化为空字符串，但可能包含未定义内容），存在潜在的逻辑错误或信息泄露风险。
- D验证: stage_c_preserved / ver_ac273951
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 46. hyp_path_ed1b8c5f15cf

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_05.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使fgets失败（例如关闭标准输入）。
- 触发路径: if (fgets(data, 100, stdin) < 0) { @ CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_05.c:42
- 结论: 对fgets返回值的检查错误：应检查返回值是否为NULL，但代码使用<0比较，导致条件永不成立，错误处理被跳过。虽然后续使用data（可能为空字符串）不会直接造成安全后果，但违反了CWE-253关于正确检查函数返回值的要求。
- D验证: stage_c_preserved / ver_6432c044
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 47. hyp_path_a958d16bbb13

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_07.c:41
- 漏洞类型: null_deref
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致 fgets 失败（如关闭 stdin 或提供 EOF），或 fgets 因其他原因返回 NULL。
- 触发路径: if (fgets(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_07.c:41; printLine(data); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_07.c:46
- 结论: fgets 函数返回 char* 类型，成功返回指向缓冲区的指针，失败返回 NULL。代码中错误地检查返回值是否小于 0，而非检查是否为 NULL。这违反了 CWE-253（不正确检查函数返回值），即使失败也不会进入错误处理分支，导致后续使用未正确填充的数据（但缓冲区初始化为空字符串，不会导致空指针解引用）。
- D验证: stage_c_preserved / ver_9f6e9769
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 48. hyp_path_5a4a94b93a5f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_09.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致fgets失败（如关闭stdin或发送EOF）
- 触发路径: if (fgets(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_09.c:36
- 结论: fgets的返回值被错误检查：fgets返回char*，失败时返回NULL，但代码将返回值与0比较（<0），这永远为假，导致fgets失败无法被检测，违反CWE-253。
- D验证: stage_c_preserved / ver_b6b4c091
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 49. hyp_path_2496eea88f2d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_10.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fgets()因stdin错误或EOF返回NULL
- 触发路径: if (fgets(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_10.c:36; printLine(data); @ 同文件第41行
- 结论: fgets()的返回值被错误地与0比较（检查是否小于0），而fgets()失败时返回NULL，正确的检查应为if (fgets(...) == NULL)。这违反了CWE-253（函数返回值的不正确检查）。尽管dataBuffer已初始化为空字符串，错误检查导致fgets失败时错误处理不执行，但后续使用空数据无直接安全影响。漏洞存在但影响极低。
- D验证: stage_c_preserved / ver_a9b6e722
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 50. hyp_path_78d1d4399831

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_13.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致fgets失败（例如关闭标准输入流或提供文件结束符）
- 触发路径: if (fgets(data, 100, stdin) < 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_13.c:36; printLine(data); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_13.c:41
- 结论: 错误检查fgets返回值：fgets失败时返回NULL，但代码将其与0比较（<0），导致错误处理无法触发，后续使用可能未正确初始化的数据。
- D验证: stage_c_preserved / ver_4b99036a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 51. hyp_path_8f6affde729b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_14.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fgets函数调用失败（如stdin意外关闭或读取错误）
- 触发路径: if (fgets(data, 100, stdin) < 0) @ CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_14.c:36
- 结论: fgets返回值检查不正确：fgets返回char*，但代码将其与0比较（<0），正确做法是检查是否为NULL。此错误导致当fgets失败返回NULL时，条件为假（NULL<0为假），不会进入错误处理，程序继续使用未修改的dataBuffer空字符串，可能导致逻辑错误或后续误用。
- D验证: stage_c_preserved / ver_b2598012
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 52. hyp_path_cea0f8b4aaf7

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_15.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致fgets调用失败，例如通过提前关闭stdin或发送EOF
- 触发路径: if (fgets(data, 100, stdin) < 0) { printLine("fgets failed!"); exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_15.c:37; printLine(data); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_15.c:42
- 结论: fgets函数的返回值检查错误，使用<0而不是==NULL，导致当fgets失败返回NULL时，条件不满足，程序继续执行后续代码，违反了API contract。
- D验证: stage_c_preserved / ver_70ae2064
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 53. hyp_path_7402ca7775e1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_16.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入导致fgets失败（例如提供EOF或关闭输入流）
- 触发路径: if (fgets(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_16.c:36; printLine(data); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_16.c:41
- 结论: 对fgets的返回值进行了错误检查，使用<0比较而非检查是否为NULL，导致fgets失败时无法正确检测，违反了CWE-253关于正确检查函数返回值的规则。尽管dataBuffer初始化为空字符串，漏洞本身存在，但可利用性较低。
- D验证: stage_c_preserved / ver_c2e41744
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 54. hyp_path_4d0cc1690968

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_18.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序运行且输入流可能遇到错误或EOF，使fgets返回NULL。
- 触发路径: if (fgets(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_18.c:36; printLine(data); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fgets_18.c:41
- 结论: 对fgets返回值的错误检查：fgets返回NULL表示失败，但代码将返回值与0比较（<0），导致当fgets失败时，条件不满足，错误地认为成功，后续仍使用未成功读入的数据（dataBuffer初始为空字符串），可能造成逻辑错误或信息泄露。
- D验证: stage_c_preserved / ver_bb737e6f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 55. hyp_path_5edfc7c3aa98

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_17.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使fgetws调用失败，例如通过关闭stdin或发送EOF。
- 触发路径: if (fgetws(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_17.c:37; printWLine(data); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_17.c:42
- 结论: fgetws函数返回指针，失败返回NULL，但代码检查返回值是否小于0，导致错误检查失效。若fgetws失败，条件为假，程序不会进入错误处理分支，而是继续执行printWLine。虽然dataBuffer已初始化为空宽字符串，但fgetws失败后其内容未定义（可能仍为空，也可能被部分修改），导致未定义行为。
- D验证: stage_c_preserved / ver_aaaec631
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 56. hyp_path_457faedd6b5b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_17.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateMutexA fails due to resource exhaustion or other reasons
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_17.c:33; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } // incorrect check, should be NULL @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_17.c:37; CloseHandle(hMutex); // called with NULL if CreateMutexA failed @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_17.c:43
- 结论: CWE-253: Incorrect Check of Function Return Value. CreateMutexA returns NULL on failure, but the code checks for INVALID_HANDLE_VALUE. If CreateMutexA fails, subsequent CloseHandle(hMutex) will be called with NULL, leading to undefined behavior (likely program crash).
- D验证: confirmed / ver_6fc1120e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 57. hyp_path_29c9a00766e5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_17.c:43
- 漏洞类型: CWE-253, CWE-754
- CWE: CWE-253; CWE-754
- 风险等级: P0
- 触发条件: 攻击者可能通过耗尽系统资源等方式导致CreateMutexW失败，但具体利用条件取决于环境，通常难以直接控制。
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_17.c:32-36; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_17.c:37; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_17.c:43
- 结论: 调用CreateMutexW后，错误地将返回值与INVALID_HANDLE_VALUE比较，而实际失败返回NULL，导致NULL句柄传入CloseHandle，可能引发程序崩溃或未定义行为。
- D验证: confirmed / ver_0aad5180
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 58. hyp_path_4f7169ede054

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_12.c:58
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致标准输入流错误或EOF
- 触发路径: if (fgetws(data, 100, stdin) < 0) @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_12.c:36; printWLine(data); @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_12.c:58
- 结论: fgetws返回值检查错误：代码检查fgetws返回值是否小于0，但fgetws失败时返回NULL（0），因此当fgetws失败时错误条件不成立，导致错误未被检测。虽然data缓冲区已初始化为空字符串，影响较低，但API契约被违反，构成CWE-253漏洞。
- D验证: stage_c_preserved / ver_2386953a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 59. hyp_path_4dcf2eb4856e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_08.c:54
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin的读取状态（如关闭stdin或发送EOF），但非必需；漏洞本身是API misuse，无需直接攻击者输入。
- 触发路径: if (fgetws(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_08.c:49; printLine("fgetws failed!"); exit(1); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_08.c:50-51; printWLine(data); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_08.c:54
- 结论: fgetws函数返回值被错误检查：代码使用`if (fgetws(data, 100, stdin) < 0)`，但fgetws返回wchar_t*类型，成功返回指针，失败返回NULL。检查`<0`无法正确捕获失败情况（NULL不小于0），导致若fgetws失败，程序继续使用已初始化为空字符串的data缓冲区，虽立即影响较低，但违反API契约，后续可能产生未定义行为或安全风险。符合CWE-253。
- D验证: stage_c_preserved / ver_9bf60eaa
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 60. hyp_path_01fbfc0e8bb0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_11.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: An attacker may cause fgetws to fail (e.g., by closing stdin or sending EOF) to demonstrate the incorrect check, but the program continues without proper failure handling.
- 触发路径: if (fgetws(data, 100, stdin) < 0) @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_11.c:36; printLine("fgetws failed!"); exit(1); @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_11.c:37-38
- 结论: The code incorrectly checks the return value of fgetws by comparing it with < 0, while the function returns NULL on failure. This violates the API contract (CWE-253) and the error handler is never executed because the condition fgetws(...) < 0 is always false for typical return values (non-negative on success, NULL which is 0 on failure). The buffer is initialized to an empty string, so the immediate impact is limited, but the violation is real and the error path is dead code.
- D验证: stage_c_preserved / ver_bd488d63
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 61. hyp_path_17196f258554

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_02.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致 fgetws 读取失败（如提前关闭 stdin 或提供无效输入流），使得返回 NULL。
- 触发路径: if (fgetws(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_02.c:36; printWLine(data); // 当 fgetws 失败时，data 保持为空字符串，无安全影响但违反契约 @ 同文件第39-41行
- 结论: fgetws 函数返回值被错误地检查为小于0，应检查是否为 NULL。尽管 data 缓冲区已初始化为空字符串，降低了未初始化数据的安全影响，但错误的返回值检查违反了 CWE-253 的 API 契约，构成代码缺陷。
- D验证: stage_c_preserved / ver_7501441b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 62. hyp_path_05c3f7668411

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_01.c:39
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，导致fgetws失败（例如提前关闭流或发送EOF）
- 触发路径: if (fgetws(data, 100, stdin) < 0) { printLine("fgetws failed!"); exit(1); } printWLine(data); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_01.c:34-40
- 结论: fgetws返回值检查错误：使用<0判断失败，但fgetws在失败时返回NULL，应使用==NULL检查。此错误导致fgetws失败时不被检测，后续使用空字符串数据（缓冲区已初始化为空字符串，但未读取用户输入）。
- D验证: stage_c_preserved / ver_9f158d2e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 63. hyp_path_5a4d155d7d8c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_03.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使fgetws返回NULL，例如关闭标准输入流或提供无效输入。
- 触发路径: if (fgetws(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_03.c:36
- 结论: fgetws的返回值检查错误：fgetws失败时返回NULL，但代码检查是否小于0，导致错误被忽略。虽然data已初始化为空字符串，但返回值检查不正确，违反CWE-253。
- D验证: stage_c_preserved / ver_e3f7dcb7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 64. hyp_path_036f91162fba

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_04.c:47
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使fgetws失败（例如关闭stdin、发送EOF或通过环境干扰输入流）
- 触发路径: if (fgetws(data, 100, stdin) < 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_04.c:42; printWLine(data); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_04.c:47
- 结论: 函数fgetws的返回值检查错误：使用'<0'与指针比较，正确应检查是否为NULL。这导致fgetws失败时错误未被处理，后续使用data可能包含未定义内容（尽管已初始化为空字符串，但标准规定失败时数组内容不确定）。
- D验证: stage_c_preserved / ver_588d9f00
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 65. hyp_path_1868389309a4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_05.c:47
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fgetws调用失败（输入流错误或EOF）
- 触发路径: if (fgetws(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_05.c:42
- 结论: fgetws返回值检查错误：使用<0而不是==NULL，导致fgetws失败时条件永远为假（除非编译器特殊行为），错误处理代码不会被执行，程序可能继续使用内容不确定的缓冲区。
- D验证: stage_c_preserved / ver_c79003d2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 66. hyp_path_a3498369e86e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_07.c:46
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序可能遇到fgetws失败的情况（如输入结束或错误），此时错误检查无效，不会进入错误处理分支。
- 触发路径: if (fgetws(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_07.c:41
- 结论: 对fgetws的返回值进行了错误检查：fgetws返回指针，但代码使用<0与整数比较，正确应为检查NULL。这违反了CWE-253，导致错误检查无效，无法正确检测fgetws失败，可能忽略错误并继续使用未初始化的数据。
- D验证: stage_c_preserved / ver_1bda4538
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 67. hyp_path_36f128075947

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_06.c:41
- 漏洞类型: null_deref
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致fgetws调用失败（例如关闭标准输入流或提供无效输入）。
- 触发路径: if (fgetws(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_06.c:41
- 结论: 函数fgetws的返回值被错误检查：代码将fgetws的返回值与0比较（<0），而fgetws失败时返回NULL（空指针），不是负数。因此，即使fgetws失败，条件也可能不成立，导致程序继续执行后续代码，但dataBuffer已初始化为空字符串，实际影响较低。
- D验证: stage_c_preserved / ver_d65ca9d9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 68. hyp_path_277cbca93d31

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_09.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使标准输入流处于错误状态或触发EOF
- 触发路径: if (fgetws(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_09.c:36; printWLine(data); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_09.c:41
- 结论: fgetws返回值检查错误：条件`fgetws(data, 100, stdin) < 0`永远不会为真（fgetws返回指针或NULL，NULL转换为整型为0，不小于0），导致fgetws失败（返回NULL）时错误处理分支不会执行，违背API contract。
- D验证: stage_c_preserved / ver_6b608c5d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 69. hyp_path_12e2420a6cd8

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_10.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可能通过关闭stdin或发送EOF导致fgetws失败，但错误检查无法捕获失败，exit(1)永不执行。无直接安全影响，但API misuse明确存在。
- 触发路径: if (fgetws(data, 100, stdin) < 0) { printLine("fgetws failed!"); exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_10.c:36-37
- 结论: 在fgetws函数返回值检查中，错误地使用了'< 0'比较，而fgetws失败时返回NULL（不是负数），导致返回值检查不正确（CWE-253）。虽然后续存在exit(1)处理，但检查逻辑本身违反API contract，且错误处理分支不可达。
- D验证: stage_c_preserved / ver_93bed565
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 70. hyp_path_1bdc69580afa

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_13.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使fgetws调用失败（例如关闭stdin或提供EOF）
- 触发路径: if (fgetws(data, 100, stdin) < 0) { printLine("fgetws failed!"); exit(1); } @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_13.c:36
- 结论: fgetws返回类型为wchar_t*，失败返回NULL，代码错误地将其与0比较（<0），导致当fgetws失败返回NULL时条件为假，错误处理被跳过，程序可能继续使用未正确初始化的数据。缓冲区虽初始化为空字符串，但违反CWE-253 API契约，属于错误返回值检查漏洞。
- D验证: stage_c_preserved / ver_3d983420
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 71. hyp_path_357539209e9e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_14.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使 fgetws 调用失败（例如关闭 stdin 或发送 EOF）
- 触发路径: if (fgetws(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_14.c:36; printWLine(data); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_14.c:41
- 结论: 函数 fgetws 的返回值检查错误：fgetws 返回 wchar_t*，失败时返回 NULL，但代码使用 '< 0' 进行比较，导致错误处理分支不会执行，违反 API contract，构成 CWE-253。
- D验证: stage_c_preserved / ver_92526895
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 72. hyp_path_19c00c180004

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_15.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使 fgetws 失败（例如通过关闭标准输入或输入 EOF）
- 触发路径: if (fgetws(data, 100, stdin) < 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_15.c:37
- 结论: 对 fgetws 返回值的错误检查：使用 'if (fgetws(data, 100, stdin) < 0)' 而非 'if (fgetws(data, 100, stdin) == NULL)'，导致函数失败时错误处理不被执行。虽然当前路径后续仅调用 printWLine 打印数据，无直接安全后果，但违反了 CWE-253 关于正确检查函数返回值的要求。
- D验证: stage_c_preserved / ver_37b920b2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 73. hyp_path_228df830809f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_16.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fgetws调用失败（例如输入流结束或错误）
- 触发路径: if (fgetws(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_16.c:36
- 结论: 函数fgetws的返回值检查不正确：fgetws失败时返回NULL，但代码检查返回值是否小于0。由于NULL（0）< 0为假，错误处理块永远不会执行，导致函数调用失败时未正确处理，违反CWE-253（函数返回值检查不正确）。
- D验证: stage_c_preserved / ver_d9aa7850
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 74. hyp_path_1c1981e24437

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_18.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致fgetws调用失败，例如关闭stdin或提供无效输入。
- 触发路径: if (fgetws(data, 100, stdin) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_18.c:36; printWLine(data); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fgets_18.c:41
- 结论: fgetws函数返回值检查错误：fgetws失败时返回NULL，但代码使用<0比较，导致错误路径无法执行。后续使用未定义内容的data缓冲区，可能输出异常数据或泄露敏感信息。
- D验证: stage_c_preserved / ver_562b3121
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 75. hyp_path_89ac12af0321

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_12.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateMutexW调用失败（例如系统资源不足），返回NULL。
- 触发路径: HANDLE hMutex = NULL; hMutex = CreateMutexW(NULL, FALSE, NULL); /* NOTE: If CreateMutexW() failed, the return value will be NULL, but we are checking to see if the return value is INVALID_HANDLE_VALUE */ @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_12.c:31-35; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } /* We'll leave out most of the implementation ... */ CloseHandle(hMutex); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_12.c:40-44
- 结论: 在CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_12.c的第一个分支中，CreateMutexW失败返回NULL，但代码将其与INVALID_HANDLE_VALUE比较，导致错误处理（exit(1)）不触发，程序继续执行并调用CloseHandle(hMutex)，传入NULL句柄，可能引发未定义行为或进程崩溃，构成CWE-253漏洞。
- D验证: confirmed / ver_eae81893
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 76. hyp_path_15a8054dcfb4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_12.c:57
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够使CreateMutexA调用失败（例如通过耗尽系统资源）
- 触发路径: void CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_12_case0() { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_12.c:27; if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_12.c:28; { HANDLE hMutex = NULL; hMutex = CreateMutexA(NULL, FALSE, NULL); /* NOTE: If CreateMutexA() failed, the return value will be NULL, but we are checking to see if the return value is INVALID_HANDLE_VALUE */ @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_12.c:31-35; /* We'll leave out most of the implementation since it has nothing to do with the CWE * and since the checkers are looking for certain function calls anyway */ CloseHandle(hMutex); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_12.c:42
- 结论: 在错误检查分支中，CreateMutexA失败时返回NULL，但代码检查INVALID_HANDLE_VALUE（而非NULL），导致失败检测失败；随后CloseHandle(NULL)调用导致未定义行为。
- D验证: confirmed / ver_72b0b915
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 77. hyp_path_d875b743147e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_08.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 系统资源不足导致CreateMutexA失败返回NULL
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_08.c:55; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } // 错误检查，应为hMutex == NULL @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_08.c:55; CloseHandle(hMutex); // 若为NULL，CloseHandle返回错误但不崩溃 @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_08.c:55
- 结论: CreateMutexA失败时返回NULL，但代码错误地检查INVALID_HANDLE_VALUE，导致未捕获失败状态；后续CloseHandle(hMutex)在hMutex为NULL时传递无效句柄，违反CWE-253要求正确检查函数返回值。
- D验证: confirmed / ver_9e0f2770
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 78. hyp_path_66316e20c127

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_11.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateMutexA 调用可能失败（例如系统资源不足）。
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_11.c:32-33; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_11.c:42; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_11.c:44
- 结论: CreateMutexA 调用后，返回值检查错误：函数失败返回 NULL，但代码将其与 INVALID_HANDLE_VALUE 比较，导致错误条件未正确捕获。如果 CreateMutexA 失败，hMutex 为 NULL，后续 CloseHandle(hMutex) 可能传入 NULL 句柄，导致未定义行为或崩溃。
- D验证: confirmed / ver_f0d2ea58
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 79. hyp_path_7b946657e1d2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_08.c:55
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateMutexW可能因系统资源不足而失败，无需用户控制输入。
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_08.c:44-48; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_08.c:55; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_08.c:55
- 结论: 对CreateMutexW的返回值使用了错误的sentinel值（INVALID_HANDLE_VALUE而非NULL），导致无法正确检测函数失败，可能使用空句柄并引发未定义行为。
- D验证: confirmed / ver_89201efc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 80. hyp_path_e6e944e8c648

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_11.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateMutexW因资源不足或其他原因失败，返回NULL
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ 42行; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ 42行后检查处; CloseHandle(hMutex); @ 44行
- 结论: 对CreateMutexW的返回值检查错误：期望检查是否返回NULL（失败），但实际检查是否等于INVALID_HANDLE_VALUE，导致当CreateMutexW失败返回NULL时，程序继续使用NULL句柄调用CloseHandle，可能造成未定义行为或崩溃。
- D验证: confirmed / ver_3f69aa7d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 81. hyp_path_f570f2e51e91

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_01.c:40
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 无需攻击者输入，由程序逻辑自身缺陷导致，但资源耗尽可能触发 CreateMutexA 失败。
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ L29; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ L34-35; CloseHandle(hMutex); @ L38-39
- 结论: CreateMutexA 失败时返回 NULL，但代码错误地检查是否等于 INVALID_HANDLE_VALUE，导致错误处理失效。当 CreateMutexA 失败时，程序不会退出，而是将 NULL 句柄传递给 CloseHandle，虽然 CloseHandle(NULL) 通常不会导致严重问题，但违反了函数返回值检查的正确性，符合 CWE-253。
- D验证: confirmed / ver_561c21e5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 82. hyp_path_4d70c4b7a8ed

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_02.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者可能通过耗尽系统资源或竞争条件使CreateMutexA失败，但不需要直接控制输入
- 触发路径: HANDLE hMutex = NULL; hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_02.c:31-32; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_02.c:36; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_02.c:42
- 结论: CreateMutexA返回值检查错误：调用失败时返回NULL，但代码与INVALID_HANDLE_VALUE比较，导致失败时未正确退出，后续使用NULL句柄调用CloseHandle，可能引发程序崩溃或未定义行为。
- D验证: confirmed / ver_e523c8bb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 83. hyp_path_6e9d0b507431

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_03.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者可能导致系统资源耗尽，使CreateMutexA返回NULL
- 触发路径: HANDLE hMutex = NULL; hMutex = CreateMutexA(NULL, FALSE, NULL); ... if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } ... CloseHandle(hMutex); @ CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_03.c:31-42
- 结论: CreateMutexA调用失败返回NULL，但代码错误地检查INVALID_HANDLE_VALUE，导致失败时未能正确识别，后续可能使用NULL句柄调用CloseHandle，违反API contract。
- D验证: confirmed / ver_1c1871e2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 84. hyp_path_8ebea3fffc39

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_04.c:48
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateMutexA函数因系统资源不足等原因失败，返回NULL。
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_04.c:37; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_04.c:42; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_04.c:48
- 结论: 对CreateMutexA返回值的检查使用了错误的sentinel值INVALID_HANDLE_VALUE，而该API失败时返回NULL。这导致如果CreateMutexA失败，程序错误地认为成功，并可能使用NULL句柄进行后续操作（如CloseHandle），尽管CloseHandle(NULL)安全，但其他潜在操作可能导致未定义行为。
- D验证: confirmed / ver_b625d2a9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 85. hyp_path_ad19a8b4e263

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_05.c:48
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateMutexA因系统资源不足等内部原因失败，无需外部输入
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_05.c:37-38; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_05.c:42; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_05.c:48
- 结论: CreateMutexA调用后错误地检查返回值：当CreateMutexA失败时返回NULL，但代码将返回值与INVALID_HANDLE_VALUE比较，导致失败时未被检测到，后续可能使用无效句柄(NULL)调用CloseHandle，引发未定义行为或资源泄漏。
- D验证: confirmed / ver_ea5f8f13
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 86. hyp_path_ca5619a62f7a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_06.c:47
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 系统资源不足等环境因素可能导致CreateMutexA失败，但攻击者无法直接控制此调用
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_06.c:40; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_06.c:41; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_06.c:47
- 结论: CreateMutexA失败时返回NULL，但代码错误地检查是否等于INVALID_HANDLE_VALUE，导致错误处理遗漏，可能引发后续CloseHandle(NULL)调用。尽管CloseHandle(NULL)不会导致崩溃，但违反了正确检查函数返回值的API契约，属于CWE-253缺陷。
- D验证: confirmed / ver_93bdf536
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 87. hyp_path_13f58bf0e4d2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_07.c:47
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够导致系统资源耗尽或其他条件使CreateMutexA失败
- 触发路径: HANDLE hMutex = NULL; hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_07.c:36-37; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_07.c:41; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_07.c:47
- 结论: 在CreateMutexA调用后，错误地检查返回值为INVALID_HANDLE_VALUE而非NULL，导致当函数失败返回NULL时，错误检查失效，进而使用NULL句柄调用CloseHandle，可能导致程序崩溃或未定义行为。
- D验证: confirmed / ver_70aff5e0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 88. hyp_path_9616083aa9ce

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_09.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateMutexA因系统资源不足或其他原因失败
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_09.c:35; if (hMutex == INVALID_HANDLE_VALUE) @ CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_09.c:36; CloseHandle(hMutex); @ CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_09.c:42
- 结论: CreateMutexA失败时返回NULL，但代码错误地使用INVALID_HANDLE_VALUE进行检查，导致错误处理逻辑失效。后续CloseHandle(hMutex)可能传入NULL句柄，引发未定义行为或程序崩溃。
- D验证: confirmed / ver_64f90133
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 89. hyp_path_218a8112eaa5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_10.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateMutexA可能失败（例如系统资源不足）
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_10.c:42; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_10.c:36; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_10.c:42
- 结论: 代码错误地检查CreateMutexA的返回值：失败时返回NULL，但代码检查是否等于INVALID_HANDLE_VALUE，导致错误处理被绕过。后续CloseHandle可能以NULL句柄调用，导致未定义行为。
- D验证: confirmed / ver_247cbe23
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 90. hyp_path_c615d6dd25f3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_13.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateMutexA 调用失败（如系统资源耗尽）
- 触发路径: HANDLE hMutex = NULL; hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_13.c:31-35; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_13.c:36-38; CloseHandle(hMutex); // hMutex 可能是 NULL @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_13.c:42
- 结论: CreateMutexA 失败时返回 NULL，但代码检查 hMutex == INVALID_HANDLE_VALUE，导致错误检查遗漏；若 CreateMutexA 失败，将使用 NULL 句柄调用 CloseHandle，可能引发未定义行为或程序崩溃。
- D验证: confirmed / ver_48aafdc6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 91. hyp_path_d35f85df82dc

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_14.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 系统资源不足导致CreateMutexA失败，返回NULL，但代码错误地检查INVALID_HANDLE_VALUE，导致错误未被正确处理。
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_14.c:32; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_14.c:36; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_14.c:42
- 结论: 函数CreateMutexA返回NULL表示失败，但代码将其与INVALID_HANDLE_VALUE比较，导致错误检查失败，使得在CreateMutexA失败时程序继续执行，并可能对无效句柄调用CloseHandle，虽然后者安全，但违反了API contract，可能导致后续对互斥体的操作失败或未定义行为。
- D验证: confirmed / ver_a6aa4cf0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 92. hyp_path_32c7929740fb

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_15.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够导致系统资源耗尽或创建互斥体失败
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ path_32c7929740fb:43; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ path_32c7929740fb:37; CloseHandle(hMutex); @ path_32c7929740fb:43
- 结论: 对CreateMutexA函数返回值检查不正确，函数失败时返回NULL，但代码错误地检查INVALID_HANDLE_VALUE，导致在失败时使用NULL句柄调用CloseHandle，可能引发程序崩溃或未定义行为。
- D验证: confirmed / ver_a2523da5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 93. hyp_path_c457046c730b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_16.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够通过耗尽系统资源等方式导致CreateMutexA失败
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ 31; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ 36; CloseHandle(hMutex); @ 42
- 结论: CreateMutexA返回NULL表示失败，但代码错误地检查INVALID_HANDLE_VALUE，导致失败时误认为成功，随后使用NULL句柄调用CloseHandle可能引发崩溃或未定义行为。
- D验证: confirmed / ver_4e60681c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 94. hyp_path_ec273ed2b2f7

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_18.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateMutexA调用失败（资源不足、权限不足等）
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_18.c:31; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_18.c:36; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_18.c:42
- 结论: CreateMutexA失败时返回NULL，但代码将其返回值与INVALID_HANDLE_VALUE比较，导致错误检查失效。若CreateMutexA失败，后续CloseHandle将使用NULL句柄，可能导致程序崩溃或未定义行为。
- D验证: confirmed / ver_d029c357
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 95. hyp_path_52dae54cb03e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_01.c:40
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateMutexW因系统资源不足或权限问题失败，返回NULL。
- 触发路径: HANDLE hMutex = NULL; hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_01.c:29-33; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_01.c:34-36; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_01.c:38-42
- 结论: CreateMutexW失败时返回NULL，但代码错误地检查是否等于INVALID_HANDLE_VALUE，导致错误处理（exit）未被触发，进而将NULL句柄传递给CloseHandle。虽然CloseHandle(NULL)本身不会导致崩溃，但违反了正确检查函数返回值的API合约，属于CWE-253漏洞。
- D验证: confirmed / ver_aba2832a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 96. hyp_path_86ec78bfcb4a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_02.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 无额外攻击者输入条件；程序运行时系统资源不足导致CreateMutexW失败即可触发
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_02.c:32; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_02.c:36-38; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_02.c:42
- 结论: 对CreateMutexW的返回值检查错误：该函数失败时返回NULL，但代码中使用INVALID_HANDLE_VALUE进行比较。若CreateMutexW失败，hMutex为NULL，不满足hMutex == INVALID_HANDLE_VALUE，导致错误处理代码exit(1)不会执行，后续CloseHandle(hMutex)将以NULL句柄调用，违反Win32 API合约，可能导致资源未正确释放或后续操作使用无效句柄。
- D验证: confirmed / ver_4d405c9a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 97. hyp_path_e643100319d4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_03.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateMutexW失败（返回NULL）
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ 42行; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ 36-38行; CloseHandle(hMutex); @ 41行
- 结论: 调用CreateMutexW后，错误地检查返回值是否为INVALID_HANDLE_VALUE，而实际失败时返回NULL，导致未正确处理失败情况。后续直接使用hMutex调用CloseHandle，虽然CloseHandle(NULL)安全，但违反API contract，可能导致资源未正确初始化或后续操作未按预期执行。
- D验证: confirmed / ver_d003ebcb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 98. hyp_path_b8544d5879e2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_04.c:48
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 无外部输入，漏洞由代码固有逻辑错误导致
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_04.c:48; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_04.c:42; CloseHandle(hMutex); // 若hMutex为NULL，行为未定义 @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_04.c:48
- 结论: 函数CreateMutexW返回NULL表示失败，代码错误地将返回值与INVALID_HANDLE_VALUE比较，导致失败时未进入错误处理分支。若CreateMutexW失败返回NULL，则CloseHandle(NULL)可能引发未定义行为。
- D验证: confirmed / ver_7e29be33
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 99. hyp_path_2e53520a4d44

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_05.c:48
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者可通过消耗系统资源（如创建大量互斥体）使CreateMutexW失败，但实际场景中可利用性较低
- 触发路径: HANDLE hMutex = NULL; hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_05.c:37-41; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_05.c:42-46; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_05.c:46-50
- 结论: 对CreateMutexW的返回值进行了错误的检查：函数失败时返回NULL，但代码将其与INVALID_HANDLE_VALUE比较。若CreateMutexW失败，程序不会正确退出，导致后续使用无效句柄调用CloseHandle(NULL)，这可能引发错误或未定义行为。
- D验证: confirmed / ver_c6f34cd9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 100. hyp_path_5aace8511b89

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_06.c:47
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者可能通过耗尽系统资源导致CreateMutexW失败，但无直接外部输入控制。
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_06.c:38; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_06.c:41; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_06.c:47
- 结论: CreateMutexW失败时返回NULL，但代码错误地检查是否等于INVALID_HANDLE_VALUE，导致失败时不会退出，继续使用NULL句柄调用CloseHandle，违反CWE-253。
- D验证: confirmed / ver_0408d291
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 101. hyp_path_197a92f667b5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_09.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateMutexW调用失败（例如系统资源不足）
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_09.c:42; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_09.c:36; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_09.c:42
- 结论: 代码错误地检查了CreateMutexW的返回值。CreateMutexW失败时返回NULL，而非INVALID_HANDLE_VALUE。因此，若CreateMutexW失败，条件`hMutex == INVALID_HANDLE_VALUE`为假，不会执行exit(1)，程序继续执行CloseHandle(hMutex)，此时hMutex为NULL，传递给CloseHandle可能导致未定义行为（如访问冲突）。
- D验证: confirmed / ver_88a4efee
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 102. hyp_path_db0276828d0c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_07.c:47
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者可能导致系统资源不足，使得CreateMutexW返回NULL；或通过其他方式使CreateMutexW失败
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_07.c:37; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_07.c:41; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_07.c:47
- 结论: 函数CreateMutexW失败时返回NULL，但代码中错误地使用INVALID_HANDLE_VALUE进行比较，导致错误无法被检测。当CreateMutexW失败时，hMutex为NULL，但条件hMutex == INVALID_HANDLE_VALUE为假，程序继续执行CloseHandle(hMutex)，传入NULL句柄可能导致程序崩溃或未定义行为。
- D验证: confirmed / ver_67c9b99b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 103. hyp_path_2ac85ac2bce1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_10.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateMutexW执行失败（例如系统资源不足），返回NULL而非INVALID_HANDLE_VALUE
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_10.c:42; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_10.c:36; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_10.c:42
- 结论: CreateMutexW失败时返回NULL，但代码错误地与INVALID_HANDLE_VALUE比较，导致错误处理被绕过，后续对失败互斥体进行CloseHandle调用，可能引发未预期行为或资源错误使用，属于CWE-253错误检查函数返回值。
- D验证: confirmed / ver_33c78a64
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 104. hyp_path_0b310d29144f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_13.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: CreateMutexW因系统资源不足等原因失败，返回NULL
- 触发路径: HANDLE hMutex = NULL; hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_13.c:31-35; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_13.c:36-38; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_13.c:40-44
- 结论: 对CreateMutexW的返回值检查错误：失败返回NULL，但代码检查了INVALID_HANDLE_VALUE，导致当CreateMutexW失败时，后续会使用NULL句柄调用CloseHandle，违反正确API使用规范，可能引发未定义行为或资源泄漏。
- D验证: confirmed / ver_f24b916d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 105. hyp_path_19a6f8b4ddf8

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_14.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者可能通过耗尽系统资源导致CreateMutexW失败
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_14.c:42; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_14.c:36-37; CloseHandle(hMutex); @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_14.c:40-44
- 结论: CreateMutexW失败时返回NULL，但代码错误地检查INVALID_HANDLE_VALUE，导致对失败情况的错误处理。若CreateMutexW失败（返回NULL），则不会触发exit(1)，而是继续执行CloseHandle(NULL)，可能导致未定义行为或资源泄漏。
- D验证: confirmed / ver_a2acb0a3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 106. hyp_path_9cebdc7ca29c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_15.c:43
- 漏洞类型: CWE-253, CWE-754
- CWE: CWE-253; CWE-754
- 风险等级: P0
- 触发条件: CreateMutexW失败（例如系统资源耗尽）
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ L43; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ L37-39; CloseHandle(hMutex); @ L44-45
- 结论: CreateMutexW失败时返回NULL，但代码错误地检查返回值是否等于INVALID_HANDLE_VALUE，导致失败时未触发exit()，随后CloseHandle(NULL)可能导致程序崩溃或未定义行为。
- D验证: confirmed / ver_834dcc1e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 107. hyp_path_3fdda8584961

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_16.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者可能通过资源耗尽或竞争条件导致CreateMutexW失败，但无法直接控制返回值
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ L32; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ L36; CloseHandle(hMutex); @ L42
- 结论: 对CreateMutexW的返回值检查错误：函数失败时返回NULL，但代码检查是否等于INVALID_HANDLE_VALUE，导致失败时未处理，后续使用NULL句柄调用CloseHandle。虽然CloseHandle(NULL)在Windows上不会崩溃，但违反了API契约的正确使用模式，可能掩盖错误状态并导致资源泄漏或未授权访问。
- D验证: confirmed / ver_799d334a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 108. hyp_path_646a4e669e8d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_18.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者可能通过耗尽系统资源导致 CreateMutexW 失败，或利用环境条件使内核对象创建失败
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_18.c:42; if (hMutex == INVALID_HANDLE_VALUE) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_18.c:36; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_18.c:42
- 结论: 调用 CreateMutexW 后错误地检查返回值是否为 INVALID_HANDLE_VALUE，但实际失败返回 NULL，导致即使创建失败也继续执行后续代码（如 CloseHandle），可能对无效句柄进行操作，违反 API 契约。
- D验证: confirmed / ver_466575a5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 109. hyp_path_0b78afa95598

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_17.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者无法控制输入，但程序依赖于外部文件系统的状态，可能导致remove()成功或失败，触发错误的返回值检查逻辑。
- 触发路径: if (REMOVE("removemecase0.txt") == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_17.c:37; printLine("remove failed!"); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_17.c:38
- 结论: 错误检查remove()函数的返回值：当remove()成功（返回0）时，错误地打印失败信息；当remove()失败（返回非0）时，未做任何处理。违反了CWE-253（不正确的函数返回值检查）。
- D验证: stage_c_preserved / ver_652e47be
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 110. hyp_path_5ffe2cd4db82

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_17.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 代码中包含错误的返回值检查逻辑，无外部输入依赖
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_17.c:42-46
- 结论: rename()函数调用后对返回值的检查逻辑颠倒：当rename()返回0（成功）时，程序打印'rename failed!'，导致错误处理与实际状态不符，违反了CWE-253。
- D验证: stage_c_preserved / ver_204e5a23
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 111. hyp_path_91432c6a0977

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_12.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够成功删除目标文件（例如文件存在且可被删除），使得 remove() 返回 0，从而触发错误分支。
- 触发路径: if (REMOVE("removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_12.c:34-38
- 结论: 函数 remove() 的返回值检查颠倒：当 remove 成功返回 0 时，代码错误地打印“remove failed!”，导致逻辑错误。攻击者可利用此漏洞，在成功删除文件时触发错误处理路径，可能造成信息泄露或错误行为。
- D验证: stage_c_preserved / ver_b7f378c2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 112. hyp_path_5ae81e660c3c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_12.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响系统环境，如通过文件权限操作、磁盘空间耗尽等方式使 rename() 返回非零（失败），即使文件名为常量。
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_12.c:39-42; if (RENAME(OLD_CASE1_FILE_NAME, NEW_CASE1_FILE_NAME) != 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_12.c:47-50
- 结论: 函数 rename() 的返回值检查错误：当 rename() 返回 0（成功）时，错误地输出 'rename failed!'，表明开发人员误解了返回值的含义。尽管文件名为硬编码常量，攻击者仍可通过影响系统环境（如修改文件权限、耗尽磁盘空间等）间接导致 rename() 失败，从而触发错误的分支逻辑。虽然第二个分支正确检查了非零返回值，但第一个分支的错误检查可能掩盖真实失败，导致安全风险。属于 CWE-253 不正确检查函数返回值漏洞。
- D验证: stage_c_preserved / ver_ce8c526c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 113. hyp_path_6d02b8ce1ca6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_08.c:49
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 无外部输入控制，但函数调用本身逻辑错误
- 触发路径: if (REMOVE("removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_08.c:49
- 结论: 代码对remove()函数的返回值进行了错误检查：当remove()成功返回0时，代码误认为失败并打印错误消息。这违反了CWE-253中关于正确检查函数返回值的要求，可能导致逻辑错误和不可预期的行为。
- D验证: stage_c_preserved / ver_c1110b5c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 114. hyp_path_bec8ca7422a8

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_11.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部条件，函数被调用时使用固定常量参数
- 触发路径: static void case11() { if(globalReturnsFalse()) { /*死代码*/ ... if (RENAME(...) != 0) { ... } } else { /*实际执行路径，未提供代码但推断无检查*/ } } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_11.c:53-57
- 结论: 存在CWE-253漏洞：在case11函数中，对rename()返回值的检查位于死代码分支（globalReturnsFalse()恒为false导致不执行），实际执行路径（else分支）未检查rename()返回值，违反了API契约。
- D验证: stage_c_preserved / ver_28f8c33d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 115. hyp_path_7fcdbbd087e3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_11.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 无外部输入依赖，函数直接调用remove
- 触发路径: if (REMOVE("removemecase0.txt") == 0) { printLine("remove failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_11.c:36
- 结论: 函数remove()的返回值检查错误：当remove返回0（成功）时，代码却打印'remove failed!'，导致成功时误报失败，失败时静默忽略。违反CWE-253规范。
- D验证: stage_c_preserved / ver_2495dfb4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 116. hyp_path_199117c79911

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_08.c:54
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 无外部输入控制，函数staticReturnsTrue()始终返回1，因此总是执行该路径。
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_08.c:54
- 结论: 在调用rename()后，错误地检查返回值：当rename()成功时（返回0），错误地打印了失败信息；当rename()失败时（返回非0），未进行任何错误处理。这违反了API contract，属于对函数返回值的错误检查。
- D验证: stage_c_preserved / ver_e5d1c03d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 117. hyp_path_fbec9e53bd28

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_11.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者可能通过控制文件系统的状态（如目标文件已存在、权限不足）使rename()成功或失败，从而触发错误的逻辑分支。
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_11.c:41
- 结论: 对rename()函数的返回值检查错误：当rename成功时（返回0），错误地打印"rename failed!"；而当rename失败时（返回非零），未进行任何错误处理，违反了CWE-253：不正确的函数返回值检查。
- D验证: stage_c_preserved / ver_741a916d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 118. hyp_path_61ca595d67e2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_01.c:34
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 无特定攻击者控制输入；任何路径调用到此代码都会触发错误的返回值检查。
- 触发路径: if (REMOVE("removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_01.c:34
- 结论: 对remove函数的返回值检查反了：当remove成功（返回0）时，打印失败信息；当remove失败（返回非零）时，不产生任何反馈。这违反了API contract，可能掩盖错误，导致后续逻辑错误或安全弱化。
- D验证: stage_c_preserved / ver_99e5a923
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 119. hyp_path_c03460f463a1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_02.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: N/A
- 触发路径: if (REMOVE("removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_02.c:36
- 结论: 函数remove()的返回值检查错误：成功时返回0，但代码将返回值等于0视为失败并打印错误信息。违反CWE-253（不正确的函数返回值检查）。
- D验证: stage_c_preserved / ver_107a96df
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 120. hyp_path_3925ce7347b4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_03.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特殊前提，任何执行该代码的路径均可触发。
- 触发路径: if (REMOVE("removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_03.c:36
- 结论: 在删除文件时错误地检查remove()的返回值，将成功返回值0误判为失败，导致操作结果误报。
- D验证: stage_c_preserved / ver_da9f90a0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 121. hyp_path_2c0503c79fcd

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_04.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 静态条件 staticTrue 始终为真，确保漏洞路径可达
- 触发路径: if (REMOVE("removemecase0.txt") == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_04.c:42; printLine("remove failed!"); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_04.c:44
- 结论: 函数 remove 的返回值检查逻辑错误：当 remove 返回 0（成功）时，代码错误地将其视为失败条件并输出错误信息；而实际应检查返回值非 0 表示失败。
- D验证: stage_c_preserved / ver_503002fe
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 122. hyp_path_23af2d889265

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_05.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: remove()函数成功执行并返回0
- 触发路径: if (REMOVE("removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_05.c:42
- 结论: 函数remove()的返回值检查逻辑错误：当remove()成功（返回0）时，错误地打印'remove failed!'，导致错误处理颠倒。
- D验证: stage_c_preserved / ver_103dc0c3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 123. hyp_path_a5a986687c89

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_06.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 程序执行到此代码路径，且 REMOVE 函数正常返回。
- 触发路径: if (REMOVE("removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_06.c:41
- 结论: 代码在调用 REMOVE 后，错误地将返回值等于 0（成功）视为失败并打印 'remove failed!'，违反了正确处理返回值的契约。
- D验证: stage_c_preserved / ver_e196ba07
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 124. hyp_path_1acbdc163d9b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_07.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 程序执行到该代码路径，并调用remove()。
- 触发路径: if (REMOVE("removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_07.c:41
- 结论: 代码中对remove()函数返回值的检查逻辑反转：成功时返回0，但条件为真时打印失败，导致误报或漏报。
- D验证: stage_c_preserved / ver_ee227a23
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 125. hyp_path_0af30400e7b7

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_10.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: N/A
- 触发路径: if (REMOVE("removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_10.c:36
- 结论: remove()函数返回0表示成功，但代码中当返回0时打印错误信息，导致成功时误报失败，失败时误判成功。
- D验证: stage_c_preserved / ver_ba953a0b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 126. hyp_path_d66a95d7e408

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_09.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部可控输入，但函数返回值检查本身错误
- 触发路径: if (REMOVE("removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_09.c:36
- 结论: 函数remove的返回值检查逻辑错误：remove返回0表示成功，但代码中当返回0时打印失败信息，导致成功操作被误报为失败。违反API contract，属于CWE-253不正确的函数返回值检查。
- D验证: stage_c_preserved / ver_caed22e8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 127. hyp_path_9cb292b14910

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_13.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 被删除的文件"removemecase0.txt"存在并可删除。
- 触发路径: if (REMOVE("removemecase0.txt") == 0) { printLine("remove failed!"); } @ path_9cb292b14910:36
- 结论: 在remove API调用中，错误地将成功返回值（0）当作失败条件，导致调用remove成功时打印错误的失败信息，违反了正确检查函数返回值的规范（CWE-253）。虽然当前代码仅打印消息，但此API误用可能被攻击者利用，例如在后续逻辑中假设文件未被删除而继续操作，导致不一致状态。
- D验证: stage_c_preserved / ver_77938871
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 128. hyp_path_c8fd2d8f60f4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_14.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 全局变量globalTrue为真，导致该分支必然执行
- 触发路径: if (REMOVE("removemecase0.txt") == 0) { printLine("remove failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_14.c:36
- 结论: 函数remove()的返回值检查逻辑反了：将成功返回值0误判为失败，导致成功删除文件时输出错误消息'remove failed!'，违反了CWE-253关于正确检查函数返回值的要求。
- D验证: stage_c_preserved / ver_19b179f9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 129. hyp_path_78cb1fd431cf

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_15.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 无需攻击者输入，静态调用即可触发。
- 触发路径: if (REMOVE("removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_15.c:37
- 结论: CWE-253: 错误检查函数返回值。函数remove()成功时返回0，失败时返回非零。代码中检查remove()返回值等于0时打印"remove failed!"，这是错误的：成功时却报告失败。这违反了API契约，可能导致逻辑错误，但影响仅限于输出错误消息，无安全后果。
- D验证: stage_c_preserved / ver_d988310c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 130. hyp_path_2aa9a7749e8d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_16.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 程序调用REMOVE函数，且该函数可能返回非零表示失败。
- 触发路径: if (REMOVE("removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_16.c:36
- 结论: 函数remove()的返回值检查错误：成功时（返回0）被误判为失败并打印错误信息，而失败时（返回非零）则不会触发任何错误处理。这违反了CWE-253（错误检查函数返回值）的API契约。
- D验证: stage_c_preserved / ver_e6d0e9a0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 131. hyp_path_7d978a1cdaa4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_18.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 无需外部输入，代码执行到此路径即可触发
- 触发路径: if (REMOVE("removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_remove_18.c:36
- 结论: 函数 remove() 的返回值检查逻辑反转：当 remove() 成功返回 0 时，代码打印 'remove failed!'，违反了 CWE-253 关于正确检查函数返回值的要求。
- D验证: stage_c_preserved / ver_ecc7a425
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 132. hyp_path_89c0a8fabe4b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_01.c:39
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者可能需要影响文件系统状态使得rename成功或失败，但漏洞核心在于开发者错误理解返回值语义。
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_01.c:39
- 结论: 在调用rename()函数后，错误地检查返回值：当返回值等于0（成功）时，却打印错误信息'rename failed!'，导致对rename调用结果的判断完全颠倒。这违反了rename()函数的API契约：成功返回0，失败返回非零。
- D验证: stage_c_preserved / ver_6e0def45
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 133. hyp_path_a5aa921e9374

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_02.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: rename()函数被调用，且成功执行（返回0）
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_02.c:41
- 结论: 代码错误地检查了rename()的返回值：当rename()返回0（成功）时，程序打印"rename failed!"。这违反了CWE-253，即不正确的函数返回值检查，导致成功操作被误报为失败。
- D验证: stage_c_preserved / ver_ad40d73d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 134. hyp_path_b192092efda3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_03.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者可能通过影响文件系统状态（如文件存在性、权限）来使rename返回预期值，但任意输入下代码行为均为错误。
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_03.c:41
- 结论: 在rename调用后，错误地检查了返回值：当返回值为0（成功）时错误地打印失败信息，而当返回值为非零（失败）时未做任何处理，导致失败条件被忽略。违反正确使用rename API的约定。
- D验证: stage_c_preserved / ver_2260994a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 135. hyp_path_bf1418dac448

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_04.c:47
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 无；漏洞在于逻辑错误本身，无需攻击者控制输入。
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_04.c:47
- 结论: 代码对rename()的返回值检查逻辑错误：当rename()成功返回0时，程序打印'rename failed!'，违反了CWE-253（不正确的函数返回值检查）。虽然直接安全影响较低（仅影响日志正确性），但API合约被明确违反，且没有防御检查或错误处理阻断该路径。
- D验证: stage_c_preserved / ver_acfc0166
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 136. hyp_path_0e9a52358752

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_05.c:47
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 无特殊前提，仅需执行到该代码路径。
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_05.c:47
- 结论: rename()函数的返回值检查不正确：当rename返回0（成功）时，却打印错误信息"rename failed!"，违反了合同期望。
- D验证: stage_c_preserved / ver_f46e8d37
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 137. hyp_path_e92610feb20c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_06.c:46
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: N/A
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_06.c:46
- 结论: 代码中对rename函数的返回值检查错误：当rename返回0（成功）时，错误地打印了失败消息。违反了CWE-253（不正确的函数返回值检查）。
- D验证: stage_c_preserved / ver_40466406
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 138. hyp_path_a140d493fc15

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_04.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致rename系统调用失败（例如通过权限不足、文件锁定、磁盘已满等）
- 触发路径: if (RENAME(OLD_CASE1_FILE_NAME, NEW_CASE1_FILE_NAME) != 0) @ 82; printLine("rename failed!"); @ 83
- 结论: rename失败后仅打印错误信息，未采取终止或回滚等错误处理，违反CWE-253对函数返回值进行适当处理的要求。虽然攻击者需能导致rename失败（如权限不足、磁盘满等），且后续逻辑可能基于重命名成功错误执行，但实际利用路径有限，影响较低。
- D验证: stage_c_preserved / ver_bba3d97f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 139. hyp_path_ddd78d025d57

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_07.c:46
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 无外部输入要求，代码本身逻辑错误即可触发
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_07.c:46
- 结论: 在 char_rename_07.c 中，对 rename() 的返回值检查条件错误：当 rename 成功（返回0）时打印失败信息，当 rename 失败（返回非零）时不打印。这违反了 CWE-253 定义，属于不正确的函数返回值检查。
- D验证: stage_c_preserved / ver_8b962349
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 140. hyp_path_45515621059d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_09.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者无法直接控制rename()参数，但可通过影响文件系统状态（如创建同名文件）间接影响rename()的返回值；当前漏洞仅限于错误信息打印，无直接安全影响。
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_09.c:41
- 结论: 对rename()函数返回值检查逻辑错误：当rename()成功（返回0）时，错误地打印了失败信息，违反了API contract，属于CWE-253不正确的返回值检查。
- D验证: stage_c_preserved / ver_15803fcd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 141. hyp_path_3f2c415888d1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_10.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: N/A
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_10.c:41
- 结论: 程序对rename()函数的返回值检查逻辑错误：当rename成功返回0时，错误地打印失败消息。违反了API contract，属于CWE-253（错误检查函数返回值）。
- D验证: stage_c_preserved / ver_59bbc9a1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 142. hyp_path_b5fe0cabbb8e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_13.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: rename函数被调用，且返回值为0（成功）
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_13.c:41
- 结论: 对rename函数的返回值检查错误：当rename返回0（成功）时，代码错误地认为失败并打印消息，违反了CWE-253（函数返回值检查不正确）的语义。
- D验证: stage_c_preserved / ver_557e6aac
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 143. hyp_path_3c29885a62aa

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_14.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 无外部输入控制，仅内部文件名常量
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_14.c:41
- 结论: 对 rename() 函数的返回值检查错误：当 rename 返回 0（成功）时，代码错误地打印 'rename failed!'，违反了函数的返回值语义契约。
- D验证: stage_c_preserved / ver_81a63f58
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 144. hyp_path_d49df3666440

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_15.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 无特殊前提，任何调用该代码路径的情况均会触发此错误检查。
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_15.c:42
- 结论: 函数rename()的返回值检查逻辑错误：当rename返回0（成功）时，代码打印'rename failed!'，而失败时（非0）没有处理。这违反了API contract，属于CWE-253。
- D验证: stage_c_preserved / ver_cecd912a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 145. hyp_path_ae0a51ec1c05

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_16.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: rename()函数调用存在，文件名硬编码，无攻击者控制，但任何执行此代码路径的场景都会触发错误检查。
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_16.c:41
- 结论: 在CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_16.c中，rename()函数的返回值检查逻辑反转：当rename()成功（返回0）时，打印"rename failed!"，导致错误的成功/失败处理，违反API contract。
- D验证: stage_c_preserved / ver_acd64a15
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 146. hyp_path_6244640c08d3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_15.c:69
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: rename操作可能因文件不存在、权限不足、路径错误等失败
- 触发路径: if (RENAME(OLD_CASE1_FILE_NAME, NEW_CASE1_FILE_NAME) != 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_15.c:69
- 结论: rename函数返回值检查不充分，仅打印错误信息而未终止或回滚，违反CWE-253要求正确检查并处理函数返回值。尽管后续代码未完全展示，但根据典型CWE测试用例模式，rename失败后程序可能继续执行并依赖rename结果，导致未定义行为或安全风险。
- D验证: stage_c_preserved / ver_89560b3e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 147. hyp_path_ae76d9df229a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_18.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序调用rename()函数，且存在后续依赖rename结果的处理逻辑。
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_18.c:41
- 结论: 代码对rename()函数的返回值检查错误：rename成功返回0，但代码在返回0时打印失败信息，违反了API contract，可能导致日志误导或错误处理逻辑失效。
- D验证: stage_c_preserved / ver_511096b2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 148. hyp_path_042bd238b5d6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_17.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法直接控制此代码路径，但可能通过环境因素（如stdout关闭、磁盘满）触发fputc失败。
- 触发路径: if (fputc((int)'A', stdout) == 0) @ CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_17.c:31; printLine("fputc failed!"); // 永远不会执行 @ CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_17.c:32-33
- 结论: CWE-253: 对fputc()返回值进行了不正确的检查。代码检查返回值是否等于0，但fputc成功返回写入字符('A')，失败返回EOF(-1)，从不返回0，因此失败条件永远不会触发，导致fputc失败时无法正确处理。
- D验证: stage_c_preserved / ver_087fb711
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 149. hyp_path_439c164cdf41

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_17.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可以通过影响环境使 stdout 写入失败（如填满磁盘、关闭进程的 stdout 管道）。
- 触发路径: if (fputs("string", stdout) == 0) { printLine("fputs failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_17.c:31
- 结论: 对 fputs() 返回值的检查不正确。fputs() 失败时返回 EOF (-1)，但代码检查返回值是否等于 0，导致无法检测到写入失败。
- D验证: stage_c_preserved / ver_22fad017
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 150. hyp_path_5832421a5161

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_17.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可能需要能力使 stdout 写入失败（例如重定向到满磁盘或关闭标准输出），但即使无外部输入，代码本身存在逻辑缺陷。
- 触发路径: if (fprintf(stdout, "%s\n", "string") == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_17.c:31
- 结论: fprintf() 返回值检查逻辑错误：代码检查返回值为0时触发失败处理，但 fprintf 成功时返回非负整数（通常大于0），失败时返回负值。因此实际失败（负值）被忽略，而从未发生的返回0被当作失败。这是 CWE-253 错误检查函数返回值的典型示例。
- D验证: stage_c_preserved / ver_05eb568f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 151. hyp_path_49a681932e5e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_17.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putc()可能由于stdout关闭或写入错误而失败
- 触发路径: if (putc((int)'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_17.c:31
- 结论: putc()返回EOF(-1)表示失败，但代码检查返回值是否等于0，导致错误检查无效。
- D验证: stage_c_preserved / ver_1470a424
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 152. hyp_path_4ecb45314db1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_17.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响标准输入stdin，使得fscanf返回EOF（如关闭输入流或输入无效字符）。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == 0) { @ path_4ecb45314db1:36
- 结论: fscanf返回值检查错误，违反CWE-253：代码将fscanf返回值与0比较，但fscanf失败时返回EOF(-1)，条件不成立，导致无法检测到读取失败。攻击者可通过使fscanf返回EOF触发错误路径，但data变量在后续未被使用，因此实际可利用性和影响较低。
- D验证: stage_c_preserved / ver_c744e99a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 153. hyp_path_e6fc5a433f31

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_17.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putchar()因输出流错误等原因返回EOF（-1）。
- 触发路径: if (putchar((int)'A') == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_17.c:31
- 结论: 对putchar()的返回值检查不正确：代码检查putchar()返回值是否等于0，但putchar()成功时返回写入的字符（'A'，即65），失败时返回EOF（-1）。因此条件永远不会成立，导致putchar()失败时无法被检测到，违反API contract，属于CWE-253（不正确的函数返回值检查）。
- D验证: stage_c_preserved / ver_7c8ae10f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 154. hyp_path_0faa3c9eb7cf

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_17.c:60
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使得fscanf返回0（例如输入空白字符串或提前EOF）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_17.c:60
- 结论: fscanf返回值检查不正确：仅检查返回值是否等于EOF，而忽略了返回值为0的情况。当fscanf返回0时，data内容保持不变（dataBuffer未初始化），虽然后续未使用data，但API contract violation成立，可能造成未初始化数据泄露或未定义行为。
- D验证: stage_c_preserved / ver_5f00a9d3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 155. hyp_path_929b731004ae

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_17.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 不存在阻止 puts() 失败的机制
- 触发路径: if (PUTS("string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_17.c:37
- 结论: 使用 puts() 时，返回值检查错误：检查是否等于 0，但 puts() 失败返回 EOF (-1)，成功返回非负整数。当 puts() 实际失败时，条件为假，错误被忽略，违反 API 契约。
- D验证: stage_c_preserved / ver_e616c123
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 156. hyp_path_a7c152d321aa

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_17.c:44
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: snprintf() call can fail (e.g., due to buffer size constraints or internal errors).
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_17.c:44
- 结论: CWE-253: Incorrect Check of Function Return Value - snprintf() returns negative on failure, but the code checks for return value == 0, causing the error handling path to never be taken on failure.
- D验证: stage_c_preserved / ver_521350ce
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 157. hyp_path_504e7c3f7291

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_17.c:60
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供不匹配格式的输入（例如空输入或非字符串），使得scanf返回0
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_17.c:60
- 结论: scanf函数返回值检查不完整：仅检查EOF，未检查返回值是否等于预期输入项数（1），当scanf返回0时（如输入不匹配），dataBuffer未被正确填充，违反CWE-253。
- D验证: stage_c_preserved / ver_c50c4c70
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 158. hyp_path_c74fa07d7726

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_17.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可以通过提供特殊输入（如EOF或格式错误）使scanf返回EOF(-1)，从而绕过失败处理逻辑，导致data未初始化。
- 触发路径: if (scanf("%99s\0", data) == 0) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_17.c:36
- 结论: 代码错误地检查了scanf函数的返回值：注释指出scanf失败时返回EOF(-1)，但代码仅检查返回值是否为0。当scanf返回EOF时，失败处理分支不执行，导致变量data未被正确初始化。虽然当前证据未显示data后续使用，但未初始化数据在后续使用中可能引发未定义行为，构成潜在的CWE-253违规。
- D验证: stage_c_preserved / ver_7c58f526
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 159. hyp_path_3228b02cf0b6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_17.c:38
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: sscanf的输入导致函数执行失败（例如，输入字符串不符合格式或发生读取错误）
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_17.c:38
- 结论: sscanf函数返回值检查错误：当sscanf失败时返回EOF(-1)，但代码仅检查返回值是否等于0，导致失败未被正确处理。
- D验证: stage_c_preserved / ver_accbd8c6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 160. hyp_path_06ecb0259853

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_17.c:68
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制或影响SRC_STRING的长度，尽管本样本中为固定字符串，但代码结构支持可变输入
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_17.c:68
- 结论: snprintf返回值检查不完整，仅检查返回值<0的错误情况，未处理返回值大于等于0但输出被截断的情况（CWE-253）。虽然本样本中SRC_STRING为固定字符串，但代码模式本身违反了安全API使用规范，存在潜在的截断风险。
- D验证: stage_c_preserved / ver_eb1ba766
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 161. hyp_path_6cdb4a5ac9df

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_17.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够通过合法凭据或其他方式使RpcImpersonateClient返回RPC_S_OK（成功），但无法直接控制返回值。成功调用将导致进程exit(1)，造成拒绝服务。
- 触发路径: if (RpcImpersonateClient(0) == RPC_S_OK) { exit(1); } @ CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_17.c:31
- 结论: 函数RpcImpersonateClient的返回值检查逻辑颠倒：代码在返回值为RPC_S_OK（成功）时调用exit(1)，而非在失败时处理错误。这违反了API契约，导致成功时错误终止，而失败时未正确处理。
- D验证: confirmed / ver_9cdfd60d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 162. hyp_path_1a147af47ba0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_17.c:62
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响SRC_STRING的值（如通过环境变量或输入）。在典型测试用例中SRC_STRING可能为常量，但实际应用中可能来自外部输入。
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_17.c:62
- 结论: sscanf函数返回值检查不完整：仅检查EOF，未检查返回值是否等于期望的匹配项数（1）。若sscanf返回0（无匹配），data将保持未初始化状态，可能导致后续使用未初始化内存。
- D验证: stage_c_preserved / ver_93e8c36d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 163. hyp_path_77b3bf7b4bc5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_17.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fwprintf调用可能因资源不足、文件锁等问题失败，但此测试用例中无外部可控输入，为直接的无条件调用。
- 触发路径: if (fwprintf(stdout, L"%s\n", L"string") == 0) { printLine("fwprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_17.c:31
- 结论: 函数fwprintf的返回值检查错误：标准规定fwprintf失败时返回负值，成功时返回非负整数。代码中检查返回值是否等于0，这无法正确捕获失败（例如返回-1）。
- D验证: stage_c_preserved / ver_e7fd85fd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 164. hyp_path_9d2633aabd63

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_17.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 不需要攻击者控制输入，但需要fputwc执行失败条件成立（如磁盘满、stdout关闭等）
- 触发路径: if (fputwc((wchar_t)L'A', stdout) == 0) { printLine("fputwc failed!"); } @ L31
- 结论: fputwc函数返回失败sentinel值为WEOF(-1)，但代码中错误地检查返回值是否等于0，导致无法正确检测失败。若fputwc失败返回WEOF，条件不满足，不会打印失败信息，违反了API contract。
- D验证: stage_c_preserved / ver_fc58ae37
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 165. hyp_path_e98208e741be

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_17.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够输入流导致fwscanf失败（如发送EOF）
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_17.c:36
- 结论: 未正确检查fwscanf的返回值：函数在失败时返回EOF（-1），但代码检查返回值是否等于0，导致错误检测逻辑。攻击者可通过使fwscanf失败（如输入EOF）绕过预期处理。
- D验证: stage_c_preserved / ver_7433cb99
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 166. hyp_path_73495560a40a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_17.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序执行到该代码路径，且putwc函数可能失败（例如stdout关闭或写入错误）。
- 触发路径: if (putwc((wchar_t)L'A', stdout) == 0) { printLine("putwc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_17.c:31
- 结论: 对putwc函数的返回值检查错误：putwc失败时返回EOF(-1)，但代码检查是否等于0，导致无法正确检测写失败。违反API contract，但后续仅打印错误消息，无其他安全后果。
- D验证: stage_c_preserved / ver_5c7f0c6c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 167. hyp_path_306e823309e1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_17.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无攻击者控制输入；需要运行时环境导致 fputws 失败（如 stdout 关闭、磁盘满等）。
- 触发路径: if (fputws(L"string", stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_17.c:31
- 结论: fputws() 返回值检查错误：成功时返回非负整数，失败时返回 WEOF(-1)，但代码检查返回值是否等于 0。这导致当 fputws 实际失败时，错误分支不会执行，忽略失败情况；当返回值为 0 时，错误分支误执行，但 fputws 通常不会返回 0，因此主要问题是遗漏错误处理。
- D验证: stage_c_preserved / ver_a673c2cb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 168. hyp_path_85cd417cdbc9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_17.c:60
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供不符合格式的输入（如空字符串或非字符串内容），导致fwscanf返回0而非EOF。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_17.c:60
- 结论: fwscanf返回值检查不完整：仅检查了EOF错误，未检查返回值是否等于期望的输入项数（1），违反CWE-253。虽然data在检查失败后未被使用，但函数返回值检查不正确本身构成API misuse。
- D验证: stage_c_preserved / ver_e5189bba
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 169. hyp_path_617903498501

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_17.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putwchar()执行时发生失败（例如文件流错误或输出设备问题）
- 触发路径: if (putwchar((wchar_t)L'A') == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_17.c:31
- 结论: putwchar()的返回值被错误地检查：失败时返回WEOF(-1)，但代码检查返回值是否等于0，导致无法检测失败。这是CWE-253：函数返回值检查不正确。虽然可能不会导致直接的安全后果，但违反了API contract。
- D验证: stage_c_preserved / ver_c1fbeaad
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 170. hyp_path_bb76c35022b5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_17.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putws可能因系统环境因素（如输出重定向失败）而失败，无需攻击者输入控制。
- 触发路径: if (PUTS(L"string") == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_17.c:37
- 结论: 函数putws的返回值检查不正确：putws失败时返回WEOF(-1)，但代码检查返回值是否等于0，导致可能无法检测到失败。这违反了API contract，属于CWE-253（错误的函数返回值检查）。
- D验证: stage_c_preserved / ver_af60c66a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 171. hyp_path_51616faea707

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_17.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特殊前提，代码执行到此调用即可触发。
- 触发路径: if (REMOVE(L"removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_17.c:37
- 结论: 函数remove()的返回值检查错误：当remove()成功返回0时，代码错误地将其视为失败并打印错误信息。违反了CWE-253（对函数返回值的错误检查）。
- D验证: stage_c_preserved / ver_fd85be50
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 172. hyp_path_75028d686e22

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_17.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_17.c:42
- 结论: 对 rename 函数的返回值检查逻辑错误：当 rename 成功（返回0）时，错误地输出了失败信息；正确的做法是检查返回值是否为非零以表示失败。
- D验证: stage_c_preserved / ver_089aaf96
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 173. hyp_path_6d4b92df9c83

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_17.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: wscanf 调用可能因输入流错误或格式不匹配而失败并返回 EOF。
- 触发路径: if (wscanf(L"%99s\0", data) == 0) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_17.c:36
- 结论: 函数 wscanf() 的返回值检查不完整：只检查了返回值是否为 0，但未处理返回 EOF (-1) 的情况。根据 CWE-253，未正确检查函数返回值可能导致错误状态被忽略，尽管后续没有直接危害操作，但违反了 API 契约。
- D验证: stage_c_preserved / ver_caf1ac14
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 174. hyp_path_4e8c4cac8954

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_17.c:44
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制 SRC_STRING 长度，使得 swprintf 因缓冲区不足而失败
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_17.c:44
- 结论: 对 swprintf 函数的返回值进行了不正确的检查：代码只检查返回值是否为 0，但 swprintf 失败时返回负值，成功时返回写入的字符数（可能为正数或 0）。这种检查方式会导致当 swprintf 失败时，程序误认为操作成功，从而继续使用未正确初始化的缓冲区，可能造成后续未定义行为或崩溃。
- D验证: stage_c_preserved / ver_1c616f76
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 175. hyp_path_e7ad532e5e19

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_17.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 任何导致 fwrite 失败或部分写入的环境条件（如磁盘满、权限不足、stdout 关闭等），但无需攻击者控制输入
- 触发路径: if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_17.c:31
- 结论: fwrite 返回值检查错误：代码检查返回值是否小于0，但 fwrite 返回 size_t（无符号），成功时返回写入对象数，失败或部分写入时返回小于 count 的非负整数，永远不会返回负数。因此 < 0 检查无法捕获任何失败情况，违反 API contract，属于 CWE-253。
- D验证: stage_c_preserved / ver_cdbca1b4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 176. hyp_path_cc9962880a17

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_17.c:38
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法控制SRC_STRING，其为常量，因此swscanf不会失败。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == 0) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_17.c:38
- 结论: 对swscanf的返回值检查不正确，但输入SRC_STRING为常量，攻击者无法控制输入使swscanf返回非1的值，因此漏洞实际不可利用，但仍违反CWE-253 contract。
- D验证: stage_c_preserved / ver_f5f750c9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 177. hyp_path_ad3d71295b2d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_17.c:62
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响SRC_STRING内容，使其导致swscanf返回0（例如输入为空字符串）
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_17.c:62
- 结论: swscanf返回值检查不完整：仅检查等于EOF的情况，但swscanf在未匹配任何输入时返回0，未视为错误，违反CWE-253 API契约。虽然代码片段未显示后续使用data，但data可能保持未初始化状态，存在潜在风险，需进一步动态验证或审计确认实际影响。
- D验证: stage_c_preserved / ver_0dd39261
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 178. hyp_path_3afc14ef290e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_17.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，但代码本身违反API契约。
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_17.c:31
- 结论: 对fwrite()的返回值进行了不正确的检查：fwrite()返回size_t（无符号整数），不可能小于0，因此条件'fwrite(...) < 0'永远为假，错误检查无效，无法正确处理写入失败的情况。代码违反了CWE-253定义。
- D验证: stage_c_preserved / ver_45f7ff8e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 179. hyp_path_3c3f13f6a924

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_12.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fprintf函数调用可能失败（如输出设备错误、磁盘空间不足）
- 触发路径: if (fprintf(stdout, "%s\n", "string") == 0) { printLine("fprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_12.c:28-32
- 结论: fprintf的返回值检查不正确：代码中存在对fprintf返回值的错误检查（==0），而实际正确检查应为<0。虽然存在正确检查的分支，但错误检查分支同样可达，构成CWE-253漏洞。
- D验证: stage_c_preserved / ver_2830cb3b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 180. hyp_path_1c65b6869125

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_12.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fputc调用实际失败，返回EOF而不是0。
- 触发路径: if (fputc((int)'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_12.c:30
- 结论: 函数fputc的返回值检查错误：正确做法是检查返回值是否为EOF（-1），但代码中错误地检查返回值是否为0，导致可能忽略写入失败的情况，违反了CWE-253。
- D验证: stage_c_preserved / ver_2d217ad1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 181. hyp_path_a63204d2fb40

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_12.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fscanf()实际返回EOF（例如输入结束或读取错误），但代码错误地认为返回0才是失败。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_12.c:35; printLine("fscanf failed!"); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_12.c:36
- 结论: fscanf()返回值的检查不正确：当fscanf()失败时返回EOF（-1），但代码检查返回值是否等于0，因此无法捕获失败情况，属于API合约违反（CWE-253）。
- D验证: stage_c_preserved / ver_c9af5d1b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 182. hyp_path_25c7bd191d8c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_12.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 目标进程的 stdout 不可用或被关闭，导致 fputs 返回 EOF
- 触发路径: if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_12.c:24; if (fputs("string", stdout) == 0) { printLine("fputs failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_12.c:30
- 结论: fputs() 函数的返回值检查错误：在 globalReturnsTrueOrFalse() 返回真时的执行路径中，将返回值与 0（成功）比较而非与 EOF（失败）比较，导致无法正确检测 fputs 失败，违反了 API contract。
- D验证: stage_c_preserved / ver_d90d5bea
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 183. hyp_path_13e5497e3047

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_12.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法直接控制输入，但环境条件可能导致putc()失败（如stdout关闭、磁盘满等）
- 触发路径: if (putc((int)'A', stdout) == 0) @ CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_12.c:30
- 结论: 代码中对putc()函数的返回值进行了错误检查。当putc()失败时返回EOF(-1)，但代码检查返回值是否等于0，导致putc()失败无法被正确检测。虽然代码中也存在正确的EOF检查分支，但错误检查分支仍然存在，可能遗漏失败处理。
- D验证: stage_c_preserved / ver_e213acf5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 184. hyp_path_974b21e64770

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_12.c:38
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: globalReturnsTrueOrFalse()返回true时触发错误检查路径；无其他外部输入控制。
- 触发路径: if (putchar((int)'A') == 0) { printLine("putchar failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_12.c:30-31
- 结论: 函数putchar的返回值检查不正确：使用putchar((int)'A') == 0判断失败，但putchar失败时返回EOF (-1)，而非0。这违反了C标准库的API约定，可能导致错误未被正确处理。
- D验证: stage_c_preserved / ver_8315b896
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 185. hyp_path_429cc7929738

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_12.c:38
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需外部输入，条件由globalReturnsTrueOrFalse()内部决定，可随机返回true
- 触发路径: void CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_12_case0() { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_12.c:24; if(globalReturnsTrueOrFalse()) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_12.c:26; if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0) { printLine("fwrite failed!");} @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_12.c:30
- 结论: 在CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_12.c中，当globalReturnsTrueOrFalse()返回true时，执行fwrite返回值的错误检查（<0）。由于fwrite返回size_t，无符号类型，<0比较永远为假，导致写入失败无法被正确检测，违反了CWE-253。
- D验证: stage_c_preserved / ver_0ba01391
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 186. hyp_path_043f2070aa2a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_12.c:44
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特定攻击者前提条件，漏洞存在于源代码中，编译执行后即可触发。
- 触发路径: if (PUTS("string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_12.c:34-38
- 结论: 在`CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_12_case0`函数中，存在对`puts()`返回值的错误检查。代码将成功返回值（0）作为失败条件处理，导致在`puts()`成功时错误地报告失败，违反了`puts()`的API契约（成功返回非负值，失败返回EOF）。
- D验证: stage_c_preserved / ver_f4e75f3c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 187. hyp_path_8be5bcc3e86a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_12.c:57
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: snprintf函数执行，返回非0成功值或负值。
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_12.c:43
- 结论: snprintf函数返回值检查错误：代码中存在两种返回值检查，第一个检查（<0）正确，但第二个检查（==0）错误地将成功时可能返回的非零正数误判为失败，导致错误检测逻辑。
- D验证: stage_c_preserved / ver_136b3aa4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 188. hyp_path_15191353460e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_12.c:49
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制程序的标准输入。
- 触发路径: if (scanf("%99s\0", data) == 0) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_12.c:35
- 结论: 在第二个scanf调用中，错误地检查返回值是否等于0而不是等于期望的输入项数（1），违反了CWE-253（函数返回值检查不正确）。
- D验证: stage_c_preserved / ver_14204238
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 189. hyp_path_35db194a9cd6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_12.c:64
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: Attacker can provide input that causes scanf to return 0 (e.g., empty input or whitespace-only input)
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_12.c:64
- 结论: VULNERABILITY_FOUND: Incorrect check of scanf return value: only EOF is checked, but scanf can return 0 on matching failure, causing missing error handling.
- D验证: stage_c_preserved / ver_19e38890
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 190. hyp_path_010386761813

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_12.c:74
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: SRC_STRING需为攻击者可控输入（如环境变量、用户输入等），使得sscanf返回0。但代码证据中SRC_STRING为未定义宏，按Juliet惯例很可能为固定常量，无法由攻击者控制。
- 触发路径: char * data = dataBuffer; if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ 72-74; sscanf返回非EOF时跳过错误处理，data未被正确写入。 @ 74; 未显示的后续代码可能使用data，导致使用未初始化或无效数据。 @ 后续使用
- 结论: sscanf函数返回值检查不完整：仅检查返回值是否等于EOF，未检查是否等于期望的匹配次数（1次）。当sscanf返回0时（例如输入空字符串或格式不匹配），代码误认为成功，导致dataBuffer未正确初始化即被使用，可能引发未定义行为。但SRC_STRING在代码中为宏，根据Juliet样本惯例通常为固定常量（如"a"），攻击者无法控制输入，因此实际可利用性极低，需动态验证或审计确认。
- D验证: stage_c_preserved / ver_863fdc83
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 191. hyp_path_1f8885bcc21b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_12.c:28
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: globalReturnsTrueOrFalse() 返回 true，使执行进入错误检查分支。; sscanf 调用由于输入字符串不符合格式或文件结束而失败，返回 EOF (-1)。
- 触发路径: if (globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_12.c:28; if (sscanf(SRC_STRING, "%99s\0", data) == 0) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_12.c:36
- 结论: 在 sscanf 返回值检查中，当 sscanf 失败时返回 EOF (-1)，但代码分支检查返回值是否等于 0 才认为失败，这导致无法正确检测到函数失败，可能继续使用未初始化的 data 缓冲区，存在未定义行为或信息泄露风险。
- D验证: stage_c_preserved / ver_e369529a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 192. hyp_path_11e4e93a564b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_12.c:40
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者需要使RpcImpersonateClient调用失败（返回非RPC_S_OK），但后续代码被省略，无直接可利用路径。
- 触发路径: void CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_12_case0() { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_12.c:24; if (RpcImpersonateClient(0) == RPC_S_OK) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_12.c:30
- 结论: 在CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_12_case0函数中，存在对RpcImpersonateClient返回值的错误检查：当返回值等于RPC_S_OK（成功）时调用exit(1)退出，而失败时继续执行后续代码。这违反了API契约（成功时应继续，失败时应终止或处理）。虽然后续代码被省略，无实际sink，但该错误检查本身构成CWE-253缺陷，若后续存在依赖模拟权限的敏感操作，则可能导致权限提升。
- D验证: confirmed / ver_adb10a8d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 193. hyp_path_4ad5d53c2b02

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_12.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法直接控制输入，但通过环境因素（如资源耗尽）可使fwprintf失败
- 触发路径: if (globalReturnsTrueOrFalse()) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_12.c:26; if (fwprintf(stdout, L"%s\n", L"string") == 0) { printLine("fwprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_12.c:30
- 结论: 函数fwprintf的返回值检查错误：当globalReturnsTrueOrFalse()为真时，使用==0检查，但fwprintf失败返回负数，导致错误检查无效，违反CWE-253。
- D验证: stage_c_preserved / ver_f98fe8e7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 194. hyp_path_a6f606a67d2e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_12.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fputwc因stdout写入错误而失败，例如磁盘空间不足或stdout关闭
- 触发路径: if (fputwc((wchar_t)L'A', stdout) == 0) { printLine("fputwc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_12.c:30
- 结论: 函数fputwc的返回值被错误地检查为等于0，而不是正确的失败标记WEOF，导致可能无法检测到fputwc失败，违反API契约。
- D验证: stage_c_preserved / ver_48017e80
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 195. hyp_path_1a377cc7baff

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_12.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: globalReturnsTrueOrFalse()返回true，使程序进入包含错误检查的分支
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == 0) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_12.c:33-37
- 结论: 在CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_12.c中，当globalReturnsTrueOrFalse()返回true时，代码检查fwscanf的返回值是否等于0来判断失败，这与API契约不符（fwscanf失败时返回EOF，成功时返回成功匹配的项数，0表示未匹配到任何项）。这种错误检查可能导致程序将未匹配输入的情况误判为失败，从而产生逻辑错误。
- D验证: stage_c_preserved / ver_80c5973f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 196. hyp_path_094eccbffb86

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_12.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fputws(L"string", stdout) == 0) { printLine("fputws failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_12.c:30
- 结论: 函数fputws的返回值被错误地检查：检查返回值是否为0来判断失败，但fputws失败时返回WEOF(-1)而非0。这种错误检查可能导致在fputws实际成功时误报失败，或在实际失败时遗漏错误处理，影响后续逻辑。
- D验证: stage_c_preserved / ver_a7878ae0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 197. hyp_path_406641b7bf12

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_12.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) < 0) @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_12.c:30
- 结论: fwrite函数返回值检查不正确：使用 '<0' 检查失败，而fwrite返回size_t，通常不会小于0，应检查是否不等于请求的写入长度。
- D验证: stage_c_preserved / ver_9e421883
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 198. hyp_path_3e7fa81cb28d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_12.c:38
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putwc可能因stdout错误而返回WEOF
- 触发路径: void CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_12_case0() { @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_12.c:24; if(globalReturnsTrueOrFalse()) { @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_12.c:26; /* NOTE: putwc() might fail... we are checking to see if the return value is 0 */ if (putwc((wchar_t)L'A', stdout) == 0) { printLine("putwc failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_12.c:28-30
- 结论: 函数putwc的返回值被错误检查：正确做法是检查返回值是否等于WEOF，但代码中在globalReturnsTrueOrFalse()返回真的分支内检查是否等于0，导致无法正确检测putwc失败。
- D验证: stage_c_preserved / ver_a0e1d8de
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 199. hyp_path_55fb89990159

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_12.c:38
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putwchar函数可能由于输出错误而失败，但调用者无法捕获该错误。
- 触发路径: if (putwchar((wchar_t)L'A') == 0) { printLine("putwchar failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_12.c:30-32; if (putwchar((wchar_t)L'A') == WEOF) { printLine("putwchar failed!"); } /* 正确检查 */ @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_12.c:36-40
- 结论: 代码中错误地比较putwchar函数的返回值与0而非WEOF，导致函数实际失败时无法检测，违反CWE-253：对函数返回值的错误检查。
- D验证: stage_c_preserved / ver_e2de6a66
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 200. hyp_path_855027783c0a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_12.c:72
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向stdin输入数据，使得fwscanf返回0（例如输入空字符串或不匹配的字符）
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_12.c:72
- 结论: 对fwscanf返回值检查不完整：仅检查了EOF，忽略返回0的情况。当输入不匹配格式或为空时，fwscanf返回0，data可能未被成功赋值，违反了CWE-253正确检查函数返回值的规范。
- D验证: stage_c_preserved / ver_40e42241
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 201. hyp_path_0f0d621fa07d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_12.c:32
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法直接控制putws()的返回值，但可通过影响系统环境（如填满磁盘、关闭输出流）间接导致putws()失败。
- 触发路径: if (PUTS(L"string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_12.c:34
- 结论: 在CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_12_case0函数中，当globalReturnsTrueOrFalse()返回真时，存在对putws()返回值的错误检查：代码使用`PUTS(L"string") == 0`来检查失败，但putws()失败时返回WEOF(-1)而非0，导致失败无法被正确检测。这是API contract违反（CWE-253）。
- D验证: stage_c_preserved / ver_f1432823
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 202. hyp_path_057d797799ff

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_12.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (REMOVE(L"removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_12.c:36
- 结论: 代码中对remove()函数返回值的检查逻辑错误：当remove()成功返回0时，条件`REMOVE(...)==0`为真，导致错误地打印'remove failed!'，违反了API contract（remove成功返回0，失败返回非零），构成CWE-253漏洞。
- D验证: stage_c_preserved / ver_3717affc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 203. hyp_path_b653e22be342

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_12.c:49
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 代码执行到 globalReturnsTrueOrFalse() 返回真分支
- 触发路径: void CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_12_case0() { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_12.c:35; if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_12.c:36; if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_12.c:40
- 结论: 函数 rename 的返回值检查逻辑错误：当 globalReturnsTrueOrFalse() 返回真时，执行分支将 rename 成功（返回 0）误判为失败并打印错误消息，失败（非零）则不做处理。这违反了 CWE-253 关于正确检查函数返回值的要求。
- D验证: stage_c_preserved / ver_158be882
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 204. hyp_path_1589bd9e7c42

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_12.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致wscanf返回EOF（例如关闭标准输入或提供无效输入），但检查条件错误地将EOF视为成功。
- 触发路径: void CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_12_case0() { if(globalReturnsTrueOrFalse()) { { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_12.c:24-28; if (wscanf(L"%99s\0", data) == 0) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_12.c:33-37
- 结论: 函数CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_12_case0的第一个分支中，wscanf返回值检查错误：检查是否等于0而非EOF(-1)，导致wscanf失败时无法被正确检测到，违反CWE-253。
- D验证: stage_c_preserved / ver_ccfea301
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 205. hyp_path_0b798a36a341

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_12.c:72
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供无法匹配%99s格式的数据（例如空输入或非%s字符），导致wscanf返回0而非EOF；或者wscanf因其他原因返回0；后续代码存在使用data的sink（虽未在证据中展示，但符合测试用例典型结构）。
- 触发路径: wchar_t * data = dataBuffer; if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_12.c:70-72
- 结论: 在wscanf调用中，返回值检查不完整：仅检查了EOF，未检查返回0或其他失败状态，违反了CWE-253。虽然后续使用data的sink未在证据中展示，但根据CWE定义，不检查返回值本身即存在隐患，且Juliet测试用例通常包含后续使用，因此保留漏洞假设，但影响程度依赖于未闭合的sink。
- D验证: stage_c_preserved / ver_8cc153de
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 206. hyp_path_cde464156db3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_12.c:34
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，但函数调用可能因缓冲区大小不足等内部条件失败。
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_12.c:43
- 结论: 代码中检查swprintf返回值时，部分检查使用`==0`判断失败，违反了API contract（失败返回负值），导致可能忽略错误，引发未定义行为。
- D验证: stage_c_preserved / ver_d7eb9ba5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 207. hyp_path_350bb2942686

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_12.c:51
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过某种方式影响SRC_STRING的内容，使得swscanf返回0（即没有匹配项）但程序错误地认为操作失败，可能影响后续逻辑
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == 0) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_12.c:35-39
- 结论: swscanf返回值检查不正确：代码将返回值与0比较视为失败，但根据API规范，失败时应返回EOF（-1），返回0表示没有匹配项但未发生错误。这违反了CWE-253（不正确检查函数返回值）的定义。
- D验证: stage_c_preserved / ver_5e392b5e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 208. hyp_path_233dc9f494c8

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_12.c:88
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的内容使其导致swscanf返回0或非1值，但SRC_STRING为不可控常量
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_12.c:88
- 结论: 代码中swscanf返回值检查不完整，仅检查是否等于EOF，未检查是否成功转换预期数量的项（返回值应为1）。违反CWE-253：当swscanf返回0或正数时，代码不会正确处理，可能导致后续使用未正确初始化的dataBuffer。但SRC_STRING为编译时常量，攻击者无法控制输入，因此无法实际触发该违规行为。
- D验证: stage_c_preserved / ver_255bed71
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 209. hyp_path_5f15b356849f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_08.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向stdin输入任意数据
- 触发路径: static void case11() { if(staticReturnsFalse()) { ... } else { @ 61; if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ 76
- 结论: fscanf的返回值检查不完整，仅检查了EOF，未检查匹配失败（返回0）的情况，违反了正确检查函数返回值的约定。
- D验证: stage_c_preserved / ver_b33737ec
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 210. hyp_path_6673820deb27

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_11.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供标准输入内容
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ L63
- 结论: VULNERABILITY_FOUND
- D验证: stage_c_preserved / ver_0866b6d2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 211. hyp_path_b75b993c4486

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_11.c:71
- 漏洞类型: integer_overflow
- CWE: CWE-190; CWE-120
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的内容，使其长度超过99
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_11.c:71
- 结论: snprintf的size参数计算存在整数溢出，当SRC_STRING长度大于等于100时，100-strlen(SRC_STRING)-1产生下溢变为大正数，导致snprintf写入超出缓冲区边界，引发缓冲区溢出。
- D验证: stage_c_preserved / ver_218a3f38
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 212. hyp_path_2f505a422700

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_08.c:78
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 假设攻击者能够控制SRC_STRING内容（如空字符串或仅空白字符），使sscanf返回0。但代码中SRC_STRING可能为固定常量（未明确外部输入），攻击者可控性证据不足。
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_08.c:78
- 结论: sscanf返回值检查不完整：仅检查了EOF，忽略了返回0（未匹配到任何字段）或正数（匹配字段数）的情况，违反API contract（CWE-253）。虽然dataBuffer后续未使用，无直接危害，但存在代码缺陷。
- D验证: stage_c_preserved / ver_b6cf38ee
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 213. hyp_path_0e52d7e78cd8

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_11.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供导致fwscanf匹配失败（返回0）的输入，而非EOF。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_11.c:63
- 结论: 对fwscanf返回值检查不完整：仅检查EOF，未检查返回值是否为1，可能导致未检测到的输入失败，但当前片段无后续数据使用，实际影响较低。
- D验证: stage_c_preserved / ver_3d2daa45
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 214. hyp_path_268528e6bc4c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_11.c:50
- 漏洞类型: CWE-253, CWE-457
- CWE: CWE-253; CWE-457
- 风险等级: P1
- 触发条件: 攻击者能够控制输入到wscanf的内容，使其返回0（如输入空字符串或不匹配的输入）。
- 触发路径: static void case11() { @ L48; wchar_t * data = dataBuffer; /* ALT: check for the correct return value */ @ L61-62; if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ L63
- 结论: wscanf返回值检查不完整：仅检查了EOF，未检查返回0的情况，导致当wscanf返回0（未成功读取任何项）时，data变量可能未正确初始化，后续使用未初始化数据或产生未定义行为。
- D验证: stage_c_preserved / ver_badeca4e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 215. hyp_path_2dfa31f0e57d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_08.c:78
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: swscanf调用可能返回非EOF的失败值（如0）
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_08.c:78
- 结论: CWE-253: Incorrect Check of Function Return Value - swscanf返回值检查不完整，只检查EOF，未检查返回值是否等于1（预期匹配项数），可能漏检输入不匹配或空输入，违反正确返回值检查规范
- D验证: stage_c_preserved / ver_212e3b42
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 216. hyp_path_992afcee444c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_08.c:76
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法使staticReturnsFalse()返回非零值，因此死代码块不可达；无实际可利用的前提条件。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_08.c:76
- 结论: wscanf返回值检查不完整，仅检查EOF，忽略其他错误返回值，但该检查位于死代码路径（staticReturnsFalse()恒假），实际不可达。存在CWE-253违规，但无实际利用可能性。
- D验证: stage_c_preserved / ver_7fcd03c6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 217. hyp_path_27292e5b1c8d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_08.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，但函数可能因内部错误（如缓冲区满）失败，而错误检查逻辑不正确。
- 触发路径: if (fprintf(stdout, "%s\n", "string") == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_08.c:43
- 结论: fprintf() 的返回值检查错误：代码检查返回值是否等于0，但 fprintf 失败时返回负值（EOF），导致无法正确检测失败情况。
- D验证: stage_c_preserved / ver_6e0a8381
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 218. hyp_path_58689eb52873

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_11.c:65
- 漏洞类型: CWE-253, CWE-561
- CWE: CWE-253; CWE-561
- 风险等级: P1
- 触发条件: 攻击者无法控制globalReturnsFalse()的返回值，因此代码块永不可达
- 触发路径: if(globalReturnsFalse()) { ... } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_11.c:52; if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_11.c:65
- 结论: 在死代码中存在CWE-253违反：swscanf返回值检查仅处理EOF，忽略其他错误返回，但代码因globalReturnsFalse()始终返回false而不可达，无实际利用路径。
- D验证: stage_c_preserved / ver_9647406a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 219. hyp_path_1ff11f417ef1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_11.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响环境导致 fprintf 失败（例如，使 stdout 关闭或磁盘满）
- 触发路径: if (fprintf(stdout, "%s\n", "string") == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_11.c:30
- 结论: fprintf 函数返回值的检查不正确：代码检查返回值是否为0，但fprintf失败时返回负数，不会返回0，导致错误未被正确处理。
- D验证: stage_c_preserved / ver_600bf0a0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 220. hyp_path_917ec2b7a8e6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_08.c:39
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fputc 必须失败（例如 stdout 被关闭或遇到写入错误）
- 触发路径: if (fputc((int)'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_08.c:43
- 结论: fputc() 函数在失败时返回 EOF (-1)，但代码检查返回值是否等于 0，导致无法正确检测失败。攻击者可能通过使 fputc 失败（如关闭 stdout）来触发未处理的错误状态。
- D验证: stage_c_preserved / ver_abfb298f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 221. hyp_path_0aa2c91c31f9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_11.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序执行到该代码路径（globalReturnsTrue() 返回真）
- 触发路径: if (fputc((int)'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_11.c:30
- 结论: 函数 fputc 的返回值检查错误：fputc 失败时返回 EOF（-1），但代码将其与 0 比较，导致失败条件永远不满足，从而无法正确检测输出失败。
- D验证: stage_c_preserved / ver_55ff9977
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 222. hyp_path_11c144013e28

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_08.c:39
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者输入；fputs()可能因I/O错误而失败，如stdout关闭或写入错误。
- 触发路径: if (fputs("string", stdout) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_08.c:43
- 结论: 对fputs()的返回值检查错误：fputs()失败时返回EOF(-1)，但代码中检查返回值是否等于0，导致无法正确检测失败。存在CWE-253违规。
- D验证: stage_c_preserved / ver_5f0e6237
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 223. hyp_path_38ff1a0b3450

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_11.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部攻击者控制输入；漏洞由代码逻辑错误直接触发。
- 触发路径: if (fputs("string", stdout) == 0) { printLine("fputs failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_11.c:30
- 结论: fputs() 的返回值检查逻辑错误：当 fputs 成功（返回 0）时，打印错误消息；当 fputs 失败（返回 EOF -1）时，错误被忽略。违反 API contract，导致错误处理颠倒。
- D验证: stage_c_preserved / ver_069f2eee
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 224. hyp_path_2fa3a440dd8b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_05.c:69
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供导致fscanf返回0的输入，如空输入或格式不匹配的字符串。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) @ case11:69
- 结论: fscanf返回值检查不完整：仅比较EOF，未检查返回值是否等于期望的项数1，导致攻击者可通过提供空输入或格式不匹配的字符串使fscanf返回0，而代码未处理此情况，违反API contract，构成CWE-253。但实际影响较低，因为后续未使用data，仅导致数据未读取。
- D验证: stage_c_preserved / ver_1796754c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 225. hyp_path_7a23338bce7b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_08.c:87
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供空行或格式不匹配的输入使fscanf返回0
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_08.c:95; 后续使用未初始化的dataBuffer @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_08.c:后续行（未显示）
- 结论: fscanf返回值检查不完整：仅检查EOF，未检查返回值为0的情况，若fscanf返回0则dataBuffer未更新，后续使用未初始化数据导致未定义行为。
- D验证: stage_c_preserved / ver_6d79c0e1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 226. hyp_path_302b89aecf7f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_08.c:39
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致 fscanf 返回 EOF（例如关闭标准输入或使读取失败）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_08.c:39; if (fscanf(stdin, "%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_08.c:48
- 结论: 函数 fscanf 的返回值检查错误：代码检查返回值是否等于 0，但 fscanf 在文件结束或错误时返回 EOF（-1），而匹配失败时返回 0。正确的做法是检查返回值是否等于 1（成功匹配项数）或检查是否不等于 EOF。当 fscanf 返回 EOF 时，程序误认为成功，但此时 data 未被正确初始化，后续使用 data 可能导致未定义行为。
- D验证: stage_c_preserved / ver_e10fda26
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 227. hyp_path_3b3f7cc708e5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_07.c:68
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过 stdin 提供特殊输入（如空字符串或非匹配字符），使 fscanf 返回 0 而不是 EOF
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) @ L68
- 结论: VULNERABILITY_FOUND: fscanf 返回值检查不完整，仅检查 EOF，忽略返回 0 的情况，导致未初始化数据使用
- D验证: stage_c_preserved / ver_d0425b82
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 228. hyp_path_03e2d9f83696

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_11.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fscanf调用失败（如输入错误或EOF）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_11.c:35
- 结论: fscanf返回值检查不正确：fscanf在失败时返回EOF(-1)，但代码检查返回值是否等于0，导致错误处理逻辑无法正确捕获失败情况。
- D验证: stage_c_preserved / ver_1cb2e3b4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 229. hyp_path_ffd204a6df28

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_10.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者通过stdin提供输入，可触发fscanf返回0（格式不匹配）或其他非EOF错误状态。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_10.c:63
- 结论: fscanf返回值检查不完整：仅检查是否等于EOF，未处理返回0（输入不匹配）或其他负数的情况，导致未处理的错误状态，违反CWE-253对函数返回值全面检查的要求。
- D验证: stage_c_preserved / ver_0fe46a0f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 230. hyp_path_1646836d7051

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_11.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供导致fscanf返回0或非EOF错误的输入
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_11.c:82-84
- 结论: fscanf返回值检查不完整：仅检查EOF，忽略其他失败情况（如返回0），违反安全编码规范
- D验证: stage_c_preserved / ver_14ff3762
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 231. hyp_path_6a5b70318150

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_13.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向stdin提供输入，使得fscanf未成功匹配任何项（返回0而非EOF）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_13.c:63
- 结论: fscanf返回值检查不完整：仅检查EOF，未检查返回值是否等于1。但代码片段中未显示后续对data的未初始化读取操作，因此实际安全影响较低，需要动态验证或确认完整代码中是否存在data使用路径。
- D验证: stage_c_preserved / ver_fd386684
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 232. hyp_path_a6cd76bc91ef

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_08.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特殊攻击前提，但需要 fwrite 实际执行失败（如写入设备无空间）。
- 触发路径: if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_08.c:43
- 结论: fwrite() 的返回值检查错误：条件 `fwrite(...) < 0` 永远不会为真，因为 fwrite 返回 size_t 类型（无符号），错误时返回 0 或解析为大的无符号数，因此当 fwrite 失败时错误不会被检测到。
- D验证: stage_c_preserved / ver_ef52a0f7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 233. hyp_path_311b203811c7

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_11.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fwrite()调用可能失败（例如磁盘空间不足）
- 触发路径: if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0) @ CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_11.c:30
- 结论: fwrite()返回值为size_t无符号类型，检查返回值小于0永远为假，导致fwrite失败时错误未被正确处理，违反CWE-253。
- D验证: stage_c_preserved / ver_86efbd87
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 234. hyp_path_0e4c0ea0d39b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_08.c:39
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 系统可能处于写入失败的状态（如磁盘满、权限不足），导致 putc() 失败时不会被正确检测。
- 触发路径: if (putc((int)'A', stdout) == 0) { printLine("putc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_08.c:43
- 结论: putc() 函数返回 EOF (-1) 表示失败，但代码错误地检查返回值是否等于 0，导致无法正确检测 putc() 失败，可能遗漏错误处理。
- D验证: stage_c_preserved / ver_6d61e6de
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 235. hyp_path_171d58d7e7c4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_11.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特殊前提，只要程序运行时 putc 调用失败即可
- 触发路径: if (putc((int)'A', stdout) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_11.c:30
- 结论: 函数 putc() 的返回值错误检查：putc() 失败时返回 EOF (-1)，但代码检查是否等于 0，导致 putc 失败时不会触发打印的错误处理。
- D验证: stage_c_preserved / ver_29dc1a45
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 236. hyp_path_015936e88900

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_08.c:39
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: No attacker control required; the bug exists regardless.
- 触发路径: if (putchar((int)'A') == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_08.c:39
- 结论: The code incorrectly checks the return value of putchar() by comparing to 0, but putchar() returns EOF (-1) on failure. This violates CWE-253: Incorrect Check of Function Return Value.
- D验证: stage_c_preserved / ver_b130e10f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 237. hyp_path_3eafe00780f7

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_11.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putchar() 调用因某些原因失败（如磁盘满、stdout 关闭等）。
- 触发路径: if (putchar((int)'A') == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_11.c:30
- 结论: 对 putchar() 的返回值进行了错误的检查：putchar() 失败时返回 EOF (-1)，但代码检查返回值是否为 0，导致无法检测到失败。
- D验证: stage_c_preserved / ver_ed184ea1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 238. hyp_path_081aece93960

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_08.c:45
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序运行环境可能导致 puts() 失败（如磁盘满、stdout 关闭等）
- 触发路径: if (PUTS("string") == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_08.c:49
- 结论: 对 puts() 的返回值检查不正确：puts() 成功时返回非负整数（可能为0），失败时返回 EOF (-1)。代码检查返回值是否等于 0，这既可能将成功返回 0 误判为失败，也可能将失败返回 -1 误判为成功（因为 -1 != 0，不进入处理分支），导致无法正确处理 puts() 的失败情况。
- D验证: stage_c_preserved / ver_6751f496
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 239. hyp_path_b8f5609037d2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_11.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: puts()函数可能失败（如文件系统错误），但此处字符串常量固定，不过漏洞在于错误检查模式本身。
- 触发路径: if (PUTS("string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_11.c:36
- 结论: 代码对puts()的返回值检查错误：检查返回值是否为0来判断失败，但puts()失败时返回EOF(-1)，成功时通常返回0。因此，当puts()失败时，条件不成立，错误被忽略；当puts()成功时，条件成立，错误打印，违反了CWE-253。
- D验证: stage_c_preserved / ver_ec07cf8c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 240. hyp_path_27344fd69569

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_05.c:69
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向stdin输入导致scanf返回0或负数（如空字符串、格式不匹配或EOF）的内容
- 触发路径: if (scanf("%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_05.c:69
- 结论: 在CWE253测试用例中，scanf的返回值仅检查是否为EOF，而未检查是否等于期望的输入项数（返回0或负数表示错误或匹配失败），违反API contract，导致输入错误被忽略。
- D验证: stage_c_preserved / ver_d885b330
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 241. hyp_path_0c8767296e3e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_08.c:39
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致scanf返回EOF，例如通过关闭标准输入或提供无效输入导致读取错误
- 触发路径: if (scanf("%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_08.c:48; // 错误检查，未处理EOF @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_08.c:48
- 结论: 函数'CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_08_case0'中错误地检查scanf的返回值。scanf成功时返回成功匹配的输入项数（对于%s格式为1），失败时返回EOF（-1）。代码中检查'if (scanf("%99s\0", data) == 0)'只会捕获返回值为0的情况（理论上不会发生），而忽略了返回EOF的失败情况，导致scanf失败时未正确处理，违反了API contract。
- D验证: stage_c_preserved / ver_b533b8b0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 242. hyp_path_369a8bc58ea0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_09.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供导致scanf返回0的输入（如不匹配格式的字符串）。
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_09.c:63
- 结论: 在scanf返回值检查中，仅检查了EOF，未处理返回0的情况。虽然当前片段未显示后续对data的使用，违反了CWE-253不正确函数返回值检查的API合约，但实际影响取决于后续代码。
- D验证: stage_c_preserved / ver_3cd2ad1b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 243. hyp_path_79e2f3b57db8

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_08.c:87
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入，导致scanf返回0（例如输入空行或不匹配格式的输入）
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_08.c:95
- 结论: 存在CWE-253漏洞：对scanf的返回值检查不完整，仅检查EOF，未检查返回0的情况（匹配失败）
- D验证: stage_c_preserved / ver_656dc65d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 244. hyp_path_2339877adf5e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_07.c:68
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供标准输入使得scanf返回0或小于1的正数（如输入空行或格式不匹配的字符串）
- 触发路径: if (scanf("%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_07.c:68
- 结论: 代码中使用scanf读取字符串，返回值检查不完整：仅检查EOF，忽略了返回值为0（未匹配任何项）或小于期望项数的情况。虽然代码片段中未显示后续使用data，但CWE253要求正确检查函数返回值，此处违反了API契约（scanf返回值的完整检查）。
- D验证: stage_c_preserved / ver_bf05c986
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 245. hyp_path_d90144bdff50

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_10.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供导致scanf返回0的输入（例如输入空行或格式不匹配的内容，使得%s匹配失败返回0）
- 触发路径: case11入口 @ 入口: case11:48; if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ 文件第63行; 若scanf返回0，错误处理被跳过，data未更新，后续代码使用data（具体后续使用未在证据中展示，但典型Juliet测试用例中会使用data） @ 文件第65行之后
- 结论: 代码对scanf的返回值检查不完整：仅检查是否等于EOF，而未检查是否返回1（期望的输入项数）。这导致当scanf因匹配失败返回0时，错误未被检测到，后续可能使用未初始化的数据。
- D验证: stage_c_preserved / ver_4924b5b4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 246. hyp_path_ce6ebcf7b6cb

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_11.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使scanf调用失败（例如提供非预期输入或触发输入错误），导致返回EOF。
- 触发路径: if (scanf("%99s\0", data) == 0) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_11.c:26; if (scanf("%99s\0", data) == 0) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_11.c:35
- 结论: 函数scanf的返回值检查错误：使用 ==0 判断失败，但scanf失败时返回EOF(-1)，而非0。程序中两处scanf调用均存在此错误（第26行和第35行），导致当scanf失败时，错误处理代码不会执行，但后续未使用未初始化的data变量，影响较低。
- D验证: stage_c_preserved / ver_70233df8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 247. hyp_path_430d48f9d5e2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_11.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: program executes case12() with globalReturnsTrue() returning true
- 触发路径: if(globalReturnsTrue()) @ L74; if (scanf("%99s\0", data) == EOF) @ L82
- 结论: VULNERABILITY_FOUND: CWE-253 Incorrect Check of Function Return Value in scanf usage.
- D验证: stage_c_preserved / ver_f71ec612
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 248. hyp_path_97b5c6d7a506

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_13.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供不符合格式的输入（如非字符串），导致scanf返回0而非EOF。
- 触发路径: char * data = dataBuffer; if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ 61-63
- 结论: scanf函数返回值检查不完整：仅检查EOF错误，未检查成功匹配项数（应为1），违反CWE-253。但后续代码未使用data，因此实际影响较低。
- D验证: stage_c_preserved / ver_6b74ee23
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 249. hyp_path_c18a3859c6b6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_05.c:77
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: SRC_STRING length + 2 > 100 - strlen(SRC_STRING)-1 (i.e., SRC_STRING length > ~97) causing truncation; attacker may control SRC_STRING content length in real scenarios
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_05.c:77
- 结论: CWE253 Incorrect Check of Function Return Value: snprintf return value is checked only for <0, missing check for truncation (return value >= buffer size). This allows silent data truncation when output exceeds buffer.
- D验证: stage_c_preserved / ver_afd17b31
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 250. hyp_path_0a41a92bf30e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_08.c:56
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: snprintf函数可能因缓冲区大小不足、内存分配失败等内部原因而失败，无需攻击者直接控制输入。
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_08.c:56
- 结论: 函数snprintf的返回值被错误地检查为'==0'，而snprintf失败时返回负数，成功时返回非负的正整数（写入的字符数）。该检查方式无法正确检测失败，违反了API契约，属于CWE-253（错误检查函数返回值）漏洞。即使当前代码中后续没有使用snprintf的输出，但错误检查本身即构成安全风险，且可能被利用导致未处理的失败状态。
- D验证: stage_c_preserved / ver_57ffc9f3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 251. hyp_path_f8f24041181a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_07.c:76
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制或影响SRC_STRING的值，使其长度超过缓冲区剩余空间，导致截断
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_07.c:76
- 结论: snprintf返回值检查不完整：仅检查返回值是否小于0，未处理截断情况（返回值 >= size）。存在违反CWE-253的API contract，但可利用性取决于SRC_STRING是否为外部可控。
- D验证: stage_c_preserved / ver_277da7ec
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 252. hyp_path_4c98faee845c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_09.c:71
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: SRC_STRING长度可能导致snprintf返回值>=缓冲区大小（即100-strlen(SRC_STRING)-1），发生截断。
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_09.c:71
- 结论: 代码使用SNPRINTF（snprintf）时，返回值检查错误：仅检查返回值<0，但根据C标准，snprintf返回所需字符数（不含空字符），若返回值>=缓冲区大小则表示输出被截断，应视为错误或至少需要处理。该检查未能识别截断情况，违反API契约（CWE-253）。
- D验证: stage_c_preserved / ver_9ddb9964
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 253. hyp_path_121895179346

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_11.c:34
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: snprintf函数调用可能失败（如缓冲区不足或系统错误）并返回负数，导致错误检查失效。
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_11.c:43
- 结论: snprintf的返回值检查不正确：代码检查返回值是否等于0来判断失败，而snprintf失败时返回负数，成功时返回写入字符数（可能为0）。因此，当snprintf失败时，错误条件不会触发，导致未处理错误。
- D验证: stage_c_preserved / ver_09046bc2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 254. hyp_path_954891e4c028

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_10.c:71
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: No external control needed; the code path is always executed when the global condition (if any) is true.
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0) { printLine("snprintf failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_10.c:69-73; if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0) { printLine("snprintf failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_10.c:71-75
- 结论: Incorrect check of snprintf return value: only checks for negative return, but does not verify the expected number of characters written.
- D验证: stage_c_preserved / ver_565167cf
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 255. hyp_path_4679f5b333b4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_08.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 环境因素（如IO错误）导致sscanf返回EOF（-1），而非攻击者可控输入
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == 0) { @ L41; if (sscanf(SRC_STRING, "%99s\0", data) == 0) { @ L50
- 结论: sscanf函数返回值检查错误：当sscanf失败时返回EOF(-1)，但代码仅检查返回值是否等于0，导致失败情况被忽略，符合CWE-253定义。尽管输入SRC_STRING为固定字符串，攻击者无法直接控制，但环境因素（如IO错误）仍可能导致sscanf返回EOF，从而触发漏洞。
- D验证: stage_c_preserved / ver_b838c831
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 256. hyp_path_118a69878fcf

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_08.c:97
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者控制输入SRC_STRING，使其导致sscanf返回0（如空字符串）
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_08.c:97
- 结论: sscanf返回值检查不完整：仅检查EOF，忽略了返回值为0的情况。尽管代码中无对data的后续使用，但违反了CWE-253关于正确检查函数返回值的要求，存在潜在未初始化数据风险（需动态验证是否存在可触发未初始化使用的路径）。
- D验证: stage_c_preserved / ver_e821c088
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 257. hyp_path_309035695205

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_05.c:71
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 不需要攻击者控制输入，违规本身存在
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_05.c:71
- 结论: 函数sscanf的返回值检查错误：仅检查了等于EOF的情况，未检查是否等于期望的匹配项数1，违反了API contract。尽管SRC_STRING为固定字符串，攻击者不可控，但代码逻辑上存在不正确的返回值检查，属于CWE-253违规。由于输入不可控，实际可利用性低，但静态证据表明存在contract violation。
- D验证: stage_c_preserved / ver_ad72d851
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 258. hyp_path_0e70cbda3ce8

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_11.c:90
- 漏洞类型: integer_overflow
- CWE: CWE-190; CWE-120; CWE-253
- 风险等级: P1
- 触发条件: SRC_STRING为长度至少100的字符串（在典型Juliet测试用例中为固定常量）
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0) @ line 90
- 结论: snprintf的size参数计算存在整数下溢：当SRC_STRING长度为100时，100-strlen(SRC_STRING)-1结果为-1，转换为size_t后为极大值，导致snprintf写入超出dataBuffer边界，造成缓冲区溢出。返回值检查仅针对负值，未能防御此溢出。
- D验证: stage_c_preserved / ver_f30cf307
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 259. hyp_path_849d74e606ad

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_09.c:65
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的内容，使其不匹配格式"%99s"（例如空字符串或特殊字符），导致sscanf返回0。
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_09.c:65
- 结论: sscanf返回值检查不完整：代码仅检查返回值为EOF的情况，忽略了返回0（输入不匹配）的情况，违反CWE-253正确检查函数返回值的要求。
- D验证: stage_c_preserved / ver_ac134a24
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 260. hyp_path_3dbfccf37e4d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_11.c:28
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: sscanf的输入SRC_STRING在此样本中为常量，攻击者无法直接影响输入，但错误检查逻辑本身固有缺陷，若SRC_STRING变为用户可控则攻击者可利用。
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == 0) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_11.c:37
- 结论: sscanf()返回值检查错误：代码检查返回值是否等于0，但sscanf在失败时返回EOF(-1)，成功时返回成功匹配的项数（此处为1）。因此无论成功或失败，条件sscanf(...)==0都不成立，导致错误从未被检测。这是对CWE253（函数返回值错误检查）的违反。
- D验证: stage_c_preserved / ver_b944be3a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 261. hyp_path_7c7f5018bf8d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_10.c:65
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的内容
- 触发路径: char * data = dataBuffer; /* ALT: check for the correct return value */ if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_10.c:63-67
- 结论: sscanf函数返回值检查不完整，仅检查EOF，忽略返回0的情况，违反CWE-253，但后续未使用data，导致可利用性未证实
- D验证: stage_c_preserved / ver_9750cf09
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 262. hyp_path_d8c9ae17883b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_11.c:76
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的值——但目前SRC_STRING为固定常量，不可控。若代码在真实场景中被改造为接受外部输入，则条件成立。
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_11.c:84
- 结论: 函数sscanf的返回值检查不正确：仅检查返回值是否为EOF（-1），但sscanf在匹配失败时返回0（成功匹配0项），而不是EOF。代码中存在CWE-253违规，但输入SRC_STRING为固定字符串常量，攻击者无法控制，因此实际可利用性较低。
- D验证: stage_c_preserved / ver_feb22ecc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 263. hyp_path_8e6396a6aaf6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_14.c:65
- 漏洞类型: CWE-253, CWE-457
- CWE: CWE-253; CWE-457
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING内容，使其能被sscanf解析但匹配0项，从而返回0
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_14.c:65
- 结论: 在sscanf调用中，仅检查返回值是否为EOF，未处理返回值为0的情况（即未成功读取任何项）。此时dataBuffer保持未初始化状态，如果后续代码访问dataBuffer则导致未定义行为，违反CWE-253并可能触发CWE-457。但当前证据中缺乏后续使用dataBuffer的代码行，路径不完全闭合。
- D验证: stage_c_preserved / ver_35d2fb41
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 264. hyp_path_5f131f06be68

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_08.c:39
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够使RpcImpersonateClient调用失败（如提供无效上下文或利用环境因素）
- 触发路径: void CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_08_case0() { @ CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_08.c:37; if(staticReturnsTrue()) { @ CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_08.c:38; if (RpcImpersonateClient(0) == RPC_S_OK) { exit(1); } @ CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_08.c:43
- 结论: 函数RpcImpersonateClient的返回值检查逻辑错误：当调用成功时（返回RPC_S_OK）程序退出，而失败时程序继续执行，违反了API契约。这可能导致在权限模拟失败时程序以错误身份运行，引发权限滥用或安全策略绕过。
- D验证: confirmed / ver_c5c86a0d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 265. hyp_path_c370c447e468

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_11.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: RpcImpersonateClient 被调用，且其返回值被错误检查。
- 触发路径: if (RpcImpersonateClient(0) == RPC_S_OK) { exit(1); } @ CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_11.c:30
- 结论: 错误检查 RpcImpersonateClient 返回值：当函数成功（返回 RPC_S_OK）时程序退出，而当函数失败时程序继续执行，违反了 CWE-253 关于正确检查函数返回值的要求。后续代码被省略，具体影响不明确，但存在明显的 API 契约违反。
- D验证: confirmed / ver_788e0701
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 266. hyp_path_187ae752f924

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_08.c:39
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 标准输出文件可能不可写或发生错误，导致fwprintf返回负数
- 触发路径: if (fwprintf(stdout, L"%s\n", L"string") == 0) { printLine("fwprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_08.c:43
- 结论: 函数fwprintf的返回值被错误地检查：fwprintf失败时返回负数（通常为-1），但代码中检查返回值是否等于0，这导致无法正确检测失败。这是CWE-253：对函数返回值的错误检查。
- D验证: stage_c_preserved / ver_4e378bf4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 267. hyp_path_0b363941d682

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_11.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无，失败条件取决于环境（如stdout错误）
- 触发路径: if (fwprintf(stdout, L"%s\n", L"string") == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_11.c:30
- 结论: fwprintf的返回值检查错误：正确做法是检查返回值是否为负（失败），但代码仅检查返回值是否为0，导致失败时无法正确处理，可能造成静默错误。
- D验证: stage_c_preserved / ver_98c2a223
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 268. hyp_path_497a5860e79f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_08.c:39
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无攻击者可控输入，但依赖于运行时环境导致fputwc失败。
- 触发路径: if (fputwc((wchar_t)L'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_08.c:43
- 结论: 函数CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_08_case0中调用fputwc后，错误地将返回值与0比较，但fputwc失败时返回WEOF（-1），导致错误检测逻辑无效，违反CWE-253（不正确的函数返回值检查）。
- D验证: stage_c_preserved / ver_2e6fd0c3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 269. hyp_path_8dafaad2729e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_11.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，但可通过使 stdout 不可写（如关闭 stdout）触发 fputwc 失败，导致错误检查失效。
- 触发路径: if (fputwc((wchar_t)L'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_11.c:30
- 结论: fputwc() 函数在失败时返回 WEOF (-1)，但代码检查返回值是否等于 0，违反了 CWE-253 定义的函数返回值正确检查规范。虽然该漏洞在当前代码中仅导致错误消息未正确打印，未直接造成安全后果，但错误检查不当本身即构成 API 误用漏洞。
- D验证: stage_c_preserved / ver_91a2acab
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 270. hyp_path_05c9d6999129

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_08.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fputws调用可能失败，但错误检查条件为==0，导致失败不会被捕获。
- 触发路径: if (fputws(L"string", stdout) == 0) { printLine("fputws failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_08.c:43
- 结论: 函数fputws的返回值检查错误：fputws失败时返回WEOF(-1)，但代码检查返回值等于0，导致无法正确检测失败。
- D验证: stage_c_preserved / ver_91b4515d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 271. hyp_path_cce207deb4b5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_11.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fputws执行期间发生错误（如stdout不可用）
- 触发路径: if (fputws(L"string", stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_11.c:30
- 结论: 对fputws的返回值检查错误：成功时可能返回0或正数，失败时返回WEOF (-1)，但代码将返回值与0比较来检测失败，导致失败时无法正确捕获，违反CWE-253。
- D验证: stage_c_preserved / ver_32841350
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 272. hyp_path_a334b5a12c89

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_07.c:68
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: Attacker provides input that causes fwscanf to return a value other than EOF (e.g., empty string or non-matching input, leading to return 0).
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { @ L68
- 结论: VULNERABILITY_FOUND: Incorrect check of fwscanf return value - only checks for EOF, ignoring other failure returns (e.g., 0 or negative other than EOF).
- D验证: stage_c_preserved / ver_3b75b51c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 273. hyp_path_71eadc916c18

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_08.c:39
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响输入，使得fwscanf失败（如输入关闭或格式错误），但返回值为EOF而非0。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == 0) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_08.c:39; if (fwscanf(stdin, L"%99s\0", data) == 0) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_08.c:48
- 结论: 函数fwscanf的返回值检查不正确：当fwscanf失败时返回EOF(-1)，但代码仅检查返回值是否为0，导致失败未被正确处理。存在两个类似调用点（第39行和第48行）。
- D验证: stage_c_preserved / ver_cd256987
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 274. hyp_path_1af9fdcc8bf8

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_11.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 输入流stdin读取失败（例如文件结束或错误）导致fwscanf返回EOF。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == 0) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_11.c:35-39
- 结论: 函数fwscanf的返回值检查错误：代码检查返回值是否等于0，但fwscanf失败时返回EOF(-1)，正确检查应为是否小于0或等于EOF。这导致失败情况无法被正确捕获，可能引发未初始化数据使用或逻辑错误。
- D验证: stage_c_preserved / ver_5c7d5201
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 275. hyp_path_11434b1c5fa1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_05.c:69
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin输入数据，使得fwscanf返回0（例如输入空白字符或空字符串）
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ L69
- 结论: 调用fwscanf时仅检查返回值是否为EOF，未检查返回值为0的情况，导致输入匹配失败时错误未被处理，违反API contract CWE-253。虽然当前代码路径中后续未使用data，但该不完整检查本身构成安全缺陷，可能在代码演化或其他执行路径中引发问题。
- D验证: stage_c_preserved / ver_36baea59
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 276. hyp_path_1220d2cc25e0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_08.c:95
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入，使得fwscanf返回0而不是EOF
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_08.c:95
- 结论: 存在不正确的函数返回值检查：对fwscanf的返回值只检查了EOF，忽略了返回0的情况，违反了CWE-253。虽然缺少后续使用data的代码，无法确认实际影响，但存在违反API contract的漏洞假设。
- D验证: stage_c_preserved / ver_b65e2794
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 277. hyp_path_8462c26257b5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_09.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 用户通过 stdin 提供输入
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ L63
- 结论: 函数 fwscanf 的返回值检查不完整，仅检查了 EOF 错误，但未检查成功读取的项数（应为 1），违反 CWE-253 定义，可能导致未正确处理输入读取失败情况。
- D验证: stage_c_preserved / ver_898d8985
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 278. hyp_path_e8387beaa7ae

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_10.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够构造输入使得 fwscanf 返回 0（例如输入空字符串或非匹配内容）。
- 触发路径: wchar_t * data = dataBuffer; if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_10.c:61-65
- 结论: 函数 fwscanf 返回值检查不完整：仅检查了 EOF，忽略了返回值为 0（未匹配任何项）的情况，违反 API contract，但代码中无后续 data 使用路径，实际安全影响较低，需动态验证确认。
- D验证: stage_c_preserved / ver_61036a17
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 279. hyp_path_0261bc0c4801

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_08.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，但fwrite可能因环境原因（如磁盘满）失败。
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) < 0) @ 43
- 结论: fwrite的返回值检查错误：使用小于0的比较，但fwrite返回size_t无符号类型，永远不会小于0，导致无法正确检测写入失败。
- D验证: stage_c_preserved / ver_9f35d722
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 280. hyp_path_be062bf259ae

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_14.c:63
- 漏洞类型: CWE-253, CWE-457
- CWE: CWE-253; CWE-457
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使得fwscanf返回0（例如输入空字符串或仅空白）
- 触发路径: wchar_t * data = dataBuffer; if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_14.c:63; 访问data内容 @ 后续使用data的代码（例如打印或拷贝）
- 结论: 对fwscanf的返回值检查不完整，仅检查了EOF，未处理返回值为0的情况，导致data可能未被正确填充，后续使用可能读取未初始化数据，造成信息泄露或未定义行为。
- D验证: stage_c_preserved / ver_74b72f36
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 281. hyp_path_927bc2ca9604

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_13.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，提供不匹配'%99s'格式的输入（如空输入或非字符串）。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_13.c:63
- 结论: fwscanf返回值检查不完整：仅检查EOF，未处理返回0（无匹配）的情况，但代码片段中未发现后续使用data的sink，因此漏洞可利用性较低，需动态验证确认。
- D验证: stage_c_preserved / ver_675de574
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 282. hyp_path_edfef7997180

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_11.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特定攻击者输入，仅依赖fwrite在特定环境下可能失败（如磁盘满、权限不足等）。
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) < 0) { ... } @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_11.c:30-32
- 结论: 函数fwrite的返回值检查不正确：fwrite返回size_t类型，检查返回值小于0永远为假，无法检测写入失败。违反CWE-253：错误检查函数返回值。
- D验证: stage_c_preserved / ver_72ea17a3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 283. hyp_path_27c7c9d72f0f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_08.c:39
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putwc 函数执行失败（例如介质错误、文件关闭等），返回 WEOF
- 触发路径: if (putwc((wchar_t)L'A', stdout) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_08.c:43
- 结论: 对 putwc 函数的返回值检查错误：putwc 返回 WEOF（-1）表示失败，但代码却检查返回值是否等于 0 来判断失败，导致无法正确检测失败情况。
- D验证: stage_c_preserved / ver_09b86e2c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 284. hyp_path_220d28cc7fd5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_11.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putwc()可能因I/O错误而失败，如stdout已关闭
- 触发路径: if (putwc((wchar_t)L'A', stdout) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_11.c:30
- 结论: 函数putwc()的返回值检查错误：putwc()返回WEOF（-1）表示失败，但代码检查是否为0，导致失败时不会执行错误处理。这是一个CWE-253不正确的函数返回值检查漏洞。
- D验证: stage_c_preserved / ver_adeea5f8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 285. hyp_path_1bdf6b2de920

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_08.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部攻击者输入，但代码本身存在逻辑错误，导致对putwchar返回值的检查无效。
- 触发路径: if (putwchar((wchar_t)L'A') == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_08.c:43
- 结论: 函数CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_08_case0中，对putwchar的返回值检查错误：putwchar失败时返回WEOF (-1)，但代码检查返回值是否等于0，因此无法正确检测putwchar的失败，这是一个典型的CWE-253漏洞。
- D验证: stage_c_preserved / ver_1f132cf5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 286. hyp_path_1077789b34a0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_11.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: globalReturnsTrue() 返回 true，使 if 分支执行
- 触发路径: if (putwchar((wchar_t)L'A') == 0) @ 30; printLine("putwchar failed!"); @ 31
- 结论: 对 putwchar() 的返回值检查错误：函数失败时返回 WEOF(-1)，但代码检查返回值是否等于 0，导致无法正确检测失败。
- D验证: stage_c_preserved / ver_b91042e6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 287. hyp_path_ace704723d1f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_08.c:49
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，但函数调用本身存在错误的返回值检查逻辑
- 触发路径: if (PUTS(L"string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_08.c:49
- 结论: 函数putws()（通过PUTS宏调用）的返回值被错误地检查为等于0时视为失败，而实际putws成功返回0，失败返回WEOF(-1)。该逻辑导致成功时误报失败，失败时无处理，违反API契约，存在CWE-253漏洞。
- D验证: stage_c_preserved / ver_9e1a9c10
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 288. hyp_path_9d994471816c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_11.c:32
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putws函数可能执行失败（返回WEOF）
- 触发路径: if (PUTS(L"string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_11.c:36
- 结论: 函数putws的返回值检查错误：putws成功时返回非负值（通常是输出的字符数），失败时返回WEOF(-1)。代码中检查返回值是否等于0来判定失败，但实际putws成功返回值不可能为0，失败返回-1也不是0，因此条件永远不成立，错误处理代码永远不会执行，导致函数失败时未被正确处理，违反CWE-253。
- D验证: stage_c_preserved / ver_e94825e1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 289. hyp_path_03f7c3f40cb3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_08.c:45
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，此API误用直接存在于代码逻辑中
- 触发路径: if (REMOVE(L"removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_08.c:49
- 结论: 在CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_08.c中，函数REMOVE的返回值被错误地检查：成功时返回0，但代码在返回值为0时打印“remove failed!”，导致逻辑颠倒。这违反了API契约，属于CWE-253错误检查函数返回值。
- D验证: stage_c_preserved / ver_0063a4d4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 290. hyp_path_002739c60162

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_11.c:32
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 文件removemecase0.txt存在且可被remove调用，攻击者可能通过文件权限等间接影响remove返回值。
- 触发路径: if (REMOVE(L"removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_11.c:36-38
- 结论: 函数remove()的返回值检查逻辑颠倒：当remove成功（返回0）时错误地打印失败信息，而失败时（返回非0）不处理，违反CWE-253。
- D验证: stage_c_preserved / ver_bc99f053
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 291. hyp_path_85d51d69e84f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_08.c:54
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法直接控制文件路径（常量），但可以通过改变文件系统状态（如权限、存在性）影响rename结果
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ 行52-56
- 结论: 对rename函数的返回值检查错误：当rename返回0（成功）时，代码打印"rename failed!"，实际应检查返回值是否为非零（失败）才打印错误消息。这违反了CWE-253的语义，可能导致对文件重命名失败的误判，从而忽略错误处理。
- D验证: stage_c_preserved / ver_bc4e5fd5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 292. hyp_path_2d1736898104

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_11.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者输入，程序自包含常量文件名
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_11.c:41
- 结论: 函数`CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_11_case0`中对`rename()`的返回值检查逻辑反转：当`rename`成功返回0时，错误地打印"rename failed!"，违反了API契约，属于CWE-253缺陷。
- D验证: stage_c_preserved / ver_40cef710
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 293. hyp_path_c4cf6cfc088a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_05.c:69
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过文件系统条件（如权限、磁盘满、路径不存在等）导致rename函数返回非零值
- 触发路径: if (RENAME(OLD_CASE1_FILE_NAME, NEW_CASE1_FILE_NAME) != 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_05.c:69
- 结论: CWE-253: Incorrect Check of Function Return Value - rename return value checked but error handling only prints message, no termination or recovery
- D验证: stage_c_preserved / ver_f6e69ecd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 294. hyp_path_07f247fb9cad

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_08.c:48
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入使wscanf返回EOF，例如关闭输入流或输入导致匹配失败的数据
- 触发路径: if (wscanf(L"%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_08.c:48
- 结论: 调用wscanf后错误地检查返回值等于0，而非检查是否小于0（如EOF），违反了API contract。当wscanf返回EOF时，错误处理分支不会执行，导致未能正确处理失败情况。尽管后续未使用未初始化变量data，但违反了函数返回值的正确使用规范。
- D验证: stage_c_preserved / ver_647aea56
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 295. hyp_path_4e31910f70cc

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_09.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向 wscanf 提供输入（例如空输入或格式不匹配的输入）
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_09.c:63
- 结论: 对 wscanf 的返回值检查不充分，仅检查是否等于 EOF，忽略了返回值为 0（表示未成功匹配任何项）的情况，可能导致使用未初始化的 dataBuffer 数据。
- D验证: stage_c_preserved / ver_ddbbc1fc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 296. hyp_path_b4c8106b9804

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_08.c:87
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向程序的标准输入提供空行或仅空白字符，使得wscanf返回0。
- 触发路径: static void case12() { if(staticReturnsTrue()) { @ case12函数入口; if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ 第95行; if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ 第99行
- 结论: 函数case12中wscanf返回值检查不完整：仅检查了EOF（返回-1），但未检查返回0的情况（表示没有匹配项）。当wscanf返回0时，dataBuffer未被写入，仍保持未初始化状态，后续再次调用wscanf时使用了未初始化的dataBuffer，违反了CWE-253关于正确检查函数返回值的要求。攻击者可提供空输入或仅空白字符使wscanf返回0，从而导致未定义行为。
- D验证: stage_c_preserved / ver_09a85f4e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 297. hyp_path_5fdf7e58f139

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_07.c:68
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入，使得 wscanf 返回0（例如输入仅包含空白或格式不匹配）
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_07.c:68-70
- 结论: 对 wscanf 返回值检查不完整，仅检查 EOF，未检查返回0（匹配失败）的情况，违反 CWE-253 对函数返回值的正确检查要求。尽管后续未直接使用 data，但返回值检查不完整本身构成 API misuse。
- D验证: stage_c_preserved / ver_9ca61dbe
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 298. hyp_path_ec19054d7b5d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_05.c:69
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入使得wscanf返回0（例如输入空字符串或格式不匹配）
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ 69
- 结论: CWE253: 函数wscanf的返回值检查不完整，仅检查EOF，未检查返回0或其他错误码，可能导致后续使用未初始化或部分数据。但当前代码片段未显示对数据buffer的后续使用，因此可利用性不确定。
- D验证: stage_c_preserved / ver_05109b9a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 299. hyp_path_1e86e0a81173

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_11.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 用户输入导致wscanf失败（如输入格式错误或流错误）
- 触发路径: if(globalReturnsTrue()) { { ... } @ L24-28; if (wscanf(L"%99s\0", data) == 0) { printLine("wscanf failed!"); } @ L35
- 结论: 函数wscanf的返回值检查错误：判断条件为返回值==0，但wscanf失败时返回EOF(-1)，导致错误处理分支不可达。虽然当前代码中错误处理仅打印消息，未使用未初始化的data，但违反了API contract，存在潜在风险。
- D验证: stage_c_preserved / ver_2cef1f4d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 300. hyp_path_ec3a1b795f38

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_10.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制提供给wscanf的输入，使其返回0（例如输入仅包含空白字符或与格式不匹配）。
- 触发路径: wchar_t * data = dataBuffer; if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_10.c:61-65
- 结论: 调用wscanf函数时，只检查返回值是否等于EOF，而未检查返回值为0的情况，违反了CWE-253关于正确检查函数返回值的要求。虽然后续未直接使用未初始化的data变量，但返回值检查不完整仍属于API契约违规，可能在其他上下文中导致漏洞。
- D验证: stage_c_preserved / ver_6fe335a0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 301. hyp_path_7a9041fe4841

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_11.c:74
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供导致wscanf返回0的输入（例如空字符串或格式不匹配的输入）
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_11.c:82
- 结论: wscanf函数返回值检查不完整，仅检查EOF，未检查返回0（表示无输入匹配）的情况，违反CWE-253关于正确检查函数返回值的要求。攻击者可通过提供空输入或格式不匹配的输入使wscanf返回0，导致dataBuffer内容未更新，可能后续使用未初始化或错误数据。
- D验证: stage_c_preserved / ver_8d82cf32
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 302. hyp_path_e2bb570a3eca

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_14.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供输入，使wscanf无法匹配格式但又不返回EOF。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_14.c:63
- 结论: 函数wscanf的返回值检查不完整，仅检查了EOF而忽略了返回0的情况，违反API contract，可能导致未检测到的输入匹配失败。
- D验证: stage_c_preserved / ver_cd10bcf6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 303. hyp_path_cdc27531cc49

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_13.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能向程序提供标准输入，使wscanf返回0（如直接输入换行或不匹配格式的字符）
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_13.c:63
- 结论: 对wscanf的返回值检查不完整：仅检查是否为EOF，忽略了返回0（未匹配任何项）的情况，导致data可能未正确初始化，后续使用可能导致未定义行为。
- D验证: stage_c_preserved / ver_70156e62
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 304. hyp_path_ccced7071431

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_08.c:56
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可能通过控制输入导致swprintf失败（如缓冲区太小），但无需攻击者直接控制，仅需函数失败即可触发漏洞。
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) == 0) @ L56
- 结论: CWE-253: Incorrect Check of Function Return Value: 对swprintf()的返回值检查错误。代码只检查返回值是否为0，而失败时返回负数，导致错误被忽略。
- D验证: stage_c_preserved / ver_dfdc6905
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 305. hyp_path_0125f396358a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_11.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者控制输入，仅需swprintf因内部原因失败（如缓冲区不足）即可触发错误处理缺失
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_11.c:43
- 结论: 代码不正确检查swprintf函数的返回值。注释说明swprintf可能失败并返回负值，但代码只检查返回值是否等于0，当swprintf失败返回负值时，条件为假，不会打印失败信息，导致错误处理缺失。
- D验证: stage_c_preserved / ver_e1ae68eb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 306. hyp_path_da89acee9347

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_07.c:76
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法控制SRC_STRING（宏常量），截断由静态数据引起，不可主动触发; 但代码逻辑上仍存在返回值检查不完整的问题
- 触发路径: wchar_t * data = dataBuffer; /* ALT: check for the correct return value */ if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) < 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_07.c:74-78; 成功分支（else隐含）未对截断做任何检查，直接使用data @ 同上
- 结论: 存在CWE-253不正确的函数返回值检查：SNPRINTF的返回值检查仅针对负值（错误情况），未检查返回值是否等于预期长度（即截断情况）。即使SRC_STRING为宏常量，代码本身违反CWE定义，但实际可利用性低。
- D验证: stage_c_preserved / ver_86000653
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 307. hyp_path_5d83f84a6dbe

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_08.c:50
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响 SRC_STRING 的内容，可能导致 swscanf 失败（例如无效输入或格式不匹配）
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_08.c:50
- 结论: 函数 swscanf 的返回值检查错误：应检查返回值是否为 EOF (-1) 来检测失败，但代码错误地检查返回值是否等于 0。这违反了 CWE-253 (Incorrect Check of Function Return Value)，可能导致未检测到的失败状态，从而使用未初始化的 data 缓冲区。
- D验证: stage_c_preserved / ver_20b19e27
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 308. hyp_path_83ebe9406353

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_08.c:89
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可能控制输入SRC_STRING，使其导致swscanf返回非EOF但非预期的值，例如空字符串导致返回0。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_08.c:97
- 结论: 对swscanf的返回值检查不完整，仅检查是否为EOF，而忽略了返回值为0或小于期望匹配数的情形，可能导致未初始化或部分初始化的缓冲区被使用，违反了CWE-253（返回值检查错误）。
- D验证: stage_c_preserved / ver_507b981d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 309. hyp_path_7a55ff5e1715

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_05.c:71
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制 SRC_STRING 的内容，使其无法匹配格式字符串 L"%99s"，导致 swscanf 返回 0 而非 EOF。但当前 SRC_STRING 为硬编码常量，无法满足该前提。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_05.c:71
- 结论: swscanf 返回值检查不完整：仅检查了 EOF，未检查返回值为 0 的情况，但 SRC_STRING 为硬编码常量且 data 后续未被使用，导致实际可利用性极低。
- D验证: stage_c_preserved / ver_d33fa449
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 310. hyp_path_6ec7bcdd295f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_07.c:70
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能控制SRC_STRING的内容，但实际SRC_STRING为常量，前提不成立。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_07.c:70
- 结论: 存在对swscanf返回值的不正确检查（CWE-253），仅检查EOF而忽略正常返回值1。但由于SRC_STRING为字符串常量，攻击者无法控制输入，该路径不可达，实际无法利用。
- D验证: stage_c_preserved / ver_6a5b52e8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 311. hyp_path_0d7b8cabc817

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_09.c:65
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入字符串SRC_STRING的内容（蓝队指出此条件不满足，因为SRC_STRING为固定字符串）
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_09.c:65
- 结论: 函数swscanf的返回值检查不完整：仅检查返回值是否等于EOF，而未检查是否等于期望的匹配项数（1）。代码违反CWE-253，但由于SRC_STRING是固定字符串字面量，攻击者无法控制其内容，导致precondition A1不成立，因此该漏洞在当前上下文中不可利用，但仍属于API contract violation。
- D验证: stage_c_preserved / ver_dc51de47
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 312. hyp_path_ac310041c977

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_11.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: swscanf函数被调用，且其返回值被错误地检查为==0，而非检查EOF(-1)或成功匹配数
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_11.c:37
- 结论: 对swscanf函数的返回值检查错误，使用了==0而不是检查是否为EOF(-1)或成功返回值，违反CWE-253，可能导致忽略错误情况。
- D验证: stage_c_preserved / ver_e7a040d0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 313. hyp_path_5ff0cb8c0385

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_10.c:65
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING输入，使其为空或仅空白字符串
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_10.c:65
- 结论: 存在CWE-253漏洞：swscanf返回值检查不完整，仅检查EOF，未处理返回0的情况，导致在输入为空或仅空白时dataBuffer未正确初始化，后续使用未初始化数据。
- D验证: stage_c_preserved / ver_7e8bdf95
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 314. hyp_path_82d3275baa3d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_01.c:28
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者控制输入，代码本身存在逻辑错误
- 触发路径: if (fprintf(stdout, "%s\n", "string") == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_01.c:28
- 结论: fprintf的返回值检查错误：代码检查返回值是否等于0，但fprintf失败时返回负值，成功时返回正数，因此错误检查无法捕获失败情况，违反CWE-253。
- D验证: stage_c_preserved / ver_1ad39eb8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 315. hyp_path_bee51898074e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_14.c:65
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的内容，使其不匹配格式L"%99s"（例如空字符串或非数字字符）
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_14.c:65; printLine("swscanf failed!"); // 仅当返回EOF时处理，返回0时跳过 @ 同一文件:65-67
- 结论: swscanf返回值检查不正确：仅检查返回值为EOF，但swscanf在输入不匹配格式时返回0，不会触发错误处理，导致data缓冲区可能未正确写入，后续使用可能依赖未初始化数据。
- D验证: stage_c_preserved / ver_46632b8d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 316. hyp_path_18e1b5c76364

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_11.c:76
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING输入，使得swscanf返回0（例如输入空字符串或格式不匹配的字符串）。
- 触发路径: wchar_t * data = dataBuffer; if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ L82-L86
- 结论: 不正确的返回值检查：swscanf的返回值仅与EOF比较，未检查是否成功匹配了预期的项目数（1），违反CWE-253。即使data后续未使用，该检查不完整本身构成安全编码缺陷。
- D验证: stage_c_preserved / ver_59c51100
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 317. hyp_path_2705f860996f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_13.c:65
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的内容
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_13.c:65
- 结论: 漏洞存在：swscanf返回值检查不完整，仅检查EOF，未检查其他错误或成功匹配数，违反CWE-253。攻击者若控制SRC_STRING，可能导致未初始化或部分初始化的数据被使用。
- D验证: stage_c_preserved / ver_4871f384
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 318. hyp_path_3413652fd7df

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_02.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入依赖，代码本身逻辑缺陷
- 触发路径: if (fprintf(stdout, "%s\n", "string") == 0) { printLine("fprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_02.c:30
- 结论: fprintf的返回值检查错误：成功时返回写入字符数（正数），失败时返回负值，但代码检查是否等于0，导致永远无法检测到失败，并且会错误地报告fprintf失败。违反CWE-253（不正确的函数返回值检查）。
- D验证: stage_c_preserved / ver_8323102d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 319. hyp_path_635182b28d3d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_03.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，但系统级故障（如磁盘满、stdout关闭）可导致fprintf失败
- 触发路径: if (fprintf(stdout, "%s\n", "string") == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_03.c:30
- 结论: fprintf()的返回值检查错误：代码检查返回值是否为0，但fprintf成功时返回非负整数（写入字符数），失败时返回EOF(-1)。因此当fprintf实际失败时（返回-1），检查条件不成立，错误未被正确处理。
- D验证: stage_c_preserved / ver_a3321268
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 320. hyp_path_f50b2e4e3355

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_04.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fprintf 调用可能因输出错误（如重定向到全满磁盘）而返回负值，无需攻击者控制输入，属于 API 误用。
- 触发路径: if (fprintf(stdout, "%s\n", "string") == 0) { printLine("fprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_04.c:36
- 结论: 对 fprintf 返回值的错误检查：当 fprintf 失败返回负值时，代码检查返回值是否等于 0，导致负值返回无法被识别为错误，违反 CWE-253。
- D验证: stage_c_preserved / ver_0cb5b9c1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 321. hyp_path_5d9337b53008

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_06.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序运行时fprintf()可能因写入错误而失败，例如stdout文件描述符被关闭或磁盘空间不足。
- 触发路径: if (fprintf(stdout, "%s\n", "string") == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_06.c:35
- 结论: fprintf()的返回值检查错误：fprintf失败时返回负数，但代码检查返回值==0，导致fprintf失败时不会触发失败处理分支，违反API contract。
- D验证: stage_c_preserved / ver_07fb94a4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 322. hyp_path_5c5eac052fdb

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_05.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，但fprintf可能因I/O错误而失败，例如磁盘满或stdout关闭
- 触发路径: if (fprintf(stdout, "%s\n", "string") == 0) { printLine("fprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_05.c:36
- 结论: fprintf返回值检查错误：使用 '== 0' 判断失败，但fprintf失败时返回负值，成功时返回非负整数（此处写入'string\n'，成功返回7或类似，不会为0）。这导致错误处理代码永远不执行，无法检测fprintf失败，违反CWE-253。虽然该错误不会直接导致内存安全或信息泄露，但使得错误检测失效，存在潜在风险。
- D验证: stage_c_preserved / ver_09deab8d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 323. hyp_path_a989eec82a6a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_07.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序运行在文件写入可能失败的环境（如磁盘满、stdout关闭等）。
- 触发路径: if (fprintf(stdout, "%s\n", "string") == 0) { printLine("fprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_07.c:35
- 结论: 函数fprintf的返回值检查不正确：fprintf出错时返回负数，但代码仅当返回值为0时认为失败，导致无法正确检测失败情况。
- D验证: stage_c_preserved / ver_2f1b3bd0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 324. hyp_path_c0338738844b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_09.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法直接控制 fprintf 的参数，但可以通过外部条件（如耗尽磁盘空间、关闭 stdout 等）导致 fprintf 失败。
- 触发路径: if (fprintf(stdout, "%s\n", "string") == 0) { printLine("fprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_09.c:30
- 结论: 对 fprintf 函数返回值的检查不正确：程序检查返回值是否等于 0，但 fprintf 失败时返回负值，成功时返回非负整数。因此，当 fprintf 由于错误（如输出设备满）而返回负值时，条件 (fprintf(...) == 0) 为假，不会检测到失败，导致错误被忽略。
- D验证: stage_c_preserved / ver_d4ac5dc2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 325. hyp_path_97d3ede81d0d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_10.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无攻击者输入，但任何导致fprintf失败的情况（如stdout关闭）都会触发错误逻辑。
- 触发路径: if (fprintf(stdout, "%s\n", "string") == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_10.c:30
- 结论: fprintf() 返回值检查错误：正确检查应为返回值为负数（EOF）表示失败，但代码错误地检查返回值是否等于0，导致失败情况不被正确识别，违反 API contract。
- D验证: stage_c_preserved / ver_8c85c95f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 326. hyp_path_361d18ec9b8d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_13.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fprintf(stdout, "%s\n", "string") == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_13.c:30
- 结论: 代码错误地将fprintf返回值为0当作失败条件，违反了CWE-253 Incorrect Check of Function Return Value。fprintf在失败时返回负值，返回0表示成功写入0字符，而此处实际写入字符串，因此该检查永远不会触发，属于不正确的返回值检查。
- D验证: stage_c_preserved / ver_353111ac
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 327. hyp_path_1802ab6f2ac5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_14.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 全局变量globalTrue为1; fprintf调用失败（返回负数）
- 触发路径: if (fprintf(stdout, "%s\n", "string") == 0) { printLine("fprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_14.c:28-32
- 结论: fprintf函数的返回值检查不正确：fprintf失败时返回负数，成功时返回写入字符数（正数），而代码检查返回值是否等于0，导致无法正确检测fprintf失败的情况。
- D验证: stage_c_preserved / ver_029ad3b3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 328. hyp_path_3240d4775890

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_15.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无额外前置条件，函数调用本身可能因系统资源不足等原因失败。
- 触发路径: if (fprintf(stdout, "%s\n", "string") == 0) { printLine("fprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_15.c:31
- 结论: 函数fprintf的返回值检查错误：fprintf失败时返回负值，但代码检查是否为0，导致无法正确检测fprintf失败。
- D验证: stage_c_preserved / ver_41ee59d2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 329. hyp_path_1dacb762c258

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_18.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fprintf() 失败因系统资源耗尽或流意外关闭，无需特定攻击者输入。
- 触发路径: if (fprintf(stdout, "%s\n", "string") == 0) { printLine("fprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_18.c:30
- 结论: fprintf() 的返回值检查不正确：代码检查返回值是否等于 0，但 fprintf() 失败时返回负数（如 -1），而非 0。这导致即使 fprintf() 失败，也不会执行错误处理逻辑，可能掩盖输出失败或导致后续逻辑错误。
- D验证: stage_c_preserved / ver_56348731
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 330. hyp_path_f992dc8aca49

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_01.c:28
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者或环境因素导致stdout写入失败（如stdout被关闭、磁盘满等）。
- 触发路径: if (fputc((int)'A', stdout) == 0) { printLine("fputc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_01.c:28
- 结论: 函数fputc()的返回值检查错误：fputc()失败时返回EOF(-1)，但代码检查返回值==0来判断失败，导致写入失败时无法正确检测。
- D验证: stage_c_preserved / ver_547aaa30
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 331. hyp_path_82cc95f8e288

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_02.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可能通过资源耗尽或环境操纵导致 fputc 调用失败
- 触发路径: if (fputc((int)'A', stdout) == 0) @ L30
- 结论: fputc() 函数返回 EOF(-1) 表示失败，但代码检查返回值是否等于 0，这是对函数返回值的错误检查，违反 API contract，导致无法正确检测 fputc 失败。
- D验证: stage_c_preserved / ver_1017be29
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 332. hyp_path_fb37777b5772

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_16.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响stdout的写入状态，例如通过提前关闭文件描述符1、将stdout重定向到不可写入的文件，或耗尽磁盘空间等方式，使得fprintf调用失败。
- 触发路径: if (fprintf(stdout, "%s\n", "string") == 0) { printLine("fprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_16.c:30
- 结论: fprintf函数的返回值检查错误。代码检查fprintf返回值是否等于0，但fprintf成功时返回非负整数（实际打印字符数），失败时返回负数，因此检查等于0永远无法正确捕获失败情况，违反CWE-253（不正确的函数返回值检查）的API契约。攻击者可通过影响stdout写入状态使fprintf失败，但错误条件无法被正确处理。
- D验证: stage_c_preserved / ver_3a4d788a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 333. hyp_path_7d5fd64b51f4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_03.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特定攻击者控制前提，代码本身存在逻辑错误。
- 触发路径: if (fputc((int)'A', stdout) == 0) { printLine("fputc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_03.c:30
- 结论: fputc() 返回 EOF (-1) 表示失败，但代码检查返回值是否等于 0，这是对函数返回值的不正确检查，违反了 API contract，可能导致错误未正确处理。虽然影响仅限于错误消息打印，但漏洞确实存在。
- D验证: stage_c_preserved / ver_6b31ec5b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 334. hyp_path_e030f4cfa609

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_04.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，但 fputc 可能由于 stdout 关闭或不可写入而失败。
- 触发路径: if (fputc((int)'A', stdout) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_04.c:36
- 结论: 代码错误地使用 `== 0` 检查 `fputc` 的返回值，而 `fputc` 失败时返回 `EOF`（-1），成功时返回写入的字符。这种检查无法捕获失败情况，违反了 CWE-253（不正确的函数返回值检查）。虽然当前环境不影响后续安全，但存在未处理错误的风险。
- D验证: stage_c_preserved / ver_6a6eda90
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 335. hyp_path_fde228da5909

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_05.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fputc()调用失败（例如磁盘满、stdout关闭），返回EOF(-1)。
- 触发路径: if (fputc((int)'A', stdout) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_05.c:36
- 结论: 函数fputc()的返回值检查错误：fputc()失败时返回EOF(-1)，但代码中检查是否等于0，导致无法正确检测失败情况。
- D验证: stage_c_preserved / ver_767c97fc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 336. hyp_path_58c2cf179f58

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_06.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部攻击者控制输入，漏洞由代码内部逻辑错误导致。
- 触发路径: if (fputc((int)'A', stdout) == 0) { printLine("fputc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_06.c:35
- 结论: 对fputc()返回值的检查错误：fputc()失败时返回EOF(-1)，但代码检查返回值是否为0，无法正确检测失败，违反API contract。
- D验证: stage_c_preserved / ver_7fe5649e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 337. hyp_path_6216d59a6f3f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_07.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入，代码本身存在逻辑错误
- 触发路径: if (fputc((int)'A', stdout) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_07.c:35
- 结论: 错误检查 fputc 返回值，使用 `==0` 而不是 `==EOF`，导致无法正确检测写入失败。
- D验证: stage_c_preserved / ver_793bde7c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 338. hyp_path_b2b395ab1f8e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_09.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fputc() 调用可能失败（例如 stdout 关闭或写入错误）
- 触发路径: if (fputc((int)'A', stdout) == 0) { printLine("fputc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_09.c:30
- 结论: 函数 fputc() 的返回值检查错误：fputc() 失败时返回 EOF (-1)，但代码检查返回值是否等于 0，导致无法正确检测失败。
- D验证: stage_c_preserved / ver_40bfb43e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 339. hyp_path_c6e44e0bf063

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_10.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法直接控制fputc的失败，但存在写入stdout失败的环境条件（如磁盘满、stdout关闭等）
- 触发路径: if (fputc((int)'A', stdout) == 0) { printLine("fputc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_10.c:30
- 结论: fputc()函数的返回值检查错误：fputc()失败时返回EOF(-1)，但代码中检查是否为0，导致失败无法被检测到，违反API contract。
- D验证: stage_c_preserved / ver_617a1a88
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 340. hyp_path_87e46d64f3ce

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_13.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需外部输入；错误返回值检查本身构成API contract violation
- 触发路径: if (fputc((int)'A', stdout) == 0) { printLine("fputc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_13.c:30
- 结论: 对fputc()返回值的不正确检查：代码检查fputc返回值是否等于0，但实际上fputc成功时返回写入的字符（例如'A'），失败时返回EOF(-1)。因此条件'fputc() == 0'永远不会为真，导致无法检测到写入失败，违反了CWE-253（函数返回值错误检查）。注释明确说明检查0是错误的，但代码仍如此实现。
- D验证: stage_c_preserved / ver_7798738b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 341. hyp_path_b8e1932b96db

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_14.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者主动控制；仅需fputc运行时发生失败（如stdout关闭、磁盘满等）即可触发漏洞。
- 触发路径: if (fputc((int)'A', stdout) == 0) { @ CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_14.c:30
- 结论: 对fputc返回值的错误检查：代码检查fputc返回值是否等于0，而fputc成功时返回写入字符（非负），失败时返回EOF(-1)，因此无论成功或失败均不满足条件，导致错误无法被检测。违反CWE-253（函数返回值检查不正确）。
- D验证: stage_c_preserved / ver_6ff1e195
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 342. hyp_path_e7fca6defc35

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_15.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fputc() 调用可能失败（例如 stdout 关闭或写入错误）
- 触发路径: if (fputc((int)'A', stdout) == 0) { printLine("fputc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_15.c:31
- 结论: 函数 fputc() 的返回值检查不正确：fputc() 失败时返回 EOF (-1)，但代码检查是否等于 0，导致无法检测失败。
- D验证: stage_c_preserved / ver_1eb51f75
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 343. hyp_path_0e43f2dc1a22

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_16.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序输出时，stdout可能由于各种原因（如磁盘满、管道关闭）导致fputc失败
- 触发路径: if (fputc((int)'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_16.c:30
- 结论: 对fputc返回值的错误检查：代码将fputc的返回值与0比较，但fputc失败时返回EOF(-1)，而非0。这导致fputc失败时无法被检测到，可能使程序在错误状态下继续执行。
- D验证: stage_c_preserved / ver_b1e47063
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 344. hyp_path_4f0a64c5239e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_18.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fputc((int)'A', stdout) == 0) { printLine("fputc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_18.c:30
- 结论: fputc() 的返回值检查错误：当 fputc 失败时返回 EOF (-1)，但代码检查返回值是否等于 0，导致无法正确检测失败。
- D验证: stage_c_preserved / ver_bf3add3e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 345. hyp_path_9e269965a589

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_02.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无额外攻击者输入；fputs失败由外部环境（如stdout错误）引起。
- 触发路径: if (fputs("string", stdout) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_02.c:30
- 结论: 函数fputs的返回值检查错误：fputs失败时返回EOF（-1），但代码检查返回值是否等于0，导致可能无法正确检测失败。虽然当前代码在检查失败后仅打印消息，没有严重后续影响，但违反了API contract。
- D验证: stage_c_preserved / ver_a4b0c48e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 346. hyp_path_0777ed3df2e7

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_01.c:28
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需外部输入；但stdout可能因环境原因（如磁盘满、管道关闭）写入失败导致fputs返回EOF(-1)
- 触发路径: if (fputs("string", stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_01.c:28
- 结论: 函数fputs的返回值检查错误：fputs成功时返回非负整数，失败时返回EOF(-1)，但代码检查返回值是否等于0，导致错误处理逻辑无法正确捕获失败。尽管输入是硬编码字符串，但stdout写入可能因环境原因（如磁盘满、管道关闭）失败，此时fputs返回EOF(-1)，条件==0永不成立，错误未被处理。
- D验证: stage_c_preserved / ver_4bb475cb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 347. hyp_path_0a2f52994e70

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_03.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可能通过填满磁盘、关闭 stdout 等方式使 fputs 失败，无需控制参数。
- 触发路径: if (fputs("string", stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_03.c:30
- 结论: fputs() 的返回值被错误检查：fputs 返回 EOF(-1) 表示失败，但代码将返回值与 0 比较，导致失败时错误处理分支永远不被执行，违反了 CWE-253。
- D验证: stage_c_preserved / ver_58b5061f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 348. hyp_path_f5ac6fef0d0b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_04.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fputs("string", stdout) == 0) { printLine("fputs failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_04.c:36
- 结论: 对fputs()的返回值检查不正确：fputs()失败时返回EOF(-1)，但代码检查返回值是否为0，导致错误处理逻辑无法正确捕获失败。
- D验证: stage_c_preserved / ver_a500736c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 349. hyp_path_737f0b91f63d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_05.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fputs() 调用可能由于 I/O 错误而失败（如 stdout 关闭或缓冲区满）
- 触发路径: if (fputs("string", stdout) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_05.c:36
- 结论: fputs() 的返回值被错误地检查为等于0，但 fputs() 成功时返回非负整数（通常为写入的字符数），失败时返回 EOF (-1)。因此，条件永远不成立，导致 fputs() 失败时无法检测到错误，违反 CWE-253。
- D验证: stage_c_preserved / ver_1a849b60
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 350. hyp_path_0599bda9f209

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_06.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 存在任何导致fputs失败的条件（如系统资源不足）
- 触发路径: if (fputs("string", stdout) == 0) { printLine("fputs failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_06.c:35
- 结论: fputs()的返回值为EOF(-1)表示失败，但代码中错误地检查返回值是否等于0，导致在写入失败时无法正确检测并处理错误，违反CWE-253。
- D验证: stage_c_preserved / ver_3a0fd308
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 351. hyp_path_847f836f20a5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_07.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，fputs失败可能由I/O错误引起，但攻击者无法直接控制。
- 触发路径: if (fputs("string", stdout) == 0) { printLine("fputs failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_07.c:35
- 结论: fputs()的返回值检查错误：fputs成功返回非负值，失败返回EOF(-1)，但代码检查返回值是否等于0，导致fputs失败时错误处理永不触发，错误被忽略。
- D验证: stage_c_preserved / ver_bc1d4e8f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 352. hyp_path_c070b22fff1c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_09.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fputs("string", stdout) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_09.c:30
- 结论: fputs的返回值检查错误：当fputs失败时返回EOF(-1)，但代码检查返回值是否等于0，导致无法检测到失败，违反了CWE-253。
- D验证: stage_c_preserved / ver_3bc2c8cf
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 353. hyp_path_688cd1f99df6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_10.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fputs("string", stdout) == 0) { printLine("fputs failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_10.c:30
- 结论: fputs()函数的返回值检查错误：使用fputs写入stdout时，失败时返回EOF(-1)，但代码检查返回值是否为0，导致无法检测到写入失败。这是一个CWE-253不正确的函数返回值检查漏洞。
- D验证: stage_c_preserved / ver_fd5059b4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 354. hyp_path_d51ea0568325

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_14.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特定攻击者控制输入，但fputs失败依赖于运行时条件（如stdout写入错误）。
- 触发路径: if (fputs("string", stdout) == 0) { printLine("fputs failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_14.c:30
- 结论: 在fputs调用后，代码错误地将返回值与0进行比较，而非检查EOF(-1)。fputs失败时返回EOF，若返回值为0可能表示成功或未写入任何字符，导致错误处理逻辑无法正确检测失败。这违反了API contract，属于CWE-253：对函数返回值的错误检查。
- D验证: stage_c_preserved / ver_4caf66ec
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 355. hyp_path_8c6e4f07ac1e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_13.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fputs()因stdout被关闭或写错误返回EOF(-1)
- 触发路径: if (fputs("string", stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_13.c:30
- 结论: fputs()函数返回值的检查不正确：成功时fputs返回非负整数（通常不是0或可能是0？但根据注释和CWE定义，错误返回EOF(-1)，成功返回非负整数），但代码检查返回值是否等于0，导致当fputs失败返回EOF(-1)或成功返回非0时，条件为假，错误处理代码无法执行，可能隐藏fputs失败的错误。
- D验证: stage_c_preserved / ver_38dd934e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 356. hyp_path_db0bd9f265af

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_15.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入，仅函数调用即可触发错误的错误检查逻辑。
- 触发路径: if (fputs("string", stdout) == 0) { printLine("fputs failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_15.c:31
- 结论: fputs函数返回值被错误检查：代码检查返回值是否等于0，但fputs失败时返回EOF(-1)，成功时返回非负整数。因此当fputs实际成功时，错误地触发失败处理，但不会导致安全后果，仅产生误报日志。违反API contract，符合CWE-253。
- D验证: stage_c_preserved / ver_abeeae7b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 357. hyp_path_a2d37816068f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_16.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fputs 调用可能因 I/O 错误而失败，但攻击者通常无法直接控制这些条件；代码为固定字符串输入。
- 触发路径: if (fputs("string", stdout) == 0) { printLine("fputs failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_16.c:30
- 结论: fputs() 的返回值检查错误：代码将返回值与0比较来判断失败，但实际错误返回值为 EOF (-1)。这种不正确的检查导致无法正确检测 fputs 失败，符合 CWE-253 定义。
- D验证: stage_c_preserved / ver_e13a33de
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 358. hyp_path_c871f5ddf9e1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_18.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fputs("string", stdout) == 0) { printLine("fputs failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_18.c:30
- 结论: fputs函数返回值的检查使用了错误的哨兵值：fputs失败时返回EOF(-1)，但代码检查返回值是否等于0，导致错误处理分支在fputs成功或失败时均不会执行。当fputs失败时，由于条件为假，错误处理被跳过，违反CWE-253（函数返回值检查不正确）。
- D验证: stage_c_preserved / ver_4763e42d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 359. hyp_path_1847d1b3e983

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_02.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制 stdin 输入（例如，提供不匹配的输入或关闭流），使 fscanf 返回非零值（成功或失败）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_02.c:35
- 结论: 函数 fscanf 的返回值检查不正确：代码检查返回值是否等于0，但 fscanf 成功时返回成功匹配的项数（应为1），失败时返回 EOF (-1)。因此，当 fscanf 失败时，条件不为真，错误处理代码不会执行，可能导致后续使用未正确初始化的 data 缓冲区。
- D验证: stage_c_preserved / ver_6a0dcd54
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 360. hyp_path_8c4e7a619b83

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_01.c:33
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特殊前提，攻击者无法直接控制输入影响此检查
- 触发路径: if (fscanf(stdin, "%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_01.c:33
- 结论: 函数 fscanf() 的返回值检查不正确：代码检查返回值是否等于 0，但 fscanf() 成功时返回读取的项数（1），失败时返回 EOF（-1）。因此，当 fscanf() 失败时，检查条件永远不会为真，导致无法检测到失败，后续若使用未初始化的 data 则存在风险。当前代码片段未展示 data 的后续使用，但违反 API contract (CWE-253) 本身构成漏洞模式。
- D验证: stage_c_preserved / ver_49bafe43
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 361. hyp_path_7e747b273007

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_02.c:92
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可以控制标准输入的内容，且输入不匹配格式（如空字符串或非空白字符序列以外的内容）。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_02.c:61; if (fscanf(stdin, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_02.c:84
- 结论: 存在CWE-253（函数返回值检查不正确）：在case11和case12中，fscanf的返回值仅与EOF比较，但正确的做法是检查返回值是否等于期望的输入项数（此处为1）。若输入不匹配格式（如空行或非字符串），fscanf返回0而非EOF，导致未正确处理失败情况，可能使data保持空字符串。尽管当前代码中dataBuffer已初始化为空字符串，且fscanf限制输入长度，未直接导致内存破坏，但返回值检查不符合API规范。
- D验证: stage_c_preserved / ver_bd7b4f8e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 362. hyp_path_827d9e470483

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_02.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，提供空白或格式不匹配的输入使fscanf返回0（理论可能，但实际对于%s极罕见）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_02.c:82
- 结论: fscanf返回值检查不完整：仅检查EOF，未检查返回值是否等于预期匹配项数(1)，当fscanf返回0时，data可能保持未初始化，导致未定义行为。
- D验证: stage_c_preserved / ver_06922ad1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 363. hyp_path_6881ef8a5e30

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_03.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使fscanf返回EOF（如关闭stdin或提供空输入）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == 0) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_03.c:35; data在if之后可能被使用（具体sink点未提供） @ 后续未知
- 结论: 函数fscanf返回值检查不完整：仅检查返回值是否等于0，忽略了EOF(-1)的情况。当fscanf返回EOF时，条件不成立，程序误认为成功，但data未被正确读取，后续使用可能导致未初始化变量或信息泄露。
- D验证: stage_c_preserved / ver_c5864a65
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 364. hyp_path_5a096800fca6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_03.c:93
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向 stdin 提供输入，且输入使 fscanf 返回 0（如空字符串或非匹配格式）。
- 触发路径: static void case12() { ... if (fscanf(stdin, "%99s\0", data) == EOF) { ... } } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_03.c:72-88; void CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_03_case1() { case11(); case12(); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_03.c:90-94
- 结论: fscanf 返回值检查不完整：仅检查了 EOF，未检查实际读取项数，可能遗漏读取失败（如输入为空或格式不匹配）的情况。
- D验证: stage_c_preserved / ver_c50cd2da
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 365. hyp_path_3f611ff917f9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_04.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可关闭stdin或发送EOF信号使fscanf返回EOF，触发错误检查遗漏。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == 0) @ 41
- 结论: fscanf返回值检查错误：检查`==0`而非`==EOF`，导致fscanf失败时错误处理被跳过，违反CWE-253。
- D验证: stage_c_preserved / ver_81e27129
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 366. hyp_path_0b122781fef7

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_03.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使得fscanf返回0
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_03.c:82
- 结论: fscanf返回值检查不完整，仅检查EOF，未检查返回0的情况，违反CWE-253。但缺乏后续使用data的sink证据，漏洞路径未闭合，可能影响较低。需要动态验证或更多上下文。
- D验证: stage_c_preserved / ver_bd9d3763
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 367. hyp_path_c394171a7fff

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_04.c:88
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入，例如空输入或不匹配格式的输入，使fscanf返回0，而代码未处理该情况。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_04.c:88
- 结论: fscanf返回值检查不完整：仅检查了EOF，未处理fscanf返回0（未匹配到任何输入）或其他错误码的情况，违反了CWE-253。
- D验证: stage_c_preserved / ver_4269e805
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 368. hyp_path_780550b482d5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_04.c:69
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，例如提供空字符串或格式不匹配的输入导致fscanf返回0
- 触发路径: if (fscanf(stdin, "%99s", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_04.c:69
- 结论: fscanf返回值检查不完整：仅检查EOF，未检查其他非正返回值（如0），导致当fscanf返回0时data可能未初始化或含旧数据，但代码中未展示后续使用data的sink，因此漏洞路径不闭合。
- D验证: stage_c_preserved / ver_4db7c73c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 369. hyp_path_4269e81cbc22

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_05.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin输入，导致fscanf()返回EOF（例如关闭输入流或提供无效输入）。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_05.c:41
- 结论: fscanf()的返回值检查不正确：fscanf()失败时返回EOF(-1)，但代码仅检查返回值是否为0。当fscanf()返回-1时，错误处理分支不会执行，违反了API contract，构成CWE-253漏洞。尽管后续未使用data，但不正确检查本身成立。
- D验证: stage_c_preserved / ver_d17a19f3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 370. hyp_path_029431ff48d0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_05.c:88
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_05.c:88
- 结论: fscanf返回值检查不完整：仅检查EOF，未检查是否成功读取到期望的项数（返回值应为1），违反CWE-253。
- D验证: stage_c_preserved / ver_fce387c5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 371. hyp_path_48c8772047f9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_06.c:40
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fscanf调用失败，例如输入流提前关闭或读取错误。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_06.c:40
- 结论: 对fscanf的返回值检查不正确：fscanf在失败时返回EOF(-1)，但代码检查是否等于0，导致失败时错误处理不被执行。虽无直接后续data使用，但违反API合约要求正确检查返回值。
- D验证: stage_c_preserved / ver_05418112
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 372. hyp_path_61966e76012d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_07.c:40
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入流，例如通过提供无效数据或提前关闭流导致fscanf失败
- 触发路径: if (fscanf(stdin, "%99s\0", data) == 0) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_07.c:40
- 结论: fscanf()返回值检查错误：函数成功时返回匹配项数1，失败时返回EOF(-1)，但代码检查是否等于0，导致失败情况未被正确处理。
- D验证: stage_c_preserved / ver_8008f6d0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 373. hyp_path_71625759dab4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_06.c:68
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供导致fscanf返回0而非EOF的输入（例如，输入仅包含空白字符或空字符串）。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_06.c:68
- 结论: fscanf返回值检查不完整：仅检查EOF，但未处理返回0的情况，虽然当前代码片段中未显示data的后续使用，但根据CWE-253定义，函数返回值检查缺失仍构成API contract violation，存在潜在安全风险。
- D验证: stage_c_preserved / ver_b591a5e5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 374. hyp_path_709334d1bf18

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_07.c:87
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向stdin输入不匹配%99s格式的内容（如空白、非字符串字符），使fscanf返回0
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_07.c:87
- 结论: fscanf返回值检查不完整：仅检查EOF，未处理匹配失败（返回0）导致API contract违反，攻击者可利用stdin输入不匹配内容使fscanf返回0，从而跳过错误处理，可能导致未初始化内存使用或逻辑错误。
- D验证: stage_c_preserved / ver_ac7df550
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 375. hyp_path_06f3e2a88164

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_07.c:98
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供触发fscanf返回0的输入（如仅空白字符或空行），导致匹配失败。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_07.c:84 (case12) 或 61 (case11)
- 结论: fscanf返回值检查不完整：仅检查EOF错误，未处理返回0（未匹配到任何输入）的情况，导致未检测到的输入错误，违反CWE-253。
- D验证: stage_c_preserved / ver_308e3d34
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 376. hyp_path_8c112a712a5b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_09.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可导致标准输入关闭或发生读取错误（例如在程序的标准输入流上发起EOF信号）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_09.c:35
- 结论: fscanf返回值检查错误：代码检查fscanf返回值是否等于0来判断失败，但fscanf失败时返回EOF（-1），正确检查应为 !=1 或 ==EOF。这导致当fscanf返回EOF时，误认为成功，未处理失败情况。虽然后续未直接使用data，但data可能保持未初始化状态，存在未定义行为风险。
- D验证: stage_c_preserved / ver_fb74aa48
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 377. hyp_path_72db133daa90

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_08.c:106
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供输入，使得fscanf返回值为0（例如输入空白行）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_08.c:106
- 结论: fscanf返回值检查不完整：仅检查了EOF，未处理返回0的情况；但由于读取的数据未被后续代码使用，该缺陷无实际安全影响。
- D验证: stage_c_preserved / ver_07c63247
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 378. hyp_path_373342699e53

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_10.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致fscanf调用失败（如关闭stdin或提供无效输入）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_10.c:35
- 结论: fscanf函数的返回值检查错误：fscanf成功时返回1，失败时返回EOF(-1)；代码检查返回值是否等于0，导致错误条件永远不会触发，fscanf失败时无法正确检测和处理。
- D验证: stage_c_preserved / ver_0859ac05
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 379. hyp_path_0a6dd09f7f00

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_09.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供输入，使得fscanf返回0（例如仅输入空白字符或格式不匹配），从而绕过EOF检查。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_09.c:82
- 结论: fscanf函数的返回值仅检查了EOF，未检查成功读取的项数（应为1）。如果输入未匹配格式（例如空输入或格式错误），fscanf可能返回0，但代码未处理，违反了正确检查函数返回值的契约。虽然当前路径未使用data，但漏洞存在。
- D验证: stage_c_preserved / ver_7e835a86
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 380. hyp_path_4e43de8d4f96

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_10.c:92
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向 stdin 提供不符合格式的输入（如非字符串数据），导致 fscanf 返回 0 而非 EOF。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_10.c:53 (case11); if (fscanf(stdin, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_10.c:79 (case12)
- 结论: fscanf 返回值检查不完整，仅检查等于 EOF，未处理返回 0（转换失败）的情况，导致输入验证不严格，违反 CWE-253。
- D验证: stage_c_preserved / ver_c99e03fb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 381. hyp_path_0910006b3ae6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_10.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供使fscanf返回0的输入（例如空字符串或非%99s匹配的输入）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_10.c:82
- 结论: fscanf返回值检查不完整：仅检查了EOF，未处理返回0（格式不匹配）的情况，违反了CWE-253关于正确检查函数返回值的要求。尽管当前代码片段后续未使用未初始化的dataBuffer，但契约违规本身构成漏洞假设，影响较低，需动态验证确认其他路径是否存在sink。
- D验证: stage_c_preserved / ver_5732218f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 382. hyp_path_255e9f0fbbb8

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_13.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fscanf调用失败（例如输入流到达文件尾或发生读取错误）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == 0) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_13.c:35
- 结论: 函数fscanf的返回值检查不正确：代码检查返回值等于0，但fscanf失败时返回EOF（-1），导致错误路径未被捕获，可能使用未初始化的数据。
- D验证: stage_c_preserved / ver_5fe9aa04
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 383. hyp_path_6152e50e7f7f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_11.c:92
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入，使得fscanf匹配失败（例如仅输入空白字符）。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_11.c:48-69 (case11) 或 72-88 (case12)
- 结论: fscanf返回值检查不完整：仅检查EOF，未检查匹配失败（返回0），违反CWE-253定义。
- D验证: stage_c_preserved / ver_190dba43
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 384. hyp_path_c8cc43f111ca

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_14.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供数据，使得 fscanf() 读取失败（例如，输入提前结束或格式不匹配）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_14.c:35
- 结论: fscanf() 调用失败时返回 EOF (-1) 而非 0，代码错误地检查返回值是否等于 0，违反 API contract (CWE-253)。错误处理未执行，data 缓冲区可能未初始化，后续使用可能导致未定义行为或信息泄露。
- D验证: stage_c_preserved / ver_cc2ddf65
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 385. hyp_path_c3d93252ea34

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_15.c:105
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入，使fscanf因格式不匹配或空输入而返回0，而非EOF。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_15.c:105
- 结论: CWE253: fscanf返回值检查不完整，仅检查EOF，未检查成功读取的item数是否为1，可能导致未检测到的读取失败。
- D验证: stage_c_preserved / ver_ee8eb057
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 386. hyp_path_71041fc2aa9a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_14.c:93
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: Attacker controls stdin input (or the program receives external input via stdin).
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_14.c:72-88 (case12); if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_14.c:48-69 (case11)
- 结论: CWE253: Incorrect check of fscanf return value - only checks for EOF, not for 0 (matching failure) or other negative values.
- D验证: stage_c_preserved / ver_1fcb502f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 387. hyp_path_49de0697bdb4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_15.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使fscanf返回EOF（例如提供空输入或触发读取错误）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == 0) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_15.c:36
- 结论: 函数fscanf的返回值检查不正确，仅检查返回值是否为0，未处理EOF（-1）或其他失败情况，违反了CWE-253。当fscanf返回EOF时，条件不成立，导致错误处理缺失，且data可能未被正确初始化，后续使用data可能导致未定义行为。
- D验证: stage_c_preserved / ver_c03630d8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 388. hyp_path_7aa3cae2768e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_16.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序通过stdin接收输入，攻击者可以提供导致fscanf失败的输入（如提前关闭流或发送不匹配格式的数据）。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == 0) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_16.c:35
- 结论: 在fscanf函数的返回值检查中，错误地将成功返回0作为失败条件，而正确做法应检查是否返回EOF(-1)。这违反了API contract，导致无法正确检测fscanf失败。
- D验证: stage_c_preserved / ver_36d2f945
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 389. hyp_path_0d2d31b207b4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_15.c:69
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供输入使得 fscanf 匹配失败（如输入空行或非字符串），导致返回 0。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_15.c:69
- 结论: fscanf 返回值检查不完整：仅检查 EOF，未验证返回值是否为 1（表示成功读取一项）。若 fscanf 返回 0（输入不匹配格式），则 data 缓冲区保持初始值（通常为空字符串），违反了 CWE-253 对返回值完整检查的要求。实际安全影响有限，因为 dataBuffer 通常初始化为空字符串，且后续仅使用 printLine 输出，不造成敏感信息泄露或代码执行。
- D验证: stage_c_preserved / ver_588a9572
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 390. hyp_path_00b5a384c6db

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_15.c:90
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供导致fscanf返回非EOF错误值的输入（例如非字符串或格式错误）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_15.c:90
- 结论: 函数fscanf返回值检查不完整：仅检查了EOF，未处理其他返回值（如0或负数错误码），违反CWE-253。但代码中未显示对data的后续不安全使用，实际安全影响较低，需要动态验证确认。
- D验证: stage_c_preserved / ver_e4a95e05
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 391. hyp_path_ccd7f1c6fc1a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_18.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可能通过输入导致fscanf失败（例如提供无效输入或触发流错误），但错误未正确报告。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == 0) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_18.c:35
- 结论: fscanf()返回值检查错误：程序检查fscanf返回值是否等于0，但fscanf成功时返回成功匹配的项数（1），失败时返回EOF（-1）。因此条件'==0'永远不会为真，导致错误状态无法被检测和处理。违反了CWE-253（函数返回值的错误检查）。
- D验证: stage_c_preserved / ver_d94335e0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 392. hyp_path_7be2637bb6d6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_01.c:28
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fwrite 调用可能失败（如 stdout 关闭、I/O 错误等）
- 触发路径: if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0) { printLine("fwrite failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_01.c:28
- 结论: fwrite() 返回值检查错误：fwrite 返回 size_t 类型，非负，但代码检查返回值是否小于 0，该条件永远不成立，导致写失败无法被正确处理，违反了 CWE-253 正确检查函数返回值的规范。
- D验证: stage_c_preserved / ver_931f5b8f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 393. hyp_path_21bb0c6cdc03

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_18.c:57
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入; dataBuffer未初始化
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_18.c:57
- 结论: fscanf返回值检查不完整：只检查EOF，忽略返回值为0或成功的情况；若fscanf返回0（输入不匹配格式），dataBuffer未更新且未初始化，导致使用未初始化数据。
- D验证: stage_c_preserved / ver_6417c539
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 394. hyp_path_88c3b409cfc9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_02.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fwrite调用可能失败（例如输出重定向到磁盘满）
- 触发路径: if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_02.c:30
- 结论: fwrite返回值的检查使用了<0，但fwrite返回类型为size_t（无符号整数），因此<0比较永远为假，导致任何错误（包括完全失败和部分写入）都无法被检测，违反了CWE-253。
- D验证: stage_c_preserved / ver_e535e017
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 395. hyp_path_04967d10e4d1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_03.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 磁盘空间不足、权限不足等导致 fwrite 失败的外部条件
- 触发路径: if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_03.c:30
- 结论: fwrite 返回值检查错误：fwrite 返回 size_t，比较 <0 永远为假，导致写入失败无法检测，违反 CWE-253。写入固定字符串，无攻击者输入，但违反 API contract。
- D验证: stage_c_preserved / ver_d4decc10
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 396. hyp_path_187d461f36be

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_04.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 需要fwrite执行失败（如stdout不可写或磁盘空间不足）
- 触发路径: if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0) { printLine("fwrite failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_04.c:36
- 结论: fwrite返回值检查错误：代码检查返回值是否小于0，但fwrite返回size_t类型，成功时返回写入的元素数，失败时返回小于请求数的非负值，永远不会小于0。因此错误条件无法被正确检测，违反了CWE-253（Incorrect Check of Function Return Value）。蓝队确认无误报。
- D验证: stage_c_preserved / ver_c290b839
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 397. hyp_path_116b90136901

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_05.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_05.c:36
- 结论: fwrite()返回值检查不正确：检查返回值是否小于0，但fwrite成功时返回写入的对象数（无符号），失败时返回小于count的正整数（通常为0），从未返回负数。因此条件'<0'恒为假，导致错误无法被捕获。
- D验证: stage_c_preserved / ver_8c6f16da
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 398. hyp_path_9fb65fd0521e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_06.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者控制输入，代码本身存在API misuse。
- 触发路径: if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_06.c:35
- 结论: 代码检查fwrite返回值是否小于0，但fwrite返回size_t（无符号），永远非负，因此条件永不成立，无法检测写入失败。这违反了API contract，属于CWE-253。
- D验证: stage_c_preserved / ver_d2c13340
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 399. hyp_path_886716c5bb59

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_07.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fwrite 执行过程中发生错误（如输出设备失败）。
- 触发路径: if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_07.c:35
- 结论: fwrite返回值检查错误：使用 '<0' 判断失败，但 fwrite 返回 size_t 类型，永远不小于0，导致无法检测写入失败，违反 CWE-253。
- D验证: stage_c_preserved / ver_5c26e525
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 400. hyp_path_e393e6faaf24

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_09.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fwrite写入stdout时发生部分写入（如信号中断或输出流限制），但未完全失败，返回值在0到strlen-1之间。
- 触发路径: if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0) { printLine("fwrite failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_09.c:30
- 结论: fwrite返回值检查不完整：仅检查返回值是否小于0，但未检查是否等于预期写入元素数，允许部分写入（返回值在0到strlen-1之间）不被视为错误，导致潜在数据不完整且无告警。
- D验证: stage_c_preserved / ver_529338c1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 401. hyp_path_044ea520504e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_10.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fwrite调用失败（例如stdout关闭、磁盘满）
- 触发路径: if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_10.c:30
- 结论: 函数fwrite的返回值检查错误：使用<0判断失败，但fwrite的返回类型是size_t（无符号），失败时返回0，因此条件永远不会为真，无法检测到写入失败。这违反了API contract，可能导致未处理的写入错误。
- D验证: stage_c_preserved / ver_590600af
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 402. hyp_path_e36b1d397fe2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_13.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: stdout写入操作可能因系统资源不足等原因失败，导致fwrite返回0或小于请求数的非负值。
- 触发路径: if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0) { printLine("fwrite failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_13.c:30
- 结论: fwrite的返回值被错误地检查是否小于0，且fwrite返回类型为size_t（无符号），因此条件<0永远为假，无法检测任何失败情况。即使fwrite失败返回0或小于请求数的非负值，错误处理也不会触发，违反了CWE-253正确检查函数返回值的要求。
- D验证: stage_c_preserved / ver_ce890c18
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 403. hyp_path_62a49d6455b7

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_14.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者输入，代码本身固有的错误检查逻辑缺陷。
- 触发路径: if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_14.c:30
- 结论: fwrite返回值检查错误：fwrite返回写入的对象数，成功时等于请求数，失败时小于请求数但不会为负。代码检查返回值<0永远为假，导致无法检测写入失败，违反了CWE-253（函数返回值错误检查）。
- D验证: stage_c_preserved / ver_a130b63b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 404. hyp_path_af4dd6a9a6c6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_15.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fwrite操作因外部条件（如stdout不可写、磁盘空间不足）而失败
- 触发路径: if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_15.c:31; printLine("fwrite failed!"); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_15.c:33
- 结论: fwrite返回值检查错误：使用<0检查失败，但fwrite在失败时返回的是小于请求大小的非负整数，永远不会返回负数，因此错误条件永不为真，导致写入失败时无法正确检测和处理。
- D验证: stage_c_preserved / ver_7f8371c6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 405. hyp_path_907cacb83745

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_18.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_18.c:30
- 结论: fwrite返回值检查不正确：仅检查返回值是否小于0，忽略了部分写入的情况（返回值小于请求大小但非负），违反了CWE253。
- D验证: stage_c_preserved / ver_309fb289
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 406. hyp_path_b018d4e98067

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_16.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_16.c:30
- 结论: fwrite返回值检查错误：使用 < 0 检查失败，但fwrite返回实际写入的元素数，失败时返回小于请求数的值，不一定是负数。导致无法正确检测fwrite失败。
- D验证: stage_c_preserved / ver_80a79c4c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 407. hyp_path_48cd6f96c612

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_01.c:28
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putc调用实际失败（如stdout关闭或缓冲满）时，错误处理不会被触发，但漏洞本身在于错误检查逻辑错误，无需攻击者控制。
- 触发路径: if (putc((int)'A', stdout) == 0) { printLine("putc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_01.c:28
- 结论: putc函数返回值检查错误：检查是否等于0，但putc失败时返回EOF(-1)而非0，导致错误被忽略（CWE-253）。
- D验证: stage_c_preserved / ver_61bdfe4a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 408. hyp_path_431c03d3114e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_02.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: stdout写入失败（如stdout被关闭或写入错误），但无法由攻击者直接触发
- 触发路径: if (putc((int)'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_02.c:30
- 结论: putc() 的返回值检查错误：putc() 在失败时返回 EOF (-1)，但代码检查返回值是否为 0，这导致 putc() 失败时不会被正确检测到。
- D验证: stage_c_preserved / ver_9cb762e4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 409. hyp_path_2519eb102c0e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_03.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putc 执行时 stdout 可能处于错误状态或不可写，导致返回 EOF。
- 触发路径: if (putc((int)'A', stdout) == 0) { printLine("putc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_03.c:30
- 结论: putc() 的返回值检查错误：putc 失败时返回 EOF（-1），但代码检查返回值是否等于 0，导致错误处理无法正确捕获失败。
- D验证: stage_c_preserved / ver_72e7be9f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 410. hyp_path_72d8066d4963

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_04.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者需要能够导致stdout写入失败（例如关闭标准输出或重定向到设备满等），但通常情况下难以控制，所以可利用性较低
- 触发路径: if (putc((int)'A', stdout) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_04.c:36
- 结论: 函数putc的返回值检查错误：将返回值与0比较，但putc失败时返回EOF(-1)，成功时返回写入字符（非0）。这导致putc失败时不会被正确检测，可能误判成功。虽然影响程度较低（仅影响错误处理逻辑），但违反了CWE-253。
- D验证: stage_c_preserved / ver_37c8e77b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 411. hyp_path_6407cbd61343

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_05.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 标准输出流(stdout)出现错误导致putc失败
- 触发路径: if (putc((int)'A', stdout) == 0) { printLine("putc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_05.c:36
- 结论: putc函数返回EOF(-1)表示失败，而代码检查返回值是否等于0，导致错误处理条件永假，putc失败时程序不处理错误，可能引发数据丢失或未定义行为。
- D验证: stage_c_preserved / ver_065aa1b6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 412. hyp_path_dfdfeb8b3af1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_06.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序运行时putc可能因I/O错误失败
- 触发路径: if (putc((int)'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_06.c:35
- 结论: putc()函数在失败时返回EOF（-1），但代码错误地检查返回值是否为0，导致错误条件可能不会被正确捕获，违反CWE-253。
- D验证: stage_c_preserved / ver_0345c077
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 413. hyp_path_d443e7d9d713

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_07.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致putc()失败，例如通过使stdout处于错误状态（如关闭文件描述符或写满磁盘）
- 触发路径: if (putc((int)'A', stdout) == 0) { printLine("putc failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_07.c:35
- 结论: 函数putc()的返回值检查不正确：putc()失败时返回EOF(-1)而非0，但代码将返回值与0比较，导致无法正确检测putc()的失败，违反了API contract，属于CWE-253。
- D验证: stage_c_preserved / ver_18565c1d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 414. hyp_path_a9bc46c73c16

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_09.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者输入；代码执行到该路径时，putc() 可能因 I/O 错误失败。
- 触发路径: if (putc((int)'A', stdout) == 0) { printLine("putc failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_09.c:30
- 结论: 函数 putc() 返回失败指示值为 EOF (-1)，但代码错误地检查返回值是否等于 0，导致 putc() 失败时无法检测到错误。这是一个 CWE-253 违反：不正确的函数返回值检查。
- D验证: stage_c_preserved / ver_486fa344
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 415. hyp_path_a4a96dfd201f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_10.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需外部输入，代码自动执行；但putc可能因系统资源不足等原因失败。
- 触发路径: if (putc((int)'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_10.c:30
- 结论: 函数putc的返回值检查错误：putc失败时返回EOF(-1)，成功时返回写入的字符，但代码检查返回值是否等于0，既不能正确检测失败也不能保证成功，违反API contract。
- D验证: stage_c_preserved / ver_2cd5c77e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 416. hyp_path_38a4f7514cb3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_13.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putc()可能因输出错误（如stdout关闭或磁盘满）而失败，返回EOF(-1)
- 触发路径: if (putc((int)'A', stdout) == 0) { printLine("putc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_13.c:30
- 结论: 在CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_13.c中，putc()的返回值检查使用了错误的条件：putc()返回EOF(-1)表示失败，但代码检查返回值是否为0。这导致putc()失败时不会被正确检测，违反API contract，属于CWE-253错误返回值检查。
- D验证: stage_c_preserved / ver_8baa26f4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 417. hyp_path_95773e08126b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_15.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (putc((int)'A', stdout) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_15.c:31
- 结论: putc函数的返回值被错误地与0比较，而putc失败时返回EOF(-1)而非0，导致错误处理条件永不为真，属于CWE-253返回值检查错误。
- D验证: stage_c_preserved / ver_d4d1b163
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 418. hyp_path_93b0e1b02680

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_14.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，但putc可能因输出错误（如stdout关闭）失败
- 触发路径: if (putc((int)'A', stdout) == 0) { printLine("putc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_14.c:30
- 结论: putc()函数返回值检查错误：代码检查putc返回值是否等于0，而putc失败时返回EOF(-1)，因此当putc失败时不会执行错误处理，导致错误被忽略。这违反了CWE-253 (Incorrect Check of Function Return Value)。
- D验证: stage_c_preserved / ver_aa492469
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 419. hyp_path_840d41a60cdb

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_16.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putc() 调用可能由于文件系统错误、权限问题等返回 EOF (-1)
- 触发路径: if (putc((int)'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_16.c:30
- 结论: 函数 putc() 的返回值检查错误：putc() 失败时返回 EOF (-1)，但代码检查是否等于 0，导致失败情况无法被正确检测和处理。
- D验证: stage_c_preserved / ver_fabebae3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 420. hyp_path_430ae43b5f2f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_18.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: No attacker-controlled input required; failure depends on runtime conditions (e.g., disk full, stdout closed).
- 触发路径: if (putc((int)'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_18.c:30
- 结论: Incorrect check of putc return value: the code checks if the return value equals 0, but putc returns EOF (-1) on failure, so failure may go undetected.
- D验证: stage_c_preserved / ver_46838732
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 421. hyp_path_f3f73a52d960

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_02.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无，该漏洞由代码自身逻辑错误导致，不依赖于外部输入或条件。
- 触发路径: if (putchar((int)'A') == 0) { printLine("putchar failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_02.c:30
- 结论: putchar() 的返回值检查错误：putchar() 成功时返回写入的字符（'A'），失败时返回 EOF（-1），永远不会返回 0。因此，条件 'putchar((int)'A') == 0' 永远不会成立，导致 putchar() 失败时不会被正确检测和处理，违反 CWE-253 定义。
- D验证: stage_c_preserved / ver_207ade2f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 422. hyp_path_93dc5109e5ed

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_01.c:28
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (putchar((int)'A') == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_01.c:28
- 结论: 函数 putchar 的返回值检查错误：putchar 失败时返回 EOF (-1)，但代码将其与 0 比较。这种检查无法正确检测 putchar 失败，可能导致程序在 putchar 实际失败时误认为成功，或在成功时误认为失败。
- D验证: stage_c_preserved / ver_55b65af6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 423. hyp_path_ce8c5a114972

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_03.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putchar()调用可能失败（例如输出流错误），但无需攻击者控制输入。
- 触发路径: if (putchar((int)'A') == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_03.c:30
- 结论: putchar()的返回值检查错误：putchar()成功时返回写入的字符（非0），失败时返回EOF(-1)，但代码检查返回值是否等于0，导致错误永远不会被检测到。这违反了CWE-253（不正确的函数返回值检查）。
- D验证: stage_c_preserved / ver_28d4abbc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 424. hyp_path_a1c2cee3dd0a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_04.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (putchar((int)'A') == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_04.c:36
- 结论: 函数putchar()的返回值检查错误：putchar()失败返回EOF(-1)，而不是0。代码检查返回值是否等于0来判定失败，导致对putchar()失败的错误处理缺失。
- D验证: stage_c_preserved / ver_715faadd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 425. hyp_path_7e23a0bf3de4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_05.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 输出设备可能处于错误状态（如磁盘满、stdout 关闭），但其并非由攻击者直接控制；然而错误检查缺陷本身独立于输入控制。
- 触发路径: if (putchar((int)'A') == 0) { printLine("putchar failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_05.c:36
- 结论: 函数 putchar() 的返回值被错误地检查为等于 0，而实际失败时返回 EOF (-1)，导致 putchar 失败时无法正确检测并处理错误。
- D验证: stage_c_preserved / ver_30e53b26
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 426. hyp_path_09a92719fd28

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_06.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特殊前提，程序执行到此代码路径即可。
- 触发路径: if (putchar((int)'A') == 0) { printLine("putchar failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_06.c:35
- 结论: putchar()返回值检查错误：函数成功时返回写入的字符（非0），失败时返回EOF（-1）。代码检查返回值是否为0，而当putchar失败时返回EOF（-1），不是0，因此无法检测到失败，违反CWE-253。
- D验证: stage_c_preserved / ver_6872a9a4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 427. hyp_path_d499786a30cf

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_07.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putchar() 调用失败（例如 stdout 被关闭或写入错误）
- 触发路径: if (putchar((int)'A') == 0) { printLine("putchar failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_07.c:35
- 结论: 对 putchar() 的返回值检查使用了错误的 sentinel 值（0），而实际失败返回值是 EOF（-1），违反 CWE-253。
- D验证: stage_c_preserved / ver_19fcec43
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 428. hyp_path_7201e45d97b2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_10.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，仅API误用
- 触发路径: if (putchar((int)'A') == 0) { printLine("putchar failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_10.c:30
- 结论: putchar()的返回值检查错误：putchar()成功时返回写入的字符（非负值），失败时返回EOF（-1）。但代码将返回值与0比较，导致无法检测到putchar失败。
- D验证: stage_c_preserved / ver_6603aec5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 429. hyp_path_d4c91ab517fe

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_09.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 能够使putchar调用失败（如关闭标准输出或填满缓冲区）
- 触发路径: if (putchar((int)'A') == 0) { printLine("putchar failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_09.c:30
- 结论: 对putchar函数的返回值进行了错误检查：putchar失败时返回EOF（-1），但代码检查返回值是否等于0，导致putchar失败时不会被正确检测到。
- D验证: stage_c_preserved / ver_8b956957
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 430. hyp_path_35c67e2415ac

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_13.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putchar函数执行失败（例如输出流错误）返回EOF(-1)。
- 触发路径: if (putchar((int)'A') == 0) { printLine("putchar failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_13.c:30
- 结论: 对putchar的返回值检查错误：putchar失败返回EOF(-1)，但代码检查返回值是否为0，导致错误条件无法触发。
- D验证: stage_c_preserved / ver_5e61a165
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 431. hyp_path_2551869f07a6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_14.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制；任何执行路径都会触发该错误检查逻辑。
- 触发路径: if (putchar((int)'A') == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_14.c:30
- 结论: putchar()返回值的检查不正确：putchar成功时返回写入的字符（非零），失败时返回EOF（-1），永远不会返回0。代码中检查是否等于0，导致错误检测永远为假，违反CWE-253。
- D验证: stage_c_preserved / ver_a2b67060
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 432. hyp_path_ac656540409c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_15.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: No specific attacker control needed; putchar failure is environmental (e.g., I/O error).
- 触发路径: if (putchar((int)'A') == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_15.c:31
- 结论: CWE-253: Incorrect Check of Function Return Value. The code calls putchar() and checks if the return value equals 0, but putchar() returns the written character on success (e.g., 'A'=65) or EOF (-1) on failure. Neither equals 0, so the error check is always false and the error handling never executes.
- D验证: stage_c_preserved / ver_53c8e45f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 433. hyp_path_81ec34bf86d7

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_16.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序执行到该代码路径，且 putchar 可能因输出错误而失败。
- 触发路径: if (putchar((int)'A') == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_16.c:30
- 结论: 函数 putchar 的返回值检查不正确。putchar 成功时返回写入的字符（非负），失败时返回 EOF(-1)。代码中错误地检查返回值是否等于 0，导致可能无法正确检测输出失败。
- D验证: stage_c_preserved / ver_29c71786
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 434. hyp_path_169e32776e21

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_18.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putchar 函数执行失败（例如输出错误），返回 EOF。
- 触发路径: if (putchar((int)'A') == 0) { printLine("putchar failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_18.c:30
- 结论: 对 putchar 函数的返回值进行了错误的检查：putchar 失败时返回 EOF（-1），但代码检查返回值是否为 0，导致可能无法正确检测 putchar 失败。
- D验证: stage_c_preserved / ver_fef4e163
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 435. hyp_path_c3c15addf2ec

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_01.c:34
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序运行环境中puts()调用可能失败（如标准输出流关闭或写入错误），无需攻击者输入控制。
- 触发路径: if (PUTS("string") == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_01.c:34
- 结论: puts()函数的返回值检查错误：puts()失败时返回EOF(-1)，成功时返回非负整数（可能为0）。代码检查返回值是否等于0，导致当puts失败时条件为假，错误处理分支不执行；而当puts成功返回0时反而执行了错误处理，混淆了成功与失败。这违反了CWE-253（函数返回值的错误检查），实际影响是puts失败时无法被检测和处理。
- D验证: stage_c_preserved / ver_23b7e83e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 436. hyp_path_2821f9555755

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_02.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序运行时，puts()可能失败的环境（如stdout被关闭或写入错误）
- 触发路径: if (PUTS("string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_02.c:36
- 结论: 代码对puts()的返回值进行了错误检查：将成功返回0视为失败条件，而实际失败返回EOF(-1)不被捕获。虽然参数为固定字符串，不影响API misuse的存在，但触发条件依赖于puts()实际失败（如stdout不可写），且后续仅执行printLine，无进一步安全影响，因此漏洞存在但风险较低。
- D验证: stage_c_preserved / ver_eede3828
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 437. hyp_path_0621a3db141d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_03.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无攻击者输入控制，函数调用可能因系统资源耗尽等原因失败。
- 触发路径: if (PUTS("string") == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_03.c:36
- 结论: puts()函数调用后，错误地检查返回值是否为0，而实际puts失败返回EOF(-1)，成功返回非负值。条件PUTS("string") == 0永远无法为真，导致puts失败时不会被检测到，违反CWE-253错误检查函数返回值。
- D验证: stage_c_preserved / ver_d38456ad
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 438. hyp_path_9f0ed0be091a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_04.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者控制输入，但若puts因环境原因（如stdout关闭）失败，则错误检查不会触发，导致静默失败。
- 触发路径: if (PUTS("string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_04.c:42
- 结论: 函数puts的返回值检查错误：当puts成功返回0时，代码错误地输出'puts failed!'；当puts失败返回EOF(-1)时，条件不成立，不会输出错误信息。这违反了CWE-253（函数返回值检查不正确），可能导致错误处理逻辑失效或误导。
- D验证: stage_c_preserved / ver_1e7b4c5f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 439. hyp_path_74c24ed3cd04

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_05.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无，该漏洞仅取决于编程错误，无需外部输入。
- 触发路径: if (PUTS("string") == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_05.c:42
- 结论: 错误检查函数返回值：puts()失败返回EOF(-1)，但代码检查返回值是否等于0，导致当puts成功返回0时错误地认为失败，反之当puts实际失败时可能漏检。
- D验证: stage_c_preserved / ver_8b8e6ee3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 440. hyp_path_981e25889354

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_06.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响puts()执行环境（如耗尽磁盘空间、关闭stdout等），但通常难以远程触发。
- 触发路径: if (PUTS("string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_06.c:41
- 结论: 函数puts()失败时返回EOF(-1)，但代码检查返回值是否等于0，导致错误处理逻辑无法在puts()失败时正确执行，违反API contract（CWE-253：不正确检查函数返回值）。
- D验证: stage_c_preserved / ver_6b520e7b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 441. hyp_path_d54b824704e2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_07.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (PUTS("string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_07.c:41
- 结论: 对puts()的返回值检查错误：成功时返回非负整数（通常为0），失败时返回EOF(-1)，但代码检查返回值是否为0，导致成功时错误触发失败处理，失败时无法捕获错误，违反了CWE-253。
- D验证: stage_c_preserved / ver_f879e07a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 442. hyp_path_a59ddca52a7e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_10.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (PUTS("string") == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_10.c:36
- 结论: 函数 puts() 的返回值检查错误：puts() 失败时返回 EOF (-1)，但代码检查返回值是否等于 0，导致无法正确检测失败。
- D验证: stage_c_preserved / ver_7f4d8967
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 443. hyp_path_be5e86a042c4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_09.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序运行环境可能导致 puts() 失败（如磁盘满、输出流错误），但攻击者不能直接控制 puts() 的参数。
- 触发路径: if (PUTS("string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_09.c:36
- 结论: 函数 puts() 的返回值检查错误：代码检查返回值是否等于 0，而 puts() 失败时返回 EOF (-1)，成功时返回非负整数（通常不为 0）。因此错误条件永远不会被触发，导致 puts() 失败时无法被正确检测。尽管输入为字符串字面量，环境因素（如输出流错误）仍可能导致失败，但缺乏正确处理，属于 API misuse 缺陷，但无直接安全利用路径，仅为可靠性问题。
- D验证: stage_c_preserved / ver_0e9be774
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 444. hyp_path_1f74535aed8e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_13.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (PUTS("string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_13.c:36
- 结论: 函数puts()的返回值检查错误：标准规定成功返回非负值（通常0），失败返回EOF(-1)，但代码检查返回值是否等于0作为失败条件，导致puts()实际失败（返回-1）时不会触发错误处理分支，违反CWE-253。
- D验证: stage_c_preserved / ver_376e1e09
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 445. hyp_path_ca1cc107c9e6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_14.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者控制输入；漏洞由开发者错误检查返回值直接导致。puts()的参数字符串常量，失败可能性较低，但运行时仍可能因输出流错误等失败。
- 触发路径: if (PUTS("string") == 0) { printLine("puts failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_14.c:36
- 结论: 函数puts()的返回值检查错误：成功时返回非负整数，失败时返回EOF(-1)，但代码将返回值与0比较来判断失败，导致无法正确检测puts()失败。
- D验证: stage_c_preserved / ver_9eb8ee45
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 446. hyp_path_ea6ac6f09643

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_15.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (PUTS("string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_15.c:35-39
- 结论: 函数puts()的返回值被错误地检查为等于0，而实际成功返回非负数，失败返回EOF(-1)。这导致puts()失败时无法被检测到，违反了API contract。
- D验证: stage_c_preserved / ver_7ef2de30
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 447. hyp_path_3094f162db70

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_16.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无额外攻击者控制输入；漏洞由编码错误本身导致。
- 触发路径: if (PUTS("string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_16.c:36
- 结论: 在检查 puts() 的返回值时，代码错误地将成功返回与 0 比较，而 puts() 成功时返回非负整数（非 0），失败时返回 EOF (-1)。因此条件 'PUTS("string") == 0' 永不为真，导致错误处理分支（printLine) 永远不会被执行。这违反了 CWE-253 (Incorrect Check of Function Return Value)，导致对 puts() 失败的检测完全失效。
- D验证: stage_c_preserved / ver_05884890
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 448. hyp_path_36ef53e85e86

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_18.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可通过环境因素（如磁盘满、管道关闭、stdout重定向等）导致puts返回EOF，但代码错误地将成功(0)识别为失败，失败(-1)识别为成功，导致忽略真正的错误。
- 触发路径: if (PUTS("string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_18.c:36
- 结论: 在CWE253_Incorrect_Check_of_Function_Return_Value__char_puts_18.c中，puts()函数的返回值被错误地检查：成功时返回0，失败时返回EOF(-1)，但代码却检查是否等于0来判断失败，导致puts失败时无法识别，puts成功时误判为失败。虽然直接后果只是错误消息输出，但违反了API合同（CWE-253）。
- D验证: stage_c_preserved / ver_cc4928d2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 449. hyp_path_cf537667cd35

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_01.c:33
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入流，导致 scanf 返回非0值（如 EOF）或成功返回1，但检查逻辑错误地只处理返回0的情况。
- 触发路径: if (scanf("%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_01.c:33
- 结论: 函数 scanf() 的返回值检查错误：代码检查返回值是否等于0，但 scanf 成功时返回成功匹配项数（此处为1），失败时返回 EOF（-1）。因此，当 scanf 失败时，条件 scanf(...)==0 为假，不会执行错误处理，导致忽略输入失败。这违反了 CWE-253（函数返回值的不正确检查）的 API contract。
- D验证: stage_c_preserved / ver_48a431a6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 450. hyp_path_ced54cdd65db

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_02.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特殊前提，任何输入场景下都可能发生
- 触发路径: if (scanf("%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_02.c:35
- 结论: 对 scanf 的返回值进行了不正确的检查，检查是否等于0，但 scanf 失败时返回 EOF (-1)，因此该检查无法捕获所有失败情况，可能导致未正确处理输入失败。
- D验证: stage_c_preserved / ver_17adf542
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 451. hyp_path_0dc9bc863ba1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_01.c:52
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供不符合%99s格式的输入（例如空输入或非字符串），使scanf返回0。
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_01.c:52
- 结论: 函数scanf的返回值检查不完整：仅检查了EOF，而未检查返回值小于1的情况（例如输入不匹配%99s时返回0），导致错误状态可能被忽略。虽然后续没有直接使用未初始化的数据，但违反了CWE-253对函数返回值正确检查的要求，影响较低。
- D验证: stage_c_preserved / ver_06eed0d8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 452. hyp_path_7543539f3849

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_03.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过关闭标准输入或发送 EOF 使 scanf() 失败，导致 data 未初始化
- 触发路径: if (scanf("%99s\0", data) == 0) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_03.c:35
- 结论: 对 scanf() 返回值的错误检查：代码检查 scanf() 返回值是否等于 0，但 scanf() 成功时返回 1，失败时返回 EOF(-1)，因此此检查无法正确捕获失败情况，导致在 scanf() 失败时 data 可能未初始化，后续使用 data 将导致未定义行为。
- D验证: stage_c_preserved / ver_006f05b8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 453. hyp_path_2d5d03f2ac11

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_02.c:92
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供输入（例如空字符串或非匹配字符），使得scanf返回0而不是EOF或1。
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_02.c:85
- 结论: 在case12中，scanf函数的返回值检查不正确：仅检查是否返回EOF，而未检查返回值是否等于期望的输入项数（1）。当scanf返回0（无匹配项）时，代码误认为成功，导致未正确处理，构成CWE-253违规。
- D验证: stage_c_preserved / ver_b02e7a4f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 454. hyp_path_4690fad4cfd3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_03.c:92
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序执行case12路径（5==5为真）; 用户输入不匹配"%99s"格式（例如输入空行或非字符串内容），导致scanf返回0
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_03.c:82
- 结论: 函数case12中调用scanf后，仅检查返回值是否为EOF，未检查返回值是否等于期望的输入项数（1）。当输入数据格式不匹配或空输入时，scanf可能返回0，导致变量data未更新，虽然dataBuffer已初始化为空字符串，但违反了CWE-253关于正确检查函数返回值的规则。影响较低，因为dataBuffer初始化为空字符串避免了未初始化风险，但API contract被违反。
- D验证: stage_c_preserved / ver_f5ec35f7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 455. hyp_path_ac42436812bf

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_02.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入流
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_02.c:63
- 结论: 函数scanf的返回值检查不完整：代码仅检查返回值是否等于EOF，而未检查是否成功读取了预期数量的项目（即1）。当scanf返回0（例如输入仅包含空白字符但未遇到EOF）时，程序误认为操作成功，继续使用未初始化的dataBuffer变量，可能导致未定义行为。
- D验证: stage_c_preserved / ver_62d80d1b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 456. hyp_path_c222b523dd6f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_02.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入，并通过输入空白字符或换行使scanf返回0。
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_02.c:82-84
- 结论: 对scanf的返回值检查不完整，仅检查了EOF，未处理返回0的情况，违反CWE-253。尽管后续使用仅限于printLine，风险较低，但API contract violation仍然存在。
- D验证: stage_c_preserved / ver_a5465712
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 457. hyp_path_2e5bd515813e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_04.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin输入流，使得scanf()返回EOF（例如，关闭stdin或使其出错）
- 触发路径: if (scanf("%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_04.c:41
- 结论: 代码中scanf()的返回值被错误地检查是否等于0，违反了CWE-253（函数返回值的不正确检查）。根据C标准，scanf()成功时返回成功匹配的输入项数（此处应为1），失败时返回EOF（-1）。条件scanf(...)==0无法捕获EOF或其它失败情况，导致失败处理分支不被执行。虽然当前代码中data变量未在后续使用，但返回值检查错误本身构成CWE-253违规。
- D验证: stage_c_preserved / ver_8be361fc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 458. hyp_path_2eb7e262830b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_03.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 用户通过 stdin 提供输入，可以导致 scanf 返回非 EOF 的错误值（如 0），例如输入空行或不匹配格式的字符。
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_03.c:82
- 结论: 对 scanf 返回值的检查不正确，仅检查是否等于 EOF，而忽略了其他错误情况（如返回 0），导致可能使用未正确读取的数据。
- D验证: stage_c_preserved / ver_289b3444
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 459. hyp_path_0fe60988b9ef

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_04.c:69
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供不符合格式的输入，导致scanf返回0而非EOF。
- 触发路径: if (scanf("%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_04.c:69
- 结论: 函数scanf返回值检查不完整：仅检查了EOF（错误或文件尾），未检查返回值是否为期望的读取项数1。当scanf因输入格式不匹配返回0时，程序未处理且未使用dataBuffer，但根据API规范，应检查完整返回值以避免未定义行为。此违规本身可被静态检测，但动态利用路径不完整。
- D验证: stage_c_preserved / ver_2283b2c7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 460. hyp_path_9b0a3f15915d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_05.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致scanf失败，例如提前关闭标准输入或提供无效输入导致读取错误
- 触发路径: if (scanf("%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_05.c:41
- 结论: scanf()返回值检查错误：检查是否为0，但失败时返回EOF(-1)，导致错误未被正确处理。虽然当前代码片段未展示后续使用未初始化data的sink，但该检查错误本身构成CWE-253违规，存在潜在风险。
- D验证: stage_c_preserved / ver_17bdb58e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 461. hyp_path_9240feaccdee

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_04.c:88
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: Attacker can provide input that causes scanf to return 0 (matching failure) without reaching EOF, e.g., empty input or format mismatch.
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_04.c:88
- 结论: CWE-253: Incorrect Check of Function Return Value - scanf() return value only checked for EOF, not for return value 0 (matching failure). This violates the API contract as scanf should return 1 on successful input. However, the provided code snippet lacks a subsequent sink that uses the potentially uninitialized data buffer, making the exploitability unconfirmed.
- D验证: stage_c_preserved / ver_fd2d7b16
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 462. hyp_path_8b8f48553da9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_06.c:40
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序执行到scanf调用时，输入流可能遇到错误或EOF。
- 触发路径: if (scanf("%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_06.c:40
- 结论: scanf()函数的返回值检查不正确：代码检查返回值是否等于0，但根据C标准，scanf失败时返回EOF(-1)，而非0。因此当scanf返回EOF时，条件不满足，错误被忽略，可能导致未定义行为。
- D验证: stage_c_preserved / ver_d6d27bd9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 463. hyp_path_43eab2fd644a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_05.c:88
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供输入，使得 scanf() 返回 0（例如输入空字符串或非匹配字符）。
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_05.c:88
- 结论: CWE253: Incorrect Check of Function Return Value - scanf() return value is only checked against EOF, but not against other failure values (e.g., 0 when no input matches). This can lead to use of uninitialized data if scanf returns 0.
- D验证: stage_c_preserved / ver_e7d68f10
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 464. hyp_path_d237334b085c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_07.c:40
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可以通过输入EOF或导致scanf失败，使得返回值不为0亦不为正数
- 触发路径: if (scanf("%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_07.c:40; printLine("scanf failed!"); // 仅在返回值为0时执行，但实际失败返回-1不会执行 @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_07.c:42
- 结论: 对scanf的返回值检查错误：代码检查scanf返回值是否等于0，但scanf在失败时返回EOF(-1)，成功时返回成功匹配的项目数（此处为1）。因此，当scanf失败时，条件不成立，错误未被正确处理，且data变量可能未初始化后被使用。
- D验证: stage_c_preserved / ver_47b83720
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 465. hyp_path_7beb6fb86cae

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_06.c:68
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向程序标准输入提供恶意输入，使 scanf 匹配失败（返回0）而非返回 EOF
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_06.c:68
- 结论: 函数 scanf 的返回值检查不完整：仅检查了 EOF，未处理输入匹配失败（返回0）的情况，导致 data 可能未被正确赋值而继续使用。尽管当前代码片段中后续仅有 printLine 调用，未见 data 被直接用于敏感操作，但该漏洞违反 CWE-253 定义，且在实际应用中可能通过未初始化或错误赋值引发后续安全后果（如堆栈信息泄露、程序逻辑异常）。需要 D 验证或审计完整函数上下文确认是否存在真正的 sink 路径。
- D验证: stage_c_preserved / ver_8efaa345
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 466. hyp_path_158ad58a801c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_07.c:87
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供标准输入，且输入无法被 scanf 格式字符串 '%99s' 正确解析（例如，输入为空行或非字符串内容）。
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_07.c:87
- 结论: scanf() 函数返回值检查不完整。代码仅检查返回值是否为 EOF，忽略了 scanf 可能返回 0（表示输入匹配失败）的情况。根据 CWE-253，不正确检查函数返回值可能导致未处理的错误状态，构成 API misuse。尽管后续代码未直接使用 data 缓冲区，但违反 API contract，存在潜在风险。
- D验证: stage_c_preserved / ver_0e3aacf6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 467. hyp_path_bf4e420d2e31

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_08.c:106
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供输入使得scanf返回0，例如空行或非匹配字符
- 触发路径: if (scanf("%99s\\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_08.c:106
- 结论: scanf的返回值检查不完整：仅检查了返回值是否为EOF，而未检查返回值是否等于期望的匹配项目数（应为1）。当scanf返回0（例如空行或类型不匹配）时，程序未识别失败，导致dataBuffer保持初始空字符串，违反函数接口契约。
- D验证: stage_c_preserved / ver_e3ba4e3e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 468. hyp_path_98eae94eb36e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_09.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使 scanf 调用失败（例如关闭标准输入流或发送 EOF 信号）
- 触发路径: scanf("%99s\0", data) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_09.c:35; if (scanf(...) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_09.c:35; 使用未经初始化检查的 data @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_09.c:（后续使用 data 的代码未显示）
- 结论: 对 scanf 返回值的检查不正确：当 scanf 失败时返回 EOF (-1)，但代码中仅检查返回值是否等于 0，导致错误处理分支不会执行，后续可能使用未初始化的变量 data，存在未定义行为风险。
- D验证: stage_c_preserved / ver_13b7a2d0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 469. hyp_path_03cc52361f73

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_10.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可以提供输入导致scanf返回非0值（例如正常输入时返回1，或者输入导致EOF）
- 触发路径: if (scanf("%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_10.c:35
- 结论: 对scanf返回值检查错误：代码仅检查返回值是否为0，但scanf成功时返回1（匹配项数），失败时返回EOF（-1）。正确的做法应检查返回值是否小于期望的匹配项数（如<1）或是否为EOF。此错误导致未能正确处理scanf失败的情况，可能使用未初始化的data变量，但后续未直接使用data降低了直接影响。
- D验证: stage_c_preserved / ver_153bb8fa
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 470. hyp_path_33ee37c077be

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_09.c:93
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入流，提供导致scanf返回0的输入（例如空输入或仅空白字符）。
- 触发路径: if (scanf("%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_09.c:82; printLine("scanf failed!"); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_09.c:83
- 结论: 函数scanf的返回值检查不完整：仅检查EOF，未检查返回值为0的情况（即没有成功读取任何匹配项），违反了CWE-253。虽然dataBuffer已初始化为空字符串且后续未使用data变量，但函数返回值检查的契约违反仍然存在，影响较低。
- D验证: stage_c_preserved / ver_9c4fa0b1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 471. hyp_path_b51f11f24448

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_09.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者提供的输入导致scanf返回0（如输入字符串与格式不匹配）或发生部分读取
- 触发路径: if (scanf("%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_09.c:82; 如果scanf返回值不为EOF，则跳过printLine，直接执行后续代码 @ 同一行; 程序继续使用data，其内容可能未正确更新 @ 后续代码（未展示）
- 结论: 函数scanf的返回值检查不完整，仅检查了EOF，未检查是否成功读取（返回1）。当scanf返回0（输入不匹配）或部分成功时，程序不会进入错误处理分支，导致后续使用未正确初始化的dataBuffer，存在未定义行为或逻辑错误的潜在风险。
- D验证: stage_c_preserved / ver_6790143f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 472. hyp_path_008ddb02b19b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_10.c:93
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入
- 触发路径: if (scanf("%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_10.c:79-80
- 结论: CWE-253: Incorrect Check of Function Return Value - scanf仅检查EOF，未检查成功读取数
- D验证: stage_c_preserved / ver_44c39b01
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 473. hyp_path_11e4032f7ce6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_10.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入到scanf的数据
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_10.c:82
- 结论: scanf返回值检查不完整：仅检查是否等于EOF，未检查返回0的情况。当输入不匹配格式时，scanf返回0，代码不会输出失败信息，可能导致后续使用未正确填充的缓冲区，造成未初始化数据使用或其他未定义行为。
- D验证: stage_c_preserved / ver_49261331
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 474. hyp_path_ea9be2180dde

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_13.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入或类似渠道控制输入，使得 scanf 返回 EOF（例如关闭 stdin 或发送 Ctrl+D）
- 触发路径: if (scanf("%99s\0", data) == 0) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_13.c:35
- 结论: 对 scanf 函数返回值检查不正确：代码检查返回值是否等于 0，但 scanf 成功时返回读取的项目数（通常为 1），失败时返回 EOF（-1）。因此当 scanf 失败或成功时，条件均不成立，导致错误处理分支不会执行，可能使用未初始化的数据或忽略输入错误。
- D验证: stage_c_preserved / ver_020002d8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 475. hyp_path_6ba22be51c24

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_11.c:92
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供非标准输入（如匹配失败但非EOF）触发 scanf 返回 0。
- 触发路径: case11(); case12(); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_11.c:92-93; if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_11.c:62-64 (case11内部); if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_11.c:83-85 (case12内部)
- 结论: 在函数 case11 和 case12 中，对 scanf 的返回值检查不完整：仅检查是否为 EOF，但未检查是否成功读取了一个项（返回值应为 1）。根据 CWE-253，正确的检查应确认返回值等于期望的输入项数。虽然当前代码中 data 已初始化为空字符串，且后续未使用，影响较低，但违反 API 契约，存在潜在的逻辑错误。
- D验证: stage_c_preserved / ver_c9cba4f9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 476. hyp_path_35a9b66427cb

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_13.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供空白或格式不匹配的输入，使scanf返回0。
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_13.c:82
- 结论: scanf返回值检查不完整：仅检查EOF，未处理返回0（输入不匹配）的情况，违反CWE-253。虽然data未初始化但后续未被使用，影响较低。
- D验证: stage_c_preserved / ver_0b0f0258
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 477. hyp_path_57d823769159

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_14.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致scanf失败（如关闭输入流或提供非法输入）
- 触发路径: if (scanf("%99s\0", data) == 0) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_14.c:33-37
- 结论: scanf返回值检查错误：代码仅检查返回值为0，忽略EOF（-1），违反CWE-253。但缺乏后续data使用的代码证据，可利用性较低，需动态验证确认。
- D验证: stage_c_preserved / ver_1edd5c65
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 478. hyp_path_faa37e112299

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_14.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供无法匹配%99s格式的输入（例如空行或非空白字符），导致scanf返回0而非EOF
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_14.c:82
- 结论: scanf的返回值检查不完整：代码仅检查返回值是否等于EOF，而忽略返回值为0（表示输入不匹配）或小于0的其他错误情况，导致可能错误地认为读取成功，后续使用未正确初始化的data缓冲区。
- D验证: stage_c_preserved / ver_05f2d3c6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 479. hyp_path_0fb1e3948a8a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_15.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供给 scanf 的输入导致读取失败（例如关闭 stdin 或发送 EOF）
- 触发路径: if (scanf("%99s\0", data) == 0) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_15.c:36
- 结论: CWE253 不正确的返回值检查：scanf() 返回 EOF (-1) 时，程序检查返回值为 0 并不成立，导致错误处理未执行，data 可能保持未初始化状态，后续使用 data 可能导致未定义行为。
- D验证: stage_c_preserved / ver_88af3fea
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 480. hyp_path_54ab8e19b2e5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_16.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供导致scanf()失败的输入（如发送EOF或格式不匹配的输入）
- 触发路径: if (scanf("%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_16.c:35
- 结论: 代码对scanf()的返回值检查不正确：检查返回0表示失败，但scanf()失败时返回EOF(-1)，因此条件永远不会为真，导致错误处理代码永远不会执行。这违反了CWE-253（不正确检查函数返回值），导致错误处理路径不可达。
- D验证: stage_c_preserved / ver_9cd3069b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 481. hyp_path_8ea8d6e527f9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_15.c:69
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够发送导致scanf返回0或非EOF错误的输入（如空行或格式不匹配的字符串）
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_15.c:69
- 结论: scanf函数返回值检查不完整：仅检查了EOF，未处理返回0（匹配失败）或其他负值错误，违反CWE-253约定。虽然当前代码片段未显示后续使用未初始化数据，但dataBuffer未初始化，若后续使用可能产生未初始化内存读取风险。
- D验证: stage_c_preserved / ver_bb203713
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 482. hyp_path_c78f89fd0c13

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_18.c:57
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供字符串，但scanf可能因输入格式不匹配返回0，未被正确处理
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_18.c:57
- 结论: CWE-253: Incorrect Check of Function Return Value - scanf返回值仅检查EOF，忽略其他失败情况（如匹配失败返回0），导致API contract violation
- D验证: stage_c_preserved / ver_f9ee391b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 483. hyp_path_62c63abe306e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_18.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使scanf返回EOF（如关闭标准输入或提供无效输入导致读取错误）
- 触发路径: if (scanf("%99s\0", data) == 0) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_18.c:35
- 结论: scanf返回值检查错误：代码仅检查返回值是否为0，而失败时返回EOF(-1)，导致错误处理遗漏。虽然未在片段中明确展示data的后续使用，但返回值检查本身不符合CWE-253要求，且通过常见测试用例模式推断，data很可能在后续被使用（如输出或逻辑判断），因此存在未初始化数据使用的潜在风险。
- D验证: stage_c_preserved / ver_547bb50e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 484. hyp_path_6c9d1f81659d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_01.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 调用snprintf时可能发生失败（如缓冲区长度不足）
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_01.c:41
- 结论: snprintf函数的返回值检查错误：代码检查返回值是否等于0来判断失败，但snprintf失败时返回负值，正确检查应为if (ret < 0)。这导致失败情况未被正确捕获。
- D验证: stage_c_preserved / ver_8e335fec
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 485. hyp_path_07150d8a0918

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_15.c:90
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: Attacker can provide input via stdin
- 触发路径: scanf("%99s\0", data) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_15.c:90; printLine("scanf failed!"); // only on EOF; other failures ignored @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_15.c:92
- 结论: VULNERABILITY_FOUND: Incorrect check of scanf return value; only checks for EOF, not for successful read. According to CWE-253, the return value of scanf must be checked to ensure the expected number of input items were read. Here, only EOF is checked, leaving the possibility that scanf returns 0 (no items matched) or a positive number less than expected, leading to uninitialized or partially initialized data.
- D验证: stage_c_preserved / ver_caf29890
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 486. hyp_path_0348e7af9492

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_02.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: snprintf 调用可能因缓冲区不足或格式错误失败，但返回值检查错误导致失败被忽略；数据流中无外部输入控制，但 contract violation 本身成立。
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_02.c:43
- 结论: snprintf 返回值检查错误：代码将返回值为 0 视为失败，但 snprintf 失败时返回负数，成功时返回写入字符数（可能为 0）。此检查逻辑导致无法正确检测 snprintf 失败（返回负数时被忽略），存在 API contract 违反。
- D验证: stage_c_preserved / ver_09801ca8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 487. hyp_path_dbd105e3719a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_02.c:71
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: SRC_STRING length may cause truncation (though currently fixed, contract violation exists)
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_02.c:71
- 结论: Incorrect check of snprintf return value: only checks for negative error, missing truncation detection (return value >= buffer size).
- D验证: stage_c_preserved / ver_6b3fc802
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 488. hyp_path_070f02bc286d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_02.c:90
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: SRC_STRING为外部可控字符串（或未来修改为外部输入）时，其长度可能大于或等于缓冲区剩余空间(100-strlen(SRC_STRING)-1)，导致snprintf截断且返回非负值，未被检查。
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_02.c:90
- 结论: snprintf返回值检查不完整：仅检查返回值<0，未检查返回值是否等于或超过缓冲区大小，可能导致输出截断未被发现，违反CWE-253。
- D验证: stage_c_preserved / ver_8626fd3a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 489. hyp_path_a51d0c1700f3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_03.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入要求；snprintf() 可能因内部错误（如内存不足、格式错误）或缓冲区大小不足返回负值。
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_03.c:43
- 结论: snprintf() 返回值错误检查：代码检查返回值为 0 时视为失败，但根据 C 标准，snprintf() 失败时返回负值，成功时返回写入字符数（非负）。这种检查无法捕获真正的失败情况（返回负值），符合 CWE-253 定义。
- D验证: stage_c_preserved / ver_c02fc6e8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 490. hyp_path_70c9338b5558

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_02.c:101
- 漏洞类型: integer_overflow
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法控制SRC_STRING的长度或内容（编译时常量）。
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_02.c:86
- 结论: SNPRINTF调用中，返回值检查仅针对<0，未检查是否发生截断或错误，违反CWE-253。但由于SRC_STRING为编译时常量且长度固定小于100，size参数始终为正，无整数回绕或缓冲区溢出风险。因此CWE-121和CWE-190不成立。
- D验证: stage_c_preserved / ver_7f426b6d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 491. hyp_path_74776739f614

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_04.c:49
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: snprintf 可能因内部错误失败（如格式字符串问题或目标缓冲区太小），但攻击者不直接控制输入
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_04.c:49
- 结论: snprintf()返回值检查错误：代码使用 '== 0' 检查失败，但 snprintf() 失败时返回负值，导致失败条件未被正确处理。
- D验证: stage_c_preserved / ver_edd415fe
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 492. hyp_path_fb8219541c89

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_05.c:49
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: snprintf函数调用存在失败可能（如缓冲区不足）
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_05.c:49
- 结论: snprintf的返回值检查错误：成功时返回写入字符数（可能非0），失败时返回负值。代码检查返回值等于0作为失败条件，这违反了CWE-253定义，可能导致未检测到snprintf失败或误判。
- D验证: stage_c_preserved / ver_1c1330c1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 493. hyp_path_08b613103a30

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_06.c:48
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: snprintf() 调用可能失败（如缓冲区不足或写入错误），返回负值
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_06.c:48
- 结论: snprintf() 的返回值检查不正确：函数失败时返回负值，但代码仅检查返回值是否为 0，导致失败时不会进入错误处理分支，未处理可能的失败情况。
- D验证: stage_c_preserved / ver_3722feff
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 494. hyp_path_c8cba18b5a0b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_07.c:48
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: snprintf函数可能失败（如写入错误或格式问题，虽然此处格式固定但底层仍可能失败）
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_07.c:48
- 结论: snprintf的返回值被错误地检查为等于0，未能捕获负数错误（snprintf失败时返回负数），导致错误条件被忽略。
- D验证: stage_c_preserved / ver_74180f4a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 495. hyp_path_ae0418cbb53c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_09.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: snprintf调用可能失败（如缓冲区不足或编码错误）
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_09.c:43
- 结论: 代码检查snprintf返回值是否等于0，但snprintf失败时返回负数，因此错误条件永远不会触发，导致无法检测snprintf失败。
- D验证: stage_c_preserved / ver_f2d7f2e6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 496. hyp_path_632d4b0e425c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_10.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: snprintf调用因资源耗尽或其他错误返回负值
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_10.c:43
- 结论: snprintf返回值检查错误：代码仅当返回值为0时处理失败，但snprintf失败时返回负值（<0），成功时返回非负（可能为0）。这违反了snprintf API契约，导致在snprintf实际失败时错误处理逻辑未被触发。
- D验证: stage_c_preserved / ver_dd031472
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 497. hyp_path_746105f0f1a6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_08.c:114
- 漏洞类型: integer_overflow
- CWE: CWE-190; CWE-121; CWE-253
- 风险等级: P1
- 触发条件: SRC_STRING长度至少为100（测试用例中通常为固定长字符串，攻击者不可控但漏洞可触发）；若实际应用中SRC_STRING可被攻击者控制，则可利用性提高。
- 触发路径: void CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_08_case1() { case11(); case12(); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_08.c:111; if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_08.c:99
- 结论: snprintf调用中第二个参数计算存在整数下溢，导致缓冲区溢出；同时，返回值检查（<0）不正确，未按CWE253要求检查返回值是否等于期望字节数。当SRC_STRING长度>=100时，100-strlen(SRC_STRING)-1下溢为负数，转换为size_t后极大，snprintf尝试写入远超dataBuffer（100字节）的内容，造成栈溢出。
- D验证: stage_c_preserved / ver_34644ab0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 498. hyp_path_265d8eb7a5b0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_10.c:90
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: The length of SRC_STRING is such that the formatted output may exceed the buffer size (100 - strlen(SRC_STRING) - 1), causing truncation. Although SRC_STRING may be constant in this Juliet sample, the code pattern violates CWE-253.
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0) @ L90
- 结论: VULNERABILITY_FOUND: Incorrect check of snprintf return value - only checks for negative error codes, ignores truncation (return value >= size).
- D验证: stage_c_preserved / ver_e1a2e9c9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 499. hyp_path_645dcbcee006

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_14.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: snprintf函数调用可能失败，例如目标缓冲区大小不足以容纳格式化输出。
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_14.c:43
- 结论: snprintf函数的返回值检查不正确：当snprintf失败时返回负值，但代码仅检查返回值是否等于0，导致对失败情况（负返回值）未正确处理。
- D验证: stage_c_preserved / ver_c0c499d8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 500. hyp_path_1090d938460e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_13.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的长度或内容，使得snprintf实际写入字符数非0或返回负数，从而绕过错误的等于0检查。
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0) { @ CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_13.c:43
- 结论: 对snprintf的返回值检查错误：代码将返回值等于0视为失败，而snprintf失败时返回负值，导致失败未被检测。尽管代码片段未展示后续对data的使用，但错误的检查本身违反CWE-253，并可能导致未正确初始化的data被使用。
- D验证: stage_c_preserved / ver_192d17b2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 501. hyp_path_53ffb3c6b608

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_15.c:44
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特殊前提，函数调用即可触发
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_15.c:44
- 结论: snprintf返回值检查不正确：函数失败时返回负值，但代码仅检查返回值是否为0，导致对负值返回的误判。虽然当前代码未直接使用data，但违反了CWE-253正确的返回值检查契约，可能掩盖错误状态。
- D验证: stage_c_preserved / ver_a4dda2d9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 502. hyp_path_8bef449b1022

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_15.c:98
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的长度，使其超过缓冲区剩余空间；但当前上下文中SRC_STRING可能为固定常量，可控性未确认。
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_15.c:98
- 结论: snprintf返回值检查不完整：仅检查返回值小于0，未处理返回值大于等于缓冲区大小时的截断情况，可能导致字符串截断或数据丢失。
- D验证: stage_c_preserved / ver_0a1de2a2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 503. hyp_path_7d7e5d4bd1a3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_16.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: snprintf函数可能因缓冲区不足或格式错误返回负数，但攻击者无法直接控制失败条件，漏洞属于API契约违反
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_16.c:43
- 结论: snprintf返回值检查错误：代码检查返回值是否为0，但snprintf失败时返回负数，成功时返回正数，因此只检查0无法捕获失败情况
- D验证: stage_c_preserved / ver_47553503
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 504. hyp_path_b39c92c1c873

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_14.c:90
- 漏洞类型: integer_overflow
- CWE: CWE-190; CWE-120
- 风险等级: P1
- 触发条件: SRC_STRING长度大于99（常量静态特征，无需攻击者控制）
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_14.c:90; if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_14.c:92
- 结论: snprintf调用中第二个参数计算存在整数溢出漏洞，可能导致缓冲区溢出。当SRC_STRING长度大于99时，100-strlen(SRC_STRING)-1下溢为非常大的无符号整数，使snprintf写入超出dataBuffer缓冲区。尽管SRC_STRING是预定义常量，但实际长度可能大于99（常见于Juliet测试集），因此漏洞在静态上存在，但外部不可控，属于静态缺陷。
- D验证: stage_c_preserved / ver_df477a24
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 505. hyp_path_eb2dd0f3f308

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_18.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: snprintf可能因缓冲区不足或写入错误返回负数
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_18.c:43
- 结论: snprintf() 返回值检查不正确：代码只检查返回值是否为0，但snprintf失败时返回负数，因此错误情况未被捕获，违反CWE-253。
- D验证: stage_c_preserved / ver_5426e961
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 506. hyp_path_2f0367893b6e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_01.c:54
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的内容
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_01.c:54
- 结论: sscanf返回值检查不正确：检查是否等于EOF，但正确做法是检查返回值是否等于成功匹配的项数（1）。当sscanf返回0或负数时，错误不会被检测到，可能导致data未正确更新。
- D验证: stage_c_preserved / ver_505359cd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 507. hyp_path_0dbbf63b2fd1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_02.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法控制SRC_STRING（常量），因此错误路径实际不可达；但若输入变为非常量，则可能触发。
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == 0) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_02.c:37
- 结论: sscanf函数返回值的检查不正确：sscanf失败时返回EOF(-1)，但代码仅检查返回值是否为0，导致当sscanf因输入错误或文件结束返回-1时，错误被遗漏。虽然由于当前输入为常量，实际路径不可达，但API契约违反仍然存在，属于代码缺陷。
- D验证: stage_c_preserved / ver_94e6f3ae
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 508. hyp_path_daf81c28e7d9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_03.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: sscanf可能因为格式不匹配或其他原因失败，返回EOF(-1)而非0
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == 0) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_03.c:37
- 结论: sscanf()的返回值检查不正确：sscanf()失败时返回EOF(-1)，但代码检查返回值是否等于0，导致失败未被正确检测。尽管此处仅打印失败消息，未造成直接数据损坏或崩溃，但违反了API contract，属于CWE-253漏洞。
- D验证: stage_c_preserved / ver_2463dbf9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 509. hyp_path_3635e5d0b7ee

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_01.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING使其导致sscanf返回EOF（-1）
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == 0) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_01.c:35
- 结论: 存在CWE-253违规：sscanf返回值检查不正确，只检查返回值是否为0，忽略了EOF（-1）情况。当前测试用例中SRC_STRING为常量，攻击者无法触发sscanf失败，因此无实际可利用路径。但代码模式违反了函数返回值检查的契约，在输入可控的场景下可能造成未初始化数据使用。
- D验证: stage_c_preserved / ver_ae01f8ba
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 510. hyp_path_745a4c034e43

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_02.c:84
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供空字符串作为SRC_STRING
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_02.c:84
- 结论: 对sscanf返回值的检查不完整：仅检查返回值是否等于EOF，而忽略了返回0的情况。当输入为空字符串时，sscanf返回0（未匹配到任何项），但程序认为成功，导致dataBuffer未被填充，后续使用未初始化的数据。
- D验证: stage_c_preserved / ver_e495af54
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 511. hyp_path_114e0c81b381

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_02.c:65
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的内容，使其无法与格式字符串匹配但又不触发EOF（例如空字符串或非空白字符序列）。
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_02.c:65
- 结论: 在sscanf调用中，仅检查返回值是否为EOF，但未处理返回0的情况，导致当输入不匹配格式时，错误未被捕获，data缓冲区未被写入。尽管代码片段未显示后续使用data的sink操作，但未正确检查返回值本身构成API contract violation，且dataBuffer未初始化，后续使用可能导致未定义行为。需要审计完整代码或动态验证来确认是否存在sink。
- D验证: stage_c_preserved / ver_a5d40599
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 512. hyp_path_19da4d5b8bcd

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_03.c:84
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING，使其导致sscanf返回0
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ 84
- 结论: sscanf返回值检查不完整：仅检查是否等于EOF，忽略了返回值为0（无匹配）的情况，违反了API contract。
- D验证: stage_c_preserved / ver_eac605c0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 513. hyp_path_ba923c8606c0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_03.c:65
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: Attacker can provide input that causes sscanf to return 0 instead of EOF.
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_03.c:65
- 结论: Incorrect check of sscanf return value: only checking for EOF, but sscanf can also return 0 indicating no input matched, leaving data potentially uninitialized or without proper null termination.
- D验证: stage_c_preserved / ver_a2a8521c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 514. hyp_path_83c1e399ff3e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_03.c:95
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入，当前路径不可利用，但API contract被违反
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_03.c:84
- 结论: 函数case12中的sscanf返回值检查不完整，仅检查EOF，未处理返回0的情况，违反了CWE-253 API contract。虽然当前输入为固定字符串SRC_STRING，无法触发0返回值，但代码逻辑存在缺陷。
- D验证: stage_c_preserved / ver_4a18ff8b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 515. hyp_path_53ae5431246f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_04.c:100
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入要求；漏洞存在于常量输入下，但CWE-253不要求外部可控输入。
- 触发路径: void CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_04_case1() { case11(); case12(); } @ 入口函数CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_04_case1; if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ case12函数内（juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_04.c:88-92）
- 结论: 存在CWE-253漏洞：sscanf返回值检查不正确。sscanf返回成功匹配的输入项数，代码仅检查是否为EOF，未验证返回是否等于期望的1，违反CWE-253。尽管输入SRC_STRING为常量导致实际影响较低，但编码错误本身构成漏洞。
- D验证: stage_c_preserved / ver_4ba8149b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 516. hyp_path_28e396e14edf

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_04.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法直接控制SRC_STRING（常量），但若未来代码修改或环境变化导致sscanf失败，错误检查将无法触发。
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == 0) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_04.c:43
- 结论: 在CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_04_case0中，sscanf的返回值检查错误：代码检查返回值是否等于0，而sscanf失败时返回EOF(-1)，导致错误条件不被触发。尽管SRC_STRING是常量，攻击者无法直接控制输入，但该代码违反了API contract（CWE-253），属于不正确的返回值检查。由于data后续未被使用，实际危害不明确，但逻辑缺陷存在。
- D验证: stage_c_preserved / ver_8eb10070
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 517. hyp_path_9f0645dfbdba

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_05.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: sscanf函数调用可能失败（如输入格式不匹配或读取错误）
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == 0) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_05.c:43
- 结论: 函数sscanf的返回值被错误地检查为等于0，但实际上sscanf成功匹配时返回1，失败返回EOF(-1)，因此检查条件永远为假，导致无法正确处理sscanf失败的情况，违反了CWE-253。
- D验证: stage_c_preserved / ver_62cbbf2a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 518. hyp_path_1b077f8a5dd8

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_04.c:71
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: SRC_STRING内容可能由攻击者控制或包含无法匹配格式的数据，导致sscanf返回0。
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_04.c:71
- 结论: sscanf函数返回值检查不正确：仅检查返回值为EOF，但sscanf成功时返回匹配项数（应为1），失败时返回0或EOF。当sscanf返回0时（例如输入不匹配格式），错误未被捕获，data缓冲区保持未初始化状态。但代码片段未展示后续使用data的语句，漏洞路径不完整，需要动态验证或审计确认后续sink是否存在。
- D验证: stage_c_preserved / ver_275ff9d4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 519. hyp_path_67f925e2033c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_04.c:90
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法控制SRC_STRING（编译时常量"Hello"），sscanf始终返回成功匹配数1，不进入错误处理分支
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_04.c:90
- 结论: sscanf返回值检查不完整：代码仅检查返回值是否为EOF，忽略了其他失败情况（如返回0或负数），但因SRC_STRING为编译时常量，实际无法触发失败路径，属于理论缺陷。
- D验证: stage_c_preserved / ver_701a0ce9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 520. hyp_path_9bebeebfe61f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_06.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可能通过控制输入字符串导致sscanf返回EOF（如发生读取错误）或返回0（如输入为空），从而触发错误的条件误判。
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_06.c:42
- 结论: 对sscanf()返回值的检查错误：代码将返回值等于0视为失败，但sscanf失败时返回EOF(-1)，成功时返回成功匹配的输入项数（可能为0）。这违反了CWE-253（不正确检查函数返回值），导致当sscanf实际失败时，错误条件不成立，错误未被处理。
- D验证: stage_c_preserved / ver_358e767f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 521. hyp_path_3743bbeb7b8d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_05.c:90
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: SRC_STRING的内容导致sscanf返回0（例如空字符串或仅空白字符）时，错误处理被绕过。虽然当前SRC_STRING可能为常量，但代码存在缺陷，在输入可控时可能引发逻辑错误。
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_05.c:90
- 结论: 代码中sscanf的返回值检查错误：将sscanf的返回值与EOF比较，但sscanf返回匹配项数，失败时返回0（不匹配）或EOF（错误）。当输入无法匹配时，错误处理被跳过，后续使用data可能基于未成功更新的内容（尽管dataBuffer已初始化为空，但逻辑上与预期不符）。这违反了CWE-253正确检查函数返回值的要求。
- D验证: stage_c_preserved / ver_c6cf73bd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 522. hyp_path_1e77499930ee

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_06.c:100
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING或其他输入参数，使其格式不匹配导致sscanf返回0
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_06.c:89
- 结论: sscanf返回值检查不完整，仅检查EOF，未检查返回值为0的情况（格式匹配失败），违反CWE-253关于不正确返回值检查的要求。当前SRC_STRING为固定字符串导致路径不可达，但API contract violation仍然存在。
- D验证: stage_c_preserved / ver_e9f9b51f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 523. hyp_path_4bad830836e0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_06.c:89
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ L87-91
- 结论: VULNERABILITY_FOUND: Incorrect check of sscanf return value - only checks for EOF, but not for 0 (no match) or other errors, violating CWE-253 contract
- D验证: stage_c_preserved / ver_49a9d1fb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 524. hyp_path_081d6a6ae1b5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_07.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 代码执行到该sscanf调用，且sscanf实际返回EOF或负数
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_07.c:42
- 结论: sscanf返回值检查不正确：程序仅检查返回值是否为0，而sscanf失败时返回EOF（-1），导致失败未被检测到。尽管当前代码片段未明确展示sscanf失败后data变量的使用，但根据典型Juliet测试用例模式，后续很可能存在使用未初始化数据的sink，因此存在潜在漏洞。
- D验证: stage_c_preserved / ver_25775a27
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 525. hyp_path_4d22c627b97c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_06.c:70
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的值（若该值为外部输入），或代码在其他路径使用时存在类似缺陷
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_06.c:70
- 结论: sscanf返回值检查不完整，仅检查EOF，忽略返回0的情况，违反CWE-253。即使当前SRC_STRING为常量，代码仍存在API使用错误，可能在其他上下文中被外部输入触发，导致未初始化读取或逻辑错误。
- D验证: stage_c_preserved / ver_86cdefe5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 526. hyp_path_9b7989c5ac0c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_07.c:89
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的内容; 提供的输入使得sscanf返回0（例如空字符串或非匹配字符）
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_07.c:89; 当sscanf返回0时，条件为假，不进入错误处理分支，程序继续使用data（可能未正确填充）。 @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_07.c:89
- 结论: 在sscanf返回值检查中，仅检查返回EOF，忽略了返回0的情况。当输入字符串无法匹配任何格式项时，sscanf返回0，但程序未将其视为错误，导致未正确检测失败，可能使用未初始化的缓冲区。
- D验证: stage_c_preserved / ver_81a263d2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 527. hyp_path_3e6a21346bcd

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_09.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 环境导致sscanf失败，例如输入字符串不符合格式
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_09.c:37
- 结论: CWE253: 对sscanf返回值的检查不正确。sscanf失败时返回EOF（-1），但代码仅检查返回值是否等于0，导致sscanf失败未被正确处理。
- D验证: stage_c_preserved / ver_b1acc2e5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 528. hyp_path_816151f10f90

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_07.c:100
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法直接控制SRC_STRING（常量），但API合同违反仍然存在；若SRC_STRING被外部可控，则漏洞可利用性更高。
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_07.c:90
- 结论: sscanf返回值检查不完整：仅检查是否等于EOF，未检查返回值是否等于期望的匹配项数（1），导致输入为空字符串时（返回0）不会被检测为错误，违反CWE-253的API合同。但输入SRC_STRING为常量，限制了实际可利用性。
- D验证: stage_c_preserved / ver_74419464
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 529. hyp_path_146abb7fab8e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_08.c:108
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法控制SRC_STRING，其为编译时常量，无外部输入；因此无法触发错误检查路径或造成实际影响。
- 触发路径: if (sscanf(SRC_STRING, "%99s", data) == EOF) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_08.c:93; printLine("sscanf failed!"); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_08.c:94
- 结论: 在函数case12和case11中，sscanf的返回值被错误地检查为等于EOF，而应检查等于期望的匹配项数（1）。这违反了CWE-253的API contract。但SRC_STRING为编译时常量，无外部可控输入，因此漏洞路径不可利用，属于低影响违规。
- D验证: stage_c_preserved / ver_6fc9b7db
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 530. hyp_path_1d1aa304edea

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_10.c:94
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制 SRC_STRING 的内容（例如通过环境变量或文件输入）或影响 sscanf 的执行状态（如提前达到文件结束）
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_10.c:62; if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_10.c:84
- 结论: 在函数 case11 和 case12 中，sscanf 的返回值仅被检查是否等于 EOF，但未检查是否等于成功匹配的项数（应为 1）。当 sscanf 返回 0 或其他非 EOF 负数时（如输入格式不匹配或读取错误），代码不会检测到失败，导致未处理的数据不完整或未初始化的状态。虽然当前输入为常量导致无法动态触发，但逻辑上违反了 API contract 和 CWE-253 定义。
- D验证: stage_c_preserved / ver_8d6a4ae1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 531. hyp_path_7690ce3c5da0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_10.c:84
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: The input string SRC_STRING can be controlled or malformed to cause sscanf to return 0 or other non-EOF values, leading to uninitialized data usage.
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_10.c:84
- 结论: Incorrect check of sscanf return value: only checks for EOF, missing check for successful match count (expected 1). This violates CWE-253.
- D验证: stage_c_preserved / ver_9c796ece
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 532. hyp_path_5198ef41bc07

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_09.c:84
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的内容，使其不匹配格式（例如空字符串或非字符串内容），导致sscanf返回0。
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_09.c:84
- 结论: sscanf函数返回值检查不完整：仅检查是否等于EOF，未处理返回0（表示无输入项匹配）的情况，违反CWE-253 API契约。虽然当前代码片段未展示后续使用data变量，但违反契约本身构成安全隐患，需动态验证或补充后续代码确认是否导致未初始化数据使用。
- D验证: stage_c_preserved / ver_b1fac1ad
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 533. hyp_path_3be8fe59d4d1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_10.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法控制输入，因为SRC_STRING是编译时常量
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_10.c:37
- 结论: CWE-253违规：sscanf()返回值检查仅检查是否等于0，未处理返回EOF(-1)的情况。但由于SRC_STRING为常量字符串，sscanf实际不会失败，因此该违规无法被利用，无安全风险。
- D验证: stage_c_preserved / ver_9a06d215
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 534. hyp_path_44bc2c5beab6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_13.c:84
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: The input string SRC_STRING can be manipulated to cause sscanf to return 0 (e.g., empty string or non-matching input) instead of 1 or EOF.
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_13.c:84
- 结论: CWE253: Incorrect Check of Function Return Value - sscanf return value not checked for successful match (only checked for EOF)
- D验证: stage_c_preserved / ver_8284b55e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 535. hyp_path_552a12a7e79f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_11.c:94
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) @ CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_11.c:62; if (sscanf(SRC_STRING, "%99s\0", data) == EOF) @ CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_11.c:85
- 结论: VULNERABILITY_FOUND
- D验证: stage_c_preserved / ver_b0534987
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 536. hyp_path_0ce7c66cab16

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_13.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响SRC_STRING内容，使得sscanf失败（如空字符串或格式不匹配）
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == 0) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_13.c:37
- 结论: 对sscanf返回值的检查不正确：当sscanf返回EOF(-1)时，代码错误地视为成功，未处理错误。但当前代码片段未显示未初始化变量data在后续被使用，需要完整代码确认利用路径。
- D验证: stage_c_preserved / ver_fb99b3d4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 537. hyp_path_69d22a7e67f8

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_13.c:94
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制 SRC_STRING 的值，使其导致 sscanf 返回0或负值但不等于EOF。当前 SRC_STRING 为常量，该条件不满足。
- 触发路径: void CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_13_case1() { case11(); case12(); } @ CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_13.c:92; if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_13.c:50-71 (case11) 或 74-90 (case12)
- 结论: CWE253 错误检查函数返回值：sscanf 返回值检查不正确，仅检查是否等于 EOF，但 sscanf 成功时返回匹配项数（通常为1），失败时返回0或负值，不等于 EOF。这导致无法正确检测解析失败的情况，但触发依赖 SRC_STRING 的可控性，当前代码中 SRC_STRING 为常量或宏，未证实为外部可控输入，因此可利用性较低。
- D验证: stage_c_preserved / ver_79a18044
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 538. hyp_path_cecd09f3f0f0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_14.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: sscanf 可因输入格式错误或空输入等原因返回 EOF
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == 0) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_14.c:37
- 结论: sscanf 返回值检查错误：成功时返回1，失败时返回EOF(-1)，但代码检查是否等于0，导致无法正确检测失败，可能使用未初始化的 data。
- D验证: stage_c_preserved / ver_01c1b30f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 539. hyp_path_324b9210de0d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_14.c:84
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制sscanf的输入（SRC_STRING），使其不匹配格式（如空字符串或非匹配字符），导致返回0而不是EOF
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_14.c:84
- 结论: sscanf返回值检查不完整：仅检查EOF，未检查返回值是否等于预期匹配项数(1)，当输入不匹配或为空时返回0，导致data未正确初始化，后续使用未初始化数据。
- D验证: stage_c_preserved / ver_b68dedef
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 540. hyp_path_1174e5f2e1f1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_14.c:94
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供输入字符串使得 sscanf 返回0（例如空字符串或空白字符）
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_14.c:58; if (sscanf(SRC_STRING, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_14.c:82
- 结论: sscanf 返回值仅检查是否为 EOF，未检查实际匹配项数，但输入为编译时常量且结果未使用，导致实际风险较低，但仍存在 CWE-253 违反
- D验证: stage_c_preserved / ver_48e9b342
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 541. hyp_path_64f7e9084ba1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_15.c:38
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法控制SRC_STRING，其为固定常量字符串，sscanf始终成功，不存在EOF返回可能性。
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == 0) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_15.c:38
- 结论: sscanf返回值检查错误：当sscanf返回EOF(-1)时，代码误判为成功，但输入源SRC_STRING为常量，sscanf始终返回1，因此该漏洞条件不可达，属于代码缺陷但无可利用路径。
- D验证: stage_c_preserved / ver_425d25bf
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 542. hyp_path_c8d15c2b4806

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_15.c:71
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够直接或间接控制SRC_STRING的内容，使其导致sscanf返回0（如空字符串或非格式匹配的输入），从而绕过EOF检查。
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_15.c:71
- 结论: 存在CWE253漏洞：sscanf函数的返回值检查不完整，仅检查了EOF，未检查返回值是否等于期望的匹配项数（1）。当sscanf返回0（例如输入字符串为空或不匹配格式）时，程序错误地认为操作成功，导致data可能未被正确写入（dataBuffer未初始化），但后续未使用data，故实际影响有限，但API contract violation成立。
- D验证: stage_c_preserved / ver_68e2a0c3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 543. hyp_path_5ba85ff44c20

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_16.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: The input string SRC_STRING causes sscanf() to fail (e.g., empty string, format mismatch, or EOF condition).
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == 0) @ CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_16.c:37; When sscanf() returns EOF, the condition fails, no error message is printed, and 'data' remains uninitialized. @ CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_16.c:37-39
- 结论: The code incorrectly checks the return value of sscanf(). sscanf() returns EOF (-1) on failure, but the code only checks if the return value is 0. When sscanf() fails (returns EOF), the condition is false, and the error handling is skipped. The variable 'data' may remain uninitialized or partially filled, leading to undefined behavior if used later.
- D验证: stage_c_preserved / ver_9d210c5a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 544. hyp_path_93400babef34

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_15.c:92
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_15.c:92
- 结论: sscanf 返回值检查不完整：仅检查 EOF，未检查返回值为 0 或小于期望匹配项数的情况，违反 CWE-253 规范。但由于 SRC_STRING 为固定常量，实际运行时 sscanf 始终返回 1，无法触发错误路径，可利用性极低。
- D验证: stage_c_preserved / ver_a7a61553
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 545. hyp_path_13c6317a5c47

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_15.c:107
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: SRC_STRING是常量，不可控。若SRC_STRING非常量，则攻击者可通过控制其内容使sscanf返回0（无匹配），导致错误检查失效。
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_15.c:71,94
- 结论: 在case11和case12中，sscanf的返回值被错误地检查是否为EOF，而不是检查成功匹配的项数（应为1），违反了CWE-253定义。但由于SRC_STRING是常量字符串，攻击者无法控制其内容，导致sscanf始终返回1，因此该错误检查从未触发不同的返回值，漏洞不可利用。尽管存在API misuse，但实际风险为零。
- D验证: stage_c_preserved / ver_b32bba8a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 546. hyp_path_a0e58406f982

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_18.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: sscanf调用失败（如输入格式不匹配或读取错误），返回-1（EOF）。; 后续代码访问data变量（如打印、赋值等），导致未定义行为。
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_18.c:37; 使用data变量（如打印或赋值） @ 后续代码（未在提供代码片段中展示，但基于CWE测试用例模式推测存在）
- 结论: sscanf()的返回值被错误检查：检查等于0而不是检查小于0（EOF）或成功匹配数。违反了CWE-253，可能导致未正确处理sscanf失败的情况。若后续使用data，则可能造成未定义行为。
- D验证: stage_c_preserved / ver_c761e08c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 547. hyp_path_c7681403cb56

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_18.c:59
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING内容使其返回0（例如空字符串或仅空白字符）; dataBuffer未初始化（需确认，代码中未显示初始化）
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_18.c:59
- 结论: sscanf函数返回值检查不完整：仅检查EOF，未检查返回值是否等于期望的匹配项数（1），导致当sscanf返回0时，程序可能误认为成功，从而使用缓冲区data中的未定义数据（若dataBuffer未初始化）或继续使用之前的内容。但当前证据未显示dataBuffer初始化状态及后续sink点，因此漏洞假设不完整。
- D验证: stage_c_preserved / ver_b26f4396
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 548. hyp_path_c9965bc1b0b3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_01.c:28
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够触发RPC调用，但无需直接控制参数；函数调用本身可能成功或失败。
- 触发路径: if (RpcImpersonateClient(0) == RPC_S_OK) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_01.c:28
- 结论: RpcImpersonateClient返回值的检查逻辑颠倒：当函数成功（返回RPC_S_OK）时程序退出，失败时程序继续执行，导致在未模拟客户端身份的情况下运行后续代码，可能造成权限提升或信息泄露。
- D验证: confirmed / ver_67ba0416
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 549. hyp_path_42aba8f2a75b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_02.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够触发RpcImpersonateClient失败（例如通过恶意RPC调用）
- 触发路径: if (RpcImpersonateClient(0) == RPC_S_OK) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_02.c:30
- 结论: RpcImpersonateClient函数返回值检查逻辑错误：成功时退出，失败时继续执行。违反CWE-253（不正确检查函数返回值）。但后续代码被注释移除，无实际依赖模拟身份的操作，因此影响较低。需要动态验证或审计确认是否存在其他代码路径。
- D验证: confirmed / ver_951b3843
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 550. hyp_path_740d7447902b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_03.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够触发 RpcImpersonateClient 返回失败（例如通过伪造的 RPC 调用或凭据无效），且程序在失败后继续执行未受保护的代码。
- 触发路径: if (RpcImpersonateClient(0) == RPC_S_OK) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_03.c:30
- 结论: 调用 RpcImpersonateClient 后，返回值检查逻辑错误：当函数成功（返回 RPC_S_OK）时调用 exit(1) 退出，而失败时却不做处理直接继续执行。这违反了 API 契约，可能导致在模拟失败后以错误权限运行后续代码，构成权限提升或信息泄露风险。
- D验证: confirmed / ver_633a79a4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 551. hyp_path_b717c14915a4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_04.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 无外部输入控制，但RpcImpersonateClient可能因内部原因失败
- 触发路径: if (RpcImpersonateClient(0) == RPC_S_OK) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_04.c:36
- 结论: RpcImpersonateClient()的返回值检查错误：当函数成功返回RPC_S_OK时，程序退出；当函数失败时，程序继续执行后续操作，这可能导致未授权访问或权限提升。
- D验证: confirmed / ver_65d27db9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 552. hyp_path_5c34bfcb714f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_05.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够使调用线程没有有效的RPC客户端上下文（例如，在非RPC线程调用RpcImpersonateClient），导致RpcImpersonateClient返回非RPC_S_OK，从而使程序跳过exit继续执行。
- 触发路径: if (RpcImpersonateClient(0) == RPC_S_OK) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_05.c:36
- 结论: 调用RpcImpersonateClient后，错误地检查返回值：当函数成功（返回RPC_S_OK）时程序退出，而当函数失败时程序继续执行。这违反了正确的错误处理逻辑，可能导致在权限模拟失败后仍以原始权限继续执行，产生权限提升或安全策略绕过风险。
- D验证: confirmed / ver_79b24228
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 553. hyp_path_ea9a885b6c91

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_06.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: RpcImpersonateClient(0) must fail, which is virtually guaranteed because the handle parameter is 0 (NULL), an invalid handle.
- 触发路径: if (RpcImpersonateClient(0) == RPC_S_OK) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_06.c:35
- 结论: CWE-253: Incorrect Check of Function Return Value. RpcImpersonateClient returns RPC_S_OK on success, but the code treats RPC_S_OK as failure and calls exit(1). When RpcImpersonateClient fails (returns non-RPC_S_OK), the program continues execution without impersonating the client, potentially leading to incorrect security context.
- D验证: confirmed / ver_51d8fe23
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 554. hyp_path_2a240c8bab9b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_07.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够发起RPC调用，使得RpcImpersonateClient失败（例如，未提供有效凭据）
- 触发路径: if (RpcImpersonateClient(0) == RPC_S_OK) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_07.c:35
- 结论: 对RpcImpersonateClient的返回值检查错误：当函数成功时（返回RPC_S_OK）程序退出，导致服务异常终止；当函数失败时（返回非RPC_S_OK）程序继续执行，可能导致未正确模拟客户端权限的情况下继续操作，产生权限绕过或信息泄露风险。
- D验证: confirmed / ver_0c5c79e3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 555. hyp_path_be8c3826629f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_09.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者可通过影响 RPC 调用环境导致 RpcImpersonateClient 失败
- 触发路径: if (RpcImpersonateClient(0) == RPC_S_OK) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_09.c:30
- 结论: RpcImpersonateClient() 成功时返回 RPC_S_OK，但代码检查返回值等于 RPC_S_OK 时退出（exit(1)），而失败时则继续执行后续代码。这导致返回值检查逻辑错误，属于 CWE-253。虽然后续代码被注释省略，但错误检查行为本身已违反 API contract。
- D验证: confirmed / ver_fe0b5a0e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 556. hyp_path_8b8835afe97d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_10.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者可使RpcImpersonateClient失败，例如控制RPC调用上下文或提供无效句柄（此处传NULL句柄）。
- 触发路径: if (RpcImpersonateClient(0) == RPC_S_OK) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_10.c:30
- 结论: 在RpcImpersonateClient成功时退出程序，失败时继续执行，违反了API契约（应检查返回值并在失败时退出），导致如果模拟失败，程序可能以未授权权限继续运行，存在权限提升风险。
- D验证: confirmed / ver_e71198e9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 557. hyp_path_83b9083316b2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_13.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 存在调用该函数的上下文，且RpcImpersonateClient返回RPC_S_OK。
- 触发路径: if (RpcImpersonateClient(0) == RPC_S_OK) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_13.c:30
- 结论: 函数RpcImpersonateClient的返回值被错误地检查：当返回RPC_S_OK（表示成功）时调用exit(1)退出，而不是继续执行需要模拟身份的代码。这违反了API契约，导致程序在成功模拟身份时意外终止，可能造成拒绝服务或功能失效。
- D验证: confirmed / ver_81154122
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 558. hyp_path_ecac4e3a42b2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_14.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够触发此代码路径（RPC调用到达该函数），但无需控制输入参数
- 触发路径: if (RpcImpersonateClient(0) == RPC_S_OK) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_14.c:30
- 结论: RpcImpersonateClient返回值检查逻辑颠倒：成功时退出导致拒绝服务，失败时继续但后续无敏感操作，违反API contract（CWE-253）。然而实际可利用性低：参数固定为0，成功条件苛刻；失败路径无后续代码，权限缺失影响不存在。
- D验证: confirmed / ver_a4bf5a97
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 559. hyp_path_5510fa153f39

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_15.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够作为RPC客户端发起请求，使服务器调用RpcImpersonateClient并影响其返回值。
- 触发路径: if (RpcImpersonateClient(0) == RPC_S_OK) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_15.c:31
- 结论: RpcImpersonateClient的返回值检查逻辑反转：当函数成功返回RPC_S_OK时，程序调用exit(1)退出，导致拒绝服务。
- D验证: confirmed / ver_7a373fac
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 560. hyp_path_378136ff27d2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_18.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: The RPC server receives a call with a NULL binding handle, causing RpcImpersonateClient to fail.
- 触发路径: if (RpcImpersonateClient(0) == RPC_S_OK) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_18.c:30
- 结论: The code incorrectly checks the return value of RpcImpersonateClient: it treats success (RPC_S_OK) as a failure by calling exit(1), and allows execution to continue when the function fails. This violates the API contract, potentially leading to unauthorized privilege escalation or security bypass.
- D验证: confirmed / ver_7e3d3f8b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 561. hyp_path_985372a4ce1f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_16.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P0
- 触发条件: 攻击者能够通过影响RpcImpersonateClient调用的环境（如网络、权限配置）使其失败。
- 触发路径: if (RpcImpersonateClient(0) == RPC_S_OK) { exit(1); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_RpcImpersonateClient_16.c:30
- 结论: RpcImpersonateClient函数返回值检查错误：当调用成功（返回RPC_S_OK）时程序退出，而调用失败时继续执行，导致可能在未模拟客户端身份的情况下运行后续代码，违反CWE-253。但后续代码被省略，无法直接确认是否存在安全敏感操作，因此影响不确定。
- D验证: confirmed / ver_1e402c75
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 562. hyp_path_151c07378e1f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_01.c:28
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fwprintf(stdout, L"%s\n", L"string") == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_01.c:28
- 结论: fwprintf返回值检查错误：检查是否等于0，但失败时返回负数（通常-1），非0，导致错误处理分支不被执行；成功时若写入0个字符则误触发错误，但实际场景中几乎不会出现。
- D验证: stage_c_preserved / ver_12ef994e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 563. hyp_path_d17fce2f8314

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_02.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需外部输入；fwprintf() 可能在I/O错误时失败
- 触发路径: if (fwprintf(stdout, L"%s\n", L"string") == 0) { printLine("fwprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_02.c:30
- 结论: 对fwprintf()的返回值检查不正确：函数失败时返回负值，但代码仅将返回值与0比较，导致失败时不会执行错误处理。
- D验证: stage_c_preserved / ver_59f85009
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 564. hyp_path_bbb484df411d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_03.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者输入；函数调用本身可能失败（例如stdout关闭或满缓冲区）。
- 触发路径: if (fwprintf(stdout, L"%s\n", L"string") == 0) { printLine("fwprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_03.c:30
- 结论: fwprintf的返回值检查错误：代码检查返回值是否为0，但fwprintf失败时返回负值，成功时返回非负整数（包括0）。正确的检查应为小于0。这违反了CWE-253，导致错误处理逻辑缺陷。
- D验证: stage_c_preserved / ver_24cb67ef
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 565. hyp_path_9159e8200f7d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_04.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: No direct attacker control; fwprintf failure may occur due to system errors (e.g., stdout closed, disk full) which are not guaranteed.
- 触发路径: if (fwprintf(stdout, L"%s\n", L"string") == 0) { printLine("fwprintf failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_04.c:36
- 结论: CWE253: Incorrect check of fwprintf return value. The code checks if the return value equals 0, but fwprintf returns a negative number on failure. Therefore, when fwprintf fails, the condition (==0) is false, and the error handling block is not executed, leading to silent failure.
- D验证: stage_c_preserved / ver_128112eb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 566. hyp_path_97f2a17ece61

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_05.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 系统环境可能导致fwprintf失败（如磁盘满、stdout关闭）。
- 触发路径: if (fwprintf(stdout, L"%s\n", L"string") == 0) { printLine("fwprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_05.c:36
- 结论: 对fwprintf的返回值检查不正确：代码检查返回值是否等于0，但fwprintf失败时返回负数，因此错误地将失败条件误判为成功。违反了CWE-253（不正确的函数返回值检查）。
- D验证: stage_c_preserved / ver_5634b69f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 567. hyp_path_3ed898b20a3d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_06.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过环境控制影响fwprintf的返回值，例如重定向标准输出或关闭文件描述符
- 触发路径: if (fwprintf(stdout, L"%s\n", L"string") == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_06.c:35
- 结论: 函数fwprintf的返回值检查不正确：代码检查返回值是否等于0，但根据C标准，fwprintf失败时返回负值（如EOF），成功时返回写入的字符数（可能不为0）。因此，当fwprintf失败时（返回负值），错误不会被捕获（因为负值不等于0），导致错误状态未被正确处理。
- D验证: stage_c_preserved / ver_004ae6b4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 568. hyp_path_5556cb3220a0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_07.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，测试代码固定字符串，但API misuse独立于输入
- 触发路径: if (fwprintf(stdout, L"%s\n", L"string") == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_07.c:35
- 结论: fwprintf()返回值的检查不正确：当fwprintf返回0时被误判为失败，但实际返回0表示成功写入0个字符（或正常返回），而失败时应返回负值。正确检查应为返回值<0。
- D验证: stage_c_preserved / ver_a34f8d59
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 569. hyp_path_728d8b37c008

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_09.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入，但调用fwprintf可能因I/O错误失败。
- 触发路径: if (fwprintf(stdout, L"%s\n", L"string") == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_09.c:30
- 结论: fwprintf返回值为负数表示失败，但代码仅检查是否等于0，导致无法正确检测失败情况。
- D验证: stage_c_preserved / ver_6aafa6bd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 570. hyp_path_f13c62b903ec

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_10.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无攻击者输入；调用 fwprintf 可能因内部错误失败
- 触发路径: if (fwprintf(stdout, L"%s\n", L"string") == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_10.c:30
- 结论: 对 fwprintf 函数的返回值检查不正确：代码检查返回值是否等于0，但 fwprintf 失败时返回负数，成功时返回非负整数（实际写入字符数）。这种检查无法捕获失败情况，属于 API 契约违规。
- D验证: stage_c_preserved / ver_8ef916d8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 571. hyp_path_0d6980814c13

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_13.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特定攻击输入；任何执行此代码的路径都会触发错误检查逻辑。
- 触发路径: if (fwprintf(stdout, L"%s\n", L"string") == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_13.c:30
- 结论: 函数 fwprintf 的返回值检查错误：代码检查返回值是否等于0，但 fwprintf 失败时返回负值（EOF），导致错误检测无法捕获失败。这是一个 CWE-253 不正确的函数返回值检查。
- D验证: stage_c_preserved / ver_d5bd42f0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 572. hyp_path_c191a26c161d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_14.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fwprintf(stdout, L"%s\n", L"string") == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_14.c:30
- 结论: 函数fwprintf的返回值检查不正确：代码检查返回值是否等于0来判断失败，但fwprintf在失败时返回负值，正确做法应检查返回值是否小于0。这导致错误处理逻辑可能被绕过，属于API contract违反。尽管该漏洞的直接影响较低（仅错误消息误导），但代码明确违反了CWE-253定义。
- D验证: stage_c_preserved / ver_636b3caa
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 573. hyp_path_2c498ceff8e7

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_15.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可能通过使标准输出流不可写（例如关闭stdout）导致 fwprintf 失败
- 触发路径: if (fwprintf(stdout, L"%s\n", L"string") == 0) @ 31
- 结论: fwprintf() 返回值检查错误：成功时返回非负整数（写入的字符数），失败时返回负值。代码检查是否等于0，当失败返回负值时不会触发失败处理，导致错误被忽略。
- D验证: stage_c_preserved / ver_cce672a4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 574. hyp_path_0aed43aa4b30

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_16.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响标准输出（例如使stdout写入失败，如磁盘满、管道关闭等）。
- 触发路径: if (fwprintf(stdout, L"%s\n", L"string") == 0) { printLine("fwprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_16.c:30
- 结论: 代码中调用fwprintf后错误地检查返回值是否等于0而非小于0，根据API契约，fwprintf失败时返回负数，此检查无法捕获失败返回码，违反CWE-253（错误返回值检查）。尽管静态支持较弱，但A阶段代码证据明确显示API使用违反约定，且注释表明开发者误解，路径可达。
- D验证: stage_c_preserved / ver_5de1251a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 575. hyp_path_36840622deaf

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_18.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序调用fwprintf且其实际执行可能失败（例如stdout被关闭或磁盘满）。
- 触发路径: if (fwprintf(stdout, L"%s\n", L"string") == 0) { printLine("fwprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_18.c:30
- 结论: fwprintf返回值检查错误：误将返回值等于0作为失败条件，但实际失败时返回负数。这违反了CWE-253，可能导致未能检测到写入错误。
- D验证: stage_c_preserved / ver_a12e24bb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 576. hyp_path_eeb730ac223e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_01.c:28
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fputwc((wchar_t)L'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_01.c:28
- 结论: fputwc函数的返回值为WEOF表示失败，但代码中错误地检查返回值是否为0，导致无法正确检测fputwc失败，可能引发未处理错误。
- D验证: stage_c_preserved / ver_577e17d2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 577. hyp_path_6f6b723b072d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_02.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fputwc((wchar_t)L'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_02.c:30
- 结论: 对fputwc函数的返回值进行错误检查：成功时返回写入字符（非0），失败时返回WEOF(-1)，但代码检查返回值是否为0，导致失败时无法检测，违反API contract。
- D验证: stage_c_preserved / ver_850455ed
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 578. hyp_path_32524bb5000d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_03.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fputwc((wchar_t)L'A', stdout) == 0) { printLine("fputwc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_03.c:30
- 结论: 对 fputwc 返回值检查不当：函数失败时返回 WEOF (-1)，但代码检查返回值是否等于 0，导致错误被忽略。
- D验证: stage_c_preserved / ver_3f1f2c7a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 579. hyp_path_8535dffca540

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_04.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fputwc可能由于写入错误（如磁盘满或权限问题）而失败。
- 触发路径: if (fputwc((wchar_t)L'A', stdout) == 0) { printLine("fputwc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_04.c:36
- 结论: 对fputwc()的返回值检查不正确：fputwc()失败时返回WEOF（-1），但代码检查返回值是否等于0，导致无法正确检测失败。
- D验证: stage_c_preserved / ver_1abbd14f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 580. hyp_path_de15a4feaabe

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_05.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响 stdout 的写入状态（例如通过关闭管道、填满磁盘等），但非必需；漏洞本身是代码逻辑错误。
- 触发路径: if (fputwc((wchar_t)L'A', stdout) == 0) { printLine("fputwc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_05.c:36
- 结论: 对 fputwc 的返回值检查错误：函数失败时返回 WEOF（-1），但代码检查返回值是否等于 0，导致失败无法被正确检测。
- D验证: stage_c_preserved / ver_29671df2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 581. hyp_path_f016bad3cd3e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_06.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fputwc 调用可能失败（如 stdout 出错），但无需攻击者直接控制输入。
- 触发路径: if (fputwc((wchar_t)L'A', stdout) == 0) { printLine("fputwc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_06.c:35
- 结论: fputwc() 返回值检查错误：函数失败返回 WEOF (-1) 而非 0，代码检查返回值等于 0 导致失败被忽略。
- D验证: stage_c_preserved / ver_8fb14b88
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 582. hyp_path_5c000af1c17b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_07.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特定攻击者控制条件，仅需fputwc执行时发生失败（如磁盘满、权限问题等）。
- 触发路径: if (fputwc((wchar_t)L'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_07.c:35
- 结论: 对fputwc函数返回值的检查不正确：fputwc失败时返回WEOF（-1），但代码检查返回值是否等于0，导致错误条件无法被正确捕获，可能遗漏错误处理。
- D验证: stage_c_preserved / ver_41657176
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 583. hyp_path_cb1932b17831

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_09.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 任何导致fputwc失败的情况（如标准输出关闭或写入错误）都会触发此错误检查。
- 触发路径: if (fputwc((wchar_t)L'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_09.c:30
- 结论: 对fputwc返回值的检查错误：fputwc失败时返回WEOF(-1)而不是0，代码使用'==0'进行检查，导致失败时不会正确识别，违反了API contract。
- D验证: stage_c_preserved / ver_5dfb516c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 584. hyp_path_38c1658a5a58

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_10.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部可控输入，但错误的返回值检查始终存在。
- 触发路径: if (fputwc((wchar_t)L'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_10.c:30
- 结论: fputwc() 的返回值检查错误：该函数成功时返回写入的宽字符，失败时返回 WEOF (-1)，但代码检查返回值是否等于 0，导致无法正确检测写入失败，违反了 CWE-253 关于正确检查函数返回值的要求。
- D验证: stage_c_preserved / ver_ca0be1ac
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 585. hyp_path_a1599283bee8

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_14.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fputwc 调用可能因 I/O 错误而失败
- 触发路径: if (fputwc((wchar_t)L'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_14.c:30
- 结论: fputwc 函数的返回值检查错误：fputwc 失败时返回 WEOF (-1)，但代码检查返回值是否为 0，导致错误条件无法正确捕获。
- D验证: stage_c_preserved / ver_199101d8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 586. hyp_path_6d71530972ed

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_13.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: Environmental conditions causing fputwc to fail (e.g., disk full, broken pipe, stdout closed).
- 触发路径: if (fputwc((wchar_t)L'A', stdout) == 0) { printLine("fputwc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_13.c:30
- 结论: The code incorrectly checks the return value of fputwc. fputwc returns WEOF (-1) on failure, but the code checks if the return value equals 0. This violates the API contract (CWE-253), leading to failure detection and silent data corruption or loss.
- D验证: stage_c_preserved / ver_e13d8e25
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 587. hyp_path_08c815e147c3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_15.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fputwc((wchar_t)L'A', stdout) == 0) { printLine("fputwc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_15.c:31
- 结论: 对 fputwc() 的返回值检查错误，将返回值与 0 比较，而 fputwc() 失败时返回 WEOF (-1)，导致错误条件被忽略，可能掩盖文件写入失败。
- D验证: stage_c_preserved / ver_510f56d8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 588. hyp_path_90955b06a179

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_16.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fputwc 调用可能因输出错误（如磁盘满、权限问题）而失败，但攻击者无需直接控制参数即可触发该漏洞。
- 触发路径: if (fputwc((wchar_t)L'A', stdout) == 0) { printLine("fputwc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_16.c:30
- 结论: fputwc() 函数在失败时返回 WEOF (-1)，但代码仅检查返回值是否等于 0 来判断失败，导致无法正确检测错误，属于 CWE-253 不正确的函数返回值检查。
- D验证: stage_c_preserved / ver_6ec6ca9f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 589. hyp_path_faf8c2b7df8a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_18.c:30
- 漏洞类型: CWE-253, CWE-754
- CWE: CWE-253; CWE-754
- 风险等级: P1
- 触发条件: fputwc 执行期间发生错误（如 stdout 关闭或写入失败），使得返回值不是 0，而是 WEOF (-1）
- 触发路径: if (fputwc((wchar_t)L'A', stdout) == 0) { printLine("fputwc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputc_18.c:30
- 结论: fputwc() 返回 WEOF (-1) 表示失败，但代码检查返回值是否等于 0，导致错误处理逻辑无法正确捕获失败情况，是典型的 CWE-253 错误返回值检查漏洞。
- D验证: stage_c_preserved / ver_68c4e099
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 590. hyp_path_02e4aa89c55b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_02.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fputws(L"string", stdout) == 0) { printLine("fputws failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_02.c:30
- 结论: fputws() 函数返回值检查错误：当 fputws() 失败时返回 WEOF（-1），但代码中将返回值与 0 比较，导致失败时不会执行错误处理，违反了 CWE-253 函数返回值检查错误。
- D验证: stage_c_preserved / ver_9630db42
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 591. hyp_path_9bfe9036be7e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_01.c:28
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制；fputws可能因I/O错误而失败
- 触发路径: if (fputws(L"string", stdout) == 0) { printLine("fputws failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_01.c:28
- 结论: 对fputws返回值的检查不正确：fputws失败时返回WEOF(-1)，而代码检查返回值是否为0，导致无法正确检测fputws失败。违反API contract，符合CWE-253定义。
- D验证: stage_c_preserved / ver_84dc22c3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 592. hyp_path_3a8f4b5c1318

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_04.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (fputws(L"string", stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_04.c:36
- 结论: 对 fputws 的返回值检查错误：函数失败时返回 WEOF（-1），但代码检查返回值是否等于 0，导致无法正确检测失败情况。
- D验证: stage_c_preserved / ver_8ff0de2f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 593. hyp_path_906524987680

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_03.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者输入控制
- 触发路径: if (fputws(L"string", stdout) == 0) { printLine("fputws failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_03.c:30
- 结论: 函数fputws的返回值检查错误：fputws失败时返回WEOF(-1)，但代码检查返回值是否为0，导致失败情况不会被正确捕获，可能使程序在fputws失败后继续执行而忽略错误，引发意外行为。
- D验证: stage_c_preserved / ver_4f6192b2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 594. hyp_path_a46ba92f9e21

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_05.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fputws 调用可能失败（例如 stdout 关闭或磁盘满），但攻击者一般无法直接控制该失败条件。
- 触发路径: if (fputws(L"string", stdout) == 0) { printLine("fputws failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_05.c:36
- 结论: 函数 fputws 的返回值检查不正确：fputws 失败时返回 WEOF (-1)，但代码检查返回值是否等于 0，导致失败无法被正确检测，违反 CWE-253（不正确的函数返回值检查）。
- D验证: stage_c_preserved / ver_cc912e08
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 595. hyp_path_4fd78cad7c29

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_06.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特定攻击前提，只要程序执行到该代码路径即可触发错误检查逻辑。
- 触发路径: if (fputws(L"string", stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_06.c:35; printLine("fputws failed!"); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_06.c:36
- 结论: 函数fputws返回值的检查错误：代码检查返回值是否等于0来判断失败，但fputws失败时返回WEOF（-1），成功时返回非负值（可能为0）。因此当fputws实际失败时（返回WEOF），条件不满足，错误被忽略；而当fputws成功返回0时，代码错误地认为失败并输出错误信息。这是典型的API misuse，违反了CWE-253。
- D验证: stage_c_preserved / ver_77888465
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 596. hyp_path_0e6835326e0d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_07.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入要求，代码本身存在 API contract 违反；攻击者可能通过影响 stdout 状态触发 fputws 失败，但漏洞本身不依赖攻击者控制输入。
- 触发路径: if (fputws(L"string", stdout) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_07.c:35
- 结论: 对 fputws() 返回值的检查不正确：函数失败时返回 WEOF (-1) 而不是 0，导致无法检测写入失败。
- D验证: stage_c_preserved / ver_6f2aac07
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 597. hyp_path_701bba57a898

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_09.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可能需要影响stdout的输出行为（如设置无效的流状态）以使得fputws返回0，但实际利用场景有限。
- 触发路径: if (fputws(L"string", stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_09.c:30; printLine("fputws failed!"); @ 同文件:32
- 结论: 函数fputws的返回值检查错误：成功时返回非负值（可能为0），失败时返回WEOF（-1）。代码中将返回值为0视为失败，触发错误的错误处理逻辑。
- D验证: stage_c_preserved / ver_f1fb6b69
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 598. hyp_path_ff02b7b98984

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_10.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者控制，fputws 可能因运行时错误（如 stdout 关闭）而失败
- 触发路径: if (fputws(L"string", stdout) == 0) { printLine("fputws failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_10.c:30
- 结论: 调用 fputws 后检查返回值是否等于0，但 fputws 失败时返回 WEOF（-1），成功时返回非负值。错误的条件导致无法正确检测失败，违反了 API contract。
- D验证: stage_c_preserved / ver_c3d01608
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 599. hyp_path_e848b06fd0a1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_13.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致fputws调用失败（如控制stdout写入资源或触发错误条件）
- 触发路径: if (fputws(L"string", stdout) == 0) { printLine("fputws failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_13.c:30
- 结论: fputws返回值的错误检查：函数fputws在失败时返回WEOF(-1)，成功时返回非负整数（可能包括0），但代码中仅检查返回值是否等于0来判断失败，导致当fputws实际失败（返回-1）时不会进入错误处理分支，可能忽略错误条件。
- D验证: stage_c_preserved / ver_3d33c20d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 600. hyp_path_e5b37704deba

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_14.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法直接控制输入或输出，但可能导致 fputws 失败（如 stdout 关闭或磁盘满）
- 触发路径: if (fputws(L"string", stdout) == 0) { printLine("fputws failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_14.c:30
- 结论: 对 fputws 函数返回值的检查错误：将成功/失败条件弄反。fputws 失败时返回 WEOF (-1)，成功时返回非负值（≥0）。代码中检查返回值是否等于 0，这既不能捕获失败（WEOF != 0），也不匹配任何标准成功返回值，导致函数调用失败时无法被检测和处理。
- D验证: stage_c_preserved / ver_3581529e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 601. hyp_path_6c41c54b5a15

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_15.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，但函数调用本身存在失败可能性（如磁盘满、stdout关闭等）
- 触发路径: if (fputws(L"string", stdout) == 0) { printLine("fputws failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_15.c:31
- 结论: fputws函数返回WEOF表示失败，但代码检查返回值是否等于0，这是错误的sentinel检查，导致当函数失败时（返回WEOF）不会触发失败处理，而成功时（返回0）却错误地报告失败。这违反了API contract。
- D验证: stage_c_preserved / ver_1e29a09e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 602. hyp_path_aafc22986987

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_16.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法直接控制fputws()的输出目标（stdout），但系统环境可能导致fputws()失败（如stdout被关闭或重定向到错误设备）。
- 触发路径: if (fputws(L"string", stdout) == 0) { @ 30; printLine("fputws failed!"); @ 31
- 结论: 对fputws()的返回值进行了错误的检查。根据API contract，fputws()在失败时返回WEOF（-1），但代码将其返回值与0进行比较，导致无法正确检测失败情况。
- D验证: stage_c_preserved / ver_a18e6073
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 603. hyp_path_49bbc3920213

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_18.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fputws()函数可能因I/O错误、磁盘满等原因失败，但攻击者通常难以直接控制stdout的输出环境，因此可利用性较低。
- 触发路径: if (fputws(L"string", stdout) == 0) { printLine("fputws failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_18.c:30
- 结论: 函数fputws()的返回值检查不正确：根据文档，fputws()失败时返回WEOF(-1)，成功时返回非负值。但代码中检查返回值是否等于0来判断失败，这会导致在fputws实际失败（返回-1）时，条件不成立，从而错误地认为成功，忽略错误处理。
- D验证: stage_c_preserved / ver_44c5c4e8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 604. hyp_path_a05f7100cc11

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_02.c:93
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供任意输入（fread读取）
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ L72-L88 (case12), L48-L69 (case11)
- 结论: 存在不正确的函数返回值检查：fread返回值与字面量比较，未正确处理部分读取或错误情况，但缓冲区已初始化且仅打印信息，实际安全影响较低。
- D验证: stage_c_preserved / ver_71a253fc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 605. hyp_path_3e7d93c36add

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_01.c:52
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供格式不匹配的输入，使fwscanf返回0，导致data缓冲区未更新
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ L52
- 结论: 函数fwscanf的返回值检查不正确：仅检查了EOF，未检查实际读取的项数（预期1项，返回0或EOF外其他值表示失败）。这违反了CWE-253，可能导致data缓冲区未正确更新，尽管后续未使用data，但存在未初始化数据使用的潜在风险。
- D验证: stage_c_preserved / ver_54c4a75a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 606. hyp_path_4cbc184d726e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_01.c:33
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin控制输入内容，使fwscanf返回EOF（例如提前关闭流或输入无效字符）。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == 0) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_01.c:33
- 结论: 函数fwscanf的返回值检查错误：代码检查返回值是否等于0，但根据CWE-253，正确做法是检查返回值是否为EOF（-1）以判断是否失败。当fwscanf返回EOF时，代码误认为成功，data可能未被正确写入，后续使用未初始化的data可能导致未定义行为。
- D验证: stage_c_preserved / ver_74671ed7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 607. hyp_path_a9ec5bbc8460

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_02.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 输入流 stdin 出现错误（如文件结束或读取错误）导致 fwscanf 返回 EOF
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_02.c:35; printLine("fwscanf failed!"); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_02.c:37
- 结论: 函数 fwscanf 的返回值检查不正确：当 fwscanf 失败时返回 EOF（-1），但代码中仅检查返回值是否为 0，导致可能无法正确检测到失败，符合 CWE-253 定义。虽然 data 变量在后续的使用未在代码证据中完整展示，但违反 API contract 的事实成立，可能存在未初始化数据使用风险。
- D验证: stage_c_preserved / ver_6a81b212
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 608. hyp_path_10e76f5776c6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_02.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供输入，使得 fwscanf 返回 0（匹配失败）或负值（如错误），但非 EOF。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) @ 行 82
- 结论: 函数 fwscanf 的返回值检查不正确：仅检查返回值是否等于 EOF，而未检查是否成功读取了期望数量的输入项（本例中应为 1）。根据 CWE-253，这种不完整的返回值检查可能导致程序在 fwscanf 返回非 EOF 但未成功读取任何输入项时，错误地认为数据有效，进而使用未初始化的 dataBuffer，造成未定义行为。
- D验证: stage_c_preserved / ver_2bf4988c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 609. hyp_path_7e6b45d9bb38

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_02.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供输入导致 fwscanf 返回0（例如输入空字符串或仅空白字符）。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_02.c:63
- 结论: CWE-253 漏洞：fwscanf 返回值检查不完整，只检查了 EOF，未检查返回值为0的情况。当输入未匹配到任何项时，返回值0不被视为错误，导致 data 缓冲区可能未正确初始化。但当前代码片段中无后续对 data 的使用，因此安全影响较低，但仍违反 API 契约。
- D验证: stage_c_preserved / ver_9c2fce93
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 610. hyp_path_01aaa9b496be

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_02.c:93
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: Attacker can provide input that causes fwscanf to return 0 (e.g., empty input or non-matching input) or a positive value (partial match) without triggering the error path.
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ L93 (in case12)
- 结论: Incorrect check of fwscanf return value: only checking for EOF, missing handling for return value 0 (no match) and other positive values (number of items matched). Although the data buffer is initialized and unused, the incomplete check violates CWE-253.
- D验证: stage_c_preserved / ver_b6dc33c8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 611. hyp_path_5f66ced3c233

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_03.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin发送导致fwscanf失败的输入（如EOF或格式不匹配）。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == 0) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_03.c:35
- 结论: 函数fwscanf返回值检查错误：代码检查返回值是否等于0，但失败时返回EOF(-1)而非0，导致无法检测失败情况，可能使用未初始化或错误的数据。
- D验证: stage_c_preserved / ver_058bb6b6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 612. hyp_path_8e2821652a04

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_04.c:99
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin的输入内容，例如提供空字符串或格式不匹配的输入，使fwscanf返回0而不是EOF
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_04.c:99
- 结论: fwscanf的返回值检查不完整，仅检查EOF，未处理返回0的情况，违反了API contract（CWE-253）。
- D验证: stage_c_preserved / ver_0ca534cf
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 613. hyp_path_e875afe6b3c5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_04.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使输入流产生错误，导致fwscanf返回EOF（例如，发送EOF信号或提供格式不正确的输入）。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == 0) { printLine("fwscanf failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_04.c:41
- 结论: 调用了fwscanf函数，但错误地检查返回值：代码检查返回值是否等于0，而实际上fwscanf失败时返回EOF（-1），导致当返回EOF时不会进入错误处理分支，可能使用未初始化的data变量。这违反了CWE-253（函数返回值错误检查）的API contract。
- D验证: stage_c_preserved / ver_6fa5037e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 614. hyp_path_7299b6d7bc8e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_04.c:69
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向stdin提供输入，使得fwscanf匹配失败（例如输入非格式要求的字符串），返回0而非EOF。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_04.c:69
- 结论: CWE-253: 函数fwscanf返回值检查不完整，仅检查了EOF错误，忽略了返回0的情况。当fwscanf返回0时（输入格式不匹配），data变量可能未被正确写入，后续使用（虽然代码片段未展示）可能导致未初始化数据读。
- D验证: stage_c_preserved / ver_db730e3f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 615. hyp_path_4799504c80b3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_05.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响输入流，使得fwscanf调用失败（例如提供空输入或触发文件结束）
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == 0) @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_05.c:41
- 结论: 函数检查fwscanf返回值是否等于0，但fwscanf失败时返回EOF(-1)而不是0，因此当fwscanf失败时，条件不满足，不会打印错误消息，导致错误未被处理。这违反了CWE-253。后续代码若使用未初始化的data变量可能导致未定义行为，但当前代码片段未展示后续使用，因此存在潜在但未完全确认的漏洞。
- D验证: stage_c_preserved / ver_0bad09e7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 616. hyp_path_0adb3ddd05ee

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_06.c:40
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法直接控制fwscanf的返回值，但任何导致fwscanf失败的情况（如EOF、输入格式错误）都会触发错误检查逻辑缺陷。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == 0) { printLine("fwscanf failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_06.c:40
- 结论: 函数fwscanf的返回值检查错误：当fwscanf失败时返回EOF（-1），但代码检查返回值是否等于0，导致无法正确检测失败情况。虽然当前仅打印信息，但违反了API contract，可能掩盖后续错误处理。
- D验证: stage_c_preserved / ver_d5d5855d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 617. hyp_path_acb344e09089

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_04.c:88
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向stdin提供特殊输入，例如仅输入空白字符，导致fwscanf匹配失败返回0
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_04.c:88
- 结论: fwscanf返回值检查错误，仅检查EOF而未检查实际匹配项数。如果输入不匹配格式（如空白行），fwscanf返回0，data保持未初始化，后续使用可能导致未定义行为或信息泄露。
- D验证: stage_c_preserved / ver_b38b4778
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 618. hyp_path_644c56e27118

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_06.c:87
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供输入使fwscanf返回0（例如输入为空或仅包含空白字符）
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_06.c:87
- 结论: 对fwscanf的返回值检查不完整，只检查了EOF，未处理返回0或其他错误情况，违反CWE-253，可能导致使用未正确初始化的数据。
- D验证: stage_c_preserved / ver_ff0dff3e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 619. hyp_path_4e2840e16901

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_06.c:68
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者提供输入使得fwscanf返回0（无匹配项）
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_06.c:68
- 结论: fwscanf返回值检查不完整：仅检查EOF失败情况，未检查返回0（无匹配）导致data内容可能未更新，违反CWE-253
- D验证: stage_c_preserved / ver_2cf7ba5f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 620. hyp_path_70dbd78f25d3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_07.c:40
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入流，使其在 fwscanf 调用时失败（例如提供 EOF 或达到文件末尾）。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_07.c:40
- 结论: 调用 fwscanf 后检查返回值是否等于0，但 fwscanf 失败时返回 EOF(-1)，导致错误处理条件遗漏，可能使用未初始化的 data 或导致未定义行为。
- D验证: stage_c_preserved / ver_dacc3440
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 621. hyp_path_d335cc64d3b4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_07.c:87
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入，使得fwscanf返回0（例如输入空字符串或与%99s不匹配的数据）
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_07.c:87
- 结论: fwscanf返回值检查不完整：仅检查返回值是否为EOF，未检查实际成功匹配的项数。当fwscanf返回0（如输入与格式不匹配）时，无法正确识别输入失败，可能导致后续使用未初始化的data值。
- D验证: stage_c_preserved / ver_31d87595
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 622. hyp_path_3d0be9d1e3b3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_09.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致fwscanf失败，例如通过关闭标准输入或提供导致读取错误的数据。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == 0) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_09.c:35
- 结论: 代码错误地检查fwscanf的返回值，将返回值等于0视为失败，而实际失败时返回EOF(-1)。这导致当fwscanf失败时，错误处理分支不被触发，违反了CWE-253关于正确检查函数返回值的规范。尽管当前代码片段未展示后续对未初始化数据的使用，但返回值检查错误本身构成可靠漏洞假设，需动态验证潜在影响。
- D验证: stage_c_preserved / ver_a8a10240
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 623. hyp_path_64ce5373a895

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_10.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin的行为，例如通过关闭输入流或发送EOF，使得fwscanf返回-1（EOF），从而绕过错误检查
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_10.c:35; printLine("fwscanf failed!"); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_10.c:36
- 结论: 对fwscanf()的返回值检查不正确，只检查是否等于0，但未检查EOF（-1）或其他失败返回值。当fwscanf返回EOF时，条件不成立，错误未被检测，后续代码可能使用未初始化的data变量，违反CWE253。
- D验证: stage_c_preserved / ver_e8e1adc8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 624. hyp_path_e1d1e0709e17

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_13.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入流（如stdin）使其返回EOF或错误。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_13.c:35
- 结论: 函数fwscanf的返回值检查不正确：当fwscanf返回EOF（-1）时，代码仅检查是否等于0，导致输入失败未被检测到，错误处理路径未执行。
- D验证: stage_c_preserved / ver_5ec0a90d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 625. hyp_path_ebc05d97b470

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_09.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供不符合%99s格式的输入（如仅空白字符或空输入），导致fwscanf返回0而不是EOF。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_09.c:82
- 结论: 函数fwscanf的返回值检查不完整：仅检查是否等于EOF，未检查返回0（输入匹配失败）的情况，违反CWE-253。虽然dataBuffer已初始化为空字符串，未读取数据时后续使用影响较低，但API contract violation仍然存在，可能导致程序逻辑错误（如认为输入成功实际失败）。
- D验证: stage_c_preserved / ver_f081746c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 626. hyp_path_3f0de1e2efd1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_13.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向stdin提供字符串，使得fwscanf返回0（例如，输入空字符串或不匹配格式的内容）。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_13.c:82
- 结论: 函数fwscanf的返回值检查不完整：仅检查是否等于EOF，未处理返回0的情况，当输入不匹配格式或为空时，data缓冲区可能未被正确填充，违反CWE-253。但当前代码片段未展示后续使用data，因此实际影响取决于后续上下文。
- D验证: stage_c_preserved / ver_e35815a3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 627. hyp_path_bdff89d05dad

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_14.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过 stdin 提供输入，使得 fwscanf 的返回值不为0（包括 EOF）
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == 0) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_14.c:35
- 结论: 函数 fwscanf 的返回值检查错误：代码仅检查返回值是否为0，但 fwscanf 在失败时返回 EOF（-1），成功时返回成功匹配的输入项数（通常为1）。如果 fwscanf 返回 EOF，不会被认为失败，导致错误处理遗漏，可能后续使用未正确初始化的 data 缓冲区，造成逻辑错误或未初始化内存访问。
- D验证: stage_c_preserved / ver_b64351e8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 628. hyp_path_c55ad0e4025a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_15.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供数据，触发fwscanf返回EOF（如不输入任何内容、输入格式错误或提前关闭输入流）。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_15.c:36
- 结论: 函数fwscanf的返回值检查错误：代码检查返回值为0，但fwscanf失败时返回EOF(-1)，导致错误处理路径未被执行。
- D验证: stage_c_preserved / ver_5212bd97
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 629. hyp_path_69481e33f6f9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_14.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供使fwscanf返回非EOF但非1的输入（如空输入或格式不匹配的字符串）
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_14.c:82; printLine("fwscanf failed!"); // only on EOF, not on partial read @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_14.c:84; data buffer may contain uninitialized or incomplete data after non-EOF return @ implicit
- 结论: fwscanf返回值检查不完整：仅检查EOF，但未验证是否成功读取到期望数量的项（如返回1）。当输入格式不匹配或提前结束时，fwscanf可能返回0或小于期望值，导致后续使用未完全初始化的dataBuffer，可能引发未定义行为或信息泄露。
- D验证: stage_c_preserved / ver_9d695afa
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 630. hyp_path_5f4567d2e797

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_16.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可以通过关闭标准输入或发送EOF信号使fwscanf返回EOF，从而绕过失败处理，导致程序使用未初始化的data变量。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == 0) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_16.c:35
- 结论: 在fwscanf函数调用中，返回值检查不正确：代码仅检查返回值是否等于0，但fwscanf失败时返回EOF(-1)，而不是0。这违反了函数契约，可能导致错误未被检测，从而使程序使用未初始化的数据或继续执行错误状态。攻击者可通过关闭标准输入或发送EOF信号触发此路径。
- D验证: stage_c_preserved / ver_880be7dc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 631. hyp_path_5fc234f481c6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_15.c:106
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入的内容，例如通过程序交互提供空行（直接回车）
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_15.c:99
- 结论: 代码中对fwscanf的返回值检查不完整：仅检查返回值是否为EOF，而未检查返回值是否大于0（即成功匹配的项数）。当输入为空（例如用户直接输入换行符）时，fwscanf返回0，代码不认为出错，导致dataBuffer保持初始空字符串。虽然后续未使用dataBuffer，但违反了CWE-253对函数返回值正确检查的要求。
- D验证: stage_c_preserved / ver_a76ad8d5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 632. hyp_path_f5737d571622

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_15.c:69
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_15.c:69
- 结论: CWE-253: Incorrect Check of Function Return Value on fwscanf
- D验证: stage_c_preserved / ver_8e244898
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 633. hyp_path_853a85b080bf

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_16.c:59
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，提供格式不匹配的字符串（如空字符串或非匹配字符），使得fwscanf返回0而非EOF。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ L59
- 结论: 存在CWE-253漏洞：对fwscanf返回值检查不完整，仅检查EOF而忽略返回0的情况，导致在格式不匹配时dataBuffer可能未初始化，后续使用可能造成未定义行为。
- D验证: stage_c_preserved / ver_92024efa
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 634. hyp_path_fc91629a3d72

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_15.c:90
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制 stdin 输入，使 fwscanf 返回 0（无匹配项）
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_15.c:90
- 结论: 程序调用 fwscanf 后仅检查返回值是否为 EOF，未检查其他可能的失败返回值（如 0），导致输入格式不匹配时 data 缓冲区可能未被正确更新，构成 CWE-253 违规，但代码片段未展示 data 后续使用，可利用性待验证。
- D验证: stage_c_preserved / ver_333b8efc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 635. hyp_path_f8b6b23c80dc

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_01.c:28
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 需要在fwrite执行时发生写入错误（如磁盘满、stdout关闭等）。
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) < 0) { printLine("fwrite failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_01.c:28
- 结论: fwrite函数的返回值检查错误：代码检查返回值是否小于0，但fwrite失败时返回实际写入的元素数（小于请求数），不会返回负数。正确的检查应判断返回值是否不等于请求写入的元素数。此错误可能导致写入部分数据而未被检测到。
- D验证: stage_c_preserved / ver_08e71539
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 636. hyp_path_181d6de4fe0a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_02.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法直接控制输入，但可以尝试制造I/O错误（例如耗尽磁盘空间）以触发fwrite失败，但错误检查的缺陷使得失败无法被检测到。
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) < 0) @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_02.c:30
- 结论: 对fwrite返回值的检查不正确：fwrite返回size_t类型，不可能小于0，因此错误检查条件永远为假，fwrite失败时无法被检测到。
- D验证: stage_c_preserved / ver_d7883bdb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 637. hyp_path_93d0293877d9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_18.c:57
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使fwscanf返回0，例如输入空行或无效数据
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_18.c:57; if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_18.c:59
- 结论: 函数fwscanf的返回值检查不完整，只检查是否等于EOF，未检查是否等于期望的输入项数（1）。如果fwscanf返回0（无匹配输入），则data可能保持未初始化或空字符串，构成CWE-253违反。尽管后续未直接使用data，但返回值检查本身违反API契约，存在潜在风险。
- D验证: stage_c_preserved / ver_3c6a2236
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 638. hyp_path_aa829c8f51e3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_18.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使得fwscanf返回EOF
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == 0) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_18.c:35
- 结论: fwscanf的返回值检查条件错误：成功时返回1，失败返回EOF(-1)，代码检查是否等于0，导致当fwscanf实际失败时（返回EOF）不会进入错误处理分支。虽然当前代码片段在if块内仅打印固定字符串，未直接使用未初始化的data变量，但API misuse本身符合CWE-253，且在不完整的路径中可能因后续代码使用data而引发未定义行为。
- D验证: stage_c_preserved / ver_00e1e4cb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 639. hyp_path_ed5b08cc98da

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_03.c:30
- 漏洞类型: CWE-253, CWE-398
- CWE: CWE-253; CWE-398
- 风险等级: P1
- 触发条件: fwrite可能因系统错误或重定向失败，但检查条件错误导致无法捕获
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_03.c:30
- 结论: fwrite()返回值检查错误：使用<0比较，但fwrite返回size_t（无符号类型），条件永远为假，无法检测写入失败。
- D验证: stage_c_preserved / ver_ed056fa0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 640. hyp_path_7344677805d3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_04.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fwrite 在运行时可能因资源不足而失败，但攻击者无需直接控制输入，错误条件恒假导致错误被忽略。
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_04.c:36
- 结论: 函数 fwrite 的返回值检查错误：fwrite 返回实际写入的元素数（size_t类型），从不返回负数，但此处检查返回值是否小于0，导致无法检测到写入失败。
- D验证: stage_c_preserved / ver_46a57c45
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 641. hyp_path_478819360511

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_05.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fwrite()执行失败的条件（如stdout写入失败）
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_05.c:36
- 结论: 代码使用了错误的返回值检查条件，fwrite()返回size_t（无符号类型），检查其返回值是否小于0永远为假，导致无法正确检测fwrite失败，违反了CWE-253（Incorrect Check of Function Return Value）。
- D验证: stage_c_preserved / ver_f6e11666
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 642. hyp_path_15b7382bfd37

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_06.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fwrite 调用可能失败（如 stdout 关闭、磁盘满、权限不足）
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_06.c:35
- 结论: fwrite 返回值类型为 size_t（无符号），但代码检查其是否小于 0，该条件永远为假，导致无法正确检测写入失败，属于 CWE-253 错误返回值检查。
- D验证: stage_c_preserved / ver_c03d4b57
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 643. hyp_path_2315458d8041

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_07.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 存在导致fwrite失败的环境条件（如磁盘满、stdout关闭等）
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_07.c:35
- 结论: 函数fwrite的返回值检查不正确：fwrite成功时返回写入的对象数，失败时返回0或小于count的数，但不会返回负数。代码检查返回值<0，导致fwrite失败时无法被正确检测。
- D验证: stage_c_preserved / ver_25d3e8eb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 644. hyp_path_52b40d293319

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_10.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fwrite因磁盘满、权限错误等任何原因失败
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) < 0) @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_10.c:30
- 结论: 程序使用fwrite函数时，检查返回值是否小于0，但fwrite返回值为无符号类型size_t，永远不会小于0，导致无法检测到写入失败。
- D验证: stage_c_preserved / ver_36230ec4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 645. hyp_path_8fb6eb581060

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_09.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特殊攻击前提，任何调用此路径的场景都会触发错误的返回值检查。
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) < 0) @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_09.c:30
- 结论: 对 fwrite 的返回值检查不正确，使用 < 0 进行比较，但 fwrite 返回 size_t，成功时返回写入的元素数（等于请求数），失败时返回小于请求数的值（通常为 0），不会返回负数。因此当 fwrite 失败时，条件 < 0 永为假，导致错误被忽略。
- D验证: stage_c_preserved / ver_fc2e6bdb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 646. hyp_path_39a87143a0a9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_14.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响fwrite的写入结果，例如通过耗尽磁盘空间或限制stdout缓冲等
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_14.c:30
- 结论: fwrite()返回值检查不正确：fwrite返回写入的元素数，失败时返回小于请求数量的值（通常为0），而非负数。代码中用 < 0 检查错误是无效的，无法捕获写入失败，属于CWE-253（不正确的函数返回值检查）。
- D验证: stage_c_preserved / ver_e033d0dc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 647. hyp_path_fef7a3f96d2b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_13.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fwrite() 调用可能失败（例如文件系统满、权限错误）.
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_13.c:30
- 结论: 对 fwrite() 的返回值检查错误：使用 `< 0` 比较，但 fwrite() 返回无符号 size_t，永远不小于 0，导致错误条件永不触发，违反 CWE-253。尽管实际影响较低（无外部输入），但漏洞本身存在。
- D验证: stage_c_preserved / ver_0c487257
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 648. hyp_path_9f4252f6ec0f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_15.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入，每次调用均触发错误检查逻辑; 需要stdout写入失败（如磁盘满、权限不足）才能实际触发漏洞
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) < 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_15.c:31
- 结论: fwrite的返回值检查错误：正确检查应比较返回值是否等于期望写入的项数（wcslen(L"string")），而非检查是否小于0。由于fwrite返回size_t无符号类型，返回值永远不小于0，导致写入失败无法被检测。
- D验证: stage_c_preserved / ver_e9cd4a27
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 649. hyp_path_74db31b7033c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_16.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fwrite 可能因资源限制、文件系统错误等原因失败，但代码的错误检查无效，无法捕获此异常。
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) < 0) { printLine("fwrite failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_16.c:30
- 结论: 对 fwrite 返回值的检查不正确：将返回值与小于 0 比较，但 fwrite 返回 size_t（无符号类型），永远不会小于 0。这导致无法检测写入失败的情况，违反 CWE-253 错误检查函数返回值。
- D验证: stage_c_preserved / ver_b8e5d2e9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 650. hyp_path_593156b53d7d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_18.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者需通过其他手段导致stdout写入失败，如文件系统错误、资源耗尽或stdout关闭。
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) < 0) { printLine("fwrite failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_18.c:30
- 结论: fwrite返回值检查错误：条件fwrite(...) < 0永远不会为真，因为fwrite返回size_t类型，失败时返回0或小于请求数的正值，而非负数，导致错误未被正确处理。
- D验证: stage_c_preserved / ver_d106ea43
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 651. hyp_path_62ebe4f49592

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_02.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putwc()调用因任何原因失败（如输出错误）
- 触发路径: if (putwc((wchar_t)L'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_02.c:30
- 结论: putwc()函数返回EOF(-1)表示失败，但代码错误地检查返回值是否为0，导致无法检测写入失败。
- D验证: stage_c_preserved / ver_47007d96
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 652. hyp_path_d5ebdedbb68c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_01.c:28
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者控制输入，但环境因素（如stdout关闭、磁盘满等）可能导致putwc失败
- 触发路径: if (putwc((wchar_t)L'A', stdout) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_01.c:28
- 结论: putwc()函数可能失败返回EOF(-1)，但代码错误地检查返回值是否为0。当putwc失败时，条件不成立，不会打印错误信息，导致错误被忽略。
- D验证: stage_c_preserved / ver_0985ed62
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 653. hyp_path_3b26d6a48ec7

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_03.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致putwc失败（例如通过关闭stdout或写入错误）。
- 触发路径: if (putwc((wchar_t)L'A', stdout) == 0) @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_03.c:30
- 结论: 函数putwc的返回值检查错误：putwc失败时返回EOF(-1)，但代码检查返回值为0才视为失败，导致错误未正确检测。
- D验证: stage_c_preserved / ver_5fca5492
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 654. hyp_path_98a8d24892f2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_04.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (putwc((wchar_t)L'A', stdout) == 0) { printLine("putwc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_04.c:36
- 结论: putwc()返回值检查错误：函数失败时返回EOF(-1)，但代码检查返回值是否等于0，导致无法正确检测失败。
- D验证: stage_c_preserved / ver_f8089e52
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 655. hyp_path_aeced34e4a41

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_05.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特定攻击者输入要求；函数自身可能失败（如输出流错误）
- 触发路径: if (putwc((wchar_t)L'A', stdout) == 0) { printLine("putwc failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_05.c:36
- 结论: 函数putwc()在失败时返回EOF(-1)，但代码检查返回值是否为0，这是错误的检查。如果putwc()失败，将不会检测到错误，可能导致未处理的异常或资源泄露。
- D验证: stage_c_preserved / ver_b4dc138b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 656. hyp_path_1ccebb9bf492

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_06.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putwc()调用可能失败（例如stdout关闭或缓冲刷新失败），但代码中无外部输入控制，攻击者无法直接影响该调用，然而返回值检查错误独立于输入。
- 触发路径: if (putwc((wchar_t)L'A', stdout) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_06.c:35
- 结论: 对putwc()函数的返回值检查错误：putwc()失败时返回EOF（即-1），但代码中将其与0比较，导致永远无法检测到失败，违反了API contract。
- D验证: stage_c_preserved / ver_e8d0e013
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 657. hyp_path_01f398a2a10f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_07.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putwc可能因stdout错误而失败（如文件流关闭或写入错误）
- 触发路径: if (putwc((wchar_t)L'A', stdout) == 0) { printLine("putwc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_07.c:35
- 结论: 函数putwc的返回值检查错误：putwc失败时返回EOF(-1)，但代码检查返回值是否等于0，导致失败情况未被正确处理。
- D验证: stage_c_preserved / ver_5127a81b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 658. hyp_path_eef027ba2919

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_10.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入，代码自动执行；但错误检查逻辑导致putwc失败时无法被正确捕获。
- 触发路径: if (putwc((wchar_t)L'A', stdout) == 0) { printLine("putwc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_10.c:30
- 结论: 对putwc返回值检查错误，应该检查返回值是否为WEOF（-1）而不是0。当前代码检查putwc返回值等于0，但putwc失败返回WEOF（-1），导致无法正确检测putwc失败。
- D验证: stage_c_preserved / ver_a7be6ceb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 659. hyp_path_a9ecf5e6d3f0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_09.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putwc()执行时遇到失败条件（例如stdout关闭或磁盘空间不足）
- 触发路径: if (putwc((wchar_t)L'A', stdout) == 0) { printLine("putwc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_09.c:30
- 结论: 代码对putwc()的返回值使用了错误的哨兵值检查，导致函数失败时可能未被正确检测。putwc()失败返回EOF(-1)，但代码检查返回值是否为0，因此当putwc()失败时，错误路径不会执行，但程序行为仍然正常（只是字符未输出）。这是CWE-253不正确的函数返回值检查。
- D验证: stage_c_preserved / ver_9939462c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 660. hyp_path_223dcc9e2cff

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_13.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特定的攻击者控制输入，但putwc可能因stdout写入错误而失败。
- 触发路径: if (putwc((wchar_t)L'A', stdout) == 0) { printLine("putwc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_13.c:30
- 结论: 在putwc函数调用后，错误地检查返回值是否等于0，而putwc失败时返回WEOF（通常为-1），永远不会等于0，导致putwc失败时未正确处理。
- D验证: stage_c_preserved / ver_fdba3599
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 661. hyp_path_f2e1bca73ab3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_14.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putwc()调用因某些条件（如输出错误、磁盘满等）失败
- 触发路径: if (putwc((wchar_t)L'A', stdout) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_14.c:30
- 结论: 对putwc()返回值的检查错误：函数失败时返回WEOF（-1），但代码仅检查返回值是否为0，导致无法正确检测写入失败。
- D验证: stage_c_preserved / ver_ca52e48e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 662. hyp_path_3e668b561268

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_15.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特定攻击者输入控制，putwc() 可能因输出错误等原因失败。
- 触发路径: if (putwc((wchar_t)L'A', stdout) == 0) { printLine("putwc failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_15.c:31
- 结论: 函数 putwc() 返回 EOF (-1) 表示失败，但代码错误地检查返回值是否等于 0，导致错误未被检测到；可能造成未处理错误或后续行为异常。
- D验证: stage_c_preserved / ver_499e3d74
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 663. hyp_path_9b0f97d2a715

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_16.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入要求，仅需putwc函数实际失败（如stdout错误）。
- 触发路径: if (putwc((wchar_t)L'A', stdout) == 0) { printLine("putwc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_16.c:30
- 结论: 对putwc函数的返回值检查错误：putwc返回WEOF（-1）表示失败，而代码检查是否等于0，这无法正确捕获失败情况，违反了CWE-253（函数返回值检查不正确）的API契约。
- D验证: stage_c_preserved / ver_93e63d7c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 664. hyp_path_fe9b3c6b9681

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_18.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可能通过影响stdout的状态（例如关闭流）导致putwc失败，但无需直接控制输入。
- 触发路径: if (putwc((wchar_t)L'A', stdout) == 0) { printLine("putwc failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putc_18.c:30
- 结论: 对putwc()函数的返回值检查不正确：putwc()失败时返回WEOF(-1)，但代码检查返回值是否为0，导致错误检测。
- D验证: stage_c_preserved / ver_17581df9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 665. hyp_path_a54f0c50667a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_01.c:28
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特殊前提，只需 putwchar 实际失败即可暴露错误检查。
- 触发路径: if (putwchar((wchar_t)L'A') == 0) { printLine("putwchar failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_01.c:28
- 结论: 对 putwchar 的返回值检查错误：代码将返回值与 0 比较，但 putwchar 失败时返回 WEOF(-1)，正确检查应为 != WEOF。这违反了 API 契约，属于 CWE-253 漏洞。
- D验证: stage_c_preserved / ver_8db05702
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 666. hyp_path_928d92eee6b1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_02.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序执行到该调用点时，putwchar 可能因某些条件（如输出错误）而失败。
- 触发路径: if (putwchar((wchar_t)L'A') == 0) @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_02.c:30
- 结论: 对 putwchar() 的返回值检查错误：putwchar() 失败时返回 WEOF (-1)，但代码将其与 0 比较，导致失败无法被正确检测，可能引发未处理的错误状态。
- D验证: stage_c_preserved / ver_e7ad134b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 667. hyp_path_9647f5ed872b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_03.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致putwchar()执行失败（例如使输出设备不可用或限制缓冲区空间）
- 触发路径: if (putwchar((wchar_t)L'A') == 0) { printLine("putwchar failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_03.c:30
- 结论: 对putwchar()函数返回值的检查不正确：putwchar()失败时返回WEOF(-1)，但代码检查返回值是否等于0，导致无法检测失败情况。
- D验证: stage_c_preserved / ver_86b684c8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 668. hyp_path_b630d51f3847

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_04.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响putwchar()的执行环境，导致其失败（如文件系统错误、输出流关闭等）。
- 触发路径: if (putwchar((wchar_t)L'A') == 0) { printLine("putwchar failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_04.c:36
- 结论: 函数putwchar()可能返回WEOF(-1)表示失败，但代码错误地检查返回值是否等于0，导致失败情况无法被正确捕获，违反API contract。
- D验证: stage_c_preserved / ver_65baf626
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 669. hyp_path_e2661317cc4b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_05.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致putwchar调用失败（如通过控制文件描述符或输出环境）
- 触发路径: if (putwchar((wchar_t)L'A') == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_05.c:36
- 结论: CWE-253：对putwchar的返回值检查错误。函数成功时返回写入的宽字符，失败时返回WEOF(-1)，但代码检查返回值是否等于0，导致失败时错误未被捕获。
- D验证: stage_c_preserved / ver_fc368b47
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 670. hyp_path_ada9236ea3bd

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_06.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需外部输入控制，putwchar函数自身的失败条件即可触发
- 触发路径: if (putwchar((wchar_t)L'A') == 0) { printLine("putwchar failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_06.c:35
- 结论: 在调用putwchar函数后，检查返回值是否等于0，但putwchar失败时返回WEOF(-1)，而非0。因此对函数返回值的检查条件错误，无法正确检测失败情况。
- D验证: stage_c_preserved / ver_6806409e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 671. hyp_path_803ba81967d4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_07.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无，任何执行路径都会命中此误用
- 触发路径: if (putwchar((wchar_t)L'A') == 0) { printLine("putwchar failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_07.c:35
- 结论: 对putwchar()的返回值检查错误：putwchar失败时返回WEOF(-1)，但代码检查返回值是否为0，导致无法正确检测失败。
- D验证: stage_c_preserved / ver_06ae56e5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 672. hyp_path_465b1edc8d40

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_09.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putwchar调用可能失败（如输出错误），但无需攻击者输入控制
- 触发路径: if (putwchar((wchar_t)L'A') == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_09.c:30
- 结论: 代码错误地检查putwchar返回值是否等于0，而putwchar失败时返回WEOF(-1)，正确的检查应是是否为WEOF。这违反了CWE-253，可能导致未检测到函数失败，影响程序健壮性，可能被利用于后续拒绝服务或逻辑错误。
- D验证: stage_c_preserved / ver_46c13b52
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 673. hyp_path_cbfa92e027b0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_10.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，但 putwchar() 可能因内部原因（如输出错误）失败。
- 触发路径: if (putwchar((wchar_t)L'A') == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_10.c:30
- 结论: 代码中检查 putwchar() 的返回值是否等于 0，然而 putwchar() 失败时返回 WEOF (-1)，而非 0。因此，当 putwchar() 失败时，条件为假，不会执行错误处理，导致未能正确检测到失败。
- D验证: stage_c_preserved / ver_bd48b80b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 674. hyp_path_d52690ecb441

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_13.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (putwchar((wchar_t)L'A') == 0) { printLine("putwchar failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_13.c:30
- 结论: 对putwchar函数返回值进行了错误的检查，将其与0比较，但函数失败时返回WEOF(-1)而非0，导致未正确处理写入失败的情况。
- D验证: stage_c_preserved / ver_b79bf552
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 675. hyp_path_ed1b5bedcbe9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_14.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putwchar()执行时发生写入错误（如设备无空间、权限不足等）。
- 触发路径: if (putwchar((wchar_t)L'A') == 0) @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_14.c:30; printLine("putwchar failed!"); @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_14.c:31
- 结论: putwchar()在失败时返回WEOF(-1)，但代码错误地使用等于0的条件检查，导致写入失败无法被正确检测，可能造成数据丢失或程序行为异常。
- D验证: stage_c_preserved / ver_d63a44e5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 676. hyp_path_b5f8a2302578

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_15.c:31
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putwchar()因某些原因（如设备错误、权限不足等）返回WEOF(-1)
- 触发路径: if (putwchar((wchar_t)L'A') == 0) { printLine("putwchar failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_15.c:31
- 结论: 在putwchar的返回值检查中，错误地将返回值与0比较，而非与WEOF(-1)比较，导致putwchar失败时无法正确检测并处理错误，违反了API契约，属于CWE-253 Incorrect Check of Function Return Value。
- D验证: stage_c_preserved / ver_718e9b99
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 677. hyp_path_e66cc58c39c0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_16.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (putwchar((wchar_t)L'A') == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_16.c:30
- 结论: 在调用putwchar时，错误地将返回值与0比较而非与WEOF比较，导致当putwchar实际失败（返回WEOF）时，错误检查条件不满足，从而不执行失败处理逻辑。这违反了API契约，属于CWE-253错误返回值检查。
- D验证: stage_c_preserved / ver_a72bd534
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 678. hyp_path_67e14eca0fcd

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_18.c:30
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可能通过影响输出流（如关闭stdout）导致putwchar失败，但无法直接控制返回值。
- 触发路径: if (putwchar((wchar_t)L'A') == 0) { printLine("putwchar failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_putchar_18.c:30
- 结论: putwchar函数的返回值检查错误：putwchar()成功时返回写入的宽字符（非0），失败时返回WEOF（-1）。代码使用==0作为失败条件，导致putwchar失败时不会触发错误处理，违反了CWE-253（Incorrect Check of Function Return Value）。
- D验证: stage_c_preserved / ver_51c2c13b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 679. hyp_path_0871d61bdaf0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_01.c:34
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特定攻击者输入，但putws()的返回值可因运行时环境（如输出错误）而变。
- 触发路径: if (PUTS(L"string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_01.c:34
- 结论: 对putws()的返回值进行了错误的检查：代码检查返回值是否为0，但putws()成功时返回非负整数（可能为0），失败时返回WEOF(-1)。正确的检查应该是测试返回值是否为WEOF。这种错误检查可能导致在putws实际成功时误报失败，或在putws失败时误认为成功，从而引发不正确的错误处理。
- D验证: stage_c_preserved / ver_f965ea99
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 680. hyp_path_895c6041ef94

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_02.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者输入，代码固有缺陷
- 触发路径: if (PUTS(L"string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_02.c:36
- 结论: 函数 putws() 的返回值检查不正确：putws() 失败时返回 WEOF (-1)，但代码检查返回值为 0 时认为失败，导致错误处理逻辑未被触发，违反 API contract。
- D验证: stage_c_preserved / ver_b3b2dc0f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 681. hyp_path_e25505b2b933

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_03.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部攻击者控制输入；代码自身逻辑缺陷。
- 触发路径: if (PUTS(L"string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_03.c:36
- 结论: 对wchar_t puts（putws）函数的返回值检查错误：代码检查返回值是否为0，但putws成功时返回非负值（通常为实际写入的字符数），失败时返回WEOF(-1)。因此，当putws成功时，条件为假，不会进入错误处理；当putws失败时，条件也为假（因为-1 ≠ 0），同样不会进入错误处理。这导致putws失败时无法被检测，违反CWE-253（函数返回值错误检查）。
- D验证: stage_c_preserved / ver_b69e60f0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 682. hyp_path_9e9587ac2d15

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_02.c:71
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (PUTS(L"string") == WEOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_02.c:71
- 结论: FUNCTION_RETURN_VALUE_MISCHECK
- D验证: stage_c_preserved / ver_3d1dd069
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 683. hyp_path_536bda16614b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_04.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入；该代码为自包含测试用例，但返回值检查逻辑错误在任何调用场景下均存在
- 触发路径: if (PUTS(L"string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_04.c:42
- 结论: 代码错误地检查了putws()函数的返回值。putws()失败时返回WEOF(-1)，但代码通过检查返回值是否等于0来判断失败，导致成功时误判为失败，失败时误判为成功，违反CWE-253。
- D验证: stage_c_preserved / ver_d038a57f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 684. hyp_path_69842de57cfa

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_05.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需外部输入；代码本身逻辑错误，静态存在。
- 触发路径: if (PUTS(L"string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_05.c:42
- 结论: 在调用putws（通过PUTS宏）时，错误地将返回值是否为0作为失败条件，而标准规定失败返回WEOF(-1)，成功返回非负值（可能为0）。这导致成功时误报失败，失败时漏报，违反了CWE-253（函数返回值检查不正确）。
- D验证: stage_c_preserved / ver_f803cf24
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 685. hyp_path_e611bc66ac31

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_06.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部攻击者控制输入，但 putws() 可能因内部错误（如文件系统满、输出设备错误）而失败。
- 触发路径: if (PUTS(L"string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_06.c:41
- 结论: 函数 putws() 的返回值检查错误：代码检查返回值是否为 0，但 putws() 失败时返回 WEOF (-1)，而非 0，违反了 API contract，导致错误处理无法正确捕获失败情况。
- D验证: stage_c_preserved / ver_444214c5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 686. hyp_path_5166c5e3caca

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_07.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特定攻击者输入，代码执行到该路径即可
- 触发路径: if (PUTS(L"string") == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_07.c:41
- 结论: CWE253: 不正确的函数返回值检查。函数 putws() 失败时返回 WEOF (-1)，但代码检查返回值是否等于 0，这导致失败未被正确检测。虽然此处仅打印一条消息，但违反了 API contract。
- D验证: stage_c_preserved / ver_dbcf9768
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 687. hyp_path_287ce28ec485

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_07.c:76
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需外部输入，即使使用常量字符串，返回值检查错误仍然构成 API misuse 漏洞。
- 触发路径: if (PUTS(L"string") == WEOF) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_07.c:76
- 结论: VULNERABILITY_FOUND: 对 puts 函数（实际为 wchar_t 变种）的返回值检查使用了错误的常量 WEOF，违反了 CWE-253 定义的不正确返回值检查。
- D验证: stage_c_preserved / ver_477a6011
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 688. hyp_path_41a2f6577a14

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_09.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法直接控制函数参数，但函数可能因环境因素（如磁盘满、权限不足）失败，此漏洞属于逻辑缺陷，无需攻击者主动控制。
- 触发路径: if (PUTS(L"string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_09.c:36
- 结论: CWE-253: 不正确的函数返回值检查。函数PUTS（可能是putws的宏）失败时返回WEOF(-1)，但代码错误地检查返回值是否等于0，导致无法正确检测失败。
- D验证: stage_c_preserved / ver_767e9eb2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 689. hyp_path_a90997c8e7c2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_10.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 不需要攻击者输入；但putws可能因环境因素（如输出流错误）而失败
- 触发路径: if (PUTS(L"string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_10.c:36
- 结论: 函数putws的返回值检查错误：putws失败时返回WEOF(-1)，但代码检查返回值是否为0来判断失败，导致失败时无法正确处理。
- D验证: stage_c_preserved / ver_e598a386
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 690. hyp_path_309995088551

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_13.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: putws()调用失败（例如标准输出不可用或写入错误）即可触发错误条件检查不正确的问题。无外部输入控制。
- 触发路径: if (PUTS(L"string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_13.c:36
- 结论: 函数putws()的返回值检查不正确：代码检查返回值是否等于0，但putws()成功时返回非负整数（写入的字符数），失败时返回WEOF（-1）。因此，当putws()失败时，条件为假（因为-1 != 0），不会执行错误处理逻辑（printLine("puts failed!")），导致错误被忽略；反之，如果putws()成功且返回0（例如写入0个字符），则会误触发错误处理。这违反了API contract，属于CWE-253缺陷。由于B阶段风险分数较低，且无外部输入控制，该漏洞影响有限，但仍需确认。
- D验证: stage_c_preserved / ver_92fd367c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 691. hyp_path_e78515540409

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_14.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者输入，代码本身存在错误返回值检查
- 触发路径: if (PUTS(L"string") == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_14.c:36; printLine("puts failed!"); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_14.c:36
- 结论: 函数putws的返回值检查错误：putws失败时返回WEOF(-1)，但代码检查返回值是否等于0，导致无法正确检测putws失败。
- D验证: stage_c_preserved / ver_b129aa23
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 692. hyp_path_1d24bb75999b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_15.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制；putws调用可能失败（如输出错误），但漏洞在于开发人员错误检查返回值，属于代码缺陷。
- 触发路径: if (PUTS(L"string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_15.c:37
- 结论: 函数putws的返回值检查错误：putws失败时返回WEOF (-1)，但代码检查返回值是否为0，导致无法正确检测putws失败。这违反了CWE-253（不正确的函数返回值检查）。
- D验证: stage_c_preserved / ver_29e38534
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 693. hyp_path_a2527c87d961

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_18.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: No external input required; the vulnerability is inherent in the logic.
- 触发路径: if (PUTS(L"string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_18.c:36
- 结论: CWE253: Incorrect Check of Function Return Value - The code checks if PUTS(L"string") == 0, but putws() returns 0 on success and WEOF (-1) on failure. Thus, the condition incorrectly treats success as failure, leading to a wrong path.
- D验证: stage_c_preserved / ver_92d5a681
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 694. hyp_path_9c13b6a8f4f0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_16.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法直接控制 putws 的输入（固定字符串），但可能通过影响 stdout 状态（如关闭输出）间接导致 putws 失败，但这种间接控制在实际攻击中难以触发。
- 触发路径: if (PUTS(L"string") == 0) { printLine("puts failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_16.c:36
- 结论: 程序错误地检查 putws 返回值，将失败条件判定为返回值等于0，而实际失败返回值是WEOF(-1)。这违反了API contract（CWE-253），但当前输入固定，错误处理仅打印消息，攻击者难以利用，影响较低。
- D验证: stage_c_preserved / ver_c7502c9a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 695. hyp_path_dc8fcfa83117

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_01.c:34
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (REMOVE(L"removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_01.c:34
- 结论: 对remove函数返回值检查条件错误：将成功返回值0视为失败，导致错误处理逻辑反转。当remove成功时错误地执行失败处理，当remove失败时不执行任何处理。
- D验证: stage_c_preserved / ver_8d16550d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 696. hyp_path_1436e8b880f3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_02.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入，漏洞由硬编码逻辑错误导致。
- 触发路径: if (REMOVE(L"removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_02.c:36
- 结论: 对 _wremove 函数返回值的条件检查颠倒：当函数成功返回0时，代码错误地认为失败并打印错误消息；当函数失败返回非0时，代码不做任何处理，违反 CWE-253 正确检查函数返回值的规范。
- D验证: stage_c_preserved / ver_c426af09
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 697. hyp_path_7ae5011aa91d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_03.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (REMOVE(L"removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_03.c:36
- 结论: REMOVE函数返回0表示成功，但代码中错误地将返回0视为失败并打印'remove failed!'，违反API contract，导致错误的状态报告。
- D验证: stage_c_preserved / ver_b6a255fa
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 698. hyp_path_32ae3d705cf2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_04.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序执行到该代码路径
- 触发路径: if (REMOVE(L"removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_04.c:42
- 结论: 对wchar_t remove函数的返回值检查错误：当remove成功（返回0）时打印了失败消息，而当失败时没有任何处理。违反CWE-253：错误检查函数返回值。
- D验证: stage_c_preserved / ver_f3c15763
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 699. hyp_path_44070e46384d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_05.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，但代码逻辑错误导致对 remove 成功和失败的处理颠倒。
- 触发路径: if (REMOVE(L"removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_05.c:42
- 结论: 对 remove() 函数的返回值检查逻辑颠倒：当 remove() 成功（返回0）时，代码错误地打印 'remove failed!'；当 remove() 失败（返回非0）时，未做任何处理。这违反了 remove() 函数的契约，属于 CWE-253（错误的函数返回值检查）。
- D验证: stage_c_preserved / ver_1e6f6841
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 700. hyp_path_3bc2eb958ca1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_06.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 文件路径L"removemecase0.txt"必须存在且可被删除，但实际影响取决于业务逻辑
- 触发路径: if (REMOVE(L"removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_06.c:41
- 结论: remove()函数的返回值检查条件颠倒：当文件删除成功（返回0）时，错误地打印失败消息；当删除失败（返回非零）时，程序未做处理，违反CWE-253。
- D验证: stage_c_preserved / ver_7634423a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 701. hyp_path_3fbc385afd14

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_07.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (REMOVE(L"removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_07.c:41
- 结论: 对remove函数返回值的检查条件反转：当remove返回0（成功）时，程序打印失败消息，实际上应检查非0值表示失败。这违反了CWE-253（函数返回值的错误检查），可能导致对文件删除操作状态的错误判断。
- D验证: stage_c_preserved / ver_b64392eb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 702. hyp_path_ab6bb622ccf3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_09.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者控制输入，漏洞由代码逻辑错误本身导致。
- 触发路径: if (REMOVE(L"removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_09.c:36
- 结论: 在CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_09.c中，对remove()函数的返回值检查错误：当remove()返回0（成功）时，代码却打印"remove failed!"，导致成功操作被错误报告为失败，违反了正确检查函数返回值的约定。
- D验证: stage_c_preserved / ver_d2450dce
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 703. hyp_path_e613241831b2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_10.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (REMOVE(L"removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_10.c:36
- 结论: 在remove函数返回值检查中，条件判断错误：当remove返回0（成功）时打印失败信息，而当remove返回非零（失败）时未作处理。这违反了CWE-253关于正确检查函数返回值的规范，可能导致逻辑错误或安全漏洞，但当前影响仅限于错误日志输出，后续无关键依赖，因此影响较低。
- D验证: stage_c_preserved / ver_ea15fad6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 704. hyp_path_304d3022119b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_13.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，但逻辑错误可在任意执行路径触发。
- 触发路径: if (REMOVE(L"removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_13.c:36
- 结论: API misuse: 错误检查 remove() 的返回值。remove() 成功返回0，失败返回非0，但代码中当返回值为0时打印失败信息，导致成功时误报失败，失败时无提示。
- D验证: stage_c_preserved / ver_5978f6aa
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 705. hyp_path_89580c1d5ace

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_14.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者输入，仅需程序执行到此代码路径，但参数为固定字符串，外部不可控。
- 触发路径: if (REMOVE(L"removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_14.c:36
- 结论: 对REMOVE函数返回值的检查逻辑反了：REMOVE成功时返回0，但代码将返回值等于0视为失败并打印失败消息，而未处理实际失败的情况。这违反了CWE-253（不正确的函数返回值检查）。
- D验证: stage_c_preserved / ver_69c924a9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 706. hyp_path_825b324301d6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_15.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入要求，函数内部直接调用remove。
- 触发路径: if (REMOVE(L"removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_15.c:37
- 结论: 函数remove的返回值检查错误：当remove返回0（成功）时，错误地打印"remove failed!"；当返回非零（失败）时，未处理错误。违反了CWE-253（函数返回值检查不正确）。
- D验证: stage_c_preserved / ver_f1e4cd8f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 707. hyp_path_46e4476ec89d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_16.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，仅函数返回值错误判断。
- 触发路径: if (REMOVE(L"removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_16.c:36
- 结论: 函数 remove() 的返回值检查错误：当 remove() 成功（返回0）时，代码却打印"remove failed!"，导致成功删除文件被误判为失败。这种 API contract 违反可能使上层逻辑错误地处理文件操作结果，在安全敏感场景中可能导致防御绕过。
- D验证: stage_c_preserved / ver_17ed2ed2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 708. hyp_path_ac3319b41ea9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_18.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部攻击者控制输入，仅为程序内部逻辑错误
- 触发路径: if (REMOVE(L"removemecase0.txt") == 0) { printLine("remove failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_18.c:36
- 结论: 对remove()函数返回值检查错误：当remove成功（返回0）时错误地打印失败信息，而当remove失败（返回非0）时未做任何处理。违反CWE-253定义。
- D验证: stage_c_preserved / ver_57d17ea7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 709. hyp_path_ff6a96f1a8f1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_01.c:39
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可能通过控制文件路径或环境来影响rename()的返回值，但无需直接控制输入。
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_01.c:39
- 结论: 在调用rename()函数时，错误地检查了返回值：成功时返回0，但代码将0视为失败，导致成功时误报失败，失败时可能忽略错误。这是对API返回值的误用，违反了CWE-253。
- D验证: stage_c_preserved / ver_ec40f17d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 710. hyp_path_1e500688524c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_02.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需攻击者输入，代码直接运行即触发
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ L41
- 结论: 对wrename函数的返回值检查错误：当rename成功时返回0，但代码将返回值==0视为失败并打印错误消息；当rename失败时返回非零，代码却没有处理。这违反了API contract，可能导致在rename失败后程序继续执行而忽略错误。
- D验证: stage_c_preserved / ver_6105f0ab
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 711. hyp_path_f59571cdf70f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_03.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: rename()调用成功（例如旧文件存在且可重命名）
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_03.c:41
- 结论: 检查函数返回值错误：rename()成功时返回0，但代码将返回0认为是失败并打印错误信息，违反API contract。
- D验证: stage_c_preserved / ver_ab875091
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 712. hyp_path_268b67adcd2e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_04.c:47
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_04.c:47
- 结论: 函数RENAME的返回值检查错误：成功时返回0，失败时返回非0，但代码将返回0视为失败并打印错误消息，导致成功时错误地报告失败，违反API合同。
- D验证: stage_c_preserved / ver_68c89cb2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 713. hyp_path_1d9043803c8e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_05.c:47
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入，静态代码逻辑错误。
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_05.c:47
- 结论: 对rename()返回值的检查逻辑颠倒：当rename成功返回0时，却打印失败消息，而rename失败时未做任何处理。违反API契约，属于CWE-253（不正确的函数返回值检查）。
- D验证: stage_c_preserved / ver_97ce5ecb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 714. hyp_path_af5581172187

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_06.c:46
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_06.c:46
- 结论: 函数rename()的返回值检查错误：当rename成功返回0时，代码却将其视为失败并打印错误消息，违反了CWE-253正确检查函数返回值的要求。
- D验证: stage_c_preserved / ver_fb7a1b6d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 715. hyp_path_f3bbc7553693

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_07.c:46
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法控制文件名，但函数返回值检查错误本身即为漏洞，不依赖外部输入
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_07.c:46; printLine("rename failed!"); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_07.c:47
- 结论: 函数返回值检查错误：RENAME返回0表示成功，但代码在返回0时打印"rename failed!"，导致成功时被错误地当作失败处理，违反了CWE-253。
- D验证: stage_c_preserved / ver_4f9ca64e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 716. hyp_path_5526b95b09cd

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_09.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无需外部输入，纯逻辑错误
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_09.c:41
- 结论: 函数错误地检查了rename的返回值，将成功（返回0）误判为失败，导致在文件重命名成功时执行错误的失败处理，违反CWE-253。
- D验证: stage_c_preserved / ver_d8b68cf5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 717. hyp_path_e49c7fb1cd4e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_10.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 重命名操作可能因文件系统状态（如目标文件存在且无权限、源文件不存在等）而失败。
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_10.c:41
- 结论: 在rename函数调用中，返回值检查逻辑错误：成功时（返回0）打印失败信息，而失败时（返回非零）不打印，导致错误状态被忽略。这违反了API contract，可能掩盖文件重命名的失败，导致后续逻辑基于错误的假设继续执行。
- D验证: stage_c_preserved / ver_d85a64c8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 718. hyp_path_de062c23f96a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_13.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: rename()函数执行成功时返回0，但条件判断将返回0视为失败，导致错误处理逻辑颠倒
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_13.c:41
- 结论: 在rename()函数返回值为0（成功）的情况下，错误地打印了"rename failed!"，违反了CWE-253（不正确的函数返回值检查）。
- D验证: stage_c_preserved / ver_9ca39f26
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 719. hyp_path_cac8015e242e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_14.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特定前提条件，只要rename()成功执行即可触发错误的错误处理。
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_14.c:41
- 结论: 在rename()返回0（成功）时，代码错误地将其视为失败并打印错误信息，违反了CWE-253。
- D验证: stage_c_preserved / ver_634f5c67
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 720. hyp_path_1e082b9610a3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_15.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: rename函数可能因文件不存在、权限不足等原因失败，返回非0值
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_15.c:42
- 结论: 对rename函数返回值检查错误：if (RENAME(...) == 0) 将成功返回0视为失败，导致成功时打印错误消息；失败时返回非0，程序不进行任何处理，违反CWE-253。
- D验证: stage_c_preserved / ver_c82f6e0b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 721. hyp_path_5037abf92b3b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_18.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_18.c:41
- 结论: 函数rename的返回值检查错误：成功返回0，失败返回非0，但代码中检查返回值等于0时认为失败，导致逻辑颠倒，违反API contract。
- D验证: stage_c_preserved / ver_f5b25c6f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 722. hyp_path_dd50cf8f462e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_16.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_16.c:41
- 结论: 函数rename()的返回值检查错误：当rename返回0（成功）时，代码错误地打印'rename failed!'；而当rename失败时，不进行任何处理。这违反了API contract，属于CWE-253 Incorrect Check of Function Return Value。
- D验证: stage_c_preserved / ver_c72b3e7e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 723. hyp_path_11d9eac2881d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_01.c:33
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致wscanf失败（如关闭stdin、提供无效输入或达到文件结束条件）
- 触发路径: if (wscanf(L"%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_01.c:33
- 结论: 调用wscanf后未正确检查返回值：代码仅检查返回值是否为0，但wscanf失败时返回EOF(-1)。当wscanf失败时，条件不满足，程序误认为读取成功，可能使用未初始化或部分写入的data缓冲区，违反CWE253（函数返回值检查错误）。
- D验证: stage_c_preserved / ver_e8482643
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 724. hyp_path_70486f236c79

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_02.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致wscanf失败，例如通过关闭标准输入、发送无效输入或触发输入流错误。
- 触发路径: if (wscanf(L"%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_02.c:35; 当wscanf返回EOF(-1)时，条件不成立，不执行错误处理，后续代码可能使用未初始化或部分写入的data。 @ 同上
- 结论: 在检查wscanf返回值时，错误地认为返回0表示失败，实际上失败返回EOF(-1)，导致当wscanf失败时未进入错误处理分支，程序可能使用未初始化的data。
- D验证: stage_c_preserved / ver_31a30fea
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 725. hyp_path_7176c18e2ac9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_01.c:52
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入，输入使得wscanf返回0，例如纯空白或空字符串
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_01.c:52
- 结论: 对wscanf返回值的检查不完整：仅检查EOF，未处理返回值为0的情况，违反CWE-253。尽管当前代码路径中dataBuffer后续未使用，但API contract violation存在。
- D验证: stage_c_preserved / ver_cc03ccc1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 726. hyp_path_0081ed3b2b64

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_02.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供任意字符串
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_02.c:63
- 结论: wscanf返回值检查不完整，仅检查EOF，未检查是否成功匹配1项，违反CWE-253规范
- D验证: stage_c_preserved / ver_1302d8f3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 727. hyp_path_06d42690f4a7

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_03.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: wscanf调用失败，返回EOF(-1)而非0
- 触发路径: if (wscanf(L"%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_03.c:35
- 结论: wscanf返回值检查不正确：函数返回EOF(-1)表示失败，但代码仅检查返回值是否等于0，导致当wscanf失败时错误未被正确处理。尽管失败分支仅输出消息而未使用未初始化变量，但函数返回值检查本身违反CWE-253。
- D验证: stage_c_preserved / ver_6fcc5b50
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 728. hyp_path_062964243806

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_02.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供空字符串，使wscanf返回0
- 触发路径: wchar_t * data = dataBuffer; @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_02.c:80; if (wscanf(L"%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_02.c:82; printLine("wscanf failed!"); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_02.c:84
- 结论: 函数wscanf的返回值检查不完整（仅检查EOF，未检查返回0），违反API contract（CWE-253），但当前代码路径中后续未使用data变量，未形成未初始化数据访问的完整漏洞路径，安全影响较低，需要动态验证确认是否存在其他使用路径。
- D验证: stage_c_preserved / ver_f6859cd7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 729. hyp_path_f907c4e5af15

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_03.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向stdin提供仅空白字符或与格式不匹配的输入，使wscanf返回0。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) @ 63; if (wscanf(L"%99s\0", data) == EOF) @ 66
- 结论: wscanf的返回值检查不完整，仅检查EOF而忽略返回0的情况，违反CWE-253的API contract。攻击者可提供导致wscanf返回0的输入（如仅空白字符），虽不直接导致安全后果，但可能导致后续使用未初始化的dataBuffer，需动态验证确认影响。
- D验证: stage_c_preserved / ver_464fd89a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 730. hyp_path_f18786e3cb4f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_04.c:41
- 漏洞类型: CWE-253, CWE-754
- CWE: CWE-253; CWE-754
- 风险等级: P1
- 触发条件: 攻击者能够控制输入导致 wscanf 失败（例如发送 EOF 信号或输入格式错误）
- 触发路径: if (wscanf(L"%99s\0", data) == 0) { @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_04.c:41; printLine("wscanf failed!"); @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_04.c:42
- 结论: wscanf 的返回值检查不正确：仅检查返回值为 0 的情况，但 wscanf 失败时返回 EOF(-1)，导致错误状态被忽略，可能使用未初始化的数据或导致其他未定义行为。
- D验证: stage_c_preserved / ver_b5e49022
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 731. hyp_path_4582df418c05

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_03.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向标准输入提供导致wscanf返回0的输入（例如仅空格或空行）
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_03.c:82
- 结论: 在wscanf调用中，仅检查了返回值为EOF的情况，未检查成功时返回值是否等于预期输入项数（应为1）。若wscanf返回0（例如输入仅空白符或空输入），dataBuffer可能未更新且保持未初始化，违反CWE-253。虽当前代码片段未显示后续使用data，但典型Juliet用例中通常存在后续使用，漏洞假设仍合理。
- D验证: stage_c_preserved / ver_b5f51ef0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 732. hyp_path_d7aa91f1492c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_04.c:69
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供导致wscanf返回0的输入（例如空输入或格式不匹配）
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_04.c:69
- 结论: 函数wscanf的返回值检查不完整：仅检查是否等于EOF，未检查是否成功读取了预期的1个项。当wscanf返回0（未匹配任何输入）时，代码无法检测到错误，可能导致后续使用未初始化的缓冲区数据。
- D验证: stage_c_preserved / ver_f8b66fbc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 733. hyp_path_371628367ace

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_05.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使wscanf返回EOF（如提前关闭stdin或提供无效输入）; data在wscanf调用前未初始化
- 触发路径: if (wscanf(L"%99s\0", data) == 0) { printLine("wscanf failed!"); } @ 39-41
- 结论: 代码中wscanf返回值检查不完整：仅检查返回0的情况，未处理返回EOF(-1)的失败场景。当wscanf返回EOF时，条件不满足，跳过错误处理，data可能保持未初始化。但后续使用data的代码未提供，无法确认未初始化数据被用于敏感操作，影响取决于后续上下文。
- D验证: stage_c_preserved / ver_d4cf9c28
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 734. hyp_path_e1b3deb6d721

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_04.c:88
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供输入使得wscanf返回值非EOF但为0（例如输入空串或格式不匹配），导致data未正确填充。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_04.c:88
- 结论: wscanf函数的返回值检查不完整：仅检查了EOF错误，未处理返回值为0（表示未匹配任何项）的情况，且dataBuffer未显式初始化，若wscanf返回0则data保持未定义值，违反CWE-253。
- D验证: stage_c_preserved / ver_943f52d6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 735. hyp_path_b7a9af2f280a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_06.c:40
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致wscanf函数失败，例如关闭标准输入流或提供无效输入导致读取错误。
- 触发路径: if (wscanf(L"%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_06.c:40
- 结论: wscanf返回值检查错误：函数失败时返回EOF(-1)，但代码检查返回值是否等于0，导致当wscanf失败时条件不成立，误认为成功，进而可能使用未初始化的数据。
- D验证: stage_c_preserved / ver_13d0b3a4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 736. hyp_path_8dab95b6a64b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_05.c:99
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供导致wscanf返回0（匹配失败）而非EOF的输入，从而绕过错误检查。
- 触发路径: void CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_05_case1() { case11(); case12(); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_05.c:96; if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_05.c:67-69 或 87-89
- 结论: 在case11和case12中，wscanf的返回值仅检查是否为EOF，忽略了返回0的情况，违反了CWE-253正确检查函数返回值的要求。但由于读取的data变量在后续未使用，实际影响较低，未形成完整的source-sink路径。
- D验证: stage_c_preserved / ver_49f27c91
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 737. hyp_path_278440f505cb

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_05.c:88
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供输入（如空行或仅空白字符）使得wscanf匹配失败但未触发EOF（返回0）。
- 触发路径: wchar_t * data = dataBuffer; @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_05.c:86; if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_05.c:88
- 结论: 函数wscanf的返回值检查不完整：代码仅检查返回值是否等于EOF，忽略了wscanf可能返回0（未匹配任何项）的情况。当wscanf返回0时，dataBuffer未被写入有效数据，违反CWE-253（函数返回值错误检查）的API契约。格式字符串中多余的空字符'\0'不影响核心漏洞，后续无实际使用降低了可利用性但未消除漏洞。
- D验证: stage_c_preserved / ver_135930f8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 738. hyp_path_c69cb13a160c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_06.c:68
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入控制wscanf的输入内容，例如提供空字符串或无效字符导致wscanf返回0。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_06.c:68
- 结论: 在wscanf函数调用后，仅检查返回值是否为EOF，但未检查返回值是否等于成功匹配的项数（应为1）。当wscanf返回0（如输入空字符串或格式不匹配）时，程序认为读取成功，实际data指向的缓冲区内容可能未初始化或保持未定义状态，可能导致未初始化内存使用。
- D验证: stage_c_preserved / ver_30f000fd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 739. hyp_path_1548085f6bcd

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_06.c:87
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_06.c:87
- 结论: wscanf返回值检查不完整，仅检查EOF，未检查返回0的情况（匹配失败但未到EOF），导致使用未初始化的dataBuffer。
- D验证: stage_c_preserved / ver_90859841
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 740. hyp_path_0be23b400163

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_07.c:40
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致wscanf失败，例如提供无效输入或触发读取错误
- 触发路径: if (wscanf(L"%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_07.c:40
- 结论: CWE-253: 不正确的函数返回值检查。代码中调用wscanf后，仅检查返回值是否等于0，但wscanf在失败时返回EOF（-1），因此当wscanf失败返回-1时，条件不成立，不会执行失败处理，导致错误返回值被忽略，攻击者可通过导致wscanf失败来触发未处理错误。
- D验证: stage_c_preserved / ver_14fedc87
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 741. hyp_path_1cd38d353a10

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_09.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可能通过控制输入导致wscanf失败（如通过关闭stdin或发送非法输入）
- 触发路径: if (wscanf(L"%99s", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_09.c:35
- 结论: wscanf函数的返回值检查不正确：仅检查返回值是否为0，而忽略了失败时返回EOF（-1）的情况，导致错误处理缺失。
- D验证: stage_c_preserved / ver_41553848
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 742. hyp_path_e2032333be61

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_07.c:87
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供非预期的输入，使得wscanf返回0。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_07.c:87
- 结论: wscanf返回值检查不完整，仅检查EOF，未检查返回0的情况。虽然后续未使用data，但违反CWE-253，可能在某些扩展场景下导致未初始化数据残留。
- D验证: stage_c_preserved / ver_789061b3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 743. hyp_path_c9f9bee7e7af

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_07.c:97
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供数据，且数据可能不匹配格式（例如输入空白或无效字符），导致wscanf返回0而非EOF。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_07.c:84-87
- 结论: 存在CWE253漏洞：wscanf的返回值仅检查了EOF，未处理返回0（无匹配项）的情况，导致输入验证不完整。
- D验证: stage_c_preserved / ver_934b70f5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 744. hyp_path_f9d5d44c7db8

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_09.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: User input via stdin can be provided to wscanf
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_09.c:82
- 结论: VULNERABILITY_FOUND: Incorrect check of wscanf return value - only checks for EOF, but does not verify that the expected number of items was read (e.g., return value != 1).
- D验证: stage_c_preserved / ver_4a6fa401
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 745. hyp_path_1db48a0abe9b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_09.c:93
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供标准输入，使 wscanf 返回 0 而非 EOF
- 触发路径: case12(); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_09.c:93; if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_09.c:80
- 结论: 在 case12 中，wscanf 的返回值仅检查是否等于 EOF，忽略了返回 0（表示输入匹配失败）的情况，导致部分失败不被检测，违反 CWE-253 正确的返回值检查约定。
- D验证: stage_c_preserved / ver_addb23d8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 746. hyp_path_c90deeae27ce

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_10.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够导致wscanf调用失败，例如输入EOF或触发错误状态。
- 触发路径: if (wscanf(L"%99s\0", data) == 0) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_10.c:35
- 结论: wscanf返回值检查错误：代码仅检查返回值是否为0，但wscanf失败时返回EOF(-1)，导致失败情况未被识别，程序在wscanf失败后可能使用未初始化的data变量。
- D验证: stage_c_preserved / ver_80b98ed0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 747. hyp_path_d2570371aa4d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_10.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向wscanf提供不匹配格式的输入，导致返回0而非EOF
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_10.c:82
- 结论: 对wscanf返回值的检查不完整：只检查了EOF，未检查返回0的情况，导致当输入不匹配时缓冲区未被赋值，虽当前代码片段未展示后续使用，但违反CWE-253安全编码规范，存在潜在未初始化数据风险。
- D验证: stage_c_preserved / ver_c818fe53
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 748. hyp_path_bc46d65d4922

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_13.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: wscanf函数执行失败（例如输入EOF、格式匹配失败或输入错误）
- 触发路径: if (wscanf(L"%99s", data) == 0) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_13.c:35
- 结论: 代码对wscanf返回值的检查不正确：wscanf失败时返回EOF(-1)，但代码检查是否等于0，导致失败被误认为成功，属于CWE-253（函数返回值检查错误）。
- D验证: stage_c_preserved / ver_219f3860
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 749. hyp_path_cae60f66fa43

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_14.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够触发wscanf失败（例如输入结束符EOF），但代码未正确检测。
- 触发路径: if (wscanf(L"%99s\0", data) == 0) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_14.c:35
- 结论: 对wscanf的返回值检查错误：仅当返回值为0时认为失败，但wscanf失败时返回EOF(-1)而不是0，导致未检测到wscanf失败，可能使用未初始化的data。
- D验证: stage_c_preserved / ver_1c4ae3d0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 750. hyp_path_495a78773e1f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_14.c:93
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可通过标准输入提供数据，使wscanf返回0（匹配失败）而非EOF
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_14.c:87
- 结论: 存在CWE-253违规：对wscanf的返回值检查不完整，仅检查了EOF，忽略了返回0（匹配失败）的情况
- D验证: stage_c_preserved / ver_e4f5ced9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 751. hyp_path_3c1fd5813cc1

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_15.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使wscanf调用失败（例如通过关闭标准输入或发送EOF信号）。
- 触发路径: if (wscanf(L"%99s\0", data) == 0) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_15.c:36
- 结论: 对wscanf的返回值检查不正确：代码检查返回值是否等于0，但wscanf失败时返回EOF（-1），而非0，导致失败情况未被捕获。
- D验证: stage_c_preserved / ver_0fa7b950
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 752. hyp_path_7ebaf80f03df

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_13.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向wscanf提供输入，导致其返回0（例如，输入流为空且非EOF）
- 触发路径: wchar_t * data = dataBuffer; @ L80; if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ L82
- 结论: 对wscanf的返回值检查不完整：只检查了EOF（文件结束或错误），而未检查返回0（表示无匹配）的情况。虽然当前代码片段在wscanf返回0时只跳过if块，未继续使用data，但该API使用模式违反了CWE-253中关于完整检查函数返回值的要求，存在潜在的未初始化数据使用风险，但实际利用路径未闭合，安全影响较低。
- D验证: stage_c_preserved / ver_e57abf2b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 753. hyp_path_1c7ab4c4aae3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_14.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供特殊构造的输入，使wscanf匹配失败但返回0（例如空行或非字符串输入）。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_14.c:82
- 结论: 函数wscanf的返回值检查不完整：仅检查了EOF，但未检查返回0（表示匹配失败）的情况，导致在输入无效时data内容未更新，可能使用未初始化的缓冲区数据。
- D验证: stage_c_preserved / ver_2e0bfcbc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 754. hyp_path_d41cc9df1e92

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_15.c:69
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供数据，导致wscanf返回非预期值（如0）
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_15.c:69
- 结论: wscanf返回值检查不完整，只检查了EOF，但未检查是否成功读取了wchar_t字符串。正确的检查应验证返回值是否等于1（成功匹配一个输入项），仅检查EOF会遗漏wscanf返回0（未匹配任何项）的错误情况。
- D验证: stage_c_preserved / ver_3d8b57fe
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 755. hyp_path_0ea8cc52d895

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_15.c:106
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向标准输入提供数据，使得 wscanf 返回 0（即输入格式不匹配）。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_15.c:88 或 68
- 结论: 函数 wscanf 的返回值仅检查是否为 EOF，而未检查是否等于期望的匹配项数（1），导致当输入不匹配格式时（返回0），程序不会检测到错误，可能继续使用未修改的数据。尽管 data 变量后续未被使用，降低了可利用性，但返回值检查不完整违反了 CWE-253 的契约。
- D验证: stage_c_preserved / ver_0741665b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 756. hyp_path_6853e2b76320

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_16.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够在wscanf输入时导致错误（如关闭标准输入或发送特殊信号）
- 触发路径: if (wscanf(L"%99s\0", data) == 0) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_16.c:35
- 结论: 函数wscanf的返回值检查不正确：代码检查返回值是否为0来判断失败，但wscanf失败时返回EOF(-1)，导致失败时未正确处理，可能导致使用未初始化的data。
- D验证: stage_c_preserved / ver_92dead7f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 757. hyp_path_b8b3805b7b03

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_16.c:59
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入流，使得wscanf返回0而不是EOF（例如输入空行或非匹配的字符）。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_16.c:59
- 结论: 对wscanf的返回值检查不完整：仅检查是否等于EOF，但忽略了返回0表示匹配失败的情况，导致输入失败时dataBuffer内容未更新，可能使用未初始化或部分覆盖的数据。
- D验证: stage_c_preserved / ver_8ab9fbbb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 758. hyp_path_d21377cdc74a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_01.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: The output buffer size is limited such that swprintf() can fail, and SRC_STRING length can be controlled or large enough to cause failure.
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_01.c:41
- 结论: The code incorrectly checks the return value of swprintf() by comparing it to 0, whereas the function returns a negative value on failure. This violates the API contract and constitutes a CWE-253 (Incorrect Check of Function Return Value) vulnerability.
- D验证: stage_c_preserved / ver_966dd45d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 759. hyp_path_aa663c0bca84

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_15.c:90
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向标准输入提供任意数据，理论上可能导致wscanf返回非EOF的错误值（如0），但实际对于%99s格式极难触发。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_15.c:90
- 结论: wscanf返回值检查不完整：仅检查EOF，未处理返回值为0或其他非正数的情况。虽然实际触发概率较低（%99s格式返回0情况罕见），但违反了CWE-253要求对所有可能的错误返回值进行检查。后续未发现对dataBuffer的使用，因此安全影响未证实，但返回值检查不完整本身构成代码缺陷。
- D验证: stage_c_preserved / ver_8d902c00
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 760. hyp_path_c8c39b9c681d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_01.c:60
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的长度，使其接近缓冲区大小，导致snprintf截断。
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) < 0) @ L60; if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) < 0) @ L62
- 结论: VULNERABILITY_FOUND: snprintf返回值检查不完整，未检测到缓冲区截断。
- D验证: stage_c_preserved / ver_8e27e0af
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 761. hyp_path_affb3aadaad0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_02.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特定攻击者控制输入，但swprintf可能因缓冲区大小或格式问题失败
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_02.c:43
- 结论: 对swprintf函数返回值的检查不正确。注释说明swprintf失败时返回负值，但代码仅检查返回值等于0，导致未处理失败情况。如果swprintf失败，错误不会被检测到，可能影响后续逻辑。
- D验证: stage_c_preserved / ver_cbf2c227
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 762. hyp_path_16322e621273

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_18.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过输入导致wscanf返回-1（例如EOF或无效输入）。
- 触发路径: if (wscanf(L"%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_18.c:35
- 结论: wscanf返回值检查错误。代码仅检查返回值是否等于0，但wscanf失败时返回EOF(-1)，导致无法正确检测失败。若wscanf返回-1，程序不会进入失败分支，可能继续使用未初始化的data变量，造成未定义行为。
- D验证: stage_c_preserved / ver_64492006
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 763. hyp_path_a3c4f900416b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_03.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制 SRC_STRING 或 data 的内容，使得 swprintf 执行失败（例如输出长度超过缓冲区限制）。
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_03.c:43
- 结论: 代码对 swprintf 返回值的检查不正确：当 swprintf 失败返回负值时，条件 (return == 0) 不成立，错误未被捕获，违反 CWE-253。
- D验证: stage_c_preserved / ver_84b21267
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 764. hyp_path_2f21e6fea43d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_04.c:49
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制 SRC_STRING 内容及长度，使得输出长度超出 data 剩余缓冲区（100-wcslen(SRC_STRING)-1），导致 swprintf 失败返回负数
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_04.c:49
- 结论: 函数 SNPRINTF (实际为 swprintf 的宏) 的返回值检查错误：代码仅检查返回值是否等于0，但 swprintf 失败时返回负数，成功时返回非负整数。这导致当 swprintf 失败（如缓冲区太小）时，程序错误地认为操作成功，可能基于未完整写入的缓冲区数据继续执行，违反 CWE-253 定义。
- D验证: stage_c_preserved / ver_5fcf8af0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 765. hyp_path_88dae3971d0f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_03.c:90
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: No external input; the incomplete check is a contract violation regardless of data source.
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_03.c:90
- 结论: Incorrect check of snprintf return value: only checks for negative values, does not verify that the output was truncated or that the function succeeded fully, violating CWE-253.
- D验证: stage_c_preserved / ver_d448c23a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 766. hyp_path_db4a1aee6ad2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_05.c:49
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: swprintf可能因输出缓冲区满或格式错误失败，返回负数
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_05.c:49
- 结论: CWE253: 不正确的函数返回值检查。对swprintf的返回值检查为==0，但swprintf失败时返回负数，导致失败情况被误判为成功，静默忽略失败。
- D验证: stage_c_preserved / ver_20569041
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 767. hyp_path_4383fe329661

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_04.c:77
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: SRC_STRING为固定常量，非外部可控；若未来修改为可变输入则攻击者可控制其长度导致截断。
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) < 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_04.c:77
- 结论: SNPRINTF返回值检查不完整，仅检查<0，未检测缓冲区截断，违反API contract。当前SRC_STRING为固定常量，无实际可利用性，但若未来输入可变则存在风险。
- D验证: stage_c_preserved / ver_2625a74a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 768. hyp_path_6317a3475465

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_06.c:48
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: SRC_STRING为常量，非外部可控；swprintf可能因缓冲区不足或内部错误失败，但不受攻击者直接控制。
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_06.c:48
- 结论: 代码中错误地检查了swprintf()的返回值，将返回值是否为0作为失败标志，而实际上swprintf失败时返回负数，成功时返回非负整数。这导致当swprintf实际失败返回负数时，错误条件不被触发，错误未被处理。尽管SRC_STRING为常量，失败概率较低，但代码仍违反API合同（CWE-253），存在潜在未定义行为风险。
- D验证: stage_c_preserved / ver_146bfb93
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 769. hyp_path_09ad8ad54884

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_05.c:107
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法控制SRC_STRING的内容或长度（编译时常量），因此截断条件无法由外部触发；需要SRC_STRING长度使得snprintf返回值大于等于缓冲区大小，但当前常量不满足此条件。
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_05.c:96-98（case12）或类似行（case11）
- 结论: 对snprintf的返回值检查不完整，只检查了<0的错误情况，未检查返回值大于等于缓冲区大小的截断情况，构成CWE-253违规。但由于SRC_STRING为编译时常量，攻击者无法控制其长度，外部攻击路径不可达，漏洞的实际可利用性极低。
- D验证: stage_c_preserved / ver_9dee8e0f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 770. hyp_path_c430128d85ed

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_07.c:48
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: No specific precondition; the code always executes this check.
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_07.c:48
- 结论: CWE-253: Incorrect check of function return value for swprintf. The code compares the return value to 0, but swprintf returns a negative value on failure, so the error check is ineffective.
- D验证: stage_c_preserved / ver_5b91e7ca
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 771. hyp_path_bb30a4bd8f89

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_09.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: swprintf函数被调用时可能失败（例如输出缓冲区太小或格式错误）。
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_09.c:43
- 结论: 代码错误地检查swprintf函数的返回值：当swprintf失败时返回负值，但代码检查返回值是否等于0来判断失败，导致无法正确检测失败。这违反了CWE-253（函数返回值检查不正确）。
- D验证: stage_c_preserved / ver_c2cd3d93
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 772. hyp_path_260f0281275b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_10.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响SNPRINTF的输入参数（例如SRC_STRING的内容或长度），导致调用失败，但错误检查无法识别。
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_10.c:43
- 结论: 对swprintf返回值的检查不正确：代码检查返回值是否等于0，但swprintf失败时返回负值，而0表示成功但未写入字符。这种错误检查导致无法检测到失败情况，可能引发未定义行为或数据损坏。
- D验证: stage_c_preserved / ver_02d2d47a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 773. hyp_path_d1df8c420aef

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_09.c:90
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入字符串SRC_STRING的长度，使其超过目标缓冲区剩余容量。
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_09.c:90
- 结论: snprintf的返回值检查不完整：代码仅检查返回值是否小于0，未检查是否因缓冲区过小导致输出被截断（snprintf返回应写入字符数可能大于等于缓冲区大小）。这违反了正确的错误处理约定，可能导致后续使用不完整或损坏的数据。
- D验证: stage_c_preserved / ver_e3cbeaa5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 774. hyp_path_5e37f193f2e9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_10.c:101
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的长度（代码中SRC_STRING定义为常量，实际不可控，但缺陷模式仍存在）
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_10.c:88-89; printLine("snprintf failed!"); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_10.c:90
- 结论: SNPRINTF返回值检查不正确：仅检查 < 0，未检查返回值是否 >= 缓冲区大小，导致截断未被检测。
- D验证: stage_c_preserved / ver_0de96535
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 775. hyp_path_5b035f1bc596

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_14.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: swprintf 调用失败（例如缓冲区大小不足或格式错误），返回负值。
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_14.c:43
- 结论: 对 swprintf(snprintf) 的返回值检查错误：成功时返回写入字符数（非负），失败时返回负值。代码仅检查返回值是否为0，导致失败时无法正确识别，违反了 CWE-253（函数返回值检查不正确）。
- D验证: stage_c_preserved / ver_eaa0ad2a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 776. hyp_path_0214b1963f96

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_13.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特定攻击者输入，但swprintf可能因内部条件（如目标缓冲区大小计算错误导致负数或无符号溢出）失败。
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_13.c:43
- 结论: 在CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_13.c中，对swprintf函数的返回值检查不正确。函数失败时返回负数，但代码仅检查返回值是否等于0，导致失败状态被忽略，可能引发后续未定义行为或逻辑错误。
- D验证: stage_c_preserved / ver_9753560a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 777. hyp_path_80bb0d0ab5e0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_13.c:90
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: Attacker can control SRC_STRING length to cause truncation without triggering the error check.
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) < 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_13.c:90
- 结论: Incorrect check of snprintf return value: only checks for negative error but not for truncation (return value >= buffer size).
- D验证: stage_c_preserved / ver_95960b08
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 778. hyp_path_c7c3f899e26a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_15.c:44
- 漏洞类型: buffer_overflow
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可能通过控制输入导致swprintf失败（例如提供过长的字符串使缓冲区溢出），但实际利用依赖后续代码对data的使用。
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_15.c:44
- 结论: 存在对swprintf函数返回值的错误检查：代码检查返回值是否等于0，但swprintf失败时返回负数，成功写入0个字符时返回0。这导致失败情况被忽略，而成功写入0个字符被误报为失败。违反CWE-253要求正确检查函数返回值。
- D验证: stage_c_preserved / ver_fa612574
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 779. hyp_path_0c71ac846060

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_18.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的内容或长度，使得swprintf调用失败（例如缓冲区不足或格式化错误）。
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) == 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_18.c:43
- 结论: 对swprintf的返回值检查不正确：当swprintf失败时返回负数，但代码仅检查返回值是否等于0，导致失败时未正确处理。
- D验证: stage_c_preserved / ver_1bb7cf11
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 780. hyp_path_b0bc03340a19

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_16.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可能通过影响程序状态（如耗尽内存）使swprintf失败，但实际攻击者控制能力有限；漏洞的存在不依赖于攻击者输入。
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_16.c:43
- 结论: 错误的返回值检查：代码中检查SNPRINTF（swprintf）的返回值是否等于0来判断失败，但实际swprintf失败时返回负数，返回0表示成功写入了0个字符，因此无法正确检测失败情况，违反了API contract，属于CWE-253错误检查函数返回值。
- D验证: stage_c_preserved / ver_9c4ebe99
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 781. hyp_path_089effbd26fa

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_01.c:54
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: Attacker can influence SRC_STRING (e.g., via environment or input)
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_01.c:54
- 结论: Incorrect check of swscanf return value: only checking for EOF but not for other failure modes or mismatched items
- D验证: stage_c_preserved / ver_71951e50
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 782. hyp_path_64962a1846da

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_02.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无攻击者控制输入；仅当swscanf失败时触发，但当前环境不可达
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_02.c:37
- 结论: 对swscanf返回值的错误检查：代码只检查返回值是否等于0，而未检查返回值是否为EOF（-1），违反了正确检查惯例。虽然由于SRC_STRING是常量，实际运行时swscanf不会失败，导致不可达路径，但代码逻辑本身存在CWE-253违规。
- D验证: stage_c_preserved / ver_3c6b7620
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 783. hyp_path_e62e71ec60c9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_02.c:65
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的内容，使其产生swscanf返回0（例如空字符串）的情况。但在当前Juliet测试用例中SRC_STRING为静态常量，不可控。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ L65
- 结论: 函数swscanf的返回值检查不完全：仅检查了EOF，但忽略了返回值为0的情况（即无匹配输入）。根据CWE253，应检查返回值是否等于预期的成功匹配项数（1），否则当输入为空字符串时，错误不会被检测到。
- D验证: stage_c_preserved / ver_816318d6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 784. hyp_path_75bdc4573b29

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_03.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的值，使其导致swscanf解析失败（例如返回EOF）
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == 0) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_03.c:37
- 结论: 对swscanf返回值检查不完整，但当前场景下SRC_STRING为编译时常量，无法触发失败条件；若SRC_STRING来自外部输入，则存在可被利用的漏洞。
- D验证: stage_c_preserved / ver_8a50f35b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 785. hyp_path_fcfb7acd7689

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_02.c:84
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING内容，使其无法匹配格式（例如空字符串），导致swscanf返回0而非EOF；且dataBuffer可能未初始化或包含敏感数据，后续使用未检查的数据。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_02.c:84
- 结论: 对swscanf函数返回值检查不完整：仅检查是否返回EOF，未处理返回0（表示未匹配任何项）或其他非EOF失败情况，违反CWE-253。但当前测试用例中SRC_STRING为固定常量，且无后续使用dataBuffer的证据，因此可利用性较低，需要动态验证或审计确认实际环境中输入是否可控及dataBuffer后续使用路径。
- D验证: stage_c_preserved / ver_634cf0f2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 786. hyp_path_3b8998dd3996

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_04.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无特殊前提条件，只需swscanf执行即可。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_04.c:43
- 结论: 函数swscanf的返回值检查错误：只检查返回值是否等于0，但失败时返回EOF(-1)，导致失败无法被正确检测。违反API contract，属于CWE-253。
- D验证: stage_c_preserved / ver_1eb0acb0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 787. hyp_path_723d025cd40e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_04.c:100
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 程序执行到 case11 或 case12，且 swscanf 输入字符串 SRC_STRING 内容导致匹配项数为 0。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_04.c:66-71 (case11) 或 90-95 (case12)
- 结论: 在 case11 和 case12 中，swscanf 的返回值被检查是否等于 EOF，但标准要求检查返回值是否等于预期匹配项数（此处为 1）。如果 swscanf 返回 0（表示未成功匹配任何项），则不会触发失败处理，导致逻辑上遗漏对输入格式错误的处理。尽管 data 缓冲区已初始化为空字符串，后续没有危险操作，但函数返回值检查违反 CWE-253 定义。
- D验证: stage_c_preserved / ver_a3fd5940
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 788. hyp_path_644a7b919d37

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_03.c:65
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的内容，使其无法匹配格式%99s，导致swscanf返回0。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_03.c:65
- 结论: 函数swscanf的返回值被错误检查：只检查了EOF，但未检查返回0的情况。若swscanf返回0，dataBuffer内容保持不变（可能未初始化），且后续代码可能使用该未初始化数据导致未定义行为。但缺少data后续使用的代码片段，证据不闭合。
- D验证: stage_c_preserved / ver_99fa917d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 789. hyp_path_6bb8d1dd4b37

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_04.c:71
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的内容，使其输入为空或仅空白字符，导致swscanf返回0
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_04.c:71
- 结论: swscanf返回值检查不完整：仅检查返回EOF，忽略了返回0（无匹配项）的情况，违反CWE-253。但后续代码未使用data，未形成未初始化变量使用漏洞，需动态验证可利用性。
- D验证: stage_c_preserved / ver_5b5d61e2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 790. hyp_path_30a8099ea1c0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_04.c:90
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 假设攻击者能够控制 SRC_STRING，但实际 SRC_STRING 为常量，不可控。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_04.c:90
- 结论: 函数 swscanf 的返回值检查不充分：仅检查是否等于 EOF，而未检查是否等于期望的匹配项数（1）。但 SRC_STRING 在测试用例中为字符串常量，攻击者无法控制输入，导致 swscanf 始终返回 1，不会触发未初始化数据使用路径。
- D验证: stage_c_preserved / ver_315d8eee
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 791. hyp_path_6471a14069cf

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_05.c:43
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: SRC_STRING为固定字符串，swscanf必然返回1
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_05.c:43
- 结论: 存在CWE-253不正确的函数返回值检查，但受限于SRC_STRING为固定常量，swscanf总是成功，错误处理路径不可达，无安全后果。
- D验证: stage_c_preserved / ver_d3f3644c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 792. hyp_path_d9e5454758a6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_06.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供导致swscanf失败的输入（如格式不匹配或空输入）
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == 0) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_06.c:42
- 结论: 对swscanf的返回值检查不正确。swscanf成功时返回1，失败时返回EOF(-1)，但代码中检查返回值是否等于0，导致当swscanf失败时条件不成立，错误未被捕获。
- D验证: stage_c_preserved / ver_c669adb8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 793. hyp_path_7a3a4900bc4c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_05.c:100
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者理论上能够影响SRC_STRING的内容，但在此测试用例中SRC_STRING为固定常量，实际不可控
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_05.c:100
- 结论: 不完整的返回值检查：swscanf的返回值仅检查了EOF，忽略了返回0的可能性，违反CWE-253的正确检查规范。虽然SRC_STRING为固定常量导致实际可利用性低，但静态分析仍应标记此违规。
- D验证: stage_c_preserved / ver_bf48d64b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 794. hyp_path_e83026ea50a4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_06.c:70
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供输入使得 swscanf 返回 0（例如输入格式不匹配）或返回其他非 EOF 错误值。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_06.c:70
- 结论: 函数 swscanf 的返回值检查不完整：代码仅检查返回值是否等于 EOF，但未处理返回值为 0（匹配失败）或其他错误的情况。虽然此路径未使用 data 进行后续操作，但违反了 CWE-253 关于正确检查函数返回值的要求，可能在其他上下文中导致逻辑错误或未初始化数据使用。
- D验证: stage_c_preserved / ver_aafa7f67
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 795. hyp_path_90d17028dbce

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_07.c:42
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可能通过控制输入导致swscanf失败（例如提供空字符串或非法格式）
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_07.c:42
- 结论: 函数swscanf()可能返回EOF(-1)表示失败，但代码仅检查返回值是否等于0，未检查EOF或其他错误返回。当swscanf实际失败时，返回值是EOF(-1)，不等于0，因此不会进入if块，导致错误地认为操作成功，可能使用未初始化的data或造成逻辑错误。
- D验证: stage_c_preserved / ver_2fd98911
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 796. hyp_path_157753e96324

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_06.c:89
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING为空字符串或仅空白字符，导致swscanf返回0。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_06.c:89
- 结论: swscanf的返回值检查仅针对EOF，未检查返回0的情况，违反CWE-253。但后续代码未使用data变量，因此实际影响较低，仅存在API misuse而无直接数据泄露或未初始化使用风险。
- D验证: stage_c_preserved / ver_0a7e8349
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 797. hyp_path_6e6d3ad2a412

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_06.c:99
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的内容，使其导致swscanf返回0而非EOF（例如输入空字符串或格式不匹配）。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_06.c:69-71 (case11) 或 :90-92 (case12)
- 结论: 对swscanf的返回值检查不完整，仅检查是否等于EOF，忽略了返回0的情况（表示匹配失败），导致当源字符串为空或格式不匹配时，错误处理未触发。尽管本例中数据已初始化为空字符串且后续未使用，但违反了CWE-253的规范。
- D验证: stage_c_preserved / ver_66f37023
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 798. hyp_path_45d5e5f9dfca

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_09.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入导致swscanf失败（例如提供非预期格式的输入），使返回值为EOF(-1)，此时条件判断为假，错误处理被跳过，后续使用未初始化的data变量。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_09.c:37
- 结论: CWE-253: 错误检查函数返回值：swscanf()的返回值检查条件错误。当swscanf失败返回EOF(-1)时，条件(swscanf(...)==0)为假，导致错误处理代码未执行，可能使用未初始化的data变量。
- D验证: stage_c_preserved / ver_1c3f2442
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 799. hyp_path_a2b6aa92ae02

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_07.c:89
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制swscanf的输入参数（SRC_STRING），但在本测试用例中为常量，不可控
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_07.c:89
- 结论: 代码中swscanf函数返回值检查不完整：仅检查是否等于EOF，而忽略返回0的情况，违反CWE-253。但在当前测试用例中SRC_STRING为常量，攻击者无法控制输入，漏洞不可利用。
- D验证: stage_c_preserved / ver_6654ec94
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 800. hyp_path_2dc6b22cfb04

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_09.c:95
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 输入SRC_STRING为常量，实际匹配失败不会发生，但编码模式存在缺陷，若上下文输入可变则可能被利用
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_09.c:85 (case12) 或 :67 (case11)
- 结论: CWE253漏洞：swscanf函数返回值检查不完整。代码仅检查返回值等于EOF（输入错误），而未检查返回值等于0（匹配失败）。当swscanf匹配失败时返回0，程序不会进入错误处理，可能基于未读取的数据继续执行，导致逻辑错误。
- D验证: stage_c_preserved / ver_cb0f57fc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 801. hyp_path_ce09601284a4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_10.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == 0) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_10.c:37
- 结论: swscanf返回值检查不完整：仅判断返回值是否等于0，忽略了返回EOF(-1)表示失败的情况，违反CWE-253正确检查函数返回值的规范。
- D验证: stage_c_preserved / ver_94aaed55
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 802. hyp_path_a2ef0e067e6e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_09.c:84
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制 SRC_STRING 输入，使其无法被格式 "%99s" 匹配（例如空字符串或无效字符），导致 swscanf 返回 0 而非 EOF。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_09.c:84; printLine("swscanf failed!"); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_09.c:85
- 结论: 调用的 swscanf 函数返回值检查不完整：只检查了返回值是否为 EOF，但忽略了返回值为 0（表示未成功匹配任何输入）的情况。这违反了 CWE-253 关于正确检查函数返回值的要求。虽然当前代码片段未显示后续使用未初始化数据，但错误检查本身构成漏洞。
- D验证: stage_c_preserved / ver_9fb3b6e6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 803. hyp_path_2f2e3d900fda

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_10.c:84
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入字符串SRC_STRING，使其不匹配格式说明符L"%99s"，例如提供一个空字符串或仅包含空白字符的字符串。
- 触发路径: wchar_t * data = dataBuffer; @ 82; if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) @ 84; printLine("swscanf failed!"); @ 85; 当swscanf返回0时，条件不成立，不执行printLine，程序继续使用data，但data可能包含未初始化数据。 @ 84-88
- 结论: swscanf函数返回值的检查不正确，使用'== EOF'而不是检查是否等于0。当swscanf返回0时，条件不成立，程序继续使用未初始化的dataBuffer，但代码片段未展示后续对data的使用，因此实际影响不确定。
- D验证: stage_c_preserved / ver_ed13e0cc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 804. hyp_path_6d4ade619298

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_14.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: SRC_STRING 内容导致 swscanf 失败返回 -1
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_14.c:37
- 结论: 函数 swscanf 可能失败返回 EOF (-1)，但代码仅检查返回值是否为 0，未正确处理失败情况，违反 CWE-253 正确检查函数返回值。
- D验证: stage_c_preserved / ver_dc012679
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 805. hyp_path_3159260dd703

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_13.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: Attacker can control or influence the content of SRC_STRING to cause swscanf() to fail (e.g., by providing an invalid format or empty string).
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_13.c:37
- 结论: CWE-253: Incorrect Check of Function Return Value - swscanf() return value is compared to 0 instead of checking for failure (EOF). When swscanf fails (returns EOF=-1), the code does not detect the failure, and the variable 'data' may remain uninitialized or contain invalid data. Although the provided evidence does not show subsequent use of 'data', the violation itself is present. Impact depends on whether 'data' is used later, which is not confirmed in the snippet.
- D验证: stage_c_preserved / ver_f590d40c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 806. hyp_path_a73f10664c50

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_13.c:94
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者需要控制SRC_STRING的内容，但SRC_STRING是常量宏，无法由攻击者控制。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_13.c:62 (case11) 或 :85 (case12)
- 结论: CWE253: Incorrect Check of Function Return Value - swscanf返回值检查不完整。仅检查了EOF，未检查返回0（匹配失败）的情况，存在API contract violation。但SRC_STRING为编译时常量，攻击者无法控制，因此无实际可利用路径。
- D验证: stage_c_preserved / ver_f2175365
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 807. hyp_path_4d0fb940cd91

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_13.c:84
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: Attacker can influence SRC_STRING content to cause swscanf to return 0 (e.g., empty input or input starting with whitespace) or return a positive value less than the expected match count, leaving data uninitialized or partially written.
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_13.c:84
- 结论: CWE-253: Incorrect check of swscanf return value - only checked for EOF, not for successful match count or zero return. If swscanf returns 0 (no match) or positive (fewer matches than expected), the code assumes success and may use uninitialized or partially written data from dataBuffer.
- D验证: stage_c_preserved / ver_02dc0caf
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 808. hyp_path_1e112174a612

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_14.c:94
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 全局变量globalFive必须等于5才能触发缺陷代码
- 触发路径: void CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_14_case1() { case11(); case12(); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_14.c:92; if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_14.c:61; if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_14.c:82
- 结论: VULNERABILITY_FOUND: 在globalFive==5时，swscanf返回值检查仅校验EOF，未检查其他可能的错误返回值（如0），违反了CWE-253正确检查函数返回值的要求。
- D验证: stage_c_preserved / ver_e78f9bc2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 809. hyp_path_06980bf0be90

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_15.c:38
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入导致swscanf失败（如输入格式错误或遇到文件结束），但失败时返回非0值。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_15.c:38
- 结论: 在CWE253示例中，swscanf返回值为EOF（-1）表示失败，但代码仅检查返回值是否为0，导致错误条件被忽略，违反API contract。
- D验证: stage_c_preserved / ver_19c0095e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 810. hyp_path_4810f9d81144

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_15.c:71
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入字符串 SRC_STRING，使其不匹配格式（例如空字符串或仅空白字符），导致 swscanf 返回 0 而非 EOF。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_15.c:71; 后续使用了未更新的 data @ 后续使用 data 的代码行（未在片段中显示，但基于 Juliet 测试用例结构应存在）
- 结论: 函数 swscanf 的返回值检查不完整：代码仅检查返回值是否为 EOF，但忽略了返回值为 0（表示没有成功匹配并赋值任何变量）的情况。当 swscanf 返回 0 时，变量 data 未被写入，后续使用 data 可能导致未初始化内存读取或逻辑错误。
- D验证: stage_c_preserved / ver_ab9d82c3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 811. hyp_path_064e38f2ce7a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_16.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部攻击者控制输入，但函数行为依赖于输入数据，可能触发失败。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == 0) @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_16.c:37
- 结论: 函数swscanf的返回值检查不正确：代码比较返回值是否等于0，但swscanf失败时返回EOF（-1），成功返回匹配项数或0，因此未能正确捕获失败情况。
- D验证: stage_c_preserved / ver_450f4781
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 812. hyp_path_0a49bbe161e8

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_15.c:108
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) @ case12:91; if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) @ case11:69
- 结论: swscanf返回值检查不完整：仅检查了EOF（-1），未检查返回值为0（匹配失败）的情况，构成CWE-253违反。但输入SRC_STRING为常量，攻击者无法控制，实际路径不可利用。
- D验证: stage_c_preserved / ver_9a92b276
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 813. hyp_path_fa6ec102e8dc

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_14.c:84
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制 SRC_STRING 输入，使得 swscanf 返回非 EOF 但匹配项数为 0（例如提供空字符串或不符合格式的输入）。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_14.c:84
- 结论: CWE253: Incorrect Check of Function Return Value - swscanf 返回值仅检查 EOF，未检查实际匹配项数，可能导致未处理部分匹配或匹配失败，进而使用未充分初始化的缓冲区数据。
- D验证: stage_c_preserved / ver_f5bf2698
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 814. hyp_path_bce42b7910c2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_15.c:92
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的内容，导致swscanf返回值非EOF但实际未按格式读取数据（例如返回0）
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ case12:92
- 结论: CWE253: Incorrect Check of Function Return Value - swscanf返回值检查不完整，仅检查EOF而未检查是否成功读取预期的项数
- D验证: stage_c_preserved / ver_0ac83326
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 815. hyp_path_c8e84f006997

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_16.c:61
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可以控制SRC_STRING的内容，使得swscanf返回非EOF但未成功读取（如输入空字符串或格式不匹配），导致data未被正确填充。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_16.c:61
- 结论: swscanf函数返回值检查不完整：仅检查了是否等于EOF，忽略了返回0或正数但实际输入不匹配的情况，导致未正确检测到swscanf失败，可能使用未初始化的dataBuffer。
- D验证: stage_c_preserved / ver_3e8e6342
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 816. hyp_path_bb4edc7e8be4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_18.c:59
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者必须能够控制SRC_STRING的内容（若不可控则漏洞不可利用）
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_18.c:59
- 结论: swscanf返回值检查不完整：仅检查返回值是否等于EOF，未检查实际匹配项数是否为期望的1。当输入字符串格式不匹配时，swscanf返回0但不会触发错误处理，导致dataBuffer可能未被正确赋值，后续使用未初始化数据。但漏洞可利用性取决于SRC_STRING是否由攻击者控制；当前证据未明确SRC_STRING的来源，若为固定字符串则不可利用，但仍违反CWE-253。
- D验证: stage_c_preserved / ver_20c52db9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 817. hyp_path_d6991bb4dfd4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_18.c:37
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: SRC_STRING内容导致swscanf返回非0值（如EOF），且data后续被使用
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == 0) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_18.c:37
- 结论: swscanf返回值检查错误：仅检查返回值==0，但实际失败返回EOF(-1)或<0，导致未处理错误，data可能未初始化并被后续使用。
- D验证: stage_c_preserved / ver_966728b3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 818. hyp_path_1623f5d586e3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_17.c:70
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够使 fread 返回小于 99 的值（例如提供空输入或部分输入），但无法直接控制程序的安全行为。
- 触发路径: void CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_17_case1() { case11(); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_17.c:68; if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_17.c:57-60
- 结论: 函数 case11 中 fread 返回值检查不正确：要求返回值严格等于 99，但 fread 成功时返回值可能小于 99（例如文件结束或信号中断），这并不总是表示错误，违反了 CWE-253 规范。
- D验证: stage_c_preserved / ver_d0fb8a1b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 819. hyp_path_cb5720417259

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_01.c:61
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin输入数据，使得fread返回小于100-1的正数或0
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_01.c:50
- 结论: 函数fread的返回值检查不正确，将部分读取（返回值小于100-1但大于0）视为失败，违反了CWE-253定义。尽管后续未使用data数组，该缺陷导致错误处理逻辑将部分读取误判为失败，构成API contract violation。
- D验证: stage_c_preserved / ver_ef706eec
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 820. hyp_path_26c922bd663d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_16.c:70
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: Attacker can provide input via stdin that causes fread to return a value between 0 and 98 (inclusive) which does not indicate a failure but triggers the incorrect error message
- 触发路径: void CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_16_case1() { case11(); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_16.c:68; static void case11() { ... if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } ... } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_16.c:49-66
- 结论: VULNERABILITY_FOUND: Incorrect check of fread return value - checks for exact size rather than normal completion
- D验证: stage_c_preserved / ver_5391d1f0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 821. hyp_path_15e32957634c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_01.c:61
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向stdin提供导致fscanf返回0的输入，例如输入仅包含空白字符后立即EOF，或输入不匹配格式说明符。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_01.c:50
- 结论: 函数case11中fscanf的返回值检查不完整：仅检查返回值为EOF，未检查返回值为0（格式匹配失败）的情况。这违反了CWE-253正确检查函数返回值的要求。
- D验证: stage_c_preserved / ver_bca58336
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 822. hyp_path_528f807b9ab9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_12.c:96
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin输入任意内容（包括导致fscanf返回0的输入，如空行或格式不匹配的字符串）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_12.c:96
- 结论: fscanf返回值检查不完整，仅检查EOF，未检查返回0的情况，违反了CWE-253正确检查函数返回值的契约。
- D验证: stage_c_preserved / ver_b06a109a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 823. hyp_path_ff53f96abeaa

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_16.c:70
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向stdin输入不符合%99s格式的数据，使得fscanf返回0
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_16.c:54; printLine("fscanf failed!"); // 仅对EOF处理，其他返回值未处理 @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_16.c:55-57
- 结论: 函数case11中对fscanf的返回值检查不完整，违反CWE-253。但fscanf返回值未完全处理（仅检查EOF，未检查0或正数），且后续没有对data的任何使用，因此该违反无直接安全后果。需要D验证确认是否有隐含路径或上下文。
- D验证: stage_c_preserved / ver_9ac9f3f0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 824. hyp_path_d8259eb4f76c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_17.c:70
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供导致fscanf返回0的输入（如空行或非字符串内容）。
- 触发路径: static void case11() { ... if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_17.c:49-66
- 结论: fscanf返回值检查不完整：仅检查了EOF，未检查返回0的情况，违反了CWE-253。尽管代码未在后续使用data，导致实际危害路径缺失，但契约违反本身成立。
- D验证: stage_c_preserved / ver_1655dd12
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 825. hyp_path_b23d0c2f089c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_18.c:66
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供输入使fscanf返回0（例如空输入或格式不匹配），导致data未被更新，但后续printLine输出未定义内容（实际为空字符串）。
- 触发路径: if (fscanf(stdin, "%99s", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_18.c:61; printLine(data); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_18.c:63
- 结论: CWE253: Incorrect Check of Function Return Value - fscanf返回值检查不完整，仅检查EOF，未处理返回0或其他错误状态，违反CWE-253要求。
- D验证: stage_c_preserved / ver_600162c8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 826. hyp_path_ffc17f0f5783

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_12.c:96
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供不受信任的输入给标准输入
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_12.c:62-92 (case11函数)
- 结论: 对scanf()的返回值检查不完整，仅处理了EOF，未处理返回0的情况，违反了CWE-253。当输入空行或仅含空白字符时，scanf返回0，但代码未将其视为错误，可能导致后续逻辑处理不正确的输入。
- D验证: stage_c_preserved / ver_dbbca968
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 827. hyp_path_7d780e256d5b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_17.c:70
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供使scanf返回0的输入（例如仅空白字符或非字符串输入），但实际可能性极低。
- 触发路径: if (scanf("%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_17.c:58
- 结论: 函数case11中调用scanf并仅检查返回值是否等于EOF，忽略返回0的情况，违反了CWE-253对函数返回值的正确检查。尽管dataBuffer已初始化为空字符串，且scanf(%s)返回0在理论上极难触发，但API contract violation仍然存在。
- D验证: stage_c_preserved / ver_22986d78
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 828. hyp_path_bbfa479ffc42

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_16.c:70
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供输入，导致scanf返回值为0（如输入空白字符或非格式匹配字符串）
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_16.c:56-60
- 结论: 函数case11中对scanf的返回值检查不完整：仅检查是否等于EOF，而未处理返回值为0（表示未成功匹配任何项）的情况。尽管dataBuffer初始化为空字符串，导致后续printLine打印空字符串无直接安全后果，但该API misuse违反了CWE-253，存在返回值检查逻辑错误。
- D验证: stage_c_preserved / ver_d61cd067
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 829. hyp_path_bde56760564a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_01.c:61
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入流使得scanf返回0（虽然在实际交互式输入中极难触发）
- 触发路径: static void case11() { ... if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } ... } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_01.c:44-57
- 结论: 对scanf返回值检查不完整：仅检查了EOF，忽略了返回0（匹配失败）的情况，违反了CWE-253（不正确检查函数返回值）。但由于后续代码未使用data变量进行任何危险操作，且data缓冲区初始化为空字符串，缺乏sink路径，导致实际安全影响极低。
- D验证: stage_c_preserved / ver_0edc334d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 830. hyp_path_1f4c3fb30558

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_18.c:66
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供使scanf返回0的输入（例如空字符串或非空格字符）
- 触发路径: if (scanf("%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_18.c:60
- 结论: 存在CWE-253错误检查函数返回值漏洞：在case11函数中，scanf()返回值仅检查是否等于EOF，未检查是否等于1（成功匹配项数）。当输入无法匹配%99s格式（例如空输入或无效字符）时，scanf返回0，但代码未将其视为失败，导致后续逻辑可能使用未改变的初始数据（空字符串），违反API契约。
- D验证: stage_c_preserved / ver_f7f723d6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 831. hyp_path_2840c40631de

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_12.c:98
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 无外部输入控制，SRC_STRING为固定字符串
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_12.c:88
- 结论: 函数case11中，sscanf返回值检查为'== EOF'不正确；sscanf成功时返回成功匹配的项目数（这里应为1），而非EOF。该错误检查导致sscanf失败时（返回<=0）可能被忽略，后续使用data缓冲区可能包含未完全填充的数据，但dataBuffer已初始化为空字符串，实际影响较低，但违反CWE-253定义。
- D验证: stage_c_preserved / ver_d4df47d1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 832. hyp_path_cc9e5e81d37e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_17.c:78
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING的内容或长度（当前为常量，不可控）
- 触发路径: if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_17.c:68
- 结论: snprintf返回值检查不完整，未检查截断情况，违反CWE-253规定的API契约。但SRC_STRING为常量，不可由攻击者控制，因此无法实际触发截断，漏洞影响较低。
- D验证: stage_c_preserved / ver_2d8b25ba
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 833. hyp_path_8f23d81b694c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_18.c:74
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法控制SRC_STRING，但SRC_STRING为固定长度字符串（通常约99个'A'），导致snprintf第二个参数为0或极小，必然发生截断且返回值非负，不触发错误处理。
- 触发路径: static void case11() { goto sink; sink: { ... } } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_18.c:55; if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_18.c:66
- 结论: 函数snprintf的返回值检查不完整：仅检查返回值小于0的错误情况，未检查返回值大于等于缓冲区大小导致的截断情况。这违反了CWE-253定义。尽管SRC_STRING为固定常量导致攻击者无法外部控制，但截断本身发生且未被正确处理，仍构成API契约违规。
- D验证: stage_c_preserved / ver_a686d852
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 834. hyp_path_5ae328f610e0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_18.c:68
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: SRC_STRING内容导致sscanf匹配失败（返回0）
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_18.c:58-62
- 结论: sscanf返回值检查不完整：仅检查了是否等于EOF，而未检查是否成功读取（应返回1）。当sscanf返回0时（未匹配任何输入），不会打印错误，违反CWE-253对函数返回值检查的要求。
- D验证: stage_c_preserved / ver_bbb31c01
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 835. hyp_path_22cd5f75dbda

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_17.c:72
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC_STRING，使其导致sscanf返回0（例如空字符串或不匹配格式）
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) @ CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_17.c:60
- 结论: sscanf返回值检查不完整：仅检查EOF，未检查返回值是否为期望的匹配项数（1）。当输入不匹配格式时返回0，错误处理被跳过，data保持空字符串。尽管在Juliet测试中SRC_STRING为固定字符串，违反API contract（CWE-253）仍然存在。
- D验证: stage_c_preserved / ver_ea8f2b3a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 836. hyp_path_bd5ac2313f00

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_16.c:72
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 外部攻击者无法控制输入字符串（SRC_STRING为固定常量），但代码模式本身违反CWE-253。
- 触发路径: if (sscanf(SRC_STRING, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_16.c:60-63
- 结论: 在case11函数中，调用sscanf后仅检查返回值是否等于EOF，未检查返回值为0的情况（表示匹配失败）。这违反了CWE-253关于正确检查函数返回值的要求。虽然代码中SRC_STRING为固定常量，导致sscanf返回0的情况在实际运行时不可达，但代码逻辑本身存在缺陷，属于API contract violation。
- D验证: stage_c_preserved / ver_d0de4960
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 837. hyp_path_81632e032210

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_17.c:70
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fread读取时发生错误或提前结束
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_17.c:58-62
- 结论: fread的返回值被检查，但检查后仅打印错误信息，未采取终止或恢复措施，违反了CWE-253正确检查函数返回值的要求。尽管数据缓冲区已初始化为空字符串且后续未使用，降低了实际安全影响，但代码仍存在API contract violation。
- D验证: stage_c_preserved / ver_52b354fc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 838. hyp_path_ed667f02ea47

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_17.c:70
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使fwscanf匹配失败返回0
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_17.c:59
- 结论: 函数fwscanf返回值检查不完整：仅检查了EOF，未处理匹配失败返回0的情况。虽然dataBuffer已初始化且后续未使用data，但违反了CWE-253定义。
- D验证: stage_c_preserved / ver_aca0988b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 839. hyp_path_50f0d17d5f33

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_01.c:61
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可以通过标准输入提供输入数据
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_01.c:50
- 结论: API misuse: fwscanf返回值检查不完整，仅检查了EOF而忽略了其他失败情况，违反了CWE-253规范。
- D验证: stage_c_preserved / ver_8be89c67
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 840. hyp_path_decb7d3b4908

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_16.c:70
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入流的内容
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_16.c:58
- 结论: 在case11函数中，fwscanf的返回值检查不完整：仅检查是否等于EOF，未处理返回0（匹配失败）的情况。这违反了CWE253（不正确的函数返回值检查），可能导致未检测到的错误状态。
- D验证: stage_c_preserved / ver_8b5aa664
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 841. hyp_path_d422fd5ec8dd

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_18.c:66
- 漏洞类型: null_deref
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供导致wscanf匹配失败（返回0）而非EOF的输入
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_18.c:58
- 结论: wscanf的返回值检查不完整，仅检查了EOF，而忽略了其他失败条件（如返回0表示未匹配到任何输入），违反了CWE-253（函数返回值检查错误）的定义。虽然dataBuffer已初始化且后续仅打印，不影响空指针或缓冲区溢出，但错误处理遗漏构成API contract violation。
- D验证: stage_c_preserved / ver_36b2ab3a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 842. hyp_path_7869bb5e5652

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_01.c:61
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制程序的标准输入流，使得wscanf返回0（例如输入仅包含空白字符或空流）而非EOF
- 触发路径: void CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_01_case1() { case11(); } @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_01.c:59; if (wscanf(L"%99s", data) == EOF) { printLine("wscanf failed!"); } @ CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_01.c:51
- 结论: 函数case11中调用wscanf时仅检查返回值是否为EOF，未检查是否成功匹配到数据（即返回值应为1），违反了CWE-253的API contract。尽管后续代码未直接使用data，但错误返回值检查本身构成漏洞；攻击者可能通过控制输入使wscanf返回0（例如输入仅空白字符），导致程序错误认为输入成功，可能引发未定义行为。
- D验证: stage_c_preserved / ver_41976de6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 843. hyp_path_e1b56ee8b20a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_12.c:96
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供输入导致wscanf返回0（如空行或空白字符序列）
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_12.c:62-92
- 结论: 存在不正确的函数返回值检查：wscanf返回值仅检查是否为EOF，忽略返回0的情况，构成CWE253违规，但无后续数据使用，风险极低。
- D验证: stage_c_preserved / ver_d8b3d253
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 844. hyp_path_9c8841d7489a

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_18.c:74
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 假设SRC_STRING可能来自外部输入或可变数据，导致snprintf实际写入的字符数可能等于或大于缓冲区剩余空间，从而发生截断但未被不正确检查捕获。
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC_STRING)-1, L"%s\n", SRC_STRING) < 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_18.c:63-64
- 结论: 存在不正确的函数返回值检查（CWE253）：SNPRINTF返回值仅检查了负值（错误条件），但未检查是否等于或大于目标缓冲区大小（截断条件），导致可能的缓冲区截断未被检测。
- D验证: stage_c_preserved / ver_5b7f3bff
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 845. hyp_path_2e2d343f11e3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_01.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制 SRC_STRING 的值，使得 swscanf 返回 0（例如输入空字符串或无法匹配的字符）。
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_01.c:52
- 结论: CWE253: 函数 swscanf 的返回值检查不完整，仅检查了 EOF（-1），忽略了返回值为 0 的情况（表示无匹配项）。虽然本代码中 dataBuffer 已初始化为空字符串，后续也无安全敏感操作，但违反 API contract 中应检查所有错误返回的要求，仍属于 CWE-253 脆弱性。
- D验证: stage_c_preserved / ver_3974c40f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 846. hyp_path_3bcabf5ee930

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_16.c:72
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入字符串SRC_STRING，使其导致swscanf返回0（格式不匹配）或其他非EOF的错误值
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_16.c:62-63
- 结论: 在函数case11中，对swscanf的返回值检查不正确：仅检查是否等于EOF（-1），而忽略了返回值可能为0（匹配失败）或其他错误返回值的情况，违反了CWE-253对函数返回值正确检查的要求。攻击者可构造输入使swscanf返回0，导致错误未被处理。
- D验证: stage_c_preserved / ver_755054d5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 847. hyp_path_457cef62e09e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_17.c:72
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制 SRC_STRING 的内容，使其无法匹配格式 L"%99s"
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_17.c:62; // 仅检查了 EOF，未检查返回值为 0 的情况 @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_17.c:62-66
- 结论: 在函数 case11 中，调用 swscanf 后只检查了返回值是否等于 EOF，但没有检查是否成功匹配了预期的字段数（预期为1）。若 swscanf 返回 0（表示没有匹配项），则不会进入错误处理分支，导致 dataBuffer 仍保持初始的空字符串，但后续代码可能基于错误的返回值假设继续执行，违反了 CWE-253 关于正确检查函数返回值的约定。
- D验证: stage_c_preserved / ver_4e78fde2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 848. hyp_path_b0eda78a8f8d

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_18.c:68
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (swscanf(SRC_STRING, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_18.c:62
- 结论: 存在CWE253漏洞：swscanf返回值检查不完整，仅检查EOF而非成功匹配项数，违反API约定。但后续未使用data，无实际影响。
- D验证: stage_c_preserved / ver_5cf51231
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 849. hyp_path_75c0cb5da0f2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_17.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 标准输入（stdin）在读取过程中提前结束或发生错误，导致 fread 返回非0但小于请求数的值
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_17.c:36
- 结论: 函数 fread 的返回值检查不正确：代码仅检查返回值是否等于0，但 fread 可能返回介于0和请求计数之间的值来表示部分读取或错误，导致未检测到失败，进而可能使后续使用未完全填充的缓冲区数据，违反 API contract。
- D验证: stage_c_preserved / ver_954b07fd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 850. hyp_path_efd07a61bfff

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_17.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者通过stdin提供少于99字节的输入，使fread返回值介于1~98之间，从而绕过检查，但后续无对data的引用。
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_17.c:36
- 结论: fread()返回值检查不完整：仅检查返回值是否等于0，未处理部分读取（返回值介于1到98之间）的情况，导致未检测到读取失败或部分读取，虽然当前代码片段中未直接使用未初始化数据，但从API contract角度看存在CWE-253违规。
- D验证: stage_c_preserved / ver_bfab4245
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 851. hyp_path_4b2784b88e75

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_12.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向 stdin 提供输入，使 fread 读取的字节数小于 99 但大于 0
- 触发路径: void CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_12_case0() { if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_12.c:24; if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_12.c:33-37; fread(...) 调用后未正确检测返回值，当返回值在 1 到 99 之间时，程序认为成功 @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_12.c:35
- 结论: 存在对 fread 函数返回值的不正确检查：在 globalReturnsTrueOrFalse() 返回真时执行的分支中，代码检查 fread 返回值是否等于 0 来判断失败，但 fread 实际返回读取的字节数，当返回值小于请求的字节数（100-1）时表示可能失败。错误的检查可能导致部分读取或读取失败未被正确处理，进而使用未完全初始化的缓冲区，引发未定义行为或信息泄露。
- D验证: stage_c_preserved / ver_ca671632
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 852. hyp_path_0561922ec8f3

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_08.c:76
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法触发该代码路径，因为分支条件staticReturnsFalse()恒为假，但漏洞假设基于代码本身的语义错误。
- 触发路径: if(staticReturnsFalse()) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_08.c:63; if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_08.c:76
- 结论: 在死代码分支中存在对fread返回值的错误检查。fread函数返回值应检查是否小于请求的读取数量或调用ferror，但此处检查是否不等于100-1，这是不正确的，违反了CWE-253的API契约。由于代码位于staticReturnsFalse()为假时的死代码分支，实际不可执行，但代码本身存在语义错误。
- D验证: stage_c_preserved / ver_e9365d4e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 853. hyp_path_0c3f96285315

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_08.c:39
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: fread在读取时返回非0但小于99的值（例如遇到部分读取）
- 触发路径: staticReturnsTrue()返回1，进入代码块。 @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_08.c:37-41; if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_08.c:46-50; if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_08.c:48-52
- 结论: fread函数返回值检查不完整：仅检查返回值是否等于0，未处理返回值小于请求数但大于0的部分读取情况，可能导致未初始化内存或数据不完整被使用。
- D验证: stage_c_preserved / ver_3b4d49ac
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 854. hyp_path_43ff574c5bdc

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_08.c:95
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 标准输入可能不提供恰好99个字符，导致fread返回小于99的正数。
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_08.c:95
- 结论: fread返回值检查使用了!=而不是<，可能错误地将部分读取视为失败，导致API misuse（CWE-253）。尽管后续没有使用未完全填充的数据，但返回值检查逻辑不正确。
- D验证: stage_c_preserved / ver_820f61a0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 855. hyp_path_b33cf87a1ac9

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_12.c:49
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供数据，使fread返回1到99之间的值（部分成功）
- 触发路径: if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_12.c:26; if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_12.c:35; 缺失 @ 后续使用data的代码（证据中未提供，存在于样本其余部分）
- 结论: 在CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_12.c的case0函数中，当globalReturnsTrueOrFalse()返回false时，代码将fread返回值与0比较，而不是与期望读取的元素数(100-1)比较。这违反了fread API的正确使用约定。若fread部分成功（返回1-99），错误检查误认为成功，跳过printLine，后续可能使用未完全填充的data缓冲区（证据中未显示后续使用代码，但根据典型漏洞场景，可能造成数据泄露或程序异常）。
- D验证: stage_c_preserved / ver_84c9b0ba
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 856. hyp_path_5f16f189c724

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_11.c:26
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin控制输入，使得fread仅读取部分数据（例如输入不足99个字符）
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_11.c:35
- 结论: fread返回值检查错误：代码仅检查fread返回值是否等于0来判断失败，但fread可能部分成功（返回值介于1和99之间），此时不会打印错误，但后续使用可能基于未完全初始化的data导致未定义行为或信息泄露。
- D验证: stage_c_preserved / ver_97f1e5fc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 857. hyp_path_06d0c6169fb7

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_11.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供可控的stdin输入，使得fread返回非99的值（如0或50）
- 触发路径: static void case12() { if(globalReturnsTrue()) { { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_11.c:72-76; char * data = dataBuffer; /* ALT: check for the correct return value */ if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_11.c:80-84
- 结论: fread返回值检查错误：比较条件为不等于预期读取元素个数（99），但fread返回实际读取的元素数，当返回值小于99但不等于0时（例如50），条件错误认为成功，导致缓冲区部分未初始化，后续使用可能引发未初始化数据访问。
- D验证: stage_c_preserved / ver_4c90baa3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 858. hyp_path_9068d40c402f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_05.c:69
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: Attacker controls stdin content such that fread returns fewer than 99 bytes (e.g., early EOF or error).
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ L69
- 结论: CWE253 Incorrect Check of Function Return Value: fread return value is checked with '!=' instead of proper handling for partial reads. When fread returns less than requested (0-98), the code only prints an error message but does not exit or prevent further execution. Although no immediate use of the potentially uninitialized buffer is visible in the provided snippet, the API contract violation exists, and downstream usage (e.g., printing or further processing) could lead to uninitialized memory exposure or undefined behavior if present. Evidence is incomplete due to missing sink usage.
- D验证: stage_c_preserved / ver_c78d9fd3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 859. hyp_path_42e8473c6048

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_08.c:48
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入（例如通过程序交互或重定向），并输入少于99个wchar_t字符。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ L48
- 结论: fread() 返回值检查不完整：仅检查返回值是否为0，忽略了部分读取（返回值介于1到count-1之间）的情况。这违反了CWE-253，可能导致后续使用data时包含未初始化的内存或部分用户输入，引发逻辑错误或信息泄露。
- D验证: stage_c_preserved / ver_0bd154cb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 860. hyp_path_2ae3dcc1d14e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_07.c:68
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: Attacker can provide input via stdin that may cause fread to read fewer than 99 characters (e.g., early EOF or error), triggering the incorrect check
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_07.c:68
- 结论: CWE253: Incorrect Check of Function Return Value - fread return value is compared for exact equality instead of checking for errors or partial read
- D验证: stage_c_preserved / ver_6e5eb777
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 861. hyp_path_64666468bbfe

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_14.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法直接控制fread返回值，但可以通过输入控制实际读取字节数（如发送少于99字节的数据）
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_14.c:63
- 结论: 对fread返回值的检查不正确：检查条件是返回值不等于请求大小（99），而fread在部分读取成功时返回值小于请求大小，应检查返回值是否小于请求大小。这违反了CWE-253（函数返回值检查不正确）。虽然存在API contract violation，但当前代码证据缺少后续使用dataBuffer的sink路径，实际信息泄露或未定义行为未证实，需要动态验证。
- D验证: stage_c_preserved / ver_888f4195
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 862. hyp_path_702aa8a8aacf

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_05.c:69
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使得fread返回与实际读取数不同的值（如返回0或部分）
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_05.c:69
- 结论: 存在CWE-253漏洞：fread函数返回值检查不正确，使用!=100-1进行比较，没有正确检查实际读取的元素数是否小于请求数或是否失败。
- D验证: stage_c_preserved / ver_0372e6a0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 863. hyp_path_4485ac105de6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_11.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制或影响 stdin 输入，使得 fread 返回一个非零但小于请求元素数的值。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_11.c:35
- 结论: fread() 的返回值被检查是否等于0，而不是检查是否等于请求读取的元素数（100-1）。这违反了 CWE-253（函数返回值错误检查），但在此代码路径中，data 缓冲区在 fread 后未被使用，因此未初始化部分不会导致实际利用。漏洞存在但影响很低。
- D验证: stage_c_preserved / ver_a87e33b8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 864. hyp_path_619ba5e0cd33

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_02.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者可以通过stdin控制fread读取的字节数，使其返回大于0但小于99的值
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_02.c:35
- 结论: fread()返回值检查不正确：仅检查返回值为0，未检查返回值是否等于期望读取的字节数99，导致部分读取时认为成功，可能使用未完全初始化的缓冲区。
- D验证: stage_c_preserved / ver_370fadd0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 865. hyp_path_02303956d9e2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_01.c:33
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响标准输入流，使得fread只读取部分数据（如提前终止或延迟输入）。
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_01.c:33
- 结论: fread返回值检查不完整：代码仅检查fread返回值是否等于0，但未处理返回值介于1和98之间的情况，导致data数组可能未被完全填充，后续使用可能读取未初始化或部分初始化的数据，构成CWE-253漏洞。
- D验证: stage_c_preserved / ver_dea71862
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 866. hyp_path_b91683917fbc

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_13.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过 stdin 提供可控输入，使 fread 返回值不等于 100-1（例如，输入不足99个宽字符或发生读取错误）
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_13.c:63; 假设 fread 失败后 data 被用于 wprintf 等输出或进一步处理 @ 后续代码（未完全展示）
- 结论: INCORRECT_CHECK_OF_FUNCTION_RETURN_VALUE: fread 返回值被检查但错误处理不充分，程序在 fread 失败后仍可能使用不完整数据
- D验证: stage_c_preserved / ver_25981777
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 867. hyp_path_58c63a7cbe90

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_03.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin输入少于99个字符的数据，导致fread返回非0但小于99的值。
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_03.c:35
- 结论: fread返回值检查不充分：代码仅检查返回值是否为0，未检查返回值是否小于请求的元素数（99）。若fread读取部分数据（返回值在1到98之间），data缓冲区部分未更新，后续使用将导致未初始化或部分填充的数据，引发未定义行为。
- D验证: stage_c_preserved / ver_76059027
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 868. hyp_path_dc5afb0c3a74

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_03.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin输入流，使其在fread过程中发生错误或提前结束（如EOF）。
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_03.c:82
- 结论: fread返回值检查不完整：仅检查读取项数是否等于期望值，未区分文件结束和实际错误，且错误后仅打印消息未终止或处理，可能导致后续使用未完全读取或未定义的数据。
- D验证: stage_c_preserved / ver_aff359cf
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 869. hyp_path_1abd83bfca2e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_03.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使得fread返回值不等于100-1（如输入少于99个字符或触发EOF）
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_03.c:63
- 结论: fread返回值检查使用精确计数比较（!=100-1），未正确处理部分读取或EOF情况，违反CWE-253的API contract misuse。尽管当前未使用读取数据，但检查本身不精确，可被攻击者利用导致误判。
- D验证: stage_c_preserved / ver_3d61c923
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 870. hyp_path_025691bcb11f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_04.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入流，使fread部分读取数据（例如提前结束输入或产生错误）
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_04.c:41
- 结论: 对fread返回值的检查不正确：仅当返回0时视为失败，但fread可能返回大于0但小于请求元素数的值（例如部分读取或EOF），此时未正确处理错误，违反CWE-253。
- D验证: stage_c_preserved / ver_2597e63a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 871. hyp_path_2950855ea128

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_05.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入，导致fread部分读取失败（返回值介于0和100-1之间）
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_05.c:41
- 结论: fread() 返回值检查错误：代码仅检查返回值是否等于0，忽略部分读取（返回值在0到请求数之间）的情况，违反CWE-253：未正确检查函数返回值。
- D验证: stage_c_preserved / ver_ec4fcc43
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 872. hyp_path_3a626afc6170

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_05.c:88
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入，使得fread读取的字节数少于100-1（例如提前发送EOF）。
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_05.c:88
- 结论: 函数fread的返回值检查不正确：检查条件为 != 100-1，但fread成功时可能返回少于100-1的合法值（如遇到EOF），导致错误处理逻辑被错误触发。该行为违反CWE-253关于正确检查函数返回值的约定。
- D验证: stage_c_preserved / ver_13279ed5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 873. hyp_path_542377990347

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_04.c:88
- 漏洞类型: CWE-253, CWE-457
- CWE: CWE-253; CWE-457
- 风险等级: P1
- 触发条件: 攻击者可以控制stdin输入，导致fread返回小于99的值（如提前关闭或输入较短数据）
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_04.c:88
- 结论: 对fread返回值的检查虽然正确(比较是否等于请求数)，但错误处理不充分：当fread部分读取或失败时仅打印消息而不终止或重置缓冲区，导致后续使用未初始化或部分填充的数据，存在信息泄露或未初始化数据使用风险。
- D验证: stage_c_preserved / ver_ca14fd65
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 874. hyp_path_4dcdf77223fd

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_06.c:40
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供部分数据，使得fread返回值小于请求大小但大于0
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_06.c:40; printLine("fread failed!"); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_06.c:42
- 结论: fread()返回值检查不完整：仅检查返回值是否等于0，忽略了返回值小于请求大小但非0的部分读取或失败情况，导致可能使用未初始化的不完整数据。
- D验证: stage_c_preserved / ver_70a747d6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 875. hyp_path_cc729e789475

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_06.c:87
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: Attacker controls stdin input such that fread reads fewer than 99 characters or fails entirely.
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ L87-91
- 结论: VULNERABILITY_FOUND: Incorrect check of fread return value; error handling only prints message without preventing subsequent use of data.
- D验证: stage_c_preserved / ver_d7474510
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 876. hyp_path_60b03e7d8ae0

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_09.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin输入少于99字节的数据，使得fread返回正数但小于99。
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_09.c:35
- 结论: fread()返回值检查不正确：仅检查返回值是否等于0，未处理返回正数但小于请求字节数的情况，可能导致数据读取不完整。
- D验证: stage_c_preserved / ver_539a3519
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 877. hyp_path_13781654f7b4

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_07.c:40
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使得输入长度不足99字节。
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_07.c:40
- 结论: fread返回值检查不完整：仅检查了返回值为0（完全失败），但未处理返回值小于请求大小但不为0的部分读取情况，违反CWE-253定义。虽然代码未展示后续对data的使用，但缺陷本身存在，可能导致未初始化数据或信息泄露，影响程度取决于后续逻辑。
- D验证: stage_c_preserved / ver_f7d001b2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 878. hyp_path_128a13827a35

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_06.c:68
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入，使得fread返回小于100-1的正数（例如文件结束或部分读取）
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_06.c:68; printLine("fread failed!"); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_06.c:70
- 结论: fread返回值检查不正确：检查条件为 '!= 100-1'，但fread返回值小于请求字节数不代表失败（如文件结束符），正确应检查返回值是否等于0或是否遇到错误。这违反了CWE-253（函数返回值错误检查）。但后续代码仅打印错误消息，未使用读取的部分数据，因此无直接可利用路径。
- D验证: stage_c_preserved / ver_8da1b63f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 879. hyp_path_a244e932475b

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_10.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制 stdin 输入，使得 fread 返回非 0 但小于 99 的值。
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_10.c:35
- 结论: 对 fread 返回值的检查不正确：代码仅检查返回值是否等于 0，而 fread 可能返回小于请求字节数的正值（部分成功），这种情况未被处理，导致 API misuse，违反 CWE-253。
- D验证: stage_c_preserved / ver_f1b085bf
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 880. hyp_path_c93ecaec7211

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_13.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入，使得fread()返回非0但小于100-1的值，实现部分读取。
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_13.c:35
- 结论: fread() 返回值检查不正确：仅检查返回值是否等于0，未检查是否等于期望读取数量（100-1），导致部分读取时程序继续使用未完全填充的 data 数组，可能触发未初始化内存读取。
- D验证: stage_c_preserved / ver_bb4e69a5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 881. hyp_path_ec3387c12954

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_14.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入，使得fread的返回值小于100-1（例如，输入长度不足或中途终止）。
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_14.c:35
- 结论: fread()返回值检查不正确：代码检查fread的返回值是否等于0，但根据fread的API契约，返回值表示实际读取的元素数，小于请求数（包括0）表示错误或EOF。正确检查应确保返回值等于请求的元素数（100-1）。此错误检查可能导致部分读取或读取失败时未正确处理，后续使用未完全初始化的data缓冲区，造成未初始化内存访问或信息泄露。
- D验证: stage_c_preserved / ver_8200f33f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 882. hyp_path_cc78b306f95f

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_09.c:82
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，例如提供少于99字节的数据或提前关闭stdin，导致fread返回小于99的数值。
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_09.c:82
- 结论: fread返回值检查不正确：条件 `fread(...) != 99` 作为失败条件无法区分EOF和错误，且错误处理仅打印消息，未阻止后续可能使用部分填充的dataBuffer。但后续对data的使用未在代码片段中体现，实际可利用性取决于上下文。
- D验证: stage_c_preserved / ver_b6d7398a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 883. hyp_path_1dc7da6b0568

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_15.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向stdin提供输入，使得fread()返回0到98之间的值（即部分读取或EOF）。
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_15.c:36
- 结论: fread()返回值检查不正确：仅检查是否等于0，而未检查是否等于请求的元素数（100-1）。这违反了CWE-253（对函数返回值的错误检查），属于API contract violation。即使后续未直接使用data缓冲区，不正确的检查方式可能导致在fread()部分成功时无法正确识别错误，从而在后续数据依赖中引发未定义行为。
- D验证: stage_c_preserved / ver_c971d157
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 884. hyp_path_428cf89a85ce

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_14.c:82
- 漏洞类型: CWE-754, CWE-690
- CWE: CWE-754; CWE-690
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入控制fread读取的数据量，使其返回小于99的值（包括0），导致dataBuffer部分填充或未初始化
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_14.c:82
- 结论: 函数fread返回值检查虽然正确捕获了非完全读取（返回值不等于99），但错误处理不充分：仅打印错误消息，未终止执行或重置缓冲区。后续使用dataBuffer时可能访问部分填充或未初始化的数据，导致未定义行为。
- D验证: stage_c_preserved / ver_dbc4bfd3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 885. hyp_path_411f680b7416

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_16.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使得fread返回小于100-1的值但非0。
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_16.c:35
- 结论: 函数fread的返回值检查不正确，仅检查返回值是否为0，而未检查是否等于请求读取的字节数(100-1)，违反了CWE-253中关于正确检查函数返回值的要求。
- D验证: stage_c_preserved / ver_bf318d03
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 886. hyp_path_3451cb77a53c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_18.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供输入，使得 fread() 在读取过程中遇到 EOF 或错误，但返回一个非零且小于请求数（100-1）的数值。
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_18.c:35
- 结论: 对 fread() 返回值的检查不正确，只检查了返回值等于 0，而未检查是否等于请求读取的元素数。这可能导致在 fread 部分成功时（返回正数但小于请求数），错误地认为读取成功，从而使用未完全读取的数据，可能造成数据损坏或未初始化内存访问。
- D验证: stage_c_preserved / ver_df78eb11
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 887. hyp_path_31b687f821aa

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_15.c:90
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin输入数据，使fread返回值不为99（例如输入少于99个字符或通过控制EOF）。
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) { @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_15.c:90; printLine("fread failed!"); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_15.c:92
- 结论: fread返回值检查不正确：使用!= 100-1判断失败，但正确做法应检查返回值是否小于请求的项数。当fread因EOF或错误返回小于99的值时，程序仅打印错误信息，未正确处理缓冲区数据或终止，可能导致后续使用未初始化或部分填充的缓冲区，引发未定义行为或信息泄露。
- D验证: stage_c_preserved / ver_1c393c1e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 888. hyp_path_0b9a47be5c00

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_01.c:33
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin输入控制数据流，造成fread部分读取（例如输入长度小于99个宽字符）。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_01.c:33
- 结论: fread()返回值检查不完整：代码仅检查返回值是否等于0，忽略部分读取（返回值小于请求数但非0）的情况，违反CWE-253。即使后续未使用data，API contract violation仍存在。
- D验证: stage_c_preserved / ver_6c5cbc5e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 889. hyp_path_e2aa39f84dc5

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_01.c:52
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入，使得fread读取的项数小于100-1但大于0。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_01.c:52
- 结论: 在CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_01.c中，fread的返回值检查错误：使用 != (100-1) 判断是否成功，但实际应使用 < (100-1) 或将返回值与0比较。当fread成功读取部分数据但不足100-1时，程序错误地认为读取失败并打印消息，但未正确处理部分读取的数据，可能导致后续使用未完全填充的缓冲区，引发未初始化数据使用或逻辑错误。
- D验证: stage_c_preserved / ver_5f451d5c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 890. hyp_path_f1a828964e80

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_02.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响输入流，使fread返回0到99之间的非期待值，但后续无实际sink，需要额外代码配合。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ 35
- 结论: fread()返回值检查不完整，违反CWE-253合约，但当前代码路径未发现后续对data缓冲区的使用，无法构成完整利用路径。
- D验证: stage_c_preserved / ver_5afc3941
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 891. hyp_path_e8e0d8a8691c

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_03.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 标准输入提供的数据量少于100-1个wchar_t，但多于0个。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_03.c:35
- 结论: 对fread的返回值检查不完整：仅当返回值为0时认为失败，但fread可能返回小于请求大小的正值表示部分读取，此时数据不完整但程序可能继续使用未完全填充的缓冲区，导致未初始化数据或逻辑错误。
- D验证: stage_c_preserved / ver_ac7031f8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 892. hyp_path_8b7603e3e831

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_03.c:63
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin输入流，使得fread读取的字符数不等于99但成功读取部分数据（例如发送少于99个字符）。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ 61-65
- 结论: fread返回值检查不正确：代码仅检查返回值是否等于请求个数（99），未处理部分读取情况。当fread读取少于99个字符时，程序仅打印错误信息而不终止或采取恢复措施，导致后续代码可能使用部分填充的缓冲区，违反CWE-253中关于正确检查函数返回值的要求。
- D验证: stage_c_preserved / ver_2de1686b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 893. hyp_path_e564694be72e

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_04.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入控制或影响 fread 读取的数据量，使其返回值不为 0 但少于请求的 99 项。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_04.c:41
- 结论: 函数 fread 的返回值检查不正确：代码检查 fread 是否返回 0，但标准使用应检查返回值是否等于请求的读取项数。当 fread 返回小于请求项数的非零值时，程序错误地认为读取成功，可能导致后续使用未完全初始化的数据。
- D验证: stage_c_preserved / ver_5216cf58
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 894. hyp_path_87a4866598e2

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_04.c:69
- 漏洞类型: CWE-253, CWE-457
- CWE: CWE-253; CWE-457
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使其长度小于99个宽字符，导致fread返回值小于99。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_04.c:69; printLine("fread failed!"); @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_04.c:70; /* 假设后续代码使用dataBuffer，例如wprintf(data); */ @ 后续代码（CWE样例典型模式中通常有使用dataBuffer的操作）
- 结论: fread返回值检查不当：仅当返回值严格等于99时才认为成功，忽略了部分读取的情况（如返回0-98）。在部分读取时，程序仅打印错误信息但继续执行，导致dataBuffer中可能包含未初始化的数据，后续使用可能引致未初始化内存读取（CWE-457）或信息泄露。
- D验证: stage_c_preserved / ver_c23e5856
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 895. hyp_path_a8a5fb0574f8

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_05.c:41
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供部分输入，使得 fread() 返回非 0 但小于 100-1 的值。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_05.c:41
- 结论: fread() 返回值检查不完整，违反 CWE-253 规范，仅检查返回值为 0 的情况，未处理部分读取或其它错误情况。虽然代码片段未展示后续使用 data，但返回值检查不完整本身构成 API contract violation。
- D验证: stage_c_preserved / ver_eb6a13b1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 896. hyp_path_06d9740586ef

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_07.c:40
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响输入流，使得fread在读取前99个宽字符时部分成功（例如提前到达EOF或读取错误导致返回值少于100-1但非零）。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_07.c:40
- 结论: fread返回值检查不正确：仅检查返回值是否为0，而未检查返回值是否等于请求读取的元素数(100-1)，导致部分读取时未检测到错误，可能使用未完全填充的缓冲区。
- D验证: stage_c_preserved / ver_d7b8af08
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 897. hyp_path_e5945e0457ae

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_06.c:87
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入流长度或提供EOF，使fread返回小于99的正整数（部分读取），导致错误处理分支被触发，而实际并非错误
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_06.c:87
- 结论: CWE253: fread返回值检查不正确。使用'!='比较返回值与期望值，而非'<'，导致部分读取（如读取50个元素）被误判为失败，可能造成数据不完整或使用部分未初始化数据。
- D验证: stage_c_preserved / ver_6713414c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 898. hyp_path_8071ab7ee2ca

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_06.c:40
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过 stdin 提供数据，使得 fread 读取少于 99 个元素但不为0，例如在文件末尾或部分读取错误场景。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_06.c:40
- 结论: fread() 返回值检查不正确：只检查返回值是否等于0，而未检查是否等于请求读取的元素个数 (100-1)。这违反了 CWE-253 定义的正确检查函数返回值的契约，即使后续未使用缓冲区，也构成 API 误用漏洞。
- D验证: stage_c_preserved / ver_86f52cbd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 899. hyp_path_e603b36ad4f6

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_06.c:68
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使得fread返回小于请求大小的值（例如提前关闭输入流或提供较少数据）; dataBuffer为局部变量，未显式初始化，若fread未完全填充则包含未定义数据
- 触发路径: wchar_t * data = dataBuffer; /* ALT: check for the correct return value */ if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_06.c:66-70; if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_06.c:68-72
- 结论: 对fread函数返回值的检查不完整：仅当返回值不等于请求大小时打印错误，但未处理部分读取（返回值在0到99之间）的情况，也未阻止后续使用可能未完全初始化的数据缓冲区，可能导致信息泄露或未定义行为。
- D验证: stage_c_preserved / ver_754bb9b2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 900. hyp_path_0087457f09ea

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_07.c:87
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入，使得fread成功读取99个wchar_t元素。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_07.c:87
- 结论: fread的返回值检查错误：检查条件`!= 100-1`（即`!= 99`），而fread成功读取指定数量（99个）时返回99，导致误判为失败。违反了CWE-253（不正确的函数返回值检查）。
- D验证: stage_c_preserved / ver_89d5fad0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 901. hyp_path_608beb9132a7

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_09.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入流（stdin），使得fread读取的字符数少于99，但非零。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_09.c:35
- 结论: fread()返回值检查不正确：仅检查返回值是否为0（完全失败），而未检查返回值是否等于请求读取的元素数（100-1），可能导致部分读取未被检测，后续使用不完整或未初始化的数据。
- D验证: stage_c_preserved / ver_deb74d09
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 902. hyp_path_527eb98203af

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_10.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin的输入流，使fread只读取部分数据（例如通过提前关闭或缓慢发送）。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_10.c:35
- 结论: fread函数调用后，仅检查返回值是否等于0（完全失败），而未检查是否等于期望读取的元素个数（100-1），导致部分读取时无法被检测，后续使用data时可能使用未完全填充或未初始化的缓冲区，违反CWE-253规则。
- D验证: stage_c_preserved / ver_9afabd0d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 903. hyp_path_5eb672802055

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_13.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin输入流，使得fread读取的数据量少于100-1个元素。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_13.c:35
- 结论: 对fread的返回值检查不正确：仅检查返回值是否为0，而未检查是否等于期望读取的个数（100-1）。fread可能部分读取成功（例如返回值在1到98之间），此时程序会误认为数据完全读取成功，从而使用未完全填充的缓冲区，可能导致后续处理使用未初始化或部分覆盖的数据。
- D验证: stage_c_preserved / ver_45c96bad
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 904. hyp_path_e2cee57d4e39

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_14.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使fread读取部分数据（如提前结束或错误）
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_14.c:35
- 结论: fread返回值检查不完整：仅检查返回值是否为0，忽略了返回值小于预期但大于0的情况，可能导致使用部分读取的数据或未初始化数据。
- D验证: stage_c_preserved / ver_dabbaf2b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 905. hyp_path_df868af44944

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_15.c:36
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制 stdin 输入，使得 fread 读取部分数据（例如提前遇到 EOF 或 I/O 错误但返回非零值）
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_15.c:36
- 结论: 函数 fread 的返回值检查不完整：仅检查返回值是否为 0，忽略了部分读取（返回值>0但小于请求数）的情况，违反了 CWE-253（不正确的函数返回值检查）。尽管当前代码中 fread 后未立即使用 data 缓冲区，但存在未来代码演进或不同编译路径下可能引入后续使用，导致未初始化或部分更新的数据被错误使用的潜在风险。
- D验证: stage_c_preserved / ver_0775fa3b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 906. hyp_path_104410b23284

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_16.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供部分数据，使fread返回值小于100-1但大于0。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0) @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_16.c:35
- 结论: fread的返回值检查不完整：只检查返回值是否等于0，未检查是否等于请求的读取数量（100-1）。当fread返回介于1到98之间的值时，代码不会进入错误处理分支，后续使用未完全填充的data缓冲区可能导致未初始化数据被使用，违反CWE-253。
- D验证: stage_c_preserved / ver_34fe286f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 907. hyp_path_fac7922e0754

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_15.c:90
- 漏洞类型: CWE-253, CWE-170
- CWE: CWE-253; CWE-170
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供数据，导致 fread 返回小于请求大小的正数（部分读取）
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ L90
- 结论: fread 返回值检查不充分：仅检查是否完全等于请求的大小，未处理部分读取（返回值在0到请求大小之间）的情况，可能导致使用部分填充的缓冲区，造成数据未初始化或信息泄露。
- D验证: stage_c_preserved / ver_a1d12689
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 908. hyp_path_b37d70b16335

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_18.c:35
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使得fread返回部分成功（例如读取部分数据后中断）。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_18.c:35
- 结论: fread返回值检查不完整：仅检查返回值是否等于0（完全失败），而未处理部分读取（返回值小于请求数但非0）的情况。虽然代码片段中未显示后续使用未完全填充的缓冲区，但API contract violation（CWE-253）确实存在，可能导致潜在的数据损坏或未初始化数据使用，需动态验证后续路径。
- D验证: stage_c_preserved / ver_c8dadc80
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 909. hyp_path_fc69735754bf

- 漏洞位置: juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_16.c:59
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使得fread返回值不等于99（如提前关闭输入、提供少于99个字符等）。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ L59-61
- 结论: fread返回值检查不正确：代码检查fread的返回值是否等于请求读取的元素数（99），但fread成功时可能返回小于请求数的值（如部分读取或文件结束），此时代码错误地认为失败；同时，如果返回值等于99，代码认为成功，但未区分错误情况（如ferror），且未处理部分读取的情况。这违反了CWE-253（Incorrect Check of Function Return Value）。但代码片段中没有后续使用dataBuffer的操作，因此该违反不直接导致信息泄露或代码执行等安全风险，仅构成API misuse。
- D验证: stage_c_preserved / ver_1d485b4b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

## Unconfirmed / Failed Verification

These records are not reported as confirmed vulnerabilities. See `verification.failed.jsonl` for full failure details.

- hyp_path_769a11a93ec5 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_17.c:94 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_4de8caaf54fc | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_17.c:94 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_1ca3bf0e5621 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_12.c:148 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_4e323b5032e2 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_05.c:103 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_8d480b41e65c | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_08.c:143 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_c0f73607d84e | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_09.c:97 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_04f31755690c | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_07.c:102 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_883c95ba1f91 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_08.c:143 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_e5f7edd93282 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_09.c:97 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_ceb80742e4d7 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_10.c:97 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_718dbeb7bb69 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_01.c:86 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_985a170a614f | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_02.c:97 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_d0b1a55030d3 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_02.c:130 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_6a0e2bde6eb8 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_04.c:136 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_e78a1c13840e | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_06.c:135 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_f14eaf644ab6 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_10.c:130 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_f0927153ec60 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_18.c:91 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_6f84fb60fea9 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_02.c:97 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_deb0e2dbb46d | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_02.c:130 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_df8f2d47a90c | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_03.c:130 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_79d1d53021fb | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_04.c:136 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_a13939e12d00 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_05.c:136 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_2a389798c489 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_04.c:103 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_6de75bb3bab8 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_06.c:135 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_bb55a43b3488 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_07.c:135 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_408b6294f067 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_13.c:130 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_3bf9d964b2c9 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_17.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c6805b17282e | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_17.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e361fcb04bd2 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_12.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ff04d4c49bc0 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_17.c:95 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_e0bfe4be36be | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_12.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_26777b45b2b8 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_12.c:149 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_90ecfbfa75f8 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_12.c:149 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_440475b48e40 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_11.c:98 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_846bbe519ae9 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_08.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_25241ae055b0 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_07.c:103 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_ec0eb9470ce1 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_11.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_086a2a281b15 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_05.c:104 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_0b270fd94078 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_13.c:98 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_f1efedf8e517 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_08.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_11b164b586bc | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_11.c:131 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_dc113216b6b0 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_01.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1bb39e2a7807 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_11.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1b762b437ac8 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_14.c:98 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_4ccb49d14fe0 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_13.c:98 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_8111792ded47 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_02.c:98 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_417de99a601e | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_02.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a606243d145e | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_03.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_998cbe236c67 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_04.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8c3f598fb6ad | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_06.c:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_35fcc40cfa3b | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_05.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a076d31657f7 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_05.c:137 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_6d7c739f3539 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_07.c:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4e923e887f33 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_10.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e3b8beb0cdcd | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_07.c:136 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_c01df4387782 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_09.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_755e138aca83 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_13.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7d8f538f5c78 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_13.c:131 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_57b36e270541 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_14.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_15231c4474da | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_15.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8c42f0d47df5 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_14.c:131 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_e996d36ce66f | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_16.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ddd4aee8091e | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_18.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7ef24fdd1d78 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_01.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_43c56f704ec4 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_18.c:92 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_17c57cf7d2dc | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_02.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a479dbac66b8 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_03.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_490cb0309eba | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_04.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0925b3b78a6a | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_05.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f83dbed7edb8 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_06.c:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_72fef4f3706b | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_07.c:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_557e3b0f67c6 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_09.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a6df49bbd240 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_10.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_105bd78e3b44 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_13.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0d1eb4ebabdb | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_14.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_baba7f489fcc | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_15.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ff8c6dc609fe | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_16.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d4cfa1ad7cd9 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_18.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6e63317014a9 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_12.c:81 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_ce7390baa906 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_11.c:71 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_ed5c8c32e967 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_10.c:71 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_48a89d69a4ad | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_14.c:71 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_6fae00483edb | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_05.c:97 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_b62e9a03ca39 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_02.c:91 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_be14fb7b3d53 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_15.c:99 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_cc1ffa6d84c4 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_16.c:67 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_d4e63e7f354b | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_13.c:63 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_8900610f016e | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_05.c:82 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_84c849337899 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_17.c:30 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_e94dc251f993 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_17.c:68 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_27ca3e3389cf | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_12.c:37 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_04ae05ff79fc | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_12.c:62 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_dfeba1c15756 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_12.c:52 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_60a407d443e4 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_12.c:74 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_d26b38756ecc | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_08.c:84 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_3f6a8b250560 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_11.c:52 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_27f21bef5648 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_08.c:71 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_eb9cf6d51193 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_14.c:63 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_86c8854595c6 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_09.c:63 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_d6c92139c26f | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_14.c:63 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_45619f0077ec | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_08.c:95 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_fb57b6531b1d | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_07.c:70 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_9e5cd6bba53b | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_13.c:65 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_17e9afa7161f | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_08.c:38 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_6b487362d364 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_11.c:25 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_12ad5ddac9af | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_11.c:74 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_fe9117b9cdf7 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_07.c:57 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_abd6f7e365a0 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_01.c:52 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_02e6c5a2c922 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_02.c:63 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_50e15912ad47 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_03.c:63 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_543a3c7cf6e8 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_06.c:87 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_ba7a857a186c | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_14.c:82 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_ff5f1c5f4a99 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_16.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_25919bdd77f4 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_06.c:70 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_d5eedb89231d | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_15.c:73 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_51713950817a | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_04.c:99 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_979baef8a3d3 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_06.c:87 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_14afcc145daf | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_scanf_13.c:92 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_627d5497da5f | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_01.c:60 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_9a8f131802f5 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_03.c:90 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_3e5ac5edb05c | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_05.c:106 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_4bf3185113c0 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_06.c:106 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_7065d15340cd | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_13.c:90 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_4f8a0863b442 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_02.c:95 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_2d184f2c81bc | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_09.c:95 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_35961dc73e50 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_16.c:61 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_93237af0096b | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_08.c:151 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_0936b0bc7b4c | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_09.c:137 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_2776a89df460 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_11.c:138 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_e4e1a15b027e | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_01.c:27 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_a8efa335ae41 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_02.c:29 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_3f0679ba2a73 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_03.c:29 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_c4ab1f108eab | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_04.c:35 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_52ec7c71154a | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_05.c:35 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_416b47298e27 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_06.c:34 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_1a45ddceee57 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_07.c:34 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_ee4570c86bd7 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_09.c:29 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_e56d2b7d3e01 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_10.c:29 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_7acd73c5a053 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_13.c:29 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_cf8c13cc509d | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_14.c:29 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_c0784d329847 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_15.c:30 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_78c1b58721cc | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_16.c:29 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_89e729ecdb9b | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_18.c:29 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_20f64151a645 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_05.c:71 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_281d59a3e617 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_03.c:82 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_0f427b8dd550 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_05.c:88 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_9bf8554bc345 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_10.c:82 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_71f63ab3725f | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fscanf_14.c:92 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_941866a5ba67 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fwrite_06.c:57 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_684dcc09f956 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_03.c:58 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_517632e90f3a | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_puts_14.c:71 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_73869cb6b707 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_04.c:64 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_84f179224a3a | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_15.c:69 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_9bbe49317df2 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_13.c:92 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_ec9ec16fad20 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_18.c:57 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_0d22d0c677d9 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_03.c:71 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_7ae847746845 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_04.c:96 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_02bdb7697498 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_09.c:101 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_5fdfae9abfec | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_01.c:35 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_28ec956b9213 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_16.c:67 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_420e6999e474 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_02.c:94 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_91c4fb7192a5 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_03.c:84 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_69a00dc5585a | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_sscanf_05.c:90 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_62f8b7fc61a5 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_02.c:138 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_3f91fa659421 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_09.c:137 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_aeef5a0accec | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_10.c:137 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_cda91930cdbb | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_01.c:63 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_df8f6426bef5 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_16.c:78 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_0467fa691fb0 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_12.c:155 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_6b814dd4c728 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateNamedPipe_18.c:97 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_80dfc9c5ea8b | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_scanf_16.c:70 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_e35c2c79db01 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_snprintf_01.c:69 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_1bf8e83c2e22 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_18.c:97 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_49a6ade16ef2 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_16.c:101 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_2fea3f31f983 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateNamedPipe_01.c:92 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_0159e693bd8b | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/main_linux.cpp:604 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_00260922ade1 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/main.cpp:3894 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_399c2a468812 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_16.c:102 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_5ec7c4099075 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_09.c:63 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_c230124f67b2 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_02.c:82 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_6ce90c3c4eb2 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_14.c:63 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_40e9a8bdd179 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_02.c:63 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_08a0ff96d877 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_04.c:69 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_daa81597bc20 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_13.c:82 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_deba2404dfb8 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__char_fread_15.c:69 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_9c04498fda52 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_03.c:82 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_2378877bf807 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_05.c:88 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_743f45dceae4 | juliet-api-misuse/testcases/CWE253_Incorrect_Check_of_Function_Return_Value/CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_15.c:69 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
