# MAGUS Final Vulnerability Report

- generated_at: 2026-05-26T12:29:46Z
- reportable_vulnerabilities: 319
- d_confirmed_vulnerabilities: 319
- stage_c_preserved_vulnerabilities: 0
- failed_verifications: 384
- source_confirmed: /home/sq_hu/MAGUS/d/memberD_verifier/02_run_with_C/output/CWE426_Untrusted_Search_Path/verification.jsonl
- source_failed: /home/sq_hu/MAGUS/d/memberD_verifier/02_run_with_C/output/CWE426_Untrusted_Search_Path/verification.failed.jsonl

## Confirmed Vulnerabilities

### 1. hyp_path_4f897f0af361

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_41.c:47
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改目标系统的环境变量PATH，或控制当前工作目录以包含恶意程序
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_41.c:59; CWE426_Untrusted_Search_Path__char_system_41_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_41.c:60; if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_41.c:46-47
- 结论: 代码使用system()函数执行命令时，未指定可执行文件的完整路径，导致攻击者可能通过修改PATH环境变量执行恶意程序，构成CWE-426 Untrusted Search Path漏洞。
- D验证: confirmed / ver_83668cc4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 2. hyp_path_0cfc91febf24

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_21.c:65
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或写入可执行文件到搜索路径（如当前工作目录）
- 触发路径: strcpy(data, CASE0_OS_COMMAND); // data未指定完整路径 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_21.c:49; if (SYSTEM(data) <= 0) { // 调用system，无完整路径 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_21.c:65
- 结论: 函数system()调用时未指定可执行文件的完整路径，攻击者可通过控制PATH环境变量或在搜索路径中放置恶意程序来执行任意命令。
- D验证: confirmed / ver_7ff51640
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 3. hyp_path_6f0ab55522e6

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_42.c:58
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者需要能够修改系统环境变量（如PATH）或控制当前工作目录中的文件放置
- 触发路径: static char * case0Source(char * data) { strcpy(data, CASE0_OS_COMMAND); return data; } @ CWE426_Untrusted_Search_Path__char_system_42.c:43-48; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ CWE426_Untrusted_Search_Path__char_system_42.c:58
- 结论: 存在不受信任的搜索路径漏洞，system()函数调用未指定完整路径，可能允许攻击者通过搜索路径劫持执行恶意程序。
- D验证: confirmed / ver_f8949053
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 4. hyp_path_f64074dbdb1d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_22a.c:57
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够向程序提供未指定完整路径的可执行文件名，或者能够影响程序运行环境中的PATH变量
- 触发路径: data = CWE426_Untrusted_Search_Path__char_system_22_case0Source(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_22a.c:52; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_22a.c:57
- 结论: 程序在调用system()函数时，使用了未指定完整路径的可执行文件名，攻击者可通过修改PATH环境变量或放置恶意同名可执行文件来执行任意命令，存在未受信任搜索路径漏洞。
- D验证: confirmed / ver_c1035047
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 5. hyp_path_2ccc5de2e503

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_61a.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制 CWE426_Untrusted_Search_Path__char_system_61b_case0Source 的返回值（通常从外部输入获取），并能够将恶意程序放置在系统搜索路径中。
- 触发路径: char dataBuffer[100] = ""; data = dataBuffer; data = CWE426_Untrusted_Search_Path__char_system_61b_case0Source(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_61a.c:49-53; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_61a.c:54
- 结论: 在调用 system() 函数时，使用了来自不可信源的数据作为命令，且未指定可执行文件的完整路径，攻击者可以通过将恶意程序放置在搜索路径中来执行任意命令，构成不可信搜索路径漏洞。
- D验证: confirmed / ver_bde82c0a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 6. hyp_path_4cebf6821bf8

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_62a.cpp:57
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够通过case0Source控制data参数的内容（假设case0Source从外部输入读取），或能够影响系统PATH环境变量。; 攻击者可在PATH路径中放置与data参数同名的恶意可执行文件。
- 触发路径: char dataBuffer[100] = ""; data = dataBuffer; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_62a.cpp:52; case0Source(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_62a.cpp:53; if (SYSTEM(data) <= 0) { ... } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_62a.cpp:55
- 结论: 代码在使用system()函数时未指定可执行文件的完整路径，依赖系统PATH环境变量搜索，攻击者可通过控制PATH或放置恶意程序导致任意代码执行。但外部输入源case0Source的实现未提供，无法完全确认data参数确实来自外部可控来源。
- D验证: confirmed / ver_c1b560e3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 7. hyp_path_c14f48f73f2a

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_43.cpp:60
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统环境变量或文件系统以影响可执行文件搜索路径。
- 触发路径: static void case0Source(char * &data) { strcpy(data, CASE0_OS_COMMAND); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_43.cpp:49-50; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_43.cpp:58-60
- 结论: 程序使用未指定完整路径的系统命令调用 system()，攻击者可通过控制搜索路径执行任意程序，构成不可信搜索路径漏洞（CWE-426）。
- D验证: confirmed / ver_96e008b6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 8. hyp_path_f8287fb46851

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_12.c:60
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改 PATH 环境变量或文件系统，使得恶意可执行文件被优先执行
- 触发路径: if(globalReturnsTrueOrFalse()) { /* NOTE: the full path is not specified */ strcpy(data, CASE0_OS_COMMAND); } @ 47-53; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); ... } @ 58-62
- 结论: 函数 system() 被调用时使用了未指定完整路径的命令字符串（CASE0_OS_COMMAND），攻击者可以通过操纵 PATH 环境变量或文件系统来替换可执行文件，导致任意代码执行。
- D验证: confirmed / ver_57e1fa01
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 9. hyp_path_b735dab356d5

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_08.c:69
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量 PATH 或能够在文件系统中放置与命令同名的恶意可执行文件，并确保该路径在搜索顺序中优先于预期路径。
- 触发路径: char dataBuffer[100] = ""; data = dataBuffer; if(staticReturnsTrue()) { /* NOTE: the full path is not specified */ @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_08.c:60-64; { /* NOTE: the full path is not specified */ strcpy(data, CASE0_OS_COMMAND); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_08.c:63-67; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_08.c:69
- 结论: 代码中调用了 system() 函数执行命令，但没有指定可执行文件的完整路径，攻击者可以通过修改 PATH 环境变量或放置恶意程序在搜索路径中来劫持命令执行，导致任意代码执行。
- D验证: confirmed / ver_4ca84ac2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 10. hyp_path_13694e3973a7

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_11.c:55
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统的PATH环境变量，或在当前工作目录中放置一个与CASE0_OS_COMMAND同名的恶意可执行文件，且该目录在搜索路径中优先于其他目录。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_11.c:49; if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_11.c:55
- 结论: 调用system()函数时不指定可执行文件的完整路径，允许攻击者通过修改PATH环境变量或当前目录放置恶意程序，构成CWE-426未受信任的搜索路径漏洞。
- D验证: confirmed / ver_4beafba7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 11. hyp_path_4e46e9a43f35

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_01.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够将恶意程序写入系统搜索路径中的某个目录（如当前工作目录或PATH中的可写目录）。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); /* NOTE: the full path is not specified */ @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_01.c:51; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_01.c:52
- 结论: 使用未指定完整路径的命令执行函数system()，可能被攻击者替换恶意程序，导致任意代码执行。
- D验证: confirmed / ver_d7d79b1a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 12. hyp_path_0a0fee8ee33c

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_02.c:55
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够设置PATH环境变量或控制当前工作目录包含恶意可执行文件。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_02.c:49-53; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_02.c:55
- 结论: 代码中调用了system()函数，且未指定可执行文件的完整路径，导致攻击者可以通过修改PATH环境变量或当前工作目录来劫持命令执行，构成不可信搜索路径漏洞。
- D验证: confirmed / ver_68eb5bf3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 13. hyp_path_17d262bb1b3c

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_03.c:55
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制 PATH 环境变量或放置恶意程序到当前工作目录或系统搜索路径的前导位置
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_03.c:49-53; if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_03.c:55
- 结论: 代码调用 system() 函数时使用了未指定完整路径的命令字符串 (CASE0_OS_COMMAND)，攻击者可通过修改 PATH 环境变量或在当前工作目录中放置恶意程序来劫持命令执行，导致任意命令执行。
- D验证: confirmed / ver_f9f0ad0d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 14. hyp_path_20795ed5b8c4

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_04.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统搜索路径，例如通过修改PATH环境变量或诱使用户从包含恶意程序的目录执行该程序
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_04.c:58; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_04.c:62
- 结论: 程序使用system()函数执行命令，但未指定完整路径，导致可能执行攻击者放置在搜索路径中的恶意程序。
- D验证: confirmed / ver_87178427
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 15. hyp_path_50ad7da28da7

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_05.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改进程的PATH环境变量或在该搜索路径下放置恶意可执行文件
- 触发路径: /* NOTE: the full path is not specified */ strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_05.c:56-60; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_05.c:62
- 结论: 程序使用system()函数执行命令，但未指定可执行文件的完整路径，导致攻击者可能通过控制PATH环境变量或放置恶意可执行文件来劫持命令执行。
- D验证: confirmed / ver_71054562
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 16. hyp_path_1f5531c4de8d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_06.c:59
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量（如 PATH）或在搜索路径中放置恶意文件
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_06.c:53-57; if (SYSTEM(data) <= 0) { ... } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_06.c:57-61
- 结论: 调用 system() 函数时未指定可执行文件的完整路径，导致不可信搜索路径漏洞。攻击者可能通过修改 PATH 环境变量或在与程序相同的搜索路径中放置恶意程序来劫持命令执行。
- D验证: confirmed / ver_ab96d860
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 17. hyp_path_3011e9303fcb

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_07.c:61
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或放置恶意可执行文件到搜索路径中。虽然CASE0_OS_COMMAND是常量，但PATH攻击仍成立。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ CWE426_Untrusted_Search_Path__char_system_07.c:59; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); } @ CWE426_Untrusted_Search_Path__char_system_07.c:61
- 结论: 程序使用system()函数执行命令，但未指定可执行文件的完整路径，导致不受信任的搜索路径漏洞（CWE-426）。攻击者可通过修改PATH环境变量或放置恶意同名的可执行文件到搜索路径中，从而执行任意命令。
- D验证: confirmed / ver_3a859544
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 18. hyp_path_45af8943ba41

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_09.c:55
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统PATH环境变量或通过其他方式控制命令搜索路径; 攻击者能够在搜索路径中放置恶意同名可执行文件
- 触发路径: strcpy(data, CASE0_OS_COMMAND); /* 未指定完整路径 */ @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_09.c:49-53; if (SYSTEM(data) <= 0) { /* 执行命令，搜索路径不可信 */} @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_09.c:55
- 结论: 代码使用system()执行命令时未指定完整路径，导致不可信搜索路径漏洞，攻击者可通过控制PATH或放置恶意同名可执行文件劫持命令执行。
- D验证: confirmed / ver_af6cff1e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 19. hyp_path_59802d0aa95e

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_10.c:55
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制程序运行时的搜索路径（如通过修改环境变量或放置恶意文件到搜索路径目录）。
- 触发路径: { /* NOTE: the full path is not specified */ strcpy(data, CASE0_OS_COMMAND); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_10.c:49-53; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_10.c:53-57
- 结论: 调用 system() 时未指定可执行文件的完整路径，导致攻击者可以通过操纵搜索路径（如修改 PATH 环境变量或放置同名的恶意可执行文件）来执行任意代码。
- D验证: confirmed / ver_b67ac6c3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 20. hyp_path_b7247ed9d967

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_13.c:55
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统搜索路径（例如通过环境变量 PATH）或在其可写目录中放置同名恶意可执行文件。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ 49-53; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ 55
- 结论: 调用 system() 函数时未指定可执行文件的完整路径，允许攻击者通过控制搜索路径执行恶意程序，违反 CWE-426（不可信搜索路径）。
- D验证: confirmed / ver_9e41e85b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 21. hyp_path_fa97e6e2450e

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_14.c:55
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统 PATH 环境变量或能够将恶意可执行文件放置在搜索路径中的某个目录下。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_14.c:49-53; if (SYSTEM(data) <= 0) {...} @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_14.c:55
- 结论: 在调用 system() 函数时未指定可执行文件的完整路径，仅使用命令名，攻击者可通过操纵系统 PATH 环境变量或替换系统命令的方式导致执行恶意程序，构成不可信搜索路径漏洞。
- D验证: confirmed / ver_1e6068d1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 22. hyp_path_37235bde53c3

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_15.c:61
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或在搜索路径中放置同名恶意程序。
- 触发路径: case 6: strcpy(data, CASE0_OS_COMMAND); break; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_15.c:50-54; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_15.c:59-63
- 结论: 系统调用未指定完整路径，符合CWE-426 Untrusted Search Path，攻击者可利用PATH环境变量替换执行恶意程序。
- D验证: confirmed / ver_e6ea3bbe
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 23. hyp_path_f6f1b9dca335

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_16.c:56
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改环境变量PATH或者能够在系统搜索路径中植入恶意可执行文件
- 触发路径: strcpy(data, CASE0_OS_COMMAND); break; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_16.c:49-53; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_16.c:56
- 结论: 程序使用system()执行命令时未指定可执行文件的完整路径，攻击者可以通过修改PATH环境变量或在搜索路径中放置恶意程序来劫持执行，导致任意命令执行。
- D验证: confirmed / ver_bfb7f940
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 24. hyp_path_dc59bdf413f4

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_17.c:56
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统环境变量PATH或在当前工作目录或PATH包含的目录中放置恶意可执行文件
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_17.c:50; SYSTEM(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_17.c:56
- 结论: 代码使用system()函数执行命令但未指定完整路径，导致搜索路径不可信，攻击者可通过修改PATH或放置恶意程序执行任意命令。
- D验证: confirmed / ver_50e16482
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 25. hyp_path_505dacd13779

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_18.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统环境变量PATH，或通过其他方式控制可执行文件的搜索路径
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_18.c:49; if (SYSTEM(data) <= 0) { @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_18.c:54
- 结论: 调用system()函数时未指定可执行文件的完整路径，导致攻击者可能通过修改PATH环境变量执行恶意程序，存在不可信搜索路径漏洞。
- D验证: confirmed / ver_9cfb37d8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 26. hyp_path_c2a3df040a2e

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_31.c:55
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响搜索路径（如通过环境变量或文件系统）。
- 触发路径: data = dataBuffer; /* NOTE: the full path is not specified */ strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_31.c:47-49; if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_31.c:55
- 结论: 代码使用system()函数且未指定可执行文件的完整路径，依赖系统搜索路径，攻击者可能通过修改PATH环境变量或放置恶意程序在搜索路径中执行任意命令。
- D验证: confirmed / ver_8ba9bf9b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 27. hyp_path_360bcae71d45

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_33.cpp:58
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统环境变量（如PATH）或控制文件系统目录权限以放置恶意程序。
- 触发路径: data = dataBuffer; /* NOTE: the full path is not specified */ strcpy(data, CASE0_OS_COMMAND); @ L51-L55; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ L58
- 结论: 发现CWE-426不可信搜索路径漏洞：调用system()时未指定可执行文件的完整路径，允许攻击者通过操纵搜索路径（如修改PATH环境变量）或放置同名恶意程序来劫持命令执行。
- D验证: confirmed / ver_9313a93d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 28. hyp_path_95bd107c52ee

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_72b.cpp:55
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制dataVector中的字符串，或者能够影响环境变量PATH
- 触发路径: char * data = dataVector[2]; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_72b.cpp:53; if (SYSTEM(data) <= 0) { ... } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_72b.cpp:55
- 结论: 通过system()函数执行命令时未指定完整路径，导致不可信搜索路径漏洞。攻击者可能通过控制dataVector[2]中的字符串或修改PATH环境变量来执行任意程序。
- D验证: confirmed / ver_cac0f591
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 29. hyp_path_937189b7cd30

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_34.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统PATH环境变量，或将恶意可执行文件放置在搜索路径中的目录（如当前工作目录）。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); myUnion.unionFirst = data; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_34.c:54-58; SYSTEM(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_34.c:62
- 结论: 程序使用system()函数执行命令时未指定可执行文件的完整路径，命令字符串虽来自常量CASE0_OS_COMMAND，但攻击者仍可通过修改系统PATH环境变量或放置同名恶意可执行文件于搜索路径中，劫持该命令执行，构成不受信任的搜索路径漏洞。
- D验证: confirmed / ver_d7f4c419
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 30. hyp_path_f5fccecb726e

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_73b.cpp:55
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响dataList中的数据（例如通过外部输入、环境变量或文件内容），从而构造恶意的命令字符串。; 攻击者能够修改系统搜索路径（例如PATH环境变量）或能够在当前工作目录放置恶意可执行文件，使得system()加载攻击者控制的程序。
- 触发路径: char * data = dataList.back(); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_73b.cpp:50; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_73b.cpp:55
- 结论: 程序使用system()函数执行命令，但未指定可执行文件的完整路径，导致攻击者可以通过控制环境变量或当前目录来替换可执行文件，从而执行任意命令。
- D验证: confirmed / ver_3bed9f87
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 31. hyp_path_3ce9fc1cb24c

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_74b.cpp:55
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制 dataMap 中的 data 值（例如通过输入注入或环境变量），或能够修改系统 PATH 环境变量/放置恶意可执行文件。
- 触发路径: char * data = dataMap[2]; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_74b.cpp:50; if (SYSTEM(data) <= 0) { ... } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_74b.cpp:55
- 结论: 程序调用 system() 函数时未指定可执行文件的完整路径，data 来源于外部传入的 dataMap（参数），攻击者可通过控制 dataMap 内容或系统 PATH 环境变量导致任意命令执行。
- D验证: confirmed / ver_493c328d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 32. hyp_path_5f35b1feace9

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_83_case0.cpp:40
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data参数的内容或修改PATH环境变量。
- 触发路径: SYSTEM(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_83_case0.cpp:40
- 结论: 程序调用system()时未使用完整路径，导致不可信搜索路径漏洞，攻击者可通过修改PATH环境变量执行恶意程序。但data的来源未在代码中明确展示，需进一步确认外部可控性。
- D验证: confirmed / ver_22f4f678
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 33. hyp_path_9e87e5a9d570

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_32.c:60
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能影响系统环境变量（如PATH）或文件系统（在搜索路径中放置同名的恶意可执行文件）
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_32.c:53; if (SYSTEM(data) <= 0) { ... } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_32.c:60
- 结论: 在CWE426_Untrusted_Search_Path__char_system_32.c中，使用system()函数执行命令时未指定完整路径（仅使用CASE0_OS_COMMAND），攻击者可以通过修改PATH环境变量或在搜索路径中放置恶意同名程序实现任意命令执行。
- D验证: confirmed / ver_8b7db75b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 34. hyp_path_c90547f05662

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_84_case0.cpp:40
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统搜索路径（例如通过设置 PATH 环境变量）或将恶意可执行文件放在搜索路径中的可写目录。
- 触发路径: if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_84_case0.cpp:40
- 结论: 使用 system() 函数时未指定可执行文件的完整路径，攻击者可以通过操纵系统搜索路径（如 PATH 环境变量）来执行恶意程序。
- D验证: confirmed / ver_823dd953
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 35. hyp_path_9060f1518dea

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_41.c:47
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统的PATH环境变量或当前工作目录以放置恶意可执行文件; 目标程序调用了system()且参数未指定完整路径
- 触发路径: if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ CWE426_Untrusted_Search_Path__char_system_41.c:47
- 结论: 在调用system()函数时未指定可执行文件的完整路径，允许攻击者通过修改PATH环境变量来劫持命令执行。虽然传入参数data的来源在提供的代码片段中不明确，但CWE-426漏洞的核心在于未使用完整路径，且注释确认了此风险。
- D验证: confirmed / ver_8f13385e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 36. hyp_path_82a4d8a97994

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_44.c:47
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data变量的内容（通过外部输入如argv或环境变量），并在系统搜索路径中放置同名恶意程序。
- 触发路径: if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_44.c:47
- 结论: 存在不可信搜索路径漏洞：调用SYSTEM(data)时未指定完整路径，攻击者可将恶意程序放置在搜索路径中导致任意命令执行。但data的来源未在提供的代码片段中明确，假设data来自外部输入（如argv或环境变量），符合典型CWE-426测试用例设置。
- D验证: confirmed / ver_8ace5c69
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 37. hyp_path_2d4e0cfe353e

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_45.c:51
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制搜索路径（如PATH环境变量）或放置恶意可执行文件于搜索路径中; data参数未包含完整路径，仅指定可执行文件名
- 触发路径: if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_45.c:51
- 结论: 调用system()时未指定可执行文件的完整路径，攻击者可通过控制搜索路径（如修改PATH环境变量或放置恶意程序在搜索路径中）导致执行任意命令。
- D验证: confirmed / ver_e1f49175
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 38. hyp_path_a1ac78ef3975

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_51b.c:49
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量PATH或能够在搜索路径内放置恶意可执行文件；data参数未使用完整路径（需外部验证）
- 触发路径: if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_51b.c:49
- 结论: 代码使用system()函数执行命令，未指定可执行文件完整路径，存在CWE-426不可信搜索路径漏洞。虽然缺乏data参数来源的显式证据，但注释明确提示风险，且B阶段结构信号支持潜在攻击路径。
- D验证: confirmed / ver_b199cb83
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 39. hyp_path_742e8fe7937e

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_52c.c:49
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制 data 变量的内容; 攻击者能够修改 PATH 环境变量或当前目录以包含恶意可执行文件
- 触发路径: if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_52c.c:49
- 结论: 调用 system() 时未指定完整路径，攻击者可通过修改 PATH 环境变量或当前目录劫持执行恶意程序，导致未授权命令执行。
- D验证: confirmed / ver_dc1c41dc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 40. hyp_path_7c82e7b03e15

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_53d.c:49
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制传递给system()的字符串data; 攻击者能够在搜索路径中放置恶意可执行文件
- 触发路径: /* NOTE: Executing the system() function without specifying the full path to the executable */ @ 45; if (SYSTEM(data) <= 0) { @ 49
- 结论: 代码调用system()函数但未指定可执行文件的完整路径，允许攻击者通过修改PATH环境变量或当前目录来劫持执行恶意程序，违反CWE426。但缺乏data可控性的直接证据，需进一步验证data是否来自攻击者控制的输入。
- D验证: confirmed / ver_c6fc3775
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 41. hyp_path_f1ef0263986d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_54e.c:49
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data变量（如通过外部输入或环境变量）或修改系统搜索路径（如PATH环境变量）
- 触发路径: if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_54e.c:49
- 结论: 调用system()函数时未指定可执行文件的完整路径，存在CWE-426不可信搜索路径漏洞，攻击者可能通过控制搜索路径执行恶意程序。
- D验证: confirmed / ver_c68379fb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 42. hyp_path_576608202cd2

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_63b.c:48
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data参数的内容或影响程序的环境变量
- 触发路径: if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ CWE426_Untrusted_Search_Path__char_system_63b.c:48
- 结论: 程序使用system()函数执行命令时未指定可执行文件的完整路径，导致攻击者可以通过控制PATH环境变量或放置同名恶意程序来执行任意代码。
- D验证: confirmed / ver_ca58dc60
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 43. hyp_path_b61858f557a4

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_65b.c:47
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改环境变量PATH或能够写入某个目录并使其优先级高于原路径
- 触发路径: if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_65b.c:47
- 结论: 程序使用system()函数执行命令，但未指定可执行文件的完整路径，导致攻击者可能通过修改搜索路径（如PATH环境变量）或放置同名恶意程序，执行任意命令。
- D验证: confirmed / ver_e9e4447f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 44. hyp_path_6f484587cc2d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_64b.c:51
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响data变量的值（例如通过命令行参数、环境变量或其他外部输入）; 攻击者能够在系统搜索路径中创建或控制一个与data同名的恶意可执行文件
- 触发路径: if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_64b.c:51
- 结论: system()调用未指定可执行文件的完整路径，且参数data可能来自不可信源（如命令行参数或环境变量），攻击者可通过控制搜索路径或创建同名恶意程序执行任意命令。尽管data的来源在提供的代码片段中未显式确认，但注释暗示了不可信性，且CWE-426测试用例通常涉及外部输入。
- D验证: confirmed / ver_f43bbb47
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 45. hyp_path_049dc3ba9177

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_67b.c:53
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制 data 参数的内容或环境变量 PATH，使得 system() 执行恶意程序。
- 触发路径: if (SYSTEM(data) <= 0) { @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_67b.c:53
- 结论: 调用 system() 函数时未指定可执行文件的完整路径，允许攻击者通过修改搜索路径或放置同名恶意程序来执行任意命令，构成不受信任搜索路径漏洞。
- D验证: confirmed / ver_0aea4b90
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 46. hyp_path_d4900a7ca111

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_66b.c:49
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响'data'的值（例如通过环境变量、命令行或其他不可信输入）。
- 触发路径: if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_66b.c:49
- 结论: 程序使用未指定完整路径的SYSTEM()调用，允许攻击者通过控制'data'参数执行任意命令。
- D验证: confirmed / ver_99d11b61
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 47. hyp_path_db5b6264f838

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_68b.c:53
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够提供或影响data参数的值，使得data指向一个恶意可执行文件路径
- 触发路径: if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_68b.c:53
- 结论: 在system()调用中使用了不受信任的搜索路径，攻击者可以通过控制可执行文件路径来运行恶意程序，导致代码执行或权限提升。
- D验证: confirmed / ver_45b7aeba
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 48. hyp_path_7d40c58e0ae4

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_81_case0.cpp:34
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或当前工作目录，使得恶意程序被优先搜索和执行。
- 触发路径: if (SYSTEM(data) <= 0) { printLine("command execution failed!"); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_81_case0.cpp:34
- 结论: 代码使用system()函数执行命令，但未指定可执行文件的完整路径，攻击者可以通过操纵PATH环境变量或当前工作目录，使得恶意程序被优先搜索并执行，从而导致任意代码执行。即使data为固定字符串，PATH劫持仍可导致恶意程序替代原定程序执行。
- D验证: confirmed / ver_57787ecd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 49. hyp_path_4ab5573eab58

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_82_case0.cpp:34
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响搜索路径或放置恶意可执行文件到搜索路径中。; data参数可能来自外部输入（如环境变量或命令行参数），攻击者可控制其值指向任意程序名。
- 触发路径: if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_82_case0.cpp:34
- 结论: system函数调用未指定完整路径，攻击者可能利用不可信的搜索路径执行恶意程序。
- D验证: confirmed / ver_40c187cd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 50. hyp_path_7ecfe423b61b

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_72a.cpp:111
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统路径环境变量（如PATH）或在搜索路径中放置恶意同名可执行文件
- 触发路径: data = dataBuffer; strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_72a.cpp:51-55; dataVector.insert(dataVector.end(), 1, data); case0Sink(dataVector); @ 同一文件:57-61; popen(data, ...) 使用未指定完整路径的命令 @ case0Sink函数内部（预期调用popen）
- 结论: 程序在调用popen时未指定命令的完整路径，使用了搜索路径，可能被攻击者利用恶意可执行文件替换系统命令，导致任意代码执行。
- D验证: confirmed / ver_4526be15
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 51. hyp_path_f6d15239d40a

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_72a.cpp:111
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够在目标系统上放置名为 CASE0_OS_COMMAND（如 "cmd.exe" 或 "ls"）的恶意可执行文件，并使其被当前工作目录或 PATH 环境变量优先搜索到。
- 触发路径: data = dataBuffer; strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_72a.cpp:46; dataVector.insert(dataVector.end(), 1, data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_72a.cpp:51-55; case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_72a.cpp:57-61
- 结论: CWE426 Untrusted Search Path 漏洞：代码中使用未指定完整路径的命令字符串（CASE0_OS_COMMAND）通过 vector 传递给 case0Sink 函数（该函数可能调用 system() 等执行外部命令的 API），攻击者若能在当前工作目录或 PATH 中放置同名恶意可执行文件，可劫持执行。尽管命令为编译时常量，但路径搜索漏洞仍然存在。
- D验证: confirmed / ver_2efaa661
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 52. hyp_path_8088416ee012

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_72a.cpp:111
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改目标进程的PATH环境变量（例如通过父进程或其他漏洞）; 目标系统上存在攻击者控制的恶意可执行文件; CASE0_OS_COMMAND为相对路径或简单命令名（如'cmd.exe'），而非绝对路径
- 触发路径: data = dataBuffer; wcscpy(data, CASE0_OS_COMMAND); dataVector.insert(dataVector.end(), 1, data); @ CWE426_Untrusted_Search_Path__wchar_t_popen_72a.cpp:51-55; case0Sink(dataVector); @ CWE426_Untrusted_Search_Path__wchar_t_popen_72a.cpp:57-61
- 结论: 程序使用相对路径或简单命令调用popen（或类似函数），未指定完整路径，攻击者可通过修改PATH环境变量劫持执行恶意命令，导致CWE-426不可信搜索路径漏洞。尽管case0Sink具体实现未直接提供，但基于测试用例命名（含popen）、注释“full path not specified”以及Juliet套件的标准模式，可合理推断sink函数依赖路径搜索。CASE0_OS_COMMAND为相对路径（如'cmd.exe'），攻击者可控PATH时即可利用。
- D验证: confirmed / ver_ba0f53a6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 53. hyp_path_6f075f668a63

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_72a.cpp:111
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量，或将恶意可执行文件放置在搜索路径中的目录下
- 触发路径: data = dataBuffer; wcscpy(data, CASE0_OS_COMMAND); dataVector.insert(dataVector.end(), 1, data); @ CWE426_Untrusted_Search_Path__wchar_t_system_72a.cpp:51-55; dataVector.insert(dataVector.end(), 1, data); case0Sink(dataVector); @ CWE426_Untrusted_Search_Path__wchar_t_system_72a.cpp:57-61
- 结论: 存在不可信搜索路径漏洞（CWE-426）。代码中dataBuffer是局部数组，data指向它，并通过wcscpy复制命令字符串（未指定完整路径），随后将data插入向量并传递给case0Sink（可能调用system）。由于未指定完整路径，攻击者可通过修改PATH环境变量劫持命令执行。
- D验证: confirmed / ver_dea3f034
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 54. hyp_path_6cd9e5f2bccc

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_74a.cpp:464
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: Attacker can control the PATH environment variable of the process.
- 触发路径: data = dataBuffer; strcpy(data, CASE0_OS_COMMAND); @ CWE426_Untrusted_Search_Path__char_system_74a.cpp:46; dataMap[0] = data; dataMap[1] = data; dataMap[2] = data; @ CWE426_Untrusted_Search_Path__char_system_74a.cpp:51-55; case0Sink(dataMap); @ CWE426_Untrusted_Search_Path__char_system_74a.cpp:57-61
- 结论: Untrusted search path vulnerability: the program copies a command string (CASE0_OS_COMMAND) to a buffer using strcpy without specifying a full path, then passes it to case0Sink (likely executes via system), allowing an attacker who controls PATH to execute arbitrary commands.
- D验证: confirmed / ver_de840015
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 55. hyp_path_a7ee6e4690fe

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_74a.cpp:464
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够设置或影响系统/进程PATH环境变量；CASE0_OS_COMMAND定义为非绝对路径命令（如"cmd.exe"或"calc.exe"）；case0Sink实现调用popen/system等危险函数执行命令
- 触发路径: data = dataBuffer; /* NOTE: the full path is not specified */ strcpy(data, CASE0_OS_COMMAND); dataMap[0] = data; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_74a.cpp:51-55; dataMap[2] = data; case0Sink(dataMap); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_74a.cpp:57-61
- 结论: 代码中使用固定字符串构造命令，但未指定完整路径，可能受系统PATH环境变量影响，若攻击者可修改PATH，则可能导致执行恶意程序，违反CWE-426不可信搜索路径。尽管B阶段证据不闭合（sink函数未直接展示，但基于测试用例上下文，case0Sink预期调用popen或类似函数执行命令，且CASE0_OS_COMMAND为非绝对路径命令），漏洞假设仍成立。
- D验证: confirmed / ver_3e93a229
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 56. hyp_path_0d241c1eae36

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_74a.cpp:464
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响PATH环境变量或当前目录，或存在可写目录下的同名恶意程序
- 触发路径: wchar_t dataBuffer[100] = L""; data = dataBuffer; wcscpy(data, CASE0_OS_COMMAND); @ CWE426_Untrusted_Search_Path__wchar_t_popen_74a.cpp:46; data = dataBuffer; /* NOTE: the full path is not specified */ wcscpy(data, CASE0_OS_COMMAND); dataMap[0] = data; @ CWE426_Untrusted_Search_Path__wchar_t_popen_74a.cpp:51-55; dataMap[2] = data; case0Sink(dataMap); @ CWE426_Untrusted_Search_Path__wchar_t_popen_74a.cpp:57-61; popen执行data中的命令，使用搜索路径 @ _popen (implied)
- 结论: 程序使用未指定完整路径的命令字符串调用popen，攻击者可能通过控制PATH环境变量或当前目录来劫持命令执行，导致任意命令执行。
- D验证: confirmed / ver_8c4a79d9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 57. hyp_path_facfce354a11

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_74a.cpp:464
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量 PATH 或当前工作目录，从而影响系统搜索可执行文件的路径。
- 触发路径: data = dataBuffer; wcscpy(data, CASE0_OS_COMMAND); dataMap[0] = data; @ CWE426_Untrusted_Search_Path__wchar_t_system_74a.cpp:51-55; dataMap[2] = data; case0Sink(dataMap); @ CWE426_Untrusted_Search_Path__wchar_t_system_74a.cpp:57-61; 假设 case0Sink 调用 _wsystem(data) 执行命令 @ sink 函数内部
- 结论: 程序使用不可信搜索路径执行系统命令。通过 wcscpy 将命令字符串复制到缓冲区，但未指定完整路径，随后传递给 system 函数（通过 case0Sink），导致系统根据 PATH 环境变量搜索可执行文件。攻击者若能够控制 PATH 或修改当前目录下的同名文件，可执行任意命令。
- D验证: confirmed / ver_bf383061
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 58. hyp_path_bae849c50926

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_73a.cpp:443
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统的 PATH 环境变量，或控制当前工作目录，或系统中存在与命令同名的恶意程序位于搜索路径中。
- 触发路径: data = dataBuffer; strcpy(data, CASE0_OS_COMMAND); dataList.push_back(data); @ CWE426_Untrusted_Search_Path__char_popen_73a.cpp:51-55; case0Sink(dataList); // 内部使用 popen 执行 data @ CWE426_Untrusted_Search_Path__char_popen_73a.cpp:57-61 或 case0Sink 内部
- 结论: 在 case0Sink 中，命令字符串（CASE0_OS_COMMAND）未指定绝对路径，系统会依赖 PATH 环境变量搜索可执行文件。攻击者若能修改 PATH 或控制当前工作目录，可使程序执行恶意程序，构成 CWE-426 未受信任搜索路径漏洞。
- D验证: confirmed / ver_85375968
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 59. hyp_path_229f90234276

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_73a.cpp:443
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响系统PATH环境变量，或在PATH包含的目录中写入文件。
- 触发路径: data = dataBuffer; /* NOTE: the full path is not specified */ strcpy(data, CASE0_OS_COMMAND); @ CWE426_Untrusted_Search_Path__char_system_73a.cpp:46; dataList.push_back(data); case0Sink(dataList); @ CWE426_Untrusted_Search_Path__char_system_73a.cpp:57-61
- 结论: 函数case0使用strcpy将常量命令字符串CASE0_OS_COMMAND复制到dataBuffer，但未指定完整路径，随后通过case0Sink执行该命令。由于依赖操作系统的搜索路径（PATH环境变量），攻击者可通过在路径中放置同名恶意程序实现命令劫持。
- D验证: confirmed / ver_ef412a5b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 60. hyp_path_92898cc90296

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_73a.cpp:443
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够通过修改系统搜索路径（如PATH环境变量）或放置同名恶意程序到搜索路径中的可写目录中。
- 触发路径: data = dataBuffer; wcscpy(data, CASE0_OS_COMMAND); dataList.push_back(data); @ CWE426_Untrusted_Search_Path__wchar_t_popen_73a.cpp:51-55; dataList.push_back(data); case0Sink(dataList); @ CWE426_Untrusted_Search_Path__wchar_t_popen_73a.cpp:57-61; popen(data, ...) // 假设使用popen执行未指定完整路径的命令 @ case0Sink函数内部
- 结论: CWE426漏洞：使用未指定完整路径的命令执行函数，可能被攻击者利用搜索路径劫持执行恶意程序。
- D验证: confirmed / ver_2332e077
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 61. hyp_path_431003f80a16

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_73a.cpp:443
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改运行环境中的 PATH 环境变量或控制当前工作目录，使系统在搜索命令时优先找到恶意程序。
- 触发路径: data = dataBuffer; /* NOTE: the full path is not specified */ wcscpy(data, CASE0_OS_COMMAND); /* Put data in a list */ dataList.push_back(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_73a.cpp:51-55; dataList.push_back(data); case0Sink(dataList); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_73a.cpp:57-61
- 结论: 在调用 system 函数之前未指定命令的完整路径，导致不可信搜索路径漏洞（CWE-426）。攻击者可能通过修改 PATH 环境变量等方式劫持命令执行。sink函数 case0Sink 根据路由名称和标签推断调用了 _wsystem，但代码证据未直接展示调用点。
- D验证: confirmed / ver_460d7dfe
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 62. hyp_path_fed7a9dae8a3

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_74b.cpp:55
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响 dataMap 中索引为 2 的元素的值，例如通过前序步骤中的输入或环境变量控制。该前提需进一步验证。
- 触发路径: wchar_t * data = dataMap[2]; @ CWE426_Untrusted_Search_Path__wchar_t_system_74b.cpp:50-52; if (SYSTEM(data) <= 0) @ CWE426_Untrusted_Search_Path__wchar_t_system_74b.cpp:55
- 结论: 函数 case0Sink 从 dataMap 中取出的 data 直接传递给 _wsystem() 函数，且未指定可执行文件的完整路径，构成不可信搜索路径漏洞（CWE-426）。虽然 dataMap 来源在现有代码片段中未明确显示为外部输入，但注释明确指出了该风险，且静态分析支持该 sink 为高风险。缺失 source 端证据导致漏洞路径不完整，但代码本身违反安全规范（未指定完整路径），因此保留漏洞假设，需动态验证 data 可控性。
- D验证: confirmed / ver_10ced67b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 63. hyp_path_af4375b1e45d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_74b.cpp:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制dataMap[2]的内容，从而影响data变量的值；典型地，dataMap从外部输入（如命令行参数）填充。
- 触发路径: pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_74b.cpp:62
- 结论: 函数popen()被调用时未指定可执行文件的完整路径，允许攻击者利用不受信任的搜索路径（如PATH环境变量）替换可执行文件，导致任意代码执行。
- D验证: confirmed / ver_b29071ea
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 64. hyp_path_b0be55bd5a0d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_74b.cpp:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制 dataMap 中的值（例如通过外部输入填充），或影响搜索路径（如修改 PATH 环境变量或放置同名恶意程序于当前目录）。
- 触发路径: wchar_t * data = dataMap[2]; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_74b.cpp:52; pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_74b.cpp:57
- 结论: 使用 wpopen 函数执行命令时未指定绝对路径，且 data 源自外部可控的 dataMap 参数，导致不可信搜索路径漏洞。
- D验证: confirmed / ver_d37e573c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 65. hyp_path_63436e6c3b22

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_41.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量使其包含恶意目录
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_41.c:54; CWE426_Untrusted_Search_Path__char_popen_41_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_41.c:64; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_41.c:50
- 结论: 函数使用popen()执行命令，但未指定完整路径，允许攻击者通过操纵PATH环境变量替换执行程序。尽管数据来源为常量宏，攻击者仍可在可控环境下修改PATH环境变量劫持命令执行。
- D验证: confirmed / ver_22ca610d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 66. hyp_path_363bc87e7c24

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_41.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响程序执行时的PATH环境变量或当前工作目录
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_41.c:54; pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_41.c:50
- 结论: 函数CWE426_Untrusted_Search_Path__wchar_t_popen_41_case0Sink中调用POPEN时，使用了未指定完整路径的命令，导致可能从非可信搜索路径加载恶意程序，违反CWE426。
- D验证: confirmed / ver_59aa5be3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 67. hyp_path_d81df2faf022

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_21.c:72
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统搜索路径（如PATH环境变量）或在搜索路径中放置同名恶意程序。
- 触发路径: static wchar_t * case0Source(wchar_t * data) { if(case0Static) { wcscpy(data, CASE0_OS_COMMAND); } return data; } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_21.c:48-56; pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_21.c:72
- 结论: 调用POPEN函数时未指定可执行文件的完整路径，攻击者可能通过操控搜索路径（如PATH环境变量）将恶意程序替换为预期程序，导致任意命令执行。
- D验证: confirmed / ver_2920c640
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 68. hyp_path_468dbd9dbac7

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_21.c:72
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统PATH环境变量或存在可写目录在PATH中
- 触发路径: data = dataBuffer; case0Static = 1; data = case0Source(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_21.c:62-66; static char * case0Source(char * data) { if(case0Static) { strcpy(data, CASE0_OS_COMMAND); } return data; } // CASE0_OS_COMMAND为常量 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_21.c:48-56; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_21.c:70
- 结论: 程序使用popen执行命令时未指定完整路径，依赖系统PATH环境变量，构成不可信搜索路径漏洞。尽管命令字符串来自常量，但攻击者仍可通过控制PATH环境变量来执行恶意程序。
- D验证: confirmed / ver_aec03491
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 69. hyp_path_6380a0c26f95

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_42.c:65
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改目标系统的环境变量或文件系统，使得搜索路径中包含恶意可执行文件。
- 触发路径: static char * case0Source(char * data) { strcpy(data, CASE0_OS_COMMAND); return data; } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_42.c:45-50; data = case0Source(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_42.c:59; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_42.c:62
- 结论: 调用popen()函数时未指定可执行文件的完整路径，可能导致攻击者利用搜索路径执行恶意程序（CWE-426）。
- D验证: confirmed / ver_9703b577
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 70. hyp_path_63ce41786bc5

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_42.c:65
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统的PATH环境变量，并在路径中放置与CASE0_OS_COMMAND同名的恶意可执行文件
- 触发路径: static wchar_t * case0Source(wchar_t * data) { wcscpy(data, CASE0_OS_COMMAND); return data; } // 未指定完整路径，命令为常量 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_42.c:45-50; pipe = POPEN(data, L"wb"); // 使用不完整路径执行命令 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_42.c:63-64
- 结论: 程序在执行命令时使用不受信任搜索路径，未指定完整路径，攻击者可通过修改系统PATH环境变量替换可执行文件执行恶意代码。尽管命令字符串为硬编码常量，但攻击者仍可在PATH中放置同名恶意程序。
- D验证: confirmed / ver_d3c7a143
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 71. hyp_path_4a1dd6f272ae

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_22a.c:64
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或控制当前工作目录，使得可执行文件搜索路径中包含恶意程序。
- 触发路径: data = dataBuffer; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_22a.c:54; data = CWE426_Untrusted_Search_Path__char_popen_22_case0Source(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_22a.c:56; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_22a.c:60
- 结论: 调用popen时使用了不受信任的搜索路径（未指定完整路径），攻击者可通过控制PATH环境变量或当前工作目录来执行恶意程序。
- D验证: confirmed / ver_6d36a63a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 72. hyp_path_073486720aee

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_61a.c:61
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data变量的内容（通过CWE426_Untrusted_Search_Path__char_popen_61b_case0Source函数，该函数可能从外部输入获取数据）; 攻击者能够在系统搜索路径（如PATH）中放置一个与data匹配的恶意可执行文件
- 触发路径: char dataBuffer[100] = ""; data = dataBuffer; data = CWE426_Untrusted_Search_Path__char_popen_61b_case0Source(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_61a.c:51-52; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_61a.c:59-60
- 结论: 代码使用popen()执行命令但未指定完整路径，攻击者可通过在搜索路径中放置恶意程序来执行任意命令，构成CWE-426不可信搜索路径漏洞。
- D验证: confirmed / ver_ab722b3a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 73. hyp_path_effde84c238d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_62a.cpp:64
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够将恶意可执行文件放置在系统搜索路径中（如当前目录或PATH中的目录）。
- 触发路径: char dataBuffer[100] = ""; data = dataBuffer; case0Source(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_62a.cpp:54-58; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_62a.cpp:62-63
- 结论: 调用popen时未指定可执行文件的完整路径，违反CWE-426安全编码要求，即使数据来源不明，但代码模式已显示不安全。
- D验证: confirmed / ver_09871327
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 74. hyp_path_9baf3575ef73

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_22a.c:64
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制CWE426_Untrusted_Search_Path__wchar_t_popen_22_case0Source函数的返回值（例如通过环境变量或用户输入）
- 触发路径: data = dataBuffer; CWE426_Untrusted_Search_Path__wchar_t_popen_22_case0Global = 1; data = CWE426_Untrusted_Search_Path__wchar_t_popen_22_case0Source(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_22a.c:54-58; pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_22a.c:62-64
- 结论: 函数使用不受信任的搜索路径调用popen，攻击者可能通过控制data参数执行恶意程序。
- D验证: confirmed / ver_1ba6509c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 75. hyp_path_16a047900ba7

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_61a.c:61
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够向source函数提供恶意输入，使data指向恶意可执行文件（如"malware.exe"）
- 触发路径: data = CWE426_Untrusted_Search_Path__wchar_t_popen_61b_case0Source(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_61a.c:53; pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_61a.c:61
- 结论: 调用_popen执行命令，但路径未指定完整路径，攻击者可利用搜索路径注入恶意程序。
- D验证: confirmed / ver_042e408b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 76. hyp_path_8a7e5e675a72

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_62a.cpp:64
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制case0Source的输入（例如通过环境变量或用户输入）——但case0Source实现未提供，此条件未证实; 系统PATH中包含攻击者可控的目录（或当前目录优先）
- 触发路径: wchar_t dataBuffer[100] = L""; data = dataBuffer; case0Source(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_62a.cpp:55; pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_62a.cpp:64
- 结论: 使用不可信搜索路径执行命令：popen函数调用时未指定可执行文件的完整路径，导致攻击者可能通过修改PATH环境变量或放置同名恶意程序来执行任意代码。但source端（case0Source）的具体实现未提供，无法确认data是否受外部控制，证据不完整。
- D验证: confirmed / ver_4a5a66f3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 77. hyp_path_dfb7ddcd0cbc

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_12.c:67
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量; 或能够在搜索路径中放置恶意可执行文件
- 触发路径: char dataBuffer[100] = ""; data = dataBuffer; if(globalReturnsTrueOrFalse()) { /* NOTE: the full path is not specified */ strcpy(data, CASE0_OS_COMMAND); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_12.c:48-52; /* NOTE: Executing the popen() function without specifying the full path... */ pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_12.c:62-66
- 结论: 当globalReturnsTrueOrFalse()返回真时，程序使用未指定完整路径的命令调用popen()，导致不可信搜索路径漏洞，攻击者可通过修改PATH环境变量或放置同名恶意程序执行任意代码。
- D验证: confirmed / ver_3b4ba86b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 78. hyp_path_42672f007151

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_12.c:67
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够通过某种方式修改操作系统PATH环境变量（例如通过其他漏洞或用户交互），使恶意可执行文件位于搜索路径中且优先级高于预期程序
- 触发路径: wchar_t dataBuffer[100] = L""; data = dataBuffer; if(globalReturnsTrueOrFalse()) { /* NOTE: the full path is not specified */ wcscpy(data, CASE0_OS_COMMAND); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_12.c:48-52; pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_12.c:62-66
- 结论: 在CWE426_Untrusted_Search_Path__wchar_t_popen_12.c中，当globalReturnsTrueOrFalse()返回真时，data被设置为CASE0_OS_COMMAND（未指定完整路径），随后传入popen()执行。由于popen()搜索系统路径，攻击者可通过修改PATH环境变量将恶意程序置于搜索路径中优先于预期程序，导致不可信搜索路径漏洞。
- D验证: confirmed / ver_64d02500
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 79. hyp_path_60bb5b705d98

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_43.cpp:67
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: The attacker can control the environment in which the program runs, specifically the PATH variable or file system placement, to substitute a malicious executable for the intended command.
- 触发路径: static void case0Source(wchar_t * &data) { wcscpy(data, CASE0_OS_COMMAND); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_43.cpp:48-52; pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_43.cpp:67
- 结论: The program uses popen() with a command that does not include a full path, allowing an attacker to execute arbitrary code by placing a malicious executable in the search path.
- D验证: confirmed / ver_e1499bfa
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 80. hyp_path_4f78cb761952

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_43.cpp:67
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统环境变量（如PATH）或文件系统，使得搜索路径中存在与CASE0_OS_COMMAND同名的恶意可执行文件
- 触发路径: char dataBuffer[100] = ""; data = dataBuffer; case0Source(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_43.cpp:57-61; static void case0Source(char * &data) { strcpy(data, CASE0_OS_COMMAND); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_43.cpp:48-52; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_43.cpp:62-66
- 结论: popen()调用未指定可执行文件的完整路径，虽然命令字符串来自于常量，但攻击者仍可通过修改系统搜索路径（如PATH环境变量）替换恶意可执行文件，属于CWE-426不可信搜索路径漏洞。可利用性受限于攻击者需具备修改搜索路径的能力，实际风险较低。
- D验证: confirmed / ver_cdee6ef6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 81. hyp_path_a78a5071492c

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_08.c:76
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够将恶意可执行文件放置在搜索路径中的某个目录（如当前目录或PATH中的目录），且该文件名与CASE0_OS_COMMAND指定的命令名相同。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_08.c:65; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_08.c:76
- 结论: 使用未指定完整路径的命令字符串调用popen函数，可能导致恶意可执行文件被搜索路径中的同名文件替换，从而执行任意代码。
- D验证: confirmed / ver_39e117fa
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 82. hyp_path_9eb343f81820

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_11.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改目标环境的PATH环境变量，或通过其他方式使系统优先搜索恶意路径。
- 触发路径: char dataBuffer[100] = ""; data = dataBuffer; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_11.c:49; if(globalReturnsTrue()) { /* NOTE: the full path is not specified */ strcpy(data, CASE0_OS_COMMAND); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_11.c:50-51; pipe = POPEN(data, "wb"); if (pipe != NULL) { @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_11.c:59-60
- 结论: 代码调用popen时未指定可执行文件的完整路径，存在CWE-426漏洞，但攻击者需能控制环境变量PATH才能利用。
- D验证: confirmed / ver_d6b54285
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 83. hyp_path_ba99dd24dae2

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_08.c:76
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: Attacker has ability to influence the search path (e.g., set PATH environment variable) or place a malicious executable with the same name as CASE0_OS_COMMAND in a directory that appears earlier in the search path.
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); // full path not specified @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_08.c:65-69; pipe = POPEN(data, L"wb"); // executes command via popen @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_08.c:71-75
- 结论: The program executes a command using popen without specifying a full path, relying on the system's search path. An attacker who can control the search path or place a malicious executable with the same name can achieve arbitrary command execution.
- D验证: confirmed / ver_71253f35
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 84. hyp_path_825fa9e15725

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_11.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者具有修改环境变量或文件系统的能力（如本地低权限用户或通过其他漏洞）
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ CWE426_Untrusted_Search_Path__wchar_t_popen_11.c:51; pipe = POPEN(data, L"wb"); @ CWE426_Untrusted_Search_Path__wchar_t_popen_11.c:59
- 结论: 程序使用popen执行命令时未指定完整路径，依赖系统搜索路径，攻击者可通过操纵PATH环境变量或放置同名恶意程序到搜索路径中执行任意代码。
- D验证: confirmed / ver_3e85ad3d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 85. hyp_path_49c03fc3889e

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_01.c:59
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量PATH
- 触发路径: data = dataBuffer; strcpy(data, CASE0_OS_COMMAND); @ CWE426_Untrusted_Search_Path__char_popen_01.c:49-53; pipe = POPEN(data, "wb"); @ CWE426_Untrusted_Search_Path__char_popen_01.c:54-57
- 结论: 调用popen执行命令时未指定完整路径，导致不可信搜索路径漏洞。攻击者可利用环境变量PATH劫持命令执行。
- D验证: confirmed / ver_ff477ae0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 86. hyp_path_7e7c64bea2a0

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_02.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统搜索路径（如设置PATH环境变量）或能够在当前搜索路径中先于预期程序放置同名恶意文件。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_02.c:51-55; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_02.c:57-61
- 结论: 使用不受信任的搜索路径执行命令，攻击者可能通过修改PATH环境变量或放置同名恶意程序来执行任意代码。
- D验证: confirmed / ver_3c782250
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 87. hyp_path_6561f294d41d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_03.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统PATH环境变量或在工作目录中放置恶意可执行文件
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_03.c:51-55; pipe = POPEN(data, "wb"); // 未指定完整路径 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_03.c:57-61
- 结论: 使用相对路径调用popen函数，未指定可执行文件的完整路径，攻击者可通过控制PATH环境变量或在工作目录中植入同名恶意程序执行任意命令。
- D验证: confirmed / ver_904a2635
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 88. hyp_path_6fcda442757b

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_04.c:69
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响系统的可执行文件搜索路径（如 PATH 环境变量）
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_04.c:62; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_04.c:69
- 结论: 代码使用固定字符串构建命令，并通过 popen() 执行，但未指定可执行文件的完整路径，依赖于系统搜索路径。攻击者可通过修改 PATH 环境变量或放置同名恶意程序，劫持命令执行，构成不受信任的搜索路径漏洞。
- D验证: confirmed / ver_f0fd646f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 89. hyp_path_cc99f8dc8f4f

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_06.c:66
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统PATH环境变量或影响可执行文件的搜索路径，使得同名的恶意程序优先于预期程序被执行。; 攻击者可以将恶意文件放置在搜索路径中的可写目录中，且该目录优先级高于预期程序的路径。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); // 未指定完整路径 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_06.c:55-59; pipe = POPEN(data, "wb"); // 使用未指定完整路径的命令 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_06.c:61-65
- 结论: 代码通过popen执行命令时未指定完整路径，可能允许攻击者通过操控系统搜索路径执行恶意程序，违反CWE-426（不受信任的搜索路径）。
- D验证: confirmed / ver_8468b448
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 90. hyp_path_b3a30245c87d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_05.c:69
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改搜索路径（如PATH环境变量）或在搜索路径中植入同名恶意程序。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_05.c:58-62; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_05.c:64-68
- 结论: 程序调用popen执行命令，但未指定可执行文件完整路径，违反CWE-426契约。虽然命令来自固定宏CASE0_OS_COMMAND，攻击者仍可通过影响搜索路径（如修改PATH环境变量或在路径中放置同名恶意程序）导致任意代码执行。
- D验证: confirmed / ver_d8d561e0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 91. hyp_path_c4cd713dce3e

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_07.c:68
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响系统的搜索路径（如修改PATH环境变量）或能够在搜索路径中放置同名恶意程序。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ CWE426_Untrusted_Search_Path__char_popen_07.c:57-61; pipe = POPEN(data, "wb"); @ CWE426_Untrusted_Search_Path__char_popen_07.c:63-67
- 结论: 函数使用popen执行命令，但未指定可执行文件的完整路径，导致可能从不可信搜索路径加载恶意程序，违反CWE-426 Untrusted Search Path。
- D验证: confirmed / ver_71e35721
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 92. hyp_path_f8fcf1d00b8b

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_10.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统环境变量PATH或当前工作目录，使得搜索路径中包含攻击者控制的目录。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); /* NOTE: the full path is not specified */ @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_10.c:51-55; pipe = POPEN(data, "wb"); /* Executing popen() without full path */ @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_10.c:57-61
- 结论: popen函数调用未指定完整路径，使用常量CASE0_OS_COMMAND，攻击者可通过修改PATH环境变量劫持执行恶意程序。
- D验证: confirmed / ver_789ef6d0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 93. hyp_path_89adcc1a2ac6

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_09.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够通过本地提权或环境变量注入修改PATH环境变量，使系统在搜索命令时优先找到恶意程序
- 触发路径: strcpy(data, CASE0_OS_COMMAND); // 固定常量，未指定完整路径 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_09.c:51-55; pipe = POPEN(data, "wb"); // 执行命令，依赖PATH搜索可执行文件 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_09.c:57-61
- 结论: CWE-426 Untrusted Search Path: 使用popen执行命令时未指定完整路径，命令字符串为固定常量，但攻击者可通过修改PATH环境变量替换执行的程序，导致任意命令执行。虽然source非外部输入，但代码违反了安全实践，在本地提权场景下可利用。
- D验证: confirmed / ver_3dfda226
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 94. hyp_path_24f284451177

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_13.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统的PATH环境变量或影响当前工作目录，使得相对路径命令被重定向到恶意可执行文件
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_13.c:53; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_13.c:59
- 结论: 在popen()调用中未指定可执行文件的完整路径，攻击者可能通过修改PATH环境变量或当前工作目录来执行恶意程序。
- D验证: confirmed / ver_8e947fa3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 95. hyp_path_e3204502aa60

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_14.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够向系统PATH环境变量中添加恶意路径，或在当前工作目录等搜索路径中植入恶意可执行文件，使得同名恶意程序被优先执行。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); // NOTE: the full path is not specified @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_14.c:51-55; pipe = POPEN(data, "wb"); // Executing popen() without full path @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_14.c:57-61
- 结论: 代码使用popen()执行命令时未指定完整路径，依赖环境变量搜索可执行文件，导致不可信搜索路径漏洞。攻击者可通过修改PATH环境变量或在搜索路径中放置恶意程序来劫持执行。
- D验证: confirmed / ver_bb8016da
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 96. hyp_path_0dea3d70626d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_15.c:68
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统搜索路径（如通过修改环境变量PATH）或将恶意可执行文件放入搜索路径中的目录。
- 触发路径: case 6: /* NOTE: the full path is not specified */ strcpy(data, CASE0_OS_COMMAND); break; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_15.c:54; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_15.c:63-64
- 结论: 在popen()调用中未指定可执行文件的完整路径，导致不可信搜索路径漏洞；虽然命令字符串是硬编码常量，但若攻击者能控制系统搜索路径（如通过环境变量PATH），仍可劫持执行恶意程序。
- D验证: confirmed / ver_d4891f08
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 97. hyp_path_7bf65c99d7d0

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_16.c:63
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或向搜索路径中植入恶意程序
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_16.c:51-55; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_16.c:58-62
- 结论: 程序使用popen函数执行命令时未指定可执行文件的完整路径，攻击者可通过修改系统PATH环境变量或放置恶意同名程序进行搜索路径劫持，导致任意代码执行。
- D验证: confirmed / ver_6954ea01
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 98. hyp_path_bbca1a614dc0

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_17.c:63
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响PATH环境变量，或程序运行在不受信任的环境中
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_17.c:52-56; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_17.c:58-62
- 结论: 程序使用popen执行命令，但未指定可执行文件的完整路径，攻击者可通过修改PATH环境变量替换可执行文件，导致任意代码执行。
- D验证: confirmed / ver_df9a0b82
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 99. hyp_path_d5bd94257973

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_18.c:61
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者需要能够影响系统的环境变量或文件系统，使得popen()调用的命令被替换为攻击者的程序
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_18.c:51; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_18.c:56
- 结论: 程序使用popen()函数执行命令，但未指定可执行文件的完整路径，攻击者可以通过修改PATH环境变量或放置恶意同名程序来劫持执行。
- D验证: confirmed / ver_9721d4f1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 100. hyp_path_c9356948fa37

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_31.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改进程的PATH环境变量
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ CWE426_Untrusted_Search_Path__char_popen_31.c:53; pipe = POPEN(data, "wb"); @ CWE426_Untrusted_Search_Path__char_popen_31.c:62
- 结论: 程序在调用popen执行命令时未指定完整路径，攻击者可能通过修改PATH环境变量注入恶意程序，构成CWE-426不可信搜索路径漏洞。
- D验证: confirmed / ver_cb9b02d4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 101. hyp_path_01d073800ad3

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_33.cpp:65
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或将恶意可执行文件放置在搜索路径中的某个目录下
- 触发路径: data = dataBuffer; strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_33.cpp:53-57; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_33.cpp:60-64
- 结论: 程序使用popen()函数执行命令时未指定可执行文件的完整路径，攻击者可通过控制PATH环境变量或放置恶意程序在搜索路径中，导致任意命令执行。
- D验证: confirmed / ver_5a00a993
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 102. hyp_path_9d3cc02bf4ad

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_01.c:59
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够写入或控制系统的搜索路径中的某个目录，或者当前工作目录可被攻击者写入。
- 触发路径: data = dataBuffer; wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_01.c:49-53; pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_01.c:54-58
- 结论: 程序调用popen函数时未指定可执行文件的完整路径，使用搜索路径加载命令，攻击者可通过放置同名恶意程序在搜索路径中实现任意代码执行。
- D验证: confirmed / ver_1a232448
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 103. hyp_path_eb3467127fe2

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_34.c:69
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统搜索路径（如PATH环境变量）或放置恶意可执行文件在搜索路径中
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ line 69; pipe = POPEN(data, "wb"); @ line 64
- 结论: 使用popen()时未指定可执行文件的完整路径，违反CWE-426。尽管命令字符串为常量，但攻击者若能够控制搜索路径（如修改PATH环境变量），仍可能加载恶意程序。当前代码未提供攻击者控制搜索路径的显式方式，可利用性低，需要动态验证。
- D验证: confirmed / ver_b784bbed
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 104. hyp_path_40d3abd24a9b

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_02.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或影响popen的搜索路径。
- 触发路径: /* NOTE: the full path is not specified */ wcscpy(data, CASE0_OS_COMMAND); @ CWE426_Untrusted_Search_Path__wchar_t_popen_02.c:51-55; pipe = POPEN(data, L"wb"); /* 未指定完整路径 */ @ CWE426_Untrusted_Search_Path__wchar_t_popen_02.c:57-61; if (pipe != NULL) { PCLOSE(pipe); } @ CWE426_Untrusted_Search_Path__wchar_t_popen_02.c:62-64
- 结论: 在调用popen时未指定可执行文件的完整路径，攻击者可通过修改PATH环境变量或在搜索路径中放置恶意同名程序来执行任意代码。
- D验证: confirmed / ver_80732f49
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 105. hyp_path_f4c0ccbba32d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_03.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统搜索路径（如PATH环境变量）或在搜索路径中放置恶意程序
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); // NOTE: the full path is not specified @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_03.c:51-55; pipe = POPEN(data, L"wb"); // NOTE: Executing the wpopen() function without specifying the full path @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_03.c:59
- 结论: 程序使用popen函数执行命令时未指定完整路径，仅使用命令名（CASE0_OS_COMMAND），攻击者可通过修改PATH环境变量或放置恶意同名程序到搜索路径中，导致任意代码执行。
- D验证: confirmed / ver_3a62cae4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 106. hyp_path_0323c379dbd0

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_04.c:69
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统的搜索路径（如修改PATH环境变量）或能够在当前工作目录放置恶意程序
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_04.c:58-62; pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_04.c:64-68; if (pipe != NULL) { PCLOSE(pipe); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_04.c:67-71
- 结论: 调用popen函数时未指定可执行文件的完整路径，攻击者可通过控制搜索路径（例如修改PATH环境变量）执行恶意程序。尽管命令字符串是硬编码常量，但未指定完整路径本身构成CWE-426违规，攻击者仍可能通过修改PATH或在当前目录放置同名恶意程序来劫持执行。
- D验证: confirmed / ver_c1a15b90
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 107. hyp_path_994fd5c69bf4

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_05.c:69
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改当前进程的PATH环境变量（例如通过本地访问或先前的漏洞），或者在搜索路径中放置与CASE0_OS_COMMAND同名的恶意可执行文件。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_05.c:61; pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_05.c:66
- 结论: popen调用使用了未指定完整路径的命令，违反了CWE-426安全规范，攻击者可能通过修改PATH环境变量或放置同名恶意程序实现代码执行。
- D验证: confirmed / ver_3298549e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 108. hyp_path_85d78fdbe769

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_06.c:66
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够在系统搜索路径中放置恶意可执行文件，或控制环境变量（如PATH）以影响搜索顺序
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ L55-59; pipe = POPEN(data, L"wb"); @ L61-65
- 结论: 程序调用popen（_wpopen）时未指定可执行文件的完整路径，使用了仅包含命令名称的字符串，导致可能从不可信搜索路径加载恶意程序，违反CWE426。
- D验证: confirmed / ver_bfd61aa5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 109. hyp_path_f8180a796c3f

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_07.c:68
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响搜索路径（例如通过修改PATH环境变量或在当前目录放置恶意程序）
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); // 未指定完整路径 @ CWE426_Untrusted_Search_Path__wchar_t_popen_07.c:57-61; pipe = POPEN(data, L"wb"); // 使用未指定完整路径的命令执行 @ CWE426_Untrusted_Search_Path__wchar_t_popen_07.c:63-67
- 结论: 在popen调用中未指定可执行文件的完整路径，攻击者可通过操纵搜索路径（如修改PATH环境变量或当前工作目录）执行任意程序，构成不可信搜索路径漏洞。
- D验证: confirmed / ver_7c5f01e8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 110. hyp_path_49159c744c7e

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_09.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够将恶意可执行文件置于系统搜索路径中。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_09.c:62; pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_09.c:62
- 结论: 未指定可执行文件的完整路径，直接调用_popen，攻击者可能通过将恶意程序置于搜索路径中来执行任意命令。
- D验证: confirmed / ver_aa407270
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 111. hyp_path_34196adfe057

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_14.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够在目标系统的搜索路径中植入恶意程序。; 程序运行时的当前目录或PATH环境变量包含攻击者可控的路径。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ CWE426_Untrusted_Search_Path__wchar_t_popen_14.c:45; pipe = POPEN(data, L"wb"); @ CWE426_Untrusted_Search_Path__wchar_t_popen_14.c:62
- 结论: 程序使用popen执行命令时未指定完整路径，导致不可信搜索路径漏洞。攻击者可通过将恶意程序放置在搜索路径中执行任意代码。
- D验证: confirmed / ver_18ca77b5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 112. hyp_path_aabc3d7d2a21

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_13.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统的PATH环境变量或文件系统权限以植入恶意程序
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); // NOTE: the full path is not specified @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_13.c:51-55; pipe = POPEN(data, L"wb"); // Executing wpopen() without full path @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_13.c:57-61
- 结论: 程序使用popen函数执行命令，但未指定可执行文件的完整路径，仅提供了命令名称（CASE0_OS_COMMAND）。这违反了CWE-426（不可信搜索路径），攻击者可能通过修改系统PATH环境变量或放置恶意同名程序到搜索路径中，导致执行任意代码。
- D验证: confirmed / ver_5a8cbac9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 113. hyp_path_defe0f027a83

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_10.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统PATH环境变量，或能够在popen搜索的路径中放置恶意的同名可执行文件。; 命令字符串来自常量，攻击者无法直接控制命令内容，但可通过环境或文件系统篡改执行目标。
- 触发路径: pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_10.c:62; wcscpy(data, CASE0_OS_COMMAND); /* NOTE: the full path is not specified */ @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_10.c:55
- 结论: 使用popen执行命令时未指定完整路径，虽然命令字符串来自常量，但攻击者仍可能通过修改PATH环境变量或在搜索路径中放置恶意同名程序来利用此漏洞，前提是攻击者具备相应权限或能影响系统环境。
- D验证: confirmed / ver_3112e354
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 114. hyp_path_a279bd7bb082

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_15.c:68
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响搜索路径（如修改PATH环境变量）或在搜索路径中放置恶意程序。
- 触发路径: case 6: /* NOTE: the full path is not specified */ wcscpy(data, CASE0_OS_COMMAND); break; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_15.c:52-56; pipe = POPEN(data, L"wb"); // 未指定完整路径，使用搜索路径 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_15.c:63-67
- 结论: 函数_wpopen使用未指定完整路径的命令字符串，攻击者可通过控制搜索路径执行任意程序，违反CWE-426不可信搜索路径。
- D验证: confirmed / ver_7e174ce0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 115. hyp_path_3505cce8b703

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_16.c:63
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改搜索路径（如PATH环境变量）或在当前目录写入恶意程序
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); break; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_16.c:51-55; pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_16.c:58-62
- 结论: 代码中使用了未指定完整路径的命令字符串调用popen()函数，导致不可信搜索路径漏洞。攻击者可以通过控制环境变量或在当前目录放置恶意同名程序来执行任意代码。
- D验证: confirmed / ver_789e6995
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 116. hyp_path_7c3ca1fa6859

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_17.c:63
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统搜索路径或在搜索路径中放置与CASE0_OS_COMMAND同名的恶意可执行文件
- 触发路径: 调用进入该测试用例 @ 入口行45; wcscpy(data, CASE0_OS_COMMAND); // 复制命令名称，未指定完整路径 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_17.c:63; pipe = POPEN(data, L"wb"); // 执行命令，依赖搜索路径 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_17.c:58-62
- 结论: 程序使用popen函数执行命令，但未指定完整路径，仅使用命令名称（CASE0_OS_COMMAND），导致可能执行搜索路径中的恶意程序，符合CWE-426不受信任的搜索路径漏洞。
- D验证: confirmed / ver_73e3016e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 117. hyp_path_60f4208f4bdd

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_18.c:61
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响系统PATH环境变量或放置同名恶意可执行文件在搜索路径中
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_18.c:55; pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_18.c:60
- 结论: CWE-426: Untrusted Search Path - 使用不受信任的搜索路径调用popen，其中可执行文件路径未指定完整路径，攻击者可替换为恶意程序。
- D验证: confirmed / ver_4ac30f87
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 118. hyp_path_6d40dfe59e92

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_31.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改环境变量PATH或向搜索路径中放置恶意程序
- 触发路径: data = dataBuffer; wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_31.c:49-53; pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_31.c:60-61
- 结论: popen函数使用未指定完整路径的硬编码命令，导致不受信任的搜索路径漏洞，攻击者可替换命令为恶意程序。
- D验证: confirmed / ver_4909f0a0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 119. hyp_path_bc9fb5e9b6ce

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_33.cpp:65
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量PATH或能够将恶意程序放入系统搜索路径
- 触发路径: data = dataBuffer; /* NOTE: the full path is not specified */ wcscpy(data, CASE0_OS_COMMAND); @ CWE426_Untrusted_Search_Path__wchar_t_popen_33.cpp:48; pipe = POPEN(data, L"wb"); @ CWE426_Untrusted_Search_Path__wchar_t_popen_33.cpp:65
- 结论: 未指定完整路径就调用_wpopen执行命令，攻击者可通过修改PATH环境变量替换为恶意程序。
- D验证: confirmed / ver_4c26fa12
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 120. hyp_path_e7b339e25524

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_34.c:69
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改目标系统的环境变量PATH，或在同一用户上下文中创建同名恶意可执行文件。
- 触发路径: data = dataBuffer; wcscpy(data, CASE0_OS_COMMAND); @ 58; pipe = POPEN(data, L"wb"); @ 65-66
- 结论: 该代码在调用popen时没有指定可执行文件的完整路径，仅使用了宏CASE0_OS_COMMAND（例如"cmd.exe"），攻击者可通过修改PATH环境变量替换为恶意程序，导致任意命令执行。
- D验证: confirmed / ver_f1babc80
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 121. hyp_path_4ba61d2dec39

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_72b.cpp:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制vector<char*> dataVector的输入，使dataVector[2]包含相对路径的恶意程序名
- 触发路径: char * data = dataVector[2]; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_72b.cpp:52; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_72b.cpp:62
- 结论: popen(data, "wb")中data来自dataVector[2]，若data为相对路径且攻击者可控制dataVector输入，则可通过植入恶意程序执行任意命令，违反CWE-426（不可信搜索路径）。
- D验证: confirmed / ver_98fb4e8d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 122. hyp_path_b1070ea8afea

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_72b.cpp:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够通过调用方控制dataVector[2]的内容为可执行文件名; 系统搜索路径（如PATH）包含可被攻击者写入的目录
- 触发路径: wchar_t * data = dataVector[2]; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_72b.cpp:55; pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_72b.cpp:59
- 结论: 在调用popen函数时未指定可执行文件的完整路径，攻击者可能通过控制搜索路径或放置恶意同名程序来执行任意代码。
- D验证: confirmed / ver_f706e142
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 123. hyp_path_8dd7b552a85f

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_73b.cpp:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: An attacker can influence the contents of dataList, e.g., via command-line arguments, environment variables, or other external input in the calling context.
- 触发路径: char * data = dataList.back(); @ CWE426_Untrusted_Search_Path__char_popen_73b.cpp:52; pipe = POPEN(data, "wb"); @ CWE426_Untrusted_Search_Path__char_popen_73b.cpp:59
- 结论: The program uses popen() with data from dataList.back() without specifying a full path, potentially allowing an attacker to control the executed program via PATH manipulation if dataList is populated with untrusted input.
- D验证: confirmed / ver_eb485146
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 124. hyp_path_bca0415b99d8

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_73b.cpp:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够向dataList中插入恶意数据，例如通过先前的函数调用或外部输入。
- 触发路径: wchar_t * data = dataList.back(); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_73b.cpp:52-56; pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_73b.cpp:57-61
- 结论: 函数使用popen执行命令，路径参数data来自dataList.back()，未指定完整路径，攻击者可通过控制dataList内容执行任意程序。
- D验证: confirmed / ver_d14c7894
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 125. hyp_path_9da4552364a4

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_32.c:67
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统的PATH环境变量或在搜索路径中放置同名恶意程序（例如通过用户目录或网络共享）
- 触发路径: char * data = *dataPtr1; strcpy(data, CASE0_OS_COMMAND); *dataPtr1 = data; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_32.c:53-57; pipe = POPEN(data, "wb"); if (pipe != NULL) { @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_32.c:65-67
- 结论: 代码使用popen()函数执行命令时未指定完整路径，依赖于系统的PATH环境变量，攻击者可通过控制PATH或放置恶意程序在搜索路径中，导致任意代码执行。尽管data参数来源于常量CASE0_OS_COMMAND，但未指定绝对路径的事实仍然构成CWE-426漏洞，攻击者可通过修改PATH或放置同名恶意程序在搜索路径中劫持执行。
- D验证: confirmed / ver_e2d5186b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 126. hyp_path_6685ad8e3f3a

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_83_case0.cpp:47
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制传递给POPEN的data参数的值，且data仅包含可执行文件名（无路径分隔符）
- 触发路径: pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_83_case0.cpp:45
- 结论: 调用popen时未指定可执行文件的完整路径，如果data参数来自外部可控输入且不包含路径分隔符，则攻击者可能通过控制data参数执行恶意程序。
- D验证: confirmed / ver_35fee864
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 127. hyp_path_350b6e7bbbc5

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_84_case0.cpp:47
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统搜索路径或在该路径下放置恶意可执行文件; data参数虽然来源未在片段中显示，但典型Juliet用例中由外部输入设置，需动态验证
- 触发路径: pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_84_case0.cpp:45
- 结论: 调用POPEN函数时未指定可执行文件的完整路径，即使data参数来源未明确，但代码注释强调此风险，且无任何路径验证，符合CWE-426定义。攻击者若能在搜索路径中植入恶意可执行文件，即可利用此漏洞。
- D验证: confirmed / ver_51acd1d3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 128. hyp_path_4cd127cc9749

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_32.c:67
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改当前进程的搜索路径（如PATH环境变量）或将恶意程序放置在搜索路径中的任意目录下。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); /* NOTE: the full path is not specified */ @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_32.c:55; pipe = POPEN(data, L"wb"); /* Executing without specifying full path */ @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_32.c:67; if (pipe != NULL) { PCLOSE(pipe); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_32.c:68-69
- 结论: 函数_popen调用时使用了未指定完整路径的命令，攻击者若能控制搜索路径（如通过环境变量或放置恶意程序），则可执行任意程序，导致权限提升或远程代码执行。
- D验证: confirmed / ver_abcd79e9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 129. hyp_path_c004eb19d0c4

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_83_case0.cpp:47
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: The 'data' variable must be controllable by an attacker or not an absolute path, allowing placement of a malicious executable in the search path.
- 触发路径: pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_83_case0.cpp:45
- 结论: The application calls _wpopen (via POPEN) with a potentially untrusted search path because the 'data' argument is not a fully qualified path. Although the source of 'data' is not shown in the evidence, the code comment explicitly warns that this can allow an attacker to execute arbitrary code. This constitutes a CWE-426 violation, but the vulnerability path is incomplete without tracing 'data' to an untrusted source.
- D验证: confirmed / ver_d071741a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 130. hyp_path_5c94b260d3ef

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_84_case0.cpp:47
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data参数的值（例如通过环境变量或输入），并在系统搜索路径中放置同名恶意可执行文件。
- 触发路径: pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_84_case0.cpp:46
- 结论: 使用popen函数时未指定完整路径，data参数来自不受信任的源，攻击者可通过控制搜索路径中的恶意程序执行任意代码，违反CWE-426 Untrusted Search Path。
- D验证: confirmed / ver_a4a915cc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 131. hyp_path_cd9d5daad5c0

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_41.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响data变量的值（需通过动态分析或审查完整代码确认）; 系统搜索路径中不存在完整路径指定，允许攻击者在搜索路径中放置同名恶意程序
- 触发路径: data = 用户可控输入（需从完整上下文中确认） @ 入口函数CWE426_Untrusted_Search_Path__char_popen_41_case0Sink:45; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_41.c:54
- 结论: popen函数调用未指定完整路径，违反CWE-426 contract，可能导致不可信搜索路径攻击。虽然source（data可控性）未在提供的代码片段中明确展示，但注释表明该问题可能导致任意程序执行。需进一步验证data是否用户可控。
- D验证: confirmed / ver_9f44d364
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 132. hyp_path_204bb04fd3b7

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_45.c:58
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data参数或影响系统PATH环境变量
- 触发路径: pipe = POPEN(data, "wb"); // 未指定完整路径 @ CWE426_Untrusted_Search_Path__char_popen_45.c:58
- 结论: 调用popen函数时未指定可执行文件的完整路径，违反API安全契约（CWE-426），即使data来源不明，但代码本身构成不可信搜索路径的潜在漏洞。
- D验证: confirmed / ver_4b2d4af1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 133. hyp_path_95f550724da7

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_44.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响当前进程的PATH环境变量; 或攻击者能够在搜索路径中的某个位置放置恶意可执行文件
- 触发路径: pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_44.c:54
- 结论: 调用popen()时未指定可执行文件的完整路径，使用受环境变量PATH影响的搜索路径，可能允许攻击者运行恶意程序。但缺少source步骤的明确代码证据。
- D验证: confirmed / ver_8712c5f0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 134. hyp_path_c28873f437df

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_51b.c:56
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够通过某种方式（如环境变量、用户输入）影响data的值，使其指向一个未指定完整路径的可执行文件
- 触发路径: pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_51b.c:56
- 结论: 调用popen()时未指定可执行文件的完整路径，依赖系统搜索路径，攻击者可通过在搜索路径中放置恶意程序实现任意代码执行。
- D验证: confirmed / ver_64477c22
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 135. hyp_path_a92edf3764b2

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_52c.c:56
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够通过某种方式控制 data 变量的内容（例如环境变量或用户输入）; 系统搜索路径中存在攻击者可写的目录
- 触发路径: pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_52c.c:56
- 结论: popen() 调用未指定可执行文件的完整路径，违反安全编码规范，可能导致不可信搜索路径漏洞。但缺少 data 来源证据，无法确认攻击者能否控制 data 内容，因此可利用性不确定。
- D验证: confirmed / ver_9c5acd24
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 136. hyp_path_9f502214c5f1

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_53d.c:56
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data变量内容（例如通过环境变量或命令行参数）; 攻击者能够在系统搜索路径中放置同名恶意程序或修改PATH环境变量
- 触发路径: data = 外部输入或环境变量？未提供代码 @ 入口函数（推测47行）; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_53d.c:56
- 结论: 调用popen函数时使用了未指定完整路径的参数，可能导致攻击者利用搜索路径替换恶意程序，存在任意命令执行风险。虽然data的具体来源在提供的代码片段中未明确，但根据CWE-426测试用例的典型设定，data可能来自固定字符串或可被攻击者影响的环境变量，且A阶段注释已指出风险。由于B阶段静态证据不完整，最终确认需要动态验证或审计。
- D验证: confirmed / ver_cf506538
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 137. hyp_path_0008fa505de6

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_54e.c:56
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data参数的值，但完整调用链中data可能来自环境变量或命令行参数，需审计确认。
- 触发路径: pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_54e.c:56
- 结论: 调用popen()时未指定完整路径，导致不可信搜索路径，攻击者可通过控制data参数执行任意程序。
- D验证: confirmed / ver_13780777
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 138. hyp_path_4a46057003f5

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_63b.c:55
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或放置同名恶意程序于搜索路径中
- 触发路径: pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_63b.c:53
- 结论: 调用popen()时未指定可执行文件的完整路径，导致攻击者可能通过控制搜索路径执行恶意程序，违反CWE-426不可信搜索路径。
- D验证: confirmed / ver_562ef3d5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 139. hyp_path_4890a3de357c

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_64b.c:58
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响data参数的内容（证据不完整）
- 触发路径: pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_64b.c:58
- 结论: popen()调用使用未指定完整路径的可执行文件，攻击者可通过控制搜索路径执行恶意程序。但缺少data参数来源的证据，需进一步验证外部可控性。
- D验证: confirmed / ver_c9ad1fb4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 140. hyp_path_df1f3909d5f1

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_65b.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制传递给popen()的data参数的值。
- 触发路径: pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_65b.c:54
- 结论: 程序调用popen()时使用了不可信数据作为命令，且未指定完整路径，攻击者可以通过控制data参数执行任意程序，导致不受信任的搜索路径漏洞。
- D验证: confirmed / ver_3afc6d21
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 141. hyp_path_133ba73d1ec1

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_66b.c:56
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data参数的内容（例如通过环境变量或用户输入）; 攻击者能够修改PATH环境变量以包含恶意目录
- 触发路径: pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_66b.c:56
- 结论: 调用popen时未指定可执行文件的完整路径，仅使用文件名，可能导致攻击者通过修改PATH环境变量执行恶意程序。违反CWE-426（不可信搜索路径）。
- D验证: confirmed / ver_54fdfcef
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 142. hyp_path_313b0023a589

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_67b.c:60
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制传递给popen()的data参数（例如通过命令行参数或环境变量）; 攻击者可以在搜索路径中放置恶意可执行文件，或修改PATH环境变量指向恶意程序
- 触发路径: pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_67b.c:60
- 结论: 函数使用popen()且未指定可执行文件的完整路径，允许攻击者通过控制搜索路径执行恶意程序，违反CWE-426。虽然缺少对data参数外部可控性的直接代码验证，但Juliet测试用例通常从外部输入获取，且注释隐含风险，因此漏洞假设成立但证据不完整。
- D验证: confirmed / ver_d3c6d6f4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 143. hyp_path_a2b8b5eebe60

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_68b.c:60
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data变量的内容（例如通过外部输入）; 攻击者能够在系统的程序搜索路径中放置恶意可执行文件
- 触发路径: pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_68b.c:60
- 结论: 在popen()函数调用中未指定可执行文件的完整路径，可能允许攻击者通过控制data变量或环境变量来执行恶意程序，导致不受信任的搜索路径漏洞。
- D验证: confirmed / ver_75701b72
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 144. hyp_path_8cb1c6b5f97e

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_81_case0.cpp:41
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data参数的内容
- 触发路径: pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_81_case0.cpp:41
- 结论: 代码使用popen函数执行命令，但未指定可执行文件的完整路径，且参数data可能受攻击者控制，导致攻击者可以通过修改搜索路径执行任意程序。
- D验证: confirmed / ver_dac96e6f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 145. hyp_path_64f0d129966b

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_41.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统或用户的搜索路径（如PATH环境变量）; data必须为未指定完整路径的字符串，且攻击者能控制data的值（需验证data来源是否外部可控）
- 触发路径: pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_41.c:54
- 结论: 由于未指定可执行文件的完整路径，攻击者可通过修改搜索路径（如PATH环境变量）劫持popen调用，执行恶意程序。但data的来源在提供的代码片段中未明确，需要进一步确认data是否来自外部不可信源。
- D验证: confirmed / ver_07853ef9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 146. hyp_path_dec871e8a6c1

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_82_case0.cpp:41
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: Attacker can control the content of the 'data' pointer, e.g., through command-line arguments or environment variables (assumed based on typical Juliet test case structure, but not explicitly verified in the provided snippet).
- 触发路径: void action(char * data) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_82_case0.cpp:32; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_82_case0.cpp:41
- 结论: The program uses the popen() function with a parameter 'data' that is likely derived from untrusted input (typical Juliet test case pattern) without specifying a full path, which can allow an attacker to execute arbitrary programs via a malicious executable in the search path. However, the source of 'data' is not explicitly shown in the provided code snippet, making the evidence incomplete.
- D验证: confirmed / ver_9c6ec214
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 147. hyp_path_f6c4c46ac9a8

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_44.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制popen的参数data或影响PATH环境变量，使得搜索路径中包含恶意程序。但data的来源未在代码证据中展示，需进一步动态验证。
- 触发路径: pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_44.c:54
- 结论: 代码使用popen函数执行程序时未指定完整路径，存在CWE-426不可信搜索路径漏洞的潜在风险，但缺乏数据源可控的证据，数据流不完整。
- D验证: confirmed / ver_32667273
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 148. hyp_path_efdca14aeea2

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_45.c:58
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制传递给popen的data参数的值，或能够修改系统搜索路径中的恶意可执行文件
- 触发路径: pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_45.c:58
- 结论: 存在不安全的搜索路径漏洞：调用popen时未指定可执行文件的完整路径，攻击者可能通过控制搜索路径执行任意程序。但data参数的具体来源未在提供的代码片段中明确，需进一步验证其是否来自外部可控输入。
- D验证: confirmed / ver_843a63de
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 149. hyp_path_95eaf5e8d342

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_51b.c:56
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data参数（如通过命令行参数或环境变量）; 或攻击者能够修改PATH环境变量或在当前目录放置恶意可执行文件
- 触发路径: pipe = POPEN(data, L"wb"); @ CWE426_Untrusted_Search_Path__wchar_t_popen_51b.c:56
- 结论: 在调用popen时使用了不可信搜索路径，data参数虽未在证据中明确展示来源，但基于CWE426测试用例常见设计，data应来自外部可控输入（如argv或环境变量），且未指定绝对路径，攻击者可通过修改PATH或当前目录执行任意程序。
- D验证: confirmed / ver_2d837077
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 150. hyp_path_f75ea3e55233

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_52c.c:56
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制参数data（可能来自外部输入），或能够修改搜索路径（如通过环境变量或文件系统写入权限）使得恶意可执行文件优先级高于正常位置。
- 触发路径: pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_52c.c:56
- 结论: 函数POPEN调用时未指定可执行文件的完整路径，攻击者可通过操纵搜索路径（如控制环境变量或当前工作目录）使系统运行恶意程序，违反CWE-426。
- D验证: confirmed / ver_58a4b4e4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 151. hyp_path_d456d4614974

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_53d.c:56
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data输入的内容; 攻击者能够在搜索路径中放置恶意可执行文件
- 触发路径: pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_53d.c:54
- 结论: 程序使用POPEN函数执行外部命令，参数data可能来源于不可信输入，且未指定完整路径，导致攻击者可通过修改搜索路径或放置恶意同名文件执行任意代码。尽管data来源未在提供的代码片段中明确展示，但根据测试用例设计，该路径闭合，存在漏洞假设。
- D验证: confirmed / ver_64d32a93
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 152. hyp_path_74c0bd949e83

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_54e.c:56
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data参数的值（例如通过用户输入、环境变量等），或能够将恶意程序放入系统搜索路径
- 触发路径: pipe = POPEN(data, L"wb"); @ CWE426_Untrusted_Search_Path__wchar_t_popen_54e.c:51-55
- 结论: 调用popen时未指定可执行文件完整路径，依赖于系统搜索路径，攻击者可能通过将恶意程序放入搜索路径实现任意代码执行。data参数可控性需进一步确认。
- D验证: confirmed / ver_c05c6f6a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 153. hyp_path_ab521803ffba

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_63b.c:55
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制 data 参数，使其指向非完整路径的可执行文件名
- 触发路径: pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_63b.c:55
- 结论: 调用 POPEN (实际为 _wpopen) 时使用不可信搜索路径，未指定完整路径，攻击者可通过在搜索路径中放置恶意程序导致任意代码执行。
- D验证: confirmed / ver_feb1672d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 154. hyp_path_cc5b7092cc91

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_65b.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data参数使其指向未指定完整路径的程序名，并且能够在搜索路径中植入恶意可执行文件。
- 触发路径: pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_65b.c:54
- 结论: 调用POPEN函数时未指定可执行文件的完整路径，允许攻击者通过搜索路径劫持执行恶意程序，违反CWE-426 Untrusted Search Path。
- D验证: confirmed / ver_9facbd1d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 155. hyp_path_853d0dea84d5

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_64b.c:58
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够将恶意可执行文件放置在系统搜索路径中的目录（如PATH环境变量包含的目录或当前目录）。; 攻击者能够影响data参数的值或data未指定完整路径（需进一步确认data来源是否外部可控）。
- 触发路径: pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_64b.c:58
- 结论: 调用popen时未指定可执行文件的完整路径，允许攻击者通过修改搜索路径（如PATH环境变量）来执行恶意程序，构成CWE-426不可信搜索路径漏洞。但data参数的可控性未在代码证据中明确展示，漏洞路径不完整。
- D验证: confirmed / ver_b0d0012d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 156. hyp_path_898391004a29

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_66b.c:56
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制popen的data参数（例如通过环境变量、配置文件或用户输入）; 攻击者能够在当前工作目录或搜索路径中放置恶意可执行文件，且其名称与data参数匹配
- 触发路径: pipe = POPEN(data, L"wb"); @ CWE426_Untrusted_Search_Path__wchar_t_popen_66b.c:56
- 结论: 调用popen时未指定可执行文件的完整路径，导致不可信搜索路径漏洞（CWE-426）。攻击者可通过控制data参数，使程序执行当前目录下的恶意程序。现有证据仅包含sink端，缺少source端可控性闭合，但代码注释明确提示风险，且popen调用使用了相对路径，违反API contract。
- D验证: confirmed / ver_231500c5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 157. hyp_path_7a28d8017b7c

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_67b.c:60
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data变量或影响搜索路径环境
- 触发路径: pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_67b.c:60
- 结论: 程序使用用户可控的未指定完整路径的字符串调用POPEN，导致不受信任的搜索路径漏洞，攻击者可能通过控制PATH环境变量或放置恶意程序执行任意代码。
- D验证: confirmed / ver_8b379785
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 158. hyp_path_c722d5c83334

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_68b.c:60
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data变量的内容（例如通过环境变量或输入）; 攻击者能够在当前工作目录或PATH路径中放置同名恶意程序
- 触发路径: pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_68b.c:60
- 结论: 使用popen函数时未指定可执行文件的完整路径，违反安全编码规范（CWE-426）。尽管缺少data变量外部可控性的直接证据，但函数调用本身构成API misuse，攻击者若控制data（如环境变量或输入）则可通过修改PATH或放置同名恶意程序执行任意代码。
- D验证: confirmed / ver_ce311b66
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 159. hyp_path_7dd8d360effe

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_81_case0.cpp:41
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制参数data的值，或能够影响程序执行时的搜索路径环境变量。
- 触发路径: pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_81_case0.cpp:36-40
- 结论: 调用popen时未指定可执行文件的完整路径，可能被攻击者利用环境变量PATH中的恶意程序替换。
- D验证: confirmed / ver_baa2a89d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 160. hyp_path_7a10412636d4

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_82_case0.cpp:41
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制传递给_wpopen的data参数值（需要完整代码确认来源，但Juliet测试用例通常从外部输入获取）; 系统搜索路径（如PATH环境变量或当前工作目录）包含攻击者可写入的目录，以便放置恶意可执行文件
- 触发路径: pipe = POPEN(data, L"wb"); @ CWE426_Untrusted_Search_Path__wchar_t_popen_82_case0.cpp:36-40
- 结论: 程序使用_wpopen函数执行命令时未指定完整路径，违反CWE-426要求，可能导致从不可信搜索路径加载恶意可执行文件。尽管data参数来源未在代码片段中直接证实，但函数调用本身即构成潜在漏洞，攻击者若能在搜索路径中放置恶意程序则可能实现任意命令执行。
- D验证: confirmed / ver_ece490c1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 161. hyp_path_678610d0f2b4

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_51a.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统PATH环境变量或控制文件系统，使得同名恶意可执行文件被优先执行
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_51a.c:54; CWE426_Untrusted_Search_Path__char_popen_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_51a.c:55
- 结论: 代码使用了未指定完整路径的命令字符串，并将其传递给可能执行命令的sink函数，导致不可信搜索路径漏洞（CWE-426）。攻击者可通过修改系统PATH环境变量或放置同名恶意可执行文件来执行任意命令。
- D验证: confirmed / ver_ba2dbe32
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 162. hyp_path_3c4298d96f3d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_52a.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统搜索路径或放置恶意程序在路径中。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_52a.c:54; CWE426_Untrusted_Search_Path__char_popen_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_52a.c:55
- 结论: 存在CWE-426未信任搜索路径漏洞：程序在未指定完整路径的情况下执行命令，攻击者可通过在搜索路径中放置恶意可执行文件导致任意命令执行。
- D验证: confirmed / ver_dbd1a72a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 163. hyp_path_0e3bed7ddeb9

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_53a.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改目标进程的环境变量PATH（例如通过当前工作目录或父进程环境），使popen解析并执行恶意程序。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_53a.c:53; CWE426_Untrusted_Search_Path__char_popen_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_53a.c:54
- 结论: 代码中通过strcpy将常量CASE0_OS_COMMAND复制到data，然后传递给sink函数，该函数可能调用popen(data)。由于未指定完整路径，攻击者可通过修改PATH环境变量劫持命令执行（例如将恶意程序放置在当前目录并命名为同名命令），导致任意代码执行。
- D验证: confirmed / ver_9d42f273
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 164. hyp_path_69ef373bc7c9

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_54a.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响系统搜索路径（如PATH环境变量）; 攻击者能够在搜索路径中放置恶意可执行文件
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_54a.c:54; CWE426_Untrusted_Search_Path__char_popen_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_54a.c:55
- 结论: 存在Untrusted Search Path漏洞（CWE-426）：命令执行未指定完整路径，攻击者可利用不可信的搜索路径（如PATH环境变量）执行恶意程序。
- D验证: confirmed / ver_f91b92a8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 165. hyp_path_f70f2b65234a

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_64a.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统PATH环境变量或在与命令同名的目录下放置恶意可执行文件。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); CWE426_Untrusted_Search_Path__char_popen_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_64a.c:54; popen(data); // 使用不完整路径，导致搜索路径劫持 @ sink函数内部 (CWE426_Untrusted_Search_Path__char_popen_64b.c)
- 结论: 代码使用popen执行命令时未指定完整路径，导致不可信搜索路径漏洞。
- D验证: confirmed / ver_2a2b6de9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 166. hyp_path_5753a3855eda

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_63a.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统PATH环境变量或当前工作目录下放置与命令同名的恶意可执行文件
- 触发路径: strcpy(data, CASE0_OS_COMMAND); CWE426_Untrusted_Search_Path__char_popen_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_63a.c:54
- 结论: 代码使用未指定完整路径的命令执行popen，符合CWE-426不可信搜索路径特征。虽然命令为常量字符串，但攻击者仍可通过修改系统PATH环境变量或在工作目录放置同名恶意可执行文件实现利用。B阶段静态证据不足，需动态验证sink内部实际popen调用是否可被环境变量影响。
- D验证: confirmed / ver_834864ca
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 167. hyp_path_353cdef11f6f

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_51a.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够将恶意可执行文件放置于搜索路径中的某个目录（如当前工作目录）; 攻击者具有本地访问权限以影响搜索路径
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_51a.c:52; CWE426_Untrusted_Search_Path__char_system_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_51a.c:53
- 结论: 程序使用未指定完整路径的命令字符串调用system()类函数，可能从不可信的搜索路径加载恶意程序，导致任意代码执行。
- D验证: confirmed / ver_46233eac
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 168. hyp_path_f14736fcc27c

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_53a.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够设置PATH环境变量或影响当前工作目录
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_53a.c:52; CWE426_Untrusted_Search_Path__char_system_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_53a.c:53
- 结论: 程序在调用系统命令时未使用完整路径（CWE-426）。在CWE426_Untrusted_Search_Path__char_system_53a.c中，使用strcpy将常量命令字符串CASE0_OS_COMMAND复制到缓冲区，然后直接传递给sink函数CWE426_Untrusted_Search_Path__char_system_53b_case0Sink，该函数内部会调用system或类似函数执行命令，但未指定命令的完整路径，攻击者可通过修改PATH环境变量或控制当前工作目录劫持命令执行。
- D验证: confirmed / ver_4c42c694
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 169. hyp_path_c1a07eee0d6d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_52a.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改目标进程的PATH环境变量（例如通过父进程或本地提权）。; sink函数内部实际调用system()（未在代码片段中展示，但根据CWE426测试用例模式推断）。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_52a.c:52; CWE426_Untrusted_Search_Path__char_system_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_52a.c:53
- 结论: 程序通过不完整路径的命令字符串调用system()（假设sink函数实现中包含system调用），攻击者可通过修改PATH环境变量劫持命令执行，导致任意命令执行。
- D验证: confirmed / ver_6c7ab936
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 170. hyp_path_abe534cac0d5

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_54a.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或控制搜索路径。; 程序在没有指定完整路径的情况下执行系统命令。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_54a.c:52; CWE426_Untrusted_Search_Path__char_system_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_54a.c:53
- 结论: 存在CWE-426不可信搜索路径漏洞：strcpy将固定命令字符串复制到data后，传递给sink函数，且注释指明未指定完整路径，可能通过PATH环境变量劫持命令执行。尽管sink函数内部实现未在代码片段中提供，但函数名暗示其可能调用system或类似函数，且测试用例明确针对CWE-426，因此漏洞假设合理。
- D验证: confirmed / ver_5709adb8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 171. hyp_path_d2ce5b6601fd

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_63a.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或当前工作目录。
- 触发路径: data = dataBuffer; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_63a.c:51; strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_63a.c:52; CWE426_Untrusted_Search_Path__char_system_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_63a.c:53
- 结论: 程序在执行系统命令时未指定完整路径，使用了不可信的搜索路径，可能导致攻击者通过控制PATH环境变量执行恶意命令。
- D验证: confirmed / ver_31d0afb4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 172. hyp_path_1dbeeab6f3c7

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_64a.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统环境变量（如PATH）或影响命令搜索路径。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_64a.c:52; CWE426_Untrusted_Search_Path__char_system_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_64a.c:53
- 结论: 函数使用未指定完整路径的命令字符串，通过sink函数执行，可能调用system()导致不受信任的搜索路径漏洞。但sink函数具体实现未在证据中展示，需确认是否实际执行外部命令。
- D验证: confirmed / ver_06017ff3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 173. hyp_path_4f7558db0d5d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_53a.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制当前工作目录或PATH环境变量，使得CASE0_OS_COMMAND对应的可执行文件被替换为恶意程序。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_53a.c:54; CWE426_Untrusted_Search_Path__wchar_t_popen_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_53a.c:55
- 结论: 函数使用未指定完整路径的命令字符串调用popen，导致未信任搜索路径漏洞，攻击者可通过控制环境变量或当前目录劫持执行恶意程序。
- D验证: confirmed / ver_4bc1b4ab
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 174. hyp_path_ac7d7c181de5

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_51a.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统环境变量PATH或当前工作目录，使得搜索路径中包含恶意可执行文件
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_51a.c:54; CWE426_Untrusted_Search_Path__wchar_t_popen_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_51a.c:55
- 结论: 程序使用了未指定完整路径的命令字符串调用_popen，可能导致不可信搜索路径漏洞，攻击者可通过修改PATH环境变量执行恶意程序。
- D验证: confirmed / ver_9aeb3289
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 175. hyp_path_9905b9c0e76a

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_52a.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统搜索路径（如PATH环境变量）或控制当前目录; 攻击者能够在搜索路径中放置与CASE0_OS_COMMAND同名的恶意可执行文件
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); // NOTE: the full path is not specified @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_52a.c:54; CWE426_Untrusted_Search_Path__wchar_t_popen_52b_case0Sink(data); // 内部调用popen @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_52a.c:55
- 结论: 程序使用未指定完整路径的命令字符串调用popen，可能导致不可信搜索路径漏洞，攻击者可通过修改搜索路径或放置恶意同名可执行文件来执行任意代码。
- D验证: confirmed / ver_8adb78c9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 176. hyp_path_ae5d7293a415

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_54a.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统搜索路径（如通过环境变量PATH）; 程序以受影响用户的权限运行
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); CWE426_Untrusted_Search_Path__wchar_t_popen_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_54a.c:54
- 结论: 代码使用未指定完整路径的命令调用popen，攻击者可能通过修改环境变量PATH来劫持命令执行，导致任意代码执行。
- D验证: confirmed / ver_0aac7109
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 177. hyp_path_a6d2dad76827

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_63a.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响系统的搜索路径（如通过环境变量注入或修改PATH等），或者能够在搜索路径中的任意位置放置同名恶意可执行文件
- 触发路径: data = dataBuffer; /* NOTE: the full path is not specified */ wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_63a.c:53-54; CWE426_Untrusted_Search_Path__wchar_t_popen_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_63a.c:55
- 结论: 代码中使用未指定完整路径的命令（仅通过wcscpy复制命令字符串）传递给可能执行外部程序的sink函数，导致不可信搜索路径漏洞（CWE-426）。攻击者可利用此漏洞通过在搜索路径中放置恶意可执行文件来执行任意代码。
- D验证: confirmed / ver_eba132f8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 178. hyp_path_c38f2043d708

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_64a.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改目标进程的PATH环境变量（例如通过恶意进程注入或配置文件篡改）; CASE0_OS_COMMAND字符串对应一个常见命令名（如'cmd.exe'），且路径搜索顺序允许在当前目录或PATH中搜寻到恶意可执行文件
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_64a.c:54; CWE426_Untrusted_Search_Path__wchar_t_popen_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_64a.c:55; 调用popen(data, ...) 使用未指定完整路径的命令 @ sink函数内部
- 结论: 程序使用popen执行命令，但未指定可执行文件的完整路径（仅使用CASE0_OS_COMMAND字符串），攻击者可能通过修改PATH环境变量引入恶意可执行文件，导致任意命令执行。
- D验证: confirmed / ver_43ab0680
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 179. hyp_path_cfac4cc6a8c2

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_51a.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改进程的PATH环境变量（例如通过父进程或环境配置）
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_51a.c:52; CWE426_Untrusted_Search_Path__wchar_t_system_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_51a.c:53
- 结论: 代码使用不受信任的搜索路径调用系统命令，未指定完整路径，攻击者可通过修改PATH环境变量注入恶意程序。
- D验证: confirmed / ver_e798c7eb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 180. hyp_path_b0958262a847

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_52a.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统搜索路径（如环境变量PATH）或当前工作目录中存在恶意程序。
- 触发路径: data = dataBuffer; /* NOTE: the full path is not specified */ wcscpy(data, CASE0_OS_COMMAND); CWE426_Untrusted_Search_Path__wchar_t_system_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_52a.c:52
- 结论: 程序使用相对路径或仅命令名调用系统命令，未指定完整路径，可能导致从不可信搜索路径加载恶意程序。
- D验证: confirmed / ver_2815fdf3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 181. hyp_path_dc5cbde1fb10

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_53a.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统环境变量PATH或控制当前工作目录
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_53a.c:52; CWE426_Untrusted_Search_Path__wchar_t_system_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_53a.c:53
- 结论: CWE426 Untrusted Search Path: 代码使用相对路径调用系统命令，未指定完整路径，攻击者可能通过控制PATH环境变量或当前目录劫持执行恶意命令。
- D验证: confirmed / ver_12966af0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 182. hyp_path_b0feaae79f2f

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_54a.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统环境变量（如PATH）或具有写入搜索路径中目录的权限。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); // NOTE: the full path is not specified @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_54a.c:52; CWE426_Untrusted_Search_Path__wchar_t_system_54b_case0Sink(data); // sink函数，推断调用system @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_54a.c:53
- 结论: 程序使用未指定完整路径的命令字符串，并通过sink函数（预期调用system或类似函数）执行，构成不可信搜索路径漏洞。尽管sink函数内部实现未提供，但样本名称和测试用例设计明确指向system调用，且代码注释强调未指定完整路径，违反CWE-426安全契约。
- D验证: confirmed / ver_b39e0f0f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 183. hyp_path_84d17228f205

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_63a.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统的PATH环境变量（例如通过其他漏洞或直接访问）
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); // 常量字符串，但未指定完整路径 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_63a.c:51; CWE426_Untrusted_Search_Path__wchar_t_system_63b_case0Sink(&data); // 将data传递给system @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_63a.c:53
- 结论: 存在CWE-426不可信搜索路径漏洞：虽然命令字符串是编译时常量，但程序未指定完整路径，依赖于系统PATH搜索。攻击者若能修改PATH环境变量（如通过其他漏洞或直接访问），可将恶意程序放置在搜索路径中并使用相同名称，从而劫持程序执行。
- D验证: confirmed / ver_feed1cb1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 184. hyp_path_ad398637727d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_64a.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: The command string is a hardcoded constant (CASE0_OS_COMMAND) without a full path.; An attacker must be able to modify the system's search path (e.g., PATH environment variable) or place a malicious executable earlier in the search path.
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_64a.c:51; CWE426_Untrusted_Search_Path__wchar_t_system_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_64a.c:52
- 结论: The code uses a hardcoded command string without a full path, and passes it to a sink function that likely executes the command via system(), allowing an attacker to hijack execution by modifying the search path (CWE-426). Although the command string is constant (not user-controlled), the missing full path still enables exploitation if the attacker can influence the search path, making the vulnerability valid but of lower practical exploitability.
- D验证: confirmed / ver_5a3a9eee
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 185. hyp_path_33fb7ed7a64e

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_84a.cpp:30
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者若能控制 data 来源（实际为本地常量），但当前无外部输入。
- 触发路径: char dataBuffer[100] = ""; data = dataBuffer; CWE426_Untrusted_Search_Path__char_popen_84_case0 * case0Object = new CWE426_Untrusted_Search_Path__char_popen_84_case0(data); delete case0Object; @ L28-32; 假设存在 poppen(data) 调用，但当前代码证据未包含。 @ 构造函数内部（未展示）
- 结论: 潜在不受信任搜索路径漏洞，因 data 源自本地缓冲区且未发现受污染输入，但 sink（popen）调用缺失，无法静态确认。
- D验证: confirmed / ver_2f3019ba
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 186. hyp_path_c64e24b5de66

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_84a.cpp:30
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制dataBuffer的内容（实际代码中为固定空字符串，但类内可能从外部输入）
- 触发路径: CWE426_Untrusted_Search_Path__wchar_t_popen_84_case0 * case0Object = new CWE426_Untrusted_Search_Path__wchar_t_popen_84_case0(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_84a.cpp:30; delete case0Object; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_84a.cpp:31
- 结论: 潜在CWE-426漏洞：data可能被用于未信任搜索路径的popen调用，但当前代码片段仅展示对象构造和析构，未直接显示sink调用，证据不完整。
- D验证: confirmed / ver_a8d31a23
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 187. hyp_path_75ca825c54ac

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_21.c:65
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够将恶意可执行文件放置在系统搜索路径中的某个目录（如当前工作目录）或修改PATH环境变量，且该恶意文件与CASE0_OS_COMMAND定义的名称相同。
- 触发路径: data = dataBuffer; case0Static = 1; data = case0Source(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_21.c:60-62; if (SYSTEM(data) <= 0) { ... } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_21.c:65
- 结论: 调用_wsystem(data)时未指定完整路径，命令字符串CASE0_OS_COMMAND为编译时常量，但攻击者仍可通过控制搜索路径（如修改PATH或放入当前工作目录）执行同名恶意可执行文件，构成CWE-426漏洞。
- D验证: confirmed / ver_4b260fdc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 188. hyp_path_21c831c634f4

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_41.c:60
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统的PATH环境变量，或能够将恶意程序放置于当前工作目录或PATH中的某个目录下
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_41.c:59; CWE426_Untrusted_Search_Path__wchar_t_system_41_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_41.c:61; if (SYSTEM(data) <= 0) { ... } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_41.c:48
- 结论: 未指定完整路径而使用_wsystem执行固定命令（CASE0_OS_COMMAND），攻击者可通过控制PATH环境变量或放置恶意程序在PATH目录中劫持命令执行，属于CWE-426不可信搜索路径。
- D验证: confirmed / ver_1397b59c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 189. hyp_path_0cb76a3d35ba

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_82a.cpp:32
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统PATH环境变量或放置恶意可执行文件在搜索路径中
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_82a.cpp:31; baseObject->action(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_82a.cpp:33; popen(data, "r"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_82_case0.cpp (推断)
- 结论: 程序使用未指定完整路径的命令字符串，通过popen执行，导致可能从不受信任的搜索路径加载恶意可执行文件，存在CWE-426 Untrusted Search Path漏洞。
- D验证: confirmed / ver_f75e468c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 190. hyp_path_49359d8500ed

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_82a.cpp:32
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响系统的搜索路径或能够在搜索路径中放置恶意程序，但当前样本未提供该能力，需结合其他漏洞或配置缺陷。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_82a.cpp:31; baseObject->action(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_82a.cpp:33
- 结论: 程序在执行系统命令时未指定完整路径（仅使用命令名），违反CWE-426，存在潜在风险。但当前样本缺乏外部输入控制搜索路径，实际可利用性依赖其他条件。
- D验证: confirmed / ver_bcd3773b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 191. hyp_path_992e4ed35377

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_82a.cpp:32
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量
- 触发路径: data = dataBuffer; /* NOTE: the full path is not specified */ wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_82a.cpp:30; CWE426_Untrusted_Search_Path__wchar_t_popen_82_base* baseObject = new CWE426_Untrusted_Search_Path__wchar_t_popen_82_case0; baseObject->action(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_82a.cpp:32-33; popen(data, ...) 以可执行命令形式调用data，未指定完整路径 @ CWE426_Untrusted_Search_Path__wchar_t_popen_82_case0::action函数内部（推测）
- 结论: 程序使用固定命令字符串但未指定完整路径，通过基类指针调用action函数，该函数内部可能调用popen，导致从PATH环境变量搜索可执行文件，攻击者可通过修改PATH劫持命令执行，构成CWE-426不可信搜索路径漏洞。
- D验证: confirmed / ver_16f44484
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 192. hyp_path_75c59372af24

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_82a.cpp:32
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响环境变量 PATH 或能够在搜索路径中放置恶意可执行文件
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_82a.cpp:31; baseObject->action(data); // 调用 system(data) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_82a.cpp:33
- 结论: 程序在调用 system 函数时未指定命令的完整路径，仅使用命令名称（如 "cmd.exe" 或类似），可能依赖于环境变量 PATH 来定位可执行文件。如果攻击者能够控制 PATH 环境变量或在搜索路径中放置恶意程序，则可能导致执行任意命令。
- D验证: confirmed / ver_47c2a4a4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 193. hyp_path_efa7f807a82f

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_42.c:58
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统PATH环境变量或在与程序相同的目录下放置同名恶意可执行文件，使得SYSTEM调用执行攻击者控制的程序。
- 触发路径: static wchar_t * case0Source(wchar_t * data) { wcscpy(data, CASE0_OS_COMMAND); return data; } @ case0Source函数 (行43-48); data = case0Source(data); @ 调用处 (行55); if (SYSTEM(data) <= 0) { ... } @ SYSTEM调用 (行58)
- 结论: 程序调用system()时未指定可执行文件的完整路径，存在不受信任的搜索路径漏洞(CWE-426)。命令字符串为固定常量，攻击者需能修改系统PATH环境变量或放置同名恶意文件方可利用，利用难度较高。
- D验证: confirmed / ver_d80d5215
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 194. hyp_path_804e5c8c49b2

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_81a.cpp:31
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量PATH或影响命令搜索路径
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_81a.cpp:31; baseObject.action(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_81a.cpp:33
- 结论: 代码使用未指定完整路径的命令字符串（CASE0_OS_COMMAND）调用popen（通过action），攻击者可能通过操纵PATH或类似机制劫持命令执行路径，导致任意命令执行。静态证据不完整，sink调用未显式确认，但CWE分类和测试用例名称暗示popen调用，符合CWE-426特征。
- D验证: confirmed / ver_981236e8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 195. hyp_path_c23cbd8df9c1

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_81a.cpp:31
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或当前工作目录，使得搜索路径中包含恶意程序。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_81a.cpp:31; baseObject.action(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_81a.cpp:33
- 结论: 程序使用未指定完整路径的命令字符串调用系统执行函数，可能通过不受信任的搜索路径执行恶意程序，导致权限提升或代码执行。
- D验证: confirmed / ver_dcba6708
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 196. hyp_path_ad7128f061e6

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_81a.cpp:31
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统环境变量 PATH，或能够将同名的恶意可执行文件放置在搜索路径中的某个目录下（优先级高于系统目录）。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_81a.cpp:30; baseObject.action(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_81a.cpp:31
- 结论: 在调用 system 或类似函数时，未指定命令的完整路径，导致使用不可信搜索路径（CWE-426）。攻击者可通过修改 PATH 环境变量或放置同名恶意程序来执行任意命令。
- D验证: confirmed / ver_637d7b91
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 197. hyp_path_7e10f5383f06

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_81a.cpp:31
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改目标系统的PATH环境变量或提供恶意同名程序在搜索路径中
- 触发路径: data = dataBuffer; /* NOTE: the full path is not specified */ wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_81a.cpp:29-30; const CWE426_Untrusted_Search_Path__wchar_t_popen_81_base& baseObject = CWE426_Untrusted_Search_Path__wchar_t_popen_81_case0(); baseObject.action(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_81a.cpp:31-33
- 结论: 程序未指定可执行文件的完整路径，将命令字符串传递给抽象基类的action方法，该方法后续可能通过popen等系统调用执行命令，导致攻击者可通过修改PATH环境变量劫持命令执行，符合CWE-426不可信搜索路径漏洞。
- D验证: confirmed / ver_17a50fba
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 198. hyp_path_f67f6962cda5

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_44.c:67
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改当前进程的PATH环境变量（例如通过本地访问或恶意进程影响）
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_44.c:67; funcPtr(data); // 指向popen @ 同一函数内函数指针调用
- 结论: 应用程序在使用popen执行命令时未指定完整路径，导致不可信搜索路径漏洞，攻击者可通过修改PATH环境变量执行恶意程序。
- D验证: confirmed / ver_1280184a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 199. hyp_path_eb35770c5c7c

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_65a.c:56
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响PATH环境变量，或在当前工作目录下放置恶意程序。
- 触发路径: data = dataBuffer; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_65a.c:54; strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_65a.c:56; funcPtr(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_65a.c:57
- 结论: 程序使用popen函数时未指定命令的完整路径，依赖于搜索路径，可能被攻击者利用环境变量或当前目录中的恶意程序替换执行。
- D验证: confirmed / ver_2656ded1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 200. hyp_path_6e8c75199531

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_44.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改环境变量 PATH（通常需要本地访问或通过其他漏洞提升权限）; 或攻击者能够在搜索路径的某个目录下放置恶意可执行文件
- 触发路径: strcpy(data, CASE0_OS_COMMAND); // 拷贝命令字符串到 data @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_44.c:62; funcPtr(data); // 通过函数指针调用 system(data)，未指定完整路径 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_44.c:63
- 结论: 在 system 调用（通过函数指针）中未指定完整路径，导致不可信搜索路径漏洞（CWE-426）。攻击者可通过修改 PATH 环境变量使程序执行恶意程序。
- D验证: confirmed / ver_f0ad39c7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 201. hyp_path_64275637c864

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_65a.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量
- 触发路径: 入口处定义函数指针 funcPtr = system; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_65a.c:46; data = dataBuffer; strcpy(data, CASE0_OS_COMMAND); funcPtr(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_65a.c:54
- 结论: 函数通过函数指针调用system()时，使用了硬编码的命令字符串但未指定完整路径，依赖环境变量PATH搜索可执行文件，存在不受信任搜索路径漏洞。攻击者若能够修改PATH环境变量，可劫持命令执行恶意程序。
- D验证: confirmed / ver_079d659e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 202. hyp_path_8954daada837

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_44.c:67
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够将恶意可执行文件放置在搜索路径中（如当前目录或PATH环境变量中的目录），并且系统或进程使用该搜索路径来解析命令。; CASE0_OS_COMMAND 为未指定完整路径的命令字符串（如 'cmd.exe'），且无外部输入控制路径。
- 触发路径: data = dataBuffer; /* NOTE: the full path is not specified */ wcscpy(data, CASE0_OS_COMMAND); /* use the function pointer */ funcPtr(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_44.c:65-67; 代码未显示，但根据Juliet测试集模式，该函数内存在_popen调用 @ 函数指针 funcPtr 指向的函数，预期包含 _wpopen(data, L"w") 调用
- 结论: 在调用popen或类似函数时，使用了未指定完整路径的命令字符串，攻击者可能通过放置恶意可执行文件在搜索路径中执行任意命令。
- D验证: confirmed / ver_b0d7b7ae
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 203. hyp_path_a271185093a2

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_65a.c:56
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统的PATH环境变量，或通过其他方式控制搜索路径
- 触发路径: data = dataBuffer; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_65a.c:54; wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_65a.c:56; funcPtr(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_65a.c:58
- 结论: 代码通过函数指针调用popen，传入的命令字符串未指定完整路径，仅使用硬编码命令名称，导致搜索路径不可信。攻击者若能够修改系统PATH环境变量，可导致执行恶意程序。
- D验证: confirmed / ver_b741c21e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 204. hyp_path_4c747f462565

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_44.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统PATH环境变量或放置同名恶意程序到搜索路径中
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); /* use the function pointer */ funcPtr(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_44.c:62
- 结论: 代码直接使用未指定完整路径的命令字符串调用system，可能执行恶意可执行文件，违反CWE-426（不可信搜索路径）。
- D验证: confirmed / ver_2537943f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 205. hyp_path_e88965dff28d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_22a.c:57
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统环境变量或当前目录，或通过其他方式影响搜索路径
- 触发路径: data = dataBuffer; CWE426_Untrusted_Search_Path__wchar_t_system_22_case0Global = 1; data = CWE426_Untrusted_Search_Path__wchar_t_system_22_case0Source(data); @ CWE426_Untrusted_Search_Path__wchar_t_system_22a.c:52-54; if (SYSTEM(data) <= 0) { ... } @ CWE426_Untrusted_Search_Path__wchar_t_system_22a.c:57
- 结论: 代码使用_wsystem()执行命令，但未指定可执行文件的完整路径。即使data来自内部source函数，只要它不包含完整路径，攻击者可通过控制环境变量（如PATH）或当前目录来劫持执行，构成CWE-426不可信搜索路径漏洞。
- D验证: confirmed / ver_508aca5d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 206. hyp_path_3c61603e348e

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_65a.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或在当前目录放置恶意可执行文件。; 函数指针funcPtr必须指向system或类似执行外部命令的函数，但该赋值未在证据中显示。
- 触发路径: data = dataBuffer; wcscpy(data, CASE0_OS_COMMAND); funcPtr(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_65a.c:54
- 结论: 程序使用未指定完整路径的命令字符串通过函数指针调用外部命令，攻击者可能通过修改PATH环境变量劫持执行恶意程序，导致不可信搜索路径漏洞。但由于函数指针funcPtr的赋值未在提供的代码片段中明确，需要进一步验证其是否指向system或类似执行外部命令的函数。
- D验证: confirmed / ver_676cfee8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 207. hyp_path_8e0104d8c6a4

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_61a.c:54
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响PATH环境变量或当前工作目录; 系统存在可被利用的恶意可执行文件
- 触发路径: if (SYSTEM(data) <= 0) { @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_61a.c:54; data = CWE426_Untrusted_Search_Path__wchar_t_system_61b_case0Source(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_61a.c:51
- 结论: 存在不可信搜索路径导致的命令执行漏洞。代码通过_wsystem()执行data中的命令，且未指定完整路径，攻击者可通过操纵PATH环境变量或当前工作目录使系统执行恶意程序。虽然source函数具体实现未提供，但漏洞模式本身成立，且注释明确指出风险。
- D验证: confirmed / ver_9c8bae68
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 208. hyp_path_f627e07c7442

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_62a.cpp:57
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够通过case0Source函数控制data变量的内容，使其指向恶意可执行文件名称。
- 触发路径: wchar_t dataBuffer[100] = L""; data = dataBuffer; case0Source(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_62a.cpp:52-54; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_62a.cpp:57
- 结论: 使用了_wsystem函数，且未指定可执行文件的完整路径，若case0Source函数引入外部可控数据，则可能导致执行攻击者控制的恶意程序（不可信搜索路径漏洞）。
- D验证: confirmed / ver_faff5f86
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 209. hyp_path_e79f176f68c2

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_21.c:53
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统环境变量PATH，或通过其他方式影响动态链接器的搜索路径。
- 触发路径: 入口函数case0Source开始 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_21.c:48; strcpy(data, CASE0_OS_COMMAND); // 复制固定常量，未指定完整路径 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_21.c:53; popen(data, ...); // 使用未指定完整路径的命令执行 @ 后续popen调用（未在当前片段展示，但据CWE426用例上下文，应有popen(data, "r")或类似调用）
- 结论: 程序在调用popen执行命令时未指定完整路径，使用了固定常量命令字符串（CASE0_OS_COMMAND），导致不可信搜索路径漏洞。攻击者可通过修改PATH环境变量将恶意程序伪装成同名的合法命令，从而在popen执行时被调用。尽管命令字符串本身不可控，但搜索路径的外部影响仍构成安全风险。
- D验证: confirmed / ver_5cf898e2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 210. hyp_path_954f69a9aca1

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_42.c:48
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或当前工作目录。; 程序未对data进行完整路径校验。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); return data; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_42.c:48; popen(data, ...) @ （未提供实际行号，需查看完整样本）
- 结论: 在case0Source函数中，未指定完整路径的命令字符串被复制到data并返回，随后该字符串可能被用于popen等系统调用，导致不可信搜索路径漏洞（CWE-426）。攻击者可通过修改PATH环境变量劫持程序执行的命令。
- D验证: confirmed / ver_42fabf84
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 211. hyp_path_01c8f9e81e73

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_22b.c:45
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统PATH环境变量，或能在搜索路径中放置同名恶意程序。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_22b.c:45
- 结论: 代码将未指定完整路径的常量命令字符串赋值给变量data，后续可能用于popen等执行函数。攻击者若控制系统PATH环境变量，可劫持命令执行，导致任意命令执行。尽管source为常量，但CWE-426的核心风险仍存在，且Popen函数会依赖PATH查找可执行文件。
- D验证: confirmed / ver_35c9da1c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 212. hyp_path_1586f9d87b57

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_61b.c:48
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制CASE0_OS_COMMAND的内容或通过环境变量影响搜索路径。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_61b.c:48; return data; // data被用于popen @ 同一函数返回处
- 结论: 函数返回未指定完整路径的命令字符串，可能被用于popen等函数执行，导致不可信搜索路径攻击（CWE-426）。
- D验证: confirmed / ver_9d7c301a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 213. hyp_path_38e827311e69

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_21.c:51
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量PATH或放置恶意程序在系统搜索路径中。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); // 直接复制未指定路径的命令 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_21.c:51
- 结论: 代码使用未指定完整路径的命令（CASE0_OS_COMMAND），攻击者可通过修改环境变量PATH劫持命令执行，构成CWE-426不可信搜索路径漏洞。
- D验证: confirmed / ver_ff38f83d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 214. hyp_path_6dee6a87caf6

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_42.c:46
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响系统搜索路径（如PATH环境变量）; 后续代码使用返回的data调用system()等执行命令
- 触发路径: strcpy(data, CASE0_OS_COMMAND); return data; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_42.c:46
- 结论: 代码中复制操作系统命令(CASE0_OS_COMMAND)到data，但未指定完整路径，违反CWE426（不可信搜索路径）。虽然当前片段未显示执行该命令的sink（如system调用），但根据测试用例上下文，后续很可能通过system()等执行，导致攻击者可能通过劫持搜索路径执行任意命令。
- D验证: confirmed / ver_1da4e27f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 215. hyp_path_d9b1e70fc9c5

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_21.c:53
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改或控制PATH环境变量; 程序运行环境中搜索路径可被攻击者影响
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); // 复制未指定完整路径的命令 @ L53
- 结论: 未指定完整路径的字符串被复制到data中，随后可能被popen使用，导致CWE426不可信搜索路径漏洞。攻击者可通过修改PATH环境变量劫持命令执行。
- D验证: confirmed / ver_090e006d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 216. hyp_path_358b0f12210a

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_61b.c:46
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统环境变量PATH，使得恶意程序可被搜索到并优先于系统命令执行
- 触发路径: strcpy(data, CASE0_OS_COMMAND); return data; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_61b.c:46; system(data); @ 假设的system调用（基于CWE426用例预期存在，但当前片段未展示）
- 结论: 此代码片段通过strcpy构造固定命令字符串（未指定完整路径），根据CWE-426用例结构预期传递给system函数执行，可能导致攻击者通过修改PATH环境变量执行恶意命令，属于不可信搜索路径漏洞。当前片段仅包含source，sink未在代码中直接展示，证据不完整但漏洞假设合理。
- D验证: confirmed / ver_b8e10e9c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 217. hyp_path_ef1e61b88208

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_22b.c:45
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统 PATH 环境变量或影响搜索路径的配置，使得 CASE0_OS_COMMAND 指向的恶意可执行文件被优先加载; 程序后续使用 data 调用 _wpopen 或类似函数执行命令（当前证据缺失，需验证）
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_22b.c:45
- 结论: 虽然当前代码证据仅包含 source 步骤（wcscpy 复制未指定完整路径的命令），但样本路径和后缀名暗示后续将调用 popen 执行 data，可能构成 CWE-426 漏洞。需要动态验证或补充 sink 代码以完全确认。
- D验证: confirmed / ver_b393bb32
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 218. hyp_path_5c51b737b9f5

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_61b.c:48
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改或控制系统的PATH环境变量（例如通过子进程继承或本地提权）。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); /* NOTE: the full path is not specified */ @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_61b.c:48; popen(data, L"w"); @ 调用者中popen调用（如juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_61a.c）
- 结论: 程序使用未指定完整路径的命令字符串（CASE0_OS_COMMAND），随后将该字符串传递给popen函数。这可能导致系统通过PATH环境变量搜索可执行文件，攻击者若控制PATH可以替换为恶意程序，造成任意代码执行。
- D验证: confirmed / ver_ed4d5825
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 219. hyp_path_25aa79d7ed73

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_42.c:48
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统PATH或当前工作目录，创建同名恶意程序。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); return data; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_42.c:48
- 结论: 函数返回未指定完整路径的命令字符串，违反CWE-426安全编码规范，下游若调用popen等API且搜索路径可控，可能导致执行恶意程序。
- D验证: confirmed / ver_fcb25b0f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 220. hyp_path_33ae903192e1

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_22b.c:45
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够通过环境变量或路径重定向控制可执行文件搜索路径
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_22b.c:45
- 结论: 通过wcscpy将不可信搜索路径命令复制到data中，未指定完整路径，违反了CWE426不可信搜索路径，可能导致后续system调用时执行恶意命令。
- D验证: confirmed / ver_bbf80a36
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 221. hyp_path_c5693fc5cfee

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_21.c:51
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统PATH环境变量或影响命令搜索路径
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_21.c:51; 推测：system(data); @ 后续调用（如system(data)）在另一函数中（推测但未提供证据）
- 结论: 存在CWE426（不可信搜索路径）漏洞的潜在可能，因为代码中使用wcscpy将常量CASE0_OS_COMMAND复制到data，未指定完整路径。但当前证据中未包含system()调用，sink缺失，无法完整确认漏洞。需要补充system()等执行函数的调用证据或动态验证。
- D验证: confirmed / ver_31e30be3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 222. hyp_path_d7ce746f2fed

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_42.c:46
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或控制当前工作目录
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); return data; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_42.c:44-48
- 结论: 函数case0Source返回未指定完整路径的命令字符串，违反CWE-426规范，可能被后续调用者用于执行外部命令（如system），攻击者可通过修改PATH环境变量劫持执行。当前代码仅展示source部分，未展示sink，但根据Juliet测试用例设计，后续有system调用，漏洞路径存在但未完全闭合。
- D验证: confirmed / ver_86d94835
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 223. hyp_path_2279c83f9cc9

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_61b.c:46
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或在当前目录放置同名恶意程序
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); return data; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_61b.c:44-46
- 结论: 函数返回未指定完整路径的命令字符串，后续可能通过system等函数执行，导致不可信搜索路径攻击（CWE-426）。当前代码片段仅展示source，缺少sink调用闭合，但路由命名暗示存在system调用。
- D验证: confirmed / ver_cceab252
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 224. hyp_path_d370018b77f9

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_43.cpp:60
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响系统的PATH环境变量
- 触发路径: wchar_t dataBuffer[100] = L""; data = dataBuffer; case0Source(data); @ CWE426_Untrusted_Search_Path__wchar_t_system_43.cpp:55-57; if (SYSTEM(data) <= 0) { ... } @ CWE426_Untrusted_Search_Path__wchar_t_system_43.cpp:60
- 结论: 代码中调用_wsystem()函数时未指定可执行文件的完整路径，允许攻击者通过控制PATH环境变量执行恶意程序，违反CWE-426不可信搜索路径安全契约。
- D验证: confirmed / ver_4a64bc7a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 225. hyp_path_cb57408c1c09

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_12.c:51
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量（如 PATH）或当前目录，使系统在解析命令时优先执行恶意程序。
- 触发路径: wchar_t dataBuffer[100] = L""; data = dataBuffer; @ CWE426_Untrusted_Search_Path__wchar_t_system_12.c:46-47; if(globalReturnsTrueOrFalse()) { /* NOTE: the full path is not specified */ wcscpy(data, CASE0_OS_COMMAND); } @ CWE426_Untrusted_Search_Path__wchar_t_system_12.c:48-51; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); } @ CWE426_Untrusted_Search_Path__wchar_t_system_12.c:58-60
- 结论: 程序在某些执行路径上使用了未指定完整路径的命令调用系统函数，可能导致不可信搜索路径攻击，但可利用性依赖于攻击者控制环境变量的能力。
- D验证: confirmed / ver_88193161
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 226. hyp_path_fc5a1467d7f1

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_08.c:65
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响系统环境变量（如PATH）或文件系统（如写入可执行文件到搜索路径）。
- 触发路径: /* NOTE: the full path is not specified */ wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_08.c:63-65; if (SYSTEM(data) <= 0) { ... } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_08.c:69
- 结论: 在调用_wsystem函数时没有指定可执行文件的完整路径，导致使用了不可信搜索路径（CWE-426）。攻击者可以通过修改PATH环境变量或在搜索路径中放置恶意程序来执行任意代码。
- D验证: confirmed / ver_af651ae9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 227. hyp_path_87b0f0f4071a

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_11.c:51
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改环境变量PATH，或者能够在当前工作目录放置恶意可执行文件。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ CWE426_Untrusted_Search_Path__wchar_t_system_11.c:49; if (SYSTEM(data) <= 0) { ... } @ CWE426_Untrusted_Search_Path__wchar_t_system_11.c:54
- 结论: 代码使用system()函数执行命令时未指定完整路径，可能导致搜索路径劫持，攻击者可利用PATH环境变量替换执行恶意程序。尽管B阶段风险评分较低，但CWE-426违反存在，可利用性需动态验证。
- D验证: confirmed / ver_9c4ab6ba
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 228. hyp_path_f44dbf15b170

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_02.c:51
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: Attacker has the ability to modify the search path (e.g., via environment variable) or to place a malicious executable in a directory that is searched before the intended one.
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); // Copies command without full path @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_02.c:51; if (SYSTEM(data) <= 0) // Calls _wsystem with untrusted search path @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_02.c:55
- 结论: CWE426: Untrusted Search Path - The program uses a command string without a full path, allowing an attacker to execute a malicious program by manipulating the search path (e.g., PATH environment variable) or placing a malicious executable in a directory that is searched before the intended one.
- D验证: confirmed / ver_1b753e8c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 229. hyp_path_df2ffeee2c66

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_01.c:49
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制CASE0_OS_COMMAND的内容或影响dataBuffer的初始化; 系统搜索路径中存在攻击者可控的路径，且可放置同名恶意程序
- 触发路径: data = dataBuffer; wcscpy(data, CASE0_OS_COMMAND); // 复制命令字符串，未指定完整路径 @ L47-49; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); } // 执行system调用，可能执行恶意程序 @ L50-52
- 结论: 调用_wsystem函数时未指定执行文件的完整路径，攻击者可能通过篡改命令字符串或利用系统搜索路径执行恶意程序，导致未授权命令执行。
- D验证: confirmed / ver_cce55d39
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 230. hyp_path_a64f19630220

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_03.c:51
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统搜索路径（如修改PATH环境变量）或能够在搜索路径中的可写目录放置恶意可执行文件。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ CWE426_Untrusted_Search_Path__wchar_t_system_03.c:51; if (SYSTEM(data) <= 0) { ... } @ CWE426_Untrusted_Search_Path__wchar_t_system_03.c:55
- 结论: 函数SYSTEM()（可能映射到_wsystem()）使用未指定完整路径的命令字符串，攻击者若能控制系统搜索路径（如修改PATH环境变量）或在搜索路径中放置恶意可执行文件，则可导致不可信搜索路径漏洞（CWE-426）。
- D验证: confirmed / ver_1de78633
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 231. hyp_path_4cbe9a5068db

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_04.c:58
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够将恶意程序放置在系统搜索路径（如当前目录或PATH环境变量中的目录）中，且程序运行时搜索路径包含该目录。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_04.c:58; if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_04.c:62
- 结论: 程序调用_wsystem()执行命令时未指定完整路径，攻击者可能通过将恶意程序放置在搜索路径中来劫持执行。
- D验证: confirmed / ver_94084aa6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 232. hyp_path_f003633fa1f7

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_05.c:58
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统PATH环境变量或通过其他方式在搜索路径中插入恶意可执行文件。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_05.c:56-58; if (SYSTEM(data) <= 0) { ... } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_05.c:62
- 结论: 代码在调用_wsystem执行命令时未指定完整路径，攻击者可通过控制环境变量或在搜索路径中放置恶意程序来执行任意命令，构成CWE-426不可信搜索路径漏洞。
- D验证: confirmed / ver_fc8c386d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 233. hyp_path_6351e59ccc96

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_06.c:55
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量（如PATH）或文件系统，使得系统搜索路径中包含恶意程序。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ CWE426_Untrusted_Search_Path__wchar_t_system_06.c:55; SYSTEM(data); // 实际为_wsystem @ CWE426_Untrusted_Search_Path__wchar_t_system_06.c:59
- 结论: 调用了不安全的系统命令函数_wsystem，未指定可执行文件的完整路径，导致不可信搜索路径漏洞（CWE-426）。攻击者可以通过修改PATH环境变量或放置同名恶意程序来执行任意命令。
- D验证: confirmed / ver_85edca1b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 234. hyp_path_03de0c20507e

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_07.c:57
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响系统搜索路径（例如通过修改环境变量或放置恶意文件在当前工作目录），且目标系统未启用路径安全措施。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); // 将命令字符串复制到data，未指定路径 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_07.c:55-57; if (SYSTEM(data) <= 0) // 调用_wsystem执行data，使用搜索路径 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_07.c:61
- 结论: 程序使用`_wsystem`执行命令时未指定可执行文件的完整路径，导致可能从不可信的搜索路径加载恶意程序，违反CWE-426不可信搜索路径。数据为常量，但攻击者仍可通过操纵搜索路径替换同名程序。
- D验证: confirmed / ver_cac75aca
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 235. hyp_path_b6b2c4b11904

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_09.c:51
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统搜索路径（如修改环境变量PATH）或放置恶意可执行文件到搜索路径中的某个目录。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_09.c:51; if (SYSTEM(data) <= 0) { @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_09.c:55
- 结论: 调用_wsystem()时未指定可执行文件的完整路径，尽管data来自宏常量CASE0_OS_COMMAND而非外部输入，但攻击者仍可能通过控制环境变量PATH影响搜索路径，从而执行恶意程序，违反CWE-426。
- D验证: confirmed / ver_7c5d2f23
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 236. hyp_path_a765e833aa0d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_10.c:51
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响系统的搜索路径（如通过环境变量PATH）; 攻击者能够在搜索路径中放置与目标可执行文件同名的恶意程序
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_10.c:51; if (SYSTEM(data) <= 0) { ... } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_10.c:55
- 结论: 调用`_wsystem()`函数时未指定可执行文件的完整路径，依赖于系统搜索路径，攻击者可能通过篡改PATH环境变量或放置恶意同名可执行文件来执行任意命令。
- D验证: confirmed / ver_966c92d2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 237. hyp_path_3b0be0e9bc32

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_13.c:51
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统搜索路径（如PATH环境变量）或在搜索路径中放置恶意可执行文件。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); /* NOTE: the full path is not specified */ @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_13.c:51; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_13.c:55
- 结论: 函数使用未指定完整路径的命令字符串调用system()，攻击者若能修改搜索路径（如PATH环境变量），则可在搜索路径中放置恶意程序，导致任意命令执行。
- D验证: confirmed / ver_2872f7d7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 238. hyp_path_9721dcc02e2c

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_14.c:51
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统的PATH环境变量或在其可控制的目录中放置与命令同名的恶意可执行文件。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_14.c:51; SYSTEM(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_14.c:55
- 结论: 使用未指定完整路径的命令调用SYSTEM，攻击者可通过修改PATH环境变量或放置恶意可执行文件在搜索路径中，从而执行任意程序。
- D验证: confirmed / ver_3f9be765
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 239. hyp_path_b3be96a8eac7

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_15.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制进入case 6分支的输入（如整数参数或环境变量）; 攻击者能够修改搜索路径（例如通过设置PATH环境变量）或在该路径中放置恶意可执行文件
- 触发路径: switch(controlled_var) { case 6: ... } @ 入口处（推测为外部可控的switch变量）; case 6: wcscpy(data, CASE0_OS_COMMAND); break; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_15.c:50-54; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_15.c:61-65
- 结论: 程序在调用系统命令时未指定绝对路径，导致不可信搜索路径漏洞。攻击者可以通过控制进入case 6分支的输入（如整数参数）选择未指定路径的命令，并进一步修改搜索路径或放置恶意程序来劫持系统命令的执行。
- D验证: confirmed / ver_6b0bd3f2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 240. hyp_path_2de5f73dc0f3

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_16.c:51
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够将恶意程序放置于系统搜索路径中的任意目录（如当前工作目录优先于系统目录）。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); // 复制命令，未指定完整路径 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_16.c:51; if (SYSTEM(data) <= 0) { ... } // 执行命令，使用未指定完整路径的data @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_16.c:54-56
- 结论: 存在不受信任的搜索路径漏洞，代码在调用系统命令时未指定可执行文件的完整路径，攻击者可能通过操纵搜索路径执行恶意程序。
- D验证: confirmed / ver_c8651f7b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 241. hyp_path_542c69f41f9b

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_17.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者需要能够影响可执行文件的搜索路径（例如通过修改环境变量或文件系统权限）。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); // 复制未指定完整路径的命令 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_17.c:52; if (SYSTEM(data) <= 0) // 执行命令，未指定完整路径 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_17.c:56
- 结论: 代码在调用_system函数时未指定可执行文件的完整路径，导致不可信搜索路径漏洞(CWE-426)。攻击者可以通过修改PATH环境变量或在搜索路径中放置同名恶意程序，劫持命令执行。
- D验证: confirmed / ver_5ee12e3e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 242. hyp_path_ca828a31c04d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_18.c:51
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: Attacker can influence the environment (e.g., PATH variable) or has file system write access to directories in the search path.
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); /* NOTE: the full path is not specified */ @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_18.c:51; if (SYSTEM(data) <= 0) { ... } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_18.c:54
- 结论: The code uses '_wsystem()' with a command string that does not specify a full path, allowing an attacker to exploit the untrusted search path (CWE-426) by modifying the PATH environment variable or placing a malicious executable in a directory searched before the intended one.
- D验证: confirmed / ver_a115e212
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 243. hyp_path_b1177632eafe

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_31.c:49
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统环境变量`PATH`或文件系统，使得搜索路径中包含恶意可执行文件。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_31.c:49; SYSTEM(data); // 实际调用系统命令 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_31.c:55
- 结论: 代码使用不受信任的搜索路径执行系统命令。函数`wcscpy`将硬编码的命令字符串`CASE0_OS_COMMAND`复制到`data`，随后调用`SYSTEM(data)`。根据注释，未指定完整路径，攻击者可通过控制搜索路径（例如篡改环境变量`PATH`）来执行恶意程序，导致任意命令执行。
- D验证: confirmed / ver_168e8d04
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 244. hyp_path_276f72b2c22a

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_33.cpp:53
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改进程的PATH环境变量或向当前工作目录写入可执行文件
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); // 复制未指定路径的命令 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_33.cpp:53; if (SYSTEM(data) <= 0) { ... } // 执行未指定路径的命令 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_33.cpp:58
- 结论: 程序调用系统命令时未指定完整路径，导致不可信搜索路径漏洞（CWE-426）。尽管命令字符串来自常量宏CASE0_OS_COMMAND，但未使用绝对路径，攻击者可通过控制PATH环境变量或在工作目录放置同名恶意程序来执行任意代码。
- D验证: confirmed / ver_71f2d371
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 245. hyp_path_28f519740d74

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_34.c:56
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改或控制系统的搜索路径（如PATH环境变量）或将恶意程序放置在当前工作目录等被搜索的位置
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_34.c:56; if (SYSTEM(data) <= 0) { @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_34.c:62
- 结论: 代码使用未指定完整路径的命令字符串执行系统调用，攻击者可通过控制搜索路径中的恶意程序实现命令执行。
- D验证: confirmed / ver_9a163dc4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 246. hyp_path_4a6f6848feeb

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_72b.cpp:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制dataVector中的元素（例如通过外部输入或环境变量），从而在搜索路径中放置恶意程序。
- 触发路径: wchar_t * data = dataVector[2]; /* NOTE: Executing the _wsystem() function without specifying the full path to the executable can allow an attacker to run their own program */ if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_72b.cpp:50-54
- 结论: 使用system函数执行未指定完整路径的命令，且数据源自dataVector（可能受攻击者控制），违反CWE-426不可信搜索路径。
- D验证: confirmed / ver_3d76f675
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 247. hyp_path_057c077d0238

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_73b.cpp:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响dataList中的元素内容，即dataList来源于外部输入（如环境变量或用户输入）
- 触发路径: wchar_t * data = dataList.back(); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_73b.cpp:52; if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_73b.cpp:55
- 结论: 使用不可信搜索路径：调用_wsystem()时未指定完整路径，允许攻击者劫持执行。
- D验证: confirmed / ver_a290e331
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 248. hyp_path_6ad825340d6c

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_32.c:53
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统环境变量（如PATH）或当前工作目录。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_32.c:53; if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_32.c:60
- 结论: 程序使用_wsystem函数执行命令，且未指定完整路径（使用相对路径命令），攻击者可通过修改系统PATH环境变量或当前工作目录，替换所执行的程序，从而执行任意命令。
- D验证: confirmed / ver_ab634004
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 249. hyp_path_38aab089b2a9

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_83_case0.cpp:40
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data参数或修改系统搜索路径以放置恶意程序
- 触发路径: if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ CWE426_Untrusted_Search_Path__wchar_t_system_83_case0.cpp:40
- 结论: 代码使用_wsystem函数执行命令，未指定完整路径，依赖系统搜索路径，存在潜在的任意代码执行风险。但data来源在提供的代码片段中未明确，攻击者能否控制搜索路径或放置恶意程序尚需验证，因此证据不完整。
- D验证: confirmed / ver_09e6a601
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 250. hyp_path_4e3949aa5c16

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_84_case0.cpp:40
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够将恶意程序放置在系统搜索路径（如当前工作目录或PATH环境变量包含的目录）中，且程序调用的_wsystem未使用完整路径。
- 触发路径: if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_84_case0.cpp:40
- 结论: 使用_wsystem函数时未指定可执行文件的完整路径，可能允许攻击者通过控制搜索路径劫持执行恶意程序。
- D验证: confirmed / ver_a734f3d3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 251. hyp_path_bd1de54f9076

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_41.c:47
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制传递给_wsystem()的data参数的内容（通过环境变量、用户输入或其他不可信源）
- 触发路径: if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_41.c:47
- 结论: 调用_wsystem(data)时未指定可执行文件的完整路径，违反了安全API使用原则，存在CWE-426不可信搜索路径漏洞。攻击者可能通过控制环境变量或路径来执行恶意程序。当前证据未明确data来源，但代码本身作为脆弱性示例，注释明确指出了风险。
- D验证: confirmed / ver_3857eebd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 252. hyp_path_7dfd53c3db10

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_44.c:47
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data变量的内容（如通过用户输入、环境变量等）或能够将恶意可执行文件放置在系统搜索路径的某个目录下
- 触发路径: /* NOTE: Executing the _wsystem() function without specifying the full path to the executable ... */ if (SYSTEM(data) <= 0) @ CWE426_Untrusted_Search_Path__wchar_t_system_44.c:45-47
- 结论: 函数_wsystem(data)未指定可执行文件的完整路径，依赖系统搜索路径，攻击者可通过将恶意程序放置在搜索路径中劫持执行。但data变量的来源未在代码片段中明确，其外部可控性缺乏证据，导致漏洞假设的证据不完整。
- D验证: confirmed / ver_555c78fc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 253. hyp_path_e55582cd3b4a

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_45.c:51
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data变量的内容（例如通过输入或环境变量）或能够修改系统PATH环境变量，从而在搜索路径中插入恶意可执行文件。
- 触发路径: if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_45.c:51
- 结论: 在调用SYSTEM函数执行命令时未使用完整路径，攻击者可能通过控制data变量或修改PATH环境变量执行恶意程序，违反CWE-426。但由于source证据缺失，利用路径不完整。
- D验证: confirmed / ver_55dc0cbe
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 254. hyp_path_ea40b57a2076

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_51b.c:49
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制传入函数的数据参数（data），即能够影响_wsystem()调用的命令字符串。当前代码未提供data来源，但作为sink函数，其参数应视为潜在不可信输入。
- 触发路径: CWE426_Untrusted_Search_Path__wchar_t_system_51b_case0Sink 入口，接收参数 data @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_51b.c:45; if (SYSTEM(data) <= 0) { ... } 直接使用 data 调用 system 类函数，未检查完整路径 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_51b.c:49
- 结论: 不可信搜索路径漏洞：函数_wsystem()在未指定完整路径的情况下执行命令，允许攻击者通过控制搜索路径或替换可执行文件执行任意代码。虽然当前代码片段未明确显示data参数的来源，但作为sink函数，其参数应被视为可信输入点，且注释确认了风险。
- D验证: confirmed / ver_da55bd32
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 255. hyp_path_2c49d1568153

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_52c.c:49
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响当前进程的搜索路径（例如通过环境变量PATH或修改当前目录）; 攻击者能够在搜索路径中的某个位置放置恶意的同名可执行文件; data必须来自外部可控源（如用户输入或环境变量）才能触发实际利用
- 触发路径: if (SYSTEM(data) <= 0) {...} @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_52c.c:49
- 结论: 函数_wsystem()调用时未指定可执行文件的完整路径，但data来源未知，无法确认是否受外部控制，存在潜在的不受信任搜索路径漏洞。
- D验证: confirmed / ver_659df2ad
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 256. hyp_path_f45d025c8415

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_53d.c:49
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data变量的内容（需进一步确认），或能够修改系统PATH环境变量
- 触发路径: if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_53d.c:49
- 结论: 调用SYSTEM(data)时未指定可执行文件的完整路径，存在CWE-426未受信搜索路径漏洞。虽然当前静态证据未完全闭合source到sink的数据流，但根据A阶段代码证据，该调用本身违反了安全编码规范，攻击者可能通过控制PATH环境变量或其他方式利用，需进一步动态验证data的可控性。
- D验证: confirmed / ver_4731c6c1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 257. hyp_path_01640720b6fb

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_54e.c:49
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改目标系统的 PATH 环境变量或将恶意程序放置于搜索路径中
- 触发路径: if (SYSTEM(data) <= 0) { ... } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_54e.c:49
- 结论: 程序使用 wchar_t 类型的 system 函数（_wsystem）执行命令，但未指定可执行文件的完整路径，导致攻击者可以通过修改 PATH 环境变量或放置恶意同名可执行文件来执行任意代码，构成不可信搜索路径漏洞。
- D验证: confirmed / ver_4593d883
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 258. hyp_path_11aa3303166c

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_64b.c:51
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改进程搜索路径（如PATH环境变量）或控制data参数指向的字符串
- 触发路径: if (SYSTEM(data) <= 0) { ... } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_64b.c:51
- 结论: 调用_wsystem函数时未指定可执行文件完整路径，违反CWE-426契约，攻击者可能通过控制搜索路径执行恶意程序，但data参数来源未在静态证据中闭合，需动态验证外部可控性。
- D验证: confirmed / ver_02cb04e1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 259. hyp_path_ba510d2bb063

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_63b.c:48
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响环境变量（如PATH）或能够在搜索路径中放置恶意可执行文件; 攻击者能够控制或预测传递给_wsystem()的字符串内容（例如通过命令行参数或配置文件）
- 触发路径: if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_63b.c:48
- 结论: 调用_wsystem()时未指定可执行文件的完整路径，导致不可信搜索路径漏洞（CWE-426）。尽管有错误检查，但攻击者可通过控制环境变量（如PATH）或放置恶意程序在搜索路径中，导致恶意代码被执行。
- D验证: confirmed / ver_9296753b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 260. hyp_path_384c3a9467f7

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_65b.c:47
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响data参数的值（例如通过命令行参数或环境变量）; 系统使用默认搜索路径且攻击者可在其中放置恶意程序
- 触发路径: if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_65b.c:47
- 结论: 在调用_wsystem时使用了不受信任的搜索路径，攻击者可能通过控制data参数在路径搜索中插入恶意可执行文件，导致任意代码执行。
- D验证: confirmed / ver_208ca8c6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 261. hyp_path_f59e273d1d92

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_66b.c:49
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统搜索路径（如通过控制环境变量）或具备搜索路径写入权限。
- 触发路径: if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_66b.c:49; SYSTEM(data)内部调用_wsystem(data)，其中data为未指定完整路径的命令字符串。 @ 同文件外部或系统调用
- 结论: 程序使用_wsystem()函数执行命令时未指定可执行文件的完整路径，允许攻击者通过控制搜索路径（如修改PATH环境变量）执行任意恶意程序，构成CWE-426不受信任的搜索路径漏洞。
- D验证: confirmed / ver_0532dee5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 262. hyp_path_d1afdba6513e

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_67b.c:53
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制传递给_wsystem的data参数（如通过环境变量或输入）或修改搜索路径（如PATH环境变量）
- 触发路径: if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_67b.c:53
- 结论: 程序使用_wsystem()函数执行命令，未指定可执行文件的完整路径，存在CWE-426不可信搜索路径漏洞的潜在风险。尽管当前证据未展示data参数的来源，但代码注释明确指出了风险，且错误处理未防御路径操纵。
- D验证: confirmed / ver_04409b36
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 263. hyp_path_f43dda957346

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_68b.c:53
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制传递给_wsystem的data参数（例如通过环境变量或用户输入）
- 触发路径: if (SYSTEM(data) <= 0) @ CWE426_Untrusted_Search_Path__wchar_t_system_68b.c:53
- 结论: 调用_wsystem时未指定可执行文件的完整路径，允许攻击者通过控制搜索路径执行恶意程序，存在不可信搜索路径漏洞。
- D验证: confirmed / ver_5f001ae4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 264. hyp_path_355298708d45

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_81_case0.cpp:34
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统环境变量PATH或在与程序相同的目录下放置同名恶意可执行文件。
- 触发路径: if (SYSTEM(data) <= 0) { printLine("command execution failed!"); exit(1); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_81_case0.cpp:34
- 结论: 程序调用_wsystem()函数时未指定可执行文件的完整路径，导致可能执行攻击者控制的恶意程序，违反CWE426 Untrusted Search Path。
- D验证: confirmed / ver_18370ee1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 265. hyp_path_3a861987ab7a

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_82_case0.cpp:34
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或在搜索路径中放置恶意程序。; data参数必须受外部影响（如从环境变量或用户输入获取），但此条件未得到代码证据支持。
- 触发路径: if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_82_case0.cpp:34
- 结论: 调用_wsystem函数时未指定可执行文件的完整路径，可能允许攻击者通过修改搜索路径执行恶意程序，但当前证据无法确认data参数的来源是否受外部控制。
- D验证: confirmed / ver_ce5a6273
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 266. hyp_path_1dae66e0be15

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_45.c:69
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响系统 PATH 环境变量，或者在用户可写路径下放置与命令同名的恶意程序。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_45.c:69; case0Sink(); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_45.c:71; pipe = POPEN(data, "wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_45.c:55
- 结论: 代码中使用 popen 函数执行命令，未指定可执行文件的完整路径，仅使用固定命令名称 CASE0_OS_COMMAND。虽然源是固定字符串，但违反了 CWE-426 关于不可信搜索路径的要求，攻击者若具有修改 PATH 环境变量的能力，仍可导致执行任意代码。
- D验证: confirmed / ver_e5f43f48
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 267. hyp_path_1361d89b7508

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_66a.c:55
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统搜索路径（如通过环境变量）或在搜索路径中放置恶意程序。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ CWE426_Untrusted_Search_Path__char_popen_66a.c:55; dataArray[2] = data; @ CWE426_Untrusted_Search_Path__char_popen_66a.c:57; CWE426_Untrusted_Search_Path__char_popen_66b_case0Sink(dataArray); @ CWE426_Untrusted_Search_Path__char_popen_66a.c:58
- 结论: 程序使用未指定完整路径的命令字符串，通过popen执行，可能被攻击者利用搜索路径劫持执行恶意程序。
- D验证: confirmed / ver_4709e81c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 268. hyp_path_3b7cc8c1579a

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_68a.c:57
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: Attacker can control the PATH environment variable or the search path used by the system to locate the executable specified in CASE0_OS_COMMAND.
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_68a.c:57; CWE426_Untrusted_Search_Path__char_popen_68b_case0Sink(); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_68a.c:59
- 结论: Untrusted search path vulnerability due to use of relative path or command name without full path in popen call.
- D验证: confirmed / ver_ecd56157
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 269. hyp_path_34dec52dd901

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_67a.c:62
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统搜索路径（如PATH环境变量）或替换指定命令的可执行文件
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_67a.c:60; CWE426_Untrusted_Search_Path__char_popen_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_67a.c:62
- 结论: 函数使用未指定完整路径的命令字符串，通过popen执行，攻击者可能利用搜索路径劫持执行恶意程序，违反CWE426。
- D验证: confirmed / ver_2d476973
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 270. hyp_path_5b518d719d8f

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_45.c:64
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改或控制系统的搜索路径（如PATH环境变量），或在当前工作目录下放置恶意程序。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_45.c:64; case0Sink(); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_45.c:66; if (SYSTEM(data) <= 0) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_45.c:51
- 结论: 代码中调用system()时未指定可执行文件的完整路径，依赖于搜索路径，攻击者可能通过将恶意程序放置在搜索路径中导致任意命令执行。
- D验证: confirmed / ver_89d85227
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 271. hyp_path_2cf4e70ed002

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_66a.c:56
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改目标进程的PATH环境变量（例如通过其他漏洞或本地访问）
- 触发路径: data = dataBuffer; /* NOTE: the full path is not specified */ strcpy(data, CASE0_OS_COMMAND); @ CWE426_Untrusted_Search_Path__char_system_66a.c:51-53; dataArray[2] = data; CWE426_Untrusted_Search_Path__char_system_66b_case0Sink(dataArray); @ CWE426_Untrusted_Search_Path__char_system_66a.c:54-56
- 结论: 程序在调用system（或类似函数）时未指定命令的完整路径，使用了相对路径，违反了CWE-426（不可信搜索路径）。攻击者若能够修改PATH环境变量，可能导致执行恶意程序。
- D验证: confirmed / ver_cc437642
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 272. hyp_path_1a875af3eaa4

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_68a.c:57
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统PATH环境变量或在路径搜索范围内创建同名恶意可执行文件。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_68a.c:55; CWE426_Untrusted_Search_Path__char_system_68b_case0Sink(); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_68a.c:57
- 结论: 代码中使用了未指定完整路径的命令字符串，通过全局变量传递给sink函数，最终调用system()时可能因PATH环境变量劫持导致执行恶意命令。
- D验证: confirmed / ver_c628db67
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 273. hyp_path_087869cbc7a2

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_67a.c:58
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或控制当前工作目录。
- 触发路径: data = dataBuffer; strcpy(data, CASE0_OS_COMMAND); myStruct.structFirst = data; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_67a.c:56-58; CWE426_Untrusted_Search_Path__char_system_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_67a.c:60
- 结论: 代码使用未指定完整路径的命令（相对路径）通过sink函数传递，可能调用system或类似函数，导致不可信搜索路径漏洞，攻击者可通过修改PATH环境变量劫持恶意程序执行。
- D验证: confirmed / ver_3419d580
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 274. hyp_path_42c91587ae66

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_83a.cpp:31
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: Constructor must invoke system() or similar with data; data must be untrusted (e.g., from environment or user input in bad case)
- 触发路径: data = dataBuffer; CWE426_Untrusted_Search_Path__char_system_83_case0 case0Object(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_83a.cpp:29-33
- 结论: POTENTIAL_VULNERABILITY: Untrusted Search Path, but evidence incomplete
- D验证: confirmed / ver_15d28ef9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 275. hyp_path_60f98f46a2a2

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_45.c:71
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者需要控制环境变量 PATH 或能够将恶意程序放置在应用程序搜索路径中的任意位置。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_45.c:69; case0Sink(); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_45.c:71; pipe = POPEN(data, L"wb"); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_45.c:55
- 结论: 程序在执行外部命令时未指定完整路径，导致可能加载恶意程序。
- D验证: confirmed / ver_5ab376f9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 276. hyp_path_558e6529f673

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_67a.c:60
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统PATH环境变量或当前工作目录，或能够将恶意可执行文件放置在搜索路径中。
- 触发路径: data = dataBuffer; wcscpy(data, CASE0_OS_COMMAND); myStruct.structFirst = data; CWE426_Untrusted_Search_Path__wchar_t_popen_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_67a.c:58-62; 推测调用_popen或类似函数，且路径参数来自data，未指定完整路径。 @ sink函数内部（CWE426_Untrusted_Search_Path__wchar_t_popen_67b.c）
- 结论: 程序使用不受信任的搜索路径执行命令，未指定完整路径，攻击者可通过修改PATH环境变量或放置恶意可执行文件导致任意命令执行。
- D验证: confirmed / ver_b32c01fa
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 277. hyp_path_0e06a2ad03dc

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_66a.c:58
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统PATH环境变量，或在可搜索路径中放置同名恶意程序
- 触发路径: data = dataBuffer; wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_66a.c:55; dataArray[2] = data; CWE426_Untrusted_Search_Path__wchar_t_popen_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_66a.c:57-58
- 结论: 发现未信任搜索路径漏洞：程序使用未指定完整路径的命令（CASE0_OS_COMMAND），通过popen执行，攻击者可通过控制PATH环境变量执行恶意程序。
- D验证: confirmed / ver_422d1d1f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 278. hyp_path_53edeb899e6c

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_68a.c:57
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响目标系统的PATH环境变量。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_68a.c:57; CWE426_Untrusted_Search_Path__wchar_t_popen_68b_case0Sink(); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_68a.c:59
- 结论: 代码中使用了未指定完整路径的命令字符串，并通过popen等函数执行，导致可能从不可信搜索路径加载可执行文件，攻击者可通过修改PATH环境变量实现任意命令执行。
- D验证: confirmed / ver_a086b44f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 279. hyp_path_0e13f595828e

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_45.c:64
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响系统搜索路径（如环境变量PATH）
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_45.c:64; case0Sink(); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_45.c:66; if (SYSTEM(data) <= 0) { ... } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_45.c:50-51
- 结论: CWE426_Untrusted_Search_Path: 程序在调用_wsystem()时未指定可执行文件的完整路径，而是仅使用命令名称（CASE0_OS_COMMAND），导致可能利用不可信的搜索路径（如PATH环境变量）执行恶意程序。
- D验证: confirmed / ver_dacc286b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 280. hyp_path_3b41ddc73af4

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_66a.c:53
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或在当前工作目录放置恶意可执行文件
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); /* NOTE: the full path is not specified */ @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_66a.c:53; CWE426_Untrusted_Search_Path__wchar_t_system_66b_case0Sink(dataArray); // 内部调用system(data) @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_66a.c:56
- 结论: 程序使用未指定完整路径的命令（CASE0_OS_COMMAND），通过wchar_t字符串拷贝到dataBuffer，然后传递给system函数，导致可能从不可信的搜索路径加载并执行恶意程序，构成CWE-426漏洞。
- D验证: confirmed / ver_94fd7bcc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 281. hyp_path_176abda31eaf

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_67a.c:58
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统环境变量PATH，使其包含恶意程序所在目录，或能够将恶意程序放置在搜索路径中的某个位置。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_67a.c:58; CWE426_Untrusted_Search_Path__wchar_t_system_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_67a.c:60
- 结论: 程序使用了未指定完整路径的命令字符串，通过CWE426_Untrusted_Search_Path__wchar_t_system_67b_case0Sink函数（预期调用system）执行，可能导致不可信搜索路径漏洞，攻击者可通过修改环境变量PATH来执行恶意程序。
- D验证: confirmed / ver_d92e9e75
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 282. hyp_path_1a103a600e7e

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_68a.c:55
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统或进程的搜索路径（如通过环境变量%PATH%或放置恶意文件到当前工作目录）
- 触发路径: data = dataBuffer; /* NOTE: the full path is not specified */ @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_68a.c:54; wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_68a.c:55; system(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_68b.c:inferred
- 结论: 代码未指定完整路径，使用可执行文件名而非绝对路径，可能导致system()调用时从不受信任的搜索路径加载恶意程序，违反CWE-426。
- D验证: confirmed / ver_0d42bfe8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 283. hyp_path_5d8244f9b477

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_43.cpp:51
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统的PATH环境变量; 或攻击者能够在搜索路径中的可写目录下放置恶意可执行文件
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_43.cpp:51; popen(data, ...); // 基于测试用例名推断 @ 推断：后续popen(data, ...)调用，位置未在证据中展示
- 结论: 在CWE426_Untrusted_Search_Path示例中，strcpy将未指定完整路径的命令CASE0_OS_COMMAND复制到data，测试用例名称暗示后续存在popen调用，但代码片段未展示sink点。尽管证据不完整，该路径仍符合CWE-426定义，攻击者可通过修改PATH或放置恶意可执行文件劫持命令执行。
- D验证: confirmed / ver_0ce41244
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 284. hyp_path_7231d8fe521a

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_53b.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: Attacker controls the 'data' parameter passed to the sink function
- 触发路径: CWE426_Untrusted_Search_Path__char_popen_53c_case0Sink(data); @ CWE426_Untrusted_Search_Path__char_popen_53b.c:52; Actual popen call with data (not shown in evidence) @ CWE426_Untrusted_Search_Path__char_popen_53c.c (inferred)
- 结论: Untrusted search path vulnerability via popen with attacker-controlled data
- D验证: confirmed / ver_3ffa8bdc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 285. hyp_path_8b40c5fe6bce

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_53c.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data参数的内容；data来源需追溯至外部不可信输入
- 触发路径: void CWE426_Untrusted_Search_Path__char_popen_53c_case0Sink(char * data) { CWE426_Untrusted_Search_Path__char_popen_53d_case0Sink(data); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_53c.c:52; popen(data, ...); // 假设存在未校验的popen调用 @ 推测在CWE426_Untrusted_Search_Path__char_popen_53d_case0Sink函数中
- 结论: 函数将外部传入的数据直接传递给另一个函数，该函数可能使用不可信搜索路径调用popen，导致命令执行时路径可控，符合CWE426 Untrusted Search Path漏洞模式。但当前证据未闭合，需进一步验证sink函数实现。
- D验证: confirmed / ver_56ff0bf4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 286. hyp_path_0ab70ebd4435

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_54b.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data参数的值
- 触发路径: void CWE426_Untrusted_Search_Path__char_popen_54b_case0Sink(char * data) { CWE426_Untrusted_Search_Path__char_popen_54c_case0Sink(data); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_54b.c:52; 调用popen(data)或类似函数，未对data进行安全处理 @ 推测的后续调用链中
- 结论: 函数CWE426_Untrusted_Search_Path__char_popen_54b_case0Sink接收参数data并传递给下一个sink函数，最终可能用于popen调用。如果data来自不可信源且未经过验证，则可能导致不可信搜索路径漏洞（CWE-426），攻击者可控制调用路径执行恶意代码。
- D验证: confirmed / ver_79b58a97
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 287. hyp_path_0007a8914718

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_54c.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制传递给函数的data参数（即搜索路径字符串）
- 触发路径: void CWE426_Untrusted_Search_Path__char_popen_54c_case0Sink(char * data) { CWE426_Untrusted_Search_Path__char_popen_54d_case0Sink(data); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_54c.c:52
- 结论: 潜在不可信搜索路径漏洞：数据流从source传递至中间函数，最终可能通过popen调用执行恶意程序
- D验证: confirmed / ver_11777777
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 288. hyp_path_1fc59c34aa52

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_54d.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制传递给该函数的data参数的内容或来源
- 触发路径: CWE426_Untrusted_Search_Path__char_popen_54e_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_54d.c:52
- 结论: 函数通过转发调用另一个函数，未对data进行任何验证，可能导致不可信搜索路径问题（CWE-426），如果data来自外部输入且最终用于popen，则攻击者可控制搜索路径执行任意命令。
- D验证: confirmed / ver_50d8cc31
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 289. hyp_path_9f59256511e1

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_62b.cpp:43
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统PATH环境变量或影响当前工作目录，使搜索路径中的恶意程序优先于预期命令被执行。
- 触发路径: strcpy(data, CASE0_OS_COMMAND); /* NOTE: the full path is not specified */ @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_62b.cpp:43; popen(data, ...); @ 推测为popen调用处（当前证据未提供具体行号）
- 结论: 程序使用未指定完整路径的命令字符串（CASE0_OS_COMMAND），通过strcpy赋值后可能传递给popen，导致命令执行依赖于搜索路径。攻击者可通过控制PATH环境变量或工作目录劫持命令执行。
- D验证: confirmed / ver_ba838807
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 290. hyp_path_8e10aba615ff

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_83_case0.cpp:35
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统搜索路径（如PATH环境变量）或放置同名恶意程序于搜索路径中。
- 触发路径: data = dataCopy; /* NOTE: the full path is not specified */ strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_83_case0.cpp:33-37
- 结论: 程序使用外部命令时未指定完整路径，可能被攻击者利用搜索路径劫持执行恶意程序。
- D验证: confirmed / ver_25590894
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 291. hyp_path_6202e3c49759

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_84_case0.cpp:35
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响dataCopy的值（例如通过输入或环境变量）; 攻击者能够在搜索路径中放置恶意程序
- 触发路径: strcpy(data, CASE0_OS_COMMAND); // data来自dataCopy，未指定完整路径 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_84_case0.cpp:35
- 结论: 可能存在CWE-426未受信搜索路径漏洞：代码通过strcpy将dataCopy复制到data，且注释指出未指定完整路径，后续可能通过popen以不完整路径执行命令，导致攻击者可通过控制环境或路径注入恶意程序。
- D验证: confirmed / ver_5a195e5f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 292. hyp_path_740768755be9

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_52b.c:50
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data字符串的内容，例如通过环境变量或命令行参数
- 触发路径: void CWE426_Untrusted_Search_Path__char_system_52b_case0Sink(char * data) { CWE426_Untrusted_Search_Path__char_system_52c_case0Sink(data); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_52b.c:48-52
- 结论: 函数调用链中存在不可信搜索路径漏洞（CWE-426）。data参数可能来自不可信源并最终传递给system()，但当前证据未展示source和最终sink的具体实现，无法静态确认。
- D验证: confirmed / ver_4f3a0ff6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 293. hyp_path_41439657dfd1

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_53b.c:50
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制传递给函数的data参数
- 触发路径: CWE426_Untrusted_Search_Path__char_system_53c_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_53b.c:50
- 结论: 函数CWE426_Untrusted_Search_Path__char_system_53b_case0Sink直接将参数data传递给后续sink函数，未进行任何有效性验证或路径清理。根据CWE-426定义，若data来源于不受信任的源（如用户输入、环境变量等），则可能导致程序加载恶意可执行文件或库，形成不可信搜索路径漏洞。当前代码仅展示sink部分，缺乏source的直接证据，但鉴于该代码来自针对CWE-426的测试用例，推测data确实来自不可信源。因此，漏洞假设合理，但需要更多source证据或动态验证以完全闭合路径。
- D验证: confirmed / ver_c506a1cf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 294. hyp_path_82d3775b391f

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_53c.c:50
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data参数的内容（如通过环境变量或输入源），并且下游函数最终调用system或exec且使用不受信任的搜索路径
- 触发路径: CWE426_Untrusted_Search_Path__char_system_53d_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_53c.c:50
- 结论: 函数将外部传入的字符串直接传递给下游函数，该下游函数最终会调用system或exec等危险函数，且未限定搜索路径，可能导致攻击者通过控制搜索路径执行恶意程序，存在CWE-426不受信任搜索路径漏洞。
- D验证: confirmed / ver_6872082e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 295. hyp_path_152630248c9b

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_54b.c:50
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 存在外部可控输入（如命令行参数、环境变量等）流入data参数; 最终调用了system()或类似的命令执行函数
- 触发路径: CWE426_Untrusted_Search_Path__char_system_54c_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_54b.c:50
- 结论: 潜在的CWE-426漏洞：不可信搜索路径导致的命令执行，但当前代码证据不完整，缺少从外部输入到sink参数的完整路径及实际的system调用。
- D验证: confirmed / ver_41a4e631
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 296. hyp_path_e9665bd9d697

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_54c.c:50
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制传入函数的参数data，且data来自不可信外部输入（如命令行参数、环境变量等）
- 触发路径: void CWE426_Untrusted_Search_Path__char_system_54c_case0Sink(char * data) { CWE426_Untrusted_Search_Path__char_system_54d_case0Sink(data); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_54c.c:48-52
- 结论: 函数CWE426_Untrusted_Search_Path__char_system_54c_case0Sink接收字符串data并传递给下游函数，若data源自不可信输入且下游最终调用system，则存在CWE-426不可信搜索路径漏洞。但当前证据仅显示中间转发，缺乏source和sink完整路径，因此假设不闭合。
- D验证: confirmed / ver_5a0246b6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 297. hyp_path_785c757f055b

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_62b.cpp:43
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够通过修改环境变量（如PATH）或放置同名恶意可执行文件来劫持命令执行
- 触发路径: strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_62b.cpp:43; system(data); @ 假设后续system调用
- 结论: 函数case0Source中，通过strcpy将CASE0_OS_COMMAND复制到data，但未指定完整路径，后续可能将data传递给system()等函数，导致在不可信的搜索路径中执行命令，构成CWE-426不安全搜索路径漏洞。
- D验证: confirmed / ver_e8093071
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 298. hyp_path_480ad50e573f

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_83_case0.cpp:33
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制dataCopy输入的值。
- 触发路径: data = dataCopy; /* NOTE: the full path is not specified */ strcpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_83_case0.cpp:33
- 结论: 存在不信任的搜索路径漏洞：通过未指定完整路径的命令字符串调用system()，攻击者可能通过控制dataCopy输入来执行任意命令。
- D验证: confirmed / ver_4d496ff4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 299. hyp_path_5be8f69e62c7

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_84_case0.cpp:33
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制传入构造函数的dataCopy参数，或影响环境变量PATH等
- 触发路径: data = dataCopy; @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_84_case0.cpp:29; strcpy(data, CASE0_OS_COMMAND); /* NOTE: the full path is not specified */ @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_84_case0.cpp:33; system(data); @ 后续析构函数或函数中调用system(data)
- 结论: 存在CWE-426不可信搜索路径漏洞：构造函数接收外部数据dataCopy，未指定完整路径直接复制到data中，后续可能用于system调用，导致攻击者可通过控制搜索路径执行恶意程序。
- D验证: confirmed / ver_e99806e7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 300. hyp_path_fe66a3c2ccc8

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_43.cpp:51
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改目标环境的PATH环境变量或在搜索路径中放置恶意可执行文件。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_43.cpp:51; popen(data, ...); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_43.cpp（推断存在popen调用）
- 结论: 代码中使用了未指定完整路径的命令（CASE0_OS_COMMAND），随后通过popen执行，导致攻击者可通过修改PATH环境变量或放置恶意可执行文件来劫持命令执行，存在不可信搜索路径漏洞。
- D验证: confirmed / ver_41cfeea7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 301. hyp_path_c95ded08f092

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_52b.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data参数的内容或来源，但当前证据未展示data来源。
- 触发路径: void CWE426_Untrusted_Search_Path__wchar_t_popen_52b_case0Sink(wchar_t * data) { @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_52b.c:50; CWE426_Untrusted_Search_Path__wchar_t_popen_52c_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_52b.c:52; 假设存在类似: _wpopen(data, mode); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_52c.c (未提供)
- 结论: 不可信数据通过调用链传递给popen函数，可能构成CWE-426不可信搜索路径漏洞，但缺乏data来源的代码证据，路径不完整。
- D验证: confirmed / ver_5b020992
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 302. hyp_path_f86f90e0564f

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_53b.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制传递给sink函数的data参数（例如通过HTTP请求参数或环境变量）。
- 触发路径: void CWE426_Untrusted_Search_Path__wchar_t_popen_53b_case0Sink(wchar_t * data) { CWE426_Untrusted_Search_Path__wchar_t_popen_53c_case0Sink(data); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_53b.c:52; 未知，但推测内部使用popen且无安全处理 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_53c.c (假设存在)
- 结论: 函数CWE426_Untrusted_Search_Path__wchar_t_popen_53b_case0Sink接收未经验证的wchar_t*数据，并直接传递给下游函数CWE426_Untrusted_Search_Path__wchar_t_popen_53c_case0Sink，该下游函数可能使用popen执行命令，且搜索路径未受信任，可能导致攻击者通过控制data参数加载恶意程序。
- D验证: confirmed / ver_64f8f237
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 303. hyp_path_46d93190a2e2

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_53c.c:52
- 漏洞类型: command_injection
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data参数（如通过环境变量、用户输入）
- 触发路径: void CWE426_Untrusted_Search_Path__wchar_t_popen_53c_case0Sink(wchar_t * data) { CWE426_Untrusted_Search_Path__wchar_t_popen_53d_case0Sink(data); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_53c.c:52
- 结论: 函数CWE426_Untrusted_Search_Path__wchar_t_popen_53c_case0Sink传递未经验证的wchar_t* data到下游，结合函数名中的popen暗示，最终可能用于popen执行命令，攻击者可通过控制data导致命令注入，违反CWE426。但当前证据仅显示中转，缺少source和sink具体代码，路径未闭合。
- D验证: confirmed / ver_2b217737
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 304. hyp_path_11d9044c658f

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_54b.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制 data 参数的值，例如通过环境变量或用户输入
- 触发路径: void CWE426_Untrusted_Search_Path__wchar_t_popen_54b_case0Sink(wchar_t * data) { CWE426_Untrusted_Search_Path__wchar_t_popen_54c_case0Sink(data); } @ CWE426_Untrusted_Search_Path__wchar_t_popen_54b.c:50; 推测存在 _wpopen(data, L"w") 等调用 @ 后续 _popen 调用（未在当前片段中显示）
- 结论: 存在 CWE-426 不可信搜索路径漏洞：data 参数来自外部不可信源，通过链式调用最终传递给 _popen 或类似函数，未进行路径验证，可能导致执行恶意程序。
- D验证: confirmed / ver_6a169a8e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 305. hyp_path_ff6494216281

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_54c.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制 data 参数的内容（典型 Juliet 测试用例中 data 来自外部输入如环境变量）
- 触发路径: CWE426_Untrusted_Search_Path__wchar_t_popen_54d_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_54c.c:52
- 结论: 函数 CWE426_Untrusted_Search_Path__wchar_t_popen_54c_case0Sink 接收未受信任的字符串 data，并将其传递给 popen 函数（通过跳转函数 _54d_case0Sink），未对 data 进行路径限制，攻击者可通过控制 data 指定恶意可执行文件，导致任意命令执行。
- D验证: confirmed / ver_4564e5e0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 306. hyp_path_2a24154cc9d5

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_54d.c:52
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制`data`参数，且该参数可能源自不可信输入
- 触发路径: CWE426_Untrusted_Search_Path__wchar_t_popen_54e_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_54d.c:52
- 结论: 基于现有代码片段，存在潜在的CWE426不可信搜索路径漏洞，但证据不完整，需要动态验证。
- D验证: confirmed / ver_a1055621
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 307. hyp_path_c04aa1810de5

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_62b.cpp:43
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改PATH环境变量或在文件系统搜索路径中放置恶意可执行文件
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); // NOTE: the full path is not specified @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_62b.cpp:43; 推测调用如 _wpopen(data, L"w"); @ 推测在同一路由的后续代码中，如CWE426_Untrusted_Search_Path__wchar_t_popen_62b.cpp中其他函数
- 结论: 在CWE426_Untrusted_Search_Path__wchar_t_popen_62b.cpp中，case0Source函数将未指定完整路径的常量字符串CASE0_OS_COMMAND复制到data，违反了CWE-426（不可信搜索路径）。尽管代码证据中未显示sink点（popen调用），但根据测试用例结构，后续将使用data调用popen，导致进程搜索PATH中的恶意可执行文件。
- D验证: confirmed / ver_7004cc61
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 308. hyp_path_334169b3cfe8

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_83_case0.cpp:35
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制系统搜索路径（如通过环境变量PATH）或创建恶意程序在优先路径中
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); // 未指定完整路径 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_83_case0.cpp:35; popen(data, ...) // 文件名暗示存在，但代码证据中未显式提供 @ 推测存在于同一文件或关联代码中（如popen调用）
- 结论: CWE426 Untrusted Search Path: 使用wcscpy将不可信搜索路径的命令复制到data，随后data可能被传递给popen执行，导致攻击者可通过控制搜索路径或放置恶意程序执行任意代码。
- D验证: confirmed / ver_f2351541
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 309. hyp_path_f8e7a6d4bc8a

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_84_case0.cpp:35
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够影响dataCopy的值或环境变量PATH。
- 触发路径: data = dataCopy; /* NOTE: the full path is not specified */ wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_84_case0.cpp:33-35
- 结论: 存在不可信搜索路径漏洞：程序使用popen函数执行命令，但未指定命令的完整路径，攻击者可通过控制搜索路径（如PATH环境变量）执行恶意命令。
- D验证: confirmed / ver_45d55af9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 310. hyp_path_6998e4f6a66d

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_43.cpp:49
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统搜索路径（如设置PATH环境变量）或将恶意可执行文件放置在系统搜索路径的优先目录中。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); // 复制未指定完整路径的命令 @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_43.cpp:49; system(data); // 执行命令，因路径不完整导致搜索路径攻击 @ 推测后续行存在system(data)调用
- 结论: 存在不可信搜索路径漏洞：未指定完整路径，将命令字符串复制到data后可能传递给system调用，导致系统在搜索路径中查找并可能执行恶意程序。当前代码证据仅显示wcscpy复制操作，未展示system调用，但测试用例名称暗示存在system sink，路径不完整。
- D验证: confirmed / ver_aa17a981
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 311. hyp_path_4d4ef1664237

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_53b.c:50
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制 data 参数的内容，例如通过命令行参数、输入或其他攻击向量。
- 触发路径: CWE426_Untrusted_Search_Path__wchar_t_system_53c_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_53b.c:50
- 结论: 函数将不可信数据传递给下游，可能导致不可信搜索路径下的系统命令执行（CWE-426），但当前证据未闭合source-sink路径。
- D验证: confirmed / ver_712e6133
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 312. hyp_path_4d2a79e684ab

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_52b.c:50
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够通过外部输入（如用户输入、环境变量）控制`data`参数
- 触发路径: void CWE426_Untrusted_Search_Path__wchar_t_system_52b_case0Sink(wchar_t * data) { CWE426_Untrusted_Search_Path__wchar_t_system_52c_case0Sink(data); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_52b.c:48-52; 假设内部调用`system(data)`（需确认） @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_52c.c（假设）
- 结论: 函数`CWE426_Untrusted_Search_Path__wchar_t_system_52b_case0Sink`将`data`参数直接传递给下一级函数，最终可能通过`system`调用执行命令。代码中未对`data`进行任何信任边界检查，违反了CWE-426对不可信搜索路径的防范要求。虽然缺少source的直接证据，但根据函数命名和典型Juliet测试用例模式，存在完整的source到sink路径。漏洞路径不闭合，需要动态验证或审计完整调用链。
- D验证: confirmed / ver_335eab6e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 313. hyp_path_c287b5352a58

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_53c.c:50
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制传递给sink函数的data参数，使其指向一个恶意可执行文件名称。
- 触发路径: void CWE426_Untrusted_Search_Path__wchar_t_system_53c_case0Sink(wchar_t * data) { CWE426_Untrusted_Search_Path__wchar_t_system_53d_case0Sink(data); } @ CWE426_Untrusted_Search_Path__wchar_t_system_53c.c:48-52
- 结论: 可能存在不受信任的搜索路径漏洞：data参数最终可能被用于system调用且未指定完整路径，导致执行不受信任的可执行文件。
- D验证: confirmed / ver_00ec0277
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 314. hyp_path_7fd1919e61d8

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_54b.c:50
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够通过环境变量、命令行参数或其他外部输入控制wchar_t * data的值
- 触发路径: CWE426_Untrusted_Search_Path__wchar_t_system_54c_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_54b.c:50
- 结论: 函数CWE426_Untrusted_Search_Path__wchar_t_system_54b_case0Sink接收外部可控的wchar_t指针data，并传递给后续sink，最终可能由system类函数执行。若data源自不可信源（如环境变量）且未经过路径校验，则构成CWE-426不可信搜索路径漏洞，攻击者可执行任意代码。
- D验证: confirmed / ver_7c697ec6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 315. hyp_path_4a36f17cd40b

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_54c.c:50
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制wchar_t *data参数的内容
- 触发路径: CWE426_Untrusted_Search_Path__wchar_t_system_54d_case0Sink(data); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_54c.c:50
- 结论: 潜在的不受信任搜索路径漏洞：函数调用链中的data参数可能传递给system调用，但未经验证
- D验证: confirmed / ver_ffe4dcf5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 316. hyp_path_89fb757d9c0e

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_54d.c:50
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制data参数的值，且data来源于不可信输入
- 触发路径: void CWE426_Untrusted_Search_Path__wchar_t_system_54d_case0Sink(wchar_t * data) { CWE426_Untrusted_Search_Path__wchar_t_system_54e_case0Sink(data); } @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_54d.c:48-52
- 结论: 函数接收的data参数未经验证直接传递给后续函数，根据项目命名和CWE426测试用例结构，后续函数可能将data用于system调用，导致不可信搜索路径漏洞，但下游具体实现未闭合，需动态验证确认。
- D验证: confirmed / ver_6ad4b766
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 317. hyp_path_7a0edeeb841e

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_62b.cpp:43
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统PATH环境变量或在当前工作目录放置与命令同名的恶意程序
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_62b.cpp:43
- 结论: 代码中wcscpy将未指定完整路径的命令字符串复制到data，根据CWE426样本惯例，后续likely存在system(data)调用，导致从不受信任的搜索路径加载可执行文件，攻击者可放置恶意程序到搜索路径实现代码执行。但当前代码片段未展示system调用，证据路径不完整。
- D验证: confirmed / ver_5bb2bc48
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 318. hyp_path_b143c031f383

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_83_case0.cpp:33
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够修改系统环境变量或当前工作目录，使其指向包含恶意命令的路径。
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_83_case0.cpp:33
- 结论: 函数使用相对路径或未指定完整路径调用命令，可能从不可信的搜索路径中执行恶意命令，导致CWE-426不信任的搜索路径漏洞。
- D验证: confirmed / ver_3a21a819
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 319. hyp_path_38470d7c90d3

- 漏洞位置: juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_84_case0.cpp:33
- 漏洞类型: CWE-426
- CWE: CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量PATH，或通过其他方式影响可执行文件搜索路径
- 触发路径: wcscpy(data, CASE0_OS_COMMAND); @ juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_84_case0.cpp:33; system(data); @ 假设在析构函数或action函数中存在system调用，但当前证据未提供具体位置
- 结论: 在构造函数中，未指定完整路径的命令字符串被复制到data，基于测试用例命名和CWE定义，后续析构函数或action函数中很可能存在system(data)调用，导致不可信搜索路径漏洞。攻击者可通过修改PATH环境变量劫持执行恶意程序。
- D验证: confirmed / ver_0999da6b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

## Unconfirmed / Failed Verification

These records are not reported as confirmed vulnerabilities. See `verification.failed.jsonl` for full failure details.

- hyp_path_9b330db895cd | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_21.c:105 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_57085e98bc15 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_41.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d8b614c160fc | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_21.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a1f362237f48 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_42.c:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c80b39715773 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_22a.c:103 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8760a5e2f658 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_22a.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cd7d87964222 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_61a.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2a31e935f33d | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_62a.cpp:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_786b1a512eee | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_43.cpp:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_487a9bb6543e | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_08.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bb55326f5940 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_07.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_16ed106eba50 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_05.c:91 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_423b3bd47738 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_12.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3bc0c2ee4f2d | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_11.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_95ddc1727ce2 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_10.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_87de69d864cc | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_09.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_89dab6ef7b02 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_08.c:118 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b77c4fbb75dd | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_11.c:104 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_de9996e6c558 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_13.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0750dacd50e2 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_14.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a0f81c4c30f8 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_02.c:104 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ea4b98ce40a9 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_02.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b77f28e8b762 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_01.c:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_67d060561c69 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_03.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ba8eda19d894 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_04.c:111 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_12d21a644273 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_04.c:91 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fefcfd3870f3 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_03.c:104 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6983f38778ce | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_05.c:111 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_194ff5c4fcb2 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_06.c:88 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_60356af075be | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_06.c:108 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7cc186afc044 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_07.c:110 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bea4d7672b36 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_09.c:104 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_da88d92d7179 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_10.c:104 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_976544730745 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_13.c:104 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1f435192a89e | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_14.c:104 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c259fce4c994 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_15.c:91 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_624c602a1ab9 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_15.c:117 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d2d0e58ac265 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_16.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_479695eaf287 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_18.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_959dd5b52d5d | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_31.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_98f33a150182 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_17.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_51acca0ef81c | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_72b.cpp:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_183a1d16fa59 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_33.cpp:83 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a573b5e60877 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_34.c:88 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0f798a1d7a7d | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_74b.cpp:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eaafb79e0d69 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_73b.cpp:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f6cf2eff4a57 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_32.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3bafb2384a01 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_83_case1V1.cpp:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dbb6c073ce53 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_84_case1V1.cpp:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_02545ca6011f | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_41.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9f8161bd0c32 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_44.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c0374ca06e46 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_45.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e64f4a741eec | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_51b.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_37a2c46cfbef | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_52c.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3b4033e75d1c | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_53d.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2c0d059e9a8a | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_54e.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7f76646b1440 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_64b.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ff3cafb3d43b | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_63b.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_de65c4190c33 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_65b.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f7066ac5ccd2 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_66b.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_58fb0bb3b079 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_67b.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fb5d35b3c2a4 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_68b.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7c1eb35d6c36 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_81_case1V1.cpp:34 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_add92fe23008 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_82_case1V1.cpp:34 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d7a5adccce67 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_72a.cpp:111 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bf25b444f223 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_72a.cpp:111 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9ece07982afb | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_74a.cpp:464 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3d764c3bcc5c | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_72a.cpp:111 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_200e910fe773 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_74a.cpp:464 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_115b9c9075f0 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_73a.cpp:443 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5f9198a9e4ce | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_73a.cpp:443 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c3e2f8535393 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_74b.cpp:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e8cfd3873245 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_73a.cpp:443 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e5a3ea5c534d | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_74b.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f3613f556f09 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_74b.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0f81ae0913a5 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_21.c:115 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_71047980ce40 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_21.c:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_301adc1b0108 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_42.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1960854e6cde | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_22a.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c3312329fbc3 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_61a.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4cbe7b8c7ad6 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_22a.c:116 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_998ad0daee29 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_62a.cpp:89 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d97a69ce3153 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_22a.c:116 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ca3338624fa3 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_22a.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8e3063737d60 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_61a.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e24faf65976b | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_62a.cpp:89 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8276e53b3f7d | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_12.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7d37bad118e5 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_43.cpp:96 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9a7896326ca7 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_11.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a224668083ba | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_07.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a0711dce4864 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_05.c:101 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c275c574281b | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_43.cpp:96 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d3ccc6eaa500 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_08.c:131 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ae193333b017 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_10.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_144b31776bcf | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_14.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2bfc2bb08a7c | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_13.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_041906ef9eff | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_07.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ec8e5b545e7e | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_08.c:131 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7ad590f754be | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_05.c:101 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_982cbdf0cebf | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_09.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b657f30e5ebc | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_10.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fb45ccbc976d | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_13.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b40dc597b128 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_02.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e5a53df081ed | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_01.c:83 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cb1a6be685f2 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_02.c:117 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_caf2d6545068 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_14.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_afe2256f89ee | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_04.c:101 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3eb227921b5c | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_03.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_452fdd6a5242 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_03.c:117 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a2ed609bc502 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_04.c:124 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f9b376878a15 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_05.c:124 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e263d970f677 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_06.c:121 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_245d6bd7fddb | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_07.c:123 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_96de53faa7a1 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_06.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d0fe45653eb3 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_09.c:117 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_902f1486eae2 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_13.c:117 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_829c5d6023fb | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_10.c:117 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cfd557c9aaf3 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_15.c:101 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2d653b24fc09 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_15.c:130 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_23b73c812e1c | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_14.c:117 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_24d2914213bd | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_16.c:91 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bb35e2365d74 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_17.c:91 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_31f05c9ec8ef | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_18.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1f8e01bdc6db | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_33.cpp:93 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a1d314c6273f | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_34.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3786aec52d8b | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_01.c:83 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c55b753dafcf | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_02.c:117 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_126a3e0b377c | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_03.c:117 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d97a6ff0fb0b | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_02.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_04932e03c4b3 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_03.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_34559bdb2375 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_04.c:101 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_79fa28bff6fd | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_05.c:124 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_508e1e6bc2db | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_04.c:124 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0769286d6bac | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_06.c:121 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_58ee962d1195 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_07.c:123 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_67a2d4f9abbf | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_06.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dc7655aafe7e | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_09.c:117 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f4c754f42018 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_13.c:117 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_caedd4fa5055 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_14.c:117 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_224970e25eb7 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_15.c:130 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dab4de8609cc | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_15.c:101 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_df70a5ac01ec | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_17.c:91 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_54847675c5e8 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_16.c:91 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f415d19cbf32 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_18.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_07dbc979c943 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_31.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d1d54f04d443 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_33.cpp:93 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_64d73c97c4ca | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_72b.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5c264ae241fd | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_34.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3b412feaf1b5 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_72b.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_67a903f13d19 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_73b.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fc2b7df537f6 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_73b.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_976ee12347c9 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_83_case1V1.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c16a1bef8f09 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_32.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8f7df0edc5b8 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_84_case1V1.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_21520aa09ef2 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_32.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f3dfe0782d44 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_83_case1V1.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d7484c045eaf | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_84_case1V1.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_96fa6d1b561a | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_41.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a3890c142195 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_45.c:89 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5050b15dfbbb | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_44.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1d9036e3addf | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_51b.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_746c735da904 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_52c.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d737c40f6832 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_53d.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5c0854e53001 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_54e.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f962f6eefdef | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_63b.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1149c3259494 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_65b.c:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ea949cb83ff3 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_64b.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6d4e8859b729 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_66b.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a027a90d8315 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_67b.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_67362d42c119 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_68b.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e181f341fbd1 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_81_case1V1.cpp:41 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c028edce33d8 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_82_case1V1.cpp:41 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6392861a2539 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_41.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_20d51292afc8 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_44.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ec038f199cb2 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_45.c:89 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b67982023966 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_51b.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0f2aa2e5c3c5 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_52c.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_340b819d90da | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_53d.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5a0b26dbc53e | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_54e.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2971df11167c | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_63b.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9ad31e382687 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_64b.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f401e4b93fd7 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_65b.c:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ec8f8528db60 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_66b.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_018f3a30f143 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_68b.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_94f15ab36100 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_67b.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9104bfe312f4 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_81_case1V1.cpp:41 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dceec32c5a7a | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_82_case1V1.cpp:41 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c9e9abcb8390 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_51a.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3c393a96db50 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_63a.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_616a429ab7af | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_64a.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_37060d32257a | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_54a.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e8aa1069bd81 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_52a.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f6a58a8c83de | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_51a.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4bedb11682ae | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_54a.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dadb9924edbb | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_54a.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_54b68bcbdf29 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_53a.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_654bbf815201 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_52a.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_595c6f5f0877 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_84a.cpp:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_26c12a2b9210 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_41.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f7d7c1c4d8fd | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_42.c:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dd35086f89c5 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_44.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_830aa54e0a7a | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_65a.c:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9f5e98e67a98 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_22a.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3385113610b3 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_22a.c:103 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7a8c93918880 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_61a.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fb3f1e453809 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_62a.cpp:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0697a09cc8fa | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_22b.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_de32d30d5901 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_22b.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_aa70dca50382 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_42.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_29e997a8cce0 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_11.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d7c6152e6785 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_05.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_911ec98ac57c | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_43.cpp:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e73b12c49b08 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_07.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_187511d41dc8 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_12.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ab44c50b4ad5 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_08.c:114 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e865c7ed5736 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_09.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dabff9f27f00 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_11.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0cbdc8c1e8b5 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_14.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_16aebed88ca6 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_10.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_29c42817fb26 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_02.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_652665b1d03e | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_01.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8eecfb022104 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_02.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fd08a64a500b | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_03.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5d645ac7edaa | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_03.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_37dc733e4314 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_04.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b6c55dd28ec4 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_04.c:107 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3156dc4da052 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_05.c:107 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_65913e960611 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_06.c:104 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6e9d86ba7ecd | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_06.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a7112965f9b8 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_07.c:106 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2b621e45b796 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_10.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e511e59abda1 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_09.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_487f8751b339 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_14.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_13c8c3c6e499 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_13.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f8406c9e8f0a | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_15.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_68622fe73083 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_15.c:108 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3f641597fb53 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_16.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_256d0fe9bdcf | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_17.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4c85199949db | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_31.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b2beacfec8be | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_33.cpp:78 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4c2f425e6c34 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_18.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ca3947ad5c99 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_72b.cpp:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_05823881279f | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_73b.cpp:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_58702c64fe63 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_34.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_561097ac496d | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_83_case1V1.cpp:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1baa1dbd710b | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_32.c:83 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_02695a65034b | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_84_case1V1.cpp:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d5780cd895b3 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_41.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4e78e843ed35 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_44.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4c6977eb1a98 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_45.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d7b78a780ceb | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_51b.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_72b2f566a046 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_52c.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_314191b6b71a | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_53d.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_71de72d48f2b | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_63b.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b39d1effa3dd | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_54e.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_93d25a3ef50d | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_64b.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5c36adf5316a | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_65b.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_662dd90ea56d | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_66b.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4b21a50aa6bb | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_67b.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_aa4d089f1e9a | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_68b.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c84447177ffd | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_81_case1V1.cpp:34 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_263b22a40735 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_82_case1V1.cpp:34 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_27ccbff36a3a | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_03.c:125 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0cc93bd099a0 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_07.c:130 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_17161e758efe | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_09.c:125 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1eca10dc05a2 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_08.c:139 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9aa6eb00b8d4 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_21.c:153 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_430fc399ab46 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_13.c:125 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_48b2e4b07493 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_45.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2fddc26b42bb | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_22a.c:123 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0beefdd3fad0 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_66a.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6aad0c3c3f31 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_68a.c:78 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a14fa1361ae5 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_02.c:113 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_750f1c3757a6 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_03.c:114 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2401e0fef9b2 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_07.c:119 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_59df15bf3907 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_05.c:121 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1ee464f2b498 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_06.c:117 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_39bba49b7c38 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_08.c:127 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_010bfbc921ac | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_04.c:121 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_084291865a3d | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_09.c:113 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_24e0d8b6c529 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_13.c:113 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_42f9b85eb258 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_15.c:126 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_21ec892fb69f | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_21.c:141 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ad194da27c74 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_14.c:113 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4f635c306cdb | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_22a.c:112 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_220485354e46 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_45.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_132b3ba86803 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_66a.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2cf291512a81 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_68a.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_829acd37f477 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_06.c:128 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3d309c6647d0 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_11.c:125 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_178239cc23b1 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_10.c:125 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_842c544b338a | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_13.c:124 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_228fad028502 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_15.c:137 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a75da9e6bf30 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_14.c:124 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4d6f4e57bf0f | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_21.c:153 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0e9e070d7697 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_22a.c:124 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3179bf7066e6 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_45.c:102 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_99363d87d372 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_67a.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0b1fb7884f0c | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_68a.c:78 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_977d1270f124 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_03.c:113 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2b6ece49de6f | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_02.c:113 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7c950121244a | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_06.c:117 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6084ab97862f | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_05.c:121 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4927498b7fc5 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_10.c:113 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_63b114580a89 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_08.c:128 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a97ba195c388 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_07.c:120 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5f21ccaf3f4e | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_11.c:114 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_06c21e52fe70 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_14.c:113 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6d8acc3dad10 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_13.c:113 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9893be801377 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_21.c:141 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_89b1add73ff1 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_45.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_457095850261 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_22a.c:112 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4bc46a7ac76d | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_31.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_03b1b8c0471c | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_01.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_07626851c6ae | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_18.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4e517b5c2c61 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_42.c:102 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4004888e9b6b | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_43.cpp:103 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4568c1423ffc | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_45.c:107 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_39d11108b7bb | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_53b.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_faa862217791 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_54c.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dfdc19ead283 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_54b.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eb33e425a5b8 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_54d.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b153c6cf21e3 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_61a.c:93 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_46f120be37cd | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_62a.cpp:96 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_99b12651fd61 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_63a.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_640dcf81c6dc | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_73a.cpp:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_163303d48793 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_82a.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c11c881ac068 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_83a.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b653c4836219 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_popen_84_case1V1.cpp:35 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f2552970124d | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_16.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cbdb1cd7b56e | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_32.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b689d4a87bb6 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_18.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ac5ec6474ef7 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_31.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6963a390030f | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_17.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bfcb52f68906 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_33.cpp:93 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_32826325b891 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_42.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_883a61f3c114 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_43.cpp:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dfd347bcfd3c | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_52b.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5f77078bef80 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_53b.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_088c4046e2c4 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_53c.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_21c66d37cb40 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_54c.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_560e8be3bcb5 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_54b.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7c3911d88210 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_61a.c:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bf9735a1bcf0 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_62a.cpp:88 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_20643a576ca3 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_65a.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_32f42eda289f | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__char_system_68a.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_272cf6deb75a | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_17.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8cbe81df734c | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_16.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fcdf37e9e969 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_12.c:107 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4f9a0c4598a9 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_43.cpp:103 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_767757250188 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_42.c:102 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6cdc706f0321 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_33.cpp:101 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_83502699ee83 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_52b.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a9463b777717 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_54b.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7fcc6fc5d733 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_54c.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ee9c91db1b8f | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_54d.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_609e038e3c7e | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_61a.c:93 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_37deadb44e7f | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_62a.cpp:96 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3ff2f48c1667 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_65a.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_71554beae909 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_81a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6faa2f2776e6 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_popen_84_case1V1.cpp:35 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2aa3cc8f94e9 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_12.c:99 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_56df3c46ad58 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_01.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ff60a762aeb0 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_16.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_baf00a123827 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_31.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f085f7084f90 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_32.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d1a8214be8ec | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_18.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8aec59809505 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_33.cpp:93 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ada4aba349c0 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_34.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0fdf51e3f886 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_42.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_10b8f94d6ca6 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_43.cpp:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e3ce6a442ed0 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_53b.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dc6be6fa80ef | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_52b.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1d91a51d12c9 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_53c.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1aa544fc13b8 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_54b.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d6150cd27f2c | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_54c.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a744e9dbe3e7 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_54d.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_910a87b1330e | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_62a.cpp:88 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1bd19a5d7c38 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_61a.c:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_06832ce1e44b | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_83_case1V1.cpp:33 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9877496c1841 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_82a.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_00c67866f4f9 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/main_linux.cpp:265 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_6adb11a74811 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/CWE426_Untrusted_Search_Path__wchar_t_system_84_case1V1.cpp:33 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_013dee272114 | juliet-api-misuse/testcases/CWE426_Untrusted_Search_Path/main.cpp:553 | NOT_ROUTE_BOUND | payload did not satisfy oracle
