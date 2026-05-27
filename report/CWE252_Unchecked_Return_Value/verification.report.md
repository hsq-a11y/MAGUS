# MAGUS Final Vulnerability Report

- generated_at: 2026-05-25T18:53:36Z
- reportable_vulnerabilities: 809
- d_confirmed_vulnerabilities: 71
- stage_c_preserved_vulnerabilities: 738
- failed_verifications: 194
- source_confirmed: /home/sq_hu/MAGUS/d/memberD_verifier/02_run_with_C/output/CWE252_Unchecked_Return_Value/verification.jsonl
- source_failed: /home/sq_hu/MAGUS/d/memberD_verifier/02_run_with_C/output/CWE252_Unchecked_Return_Value/verification.failed.jsonl

## Confirmed Vulnerabilities

### 1. hyp_path_f0a90b634bda

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_17.c:51
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 程序运行环境可能因资源不足导致CreateNamedPipeA失败
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; BOOL fConnected = FALSE; hPipe = CreateNamedPipeA( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_17.c:34-38; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_17.c:46-50; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_17.c:49-53
- 结论: 在CreateNamedPipeA调用后未检查返回值。若函数失败返回INVALID_HANDLE_VALUE，后续ConnectNamedPipe和CloseHandle操作可能对无效句柄执行，导致未定义行为或资源泄露。
- D验证: confirmed / ver_2821c13e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 2. hyp_path_3850a5180d4c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_17.c:51
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeW调用因权限不足、命名管道已存在或其他原因失败。
- 触发路径: hPipe = CreateNamedPipeW( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ... ); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_17.c:34-38; fConnected = ConnectNamedPipe(hPipe, NULL) ... ; @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_17.c:46-50; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_17.c:49-53
- 结论: CreateNamedPipeW的返回值未被检查，如果管道创建失败，后续使用无效句柄调用ConnectNamedPipe和CloseHandle可能导致未定义行为或资源泄露。
- D验证: confirmed / ver_46b7b705
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 3. hyp_path_bc2d43c99df8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_12.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 程序执行到ConnectNamedPipe调用处，且管道连接可能失败。
- 触发路径: exit(1); } fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); /* We'll leave out most of the implementation since it has nothing to do with the CWE */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_12.c:73-77; /* ... */ CloseHandle(hPipe); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_12.c:48-52
- 结论: 函数ConnectNamedPipe的返回值被检查并存储到fConnected，但后续未使用该变量，导致未正确处理管道连接失败的情况，违反CWE-252要求，存在未检查返回值漏洞。
- D验证: confirmed / ver_623fdeca
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 4. hyp_path_72dc700dd266

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_08.c:63
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeA可能因系统资源不足、管道名称冲突等原因失败，攻击者无法直接控制，但存在潜在风险。
- 触发路径: hPipe = CreateNamedPipeA(pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_08.c:63; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_08.c:63; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_08.c:63
- 结论: 未检查CreateNamedPipeA的返回值，如果函数失败返回INVALID_HANDLE_VALUE，后续ConnectNamedPipe和CloseHandle将使用无效句柄，可能导致未定义行为或资源错误。
- D验证: confirmed / ver_508fc043
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 5. hyp_path_3896704b8014

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_11.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者需要能够影响系统资源（如内存、管道名称）导致CreateNamedPipeA或ConnectNamedPipe失败。
- 触发路径: hPipe = CreateNamedPipeA( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_11.c:50; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_11.c:50; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_11.c:50
- 结论: 未检查CreateNamedPipeA和ConnectNamedPipe的返回值，可能导致后续操作使用无效句柄，违反API contract。
- D验证: confirmed / ver_c9b8f3b5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 6. hyp_path_ac4651c7c92b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_08.c:63
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够通过创建同名管道或耗尽系统资源等方式使CreateNamedPipeW调用失败。
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeW(...); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_08.c:46-50; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_08.c:58-62; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_08.c:63
- 结论: CreateNamedPipeW的返回值未被检查，若调用失败则hPipe为INVALID_HANDLE_VALUE，后续ConnectNamedPipe和CloseHandle使用无效句柄可能导致未定义行为或资源泄漏。
- D验证: confirmed / ver_bb001564
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 7. hyp_path_d914dd2cd2c7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_11.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者无法直接控制管道创建结果，但可通过系统资源耗尽或权限限制使 CreateNamedPipeW 失败
- 触发路径: hPipe = CreateNamedPipeW(pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_11.c:36; CloseHandle(hPipe); // 使用未检查的 hPipe @ CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_11.c:50
- 结论: 未检查 CreateNamedPipeW 的返回值，若管道创建失败（返回 INVALID_HANDLE_VALUE），后续 CloseHandle 调用将使用无效句柄，可能导致未定义行为或资源错误。
- D验证: confirmed / ver_821ce37a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 8. hyp_path_7ae34ecb10b5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_01.c:48
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeA 因竞争条件、权限不足或其他原因失败
- 触发路径: hPipe = CreateNamedPipeA(pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ... NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_01.c:48
- 结论: 调用 CreateNamedPipeA 后未检查返回值，若函数失败返回 INVALID_HANDLE_VALUE，后续使用该句柄可能导致未定义行为。
- D验证: confirmed / ver_f2d1742b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 9. hyp_path_0a55dd2a42d3

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_02.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeA调用失败，例如由于系统资源不足或名称冲突
- 触发路径: hPipe = CreateNamedPipeA( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ... NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_02.c:35; /* NOTE: Do not check the return value */ fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_02.c:45-47
- 结论: CreateNamedPipeA的返回值未检查，若调用失败则后续ConnectNamedPipe使用无效句柄，违反CWE-252（未检查返回值）。
- D验证: confirmed / ver_0844da49
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 10. hyp_path_55d2aeab1283

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_05.c:56
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者可能通过影响系统资源或管道名称使CreateNamedPipeA失败，但具体可控性较低
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; hPipe = CreateNamedPipeA(pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); /* NOTE: Do not check the return value */ @ 39-43; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); // 使用可能无效的hPipe @ 51-55; CloseHandle(hPipe); // 关闭可能无效的句柄 @ 56-60
- 结论: 未检查CreateNamedPipeA的返回值，若函数失败则hPipe为INVALID_HANDLE_VALUE，后续ConnectNamedPipe和CloseHandle操作在无效句柄上可能导致未定义行为或拒绝服务。
- D验证: confirmed / ver_ea490f01
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 11. hyp_path_8269fc65d3a9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_03.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeA调用失败（例如命名管道已存在或权限不足）
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeA(pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ... NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_03.c:33-37; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_03.c:45-49
- 结论: 对CreateNamedPipeA的返回值未作检查，违反了API契约。如果CreateNamedPipeA失败（返回INVALID_HANDLE_VALUE），后续对无效句柄的ConnectNamedPipe调用可能导致异常行为。
- D验证: confirmed / ver_53dbeea4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 12. hyp_path_f3c44e30ac31

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_04.c:56
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeA可能因资源不足或权限问题失败，返回INVALID_HANDLE_VALUE。
- 触发路径: hPipe = CreateNamedPipeA( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ... NULL); @ L43; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ L51-55; CloseHandle(hPipe); @ L56
- 结论: CreateNamedPipeA返回值未检查，可能使用无效句柄调用ConnectNamedPipe和CloseHandle，违反CWE-252。
- D验证: confirmed / ver_c4970b57
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 13. hyp_path_9130273a3e4c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_06.c:55
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeA函数执行失败，可能由于系统资源不足或参数错误。
- 触发路径: hPipe = CreateNamedPipeA( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ... NULL); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_06.c:55; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); // hPipe可能为INVALID_HANDLE_VALUE @ 同一文件:55; CloseHandle(hPipe); // 关闭无效句柄 @ 同一文件:57
- 结论: 在CreateNamedPipeA调用后未检查返回值，如果函数失败返回INVALID_HANDLE_VALUE，后续的ConnectNamedPipe调用将操作无效句柄，可能产生逻辑错误或意外行为。
- D验证: confirmed / ver_137695f2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 14. hyp_path_10abbabb0b5f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_07.c:55
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeA 由于资源不足、权限不足或其他原因失败
- 触发路径: hPipe = CreateNamedPipeA(...); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_07.c:38-42; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_07.c:51-53; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_07.c:55
- 结论: CreateNamedPipeA 的返回值未被检查，若调用失败则返回 INVALID_HANDLE_VALUE，随后在无效句柄上调用 ConnectNamedPipe 和 CloseHandle，可能导致未定义行为或资源泄漏。
- D验证: confirmed / ver_327d0369
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 15. hyp_path_4d4a7596e604

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_10.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者可能通过耗尽系统资源或竞争条件导致 CreateNamedPipeA 失败，但无需直接控制输入参数
- 触发路径: NULL); /* NOTE: Do not check the return value */ fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_10.c:45-47; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_10.c:50-52
- 结论: 调用 CreateNamedPipeA 后未检查返回值，违反 CWE-252（未检查返回值），可能导致在管道创建失败的情况下继续使用无效句柄，进而引发后续 ConnectNamedPipe 和 CloseHandle 操作在无效句柄上执行，造成未定义行为或资源泄露。
- D验证: confirmed / ver_9c38e4e3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 16. hyp_path_054850cd50f2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_13.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeA调用失败返回INVALID_HANDLE_VALUE
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeA(...); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_13.c:33-37; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_13.c:45-49; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_13.c:50
- 结论: 在创建命名管道时未检查CreateNamedPipeA的返回值，可能导致后续使用无效句柄操作，违反CWE-252未检查返回值。
- D验证: confirmed / ver_7b2050e9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 17. hyp_path_f3974e3260be

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_09.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeA可能因资源不足或参数错误失败返回INVALID_HANDLE_VALUE，攻击者无法直接控制但系统状态可影响。
- 触发路径: hPipe = CreateNamedPipeA(...) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_09.c:44; /* NOTE: Do not check the return value */ @ 同一文件第46行; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ 同一文件第47行
- 结论: CreateNamedPipeA的返回值未检查，可能返回INVALID_HANDLE_VALUE，直接用于ConnectNamedPipe和CloseHandle，违反CWE-252契约。
- D验证: confirmed / ver_c7a6b289
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 18. hyp_path_827b443827b9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_14.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者可能通过环境因素导致CreateNamedPipeA调用失败，例如管道名称冲突或系统资源不足
- 触发路径: NULL); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_14.c:45; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_14.c:48
- 结论: 代码中CreateNamedPipeA的返回值未被检查，随后直接传递给ConnectNamedPipe和CloseHandle，如果CreateNamedPipeA失败（返回INVALID_HANDLE_VALUE），则后续操作可能导致未定义行为或资源泄露，违反CWE-252未检查返回值。
- D验证: confirmed / ver_01e6bf44
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 19. hyp_path_ee0765d3b821

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_15.c:51
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeA因权限不足、管道名冲突或其他系统错误而失败。
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; BOOL fConnected = FALSE; hPipe = CreateNamedPipeA( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_15.c:34-38; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ same file: line 48; CloseHandle(hPipe); @ same file: line 51
- 结论: 函数CreateNamedPipeA的返回值未被检查，若调用失败则hPipe为INVALID_HANDLE_VALUE，后续ConnectNamedPipe和CloseHandle使用无效句柄，违反CWE-252，可能导致程序异常或资源泄露。
- D验证: confirmed / ver_7c0b2d99
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 20. hyp_path_fa2725ff9c3c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_16.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeA因环境因素失败（如管道名称无效、系统资源不足），无需攻击者直接输入控制
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeA(pipeName, ...); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_16.c:33-37; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_16.c:45-49; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_16.c:48-52
- 结论: 未检查CreateNamedPipeA返回值，若函数失败则hPipe为INVALID_HANDLE_VALUE，后续ConnectNamedPipe和CloseHandle在无效句柄上操作，导致未定义行为。
- D验证: confirmed / ver_834ce881
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 21. hyp_path_8db831139a56

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_18.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeA调用失败（如命名管道已存在或权限不足）
- 触发路径: hPipe = CreateNamedPipeA(pipeName, ...); // 返回值未检查 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_18.c:50; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); // 使用可能无效的hPipe @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_18.c:50; CloseHandle(hPipe); // 关闭可能无效的句柄 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_18.c:50
- 结论: CreateNamedPipeA的返回值未被检查，如果调用失败返回INVALID_HANDLE_VALUE，后续ConnectNamedPipe和CloseHandle将使用无效句柄，可能导致程序异常行为或拒绝服务。
- D验证: confirmed / ver_b94cc604
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 22. hyp_path_0f8dfa6b408b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_02.c:50
- 漏洞类型: CWE-252, CWE-703
- CWE: CWE-252; CWE-703
- 风险等级: P0
- 触发条件: CreateNamedPipeW调用失败（如系统资源不足）
- 触发路径: hPipe = CreateNamedPipeW(pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_02.c:36; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_02.c:45; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_02.c:50
- 结论: CreateNamedPipeW的返回值未检查，若调用失败则返回INVALID_HANDLE_VALUE，后续ConnectNamedPipe和CloseHandle将使用无效句柄，导致未定义行为或资源泄漏。
- D验证: confirmed / ver_ef2587e9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 23. hyp_path_6d2963f10dfe

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_01.c:48
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeW失败（例如管道名称冲突或系统资源不足）导致返回INVALID_HANDLE_VALUE。
- 触发路径: hPipe = CreateNamedPipeW(pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_01.c:43; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_01.c:44; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_01.c:48
- 结论: 函数CreateNamedPipeW的返回值未被检查，导致后续ConnectNamedPipe和CloseHandle使用可能无效的句柄，且CloseHandle的返回值也未被检查，违反CWE-252（未检查返回值）。
- D验证: confirmed / ver_55b84931
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 24. hyp_path_1048cd692e09

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_04.c:56
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeW因资源不足、权限不足或其他原因失败时，hPipe为INVALID_HANDLE_VALUE。
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeW( pipeName, ...); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_04.c:41-43; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_04.c:52-53; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_04.c:55-56
- 结论: 未检查CreateNamedPipeW的返回值，如果管道创建失败，后续的ConnectNamedPipe和CloseHandle可能在无效句柄上操作，导致未定义行为或资源泄漏。
- D验证: confirmed / ver_c5cf264e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 25. hyp_path_5abbbb3d1715

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_03.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 无外部可控输入，但内部错误（如管道创建失败或句柄无效）可触发未定义行为或资源泄漏。
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeW(...); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_03.c:33-37; CloseHandle(hPipe); /* return value not checked */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_03.c:48-52
- 结论: CreateNamedPipeW和CloseHandle的返回值未检查，可能导致在管道创建失败时使用无效句柄，或在关闭句柄时忽略错误，引发未定义行为或资源泄漏。
- D验证: confirmed / ver_fd893a4b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 26. hyp_path_f417ec881f78

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_06.c:55
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 不需要攻击者控制输入；CreateNamedPipeW因系统资源不足等原因可能失败
- 触发路径: hPipe = CreateNamedPipeW(pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_06.c:55; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_06.c:52; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_06.c:55
- 结论: 调用CreateNamedPipeW后未检查返回值，若函数失败返回INVALID_HANDLE_VALUE，后续使用该无效句柄进行ConnectNamedPipe和CloseHandle可能导致未定义行为或资源泄露。
- D验证: confirmed / ver_e21ce31e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 27. hyp_path_7d98b9e3e2e8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_09.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeW调用因某种原因失败（如管道名称冲突、权限不足等）。
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeW(...); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_09.c:33; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_09.c:45; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_09.c:50
- 结论: 未检查CreateNamedPipeW的返回值，若函数失败，后续操作可能使用无效句柄，违反CWE-252（未检查返回值）。
- D验证: confirmed / ver_771183bb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 28. hyp_path_6690cc151378

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_07.c:55
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeW可能因系统资源不足或管道名称冲突而失败，但无需外部攻击者输入控制
- 触发路径: hPipe = CreateNamedPipeW( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ... NULL); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_07.c:55; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_07.c:55; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_07.c:55
- 结论: 未检查CreateNamedPipeW的返回值，如果该函数失败返回INVALID_HANDLE_VALUE，后续对无效句柄调用ConnectNamedPipe和CloseHandle可能导致未定义行为或资源泄露。
- D验证: confirmed / ver_2cf26382
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 29. hyp_path_43d410e96345

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_05.c:56
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够影响系统资源状态导致CreateNamedPipeW失败（如耗尽内存或管道实例数上限）
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeW( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ...); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_05.c:39-43; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_05.c:51-55; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_05.c:54-58
- 结论: 未检查CreateNamedPipeW的返回值，当函数失败返回INVALID_HANDLE_VALUE时，后续对ConnectNamedPipe和CloseHandle的调用使用了无效句柄，可能导致未定义行为或资源泄漏。
- D验证: confirmed / ver_7a2eb938
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 30. hyp_path_9a814fe807b8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_10.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 服务端程序运行，但管道创建条件不满足导致CreateNamedPipeW失败（如已达最大实例数）
- 触发路径: hPipe = CreateNamedPipeW(...); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_10.c:48; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_10.c:49; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_10.c:50
- 结论: 未检查CreateNamedPipeW的返回值，如果函数失败返回INVALID_HANDLE_VALUE，后续ConnectNamedPipe和CloseHandle将使用无效句柄，可能导致未定义行为或拒绝服务。
- D验证: confirmed / ver_da92e784
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 31. hyp_path_1b3f45bb0814

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_14.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者可能通过影响系统资源（如管道名称冲突、权限不足等）使 CreateNamedPipeW 失败
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeW( pipeName, FILE_FLAG_FIRST_PIPE_INSTANCE, ... ); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_14.c:33-37; /* NOTE: Do not check the return value */ fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_14.c:45-49
- 结论: CreateNamedPipeW 的返回值未被检查，若函数失败返回 INVALID_HANDLE_VALUE，后续调用 ConnectNamedPipe 将使用无效句柄，可能导致未定义行为或程序异常。违反了 CWE-252（未检查返回值）。
- D验证: confirmed / ver_cb9712de
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 32. hyp_path_e8d12a9c7869

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_13.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeW因资源不足或其他原因失败返回INVALID_HANDLE_VALUE
- 触发路径: hPipe = CreateNamedPipeW(pipeName, ...); @ CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_13.c:35; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_13.c:45
- 结论: CreateNamedPipeW的返回值未被检查，如果函数失败返回INVALID_HANDLE_VALUE，后续的ConnectNamedPipe将使用无效句柄，导致未定义行为或进程崩溃，违反了CWE-252未检查返回值。
- D验证: confirmed / ver_c4dd44cb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 33. hyp_path_a9378d529cdd

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_15.c:51
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 无特殊前提，正常执行即可触发未检查返回值。
- 触发路径: hPipe = CreateNamedPipeW(pipeName, ...); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_15.c:46; ConnectNamedPipe(hPipe, NULL) 以及后续 CloseHandle(hPipe) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_15.c:46
- 结论: 调用CreateNamedPipeW后返回值未检查，可能返回INVALID_HANDLE_VALUE，导致后续ConnectNamedPipe和CloseHandle使用无效句柄，违反CWE-252。
- D验证: confirmed / ver_6f865f26
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 34. hyp_path_3c9cf19c5758

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_18.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 系统调用可能因资源不足等原因失败，无需攻击者控制输入
- 触发路径: HANDLE hPipe = INVALID_HANDLE_VALUE; ... hPipe = CreateNamedPipeW(...); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_18.c:35-36; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_18.c:45-46; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_18.c:50
- 结论: 调用CreateNamedPipeW后未检查返回值，直接使用可能无效的管道句柄调用ConnectNamedPipe和CloseHandle，导致未定义行为或资源泄漏。违反CWE-252（未检查返回值）。
- D验证: confirmed / ver_55bf7352
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 35. hyp_path_4c3c173364d1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_16.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateNamedPipeW可能因资源不足或权限失败而返回INVALID_HANDLE_VALUE
- 触发路径: hPipe = CreateNamedPipeW(...); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_16.c:49; fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_16.c:49; CloseHandle(hPipe); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_16.c:50
- 结论: 未检查CreateNamedPipeW的返回值，后续使用可能无效的句柄hPipe调用ConnectNamedPipe和CloseHandle，违反API contract，可能导致未定义行为或资源泄漏。
- D验证: confirmed / ver_4456a676
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 36. hyp_path_1d415eb4bace

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_17.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够导致输入流结束或发生错误（如关闭stdin）
- 触发路径: fgets(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_17.c:36
- 结论: 未检查fgets返回值，违反API contract，可能导致使用未正确初始化的缓冲区或忽略错误条件。
- D验证: stage_c_preserved / ver_ce82e078
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 37. hyp_path_d57008d119e7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_12.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可以通过控制标准输入使fgets失败（如提前关闭输入流）
- 触发路径: void CWE252_Unchecked_Return_Value__char_fgets_12_case0() { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_12.c:24; if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_12.c:25; printLine("Please enter a string: "); /* NOTE: Do not check the return value */ fgets(data, 100, stdin); printLine(data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_12.c:33-36
- 结论: 未检查fgets返回值，当fgets失败时data缓冲区可能未正确初始化，后续printLine(data)可能输出未定义内容或导致信息泄露。
- D验证: stage_c_preserved / ver_68f5a51f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 38. hyp_path_5cf537b4ce95

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_08.c:48
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制输入流关闭或导致fgets失败（如EOF）
- 触发路径: fgets(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_08.c:48
- 结论: 函数fgets的返回值未被检查，违反了API contract（CWE-252），可能导致后续操作使用未正确初始化的数据，尽管data已初始化为空字符串，影响较低。
- D验证: stage_c_preserved / ver_65819b4d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 39. hyp_path_6aad80687b6b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_01.c:33
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够使fgets调用失败（例如，通过关闭标准输入或触发EOF）。
- 触发路径: fgets(data, 100, stdin); @ CWE252_Unchecked_Return_Value__char_fgets_01.c:33
- 结论: fgets函数返回值未检查，违反CWE-252未检查返回值，尽管data已初始化为空字符串且printLine(data)无直接危害，但API误用成立。
- D验证: stage_c_preserved / ver_25bdf231
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 40. hyp_path_d8a06003c566

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_11.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdin读取失败（如输入重定向结束或错误）导致fgets返回NULL。
- 触发路径: fgets(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_11.c:35
- 结论: 未检查fgets返回值，违反CWE-252，可能导致程序忽略输入错误（如EOF或读取失败），后续使用未充分验证的数据。
- D验证: stage_c_preserved / ver_7f9b81b0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 41. hyp_path_5fa270b7ad8b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_02.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin的状态（例如关闭输入流或发送EOF信号）
- 触发路径: fgets(data, 100, stdin); // 返回值未检查 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_02.c:35; printLine(data); // 使用可能未初始化的data（实际为空） @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_02.c:36
- 结论: fgets返回值未检查，违反CWE-252 API契约；尽管data初始化为空，但fgets失败时data未被修改，printLine可能打印空字符串，实际安全风险极低，但违反契约成立。
- D验证: stage_c_preserved / ver_e228507b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 42. hyp_path_d8b304f8964f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_03.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够导致stdin出现错误或触发EOF，使fgets返回NULL。
- 触发路径: fgets(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_03.c:35; printLine(data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_03.c:36
- 结论: 未检查fgets返回值，违反CWE-252，可能导致程序在fgets失败时使用未初始化的数据或产生未定义行为。
- D验证: stage_c_preserved / ver_8b79fea0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 43. hyp_path_6f2cfba04963

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_04.c:41
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够导致stdin读取失败（如关闭输入流）
- 触发路径: fgets(data, 100, stdin); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_04.c:41; printLine(data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_04.c:42
- 结论: fgets返回值未检查，违反CWE-252 API contract。尽管缓冲区已初始化为空字符串，但未检查返回值可能导致无法检测读取失败，后续使用可能产生未预期的空字符串数据，造成逻辑错误。
- D验证: stage_c_preserved / ver_baa469e1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 44. hyp_path_1c4ec764592d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_07.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: Standard input (stdin) may fail or return EOF.
- 触发路径: fgets(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_07.c:40
- 结论: CWE252: Unchecked Return Value - fgets() return value is not checked, which violates API contract by ignoring potential failure.
- D验证: stage_c_preserved / ver_a40fa6af
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 45. hyp_path_d4ff554a9a59

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_05.c:41
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者无法直接控制 fgets 失败，但可以通过关闭标准输入或提供无效输入（如 EOF）间接触发返回值 NULL
- 触发路径: fgets(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_05.c:41
- 结论: 未检查 fgets 返回值，违反 CWE-252，可能导致程序在 fgets 失败时使用未初始化或未更改的缓冲数据
- D验证: stage_c_preserved / ver_057082db
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 46. hyp_path_3918b4cb2637

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_06.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够导致stdin输入流错误或EOF，使fgets返回NULL。
- 触发路径: fgets(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_06.c:40; printLine(data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_06.c:41
- 结论: 未检查fgets()返回值，违反CWE-252，虽然缓冲区初始化为空字符串降低直接影响，但仍可能导致程序行为与预期不符，存在潜在安全风险。
- D验证: stage_c_preserved / ver_ad9d2ea8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 47. hyp_path_b970fac6d5f1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_09.c:35
- 漏洞类型: null_deref
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者无法直接控制输入，但可通过关闭stdin或导致读取错误（如EOF）使fgets返回NULL，从而触发未定义行为。
- 触发路径: fgets(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_09.c:35; printLine(data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_09.c:36
- 结论: fgets返回值未被检查，违反CWE-252（未检查返回值），当fgets失败返回NULL时，后续printLine(data)会导致解引用空指针，引发未定义行为或程序崩溃。
- D验证: stage_c_preserved / ver_4201eb18
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 48. hyp_path_6133038dc45b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_13.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够使stdin读取失败（例如提前关闭输入流或发送EOF）
- 触发路径: fgets(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_13.c:35
- 结论: 未检查fgets返回值，可能导致使用无效数据或逻辑错误
- D验证: stage_c_preserved / ver_3cb4bceb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 49. hyp_path_3efee1f6a7f0

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_14.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够使stdin进入EOF或读取错误状态
- 触发路径: fgets(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_14.c:35; printLine(data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_14.c:36
- 结论: 函数fgets的返回值未被检查，违反了CWE-252（未检查返回值）。尽管data缓冲区已初始化为空字符串，fgets失败时不会导致未定义数据，但API契约被违反，可能导致逻辑错误或未处理错误状态。
- D验证: stage_c_preserved / ver_0e78a2ef
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 50. hyp_path_a83d721c1d20

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_15.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可通过提供EOF或使流错误导致fgets返回NULL
- 触发路径: printLine("Please enter a string: "); /* NOTE: Do not check the return value */ fgets(data, 100, stdin); @ 34-36
- 结论: fgets返回值未检查，违反API契约，可能在使用非预期数据时导致未定义行为
- D验证: stage_c_preserved / ver_5cca5fc2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 51. hyp_path_2ae7a37c1e36

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_10.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可以通过关闭stdin或提供EOF使fgets失败，触发未定义行为
- 触发路径: fgets(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_10.c:35; printLine(data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_10.c:36
- 结论: 未检查fgets返回值，违反CWE-252。如果fgets失败，data内容未定义，可能导致printLine输出未初始化数据（信息泄露或未定义行为）。
- D验证: stage_c_preserved / ver_92a6f805
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 52. hyp_path_7277b322501c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_16.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin发送EOF或其他错误使fgets返回NULL
- 触发路径: printLine("Please enter a string: "); /* NOTE: Do not check the return value */ fgets(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_16.c:33-35; printLine(data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_16.c:36
- 结论: 在函数调用fgets后未检查返回值（CWE-252）。fgets可能返回NULL表示错误或EOF，但代码未做检查。虽然data指向已初始化的栈数组，fgets失败后dataBuffer内容保持空字符串，printLine(data)不会导致未定义行为，但违反了API contract，存在潜在的后续处理风险（如错误信息泄露或逻辑错误）。
- D验证: stage_c_preserved / ver_074c0362
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 53. hyp_path_da82a146c4f3

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_18.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 标准输入在读取时发生错误或提前关闭，导致fgets()返回NULL
- 触发路径: fgets(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_18.c:35; printLine(data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fgets_18.c:36
- 结论: 未检查fgets()返回值，违反CWE-252，可能导致在读取失败或文件结束时使用未初始化的缓冲区数据
- D验证: stage_c_preserved / ver_bafd4c79
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 54. hyp_path_0c0b36c32f3b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_17.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够使fgetws失败，例如关闭标准输入流或发送EOF信号
- 触发路径: /* NOTE: Do not check the return value */ fgetws(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_17.c:36; printWLine(data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_17.c:37
- 结论: fgetws返回值未被检查，违反CWE-252（未检查返回值）。缓冲区事先已初始化为空字符串，fgetws失败时data内容不变，但违反API契约要求检查返回值。
- D验证: stage_c_preserved / ver_584cec99
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 55. hyp_path_716cc5add5ae

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_17.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者可能通过资源耗尽等方式使CreateMutexW失败，返回NULL
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_17.c:38
- 结论: 未检查CreateMutexW的返回值，属于CWE-252未检查返回值漏洞。但后续CloseHandle(NULL)在Windows API中定义良好，不会导致未定义行为或崩溃，实际风险极低。
- D验证: confirmed / ver_500c6140
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 56. hyp_path_ada1eb33bda7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_17.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够通过耗尽系统资源等方式使CreateMutexA失败
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_17.c:38; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_17.c:38
- 结论: 未检查CreateMutexA返回值，如果函数失败返回NULL，则CloseHandle(NULL)可能导致程序崩溃（CWE-252）。
- D验证: confirmed / ver_de5d7643
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 57. hyp_path_77c78b672c30

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_08.c:48
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行且接收输入；fgetws 可能因文件结束或读取错误而失败
- 触发路径: fgetws(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_08.c:48
- 结论: fgetws 的返回值未被检查，违反 CWE-252：未检查返回值。如果 fgetws 失败，程序可能继续使用未修改的数据，导致逻辑错误或未定义行为。
- D验证: stage_c_preserved / ver_f6761a1d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 58. hyp_path_42013b5e5e3f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_11.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够导致fgetws失败，例如提前关闭stdin或引发读取错误。
- 触发路径: fgetws(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_11.c:35; printWLine(data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_11.c:36
- 结论: fgetws调用后未检查返回值，违反CWE-252 (Unchecked Return Value)，即使缓冲区已初始化为空字符串，失败时缓冲区可能处于未定义状态，构成API contract violation。
- D验证: stage_c_preserved / ver_027b1bda
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 59. hyp_path_1c18bc704c71

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_12.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdin遇到EOF或读取错误导致fgetws返回NULL
- 触发路径: /* NOTE: Do not check the return value */ fgetws(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_12.c:34; printWLine(data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_12.c:36
- 结论: 未检查fgetws()的返回值，当函数失败时（如EOF或读取错误），data缓冲区内容保持为初始空字符串而非读取的数据，违反了API契约，可能导致后续逻辑依赖未更新的缓冲区。
- D验证: stage_c_preserved / ver_a741b4d1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 60. hyp_path_210fa0932798

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_01.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制输入流使得fgetws失败（如关闭stdin或发送EOF）
- 触发路径: fgetws(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_01.c:33; printWLine(data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_01.c:34
- 结论: 未检查fgetws()的返回值，违反CWE-252。如果fgetws失败（如EOF或错误），data缓冲区保持初始空字符串，后续printWLine使用该数据，虽然影响有限（打印空字符串），但违反了API使用规范。
- D验证: stage_c_preserved / ver_f2bd994b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 61. hyp_path_f05e449bafc8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_02.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够使标准输入流在输入过程中遇到错误或EOF，导致fgetws返回NULL。
- 触发路径: fgetws(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_02.c:35; printWLine(data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_02.c:36
- 结论: fgetws函数的返回值未检查，违反了CWE-252（未检查返回值）。即使dataBuffer已初始化为空字符串，若fgetws失败（返回NULL），后续printWLine(data)会使用未经检查的数据，构成API合约违规。
- D验证: stage_c_preserved / ver_79b2ed2a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 62. hyp_path_5ffe4d784b58

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_04.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin输入条件（如提前关闭或发送异常数据），使fgetws返回NULL或错误值。
- 触发路径: fgetws(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_04.c:41
- 结论: CWE-252: 未检查返回值 - 函数fgetws的返回值未被检查，可能导致后续操作使用无效数据。
- D验证: stage_c_preserved / ver_5f9c1d35
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 63. hyp_path_55a8d47f5649

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_03.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够使fgetws失败，例如关闭stdin或制造读取错误。
- 触发路径: fgetws(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_03.c:35; printWLine(data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_03.c:36
- 结论: 未检查fgetws的返回值，违反API contract（CWE-252）。虽然data缓冲区已初始化为空字符串，但调用失败时可能无法检测EOF或输入错误，导致程序行为异常。
- D验证: stage_c_preserved / ver_9ebc0e4a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 64. hyp_path_4bbe230afc58

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_05.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过关闭stdin或提供无效输入导致fgetws失败
- 触发路径: fgetws(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_05.c:41
- 结论: fgetws的返回值未检查，违反CWE-252: Unchecked Return Value。如果fgetws失败（如遇到EOF或错误），返回NULL且data内容可能未定义，后续printWLine使用未定义数据可能导致信息泄露或程序行为异常。
- D验证: stage_c_preserved / ver_bd79b666
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 65. hyp_path_2b902497db96

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_06.c:41
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者通过关闭stdin或导致输入错误使fgetws失败
- 触发路径: /* NOTE: Do not check the return value */ fgetws(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_06.c:40
- 结论: fgetws函数的返回值未被检查，在fgetws失败时，data缓冲区内容可能未定义（或保持部分写入状态），程序随后使用data，违反CWE-252（未检查返回值）。
- D验证: stage_c_preserved / ver_e2dd5704
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 66. hyp_path_1d5a8fbdba47

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_07.c:41
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可以触发 fgetws 失败（如关闭标准输入或发送 EOF）
- 触发路径: fgetws(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_07.c:40
- 结论: 未检查 fgetws 的返回值，可能导致使用未更新或错误的数据。
- D验证: stage_c_preserved / ver_56151815
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 67. hyp_path_7bed55d58722

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_13.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序从stdin读取，可能在读取时遇到EOF或错误
- 触发路径: fgetws(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_13.c:35
- 结论: 函数fgetws的返回值未检查，违反API契约。如果fgetws失败（如遇到EOF或读取错误），返回NULL，但代码未检查直接使用data，可能导致后续使用未初始化的缓冲区数据。
- D验证: stage_c_preserved / ver_ac32ffb4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 68. hyp_path_15bf32e7315c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_14.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可以通过关闭stdin或发送EOF使fgetws失败。
- 触发路径: fgetws(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_14.c:35
- 结论: 未检查fgetws返回值，违反了CWE-252，可能导致使用无效或未定义的数据。尽管缓冲区已初始化为空字符串，但若fgetws失败，后续使用可能视为不可预料行为。
- D验证: stage_c_preserved / ver_6478f836
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 69. hyp_path_4088a1cd74e7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_09.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响 stdin 输入（例如提供特殊字符或提前关闭输入流），使 fgetws 返回 NULL。
- 触发路径: fgetws(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_09.c:35
- 结论: 调用 fgetws 后未检查返回值，违反 CWE-252 规则。即使缓冲区已初始化，函数失败时数据未更新，后续使用可能导致逻辑错误或意外行为，构成 API misuse。
- D验证: stage_c_preserved / ver_d1dff26f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 70. hyp_path_7d922c2da694

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_10.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够使fgetws失败，例如关闭标准输入或发送EOF
- 触发路径: fgetws(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_10.c:35; printWLine(data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_10.c:36
- 结论: 未检查fgetws返回值，违反CWE-252最佳实践。即使缓冲区已初始化，未检查返回值可能导致在输入失败时程序行为与预期不符（例如，后续逻辑依赖成功读取），属于编码缺陷。
- D验证: stage_c_preserved / ver_b8aa83e1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 71. hyp_path_eb8461f71d8c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_15.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够触发fgetws失败（例如提供EOF或导致读取错误）
- 触发路径: printLine("Please enter a string: "); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_15.c:34; fgetws(data, 100, stdin); // 返回值未被检查 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_15.c:36; printWLine(data); // 依赖可能无效的data @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_15.c:37
- 结论: 未检查fgetws返回值，违反CWE-252，可能导致后续使用无效数据。
- D验证: stage_c_preserved / ver_75e0eab2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 72. hyp_path_515cb33f0dc7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_16.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过关闭 stdin 或发送特殊输入导致 fgetws 失败，但用户输入场景下风险较低。
- 触发路径: /* NOTE: Do not check the return value */ fgetws(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_16.c:35; printWLine(data); @ 同一文件:36
- 结论: 未检查 fgetws 返回值，违反 CWE-252 API 契约，但缓冲区已初始化，影响较低。
- D验证: stage_c_preserved / ver_6c89bb2c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 73. hyp_path_6f3e9f73a7d9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_18.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够导致fgetws调用失败（例如通过关闭标准输入流或提供无效输入）。
- 触发路径: fgetws(data, 100, stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_18.c:35; printWLine(data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_18.c:36
- 结论: 函数fgetws的返回值未检查，违反API合约，尽管缓冲区已初始化，但调用失败可能导致使用无效状态，存在潜在未定义行为。
- D验证: stage_c_preserved / ver_fe570c5e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 74. hyp_path_dc39dc7d2b34

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_12.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够通过耗尽系统资源或利用其他手段使CreateMutexW失败（例如创建大量互斥体）
- 触发路径: HANDLE hMutex = NULL; hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_12.c:31-33; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_12.c:36-37
- 结论: 在CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_12.c中，当globalReturnsTrueOrFalse()返回true时，代码调用CreateMutexW后未检查返回值，若函数失败返回NULL，则后续调用CloseHandle(NULL)将导致无效句柄异常（访问冲突或程序崩溃），违反了CWE-252未检查返回值约定。
- D验证: confirmed / ver_3e303d85
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 75. hyp_path_c56e33c836d2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_12.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: globalReturnsTrueOrFalse()返回true（约50%概率）; CreateMutexA因系统资源不足等原因返回NULL
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); /* NOTE: Do not check the return value */ @ CWE252_Unchecked_Return_Value__char_w32CreateMutex_12.c:31-35; CloseHandle(hMutex); @ CWE252_Unchecked_Return_Value__char_w32CreateMutex_12.c:35-39
- 结论: 在globalReturnsTrueOrFalse()返回true的分支中，调用CreateMutexA后未检查返回值。尽管CloseHandle(NULL)行为定义明确（返回FALSE并设置ERROR_INVALID_HANDLE），不会导致崩溃或未定义行为，但代码仍违反了CWE-252要求检查函数返回值的契约。这种未检查的返回值可能掩盖CreateMutexA失败的事实，导致程序在后续逻辑中依赖一个假设为有效的互斥体句柄，从而引发潜在的竞态条件或安全漏洞。该漏洞影响较低，需要动态验证以确认实际后果。
- D验证: confirmed / ver_a7a7042f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 76. hyp_path_ca58f7236aa7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_08.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够导致系统资源耗尽，使CreateMutexA失败；或程序在资源紧张的环境下运行
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_08.c:46; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_08.c:50
- 结论: 未检查CreateMutexA的返回值，如果函数失败返回NULL，则后续CloseHandle(NULL)可能导致程序崩溃或未定义行为。
- D验证: confirmed / ver_46e128d9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 77. hyp_path_ba2afcc11fa9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_11.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateMutexA因资源不足、权限等原因失败
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_11.c:33; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_11.c:37
- 结论: 函数CreateMutexA的返回值未被检查，违反API合约（应检查返回值是否为NULL），若Mutex创建失败，后续CloseHandle可能传递无效句柄，可能导致未定义行为或资源泄漏。
- D验证: confirmed / ver_13ffcabb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 78. hyp_path_1002df721d28

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_08.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateMutexW调用失败（如系统资源不足）
- 触发路径: HANDLE hMutex = NULL; hMutex = CreateMutexW(NULL, FALSE, NULL); /* NOTE: Do not check the return value */ @ CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_08.c:44-48; CloseHandle(hMutex); @ CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_08.c:50
- 结论: 调用CreateMutexW后未检查返回值，若失败则hMutex为NULL，随后调用CloseHandle(NULL)是安全的（返回FALSE，不崩溃），但违反了CWE-252 API契约，即未验证关键系统调用的返回值，可能导致资源管理问题（如未正确获取互斥体）。
- D验证: confirmed / ver_c2c638d7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 79. hyp_path_aad143189113

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_02.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者可能通过耗尽系统资源（如句柄数）导致 CreateMutexA 失败
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_02.c:37; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_02.c:37
- 结论: CreateMutexA 返回值未检查，可能导致空句柄传递给 CloseHandle，引发未定义行为或程序崩溃。
- D验证: confirmed / ver_2ae1512f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 80. hyp_path_0b8e40e94378

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_03.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够耗尽系统资源或触发CreateMutexA失败条件
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_03.c:37; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_03.c:37
- 结论: 调用CreateMutexA后未检查返回值，可能导致句柄为NULL，随后将NULL句柄传递给CloseHandle，造成未定义行为或程序崩溃。
- D验证: confirmed / ver_79595dda
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 81. hyp_path_b079ee88366e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_11.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 系统资源不足时CreateMutexW可能失败
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_11.c:37; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_11.c:37
- 结论: 调用CreateMutexW后未检查返回值，违反CWE-252。若CreateMutexW失败返回NULL，则后续CloseHandle(NULL)因无效句柄可能导致程序崩溃。
- D验证: confirmed / ver_4a8f066e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 82. hyp_path_6a6239dcf595

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_04.c:43
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateMutexA调用因系统资源不足或权限不足而失败，返回NULL。
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_04.c:43; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_04.c:43
- 结论: 调用CreateMutexA后未检查返回值，尽管CloseHandle(NULL)安全，但违反CWE-252规范，可能导致未处理的错误状态或资源泄漏（若CreateMutexA失败且未处理）。
- D验证: confirmed / ver_c42bfc5e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 83. hyp_path_3b0328620392

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_01.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者无法直接控制CreateMutexA的参数，但可能通过耗尽系统资源（如内存耗尽）导致CreateMutexA失败。
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_01.c:30; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_01.c:35
- 结论: CreateMutexA的返回值未被检查，违反了CWE-252（未检查返回值）。虽然攻击者无法直接控制参数，但可能通过耗尽系统资源导致CreateMutexA失败返回NULL，后续CloseHandle(NULL)会失败但不导致崩溃。漏洞存在但影响较低。
- D验证: confirmed / ver_ecdab749
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 84. hyp_path_333460f9783a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_06.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者可通过耗尽系统资源使CreateMutexA失败，导致返回NULL。
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_06.c:42; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_06.c:42
- 结论: 未检查CreateMutexA的返回值，如果创建互斥体失败，hMutex为NULL，后续CloseHandle(NULL)导致未定义行为。
- D验证: confirmed / ver_652830b3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 85. hyp_path_483ab5e2891f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_05.c:43
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够耗尽系统资源，导致CreateMutexA失败；或程序运行在资源受限环境中。
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_05.c:43; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_05.c:45
- 结论: 对CreateMutexA的返回值未进行检查，违反CWE-252（未检查返回值）。如果CreateMutexA调用失败，hMutex可能为NULL，随后传递给CloseHandle将导致未定义行为（如程序崩溃或资源泄漏）。
- D验证: confirmed / ver_7e88be27
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 86. hyp_path_63bfb605f040

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_07.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateMutexA 调用失败（如系统资源不足）
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_07.c:42
- 结论: CreateMutexA 的返回值未被检查，违反 CWE-252。若 CreateMutexA 失败（返回 NULL），程序未处理错误，后续虽然 CloseHandle(NULL) 安全，但同步逻辑可能失效，影响程序正确性。
- D验证: confirmed / ver_d4a2e607
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 87. hyp_path_aa628d13dc82

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_10.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 系统资源不足或达到限制，导致CreateMutexA返回NULL
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); // 返回值未检查 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_10.c:37; CloseHandle(hMutex); // 若hMutex为NULL，导致无效句柄异常 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_10.c:37
- 结论: 对CreateMutexA的返回值未作检查，可能导致在函数失败时使用无效句柄（NULL）进行CloseHandle，引发程序崩溃或未定义行为。违反CWE-252（未检查返回值）。
- D验证: confirmed / ver_786369c7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 88. hyp_path_21244b631046

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_09.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateMutexA可能因系统资源不足返回NULL，攻击者可通过耗尽资源间接触发，但无直接外部输入控制。
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_09.c:35; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_09.c:38
- 结论: CreateMutexA返回值未检查，导致违反CWE-252 API契约。后续CloseHandle可能传入NULL句柄，尽管CloseHandle(NULL)通常不会造成崩溃，但该代码路径明确存在未检查返回值漏洞。
- D验证: confirmed / ver_76ea5f30
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 89. hyp_path_89f789840ebc

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_13.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 系统资源不足或互斥量创建失败
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ 37; CloseHandle(hMutex); // 未检查返回值，可能传入NULL @ 37
- 结论: CreateMutexA的返回值未检查，如果创建失败返回NULL，后续CloseHandle可能接收到无效句柄，虽然CloseHandle(NULL)可能不会立即崩溃，但违反了API contract，可能导致资源泄漏或意外行为。
- D验证: confirmed / ver_174d8903
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 90. hyp_path_d5fbde7ae03d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_14.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 系统资源不足导致CreateMutexA失败（返回NULL）。
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_14.c:35; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_14.c:37
- 结论: 调用CreateMutexA后未检查返回值，可能导致空句柄被传递给CloseHandle，违反API合同，存在CWE-252漏洞。
- D验证: confirmed / ver_ca8880ad
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 91. hyp_path_fd5b1a1a1e53

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_15.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 系统资源耗尽或权限不足导致CreateMutexA失败
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_15.c:38
- 结论: CreateMutexA的返回值未被检查，如果函数失败则hMutex为NULL，违反CWE-252要求，尽管CloseHandle(NULL)是安全的，但错误未被处理，可能掩盖程序逻辑问题。
- D验证: confirmed / ver_9e2b82d6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 92. hyp_path_155753c8bb03

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_16.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够通过消耗系统资源（如大量创建互斥体）导致CreateMutexA失败
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_16.c:37; /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_16.c:37; CloseHandle(hMutex); // hMutex可能为NULL @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_16.c:37
- 结论: 调用CreateMutexA后未检查返回值，若函数失败返回NULL，后续CloseHandle(NULL)将导致程序崩溃或资源泄漏。
- D验证: confirmed / ver_74adf239
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 93. hyp_path_b4e15dd0771d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_01.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够通过耗尽系统资源等方式导致CreateMutexW失败，但利用难度较高
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); // 未检查返回值 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_01.c:35; CloseHandle(hMutex); // 若CreateMutexW失败，hMutex为NULL，导致无效句柄异常 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_01.c:35
- 结论: CreateMutexW调用后未检查返回值，若函数失败返回NULL，则hMutex为NULL，随后传递给CloseHandle将导致无效句柄异常，程序可能崩溃或产生未定义行为，违反了CWE-252的要求。
- D验证: confirmed / ver_b74b9e77
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 94. hyp_path_f69e15f0e1fb

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_02.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateMutexW执行失败（例如系统资源不足）。
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ 27; CloseHandle(hMutex); // 若hMutex为NULL，可能引发异常 @ 37
- 结论: CreateMutexW调用后未检查返回值，可能导致后续CloseHandle使用了无效句柄（NULL），违反API契约。
- D验证: confirmed / ver_a12e0212
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 95. hyp_path_d05e823a916d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_18.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 无需攻击者控制，API调用本身可能失败
- 触发路径: hMutex = CreateMutexA(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_18.c:37; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_18.c:39
- 结论: 调用CreateMutexA后未检查返回值，违反CWE-252（未检查返回值）。如果CreateMutexA失败返回NULL，后续CloseHandle将处理无效句柄，可能导致程序行为异常（如CloseHandle返回错误或未定义行为）。
- D验证: confirmed / ver_6f72dc98
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 96. hyp_path_2d6731186703

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_04.c:43
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateMutexW 因资源不足等原因失败，返回 NULL
- 触发路径: HANDLE hMutex = NULL; hMutex = CreateMutexW(NULL, FALSE, NULL); /* NOTE: Do not check the return value */ /* We'll leave out most of the implementation since it has nothing to do with the CWE */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_04.c:37-41; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_04.c:43
- 结论: CreateMutexW 的返回值未检查，若函数失败返回 NULL，则后续 CloseHandle(NULL) 调用可能导致未定义行为（如程序崩溃或资源泄漏）。
- D验证: confirmed / ver_de7cbcbe
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 97. hyp_path_1dd7539e7a0f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_05.c:43
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateMutexW可能失败（如系统资源不足）
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_05.c:43
- 结论: 调用CreateMutexW后未检查返回值，违反CWE-252。如果CreateMutexW失败返回NULL，后续CloseHandle(hMutex)将关闭无效句柄，可能导致未定义行为或资源竞争。
- D验证: confirmed / ver_b146c3e4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 98. hyp_path_1234c074f02e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_03.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 无外部输入控制，但CreateMutexW可能因系统资源不足等内部原因失败，导致返回NULL。
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_03.c:37; CloseHandle(hMutex); @ 同一文件:38-39
- 结论: 调用CreateMutexW后未检查返回值，若失败则hMutex为NULL，随后传递给CloseHandle导致未定义行为。
- D验证: confirmed / ver_6f30d2d5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 99. hyp_path_b6a734cfa501

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_06.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 系统资源不足或句柄数达到上限可能导致CreateMutexW失败，无需外部输入控制。
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_06.c:42; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_06.c:44
- 结论: 未检查CreateMutexW的返回值可能导致使用无效句柄，违反API contract CWE-252。
- D验证: confirmed / ver_4d1ed9e8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 100. hyp_path_332297b69493

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_09.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateMutexW由于资源不足或其他原因失败，返回NULL。
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_09.c:37; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_09.c:39
- 结论: 未检查CreateMutexW的返回值，可能导致后续CloseHandle传入NULL句柄，引发未定义行为。
- D验证: confirmed / ver_0caff34e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 101. hyp_path_cdb5d7549a7b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_07.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateMutexW可能因系统资源不足返回NULL，攻击者无法直接控制该条件
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_07.c:42; CloseHandle(hMutex); // 未检查hMutex是否为NULL @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_07.c:44
- 结论: 调用CreateMutexW后未检查返回值，违反了API使用合同（CWE-252）。虽然CloseHandle(NULL)是安全的，不会导致崩溃或未定义行为，但未检查返回值可能隐藏其他问题（如未获得互斥锁），且不符合安全编码规范。
- D验证: confirmed / ver_79d7a3ea
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 102. hyp_path_a7461a489dd2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_10.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateMutexW可能因系统资源不足等原因返回NULL，但无外部输入控制
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_10.c:37
- 结论: CreateMutexW的返回值未检查，违反API契约，构成CWE-252漏洞。尽管CloseHandle(NULL)有定义行为，但未检查返回值可能导致后续操作在非NULL句柄上失败或资源泄露，属于未检查返回值错误。
- D验证: confirmed / ver_29cf2d52
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 103. hyp_path_20fe0a68db98

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_14.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 无外部输入控制，但可能因系统资源不足导致CreateMutexW失败，例如内存耗尽或已达最大句柄数限制
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_14.c:37; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_14.c:39
- 结论: CreateMutexW调用后未检查返回值，若创建失败返回NULL，后续CloseHandle(NULL)会导致未定义行为或程序崩溃，违反了CWE-252要求检查API返回值的约定。
- D验证: confirmed / ver_9eca05a6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 104. hyp_path_0c1696f8ac1e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_13.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateMutexW调用失败，可能由于系统资源耗尽或权限不足，攻击者虽难以直接控制，但属于API误用
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_13.c:33; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_13.c:37
- 结论: 未检查CreateMutexW的返回值，若创建互斥体失败（返回NULL），则后续CloseHandle(NULL)可能导致未定义行为（如程序崩溃或资源泄漏）。
- D验证: confirmed / ver_4222ff4b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 105. hyp_path_19cd4770e030

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_15.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 系统资源不足（如内存不足）导致CreateMutexW失败，返回NULL；攻击者无法直接控制函数参数，但可诱发资源耗尽条件。
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_15.c:38; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_15.c:40
- 结论: 调用CreateMutexW后未检查返回值，如果创建互斥体失败（返回NULL），则hMutex为NULL，随后调用CloseHandle(NULL)会导致未定义行为（如程序崩溃），违反了CWE-252未检查返回值的要求。
- D验证: confirmed / ver_56dd2581
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 106. hyp_path_040026fc224f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_16.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 无，代码自动执行，无需攻击者输入。
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_16.c:37; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_16.c:37
- 结论: 调用CreateMutexW后未检查返回值，若返回NULL则后续CloseHandle(NULL)调用导致未定义行为（通常程序崩溃），违反CWE-252未检查返回值。
- D验证: confirmed / ver_7516bea2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 107. hyp_path_5204677026bc

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_18.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: CreateMutexW 因资源不足等原因返回 NULL
- 触发路径: hMutex = CreateMutexW(NULL, FALSE, NULL); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_18.c:37; /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_18.c:37; CloseHandle(hMutex); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_18.c:37
- 结论: 在调用 CreateMutexW 后未检查返回值，若函数失败返回 NULL，则将 NULL 句柄传给 CloseHandle，违反 API 合同，导致未正确处理错误，可能掩盖系统资源不足等失败情况。
- D验证: confirmed / ver_a4309dda
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 108. hyp_path_c09e55527b38

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_12.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者需要能够影响或预测globalReturnsTrueOrFalse()的返回值，使其为true（例如通过控制随机种子或环境状态），但具体控制方式取决于函数实现，此处假设该函数可被影响。
- 触发路径: void CWE252_Unchecked_Return_Value__char_remove_12_case0() { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_12.c:30; if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_12.c:32; REMOVE("removemecase0.txt"); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_12.c:35
- 结论: 当globalReturnsTrueOrFalse()返回true时，程序进入if分支并调用REMOVE("removemecase0.txt")，但未检查返回值。若删除操作失败（如文件不存在或权限不足），程序将无法感知，可能导致后续逻辑错误或安全假设被突破，违反CWE-252: Unchecked Return Value。
- D验证: stage_c_preserved / ver_d92f08a2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 109. hyp_path_37196f4276ce

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_12.c:43
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者可通过影响环境使重命名失败，但无需外部输入控制，API contract违反本身即构成漏洞
- 触发路径: void CWE252_Unchecked_Return_Value__char_rename_12_case0() { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_12.c:33; if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_12.c:35; /* NOTE: Do not check the return value */ RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_12.c:36
- 结论: 在函数CWE252_Unchecked_Return_Value__char_rename_12_case0中，当globalReturnsTrueOrFalse()返回true时，调用RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt")后未检查返回值，违反了CWE-252（未检查返回值），可能导致重命名失败未被检测，进而引起程序状态不一致或后续错误。
- D验证: stage_c_preserved / ver_caf54467
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 110. hyp_path_cd19b59082bc

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_06.c:75
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: rename系统调用可能因为权限、路径错误等原因失败; 调用者后续逻辑依赖于rename操作成功（代码中未显式验证，但隐含在典型使用场景中）
- 触发路径: if (RENAME(OLD_CASE1_FILE_NAME, "newcase1filename.txt") != 0) { printLine("rename failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_06.c:75
- 结论: 函数检查了rename的返回值，但仅在失败时打印错误信息，未终止或返回错误码，导致调用者可能无法得知操作失败，若调用者后续依赖rename结果则可能出现未定义行为。
- D验证: stage_c_preserved / ver_f96c9e8e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 111. hyp_path_7b9dcea254f1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_11.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者无法直接控制文件路径，但可能通过影响文件系统状态（如竞争条件）利用。
- 触发路径: REMOVE("removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_11.c:35
- 结论: 调用 remove 函数未检查返回值，违反 CWE-252 API 契约，可能因文件删除失败导致后续逻辑错误。
- D验证: stage_c_preserved / ver_88ed6508
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 112. hyp_path_034ded9dc558

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_08.c:48
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: REMOVE函数执行失败，例如文件不存在、权限不足或磁盘满等场景。虽然文件名固定，但失败条件仍可能由环境因素或其他攻击触发。
- 触发路径: REMOVE("removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_08.c:48
- 结论: 函数CWE252_Unchecked_Return_Value__char_remove_08_case0调用REMOVE("removemecase0.txt")后未检查返回值，违反了CWE-252（未检查返回值）。这可能导致删除操作失败时程序无法感知错误，进而影响后续逻辑，例如误认为文件已删除并继续执行依赖文件不存在的操作。尽管B阶段风险分数较低，但该漏洞在代码层面是明确的API contract违反，且无防御措施。
- D验证: stage_c_preserved / ver_f5feb839
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 113. hyp_path_44a160f55c66

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_11.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者可能通过影响文件系统状态（如权限、路径存在性）使 rename 失败，但无需攻击者控制输入。
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_11.c:38
- 结论: 函数 CWE252_Unchecked_Return_Value__char_rename_11_case0 中调用 rename 函数但未检查返回值，违反 CWE-252 规定，可能忽略文件重命名失败的错误，导致程序状态与预期不一致。
- D验证: stage_c_preserved / ver_029f02cc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 114. hyp_path_4c8d912aaba2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_16.c:53
- 漏洞类型: CWE-754
- CWE: CWE-754
- 风险等级: P1
- 触发条件: 攻击者能够影响外部条件使rename失败（如更改文件权限、填充磁盘空间）
- 触发路径: if (RENAME(OLD_CASE1_FILE_NAME, "newcase1filename.txt") != 0) { printLine("rename failed!"); } break; @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_16.c:53
- 结论: 在文件重命名操作后，虽然检查了返回值，但仅在失败时打印消息，未进行错误恢复或终止流程，导致程序在错误状态下继续执行，可能造成后续操作基于无效的文件状态。
- D验证: stage_c_preserved / ver_f82bf4b6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 115. hyp_path_9f7f2dd731e0

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_08.c:51
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响文件系统状态（例如使源文件不存在或权限不足），导致rename失败。
- 触发路径: void CWE252_Unchecked_Return_Value__char_rename_08_case0() { @ 46; if(staticReturnsTrue()) { @ 48; RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt"); // NOTE: Do not check the return value @ 51
- 结论: 文件重命名操作（rename）的返回值未被检查，可能导致程序在文件重命名失败时仍假设成功，属于未检查返回值漏洞（CWE-252）。
- D验证: stage_c_preserved / ver_0c6f7541
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 116. hyp_path_ace9675cb53f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_17.c:56
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供特殊输入导致scanf返回0（理论上可能但极难）
- 触发路径: if (scanf("%99s\0", data) == EOF) { @ CWE252_Unchecked_Return_Value__char_scanf_17.c:56
- 结论: 对scanf的返回值检查不完整：仅检查EOF错误，未检查是否成功读取到预期数量的项（返回1）。当scanf返回0（即没有匹配到任何项，但实际极少发生）时，程序不会处理，导致可能使用未初始化或部分填充的缓冲区，违反CWE-252。
- D验证: stage_c_preserved / ver_ab5501a9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 117. hyp_path_157a38191d6d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_17.c:56
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够向stdin提供不符合格式的输入
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_17.c:56
- 结论: 在调用fwscanf时，只检查了是否返回EOF（错误情况），而未检查是否成功读取了期望的输入项（返回1）。当输入不匹配格式时，fwscanf返回0而不设置EOF，导致data可能包含未初始化的数据，构成CWE-252未检查返回值。
- D验证: stage_c_preserved / ver_94f119fd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 118. hyp_path_61426197f4ed

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_01.c:33
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: N/A
- 触发路径: /* NOTE: Do not check the return value */ REMOVE("removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_01.c:33
- 结论: 未检查remove函数的返回值，违反了CWE-252（未检查返回值）。虽然文件名硬编码，但无法确认删除操作是否成功，可能导致程序状态不一致或资源清理失败。
- D验证: stage_c_preserved / ver_9a04c06b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 119. hyp_path_0bce0087d572

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_17.c:58
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供输入，导致swscanf返回0（匹配失败）或非1值
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_17.c:58
- 结论: 未正确检查swscanf返回值，仅检查了EOF，未验证是否成功解析输入，可能导致使用未初始化数据或错误处理
- D验证: stage_c_preserved / ver_7afcd1ee
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 120. hyp_path_bf69c686927c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_03.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够影响文件系统状态，使得remove()调用失败（例如创建同名目录、修改权限、使文件锁定等），但程序未检查返回值。
- 触发路径: REMOVE("removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_03.c:35
- 结论: 未检查remove()函数的返回值，违反了API contract，可能导致文件删除操作失败时程序未感知，进而产生后续逻辑错误。
- D验证: stage_c_preserved / ver_924e89f3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 121. hyp_path_56949a726742

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_02.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者可能通过影响文件系统状态（如提前删除目标文件或修改权限）使 REMOVE() 调用失败，但此处路径硬编码，攻击者控制能力有限。
- 触发路径: REMOVE("removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_02.c:35
- 结论: 调用 REMOVE() 未检查返回值，违反了 API 契约，忽略删除操作可能失败的情况，导致程序在文件删除失败后继续执行，可能影响文件系统状态的正确性。
- D验证: stage_c_preserved / ver_82271939
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 122. hyp_path_746aa38ce0f1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_05.c:41
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 程序执行到该代码路径，且remove函数调用发生。
- 触发路径: /* NOTE: Do not check the return value */ REMOVE("removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_05.c:39-43
- 结论: 程序调用remove函数删除文件，但未检查返回值，违反了不检查返回值的API contract，可能导致删除操作失败未被发现，进而影响后续逻辑或资源清理。
- D验证: stage_c_preserved / ver_85c26449
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 123. hyp_path_d1b8e9bc23ab

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_04.c:41
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者需能够影响文件删除操作的成功与否（例如通过修改文件权限、耗尽磁盘空间等），但无法控制文件名。
- 触发路径: REMOVE("removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_04.c:41
- 结论: 函数remove()的返回值未检查，可能导致删除操作失败未被发现，造成程序状态不一致或后续错误处理缺失。尽管文件名固定，攻击者仍可通过影响文件系统状态（如权限、磁盘空间）使删除失败，从而触发未处理的错误路径。
- D验证: stage_c_preserved / ver_0bd7d30f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 124. hyp_path_69262e29434d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_06.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 无特定攻击者控制输入，但文件删除操作依赖于系统状态（如文件是否存在、权限等），未检查返回值可能导致未预期的行为。
- 触发路径: REMOVE("removemecase0.txt"); @ CWE252_Unchecked_Return_Value__char_remove_06.c:40
- 结论: CWE252_Unchecked_Return_Value: 未检查 remove() 函数的返回值，导致文件删除操作是否成功不可知，无法处理错误状态。虽然攻击者不直接控制输入，但文件删除失败可能被利用（例如通过竞争条件或权限错误），影响较低但仍是API contract违反。
- D验证: stage_c_preserved / ver_ba73bf87
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 125. hyp_path_9a5e60079761

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_07.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: REMOVE("removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_07.c:40
- 结论: 未检查remove函数的返回值，违反了CWE-252（未检查返回值）。虽然删除的文件名是固定的，但若删除失败且未处理，可能导致后续逻辑错误或状态不一致。
- D验证: stage_c_preserved / ver_99d3a333
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 126. hyp_path_fc7b3d43bc23

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_09.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者无法直接控制文件路径，但可能通过影响系统环境间接导致remove失败（如文件被占用、权限修改），利用难度较高。
- 触发路径: REMOVE("removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_09.c:35
- 结论: 未检查remove函数的返回值，导致CWE-252未检查返回值漏洞。
- D验证: stage_c_preserved / ver_977998f1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 127. hyp_path_2837613035ce

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_14.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 无需攻击者控制输入，函数调用本身即违反 API 契约。
- 触发路径: REMOVE("removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_14.c:35
- 结论: 调用 REMOVE 函数删除文件后未检查返回值，违反 CWE-252（Unchecked Return Value），可能导致未处理的错误或状态不一致。
- D验证: stage_c_preserved / ver_d552910f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 128. hyp_path_6669778b5c7d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_13.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 文件"removemecase0.txt"无法被删除（如被锁定、路径错误、权限不足）
- 触发路径: REMOVE("removemecase0.txt"); // 未检查返回值 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_13.c:35
- 结论: 调用remove函数删除文件时未检查返回值，可能导致删除失败但程序无感知，违反CWE-252未检查返回值。
- D验证: stage_c_preserved / ver_5b9b350c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 129. hyp_path_43ac9bddb263

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_10.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够使REMOVE调用失败，例如通过创建同名目录、移除文件或利用权限控制，但文件路径为硬编码字符串，攻击者无法直接控制路径。
- 触发路径: REMOVE("removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_10.c:35
- 结论: 存在CWE-252未检查返回值漏洞：调用REMOVE删除文件但未检查其返回值，可能导致删除失败未被处理。尽管文件路径为硬编码常量限制了攻击者控制能力，但漏洞本质不变。
- D验证: stage_c_preserved / ver_0a33fe46
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 130. hyp_path_9c214aa3aedd

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_15.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者可能能够影响文件系统中文件"removemecase0.txt"的状态（如提前删除或更改权限），导致REMOVE调用失败，但程序未检查返回值。
- 触发路径: case 6: /* NOTE: Do not check the return value */ REMOVE("removemecase0.txt"); break; default: @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_15.c:36
- 结论: 在REMOVE调用后未检查返回值，违反CWE-252：未检查返回值。如果文件删除失败（例如文件不存在或权限不足），程序将继续执行而不处理错误，可能导致后续逻辑错误或意外行为。
- D验证: stage_c_preserved / ver_d6fc5cb4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 131. hyp_path_7e6a77657898

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_17.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够影响文件系统状态（如更改权限、占用文件），使得remove()失败
- 触发路径: REMOVE("removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_17.c:36
- 结论: 调用remove()后未检查返回值，若文件删除失败（如文件不存在、权限不足），程序无法得知错误，可能导致资源泄露或状态不一致。文件名虽为固定字符串，但仍违反CWE-252。
- D验证: stage_c_preserved / ver_7dcdf222
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 132. hyp_path_36e87d05d661

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_16.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 文件路径固定，但攻击者可能通过影响文件系统状态（如权限、文件存在性）导致remove失败，而返回值未被检查。
- 触发路径: REMOVE("removemecase0.txt"); @ 35; /* NOTE: Do not check the return value */ REMOVE("removemecase0.txt"); break; @ 33-37
- 结论: 未检查REMOVE函数的返回值，可能导致删除操作失败未被发现，违反CWE-252 Unchecked Return Value。
- D验证: stage_c_preserved / ver_a4b9e907
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 133. hyp_path_2f766f3682fb

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_18.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够通过权限设置、文件锁定等方式使文件删除操作失败
- 触发路径: REMOVE("removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_remove_18.c:35
- 结论: 调用 remove 函数删除文件时未检查返回值，违反 API 契约，可能导致程序忽略删除失败的错误状态，影响后续逻辑。攻击者可通过权限设置或文件锁定使删除失败，从而破坏程序状态。
- D验证: stage_c_preserved / ver_b795b5c4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 134. hyp_path_2230864d397f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_01.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 存在外部影响可能导致rename()失败（如权限不足、磁盘满等）
- 触发路径: /* NOTE: Do not check the return value */ RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_01.c:36
- 结论: 未检查rename()函数的返回值，违反API契约，可能导致文件重命名操作失败时未正确处理，影响后续逻辑。
- D验证: stage_c_preserved / ver_269732d4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 135. hyp_path_4282ddbd4175

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_03.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 依赖文件系统状态，但无需攻击者控制输入
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_03.c:38
- 结论: 未检查文件重命名函数rename的返回值，可能导致操作失败不被察觉，符合CWE-252未检查返回值漏洞。蓝队确认漏洞存在。
- D验证: stage_c_preserved / ver_c7363318
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 136. hyp_path_99de7ba45c24

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_02.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 调用RENAME时未对其返回值进行检查
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_02.c:38
- 结论: 未检查RENAME函数的返回值，可能导致重命名操作失败而不被察觉，违反API contract。
- D验证: stage_c_preserved / ver_427d4f6b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 137. hyp_path_03aba10f7c72

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_04.c:44
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够创建或利用条件使rename调用失败，例如通过文件系统竞争或权限不足。
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_04.c:44
- 结论: 调用rename函数时未检查返回值，违反了CWE-252 Unchecked Return Value的API契约，可能导致程序在rename失败后继续执行，造成文件状态不一致或数据丢失。
- D验证: stage_c_preserved / ver_b4978222
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 138. hyp_path_8ae402115899

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_05.c:44
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者需要能够影响文件系统状态（如通过其他漏洞或共享环境）
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_05.c:44
- 结论: 函数rename的返回值未被检查，违反了CWE-252（未检查返回值）的API契约。虽然文件名是硬编码的，但rename操作可能因文件系统状态（如权限、磁盘空间）失败，导致未处理错误状态。
- D验证: stage_c_preserved / ver_7c2011d8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 139. hyp_path_0ef902126b30

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_06.c:43
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够影响文件系统状态（例如通过其他漏洞消耗磁盘空间或修改文件权限）
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_06.c:43
- 结论: 代码对rename系统调用的返回值未进行检查，违反API contract，可能导致rename失败时程序无法感知，从而引发后续未定义行为或逻辑错误。
- D验证: stage_c_preserved / ver_b62b1d79
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 140. hyp_path_9e5ddf7407a9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_07.c:43
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够影响文件系统状态（如权限、路径存在性），使rename调用失败。
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_07.c:43
- 结论: 未检查rename函数的返回值，违反CWE-252（未检查返回值），可能导致程序在文件重命名失败时继续执行，造成数据不一致或后续操作错误。
- D验证: stage_c_preserved / ver_26bd0f52
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 141. hyp_path_2424d329d4da

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_10.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者可能通过间接手段（如耗尽磁盘空间、删除原文件等）使rename失败，但文件名固定，直接控制能力有限。
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_10.c:38
- 结论: 在rename函数调用后未检查返回值，违反了CWE-252（未检查返回值）。rename可能失败（如原文件不存在、权限不足等），导致程序在后续逻辑中基于错误的文件状态继续执行，可能引发资源不一致或安全机制绕过。
- D验证: stage_c_preserved / ver_70e5034b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 142. hyp_path_7ff8d26f6238

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_09.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过竞争条件、文件系统权限或创建同名文件等方式使rename函数失败。
- 触发路径: /* NOTE: Do not check the return value */ RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt"); @ CWE252_Unchecked_Return_Value__char_rename_09.c:38
- 结论: 调用rename函数（通过RENAME宏）后未检查返回值，违反了CWE-252（未检查返回值）。虽然文件名是硬编码，但rename可能因文件系统错误（如权限不足、目标已存在、竞争条件）而失败，程序忽略错误可能导致文件状态不一致或后续操作基于错误的假设。
- D验证: stage_c_preserved / ver_c8b3e09e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 143. hyp_path_2ee39fc1be53

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_15.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 控制程序执行到case 6分支（通过switch语句）; RENAME调用可能失败的外部条件（如文件系统状态）
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_15.c:39
- 结论: 在case 6分支中调用RENAME(rename)函数时未检查返回值，违反CWE-252（未检查返回值）。攻击者可能通过制造文件操作失败（如权限不足、文件不存在）导致后续逻辑错误或数据不一致。
- D验证: stage_c_preserved / ver_e35fdd0c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 144. hyp_path_5260aa63482b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_14.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够通过修改文件系统权限、删除源文件或创建竞争条件等方式使重命名操作失败，而程序未检查返回值无法感知失败。
- 触发路径: { /* NOTE: Do not check the return value */ RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_14.c:38
- 结论: 文件重命名函数RENAME的返回值未被检查，若重命名失败（如文件不存在、权限不足），程序无法感知错误，可能导致数据不一致或后续操作在错误假设下进行。
- D验证: stage_c_preserved / ver_2f692ecb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 145. hyp_path_8dfc6e1b9cd2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_13.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够影响文件系统状态（如删除或重命名源文件、修改权限），使得 rename 操作失败
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_13.c:38
- 结论: 调用 rename 函数后未检查返回值，违反 CWE-252（未检查返回值）。即使文件名是常量，rename 仍可能因环境因素失败，未检查返回值会导致程序无法感知错误，可能引发后续逻辑错误或状态不一致。
- D验证: stage_c_preserved / ver_edaefcaf
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 146. hyp_path_68cd8e7db8c3

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_16.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响 rename 操作的成功条件，例如在文件系统中创建同名的目标文件或修改源文件/目录的权限。
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_16.c:38
- 结论: 程序调用 rename 函数但未检查其返回值，违反了 CWE252（Unchecked Return Value），可能导致重命名操作失败时程序继续执行，造成潜在安全影响。
- D验证: stage_c_preserved / ver_78f3937a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 147. hyp_path_a0cd44daa387

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_18.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够影响文件系统状态使得rename()调用失败（例如源文件不存在、权限不足等）
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_18.c:38
- 结论: 未检查rename()函数的返回值，违反API contract，可能导致文件重命名失败时程序状态不一致。
- D验证: stage_c_preserved / ver_2914f76e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 148. hyp_path_39dcc1ded72f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_17.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P0
- 触发条件: 攻击者可能通过修改文件系统状态（如删除源文件、修改权限等）触发 RENAME 失败，但无需直接控制输入参数。
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, "newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_17.c:39
- 结论: CWE252_Unchecked_Return_Value__char_rename_17.c 中，RENAME 函数调用后未检查返回值，违反 API contract，可能导致重命名操作失败未被处理，从而影响文件系统状态或程序行为。
- D验证: stage_c_preserved / ver_f37c0200
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 149. hyp_path_9bf9626872f1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_12.c:70
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC的内容，使得sscanf返回非EOF的失败值（如0或负数），导致data缓冲区未正确填充。
- 触发路径: static void case11() { if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_12.c:60; if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_12.c:70
- 结论: 在case11函数中，sscanf的返回值仅检查了EOF，未处理其他失败返回值（如0表示匹配失败，或输入错误），导致数据缓冲区可能未初始化或包含不完整数据，违反CWE-252要求检查所有错误条件。
- D验证: stage_c_preserved / ver_3d490dcc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 150. hyp_path_1454668d50c1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_12.c:82
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供特殊输入，使 scanf 返回 0（如空串或非匹配字符）或产生其他非 EOF 错误。
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_12.c:82
- 结论: scanf 返回值检查仅覆盖 EOF，未处理返回 0（匹配失败）或其他非 EOF 错误码。若 scanf 返回 0，data 缓冲区内容未定义，后续使用可能导致未初始化内存读取。当前代码片段未展示成功分支中 data 的使用，但 CWE-252 违反存在，需动态验证后续路径。
- D验证: stage_c_preserved / ver_c41b513e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 151. hyp_path_466b1716c20a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_12.c:68
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过 stdin 提供输入，使得 wscanf 匹配失败（返回 0）。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_12.c:68
- 结论: CWE252 未检查返回值漏洞：wscanf 的返回值仅检查了 EOF，但未检查是否成功匹配预期数量的输入项（1项）。若 wscanf 返回 0（未匹配），则 data 缓冲区保持初始空字符串，程序未检测此情况，后续使用空字符串可能导致逻辑错误或意外行为。
- D验证: stage_c_preserved / ver_a7303bb1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 152. hyp_path_04e5009d8479

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_12.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 代码执行到达if分支，即globalReturnsTrueOrFalse()返回true
- 触发路径: void CWE252_Unchecked_Return_Value__char_fprintf_12_case0() { if(globalReturnsTrueOrFalse()) { /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_12.c:24-28; { /* NOTE: Do not check the return value */ fprintf(stdout, "%s\n", "string"); } else @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_12.c:27-31
- 结论: 在CWE252_Unchecked_Return_Value__char_fprintf_12_case0函数中，当globalReturnsTrueOrFalse()返回true时，执行未检查fprintf返回值的分支，违反了CWE-252规范，可能导致错误未被处理。
- D验证: stage_c_preserved / ver_d28c82dd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 153. hyp_path_12b73bb71bf9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_12.c:70
- 漏洞类型: CWE-253, CWE-252
- CWE: CWE-253; CWE-252
- 风险等级: P1
- 触发条件: SRC输入为空字符串，导致swscanf返回0
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_12.c:70
- 结论: 未完全检查swscanf返回值，仅处理EOF未处理返回0的情况，导致输入为空字符串时data保持未初始化状态。虽然当前函数中未使用data，但存在未初始化变量潜在风险，需进一步验证后续是否有其他路径使用data。
- D验证: stage_c_preserved / ver_e641bd60
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 154. hyp_path_fdff3e8b1560

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_12.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 需globalReturnsTrueOrFalse()返回true，且fputc失败（如stdout关闭、磁盘满）才体现实际影响；但未检查返回值本身即违反契约。
- 触发路径: void CWE252_Unchecked_Return_Value__char_fputc_12_case0() { if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_12.c:24-26; /* NOTE: Do not check the return value */ fputc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_12.c:27-28
- 结论: 在CWE252_Unchecked_Return_Value__char_fputc_12_case0函数中，当globalReturnsTrueOrFalse()返回true时，fputc的返回值未被检查，违反了CWE-252未检查返回值的定义，可能导致程序在fputc失败（如输出错误）时继续执行，忽略错误状态。
- D验证: stage_c_preserved / ver_9ad23e6c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 155. hyp_path_76f5ca900c54

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_08.c:72
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够向stdin提供输入，使得fscanf返回0（例如输入纯空格或非%s匹配内容）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_08.c:72
- 结论: fscanf返回值检查不完整：仅检查了EOF错误，未检查返回是否等于期望的输入项数1，导致当fscanf返回0时（如输入不匹配），dataBuffer可能未被更新或包含未初始化数据，违反了CWE-252对返回值检查的要求。
- D验证: stage_c_preserved / ver_b6d6ce1d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 156. hyp_path_8c8113204613

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_12.c:45
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者不需要直接控制输入，但fscanf可能因stdin关闭或文件结束而失败，导致数据未初始化或部分读取。
- 触发路径: void CWE252_Unchecked_Return_Value__char_fscanf_12_case0() { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_12.c:24; if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_12.c:26; fscanf(stdin, "%99s\0", data); // NOTE: Do not check the return value @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_12.c:34
- 结论: 在CWE252_Unchecked_Return_Value__char_fscanf_12_case0函数中，当globalReturnsTrueOrFalse()返回true时，执行未检查返回值的fscanf调用，违反CWE-252（未检查返回值）的要求，可能导致未检测到输入失败，进而使用不确定的数据。
- D验证: stage_c_preserved / ver_f38e439e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 157. hyp_path_de9ce5de83e2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_12.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行时globalReturnsTrueOrFalse()返回true; 输出环境可能导致putc失败（如stdout关闭）
- 触发路径: void CWE252_Unchecked_Return_Value__char_putc_12_case0() { @ L24; if(globalReturnsTrueOrFalse()) { @ L25; /* NOTE: Do not check the return value */ @ L27; putc((int)'A', stdout); // 未检查返回值 @ L30
- 结论: 在函数CWE252_Unchecked_Return_Value__char_putc_12_case0中，当globalReturnsTrueOrFalse()返回true时，进入不检查返回值的分支，调用putc写入'A'到stdout后未检查返回值，违反CWE-252。如果putc失败（如stdout关闭或写入错误），程序无法感知，可能导致数据丢失或后续行为异常。
- D验证: stage_c_preserved / ver_6b4ac4c8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 158. hyp_path_fb10e456c47e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_12.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序执行时，globalReturnsTrueOrFalse()返回true
- 触发路径: void CWE252_Unchecked_Return_Value__char_putchar_12_case0() { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_12.c:24; if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_12.c:26; /* NOTE: Do not check the return value */ putchar((int)'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_12.c:28
- 结论: 函数putchar的返回值未检查，当globalReturnsTrueOrFalse()返回true时，忽略putchar可能的失败，违反CWE-252未检查返回值。
- D验证: stage_c_preserved / ver_10e8b24d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 159. hyp_path_92f8966634cc

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_12.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部输入控制，但内部条件globalReturnsTrueOrFalse()随机为真时触发未检查返回值的路径
- 触发路径: void CWE252_Unchecked_Return_Value__char_puts_12_case0() { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_12.c:30; if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_12.c:31; PUTS("string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_12.c:34
- 结论: 代码中存在未检查puts返回值的执行路径，违反CWE-252（未检查返回值）。当globalReturnsTrueOrFalse()返回真时，PUTS("string")的返回值未被检查，尽管puts参数为固定字符串且实际影响可能有限，但仍构成API misuse。
- D验证: stage_c_preserved / ver_e4bdd10f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 160. hyp_path_da2b257bc3fd

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_12.c:45
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够使scanf返回EOF或错误码（如通过提供无效输入或关闭输入流）
- 触发路径: void CWE252_Unchecked_Return_Value__char_scanf_12_case0() { if(globalReturnsTrueOrFalse()) { { ... } else { { ... } } } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_12.c:24-28; scanf("%99s\0", data); // 未检查返回值 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_12.c:34
- 结论: 在函数CWE252_Unchecked_Return_Value__char_scanf_12_case0中，当globalReturnsTrueOrFalse()返回假时，代码直接调用scanf而不检查返回值，违反了CWE-252（未检查返回值），可能导致未处理错误状态。
- D验证: stage_c_preserved / ver_cd4f097e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 161. hyp_path_a8bf36b6c6e9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_12.c:53
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 函数内部globalReturnsTrueOrFalse()返回true，导致执行未检查分支。无需外部输入控制，随机即可触发。
- 触发路径: void CWE252_Unchecked_Return_Value__char_snprintf_12_case0() { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_12.c:32; if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_12.c:33; SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC); // 未检查返回值 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_12.c:42
- 结论: 在CWE252_Unchecked_Return_Value__char_snprintf_12_case0函数中，当globalReturnsTrueOrFalse()返回true时，执行未检查SNPRINTF返回值的分支，违反CWE-252。
- D验证: stage_c_preserved / ver_926591ce
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 162. hyp_path_b21555494345

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_12.c:47
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部可控输入，但分支条件globalReturnsTrueOrFalse()随机返回真值，路径可达
- 触发路径: sscanf(SRC, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_12.c:36
- 结论: 存在未检查的sscanf返回值，违反CWE-252。当globalReturnsTrueOrFalse()返回真时，执行未检查返回值的sscanf调用，可能导致后续使用未初始化数据或静默失败。
- D验证: stage_c_preserved / ver_ad4bb229
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 163. hyp_path_482c91ed307a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_08.c:60
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (!ImpersonateSelf(SecurityImpersonation)) { exit(1); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_08.c:60
- 结论: 存在未检查返回值漏洞（CWE-252），但调用位于死代码分支，运行时不可达，实际利用风险低。需动态验证确认不可达性。
- D验证: stage_c_preserved / ver_acccccf2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 164. hyp_path_fc5feab6f7d9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_12.c:33
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: globalReturnsTrueOrFalse()返回true（50%概率随机，攻击者无法直接控制）
- 触发路径: void CWE252_Unchecked_Return_Value__w32ImpersonateSelf_12_case0() { if(globalReturnsTrueOrFalse()) { /* NOTE: Do not check if ImpersonateSelf() fails */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_12.c:23-27; ImpersonateSelf(SecurityImpersonation); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_12.c:28
- 结论: 在CWE252_Unchecked_Return_Value__w32ImpersonateSelf_12_case0函数中，当globalReturnsTrueOrFalse()返回true时，ImpersonateSelf(SecurityImpersonation)的返回值未被检查，违反CWE-252，可能导致模拟失败而程序继续执行，影响安全上下文。
- D验证: stage_c_preserved / ver_54b341df
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 165. hyp_path_9d0fc44e874e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_12.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: globalReturnsTrueOrFalse() 返回 true
- 触发路径: void CWE252_Unchecked_Return_Value__wchar_t_fprintf_12_case0() { if(globalReturnsTrueOrFalse()) { /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_12.c:24-28; { /* NOTE: Do not check the return value */ fwprintf(stdout, L"%s\n", L"string"); } else @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_12.c:27-31
- 结论: 在CWE252_Unchecked_Return_Value__wchar_t_fprintf_12.c的case0函数中，当globalReturnsTrueOrFalse()返回true时，代码路径不检查fwprintf的返回值，违反CWE-252。虽然影响较低（仅输出缺失），但属于API contract违反。
- D验证: stage_c_preserved / ver_362bd812
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 166. hyp_path_2a4c439d7f54

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_12.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: globalReturnsTrueOrFalse()返回true
- 触发路径: void CWE252_Unchecked_Return_Value__wchar_t_fputc_12_case0() { if(globalReturnsTrueOrFalse()) { /* NOTE: Do not check the return value */ @ CWE252_Unchecked_Return_Value__wchar_t_fputc_12.c:24-28; { /* NOTE: Do not check the return value */ fputwc((wchar_t)L'A', stdout); } @ CWE252_Unchecked_Return_Value__wchar_t_fputc_12.c:27-31
- 结论: 在fputwc调用后未检查返回值，可能导致写操作失败未被检测，违反API contract。
- D验证: stage_c_preserved / ver_540d85eb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 167. hyp_path_c3f7b66e579e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_12.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 函数globalReturnsTrueOrFalse()返回true，使得代码进入不检查返回值的分支。
- 触发路径: void CWE252_Unchecked_Return_Value__wchar_t_fputs_12_case0() { if(globalReturnsTrueOrFalse()) { /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_12.c:24-28; fputws(L"string", stdout); // 不检查返回值 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_12.c:29
- 结论: 在函数CWE252_Unchecked_Return_Value__wchar_t_fputs_12_case0中，当globalReturnsTrueOrFalse()返回true时，调用fputws(L"string", stdout)但未检查其返回值，违反了CWE-252（未检查返回值）的规范。虽然存在另一分支检查返回值，但该不检查路径可达，可能导致未处理的写入失败。
- D验证: stage_c_preserved / ver_5825c142
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 168. hyp_path_7091f22f8926

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_12.c:45
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，导致fwscanf失败。
- 触发路径: fwscanf(stdin, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_12.c:34
- 结论: 未检查fwscanf的返回值，可能导致输入失败未被检测，后续使用未定义的数据。
- D验证: stage_c_preserved / ver_c7710081
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 169. hyp_path_c4acb472ec6b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_12.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: globalReturnsTrueOrFalse()返回true
- 触发路径: void CWE252_Unchecked_Return_Value__wchar_t_putc_12_case0() { if(globalReturnsTrueOrFalse()) { /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_12.c:24-28; putwc((wchar_t)L'A', stdout); } // 未检查返回值 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_12.c:29-31
- 结论: 在CWE252_Unchecked_Return_Value__wchar_t_putc_12_case0函数中，当globalReturnsTrueOrFalse()返回true时，执行if分支中的putwc((wchar_t)L'A', stdout)而不检查返回值，违反CWE-252（未检查返回值）。
- D验证: stage_c_preserved / ver_927d4523
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 170. hyp_path_71e494132fa7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_12.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: globalReturnsTrueOrFalse()返回true; putwchar调用可能失败（如I/O错误）
- 触发路径: void CWE252_Unchecked_Return_Value__wchar_t_putchar_12_case0() { if(globalReturnsTrueOrFalse()) { /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_12.c:24-28; putwchar((wchar_t)L'A'); // 未检查返回值 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_12.c:29
- 结论: 在函数CWE252_Unchecked_Return_Value__wchar_t_putchar_12_case0中，当globalReturnsTrueOrFalse()返回true时，进入不检查putwchar返回值的分支，违反CWE-252未检查返回值漏洞。
- D验证: stage_c_preserved / ver_e3d9a7e4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 171. hyp_path_ed9c23ef1e4b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_12.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序执行到未检查返回值的分支（取决于globalReturnsTrueOrFalse()的返回）。
- 触发路径: if(globalReturnsTrueOrFalse()) { /* NOTE: Do not check the return value */ PUTS(L"string"); } else @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_12.c:33-37
- 结论: 函数_putws的返回值未被检查，当写入失败时无法检测到错误，可能影响程序正确性。
- D验证: stage_c_preserved / ver_2db6ff37
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 172. hyp_path_ad83327d1614

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_12.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者不能直接控制文件名，但可能通过环境或竞争条件影响_wremove的成功与否
- 触发路径: void CWE252_Unchecked_Return_Value__wchar_t_remove_12_case0() @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_12.c:30; if(globalReturnsTrueOrFalse()) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_12.c:31; /* NOTE: Do not check the return value */ REMOVE(L"removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_12.c:34
- 结论: 在'CWE252_Unchecked_Return_Value__wchar_t_remove_12.c'中，当globalReturnsTrueOrFalse()返回true时，代码直接调用REMOVE(L"removemecase0.txt")而不检查返回值，违反了API契约，导致CWE-252未检查返回值漏洞。
- D验证: stage_c_preserved / ver_93b5120b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 173. hyp_path_fd47f4312f68

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_12.c:43
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: RENAME函数因任何原因失败（如文件锁、路径无效等），但无需攻击者主动输入。
- 触发路径: /* NOTE: Do not check the return value */ RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_12.c:36-40
- 结论: 代码中在全局函数返回真或假的一个分支内未检查RENAME函数的返回值，违反CWE-252（Unchecked Return Value），可能导致文件重命名失败时程序忽略错误，造成数据丢失或不一致。
- D验证: stage_c_preserved / ver_71217638
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 174. hyp_path_20d9dcecf213

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_12.c:45
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: globalReturnsTrueOrFalse() 在运行时返回真值，无需外部输入控制。
- 触发路径: void CWE252_Unchecked_Return_Value__wchar_t_scanf_12_case0() { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_12.c:24; if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_12.c:26; wscanf(L"%99s\0", data); // NOTE: Do not check the return value @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_12.c:34
- 结论: 在 CWE252_Unchecked_Return_Value__wchar_t_scanf_12_case0 函数中，当 globalReturnsTrueOrFalse() 返回真时，调用 wscanf 但未检查其返回值，违反了 CWE-252 对返回值检查的要求。
- D验证: stage_c_preserved / ver_47315657
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 175. hyp_path_ca2f3f94a19c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_11.c:59
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供导致wscanf返回0的输入（例如以空格开头）
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_11.c:59
- 结论: CWE-252: wscanf返回值未充分检查，仅处理EOF错误，未处理返回0（输入不匹配）的情况，导致data缓冲区在wscanf返回0时仍保持未初始化状态。后续代码可能使用未初始化的data，但当前证据未闭合后续使用路径，需动态验证。
- D验证: stage_c_preserved / ver_cedcad0a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 176. hyp_path_11005ec82ded

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_12.c:53
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: globalReturnsTrueOrFalse()返回false，执行未检查分支; snwprintf调用可能因缓冲区不足或其他错误而失败（尽管SRC固定，但内存不足等外部因素仍可能发生）
- 触发路径: void CWE252_Unchecked_Return_Value__wchar_t_snprintf_12_case0() { if(globalReturnsTrueOrFalse()) { { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_12.c:32-36; wchar_t * data = dataBuffer; /* NOTE: Do not check the return value */ SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC); } } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_12.c:40-44
- 结论: 在CWE252_Unchecked_Return_Value__wchar_t_snprintf_12_case0中，当globalReturnsTrueOrFalse()返回false时，执行未检查swprintf返回值的分支（第40-44行），违反CWE-252要求：始终检查返回值。虽然SRC为固定字符串且后续未使用data，但未检查返回值本身构成API contract violation，潜在风险包括未检测到snwprintf失败导致数据不完整或缓冲区异常。
- D验证: stage_c_preserved / ver_f8d71a6c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 177. hyp_path_70385776e782

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_08.c:74
- 漏洞类型: CWE-252, CWE-457
- CWE: CWE-252; CWE-457
- 风险等级: P1
- 触发条件: 攻击者能够控制输入SRC，使其导致swscanf返回0（匹配失败）
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_08.c:74
- 结论: 函数swscanf的返回值检查不完整：仅检查是否等于EOF，未处理返回0（匹配失败）的情况，违反API contract，构成CWE-252漏洞。此外，dataBuffer未显式初始化，若后续使用data可能导致CWE-457，但当前路径未直接使用data，影响较低。
- D验证: stage_c_preserved / ver_388b69de
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 178. hyp_path_2ee88aceba92

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_12.c:47
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行时 globalReturnsTrueOrFalse() 返回假; swscanf 可能失败（如 SRC 输入不符合格式）
- 触发路径: wchar_t * data = dataBuffer; /* NOTE: Do not check the return value */ swscanf(SRC, L"%99s\0", data); @ CWE252_Unchecked_Return_Value__wchar_t_sscanf_12.c:34-38
- 结论: 存在未检查 swscanf 返回值的 CWE-252 违规：在 globalReturnsTrueOrFalse() 返回假时，代码执行未检查返回值的分支，调用 swscanf(SRC, L"%99s\0", data) 而不校验结果；若 swscanf 失败（返回 EOF），data 缓冲区内容不确定，可能导致后续未定义行为。
- D验证: stage_c_preserved / ver_50947e05
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 179. hyp_path_b435da28f4be

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_05.c:65
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入，导致fscanf返回0（匹配失败）或非EOF错误
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_05.c:65
- 结论: fscanf返回值检查不完整：仅检查EOF，未验证成功读取次数（应为1），违反了CWE-252。虽然data后续未使用，实际影响较低，但符合CWE定义。
- D验证: stage_c_preserved / ver_d9edf67f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 180. hyp_path_007dfff2f0e1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_07.c:64
- 漏洞类型: CWE-253, CWE-252
- CWE: CWE-253; CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供输入使得fscanf返回0（例如输入空字符串或格式不匹配）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_07.c:64
- 结论: fscanf返回值检查不完整：仅检查EOF，未检查是否成功读取到所需数量的项（应为1），违反CWE-253。后续未使用data降低可利用性，但API contract violation明确存在。
- D验证: stage_c_preserved / ver_959246c1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 181. hyp_path_c9e2808d383a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_10.c:59
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: Attacker can control stdin input to cause fscanf to return 0 (matching failure) instead of EOF, bypassing the error check.
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_10.c:59
- 结论: Vulnerability found: insufficient return value check on fscanf. Only checking for EOF, but fscanf can return 0 on matching failure, leaving dataBuffer potentially uninitialized.
- D验证: stage_c_preserved / ver_418e07c5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 182. hyp_path_028c50c58349

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_07.c:53
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: staticTrue为真（通常为1），使第一个if分支可达
- 触发路径: putc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_07.c:51
- 结论: 存在未检查返回值的putc调用，违反CWE-252。
- D验证: stage_c_preserved / ver_153f2a03
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 183. hyp_path_c3fae82d377c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_14.c:59
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入的内容（例如通过重定向或交互式输入）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_14.c:59
- 结论: fscanf返回值检查不完整：仅检查了EOF（返回-1），未处理返回0（匹配失败）或其他错误情况，导致可能未检测到输入错误，违反CWE-252原则。
- D验证: stage_c_preserved / ver_cab28f23
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 184. hyp_path_ad58685e03cb

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_08.c:91
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供导致 scanf 返回非 EOF 错误值的输入（如不匹配格式的输入或输入错误）
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_08.c:91
- 结论: 对 scanf 返回值的检查不完整，仅处理 EOF 错误，未处理其他错误情况（如返回值不为 1），违反 CWE-252。
- D验证: stage_c_preserved / ver_f7b8111d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 185. hyp_path_748187fed856

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_07.c:64
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制输入流，提供不匹配格式的输入（如仅空白或空字符串）使scanf返回0。
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_07.c:64
- 结论: 未完整检查scanf返回值：仅检查EOF而忽略返回0（未匹配任何项）的情况，导致可能使用未正确初始化的dataBuffer，违反CWE-252。
- D验证: stage_c_preserved / ver_c32b4e8d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 186. hyp_path_74e9c65d0a4f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_05.c:65
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供输入，导致 scanf 返回 0（未成功匹配），而 data 未初始化或包含之前数据
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ 65
- 结论: 存在未完全检查 scanf 返回值的路径，可能导致 CWE-252 未检查返回值漏洞
- D验证: stage_c_preserved / ver_4aeb39f1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 187. hyp_path_b05c301ebb29

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_10.c:59
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供输入导致scanf返回0（例如输入空字符串或非字符串数据，不匹配%99s格式）。
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_10.c:59
- 结论: scanf返回值检查不完整：仅检查了EOF，未检查返回值是否为1（成功匹配项数），导致输入不匹配格式说明符时（返回0）错误被忽略，dataBuffer可能未初始化而被后续使用。
- D验证: stage_c_preserved / ver_ae5a48a4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 188. hyp_path_641437fbd8f5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_13.c:59
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 用户输入不匹配%99s格式（例如仅输入空白），导致scanf返回0。
- 触发路径: if (scanf("%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_13.c:59
- 结论: 在scanf调用后，仅检查了返回值为EOF的情况，未检查返回值是否为0（无输入匹配），导致data变量可能未初始化，但后续代码未使用data，因此漏洞存在但实际影响较低。
- D验证: stage_c_preserved / ver_7221575b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 189. hyp_path_cca844278fcf

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_11.c:78
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供不匹配的输入（如非空白字符模式），导致scanf返回0；存在后续使用data的代码路径（当前代码片段无，但需考虑扩展上下文）
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_11.c:78
- 结论: 对scanf的返回值检查不完整：仅检查了EOF错误，但未检查成功读取的项目数是否为1（scanf返回0表示输入不匹配）。虽然当前代码片段无后续使用data，但若在其他调用上下文中存在后续使用时，可能导致未定义行为或信息泄露。
- D验证: stage_c_preserved / ver_2aab54a3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 190. hyp_path_283fe83c2345

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_14.c:59
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供输入使scanf返回0（例如空输入或非字符串内容）
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_14.c:59
- 结论: scanf返回值检查不完整：仅检查了EOF错误，未检查scanf是否成功读取了一个字符串（正常应返回1）。如果scanf返回0（例如空输入或格式不匹配），程序不会检测到错误，可能使用未修改的dataBuffer，导致未定义行为或逻辑错误。
- D验证: stage_c_preserved / ver_07f06456
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 191. hyp_path_c9a18877183b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_11.c:86
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC字符串的内容和长度，使其在拼接后超过缓冲区剩余大小（100-strlen(SRC)-1），导致snprintf截断。注意：虽然当前代码片段未明确展示SRC来自外部输入，但常见Juliet测试用例中SRC由常量定义或可能来自环境变量，实际利用需SRC可控；若SRC不可控，则漏洞影响有限。
- 触发路径: if (SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC) < 0) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_11.c:86
- 结论: snprintf的返回值检查不完整：仅检查返回值是否小于0，而未检查是否发生截断（即返回值大于等于缓冲区大小）。当snprintf因缓冲区不足而截断时，返回值为应写入的字符数（非负数），导致截断未被检测到，可能造成数据丢失或信息泄露。
- D验证: stage_c_preserved / ver_191b6880
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 192. hyp_path_1d6d0216dc55

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_08.c:93
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC输入，导致sscanf无法匹配格式（如空字符串或非空白字符序列），使返回值不为EOF而成功读取项数少于1
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_08.c:93
- 结论: sscanf返回值检查不充分：仅检查返回值是否为EOF，而未检查是否成功读取了一个项（返回值应为1）。若sscanf返回0（如输入为空或格式不匹配），则dataBuffer可能保持未初始化状态，导致未定义行为。
- D验证: stage_c_preserved / ver_95ebc413
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 193. hyp_path_1c48246d9940

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_14.c:67
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC字符串的内容或长度，可能导致snprintf截断。
- 触发路径: SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_14.c:67; if (SNPRINTF(...) < 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_14.c:67
- 结论: snprintf的返回值检查不完整：仅检查了返回值<0的错误情况，未检查因目标缓冲区不足导致的截断（snprintf返回大于等于缓冲区大小的值）。虽然当前代码中未引发直接的安全后果，但违反了预期API契约，可能在某些场景下导致数据丢失或逻辑错误。
- D验证: stage_c_preserved / ver_4ad1fbd7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 194. hyp_path_f0514013ec45

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_07.c:66
- 漏洞类型: CWE-252, CWE-253
- CWE: CWE-252; CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC输入字符串
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_07.c:66; 仅检查返回值是否为EOF，未检查是否等于1 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_07.c:66; 使用data变量（如printLine或其它操作） @ 后续代码（缺失，可能调用printLine或其他操作）
- 结论: 对sscanf返回值的检查不完整，仅检查了EOF，而未检查返回值是否等于期望的匹配数（1）。如果输入字符串不符合格式（如空字符串或非数字），sscanf可能返回0，此时dataBuffer未被写入有效数据（可能保持空字符串或未初始化），后续使用data可能导致逻辑错误或信息泄露。
- D验证: stage_c_preserved / ver_9b6aa054
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 195. hyp_path_2db23bdcd876

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_09.c:61
- 漏洞类型: CWE-252, CWE-253
- CWE: CWE-252; CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响SRC的内容（例如通过环境变量、输入文件或网络数据），使sscanf返回0（匹配失败）。
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_09.c:61
- 结论: sscanf返回值检查不完整，仅检查EOF，忽略了匹配失败（返回0）的情况，违反API contract；但代码证据中未显示对dataBuffer的后续使用，无法确认实际内存访问路径，需进一步动态验证或审计确认是否存在sink点。
- D验证: stage_c_preserved / ver_904c906e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 196. hyp_path_0b4077f0b5d0

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_13.c:61
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制sscanf的输入源SRC，使其格式不匹配（如空字符串或非空白字符），导致sscanf返回0，但攻击者不能触发EOF
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_13.c:61
- 结论: sscanf返回值检查不完整：仅检查了返回值是否为EOF，未检查返回值为0（未匹配到任何输入项）的情况。存在违反CWE-252的API contract violation，但证据中未显示后续使用data的sink，因此无法确认未初始化变量使用（CWE-457）的实际路径。
- D验证: stage_c_preserved / ver_368df227
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 197. hyp_path_6a80a775aecf

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_08.c:91
- 漏洞类型: CWE-252, CWE-253
- CWE: CWE-252; CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向stdin提供特定输入（如空字符串或格式不匹配的字符），使fwscanf返回0而非EOF。
- 触发路径: wchar_t * data = dataBuffer; if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_08.c:89-93
- 结论: 函数fwscanf返回值仅检查了EOF，未检查是否成功读取了预期的1个匹配项。当输入不匹配时，fwscanf返回0，程序不进入错误处理分支，dataBuffer保持未初始化。后续代码可能使用未初始化的dataBuffer（如通过wprintf输出），导致未初始化内存读取。由于sink代码未在当前片段中明确展示，证据不完全闭合。
- D验证: stage_c_preserved / ver_79c086be
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 198. hyp_path_0d9bc6f390ca

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_05.c:65
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入传入数据，使得fwscanf返回0（例如仅输入空白字符）或非EOF错误值
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_05.c:65
- 结论: 在CWE252_Unchecked_Return_Value__wchar_t_fscanf_05.c的case11中，fwscanf返回值检查不完整：仅检查了EOF，未处理返回0（匹配失败）或其他负值。这构成CWE-252违反，但由于代码中缺少对data后续使用的证据，实际危害路径未闭合。
- D验证: stage_c_preserved / ver_dcb94283
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 199. hyp_path_b0f0fce904f8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_10.c:59
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供输入使得fwscanf返回0（格式匹配失败）
- 触发路径: 入口 @ CWE252_Unchecked_Return_Value__wchar_t_fscanf_10.c:44; if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ CWE252_Unchecked_Return_Value__wchar_t_fscanf_10.c:59
- 结论: CWE252: Unchecked Return Value - fwscanf failure not fully handled, return value 0 (input mismatch) is not checked, violating API contract; although no immediate use of uninitialized data is evident in the provided snippet, the unchecked return value alone constitutes a vulnerability per CWE definition.
- D验证: stage_c_preserved / ver_2fdeefe8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 200. hyp_path_d851a91b65cb

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_11.c:78
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供导致匹配失败但不触发EOF的输入（例如非空白字符但格式不匹配）。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_11.c:78
- 结论: fwscanf返回值检查不完整：仅检查是否等于EOF，但未处理匹配失败（返回0或小于预期项数）的情况，导致未检测到输入错误。
- D验证: stage_c_preserved / ver_bd5e2728
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 201. hyp_path_1b30c55475c8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_07.c:64
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入，使得fwscanf返回0（如空输入但不触发EOF）。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_07.c:64
- 结论: 对fwscanf返回值检查不完整，仅检查EOF，未检查是否成功读取到预期项数（返回1），违反CWE-252。但当前代码中data变量后续未被使用，无直接安全影响，属于不良实践。
- D验证: stage_c_preserved / ver_069fd2b5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 202. hyp_path_2e284f21babd

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_14.c:54
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: No external input control required; the function is called with a string literal but CWE-252 mandates checking return value regardless of input source.
- 触发路径: PUTS(L"string"); // no return value check @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_14.c:54-58 (else branch, not shown but implied by dead code marker)
- 结论: VULNERABILITY: Unchecked return value of PUTS (likely _putws) in the actual execution path; the checked branch is dead code per CWE 561 comment
- D验证: stage_c_preserved / ver_f9ad7c4d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 203. hyp_path_097ce47b3400

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_09.c:54
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 全局变量或输入控制选择bad分支
- 触发路径: REMOVE(L"removemecase1.txt"); // 无返回值检查 @ 推测为bad分支所在位置，但未在提供的代码片段中显式出现，可能位于同一源文件的其他函数或switch case中
- 结论: 在bad分支中可能存在未检查返回值的REMOVE调用，导致删除失败状态被忽略，但当前代码证据仅显示good分支中的返回值检查。
- D验证: stage_c_preserved / ver_9c5dddd8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 204. hyp_path_7835a7226b77

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_05.c:65
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入使得wscanf返回0（例如输入仅空白字符或空行）。; dataBuffer未初始化或包含敏感数据，且data在后续代码中被使用（需动态验证）。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_05.c:65
- 结论: wscanf返回值检查不完整：仅检查EOF，未检查返回0（无匹配项）的情况，导致data可能未更新，违反CWE-252。
- D验证: stage_c_preserved / ver_9f2a281a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 205. hyp_path_a1f19b605470

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_09.c:59
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: Attacker provides input consisting only of whitespace or empty input, causing wscanf to return 0 instead of EOF
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_09.c:59
- 结论: CWE-252: Unchecked Return Value - wscanf return value checked only for EOF, not for 0 (no match), leaving data buffer uninitialized on empty input.
- D验证: stage_c_preserved / ver_d8afdfaa
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 206. hyp_path_41ed7fd1acff

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_07.c:64
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: Attacker can provide input to the program that triggers wscanf, resulting in return value other than 1 or EOF
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ L64
- 结论: API misuse - incomplete check of wscanf return value, only checking for EOF but not for successful assignment count
- D验证: stage_c_preserved / ver_dc1992e8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 207. hyp_path_52937c685bed

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_10.c:59
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供导致wscanf返回0的输入（如空行或无效字符）
- 触发路径: if (wscanf(L"%99s", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_10.c:59
- 结论: 函数wscanf的返回值检查不完整：仅检查了EOF错误，未处理返回值为0（匹配失败或未赋值）的情况。若wscanf返回0，数据缓冲区dataBuffer可能保持未初始化状态，但当前代码片段中未发现后续使用dataBuffer的路径，导致漏洞可利用性较低，需动态验证确认是否存在实际影响。
- D验证: stage_c_preserved / ver_e0a7fa6c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 208. hyp_path_896266449bdc

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_13.c:59
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供不匹配%99s格式的输入（例如空输入或仅空白字符），导致wscanf返回0而非EOF。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_13.c:59
- 结论: wscanf返回值检查不完整：仅检查了EOF，未检查返回0的情况，违反了CWE-252（Unchecked Return Value）。但代码中无后续读取dataBuffer的sink，因此可利用性较低，需动态验证或审计以确认是否存在隐式使用或扩展路径。
- D验证: stage_c_preserved / ver_4545da06
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 209. hyp_path_ce5410e7844a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_14.c:67
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响SRC内容或程序环境导致SNPRINTF失败（如缓冲区空间不足）
- 触发路径: wchar_t * data = dataBuffer; if (SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC) < 0) { printLine("snwprintf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_14.c:65-67
- 结论: SNPRINTF返回值已检查但错误处理仅打印消息，未终止操作或传播错误，违反CWE-252要求。虽然后续未使用dataBuffer，但根据CWE定义，不充分的错误处理仍构成漏洞。
- D验证: stage_c_preserved / ver_2c4dc775
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 210. hyp_path_907793c6a60d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_13.c:67
- 漏洞类型: CWE-252, CWE-253
- CWE: CWE-252; CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC字符串长度，使其超过缓冲区剩余大小（当前不满足，因SRC为常量）
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC) < 0) { printLine("snwprintf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_13.c:67
- 结论: snprintf返回值检查不完整（仅检查<0，未检查截断），但当前代码中SRC为固定字符串，攻击者无法控制其长度，因此实际可利用性极低。技术合同违反存在，但无实际攻击路径。
- D验证: stage_c_preserved / ver_2fcb7ad2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 211. hyp_path_5f2099e091a6

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_10.c:61
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC的值，使swscanf返回0（例如输入空字符串或格式不匹配），而不返回EOF。
- 触发路径: 调用case11，传入SRC和dataBuffer @ L46（入口）; if (swscanf(SRC, L"%99s\0", data) == EOF) { ... } @ L61; printLine("swscanf failed!"); // 仅处理EOF，未处理返回0 @ L63
- 结论: swscanf返回值检查不完整，仅检查了EOF，未处理返回0的情况。当swscanf返回0时，data变量未被写入，后续使用可能导致未初始化内存读取或逻辑错误，构成CWE-252未检查返回值漏洞。
- D验证: stage_c_preserved / ver_6ae42488
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 212. hyp_path_e8bd86a460e7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_13.c:61
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC输入，使swscanf返回0（例如输入空字符串或不匹配的格式）; dataBuffer为局部变量，未显式初始化; 后续代码使用了data变量（在提供的代码片段未明确展示，但基于CWE测试样例预期存在）
- 触发路径: wchar_t * data = dataBuffer; if (swscanf(SRC, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_13.c:59-61
- 结论: 程序未完整检查swscanf返回值，仅检查是否等于EOF，未处理返回0（无匹配）的情况。若swscanf返回0，dataBuffer未被更新且局部变量未初始化，后续使用data变量将导致未初始化内存读取。
- D验证: stage_c_preserved / ver_57edf6d8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 213. hyp_path_0c108cea27cc

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_11.c:80
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制输入SRC，使得swscanf返回0
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_11.c:80
- 结论: 对swscanf的返回值检查不完整：仅检查了EOF，未检查返回值为0的情况。当swscanf返回0时，dataBuffer未被写入，但后续未使用data，因此未初始化变量使用不成立。然而，返回值检查不完整仍构成CWE-252违规，但当前代码路径无后续使用，潜在影响较低。
- D验证: stage_c_preserved / ver_64802198
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 214. hyp_path_176ad5d5414a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_03.c:78
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供不符合%99s格式的输入，导致fscanf返回0而非EOF。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_03.c:78
- 结论: fscanf返回值检查不完整：仅检查EOF，未处理返回0（格式不匹配）的情况，违反CWE-252。尽管data未被后续使用且dataBuffer通常初始化为空字符串，降低了未初始化数据风险，但API契约违规依然存在，可能在某些实现或变异场景下产生影响。
- D验证: stage_c_preserved / ver_32ca0d3b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 215. hyp_path_01c00d129af7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_02.c:59
- 漏洞类型: CWE-252, CWE-253
- CWE: CWE-252; CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供使fscanf返回0的输入（如空字符串或格式不匹配的数据）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_02.c:59
- 结论: fscanf返回值检查不完整：仅检查EOF，忽略返回0的情况（格式匹配失败），违反了CWE-252。虽然当前代码中未初始化的dataBuffer未被后续使用，但返回值检查本身不完整，构成API misuse。
- D验证: stage_c_preserved / ver_175195f6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 216. hyp_path_ede0f0c65461

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_04.c:65
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin输入导致fscanf返回0（例如空字符串或格式不匹配）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_04.c:65; printLine("fscanf failed!");} // 仅处理EOF，未处理返回0等情况 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_04.c:66-67
- 结论: fscanf返回值检查不完整：仅检查EOF而忽略返回0等其他失败情况，构成CWE-252未完全检查返回值漏洞。但由于dataBuffer已初始化为空字符串且后续未使用data，实际可利用性极低。
- D验证: stage_c_preserved / ver_faacbba3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 217. hyp_path_5c66aace4d37

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_03.c:59
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够向stdin提供仅含空白或空输入，使fscanf返回0。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_03.c:59
- 结论: fscanf返回值检查不完整：仅处理EOF，未处理返回0的情况。虽然dataBuffer已初始化为空字符串，不存在未初始化问题，但API misuse仍然存在，属于CWE-253。但由于代码片段中未显示后续使用data，漏洞路径未闭合，实际影响较低。
- D验证: stage_c_preserved / ver_1b1c51e3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 218. hyp_path_7422c731be18

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_04.c:84
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够向stdin提供输入，使得fscanf返回0（例如输入为空行或仅空白字符）。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_04.c:84; 后续使用data（例如打印或传递给其他函数） @ 后续代码（未完全显示，猜测在85行之后使用data变量）
- 结论: fscanf返回值检查不完整：仅检查了EOF，但未检查返回值是否为1（成功读取一个字符串）。当输入不匹配%99s格式（例如输入为空行或仅空白字符）时，fscanf返回0，data保持未初始化值，后续使用data可能导致未初始化数据泄露或其他未定义行为，违反CWE-252对返回值完整检查的要求。
- D验证: stage_c_preserved / ver_f0c8eee0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 219. hyp_path_e5285f36c284

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_05.c:84
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供不符合"%99s"格式的输入，例如空行或仅空白字符。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_05.c:84
- 结论: fscanf返回值检查不完整：仅检查EOF，未检查返回值是否等于1，导致输入不匹配格式时data未更新，使用未初始化数据。
- D验证: stage_c_preserved / ver_6d6fe92d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 220. hyp_path_c736fb8a1a35

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_06.c:83
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够向stdin输入仅包含空白字符的字符串（如空格、制表符），导致fscanf返回0而非EOF
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_06.c:83; printLine("fscanf failed!"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_06.c:85
- 结论: 函数fscanf的返回值未完全检查：仅当返回EOF时处理错误，未检查返回0（表示匹配失败）的情况。当用户输入仅包含空白字符时，fscanf返回0，dataBuffer未被写入有效数据，后续使用dataBuffer可能导致未初始化数据读取或逻辑错误。
- D验证: stage_c_preserved / ver_d224cd72
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 221. hyp_path_c56661375952

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_09.c:78
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可以提供输入导致fscanf匹配失败（如输入非空格字符串），此时返回值为0，但代码未检查，data可能未更新。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ L78
- 结论: VULNERABILITY_FOUND: CWE252 Unchecked Return Value - fscanf return value not properly checked; only checks for EOF, but not for other error conditions (e.g., matching failure).
- D验证: stage_c_preserved / ver_92205e00
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 222. hyp_path_bd9b32c74f6e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_10.c:78
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够向stdin提供不匹配格式的输入
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_10.c:78
- 结论: fscanf返回值检查不完整：仅检查EOF，未检查返回值为0（表示未匹配到任何输入）的情况，可能导致未初始化的data被后续使用，违反CWE-252。
- D验证: stage_c_preserved / ver_902ffd5c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 223. hyp_path_214fed5cd6b7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_14.c:78
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够向stdin提供输入，使得fscanf匹配失败（返回0），且后续存在对dataBuffer的读取操作
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_14.c:78
- 结论: fscanf返回值检查不完整：仅检查EOF，未检查返回0（匹配失败）的情况。若后续存在对dataBuffer的读取操作，可能导致使用未初始化数据，但目前证据未展示后续sink路径。
- D验证: stage_c_preserved / ver_219b943b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 224. hyp_path_65dbd9c480bd

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_13.c:78
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入，使得fscanf返回0（例如输入为空或格式不匹配）。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ 78
- 结论: fscanf返回值检查不完整：仅检查了EOF（-1），未检查是否成功读取了期望的一个字符串（返回值应为1）。若fscanf返回0（例如输入流为空或格式不匹配），则dataBuffer可能未被正确赋值，导致后续使用未初始化或错误数据。
- D验证: stage_c_preserved / ver_b5470f7c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 225. hyp_path_ec18639744bf

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_15.c:86
- 漏洞类型: CWE-252, CWE-253
- CWE: CWE-252; CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使其无法匹配"%99s"格式（例如输入空字符串或仅空白字符导致匹配数为0）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_15.c:86
- 结论: 代码对fscanf的返回值检查不完整：仅检查了是否为EOF，但未处理返回0的情况（输入不匹配格式）。当fscanf返回0时，data未写入有效数据，后续使用data可能导致未初始化数据读取或程序行为异常。
- D验证: stage_c_preserved / ver_dc49a548
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 226. hyp_path_959a6893c0e8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_16.c:55
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供特殊输入（如空输入或格式不匹配的输入），导致fscanf返回0，绕过EOF检查。; 后续必须存在使用data缓冲区的代码路径（未在当前触发路径中显式展示，但典型场景下存在）。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_16.c:55
- 结论: fscanf返回值检查不完整：仅检查EOF，未检查返回0的情况。若后续存在使用data缓冲区的代码，则可能使用未写入数据的缓冲区，违反CWE-252。但当前证据未展示后续sink位置，需进一步确认。
- D验证: stage_c_preserved / ver_6a39dded
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 227. hyp_path_aa2785005cf2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_18.c:53
- 漏洞类型: CWE-252, CWE-253
- CWE: CWE-252; CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入，使得 fscanf 返回 0（例如输入空行或无法匹配 %99s 的数据）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_18.c:53
- 结论: 未正确检查 fscanf 的返回值：仅检查了 EOF 失败情况，未检查返回值为 0（即未成功读取任何项）的情况，可能导致 data 未更新或后续使用未初始化数据。
- D验证: stage_c_preserved / ver_ffd750f3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 228. hyp_path_9ad549a979d5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_15.c:65
- 漏洞类型: CWE-252, CWE-456
- CWE: CWE-252; CWE-456
- 风险等级: P1
- 触发条件: 攻击者能向stdin输入EOF（如Ctrl+D）或任何导致fscanf失败并返回EOF的输入，使得dataBuffer未被修改且仍为未初始化状态。
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_15.c:65; printLine(data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_15.c:67
- 结论: fscanf返回值未完全检查：当fscanf返回EOF时，程序仅打印错误消息，未阻止后续使用未初始化的dataBuffer，导致未初始化数据被printLine使用。攻击者可提供EOF（如Ctrl+D）触发此路径。
- D验证: stage_c_preserved / ver_b2f8d829
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 229. hyp_path_6f21a5c11b28

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_02.c:59
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: The attacker provides input that causes scanf to return 0 (e.g., an empty input or a non-matching input) or any value other than 1, leaving the data buffer uninitialized or containing unpredictable content.
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_02.c:59; data is subsequently used without verifying that scanf returned 1 (e.g., implicitly via program flow) @ after the if block (line 61 onwards)
- 结论: The code checks only for EOF return from scanf, but does not verify that scanf successfully read exactly one item. If scanf returns 0 (input matching failure) or a positive value less than 1, the data buffer may remain uninitialized or contain stale data, violating the API contract and CWE-252.
- D验证: stage_c_preserved / ver_f7a735b6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 230. hyp_path_75b0ed3c79c4

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_01.c:48
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入，提供导致scanf返回0的输入（如非字符串）
- 触发路径: if (scanf("%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_01.c:48; 仅检查EOF，未检查返回值是否为1，当scanf返回0时data内容未定义。 @ 同上
- 结论: 存在CWE-252未充分检查scanf返回值，但后续未使用data变量，导致实际安全影响较低。
- D验证: stage_c_preserved / ver_c840188e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 231. hyp_path_1549ebf02961

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_03.c:78
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供不匹配%99s格式的输入（例如空输入或非字符串），使scanf返回0而非EOF，导致dataBuffer保持未初始化状态。
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_03.c:78
- 结论: CWE252: Unchecked Return Value - scanf返回值仅检查EOF，未检查返回0（匹配失败）的情况，导致当输入不匹配时dataBuffer内容未更新且未经检测，后续使用可能触发未初始化数据行为。
- D验证: stage_c_preserved / ver_85d1f933
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 232. hyp_path_6d54fd8b59f1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_04.c:65
- 漏洞类型: CWE-252, CWE-754
- CWE: CWE-252; CWE-754
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入，并提供一个使scanf返回0的输入（例如空字符串或仅空白）。
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_04.c:65
- 结论: 在scanf调用中，仅检查返回值是否为EOF，而未检查返回值是否等于期望的匹配项数（1），导致scanf可能返回0（表示未匹配到任何输入）时未被处理，违反CWE-252和CWE-754。但由于后续未使用scanf写入的数据，实际利用性较低。
- D验证: stage_c_preserved / ver_c4aad5d6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 233. hyp_path_8223980e18c3

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_04.c:84
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供不匹配 %s 格式的输入（如空行、空白或无效字符），使 scanf 返回 0。
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_04.c:84; 未知 @ 假设后续代码使用 data（例如 printLine(data) 或字符串操作），未在提供片段中明确显示
- 结论: 在 scanf 返回值为 0（匹配失败）时，dataBuffer 未被有效初始化，若后续代码（如 printLine）使用 data，则可能导致未初始化数据访问。
- D验证: stage_c_preserved / ver_543cfb2e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 234. hyp_path_8bd6be2b6927

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_06.c:64
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供空白字符输入（仅空格、制表符或换行符），导致 scanf 返回 0 而非 EOF，从而绕过失败检查。
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_06.c:64
- 结论: 对 scanf 返回值的检查不完整：代码仅检查了 EOF（返回值为 -1），但未处理返回值为 0 的情况（表示未成功匹配任何输入项）。当输入为空白字符时，scanf 返回 0，dataBuffer 保持未初始化状态，导致未初始化变量读取风险。违反了 CWE-252 中要求全面检查函数返回值的原则。
- D验证: stage_c_preserved / ver_1d39228a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 235. hyp_path_b673e56205ac

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_07.c:83
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入，提供导致scanf返回0的输入（如空行或非匹配字符）
- 触发路径: if (scanf("%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_07.c:83
- 结论: 代码检查了scanf返回值是否等于EOF，但未检查返回值是否为1（成功读取一个项）。当scanf返回0（例如输入为空行或格式不匹配）时，dataBuffer未被写入，后续使用未初始化的data将导致未定义行为，违反了CWE-252要求完全检查返回值的规定。
- D验证: stage_c_preserved / ver_0e9f83b2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 236. hyp_path_5f299f7bb558

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_09.c:78
- 漏洞类型: CWE-252, CWE-253
- CWE: CWE-252; CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供导致 scanf 返回 0 的输入（例如仅输入空白字符后立即结束文件，或输入流处于错误状态但未触发 EOF）。
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_09.c:78; 仅检查 EOF，未处理返回 0 的情况。 @ 同上; char * data = dataBuffer; // dataBuffer 可能未初始化 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_09.c:76
- 结论: 对 scanf 的返回值检查不完整：仅检查了返回 EOF 的情况，未检查返回为 0（表示没有成功匹配任何输入项）的情况。当用户输入不匹配（如空输入或格式错误）时，scanf 返回 0，但代码不会执行错误处理，导致 data 可能包含未初始化的内容（若 dataBuffer 未初始化）或上次残留数据，构成潜在的内存或逻辑安全问题。
- D验证: stage_c_preserved / ver_cd05b30e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 237. hyp_path_3e6c39f0751f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_13.c:78
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够使输入不匹配格式（如空字符串或非字符串内容），导致scanf返回0
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_13.c:78
- 结论: 代码调用了scanf，但仅检查返回值是否为EOF，未检查是否等于1（期望的匹配项数）。若scanf返回0（例如输入不匹配格式），data缓冲区可能未正确初始化，但当前代码片段中未显示后续使用data的sink，路径不完整。
- D验证: stage_c_preserved / ver_c6a30169
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 238. hyp_path_c8f75db6aaf5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_15.c:65
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供任意数据，使得scanf返回非EOF的值（例如0，表示未匹配任何项）
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_15.c:65
- 结论: 存在CWE-252漏洞：scanf返回值未完全检查，仅检查EOF，未处理返回0或其它非EOF值的情况，攻击者可提供不匹配的输入导致scanf返回0，程序未处理，可能导致后续逻辑错误或使用未初始化数据。
- D验证: stage_c_preserved / ver_8f7596e5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 239. hyp_path_4867c98b0994

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_14.c:78
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制输入使scanf返回0（如输入空白字符或空串）
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_14.c:78
- 结论: 对scanf的返回值检查不完整，仅检查EOF，未处理返回0的情况。若scanf返回0，dataBuffer内容未更新，后续使用data可能导致使用未初始化内存。
- D验证: stage_c_preserved / ver_46424123
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 240. hyp_path_b7b6b2f759ec

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_10.c:78
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供空字符串或空格使scanf返回0
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_10.c:78
- 结论: 存在CWE-252 API misuse：对scanf的返回值检查不完整，仅检查了EOF，未处理返回0的情况，违反了安全编码规范。但当前代码片段未显示后续使用dataBuffer，因此无法确认未初始化变量使用的实际路径。
- D验证: stage_c_preserved / ver_a4afdc7d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 241. hyp_path_bb1c6084ffb5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_16.c:55
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: Attacker provides input that causes scanf to return a value other than 1 or EOF (e.g., 0 due to matching failure)
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_16.c:55
- 结论: Incomplete check of scanf return value: only checks for EOF, ignores other return values indicating failure or mismatch, violating CWE-252.
- D验证: stage_c_preserved / ver_e193772d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 242. hyp_path_0dbbe322b9d6

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_02.c:67
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC字符串长度，使snprintf返回值非负但小于预期写入长度（如数据被截断）
- 触发路径: if (SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC) < 0) @ L67
- 结论: 存在CWE-252未检查返回值漏洞（弱）：snprintf返回值仅检查负值错误，未检查写入字符数是否满足预期，可能导致数据截断不被发现。
- D验证: stage_c_preserved / ver_763fbccb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 243. hyp_path_3ff508dba26a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_15.c:86
- 漏洞类型: buffer_overflow
- CWE: CWE-252; CWE-120
- 风险等级: P1
- 触发条件: 攻击者能提供输入使scanf返回0（如空白输入）或输入长度超过dataBuffer容量（如果小于99）
- 触发路径: if (scanf("%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_15.c:86
- 结论: scanf函数返回值检查不完整，仅检查EOF，未处理返回值0的情况；同时dataBuffer大小未指定，若小于99则存在缓冲区溢出风险，导致未初始化使用或缓冲区溢出。
- D验证: stage_c_preserved / ver_0adf7c56
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 244. hyp_path_91fe86c2fc6f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_03.c:86
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者无法控制SRC（SRC为固定字符串常量）
- 触发路径: if (SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC) < 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_03.c:86
- 结论: CWE-253: Incorrect Check of Return Value - snprintf返回值检查不完整，仅检查了负值错误，未检查截断情况（返回值>=缓冲区大小）。但实际SRC为固定字符串，攻击者无法控制，因此无实际可利用路径。
- D验证: stage_c_preserved / ver_3a94cf65
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 245. hyp_path_f8cd3c304864

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_04.c:73
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入字符串SRC的内容和长度
- 触发路径: if (SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC) < 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_04.c:73
- 结论: snprintf返回值检查不完整：只检查负值错误，未检查正值截断（返回值小于期望写入长度）。尽管存在API misuse，但后续仅将data用于printLine输出，未涉及安全敏感操作，因此可利用性低，但仍违反CWE-253定义。
- D验证: stage_c_preserved / ver_1d049afe
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 246. hyp_path_e094506bfd0b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_06.c:91
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC的长度，使其大于缓冲区剩余空间（100-strlen(SRC)-1），造成截断; SRC的长度确为攻击者可控（证据中未明确，但测试用例下可能存在输入机制）
- 触发路径: if (SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC) < 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_06.c:91
- 结论: snprintf返回值检查不完整，仅检查失败（返回<0），未检测可能的数据截断（返回值>=size），违反了CWE-252对返回值的正确检查要求。虽然SRC的可控性未确认，但若SRC长度可控且足够大，可能导致缓冲区截断，后续使用截断后的数据可能引发安全问题。
- D验证: stage_c_preserved / ver_6ae260fc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 247. hyp_path_4c477a70b5f6

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_10.c:86
- 漏洞类型: CWE-252, CWE-253
- CWE: CWE-252; CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入字符串SRC的长度，使其导致snprintf返回值大于等于缓冲区大小（即发生截断）。
- 触发路径: if (SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC) < 0) { printLine("snprintf failed!"); } @ 86
- 结论: snprintf的返回值检查不完整：仅检查返回值为负的情况，未检查返回值为正且大于等于缓冲区大小的情况（即截断），违反API契约。
- D验证: stage_c_preserved / ver_f9592be3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 248. hyp_path_6aa3ff41136a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_14.c:86
- 漏洞类型: CWE-252, CWE-253
- CWE: CWE-252; CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC字符串的长度，使其大于 (100 - strlen(SRC) - 1) 即导致截断。但由于SRC长度同时用于自身，实际需要满足 strlen(SRC) > 99，即SRC长度超过99字符。需证据表明SRC来自外部输入，而非固定常量。
- 触发路径: if (SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC) < 0) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_14.c:86; 检查仅对负值处理，未检查截断情况；截断发生后数据不完整，但未采取任何措施。 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_14.c:86-88
- 结论: 对snprintf的返回值检查不完整：仅检查了负值（错误），未检查返回值是否等于或大于目标缓冲区大小（截断情况）。当snprintf返回值非负但小于缓冲区大小时，数据被截断而未报告，可能导致隐蔽信息丢失或逻辑错误。
- D验证: stage_c_preserved / ver_13cd1677
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 249. hyp_path_83104d306561

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_07.c:91
- 漏洞类型: integer_overflow
- CWE: CWE-252; CWE-190; CWE-121
- 风险等级: P1
- 触发条件: SRC长度固定为150，导致100-strlen(SRC)-1计算为负，作为size_t回绕为极大值；该条件由代码静态决定，无需攻击者控制。
- 触发路径: if (SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC) < 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_07.c:91; snprintf因size_t参数巨大，实际写入超过100字节，覆盖栈上后续内存 @ same
- 结论: 由于strlen(SRC)大于100，计算snprintf第二个参数时发生整数回绕，导致size_t参数变为巨大值，snprintf写入超出栈缓冲区dataBuffer[100]的数据，造成栈缓冲区溢出。SRC固定长度为150，每次调用均触发，可覆盖栈上关键数据（如返回地址），可能导致代码执行。
- D验证: stage_c_preserved / ver_b1546aa6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 250. hyp_path_ab46d45baac5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_01.c:50
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制输入字符串（SRC）的内容。
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_01.c:50
- 结论: sscanf返回值检查不充分：仅检查是否等于EOF，未检查返回值是否等于期望的匹配项数（1）。当输入为空字符串或格式不匹配时，sscanf返回0，导致dataBuffer未写入数据，后续使用未初始化内存，可能造成信息泄露或未定义行为。
- D验证: stage_c_preserved / ver_abb9fd12
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 251. hyp_path_62a034d184c0

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_02.c:61
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者提供导致sscanf返回0（而非EOF）的输入，例如空字符串或非空白字符序列（格式%99s不匹配）。
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_02.c:61
- 结论: sscanf返回值检查不完整：仅检查EOF，未检查返回值是否等于1（预期匹配项数）。当输入格式不匹配时，sscanf返回0，程序误认为操作成功，可能使用未正确初始化的数据。
- D验证: stage_c_preserved / ver_a2eb09e1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 252. hyp_path_2e52c52247a9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_04.c:67
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC内容，使其不匹配"%99s"格式（如空字符串或非字符串输入），导致sscanf返回0。
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_04.c:67
- 结论: sscanf返回值检查不完整：仅检查EOF，未检查返回值是否等于1。当输入不匹配"%99s"格式时，sscanf可能返回0，导致dataBuffer保持未初始化，后续使用可能导致信息泄露或未定义行为。
- D验证: stage_c_preserved / ver_d3c79402
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 253. hyp_path_2cce49f90acb

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_03.c:80
- 漏洞类型: CWE-253, CWE-457
- CWE: CWE-253; CWE-457
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC字符串内容，使其导致sscanf返回0（例如输入空字符串或仅空白）; dataBuffer为局部变量且未显式初始化（基于代码片段未显示初始化）
- 触发路径: char * data = dataBuffer; if (sscanf(SRC, "%99s\0", data) == EOF) { ... } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_03.c:78-80; 缺少对sscanf返回0的检查，导致data未更新且dataBuffer未初始化 @ 同文件，sscanf返回0时未处理
- 结论: sscanf返回值检查不完整：仅检查EOF，未检查返回0（未匹配任何输入）的情况。若sscanf返回0且dataBuffer为局部未初始化变量，后续使用data可能导致使用未初始化变量，违反CWE-253和CWE-457。
- D验证: stage_c_preserved / ver_58edf82a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 254. hyp_path_8fd2d9914c59

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_04.c:86
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制或影响sscanf的输入源SRC（例如通过环境变量、输入流等）使其产生返回值为0的输入。
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_04.c:86
- 结论: CWE252: Unchecked Return Value - sscanf返回值检查不完整，仅检查EOF而未检查返回0的情况。若sscanf因输入为空或匹配失败返回0，则data缓冲区内容未更新（可能残留未初始化数据），但当前代码片段中data变量未被后续使用，因此利用路径不完整。
- D验证: stage_c_preserved / ver_325bc267
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 255. hyp_path_9125ecd32031

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_05.c:86
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC输入，使其导致sscanf返回0（例如空字符串）
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_05.c:86
- 结论: sscanf返回值检查不完整：仅检查了EOF，未处理返回值小于期望匹配项数（如0）的情况，可能导致后续处理使用未正确初始化的数据。
- D验证: stage_c_preserved / ver_9f53667d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 256. hyp_path_ad5233971d29

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_10.c:80
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制 SRC 输入，使其导致 sscanf 匹配失败（如输入空字符串或不匹配格式），但返回值为0而非 EOF。
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_10.c:80
- 结论: CWE252 未检查返回值：对 sscanf 的返回值检查不完整，仅检查是否返回 EOF，但未检查是否成功读取了期望的数据（返回值应为1）。如果 sscanf 返回0（匹配失败），则 data 变量内容未定义，后续使用可能导致不可预期行为。
- D验证: stage_c_preserved / ver_3ca229a1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 257. hyp_path_f2b12a9f2aa7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_06.c:85
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够向SRC提供输入字符串，使其不符合"%99s"格式；程序中后续存在使用data变量且未检查返回值是否完全成功的情况（但证据中未显示此类后续代码）。
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_06.c:85
- 结论: sscanf返回值检查不完整：仅检查EOF，未处理返回0或其他正数但未匹配预期项数的情况。当输入字符串不符合格式时，sscanf可能返回0，但代码未视为失败，可能导致未初始化或部分初始化的数据被后续使用，违反CWE-252。然而，证据中未显示后续使用data的明确路径，漏洞利用性依赖于未验证的后续代码。
- D验证: stage_c_preserved / ver_a29187c9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 258. hyp_path_d8c87b2f4d43

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_09.c:80
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制输入SRC，使其无法匹配格式（如空字符串或仅空白字符），且不触发EOF。
- 触发路径: char * data = dataBuffer; @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_09.c:78; if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_09.c:80; 未在sscanf返回0时处理，data可能未被修改，后续使用未更新或未初始化的dataBuffer数据。 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_09.c:82（后续）
- 结论: sscanf返回值检查不完整：仅检查是否等于EOF，忽略返回0（未匹配任何项）的情况。若输入无法匹配格式字符串，dataBuffer内容未更新，后续使用可能导致行为异常或信息泄漏，但影响较低，需动态验证数据缓冲区是否包含敏感信息。
- D验证: stage_c_preserved / ver_c2d0c4ab
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 259. hyp_path_f83ad2f1c4b9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_07.c:85
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者若能控制SRC（如通过环境变量或外部输入），可能使sscanf返回0；但在典型测试用例中SRC为常量，该前提不成立。
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_07.c:85
- 结论: sscanf返回值检查不完整：仅检查EOF，未处理返回0（没有匹配到任何输入）的情况。尽管当前代码片段中后续未使用data缓冲区，但API contract要求检查所有可能的错误返回；从代码设计意图看，此处可能存在防御不足。
- D验证: stage_c_preserved / ver_9772ed9b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 260. hyp_path_1e6d3461bea7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_14.c:80
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC的内容，使得sscanf返回0（格式匹配失败但非EOF）
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_14.c:80
- 结论: 存在CWE-252漏洞：sscanf返回值检查不完整，仅检查EOF，未处理返回0的情况，可能导致未初始化内存使用。
- D验证: stage_c_preserved / ver_e2d07da9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 261. hyp_path_84203190067e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_18.c:55
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够向SRC提供任意字符串作为输入，特别是空字符串或仅空白字符等不匹配%99s格式的内容
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_18.c:55
- 结论: sscanf返回值检查不完整：仅检查EOF，未检查返回值是否等于期望的匹配项数（应为1）。当输入不匹配格式时，sscanf可能返回0，导致后续使用dataBuffer中未写入有效数据的内容，造成未定义行为。
- D验证: stage_c_preserved / ver_8ea2e5d7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 262. hyp_path_c0b5fb4ece6e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_16.c:57
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC变量的内容，使其不匹配"%99s"格式且不触发EOF（例如空字符串或仅空白字符）。
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_16.c:57
- 结论: sscanf返回值检查不充分：仅检查EOF，未检查成功匹配数量。若输入无法匹配格式（返回0），则data可能包含未初始化的数据，导致未定义行为。
- D验证: stage_c_preserved / ver_cde100f4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 263. hyp_path_0a03a1387b50

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_15.c:67
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC内容，使sscanf返回0（例如输入空字符串或无效格式）
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_15.c:67
- 结论: 存在CWE-252未检查返回值漏洞：sscanf返回值检查不完整，仅检查EOF，忽略返回0的情况。但后续代码未使用data，因此当前影响较低，需要动态验证或进一步审计以确认可利用性。
- D验证: stage_c_preserved / ver_151ec388
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 264. hyp_path_a87f11dc347d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_15.c:88
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入到sscanf的源字符串SRC，使其输入不匹配格式（例如空字符串或非字符串内容）导致sscanf返回0。
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_15.c:88
- 结论: 对sscanf的返回值检查不完整：仅检查了EOF错误，未处理匹配失败（返回0）的情况。虽然当前代码片段中data在sscanf后未被直接使用，导致无直接安全危害，但返回值检查缺失本身违反了CWE-253（不正确的返回值检查）的契约，存在潜在风险。当代码后续扩展使用data或传递到其他函数时，可能引发未定义行为。
- D验证: stage_c_preserved / ver_e4084f44
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 265. hyp_path_8adb13badffd

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_04.c:84
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin输入数据，提供格式不匹配或空输入使fwscanf返回0
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_04.c:84
- 结论: fwscanf返回值检查不完整：仅检查EOF（失败）情况，未检查返回0（无匹配）的情况，违反CWE-252要求检查所有错误返回值
- D验证: stage_c_preserved / ver_bb7e6591
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 266. hyp_path_2663ff2a2691

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_03.c:78
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin输入一个无法匹配%99s格式的字符串（例如仅空白字符或空行），使得fwscanf返回0而非EOF。
- 触发路径: wchar_t * data = dataBuffer; @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_03.c:76; if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_03.c:78
- 结论: 对fwscanf的返回值检查不充分：仅检查EOF，未检查返回值为0（匹配失败）的情况，违反了CWE-252的API合同。虽然未初始化变量被后续使用的路径未闭合，但返回值检查不完整本身构成漏洞。
- D验证: stage_c_preserved / ver_1781db3e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 267. hyp_path_a920419f01d2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_02.c:78
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入，使其仅包含空白字符（如空格、换行），导致fwscanf返回0，不进入EOF分支，程序继续执行但后续无data使用。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_02.c:78
- 结论: fwscanf返回值检查不完整：仅检查EOF，未处理返回0的情况，违反CWE-252 API合约。但后续无对data变量的使用，导致实际影响极低，数据未初始化的风险未显式触发。
- D验证: stage_c_preserved / ver_67a18e29
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 268. hyp_path_eb3180f938cf

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_06.c:83
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: Attacker controls stdin and can provide input that causes fwscanf to return 0 (e.g., format mismatch)
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_06.c:83
- 结论: Partial missing return value check: fwscanf returns number of matched items; checking only EOF leaves cases where fwscanf returns 0 (input format mismatch) unchecked, potentially leading to use of uninitialized data.
- D验证: stage_c_preserved / ver_b2d06e4b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 269. hyp_path_f011204d037a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_07.c:83
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供导致fwscanf返回0的输入（如不匹配格式的字符串）
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ 83; 代码中未显示对data的后续使用，成功分支无其他操作 @ 之后
- 结论: fwscanf返回值检查不完整：仅检查了EOF，未检查返回值为0或其他错误的情况，但代码中未显示后续使用data的路径，因此无法确认未初始化数据被实际使用。
- D验证: stage_c_preserved / ver_a34216fa
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 270. hyp_path_21b6308dbba9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_10.c:78
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供特殊输入导致fwscanf返回0（匹配失败但非EOF）
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_10.c:78
- 结论: 对fwscanf的返回值检查不充分，仅检查EOF，未检查返回值为0（匹配失败）的情况，且dataBuffer未初始化，但代码中无后续使用data变量的sink，无法直接利用，但违反API契约。
- D验证: stage_c_preserved / ver_128cdf11
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 271. hyp_path_fa7ffb971c92

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_15.c:65
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使fwscanf返回0但非EOF
- 触发路径: wchar_t * data = dataBuffer; if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_15.c:63-67
- 结论: 未完全检查fwscanf返回值，仅检查EOF，未处理返回值为0的情况，违反CWE-252。虽然dataBuffer后续未被使用，但代码违反API契约，存在潜在风险。
- D验证: stage_c_preserved / ver_03024020
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 272. hyp_path_c59089e0a986

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_18.c:53
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin传递输入，使得fwscanf匹配失败（返回0而非EOF），导致data内容未定义。
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ L53
- 结论: 在CWE252_Unchecked_Return_Value函数中，fwscanf的返回值检查不完整：仅检查了EOF，而未检查返回值为0的情况。虽然当前代码片段中后续未使用data变量，但未检查所有返回值违反了API契约（CWE-252），可能在某些上下文中导致未初始化数据的使用或逻辑错误。
- D验证: stage_c_preserved / ver_ad4cf2c2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 273. hyp_path_596dad40e7dc

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_14.c:61
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: global_five == 5（使未检查分支执行的条件）
- 触发路径: putwchar((wchar_t)L'A'); // 无返回值检查 @ case12函数内if(global_five==5)分支（推测行号，证据中未显式提供）
- 结论: 可能的未检查返回值漏洞：在全局条件global_five==5的分支中，putwchar调用后未检查返回值是否等于WEOF，导致错误未被处理。当前证据仅展示检查分支，但CWE252测试用例典型结构包含未检查分支，需进一步确认。
- D验证: stage_c_preserved / ver_287b6e08
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 274. hyp_path_4077d87fd0e3

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_15.c:78
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: Attacker can influence file rename operation through environment or file system state
- 触发路径: likely RENAME call without checking return value (code not fully shown) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_15.c:72 (case12 entry)
- 结论: VULNERABILITY_FOUND: CWE252 Unchecked Return Value in case12 of switch statement - RENAME return value is not checked
- D验证: stage_c_preserved / ver_8bf954ca
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 275. hyp_path_c5983bf858df

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_02.c:78
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入控制输入内容；在true分支中任何非EOF输入均触发未检查；在else分支中输入空字符串或无效字符使wscanf返回0。
- 触发路径: wscanf(L"%99s", data); // 未检查返回值 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_02.c:68 (true分支); if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } // 仅检查EOF @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_02.c:78 (else分支)
- 结论: wscanf函数返回值检查不完整：在true分支中完全未检查返回值；在else分支中仅检查了EOF错误，未检查返回值为0或其他错误情况。攻击者可通过输入空字符串或无效字符使wscanf返回0，导致dataBuffer未正确填充，后续使用未初始化数据，违反CWE-252语义。
- D验证: stage_c_preserved / ver_0432e885
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 276. hyp_path_8b112ba44c76

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_04.c:65
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供输入，使得 wscanf 返回 0（例如空输入或格式错误）
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_04.c:65
- 结论: 在 wscanf 返回值检查中，仅检查了 EOF，未检查返回值是否等于期望的读取项数（1），导致 wscanf 返回 0 或其它负值时错误未被处理，可能使用未初始化的 dataBuffer，构成 CWE-252 未检查返回值漏洞，但缺乏 data 后续使用的完整路径，无法确认可利用性。
- D验证: stage_c_preserved / ver_602d192f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 277. hyp_path_2e7ddc27d6da

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_03.c:59
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供导致wscanf返回0（无匹配）或正数但小于预期的输入，且后续代码理论上可能使用dataBuffer（但当前路径未使用）
- 触发路径: if (wscanf(L"%99s", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_03.c:59
- 结论: wscanf返回值检查不完整：仅检查EOF，未处理返回值为0或其他错误情况，违反了API契约。尽管当前代码中后续未使用dataBuffer，但该不完整检查仍构成潜在漏洞，需动态验证。
- D验证: stage_c_preserved / ver_85e6c228
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 278. hyp_path_b0ee4116e4a6

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_04.c:84
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供空输入或格式不匹配的输入，导致 wscanf 返回 0
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_04.c:84
- 结论: wscanf 返回值检查不完整：仅检查了 EOF 失败情况，未处理返回值为 0（未匹配任何项）或小于期望匹配数的情况，导致输入格式不匹配或空输入时 data 缓冲区内容可能未完全定义，违反 CWE-252 API contract。
- D验证: stage_c_preserved / ver_4b8b45e3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 279. hyp_path_2db25e07a28c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_03.c:78
- 漏洞类型: CWE-252, CWE-253, CWE-754
- CWE: CWE-252; CWE-253; CWE-754
- 风险等级: P1
- 触发条件: 攻击者能够提供输入，使得wscanf返回0（例如输入内容与格式%99s不匹配，但未触发EOF条件）
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_03.c:78; 假设后续存在使用data的代码，如通过printf或其它函数处理data @ 同文件后续使用data的位置（未在片段中展示，但根据常见模式，可能位于else分支或之后，例如输出或进一步处理）
- 结论: wscanf函数返回值检查不完整：仅检查了返回值为EOF的情况，但未处理返回值为0（表示未成功匹配任何输入项）的情况。这可能导致在输入格式不匹配时，data缓冲区内容未更新，后续使用未初始化的或陈旧的数据，存在信息泄露或未定义行为风险。虽然后续使用data的具体代码位置未在提供片段中展示，但典型Juliet测试用例中通常存在此类使用，使得漏洞路径合理。
- D验证: stage_c_preserved / ver_b0c7e534
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 280. hyp_path_489f1179b65a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_05.c:84
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供输入使得wscanf返回0（如仅输入空白字符或格式不匹配）。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ 84
- 结论: wscanf返回值检查不完整，仅处理了EOF错误，未检查返回值为0的情况，构成CWE-252 API misuse。
- D验证: stage_c_preserved / ver_6fb37c81
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 281. hyp_path_ad5fef401cb4

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_06.c:64
- 漏洞类型: CWE-252, CWE-457
- CWE: CWE-252; CWE-457
- 风险等级: P1
- 触发条件: 攻击者能够提供输入导致wscanf返回0（无匹配）
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ 64
- 结论: Vulnerability: Incomplete check of wscanf return value leaving data uninitialized on no match, though no subsequent use of data evidenced in this path.
- D验证: stage_c_preserved / ver_bfcf11bc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 282. hyp_path_3dc054006849

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_06.c:83
- 漏洞类型: CWE-252, CWE-456
- CWE: CWE-252; CWE-456
- 风险等级: P1
- 触发条件: 攻击者能够提供导致wscanf匹配失败但非EOF的输入。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_06.c:83
- 结论: wscanf返回值检查不完整：仅检查EOF，未检查返回0（匹配失败）的情况，可能导致dataBuffer未初始化就被后续使用。
- D验证: stage_c_preserved / ver_c0e2bd17
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 283. hyp_path_fc02462bd64b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_07.c:83
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入，使wscanf返回非EOF的错误值（如匹配失败返回0）
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_07.c:83
- 结论: wscanf返回值检查不完整，仅检查EOF，未处理其他错误返回值（如0），违反CWE-252。但由于后续未使用输入数据，直接影响较低，需动态验证实际可利用性。
- D验证: stage_c_preserved / ver_e9ee7c52
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 284. hyp_path_892eb3524081

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_09.c:78
- 漏洞类型: CWE-252, CWE-253
- CWE: CWE-252; CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够提供不符合格式L"%99s"的输入，导致wscanf返回0。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_09.c:78
- 结论: wscanf返回值检查不完整：仅检查EOF，未检查返回值为0的情况。虽然代码中后续无data使用，但违反API contract（未验证成功读取项数），存在潜在风险。
- D验证: stage_c_preserved / ver_70c15b3b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 285. hyp_path_7685a3144777

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_14.c:78
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供数据，使得wscanf返回0（例如输入空字符串或仅空白字符）
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_14.c:78
- 结论: wscanf返回值检查不完整，仅检查EOF，未检查期望匹配项数（1），可能导致未检测到输入失败，进而使用未更新的缓冲区数据；但后续使用data的代码未在提供的证据中展示，source-sink路径不完整。
- D验证: stage_c_preserved / ver_1902d1ed
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 286. hyp_path_30b03b70cc13

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_15.c:86
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使wscanf返回值为0（或不是1也不是EOF）
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_15.c:86
- 结论: wscanf返回值未完全检查：仅检查EOF，未检查成功匹配项数是否为1，攻击者可提供导致返回0的输入（如空输入或格式不匹配），违反CWE-252 API contract。尽管后续未使用数据，但存在未处理错误状态。
- D验证: stage_c_preserved / ver_4da82924
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 287. hyp_path_9d1b4e93ecef

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_13.c:78
- 漏洞类型: CWE-252, CWE-253
- CWE: CWE-252; CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入流，使其输入导致wscanf返回0（例如输入全为空白字符）; dataBuffer在调用前未初始化
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_13.c:78-80; 若wscanf返回0，则跳过错误处理，data保持未初始化 @ 相同位置; 使用未初始化的data导致潜在安全问题 @ 后续使用data的代码（未提供）
- 结论: 代码对wscanf的返回值检查不完整：仅检查了EOF（-1），未检查返回值为0的情况。如果wscanf返回0，则data内容来自未初始化的dataBuffer，后续使用未初始化数据可能导致未定义行为（如信息泄露或代码执行）。
- D验证: stage_c_preserved / ver_4a514cb4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 288. hyp_path_a6fcaf34c5d1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_16.c:55
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可控制标准输入，提供导致wscanf返回0的输入（如空输入或仅空白），使data缓冲区内容未更新。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_16.c:55
- 结论: CWE252: Unchecked Return Value - wscanf返回值检查不完整，仅检查EOF，未处理返回0（无匹配）的情况，违反API contract，data缓冲区在匹配失败时不更新，若后续代码使用data则存在未初始化数据风险。当前代码片段无直接后续使用，但漏洞本身存在。
- D验证: stage_c_preserved / ver_0ca2f92a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 289. hyp_path_d58d94d71411

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_10.c:86
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC的内容或长度，使得SNPRINTF返回错误（如缓冲区不足或格式错误）
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC) < 0) { printLine("snwprintf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_10.c:86
- 结论: VULNERABILITY_FOUND
- D验证: stage_c_preserved / ver_3682d509
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 290. hyp_path_55a0f092e22e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_09.c:86
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者无法控制SRC，SRC为编译时常量，故precondition不成立
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC) < 0) { printLine("snwprintf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_09.c:86
- 结论: 代码违反了CWE-252合约：仅检查swprintf返回值<0，未检查是否发生截断（返回值不等于预期写入长度）。即使SRC为固定常量，截断仍可能发生（若SRC长度超过缓冲区剩余空间），但攻击者无法控制SRC，导致可利用性极低。
- D验证: stage_c_preserved / ver_7a8b39e4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 291. hyp_path_ffafe2cdd4db

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_07.c:91
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC字符串的长度，使得SNPRINTF的返回值大于等于目标缓冲区剩余空间（100-wcslen(SRC)-1），导致输出被截断。SRC必须来源于外部输入或受攻击者影响。
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC) < 0) { printLine("snwprintf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_07.c:91
- 结论: 对SNPRINTF的返回值检查不完整：仅检查了返回值为负的错误情况，但未检查返回值是否大于等于缓冲区大小（即截断情况）。虽然snprintf保证缓冲区不会溢出，但未检测截断可能导致数据不完整，进而影响后续逻辑，构成CWE-252未检查返回值的风险。
- D验证: stage_c_preserved / ver_1ed32d3d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 292. hyp_path_79a9ba2c8498

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_14.c:86
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: SRC为外部可控变量且长度超过剩余缓冲区空间，导致snwprintf返回非负截断值
- 触发路径: if (SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC) < 0) { printLine("snwprintf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_14.c:86
- 结论: CWE252: Unchecked Return Value - 代码检查了snwprintf返回值<0，但未检查返回值是否等于或超过缓冲区大小（截断情况），构成不完整检查。
- D验证: stage_c_preserved / ver_5abafbde
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 293. hyp_path_c4f27a92a713

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_02.c:80
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC输入，使得swscanf返回0（无匹配项）
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_02.c:80
- 结论: CWE-252: Unchecked Return Value - swscanf return value not fully checked (only EOF checked, missing check for 0 matching items)
- D验证: stage_c_preserved / ver_4f40929e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 294. hyp_path_d2d3061f008d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_02.c:61
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响SRC内容，但在本测试用例中SRC为常量，不可控。
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) { printLine("swscanf failed!");} @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_02.c:61
- 结论: swscanf返回值检查不完整：仅检查是否等于EOF，未处理返回0的情况。但在该测试用例中，SRC为固定常量，且dataBuffer已初始化为空字符串，即使swscanf返回0，data内容不变，后续无使用，因此实际风险极低。
- D验证: stage_c_preserved / ver_6682177a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 295. hyp_path_75ede131b4fa

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_04.c:67
- 漏洞类型: CWE-252, CWE-457
- CWE: CWE-252; CWE-457
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC输入（如提供空字符串或格式不匹配的字符串）; dataBuffer未初始化（局部变量，未显式赋初值）
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_04.c:67; 未检查返回值为0的情况，直接使用未初始化的data。 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_04.c:67 (else分支隐式); data可能被用于输出或其他操作，但当前片段未显式展示。 @ 假设的后续代码（Juliet测试用例中通常存在）
- 结论: 在swscanf调用中，仅检查返回值是否为EOF，而未检查返回值为0（表示未匹配任何字符）的情况，导致在输入不匹配格式时，data可能包含未初始化内容，后续使用可能导致未定义行为或信息泄露。攻击者可控制SRC输入（如空字符串）触发此路径。
- D验证: stage_c_preserved / ver_7e8d14c6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 296. hyp_path_1894cfe007dd

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_03.c:61
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC字符串内容，使其无法匹配格式"%99s"，导致swscanf返回0。
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_03.c:61
- 结论: swscanf返回值检查不完整，仅处理EOF，忽略返回0的情况，导致dataBuffer可能未初始化，但后续未使用data，利用需要进一步sink点。
- D验证: stage_c_preserved / ver_b17b66cf
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 297. hyp_path_0f0ca7c10286

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_05.c:86
- 漏洞类型: CWE-252, CWE-457
- CWE: CWE-252; CWE-457
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC的内容导致swscanf失败（返回EOF）
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_05.c:86
- 结论: swscanf返回值检查不完整：当swscanf返回EOF时，仅打印错误信息，未对data进行错误处理或终止后续使用，后续对未初始化data的引用可能导致未定义行为或信息泄露。尽管当前证据未显式展示sink行，但根据Juliet测试用例常见结构，函数末尾通常存在对data的使用（如wprintf），因此漏洞路径存在但证据不闭合。
- D验证: stage_c_preserved / ver_5c2d9bd7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 298. hyp_path_acdc377377b5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_03.c:80
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC输入，使其返回0（例如空字符串或不匹配格式）; 若SRC为常量，无法满足此条件，漏洞不可利用
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_03.c:80; printLine("swscanf failed!");} @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_03.c:81-82; data可能被使用，但未展示 @ 后续代码未展示
- 结论: swscanf返回值检查不完整：仅检查了EOF，未处理返回0（无匹配）的情况。若SRC为可控或意外为空字符串，将导致data未正确设置，可能使用未初始化数据或残留数据。虽然SRC在典型Juliet测试中为常量，但存在契约违反（CWE-252），且dataBuffer未显式初始化。由于后续data使用代码缺失，无法确认实际影响，但违反API合同成立。
- D验证: stage_c_preserved / ver_0413464f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 299. hyp_path_0df93b26babd

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_06.c:66
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制 SRC（swscanf 的输入源）
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_06.c:66
- 结论: 对 swscanf 返回值的检查不完整：仅检查了 EOF，未处理返回 0（匹配失败）的情况。虽然当前代码片段未展示后续使用 data，但违反 API contract 本身构成安全缺陷，可能在未来维护中引发未初始化数据使用。
- D验证: stage_c_preserved / ver_2e0dd46d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 300. hyp_path_c329a2abea88

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_07.c:85
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC输入字符串的内容，使其不匹配"%99s"格式（例如提供空字符串或非字符串内容），导致swscanf返回0而非EOF
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_07.c:85
- 结论: 在swscanf调用中，返回值检查不完整：仅检查了EOF，而未检查其他可能的失败返回值（例如返回0表示未成功匹配任何项），导致在返回0时data可能未被正确写入，后续使用data可能造成未初始化数据读取或其他未定义行为。
- D验证: stage_c_preserved / ver_ad08fe3e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 301. hyp_path_2e9638243a2b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_06.c:85
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制或影响输入字符串SRC的内容，使其无法匹配格式字符串L"%99s"，从而导致swscanf返回0而非EOF
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_06.c:85
- 结论: 代码调用swscanf时仅检查返回值是否为EOF，而未检查返回值是否等于预期的匹配项数（应为1）。当输入字符串不匹配格式时，swscanf返回0，data缓冲区保持未初始化状态。虽然未展示后续对data的使用，但该API误用违反了CWE-252（未检查返回值）的要求，存在潜在安全风险。
- D验证: stage_c_preserved / ver_3874f63a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 302. hyp_path_a87fa4de9a0d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_09.c:80
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC参数的内容（例如用户输入），使其导致swscanf返回0（如空字符串或格式不匹配）。
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_09.c:80
- 结论: 对swscanf的返回值检查不完整：仅检查了EOF，未检查返回值为0（匹配失败）的情况，可能导致data缓冲区未填充或部分填充。虽然代码片段中未显示后续使用data，但未检查返回值本身违反了CWE-252契约，潜在风险存在。
- D验证: stage_c_preserved / ver_ded1bc39
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 303. hyp_path_3bdd606ae801

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_10.c:80
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: SRC为外部可控字符串，且内容导致swscanf返回0（如空字符串）
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_10.c:80
- 结论: swscanf返回值检查不完整，未处理返回0的情况，可能导致data缓冲区在后续使用中被读取未初始化数据
- D验证: stage_c_preserved / ver_d98dfac3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 304. hyp_path_1979adf6ddaa

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_14.c:80
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC的内容（如通过输入或环境变量），使swscanf返回0而不是EOF
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_14.c:80
- 结论: 对swscanf的返回值检查不完整：仅检查了EOF（输入失败），未检查返回值为0（匹配失败）的情况。虽然当前代码中SRC为固定字符串，swscanf可能不会返回0，但代码违反了CWE252契约，理论上当输入可控时存在风险。
- D验证: stage_c_preserved / ver_7acd69e7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 305. hyp_path_a5b3759c412d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_12.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部输入控制，但程序状态使globalReturnsTrueOrFalse返回true。
- 触发路径: void CWE252_Unchecked_Return_Value__char_fwrite_12_case0() { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_12.c:24; if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_12.c:25; fwrite((char *)"string", sizeof(char), strlen("string"), stdout); // 未检查返回值 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_12.c:29
- 结论: fwrite的返回值未被检查，违反CWE-252（未检查返回值），可能导致未处理的写入错误。
- D验证: stage_c_preserved / ver_87bddad3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 306. hyp_path_e78e06c09648

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_16.c:57
- 漏洞类型: CWE-253, CWE-252
- CWE: CWE-253; CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC，使得swscanf返回0（例如提供空输入或格式不匹配的输入）。
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_16.c:57
- 结论: swscanf返回值检查不完整：仅检查了失败条件（EOF），但未检查返回值是否为0（表示未匹配到任何输入）。这违反了API contract要求全面检查返回值的约定，即使当前代码片段中后续未使用data，也构成逻辑错误，可能影响程序正确性。
- D验证: stage_c_preserved / ver_d0750cab
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 307. hyp_path_1649c2140e36

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_12.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 函数被调用; globalReturnsTrueOrFalse()返回true
- 触发路径: void CWE252_Unchecked_Return_Value__wchar_t_fwrite_12_case0() { @ 24行; if(globalReturnsTrueOrFalse()) { @ 25行; /* NOTE: Do not check the return value */ fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout); @ 27-28行
- 结论: 函数中存在未检查fwrite返回值的路径，违反CWE-252（Unchecked Return Value）。当globalReturnsTrueOrFalse()返回true时，fwrite的返回值未被检查，可能导致写入失败未处理，进而引发数据不一致或后续错误。
- D验证: stage_c_preserved / ver_8b9e6f3f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 308. hyp_path_b79c08c9524c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_07.c:53
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者通过环境因素导致stdout写入失败
- 触发路径: if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) != wcslen(L"string")) { printLine("fwrite failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_07.c:53
- 结论: fwrite返回值被检查但不充分，仅打印错误信息，未终止或回滚，可能忽略写失败错误，符合CWE252未充分检查返回值。
- D验证: stage_c_preserved / ver_56b11cf7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 309. hyp_path_010998978cd6

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_11.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者无法直接控制输入，但可能通过影响 stdout 的状态（如关闭文件描述符或导致 I/O 错误）间接触发该问题，但极难实现。
- 触发路径: fprintf(stdout, "%s\n", "string"); @ CWE252_Unchecked_Return_Value__char_fprintf_11.c:29
- 结论: fprintf 的返回值未被检查，违反 CWE252 未检查返回值的要求。尽管输入为固定字符串，但 I/O 错误在理论上可能发生，构成 API contract 违反。实际利用极难，但漏洞存在。
- D验证: stage_c_preserved / ver_8c16131e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 310. hyp_path_46efe34ea736

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_08.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: void CWE252_Unchecked_Return_Value__char_fprintf_08_case0() { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_08.c:37; if(staticReturnsTrue()) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_08.c:38; fprintf(stdout, "%s\n", "string"); // 未检查返回值 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_08.c:42
- 结论: 在函数staticReturnsTrue()返回真时，调用fprintf(stdout, "%s\n", "string")但未检查其返回值。根据CWE-252，未检查返回值构成API contract violation，尽管参数为固定字符串，在stdout故障等极端条件下仍可能忽略错误，影响较低。
- D验证: stage_c_preserved / ver_2f93cc96
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 311. hyp_path_69cbd7c9b230

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_08.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: fputc 的返回值未被检查; 存在可能导致 fputc 失败的环境条件
- 触发路径: fputc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_08.c:42
- 结论: 函数 fputc 的返回值未被检查，违反了 CWE-252 未检查返回值的要求，可能导致在写操作失败时程序无法感知，进而产生数据丢失或未定义行为。
- D验证: stage_c_preserved / ver_8f4d1142
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 312. hyp_path_091536aafc82

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_11.c:26
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行时stdout输出环境存在错误（如stdout关闭、写入失败等）
- 触发路径: fputc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_11.c:26
- 结论: 调用fputc后未检查返回值，违反了CWE-252（未检查返回值）的定义。虽然stdout写入失败的情况较少，但若程序在错误环境中运行（如stdout重定向到管道或文件），忽略fputc返回值可能导致数据未完全写入且程序无法感知，属于API misuse。
- D验证: stage_c_preserved / ver_4baa83c4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 313. hyp_path_3cb1e909f573

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_08.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: fputs执行时遇到错误（如stdout重定向到文件且磁盘空间不足，或stdout已关闭）
- 触发路径: fputs("string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_08.c:42
- 结论: fputs函数返回值未检查，存在CWE-252未检查返回值漏洞。虽然写入stdout通常不易失败，但在stdout重定向到文件且磁盘满或stdout关闭等情况下，fputs可能返回EOF，忽略返回值会导致错误未被处理。
- D验证: stage_c_preserved / ver_4904943a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 314. hyp_path_56a8d0112355

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_11.c:26
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdout的写入状态（如通过资源耗尽、文件系统限制等）或应用程序运行在磁盘满等异常环境
- 触发路径: void CWE252_Unchecked_Return_Value__char_fputs_11_case0() { if(globalReturnsTrue()) { /* NOTE: Do not check the return value */ @ 24-28; fputs("string", stdout); @ 27-31
- 结论: fputs的返回值未被检查，违反了CWE-252（未检查返回值）的API contract。如果fputs调用失败（例如输出缓冲区满或stdout关闭），程序将无法感知错误，可能导致数据丢失或程序状态不一致。
- D验证: stage_c_preserved / ver_3010c186
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 315. hyp_path_ae0c6d043107

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_08.c:47
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin输入数据，或使fscanf调用失败（如EOF）
- 触发路径: fscanf(stdin, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_08.c:47
- 结论: fscanf返回值未检查，违反CWE-252，但当前路径中后续未使用data变量，影响较低，需动态验证或其他路径闭合
- D验证: stage_c_preserved / ver_80005e28
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 316. hyp_path_351feac3b98f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_11.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin输入; fscanf可能因输入错误或格式不匹配而失败
- 触发路径: fscanf(stdin, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_11.c:34
- 结论: fscanf的返回值未被检查，违反CWE-252，可能导致未初始化数据或错误处理。
- D验证: stage_c_preserved / ver_cff440ee
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 317. hyp_path_64aa081c80ef

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_15.c:102
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin输入数据
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_15.c:102 (case12) 和 101 (case11)
- 结论: fscanf返回值检查不完整，仅检查是否为EOF，未检查是否成功读取预期项数（1），违反CWE-252要求，构成API misuse。
- D验证: stage_c_preserved / ver_91953a6e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 318. hyp_path_0a04b49c5c00

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_08.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部输入控制，但写操作可能因环境原因失败（如stdout重定向到文件且磁盘满）。
- 触发路径: fwrite((char *)"string", sizeof(char), strlen("string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_08.c:42
- 结论: 未检查fwrite的返回值，违反CWE-252：未检查返回值。虽然fwrite写入stdout失败可能性较低，但违反API contract，可能导致数据未完全写入而程序未察觉。
- D验证: stage_c_preserved / ver_67b622c5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 319. hyp_path_3964298b2ed9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_11.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: globalReturnsTrue() 始终返回 true，确保分支进入。
- 触发路径: if(globalReturnsTrue()) { /* NOTE: Do not check the return value */ @ L24-28; fwrite((char *)"string", sizeof(char), strlen("string"), stdout); @ L29
- 结论: fwrite 返回值未检查，可能导致写入失败时程序继续执行，违反 CWE-252 (Unchecked Return Value)。
- D验证: stage_c_preserved / ver_ddf06eeb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 320. hyp_path_b6ebdfab8fdd

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_08.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序执行到该路径（staticReturnsTrue返回1，恒成立）
- 触发路径: putc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_08.c:42
- 结论: 调用putc时未检查返回值，违反API契约，可能导致write错误未被发现，符合CWE-252未检查返回值缺陷。
- D验证: stage_c_preserved / ver_d2b12191
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 321. hyp_path_a4b0a82541d5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_11.c:26
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特定攻击前提，但依赖于putc的运行时行为（如输出失败返回EOF）
- 触发路径: putc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_11.c:27
- 结论: 函数CWE252_Unchecked_Return_Value__char_putc_11_case0调用putc但未检查其返回值，违反了API contract，可能导致未处理的失败状态。
- D验证: stage_c_preserved / ver_cdbf1e13
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 322. hyp_path_01457bc3adb4

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_08.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响系统资源（如磁盘空间）或stdout状态，导致putchar失败
- 触发路径: putchar((int)'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_08.c:42
- 结论: 函数CWE252_Unchecked_Return_Value__char_putchar_08_case0调用putchar但未检查返回值，违反CWE-252未检查返回值规范。虽然putchar失败通常不会导致直接安全漏洞，但在极端环境（如stdout重定向到磁盘满）下可能导致未预期的行为，属于API misuse。
- D验证: stage_c_preserved / ver_022782cc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 323. hyp_path_26e1cdc8fce8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_11.c:26
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout或底层文件描述符发生I/O错误（如磁盘满、管道关闭）
- 触发路径: putchar((int)'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_11.c:29
- 结论: putchar函数的返回值未被检查，违反CWE-252（未检查返回值）。尽管路径可达且注释要求不检查，但putchar失败通常仅导致I/O错误或字符写入失败，安全影响较低（如信息丢失或显示异常），未直接影响机密性、完整性或可用性。
- D验证: stage_c_preserved / ver_afd93fc7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 324. hyp_path_181c45ce9581

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_08.c:48
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无需外部输入控制，漏洞由代码自身的疏忽导致。
- 触发路径: PUTS("string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_08.c:48
- 结论: 调用 puts() 函数后未检查其返回值，违反了 API contract 中关于错误处理的要求，可能导致未检测到的写入失败。
- D验证: stage_c_preserved / ver_ee432341
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 325. hyp_path_370a36d4ed60

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_11.c:32
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者无法直接控制输入，但可能通过环境影响（如修改标准输出目标、耗尽系统资源）间接导致puts失败。
- 触发路径: PUTS("string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_11.c:32
- 结论: 函数CWE252_Unchecked_Return_Value__char_puts_11_case0中，对puts函数返回值未作检查，违反CWE-252（未检查返回值）。虽输入固定，但puts仍可能因输出重定向失败或资源耗尽返回EOF，忽略该错误可能使程序在错误状态下继续执行。
- D验证: stage_c_preserved / ver_993c5de6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 326. hyp_path_d90740a319ab

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_03.c:89
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: Attacker can provide input that causes scanf to return 0 (input mismatch) but not EOF
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_03.c:81
- 结论: CWE252: Unchecked Return Value - scanf return value only checked for EOF, not for success
- D验证: stage_c_preserved / ver_affdcef5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 327. hyp_path_1a1c0cd5a698

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_08.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制输入流（例如通过stdin重定向或关闭输入）导致scanf返回0或EOF
- 触发路径: scanf("%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_08.c:39
- 结论: 在CWE252_Unchecked_Return_Value__char_scanf_08.c的case0中，调用scanf未检查返回值，违反CWE-252 API contract，但代码中无后续使用data的语句，因此实际安全影响缺失，无法形成完整漏洞路径。
- D验证: stage_c_preserved / ver_6a5bd41f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 328. hyp_path_152d288b0b6a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_11.c:26
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: globalReturnsTrue()返回true，确保代码进入if分支执行scanf调用。
- 触发路径: scanf("%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_11.c:26
- 结论: 在函数CWE252_Unchecked_Return_Value__char_scanf_11_case0中，调用了scanf函数但未检查其返回值，构成CWE-252“未检查返回值”的API违反。尽管当前data变量未进一步使用，未检查返回值可能导致输入截断或数据未成功读取，在扩展场景下可能引发安全缺陷。
- D验证: stage_c_preserved / ver_f4c4636e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 329. hyp_path_d559f2218695

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_14.c:88
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供不匹配%s格式的输入（如数字或空输入），导致scanf返回0而非EOF
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_14.c:59-61（case11）或79-81（case12）
- 结论: 存在未完全检查scanf返回值的API误用：仅检查EOF而未检查返回值为0的情况，违反CWE-252要求
- D验证: stage_c_preserved / ver_e7f88a6d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 330. hyp_path_3f8e2946cec7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_08.c:55
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 在测试用例中SRC为固定常量，攻击者无法直接控制输入，但在实际应用中若SRC由外部输入控制，则可触发截断或错误。
- 触发路径: SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_08.c:55
- 结论: 在snprintf调用后未检查返回值，违反API contract（CWE-252），可能导致截断或错误未被处理。
- D验证: stage_c_preserved / ver_26cfe9cf
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 331. hyp_path_0b5ca5c3c481

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_11.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部输入要求；globalReturnsTrue()编译时已知返回真，代码块必然执行
- 触发路径: SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_11.c:34
- 结论: 函数CWE252_Unchecked_Return_Value__char_snprintf_11_case0中调用了SNPRINTF（snprintf）但未检查其返回值，违反了CWE-252（未检查返回值）的API契约。snprintf返回实际写入的字符数或负数表示错误，忽略返回值可能导致未检测到的输出错误、数据截断或后续逻辑问题。
- D验证: stage_c_preserved / ver_c4ee74a1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 332. hyp_path_329d06b6db36

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_14.c:97
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者无法控制SRC，SRC为编译时常量
- 触发路径: if (SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC) < 0) { printLine("snprintf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_14.c:82-85 (case12) 或 61-64 (case11)
- 结论: snprintf返回值检查不完整：只检查了负值（错误情况），但未检查返回值是否大于等于缓冲区大小（截断情况），违反CWE-252。但由于SRC为编译时常量且后续未使用data，实际可利用性低。
- D验证: stage_c_preserved / ver_e25923e4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 333. hyp_path_0b8970e75c78

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_04.c:97
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制或影响SRC的内容（如提供空字符串或格式不匹配的输入）
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ case12函数内
- 结论: 在case12中，sscanf返回值检查不完整：仅检查了EOF(-1)，未检查返回0（无匹配项）的情况，导致可能未检测到读取失败。虽然后续未使用data变量，但违反了CWE-252的API合同。
- D验证: stage_c_preserved / ver_8f110553
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 334. hyp_path_0ab2470bc0b0

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_07.c:96
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制输入字符串，使其为空或不匹配%99s格式
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_07.c:96
- 结论: sscanf返回值检查不完整：仅检查返回EOF的情况，但sscanf在匹配失败（如输入为空或格式不匹配）时返回0，未处理导致数据可能未正确写入，违反CWE-252要求
- D验证: stage_c_preserved / ver_119213eb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 335. hyp_path_6a6d1cfd816e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_08.c:49
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者需要能够控制SRC的值使其导致sscanf失败，但SRC宏定义未提供，可能为常量；后续代码需使用未正确初始化的data。
- 触发路径: sscanf(SRC, "%99s\0", data); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_08.c:49
- 结论: 在函数CWE252_Unchecked_Return_Value__char_sscanf_08_case0中，调用sscanf后未检查返回值，违反了CWE-252（未检查返回值）的API contract，但SRC可能为常量字符串，且后续代码未明确展示data的使用，因此漏洞路径可能不可达或影响较低。
- D验证: stage_c_preserved / ver_280a9964
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 336. hyp_path_917d456fe0d4

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_08.c:104
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制 SRC 输入，使得 sscanf 返回 0（例如输入字符串不匹配格式）。
- 触发路径: case11(); case12(); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_08.c:102-106; if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_08.c:93-98 (case12) 或 73-78 (case11)
- 结论: sscanf() 的返回值检查不完整：只检查了 EOF 失败情况，但未检查返回值为 0（未成功匹配）的情况。这违反了 API 契约（CWE-252），尽管当前代码片段中未发现后续对 data 的使用，但该漏洞模式本身存在，可能在其他调用路径或演化中导致未初始化数据使用。
- D验证: stage_c_preserved / ver_0fd67653
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 337. hyp_path_36d8fe065d23

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_09.c:90
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC（当前为常量，不可控）使得sscanf返回0；或当SRC变为外部可控时，通过提供空输入或格式不匹配的输入触发。
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_09.c:46-67 (case11) 和 70-86 (case12)
- 结论: 函数case11和case12中，sscanf的返回值仅检查是否等于EOF，而未检查返回0的情况（表示未匹配任何输入项）。这违反了对sscanf返回值完整检查的API contract，属于CWE-252。但由于SRC为常量且后续未使用data，实际可利用路径缺失。
- D验证: stage_c_preserved / ver_fdf7b033
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 338. hyp_path_2a2948e7bd3e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_11.c:28
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC的内容（但在当前测试用例中SRC为常量，因此即时利用不可行）
- 触发路径: sscanf(SRC, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_11.c:28
- 结论: sscanf返回值未检查，违反CWE-252。虽然当前SRC为常量且调用必定成功，但未检查返回值是一种编码缺陷，可能在未来环境变化或代码复用引入可变输入时导致未初始化的数据使用。
- D验证: stage_c_preserved / ver_af6e3630
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 339. hyp_path_0bc204252460

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_08.c:41
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: staticReturnsTrue()返回true（恒成立），确保ImpersonateSelf被调用。
- 触发路径: ImpersonateSelf(SecurityImpersonation); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_08.c:41
- 结论: ImpersonateSelf函数调用后未检查返回值，导致如果身份模拟失败，程序可能继续执行而认为模拟成功，违反API契约（CWE-252）。
- D验证: stage_c_preserved / ver_bf0763e1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 340. hyp_path_0f406f1a0247

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_11.c:28
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过某种方式使ImpersonateSelf调用失败（例如系统资源不足、权限不足等），但此处无需外部输入控制。
- 触发路径: { /* NOTE: Do not check if ImpersonateSelf() fails */ ImpersonateSelf(SecurityImpersonation); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_11.c:26-30
- 结论: 调用ImpersonateSelf时未检查返回值，违反CWE-252。如果ImpersonateSelf失败，线程将无法正确模拟安全上下文，可能导致后续权限相关操作以错误权限执行，存在权限提升或信息泄露风险。
- D验证: stage_c_preserved / ver_0b1ea9d0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 341. hyp_path_5a3762f36098

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_04.c:76
- 漏洞类型: CWE-268
- CWE: CWE-268
- 风险等级: P1
- 触发条件: 无需外部输入，ImpersonateSelf调用本身在可执行路径上，且STATIC_CONST_TRUE和STATIC_CONST_FALSE的条件决定分支可达。
- 触发路径: case11(); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_04.c:75; if (!ImpersonateSelf(SecurityImpersonation)) { exit(1); } // 成功时未调用RevertToSelf @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_04.c:52-57; case12(); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_04.c:76; if (!ImpersonateSelf(SecurityImpersonation)) { exit(1); } // 成功时未调用RevertToSelf @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_04.c:66-69
- 结论: ImpersonateSelf返回成功（非零值）后，未调用RevertToSelf恢复原始安全上下文，导致模拟权限在进程生命周期内持久化，违反API contract，存在潜在权限滥用风险。
- D验证: stage_c_preserved / ver_daf8d19e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 342. hyp_path_1f41a788383a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_08.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够导致 stdout 写入失败（例如，通过关闭文件描述符或重定向到无效位置）
- 触发路径: fwprintf(stdout, L"%s\n", L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_08.c:42
- 结论: CWE-252: 未检查 fwprintf 返回值。代码中调用 fwprintf 后未检查返回值，当写入失败时程序可能继续执行，导致未处理的错误条件。
- D验证: stage_c_preserved / ver_c685f3ca
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 343. hyp_path_1e314bacb99a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_11.c:26
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊前提，攻击者无法控制输出内容，但返回值仍可能指示部分失败。
- 触发路径: fwprintf(stdout, L"%s\n", L"string"); @ CWE252_Unchecked_Return_Value__wchar_t_fprintf_11.c:29
- 结论: 未检查fwprintf返回值，违反CWE-252未检查返回值的要求。
- D验证: stage_c_preserved / ver_b082ce9c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 344. hyp_path_6a4f00e340ef

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_08.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 调用fputwc时，stdout可能处于错误状态（如磁盘满、权限不足）
- 触发路径: fputwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_08.c:42
- 结论: 代码未检查fputwc的返回值，违反CWE252：未检查返回值。fputwc可能因输出错误而失败，但返回值未被检查，可能导致程序在错误状态下继续执行。
- D验证: stage_c_preserved / ver_da949f78
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 345. hyp_path_90bea588c0f3

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_11.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够导致 fputwc 操作失败（例如通过填满磁盘或关闭 stdout）
- 触发路径: fputwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_11.c:29
- 结论: 函数 fputwc 的返回值未被检查，违反 API contract，可能导致未处理的错误条件。虽然当前代码没有直接利用该返回值，但忽略返回值是典型 API misuse。
- D验证: stage_c_preserved / ver_236d72e6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 346. hyp_path_1dd53a565066

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_08.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行时环境可能导致 fputws 失败（如磁盘满、权限不足、stdout 关闭），但未检查返回值。
- 触发路径: fputws(L"string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_08.c:42
- 结论: 函数 fputws 的返回值未被检查，可能导致未检测到的输出错误，违反 CWE-252 Unchecked Return Value。
- D验证: stage_c_preserved / ver_7d7d4174
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 347. hyp_path_43dd01cd9b35

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_11.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 标准输出流stdout在运行时可能处于错误状态（例如重定向到无效文件或磁盘满）
- 触发路径: fputws(L"string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_11.c:29
- 结论: 函数fputws的返回值未被检查，违反CWE-252。当向stdout写入失败时（例如stdout被重定向到文件且磁盘满），程序将无法感知错误，可能导致数据丢失或未定义行为。
- D验证: stage_c_preserved / ver_4a7923f2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 348. hyp_path_534362411f9b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_08.c:47
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，例如提供EOF或格式不匹配导致fwscanf失败
- 触发路径: void CWE252_Unchecked_Return_Value__wchar_t_fscanf_08_case0() { if(staticReturnsTrue()) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_08.c:37-41; wchar_t * data = dataBuffer; /* NOTE: Do not check the return value */ fwscanf(stdin, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_08.c:45-49
- 结论: 调用fwscanf未检查返回值，违反CWE-252（未检查返回值），可能导致未定义行为或未初始化数据使用。
- D验证: stage_c_preserved / ver_efd66545
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 349. hyp_path_2c38fb3f6771

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_08.c:101
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供标准输入，使得fwscanf返回0（例如输入空行或无效匹配）
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_08.c:71 或 90
- 结论: 在case11和case12中，对fwscanf的返回值检查不完整，仅检查是否等于EOF，而未处理返回0（匹配失败）的情况，违反了CWE-252 Unchecked Return Value的要求。尽管dataBuffer已初始化为空字符串，使得匹配失败时数据为空而非未初始化，但仍构成API misuse。
- D验证: stage_c_preserved / ver_4f1d17c7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 350. hyp_path_0a655d2c8b37

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_09.c:88
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供数据，使fwscanf读取失败但返回0（例如输入空行或格式不匹配）
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_09.c:74
- 结论: fwscanf返回值仅检查EOF，未检查其他错误返回值（如返回0），违反CWE-252要求，但后续未使用data值，实际安全影响较低。
- D验证: stage_c_preserved / ver_19c0bd8f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 351. hyp_path_6e3d5e93592a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_11.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够向stdin提供输入（或触发输入失败）
- 触发路径: fwscanf(stdin, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_11.c:34
- 结论: fwscanf的返回值未检查，违反CWE-252。若输入操作失败，dataBuffer可能包含未初始化数据，导致未定义行为或潜在信息泄露。
- D验证: stage_c_preserved / ver_3108cbe4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 352. hyp_path_8d10d2d7c681

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_15.c:101
- 漏洞类型: CWE-253, CWE-252
- CWE: CWE-253; CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入，使得fwscanf返回0（例如输入无效字符）
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) { ... } @ L:50-72 (case11) 和 L:75-97 (case12)
- 结论: 存在API contract违反：fwscanf返回值检查不完整，仅检查EOF，未检查匹配失败（返回0），可能导致未处理的错误状态。但后续未使用data，无实际安全影响。
- D验证: stage_c_preserved / ver_1fc1b686
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 353. hyp_path_1261f3beb3ea

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_08.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部输入控制，但fwrite可能因环境原因（如磁盘满、管道破裂、权限不足）失败。
- 触发路径: fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_08.c:42
- 结论: 调用fwrite时未检查返回值，可能因写入不完整导致数据丢失或程序状态异常，违反CWE252的API contract。
- D验证: stage_c_preserved / ver_14b69c9b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 354. hyp_path_4df1b53ab330

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_11.c:26
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout 写入可能失败（如管道关闭、磁盘满等），但攻击者无法直接控制。
- 触发路径: fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_11.c:29
- 结论: fwrite 函数的返回值未被检查，违反了 CWE-252（未检查返回值）的定义。如果 fwrite 写入 stdout 失败（例如磁盘满、管道破裂等），将无法获知写入是否完整，可能导致数据丢失或程序状态不一致。
- D验证: stage_c_preserved / ver_00a5ea16
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 355. hyp_path_3c9a08fb8b66

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_08.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdout输出行为（如通过重定向到特殊文件或设备）以引发写入失败。
- 触发路径: putwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_08.c:42
- 结论: putwc函数的返回值未检查，可能导致未检测到的写入失败，违反CWE-252。
- D验证: stage_c_preserved / ver_fd7704b8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 356. hyp_path_736fc6f604ee

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_11.c:26
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行环境中stdout可能失败（如重定向到无效文件、磁盘满等），但攻击者无法直接控制该条件。
- 触发路径: putwc((wchar_t)L'A', stdout); @ CWE252_Unchecked_Return_Value__wchar_t_putc_11.c:29
- 结论: 在CWE252_Unchecked_Return_Value__wchar_t_putc_11_case0函数中，对putwc的返回值未进行检查，违反了CWE-252（未检查返回值）定义。虽然实际利用需要stdout写入失败等环境条件，且攻击者无法直接控制，但API contract violation明确存在，可能导致未检测到的写入失败。
- D验证: stage_c_preserved / ver_628a0935
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 357. hyp_path_a8b873f395b6

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_08.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无需特殊前提，任何执行路径均会触发该违规。
- 触发路径: putwchar((wchar_t)L'A'); @ CWE252_Unchecked_Return_Value__wchar_t_putchar_08.c:42
- 结论: 函数putwchar的返回值未被检查，违反API契约（CWE-252），可能导致未检测到的写入错误。
- D验证: stage_c_preserved / ver_6b2e072e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 358. hyp_path_6e233f05fbf8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_11.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: globalReturnsTrue()返回真（通常为真），导致进入分支执行putwchar。
- 触发路径: putwchar((wchar_t)L'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_11.c:29
- 结论: 调用putwchar输出宽字符后未检查返回值（WEOF），可能导致未检测到的写入错误，违反API合同（CWE-252）。虽然影响可能较低（输出错误），但存在明确的API misuse。
- D验证: stage_c_preserved / ver_14314f6c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 359. hyp_path_445870c33f92

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_08.c:45
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: PUTS(L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_08.c:45
- 结论: 函数 _putws 或类似的 PUTS 调用未检查返回值，违反 API contract，可能导致未检测到的 I/O 错误。
- D验证: stage_c_preserved / ver_9398d309
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 360. hyp_path_4e7114c45607

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_11.c:32
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序执行流经globalReturnsTrue()为真的分支即可触发，该函数恒返回true
- 触发路径: PUTS(L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_11.c:34
- 结论: 函数_putws的返回值未被检查，违反了CWE-252（未检查返回值）。尽管输入是硬编码字符串，但_putws可能失败（如输出设备错误），未处理返回值会导致错误状态被忽略，可能引发后续行为异常。
- D验证: stage_c_preserved / ver_6a154fdc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 361. hyp_path_1e56481de0d3

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_08.c:45
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能无法控制输入，但若文件系统状态变化（如文件被占用、权限不足），删除操作可能失败。
- 触发路径: REMOVE(L"removemecase0.txt"); @ CWE252_Unchecked_Return_Value__wchar_t_remove_08.c:45
- 结论: 函数CWE252_Unchecked_Return_Value__wchar_t_remove_08_case0调用了REMOVE(L"removemecase0.txt")但未检查其返回值，违反了CWE-252要求检查返回值的规范。虽然文件名硬编码，攻击者无法直接控制，但忽略返回值可能导致程序在删除失败时未获知，影响文件操作的正确性。
- D验证: stage_c_preserved / ver_c09c18c1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 362. hyp_path_c708577fc7f4

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_11.c:32
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过影响文件系统状态（如权限、文件存在性）间接导致删除失败，但无需主动控制输入。
- 触发路径: REMOVE(L"removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_11.c:33-35
- 结论: 函数调用REMOVE删除文件但不检查返回值，违反了CWE-252：未检查返回值。虽然参数为常量字符串，攻击者无法直接控制，但未检查返回值仍是违反API合约的行为。
- D验证: stage_c_preserved / ver_016747f5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 363. hyp_path_2b1325e6aa01

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_08.c:51
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_08.c:51
- 结论: 调用_wrename重命名文件时未检查返回值，违反CWE-252未检查返回值，可能导致重命名操作失败而未被发现，影响文件操作可靠性。
- D验证: stage_c_preserved / ver_4c6a3a03
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 364. hyp_path_286f26fdefd3

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_11.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响文件系统状态，例如创建同名目标文件、修改文件权限或使源文件不可用。
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_11.c:38
- 结论: 函数CWE252_Unchecked_Return_Value__wchar_t_rename_11_case0中调用了RENAME宏来重命名文件，但未检查其返回值。根据CWE-252，未检查返回值可能导致程序忽略错误状态，例如重命名失败（如目标文件已存在、权限不足等），进而造成数据丢失、文件损坏或意外行为。
- D验证: stage_c_preserved / ver_278436c2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 365. hyp_path_26b83c535936

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_08.c:47
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin输入流导致wscanf返回EOF或错误
- 触发路径: void CWE252_Unchecked_Return_Value__wchar_t_scanf_08_case0() { if(staticReturnsTrue()) { @ 37-41; wchar_t * data = dataBuffer; /* NOTE: Do not check the return value */ wscanf(L"%99s\0", data); } } @ 45-49
- 结论: 未检查wscanf返回值，可能因输入错误导致dataBuffer内容不确定
- D验证: stage_c_preserved / ver_c1bc81ff
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 366. hyp_path_104470cbf5bf

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_10.c:88
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供不匹配格式的输入，使得wscanf返回0。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_10.c:82
- 结论: 在case12中，wscanf的返回值仅检查了EOF，而未检查返回0（无匹配）的情况。当输入不匹配格式时，wscanf返回0，但程序未处理此情况，违反了CWE-252原则。尽管dataBuffer已初始化为空字符串且后续未使用，但API contract violation明确，可能导致未定义行为或逻辑错误。
- D验证: stage_c_preserved / ver_4bc59f90
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 367. hyp_path_3fc4ea2b5e6a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_11.c:26
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入流（stdin）注入文件结束符或格式不匹配导致wscanf失败。
- 触发路径: wscanf(L"%99s\0", data); // 未检查返回值 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_11.c:26
- 结论: 在函数CWE252_Unchecked_Return_Value__wchar_t_scanf_11_case0中，调用wscanf后未检查其返回值，违反CWE-252 API合同。尽管后续未直接使用data，但wscanf失败可能导致缓冲区内容未初始化或程序状态异常，且忽略返回值本身构成安全漏洞。
- D验证: stage_c_preserved / ver_e9806013
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 368. hyp_path_6a2fa419d293

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_08.c:101
- 漏洞类型: CWE-252, CWE-391
- CWE: CWE-252; CWE-391
- 风险等级: P1
- 触发条件: 攻击者能够提供输入给wscanf，使得wscanf返回0（例如空输入或无效输入），但后续未使用data，因此无直接数据流影响。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_08.c:75 (case11) 或 95 (case12)
- 结论: 在case11和case12中，wscanf调用后仅检查返回值是否为EOF，未检查是否成功读取预期的字段数（即返回值是否等于1），违反CWE-252（未检查返回值）和CWE-391（未检查错误情况）。尽管当前代码中data变量后续未被使用，但检查不完整构成API misuse。
- D验证: stage_c_preserved / ver_f530808c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 369. hyp_path_ab4d6cbe30da

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_14.c:89
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供输入使得wscanf返回0（即输入不匹配格式）; globalFive==5条件成立（测试用例中通常为真）
- 触发路径: wscanf(L"%99s\0", data) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_14.c:89
- 结论: wscanf返回值检查不完整：仅检查是否等于EOF，但未检查返回值为0（表示未匹配任何输入）的情况，违反了CWE-252要求完整检查返回值。虽然当前代码后续未使用data，但返回值检查缺失仍构成API misuse。
- D验证: stage_c_preserved / ver_cf72d046
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 370. hyp_path_d9d407abb133

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_08.c:55
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 函数staticReturnsTrue()返回1，保证if条件恒真，SNPRINTF被调用。
- 触发路径: SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_08.c:55
- 结论: 在调用SNPRINTF（swprintf）时未检查返回值，违反CWE-252。注释明确说明不检查返回值，可能导致数据截断或写入不完全，但未处理错误。
- D验证: stage_c_preserved / ver_117ae1e6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 371. hyp_path_24658c2d5ca2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_11.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊前提条件，任何导致 swprintf 失败的情况（如目标缓冲区过小、编码错误等）均可触发返回值未检查的漏洞。
- 触发路径: SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_11.c:34
- 结论: 函数调用 swprintf（通过 SNPRINTF 宏）后未检查其返回值。代码注释明确指示不检查返回值，违反了 CWE-252（未检查返回值）的 API 契约。即使缓冲区长度计算正确避免了溢出，但返回值未检查可能导致数据截断或写入失败未被处理，影响数据完整性。
- D验证: stage_c_preserved / ver_58fb7e76
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 372. hyp_path_0dfc0c1f4b30

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_08.c:110
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin输入（或标准输入流可控）
- 触发路径: fgetws(data, 100, stdin); // 返回值未检查 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_08.c:case12 函数体内（约L90-100）; fgetws(data, 100, stdin); // 返回值未检查 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_08.c:case11 函数体内（约L70-80）
- 结论: 存在CWE-252未检查返回值漏洞：fgetws()返回值未被检查，可能导致后续逻辑在读取失败时仍使用未定义的缓冲区内容。
- D验证: stage_c_preserved / ver_c527b80d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 373. hyp_path_3ab3e6341db8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_08.c:41
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无（当前SRC为常量；未来若SRC变为可控输入，则攻击者可控制swscanf的返回值）
- 触发路径: swscanf(SRC, L"%99s\0", data); @ CWE252_Unchecked_Return_Value__wchar_t_sscanf_08.c:41
- 结论: swscanf返回值未检查，违反CWE-252规范。尽管SRC为硬编码常量导致当前实际可利用性低，但静态违反安全编码规则，存在代码维护后风险（如SRC变为外部输入时）。
- D验证: stage_c_preserved / ver_a819b29d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 374. hyp_path_2a6a443e1e46

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_06.c:96
- 漏洞类型: CWE-252, CWE-253
- CWE: CWE-252; CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够影响输入流SRC，使得swscanf返回0而非EOF，例如提供与格式不匹配的输入。
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_06.c:80
- 结论: 函数swscanf的返回值被检查为EOF，但未检查返回0（格式匹配失败但未到文件尾）的情况，违反了CWE-252（未检查返回值）和CWE-253（错误检查返回值）的API contract。尽管当前路径（case12）中data未后续使用，直接危害较低，但若SRC受攻击者控制且后续存在依赖data有效性的代码，则可能导致未定义行为或逻辑错误。case11为死代码，已排除。
- D验证: stage_c_preserved / ver_3b8ed9f2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 375. hyp_path_80baa790db76

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_11.c:28
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部可控输入，但违反API契约不需要外部输入。实际场景中若SRC来自外部输入则可利用。
- 触发路径: swscanf(SRC, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_11.c:28
- 结论: 在函数CWE252_Unchecked_Return_Value__wchar_t_sscanf_11_case0中，调用swscanf时未检查返回值，违反了CWE-252的要求。尽管SRC为常量字符串，swscanf失败概率极低，但未检查返回值本身就是API misuse，构成CWE violation。
- D验证: stage_c_preserved / ver_a3ef885b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 376. hyp_path_27e678bbdc28

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_15.c:103
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够向标准输入stdin提供数据，使得fgetws可能返回NULL或失败
- 触发路径: fgetws(data, 100, stdin); // 返回值未检查 @ case11函数内; fgetws(data, 100, stdin); // 返回值未检查 @ case12函数内
- 结论: 未检查fgetws返回值，违反CWE-252，可能导致后续操作使用无效数据或触发未定义行为
- D验证: stage_c_preserved / ver_feedf585
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 377. hyp_path_126fa67b98cc

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_11.c:91
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_11.c:76或55
- 结论: 存在CWE-252违规：swscanf返回值检查不完整，仅检查EOF，忽略返回0的情况。但由于输入SRC为编译时常量，且后续未使用data（仅失败时打印信息），实际无法被攻击者利用，无安全影响。
- D验证: stage_c_preserved / ver_6b6c5377
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 378. hyp_path_9fe9d5cb47d2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_01.c:27
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响 stdout 写入状态（如控制文件描述符、触发写入错误）
- 触发路径: fprintf(stdout, "%s\n", "string"); @ CWE252_Unchecked_Return_Value__char_fprintf_01.c:27
- 结论: fprintf 函数调用后未检查返回值，违反 CWE-252（未检查返回值），可能导致写入失败未被发现。
- D验证: stage_c_preserved / ver_d5b2e018
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 379. hyp_path_002dc8363034

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_03.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无攻击者可控输入；仅系统级错误可能导致fprintf失败
- 触发路径: fprintf(stdout, "%s\n", "string"); @ 29
- 结论: fprintf调用后未检查返回值，违反CWE252（Unchecked Return Value）
- D验证: stage_c_preserved / ver_c32af2c9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 380. hyp_path_5b1e5136373d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_02.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过改变系统状态（如耗尽磁盘空间、关闭 stdout 描述符或重定向到受限文件）导致 fprintf 写入失败
- 触发路径: fprintf(stdout, "%s\n", "string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_02.c:29
- 结论: 函数 fprintf 的返回值未被检查，违反 CWE-252（未检查返回值）。尽管写入 stdout 且字符串为硬编码，但若标准输出重定向或系统资源不足时，可能发生写失败而未处理，构成可违反 API contract 的漏洞。
- D验证: stage_c_preserved / ver_501809f3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 381. hyp_path_2b53acd377b8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_04.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者需要能够使 stdout 写入失败（如耗尽磁盘空间或关闭 stdout）
- 触发路径: fprintf(stdout, "%s\n", "string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_04.c:35
- 结论: fprintf 返回值未检查，违反 CWE-252，可能导致写入错误被忽略。但攻击面有限，因为输出字符串固定且 stdout 在典型环境下稳定。
- D验证: stage_c_preserved / ver_28096479
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 382. hyp_path_a6ac84094908

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_05.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过磁盘满、管道关闭或重定向stdout等方式诱发fprintf写入失败，但需要一定的环境或资源操控能力。
- 触发路径: fprintf(stdout, "%s\n", "string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_05.c:35
- 结论: 代码在调用fprintf后未检查返回值，违反了CWE-252（未检查返回值）的定义。即使写入固定字符串到stdout，写入失败时错误被忽略，可能导致未预期的行为。
- D验证: stage_c_preserved / ver_790f6e7e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 383. hyp_path_6f5453f19919

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_06.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout写入操作可能失败（如文件系统满、stdout被关闭或重定向到不可写设备）。
- 触发路径: fprintf(stdout, "%s\n", "string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_06.c:34
- 结论: 未检查fprintf返回值，可能忽略写入错误（固定字符串输出到stdout，违反API契约）。
- D验证: stage_c_preserved / ver_7323d0ef
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 384. hyp_path_cc93ccc1d0d4

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_07.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 代码执行到此语句即可，无外部输入要求
- 触发路径: fprintf(stdout, "%s\n", "string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_07.c:34
- 结论: 调用 fprintf 未检查返回值，违反 CWE-252：未检查返回值。代码中明确注释不检查返回值，属于 API misuse，尽管输出固定字符串且影响较低，但不能否定违反。
- D验证: stage_c_preserved / ver_ded7b715
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 385. hyp_path_7f9328fdcad1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_09.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: fprintf(stdout, "%s\n", "string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_09.c:29
- 结论: 未检查fprintf返回值，违反CWE-252，可能导致未检测到的输出错误。虽然失败概率较低，但API contract violation明确存在。
- D验证: stage_c_preserved / ver_3f316ded
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 386. hyp_path_3ff6e1430788

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_13.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 标准输出可能被重定向到不可写设备或发生其他I/O错误
- 触发路径: fprintf(stdout, "%s\n", "string"); @ L29
- 结论: 在调用 fprintf 后未检查其返回值，违反了 CWE-252 (未检查返回值) 的 API contract。fprintf 可能因输出错误（如磁盘满、stdout 关闭等）而失败，忽略返回值会导致程序无法感知写入失败，可能造成数据丢失或不一致，但直接影响安全的风险较低。
- D验证: stage_c_preserved / ver_bd346d6d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 387. hyp_path_ce161ef3079e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_10.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者需能够改变stdout行为（例如通过重定向、磁盘填满、环境变量劫持等）
- 触发路径: fprintf(stdout, "%s\n", "string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_10.c:29
- 结论: 代码忽略了fprintf的返回值，未检查输出是否成功，违反了CWE-252的API契约要求，可能导致错误状态丢失。
- D验证: stage_c_preserved / ver_aaba535b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 388. hyp_path_93922f67965e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_14.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行环境中stdout发生写入错误
- 触发路径: fprintf(stdout, "%s\n", "string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_14.c:29
- 结论: fprintf函数调用未检查返回值，可能忽略写入错误，导致数据丢失或日志不完整。
- D验证: stage_c_preserved / ver_733c8710
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 389. hyp_path_0c30e95011a7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_15.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过关闭stdout或导致磁盘满等条件使fprintf失败，但具体可利用性较低。
- 触发路径: fprintf(stdout, "%s\n", "string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_15.c:30
- 结论: 在case 6分支中调用fprintf(stdout, ...)后未检查返回值，违反了CWE-252（未检查返回值）的API契约。路径可达，注释明确表示不检查返回值，构成可验证的CWE违规。
- D验证: stage_c_preserved / ver_2ccaa9f5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 390. hyp_path_54fc67373d69

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_16.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: fprintf(stdout, "%s\n", "string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_16.c:29
- 结论: fprintf的返回值未被检查，违反CWE-252（未检查返回值）。虽然写入stdout失败概率低，但代码明确注释不检查返回值，构成API contract violation。
- D验证: stage_c_preserved / ver_c34b47e9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 391. hyp_path_a748389b4408

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_17.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部输入控制，但任何导致fprintf失败的条件（如stdout关闭、磁盘满）都会导致未处理错误。
- 触发路径: fprintf(stdout, "%s\n", "string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_17.c:30
- 结论: fprintf返回值未被检查，即使写入失败也无法感知，违反CWE-252。
- D验证: stage_c_preserved / ver_e4cedba4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 392. hyp_path_27905ed86261

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_18.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: 函数入口 @ CWE252_Unchecked_Return_Value__char_fprintf_18.c:24; sink: /* NOTE: Do not check the return value */ fprintf(stdout, "%s\n", "string"); @ CWE252_Unchecked_Return_Value__char_fprintf_18.c:29
- 结论: fprintf 返回值未检查，违反 CWE-252（未检查返回值）。虽然写入 stdout 且为硬编码字符串，实际风险极低，但根据 API 契约仍应视为漏洞。
- D验证: stage_c_preserved / ver_21e10ab5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 393. hyp_path_5601be0e2ab1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_01.c:27
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout在被调用时可能不可写（如磁盘满、stdout关闭等环境问题）
- 触发路径: fputc((int)'A', stdout); // 未检查返回值 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_01.c:27
- 结论: 在调用fputc时未检查返回值，违反了CWE-252（未检查返回值）。尽管stdout通常成功，但若写入失败（如磁盘满或stdout关闭），程序将无法感知错误，可能导致数据丢失或不完整输出。实际可利用性极低，但代码确实违反CWE-252。
- D验证: stage_c_preserved / ver_3b6a0784
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 394. hyp_path_bdea84529625

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_03.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout 写入可能失败（如文件系统满、管道关闭、权限错误等）
- 触发路径: fputc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_03.c:29
- 结论: fputc() 的返回值未被检查，可能导致写入失败时无法发现错误，违反 CWE-252: Unchecked Return Value。
- D验证: stage_c_preserved / ver_613891c2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 395. hyp_path_535149a62e41

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_02.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 目标程序在特定环境下运行，使得stdout写入可能失败（如磁盘满、管道关闭、权限不足）
- 触发路径: fputc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_02.c:29
- 结论: fputc函数返回值未检查，违反CWE-252。如果写入stdout失败（例如磁盘满或重定向管道关闭），程序无法感知错误，可能导致数据丢失或后续逻辑错误。
- D验证: stage_c_preserved / ver_6da5524b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 396. hyp_path_5910bf4ebf26

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_04.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特定攻击者输入，但 stdout 可能处于错误状态（如重定向到文件且空间不足）。
- 触发路径: fputc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_04.c:35
- 结论: fputc 的返回值未被检查，违反了 CWE-252 (Unchecked Return Value)。虽然此例中影响可能较低，但仍是 API contract 违反。
- D验证: stage_c_preserved / ver_8015774e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 397. hyp_path_b44e0bbce45e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_06.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部输入要求，任何执行路径都会触发
- 触发路径: fputc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_06.c:34
- 结论: 函数fputc的返回值未被检查，违反了CWE-252（未检查返回值）。如果fputc失败，程序无法感知错误，可能导致数据丢失或逻辑错误。
- D验证: stage_c_preserved / ver_78d3f855
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 398. hyp_path_2fea50997045

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_05.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout写入操作失败（如文件描述符关闭、磁盘满、管道破裂）
- 触发路径: fputc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_05.c:35
- 结论: fputc返回值未被检查，违反CWE-252。尽管写入stdout失败概率低，但在某些条件下（如stdout关闭、磁盘满、管道破裂）可能导致程序状态不一致或数据丢失。
- D验证: stage_c_preserved / ver_21da03eb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 399. hyp_path_8b85f8d18e5e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_07.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 环境因素（如stdout关闭、磁盘满）可能导致fputc失败，返回EOF。
- 触发路径: fputc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_07.c:34
- 结论: fputc返回值未检查，违反CWE-252：未检查返回值。即使fputc通常成功，但忽略返回值会导致错误未被处理，可能引发后续问题。
- D验证: stage_c_preserved / ver_5175861f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 400. hyp_path_340290c98ed3

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_09.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout可能处于错误状态或已关闭，导致fputc返回EOF但未被检查。
- 触发路径: fputc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_09.c:29
- 结论: fputc返回值未检查，违反了CWE-252未检查返回值规范，可能导致写入失败未被发现。
- D验证: stage_c_preserved / ver_98cf965a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 401. hyp_path_d53fce846fbf

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_10.c:29
- 漏洞类型: buffer_overflow
- CWE: CWE-252
- 风险等级: P1
- 触发条件: fputc调用可能失败的环境条件（如stdout被关闭、文件系统错误、输出缓冲区溢出等）
- 触发路径: fputc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_10.c:29
- 结论: fputc调用未检查返回值，违反CWE-252。如果fputc失败（例如stdout被关闭或写入错误），程序将无法感知错误，可能导致数据丢失或未处理的错误状态。尽管stdout失败的概率通常较低，但在特定环境（如重定向到文件、磁盘满、权限更改）下可能被触发，构成潜在的完整性或可用性风险。
- D验证: stage_c_preserved / ver_78151765
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 402. hyp_path_e718e0104583

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_13.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者需要能够影响stdout的状态（例如通过重定向或关闭），但通常不可控。
- 触发路径: fputc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_13.c:29
- 结论: 调用fputc时未检查返回值，可能忽略写入错误，违反CWE-252 (Unchecked Return Value) 要求。
- D验证: stage_c_preserved / ver_b77d7215
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 403. hyp_path_39046b70375e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_15.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 运行时 stdout 写入操作可能失败（如管道中断、权限不足）
- 触发路径: fputc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_15.c:30
- 结论: fputc 的返回值未被检查，当写入 stdout 失败时（例如管道关闭、磁盘满），程序无法感知错误，可能导致不完整输出或数据丢失，违反 CWE252 未检查返回值的要求。
- D验证: stage_c_preserved / ver_aa0e2820
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 404. hyp_path_3b9c5ebbbaad

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_16.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者无法直接控制IO错误，但可能通过使stdout重定向到低空间设备等方式间接触发写入失败。
- 触发路径: fputc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_16.c:29
- 结论: 在标准输出fputc调用后未检查返回值，违反CWE-252。虽然写入stdout通常成功，但忽略返回值可能导致未检测到的写入失败，在特定环境下（如重定向到文件且磁盘满）可能造成数据丢失或程序逻辑异常。
- D验证: stage_c_preserved / ver_20da1ba1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 405. hyp_path_dc35a072c28d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_14.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 任何导致fputc失败的环境条件（如stdout错误）即可触发。
- 触发路径: fputc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_14.c:29
- 结论: 对fputc的返回值未进行检查，违反CWE-252（未检查返回值），可能导致输出数据未完全写入或丢失。
- D验证: stage_c_preserved / ver_bb318d3b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 406. hyp_path_f85f614cd9ab

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_17.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无需攻击者输入，运行时可能因外部原因（如文件系统满）导致写入失败。
- 触发路径: fputc((int)'A', stdout); // 返回值未检查 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_17.c:30
- 结论: CWE-252: 未检查返回值。在 fputc 调用后未检查返回值，如果写入失败（如磁盘已满），程序可能继续执行而不知道写入失败，导致数据丢失或错误。
- D验证: stage_c_preserved / ver_e58ff8da
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 407. hyp_path_45a5102f55f7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_18.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特定攻击者控制输入，但stdout写入操作可能因环境因素（如stdout关闭、磁盘满等）失败。
- 触发路径: fputc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_18.c:29
- 结论: 未检查fputc返回值：调用fputc((int)'A', stdout)后未检查返回值，违反了CWE-252（未检查返回值）的API契约。
- D验证: stage_c_preserved / ver_c6acb588
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 408. hyp_path_4ded8bd5ad51

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_01.c:27
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行在stdout可能失败的环境中（如重定向到只读文件、或stdout被关闭）
- 触发路径: fputs("string", stdout); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_01.c:27
- 结论: fputs函数的返回值未被检查，违反API contract，可能导致未检测到的写失败（CWE-252）。
- D验证: stage_c_preserved / ver_014bfecb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 409. hyp_path_50335d778b1f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_02.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout可能被重定向或关闭，导致fputs失败，但典型场景中stdout失败概率较低
- 触发路径: fputs("string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_02.c:29
- 结论: fputs返回值未检查，违反CWE-252 Unchecked Return Value
- D验证: stage_c_preserved / ver_5e40d438
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 410. hyp_path_2b5c96b19d6f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_05.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: fputs("string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_05.c:35
- 结论: 未检查fputs返回值，违反API contract，可能导致部分数据未写入或程序行为异常。
- D验证: stage_c_preserved / ver_9c378b0b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 411. hyp_path_5755bca185d4

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_04.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: fputs("string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_04.c:35
- 结论: 代码调用fputs但未检查返回值，违反CWE-252（未检查返回值）的API contract。
- D验证: stage_c_preserved / ver_6039b3a9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 412. hyp_path_2e27847deab4

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_03.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者无法直接控制stdout状态，但可能通过系统环境间接影响
- 触发路径: fputs("string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_03.c:29
- 结论: 未检查fputs返回值，可能导致写入失败未被察觉
- D验证: stage_c_preserved / ver_a6257111
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 413. hyp_path_e7b533398a4e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_06.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout发生错误（如文件描述符关闭、磁盘满、管道破裂等）
- 触发路径: fputs("string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_06.c:34
- 结论: 未检查fputs函数的返回值，违反CWE-252（未检查返回值），可能导致写入错误未被发现。
- D验证: stage_c_preserved / ver_efbc36bd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 414. hyp_path_66678815a985

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_09.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够使fputs失败（例如关闭标准输出流stdout）
- 触发路径: fputs("string", stdout); @ L29
- 结论: 函数fputs的返回值未被检查，可能导致写入错误（如标准输出关闭）未被发现，违反CWE-252规范。
- D验证: stage_c_preserved / ver_ae25947f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 415. hyp_path_94ddb1358bda

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_07.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无需攻击者输入；任何导致stdout写入失败的条件即可。
- 触发路径: fputs("string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_07.c:34
- 结论: 未检查fputs的返回值，若写入失败（如stdout关闭或磁盘满）则无法感知错误，违反CWE-252。
- D验证: stage_c_preserved / ver_f3f906e1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 416. hyp_path_10db483cd430

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_10.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout写入操作在运行时可能失败（由环境因素导致，非攻击者直接控制）。
- 触发路径: fputs("string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_10.c:29
- 结论: fputs返回值未检查，违反CWE-252，可能导致未处理的写入失败。
- D验证: stage_c_preserved / ver_e580f42b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 417. hyp_path_359acb6f4197

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_13.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行环境可能导致fputs写入失败（如stdout被重定向到有写入问题的文件）
- 触发路径: fputs("string", stdout); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_13.c:29
- 结论: 调用fputs时未检查返回值，违反CWE-252未检查返回值约定。写入stdout通常不会导致严重安全后果，但忽略返回值可能掩盖写入失败，在安全敏感场景下可能导致日志不完整或数据丢失。
- D验证: stage_c_preserved / ver_c3613af3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 418. hyp_path_1b442d555a0c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_16.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊前提条件，任意调用均存在未检查返回值的问题。
- 触发路径: fputs("string", stdout); @ CWE252_Unchecked_Return_Value__char_fputs_16.c:29
- 结论: fputs函数返回值未被检查，违反了CWE-252（Unchecked Return Value），可能导致输出失败未被检测到。
- D验证: stage_c_preserved / ver_63141f1c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 419. hyp_path_dc5f0d7cf3f6

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_14.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: fputs("string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_14.c:29
- 结论: fputs函数返回值未检查，违反CWE-252规范，可能导致写入失败时未发现错误
- D验证: stage_c_preserved / ver_e48e31b7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 420. hyp_path_73ff49e92e30

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_15.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 运行时环境异常（如stdout关闭或磁盘满）
- 触发路径: fputs("string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_15.c:30
- 结论: 未检查fputs返回值，违反CWE-252，可能导致写入失败未被检测。尽管stdout通常可靠，但在极端环境下（如管道关闭、磁盘满）可能失败，且代码无任何错误处理。
- D验证: stage_c_preserved / ver_3a289cae
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 421. hyp_path_67c18765b8bb

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_18.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊前提，任何调用fputs都应检查返回值
- 触发路径: fputs("string", stdout); // NOTE: Do not check the return value @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_18.c:29
- 结论: fputs返回值未检查，可能遗漏写入失败错误，违反CWE-252。
- D验证: stage_c_preserved / ver_5195bb1a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 422. hyp_path_d97525ba7f73

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_17.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: fputs调用发生错误（如stdout关闭、写错误）
- 触发路径: fputs("string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_17.c:30
- 结论: fputs返回值未检查，违反API contract，可能导致未处理的错误状态
- D验证: stage_c_preserved / ver_6daf2181
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 423. hyp_path_378087a9eafa

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_01.c:32
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入影响fscanf的执行结果（例如提供无效输入或提前关闭流），导致fscanf失败。
- 触发路径: fscanf(stdin, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_01.c:32
- 结论: fscanf函数调用后未检查返回值，违反API contract（CWE-252），可能使用未初始化数据或导致逻辑错误，但当前代码路径后续无实际使用，影响较低。
- D验证: stage_c_preserved / ver_add36aa3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 424. hyp_path_2ac55394842b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_01.c:57
- 漏洞类型: CWE-253
- CWE: CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制输入长度，使fread读取部分数据（如50字节）
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ case11函数内
- 结论: fread返回值检查条件使用!=而不是<，导致部分读取时触发错误处理，但仅打印失败消息，无后续使用不完整数据。属于API misuse，违反CWE-253，但无实际安全影响。
- D验证: stage_c_preserved / ver_4b4488b9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 425. hyp_path_e254171486c7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_02.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，导致fscanf读取失败（例如输入为空或格式不匹配）。
- 触发路径: fscanf(stdin, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_02.c:34
- 结论: fscanf返回值未检查，可能读取失败导致后续使用未初始化或错误数据。
- D验证: stage_c_preserved / ver_55344e1e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 426. hyp_path_98e77e0c7b4a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_03.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可通过提前关闭stdin或提供无效输入使fscanf失败，导致data未正确初始化。
- 触发路径: fscanf(stdin, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_03.c:34
- 结论: 在fscanf调用后未检查其返回值，违反了CWE-252，可能导致未初始化数据被使用，但代码上下文未展示后续sink操作，利用性较低。
- D验证: stage_c_preserved / ver_82ab28b7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 427. hyp_path_65e07751b138

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_05.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够导致fscanf读取失败，例如关闭stdin或提供不匹配的输入格式。
- 触发路径: /* NOTE: Do not check the return value */ fscanf(stdin, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_05.c:40
- 结论: 未检查fscanf的返回值，违反CWE-252。如果fscanf调用失败（例如stdin提前关闭），data缓冲区可能包含未初始化或残留数据，但后续使用路径未被当前代码片段覆盖，需进一步验证。
- D验证: stage_c_preserved / ver_418294b6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 428. hyp_path_eb80438e8c96

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_04.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin触发输入结束或格式错误条件
- 触发路径: fscanf(stdin, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_04.c:40
- 结论: 函数fscanf的返回值未被检查，如果fscanf读取失败（如输入结束或格式不匹配），data变量将保持调用前的未初始化或初始状态，违反CWE-252安全要求。
- D验证: stage_c_preserved / ver_636a12c3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 429. hyp_path_58ba88d758be

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_07.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin输入状态（如提前关闭流或提供导致fscanf失败的数据）
- 触发路径: fscanf(stdin, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_07.c:39
- 结论: fscanf函数返回值未被检查，违反CWE-252（未检查返回值）。代码中fscanf调用后未检查返回值，可能导致输入错误时程序基于未初始化数据继续执行，引发未定义行为。
- D验证: stage_c_preserved / ver_9d744938
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 430. hyp_path_26092a3033ff

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_06.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使fscanf返回0或EOF
- 触发路径: fscanf(stdin, "%99s\0", data); @ 39
- 结论: 未检查fscanf返回值，违反CWE-252，可能导致fscanf失败时使用未初始化数据或数据读取错误
- D验证: stage_c_preserved / ver_5a35ff16
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 431. hyp_path_9ea785f51ca6

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_09.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin输入使fscanf失败（如提供空输入或关闭流），且dataBuffer未初始化。
- 触发路径: fscanf(stdin, "%99s\0", data); @ L34
- 结论: 未检查fscanf返回值可能导致使用未初始化的dataBuffer数据，违反CWE-252。但证据中缺少后续使用data的代码，无法确认实际影响。
- D验证: stage_c_preserved / ver_ac3b40bd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 432. hyp_path_424ee0da830b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_10.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供无效输入或提前关闭输入流，导致fscanf返回0或EOF，使data缓冲区内容未定义。
- 触发路径: fscanf(stdin, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_10.c:34
- 结论: fscanf的返回值未被检查，当fscanf调用失败（如输入流结束或格式不匹配）时，data缓冲区内容未定义，后续使用该缓冲区可能导致未定义行为，违反CWE-252未检查返回值的要求。
- D验证: stage_c_preserved / ver_126c112e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 433. hyp_path_bed577251105

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_13.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够使fscanf失败（例如通过关闭stdin或提供无效输入）。
- 触发路径: fscanf(stdin, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_13.c:34
- 结论: fscanf函数返回值未检查，可能导致未初始化或无效数据被使用，违反CWE-252。
- D验证: stage_c_preserved / ver_c437b51b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 434. hyp_path_d57c9dca30af

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_14.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供数据或输入流出现错误
- 触发路径: fscanf(stdin, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_14.c:34
- 结论: fscanf的返回值未检查，可能导致后续逻辑基于未定义或错误的数据执行，符合CWE-252未检查返回值缺陷
- D验证: stage_c_preserved / ver_ba1c3190
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 435. hyp_path_69a854d61220

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_15.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin的状态（例如提供无效输入、触发EOF或关闭流）
- 触发路径: fscanf(stdin, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_15.c:35
- 结论: 调用fscanf后未检查返回值，违反CWE-252。如果fscanf读取失败（如EOF或错误），data缓冲区内容未定义，后续使用可能导致未初始化数据访问或程序异常。
- D验证: stage_c_preserved / ver_0769c1ab
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 436. hyp_path_1e977963099c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_17.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin的状态或输入内容，使得fscanf无法成功读取数据。
- 触发路径: fscanf(stdin, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_17.c:35
- 结论: fscanf的返回值未被检查，可能未检测到输入失败，导致后续使用未初始化或部分初始化的数据，存在信息泄露或逻辑错误的风险。
- D验证: stage_c_preserved / ver_9420ca6c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 437. hyp_path_32745fb623d7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_16.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入（例如通过本地输入或远程进程注入），使fscanf失败（如提供空输入或触发EOF）。
- 触发路径: fscanf(stdin, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_16.c:34
- 结论: 调用fscanf后未检查返回值，违反CWE-252。如果fscanf读取失败，data缓冲区保持初始化时的空字符串，但后续可能误用该数据，导致逻辑错误或未初始化变量使用风险。
- D验证: stage_c_preserved / ver_aa735f75
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 438. hyp_path_7a8c7685d5c5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_18.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin输入导致fscanf失败（例如EOF、格式不匹配）
- 触发路径: fscanf(stdin, "%99s\0", data); @ 34
- 结论: fscanf返回值未检查，违反API契约，可能导致后续使用未初始化数据，但当前代码片段未展示后续使用，可利用性低。
- D验证: stage_c_preserved / ver_41fcefc5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 439. hyp_path_051f6d7eed6e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_01.c:27
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout写入失败（如文件描述符无效或磁盘空间不足）
- 触发路径: fwrite((char *)"string", sizeof(char), strlen("string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_01.c:27
- 结论: fwrite返回值未检查，可能导致写入失败未被发现。
- D验证: stage_c_preserved / ver_5e069d84
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 440. hyp_path_b28c38fc5253

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_18.c:62
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可通过stdin提供格式不匹配的输入（如非空白字符或超出长度）使fscanf返回0，导致未处理的错误状态。
- 触发路径: void CWE252_Unchecked_Return_Value__char_fscanf_18_case1() { case11(); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_18.c:60-64; static void case11() { goto sink; sink: { char dataBuffer[100] = ""; char * data = dataBuffer; if (fscanf(stdin, "%99s\0", data) == EOF) { printLine("fscanf failed!"); } } } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_18.c:43-58
- 结论: fscanf返回值检查不完整：仅检查EOF，未处理返回0（输入格式不匹配）的情况，违反CWE-252要求完整检查函数返回值。虽然后续无直接使用dataBuffer，但API contract violation本身成立，存在未处理的错误状态。
- D验证: stage_c_preserved / ver_e6289821
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 441. hyp_path_860a2bf9a4f8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_17.c:66
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供导致fscanf失败（如提前关闭输入流或无效数据）
- 触发路径: if (fscanf(stdin, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_17.c:55; printLine("fscanf failed!"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_17.c:56
- 结论: fscanf的返回值被检查为EOF，但错误处理仅打印消息，未终止或错误恢复，导致fscanf失败后程序继续使用未更新数据（本例中无直接后续使用，但违反CWE-252规范要求恰当处理返回值）。
- D验证: stage_c_preserved / ver_804a48c3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 442. hyp_path_351d46900ae3

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_02.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过影响标准输出流（如关闭stdout）导致fwrite失败，但实际攻击场景有限；主要风险是程序未正确处理写入失败情况。
- 触发路径: fwrite((char *)"string", sizeof(char), strlen("string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_02.c:29
- 结论: fwrite函数返回值未检查，违反了CWE-252（未检查返回值）。尽管fwrite写入stdout通常成功，但在某些条件下（如stdout关闭、写错误）可能失败，导致数据未完整写入或程序状态不一致。
- D验证: stage_c_preserved / ver_1623df3b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 443. hyp_path_969b1b976983

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_03.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者无法直接控制stdout状态，但环境因素（如stdout关闭、磁盘空间不足）可能导致fwrite失败
- 触发路径: fwrite((char *)"string", sizeof(char), strlen("string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_03.c:29
- 结论: 函数fwrite的返回值未被检查，违反了API约定，可能导致未检测到的写入错误（如stdout关闭或磁盘空间不足时数据未完全写入）。环境因素不可控，但漏洞存在。
- D验证: stage_c_preserved / ver_1342ba04
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 444. hyp_path_dfae1e0d11f5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_05.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 运行环境中stdout可能被关闭或重定向到不可写目标（如磁盘满、管道破裂）
- 触发路径: fwrite((char *)"string", sizeof(char), strlen("string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_05.c:35
- 结论: fwrite调用未检查返回值，违反CWE-252未检查返回值要求，在stdout写入失败时可能导致数据丢失。
- D验证: stage_c_preserved / ver_3e988a92
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 445. hyp_path_cc0d9d7e156b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_04.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 标准输出写入操作失败（如输出重定向到文件且磁盘满）
- 触发路径: fwrite((char *)"string", sizeof(char), strlen("string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_04.c:35
- 结论: 未检查fwrite的返回值，可能忽略写入错误，导致数据丢失或不完整。
- D验证: stage_c_preserved / ver_02f396fc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 446. hyp_path_cd5adec6f60d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_06.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout 写入操作可能失败（如磁盘空间不足、文件描述符关闭）
- 触发路径: fwrite((char *)"string", sizeof(char), strlen("string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_06.c:34
- 结论: 函数 fwrite 的返回值未被检查，违反了 CWE-252。当写入 stdout 失败时（例如文件系统满、输出重定向关闭等），无法得知写入是否成功，可能导致数据丢失或逻辑错误。
- D验证: stage_c_preserved / ver_204518b6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 447. hyp_path_3892cb70950a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_07.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序执行到该代码路径，无需用户输入；但stdout可能因重定向或关闭而不可写。
- 触发路径: fwrite((char *)"string", sizeof(char), strlen("string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_07.c:34
- 结论: 调用fwrite函数写入stdout时未检查返回值，违反CWE-252（未检查返回值）。虽然攻击者无法直接控制写入内容，且写入失败概率较低，但若stdout被重定向或关闭，可能导致数据丢失或不完整，构成API misuse漏洞。
- D验证: stage_c_preserved / ver_7d980dca
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 448. hyp_path_be2e714cf8ff

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_10.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过某种方式影响stdout的写入（如重定向或关闭文件描述符），但在此上下文中可能性较低。
- 触发路径: fwrite((char *)"string", sizeof(char), strlen("string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_10.c:29
- 结论: 调用fwrite时未检查返回值，违反CWE-252（未检查返回值），可能在某些错误条件下导致数据写入失败未被发现。
- D验证: stage_c_preserved / ver_540c80f3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 449. hyp_path_03ff594a8290

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_09.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过影响stdout状态（如关闭管道、填满文件系统）导致fwrite失败
- 触发路径: fwrite((char *)"string", sizeof(char), strlen("string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_09.c:29
- 结论: 调用fwrite时未检查返回值，可能导致写入失败时部分数据丢失或程序状态不一致，违反CWE-252规范。
- D验证: stage_c_preserved / ver_e6887bb6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 450. hyp_path_7dad93063e07

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_15.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout写入失败（如重定向到文件且磁盘满）
- 触发路径: fwrite((char *)"string", sizeof(char), strlen("string"), stdout); @ CWE252_Unchecked_Return_Value__char_fwrite_15.c:30
- 结论: fwrite返回值未检查，违反API合约，可能导致未检测到的写入错误。
- D验证: stage_c_preserved / ver_45b4d0bb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 451. hyp_path_0995e35d34d2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_14.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够使 stdout 写入失败，例如在容器或沙箱环境中限制磁盘空间或破坏管道
- 触发路径: fwrite((char *)"string", sizeof(char), strlen("string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_14.c:29
- 结论: fwrite 返回值未被检查，违反 CWE-252 (Unchecked Return Value)。写入固定字符串到 stdout，但 stdout 写入可能因磁盘满、管道破裂等失败，攻击者可通过操纵环境（如限制磁盘空间或破坏管道）导致写入失败，而程序无法感知错误，可能造成数据丢失或后续逻辑异常。
- D验证: stage_c_preserved / ver_4e826242
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 452. hyp_path_fc19c63613b0

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_16.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者需要能够影响 stdout 的状态（例如通过重定向或关闭文件描述符），但此场景在正常执行中不太可能，且仅写入固定字符串。
- 触发路径: fwrite((char *)"string", sizeof(char), strlen("string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_16.c:29
- 结论: fwrite 返回值未检查，违反了 CWE-252（未检查返回值）的 API contract，可能导致写入失败未被检测。
- D验证: stage_c_preserved / ver_a4e15399
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 453. hyp_path_cef64b1c177b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_13.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特定攻击者控制，但错误可能由环境因素触发
- 触发路径: fwrite((char *)"string", sizeof(char), strlen("string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_13.c:29
- 结论: fwrite返回值未检查，违反CWE-252，可能导致写入不完整或错误未被捕获
- D验证: stage_c_preserved / ver_ee58f772
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 454. hyp_path_8ee331a2c157

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_17.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无需攻击者控制输入，但需要运行时环境导致 fwrite 写入失败（如 stdout 关闭、磁盘空间耗尽、权限不足等）
- 触发路径: fwrite((char *)"string", sizeof(char), strlen("string"), stdout); @ 30
- 结论: fwrite 的返回值未被检查，违反 API contract（CWE-252）。如果写入失败（如 stdout 关闭或磁盘满），则无法感知错误，可能导致数据丢失或程序行为异常。
- D验证: stage_c_preserved / ver_f2802112
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 455. hyp_path_fdd51aff0d04

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_01.c:27
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特定攻击者控制，但环境因素（如stdout关闭、磁盘满）可能导致putc失败。
- 触发路径: putc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_01.c:27
- 结论: 忽略putc返回值，违反CWE-252，可能导致写入失败未被检测，影响输出完整性。实际可利用性较低，因为仅输出单字符且环境因素难以控制，但代码存在明确的API contract violation。
- D验证: stage_c_preserved / ver_4973c940
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 456. hyp_path_284e51f8531f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_18.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响系统环境导致fwrite失败（如耗尽磁盘空间或关闭stdout）。
- 触发路径: fwrite((char *)"string", sizeof(char), strlen("string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_18.c:29
- 结论: 代码调用fwrite后未检查返回值，违反API契约（CWE-252），可能导致数据写入失败而不被察觉。
- D验证: stage_c_preserved / ver_1acd1d02
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 457. hyp_path_4686135ca04c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_03.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序可能处于错误状态（如 stdout 关闭或磁盘满）导致 putc 失败。
- 触发路径: putc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_03.c:29
- 结论: 未检查 putc 函数的返回值，违反 CWE-252（未检查返回值），可能导致输出错误未被发现。
- D验证: stage_c_preserved / ver_1c436ee5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 458. hyp_path_c48237f1d53c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_05.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊前提条件，仅需程序执行到此代码路径。
- 触发路径: putc((int)'A', stdout); @ CWE252_Unchecked_Return_Value__char_putc_05.c:35
- 结论: 在CWE252_Unchecked_Return_Value__char_putc_05.c的第35行，putc函数的返回值未被检查，违反了CWE-252（未检查返回值）的API契约。虽然此处的调用通常不会产生严重安全后果，但根据审计原则，仍视为API misuse。
- D验证: stage_c_preserved / ver_cb66a800
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 459. hyp_path_8dbb3108ab1c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_02.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout出现错误（如磁盘满、管道破裂等）。
- 触发路径: putc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_02.c:29
- 结论: 未检查putc的返回值，可能导致输出错误被忽略，违反CWE-252。
- D验证: stage_c_preserved / ver_f53fe734
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 460. hyp_path_acdec5a36316

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_06.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊前提条件，仅需 putc 执行。
- 触发路径: putc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_06.c:34
- 结论: 在 putc((int)'A', stdout) 调用中未检查返回值，违反了 CWE-252（未检查返回值），可能导致写入错误被忽略，构成 API 误用。
- D验证: stage_c_preserved / ver_05daaef7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 461. hyp_path_6c2cabb4fac1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_04.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过影响环境（如填满磁盘）导致 putc 失败，但非直接控制输入
- 触发路径: putc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_04.c:35
- 结论: 调用 putc 写入 stdout 时未检查返回值，违反 CWE-252（未检查返回值）。当写入失败（如磁盘满或管道关闭）时，程序无法感知错误，可能导致数据丢失或输出不完整。
- D验证: stage_c_preserved / ver_8937234a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 462. hyp_path_44f93eb5efd3

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_09.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无直接攻击者控制输入，但需要环境异常（如stdout关闭）
- 触发路径: putc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_09.c:29
- 结论: 在putc调用后未检查返回值，违反CWE-252（未检查返回值）。虽然直接安全影响较低，但可能在某些环境（如stdout关闭或写入错误）导致后续未定义行为或信息泄露。
- D验证: stage_c_preserved / ver_618ff545
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 463. hyp_path_9c2b0f3e0b66

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_07.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过重定向或关闭 stdout 使 putc 失败（但通常需要与环境交互）
- 触发路径: putc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_07.c:34
- 结论: 调用 putc 时未检查返回值，违反 CWE-252。如果 putc 失败（例如 stdout 关闭或写入错误），程序无法感知错误，可能导致数据丢失或不一致。
- D验证: stage_c_preserved / ver_cab7e559
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 464. hyp_path_8f4a463468a2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_13.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行环境可能导致 putc 失败（如 stdout 被关闭、磁盘满等）。
- 触发路径: putc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_13.c:29
- 结论: 在调用 putc 时未检查返回值，违反了 CWE-252，可能导致写入错误被忽略。
- D验证: stage_c_preserved / ver_a2d6d838
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 465. hyp_path_db63a802641b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_10.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序正常执行，但stdout可能处于错误状态（如文件系统满、管道关闭等）。
- 触发路径: putc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_10.c:29
- 结论: 函数putc的返回值未被检查，可能忽略写入错误，违反CWE-252要求，属于API contract misuse。
- D验证: stage_c_preserved / ver_393c7959
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 466. hyp_path_26ec330680f1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_14.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊攻击者控制条件，但 stdout 可能因程序环境或系统状态而写入失败。
- 触发路径: putc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_14.c:29
- 结论: 未检查 putc 返回值，违反 CWE-252：未检查返回值。当 putc 写入失败时（如 stdout 关闭或磁盘满），程序无法感知错误，可能导致数据丢失或不一致。
- D验证: stage_c_preserved / ver_af3f7010
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 467. hyp_path_6e2affe92140

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_17.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无需攻击者控制输入；函数调用本身忽略返回值即构成安全缺陷。
- 触发路径: putc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_17.c:30
- 结论: 调用 putc 函数后未检查返回值，可能导致未检测到的写入错误（如 stdout 关闭或出错），违反 CWE-252：Unchecked Return Value。
- D验证: stage_c_preserved / ver_6a185c43
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 468. hyp_path_27fc7195aef5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_16.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过资源耗尽（如文件系统满、stdout 被关闭）导致 putc 失败
- 触发路径: putc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_16.c:29
- 结论: putc 函数的返回值未被检查，违反 API contract，属于 CWE-252 未检查返回值漏洞。
- D验证: stage_c_preserved / ver_147dc6e5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 469. hyp_path_79e887c061c0

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_18.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: putc((int)'A', stdout); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_18.c:29
- 结论: 未检查 putc 返回值，违反 API contract，可能导致输出错误未被感知。
- D验证: stage_c_preserved / ver_38611c94
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 470. hyp_path_656e516bfc93

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_15.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过某种方式导致stdout处于错误状态（如关闭文件描述符或使流不可写）
- 触发路径: putc((int)'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_15.c:30
- 结论: 在CWE252_Unchecked_Return_Value__char_putc_15.c的case 6中，putc((int)'A', stdout)的返回值未被检查，违反了CWE-252要求检查返回值的契约，可能导致在stdout出错时程序无法感知，造成输出数据丢失或行为异常。
- D验证: stage_c_preserved / ver_1c9d6755
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 471. hyp_path_88484c26094d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_01.c:27
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无攻击者控制输入
- 触发路径: putchar((int)'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_01.c:27
- 结论: 调用 putchar 时未检查返回值，违反 CWE-252 未检查返回值规则，但输入为常量字符，无攻击者控制，实际影响较低。
- D验证: stage_c_preserved / ver_ad80354f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 472. hyp_path_d8c0cb85307a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_03.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: putchar((int)'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_03.c:29
- 结论: 调用putchar时未检查返回值，违反CWE-252（未检查返回值）的API contract。尽管putchar返回值通常不关键，但根据CWE定义，未检查返回值即构成安全漏洞，可能导致未处理的写错误或数据丢失。
- D验证: stage_c_preserved / ver_46bb4130
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 473. hyp_path_8429caf4243a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_02.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够造成putchar写入失败（例如，通过消耗文件系统空间或使stdout关闭）
- 触发路径: putchar((int)'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_02.c:29
- 结论: putchar函数返回值未检查，违反CWE-252未检查返回值，可能导致在写入失败时程序继续执行，丢失数据或引发未定义行为。
- D验证: stage_c_preserved / ver_d30107dd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 474. hyp_path_a4402d67a096

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_05.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 依赖系统环境错误（如stdout关闭或磁盘满），无外部输入控制
- 触发路径: putchar((int)'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_05.c:35
- 结论: 未检查putchar函数的返回值。根据CWE-252，忽略返回值可能导致未处理的错误状态，例如写入失败时程序仍以为成功，可能引起后续逻辑错误或数据不一致。
- D验证: stage_c_preserved / ver_3d412181
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 475. hyp_path_ab0042b28c3d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_04.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无需特殊前提，任何执行路径都会触发该未检查返回值的调用。
- 触发路径: putchar((int)'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_04.c:35
- 结论: 未检查 putchar 函数的返回值，违反 CWE-252，可能导致输出错误未被发现。
- D验证: stage_c_preserved / ver_11326805
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 476. hyp_path_5e170fb4f1ad

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_06.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响输出设备或文件系统状态，导致putchar失败。
- 触发路径: putchar((int)'A'); @ L34
- 结论: 未检查putchar的返回值，可能忽略输出错误，导致数据丢失或不完整。
- D验证: stage_c_preserved / ver_3f3b93b1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 477. hyp_path_9cc9761e6cee

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_07.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 应用程序运行在输出可能失败的环境（如磁盘满、stdout关闭），但无需攻击者输入控制。
- 触发路径: putchar((int)'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_07.c:34
- 结论: 函数putchar的返回值未被检查，即使putchar执行失败（例如stdout关闭或出错），错误也被忽略，违反CWE-252规则。
- D验证: stage_c_preserved / ver_fd22ad2c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 478. hyp_path_dad2512bbed6

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_09.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部输入控制，代码直接调用putchar
- 触发路径: putchar((int)'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_09.c:29
- 结论: 未检查putchar的返回值，违反CWE-252：未检查返回值。虽然此处仅输出单个字符，但失败可能导致数据未输出，在安全上下文中可能引发问题。
- D验证: stage_c_preserved / ver_882228da
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 479. hyp_path_36ed1fc1574d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_10.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdout的输出目标（例如通过重定向、修改文件描述符或关闭管道），使得putchar写入失败返回EOF。
- 触发路径: putchar((int)'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_10.c:29
- 结论: 未检查putchar的返回值，违反CWE-252（未检查返回值）。虽然此实例仅输出单个字符，且后续无逻辑依赖，但函数返回值未被检查，若写入失败（如stdout重定向至不可写文件或管道关闭）则错误被忽略，符合CWE-252定义。
- D验证: stage_c_preserved / ver_088e32c4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 480. hyp_path_2feb1cae27a1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_13.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: putchar((int)'A'); @ L29
- 结论: 调用 putchar 后未检查返回值，可能导致未检测到的 I/O 错误，违反 CWE-252 (Unchecked Return Value)。
- D验证: stage_c_preserved / ver_2dc71761
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 481. hyp_path_059d77bc0120

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_15.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行至case 6分支
- 触发路径: case 6: /* NOTE: Do not check the return value */ putchar((int)'A'); break; @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_15.c:30
- 结论: 未检查putchar()的返回值，可能导致输出操作失败未被检测到，违反CWE-252 API contract。
- D验证: stage_c_preserved / ver_f63f99a1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 482. hyp_path_903170da20be

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_16.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响 stdout 的状态（如关闭、重定向、或导致写入错误）
- 触发路径: putchar((int)'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_16.c:29
- 结论: 在 putchar 调用后未检查返回值，违反 CWE-252 未检查返回值，可能导致输出错误未被发现。
- D验证: stage_c_preserved / ver_bcf3e11b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 483. hyp_path_47e338b2fba9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_17.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无攻击者控制输入，仅为 API 使用不规范
- 触发路径: putchar((int)'A'); @ CWE252_Unchecked_Return_Value__char_putchar_17.c:30
- 结论: 忽略 putchar 返回值可能导致未检测到的输出错误，符合 CWE-252 定义
- D验证: stage_c_preserved / ver_51822e2e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 484. hyp_path_f71f0255478e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_14.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 输出可能因环境因素（如文件系统满、stdout重定向失败）而失败。
- 触发路径: putchar((int)'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_14.c:29
- 结论: 调用putchar后未检查其返回值，违反了CWE-252（Unchecked Return Value）的API合约。虽然当前示例仅输出单个字符，但错误条件（如写入失败）可能被忽略，导致静默失败或未定义行为。
- D验证: stage_c_preserved / ver_46eff589
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 485. hyp_path_a53a2189f0a6

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_18.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: sink: /* NOTE: Do not check the return value */ putchar((int)'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putchar_18.c:29
- 结论: 函数 putchar 的返回值未被检查，违反 CWE-252 定义。当 putchar 失败时（例如文件流错误），程序无法感知错误，可能导致未定义行为或信息丢失。
- D验证: stage_c_preserved / ver_22d482d1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 486. hyp_path_c6077cd75b1c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_01.c:33
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊前提条件，任何执行路径都会触发未检查返回值的调用。
- 触发路径: PUTS("string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_01.c:33
- 结论: CWE252: 未检查puts()函数的返回值。函数puts()可能失败并返回EOF，但代码明确注释不检查返回值，违反了安全使用API的约定。
- D验证: stage_c_preserved / ver_e1e9f6d7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 487. hyp_path_b08b2346ea50

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_02.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序执行到该代码路径
- 触发路径: PUTS("string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_02.c:35
- 结论: 调用PUTS函数后未检查其返回值，违反CWE-252。尽管传入硬编码字符串，但PUTS调用可能失败（如文件描述符问题、管道破裂等），返回值未检查导致错误被忽略，符合CWE-252定义。
- D验证: stage_c_preserved / ver_3eaf556d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 488. hyp_path_882e085fce06

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_05.c:41
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 任何导致puts失败的环境条件（如磁盘满、stdout关闭）
- 触发路径: PUTS("string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_05.c:41
- 结论: puts函数的返回值未被检查，违反了API contract，可能导致程序在puts失败时继续执行而忽略错误状态。
- D验证: stage_c_preserved / ver_00108722
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 489. hyp_path_e030c32899df

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_03.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部输入控制，但返回值检查是必须的
- 触发路径: PUTS("string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_03.c:35
- 结论: 对puts的返回值未进行检查，可能导致错误状态被忽略，违反CWE-252。
- D验证: stage_c_preserved / ver_fe8a38de
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 490. hyp_path_87d4637091d1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_04.c:41
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部输入控制；攻击者无法直接导致puts失败，但可能存在输出设备错误等不可控因素
- 触发路径: PUTS("string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_04.c:41
- 结论: 函数PUTS（实际为puts）的返回值未被检查，违反了CWE-252（未检查返回值）。尽管当前调用为固定字符串，失败可能性低，但违反了API contract。
- D验证: stage_c_preserved / ver_43d62c5a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 491. hyp_path_3b7ff66d2d9a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_06.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行环境可能导致 puts 输出失败（如 stdout 关闭、磁盘满）。
- 触发路径: PUTS("string"); @ CWE252_Unchecked_Return_Value__char_puts_06.c:40
- 结论: 未检查 puts() 函数的返回值，违反 CWE-252 未检查返回值，可能导致未处理的错误状态（如输出失败），但实际影响较低。
- D验证: stage_c_preserved / ver_6494d09e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 492. hyp_path_9f43066573af

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_07.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过关闭stdout或耗尽文件描述符来导致puts失败，但通常需要本地用户或特定环境条件。
- 触发路径: /* NOTE: Do not check the return value */ PUTS("string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_07.c:40
- 结论: 在调用puts函数后未检查其返回值，违反了CWE-252（未检查返回值）。puts函数可能因stdout关闭或写入错误而返回EOF，但返回值被忽略，可能导致数据丢失或程序行为异常。
- D验证: stage_c_preserved / ver_bdf84dfd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 493. hyp_path_bfdb7fa76dda

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_10.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: PUTS("string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_10.c:35
- 结论: 在 puts 调用后未检查返回值，违反了 CWE-252（未检查返回值）的 API contract。
- D验证: stage_c_preserved / ver_86f44d35
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 494. hyp_path_1f9b35de87eb

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_13.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行环境可能导致 PUTS 失败（如磁盘满、权限不足或输出流关闭）。
- 触发路径: PUTS("string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_13.c:35
- 结论: CWE-252 未检查返回值：调用 PUTS 时未检查其返回值，当输出操作失败时可能导致程序状态不一致或后续错误。
- D验证: stage_c_preserved / ver_e89f7f01
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 495. hyp_path_609534cd795c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_16.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 环境因素（如文件系统满、设备错误）可能导致puts返回EOF
- 触发路径: PUTS("string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_16.c:35
- 结论: 调用puts时未检查返回值，违反CWE-252未检查返回值，可能因环境因素导致输出失败但未被检测。参数为字符串常量，影响较低，但仍违反API契约。
- D验证: stage_c_preserved / ver_23eb892e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 496. hyp_path_f24ceb8cebb7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_15.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够导致标准输出写入失败（例如通过填满磁盘空间或关闭stdout）
- 触发路径: PUTS("string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_15.c:36
- 结论: 未检查puts()函数的返回值，违反CWE-252。如果puts失败，程序无法感知，可能导致丢失输出或逻辑错误。
- D验证: stage_c_preserved / ver_c4de08ac
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 497. hyp_path_8c7192752442

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_14.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过影响系统资源（如磁盘满、stdout重定向）导致puts失败，但无需直接控制输入。
- 触发路径: PUTS("string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_14.c:35
- 结论: 在代码片段中，调用puts函数后未检查其返回值，违反CWE-252定义。puts返回非负表示成功，EOF表示失败，未检查可能导致程序忽略输出错误。虽然puts参数为常量，失败概率较低且无后续关键操作依赖其成功，实际影响有限，但漏洞存在。
- D验证: stage_c_preserved / ver_7627c037
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 498. hyp_path_3a2c20db7dd2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_17.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者无法直接控制输入，但可能通过影响环境（如关闭stdout）使puts失败。
- 触发路径: PUTS("string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_17.c:36
- 结论: 调用puts函数未检查返回值，违反CWE252定义，可能导致输出失败未被处理。
- D验证: stage_c_preserved / ver_db001725
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 499. hyp_path_36ff51e3b0f1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_18.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 输出环境可能异常（如文件系统满、输出流错误等），但无需攻击者控制输入。
- 触发路径: /* NOTE: Do not check the return value */ PUTS("string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_18.c:35
- 结论: 在puts函数调用后未检查返回值，可能忽略写入错误，违反CWE-252。
- D验证: stage_c_preserved / ver_16eb1706
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 500. hyp_path_dd6053060954

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_01.c:32
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入
- 触发路径: scanf("%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_01.c:32
- 结论: 未检查scanf的返回值，如果输入失败，data可能包含未定义内容，违反CWE-252未检查返回值
- D验证: stage_c_preserved / ver_cce6ab43
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 501. hyp_path_e3d0a9023f3f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_03.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响标准输入流（例如关闭输入、注入无效数据）
- 触发路径: scanf("%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_03.c:34
- 结论: 未检查 scanf() 的返回值，违反 API contract，可能导致未处理的输入错误或未初始化数据使用。
- D验证: stage_c_preserved / ver_62286482
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 502. hyp_path_66b88b747fc8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_02.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够向程序的标准输入提供数据，以触发scanf失败（如提前关闭输入流或提供不匹配的数据）。
- 触发路径: scanf("%99s\0", data); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_02.c:34
- 结论: scanf函数的返回值未被检查，违反了CWE-252（未检查返回值），可能导致程序在输入失败时使用未定义或未正确填充的数据，进而引发逻辑错误或信息泄露。
- D验证: stage_c_preserved / ver_34115288
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 503. hyp_path_57dd033182c8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_04.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入，使得scanf读取失败或返回0。
- 触发路径: scanf("%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_04.c:40
- 结论: 调用scanf未检查返回值，违反CWE-252。scanf可能读取失败导致data未更新，但后续可能使用未定义的缓冲区内容，存在潜在的信息泄露或逻辑错误风险。
- D验证: stage_c_preserved / ver_c6da4517
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 504. hyp_path_c5f8117eba1c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_05.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供输入，导致 scanf 读取失败或输入异常数据。
- 触发路径: scanf("%99s\0", data); @ 40
- 结论: 未检查 scanf 返回值，可能导致使用未初始化或无效数据。
- D验证: stage_c_preserved / ver_09c7f463
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 505. hyp_path_13256cc14c1a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_07.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响输入流（如stdin）导致scanf失败
- 触发路径: scanf("%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_07.c:39
- 结论: 程序调用scanf函数但不检查返回值，违反CWE-252（未检查返回值）定义的API contract。如果scanf失败（例如文件结束或输入错误），dataBuffer可能包含未初始化的数据，后续使用可能导致未定义行为或信息泄露。
- D验证: stage_c_preserved / ver_5629db4a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 506. hyp_path_6e0970a28a95

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_10.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无需特定攻击者控制，scanf在任何输入失败场景下均未检查返回值。
- 触发路径: scanf("%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_10.c:34
- 结论: 调用scanf时未检查返回值，违反CWE-252（未检查返回值）的API contract，导致在输入失败（如EOF或格式不匹配）时data内容保持未初始化状态，后续使用可引发未定义行为。
- D验证: stage_c_preserved / ver_6b88f2c7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 507. hyp_path_97b17a12e079

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_06.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过控制输入导致 scanf 失败或部分读取，例如输入流结束或格式匹配失败。
- 触发路径: scanf("%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_06.c:39
- 结论: 未检查 scanf() 的返回值，可能导致后续使用未初始化或部分初始化的 data 缓冲区数据。
- D验证: stage_c_preserved / ver_549f8f38
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 508. hyp_path_8c92ba56c2f5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_09.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 用户输入可能触发scanf失败（如EOF或格式错误）
- 触发路径: scanf("%99s\0", data); // 未检查返回值 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_09.c:34
- 结论: 未检查scanf函数的返回值，违反CWE-252（未检查返回值）。虽然代码明确忽略返回值，但后续未展示对未初始化数据的使用，实际安全影响依赖于下游逻辑，需要动态验证或审计确认。
- D验证: stage_c_preserved / ver_e5fce956
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 509. hyp_path_76560663ada0

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_13.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 用户输入不符合格式预期或IO错误，导致scanf返回EOF或匹配失败。
- 触发路径: scanf("%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_13.c:34
- 结论: 未检查scanf的返回值，导致在输入失败时dataBuffer保持未初始化状态，存在使用未初始化内存的风险，违反CWE-252。
- D验证: stage_c_preserved / ver_514fa030
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 510. hyp_path_0e7e685f56a3

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_15.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够操纵输入流使scanf()失败（如提前关闭stdin或输入不匹配格式）
- 触发路径: scanf("%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_15.c:35
- 结论: 代码未检查scanf()返回值，违反CWE-252（未检查返回值）。如果scanf失败（如输入流结束或匹配失败），dataBuffer可能包含未初始化数据，导致后续使用不可预测行为。
- D验证: stage_c_preserved / ver_30d24dfa
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 511. hyp_path_0e9ce52edcaf

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_16.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供格式化字符串不匹配的输入
- 触发路径: scanf("%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_16.c:34
- 结论: 未检查scanf()返回值，违反API合约，可能导致输入失败时数据未正确写入，引发未定义行为。
- D验证: stage_c_preserved / ver_e022a5a0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 512. hyp_path_1b4fbb3a2646

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_14.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响程序输入，导致scanf返回值不等于1。
- 触发路径: scanf("%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_14.c:34
- 结论: 未检查scanf返回值，违反API contract，可能导致后续使用未初始化或错误数据，但缺少后续数据使用的确认，证据不完整。
- D验证: stage_c_preserved / ver_47e6bd80
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 513. hyp_path_8ba046244b1e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_18.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供输入导致scanf失败（如提前关闭stdin或输入非预期格式）
- 触发路径: scanf("%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_18.c:34
- 结论: 未检查scanf()返回值，违反CWE-252。如果scanf失败，data可能包含未初始化数据，导致后续使用不可信数据，造成未定义行为或信息泄露。
- D验证: stage_c_preserved / ver_47fbd885
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 514. hyp_path_13a0fa553248

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_16.c:66
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够向程序提供输入，使得scanf无法匹配%99s格式（例如输入仅包含空白字符或提前EOF）
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_16.c:62
- 结论: 在case11函数中，scanf返回值仅检查了EOF，未检查返回0（输入不匹配）的情况，构成CWE-252未检查返回值的违规。尽管dataBuffer已初始化为空字符串降低了未初始化使用的风险，但程序未正确处理scanf失败的情况，违反了API contract。
- D验证: stage_c_preserved / ver_693a7d00
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 515. hyp_path_7c65ebea3caa

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_17.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制程序的标准输入，提供导致scanf返回0或EOF的输入（如空输入、格式不匹配或关闭输入流）。
- 触发路径: scanf("%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_17.c:35
- 结论: 调用scanf未检查返回值，违反CWE-252，但缺乏dataBuffer初始化及后续使用证据，实际影响不明确。
- D验证: stage_c_preserved / ver_bc90fd7f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 516. hyp_path_50f6736eede8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_18.c:62
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供输入，使得scanf返回0（例如，输入为空或仅含空白字符）。
- 触发路径: if (scanf("%99s\0", data) == EOF) { printLine("scanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_18.c:50
- 结论: 在case11函数中，scanf的返回值检查不完整：仅检查了EOF，未处理返回0的情况（例如输入仅含空白字符或为空）。虽然dataBuffer已初始化为空字符串，实际风险很低，但仍违反CWE-252要求完整检查返回值的契约。
- D验证: stage_c_preserved / ver_8c328b19
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 517. hyp_path_fac7e9c8d134

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_01.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC的内容和长度（但在当前测试用例中不可控）
- 触发路径: SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_01.c:40
- 结论: snprintf返回值未检查，违反CWE-252，尽管当前测试用例中SRC为固定字符串，导致截断风险较低，但代码本身存在API misuse，可能在其他上下文中被利用。
- D验证: stage_c_preserved / ver_5dee2253
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 518. hyp_path_b40ca53f3845

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_02.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无攻击者可控输入，但缓冲区大小随 SRC 变化，若 SRC 意外变长或环境更改，返回值可指示截断错误。
- 触发路径: SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_02.c:42
- 结论: 未检查 snprintf 返回值，违反 CWE-252 未检查返回值的要求。虽然数据来源为本地固定字符串，无直接外部输入，但违反 API 契约可能导致在缓冲区大小计算错误或环境变化时输出截断不可检测，存在潜在稳定性风险。
- D验证: stage_c_preserved / ver_376d6feb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 519. hyp_path_bbe426f2b6f0

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_04.c:48
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序执行到该snprintf调用处
- 触发路径: SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_04.c:48
- 结论: snprintf返回值未检查，可能导致输出截断或未完全写入，违反CWE-252 Unchecked Return Value的API契约。
- D验证: stage_c_preserved / ver_e9bd84c2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 520. hyp_path_2c6fd9e6f957

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_03.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 输入SRC为固定字符串，但攻击者可通过其他路径修改全局状态（如SRC指向的内存）影响调用结果。
- 触发路径: SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC); @ 42
- 结论: snprintf返回值未被检查，违反了CWE-252，可能导致未检测到的输出错误或数据截断。尽管当前输入为固定字符串，但根据CWE定义，任何对可能失败的API返回值不检查均构成漏洞。
- D验证: stage_c_preserved / ver_0f1f0e68
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 521. hyp_path_ec63b57ca13b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_06.c:47
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能间接控制 SRC 的长度，导致 snprintf 截断输出。
- 触发路径: SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_06.c:47
- 结论: snprintf 函数调用未检查返回值，可能导致数据截断或信息丢失，违反 CWE-252 关于未检查返回值的约定。
- D验证: stage_c_preserved / ver_e61f6b56
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 522. hyp_path_1ed8a61a6b86

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_10.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: snprintf返回值被忽略，任何截断或错误均不可知。
- 触发路径: SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_10.c:42
- 结论: 函数snprintf的返回值未被检查，违反CWE-252。忽略返回值可能导致截断或写入失败未被检测，造成数据不完整或逻辑错误。
- D验证: stage_c_preserved / ver_e3fc39db
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 523. hyp_path_433f520e76af

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_07.c:47
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_07.c:47
- 结论: snprintf 返回值未检查，违反 CWE-252 API contract，即使当前输入不导致截断，也是编程缺陷。
- D验证: stage_c_preserved / ver_7b01c95a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 524. hyp_path_51daa2844fc5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_05.c:48
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: SRC 内容导致输出长度超过缓冲区限制
- 触发路径: SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_05.c:48
- 结论: snprintf 返回值未检查，可能导致未检测到输出截断（CWE-252）
- D验证: stage_c_preserved / ver_3b1a1492
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 525. hyp_path_4a630e862621

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_09.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者无法控制SRC内容，SRC为编译时常量
- 触发路径: SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_09.c:42
- 结论: SNPRINTF返回值未检查，违反API契约，但输入SRC为编译时常量，攻击者无法控制，因此安全影响较低，可能导致未被识别的数据截断，但实际可利用性低。
- D验证: stage_c_preserved / ver_5f085420
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 526. hyp_path_eead73589b04

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_14.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 存在 snprintf 调用，且返回值未被检查。
- 触发路径: SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_14.c:42
- 结论: 在 snprintf 调用后未检查返回值，违反 CWE-252 未检查返回值的要求。snprintf 可能因缓冲区大小不足或写入错误而失败，未检查返回值会导致程序无法感知错误，可能引发数据截断或未定义行为。
- D验证: stage_c_preserved / ver_02ff20c8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 527. hyp_path_4289601cbee1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_13.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 代码中明确注释不检查返回值，但无外部输入。
- 触发路径: SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_13.c:42
- 结论: snprintf返回值未被检查，违反CWE252（未检查返回值）。尽管输入为固定字符串，但未检查返回值可能导致未检测到的截断，违反API契约。
- D验证: stage_c_preserved / ver_64007415
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 528. hyp_path_7fd9d28f788d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_15.c:43
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: snprintf may return a negative value indicating an output error, though unlikely with given constants.
- 触发路径: SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_15.c:43
- 结论: CWE-252: Unchecked Return Value - snprintf's return value is not checked, violating API contract. Although practical exploitability is low due to fixed format and constant SRC, the contract violation persists.
- D验证: stage_c_preserved / ver_4eb61c71
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 529. hyp_path_0e51bcd8f6f6

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_16.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: SRC字符串长度超过缓冲区剩余空间时，snprintf可能截断输出，但调用方未检查返回值。
- 触发路径: SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_16.c:42
- 结论: snprintf返回值未检查，可能导致输出截断，违反CWE252（Unchecked Return Value）。
- D验证: stage_c_preserved / ver_3cb161ad
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 530. hyp_path_ffc3fbae9b97

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_17.c:43
- 漏洞类型: buffer_overflow
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者控制SRC内容可能导致缓冲区溢出或写入失败，但实际利用困难。
- 触发路径: SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_17.c:43
- 结论: 调用SNPRINTF未检查返回值，违反CWE-252（Unchecked Return Value）API contract，可能导致未检测的截断或写入失败。
- D验证: stage_c_preserved / ver_a65bdf3a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 531. hyp_path_42d6f11f41bb

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_18.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无需特定攻击者输入，任何导致snprintf写入数据超出缓冲区剩余大小或系统写入错误的情况均可能触发未处理错误。
- 触发路径: SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_18.c:42
- 结论: CWE252漏洞：函数snprintf的返回值未被检查，违反API契约。如果snprintf因缓冲区大小不足或写入错误而失败，程序无法感知，可能导致数据截断或未处理错误状态，进而影响后续逻辑。
- D验证: stage_c_preserved / ver_96d2f162
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 532. hyp_path_e55cc197a926

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_16.c:74
- 漏洞类型: integer_overflow
- CWE: CWE-121; CWE-190
- 风险等级: P1
- 触发条件: 攻击者能够控制全局变量SRC的值（通过之前调用的fgets设置），使其长度大于等于100
- 触发路径: if (SNPRINTF(data,100-strlen(SRC)-1, "%s\n", SRC) < 0) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_16.c:65
- 结论: snprintf调用的长度参数计算存在整数溢出风险，当SRC长度大于等于100时，100-strlen(SRC)-1变为负数，在转换为size_t后变成极大值，snprintf会尝试写入大量数据，导致栈缓冲区溢出。
- D验证: stage_c_preserved / ver_40ed61fc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 533. hyp_path_9da4ed9c0615

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_01.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC的内容（或SRC来自不可信源），导致sscanf返回非预期值。
- 触发路径: sscanf(SRC, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_01.c:34
- 结论: 调用sscanf后未检查返回值，违反CWE-252。若sscanf失败（例如输入格式不匹配或读取错误），data可能保持未初始化或部分初始化的状态，导致后续使用时发生未定义行为。
- D验证: stage_c_preserved / ver_dd1d814f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 534. hyp_path_79b7f49dab5e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_02.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: sscanf的输入SRC可能失败（如空字符串或格式不匹配），导致data内容保持不变（可能未初始化）
- 触发路径: sscanf(SRC, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_02.c:36
- 结论: 未检查sscanf返回值，违反CWE-252，可能导致使用未正确初始化的数据。
- D验证: stage_c_preserved / ver_d81f34bc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 535. hyp_path_bd161eebb628

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_04.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制 SRC 输入，使其不符合格式字符串要求，导致 sscanf 返回 0 或小于预期的匹配数。
- 触发路径: sscanf(SRC, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_04.c:42
- 结论: sscanf 返回值未检查，违反 CWE-252 规则，可能导致后续使用未定义或部分填充的数据。
- D验证: stage_c_preserved / ver_d5ffaeca
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 536. hyp_path_cc93aba7d4af

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_05.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过宏定义SRC控制输入内容，使其无法完全匹配格式字符串，导致sscanf失败（返回0或EOF）。
- 触发路径: sscanf(SRC, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_05.c:42
- 结论: 未检查sscanf返回值，违反CWE-252 Unchecked Return Value，若sscanf失败则dataBuffer内容可能保持初始值（空字符串），但程序未验证操作是否成功，后续使用可能产生逻辑错误。
- D验证: stage_c_preserved / ver_18579a96
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 537. hyp_path_0bf538580d47

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_03.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC输入，使其不匹配格式（例如空字符串或非字符串），导致sscanf返回0或EOF。
- 触发路径: sscanf(SRC, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_03.c:36
- 结论: sscanf返回值未被检查，存在API契约违反（CWE-252），即使当前路径未展示后续使用，未检查返回值本身构成安全缺陷。
- D验证: stage_c_preserved / ver_da1949cc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 538. hyp_path_08c415748775

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_07.c:41
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响SRC的值（如控制输入字符串）
- 触发路径: sscanf(SRC, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_07.c:41
- 结论: 未检查sscanf返回值，违反API契约，可能导致数据未正确初始化或更新，属于CWE-252未检查返回值漏洞。
- D验证: stage_c_preserved / ver_d93aaa7c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 539. hyp_path_f29108f2ecec

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_06.c:41
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: sscanf调用可能失败（例如输入格式不匹配或EOF），但返回值未被检查，导致data可能处于未初始化或部分填充状态。SRC为常量，实际失败可能性较低。
- 触发路径: sscanf(SRC, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_06.c:41
- 结论: 调用sscanf后未检查返回值，违反API contract，存在CWE-252未检查返回值漏洞。
- D验证: stage_c_preserved / ver_e1f7bb48
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 540. hyp_path_9d62f96ac6fc

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_10.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC输入（但实际SRC为常量，不满足）
- 触发路径: sscanf(SRC, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_10.c:36
- 结论: sscanf调用未检查返回值，违反CWE-252，但SRC是固定常量，攻击者无法控制输入，因此无实际可利用路径。
- D验证: stage_c_preserved / ver_7b2e8c67
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 541. hyp_path_7b8fab689690

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_09.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 假设SRC可能由攻击者控制或环境导致sscanf失败，但证据中SRC来源未指定。
- 触发路径: sscanf(SRC, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_09.c:36
- 结论: sscanf函数返回值未检查，违反CWE-252，但缺乏后续使用未初始化数据的证据且输入SRC来源未明确，可利用性较低。
- D验证: stage_c_preserved / ver_da6650de
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 542. hyp_path_d29701a2f08a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_12.c:94
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_12.c:82
- 结论: CWE252_Unchecked_Return_Value: sscanf返回值仅检查EOF，未检查成功匹配数，导致返回值未完全验证
- D验证: stage_c_preserved / ver_2d4e1711
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 543. hyp_path_647e4f095d70

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_15.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制输入字符串SRC，使其无法与格式字符串匹配，或导致sscanf返回失败。
- 触发路径: sscanf(SRC, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_15.c:37
- 结论: 存在CWE-252未检查返回值漏洞：sscanf调用后未检查返回值，可能导致使用未初始化的数据或静默失败。
- D验证: stage_c_preserved / ver_b6a1bda8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 544. hyp_path_e1be66a91b2e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_13.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能能够影响SRC的内容或输入流，但SRC的定义（如是否来自外部输入）未在代码证据中提供
- 触发路径: sscanf(SRC, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_13.c:36
- 结论: sscanf函数的返回值未被检查，违反CWE-252（未检查返回值）。如果sscanf执行失败（例如输入格式不匹配或达到文件结尾），数据缓冲区可能未被正确初始化，导致后续使用未初始化数据，引发未定义行为。但SRC的来源和可控性未在代码片段中明确，因此可利用性较低。
- D验证: stage_c_preserved / ver_f2ab1a4c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 545. hyp_path_c377da7302a1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_14.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者需要能够控制SRC的内容，使得sscanf调用失败或返回非预期值。但当前代码片段中SRC来源未定义，可能为固定字符串，导致此条件不一定满足。
- 触发路径: sscanf(SRC, "%99s\0", data); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_14.c:36
- 结论: sscanf函数的返回值未被检查，违反CWE-252。虽然具体可利用性取决于SRC是否可控及data的后续使用，但代码中明确缺少返回值检查，构成API contract violation。
- D验证: stage_c_preserved / ver_6a8ec771
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 546. hyp_path_b20c26253acc

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_16.c:68
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制sscanf的输入字符串（SRC）
- 触发路径: if (sscanf(SRC, "%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_16.c:60
- 结论: sscanf返回值检查不完整：代码仅检查返回值是否为EOF，但未检查返回值是否等于期望的匹配项数（例如1）。sscanf可能因输入不匹配而返回0，此时data未被正确填充，但程序不处理此情况。尽管dataBuffer已初始化为空字符串，且后续仅打印，违反CWE-252原则，存在潜在未定义行为风险。
- D验证: stage_c_preserved / ver_208e4641
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 547. hyp_path_69537f7359f0

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_16.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制 SRC 输入（在当前测试样本中不成立，但代码逻辑允许此类输入）。
- 触发路径: sscanf(SRC, "%99s\0", data); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_16.c:36
- 结论: sscanf 返回值未被检查，违反 API contract，存在 CWE-252 漏洞（未检查返回值）。尽管当前测试用例中 SRC 为固定字符串导致 sscanf 始终成功，数据被初始化，但代码本身缺少返回值检查，违反了安全编码规范。
- D验证: stage_c_preserved / ver_e756010b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 548. hyp_path_0432b9267957

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_17.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC内容（如空字符串或特殊字符）导致sscanf匹配失败。
- 触发路径: sscanf(SRC, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_17.c:37
- 结论: 未检查sscanf返回值，违反CWE-252 API contract，但缺乏后续使用data的sink代码，无法确认安全影响，需要动态验证或审计补充后续代码。
- D验证: stage_c_preserved / ver_fbf720e1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 549. hyp_path_dacd78dee0d3

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_18.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: SRC内容可能不匹配sscanf格式（如空字符串、非预期字符）
- 触发路径: sscanf(SRC, "%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_18.c:36
- 结论: sscanf返回值未检查，违反CWE-252。即使SRC为常量，如果格式不匹配（例如空字符串或非预期输入），sscanf可能返回0或EOF，导致data未初始化；后续使用未初始化的data可能导致未定义行为或信息泄露。
- D验证: stage_c_preserved / ver_cb9ef3ea
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 550. hyp_path_47c512bf8d2d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_18.c:64
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无；sscanf返回值检查不完整是静态的，无需攻击者控制
- 触发路径: static void case11() { goto sink; sink: { ... if (sscanf(SRC, "%99s\0", data) == EOF) { printLine("sscanf failed!"); } } } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_18.c:45-60
- 结论: 在函数case11中，sscanf的返回值仅检查了EOF，未检查成功情况（返回值应为1），违反了CWE-252。虽然SRC可能是常量且后续未使用data，但返回值检查不完整本身构成漏洞。
- D验证: stage_c_preserved / ver_eefd3ae8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 551. hyp_path_b1b9e1198bb1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_01.c:26
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 调用ImpersonateSelf时存在失败的可能性（如权限不足）
- 触发路径: ImpersonateSelf(SecurityImpersonation); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_01.c:26
- 结论: 未检查ImpersonateSelf()的返回值，根据CWE-252定义，可能导致安全降级或后续权限错误。
- D验证: stage_c_preserved / ver_a498a7b8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 552. hyp_path_e8bfa2a8e8f5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_02.c:28
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无，仅需API调用本身失败即可触发未检查返回值漏洞。
- 触发路径: ImpersonateSelf(SecurityImpersonation); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_02.c:28
- 结论: ImpersonateSelf() 的返回值未被检查，可能导致身份模拟失败时继续执行敏感操作，违反 CWE-252。
- D验证: stage_c_preserved / ver_bc8ac931
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 553. hyp_path_363106f0142a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_04.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过本地权限限制或资源耗尽影响 ImpersonateSelf 的执行环境，使其失败。
- 触发路径: ImpersonateSelf(SecurityImpersonation); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_04.c:34
- 结论: ImpersonateSelf() 的返回值未被检查，违反 API contract (CWE-252)。如果 ImpersonateSelf 失败，程序将继续执行而未模拟安全上下文，可能导致权限提升防御失效或错误的安全上下文。
- D验证: stage_c_preserved / ver_81bb7edc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 554. hyp_path_458744bdcf93

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_03.c:28
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过某些方式使ImpersonateSelf失败（如系统资源不足、安全策略限制等）
- 触发路径: ImpersonateSelf(SecurityImpersonation); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_03.c:28
- 结论: 未检查ImpersonateSelf的返回值，违反CWE-252。如果ImpersonateSelf失败，后续代码可能错误地假设权限已提升，导致权限缺失或潜在提权。
- D验证: stage_c_preserved / ver_2aa9c70b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 555. hyp_path_c2e3922e6308

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_05.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: The program is executed in an environment where ImpersonateSelf() can fail (e.g., process lacks necessary privileges).
- 触发路径: ImpersonateSelf(SecurityImpersonation); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_05.c:34
- 结论: CWE-252: Unchecked Return Value - ImpersonateSelf() return value is not checked, allowing potential privilege escalation or security context errors if the call fails.
- D验证: stage_c_preserved / ver_c21e5465
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 556. hyp_path_0c87a6430a21

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_06.c:33
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过影响系统状态或权限设置导致ImpersonateSelf失败，但具体控制能力不确定。
- 触发路径: ImpersonateSelf(SecurityImpersonation); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_06.c:33
- 结论: ImpersonateSelf函数的返回值未被检查，违反API contract。如果ImpersonateSelf失败，后续代码可能以错误权限运行，或无法正确处理错误状态。
- D验证: stage_c_preserved / ver_afad610e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 557. hyp_path_2030bc1e54b4

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_07.c:33
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过资源耗尽、权限限制等方式导致ImpersonateSelf调用失败（返回0），但具体前提条件依赖于系统状态。
- 触发路径: ImpersonateSelf(SecurityImpersonation); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_07.c:33
- 结论: ImpersonateSelf函数调用后未检查返回值，违反了CWE-252（未检查返回值），可能导致程序在模拟身份失败时继续执行，影响安全策略的实施。
- D验证: stage_c_preserved / ver_8f3dc14b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 558. hyp_path_45fd5ef2247c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_09.c:28
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部用户输入，代码本身存在误用
- 触发路径: ImpersonateSelf(SecurityImpersonation); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_09.c:28
- 结论: 未检查ImpersonateSelf()的返回值，违反了API contract，可能导致模拟失败，使得线程安全上下文未按预期更改，从而造成权限漏洞。
- D验证: stage_c_preserved / ver_e67b2195
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 559. hyp_path_71b5f7961e85

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_10.c:28
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: ImpersonateSelf(SecurityImpersonation); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_10.c:28
- 结论: 未检查ImpersonateSelf()函数的返回值，违反CWE-252（未检查返回值）。虽然当前代码没有后续利用，但API contract要求检查返回值以确保安全上下文正确设置，存在潜在风险。
- D验证: stage_c_preserved / ver_5f4d2169
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 560. hyp_path_51ff35f1073e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_13.c:28
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊条件，函数调用即可触发。
- 触发路径: ImpersonateSelf(SecurityImpersonation); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_13.c:28
- 结论: 调用ImpersonateSelf后未检查返回值，违反CWE-252未检查返回值，可能导致后续操作使用无效模拟令牌，进而引发权限提升或安全上下文错误。
- D验证: stage_c_preserved / ver_0ae2cdf2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 561. hyp_path_f60a0474c891

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_16.c:28
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过某种方式导致ImpersonateSelf失败，但无需直接控制输入。
- 触发路径: ImpersonateSelf(SecurityImpersonation); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_16.c:28
- 结论: 调用ImpersonateSelf后未检查返回值，违反API契约。如果ImpersonateSelf失败，后续代码可能在没有正确权限的情况下执行，导致权限提升失败或逻辑错误。
- D验证: stage_c_preserved / ver_1b26d96c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 562. hyp_path_bd33c20357e0

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_15.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过某种方式影响系统状态（如降低当前线程权限），使得ImpersonateSelf调用失败，但该异常未被捕获。
- 触发路径: ImpersonateSelf(SecurityImpersonation); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_15.c:29
- 结论: 在CWE252_Unchecked_Return_Value__w32ImpersonateSelf_15.c的case 6中，调用ImpersonateSelf(SecurityImpersonation)后未检查其返回值。根据API contract，ImpersonateSelf返回零表示失败，应通过GetLastError获取错误信息并处理。忽略返回值可能导致后续操作在意外安全上下文中执行，造成权限提升或安全策略绕过。
- D验证: stage_c_preserved / ver_44cacc83
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 563. hyp_path_697d93980fb3

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_14.c:28
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无前置条件，攻击者无法直接控制该调用，但函数可能因环境原因失败。
- 触发路径: ImpersonateSelf(SecurityImpersonation); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_14.c:28
- 结论: 调用ImpersonateSelf后未检查返回值，违反API contract（返回0表示失败），存在CWE-252漏洞。由于未提供后续代码，无法确认是否存在依赖模拟身份的操作，但漏洞本身成立，可能造成权限模拟未生效而后续错误地假设已模拟身份。
- D验证: stage_c_preserved / ver_fa2517e3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 564. hyp_path_be2b2edaf39c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_18.c:28
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: ImpersonateSelf调用可能由于各种原因失败（如资源不足、权限不足等），攻击者可能通过触发这些失败条件利用该漏洞。但本漏洞不要求攻击者直接控制输入。
- 触发路径: ImpersonateSelf(SecurityImpersonation); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_18.c:28
- 结论: ImpersonateSelf函数的返回值未被检查，违反了CWE-252未检查返回值的规定，可能导致程序在权限提升失败时仍以低权限继续运行，进而引发权限相关安全风险。
- D验证: stage_c_preserved / ver_d095d122
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 565. hyp_path_7352f9c59ad2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_17.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序执行到该代码路径，调用ImpersonateSelf函数。
- 触发路径: ImpersonateSelf(SecurityImpersonation); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__w32ImpersonateSelf_17.c:29
- 结论: 调用ImpersonateSelf函数后未检查返回值，可能导致在模拟身份失败的情况下继续执行，违反安全策略。
- D验证: stage_c_preserved / ver_b17160a1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 566. hyp_path_2d98ee189c25

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_01.c:27
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: fwprintf(stdout, L"%s\n", L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_01.c:27
- 结论: 调用fwprintf时未检查返回值，违反CWE-252未检查返回值的要求，构成API contract violation。
- D验证: stage_c_preserved / ver_066d36eb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 567. hyp_path_f9f0914a1cd6

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_02.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无；攻击者无法直接控制输入，但环境因素可能使 fwprintf 失败。
- 触发路径: fwprintf(stdout, L"%s\n", L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_02.c:29
- 结论: 在 fwprintf 调用后未检查返回值，违反了 CWE-252（未检查返回值）。尽管实际写入 stdout 且为固定字符串，失败可能性极低，但 API contract 要求检查返回值以检测错误。
- D验证: stage_c_preserved / ver_a1a0a079
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 568. hyp_path_d17ac0d541e1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_03.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够导致fwprintf失败，例如通过控制文件系统资源耗尽或关闭标准输出流。
- 触发路径: fwprintf(stdout, L"%s\n", L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_03.c:29
- 结论: 函数fwprintf的返回值未被检查，违反CWE-252未检查返回值。当标准输出发生错误时（如磁盘满、管道关闭），程序无法感知错误，可能导致数据丢失或程序状态不一致。
- D验证: stage_c_preserved / ver_7b3b667b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 569. hyp_path_9aa21fb48ac1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_04.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout写入失败（如磁盘满、权限不足、stdout被关闭等）
- 触发路径: fwprintf(stdout, L"%s\n", L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_04.c:35
- 结论: 在fwprintf调用中未检查返回值，违反CWE-252（未检查返回值）的API契约，可能导致输出不完整或数据丢失，但攻击者难以直接利用，影响较低。
- D验证: stage_c_preserved / ver_86e42c9a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 570. hyp_path_6a3b426c4173

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_05.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能需要影响输出环境（如重定向 stdout 到受限设备），但通常无需直接控制输入
- 触发路径: fwprintf(stdout, L"%s\n", L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_05.c:35
- 结论: 未检查 fwprintf 函数的返回值，违反 CWE-252 未检查返回值要求。虽然向 stdout 输出失败概率较低，但根据 API 契约应检查返回值。
- D验证: stage_c_preserved / ver_9235f1db
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 571. hyp_path_4f7d276de4f2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_07.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 需要系统环境导致fwprintf失败（如磁盘满、stdout关闭等）
- 触发路径: fwprintf(stdout, L"%s\n", L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_07.c:34
- 结论: 在调用fwprintf时未检查返回值，违反CWE-252（未检查返回值），可能导致输出失败时程序未能感知错误。
- D验证: stage_c_preserved / ver_cd4835c9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 572. hyp_path_36a80d7b92a0

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_06.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 输出流（stdout）被重定向到可能发生错误的文件或设备；或者系统资源受限导致写入失败。
- 触发路径: fwprintf(stdout, L"%s\n", L"string"); @ CWE252_Unchecked_Return_Value__wchar_t_fprintf_06.c:34
- 结论: 调用fwprintf时未检查返回值，违反CWE-252：未检查返回值。虽然当前写入标准输出，失败可能性低，但仍存在潜在风险，如输出重定向到文件时可能因磁盘满等原因失败而未被检测。
- D验证: stage_c_preserved / ver_7ea80639
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 573. hyp_path_dad5a6259205

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_09.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够使stdout写入失败（例如通过重定向到满磁盘、文件系统错误等）
- 触发路径: fwprintf(stdout, L"%s\n", L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_09.c:29
- 结论: fwprintf的返回值未被检查，违反了CWE-252（未检查返回值）。代码注释明确指示不检查返回值，且无任何错误处理机制，即使stdout写入失败的可能性较低，但违反API契约是确定的。
- D验证: stage_c_preserved / ver_ccf5f9f1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 574. hyp_path_f704ea7701a5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_10.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部输入控制，但违反API契约要求检查返回值。
- 触发路径: fwprintf(stdout, L"%s\n", L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_10.c:29
- 结论: 函数fwprintf的返回值未被检查，违反了CWE-252（未检查返回值）的API契约。尽管当前调用使用硬编码字符串，不存在外部输入控制，实际安全影响极低，但代码层面存在契约违规。
- D验证: stage_c_preserved / ver_2f5421ce
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 575. hyp_path_7051dec56521

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_15.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 标准输出可能出现错误（如磁盘满、管道关闭等）。
- 触发路径: case 6: /* NOTE: Do not check the return value */ fwprintf(stdout, L"%s\n", L"string"); break; @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_15.c:30
- 结论: 调用 fwprintf 未检查返回值，可能忽略输出错误，违反 CWE-252 未检查返回值。
- D验证: stage_c_preserved / ver_2929ec72
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 576. hyp_path_7a0218e0d546

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_13.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特定攻击者控制输入；但系统环境可能导致stdout写入失败（如磁盘满、权限不足）
- 触发路径: fwprintf(stdout, L"%s\n", L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_13.c:29
- 结论: CWE252: 未检查返回值 - fwprintf函数的返回值被忽略，调用可能失败，但程序未检测错误，可能导致数据未写入或丢失。
- D验证: stage_c_preserved / ver_e16c0e68
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 577. hyp_path_05eb3902ac50

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_14.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过操纵环境（如填满磁盘或关闭stdout）使fwprintf失败，但无需直接控制输入。
- 触发路径: fwprintf(stdout, L"%s\n", L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_14.c:29
- 结论: 未检查fwprintf返回值，违反CWE-252规定，可能导致写入错误未被发现。
- D验证: stage_c_preserved / ver_198a71dc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 578. hyp_path_f67befd3facd

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_16.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: fwprintf(stdout, L"%s\n", L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_16.c:29
- 结论: 调用 fwprintf 后未检查返回值，违反 CWE-252 的 API contract，可能因环境因素（如 stdout 重定向到已满磁盘）导致写入失败未被发现。尽管输出为常量字符串且目标为 stdout，实际风险较低，但漏洞假设依然成立。
- D验证: stage_c_preserved / ver_1e4b97c9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 579. hyp_path_be5ad489013c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_17.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: fwprintf(stdout, L"%s\n", L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_17.c:30
- 结论: 未检查fwprintf的返回值，违反CWE-252，可能忽略写入错误。
- D验证: stage_c_preserved / ver_765b71f1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 580. hyp_path_dac67d67c736

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_01.c:27
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够导致fputwc调用失败（如资源耗尽或文件系统攻击）。
- 触发路径: fputwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_01.c:27
- 结论: 未检查fputwc返回值，可能导致写入错误被忽略。
- D验证: stage_c_preserved / ver_ba9d78f9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 581. hyp_path_43fa5be5c409

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_18.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部输入控制，但API contract要求检查返回值
- 触发路径: fwprintf(stdout, L"%s\n", L"string"); @ CWE252_Unchecked_Return_Value__wchar_t_fprintf_18.c:29
- 结论: 未检查fwprintf返回值，违反CWE-252，可能导致未检测到的写错误。
- D验证: stage_c_preserved / ver_b2e3b12d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 582. hyp_path_1e999e41b3a5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_02.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无需攻击者输入，但 stdout 可能处于错误状态。
- 触发路径: fputwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_02.c:29
- 结论: 函数 fputwc 的返回值未被检查，违反 CWE-252：未检查返回值。即使注释说明不检查，仍可能导致部分字符写入失败而未被发现。
- D验证: stage_c_preserved / ver_0a76da0f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 583. hyp_path_c534518cf051

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_03.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout 可能被重定向、关闭或出现写入错误。
- 触发路径: fputwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_03.c:29
- 结论: 调用 fputwc 时未检查返回值，违反 CWE-252，可能导致数据未完整写入 stdout 而未被检测到。
- D验证: stage_c_preserved / ver_b8e720c6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 584. hyp_path_af0f6ecd66b3

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_04.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: fputwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_04.c:35
- 结论: 在调用fputwc后未检查其返回值，违反了CWE-252（未检查返回值）的要求。虽然写入stdout失败通常不会导致严重安全后果，但忽略返回值可能导致程序状态不一致或后续逻辑错误。
- D验证: stage_c_preserved / ver_7a639f06
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 585. hyp_path_10a6fa45c469

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_06.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊前提条件，仅为一次固定参数的调用。
- 触发路径: fputwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_06.c:34
- 结论: 函数fputwc的返回值未被检查，违反了CWE-252（未检查返回值）的API合约。尽管该调用写入一个固定宽字符，错误时不会直接导致安全影响，但存在API misuse。
- D验证: stage_c_preserved / ver_3653385c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 586. hyp_path_9d11d499307e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_05.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout在运行时可能处于错误状态（例如被重定向到文件且磁盘满，或管道关闭）。
- 触发路径: fputwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_05.c:35
- 结论: 函数fputwc的返回值未被检查，违反了API契约，可能导致在写入失败时程序未察觉，属于CWE-252未检查返回值漏洞。
- D验证: stage_c_preserved / ver_8b9c534b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 587. hyp_path_d6be3b35db8c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_07.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdout写入环境（如重定向输出到受限文件）
- 触发路径: fputwc((wchar_t)L'A', stdout); @ CWE252_Unchecked_Return_Value__wchar_t_fputc_07.c:34
- 结论: 未检查fputwc的返回值，可能导致未检测到的写入失败，违反CWE-252约定。
- D验证: stage_c_preserved / ver_57e91b80
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 588. hyp_path_546984a6d7eb

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_10.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: fputwc((wchar_t)L'A', stdout); @ 29
- 结论: 未检查fputwc返回值，可能导致未检测到的输出错误或数据丢失。
- D验证: stage_c_preserved / ver_5f0b1a93
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 589. hyp_path_023f6d6267cb

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_09.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 写入stdout可能因环境因素失败，无外部输入控制
- 触发路径: fputwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_09.c:29
- 结论: 调用fputwc未检查返回值，违反了CWE-252（未检查返回值）的API合约。尽管在常见情况下失败概率低，但若写入失败（如stdout关闭、磁盘满），程序无法检测到错误，导致数据丢失或后续逻辑错误。
- D验证: stage_c_preserved / ver_1491e3ad
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 590. hyp_path_bc1f8c563b70

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_13.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响标准输出写入状态（如关闭stdout或使其出错）
- 触发路径: fputwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_13.c:29
- 结论: 未检查fputwc返回值，违反CWE-252，可能忽略写入失败错误，虽影响有限但属API misuse
- D验证: stage_c_preserved / ver_bbd30878
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 591. hyp_path_365c0c7c9e79

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_14.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序执行到该调用点，stdout可能处于错误状态
- 触发路径: fputwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_14.c:29
- 结论: 未检查fputwc返回值，违反CWE-252，可能导致写入失败未被检测
- D验证: stage_c_preserved / ver_941262b6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 592. hyp_path_70dc9aea6af5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_16.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊攻击者控制前提，任何导致 fputwc 失败的条件即可触发未检查错误。
- 触发路径: fputwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_16.c:29
- 结论: 调用 fputwc 后未检查返回值，违反 API 契约，可能导致未检测到的写入错误。
- D验证: stage_c_preserved / ver_d7bde3e8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 593. hyp_path_c629253c1876

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_15.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行时stdout可能发生写入错误
- 触发路径: fputwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_15.c:30
- 结论: 未检查fputwc返回值，违反CWE-252，可能导致输出不完整或未检测到写入错误。
- D验证: stage_c_preserved / ver_f7bc0819
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 594. hyp_path_904680b47952

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_17.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊攻击者控制条件，但stdout可能因环境因素（如磁盘满、管道关闭）写入失败
- 触发路径: fputwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_17.c:30
- 结论: 调用fputwc写入宽字符到stdout后未检查返回值，违反CWE-252 Unchecked Return Value契约，可能导致写入失败未被发现。
- D验证: stage_c_preserved / ver_7474a9e7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 595. hyp_path_9a25ced4dc8d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputc_18.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊攻击前提，标准输出可能被重定向或关闭。
- 触发路径: /* NOTE: Do not check the return value */ fputwc((wchar_t)L'A', stdout); @ L29
- 结论: 未检查 fputwc 返回值，违反了 API contract，可能导致未检测到的写入失败。
- D验证: stage_c_preserved / ver_4107b34f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 596. hyp_path_788a2dbc4806

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_01.c:27
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特定攻击者控制输入，但依赖于运行时环境导致fputws失败
- 触发路径: fputws(L"string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_01.c:27
- 结论: 未检查fputws返回值，可能导致未检测到的写入错误
- D验证: stage_c_preserved / ver_f8c20792
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 597. hyp_path_386da655795e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_03.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: fputws(L"string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_03.c:29
- 结论: 函数fputws的返回值未被检查，违反了CWE-252（未检查返回值）的定义。虽然在本例中写入固定字符串到stdout，返回值未被检查可能导致写入失败未被检测，但这是明确的API契约违反。
- D验证: stage_c_preserved / ver_d524085b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 598. hyp_path_5857dabe439a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_02.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者无法直接控制输入，但可能通过影响系统资源（如导致磁盘满、关闭stdout或破坏管道）间接触发fputws失败。
- 触发路径: fputws(L"string", stdout); @ CWE252_Unchecked_Return_Value__wchar_t_fputs_02.c:29
- 结论: 函数fputws的返回值未被检查，违反了CWE-252（未检查返回值）的要求。虽然stdout通常不会失败，但在特定条件下（如磁盘满、管道破裂、stdout被关闭）写入可能失败，忽略返回值会导致程序无法感知错误，可能引起数据丢失或未定义行为。
- D验证: stage_c_preserved / ver_25d03c25
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 599. hyp_path_1b61200c72ba

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_05.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: fputws(L"string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_05.c:35
- 结论: 调用fputws后未检查返回值，违反CWE-252：未检查返回值。如果写入失败，程序将无法感知错误，可能导致数据丢失或未定义行为。
- D验证: stage_c_preserved / ver_63dad0fc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 600. hyp_path_8f62ae80749c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_04.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: fputws(L"string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_04.c:35
- 结论: 函数fputws的返回值未检查，违反了CWE-252(未检查返回值)的API contract。如果写入失败，程序将无法感知错误，可能导致数据丢失或不完整。
- D验证: stage_c_preserved / ver_470d62c3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 601. hyp_path_c916ede4e281

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_06.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行环境可能导致stdout写入失败（如重定向到已满磁盘或stdout关闭）
- 触发路径: fputws(L"string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_06.c:34
- 结论: fputws函数返回值未检查，违反API contract，可能导致在写入失败时程序未感知错误，属于CWE-252未检查返回值漏洞。
- D验证: stage_c_preserved / ver_350ef855
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 602. hyp_path_a795b0ba83fe

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_07.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout可能出错（如磁盘满、管道破裂、文件描述符关闭）
- 触发路径: fputws(L"string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_07.c:34
- 结论: fputws调用后未检查返回值，违反了CWE-252（未检查的返回值）。虽然写入内容为硬编码字符串，但若写入失败（例如磁盘满或stdout关闭），程序无法感知错误，可能导致数据完整性或可用性问题。
- D验证: stage_c_preserved / ver_688366be
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 603. hyp_path_c7272e7e6686

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_09.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊攻击前提，任何导致fputws失败的条件即可触发漏洞。
- 触发路径: fputws(L"string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_09.c:29
- 结论: 函数fputws的返回值未被检查，违反API contract，可能导致未检测到的写入错误。
- D验证: stage_c_preserved / ver_2db7f29b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 604. hyp_path_0be167c9cceb

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_10.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊前提条件，仅需执行到该代码路径
- 触发路径: fputws(L"string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_10.c:29
- 结论: 未检查 fputws 的返回值，可能忽略写入失败，违反了 CWE-252（Unchecked Return Value）。虽然风险较低（stdout 写入失败可能性小），但漏洞真实存在。
- D验证: stage_c_preserved / ver_8fe479da
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 605. hyp_path_edc78e02f83d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_13.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 任何导致fputws失败的条件（如stdout关闭）均可触发漏洞。
- 触发路径: fputws(L"string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_13.c:29
- 结论: 调用fputws时未检查返回值，违反CWE-252：未检查返回值。尽管fputws输出硬编码字符串，错误发生的可能性较低，但仍然是API contract违规。
- D验证: stage_c_preserved / ver_692692ad
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 606. hyp_path_1d1d49221ca2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_15.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: fputws 调用可能失败的外部条件（如 stdout 关闭、磁盘满等）
- 触发路径: case 6: /* NOTE: Do not check the return value */ fputws(L"string", stdout); break; default: @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_15.c:30
- 结论: fputws 函数的返回值未被检查，违反 CWE-252 (Unchecked Return Value)。当 fputws 写入失败时，程序不会感知错误，可能导致数据丢失或状态不一致。
- D验证: stage_c_preserved / ver_47f52b5b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 607. hyp_path_ef5f1ab1c084

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_14.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout可能被关闭或出现I/O错误
- 触发路径: fputws(L"string", stdout); @ line 29
- 结论: 代码调用fputws时未检查返回值，违反CWE-252（未检查返回值）的API contract。虽然输出为硬编码字符串，但未检查返回值可能导致未处理错误，构成安全漏洞。
- D验证: stage_c_preserved / ver_54664370
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 608. hyp_path_b32944af27da

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_16.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过某种方式导致 stdout 写入失败（如重定向到文件且磁盘满），但通常需要特定环境条件。
- 触发路径: fputws(L"string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_16.c:29
- 结论: 未检查 fputws 函数的返回值，可能导致写入 stdout 失败时未被发现，违反 CWE-252 Unchecked Return Value。
- D验证: stage_c_preserved / ver_cfb5275f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 609. hyp_path_0e585c1ef936

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_17.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特定攻击者控制输入，但stdout可能因环境原因失败。
- 触发路径: fputws(L"string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_17.c:30
- 结论: 在代码中，fputws函数的返回值未被检查，违反了API契约，可能导致写入失败等错误未被检测和处理。
- D验证: stage_c_preserved / ver_dbd61183
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 610. hyp_path_410c3d35c17e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_18.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: fputws(L"string", stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fputs_18.c:29
- 结论: 未检查fputws返回值，违反CWE-252要求，可能导致写入stdout失败被忽略。
- D验证: stage_c_preserved / ver_1241c9a6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 611. hyp_path_bc48f72a926b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_01.c:32
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入，使fwscanf返回值为0或EOF，导致data未正确赋值。
- 触发路径: fwscanf(stdin, L"%99s\0", data); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_01.c:32
- 结论: 调用fwscanf时未检查返回值，违反API contract（CWE-252）。如果fwscanf读取失败，data可能包含未定义内容，但后续代码未使用或未确认，影响较低。
- D验证: stage_c_preserved / ver_1767464b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 612. hyp_path_e6e7d78ad50e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_04.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过控制 stdin 使输入失败，如提前关闭输入流或提供不匹配格式的输入。
- 触发路径: fwscanf(stdin, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_04.c:40
- 结论: 未检查 fwscanf 返回值，若输入失败（如 EOF 或格式不匹配），data 可能未被正确写入，后续使用未初始化数据导致未定义行为。
- D验证: stage_c_preserved / ver_01cd892a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 613. hyp_path_d26f06442f3e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_03.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin输入（如通过管道或重定向）导致fwscanf读取失败。
- 触发路径: fwscanf(stdin, L"%99s\0", data); @ CWE252_Unchecked_Return_Value__wchar_t_fscanf_03.c:34
- 结论: 调用fwscanf后未检查返回值，违反API契约（CWE-252），即使没有后续使用，未处理错误状态也可能导致未初始化数据读取或程序行为异常。
- D验证: stage_c_preserved / ver_721701e7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 614. hyp_path_1275f353ff6b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_02.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够向 stdin 提供输入，且输入内容不符合格式规范导致 fwscanf 失败
- 触发路径: fwscanf(stdin, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_02.c:34
- 结论: 调用 fwscanf 后未检查返回值，可能读取失败导致 data 未正确初始化，违反 CWE-252。
- D验证: stage_c_preserved / ver_94bab153
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 615. hyp_path_0e57e3bde83f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_09.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响标准输入的内容或状态，例如关闭 stdin 或发送无效数据。
- 触发路径: fwscanf(stdin, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_09.c:34
- 结论: 未检查 fwscanf 的返回值，可能导致使用未初始化的数据或错误处理，违反 CWE-252 安全规范。
- D验证: stage_c_preserved / ver_027eecf8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 616. hyp_path_40adc36a3ddb

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_05.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响标准输入流（stdin）的内容或状态，如提前关闭stdin或输入无效数据，导致fwscanf读取失败。
- 触发路径: fwscanf(stdin, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_05.c:40
- 结论: 函数fwscanf的返回值未被检查，违反了CWE-252（Unchecked Return Value）。虽然当前路径未直接导致敏感操作，但未检查返回值可能导致后续使用未初始化数据，引发未定义行为或信息泄露。
- D验证: stage_c_preserved / ver_5245ff5c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 617. hyp_path_30175f4bea8e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_10.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin触发读取失败或EOF
- 触发路径: fwscanf(stdin, L"%99s\0", data); @ 行34
- 结论: 调用fwscanf未检查返回值，违反API contract，可能导致使用未初始化的dataBuffer数据。
- D验证: stage_c_preserved / ver_d0b29295
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 618. hyp_path_52c634be30c4

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_07.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供导致 fwscanf 失败的特殊输入（如无效格式或EOF）。
- 触发路径: fwscanf(stdin, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_07.c:39
- 结论: 未检查 fwscanf 的返回值，违反 CWE-252 的 API 使用契约，可能导致在输入失败时使用未初始化的缓冲区数据。但未提供后续代码，影响不确定。
- D验证: stage_c_preserved / ver_73e69b53
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 619. hyp_path_70e0f4b90338

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_06.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: fwscanf 调用可能失败（例如输入结束、格式不匹配）
- 触发路径: fwscanf(stdin, L"%99s\0", data); @ L39
- 结论: 未检查 fwscanf 函数的返回值，可能导致输入失败时使用未初始化或部分写入的缓冲区 data。但由于缺乏后续数据使用的代码证据，该漏洞的实际可利用性待验证。
- D验证: stage_c_preserved / ver_6820ed7b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 620. hyp_path_5e91ca24516f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_13.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入，使fwscanf失败（例如提前关闭stdin或输入非预期内容）。
- 触发路径: fwscanf(stdin, L"%99s\0", data); @ 第34行
- 结论: 调用fwscanf未检查返回值，违反CWE-252。若fwscanf失败（如EOF、格式不匹配），dataBuffer内容未定义，后续使用可能导致未初始化数据访问或逻辑错误。
- D验证: stage_c_preserved / ver_ff4d6094
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 621. hyp_path_691d757917cf

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_14.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响标准输入（stdin）的内容或状态，例如提前关闭输入流或发送意外输入。
- 触发路径: fwscanf(stdin, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_14.c:34
- 结论: 函数fwscanf的返回值未被检查，违反CWE-252（未检查返回值）。攻击者可通过操纵stdin使fwscanf失败，导致dataBuffer内容未定义，但实际利用影响较低，需要动态验证。
- D验证: stage_c_preserved / ver_fc094379
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 622. hyp_path_391827b231d8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_15.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可控制 stdin 输入导致 fwscanf 失败
- 触发路径: fwscanf(stdin, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_15.c:35
- 结论: 未检查 fwscanf 返回值，可能导致读取失败时使用未初始化或部分初始化的数据，违反 API contract。
- D验证: stage_c_preserved / ver_ec6a2631
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 623. hyp_path_91961ff7a25a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_16.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够导致 fwscanf 失败（如提前关闭 stdin 或输入格式不匹配）
- 触发路径: fwscanf(stdin, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_16.c:34
- 结论: 未检查 fwscanf 返回值，失败时 data 缓冲区内容未定义，后续使用可能导致未初始化数据泄露或程序崩溃。
- D验证: stage_c_preserved / ver_207677c1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 624. hyp_path_87e7d258a739

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_17.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin输入（如提供空文件或提前关闭输入流），使得fwscanf返回0或EOF。
- 触发路径: fwscanf(stdin, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_17.c:35
- 结论: 未检查fwscanf返回值，若读取失败则data内容可能保持未定义数据，违反CWE-252。
- D验证: stage_c_preserved / ver_2d7b28df
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 625. hyp_path_08d7b39fc8f4

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_18.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入，导致fwscanf返回非期望值（如0或EOF）。
- 触发路径: fwscanf(stdin, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_18.c:34
- 结论: 未检查fwscanf返回值，违反CWE-252 Unchecked Return Value，可能导致后续使用未初始化数据或逻辑错误。
- D验证: stage_c_preserved / ver_435ab0e9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 626. hyp_path_e12776975d14

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_16.c:66
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供不匹配格式的输入
- 触发路径: if (fwscanf(stdin, L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_16.c:58
- 结论: 在函数case11中，fwscanf的返回值仅检查了EOF，未检查返回值为0的情况（表示无匹配项），违反了CWE-252 API contract。尽管后续未使用data进行敏感操作，返回值未完全检查仍构成漏洞，但实际影响较低。
- D验证: stage_c_preserved / ver_4883e923
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 627. hyp_path_34fbfdd9d437

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_01.c:27
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout 出现错误（如关闭、重定向到不可写设备等）
- 触发路径: fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout); @ CWE252_Unchecked_Return_Value__wchar_t_fwrite_01.c:27
- 结论: fwrite 返回值未检查，违反 API contract。若 stdout 发生 I/O 错误（如关闭、磁盘满），将导致数据丢失，符合 CWE-252 定义。虽然写入固定字符串，影响范围有限，但漏洞模式成立。
- D验证: stage_c_preserved / ver_a4b67649
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 628. hyp_path_da2c7fedbb4c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_03.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 环境因素导致fwrite失败（例如stdout被重定向到不可写文件）
- 触发路径: fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout); @ CWE252_Unchecked_Return_Value__wchar_t_fwrite_03.c:29
- 结论: fwrite的返回值未被检查，违反了CWE-252（未检查返回值）。即使输入为常量字符串，若fwrite失败（如stdout重定向到不可写文件），程序无法感知输出不完整，导致数据丢失。
- D验证: stage_c_preserved / ver_15d7d655
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 629. hyp_path_00b1443c8ecc

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_02.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout 的写入操作可能失败（例如，stdout 被重定向到已满的磁盘文件或管道被关闭）
- 触发路径: fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_02.c:29
- 结论: 在调用 fwrite 时未检查返回值，违反 CWE-252（未检查返回值）。fwrite 可能因写入失败（如磁盘满、stdout 关闭等）而返回错误码，但代码未处理，可能导致数据丢失或程序状态不一致。
- D验证: stage_c_preserved / ver_e856f1e4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 630. hyp_path_8d833d9424d5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_04.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: fwrite调用可能失败（如stdout关闭、磁盘满、权限拒绝等）
- 触发路径: fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_04.c:35
- 结论: 函数fwrite的返回值未被检查，违反了CWE-252（未检查返回值）的API contract。虽然当前写入的是硬编码字符串且B阶段评分较低，但fwrite可能因标准输出关闭、磁盘满、权限错误等原因失败，导致数据丢失或部分写入，进而影响系统完整性。该漏洞属于contract violation，实际可利用性取决于环境，需要动态验证。
- D验证: stage_c_preserved / ver_360650e4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 631. hyp_path_0b25ee6a38ac

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_05.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 标准输出流发生错误（如文件描述符关闭、磁盘满等）
- 触发路径: fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_05.c:35
- 结论: fwrite返回值未被检查，违反CWE-252（未检查返回值）。尽管写入stdout通常不会失败，但在文件描述符错误、磁盘满等异常条件下可能导致数据丢失或程序行为异常，但可利用性和影响较低。
- D验证: stage_c_preserved / ver_6f6b50f8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 632. hyp_path_657efbe655f0

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_18.c:62
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入内容，使得fwscanf返回0（如输入空串或仅空白符）
- 触发路径: static void case11() { goto sink; sink: { wchar_t dataBuffer[100] = L""; wchar_t * data = dataBuffer; if (fwscanf(stdin, L"%99s\0", data) == EOF) { printLine("fwscanf failed!"); } } } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_18.c:43-58
- 结论: 函数对fwscanf的返回值检查不完整，仅处理EOF错误，未处理返回0的情况（未匹配到任何项）。当攻击者提供无法匹配格式的输入（如空行或仅空白符）时，fwscanf返回0，data保持初始化为空字符串。虽然本用例中后续未使用data，但违反了CWE-252要求检查返回值的约定，构成不完全检查漏洞。
- D验证: stage_c_preserved / ver_66b70145
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 633. hyp_path_9b7b38e1c389

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_06.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响写操作的环境（如重定向stdout到慢设备或受限文件系统），使得fwrite可能失败。
- 触发路径: fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_06.c:34
- 结论: fwrite函数的返回值未被检查，违反了CWE-252（未检查返回值）的定义。虽然写入stdout通常不会失败，但在某些环境（如输出重定向到文件或管道）中，fwrite可能失败，导致数据丢失或未写入，忽略返回值会隐藏错误状态。
- D验证: stage_c_preserved / ver_95668497
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 634. hyp_path_b1dc7aa6a25a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_07.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 运行环境可能导致stdout写入失败（如磁盘满、管道关闭、stdout重定向到文件且空间不足）
- 触发路径: fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_07.c:34
- 结论: 未检查fwrite返回值可能导致数据写入不完整或丢失，违反CWE-252规范。
- D验证: stage_c_preserved / ver_ea0e87d6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 635. hyp_path_94a129e86880

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_09.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊前提条件，任何导致fwrite失败的环境因素均可触发漏洞。
- 触发路径: fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout); @ CWE252_Unchecked_Return_Value__wchar_t_fwrite_09.c:29
- 结论: 调用fwrite函数写入stdout，但未检查返回值，违反CWE-252定义，可能导致数据未完全写入或写入失败而未被发现，影响数据完整性。
- D验证: stage_c_preserved / ver_31c22b7f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 636. hyp_path_90677aff18c1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_10.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: fwrite调用可能失败（例如stdout关闭、磁盘空间不足等），且程序不检查返回值。
- 触发路径: fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_10.c:29
- 结论: fwrite的返回值未被检查，违反了CWE-252（未检查返回值）。这可能导致数据未完全写入而程序继续执行，造成数据丢失或不一致。
- D验证: stage_c_preserved / ver_5acfa482
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 637. hyp_path_809dfee6cb86

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_13.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout写入失败（例如被重定向到文件且磁盘空间不足，或管道破裂等）。
- 触发路径: fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_13.c:29
- 结论: 未检查fwrite返回值，可能导致数据写入失败时程序未察觉，违反CWE-252 API contract。
- D验证: stage_c_preserved / ver_2eb42103
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 638. hyp_path_8c1c45f5a00c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_14.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_14.c:29
- 结论: 未检查fwrite返回值，违反CWE-252，可能导致数据写入不完整或失败未被发现。
- D验证: stage_c_preserved / ver_6ea66d6c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 639. hyp_path_430cddeedb04

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_15.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特定攻击者控制，但stdout可能失败（如缓冲区满、重定向到磁盘满）
- 触发路径: fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_15.c:30
- 结论: fwrite返回值未检查，违反CWE-252 API contract，可能导致写入失败时未处理
- D验证: stage_c_preserved / ver_5c12ccc9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 640. hyp_path_7b2fa959f4fa

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_16.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout 文件流可能被关闭或重定向到不可写的位置，导致 fwrite 写入失败。
- 触发路径: fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_16.c:29
- 结论: fwrite 的返回值未被检查，违反了 CWE-252 未检查返回值的要求。尽管写入 stdout 通常成功，但忽略返回值可能导致在写入失败时程序无法感知，从而丢失数据或产生潜在不一致。
- D验证: stage_c_preserved / ver_fda0fc12
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 641. hyp_path_7675390dce89

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_17.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行时 stdout 可能发生错误（如管道断裂、磁盘满等），但攻击者一般难以直接控制此条件。
- 触发路径: fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_17.c:30
- 结论: 未检查 fwrite 返回值，违反 CWE-252：未检查返回值。fwrite 可能因输出错误（如 stdout 关闭或写入失败）而部分写入或失败，导致数据丢失或不完整。
- D验证: stage_c_preserved / ver_811c0d3c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 642. hyp_path_46143b20d370

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_18.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者无法直接控制输入，但环境异常（如stdout关闭、磁盘满）可导致写入失败。
- 触发路径: fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_18.c:29
- 结论: fwrite调用未检查返回值，违反CWE-252 API contract，虽然写入stdout，但环境异常（如stdout关闭、磁盘满）可能导致数据丢失或不一致而不被察觉。
- D验证: stage_c_preserved / ver_448aea05
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 643. hyp_path_bdd5c2d105e1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_01.c:27
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout输出可能因文件系统满、管道关闭等原因失败，但程序不检查返回值。
- 触发路径: putwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_01.c:27
- 结论: 函数putwc的返回值未检查，可能导致写入错误未被检测，违反CWE-252。
- D验证: stage_c_preserved / ver_12f90e36
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 644. hyp_path_1c745d042d24

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_02.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行时 stdout 可能处于错误状态或可写空间不足。
- 触发路径: putwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_02.c:29
- 结论: 未检查 putwc 返回值，可能忽略写入失败，导致数据丢失或未定义行为。
- D验证: stage_c_preserved / ver_ec47f908
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 645. hyp_path_c5c31847897d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_04.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 需要stdout在写入时发生错误（例如管道关闭、磁盘满等）。
- 触发路径: putwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_04.c:35
- 结论: 在代码中调用putwc函数时未检查其返回值，违反了CWE-252（未检查返回值）的API contract，可能导致写入失败未被察觉，进而影响程序正确性或潜在的安全问题。
- D验证: stage_c_preserved / ver_90ead6e6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 646. hyp_path_d7dd7e337dce

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_03.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout操作可能失败（如文件描述符关闭）
- 触发路径: putwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_03.c:29
- 结论: 对putwc函数的返回值未进行检查，可能忽略写入失败的错误条件，违反CWE-252。
- D验证: stage_c_preserved / ver_aa2fe5ac
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 647. hyp_path_e07473934b25

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_05.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 标准输出出现写入失败（如磁盘满、管道关闭等）。
- 触发路径: putwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_05.c:35
- 结论: 未检查putwc的返回值，违反CWE-252：未检查返回值。虽然putwc失败仅导致字符未输出，但不符合安全编码规范。
- D验证: stage_c_preserved / ver_e0857481
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 648. hyp_path_cb82e6a6556f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_06.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序执行到该代码路径。
- 触发路径: putwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_06.c:34
- 结论: 调用putwc后未检查返回值，违反CWE-252，可能导致写入失败时无法检测，引发数据丢失或未定义行为。
- D验证: stage_c_preserved / ver_f005e59c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 649. hyp_path_a01a54a48f89

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_09.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特定攻击者输入，但运行环境可能存在写失败风险（如磁盘满、stdout关闭）。
- 触发路径: putwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_09.c:29
- 结论: 函数putwc的返回值未被检查，违反API contract，可能导致未处理的失败情况。
- D验证: stage_c_preserved / ver_6d022bdc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 650. hyp_path_4e877f393863

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_07.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部输入控制，攻击者无法直接触发；但标准输出可能因系统资源不足等原因失败，导致未处理错误状态。
- 触发路径: putwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_07.c:34
- 结论: 未检查putwc返回值，违反CWE-252。putwc写入stdout失败时返回WEOF，但代码未检查，存在API misuse。
- D验证: stage_c_preserved / ver_26053b4a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 651. hyp_path_714d8455d8a1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_10.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部输入控制；依赖系统环境导致的写入失败。
- 触发路径: putwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_10.c:29
- 结论: 在putwc调用后未检查返回值，违反API contract，可能忽略写入失败的错误状态。
- D验证: stage_c_preserved / ver_84f182a3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 652. hyp_path_f0d4228d0a14

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_13.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特定攻击者输入，但stdout可能因环境原因（如重定向、管道破裂）出错。
- 触发路径: putwc((wchar_t)L'A', stdout); @ L29
- 结论: 调用putwc时未检查返回值，如果写入失败（如stdout关闭或出错），程序无法感知，可能导致输出丢失或数据不一致。
- D验证: stage_c_preserved / ver_51f22d7c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 653. hyp_path_70be48f191b3

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_15.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: stdout写入可能失败（例如文件流错误）。
- 触发路径: putwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_15.c:30
- 结论: 函数putwc的返回值未被检查，违反了CWE-252（Unchecked Return Value）的API合约。在特定条件下（如stdout写入失败），程序将无法检测到错误，可能导致数据丢失或状态不一致。
- D验证: stage_c_preserved / ver_a25c5f75
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 654. hyp_path_7129b8cd8932

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_16.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行时stdout可能出现写入错误（例如管道关闭、磁盘满等）
- 触发路径: putwc((wchar_t)L'A', stdout); @ 29
- 结论: 函数putwc的返回值未被检查，可能导致未检测到的写入错误。
- D验证: stage_c_preserved / ver_9a9d57bb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 655. hyp_path_2321d5177546

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_14.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无攻击者控制输入，但代码本身存在缺陷
- 触发路径: putwc((wchar_t)L'A', stdout); @ CWE252_Unchecked_Return_Value__wchar_t_putc_14.c:29
- 结论: 调用putwc时未检查返回值，违反CWE-252（未检查返回值）的API契约，可能导致写入错误被忽略。但无外部输入，影响较低。
- D验证: stage_c_preserved / ver_e0a12d6a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 656. hyp_path_48ba28f3f9b0

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_18.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: putwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_18.c:29
- 结论: 未检查 putwc 返回值，违反 CWE-252 规范，可能导致输出错误未被发现。
- D验证: stage_c_preserved / ver_c5d53cf7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 657. hyp_path_fd2e03be0b68

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_17.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序以写模式打开 stdout，但未对写入失败进行处理；攻击者可能通过环境因素（如文件系统错误）触发此漏洞
- 触发路径: putwc((wchar_t)L'A', stdout); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_17.c:30
- 结论: 在函数调用 putwc 后未检查返回值，违反 CWE-252（未检查返回值）的 API contract。如果写入失败，程序无法获知错误状态，可能导致数据丢失或未定义行为。
- D验证: stage_c_preserved / ver_0c4ecfa3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 658. hyp_path_11a06dbb3586

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_01.c:27
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行环境可能发生输出错误（如磁盘满、管道断裂）。
- 触发路径: putwchar((wchar_t)L'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_01.c:27
- 结论: 调用了putwchar函数，但未检查其返回值，违反CWE-252（未检查返回值）。如果putwchar执行失败（如写入错误），程序无法感知，可能导致输出不完整或静默错误。
- D验证: stage_c_preserved / ver_ad53e0fc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 659. hyp_path_8ceffc90580f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_04.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无需攻击者输入，代码本身缺陷。
- 触发路径: putwchar((wchar_t)L'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_04.c:35
- 结论: 未检查putwchar函数的返回值，违反CWE-252（未检查返回值），可能导致未处理的错误状态。
- D验证: stage_c_preserved / ver_eea52b86
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 660. hyp_path_45ff9fc41c8d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_02.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: putwchar((wchar_t)L'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_02.c:29
- 结论: 未检查putwchar函数的返回值，违反CWE-252（未检查返回值）定义。即使当前输出固定字符'A'，若putwchar失败（返回WEOF），程序仍继续执行而不感知错误，可能导致后续逻辑基于错误的输出状态运行，潜在影响程序正确性与可靠性。
- D验证: stage_c_preserved / ver_e6cbc5e0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 661. hyp_path_e90825612b74

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_03.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者需要能够影响标准输出流的状态（如关闭或重定向），但实际利用性较低。
- 触发路径: putwchar((wchar_t)L'A'); @ L29
- 结论: 函数putwchar的返回值未被检查，违反CWE-252（Unchecked Return Value），可能导致写入错误被忽略。
- D验证: stage_c_preserved / ver_a7cdf014
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 662. hyp_path_6fd17025222f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_06.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊前提，只要执行该路径即可触发。
- 触发路径: putwchar((wchar_t)L'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_06.c:34
- 结论: 函数putwchar的返回值未被检查，违反CWE-252（未检查返回值）的API合约。尽管参数为常量字符且影响较低，但任何未检查的返回值均构成安全编码违规。
- D验证: stage_c_preserved / ver_7a213cdd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 663. hyp_path_68cdd866878a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_05.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无额外攻击者控制，仅依赖静态分析确认返回值未检查。
- 触发路径: putwchar((wchar_t)L'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_05.c:35
- 结论: 调用 putwchar 时未检查返回值，违反 CWE-252 定义的 API 契约，可能导致错误状态被忽略。属于 CWE-252 的典型场景，但由于 B 阶段风险评分较低（0.00），且缺少源到汇的完整数据流，实际可利用性较弱。
- D验证: stage_c_preserved / ver_96e8914c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 664. hyp_path_24636e12cc1b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_10.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特定攻击前提；需要输出设备或文件系统发生写入错误。
- 触发路径: putwchar((wchar_t)L'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_10.c:29
- 结论: 未检查putwchar函数的返回值，违反CWE-252（未检查返回值）。如果写入失败，可能导致数据丢失或输出不完整。
- D验证: stage_c_preserved / ver_4f034a78
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 665. hyp_path_bb707bbc95f7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_07.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无需攻击者输入；任何导致putwchar失败的环境因素（如输出流关闭）即可触发。
- 触发路径: putwchar((wchar_t)L'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_07.c:34
- 结论: 在代码行34中调用putwchar函数，但未检查其返回值。根据CWE-252定义，程序未检查可能表示失败或错误的函数返回值，可能导致未处理错误条件。
- D验证: stage_c_preserved / ver_86f7719c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 666. hyp_path_1fc0e1de3aa3

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_09.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 系统输出可能失败（如磁盘满、stdout 关闭）导致 putwchar 返回 WEOF。
- 触发路径: putwchar((wchar_t)L'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_09.c:29
- 结论: 未检查 putwchar 的返回值，可能导致输出错误未被发现，违反 API contract（CWE-252）。
- D验证: stage_c_preserved / ver_3e115f64
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 667. hyp_path_358af174ab61

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_16.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊前提，函数调用存在即可
- 触发路径: putwchar((wchar_t)L'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_16.c:29
- 结论: CWE-252 Unchecked Return Value: putwchar函数的返回值未检查，违反了API契约。即使注释说明不检查返回值，仍可能导致未检测到的错误。
- D验证: stage_c_preserved / ver_7826bc6f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 668. hyp_path_3c9c7d9ff784

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_14.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: putwchar((wchar_t)L'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_14.c:29
- 结论: putwchar函数返回值未被检查，违反CWE-252。即使写入失败（如磁盘满或管道关闭），程序无法感知并继续执行，可能导致数据丢失或未处理的错误状态。
- D验证: stage_c_preserved / ver_0ff30e9e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 669. hyp_path_82958492d126

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_15.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过影响输出设备或环境（如重定向到已满文件系统、输出设备故障）导致 putwchar 返回 WEOF。
- 触发路径: putwchar((wchar_t)L'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_15.c:30
- 结论: 在 case 6 中调用了 putwchar 但未检查其返回值，违反 CWE-252。如果 putwchar 失败（例如输出设备故障），程序无法感知错误状态，可能导致后续逻辑基于错误的假设继续执行（尽管本例中后续仅 break，但上下文可能隐含依赖）。
- D验证: stage_c_preserved / ver_8bdd5d76
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 670. hyp_path_03f302bc9613

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_13.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 调用putwchar时发生写入失败（例如stdout不可用）
- 触发路径: putwchar((wchar_t)L'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_13.c:29
- 结论: 在调用putwchar函数后未检查其返回值，违反了CWE-252定义，导致写操作失败未被检测到。尽管写入常量字符L'A'，且实际利用依赖于环境条件（如stdout关闭），但缺陷本身必须报告。
- D验证: stage_c_preserved / ver_751d2965
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 671. hyp_path_0e70835cb982

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_17.c:30
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特定攻击者输入，但外部因素（如输出设备故障）可能导致putwchar失败。
- 触发路径: putwchar((wchar_t)L'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_17.c:30
- 结论: 未检查putwchar函数的返回值，当输出失败时程序可能继续执行，导致未处理错误或数据丢失。
- D验证: stage_c_preserved / ver_20ae0c22
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 672. hyp_path_ed39d7c48f30

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_18.c:29
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序能够在某些情况下导致putwchar失败，例如磁盘满、输出设备不可用等。
- 触发路径: putwchar((wchar_t)L'A'); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putchar_18.c:29
- 结论: 代码中调用了putwchar但未检查其返回值，根据CWE-252，未检查返回值可能导致忽略错误条件，例如输出失败时程序可能继续执行而不处理错误，进而可能导致数据丢失或状态不一致。
- D验证: stage_c_preserved / ver_86047220
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 673. hyp_path_61b034ec8509

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_02.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊前提，只需函数执行
- 触发路径: PUTS(L"string"); @ CWE252_Unchecked_Return_Value__wchar_t_puts_02.c:35
- 结论: 未检查_putws函数的返回值，违反了CWE-252（未检查返回值）的API contract。虽然直接后果可能只是输出失败，但仍存在安全风险。
- D验证: stage_c_preserved / ver_33818dbd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 674. hyp_path_4132976f1c7f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_01.c:33
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过环境因素（如磁盘满）导致_putws失败，但无需直接控制输入。
- 触发路径: PUTS(L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_01.c:33
- 结论: 未检查_putws函数返回值，违反CWE-252，可能导致输出不完整或失败，影响程序行为。
- D验证: stage_c_preserved / ver_6fbebff7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 675. hyp_path_5ba1a73b3eee

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_03.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: PUTS(L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_03.c:35
- 结论: 调用PUTS（_putws）时未检查返回值，违反CWE252未检查返回值的要求。虽然IO错误可能性较低，但存在未处理的错误条件，可能导致程序在IO失败时行为异常。
- D验证: stage_c_preserved / ver_8eade390
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 676. hyp_path_7d7e4c8459d5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_04.c:41
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无攻击者可控输入，依赖运行环境中的输出异常（如磁盘满、输出设备故障）
- 触发路径: PUTS(L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_04.c:41
- 结论: _putws (PUTS) 的返回值未被检查，违反 API contract，可能导致未处理的错误状态（如写入失败）。虽输出硬编码字符串，攻击者无法直接控制，但错误忽略可能影响程序后续行为。
- D验证: stage_c_preserved / ver_e12409f8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 677. hyp_path_19e3d74c27f8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_05.c:41
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊攻击者控制输入，但环境可能导致 PUTS 失败（如输出重定向到有限空间、磁盘满、权限不足等）。
- 触发路径: PUTS(L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_05.c:41
- 结论: 调用 PUTS(L"string") 后未检查返回值，违反 CWE-252（未检查返回值）。虽然 puts 失败通常不会直接导致严重安全后果，但未检查返回值可能在特定环境（如输出重定向、资源耗尽）下导致未定义行为或信息泄露。
- D验证: stage_c_preserved / ver_0da794a6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 678. hyp_path_5d0ea9be872d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_07.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序执行到该代码路径，且PUTS可能因I/O错误而失败。
- 触发路径: PUTS(L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_07.c:40
- 结论: 调用PUTS（实际上是_putws）后未检查返回值，违反CWE-252（未检查返回值）的API契约。尽管标准输出失败场景罕见，但若发生输出错误，程序将无法感知并可能继续执行，导致数据丢失或逻辑异常。
- D验证: stage_c_preserved / ver_ca2e480d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 679. hyp_path_2eb1804b94a5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_06.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部输入依赖，代码固定调用_putws。
- 触发路径: { /* NOTE: Do not check the return value */ PUTS(L"string"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_06.c:40
- 结论: 函数_putws的返回值未被检查，违反CWE252（未检查返回值），可能导致未检测到的错误，影响较低。
- D验证: stage_c_preserved / ver_8471703a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 680. hyp_path_84cf51f69146

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_09.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无攻击者控制前提，调用固定字符串；但失败条件可能由 I/O 错误引发，然而实际利用难度较高。
- 触发路径: PUTS(L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_09.c:35; /* NOTE: Do not check the return value */ @ 同一文件34行注释
- 结论: 在调用 PUTS（实际为 _putws）时未检查返回值，尽管当前场景调用固定字符串失败概率低，但仍违反 API 合同，构成 CWE-252 未检查返回值的漏洞。
- D验证: stage_c_preserved / ver_0b619171
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 681. hyp_path_460708d2a5cd

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_10.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特定攻击者控制输入，但输出失败可能由环境因素（如磁盘满、stdout关闭）触发。
- 触发路径: PUTS(L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_10.c:35
- 结论: 代码调用PUTS(L"string")但未检查其返回值，违反CWE-252（未检查返回值）的API contract。尽管puts的返回值表示操作状态，忽略返回值可能在stdout写入失败时导致程序在错误状态下继续执行，但此处为固定字符串，影响有限。
- D验证: stage_c_preserved / ver_cd0429ac
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 682. hyp_path_a8435339e696

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_13.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部输入控制，但运行时环境可能导致 PUTS 失败（如设备满、权限问题），返回值未被检查。
- 触发路径: PUTS(L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_13.c:35
- 结论: 调用 PUTS(L"string") 时未检查返回值，违反 CWE-252（未检查返回值）。
- D验证: stage_c_preserved / ver_6e321b0e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 683. hyp_path_8ee78f2fb8ba

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_14.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: { /* NOTE: Do not check the return value */ PUTS(L"string"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_14.c:35
- 结论: 程序调用了putws（通过PUTS宏）但未检查返回值，违反了CWE-252（未检查返回值）。尽管参数为硬编码字符串，但写操作可能失败（如stdout关闭），导致输出完整性受影响。
- D验证: stage_c_preserved / ver_1b25fce5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 684. hyp_path_3871ef22dd30

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_15.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 调用可能因 I/O 错误而失败，无需攻击者输入控制
- 触发路径: PUTS(L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_15.c:36
- 结论: 未检查 wchar_t puts 函数的返回值，违反 CWE-252 规则。调用可能因 I/O 错误而失败，但程序无法感知错误，可能导致后续行为异常或资源泄漏。
- D验证: stage_c_preserved / ver_89df14c6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 685. hyp_path_8fb1b6f237f1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_17.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: PUTS(L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_17.c:36
- 结论: 在调用PUTS（可能是_putws）时，没有检查返回值。根据CWE-252，未检查返回值可能导致静默错误，例如输出失败但程序未感知。尽管当前场景中puts失败可能仅导致输出缺失，但违反了API合同，应视为安全漏洞。
- D验证: stage_c_preserved / ver_abd6647d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 686. hyp_path_af8099adcff7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_16.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: PUTS(L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_16.c:35
- 结论: 未检查puts函数的返回值，可能导致写入错误未被发现，违反CWE-252。
- D验证: stage_c_preserved / ver_747f8006
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 687. hyp_path_2f443ffa0934

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_18.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无直接攻击者输入控制，但函数可能因环境故障返回错误，且未检查。
- 触发路径: PUTS(L"string"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_18.c:35
- 结论: 在sink调用PUTS(L"string")后未检查其返回值，违反CWE-252（未检查返回值）。虽然当前调用使用固定字符串且影响较低，但仍构成API contract violation。
- D验证: stage_c_preserved / ver_82234314
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 688. hyp_path_ead365c7e31a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_01.c:33
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 删除操作因权限、文件不存在或磁盘满等原因失败。
- 触发路径: REMOVE(L"removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_01.c:33
- 结论: 未检查wremove函数的返回值，导致删除操作失败时未被发现，可能影响程序逻辑完整性。
- D验证: stage_c_preserved / ver_d2f3fe5c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 689. hyp_path_337ee152d695

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_03.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: REMOVE(L"removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_03.c:35
- 结论: CWE-252: Unchecked Return Value - 调用 REMOVE (wchar_t remove) 删除文件时没有检查返回值，可能导致文件删除操作失败未被检测，进而引发后续逻辑错误或安全不一致。
- D验证: stage_c_preserved / ver_5c447d50
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 690. hyp_path_b76d52d32361

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_02.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无攻击者可控输入；但文件删除操作可能因系统级原因失败（如文件不存在、权限不足）。
- 触发路径: REMOVE(L"removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_02.c:35
- 结论: 在函数调用 REMOVE(L"removemecase0.txt") 时未检查返回值，违反了 CWE-252（未检查返回值），可能导致删除操作失败未被检测到。
- D验证: stage_c_preserved / ver_d922c40e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 691. hyp_path_c23b75a98c3a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_05.c:41
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: No specific precondition; the code unconditionally ignores return value.
- 触发路径: /* NOTE: Do not check the return value */ REMOVE(L"removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_05.c:39-43
- 结论: The return value of REMOVE (_wremove) is not checked, violating API contract and allowing undetected failure to delete file. This is a CWE-252 vulnerability, though the impact is limited to potential denial of service or data leakage if file deletion failure is not handled.
- D验证: stage_c_preserved / ver_25c49d49
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 692. hyp_path_7e4f43d3c2e7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_04.c:41
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无需攻击者控制输入；目标文件移除失败的条件（如文件被占用、权限不足）存在即可触发未检查返回值的问题。
- 触发路径: REMOVE(L"removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_04.c:41
- 结论: 函数REMOVE（对应_wremove）的返回值未被检查，违反了CWE-252未检查返回值的要求，可能导致删除操作失败时程序无法感知，进而影响后续逻辑或产生不可预测行为。
- D验证: stage_c_preserved / ver_d4012ff4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 693. hyp_path_003b69863c8d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_06.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者无法控制删除的文件名，但可通过创建同名目录、设置文件权限或使路径无效来导致删除失败。
- 触发路径: REMOVE(L"removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_06.c:40
- 结论: 函数`_wremove`的返回值未被检查，违反了CWE-252（未检查返回值）。虽然参数是硬编码字符串，但文件删除仍可能因权限、路径等原因失败，未检查返回值可能导致程序无法感知错误，造成逻辑隐患。
- D验证: stage_c_preserved / ver_966c1ee8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 694. hyp_path_fb1ac2dab9d2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_09.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊前提，仅需执行到该代码路径。
- 触发路径: REMOVE(L"removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_09.c:35
- 结论: 函数REMOVE（_wremove）的返回值未被检查，违反CWE-252：未检查返回值。调用REMOVE(L"removemecase0.txt")后未验证操作是否成功，可能导致错误状态被忽略。
- D验证: stage_c_preserved / ver_b9681b66
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 695. hyp_path_5aef36a1f32b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_07.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 文件 'removemecase0.txt' 存在且可被删除，但攻击者可能通过修改权限或路径使删除失败。
- 触发路径: REMOVE(L"removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_07.c:40
- 结论: 调用 REMOVE 宏（扩展为 _wremove）删除文件时未检查返回值，可能导致文件删除失败而未被发现，违反 CWE-252 未检查返回值的要求。
- D验证: stage_c_preserved / ver_15d1f775
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 696. hyp_path_dcf46c8009b7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_13.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 文件 "removemecase0.txt" 不存在或当前进程无删除权限，导致删除操作失败。
- 触发路径: REMOVE(L"removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_13.c:35
- 结论: 在REMOVE调用后未检查返回值，违反了CWE-252：未检查返回值。如果remove操作失败（例如文件不存在、权限不足），程序将无法感知错误，可能导致后续逻辑错误或数据不一致。
- D验证: stage_c_preserved / ver_4a1cb5a6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 697. hyp_path_5f7ce5cd92f2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_10.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: REMOVE(L"removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_10.c:35
- 结论: 函数`_wremove`的返回值未被检查，违反CWE-252。尽管文件路径为硬编码，但未检查删除操作的成功与否可能导致程序状态不一致或资源残留。
- D验证: stage_c_preserved / ver_f5b0f558
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 698. hyp_path_985fe6d7b3a9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_15.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: case 6: /* NOTE: Do not check the return value */ REMOVE(L"removemecase0.txt"); break; @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_15.c:36
- 结论: 发现未检查返回值漏洞：代码调用REMOVE函数删除文件，但未检查其返回值。根据CWE-252定义，忽略函数返回值可能导致未处理的错误状态，例如文件删除失败未被检测，进而可能导致后续逻辑错误或资源泄漏。
- D验证: stage_c_preserved / ver_c0d5121c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 699. hyp_path_98589e1bad72

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_14.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特定攻击者输入，代码在正常执行路径中触发。
- 触发路径: { /* NOTE: Do not check the return value */ REMOVE(L"removemecase0.txt"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_14.c:35
- 结论: 调用REMOVE宏（实质为_wremove）删除文件时未检查返回值，违反CWE-252（未检查返回值）的API contract。虽然本例中删除操作失败不会直接导致安全后果，但未检查返回值可能导致逻辑错误或状态不一致。
- D验证: stage_c_preserved / ver_4c708cba
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 700. hyp_path_94f845a8db79

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_16.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特定攻击者控制输入，但若文件被其他进程锁定或权限不足，删除会失败。
- 触发路径: /* NOTE: Do not check the return value */ REMOVE(L"removemecase0.txt"); break; @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_16.c:35
- 结论: 调用删除文件函数时未检查返回值，违反API contract，可能导致文件删除操作失败而未被感知，后续程序可能基于错误的文件状态继续执行。
- D验证: stage_c_preserved / ver_dd8698bb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 701. hyp_path_7387074ed07d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_18.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序执行到该代码行，且REMOVE因权限不足、文件不存在或被占用等原因失败。
- 触发路径: REMOVE(L"removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_18.c:35
- 结论: 在调用REMOVE(wchar_t版本)删除文件时未检查返回值，违反CWE-252（未检查返回值）要求。即使REMOVE因权限、文件不存在等原因失败，程序也不会检测到错误，可能导致后续逻辑依赖于删除成功而出现不一致状态。
- D验证: stage_c_preserved / ver_b2119fbf
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 702. hyp_path_c7dcdc9b14a1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_17.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 调用 remove 函数时，删除操作可能因权限、文件不存在等而失败。
- 触发路径: REMOVE(L"removemecase0.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_17.c:36
- 结论: 对 wchar_t remove 函数的返回值未作检查，违反了 CWE-252 未检查返回值的要求。虽然删除文件失败的影响通常限于文件未被删除，但仍存在潜在的风险（如后续依赖文件存在的逻辑错误）。
- D验证: stage_c_preserved / ver_0f7f2ed0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 703. hyp_path_8f96bcff7ea6

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_01.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过限制文件系统权限、磁盘满或文件锁定等方式导致rename失败。
- 触发路径: /* NOTE: Do not check the return value */ RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_01.c:36
- 结论: 代码中调用RENAME宏（宽字符版本）但未检查返回值，违反了CWE-252（未检查返回值）。这可能导致rename操作失败时程序无法感知，进而引发文件状态不一致或后续逻辑错误。
- D验证: stage_c_preserved / ver_b342349e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 704. hyp_path_1bd54053a52e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_02.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响rename执行结果（如通过控制文件系统状态或权限），但具体利用难度依赖环境。
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt"); // NOTE: Do not check the return value @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_02.c:38
- 结论: 在调用rename函数时未检查返回值，违反API contract，可能导致文件操作失败未被正确处理，符合CWE-252未检查返回值漏洞。
- D验证: stage_c_preserved / ver_fc523ae3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 705. hyp_path_f671336d5cb2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_03.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过影响文件系统状态（如删除源文件、锁定目标文件或耗尽磁盘空间）使rename失败
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_03.c:38
- 结论: 调用_wrename（RENAME宏）未检查返回值，违反CWE-252未检查返回值规则。重命名操作可能失败，但程序未处理错误，可能导致后续操作基于错误的状态继续执行，引发逻辑错误或安全风险。
- D验证: stage_c_preserved / ver_47352413
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 706. hyp_path_98c541b0193f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_04.c:44
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响文件系统状态（如创建冲突文件、修改权限）或程序运行环境，使得重命名失败
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_04.c:44
- 结论: 未检查wrename函数的返回值，如果重命名失败，程序将继续执行，可能导致文件状态不一致或数据损坏。
- D验证: stage_c_preserved / ver_d95eae92
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 707. hyp_path_9ee062b1c1e2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_05.c:44
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过创建同名文件或目录、权限操纵等方式导致RENAME失败。
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_05.c:44
- 结论: 未检查RENAME函数的返回值，违反API contract，可能导致文件重命名操作失败时未被检测，进而引发后续逻辑错误或安全影响（如文件竞争条件）。
- D验证: stage_c_preserved / ver_7bbb89bb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 708. hyp_path_f31938497625

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_06.c:43
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: rename调用失败（如文件不存在、权限不足）
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_06.c:43
- 结论: 未检查rename函数的返回值，若rename失败（如文件不存在、权限不足），错误将被忽略，可能导致数据丢失或程序状态不一致。
- D验证: stage_c_preserved / ver_d049c9de
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 709. hyp_path_f6e456f33558

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_09.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过控制环境（如文件存在性、权限）导致rename失败，但无需用户输入即可触发代码执行路径。
- 触发路径: /* NOTE: Do not check the return value */ RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_09.c:38
- 结论: 调用rename函数未检查返回值，违反CWE-252（未检查返回值）的API contract，可能导致文件操作失败未被发现。
- D验证: stage_c_preserved / ver_0467b1ab
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 710. hyp_path_026ab25f0c3d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_07.c:43
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序执行到该调用点，且重命名操作可能失败（如文件不存在、权限不足等）
- 触发路径: /* NOTE: Do not check the return value */ RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_07.c:41-45
- 结论: 未检查rename函数返回值，可能忽略文件重命名失败的错误，导致程序状态不一致或逻辑错误。
- D验证: stage_c_preserved / ver_836f5c7e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 711. hyp_path_cd4095eb537a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_10.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊前提条件，只要执行该代码路径即可
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_10.c:38
- 结论: 未检查rename函数的返回值，导致无法得知重命名操作是否成功，违反了CWE-252。
- D验证: stage_c_preserved / ver_fa604e51
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 712. hyp_path_8ff5c6e109f3

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_13.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响文件系统状态（如创建同名文件、修改权限）使重命名失败
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_13.c:38
- 结论: 调用 RENAME 函数时未检查返回值，若重命名失败（例如权限不足、目标文件存在等），程序将继续执行，可能导致后续逻辑错误（如文件未改名导致误操作），违反 API contract。
- D验证: stage_c_preserved / ver_9d731afb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 713. hyp_path_312e7c779e11

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_14.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响文件系统状态（例如使旧文件不存在或无权限）
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt"); // 未检查返回值 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_14.c:38
- 结论: 函数_wrename的返回值未被检查，违反CWE-252未检查返回值的要求。尽管输入参数为常量，攻击者仍可通过影响文件系统状态（如删除旧文件、修改权限）导致rename操作失败，可能引发逻辑错误或数据不一致。可利用性较低，但存在API contract violation。
- D验证: stage_c_preserved / ver_5ea3dca1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 714. hyp_path_2b29828c2dcc

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_16.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响文件系统状态（如创建或锁定目标文件、修改权限），或者程序运行在文件系统可能发生错误的环境中。
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_16.c:38
- 结论: 函数_wrename的返回值未被检查，违反了CWE252规范。未检查返回值可能导致文件重命名操作失败时程序继续执行，潜在影响包括数据不一致、权限绕过或后续操作基于错误状态，可能被攻击者利用。
- D验证: stage_c_preserved / ver_1a92de9b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 715. hyp_path_9b6e76209cd8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_15.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序执行到switch case 6分支，该分支由外部输入或条件触发。; RENAME参数均为硬编码常量，攻击者无法控制。
- 触发路径: case 6: /* NOTE: Do not check the return value */ RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt"); break; default: @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_15.c:37-41
- 结论: 未检查_wrename函数的返回值，违反API contract，但参数为硬编码常量，攻击者无法控制输入，失败场景仅由系统环境决定，可利用性极低。
- D验证: stage_c_preserved / ver_93c15eed
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 716. hyp_path_6cd49bda8fc6

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_17.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响文件系统状态（如创建同名文件、修改权限）导致重命名失败。
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_17.c:39
- 结论: 未检查RENAME函数的返回值，违反CWE-252。重命名操作可能失败，但错误被忽略，可能导致后续逻辑错误或文件状态不一致。
- D验证: stage_c_preserved / ver_c1918a3e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 717. hyp_path_9496b4924ee1

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_18.c:38
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt"); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_18.c:38
- 结论: 调用RENAME时未检查返回值，违反CWE-252（未检查返回值），可能导致文件重命名失败未被处理。
- D验证: stage_c_preserved / ver_e8eca57c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 718. hyp_path_db276137fe5d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_01.c:32
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入，使得wscanf调用失败（例如输入EOF或格式不匹配）。
- 触发路径: wscanf(L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_01.c:32
- 结论: 未检查wscanf的返回值，违反了CWE-252（未检查返回值）。当wscanf失败时，dataBuffer可能包含未定义数据，可能导致未初始化变量使用。
- D验证: stage_c_preserved / ver_234088a8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 719. hyp_path_2ac54fc4472b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_01.c:57
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供数据，导致wscanf返回0（匹配失败）或EOF以外的值
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_01.c:46
- 结论: 函数case11中调用wscanf时仅检查了EOF错误，未检查匹配失败（返回0）的情况，构成CWE-252未充分检查返回值的API misuse。尽管dataBuffer已初始化为空字符串，匹配失败时data内容为空，但违反了返回值检查的语义要求。
- D验证: stage_c_preserved / ver_f7c4a65b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 720. hyp_path_5e5f82341358

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_02.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响输入流，使得wscanf返回0或EOF
- 触发路径: wscanf(L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_02.c:34
- 结论: 未检查wscanf的返回值，若读取失败则data内容未定义，可能导致信息泄露或未定义行为
- D验证: stage_c_preserved / ver_9ee568b7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 721. hyp_path_a0ada2bae322

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_03.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过关闭标准输入或提供格式不匹配的数据使wscanf返回0或EOF。
- 触发路径: wscanf(L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_03.c:34
- 结论: 未检查wscanf返回值，违反CWE-252（Unchecked Return Value），可能因输入失败导致未初始化数据被使用。
- D验证: stage_c_preserved / ver_bd288834
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 722. hyp_path_b130509b678e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_06.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制标准输入，导致wscanf读取失败（例如提前结束输入、格式不匹配等）
- 触发路径: wscanf(L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_06.c:39
- 结论: 代码中调用wscanf但未检查其返回值，违反CWE-252（未检查返回值）的定义。这可能导致忽略输入错误或文件结束条件，进而引发未定义行为或逻辑错误。
- D验证: stage_c_preserved / ver_dae37bc8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 723. hyp_path_97df9a1cc64f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_04.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够向标准输入提供数据，或程序在输入失败时继续执行。
- 触发路径: wscanf(L"%99s\0", data); /* NOTE: Do not check the return value */ @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_04.c:40
- 结论: 在CWE252_Unchecked_Return_Value__wchar_t_scanf_04.c中，wscanf的返回值未被检查，违反了CWE-252（未检查返回值）。尽管缓冲区大小受%99s限制，但未检查返回值可能导致程序在输入失败或EOF时使用未初始化的数据，具体影响取决于后续代码，证据中未展示后续使用，因此需要动态验证。
- D验证: stage_c_preserved / ver_2de5d266
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 724. hyp_path_8d7499fae2bc

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_05.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: wscanf调用可能因输入错误或EOF而失败
- 触发路径: wscanf(L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_05.c:40
- 结论: 未检查wscanf返回值，违反CWE-252。尽管后续使用data未在证据中明确，但未检查返回值本身违反API contract，可能导致未定义行为或资源消耗。
- D验证: stage_c_preserved / ver_394bda11
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 725. hyp_path_08dd605db183

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_07.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响标准输入流，导致wscanf返回失败（如发送EOF或关闭输入流）。
- 触发路径: wscanf(L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_07.c:39
- 结论: 未检查wscanf函数的返回值，违反CWE-252：Unchecked Return Value。如果wscanf失败，dataBuffer内容未定义，后续使用可能导致未初始化数据访问。
- D验证: stage_c_preserved / ver_ae0b8dd2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 726. hyp_path_42bbcb2eb2bf

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_10.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供数据，wscanf可能因输入流问题而失败。
- 触发路径: wscanf(L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_10.c:34
- 结论: 未检查wscanf函数的返回值，可能导致使用未正确初始化的数据或遗漏错误处理。
- D验证: stage_c_preserved / ver_79bb8fab
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 727. hyp_path_4fa1c31ee5a5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_09.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过控制标准输入导致wscanf读取失败（如关闭stdin或提供无效输入）
- 触发路径: wscanf(L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_09.c:34
- 结论: wscanf返回值未被检查，违反CWE-252（未检查返回值）。代码中明确注释不检查返回值，且无后续错误处理，但证据片段未显示后续使用data的代码，影响程度不确定。漏洞假设成立但可利用性取决于后续代码，需动态验证或审计。
- D验证: stage_c_preserved / ver_aafb0a84
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 728. hyp_path_a21b46966210

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_13.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响输入，使wscanf失败（如提前关闭输入流或提供无效输入）
- 触发路径: wscanf(L"%99s\0", data); // 返回值未被检查 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_13.c:34
- 结论: 未检查wscanf函数的返回值，若输入失败（如EOF或错误），后续使用dataBuffer中未更新的数据，违反API contract。
- D验证: stage_c_preserved / ver_25e9f088
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 729. hyp_path_a5030b97ca17

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_15.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过输入导致wscanf失败（例如EOF或格式不匹配）
- 触发路径: wscanf(L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_15.c:35
- 结论: 未检查wscanf的返回值，违反CWE-252（未检查返回值）
- D验证: stage_c_preserved / ver_59b3c8d1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 730. hyp_path_8e407d056ef7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_14.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响标准输入流（如通过程序输入）
- 触发路径: wscanf(L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_14.c:34
- 结论: 代码未检查wscanf函数的返回值，违反了CWE-252（未检查返回值）。如果wscanf调用失败（例如输入流提前结束或格式不匹配），dataBuffer中的内容可能未被正确写入，导致后续使用data时包含未初始化或不可预测的数据，可能造成信息泄露或程序异常。尽管当前代码片段未显示直接使用data的sink，但未检查返回值本身构成安全编码违规，且潜在影响存在，需动态验证后续路径。
- D验证: stage_c_preserved / ver_478a6637
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 731. hyp_path_961c9f0c1560

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_17.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序运行在标准输入可能失败的环境中。
- 触发路径: wscanf(L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_17.c:35
- 结论: 未检查wscanf的返回值，可能导致在输入失败时程序使用无效数据。
- D验证: stage_c_preserved / ver_36a907aa
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 732. hyp_path_bb75a275c047

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_16.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供数据，导致wscanf失败（如EOF或空输入）
- 触发路径: wscanf(L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_16.c:34
- 结论: 未检查wscanf的返回值，当wscanf失败时data可能未正确填充，导致后续使用未初始化或部分初始化的数据缓冲区，可能引发未定义行为或信息泄露。
- D验证: stage_c_preserved / ver_f27eb2d0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 733. hyp_path_e8d39eb71fa6

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_18.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供数据，但wscanf可能因错误（如输入格式不匹配）而失败。
- 触发路径: wscanf(L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_18.c:34
- 结论: 调用wscanf时未检查返回值，可能导致输入处理失败或数据未正确读取，违反CWE252（未检查返回值）。
- D验证: stage_c_preserved / ver_28769e53
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 734. hyp_path_b9f5942bcd5d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_16.c:66
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供输入，可能导致wscanf返回0（无匹配），从而跳过错误处理。
- 触发路径: if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_16.c:51
- 结论: 在case11中，wscanf的返回值仅被检查是否等于EOF，而未检查返回值是否等于预期匹配数1，违反了CWE252对返回值必须完整检查的要求。虽然数据缓冲区已初始化，影响较低，但仍构成API misuse。
- D验证: stage_c_preserved / ver_fbdddbbb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 735. hyp_path_82c5af39adbc

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_17.c:66
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够向标准输入提供数据，导致wscanf返回0或非EOF值，但dataBuffer内容变化对后续无影响。
- 触发路径: static void case11() { int k; for(k = 0; k < 1; k++) { { wchar_t dataBuffer[100] = L""; wchar_t * data = dataBuffer; if (wscanf(L"%99s\0", data) == EOF) { printLine("wscanf failed!"); } } } } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_17.c:45-62; void CWE252_Unchecked_Return_Value__wchar_t_scanf_17_case1() { case11(); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_17.c:64-68
- 结论: CWE252_Unchecked_Return_Value__wchar_t_scanf_17_case1中，case11函数调用wscanf时仅检查返回值是否为EOF，未处理返回0或正数的情况，构成返回值检查不完整。虽然dataBuffer已初始化且后续无使用，未产生直接安全影响，但仍违反API合同安全编程实践。
- D验证: stage_c_preserved / ver_25877fb5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 736. hyp_path_b425b2542b33

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_18.c:62
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入
- 触发路径: void CWE252_Unchecked_Return_Value__wchar_t_scanf_18_case1() { case11(); } @ 60-62; static void case11() { ... if (wscanf(L"%99s", data) == EOF) { ... } } @ 43-58
- 结论: 存在未检查返回值漏洞：wscanf返回值仅检查EOF，未检查是否成功读取期望的输入项数（应为1），可能导致数据未正确读取，违反CWE252要求。
- D验证: stage_c_preserved / ver_0640ad86
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 737. hyp_path_f14c5b8b697b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_01.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制输入SRC的内容或长度（需验证实际数据流）
- 触发路径: SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_01.c:40
- 结论: 对swprintf的返回值未进行检查，违反CWE-252：未检查返回值。若攻击者能控制SRC内容或长度，可能导致截断或失败而不被感知。
- D验证: stage_c_preserved / ver_f262460b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 738. hyp_path_21fe39de8cf9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_02.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: SNPRINTF的返回值未被检查，违反了API契约；SRC可能来自外部输入或可控源，但至少存在未检查返回值的缺陷。
- 触发路径: SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_02.c:42
- 结论: CWE-252: Unchecked Return Value - SNPRINTF返回值未被检查，可能导致缓冲区截断或数据丢失，影响数据完整性或后续处理的安全性。
- D验证: stage_c_preserved / ver_5ccff17d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 739. hyp_path_ca0f273488ba

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_03.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过某种方式控制变量SRC的内容或长度
- 触发路径: SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC); @ CWE252_Unchecked_Return_Value__wchar_t_snprintf_03.c:42
- 结论: 未检查snprintf返回值，违反CWE-252，可能导致输出截断未被检测
- D验证: stage_c_preserved / ver_bde8c504
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 740. hyp_path_596d9925bd6e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_05.c:48
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 任何导致swprintf失败的条件（如缓冲区不足）均可触发未检查返回值问题，即使当前输入固定。
- 触发路径: SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC); @ testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_05.c:48
- 结论: 调用swprintf未检查返回值，违反CWE-252，可能导致未检测到的写入错误或数据截断。
- D验证: stage_c_preserved / ver_fbfb320e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 741. hyp_path_f2eebdb76e17

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_04.c:48
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特殊前提，只要执行到此调用即可。
- 触发路径: SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_04.c:48
- 结论: 未检查swprintf返回值，可能导致数据截断或错误未被处理，违反CWE-252未检查返回值要求。
- D验证: stage_c_preserved / ver_1061b17a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 742. hyp_path_1d7ac31a9846

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_06.c:47
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能控制SRC内容，可能导致写入长度超过缓冲区剩余空间，但返回值未被检查。
- 触发路径: wchar_t * data = dataBuffer; /* NOTE: Do not check the return value */ SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_06.c:45-49
- 结论: 调用SNPRINTF（swprintf）时未检查返回值，导致未处理数据截断的可能，违反了CWE-252未检查返回值约定。
- D验证: stage_c_preserved / ver_969ddf50
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 743. hyp_path_1428fe3e362e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_09.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: SRC长度可能变化导致写入截断，但攻击者无法直接控制SRC内容。
- 触发路径: SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC); @ 42
- 结论: 未检查swprintf的返回值，可能导致写入失败或截断未被发现，违反API contract。
- D验证: stage_c_preserved / ver_726ab402
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 744. hyp_path_3c5baba6762a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_07.c:47
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: N/A
- 触发路径: SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_07.c:47
- 结论: 代码中调用SNPRINTF（即swprintf）后未检查返回值，违反了CWE-252 API contract。尽管缓冲区大小可能充足且输入为常量，但未处理返回值可能掩盖写入失败或截断，导致数据不一致或后续逻辑异常。
- D验证: stage_c_preserved / ver_cdcb51c3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 745. hyp_path_e0ed2281a99f

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_10.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无需攻击者控制输入；未检查返回值本身即违反合同
- 触发路径: SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC); @ 42
- 结论: 函数CWE252_Unchecked_Return_Value__wchar_t_snprintf_10_case0中调用swprintf后未检查返回值，违反CWE-252 API合同。即使输入SRC为固定字符串，未检查返回值仍是明确的API misuse，可能导致输出截断未被发现，影响数据完整性。
- D验证: stage_c_preserved / ver_27a70a87
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 746. hyp_path_80ebc5a28678

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_15.c:43
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部攻击者直接可控输入，代码为测试用例
- 触发路径: 入口点 @ L32; SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC); /* NOTE: Do not check the return value */ @ L43
- 结论: 调用SNPRINTF未检查返回值，违反API contract，符合CWE-252未检查返回值。虽然当前上下文影响较低（写入本地缓冲区后仅打印），但返回值未检查仍构成安全违规。
- D验证: stage_c_preserved / ver_f6322461
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 747. hyp_path_cd5f85871f15

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_13.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能无法直接控制输入，但未检查返回值本身是违反API契约。实际可利用性可能较低，因为swprintf失败通常发生在缓冲区太小或编码错误，但未检查返回值可能导致数据截断或未写入，进而引发后续逻辑错误。
- 触发路径: SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_13.c:42
- 结论: 未检查swprintf返回值，违反CWE-252。
- D验证: stage_c_preserved / ver_b3e8d914
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 748. hyp_path_e33538b09be7

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_14.c:42
- 漏洞类型: buffer_overflow
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序正常执行至此语句，且swprintf可能失败（如输出被截断或格式化错误）
- 触发路径: SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_14.c:42
- 结论: 调用swprintf（SNPRINTF宏）后未检查返回值，违反了CWE-252（未检查返回值）的API合约。尽管在此上下文中swprintf失败可能不会立即导致缓冲区溢出，但缺失错误检查可能导致未定义行为或被忽略的截断，从而造成信息丢失或逻辑错误。
- D验证: stage_c_preserved / ver_0a6c0139
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 749. hyp_path_70a7759ebfc5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_16.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序执行到该分支，且swprintf可能失败（如缓冲区不足或输出错误）
- 触发路径: SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_16.c:42
- 结论: 未检查swprintf返回值，违反CWE-252（未检查返回值），可能导致数据写入不完整或逻辑错误，但无法直接利用于代码执行或越界访问。
- D验证: stage_c_preserved / ver_300c94af
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 750. hyp_path_531789fb6b63

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_17.c:43
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无特定攻击者输入，但假设SNPRINTF可能因缓冲区大小不足或其他原因失败。
- 触发路径: SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_17.c:43
- 结论: 调用SNPRINTF（如swprintf）后未检查其返回值，违反CWE-252（未检查返回值）的API契约。虽然B阶段风险评分较低（sink=0.00），表明实际安全影响可能较小（如后续仅使用不完整数据），但代码中明确未检查返回值，存在潜在的信息截断或错误状态未处理问题，符合CWE-252定义。
- D验证: stage_c_preserved / ver_ea096da4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 751. hyp_path_e656b7da7751

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_18.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无外部攻击者输入，但SRC可能来自程序内部，未检查返回值在逻辑上构成缺陷。
- 触发路径: SNPRINTF(data,100-wcslen(SRC)-1, L"%s\n", SRC); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_18.c:42
- 结论: 未检查swprintf（SNPRINTF）的返回值，违反了API契约，可能导致数据截断或错误未被发现。
- D验证: stage_c_preserved / ver_1b7e7333
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 752. hyp_path_cb83fbda9f14

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_01.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制输入流SRC，使其导致swscanf失败（例如空输入或格式不匹配）。
- 触发路径: swscanf(SRC, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_01.c:34
- 结论: swscanf返回值未被检查，违反CWE-252；虽然SRC来源未知可能降低可利用性，但API contract violation本身存在，且若SRC为可控输入，可能导致后续使用未初始化数据。
- D验证: stage_c_preserved / ver_9f5f94cb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 753. hyp_path_952fda8500df

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_02.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制 swscanf 的输入字符串 SRC 或其内容，或即使在 SRC 固定时，未检查返回值也可能导致 data 保持未初始化状态。
- 触发路径: swscanf(SRC, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_02.c:36
- 结论: 在调用 swscanf 后未检查返回值，违反 API contract（CWE-252），可能使用未初始化的 data 缓冲区或解析不完整的数据。
- D验证: stage_c_preserved / ver_75dee1ac
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 754. hyp_path_d5bd4c65bd8b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_03.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC的内容（或SRC为可能不匹配格式的输入）
- 触发路径: swscanf(SRC, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_03.c:36
- 结论: 调用swscanf未检查返回值，违反CWE-252，若输入不符合指定格式（如SRC内容非预期），则data内容未定义，可能导致未初始化数据使用。攻击者控制SRC的前提在Juliet样本中可能不成立，但API misuse本身存在。
- D验证: stage_c_preserved / ver_68631899
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 755. hyp_path_49ae52fd4562

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_05.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC的内容，使其不符合格式或为空
- 触发路径: swscanf(SRC, L"%99s\0", data); // 未检查返回值 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_05.c:42
- 结论: 未检查swscanf返回值，若SRC内容不符合格式'%99s'，则swscanf返回0或EOF，data保持未初始化或未更新状态，可能导致未定义行为或逻辑错误。
- D验证: stage_c_preserved / ver_fdc643b7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 756. hyp_path_780e97ce6e99

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_04.c:42
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC字符串（或SRC来自外部输入）
- 触发路径: swscanf(SRC, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_04.c:42
- 结论: 未检查swscanf返回值，若读取失败则data保持未初始化状态，后续使用可能导致未定义行为或信息泄露；但当前代码片段未展示后续使用，实际可利用性需动态验证。
- D验证: stage_c_preserved / ver_b3d95ce2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 757. hyp_path_181a9e230177

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_09.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制swscanf的输入SRC，使其返回EOF或少于预期的匹配项，导致data未正确更新。
- 触发路径: swscanf(SRC, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_09.c:36
- 结论: 未检查swscanf函数的返回值，违反API contract。若swscanf失败，data可能未正确填充，导致后续使用未初始化数据，可能造成信息泄露或程序异常。
- D验证: stage_c_preserved / ver_cd71602e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 758. hyp_path_286e48ac1d54

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_06.c:41
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: Attacker may control SRC (not confirmed in evidence) or input causes parse failure (e.g., empty string, format mismatch).
- 触发路径: swscanf(SRC, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_06.c:41
- 结论: Unchecked return value of swscanf leads to potential use of uninitialized or incomplete data, violating CWE-252, but the impact depends on whether SRC is attacker-controlled and whether data is subsequently used. B-stage signals indicate low risk and missing evidence, making this a candidate for dynamic validation.
- D验证: stage_c_preserved / ver_26a511d8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 759. hyp_path_e084a2053519

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_10.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC输入，使其无法成功匹配格式化字符串。
- 触发路径: swscanf(SRC, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_10.c:36
- 结论: 未检查swscanf返回值，可能导致data未正确更新，后续使用未初始化栈数据，违反CWE-252。
- D验证: stage_c_preserved / ver_844f7b2a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 760. hyp_path_71f40523f6ad

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_14.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC字符串的内容，从而可能使swscanf解析失败
- 触发路径: swscanf(SRC, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_14.c:36
- 结论: 在CWE252_Unchecked_Return_Value__wchar_t_sscanf_14.c的第36行调用swscanf时未检查返回值。如果swscanf失败（例如输入格式不匹配或读取错误），则dataBuffer可能保持未初始化状态，导致后续使用未初始化数据，可能引发未定义行为或信息泄露。但证据不完整，因为后续对dataBuffer的使用未在触发路径中体现，且SRC的可控性需进一步确认。
- D验证: stage_c_preserved / ver_9d8bedbd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 761. hyp_path_f9e3cbc3d90e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_16.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响SRC的内容，使其不符合格式字符串L"%99s"，导致swscanf返回小于1或EOF。
- 触发路径: swscanf(SRC, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_16.c:36
- 结论: swscanf函数的返回值未被检查，违反了CWE-252（未检查返回值）。如果swscanf调用失败，数据缓冲区data可能未被正确填充，导致后续使用未初始化或部分初始化的数据，可能引发未定义行为或信息泄露。
- D验证: stage_c_preserved / ver_13acd80e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 762. hyp_path_9ce248e49bcd

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_15.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC字符串内容，使其无法匹配格式或输入异常（但SRC来源未明确，可能为常量，降低可利用性）
- 触发路径: swscanf(SRC, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_15.c:37
- 结论: swscanf返回值未检查，可能导致未初始化内存使用或逻辑错误
- D验证: stage_c_preserved / ver_5576ba70
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 763. hyp_path_4bdf6074e971

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_16.c:68
- 漏洞类型: CWE-252, CWE-253
- CWE: CWE-252; CWE-253
- 风险等级: P1
- 触发条件: SRC必须为外部可控输入（例如用户提供），且内容导致swscanf返回0（格式匹配失败）。
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_16.c:55
- 结论: 在swscanf调用中，仅检查返回值是否为EOF，未检查返回值为0的情况，违反了CWE-252（未检查返回值）和CWE-253（不正确的返回值检查）的契约要求。尽管当前测试用例中SRC为常量字符串，返回0不可能发生，但代码逻辑上未覆盖所有失败模式，在SRC变为外部可控输入时会导致未处理的格式匹配失败。
- D验证: stage_c_preserved / ver_4f4c6533
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 764. hyp_path_a72dd94ab079

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_18.c:36
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC字符串，使其无法匹配格式（例如空字符串或非空格字符），导致swscanf返回0或EOF。
- 触发路径: swscanf(SRC, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_18.c:36
- 结论: 未检查swscanf返回值，如果读取失败，dataBuffer可能包含未初始化数据，导致后续使用未定义行为。
- D验证: stage_c_preserved / ver_6026bc42
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 765. hyp_path_bbbd225d7959

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_17.c:37
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC字符串的内容; dataBuffer未初始化（局部变量默认未定义）
- 触发路径: swscanf(SRC, L"%99s\0", data); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_17.c:37
- 结论: 在swscanf调用后未检查返回值，违反CWE-252的API契约。如果swscanf失败且dataBuffer未初始化，则data内容未定义，但当前代码片段缺少后续使用data的sink点，实际影响未确认。
- D验证: stage_c_preserved / ver_6029ab77
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 766. hyp_path_6198c15169ea

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_17.c:68
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制SRC字符串，使得swscanf返回0而非EOF。
- 触发路径: if (swscanf(SRC, L"%99s\0", data) == EOF) { printLine("swscanf failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_17.c:68
- 结论: swscanf返回值检查不完整：只检查了EOF错误，未处理返回0（无匹配项）的情况，可能导致未检测到的解析失败，违反CWE-252定义。
- D验证: stage_c_preserved / ver_8176c054
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 767. hyp_path_530882845ac5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_12.c:82
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够使stdin在fread读取时提前关闭或提供少于期望的数据量
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_12.c:82; 假设后续使用data缓冲区，例如打印或处理 @ 同一函数后续代码（未显示，但Juliet样本通常存在使用data的代码）
- 结论: 在fread调用后检查了返回值，但错误处理仅打印消息，未阻止后续使用未完全填充的data缓冲区，可能导致未初始化数据使用或信息泄露。
- D验证: stage_c_preserved / ver_89f11bac
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 768. hyp_path_f4d9d803d61a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_12.c:45
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin输入，但未检查返回值本身是代码缺陷，无需外部控制
- 触发路径: void CWE252_Unchecked_Return_Value__char_fread_12_case0() { if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_12.c:24; fread((char *)data, sizeof(char), (size_t)(100-1), stdin); // 未检查返回值 @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_12.c:35
- 结论: 在CWE252_Unchecked_Return_Value__char_fread_12_case0函数中，当globalReturnsTrueOrFalse()返回假时，执行的分支未检查fread()的返回值，违反了CWE252（未检查返回值）的API契约。即使后续未直接使用data，忽略返回值仍可能导致未定义行为或部分读取数据未被处理。
- D验证: stage_c_preserved / ver_8005dead
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 769. hyp_path_100a8864f927

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_12.c:45
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能通过控制stdin的输入状态使fread失败，但无需特殊权限
- 触发路径: void CWE252_Unchecked_Return_Value__wchar_t_fread_12_case0() { if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_12.c:24-28; wchar_t * data = dataBuffer; /* NOTE: Do not check the return value */ fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin); } } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_12.c:32-36
- 结论: 在CWE252_Unchecked_Return_Value__wchar_t_fread_12_case0函数中，当globalReturnsTrueOrFalse()返回真时，fread的返回值未被检查，违反了CWE-252（未检查返回值）的规定。这可能导致未检测到读取失败，进而使后续操作基于不完整或未初始化的数据，造成潜在的安全风险。
- D验证: stage_c_preserved / ver_e05bcf1d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 770. hyp_path_460e42e059f8

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_15.c:65
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使fread返回小于100-1的值（部分读取）
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_15.c:65
- 结论: fread返回值检查不完整，仅对完全失败（返回0或EOF）打印错误，未处理部分读取（返回值大于0但小于请求数）的情况，导致缓冲区可能未被完全初始化。虽然后续代码未在提供片段中体现，但API misuse（CWE-252）已存在，可能存在潜在安全风险。
- D验证: stage_c_preserved / ver_c68b580c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 771. hyp_path_bcd320ad28f9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_18.c:53
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制输入使得fread读取少于99个字符（如提前结束输入或输入错误）。
- 触发路径: if (fread((char *)data, sizeof(char), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_18.c:53
- 结论: fread返回值检查不充分：仅检查返回值是否等于100-1，而未处理返回值小于100-1的情况（如部分读取或EOF），可能导致data缓冲区包含未初始化或部分数据，违反CWE-252关于未检查返回值的要求。
- D验证: stage_c_preserved / ver_48fc3204
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 772. hyp_path_77db30b23ff2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_02.c:78
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: Attacker can control stdin input or cause fread to fail (e.g., EOF, error).
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_02.c:78
- 结论: CWE-252: Unchecked Return Value - fread return value checked but error handling insufficient (only print message, no recovery or abort). While the return value is compared, the failure is logged but not acted upon (e.g., terminate or use default data). This could lead to use of incomplete or uninitialized data in subsequent operations (though not evident in this snippet).
- D验证: stage_c_preserved / ver_48569e8b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 773. hyp_path_3bd71e268fd2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_03.c:78
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过提供少于99个宽字符或触发EOF，导致fread返回值小于100-1。
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ CWE252_Unchecked_Return_Value__wchar_t_fread_03.c:78
- 结论: fread返回值被检查，但失败后仅打印错误消息，未处理缓冲区未完全填充的情况。若后续存在未初始化的数据使用，则构成CWE-252漏洞，但目前缺乏后续sink证据。
- D验证: stage_c_preserved / ver_42b531f2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 774. hyp_path_d93967f5940a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_03.c:59
- 漏洞类型: CWE-253, CWE-754
- CWE: CWE-253; CWE-754
- 风险等级: P1
- 触发条件: 攻击者能够控制输入流，使fread在读取部分数据后遇到EOF或错误，导致返回值小于100-1但大于0
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_03.c:59
- 结论: fread返回值检查不完整：仅检查返回值是否等于100-1，未正确处理部分读取或错误情况，可能导致后续使用未初始化数据，但当前代码片段未显示后续sink，影响待定。
- D验证: stage_c_preserved / ver_56801704
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 775. hyp_path_1ea5df5bdd41

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_08.c:47
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 程序从stdin读取数据，但fread可能返回小于请求字节数的值或0，攻击者可通过提供不足输入触发未检查返回值的问题。
- 触发路径: fread((char *)data, sizeof(char), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_08.c:47
- 结论: 未检查fread返回值可能导致读取失败后数据处理错误，违反CWE-252。
- D验证: stage_c_preserved / ver_d362d325
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 776. hyp_path_01c77df7cbe9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_08.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无需特殊前提，任何输入均触发未检查返回值的行为。
- 触发路径: fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_08.c:39
- 结论: 函数调用fread后未检查返回值，违反CWE-252未检查返回值约定，可能导致读取数据不完整或使用未初始化数据。
- D验证: stage_c_preserved / ver_7e5f2271
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 777. hyp_path_0a4dec2f832d

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_11.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供数据，可能提前结束输入或触发错误，导致 fread 返回少于预期字符数
- 触发路径: void CWE252_Unchecked_Return_Value__char_fread_11_case0() { if(globalReturnsTrue()) { @ L24-28; char * data = dataBuffer; /* NOTE: Do not check the return value */ fread((char *)data, sizeof(char), (size_t)(100-1), stdin); @ L32-36
- 结论: 未检查 fread 返回值，违反 CWE-252 约定，但代码片段未展示后续使用读取数据，因此可利用性较低，需进一步上下文确认。
- D验证: stage_c_preserved / ver_7cf3af7e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 778. hyp_path_ef76d8605e67

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_18.c:53
- 漏洞类型: CWE-252, CWE-457
- CWE: CWE-252; CWE-457
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin控制输入，使得fread返回0或部分读取（<99）
- 触发路径: if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1) { printLine("fread failed!"); } @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_18.c:53
- 结论: fread返回值检查不完整：代码检查了fread返回值是否等于99，但如果fread返回0或部分读取，会打印错误但继续执行，导致后续使用未完全初始化的缓冲区data，可能造成信息泄露或未定义行为。
- D验证: stage_c_preserved / ver_330c3377
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 779. hyp_path_60647a083ce4

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_01.c:32
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供少于99字节的输入，从而触发读取不足
- 触发路径: fread((char *)data, sizeof(char), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_01.c:32
- 结论: fread函数返回值未检查，可能导致缓冲区未完全初始化，进而造成信息泄露或未定义行为。
- D验证: stage_c_preserved / ver_707e7c19
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 780. hyp_path_8c2edf065182

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_02.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过关闭 stdin、发送 EOF 或限制输入长度使 fread 返回小于请求的字节数
- 触发路径: fread((char *)data, sizeof(char), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_02.c:34
- 结论: fread 返回值未检查，违反 CWE-252（未检查返回值）。虽然当前代码片段后续未使用 data 缓冲区，但若在真实场景中存在后续数据处理，则可能因 fread 读取不足导致未初始化数据访问或逻辑错误。
- D验证: stage_c_preserved / ver_52f8fadc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 781. hyp_path_30ba1574f5d9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_04.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 标准输入可能提供少于99个字符或发生读取错误
- 触发路径: fread((char *)data, sizeof(char), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_04.c:40
- 结论: 未检查fread返回值，可能导致data缓冲区未完全初始化或读取失败，后续使用未初始化数据或错误数据。
- D验证: stage_c_preserved / ver_844c8027
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 782. hyp_path_9b48b948fd13

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_03.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者通过影响stdin（如提前关闭输入流或提供不完整数据）导致fread失败。
- 触发路径: fread((char *)data, sizeof(char), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_03.c:34
- 结论: fread函数的返回值未被检查。若fread失败，缓冲区data将保持未初始化状态（但局部数组dataBuffer已初始化为空串，因此未初始化风险较低）。然而，根据API契约，fread的返回值必须检查以确认读取的字符数；未检查即违反CWE-252。尽管当前代码片段后无对data的后续使用，减少了直接危害，但违规行为本身存在。
- D验证: stage_c_preserved / ver_88081b34
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 783. hyp_path_d85855baf44b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_05.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，提供少于99字节的数据或导致fread失败
- 触发路径: fread((char *)data, sizeof(char), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_05.c:40
- 结论: fread函数返回值未被检查，违反CWE-252（未检查返回值），可能导致读取字节数不足或读取失败，使用部分未初始化的缓冲区，造成信息泄露或程序行为异常。
- D验证: stage_c_preserved / ver_f3e8424f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 784. hyp_path_d25935d3f314

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_06.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，通过提供少于预期字节数或触发读取错误来影响fread的返回值。
- 触发路径: fread((char *)data, sizeof(char), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_06.c:39
- 结论: 对fread的返回值未进行检查，违反CWE-252：未检查返回值。攻击者可通过控制stdin输入，导致fread部分读取或失败，而data缓冲区内容未按预期填充，可能造成后续逻辑错误。
- D验证: stage_c_preserved / ver_842cfca5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 785. hyp_path_7fb1c83f9c6a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_11.c:26
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin输入导致读取失败或部分读取
- 触发路径: fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin); @ 26
- 结论: fread返回值未检查，违反CWE-252 API contract；但当前代码中读取的数据未被后续使用，因此无直接安全影响，但动态环境中仍可能存在风险，需要动态验证或审计确认是否有其他路径使用该数据。
- D验证: stage_c_preserved / ver_851b5a2c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 786. hyp_path_845f1c8fb033

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_07.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供少于期望字节数的输入，或fread因其他原因失败
- 触发路径: fread((char *)data, sizeof(char), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_07.c:39
- 结论: fread返回值未检查，可能读取不足预期字节数，后续将未完全初始化的data作为字符串使用，可能导致信息泄露或未定义行为（但缺少sink代码证据，路径不完整）
- D验证: stage_c_preserved / ver_74239236
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 787. hyp_path_d4a2b6a36221

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_09.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin输入，使得fread读取少于99个字符。
- 触发路径: fread((char *)data, sizeof(char), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_09.c:34
- 结论: 未检查fread返回值可能导致后续使用未初始化或部分读取的数据，违反API contract。
- D验证: stage_c_preserved / ver_0ed10444
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 788. hyp_path_cac006590ef9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_10.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入 stdin 提供不足 99 个字符的数据，使 fread 返回小于请求的大小。
- 触发路径: fread((char *)data, sizeof(char), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_10.c:34
- 结论: 调用 fread 后未检查返回值，违反 CWE-252 定义，可能导致未完全填充的 dataBuffer 被后续使用，虽然此代码片段未展示 sink 路径，但 contract violation 本身即构成漏洞假设。
- D验证: stage_c_preserved / ver_2da9b14b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 789. hyp_path_b7cdcae42e83

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_13.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，提供少于99个字符的数据。
- 触发路径: fread((char *)data, sizeof(char), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_13.c:34
- 结论: fread返回值未检查，违反CWE-252。若读取数据少于预期，data可能未完全初始化，后续使用可能导致信息泄露或逻辑错误，但当前证据不完整，需动态验证实际影响。
- D验证: stage_c_preserved / ver_b845013a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 790. hyp_path_6a4f69dfb8c6

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_14.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin输入控制fread读取的数据量（如发送小于99字节的数据或造成读取错误）
- 触发路径: fread((char *)data, sizeof(char), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_14.c:34
- 结论: fread返回值未检查，违反API contract，可能导致数据读取不完整或错误，进而引发未初始化数据使用或逻辑异常。
- D验证: stage_c_preserved / ver_4c3a7231
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 791. hyp_path_e756208302da

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_15.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin输入（例如通过重定向或控制输入流），导致fread部分读取或失败。
- 触发路径: fread((char *)data, sizeof(char), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_15.c:35
- 结论: 函数fread的返回值未被检查，违反CWE-252（未检查返回值），可能导致读取操作失败时未正确处理，进而影响程序状态或数据完整性。
- D验证: stage_c_preserved / ver_d5a54f87
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 792. hyp_path_e8391c7bf60e

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_16.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin的输入，例如提供不完整数据或触发错误
- 触发路径: fread((char *)data, sizeof(char), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_16.c:34
- 结论: fread的返回值未被检查，违反了API契约（CWE-252）。尽管代码片段中未展示后续对data的使用，但CWE-252的定义是未检查返回值即构成漏洞，无论后续是否使用。如果fread失败，data缓冲区内容不确定，可能导致未定义行为。
- D验证: stage_c_preserved / ver_85f7104c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 793. hyp_path_1589ce53e185

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_17.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够导致fread失败（如关闭stdin或制造读取错误）
- 触发路径: fread((char *)data, sizeof(char), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_17.c:35
- 结论: fread返回值未检查，违反API contract，可能导致数据未初始化或未定义行为。
- D验证: stage_c_preserved / ver_fbe31846
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 794. hyp_path_6ce6f2aa785c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_18.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin输入控制fread的实际读取量（例如提前关闭流或发送短数据），导致data缓冲区部分未更新。
- 触发路径: fread((char *)data, sizeof(char), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_18.c:34
- 结论: 函数fread的返回值未被检查，违反CWE-252 API合约，可能导致使用不完整或未初始化的数据。尽管直接影响较低，但仍构成可验证的漏洞假设。
- D验证: stage_c_preserved / ver_29f05f4f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 795. hyp_path_9c181b64bc7c

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_03.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入或导致读取失败
- 触发路径: fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_03.c:34
- 结论: fread返回值未检查，可能导致读取失败时数据未初始化或部分读取，违反CWE-252未检查返回值
- D验证: stage_c_preserved / ver_a72ddcd2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 796. hyp_path_b49f63deae6b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_01.c:32
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供少于100-1个宽字符的数据，导致fread返回值小于请求数
- 触发路径: fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_01.c:32
- 结论: 对fread的返回值未进行检查，违反CWE-252定义，即使后续未使用数据，返回值检查缺失构成API misuse。
- D验证: stage_c_preserved / ver_668f3267
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 797. hyp_path_04b91869ead2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_02.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin提供输入，使fread读取少于预期数量（如输入不足或发生错误）。
- 触发路径: fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_02.c:34
- 结论: fread返回值未检查，若fread读取失败或读取少于预期字节，则dataBuffer中的未初始化数据可能被后续使用，违反CWE-252要求。尽管代码片段未显示后续使用，但返回值未检查本身构成API contract violation。
- D验证: stage_c_preserved / ver_13bc9c76
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 798. hyp_path_1b3df5ad336a

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_04.c:40
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 标准输入可能不提供足够数据或发生读取错误。
- 触发路径: fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_04.c:40
- 结论: fread的返回值未被检查，违反CWE-252（未检查返回值），可能导致读取操作失败时数据未正确初始化，后续使用未初始化数据。
- D验证: stage_c_preserved / ver_8b3961f6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 799. hyp_path_2d348e6601a9

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_05.c:40
- 漏洞类型: CWE-252, CWE-457
- CWE: CWE-252; CWE-457
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供少于预期的数据或触发读取错误/EOF，导致fread返回值小于请求值。
- 触发路径: fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_05.c:40
- 结论: 函数fread的返回值未被检查，导致可能读取失败或部分读取时数据未初始化，违反CWE-252（未检查返回值）和CWE-457（使用未初始化变量）。
- D验证: stage_c_preserved / ver_9c5762e4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 800. hyp_path_1d9311e517aa

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_06.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够提供少于预期的输入，或存在读取失败条件
- 触发路径: fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_06.c:39
- 结论: fread函数返回值未被检查，违反CWE-252（未检查返回值），可能导致数据读取不完整或失败，后续使用部分填充或未初始化的数据。
- D验证: stage_c_preserved / ver_8ab41a39
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 801. hyp_path_2d07083bfbde

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_07.c:39
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin输入导致fread失败（如EOF或读取错误）
- 触发路径: fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_07.c:39
- 结论: fread的返回值未被检查，违反了CWE-252（未检查返回值）。如果fread失败，dataBuffer中的数据可能未正确填充，后续使用可能导致未初始化数据读取或错误处理。
- D验证: stage_c_preserved / ver_0e7d22b9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 802. hyp_path_9223c635bfdd

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_10.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够向stdin提供输入。
- 触发路径: fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_10.c:34
- 结论: fread的返回值未被检查，可能导致使用未完全初始化的数据，违反CWE-252 Unchecked Return Value。
- D验证: stage_c_preserved / ver_9bf7b03e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 803. hyp_path_d775f58b9558

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_09.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，例如提前关闭输入流或提供少量数据。
- 触发路径: fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_09.c:34
- 结论: fread返回值未检查，当读取字节数少于预期或读取失败时，后续使用dataBuffer中的数据可能导致未初始化内存访问或信息泄露。
- D验证: stage_c_preserved / ver_1b97d43a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 804. hyp_path_344117506524

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_14.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 无需特殊前提，任何输入均可能导致返回值未被检查。
- 触发路径: fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_14.c:34
- 结论: 未检查fread的返回值，可能导致读取数据不完整或失败，违反CWE-252。
- D验证: stage_c_preserved / ver_dc766506
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 805. hyp_path_276f8b33d6b5

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_16.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin的读取结果，例如通过截断输入流或导致读取失败。
- 触发路径: fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_16.c:34
- 结论: fread返回值未检查，如果fread失败（如文件结束或错误），dataBuffer内容可能未定义，违反CWE-252 API契约。
- D验证: stage_c_preserved / ver_a09a637f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 806. hyp_path_f8336891219b

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_13.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入，使得fread返回小于请求数量的元素或失败。
- 触发路径: fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_13.c:34
- 结论: fread返回值未被检查，违反CWE-252，可能导致使用未初始化数据或读取不完全的数据。
- D验证: stage_c_preserved / ver_c25a43d0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 807. hyp_path_f314060c0f57

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_15.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够影响stdin的输入状态（例如提前关闭或提供少于预期数量的数据），导致fread返回小于请求的元素数或失败。
- 触发路径: fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_15.c:35
- 结论: fread的返回值未被检查，违反API contract，可能导致未初始化的数据被使用或部分读取的数据被忽略，造成信息泄露或逻辑错误。
- D验证: stage_c_preserved / ver_ad0e7f3e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 808. hyp_path_f0ebffd775b2

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_17.c:35
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者可能控制stdin输入，导致fread读取不完整或失败。
- 触发路径: fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_17.c:35
- 结论: CWE-252: 未检查fread返回值。调用fread后未检查其返回值，可能导致未读取到足够数据或读取失败，进而使用未初始化或部分填充的数据。
- D验证: stage_c_preserved / ver_17e762ed
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 809. hyp_path_f74088236676

- 漏洞位置: juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_18.c:34
- 漏洞类型: CWE-252
- CWE: CWE-252
- 风险等级: P1
- 触发条件: 攻击者能够通过stdin输入影响fread的读取结果，如提前结束输入或输入非预期数据。
- 触发路径: fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin); @ juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_18.c:34
- 结论: 调用fread未检查返回值，可能导致数据未完全读取或读取失败，后续代码使用未初始化或部分初始化的数据，违反CWE-252未检查返回值。
- D验证: stage_c_preserved / ver_09b0d199
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

## Unconfirmed / Failed Verification

These records are not reported as confirmed vulnerabilities. See `verification.failed.jsonl` for full failure details.

- hyp_path_867066a8a076 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_17.c:89 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_53d32bbd19bb | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_17.c:89 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_a070914d23ba | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_12.c:143 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_6e871b84679e | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_08.c:105 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_13ab4cdd94f5 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_11.c:92 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_e7c515521b0e | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_08.c:105 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_4517be48cb9c | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_05.c:98 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_8bf3c02a0048 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_08.c:138 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_cc787f95545d | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_09.c:92 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_641dd56f39c7 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_07.c:97 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_4a4c559c6649 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_10.c:92 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_43dddd21231c | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_11.c:125 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_fa05f1c9ec2a | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_13.c:92 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_671eb60a0884 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_07.c:97 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_e41a1552bec7 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_05.c:98 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_db3cf150f568 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_14.c:92 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_0666e93a1213 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_08.c:138 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_d365ca99fc75 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_09.c:92 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_6be5bcdb9e2e | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_11.c:125 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_18afb7a73581 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_13.c:92 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_518f3b2e68db | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_14.c:92 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_0158df384ec7 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_10.c:92 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_f71ee1fe63a4 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_01.c:81 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_fd85602a481d | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_02.c:92 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_000e2d912a34 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_03.c:92 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_9a523a38eb29 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_04.c:98 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_d9d436a89693 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_03.c:125 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_67a32d433d07 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_05.c:131 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_9caf7e0a854c | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_07.c:130 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_452b92cfb670 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_09.c:125 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_fb0f76b7d318 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_10.c:125 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_8e50150437d2 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_06.c:97 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_3ca66e347ceb | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_06.c:130 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_1f0f7fc56aa8 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_13.c:125 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_c6e5a5b99719 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_15.c:133 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_dd53df65ed46 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_18.c:86 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_9b5d0587b409 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_14.c:125 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_6cb0ba3ebae8 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_16.c:88 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_feb3fd9de3ca | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_02.c:92 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_0290d742a9a7 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_01.c:81 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_68db76710ef5 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_02.c:125 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_aa7a665e5fd7 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_03.c:125 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_0ce2f47ed91e | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_04.c:98 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_1fde2a04b95e | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_04.c:131 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_56ac85246b9b | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_06.c:97 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_7a6d2a5de337 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_06.c:130 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_8acf8dba59ed | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_09.c:125 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_60b802bbfeb4 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_05.c:131 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_9429047131b6 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_07.c:130 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_13a0e685802f | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_10.c:125 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_0afebb3a3325 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_14.c:125 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_2df65165045f | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_15.c:133 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_b7ac7266350a | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_13.c:125 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_07a95306a4bf | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_18.c:86 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_726337e7bff6 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_17.c:63 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_828e01063b5d | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fgets_15.c:97 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_c2a0d4e958d3 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_12.c:91 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_1de4ade22fb9 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_05.c:72 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_95b73d0a8269 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_08.c:99 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_7765d9eaf4d4 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_12.c:91 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_5284112fa8e4 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_05.c:72 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_302414f1bde4 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_13.c:66 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_564c48376e53 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_09.c:66 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_87838f95c138 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_10.c:66 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_8ae57c854e47 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_02.c:86 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_048c81e40286 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_03.c:66 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_e2cdeb13a01b | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_06.c:71 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_02c07708ed2f | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_14.c:86 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_cfb71e4fdb83 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_15.c:94 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_070480268344 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_09.c:86 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_ae8532a02a57 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_15.c:72 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_f2bc10a21081 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_15.c:94 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_7cb41390a36b | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_07.c:75 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_4fabcb7e2c8c | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_rename_15.c:63 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_51bca47d286a | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_17.c:45 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_1263265c7ee4 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_17.c:58 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_48e920c98082 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputc_12.c:51 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_166f851c4344 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_12.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_0afab8d1615c | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_12.c:57 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_8e13e629e2b9 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_08.c:61 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_f8594738ff1d | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fprintf_11.c:48 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_0fc57a7ccf15 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_12.c:34 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_102e2f7b77f0 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fputs_08.c:61 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_3471da252845 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_08.c:72 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_9d7719cebcb3 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_08.c:74 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_e85d4ce81182 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_11.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_3f807112adfd | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_11.c:61 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_7b11344f13e3 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_11.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_72b0885a53b4 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_putc_08.c:61 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_90d4a4e771de | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_08.c:91 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_c5c823d02af1 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_13.c:54 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_8c572ca6da38 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_08.c:99 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_0766317f1001 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_05.c:67 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_468c15f72566 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_10.c:61 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_66cbfbc3b04a | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_14.c:61 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_e56e717ce871 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_11.c:80 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_ca159841c416 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_09.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_7d232441fb99 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_14.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_2011efd5837f | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_remove_07.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_f83f51403ca7 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_08.c:91 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_d9ef25295b5c | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_11.c:78 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_63da5901c190 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_08.c:99 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_d863cbf7e5dc | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_08.c:93 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_352e56883f03 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_09.c:61 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_c8604a7ed948 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_01.c:48 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_dbb6d35de034 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_06.c:64 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_a035e8d97921 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_07.c:83 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_6bc9f211384f | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_putc_04.c:67 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_81363eb41644 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_15.c:75 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_f412c758d671 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_05.c:84 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_3987db2b5147 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_06.c:83 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_ea11eb86ac24 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_18.c:53 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_39f394ce64fc | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_03.c:61 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_6946cba15eaf | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_02.c:80 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_398b49a9a1e0 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_06.c:66 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_09a040f5a4e4 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_13.c:80 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_28750e5ee174 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fprintf_16.c:44 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_247a0d8f2f6c | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_03.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_014291bf969c | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fscanf_16.c:55 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_7988503b7ea0 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_03.c:67 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_26698f936e05 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_rename_02.c:70 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_06c331e414fc | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_01.c:56 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_7fa8d828af26 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_18.c:53 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_0fb71fa59b84 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_03.c:86 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_c145a5cd0de5 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_03.c:67 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_a08d8b4e1282 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_15.c:88 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_7c3eacff8c0b | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_10.c:48 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_90d03aa16588 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fwrite_05.c:54 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_47201ba918ad | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fwrite_03.c:71 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_8778dec20ebf | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fscanf_11.c:89 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_249e47c28952 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_02.c:88 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_40e7d54cf205 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_05.c:94 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_bf20271826c0 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_06.c:93 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_2d252bf9841c | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_snprintf_11.c:97 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_e8e9d74d6f4b | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_05.c:97 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_4f0e02b8b843 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_10.c:91 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_78ff3227e179 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_14.c:91 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_6526dd2a2a68 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_11.c:93 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_27484648fa38 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_02.c:133 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_3b46d51f2b8a | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_03.c:132 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_a32996b45326 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_05.c:139 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_2a54fbcd83ef | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_06.c:138 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_be807f824025 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_04.c:138 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_4c500c0aab7e | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_08.c:145 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_544d150972db | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_10.c:133 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_473c6e6b0fe4 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_07.c:137 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_1717e75c4485 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_11.c:133 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_48fc63195687 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_09.c:132 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_28cab86cb6fc | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_13.c:132 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_135c17c92a3c | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_14.c:132 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_5780386225ba | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_15.c:145 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_1f92d62d2071 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_puts_03.c:76 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_a1bfd800b009 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_scanf_15.c:101 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_562a8005f830 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_03.c:96 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_85e754c132b5 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_09.c:96 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_05073cda80d6 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_02.c:132 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_33b4a314e4f0 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_04.c:138 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_5efa74b5ad71 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_03.c:133 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_5e674824ef35 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_07.c:137 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_7affe3c5fa79 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_08.c:146 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_190694bafa34 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_10.c:133 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_1f08b9c03d4b | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_09.c:133 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_20fa83a77d3f | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_11.c:133 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_1a0a8f8ab227 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_13.c:132 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_433fc31f554b | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_14.c:133 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_5830ed69a91e | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_15.c:145 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_5495748d3291 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_puts_09.c:35 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_89e4e586ee2e | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_01.c:57 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_77d55decd44d | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_scanf_17.c:66 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_6f451ad4cbb3 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_sscanf_01.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_b2f60da6a49a | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateMutex_16.c:70 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_ed692c567ff8 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_01.c:87 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_8e0d02beed70 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_12.c:150 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_f0a7bdac2494 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_16.c:96 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_eb912db6aebf | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_17.c:96 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_e361b8c74961 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_18.c:92 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_86760f5195f4 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_snprintf_12.c:100 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_ce7967387a7c | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_07.c:41 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_c92c79a441e2 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_sscanf_13.c:36 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_a03216d2f37b | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_01.c:61 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_525052076a9e | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_01.c:87 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_47f5387d5581 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateMutex_12.c:98 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_bf27684f5039 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_12.c:150 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_7811cca3e823 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_16.c:96 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_fa2d3543c4cf | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_17.c:96 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_000abb664551 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/main.cpp:64 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_130b770aafe8 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_w32CreateNamedPipe_18.c:92 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_003a6320b76f | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/main_linux.cpp:1494 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_9c1ddc54101c | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_17.c:56 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_7d5b90c72a6c | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_11.c:78 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_00ec854d8480 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_03.c:78 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_789aab25a204 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_04.c:65 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_24d693c2fee3 | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__char_fread_14.c:78 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_6af528ead81a | juliet-api-misuse/testcases/CWE252_Unchecked_Return_Value/CWE252_Unchecked_Return_Value__wchar_t_fread_13.c:78 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
