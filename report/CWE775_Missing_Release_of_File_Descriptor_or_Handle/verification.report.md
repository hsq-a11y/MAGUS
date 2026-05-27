# MAGUS Final Vulnerability Report

- generated_at: 2026-05-26T07:04:38Z
- reportable_vulnerabilities: 185
- d_confirmed_vulnerabilities: 185
- stage_c_preserved_vulnerabilities: 0
- failed_verifications: 301
- source_confirmed: /home/sq_hu/MAGUS/d/memberD_verifier/02_run_with_C/output/CWE775_Missing_Release_of_File_Descriptor_or_Handle/verification.jsonl
- source_failed: /home/sq_hu/MAGUS/d/memberD_verifier/02_run_with_C/output/CWE775_Missing_Release_of_File_Descriptor_or_Handle/verification.failed.jsonl

## Confirmed Vulnerabilities

### 1. hyp_path_1f4b762f85f9

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22a.c:43
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序多次调用该路由或长时间运行，最终耗尽文件描述符资源。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22a.c:43
- 结论: 在函数中打开文件后未关闭，导致文件描述符泄漏，违反CWE-775 Missing Release of File Descriptor or Handle after Effective Lifetime。
- D验证: confirmed / ver_f2134408
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 2. hyp_path_2e5ae73dce61

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_72a.cpp:50
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者可能通过多次请求触发此代码路径，从而累积未关闭的文件句柄
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); dataVector.insert(dataVector.end(), 1, data); dataVector.insert(dataVector.end(), 1, data); case0Sink(dataVector); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_72a.cpp:48-52
- 结论: 在函数CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_72a::case0中，通过CreateFileA打开文件句柄后，未调用CloseHandle释放句柄，导致资源泄露（文件句柄未被释放），可能被攻击者利用造成资源耗尽。
- D验证: confirmed / ver_3ee659c7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 3. hyp_path_12dcd89feb78

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_72a.cpp:51
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 代码自身逻辑，无需攻击者输入；文件描述符泄漏累积可导致拒绝服务。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_72a.cpp:49; dataVector.insert(dataVector.end(), 1, data); dataVector.insert(dataVector.end(), 1, data); case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_72a.cpp:51; sink函数中未调用close()关闭文件描述符 @ case0Sink函数（未显示close调用）
- 结论: 在CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_72a.cpp中，通过open()打开文件描述符后，未在后续代码中调用close()释放文件描述符，导致文件描述符泄漏。
- D验证: confirmed / ver_a44dae28
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 4. hyp_path_a09e35f8a990

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_51a.c:40
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序能够正常执行到第40行代码，且文件打开成功。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_51a.c:40; CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_51a.c:40
- 结论: 文件描述符未释放：程序调用OPEN()打开文件后未调用close()关闭文件描述符，导致资源泄露。
- D验证: confirmed / ver_bbcde3c4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 5. hyp_path_e14e566230ac

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_52a.c:40
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无特殊前提条件，代码路径直接触发开放文件描述符未关闭。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_52a.c:40
- 结论: 文件描述符未释放，违反API contract：open()后未调用close()，导致文件描述符泄漏。
- D验证: confirmed / ver_0d91d2ff
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 6. hyp_path_1e226d8c001a

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_53a.c:40
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 代码路径被执行，OPEN调用成功
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_53a.c:40; CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_53b_case0Sink(data); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_53a.c:40
- 结论: 在CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_53a.c中，OPEN打开文件后未关闭，直接传递给sink函数，且sink函数惯例不会释放文件描述符，导致资源泄漏。虽sink函数实现未直接提供，但根据CWE测试用例设计模式，此路径构成CWE-775漏洞。
- D验证: confirmed / ver_e43cbb4f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 7. hyp_path_7cbb1b114ffb

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54a.c:40
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者无需控制输入；漏洞由代码自身逻辑缺陷导致，但影响程序稳定性或资源耗尽。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54a.c:40; CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54a.c:40
- 结论: 文件描述符未关闭导致资源泄漏：open() 打开文件后，未调用 close() 关闭描述符，违反了 CWE775 关于文件描述符或句柄必须释放的规则。虽然 open 参数为固定字符串，但漏洞由逻辑缺陷导致，无需外部输入控制。
- D验证: confirmed / ver_0d87fc6c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 8. hyp_path_ce026fa0ef63

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_63a.c:40
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 系统能够成功打开指定文件（OPEN返回非-1的合法文件描述符）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_63a.c:40
- 结论: 在CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_63a.c中，第40行调用OPEN()打开文件后，将文件描述符传递给sink函数CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_63b_case0Sink，但sink内部实现未知，且A阶段证据表明注释明确提示不关闭文件，结合CWE-775模式，极大概率存在文件描述符未释放的漏洞。
- D验证: confirmed / ver_c93f8542
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 9. hyp_path_8d1c340b4688

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_64a.c:40
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者无需控制输入，文件路径固定，漏洞存在于正常执行路径。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_64a.c:40
- 结论: 文件描述符未释放：OPEN() 打开文件后，文件描述符被传递给 CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_64b_case0Sink 函数，但该函数未关闭文件描述符，导致资源泄漏。
- D验证: confirmed / ver_d1276c41
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 10. hyp_path_84085df42d34

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_22a.c:42
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行该路径，且sink函数内不关闭句柄
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_22a.c:34; CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_22_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_22a.c:42
- 结论: 调用CreateFile打开文件后未关闭句柄，导致资源泄漏，违反CWE775（未释放文件描述符或句柄）。
- D验证: confirmed / ver_d34508cc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 11. hyp_path_4c7a378bc3c2

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_51a.c:39
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序以正常权限运行，CreateFile调用成功，且后续没有关闭句柄的代码路径
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_51a.c:30-34; CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_51a.c:37-41
- 结论: 在CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_51a.c中，CreateFile打开文件后未关闭句柄，导致文件描述符泄漏。
- D验证: confirmed / ver_435ba750
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 12. hyp_path_98ff4c610701

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53a.c:39
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 代码正常执行该路径，无需攻击者控制输入
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53a.c:30-34; CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53a.c:37-39
- 结论: 文件句柄未关闭导致资源泄漏：CreateFile 创建了文件句柄，但在后续调用 Sink 函数后未调用 CloseHandle 释放句柄，违反 CWE775。
- D验证: confirmed / ver_26e309b6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 13. hyp_path_282af73c99a2

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52a.c:39
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: CreateFile执行成功（返回非INVALID_HANDLE_VALUE）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52a.c:30-34; CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52a.c:39
- 结论: 在函数CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52_case0中，通过CreateFile打开文件后未关闭，导致文件句柄泄漏（CWE-775 Missing Release of File Descriptor or Handle）。
- D验证: confirmed / ver_bf1fd484
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 14. hyp_path_788da9bf6633

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54a.c:39
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无需攻击者控制输入；文件句柄在函数返回后未被关闭。
- 触发路径: data = INVALID_HANDLE_VALUE; data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54a.c:30-34; CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54a.c:37-41
- 结论: CreateFile打开文件后未关闭句柄，导致文件句柄泄漏（CWE-775）。
- D验证: confirmed / ver_3c22dd41
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 15. hyp_path_971aa7198cf5

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_64a.c:39
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: No special precondition; the code path is always executed when the function is called.
- 触发路径: FILE_ATTRIBUTE_NORMAL, NULL); CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_64b_case0Sink(&data); } @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_64a.c:39
- 结论: The code opens a file handle via CreateFile() but never closes it, leading to a resource leak (missing release of file handle).
- D验证: confirmed / ver_a2037e01
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 16. hyp_path_2db3172dd8fa

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_63a.c:39
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: CreateFile调用成功，返回有效句柄
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_63a.c:30-34; CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_63a.c:37-41
- 结论: CreateFile返回的文件句柄未被关闭，导致文件句柄泄漏，违反CWE775（Missing Release of File Descriptor or Handle）
- D验证: confirmed / ver_8a969c75
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 17. hyp_path_24e8ea99cad1

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_74a.cpp:51
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行到 open() 调用，且后续没有 close() 调用。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); dataMap[0] = data; dataMap[1] = data; dataMap[2] = data; case0Sink(dataMap); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_74a.cpp:49-53
- 结论: 文件描述符泄漏：调用 open() 打开文件后未调用 close() 关闭文件描述符，导致资源泄漏。
- D验证: confirmed / ver_27e4559d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 18. hyp_path_ba708d843124

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_74a.cpp:50
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: CreateFile 调用成功返回非 INVALID_HANDLE_VALUE 的句柄。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...) @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_74a.cpp:32; dataMap[1] = data; dataMap[2] = data; case0Sink(dataMap); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_74a.cpp:48-52
- 结论: 调用 CreateFile 打开文件后未调用 CloseHandle 释放句柄，导致资源泄漏。
- D验证: confirmed / ver_0261e4d7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 19. hyp_path_262a217f515c

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_73a.cpp:51
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者可通过多次触发该路径消耗系统文件描述符资源。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); dataList.push_back(data); case0Sink(dataList); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_73a.cpp:49-53
- 结论: 文件描述符泄漏漏洞。代码使用open()打开文件，但从未调用close()关闭文件描述符，导致资源泄漏。
- D验证: confirmed / ver_e600ac74
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 20. hyp_path_7586077b3d0a

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_73a.cpp:50
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: CreateFile成功返回有效句柄
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_73a.cpp:50; dataList.push_back(data); dataList.push_back(data); case0Sink(dataList); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_73a.cpp:48-52
- 结论: 在CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_73a.cpp中，通过CreateFile打开文件句柄后，未显式调用CloseHandle关闭句柄，导致资源泄漏。违反CWE775定义。
- D验证: confirmed / ver_6e9ba518
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 21. hyp_path_375055497420

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84a.cpp:31
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够通过外部输入影响对象创建或删除的流程，但在此场景中更偏向于本地触发拒绝服务。
- 触发路径: new CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84_case0(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84a.cpp:30; delete case0Object; @ 同一文件:31
- 结论: 在创建CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84_case0对象时，可能打开文件描述符但未在析构函数或删除对象时释放，导致文件描述符泄漏。
- D验证: confirmed / ver_c6cd5051
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 22. hyp_path_68d77c04f386

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_82a.cpp:32
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行到此代码路径，open()调用成功
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_82_base* baseObject = new ...; baseObject->action(data); delete baseObject; @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_82a.cpp:30-34
- 结论: 文件描述符泄漏：在CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_82a.cpp中，通过open()打开文件后未调用close()关闭文件描述符，导致资源未释放。
- D验证: confirmed / ver_62cd60d7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 23. hyp_path_b713377f8747

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_84a.cpp:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无外部输入依赖；漏洞存在于测试用例内部，人为构造的文件打开操作未关闭。
- 触发路径: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_84_case0 * case0Object = new CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_84_case0(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_84a.cpp:29; delete case0Object; @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_84a.cpp:30
- 结论: VULNERABILITY_FOUND: 在构造函数CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_84_case0()中调用了fopen打开文件句柄，但析构函数未调用fclose，导致文件描述符泄漏。
- D验证: confirmed / ver_fc9fe362
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 24. hyp_path_27cd9e48877e

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_82a.cpp:33
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够触发该路径（例如，调用此函数）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_82a.cpp:31; baseObject->action(data); // action中未关闭句柄 @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_82a.cpp:39
- 结论: 文件句柄未释放，导致资源泄露。CreateFile打开文件后，没有对应的CloseHandle调用，违反API contract，可能导致系统资源耗尽。
- D验证: confirmed / ver_eb521f17
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 25. hyp_path_0fed6881335f

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_84a.cpp:31
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无需攻击者控制输入，漏洞由代码逻辑本身导致。
- 触发路径: data = INVALID_HANDLE_VALUE; CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_84_case0 * case0Object = new CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_84_case0(data); delete case0Object; @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_84a.cpp:29-33; 假设调用 CreateFile 分配句柄 @ 类的构造函数内部（未给出具体代码）; 假设未调用 CloseHandle @ 类的析构函数内部（未给出具体代码）
- 结论: 文件句柄可能未释放：CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_84_case0对象的构造函数可能通过CreateFile创建了文件句柄，但析构函数未调用CloseHandle，导致句柄泄漏。
- D验证: confirmed / ver_3fa7868c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 26. hyp_path_d46ed3ee04d2

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_81a.cpp:32
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行到此代码路径即可触发文件描述符泄漏
- 触发路径: /* NOTE: Open a file without closing it */ data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); const CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_81_base& baseObject = CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_81_case0(); baseObject.action(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_81a.cpp:30-32
- 结论: 文件描述符未释放：调用open()打开文件后，通过action()传递文件描述符，但未调用close()关闭，导致文件描述符泄漏。
- D验证: confirmed / ver_39038617
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 27. hyp_path_2cedc534ee54

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_81a.cpp:33
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: CreateFile成功打开文件，返回有效句柄
- 触发路径: data = INVALID_HANDLE_VALUE; data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_81a.cpp:29-33; const CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_81_base& baseObject = CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_81_case0(); baseObject.action(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_81a.cpp:36-40
- 结论: 使用CreateFile打开文件后未关闭句柄，导致文件句柄泄露
- D验证: confirmed / ver_292f9ce9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 28. hyp_path_00e1112787be

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_83a.cpp:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够触发程序执行该测试路径
- 触发路径: FILE * data; data = NULL; CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_83_case0 case0Object(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_83a.cpp:27-31
- 结论: 在CWE775_Missing_Release_of_File_Descriptor_or_Handle测试用例中，通过fopen打开文件后未调用fclose关闭，导致文件描述符泄漏。尽管当前代码片段显示data初始化为NULL并由对象管理，但测试用例整体存在fopen后未释放资源的问题。
- D验证: confirmed / ver_5f02b362
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 29. hyp_path_4528d22b79b6

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_67a.c:47
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序能够成功打开文件（open()返回非-1）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); myStruct.structFirst = data; CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_67a.c:45-47
- 结论: 文件描述符未释放：调用open()打开文件后，未调用close()关闭文件描述符，导致资源泄漏。
- D验证: confirmed / ver_1dcc7edc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 30. hyp_path_6dd390526265

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_66a.c:43
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无特殊前提条件，只要程序执行该路径即可。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_66a.c:40; dataArray[2] = data; CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_66a.c:43
- 结论: 文件描述符未释放（文件句柄泄漏）：在打开文件后未调用close()关闭文件描述符，导致资源泄漏。
- D验证: confirmed / ver_21c5b691
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 31. hyp_path_67188cea4f96

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_68a.c:45
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序正常执行到open调用处
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_68a.c:45
- 结论: 打开文件后未释放文件描述符，导致资源泄漏。
- D验证: confirmed / ver_6cd38516
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 32. hyp_path_c8fb61c14c75

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_83a.cpp:30
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者无需特殊控制；代码执行路径自动触发资源泄漏。
- 触发路径: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_83_case0 case0Object(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_83a.cpp:30
- 结论: 文件描述符在打开后未关闭，导致资源泄漏（CWE-775）。
- D验证: confirmed / ver_58d592e9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 33. hyp_path_791e0d37ae7b

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_66a.c:42
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: CreateFile 成功返回有效句柄（非 INVALID_HANDLE_VALUE），测试用例中固定文件名和 OPEN_ALWAYS 模式通常保证成功。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_66a.c:33; dataArray[2] = data; CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_66a.c:42
- 结论: 在函数 CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_66a 中，使用 CreateFile 打开文件句柄后，未调用 CloseHandle 关闭句柄，导致资源泄漏。
- D验证: confirmed / ver_0faf28ce
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 34. hyp_path_dbb1d92e3fb8

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_67a.c:46
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: CreateFile成功返回有效句柄（非INVALID_HANDLE_VALUE），代码中无错误处理，假定文件打开成功
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_67a.c:36-38; myStruct.structFirst = data; CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_67a.c:44-48
- 结论: 在CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_67a.c中，CreateFile打开文件句柄后，通过sink函数传递该句柄，但sink函数内部未调用CloseHandle关闭句柄，导致文件句柄泄漏。
- D验证: confirmed / ver_c6d58d51
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 35. hyp_path_377897458b44

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68a.c:44
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无外部输入控制文件名，但CreateFile调用可能成功返回有效句柄；若返回INVALID_HANDLE_VALUE则无泄漏，但代码未检查返回值，且路径默认假设句柄有效。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68a.c:36; CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68b_case0Sink(); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68a.c:44
- 结论: CreateFile打开文件句柄后，在sink函数中未调用CloseHandle释放句柄，违反API contract，导致资源泄漏。
- D验证: confirmed / ver_b1a2e8da
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 36. hyp_path_a341e20b34df

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83a.cpp:30
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 代码执行路径中包含打开文件句柄的操作（如CreateFile），且后续没有关闭句柄的调用。
- 触发路径: /* Initialize data */ data = INVALID_HANDLE_VALUE; CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83_case0 case0Object(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83a.cpp:28-32
- 结论: 在CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83_case0对象的构造过程中，可能通过CreateFile打开文件句柄，但未在对象析构或其他地方调用CloseHandle关闭句柄，导致文件句柄泄露，违反CWE-775。
- D验证: confirmed / ver_76fc1520
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 37. hyp_path_0d2dc29cd442

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_43.cpp:34
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: No precondition required; the code executes without any input.
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_43.cpp:24-28; case0Source(data); /* NOTE: No attempt to close the file */ @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_43.cpp:34
- 结论: File descriptor not closed after fopen() call, leading to resource leak (CWE-775).
- D验证: confirmed / ver_c1fb34a8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 38. hyp_path_9ee7e673274a

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_52b.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 存在一个通过fopen打开的FILE* data，且程序未在任何路径中调用fclose释放。
- 触发路径: void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_52b_case0Sink(FILE * data) { CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_52c_case0Sink(data); } @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_52b.c:24-28
- 结论: 文件句柄未释放：函数CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_52b_case0Sink接收一个通过fopen打开的FILE * data，但未调用fclose释放，导致文件描述符泄漏。后续调用52c函数也未释放，符合CWE-775模式。
- D验证: confirmed / ver_65a894da
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 39. hyp_path_85a4006a5702

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53b.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 已经通过fopen打开了一个文件句柄，且该句柄未被释放
- 触发路径: FILE * data = fopen(...); @ 假设的fopen调用位置（未在提供的代码中显示）; void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53b_case0Sink(FILE * data) { CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53c_case0Sink(data); } @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53b.c:24-28
- 结论: 文件句柄未释放，可能导致资源泄漏
- D验证: confirmed / ver_2a45be7d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 40. hyp_path_54b9c3114808

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53c.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够影响程序执行路径，使得fopen被调用且后续未关闭，但无需直接控制输入；从开发角度看，任何使用该路径的代码都存在泄漏。
- 触发路径: fopen(...) 获取 FILE *data @ 上游调用点（未在提供的代码证据中展示，但根据样本名称和测试用例结构，预期存在fopen调用）; CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53d_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53c.c:26
- 结论: 文件描述符未释放，导致资源泄漏（Missing Release of File Descriptor or Handle）。函数接收FILE指针并直接传递给另一个sink函数，没有执行fclose，如果之前通过fopen获取了该FILE指针，则会造成资源泄漏。当前证据仅包含sink函数，缺少上游fopen调用的直接代码，但根据Juliet测试用例命名惯例，上游存在fopen调用是合理的假设。
- D验证: confirmed / ver_5af63e76
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 41. hyp_path_4894b9877cb5

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54b.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够控制fopen的文件名或路径（导致文件被打开）。
- 触发路径: FILE *data = fopen(filename, "r"); @ 假设的前置函数中; void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54b_case0Sink(FILE * data) { CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54c_case0Sink(data); } @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54b.c:24-28
- 结论: 文件句柄未释放：函数只传递FILE指针到下一个sink，但未执行fclose，可能导致文件描述符泄漏。
- D验证: confirmed / ver_f48c50d2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 42. hyp_path_188274c7ecfa

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54c.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者不需要直接控制输入；测试用例由测试驱动提供文件打开操作，但实际环境中攻击者可能通过控制文件路径或内容触发资源泄露。
- 触发路径: FILE * data = fopen("file.txt", "w"); @ 假设的source位置，通常在同一测试用例文件的main函数或前序函数中，如CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54a.c或类似文件; CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54c_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54c.c:26
- 结论: 文件句柄未释放，导致资源泄露。函数接收FILE*指针后直接传递给另一个sink函数，未在关闭前释放文件描述符，违反了CWE-775关于释放文件描述符或句柄的要求。源代码中应存在fopen调用（测试用例中通常位于main或前序函数），但未找到对应的fclose调用。
- D验证: confirmed / ver_cecc532a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 43. hyp_path_0e5a5e9325e1

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54d.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 存在fopen调用（未在提供的代码片段中直接显示，但由测试用例结构和命名暗示），且后续路径中未调用fclose。攻击者可通过多次调用使得文件描述符耗尽。
- 触发路径: void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54d_case0Sink(FILE * data) { CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54e_case0Sink(data); } @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54d.c:24-28
- 结论: 文件描述符泄漏：fopen打开的文件指针未关闭，违反API contract导致文件描述符资源泄漏。尽管缺乏fopen调用的直接代码证据，但从函数命名和测试用例设计可推断source存在，且sink链确认指针未被释放。
- D验证: confirmed / ver_e34b1260
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 44. hyp_path_f20606e8e53f

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_61a.c:28
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序调用fopen打开文件后，未在任何路径调用fclose关闭文件描述符
- 触发路径: data = CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_61b_case0Source(data); /* NOTE: No attempt to close the file */ ; @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_61a.c:28
- 结论: 文件句柄未释放：调用fopen打开文件后，未调用fclose关闭文件，导致资源泄漏。
- D验证: confirmed / ver_77fa1b5a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 45. hyp_path_6fb552b105e7

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_43.cpp:44
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: open()调用成功返回有效的文件描述符（返回值非-1）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_43.cpp:35; case0Source(data); /* NOTE: No attempt to close the file */ @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_43.cpp:44
- 结论: 文件描述符泄漏：在函数case0Source中使用OPEN()打开文件后，未在任何路径关闭文件描述符，若open成功返回有效fd，则导致资源泄漏。
- D验证: confirmed / ver_797623e9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 46. hyp_path_5eb353219ead

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_52b.c:35
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够通过source控制文件描述符的创建（如控制文件名或路径），但此环节不涉及外部输入；漏洞存在的前提是程序执行了open()且未关闭。
- 触发路径: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_52c_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_52b.c:35
- 结论: 函数调用链中存在未释放的文件描述符：open()返回的文件描述符在后续处理中未被关闭，导致文件描述符泄漏。
- D验证: confirmed / ver_2a39bda9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 47. hyp_path_c8b42c31f0e5

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_53b.c:35
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够影响文件打开操作或控制数据流，使该sink被调用。
- 触发路径: int data = open(...); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_53a.c (假设的source函数，包含open()调用); CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_53c_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_53b.c:35
- 结论: 文件描述符通过open()获得后，在sink函数链中未被关闭，导致资源泄漏。
- D验证: confirmed / ver_4e510466
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 48. hyp_path_739f2605b89e

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_53c.c:35
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够影响程序执行路径，使得未关闭的文件描述符累积，可能导致资源耗尽。
- 触发路径: void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_53c_case0Sink(int data) { CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_53d_case0Sink(data); } @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_53c.c:33-37
- 结论: 存在文件描述符未释放漏洞：函数接收文件描述符但未关闭，导致资源泄漏。
- D验证: confirmed / ver_f11d0b42
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 49. hyp_path_9a2c79fe15f4

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54b.c:35
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够控制文件描述符的分配或触发该sink函数的调用路径。
- 触发路径: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54c_case0Sink(data); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54b.c:35
- 结论: 文件描述符在使用后未关闭，导致资源泄漏，违反CWE775 Missing Release of File Descriptor or Handle。但当前代码片段仅显示转发函数，未提供open()和close()的完整调用序列，证据不完整。
- D验证: confirmed / ver_e23ff58b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 50. hyp_path_754c16fac542

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54d.c:35
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 存在一个已打开的文件描述符作为参数data传入
- 触发路径: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54e_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54d.c:35
- 结论: 函数CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54d_case0Sink接收文件描述符后直接传递给sink函数而未关闭，导致资源泄漏。
- D验证: confirmed / ver_c159fb99
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 51. hyp_path_b111869516eb

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54c.c:35
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 存在一个打开的文件描述符未被关闭的情况。
- 触发路径: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54d_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54c.c:35
- 结论: 文件描述符未释放，违反API contract，导致资源泄漏。
- D验证: confirmed / ver_b013fb3f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 52. hyp_path_19c26b48e162

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_61a.c:38
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者可能通过影响打开操作的成功概率，但实际触发依赖于程序内部逻辑
- 触发路径: data = CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_61b_case0Source(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_61a.c:38
- 结论: 文件描述符未关闭：函数CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_61b_case0Source返回文件描述符（可能有效），但后续没有调用close()关闭文件描述符，导致资源泄漏。
- D验证: confirmed / ver_fe55e300
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 53. hyp_path_66eb35d4596d

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_62a.cpp:41
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够触发此路径多次，例如通过网络请求或用户操作。
- 触发路径: case0Source(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_62a.cpp:36; /* NOTE: No attempt to close the file */ @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_62a.cpp:41
- 结论: 在函数case0中，通过调用case0Source打开文件描述符后，没有进行关闭操作，导致文件描述符泄漏。
- D验证: confirmed / ver_2e9ff32a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 54. hyp_path_8a917e23555e

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_74b.cpp:464
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够影响dataMap中的值（例如通过之前的数据注入），但本漏洞主要关注资源泄漏，不依赖输入控制
- 触发路径: /* copy data out of dataMap */ int data = dataMap[2]; /* NOTE: No attempt to close the file */ @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_74b.cpp:36-37
- 结论: 在CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_74b.cpp的case0Sink函数中，从dataMap读取整数后未进行关闭操作，违反了CWE775规则，但缺少source（open调用）证据，路径不完整，可能存在资源泄漏风险。
- D验证: confirmed / ver_4c4981f6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 55. hyp_path_03f3eb47aa6a

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_43.cpp:43
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序以正常权限运行，CreateFile调用成功，且返回有效句柄。
- 触发路径: case0Source(data); /* NOTE: No attempt to close the file */ ; @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_43.cpp:43; data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_43.cpp:35
- 结论: 文件句柄未释放：CreateFile打开文件后未在任何路径调用CloseHandle，导致句柄泄漏。
- D验证: confirmed / ver_937cc127
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 56. hyp_path_2ad54e062c7b

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52b.c:28
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够控制程序的输入，使得满足调用该sink函数的条件。
- 触发路径: HANDLE hFile = CreateFile(...); @ L? 假设在调用sink之前有CreateFile打开句柄（源码缺失）; CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52b_case0Sink(hFile); @ L? 调用sink函数; CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52c_case0Sink(data); // 传递后未关闭 @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52b.c:28
- 结论: 函数未释放传入的文件句柄，导致资源泄漏（CWE775）。
- D验证: confirmed / ver_447f703b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 57. hyp_path_8465ae8b076a

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53b.c:28
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 存在一个先前通过CreateFile等函数创建的HANDLE被传递到此函数，且该句柄未被调用者或其他函数关闭。
- 触发路径: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53c_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53b.c:28
- 结论: 函数CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53b_case0Sink接收一个通过CreateFile等函数创建的有效句柄HANDLE data，未进行任何关闭或释放操作，直接传递给另一个函数，导致文件句柄或资源未释放，违反API合约，造成资源泄漏。
- D验证: confirmed / ver_2b83d465
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 58. hyp_path_974d277eedc7

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54b.c:28
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响传入的HANDLE参数，例如通过调用链传递一个通过CreateFile获取的未关闭句柄。
- 触发路径: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54c_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54b.c:28
- 结论: 函数CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54b_case0Sink未关闭传入的HANDLE，导致句柄泄漏，违反API contract（CreateFile后应CloseHandle）。
- D验证: confirmed / ver_6112b8be
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 59. hyp_path_a2360ea95a51

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53c.c:28
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 存在调用者通过CreateFile创建HANDLE并传递给当前sink函数
- 触发路径: void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53c_case0Sink(HANDLE data) { CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53d_case0Sink(data); } @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53c.c:28; void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53d_case0Sink(HANDLE data) { /* 无CloseHandle调用 */ } @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53d.c（推测位置）
- 结论: 函数CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53c_case0Sink接收HANDLE后未关闭，并传递给53d函数（推测同样无关闭操作），导致文件句柄泄漏。路径中缺乏CloseHandle调用，违反CWE-775。
- D验证: confirmed / ver_06ae47f0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 60. hyp_path_ad7e7ceb113c

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54c.c:28
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 存在一个先前的CreateFile调用创建了句柄，且该句柄未被关闭; 当前sink函数接收该句柄后直接传递给下一个sink函数，未在调用链中任何位置执行CloseHandle
- 触发路径: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54d_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54c.c:28
- 结论: 文件句柄通过CreateFile创建后，在后续处理路径中未显式调用CloseHandle关闭，导致资源泄漏（CWE-775）。当前sink函数接收句柄后仅转发至下一sink函数，整个调用链中未执行释放操作，测试用例名称'no_close'明确指示缺失。
- D验证: confirmed / ver_c01bc929
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 61. hyp_path_b5f22c9a4edf

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54d.c:28
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者需要能够控制或影响CreateFile的调用，但资源泄露本身即可构成安全弱点，无需攻击者主动利用。
- 触发路径: HANDLE data = CreateFile(...); @ 假设的source: CreateFile调用（未在给定代码片段中提供，但基于测试用例结构存在）; void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54d_case0Sink(HANDLE data) { CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54e_case0Sink(data); } @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54d.c:26-28; 未关闭句柄 @ 进一步的sink函数（未展示，但应缺失CloseHandle调用）
- 结论: 函数CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54d_case0Sink接收一个HANDLE参数，并将其传递给另一个sink函数。基于测试用例名称和CWE-775定义，该句柄由CreateFile创建且从未通过CloseHandle释放，导致资源泄露。尽管当前代码证据缺少CreateFile调用的source代码，但路径逻辑合理，且无硬矛盾。
- D验证: confirmed / ver_fc56552d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 62. hyp_path_656fcbf4e684

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_62a.cpp:34
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: case0Source函数内部成功调用CreateFileW并获得有效句柄
- 触发路径: data = INVALID_HANDLE_VALUE; case0Source(data); /* NOTE: No attempt to close the file */ ; /* empty statement needed for some flow variants */ @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_62a.cpp:32-36
- 结论: 文件句柄未关闭，导致资源泄露。在case0Source中可能通过CreateFile创建了句柄，但函数返回后未调用CloseHandle释放。
- D验证: confirmed / ver_a68cb993
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 63. hyp_path_37e4ed7872ad

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_12.c:47
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序控制流进入globalReturnsTrueOrFalse()返回true的分支；OPEN调用返回有效文件描述符（data != -1）。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_12.c:35; if(globalReturnsTrueOrFalse()) { /* NOTE: No attempt to close the file */ @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_12.c:37; CLOSE(data)位于else分支，当前路径缺失 @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_12.c:47
- 结论: 在if(globalReturnsTrueOrFalse())为真的分支中，OPEN函数成功打开文件后，没有执行CLOSE操作，导致文件描述符泄露（CWE-775）。
- D验证: confirmed / ver_b0b7da63
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 64. hyp_path_19d7cf67da3c

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_12.c:46
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无特殊前提，程序正常运行即可触发漏洞。
- 触发路径: data = CreateFile(..., NULL); @ line 30; if(globalReturnsTrueOrFalse()) { /* NOTE: No attempt to close the file */ } @ line 36; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ line 46
- 结论: 在特定条件下，打开的文件句柄未被关闭，导致资源泄露。
- D验证: confirmed / ver_2642b09a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 65. hyp_path_315062936575

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_72a.cpp:36
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: fopen调用成功返回非NULL文件指针
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_72a.cpp:36; dataVector.insert(dataVector.end(), 1, data); ... case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_72a.cpp:39-43
- 结论: 文件打开后未关闭，导致文件描述符泄漏，符合CWE-775定义。虽然sink函数内部代码未提供，但基于测试用例名称'fopen_no_close'和CWE上下文，推断sink中未执行fclose操作。
- D验证: confirmed / ver_ed427d60
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 66. hyp_path_f25107926c3f

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22a.c:31
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无外部输入控制，漏洞由代码逻辑固有缺陷导致。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ L31; CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_case0Sink(data); @ L33
- 结论: 在函数 CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_case0 中，通过 fopen 打开文件后未调用 fclose 关闭文件句柄，导致文件描述符泄漏，违反 CWE-775。
- D验证: confirmed / ver_eb60ded6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 67. hyp_path_d23780d47e22

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_51a.c:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够触发该代码路径（例如通过多次调用导致文件描述符耗尽）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_51a.c:29; CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_51a.c:30
- 结论: 文件描述符未释放：fopen打开文件后未调用fclose，导致资源泄漏。
- D验证: confirmed / ver_88645ee8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 68. hyp_path_458fd5536d35

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_52a.c:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行到该路由，且 fopen 调用成功返回非 NULL 文件指针。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_52a.c:29; CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_52a.c:30; 未在 sink 函数或调用返回后调用 fclose()，导致文件描述符泄漏。 @ sink 函数内部
- 结论: 文件描述符未释放：fopen() 打开文件后未调用 fclose() 关闭文件描述符。代码注释明确说明不关闭文件，且将文件指针传递给 sink 函数，sink 函数也未关闭文件，导致资源泄漏。
- D验证: confirmed / ver_16ab490c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 69. hyp_path_1ec4dca6e2c3

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53a.c:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序以正常权限执行，fopen调用成功
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53a.c:29; CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53a.c:30
- 结论: fopen后未调用fclose关闭文件描述符，导致文件资源泄漏，违反CWE-775。
- D验证: confirmed / ver_9892e250
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 70. hyp_path_352c71578c01

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54a.c:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: fopen成功返回非NULL文件指针，且后续sink函数未关闭文件或释放句柄。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54a.c:29; CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54a.c:30
- 结论: 文件描述符未释放漏洞：fopen打开文件后未调用fclose，导致文件句柄泄漏。
- D验证: confirmed / ver_fc1338de
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 71. hyp_path_c62331843ec8

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_63a.c:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者无法直接控制输入，但文件资源泄漏可能影响系统稳定性或导致资源耗尽
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_63a.c:29; CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_63a.c:30; 未调用fclose关闭文件句柄 @ sink函数内部（未展示）
- 结论: 调用fopen打开文件后未关闭文件描述符，违反了必须释放文件句柄的API契约，导致资源泄漏（CWE775）。
- D验证: confirmed / ver_47005228
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 72. hyp_path_9f7bf004f37e

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_64a.c:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 文件打开成功，无外部输入控制。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_64a.c:29; CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_64a.c:30
- 结论: 函数fopen打开文件后未调用fclose关闭，导致文件描述符泄漏，违反CWE775。sink函数内部实现未知，但根据代码路径和静态分析支持，存在未释放风险。
- D验证: confirmed / ver_6cf0ad27
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 73. hyp_path_c5356eda077c

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_74a.cpp:36
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序运行并执行该代码路径
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_74a.cpp:36; dataMap[0] = data; dataMap[1] = data; dataMap[2] = data; case0Sink(dataMap); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_74a.cpp:38-42
- 结论: 文件描述符泄漏：fopen() 打开文件后未调用 fclose() 关闭，导致资源泄漏。
- D验证: confirmed / ver_d1633345
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 74. hyp_path_6dc2ed55ea10

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_73a.cpp:36
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序能够多次执行漏洞函数（如外部循环调用case0），导致文件描述符累积泄漏。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_73a.cpp:36; 无关闭操作 @ 同一文件后续无fclose
- 结论: 文件描述符未释放：fopen打开文件后，没有对应的fclose调用，导致资源泄漏。
- D验证: confirmed / ver_3ee9258f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 75. hyp_path_2da5e39080b0

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_21.c:38
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序正常执行到漏洞代码路径，且 fopen 调用成功。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_21.c:38; case0Sink(data); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_21.c:40; static void case0Sink(FILE * data) { if(case0Static) { ; /* empty statement */ } } // 未关闭文件 @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_21.c:24-31
- 结论: 文件描述符未释放：fopen 打开文件后，在 case0Sink 函数中未调用 fclose 关闭文件，导致资源泄漏。
- D验证: confirmed / ver_ca5cf1a5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 76. hyp_path_5af74cee4646

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_41.c:32
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: fopen调用成功，返回非NULL文件指针
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ L32; case0Sink(data); @ L33; static void case0Sink(FILE *data) { /* NOTE: No attempt to close the file */ ; } @ L21-25
- 结论: 文件描述符未释放漏洞：fopen() 打开文件后未调用 fclose() 关闭，导致资源泄露。
- D验证: confirmed / ver_83cfa0cf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 77. hyp_path_c8ed2697a89b

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_82a.cpp:30
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_82a.cpp:30; baseObject->action(data); delete baseObject; @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_82a.cpp:31-33; 没有调用fclose。 @ 同一文件，函数返回处
- 结论: 在函数case0中，使用fopen打开文件后，没有在任何路径中调用fclose关闭文件，导致文件描述符未释放，违反了CWE-775。
- D验证: confirmed / ver_c2efc271
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 78. hyp_path_b89d0e6be1b6

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_81a.cpp:30
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: fopen成功打开文件（即data非NULL）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_81a.cpp:30; baseObject.action(data); // 无fclose调用 @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_81a.cpp:32
- 结论: 文件描述符或句柄未释放：fopen打开文件后未调用fclose关闭，导致资源泄露。
- D验证: confirmed / ver_30f71beb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 79. hyp_path_626aa94458b0

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_44.c:34
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够触发该代码路径多次（如通过重复请求或循环调用），以耗尽文件描述符资源。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_44.c:34
- 结论: 文件打开后未关闭，导致文件描述符泄漏。
- D验证: confirmed / ver_7abe1467
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 80. hyp_path_64bc846b8bff

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_65a.c:31
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够触发该代码路径（例如通过多次调用导致资源耗尽）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_65a.c:31
- 结论: 文件描述符未释放：fopen打开文件后没有调用fclose，导致资源泄漏，违反CWE775。
- D验证: confirmed / ver_5402d0e5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 81. hyp_path_7777e57e6c51

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_21.c:48
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无特殊攻击前提，仅需程序执行到该代码路径。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_21.c:48; case0Sink(data); // 函数内无 close 操作 @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_21.c:50
- 结论: 打开文件描述符后未释放，导致资源泄漏。
- D验证: confirmed / ver_a32990cc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 82. hyp_path_41370a7c3524

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_21.c:41
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: CreateFile调用成功，返回有效句柄（非INVALID_HANDLE_VALUE）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ line 41; case0Sink(data); @ line 48; if(case0Static) { /* NOTE: No attempt to close the file */ ; } @ line 30-32
- 结论: 函数case0Sink未关闭通过CreateFile成功创建的文件句柄，导致资源泄漏，违反CWE-775（Missing Release of File Descriptor or Handle）。
- D验证: confirmed / ver_dd7e19e6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 83. hyp_path_bba7beb42fb8

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_41.c:35
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_41.c:35; case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_41.c:42; static void case0Sink(HANDLE data) { /* NOTE: No attempt to close the file */ ; } @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_41.c:25-27
- 结论: 函数使用CreateFile打开文件句柄后未调用CloseHandle关闭，违反CWE775: Missing Release of File Descriptor or Handle，导致资源泄露。
- D验证: confirmed / ver_be95bed3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 84. hyp_path_45ea9e0147f0

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_41.c:42
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: OPEN()调用必须成功返回有效的文件描述符
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_41.c:42; case0Sink(data); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_41.c:43; static void case0Sink(int data) { /* NOTE: No attempt to close the file */ ; } @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_41.c:30-34
- 结论: 文件描述符未释放：open()打开的文件描述符在函数返回前未调用close()，导致资源泄漏。
- D验证: confirmed / ver_9b9a71ab
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 85. hyp_path_393ed81f6471

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_12.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者无法直接控制globalReturnsTrueOrFalse()的返回值，但该函数可能随机返回true，导致漏洞路径执行。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_12.c:26; if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_12.c:27; /* NOTE: No attempt to close the file */ // 空分支，无fclose @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_12.c:28-29
- 结论: 在CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_12_case0中，当globalReturnsTrueOrFalse()返回true时，fopen打开的文件未在对应分支内关闭，导致文件描述符泄漏（CWE-775）。
- D验证: confirmed / ver_5a558ed4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 86. hyp_path_6160aba76b21

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_42.c:24
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_42.c:24
- 结论: 文件句柄未释放：fopen后未调用fclose，导致文件描述符泄漏。
- D验证: confirmed / ver_122c769a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 87. hyp_path_7673800fc03b

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_61b.c:24
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: fopen成功打开文件（文件存在且可写）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); return data; @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_61b.c:24
- 结论: 文件描述符或句柄在fopen后未关闭，导致资源泄露
- D验证: confirmed / ver_10e0fe18
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 88. hyp_path_d7a97c736261

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_44.c:44
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行到此代码路径，并且 open() 调用成功
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_44.c:44
- 结论: 文件描述符未释放：open() 调用后未执行 close()，导致文件描述符泄漏。
- D验证: confirmed / ver_be6d6afd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 89. hyp_path_84acee96e1a5

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_65a.c:41
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序以正常方式运行，文件打开成功
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_65a.c:41
- 结论: 文件描述符未释放导致资源泄露：在打开文件后未调用close()，违反API contract，可能导致文件描述符耗尽。
- D验证: confirmed / ver_dfe1d7ec
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 90. hyp_path_6ab52d513863

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_44.c:37
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: CreateFile调用成功返回有效句柄（非INVALID_HANDLE_VALUE）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_44.c:37
- 结论: 代码调用CreateFile打开文件句柄后，未调用CloseHandle释放句柄，导致资源泄露（句柄未释放），违反CWE-775。
- D验证: confirmed / ver_e1996153
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 91. hyp_path_4cb33954b5a0

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_65a.c:34
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无特殊前提，只要代码执行到此路径即可。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_65a.c:34
- 结论: 文件句柄未关闭，导致资源泄漏（CWE-775）。代码中CreateFile打开文件后未调用CloseHandle。
- D验证: confirmed / ver_d27aafa1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 92. hyp_path_c5e50c819976

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_11.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行到fopen调用且fopen返回非NULL文件指针（即文件打开成功）。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_11.c:25; if(globalReturnsTrue()) { /* NOTE: No attempt to close the file */ } @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_11.c:27-28
- 结论: 文件描述符未释放：fopen打开文件后，在所有路径下均未调用fclose关闭文件，导致文件描述符泄露（CWE-775）。
- D验证: confirmed / ver_95c5b278
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 93. hyp_path_71dc0d253687

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_08.c:39
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行到fopen()语句且fopen()成功返回。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_08.c:39; if(staticReturnsTrue()) { /* NOTE: No attempt to close the file */ } @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_08.c:40-41
- 结论: 文件描述符未释放：fopen()打开文件后没有对应的fclose()调用，导致文件描述符泄漏。
- D验证: confirmed / ver_80ce54a7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 94. hyp_path_2858d3f92184

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_45.c:36
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无需外部输入，代码自动执行
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_45.c:36; case0Sink(); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_45.c:38; static void case0Sink() { FILE * data = CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_45_case0Data; /* NOTE: No attempt to close the file */ ; } @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_45.c:24-29
- 结论: 打开文件后未关闭，导致文件描述符泄漏（CWE-775 Missing Release of File Descriptor or Handle）
- D验证: confirmed / ver_330b8e30
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 95. hyp_path_631e5d688af4

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_66a.c:30
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行到该路径，且不对文件指针进行关闭操作
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_66a.c:30; CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_66b_case0Sink(dataArray); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_66a.c:33
- 结论: 函数fopen打开文件后未关闭文件描述符，导致文件描述符泄漏，可能引发资源耗尽。
- D验证: confirmed / ver_ba568221
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 96. hyp_path_baea2d601d65

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_67a.c:35
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行到该代码路径，fopen成功打开文件
- 触发路径: data = NULL; /* NOTE: Open a file without closing it */ data = fopen("Case0Source_fopen.txt", "w+"); myStruct.structFirst = data; CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_67a.c:33-37
- 结论: 在文件fopen打开后，未关闭文件描述符，导致资源泄漏。CWE775定义了缺失释放文件描述符或句柄的漏洞。
- D验证: confirmed / ver_5f96867c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 97. hyp_path_db2daa9f34af

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_68a.c:33
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者不需要特殊输入，只需程序运行到该代码路径即可触发漏洞。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_68a.c:33; CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_68b_case0Sink(); // 该函数未关闭文件 @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_68a.c:35
- 结论: 文件描述符泄露：fopen打开文件后未调用fclose关闭，导致文件描述符未被释放，可能耗尽系统资源。
- D验证: confirmed / ver_c9293a78
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 98. hyp_path_e142d67f56d1

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_01.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无外部输入控制，但代码本身执行了fopen且未关闭。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_01.c:26
- 结论: 文件描述符或句柄未释放漏洞：使用fopen打开文件后，未调用fclose关闭文件，导致资源泄漏。
- D验证: confirmed / ver_82bf4a1f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 99. hyp_path_79ace8327375

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_02.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行到fopen调用且后续路径未关闭文件
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_02.c:26
- 结论: 文件描述符未释放，导致资源泄漏漏洞。
- D验证: confirmed / ver_c95b8ba4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 100. hyp_path_600489fafa12

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_03.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无额外攻击者控制条件，代码路径可达即可触发。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_03.c:26
- 结论: 文件描述符泄露：fopen打开文件后未调用fclose关闭，导致资源泄露。
- D验证: confirmed / ver_666386c3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 101. hyp_path_fc285b094440

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_04.c:32
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无特殊前提，函数被正常调用即可触发
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_04.c:32
- 结论: 文件打开后未关闭，导致文件描述符泄漏。
- D验证: confirmed / ver_5196dbf3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 102. hyp_path_6cc95f12b17a

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_05.c:32
- 漏洞类型: null_deref
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行到 fopen 调用处，且 fopen 成功返回非空指针
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_05.c:32
- 结论: 文件描述符未释放：fopen() 打开文件后未调用 fclose()，导致资源泄露。
- D验证: confirmed / ver_9946fa99
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 103. hyp_path_20086f036ecf

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_06.c:31
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够触发此代码路径执行，例如通过程序正常调用或重复调用以耗尽文件描述符
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_06.c:31
- 结论: 文件描述符或句柄未释放：fopen打开文件后没有调用fclose关闭，导致资源泄露。
- D验证: confirmed / ver_401dce85
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 104. hyp_path_0a6fce3bd093

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_09.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: fopen调用成功（文件可打开）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_09.c:26
- 结论: 文件描述符泄漏：fopen打开文件后未调用fclose关闭，导致文件描述符资源泄漏，可能引发拒绝服务或系统资源耗尽。
- D验证: confirmed / ver_738ffab0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 105. hyp_path_02a8cf11d0c4

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_10.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无需特殊输入控制，程序正常执行即可触发资源泄漏
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_10.c:26
- 结论: 文件描述符未释放：调用fopen打开文件后，没有调用fclose关闭文件描述符，导致资源泄漏。
- D验证: confirmed / ver_725b7a9a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 106. hyp_path_845ca9e7e26e

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_13.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够控制程序多次执行此代码路径（例如通过重复调用触发）。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_13.c:26
- 结论: 文件描述符未释放：调用fopen打开文件后缺少对应的fclose调用，导致文件句柄泄漏，可能造成资源耗尽。
- D验证: confirmed / ver_8b9e302e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 107. hyp_path_4267d3a43304

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_14.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够控制程序执行流程使此代码路径被重复调用，从而耗尽系统文件描述符资源。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_14.c:26; 缺失 fclose(data); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_14.c:24-28
- 结论: 文件描述符/句柄未释放：调用fopen后没有对应的fclose，导致文件句柄泄漏。
- D验证: confirmed / ver_2c809863
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 108. hyp_path_88c19352eadc

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_15.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序能够多次执行此代码路径以耗尽系统文件描述符资源
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_15.c:26
- 结论: 在fopen打开文件后，没有调用fclose关闭文件句柄，导致文件描述符泄漏，可能造成资源耗尽。
- D验证: confirmed / ver_66107832
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 109. hyp_path_950ec03da517

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_07.c:31
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够使该函数被多次调用（例如通过多次请求），以耗尽系统文件描述符资源；但单次调用也构成漏洞。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ L31; if(staticFive==5) { ... } // 文件打开后无fclose调用，函数返回时文件句柄未释放 @ L33-? (函数返回前)
- 结论: 文件打开后未关闭，导致文件描述符泄露（CWE-775）。fopen()调用返回FILE*，但在函数返回前未调用fclose()释放资源，无论staticFive条件是否成立。单次调用即违反API contract，多次调用会加剧资源耗尽。
- D验证: confirmed / ver_4f2c7057
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 110. hyp_path_b679231082a7

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_16.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 执行该代码即可触发资源泄漏，无需攻击者控制
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_16.c:26
- 结论: 文件句柄未释放：调用fopen打开文件后未调用fclose关闭，导致文件描述符泄漏。
- D验证: confirmed / ver_0a8401a7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 111. hyp_path_e2d1c71c148e

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_18.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无特定攻击者控制输入，但函数可能被多次调用导致文件描述符耗尽
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_18.c:26
- 结论: 文件打开后未关闭，导致文件描述符泄漏
- D验证: confirmed / ver_d5a956c0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 112. hyp_path_f67c4c2e28b9

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_17.c:27
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: fopen调用成功（返回非NULL）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_17.c:27
- 结论: 文件通过fopen打开后未调用fclose关闭，导致文件描述符泄漏，违反CWE-775。
- D验证: confirmed / ver_c8529b48
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 113. hyp_path_458c0e921a95

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_32.c:30
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序正常执行到第30行并成功打开文件。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_32.c:30
- 结论: 函数fopen打开文件后未调用fclose关闭文件描述符，导致文件句柄泄漏，违反CWE775定义。可能造成资源耗尽。
- D验证: confirmed / ver_ce861da4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 114. hyp_path_9990fb9a6d52

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_31.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: fopen 调用成功（文件存在或可创建）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_31.c:26
- 结论: 文件描述符未释放漏洞：fopen 打开文件后没有调用 fclose 关闭，导致文件句柄泄露。
- D验证: confirmed / ver_2cf487eb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 115. hyp_path_5fd645ff3f19

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_33.cpp:30
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: No user control required; the file is opened with a hardcoded name, but repeated calls could exhaust system resources.
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_33.cpp:30
- 结论: Missing release of file descriptor or handle: fopen() is called without a corresponding fclose(), leading to resource leak.
- D验证: confirmed / ver_53df27ea
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 116. hyp_path_b835264c5987

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_34.c:33
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无特殊前提，程序自然执行即可触发
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_34.c:33
- 结论: 文件描述符未释放：fopen 打开文件后没有调用 fclose 关闭，导致资源泄漏。
- D验证: confirmed / ver_44c58722
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 117. hyp_path_0695ecd8d5da

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_43.cpp:27
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序运行环境允许打开文件
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ 27
- 结论: 文件打开后未关闭，导致文件描述符泄漏，可能引发资源耗尽（拒绝服务）
- D验证: confirmed / ver_fbc8e56a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 118. hyp_path_cb4daada3949

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_62b.cpp:27
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无外部输入控制，攻击者无法直接触发，但多次调用该函数可能导致文件描述符耗尽。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ 27
- 结论: 在函数case0Source中，通过fopen打开文件后，没有调用fclose关闭文件，导致文件描述符泄漏。多次调用该函数可能导致文件描述符耗尽，属于CWE-775漏洞。
- D验证: confirmed / ver_e9957671
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 119. hyp_path_cbfcd235de06

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_84_case0.cpp:27
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者可能通过影响程序运行环境（如创建大量文件）间接利用资源泄漏，但无需直接控制输入。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_84_case0.cpp:27
- 结论: 文件描述符未释放：fopen 打开文件后没有调用 fclose 关闭，导致资源泄漏。
- D验证: confirmed / ver_98269a5a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 120. hyp_path_1bddbe5a8ee8

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_83_case0.cpp:27
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: fopen调用成功（文件可正常打开）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_83_case0.cpp:27; 缺少fclose调用 @ 同一文件析构函数或任何其他位置
- 结论: 在CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_83_case0的构造函数中使用fopen打开文件后，构造函数和析构函数均未调用fclose关闭文件，导致文件描述符泄露（CWE-775）。
- D验证: confirmed / ver_501642cd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 121. hyp_path_f558841aed22

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_42.c:33
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 函数被调用一次以上，或系统资源有限
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_42.c:33; return data; // 未调用close() @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_42.c:34
- 结论: 文件描述符未释放：函数case0Source()调用open()后未关闭文件描述符，直接返回，导致文件描述符泄漏。
- D验证: confirmed / ver_13076387
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 122. hyp_path_b2364baff9e8

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_42.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够多次触发该函数，例如通过重复调用或程序循环。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_42.c:24-28
- 结论: 在函数case0Source中调用CreateFile打开文件后，没有调用CloseHandle关闭文件句柄，导致资源泄漏。多次调用可能导致句柄耗尽，影响系统稳定性。
- D验证: confirmed / ver_c38fd1f9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 123. hyp_path_81a5dc71e3c4

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_61b.c:26
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行到CreateFile调用且创建文件成功。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_61b.c:26
- 结论: 文件句柄未释放：调用CreateFile后未调用CloseHandle，导致资源泄漏。
- D验证: confirmed / ver_916f0442
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 124. hyp_path_57f664866f5e

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_61b.c:33
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 调用者未关闭返回的文件描述符
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_61b.c:33
- 结论: 函数打开文件后未关闭，返回文件描述符，违反了资源释放原则，调用者若不关闭则导致文件描述符泄漏
- D验证: confirmed / ver_ea2aeaa0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 125. hyp_path_9d1791d67ca5

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_08.c:50
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者无需额外控制，只要代码执行到此路径即可触发资源泄漏。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_08.c:49; if(staticReturnsTrue()) { /* NOTE: No attempt to close the file */ @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_08.c:50
- 结论: 打开文件描述符后没有释放，导致资源泄漏（CWE-775）。代码中调用open()后，在staticReturnsTrue()返回真时，没有调用close()关闭文件描述符。
- D验证: confirmed / ver_4a3229db
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 126. hyp_path_6532ac20a39a

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_11.c:37
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: open()调用成功返回有效文件描述符（非-1）。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_11.c:36; if(globalReturnsTrue()) { /* NOTE: No attempt to close the file */} @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_11.c:37-39
- 结论: 文件描述符未释放：调用open()打开文件后，在所有路径上都没有调用close()关闭文件描述符，导致资源泄漏。若open()成功返回有效描述符，则漏洞存在；若open()失败返回-1，则无泄漏。
- D验证: confirmed / ver_bc0851de
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 127. hyp_path_ad5e557eaa72

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_45.c:46
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无外部攻击者控制，仅需程序运行到此路径即可触发。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_45.c:46; case0Sink(); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_45.c:48
- 结论: 函数open打开文件后未调用close释放文件描述符，导致文件描述符泄漏（CWE-775）。
- D验证: confirmed / ver_a4a946f0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 128. hyp_path_87cb6c312ec4

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_08.c:49
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: CreateFile must return a valid handle (not INVALID_HANDLE_VALUE) for the leak to occur; the code does not check the return value but typical test environment ensures success.
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_08.c:42
- 结论: Missing release of file descriptor or handle: CreateFile is called without subsequent CloseHandle, leading to a resource leak if the file is successfully opened.
- D验证: confirmed / ver_f0d626ff
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 129. hyp_path_3a5c8a93af13

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_11.c:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: CreateFile 成功执行，且 globalReturnsTrue() 返回 true。
- 触发路径: data = INVALID_HANDLE_VALUE; /* NOTE: Open a file without closing it */ data = CreateFile(...); @ L28-29; if(globalReturnsTrue()) { /* NOTE: No attempt to close the file */ } @ L34-36
- 结论: 文件中打开的文件句柄未关闭，导致资源泄漏。CreateFile 调用后未调用 CloseHandle，违反了 API contract。
- D验证: confirmed / ver_109cf650
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 130. hyp_path_20e6486fdf66

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_45.c:47
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: CreateFile成功返回有效句柄，且后续没有调用CloseHandle关闭句柄。文件路径硬编码，但程序本身存在资源泄露缺陷。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_45.c:39; CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_45_case0Data = data; @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_45.c:46; case0Sink(); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_45.c:47; /* NOTE: No attempt to close the file */ ; @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_45.c:30
- 结论: 函数case0Sink中未释放通过CreateFile打开的文件句柄，导致资源泄露，违反CWE775。
- D验证: confirmed / ver_a7c9bd55
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 131. hyp_path_bc70f8b04969

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_42.c:32
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序正常执行，fopen调用成功。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_42.c:25; data = case0Source(data); /* NOTE: No attempt to close the file */ @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_42.c:32
- 结论: 文件描述符未释放，导致资源泄漏。函数case0Source中调用fopen打开文件后未关闭，调用方也未关闭，违反CWE-775。
- D验证: confirmed / ver_455c12fb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 132. hyp_path_576c9f986a94

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_72b.cpp:30
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 文件指针dataVector[2]有效且指向已打开的文件（存在对应的fopen调用）
- 触发路径: FILE * data = dataVector[2]; /* NOTE: No attempt to close the file */ @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_72b.cpp:30
- 结论: 函数从dataVector中取出文件指针data，但未调用fclose关闭文件，导致文件描述符/句柄泄露。
- D验证: confirmed / ver_bb3de3b3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 133. hyp_path_c7a56df7efce

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_73b.cpp:30
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序运行中至少有一个通过 fopen 打开的文件指针被插入到 dataList 中。
- 触发路径: FILE * data = dataList.back(); /* NOTE: No attempt to close the file */ ; @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_73b.cpp:28-32
- 结论: 从 list 中获取 FILE* 指针后，注释明确表明不关闭文件，导致文件描述符/句柄泄露。
- D验证: confirmed / ver_1bd56b4f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 134. hyp_path_5a5ee30d07f2

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_01.c:36
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者需能够多次调用此函数以耗尽系统文件描述符，但无需直接控制输入
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_01.c:36
- 结论: 文件描述符未释放：函数内打开文件后未关闭，违反CWE775定义，可能导致资源泄漏和潜在拒绝服务。
- D验证: confirmed / ver_6ae6eaac
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 135. hyp_path_3400b43ed9ff

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_02.c:36
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_02.c:36
- 结论: 文件描述符未释放（Missing Release of File Descriptor or Handle）：调用 open() 后未调用 close()，导致文件描述符泄漏。
- D验证: confirmed / ver_2c8ad9f7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 136. hyp_path_001a98b697ba

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_04.c:42
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_04.c:42
- 结论: 文件描述符未释放：调用open()后没有调用close()，导致文件描述符泄漏。
- D验证: confirmed / ver_f49feeb5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 137. hyp_path_be5154f46d1e

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_03.c:36
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者无需控制输入，路径固定，但漏洞存在，文件描述符泄漏。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_03.c:36
- 结论: 文件描述符未释放：调用 open() 打开文件后，未调用 close() 关闭文件描述符，导致资源泄漏。
- D验证: confirmed / ver_06b430d0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 138. hyp_path_5275452a8769

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_05.c:42
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行到该代码路径即可触发漏洞，无需外部输入控制；staticTrue恒为真。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_05.c:42
- 结论: 文件打开后未关闭，导致文件描述符泄漏，可能耗尽系统资源。
- D验证: confirmed / ver_02321d74
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 139. hyp_path_aca6480a9466

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_06.c:41
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无需攻击者输入，漏洞自然存在于代码中。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_06.c:41
- 结论: CWE775: Missing Release of File Descriptor or Handle. 调用open()后未调用close()，导致文件描述符泄漏。
- D验证: confirmed / ver_2d40a9e4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 140. hyp_path_44fa4e2b5189

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_09.c:36
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行到open调用处，且GLOBAL_CONST_TRUE为真
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_09.c:36
- 结论: 文件描述符泄漏：调用open()打开文件后未调用close()释放，导致资源泄露。
- D验证: confirmed / ver_0143b8d2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 141. hyp_path_8c7a22dc26ce

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_10.c:36
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行到该open调用时，文件系统允许创建/打开该文件; open调用成功返回有效文件描述符
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_10.c:36
- 结论: 文件描述符未释放：使用open()打开文件后，没有调用close()关闭文件描述符，导致资源泄露。
- D验证: confirmed / ver_a161c272
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 142. hyp_path_c7dac6586cc3

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_07.c:41
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无特殊前提，只要执行到该代码路径即可；但需确认staticFive条件是否影响其他分支的关闭操作。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_07.c:41
- 结论: 文件描述符未释放，导致资源泄露（CWE-775）：代码通过OPEN()打开文件后，在当前代码片段中未调用close()关闭文件描述符，且未发现异常处理释放机制，但需确认完整函数路径中是否存在其他关闭操作。
- D验证: confirmed / ver_f11b7b11
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 143. hyp_path_c1eec12f7919

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_15.c:36
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 文件打开成功
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_15.c:36
- 结论: 文件描述符在打开后未释放，违反了API contract，可能导致文件描述符泄露。
- D验证: confirmed / ver_60e37db3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 144. hyp_path_8f96e7cc2951

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_14.c:36
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_14.c:36
- 结论: 文件描述符泄漏：调用open()后未调用close()，违反CWE-775（未释放文件描述符或句柄）。路径可达：globalFive==5恒真，OPEN成功打开文件后未关闭。
- D验证: confirmed / ver_bdb55378
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 145. hyp_path_f5cd7c7ffa50

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_13.c:36
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行到该代码路径，且open成功返回非负文件描述符。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_13.c:36
- 结论: 函数调用open后未关闭文件描述符，导致文件描述符泄露，违反CWE-775 Missing Release of File Descriptor or Handle。
- D验证: confirmed / ver_4b3d0263
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 146. hyp_path_585b7de91e37

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_16.c:36
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: open()调用成功返回有效文件描述符（非-1）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_16.c:36; while(1) { ... } // 无限循环，无close调用 @ 第37行开始
- 结论: 文件描述符在打开后未释放，导致资源泄漏（CWE-775）。具体为open()调用后没有对应的close()，文件描述符未被释放。
- D验证: confirmed / ver_173484a7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 147. hyp_path_0e6b21549762

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_17.c:37
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序正常执行到该代码片段
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_17.c:37
- 结论: 文件描述符未释放：在for循环中打开文件（open）后，未调用close()释放文件描述符，导致资源泄漏。
- D验证: confirmed / ver_d584707a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 148. hyp_path_393df27d8e8c

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_18.c:36
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够多次调用该函数（例如通过外部接口），且系统文件描述符数量有限。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_18.c:36
- 结论: 函数调用open()后没有关闭文件描述符，导致资源泄漏，符合CWE-775定义。
- D验证: confirmed / ver_07e75f36
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 149. hyp_path_fabe02f05840

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_31.c:36
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_31.c:36
- 结论: 文件描述符打开后未关闭，可能导致文件描述符耗尽。
- D验证: confirmed / ver_284df280
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 150. hyp_path_eb837faa5f18

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_32.c:40
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无特殊攻击者控制要求，程序正常执行到该代码路径即可触发。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_32.c:40
- 结论: 文件描述符泄漏：打开文件后未调用close()关闭文件句柄，导致文件描述符资源未被释放，长期运行可能耗尽系统文件描述符资源。
- D验证: confirmed / ver_f23f49da
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 151. hyp_path_8184e980e08d

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_33.cpp:40
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无外部控制输入，但函数调用是默认行为，程序执行到该函数即可触发。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_33.cpp:40
- 结论: 在函数 CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_33::bad 中，使用 open 系统调用打开文件描述符后，未在任何路径下调用 close 释放该文件描述符，导致文件描述符泄漏，违反 CWE-775 定义。
- D验证: confirmed / ver_cc5a5f1e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 152. hyp_path_9fef258eba1d

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_34.c:43
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够触发此代码路径多次（例如通过重复请求）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_34.c:43
- 结论: 文件打开后未释放文件描述符，导致资源泄漏（CWE-775）
- D验证: confirmed / ver_0870ccc8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 153. hyp_path_53aeba1a1934

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_42.c:42
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序以正常权限运行，能够打开文件。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_42.c:30-35; /* NOTE: No attempt to close the file */ @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_42.c:42
- 结论: 文件打开后未关闭，导致文件描述符泄漏。
- D验证: confirmed / ver_3a4e98b1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 154. hyp_path_f7b788cd45b6

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_43.cpp:36
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: open()调用成功，返回有效的文件描述符（非-1）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_43.cpp:36
- 结论: 在CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_43.cpp中，调用open()打开文件后未关闭文件描述符，违反CWE-775定义，导致资源泄露。
- D验证: confirmed / ver_5697ac5e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 155. hyp_path_4fc917d344ff

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_62b.cpp:36
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够触发该函数执行，通常通过程序正常流程调用。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_62b.cpp:36
- 结论: 文件描述符未释放：在函数case0Source中调用open()打开文件，但没有对应的close()调用关闭文件描述符，导致资源泄漏。
- D验证: confirmed / ver_52211dff
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 156. hyp_path_a70ee68d5c38

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_72b.cpp:39
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够影响dataVector的内容，使其包含来自open()的有效文件描述符
- 触发路径: int data = dataVector[2]; /* NOTE: No attempt to close the file */ ; @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_72b.cpp:39
- 结论: 在函数case0Sink中，从dataVector中取出文件描述符data，但未调用close()释放文件描述符，导致文件描述符泄漏。
- D验证: confirmed / ver_d3586547
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 157. hyp_path_5eef2e1c6f2b

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_83_case0.cpp:27
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 系统资源有限，重复调用可能导致资源耗尽
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_83_case0.cpp:27
- 结论: 文件描述符未释放：open()调用后未调用close()，导致文件描述符泄漏。
- D验证: confirmed / ver_00592b28
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 158. hyp_path_3d0e81e419ee

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84_case0.cpp:27
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行到该构造函数，且后续没有在任何地方关闭文件描述符。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84_case0.cpp:27
- 结论: 在构造函数中打开文件但不关闭，导致文件描述符泄漏，可能耗尽系统资源。
- D验证: confirmed / ver_c49e1b21
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 159. hyp_path_649ee6c54244

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_73b.cpp:39
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能多次触发该sink函数，耗尽系统文件描述符资源。
- 触发路径: int data = open(...); @ 假设的open()调用位于其他源文件（如CWE775_open_no_close_73a.cpp）; int data = dataList.back(); /* NOTE: No attempt to close the file */ ; @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_73b.cpp:39
- 结论: 文件描述符未释放漏洞：Sink函数中未关闭文件描述符，导致资源泄露。
- D验证: confirmed / ver_c3480c18
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 160. hyp_path_63b6ca04719d

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_01.c:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够触发该代码路径执行（如通过程序逻辑控制）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_01.c:29
- 结论: 函数CreateFile打开文件后未关闭句柄，导致文件句柄泄漏，违反API contract，可能造成资源耗尽。
- D验证: confirmed / ver_98cc5f2b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 161. hyp_path_0e02d091a39b

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_03.c:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无外部输入，但代码中显式打开文件后未关闭。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_03.c:29
- 结论: 文件句柄未释放导致资源泄漏：调用CreateFile打开文件后未调用CloseHandle关闭句柄，违反API contract，可能耗尽系统资源。
- D验证: confirmed / ver_5a2575f2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 162. hyp_path_79cc2018cf8f

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_02.c:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无额外攻击者控制前提，代码本身存在缺陷
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_02.c:29
- 结论: 文件句柄泄露：CreateFile创建文件句柄后未调用CloseHandle关闭，导致资源泄漏。
- D验证: confirmed / ver_dd06bc65
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 163. hyp_path_ec6a5d5c38ea

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_04.c:35
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无特殊前提，程序执行到此路径即可触发。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_04.c:35
- 结论: 使用CreateFile打开文件后未关闭句柄，导致文件描述符泄漏。
- D验证: confirmed / ver_46386c55
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 164. hyp_path_feb6d55da61f

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_05.c:35
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_05.c:35
- 结论: 在CreateFile调用创建文件句柄后，没有调用CloseHandle关闭句柄，导致文件句柄泄露。
- D验证: confirmed / ver_d2d92a40
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 165. hyp_path_0a644ef884fb

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_06.c:34
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无需攻击者控制输入，硬编码路径，CreateFile默认成功返回有效句柄
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_06.c:34
- 结论: 该代码使用CreateFile打开文件后，未调用CloseHandle关闭句柄，导致文件句柄泄漏，违反CWE775（Missing Release of File Descriptor or Handle）的API contract。
- D验证: confirmed / ver_9daaf34b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 166. hyp_path_e81d4a6dcbe2

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_07.c:34
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_07.c:34
- 结论: 文件句柄在创建后未被释放，导致资源泄漏。
- D验证: confirmed / ver_e9f00cc7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 167. hyp_path_b5c368d00307

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_10.c:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序能够成功执行CreateFile（例如文件路径可访问）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ L29
- 结论: CreateFile打开文件后，未通过CloseHandle关闭句柄，导致文件句柄泄漏，符合CWE-775。
- D验证: confirmed / ver_a81fd7dc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 168. hyp_path_611b48ddb100

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_09.c:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序能够执行到CreateFile调用
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_09.c:29
- 结论: 调用CreateFile后没有调用CloseHandle关闭文件句柄，导致文件句柄泄漏，违反CWE775 Missing Release of File Descriptor or Handle。
- D验证: confirmed / ver_d8db955f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 169. hyp_path_bb6a79ddc1a0

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_13.c:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无特殊前提，代码自动执行。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_13.c:29
- 结论: 文件句柄未释放，导致资源泄漏。
- D验证: confirmed / ver_26266ccf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 170. hyp_path_4687315694b7

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_14.c:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无需攻击者输入，代码路径自然执行即可触发。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_14.c:29
- 结论: 文件句柄未释放：CreateFile打开文件后没有调用CloseHandle关闭句柄，导致资源泄漏。
- D验证: confirmed / ver_a2008f86
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 171. hyp_path_48e8d08973b8

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_15.c:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无需攻击者控制输入，程序自身行为导致未关闭句柄
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_15.c:29
- 结论: 文件句柄未释放：CreateFile打开文件后未调用CloseHandle，导致资源泄漏。
- D验证: confirmed / ver_8c4a3b2a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 172. hyp_path_7818dd0e8b99

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_16.c:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者可能通过多次调用该路径耗尽系统句柄资源，导致拒绝服务
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_16.c:29
- 结论: 函数在调用CreateFile打开文件后未关闭句柄，导致文件句柄泄漏。违反了CWE-775：缺失释放文件描述符或句柄。
- D验证: confirmed / ver_f2f409ac
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 173. hyp_path_a556a24dd808

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_17.c:30
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_17.c:30; 缺少CloseHandle(data); @ 函数结束处
- 结论: 文件句柄未关闭导致资源泄漏：调用CreateFile打开文件后，未调用CloseHandle关闭句柄。
- D验证: confirmed / ver_3b60f93e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 174. hyp_path_e146e2a570ff

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_18.c:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: No special precondition; the vulnerability is unconditional as the file handle is never closed.
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_18.c:29
- 结论: CWE775 Missing Release of File Descriptor or Handle: CreateFile opens a file handle and never calls CloseHandle, causing a resource leak.
- D验证: confirmed / ver_12ef10c1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 175. hyp_path_03c29776119e

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_31.c:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 无特定攻击者输入；漏洞存在于正常执行流程中。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ 第29行
- 结论: 函数打开文件句柄后未关闭，导致资源泄露，违反CWE-775。
- D验证: confirmed / ver_095202d0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 176. hyp_path_1e0f1a7262c1

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_32.c:33
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 函数被调用即可触发创建文件句柄；无需用户输入。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_32.c:33
- 结论: 文件句柄泄漏：调用CreateFile打开文件后未调用CloseHandle关闭句柄，导致资源泄漏。
- D验证: confirmed / ver_40bb44e0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 177. hyp_path_e24d0f205e8b

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_33.cpp:33
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序执行到该代码路径
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_33.cpp:33
- 结论: 代码通过CreateFile打开文件，但未关闭文件句柄，导致文件描述符/句柄泄漏，违反CWE-775。由于缺乏完整函数体确认无任何关闭路径，漏洞假设仍成立但证据不完整。
- D验证: confirmed / ver_c2c17727
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 178. hyp_path_458ec818a0ac

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_34.c:36
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: CreateFile调用成功返回有效句柄
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ L36
- 结论: 文件句柄未关闭导致资源泄漏。代码中调用CreateFile打开文件后，未调用CloseHandle关闭句柄，违反了CWE775。
- D验证: confirmed / ver_08e86026
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 179. hyp_path_167f15db2e2e

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_42.c:41
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 代码路径需被执行；若CreateFile失败返回INVALID_HANDLE_VALUE，未关闭仍违反CWE775
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_42.c:26; data = case0Source(data); /* NOTE: No attempt to close the file */ @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_42.c:41
- 结论: 函数case0Source使用CreateFile打开文件，但返回后未调用CloseHandle关闭句柄，导致文件句柄泄露，违反CWE775（未释放文件描述符或句柄）。
- D验证: confirmed / ver_a544c515
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 180. hyp_path_544c65c41fac

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_43.cpp:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_43.cpp:29
- 结论: 文件句柄未释放：调用CreateFile打开文件后，未调用CloseHandle关闭句柄，导致句柄泄露。
- D验证: confirmed / ver_09d76b4a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 181. hyp_path_c34f26f6e518

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_62b.cpp:29
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者无法直接控制输入，但文件句柄泄露可能导致后续资源耗尽或拒绝服务。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_62b.cpp:29
- 结论: 使用CreateFile打开文件后未调用CloseHandle关闭句柄，导致文件句柄泄露（CWE-775）。
- D验证: confirmed / ver_efedc891
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 182. hyp_path_ea31dd77de6d

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_73b.cpp:32
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 程序通过CreateFile创建了句柄并存入dataList，此函数被调用时从列表取出句柄但未关闭。
- 触发路径: HANDLE data = dataList.back(); @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_73b.cpp:32; /* NOTE: No attempt to close the file */ ; @ CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_73b.cpp:32
- 结论: 在函数case0Sink中，从dataList获取HANDLE后未关闭文件句柄，导致资源泄漏。
- D验证: confirmed / ver_91fbbefc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 183. hyp_path_b51e4b7a3240

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_72b.cpp:32
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: dataVector[2]包含一个有效的由CreateFile返回的HANDLE
- 触发路径: HANDLE data = dataVector[2]; /* NOTE: No attempt to close the file */ ; @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_72b.cpp:32
- 结论: 函数从vector中取出文件句柄后没有关闭，导致文件句柄泄漏，违反CWE775（未释放文件描述符或句柄）。
- D验证: confirmed / ver_a20ba299
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 184. hyp_path_fdbaa086eab7

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83_case0.cpp:27
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: 攻击者无需控制输入；漏洞因开发者未释放资源而存在。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83_case0.cpp:27
- 结论: 调用CreateFile打开文件后未关闭句柄，导致文件描述符泄漏（CWE-775）。
- D验证: confirmed / ver_30d5048e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 185. hyp_path_cb0da27c694c

- 漏洞位置: juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_84_case0.cpp:27
- 漏洞类型: CWE-775
- CWE: CWE-775
- 风险等级: P0
- 触发条件: CreateFile调用成功返回有效句柄（非INVALID_HANDLE_VALUE）且后续没有其他路径关闭该句柄。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_84_case0.cpp:27
- 结论: 文件句柄未释放：CreateFile打开文件后未调用CloseHandle，导致资源泄漏。
- D验证: confirmed / ver_16d04a71
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

## Unconfirmed / Failed Verification

These records are not reported as confirmed vulnerabilities. See `verification.failed.jsonl` for full failure details.

- hyp_path_c7b0c3863598 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_72a.cpp:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c0c8ba5b3939 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_72a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c42c2836e334 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22a.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_17e101e24e86 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22a.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d86d78df6bd2 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_51a.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fdc79699fbc6 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_52a.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e820fc3f0964 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_53a.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_86426b6cc8c6 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54a.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_112f1deee7d2 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_63a.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_de0dc9681426 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_64a.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0c71791fa149 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_22a.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_296ff66a442b | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_51a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a235030f6360 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_22a.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_727df95c0c66 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_439b104dc389 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_254dc18f1f3d | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b43333639a1d | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_63a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6791bd08c875 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_64a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_22a0cbd753f4 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_74a.cpp:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_91194fe4fe09 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_73a.cpp:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0492abd5b44a | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_74a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_85f55fe3e123 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_73a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_389dfe638b35 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_84a.cpp:43 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7f1e042134ce | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_82a.cpp:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_83bb3afdc812 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_82a.cpp:43 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1734c6973e0c | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_81a.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7d943552cecd | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_62a.cpp:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_971af92d667f | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_81a.cpp:43 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9a8beedba944 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_74b.cpp:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_904bafcd3d02 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_66a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2501fe1f9a80 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_67a.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5eeb232ad3fc | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_68a.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5498622538bd | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_83a.cpp:43 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e9e2f2d31959 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_66a.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b363ca7893b7 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_67a.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_586c9aa79322 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68a.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_76386fbe231f | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83a.cpp:43 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_64b5d7cec81b | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_43.cpp:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_448c14657c51 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_52b.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_15db634ba326 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53c.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_760a9bd6452f | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53b.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6fb3d8c54e7a | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54b.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4138095ff093 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54c.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c8a2a969bceb | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_62a.cpp:31 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c843f99a262e | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54d.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9eb4c4124c7d | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_72a.cpp:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a0a74782ad4d | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_73a.cpp:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3d4a45fca609 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_62a.cpp:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_00229afab36d | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_74a.cpp:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_33b043281077 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_74b.cpp:464 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4ed7411b47e9 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_81a.cpp:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7236bb83f404 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_82a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_80ca2efb1428 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_84a.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1ac89beb18da | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_83a.cpp:46 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_152ccbc6ade7 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_43.cpp:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e7a4a3930f6a | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_52b.c:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_805ca2c72a03 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_53b.c:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_81d72b85a644 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_53c.c:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_18559baec859 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54b.c:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6104d27373cc | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54c.c:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_52fe51f3335b | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54d.c:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_db2e07820c3d | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_73a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_77bea4aee051 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_74a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_efa02913973f | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_72a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_27f3ab34d713 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_81a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7899b6e6a0e5 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_82a.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5ef64cebb1d1 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_83a.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e17c323cebd1 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84a.cpp:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_217062feb95f | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52b.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_93d694e378d4 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53b.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_223115ecdbec | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_43.cpp:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3036ab26a53d | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53c.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_989d33ac6d53 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54b.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_93cd7cb39641 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54c.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2ad77dc1ad01 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54d.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bc2b393a1c53 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_61a.c:31 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_94c7dcdf3f99 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_72a.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b62277d7d233 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_74a.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f643c83e32a8 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_62a.cpp:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8101e14167ad | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_73a.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4f2d6cade12a | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_81a.cpp:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bbc2c0afda61 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_74b.cpp:464 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b5b2382347c5 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_82a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_af8ae30c279f | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_84a.cpp:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c01b87829ed0 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83a.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1018887891a6 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_21.c:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cceb9bc8a560 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_72b.cpp:46 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_565672dd85c6 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_17.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_edee9783d1df | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_08.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f3c0e713a33a | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_11.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b02caa844c99 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_08.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f6b024ebdc33 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_12.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d709781b8c62 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_12.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9c4311bbf840 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_11.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dd129d75ec5b | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_05.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_148952c09356 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_09.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_36e618bf6d03 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_07.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0bb4ab093037 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_10.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d10cba21489f | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_08.c:97 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4da83d9f7239 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_11.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ce6b9711905f | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_13.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e54811347fa2 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_14.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a36754908978 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_07.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_46c620629f10 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_05.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3c4ab407a86c | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_09.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_27b9324033aa | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_11.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c2e35a3c56e1 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_13.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_114881d494df | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_02.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ffcebabc8915 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_14.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_adea4b88ca2d | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_10.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7737c7a4cbfb | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_03.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0e5837bda484 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_04.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_af850a50376a | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_04.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9f3b040adab1 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_06.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ce2ea4507522 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_09.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_406825a0bbae | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_05.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a6fb9cc98a82 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_07.c:89 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_81fcf72ad273 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_10.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_18e83ed7d3e9 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_14.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dc2fe6cf2eb2 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_15.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0c390199e814 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_13.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_aa52a5501132 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_33.cpp:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_851b619936ae | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_02.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6d7693187698 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_02.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a3f3eea54693 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_03.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ccecb6693af9 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_04.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_da5b43e42b67 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_09.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d4083d247f70 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_06.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_031a951e8b09 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_15.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6da90b935baf | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_14.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7112f267202e | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_13.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_57a7255ad604 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_10.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_048985de1709 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_15.c:103 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0bc6f3e17802 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_16.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3f4554b2c36e | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_18.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b89727b93ff1 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_73b.cpp:46 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0536128f5884 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_21.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e932fd2336ef | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_73b.cpp:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1539ff7215f6 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22b.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dd26fdd976fe | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_73b.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_14bcfb1c27db | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_84_case1V2.cpp:35 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1238f105abd0 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_32.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_309e015e56f1 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_83_case1V2.cpp:35 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f3327a8eca25 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84_case1V2.cpp:35 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7ad743edf9e2 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_32.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b119810f2802 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83_case1V2.cpp:41 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d805057e0a7e | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_21.c:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_13bd6e1875f0 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_84_case1V2.cpp:41 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_32f3e75b114d | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22b.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b9bddffbe6cc | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_51b.c:36 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f53f3a79a176 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_81_case1V2.cpp:29 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b4cf1b9427ee | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_41.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e223386f2500 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_52c.c:45 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d29794d0f83a | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_66b.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_72c113b5533c | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_81_case1V2.cpp:29 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1b915d6955f9 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_21.c:103 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_764b66eec6e1 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_82_case1V2.cpp:29 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_63a365e0bf2b | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_22b.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6484825962fd | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_45.c:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e5d367ab75db | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53d.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_74c97f364a2b | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_51b.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_da468fc62a02 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52c.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_166784287d3f | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_63b.c:41 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_789d945dea06 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68b.c:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_57b22b8b3a75 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_82_case1V2.cpp:29 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dce2b217be34 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_72a.cpp:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b274c6818f5b | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_51a.c:46 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a60c3edaaeb3 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22a.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c2e899aa5933 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22a.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2784db8255a9 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53a.c:46 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4cbfb182a5a6 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_52a.c:46 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4fb3e282b2b1 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54a.c:46 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_404400e94a8c | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_63a.c:45 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9c6903462430 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_74a.cpp:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_63b2b3c4297e | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_64a.c:45 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bb8d5b72d754 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_73a.cpp:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8212d202bc5a | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_81a.cpp:45 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_001bf7595fef | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_44.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_377e01826c98 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_82a.cpp:46 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3b238012b364 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_65a.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_352ea8690ffc | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_08.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d72c7473ed2b | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_05.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a1c4a756644e | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_12.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a670a65bd3d9 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_07.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5bfca4c261a2 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_11.c:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0e4390c818b6 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_11.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7dc8115aed99 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_08.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3e6129c97a21 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_10.c:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_424cd3a24a9a | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_13.c:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_588b1ea18172 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_09.c:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_49e44b79be87 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_14.c:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_436841f872fe | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_02.c:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_29b3a40c66bf | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_01.c:41 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_390a4e726022 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_03.c:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_249f06cca53a | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_04.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e340d994f776 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_06.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b02a1597d771 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_05.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a440e71ee110 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_02.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e29dc1e7813c | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_04.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_07327b429e06 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_03.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_53f96ee8fee5 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_13.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fc5202007b0b | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_09.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bc2bcec4b73a | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_14.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_049f9f6f8f85 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_07.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f56608a54ddc | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_15.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_063a63a22c44 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_15.c:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cf60fa69fc51 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_33.cpp:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3857b6d8b35d | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_42.c:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c22b42128a57 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_61b.c:36 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_75bc58ef9737 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_34.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_72f0ca5d52a2 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_65a.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e57ec64a49d6 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_44.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6fea042596ca | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_44.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1810adb25247 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_65a.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f399e2d2e987 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_66a.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c5fe2689dcc9 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_67a.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f5dfa7521d0a | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_68a.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_98cda64f574e | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_32.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ae1031f7f3aa | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_43.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_553a20d72457 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_62b.cpp:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7a4b5a953036 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_83_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8f65f3c9e02b | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_84_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7f9973e45f41 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_42.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a7d8099ceb24 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_61b.c:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e90364501a7c | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_42.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_32f7476d413c | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_61b.c:45 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7200e92da74e | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_03.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_00564e8f8e3a | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/main_linux.cpp:542 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_0110cf03c79f | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/main.cpp:343 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_0520889e447d | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_10.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6f66495832ac | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_07.c:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8bc88948de3c | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_15.c:92 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_79f7989dffa4 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_14.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_151b235c99bb | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_21.c:104 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_26b9d6eb0b9d | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22a.c:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d05c1c32f432 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_03.c:92 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4d03642de49b | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_08.c:104 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_60cb9110dab5 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_13.c:92 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8663491822e2 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_21.c:116 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_16d2bca426ef | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22a.c:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5c6787deb493 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_02.c:102 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1e1bbb6292ce | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_03.c:102 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3e1d3d3cdcfe | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_05.c:108 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8b596923a7e4 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_14.c:91 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2992962907fa | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_07.c:108 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_093353cffa2e | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_08.c:115 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8b215216570c | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_09.c:102 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5710aa8ab8a1 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_11.c:102 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1577db2345e7 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_13.c:102 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_464d76d34bf0 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_14.c:102 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_38e779baa716 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_21.c:127 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_29424f2e0ea8 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_22a.c:96 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_95aa821c9b53 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_41.c:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a504e157458d | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_44.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d73503dc5a3c | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_45.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_df7b349f5d7d | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_51a.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d38efc054974 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53a.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_96a1b5839022 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_52a.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_91f184ac7665 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54a.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_393f145054ea | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_64a.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3b75a23ce9ca | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_63a.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c2637bf632ed | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_61a.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1e313115779b | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_67a.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_46442ab1c53e | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_65a.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_df85cd0be33b | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_66a.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4b47b3b4d08e | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_68a.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_89d62600d0e9 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_41.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5193360a8cb2 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_43.cpp:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e50c432a62c6 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_45.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0f02c739d85e | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_44.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_111cc34c44bb | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_51a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_64f9a604f01d | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_53a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_55f25965fa5d | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_52a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_29def522f420 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d85fa9318c1e | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_62b.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5454f23656c5 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_63a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d4f2a7d02c4a | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_64a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a58e4fe2b7c4 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_65a.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_58ef4d48ce93 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_68a.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b2d37ea6d704 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_66a.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5da2c56e4387 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_67a.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7dfe6a6dfad5 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_83_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2486a5e8e965 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1f2a68f42f43 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_31.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4806873205ae | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_41.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2c9b0d8e218a | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_43.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_42107ea7bff3 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_44.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_28c8dc9b2fc5 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_51a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d2241b3283cf | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a3fbe9d3b9f0 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_45.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_47fe58e0f7e3 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_52a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_30d78178c1ac | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_54a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5ac618bbaaad | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_62b.cpp:46 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5086ac4774ce | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_63a.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_def467d7d644 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_65a.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_115bdbe06e29 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_64a.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5123ab4f721e | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_67a.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c408d9600816 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_66a.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0ca95ffc35a9 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68a.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f11549421b97 | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_84_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_11c3f0e1297f | juliet-api-misuse/testcases/CWE775_Missing_Release_of_File_Descriptor_or_Handle/CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
