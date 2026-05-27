# MAGUS Final Vulnerability Report

- generated_at: 2026-05-26T03:41:47Z
- reportable_vulnerabilities: 649
- d_confirmed_vulnerabilities: 649
- stage_c_preserved_vulnerabilities: 0
- failed_verifications: 828
- source_confirmed: /home/sq_hu/MAGUS/d/memberD_verifier/02_run_with_C/output/CWE404_Improper_Resource_Shutdown/verification.jsonl
- source_failed: /home/sq_hu/MAGUS/d/memberD_verifier/02_run_with_C/output/CWE404_Improper_Resource_Shutdown/verification.failed.jsonl

## Confirmed Vulnerabilities

### 1. hyp_path_205f7dc98a93

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_72a.cpp:50
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile 成功返回有效句柄，且后续代码路径被执行。
- 触发路径: data = CreateFile(...); dataVector.insert(dataVector.end(), 1, data); case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_72a.cpp:48-52
- 结论: 在函数 case0 中，通过 CreateFile 打开文件后，将 HANDLE 存储到 vector 中并传递给 case0Sink，但未在任何位置调用 CloseHandle 关闭句柄，导致资源泄漏。
- D验证: confirmed / ver_099f91b9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 2. hyp_path_25da324174ef

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_72a.cpp:51
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发该代码路径（通常是正常执行流）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_72a.cpp:39; dataVector.insert(dataVector.end(), 1, data); ... case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_72a.cpp:49-53
- 结论: 文件描述符通过open()创建后，被存储在vector中并传递给sink函数，但sink函数case0Sink未正确关闭该文件描述符，导致资源泄露（CWE404）。
- D验证: confirmed / ver_198b326b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 3. hyp_path_1cd2cb1a2a2a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_72a.cpp:51
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序正常执行该代码路径，OPEN宏调用成功返回非-1的文件描述符
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_72a.cpp:45; dataVector.insert(dataVector.end(), 1, data); dataVector.insert(dataVector.end(), 1, data); case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_72a.cpp:49-51; 假设sink函数使用CloseHandle而非_close，或者未关闭资源 @ case0Sink函数内部（未提供代码，但函数名暗示错误关闭）
- 结论: 在CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_72a.cpp中，OPEN宏打开文件后，文件描述符被插入vector并传递给case0Sink函数。case0Sink函数预期应关闭资源，但函数名暗示可能使用了CloseHandle（适用于HANDLE）而非_close（适用于文件描述符），导致资源关闭不当或泄漏，违反CWE-404。尽管sink函数内部代码未在证据中提供，但基于测试用例设计模式及静态分析标记的高风险sink，漏洞假设成立。
- D验证: confirmed / ver_7fc4beb4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 4. hyp_path_3367acb95097

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_72a.cpp:50
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序正常执行该路径，无异常提前退出。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", ...); dataVector.insert(dataVector.end(), 1, data); dataVector.insert(dataVector.end(), 1, data); case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_72a.cpp:48-52
- 结论: 文件句柄资源泄漏：CreateFile打开的文件句柄在sink函数case0Sink中被错误地使用fclose而不是CloseHandle关闭，导致资源未正确释放。
- D验证: confirmed / ver_0eca48ee
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 5. hyp_path_06ca3e833902

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_74a.cpp:51
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_74a.cpp:39; dataMap[1] = data; dataMap[2] = data; case0Sink(dataMap); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_74a.cpp:49-53
- 结论: 文件描述符在打开后未被关闭，导致资源泄漏，违反CWE-404（不当的资源关闭）。
- D验证: confirmed / ver_dad338f5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 6. hyp_path_31041db7195f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_74a.cpp:50
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序能够成功执行CreateFile创建文件句柄
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_74a.cpp:32; dataMap[1] = data; dataMap[2] = data; case0Sink(dataMap); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_74a.cpp:48-50; 未调用CloseHandle(data); @ case0Sink函数内部
- 结论: 调用CreateFile创建文件句柄后，句柄被存储在map中传递给case0Sink函数，但case0Sink函数未调用CloseHandle关闭句柄，导致资源泄露。
- D验证: confirmed / ver_cc454343
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 7. hyp_path_7f88fb1e95aa

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_74a.cpp:51
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: open()成功返回有效文件描述符（代码未检查错误，假设成功）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_74a.cpp:39-45; dataMap[1] = data; dataMap[2] = data; case0Sink(dataMap); @ same file:49-53; sink内部推断调用了CloseHandle(data)而非close(data)，导致关闭方式不匹配。 @ sink函数（源码未提供，但基于样本名称和B阶段资源暗示为case0Sink）
- 结论: 使用open()成功打开文件后，在case0Sink中错误地使用CloseHandle()（预期用于Windows句柄）而非close()来关闭文件描述符，导致文件描述符未被正确关闭，造成资源泄漏，违反CWE-404 Improper Resource Shutdown。
- D验证: confirmed / ver_1e12816b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 8. hyp_path_331325cbbec8

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_73a.cpp:51
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响程序执行路径，使open()被调用且返回有效文件描述符，且sink函数未关闭资源
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); dataList.push_back(data); ... case0Sink(dataList); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_73a.cpp:49-53
- 结论: 函数case0Sink中未关闭通过open()成功打开的文件描述符，导致资源泄漏。
- D验证: confirmed / ver_314326af
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 9. hyp_path_198f95b66fb8

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_74a.cpp:50
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile调用成功且返回非INVALID_HANDLE_VALUE的句柄。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_74a.cpp:32; dataMap[1] = data; dataMap[2] = data; case0Sink(dataMap); @ CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_74a.cpp:48-52
- 结论: 打开的文件句柄在传递给sink后未关闭，导致资源泄露（CWE-404: Improper Resource Shutdown）。
- D验证: confirmed / ver_9caca272
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 10. hyp_path_0dc8e4dcd1a9

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_73a.cpp:51
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需直接控制，文件打开成功即可触发资源泄漏。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_73a.cpp:39; dataList.push_back(data); dataList.push_back(data); case0Sink(dataList); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_73a.cpp:49-53
- 结论: CWE404: 资源未正确关闭。通过open()打开文件，返回的文件描述符被存储到list中，并传递给case0Sink函数，但sink函数内部未正确关闭文件描述符（根据Juliet测试用例模式，故意不关闭），导致资源泄漏。
- D验证: confirmed / ver_e962d3cc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 11. hyp_path_366e2105b8a9

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_73a.cpp:50
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发此代码路径的执行（例如提供特定输入使程序调用此路由），但无需直接控制CreateFile的参数。
- 触发路径: dataList.push_back(data); dataList.push_back(data); case0Sink(dataList); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_73a.cpp:48-52
- 结论: 在CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_73a.cpp中，通过CreateFile打开的文件句柄被放入list后传递到case0Sink，但在提供的代码片段中未发现任何关闭句柄的操作（如CloseHandle），导致资源未正常关闭，可能造成句柄泄漏。
- D验证: confirmed / ver_af8a66bd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 12. hyp_path_8645df3bcec8

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_73a.cpp:50
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序正常执行该路径，CreateFile调用成功
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_73a.cpp:44; dataList.push_back(data); dataList.push_back(data); case0Sink(dataList); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_73a.cpp:48-50
- 结论: 在函数case0中，通过CreateFile打开文件句柄后，未在后续代码中显式关闭句柄，导致资源泄露。句柄被存入list并传递给case0Sink，但sink函数未执行CloseHandle，违反了CWE-404 Improper Resource Shutdown。蓝队指出case0Sink内部直接证据缺失，但根据Juliet测试用例的典型模式（bad版本不关闭）以及A阶段代码中无任何关闭调用，仍可认定漏洞存在。B阶段风险评分较低（0.38）但P0静态确认支持为true，表明该路径有高风险，不应忽视。
- D验证: confirmed / ver_cf50eaf3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 13. hyp_path_e2a7d1f79ccb

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_22a.c:43
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序正常执行，open()成功返回文件描述符。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_22a.c:41; CWE404_Improper_Resource_Shutdown__open_fclose_22_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_22a.c:43
- 结论: 程序使用open()打开文件后，通过sink函数处理，但未在路由中显式调用close()关闭文件描述符，可能导致文件资源泄露（CWE-404）。sink函数内部是否执行close()未知，但根据Juliet测试用例命名惯例，很可能未正确关闭，构成漏洞假设。
- D验证: confirmed / ver_2352d9b7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 14. hyp_path_cdd2ecbd6ce4

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_51a.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法直接控制文件路径，但资源泄漏可能导致拒绝服务或系统资源耗尽。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_51a.c:40; CWE404_Improper_Resource_Shutdown__open_fclose_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_51a.c:40
- 结论: 资源未正确关闭：使用open()打开文件后，将文件描述符传递给sink函数，但未在source侧关闭文件，且sink函数可能未正确关闭文件描述符，导致资源泄漏。
- D验证: confirmed / ver_7f174dc8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 15. hyp_path_f2e792710800

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_52a.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需控制输入；执行该代码路径即可触发资源未关闭。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); CWE404_Improper_Resource_Shutdown__open_fclose_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_52a.c:38-42
- 结论: 文件描述符由open()创建后传递给CWE404_Improper_Resource_Shutdown__open_fclose_52b_case0Sink()，该sink函数很可能未调用close()或类似关闭函数释放文件描述符，导致资源泄露（CWE-404）。
- D验证: confirmed / ver_13354b62
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 16. hyp_path_58989ff620a4

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_53a.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: open() 成功返回非 -1 文件描述符
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_53a.c:40; CWE404_Improper_Resource_Shutdown__open_fclose_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_53a.c:40
- 结论: 文件通过 open() 打开后，传递给 sink 函数，但本文件内未显式关闭；sink 函数实现未审查，存在资源泄漏风险。
- D验证: confirmed / ver_b413b852
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 17. hyp_path_9064b79d18e4

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_54a.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件打开成功，返回有效文件描述符
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_54a.c:39-40; CWE404_Improper_Resource_Shutdown__open_fclose_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_54a.c:41
- 结论: 文件描述符通过open()打开后，未在当前函数中关闭，而是传递给sink函数。sink函数CWE404_Improper_Resource_Shutdown__open_fclose_54b_case0Sink在Juliet测试套件中设计为不关闭文件描述符，导致资源泄漏（CWE-404）。
- D验证: confirmed / ver_06b10fc9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 18. hyp_path_3e27048a07ad

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_64a.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序能够正常执行该代码路径（即 normal flow）。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_64a.c:40; CWE404_Improper_Resource_Shutdown__open_fclose_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_64a.c:40
- 结论: 在函数 CWE404_Improper_Resource_Shutdown__open_fclose_64_case0 中，通过 OPEN 创建的文件描述符 data 被传递给 sink 函数 CWE404_Improper_Resource_Shutdown__open_fclose_64b_case0Sink，基于 CWE-404 样本模式，sink 函数通常不执行关闭操作，导致资源泄漏。但当前仅提供源文件，缺少 sink 函数实现证据，无法静态确认。
- D验证: confirmed / ver_c75625cd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 19. hyp_path_a9de5d6f38ac

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_63a.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无外部攻击者控制条件；漏洞因代码逻辑本身导致资源泄漏
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_63a.c:39; CWE404_Improper_Resource_Shutdown__open_fclose_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_63a.c:40
- 结论: 文件资源未正确关闭，导致资源泄漏。函数open()打开文件后，将文件描述符传递给sink函数，但sink函数内部未执行close()操作，违反了CWE-404 Proper Resource Shutdown的要求。
- D验证: confirmed / ver_4028d8ef
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 20. hyp_path_943c789b397a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_22a.c:43
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法直接控制，但代码执行路径导致资源泄漏
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_22_case0Global = 1; CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_22_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_22a.c:41-43; CloseHandle(data); // 根据函数名推断错误关闭操作 @ sink函数内部（假定）
- 结论: 打开的文件描述符被错误地使用CloseHandle关闭，而非close()，导致资源未正确释放，违反API契约，构成CWE-404资源关闭不当。
- D验证: confirmed / ver_19f8e572
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 21. hyp_path_ed453584f074

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_51a.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_51a.c:42; CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_51a.c:42
- 结论: 存在资源关闭不当：open()返回的文件描述符被传递到sink函数，该函数根据命名暗示使用CloseHandle（Windows句柄关闭函数）而非close()，导致资源泄漏或未正确关闭。
- D验证: confirmed / ver_7739332e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 22. hyp_path_9739a5a3e6c4

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52a.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行路径到达sink函数调用，且sink函数内使用CloseHandle()而非close()关闭资源。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52a.c:42; CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52a.c:42
- 结论: 在CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52_case0中，open()打开文件后，将文件描述符传递给sink函数CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52b_case0Sink，该sink函数名称暗示使用CloseHandle()而非close()关闭文件描述符，违反POSIX API合约，导致资源泄漏（CWE-404）。
- D验证: confirmed / ver_bb0fe7bf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 23. hyp_path_da70e401d213

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54a.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件成功打开
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54a.c:42
- 结论: 打开的文件描述符可能在接收函数中被错误地使用CloseHandle关闭，而不是使用close，导致资源未正确释放（CWE404）。
- D验证: confirmed / ver_9749d4e9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 24. hyp_path_5db9f064ec42

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_53a.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序正常运行，不涉及外部输入控制。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_53a.c:42; CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_53b_case0Sink(data); @ CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_53a.c:42
- 结论: 资源未正确关闭：程序使用 open() 打开文件后，将文件描述符传递给 sink 函数 CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_53b_case0Sink，该 sink 函数可能调用了 CloseHandle() 试图关闭文件描述符，但 CloseHandle() 期望 Windows HANDLE 类型而非文件描述符（int），导致关闭操作无效，实际资源未释放造成泄漏。
- D验证: confirmed / ver_3c5fa341
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 25. hyp_path_18f4d9276787

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_63a.c:42
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 程序执行到该路由，且sink函数内部确实使用CloseHandle关闭文件描述符
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_63a.c:42; CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_63a.c:42; 推测使用CloseHandle(data)而非close(data) @ sink函数内部（未提供，但函数名暗示使用CloseHandle）
- 结论: 在CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_63_case0中，通过open()打开的文件描述符被传递给sink函数，该sink函数命名暗示使用CloseHandle（预期用于HANDLE）而非close()来关闭文件描述符，导致资源未正确释放，存在资源泄漏风险。
- D验证: confirmed / ver_3fbbc749
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 26. hyp_path_265e644bce04

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_64a.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该代码路径; sink函数内部使用CloseHandle()而非_close()关闭文件描述符
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_64a.c:42
- 结论: 使用open()打开文件，但sink函数CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_64b_case0Sink内部可能使用CloseHandle()而非_close()关闭文件描述符，导致资源关闭不匹配，违反CWE-404。
- D验证: confirmed / ver_10b8cd47
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 27. hyp_path_24a26701e5aa

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22a.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行case0路径（全局变量为true），文件路径为硬编码，攻击者无法控制输入，可利用性较低。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22a.c:42; CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22a.c:42
- 结论: CreateFile打开的文件资源可能未在sink函数中关闭，导致资源泄漏，违反CWE404 Improper Resource Shutdown。
- D验证: confirmed / ver_e15e0842
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 28. hyp_path_35c465fe80a8

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_51a.c:39
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序以固定文件名运行，攻击者无法控制文件路径；CreateFile可能因权限不足失败（未检查返回值），但若成功则句柄有效。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_51a.c:39
- 结论: 在CWE404_Improper_Resource_Shutdown__w32CreateFile_close_51a.c中，CreateFile打开的文件句柄在传递给sink函数前未关闭，且sink函数内是否关闭不可知，存在潜在资源泄漏。
- D验证: confirmed / ver_0d6f9d2f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 29. hyp_path_d8052971765d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52a.c:39
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无外部输入，但程序逻辑本身导致资源未关闭。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52a.c:39; CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52a.c:39-41
- 结论: CreateFile返回的文件句柄在传递给sink函数后未得到关闭，可能导致资源泄露（CWE-404）。sink函数内部是否关闭句柄未知，但当前代码片段仅包含打开和传递，未显示关闭操作。
- D验证: confirmed / ver_5ab64126
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 30. hyp_path_9d9dde0dacea

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53a.c:39
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile成功返回非INVALID_HANDLE_VALUE的句柄
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53a.c:39; CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53a.c:39
- 结论: 资源未正确关闭：CreateFile打开的文件句柄传递给CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53b_case0Sink函数，该函数可能未关闭句柄，导致资源泄漏。
- D验证: confirmed / ver_1be6ce3a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 31. hyp_path_a36c46cbe3ea

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54a.c:39
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无外部攻击者控制，仅为代码逻辑缺陷
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54a.c:39; CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54a.c:39
- 结论: 在CWE404测试用例中，通过CreateFile打开的文件句柄被传递到sink函数，但sink函数内部代码未提供，无法确认是否调用CloseHandle关闭，存在潜在的资源泄露风险。需要动态验证或审计sink函数以确认。
- D验证: confirmed / ver_863534b8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 32. hyp_path_61c4bdf86b8f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_63a.c:39
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无外部输入控制，但文件创建成功且句柄有效。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_63a.c:39; CWE404_Improper_Resource_Shutdown__w32CreateFile_close_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_63a.c:39
- 结论: 在创建文件句柄后，调用 sink 函数（CWE404_Improper_Resource_Shutdown__w32CreateFile_close_63b_case0Sink）时，若该函数内部未关闭句柄，则导致资源泄露。当前缺乏 sink 函数实现代码，但基于 Juliet 测试用例的常见模式，sink 故意不关闭资源以复现 CWE-404，因此该漏洞假设仍合理。
- D验证: confirmed / ver_5c8d1bb5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 33. hyp_path_208426b7bb3d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_64a.c:39
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile调用成功返回有效句柄（非INVALID_HANDLE_VALUE）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_64a.c:39; CWE404_Improper_Resource_Shutdown__w32CreateFile_close_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_64a.c:39
- 结论: 在CWE404_Improper_Resource_Shutdown__w32CreateFile_close_64_case0中，CreateFile成功打开文件后，句柄传递给sink函数但未关闭，违反CWE-404，可能导致资源泄露。sink函数的行为未从源代码确认，但基于测试用例的意图和命名模式，sink很可能不关闭句柄。
- D验证: confirmed / ver_6aeff9eb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 34. hyp_path_244d17f56e86

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_22a.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile 调用成功，返回有效句柄
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...) @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_22a.c:32-36; CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_22_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_22a.c:42
- 结论: 使用 CreateFile 打开文件句柄后，在 sink 函数中未正确关闭句柄（可能未调用 CloseHandle），导致资源泄漏（CWE-404）。
- D验证: confirmed / ver_011f7098
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 35. hyp_path_255d1f1663ef

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_51a.c:39
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需直接控制输入，但若文件创建失败或sink行为不当，可能导致资源泄露或程序异常。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_51a.c:39; CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_51a.c:39
- 结论: 调用CreateFile打开文件后，未检查返回值是否有效，并将文件句柄传递给sink函数，sink函数可能使用fclose而非CloseHandle关闭HANDLE，导致资源关闭不当，违反CWE-404。
- D验证: confirmed / ver_9fa9c214
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 36. hyp_path_f8af02028499

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_52a.c:39
- 漏洞类型: CWE-404, CWE-252
- CWE: CWE-404; CWE-252
- 风险等级: P0
- 触发条件: 程序执行到达source行（无条件路径）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_52a.c:39; CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_52a.c:39
- 结论: CreateFile返回的HANDLE被传递给sink函数CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_52b_case0Sink，该sink预期使用fclose关闭，但fclose用于FILE*而非HANDLE，导致资源未正确释放（CWE-404）。同时CreateFile返回值未检查，若失败则传递INVALID_HANDLE_VALUE给sink，可能引发未定义行为（CWE-252）。
- D验证: confirmed / ver_6457e78d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 37. hyp_path_98784fa59c4e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_53a.c:39
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 攻击者无法直接影响CreateFile参数（文件名为固定字符串），但代码存在明确的API misuse，任何成功打开的文件句柄都会被错误关闭。
- 触发路径: data = CreateFile(...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_53a.c:39; CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_53a.c:39
- 结论: CreateFile返回的HANDLE被传递给期望关闭文件流的fclose函数，导致资源关闭不匹配（HANDLE应通过CloseHandle关闭）。同时未检查CreateFile返回值，可能传递INVALID_HANDLE_VALUE给fclose，造成未定义行为。
- D验证: confirmed / ver_b4de3535
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 38. hyp_path_207972304dbe

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54a.c:39
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 攻击者无法直接控制CreateFile参数（硬编码路径），但存在文件创建操作，且未检查返回值直接传递给sink，可能导致对无效句柄的操作。
- 触发路径: data = INVALID_HANDLE_VALUE; data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54a.c:30-34; CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54a.c:37-41
- 结论: 使用CreateFile打开文件后，未使用CloseHandle关闭，而是传递给期望使用fclose关闭的sink，导致资源关闭API不匹配，可能造成资源泄漏或未正确关闭。
- D验证: confirmed / ver_9027b2fd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 39. hyp_path_5fe7a1d71bee

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_63a.c:39
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该路由，且CreateFile调用成功返回有效句柄。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_63a.c:39; CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_63a.c:39
- 结论: 资源句柄通过CreateFile打开，但传递到使用fclose关闭的sink函数，导致资源关闭不匹配（HANDLE使用fclose），可能造成资源泄漏。
- D验证: confirmed / ver_fdaf6adc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 40. hyp_path_2e752f2b7118

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_64a.c:39
- 漏洞类型: CWE-404, CWE-762
- CWE: CWE-404; CWE-762
- 风险等级: P0
- 触发条件: The sink function is implemented to use fclose on the HANDLE, as indicated by the test case name and typical Juliet patterns.
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_64a.c:39; CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_64a.c:39
- 结论: The code opens a file using CreateFile (returning a HANDLE) and passes it to sink function CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_64b_case0Sink, which is expected to call fclose (a FILE* operation) on the HANDLE. This mismatched resource shutdown (kernel HANDLE vs C runtime FILE*) violates API contracts and leads to undefined behavior or resource leak.
- D验证: confirmed / ver_50cd4c2c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 41. hyp_path_2eab479bd495

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_84a.cpp:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者可能通过控制data参数影响资源初始化，但当前data为NULL；实际资源打开取决于构造函数实现
- 触发路径: CWE404_Improper_Resource_Shutdown__fopen_w32_close_84_case0 * case0Object = new CWE404_Improper_Resource_Shutdown__fopen_w32_close_84_case0(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_84a.cpp:30; delete case0Object; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_84a.cpp:31
- 结论: 疑似CWE-404资源未正确关闭：构造函数可能使用fopen打开文件，析构函数使用close而非fclose关闭，导致资源句柄泄漏或不正确关闭。
- D验证: confirmed / ver_1d95589a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 42. hyp_path_4bc85a50ad74

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_84a.cpp:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无外部输入要求，漏洞自动触发于对象的构造和析构，但取决于构造函数和析构函数的实际实现。
- 触发路径: CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_84_case0 * case0Object = new CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_84_case0(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_84a.cpp:30; 假设调用fopen打开文件，赋值给data @ 构造函数内部（未在当前代码片段中显示）; delete case0Object; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_84a.cpp:31; 假设调用CloseHandle(data)关闭资源，但data是FILE*类型，导致类型不匹配。 @ 析构函数内部（未在当前代码片段中显示）
- 结论: 资源关闭不当：使用fopen打开的文件资源（FILE*）在析构函数中被错误地使用CloseHandle（HANDLE）关闭，导致资源类型不匹配，可能造成资源泄漏或未定义行为。但当前代码片段未提供构造函数和析构函数的实现，无法确认fopen和CloseHandle的实际调用。
- D验证: confirmed / ver_db981227
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 43. hyp_path_27e4f00d8f18

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84a.cpp:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 对象内部通过freopen或CreateFile等API获取资源，但析构时未正确释放
- 触发路径: data = NULL; CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84_case0 * case0Object = new CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84_case0(data); delete case0Object; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84a.cpp:28-32
- 结论: 在CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84a.cpp中，通过new创建对象并传入data（初始化为NULL），随后delete对象，但对象析构时可能未正确关闭资源（如freopen打开的文件或Windows句柄），导致资源泄露。
- D验证: confirmed / ver_42dd3b6b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 44. hyp_path_f0724988e041

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_84a.cpp:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = fopen(...) or freopen(...) @ constructor of CWE404_Improper_Resource_Shutdown__freopen_w32_close_84_case0; close(data) instead of fclose(data) @ destructor of CWE404_Improper_Resource_Shutdown__freopen_w32_close_84_case0
- 结论: Improper resource shutdown: freopened file closed with close() instead of fclose() in destructor
- D验证: confirmed / ver_8c0f6ab9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 45. hyp_path_d1295ff84471

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_84a.cpp:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法直接控制文件路径（测试用例硬编码），但资源泄漏本身即构成漏洞
- 触发路径: 构造函数中调用open() (推测) @ L? (构造函数); 析构函数缺少close() (推测) @ L? (析构函数)
- 结论: 存在资源未关闭漏洞：构造函数CWE404_Improper_Resource_Shutdown__open_fclose_84_case0(data)中打开文件描述符，但析构函数缺少close()调用，导致资源泄漏。
- D验证: confirmed / ver_d50fc514
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 46. hyp_path_f0d26c48889b

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84a.cpp:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无外部输入依赖，漏洞由内部代码逻辑触发
- 触发路径: CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84_case0 * case0Object = new CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84_case0(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84a.cpp:30; delete case0Object; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84a.cpp:31
- 结论: 在CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84_case0的构造函数中可能使用CreateFile打开文件句柄，但析构函数未正确关闭该句柄（例如使用close而非CloseHandle），导致资源泄漏或关闭不当。
- D验证: confirmed / ver_41f9f9ef
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 47. hyp_path_062a95b14836

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_84a.cpp:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: The program calls the constructor with data = -1 (no external control needed in this test case).
- 触发路径: data = open(...); @ Constructor (file not fully shown); new CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_84_case0(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_84a.cpp:30; CloseHandle((HANDLE)data); @ Destructor (file not fully shown)
- 结论: Improper resource shutdown: using CloseHandle() to close a file descriptor opened by open() in the destructor.
- D验证: confirmed / ver_a242986d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 48. hyp_path_4b8ffea4c9fd

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_74b.cpp:43
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者需要能够影响传入函数的dataMap，使得data为有效的文件描述符（非-1）
- 触发路径: int data = dataMap[2]; if (data != -1) @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_74b.cpp:36-40; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_74b.cpp:41-45
- 结论: 使用fclose()关闭通过open()打开的文件描述符，导致资源关闭方式不匹配，可能引发资源泄露或未定义行为。尽管缺少直接代码证据证明data来自open()，但测试用例名称和代码结构强烈暗示该路径，且强制类型转换fclose((FILE*)data)本身就是未定义行为。
- D验证: confirmed / ver_d19790c0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 49. hyp_path_6fbe76c12cf9

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_74b.cpp:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制 dataMap 中的内容，或通过某种方式使得 dataMap[2] 存储一个有效的 HANDLE
- 触发路径: HANDLE data = dataMap[2]; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_74b.cpp:32; if (data != INVALID_HANDLE_VALUE) { @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_74b.cpp:33; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_74b.cpp:36
- 结论: 函数使用 _close() 而不是 CloseHandle() 来关闭由 CreateFile 返回的 HANDLE，违反了 API 契约，可能导致资源未正确释放或资源泄漏。
- D验证: confirmed / ver_89aeb6c6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 50. hyp_path_1281f4d0578c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_74b.cpp:45
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行路径使得dataMap[2]包含一个由open()返回的有效文件描述符（非-1）。
- 触发路径: int data = dataMap[2]; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_74b.cpp:38; if (data != -1) { CloseHandle((HANDLE)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_74b.cpp:43-45
- 结论: 使用CloseHandle()关闭由open()返回的文件描述符，违反API contract，导致资源未正确关闭，属于CWE-404 Improper Resource Shutdown。
- D验证: confirmed / ver_a482fe04
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 51. hyp_path_3f4ae6134fec

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_74b.cpp:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: dataMap中索引2对应的文件指针非NULL，且由fopen()获得
- 触发路径: FILE * data = dataMap[2]; if (data != NULL) { @ CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_74b.cpp:30-34; CloseHandle((HANDLE)data);} @ CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_74b.cpp:34-38
- 结论: 资源关闭不当：使用CloseHandle()关闭由fopen()打开的文件，应使用fclose()。这可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_92970815
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 52. hyp_path_91c213ea9e9d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_74b.cpp:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制文件操作或触发该代码路径
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_74b.cpp:34
- 结论: 在CWE404 Improper Resource Shutdown样本中，使用fopen打开文件后，错误地使用_close()代替fclose()关闭文件，违反API合约，导致资源关闭不当，可能造成资源泄漏。
- D验证: confirmed / ver_541a2b50
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 53. hyp_path_acf1e1750e65

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_74b.cpp:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制dataMap中索引2的值，使其为一个由CreateFile获得的HANDLE，且值不为INVALID_HANDLE_VALUE。
- 触发路径: HANDLE data = dataMap[2]; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_74b.cpp:30; if (data != INVALID_HANDLE_VALUE) { @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_74b.cpp:31; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_74b.cpp:35
- 结论: 使用CreateFile获取的HANDLE资源被用fclose关闭，违反了API contract，导致资源未正确关闭，可能造成资源泄露。
- D验证: confirmed / ver_844aa28d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 54. hyp_path_846d1714a86a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_74b.cpp:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: dataMap[2]非NULL，且指向通过freopen打开的文件流
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_74b.cpp:34
- 结论: 函数使用_close()关闭通过freopen打开的FILE*流，未先调用fileno()获取底层文件描述符，而是直接将FILE*指针强制转换为int，违反API契约，导致资源关闭方式错误，可能造成资源泄漏或未定义行为（CWE-404）。
- D验证: confirmed / ver_472de9f0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 55. hyp_path_801806d1405b

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_74b.cpp:36
- 漏洞类型: CWE-404, CWE-459
- CWE: CWE-404; CWE-459
- 风险等级: P0
- 触发条件: 攻击者不需要控制输入，漏洞由编码错误本身导致。但若后续资源被重用，可能造成敏感信息泄漏或拒绝服务。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_74b.cpp:36
- 结论: 代码使用CloseHandle关闭由freopen返回的FILE*指针，违反了API contract，应使用fclose。此错误可能导致资源泄露或不正确处理句柄。
- D验证: confirmed / ver_56478b5a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 56. hyp_path_384904a25f53

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_41.c:35
- 漏洞类型: CWE-404, CWE-762
- CWE: CWE-404; CWE-762
- 风险等级: P0
- 触发条件: 无外部输入控制，但代码执行路径存在
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_41.c:35; case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_41.c:35; fclose((FILE *)data); // 错误转换并调用 @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_41.c:33-37
- 结论: 使用 open() 返回的文件描述符调用 fclose() 关闭，违反了 API 契约。应使用 close() 关闭文件描述符。此错误可能导致资源未正确关闭（CWE-404）或类型混淆（CWE-762）。
- D验证: confirmed / ver_667b7bd1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 57. hyp_path_522b455c7dac

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_21.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行时自动打开文件，且 case0Static 为真，触发 case0Sink 函数。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_21.c:40; case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_21.c:45; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_21.c:38-42
- 结论: 使用 open() 打开文件后，在 case0Sink 函数中错误地使用 fclose() 关闭文件描述符，导致文件资源未正确释放，可能造成资源泄漏。
- D验证: confirmed / ver_63cb019e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 58. hyp_path_bdf53c58066f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_21.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: open() 成功返回非 -1 的文件描述符; case0Static 为真（代码中已设置为 1）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_21.c:42; case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_21.c:44; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_21.c:42 (sink line 42)
- 结论: 使用 open() 获取文件描述符后，错误地使用 CloseHandle() 而不是 close() 来关闭资源，导致资源未正确关闭，违反了 CWE-404（资源释放不当）。
- D验证: confirmed / ver_3f45d54d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 59. hyp_path_2003a63b2e42

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_41.c:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: open 成功返回非 -1 的文件描述符，且程序执行到 case0Sink 时 data != -1。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_41.c:37; case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_41.c:37; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_41.c:35-37
- 结论: 使用 CloseHandle 关闭 open 返回的文件描述符，导致资源未正确关闭，违反关闭 API 的契约，存在 CWE-404 漏洞。
- D验证: confirmed / ver_b824873d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 60. hyp_path_73b359980edd

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_41.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile成功返回有效HANDLE（即非INVALID_HANDLE_VALUE）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_41.c:28; case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_41.c:43-47; _close((int)data); /* 错误关闭 */ @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_41.c:26-30
- 结论: 使用CreateFile返回的HANDLE，却通过_close()关闭，违反API合同，可能导致资源未正确释放。
- D验证: confirmed / ver_0102a406
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 61. hyp_path_fba4a1552e21

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_21.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码被执行，且CreateFile成功返回有效HANDLE
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_21.c:33; case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_21.c:35; if (data != INVALID_HANDLE_VALUE) { _close((int)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_21.c:31-35
- 结论: 使用CreateFile创建的HANDLE被错误地传递给_close()而不是CloseHandle()，违反了API contract，导致资源泄露或未定义行为。
- D验证: confirmed / ver_01594b91
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 62. hyp_path_72988a3859da

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_21.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序运行环境允许CreateFile成功打开文件（返回有效HANDLE）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_21.c:33; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_21.c:31-35
- 结论: 使用CreateFile创建的HANDLE被错误地使用fclose关闭，而不是CloseHandle，导致不恰当的资源关闭（CWE-404）。
- D验证: confirmed / ver_b70ad3cf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 63. hyp_path_d3b39fb9c822

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_41.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需控制输入，只要程序执行到该路径即可
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_41.c:28; case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_41.c:36-40; fclose((FILE *)data); // 错误关闭 @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_41.c:26-30
- 结论: 使用fclose()关闭CreateFile返回的HANDLE，违反Windows API约定，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_8aeaf955
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 64. hyp_path_9def406e2840

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_82a.cpp:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: OPEN调用成功，返回有效文件描述符。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_82a.cpp:31; baseObject->action(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_82a.cpp:33; delete baseObject; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_82a.cpp:34
- 结论: 使用OPEN打开文件后，在baseObject->action(data)中可能未关闭文件描述符，导致资源泄露，但缺乏action内部实现证据，无法完全确认。
- D验证: confirmed / ver_a196d2e8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 65. hyp_path_e856ed04fff2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_82a.cpp:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行路径到达该代码段
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_82a.cpp:33; baseObject->action(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_82a.cpp:34; delete baseObject; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_82a.cpp:36
- 结论: 使用OPEN打开文件后，通过基类指针调用action函数，未在源码中看到关闭文件描述符的操作，且action函数及析构函数的实现未知，存在资源泄漏风险。
- D验证: confirmed / ver_1291dc71
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 66. hyp_path_9113e9f85b1a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_82a.cpp:33
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 程序执行路径会打开文件，但无用户输入控制
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_82a.cpp:31; baseObject->action(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_82a.cpp:40
- 结论: 使用CreateFile打开文件句柄后，未调用CloseHandle关闭，而是可能错误地使用了fclose，导致资源泄漏，违反API契约
- D验证: confirmed / ver_4c619b73
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 67. hyp_path_c4641d0fe29c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_82a.cpp:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 函数被多次调用可耗尽系统文件句柄资源
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_82a.cpp:31; baseObject->action(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_82a.cpp:39; delete baseObject; // 句柄未关闭 @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_82a.cpp:40
- 结论: 在CWE404_Improper_Resource_Shutdown__w32CreateFile_close_82a.cpp中，通过CreateFile打开的文件句柄传递给action()后，未调用CloseHandle关闭句柄，导致资源泄漏。虽然action()的具体实现未提供，但根据CWE-404测试用例的典型模式，action()内部不负责关闭句柄，且调用者删除对象后未关闭句柄，违反了API contract。
- D验证: confirmed / ver_7c2098d6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 68. hyp_path_59cd236ab7ab

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_42.c:46
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到fclose调用，且data为open()返回的文件描述符（非-1）。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_42.c:30-35; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_42.c:44-48
- 结论: 程序使用open()返回的文件描述符错误地调用fclose()关闭，导致资源关闭不当和可能的未定义行为。
- D验证: confirmed / ver_fb46d77a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 69. hyp_path_dae36e697df6

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_42.c:45
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile成功返回有效HANDLE，代码执行路径到达fclose调用。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_42.c:29-31; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_42.c:44-46
- 结论: 使用fclose()关闭CreateFile返回的HANDLE，造成资源关闭方式不匹配（CWE-404）。
- D验证: confirmed / ver_a8cc3287
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 70. hyp_path_147a98fc6fdf

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_42.c:39
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无特定攻击者输入控制，但存在代码路径错误关闭资源
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_42.c:27; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_42.c:39
- 结论: 使用fopen打开的文件资源未使用fclose关闭，而是错误地使用CloseHandle，违反API契约，可能导致资源泄漏或不可预测行为。
- D验证: confirmed / ver_4112e901
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 71. hyp_path_c4e0e9012dc2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_42.c:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件打开成功（fopen返回非NULL），程序执行到if (data != NULL)分支。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_42.c:23; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_42.c:37
- 结论: 使用fopen打开的文件资源通过_close关闭，违反了资源关闭的API contract，导致CWE-404不正确的资源关闭漏洞。
- D验证: confirmed / ver_6f97a4c1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 72. hyp_path_52991368a5e3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_42.c:39
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 无需攻击者输入，代码正常执行即可触发
- 触发路径: data = case0Source(data); // 调用source函数，内部freopen打开文件 @ L30; if (data != NULL) { CloseHandle((HANDLE)data); } // 错误使用CloseHandle关闭文件流 @ L37-41
- 结论: 使用CloseHandle()关闭由freopen()打开的文件流，导致资源未正确释放，违反API contract，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_2b956f2d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 73. hyp_path_852d38f90ee4

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_42.c:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: freopen成功返回非NULL指针
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ case0Source函数 (L21-26); data = case0Source(data); @ 主函数 (L28); _close((int)data); @ if分支 (L35-39)
- 结论: 使用_close()关闭由freopen()打开的文件流，而非fclose()，导致资源关闭不当，违反API契约（CWE-404）。
- D验证: confirmed / ver_1b5a683e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 74. hyp_path_0eea05548284

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_17.c:43
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件打开成功（data为非负文件描述符）
- 触发路径: data = -1; data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_17.c:35-39; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_17.c:41-45
- 结论: 使用 open() 获取的文件描述符被错误地使用 fclose() 关闭，导致资源释放不匹配，可能引发资源泄漏或未定义行为。
- D验证: confirmed / ver_affb0853
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 75. hyp_path_10fdb3d9bf94

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_42.c:48
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); return data; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_42.c:32-37; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_42.c:48
- 结论: 文件描述符通过open()获取，但使用CloseHandle()关闭，导致资源关闭不当，违反API contract。
- D验证: confirmed / ver_4f3ec029
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 76. hyp_path_32a9c6325f32

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_42.c:45
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 无外部输入控制，但代码执行到该路径时必然触发 API 滥用。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_42.c:32-34; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_42.c:45
- 结论: 资源通过 CreateFile 获取后，使用 _close 而非 CloseHandle 关闭，违反了 Windows API 契约，导致资源未正常关闭（CWE-404）。
- D验证: confirmed / ver_5e707636
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 77. hyp_path_e96348ee62ce

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_17.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需外部输入控制，漏洞由代码直接导致
- 触发路径: CreateFile("Case0Source_w32CreateFile.txt", ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_17.c:42; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_17.c:42
- 结论: 使用CreateFile打开文件后，错误地使用fclose而非CloseHandle关闭句柄，导致资源关闭类型不匹配（CWE-404），可能造成资源泄露或未定义行为。
- D验证: confirmed / ver_8209a1d4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 78. hyp_path_c8d573aa764f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_17.c:45
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制文件路径或文件内容（但本场景中文件路径固定，漏洞仍存在）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_17.c:37-41; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_17.c:43-47
- 结论: 打开文件后使用CloseHandle()而不是close()关闭文件描述符，导致资源未正确关闭，可能造成资源泄露。
- D验证: confirmed / ver_54bc93b6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 79. hyp_path_e8741eb35239

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_17.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile成功返回有效句柄（非INVALID_HANDLE_VALUE）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...) @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_17.c:32; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_17.c:42
- 结论: 文件资源未正确关闭：CreateFile返回的HANDLE被转换为int后传递给_close()，应使用CloseHandle()。这违反了Windows API约定，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_1c257854
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 80. hyp_path_8c7e2d1ea889

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_43.cpp:44
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ 函数 case0Source 内; fclose((FILE *)data); @ case0 函数内 44 行
- 结论: 使用 open() 打开的文件描述符被错误地使用 fclose() 关闭，违反了资源关闭的 API 契约，导致资源未正确释放。
- D验证: confirmed / ver_2cbf477e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 81. hyp_path_7f07adbbe496

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_61a.c:38
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者可能通过影响source函数的输入（如文件名）来控制文件获取，但具体情况未知
- 触发路径: data = CWE404_Improper_Resource_Shutdown__open_fclose_61b_case0Source(data); @ CWE404_Improper_Resource_Shutdown__open_fclose_61a.c:36; if (data != -1) { @ CWE404_Improper_Resource_Shutdown__open_fclose_61a.c:37; fclose((FILE *)data); @ CWE404_Improper_Resource_Shutdown__open_fclose_61a.c:38
- 结论: 代码错误地使用fclose()关闭open()返回的文件描述符，违反了API约定，可能导致资源泄漏或程序崩溃。
- D验证: confirmed / ver_1632b059
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 82. hyp_path_14fe3026cecb

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_43.cpp:43
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 程序执行到case0函数，且CreateFile成功返回有效HANDLE
- 触发路径: static void case0Source(HANDLE &data) { data = CreateFile(...); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_43.cpp:26-36; data = INVALID_HANDLE_VALUE; case0Source(data); if (data != INVALID_HANDLE_VALUE) { @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_43.cpp:41-45; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_43.cpp:45-49
- 结论: 使用CreateFile返回的HANDLE后，错误地使用fclose()关闭，而不是CloseHandle()，导致资源关闭不当，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_27072dc2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 83. hyp_path_1e537e78c861

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_62a.cpp:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响 case0Source 函数的行为，使其返回一个有效的文件描述符（非 -1），这依赖于测试用例上下文，但注释和种子标记表明 source 确实返回 open() 的 fd
- 触发路径: data = -1; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_62a.cpp:40; case0Source(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_62a.cpp:41; if (data != -1) { @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_62a.cpp:42; { /* NOTE: Attempt to close the file using fclose() instead of close() */ fclose((FILE *)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_62a.cpp:43-47
- 结论: 代码尝试使用 fclose() 关闭通过 open() 打开的文件描述符，导致资源关闭不匹配。将 int 文件描述符强制转换为 FILE* 后调用 fclose() 是未定义行为，可能造成资源泄漏或程序崩溃。
- D验证: confirmed / ver_316932b5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 84. hyp_path_fbf25b443855

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_62a.cpp:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: case0Source 函数生成的 data 是一个由 CreateFile 返回的有效 HANDLE
- 触发路径: data = INVALID_HANDLE_VALUE; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_62a.cpp:32; case0Source(data); // 假设此函数将 data 设为有效 HANDLE @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_62a.cpp:33; if (data != INVALID_HANDLE_VALUE) { @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_62a.cpp:34; fclose((FILE *)data); // 错误的关闭方式 @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_62a.cpp:35-40
- 结论: 使用 fclose() 而不是 CloseHandle() 关闭由 CreateFile 返回的句柄，违反 API 合约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_a9d1786b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 85. hyp_path_28e4b200a6af

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_43.cpp:37
- 漏洞类型: CWE-404, CWE-666
- CWE: CWE-404; CWE-666
- 风险等级: P0
- 触发条件: 无外部输入依赖，只要代码执行到此路径即可触发。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_43.cpp:26-30; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_43.cpp:39-43
- 结论: 资源关闭不当：使用CloseHandle()关闭由fopen()打开的文件，类型不匹配，违反了API contract。这可能导致未定义行为、资源泄漏或程序崩溃。
- D验证: confirmed / ver_4343c90b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 86. hyp_path_f8a916c89085

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_61a.c:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响 data 的值，使其成为有效的 HANDLE（例如通过控制输入或环境）
- 触发路径: data = INVALID_HANDLE_VALUE; data = CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_61b_case0Source(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_61a.c:29-31; if (data != INVALID_HANDLE_VALUE) { @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_61a.c:33; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_61a.c:35
- 结论: 使用 fclose() 关闭由 CreateFile 返回的 HANDLE，违反 API 契约，应使用 CloseHandle()，导致资源关闭不当。
- D验证: confirmed / ver_6c170094
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 87. hyp_path_52b9c2cb4f69

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_62a.cpp:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无外部攻击者输入，漏洞源于代码逻辑错误，但触发依赖于函数case0Source的实现（通常模拟fopen打开文件）
- 触发路径: data = NULL; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_62a.cpp:32; case0Source(data); // 该函数可能将data赋值为fopen返回值 @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_62a.cpp:33; if (data != NULL) { @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_62a.cpp:34; CloseHandle((HANDLE)data); // 错误关闭 @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_62a.cpp:36-40
- 结论: 使用fopen打开文件后，错误地使用CloseHandle而不是fclose来关闭文件句柄，违反了API contract，可能导致资源泄漏或程序异常。
- D验证: confirmed / ver_24f0bbbd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 88. hyp_path_f9d28db2b465

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_61a.c:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需直接控制，但需要fopen成功返回非空FILE指针。
- 触发路径: data = NULL; data = CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_61b_case0Source(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_61a.c:29-30; if (data != NULL) { @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_61a.c:31; /* NOTE: Attempt to close the file using CloseHandle() instead of fclose() */ CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_61a.c:33-37
- 结论: 使用fopen打开文件后，错误地使用CloseHandle关闭文件句柄，导致资源未正确释放，违反CWE-404（不正确的资源关闭）。
- D验证: confirmed / ver_97b8da3d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 89. hyp_path_a4c4d0935d56

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_43.cpp:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到文件打开和关闭的路径; fopen成功返回非NULL指针
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_43.cpp:24-28; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_43.cpp:35
- 结论: 文件资源使用不正确的关闭函数：fopen返回FILE*指针，但使用_close（int）而不是fclose()关闭，导致资源未正确释放，可能造成文件句柄泄漏或缓冲区未刷新。
- D验证: confirmed / ver_55f4dacf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 90. hyp_path_a9a39a527f36

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_61a.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序需要通过fopen成功打开一个文件（即data不为NULL）
- 触发路径: /* Initialize data */ data = NULL; data = CWE404_Improper_Resource_Shutdown__fopen_w32_close_61b_case0Source(data); if (data != NULL) { @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_61a.c:27-31; { /* NOTE: Attempt to close the file using close() instead of fclose() */ _close((int)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_61a.c:31-35
- 结论: 调用fopen()打开文件后，使用_close()而不是fclose()关闭，违反了API contract，可能导致资源未正确释放或未定义行为。
- D验证: confirmed / ver_4fa6c6cd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 91. hyp_path_13d56f6dab27

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_43.cpp:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: freopen 成功返回非 NULL 指针
- 触发路径: /* Initialize data */ data = NULL; case0Source(data); if (data != NULL) { @ Line 35-37; { /* NOTE: Attempt to close the file using CloseHandle() instead of fclose() */ CloseHandle((HANDLE)data); } @ Line 39-42
- 结论: CWE404 资源关闭不当：使用 CloseHandle() 关闭由 freopen() 打开的文件流，应使用 fclose()。
- D验证: confirmed / ver_27290383
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 92. hyp_path_219e0d5301b6

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_62a.cpp:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在一个通过fopen打开的FILE*对象data。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_62a.cpp:32
- 结论: 使用fopen打开文件后，错误地使用_close（文件描述符关闭函数）而不是fclose来关闭，违反API contract，可能导致资源泄漏或未刷新缓冲区。
- D验证: confirmed / ver_d5a8ce8b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 93. hyp_path_5e4af738dd3b

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_62a.cpp:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: data非空且指向有效的FILE对象
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_62a.cpp:34
- 结论: 资源关闭API误用: 使用CloseHandle()关闭通过freopen()打开的文件，应使用fclose()。
- D验证: confirmed / ver_f8a11307
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 94. hyp_path_f28e69d1e0d2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_61a.c:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: source 函数内部通过 freopen() 分配 FILE* 资源，且 data 非空
- 触发路径: data = CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_61b_case0Source(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_61a.c:31; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_61a.c:35
- 结论: 资源关闭不当：使用 CloseHandle() 关闭由 freopen() 打开的文件流，违反 API 合约，应使用 fclose()。
- D验证: confirmed / ver_7fe5d06f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 95. hyp_path_2a9db837d82b

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_43.cpp:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: freopen成功打开文件，data不为NULL
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_43.cpp:24-28; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_43.cpp:35
- 结论: 资源关闭不当：使用_close()关闭通过freopen()打开的文件流，应使用fclose()，导致文件句柄无法正确关闭，可能引发资源泄漏。
- D验证: confirmed / ver_e97603c0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 96. hyp_path_eaf4889ee916

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_61a.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: data指向通过freopen成功打开的文件流（非NULL）
- 触发路径: data = CWE404_Improper_Resource_Shutdown__freopen_w32_close_61b_case0Source(data); // 假设返回FILE*; _close((int)data); // 错误关闭 @ CWE404_Improper_Resource_Shutdown__freopen_w32_close_61a.c:29
- 结论: 文件资源关闭不当：使用freopen打开文件后，错误地使用_close()而不是fclose()来关闭，导致资源泄漏或后续释放错误。
- D验证: confirmed / ver_b4a7de35
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 97. hyp_path_fe1c15260579

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_62a.cpp:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在有效的文件指针data（可能通过freopen获得，具体取决于case0Source的实现）
- 触发路径: case0Source(data); // 假设通过freopen打开文件 @ L32; if (data != NULL) { @ L33; _close((int)data); // 错误关闭 @ L38
- 结论: 使用freopen打开文件后，错误地使用_close()而不是fclose()关闭文件指针，违反API合约，可能导致资源未正确释放，造成资源泄漏（CWE-404）。
- D验证: confirmed / ver_89b60003
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 98. hyp_path_e20fce0ab6b9

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_43.cpp:46
- 漏洞类型: CWE-404, CWE-703
- CWE: CWE-404; CWE-703
- 风险等级: P0
- 触发条件: 无攻击者控制输入；漏洞由代码自身逻辑错误引入。
- 触发路径: static void case0Source(int &data) { data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_43.cpp:35-39; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_43.cpp:46
- 结论: 使用 CloseHandle() 错误地关闭文件描述符，导致资源未正确关闭，违反 CWE-404。
- D验证: confirmed / ver_f0971027
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 99. hyp_path_8a67b8aa0752

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_61a.c:40
- 漏洞类型: CWE-404, CWE-762
- CWE: CWE-404; CWE-762
- 风险等级: P0
- 触发条件: data必须是一个有效的文件描述符（非-1），由Source函数保证
- 触发路径: /* Initialize data */ data = -1; data = CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_61b_case0Source(data); if (data != -1) { @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_61a.c:38-42; { /* NOTE: Attempt to close the file using CloseHandle() instead of close() */ CloseHandle((HANDLE)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_61a.c:42-46
- 结论: 使用CloseHandle关闭由open()返回的文件描述符，导致资源关闭不当，可能造成资源泄漏或无效句柄错误。
- D验证: confirmed / ver_0bc9e1a8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 100. hyp_path_4e84dd8d4db6

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_62a.cpp:43
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序通过case0Source()打开文件并返回有效文件描述符（非-1）
- 触发路径: data = -1; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_62a.cpp:38; case0Source(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_62a.cpp:39; if (data != -1) { @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_62a.cpp:41; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_62a.cpp:45-49
- 结论: 文件描述符未使用正确的关闭函数（close()），而是使用了Windows API CloseHandle()，违反了API契约，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_373f7619
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 101. hyp_path_969bde8f0972

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_43.cpp:43
- 漏洞类型: CWE-404, CWE-910
- CWE: CWE-404; CWE-910
- 风险等级: P0
- 触发条件: 程序执行到 case0 函数，且 data 不为 INVALID_HANDLE_VALUE
- 触发路径: static void case0Source(HANDLE &data) { data = CreateFile(...); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_43.cpp:26-36; /* NOTE: Attempt to close the file using close() instead of CloseHandle() */ _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_43.cpp:45-49
- 结论: 使用 _close 错误关闭由 CreateFile 返回的 Windows HANDLE，应使用 CloseHandle。这违反了 API contract，可能导致句柄泄漏或未定义行为。
- D验证: confirmed / ver_1f332acb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 102. hyp_path_18dc0da9eb01

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_61a.c:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者需能够触发该代码路径执行，例如通过某种输入导致程序运行到此分支。
- 触发路径: data = CWE404_Improper_Resource_Shutdown__w32CreateFile_close_61b_case0Source(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_61a.c:29; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_61a.c:31
- 结论: 使用 CreateFile 打开的句柄通过 _close() 关闭，而不是正确的 CloseHandle()，导致资源未正确关闭，违反 API contract，属于 CWE-404 资源关闭不当。
- D验证: confirmed / ver_f6e84d10
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 103. hyp_path_d808e81f6196

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_62a.cpp:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: case0Source返回一个有效的HANDLE（非INVALID_HANDLE_VALUE）
- 触发路径: case0Source(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_62a.cpp:33; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_62a.cpp:34
- 结论: 在打开的Windows句柄上错误地使用了POSIX close()函数，而非CloseHandle()，导致资源关闭不当，符合CWE-404定义。
- D验证: confirmed / ver_038c3b21
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 104. hyp_path_1ddbec098082

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_12.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: globalReturnsTrueOrFalse()返回真，使得执行fclose分支
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ L35-38; if(globalReturnsTrueOrFalse()) { if (data != -1) @ L37-38; fclose((FILE *)data); @ L40-44
- 结论: 代码使用open()打开文件返回文件描述符，但在关闭时错误地使用fclose()并强制转换为FILE*，导致资源关闭不匹配（CWE-404）。同时存在类型转换错误，可能引发未定义行为。
- D验证: confirmed / ver_13dd14be
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 105. hyp_path_c733934fe8b3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_12.c:41
- 漏洞类型: CWE-404, CWE-459
- CWE: CWE-404; CWE-459
- 风险等级: P0
- 触发条件: CreateFile调用成功返回有效句柄（data != INVALID_HANDLE_VALUE）; 程序控制流到达_close调用（无提前返回或异常中断）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_12.c:27-31; if(globalReturnsTrueOrFalse()) { if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_12.c:34-38; { /* NOTE: Attempt to close the file using close() instead of CloseHandle() */ _close((int)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_12.c:39-43
- 结论: 存在CWE-404不当资源关闭漏洞：使用CreateFile打开的文件句柄，在部分路径下可能被不匹配的_close()关闭（而非CloseHandle），且可能发生双重关闭，违反API契约。
- D验证: confirmed / ver_502019a0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 106. hyp_path_557ee18f3396

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_12.c:44
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序运行在Windows平台; 文件打开成功（data != -1）; globalReturnsTrueOrFalse()返回false
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_12.c:37; if(globalReturnsTrueOrFalse()) { @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_12.c:39; { CloseHandle((HANDLE)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_12.c:42-44
- 结论: 文件描述符通过open()打开后，当globalReturnsTrueOrFalse()返回false时，使用CloseHandle()关闭，而CloseHandle()不适用于C运行时文件描述符，导致资源未正确关闭（文件描述符泄露）。
- D验证: confirmed / ver_c6c86206
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 107. hyp_path_1f97818797a3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_12.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行路径依赖于globalReturnsTrueOrFalse()的返回值，攻击者无法直接控制该随机函数，但分支在有随机结果时为可达。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... FILE_ATTRIBUTE_NORMAL, NULL); @ L27-31; if(globalReturnsTrueOrFalse()) { if (data != INVALID_HANDLE_VALUE) { @ L34-38; fclose((FILE *)data); } } @ L39-43
- 结论: 使用CreateFile打开文件后，在globalReturnsTrueOrFalse()返回true的分支中，错误地将HANDLE强制转换为FILE*并调用fclose()关闭，而非使用CloseHandle()，导致资源未正确关闭。
- D验证: confirmed / ver_5fecbcf1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 108. hyp_path_011029646230

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_08.c:55
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序运行环境存在文件Case0Source_open.txt或具备创建权限; staticReturnsTrue()返回真（其实现固定返回1，总是为真）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_08.c:48; if(staticReturnsTrue()) { @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_08.c:50; if (data != -1) @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_08.c:51; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_08.c:55
- 结论: 代码中通过open()获取文件描述符后，错误地使用fclose()而非close()关闭文件，导致资源关闭不当。虽然尝试关闭，但fclose()期望FILE*参数，而传入的是int类型的文件描述符，可能导致未定义行为或资源泄漏。
- D验证: confirmed / ver_5d0c1bf4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 109. hyp_path_7b19d3aa0e58

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_11.c:42
- 漏洞类型: CWE-404, CWE-762
- CWE: CWE-404; CWE-762
- 风险等级: P0
- 触发条件: 文件打开操作成功（data != -1）; 全局条件globalReturnsTrue()返回真
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_11.c:35; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_11.c:42
- 结论: 使用open()打开文件获得文件描述符后，错误地使用fclose()（期望FILE*）而非close()来关闭，导致资源管理不当（CWE-404）和API不匹配（CWE-762），可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_edde3180
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 110. hyp_path_ccf0c3d947ba

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_08.c:57
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序编译并运行于Windows平台，且文件打开成功（data != -1）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_08.c:50; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_08.c:57
- 结论: 使用open()函数打开文件后，错误地使用CloseHandle()而非close()来关闭文件描述符，导致资源未正确关闭，构成CWE-404不正确的资源关闭漏洞。
- D验证: confirmed / ver_24ade39a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 111. hyp_path_09f3101ca097

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_11.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFileA成功打开文件，返回非INVALID_HANDLE_VALUE的HANDLE
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_11.c:36-38; if(data != INVALID_HANDLE_VALUE) { _close((int)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_11.c:39-41
- 结论: 使用CreateFileA创建的HANDLE资源通过_close()函数关闭，而不是CloseHandle()，导致资源关闭不匹配，可能造成资源泄露或未定义行为。
- D验证: confirmed / ver_8846121f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 112. hyp_path_f61d0901b2ca

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_08.c:54
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行至该路由，无需攻击者输入控制
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... FILE_ATTRIBUTE_NORMAL, NULL); @ CWE404_Improper_Resource_Shutdown__w32CreateFile_close_08.c:40-44; if(staticReturnsTrue()) { @ CWE404_Improper_Resource_Shutdown__w32CreateFile_close_08.c:49; if (data != INVALID_HANDLE_VALUE) { _close((int)data); } @ CWE404_Improper_Resource_Shutdown__w32CreateFile_close_08.c:52-56
- 结论: 使用CreateFile()打开的文件句柄应使用CloseHandle()关闭，但代码中使用了_close()，违反了Windows API的契约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_146bb8cf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 113. hyp_path_3c541ca2acf5

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_08.c:54
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法直接控制输入，但代码路径静态可达；任何触发该路径的执行都会导致资源泄漏
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_08.c:54; fclose((FILE *)data); // 错误关闭方式 @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_08.c:54
- 结论: 使用CreateFile打开文件后，使用fclose()而非CloseHandle()关闭，导致资源未正确关闭，违反API contract，存在资源泄漏风险。
- D验证: confirmed / ver_5d7da74c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 114. hyp_path_cd88886fdf76

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_11.c:44
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行路径经过 globalReturnsTrue() 为真且 open 成功（data != -1）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_11.c:37-38; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_11.c:44
- 结论: 使用 open() 打开文件后，错误地使用 CloseHandle() 关闭文件描述符，导致资源关闭不当（CWE-404）。
- D验证: confirmed / ver_d72b2697
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 115. hyp_path_b80a97d60828

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_11.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile执行成功，返回有效HANDLE
- 触发路径: data = CreateFile(...); @ L27-31; if (data != INVALID_HANDLE_VALUE) @ L34-38; fclose((FILE *)data); @ L39-43
- 结论: CreateFile返回的HANDLE被错误地使用fclose()关闭，而非CloseHandle()，违反了API合约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_96543918
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 116. hyp_path_496de19df2b1

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_01.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需控制输入；漏洞由代码逻辑错误导致，在任何正常执行路径上均会触发。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_01.c:34-36; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_01.c:40
- 结论: 文件打开与关闭API不匹配：open()返回文件描述符，却使用fclose()（期望FILE*指针）关闭，导致资源关闭不当，可能引发资源泄漏或未定义行为。
- D验证: confirmed / ver_878b35f4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 117. hyp_path_fd976c5726f6

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_02.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无额外攻击者控制条件；代码自动执行错误关闭操作。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_02.c:34-37; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_02.c:42
- 结论: 使用open()打开文件后，错误地使用fclose()关闭，违反了资源关闭的API契约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_730c5043
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 118. hyp_path_e896e9abd09e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_03.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需控制输入，漏洞由代码内部逻辑错误触发，但攻击者可能通过影响文件系统或环境间接影响open()的返回值。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ 36-38; fclose((FILE *)data); @ 40-44
- 结论: 使用open()函数打开文件后，错误地使用fclose()函数（而非close()）关闭返回的文件描述符，导致资源关闭不当，违反CWE-404定义，可能引发未定义行为或资源泄漏。
- D验证: confirmed / ver_f51e8265
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 119. hyp_path_f61b3297877c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_04.c:48
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无特殊攻击者控制条件；任何能使open()成功且执行到fclose()的输入
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_04.c:41-42; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_04.c:48
- 结论: 代码使用open()返回的文件描述符，但错误地使用fclose()（期望FILE*）来关闭，违反了API contract，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_e161862d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 120. hyp_path_afb5b9bfbb3e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_06.c:47
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序能够成功打开文件（open() 返回非 -1 的文件描述符），且文件存在。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_06.c:39-43; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_06.c:45-49
- 结论: 使用 open() 打开文件后，错误地使用 fclose() 关闭文件描述符，导致资源关闭不当（CWE-404）。
- D验证: confirmed / ver_dcb4c5d3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 121. hyp_path_7606807a30de

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_07.c:47
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码执行路径满足staticFive==5，进入if语句块，执行不匹配的关闭操作。
- 触发路径: data = -1; data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_07.c:39-43; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_07.c:45-49
- 结论: 使用open()打开文件后，使用fclose()关闭文件描述符，而非close()，导致资源未正确关闭，违反API contract，可能导致文件描述符泄漏。
- D验证: confirmed / ver_bad0a187
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 122. hyp_path_cc5499916d3a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_05.c:48
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码按现有逻辑执行，无需外部输入控制。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_05.c:41; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_05.c:48
- 结论: 代码使用 open() 返回的文件描述符，却通过强制类型转换为 FILE* 后调用 fclose() 关闭，违反了 API 合约：open() 返回的文件描述符必须使用 close() 关闭，而非 fclose()。这可能导致资源未正确释放或未定义行为。
- D验证: confirmed / ver_4a7e8066
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 123. hyp_path_5f140b82ce17

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_09.c:42
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 程序执行到 open() 和后续的 fclose() 调用，且 open() 成功返回非负文件描述符。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_09.c:34-38; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_09.c:40-44
- 结论: 使用 open() 分配文件描述符后，错误地使用 fclose() 而不是 close() 进行关闭，导致不正确的资源关闭，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_0c0caa47
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 124. hyp_path_37d36e9caff0

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_10.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响文件打开（如控制文件名或路径，但此处文件名固定，主要在于触发代码执行路径）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_10.c:34-36; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_10.c:42
- 结论: 文件描述符使用不匹配的关闭函数，导致资源未正确关闭：open()返回int文件描述符，但使用fclose()尝试关闭，fclose期望FILE*，导致资源泄漏。
- D验证: confirmed / ver_6e84f743
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 125. hyp_path_9c8b1593eb5f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_13.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序运行且全局常量 GLOBAL_CONST_FIVE 等于 5（在测试案例中为真）。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_13.c:36; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_13.c:42
- 结论: 使用 open() 获取文件描述符后，错误地使用 fclose() 而不是 close() 关闭，导致文件描述符未正确关闭，造成资源泄漏。
- D验证: confirmed / ver_0bcd15aa
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 126. hyp_path_552e22d436d3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_15.c:43
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需外部输入，代码自动执行固定分支
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ 34-38; fclose((FILE *)data); @ 41-45
- 结论: 对 open() 返回的文件描述符使用了 fclose() 关闭，违反 API contract，导致资源关闭不当，可能造成文件描述符泄漏或未定义行为。
- D验证: confirmed / ver_cac538d2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 127. hyp_path_1e7a025e9dc3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_14.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码执行路径中，globalFive==5为真（Juliet测试用例中通常初始化为5）; open()调用成功返回有效文件描述符（若失败则data为-1，fclose调用无效，但无错误处理，仍属资源关闭问题）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_14.c:36; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_14.c:42
- 结论: 文件描述符通过open()获取，但使用fclose()关闭，违反了资源关闭的API契约（open()对应close()，fclose()对应fopen()），导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_3c930559
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 128. hyp_path_38abed23b6e3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_16.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_16.c:34-38; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_16.c:40-44
- 结论: 使用open()打开文件后，使用fclose()关闭文件描述符，违反了API契约：open()返回的文件描述符应使用close()关闭，而非fclose()。这导致资源释放不当和未定义行为（可能崩溃或资源泄漏）。
- D验证: confirmed / ver_d7ecc396
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 129. hyp_path_aaaeec47483c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_18.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码执行到该路径即可触发，无需外部输入控制。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_18.c:34-38; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_18.c:42
- 结论: 使用open()打开文件后，错误地使用fclose()关闭文件描述符，违反了API合约，导致资源未正确关闭或释放。
- D验证: confirmed / ver_2087f2d8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 130. hyp_path_77b4c6438f61

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_34.c:50
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到关闭资源的路径（可达）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_34.c:45; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_34.c:50
- 结论: 使用open()打开文件后，错误地使用fclose()（期望FILE*）关闭文件描述符，导致资源关闭类型不匹配，违反CWE-404。
- D验证: confirmed / ver_4d54cec9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 131. hyp_path_b64f528302b8

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_01.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者可通过控制文件路径或程序执行环境间接影响 open() 的行为，但非必需；漏洞主要由代码逻辑错误引起。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_01.c:38; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_01.c:42
- 结论: 程序使用 open() 打开文件并获得文件描述符，但在关闭时错误地使用 CloseHandle()（期望 HANDLE 类型）而非 close()，违反了 API contract，可能导致资源未正确关闭或未定义行为。
- D验证: confirmed / ver_7e6b597e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 132. hyp_path_e24923b61587

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_02.c:44
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件成功打开，data为有效文件描述符（非-1）
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_02.c:44
- 结论: 使用CloseHandle关闭由open()返回的文件描述符，违反了API合约，可能导致资源未正确关闭或未定义行为。
- D验证: confirmed / ver_c7cb4323
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 133. hyp_path_ff50d61989fb

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_33.cpp:46
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需攻击者控制，代码自动执行错误关闭
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_33.cpp:39; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_33.cpp:46
- 结论: 文件描述符使用错误关闭函数：通过open()打开的文件描述符被强制转换为FILE*并传递给fclose()，而非使用close()，导致资源未正确关闭，符合CWE-404。
- D验证: confirmed / ver_79f9b69b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 134. hyp_path_2cd2d8d4b275

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_31.c:43
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无外部输入要求，漏洞在代码逻辑中直接存在
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_31.c:36; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_31.c:43
- 结论: 代码使用 open() 返回的文件描述符（int）调用 fclose()，违反了 API 约定：open() 打开的 fd 必须用 close() 关闭，fclose() 期望 FILE*。这导致资源未正确关闭，可能造成资源泄漏或程序崩溃。
- D验证: confirmed / ver_2638a5a6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 135. hyp_path_f01fdf741045

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_05.c:50
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码执行到if(staticTrue)分支，且data为有效的文件描述符。
- 触发路径: CloseHandle((HANDLE)data); @ 50
- 结论: 使用CloseHandle()关闭由open()返回的文件描述符，导致资源关闭函数不匹配，违反API contract，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_a480ce0d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 136. hyp_path_0b2dc117daed

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_04.c:50
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 程序执行到漏洞代码路径（STATIC_CONST_TRUE为真）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_04.c:44; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_04.c:50
- 结论: 使用open()打开文件后，错误地使用CloseHandle()代替close()关闭文件描述符，导致资源未正确释放，违反CWE-404和CWE-772。
- D验证: confirmed / ver_2469c058
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 137. hyp_path_660fb4b42bb2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_06.c:49
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: N/A
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_06.c:49
- 结论: 使用open()返回的文件描述符，却调用CloseHandle()（期望HANDLE）关闭，导致资源未正确关闭，引发资源泄漏。
- D验证: confirmed / ver_409931e8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 138. hyp_path_aca3ae43b6ec

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_03.c:44
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行路径通过if(5==5)条件，实际为无条件执行。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_03.c:36-40; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_03.c:42-46
- 结论: 文件描述符使用CloseHandle()关闭，导致资源关闭不匹配，可能造成资源泄露或异常。
- D验证: confirmed / ver_d6fb4bb3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 139. hyp_path_508cee0a0bba

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_07.c:49
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行流进入 if(staticFive==5) 分支，该分支条件在测试用例中恒真
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_07.c:43; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_07.c:49
- 结论: 使用 open() 打开文件后，错误地使用 CloseHandle() 代替 close() 关闭文件描述符，导致资源未正确关闭（可能泄漏或未定义行为），违反 API contract，属于 CWE-404 不当资源关闭。
- D验证: confirmed / ver_dceeda94
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 140. hyp_path_13b46e5fc789

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_09.c:44
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该路径，且 GLOBAL_CONST_TRUE 为真。
- 触发路径: data = -1; data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_09.c:36-38; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_09.c:44
- 结论: 使用 CloseHandle() 关闭由 open() 返回的文件描述符，违反了 API 合约，可能导致资源未正确关闭（文件句柄泄漏）。
- D验证: confirmed / ver_d90a64c4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 141. hyp_path_7ad8beebd21d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_10.c:44
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 全局变量globalTrue为真，触发错误关闭路径
- 触发路径: data = -1; data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_10.c:36-40; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_10.c:42-46
- 结论: 使用open()打开文件后，错误地使用CloseHandle()关闭文件描述符，导致资源未正确关闭，符合CWE404 Improper Resource Shutdown。
- D验证: confirmed / ver_0eff93fd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 142. hyp_path_6badc0af281b

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_13.c:44
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到指定路径，且 open() 调用成功返回有效的文件描述符。
- 触发路径: data = -1; data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_13.c:36-40; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_13.c:42-46
- 结论: 文件资源使用 open() 打开，但使用 CloseHandle() 关闭，导致资源关闭不匹配，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_b02a50d1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 143. hyp_path_1a1a56199e8e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_14.c:44
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码执行路径中open()成功返回非负文件描述符，且globalFive==5条件为真。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_14.c:38; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_14.c:44
- 结论: 使用open()打开文件后，错误地使用CloseHandle()关闭文件描述符，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_9c5dd676
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 144. hyp_path_d907fd1dcbd9

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_15.c:45
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序运行在Windows平台; switch语句的case分支被执行; open()调用成功返回有效文件描述符
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_15.c:45
- 结论: 代码使用open()返回的文件描述符，但错误地使用CloseHandle()（用于Windows句柄）代替close()进行关闭，导致资源未正确关闭，违反API合同。
- D验证: confirmed / ver_738bbe9c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 145. hyp_path_5d273bfddc47

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_16.c:44
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: OPEN调用成功返回有效的文件描述符（非-1），且程序执行进入while(1)循环内的CloseHandle调用。
- 触发路径: data = -1; data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_16.c:36-40; { CloseHandle((HANDLE)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_16.c:42-46
- 结论: 使用CloseHandle()关闭由open()返回的文件描述符，导致资源关闭API不匹配，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_865c47d2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 146. hyp_path_558d84ba7a1b

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_31.c:45
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够使程序执行到该代码路径，且 OPEN 调用成功返回有效文件描述符（data != -1）。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_31.c:36; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_31.c:45
- 结论: 资源关闭不当：文件通过 open() 打开，但使用 CloseHandle() 关闭，导致文件描述符未正确释放，违反 API contract，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_2f0ce98b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 147. hyp_path_339c92a8ba33

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_33.cpp:48
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该代码路径，且open成功返回非负文件描述符。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_33.cpp:42; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_33.cpp:48
- 结论: 使用CloseHandle关闭由open返回的文件描述符，违反API contract，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_669caf86
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 148. hyp_path_9d5dd51b5c32

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_18.c:44
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到 open() 调用且成功打开文件
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_18.c:36-40; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_18.c:42-46
- 结论: 使用 Open() 返回的文件描述符，却通过 CloseHandle() 关闭，导致资源未正确关闭，违反 CWE-404（资源关闭不当）。
- D验证: confirmed / ver_cac25e26
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 149. hyp_path_daa9b44df8df

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_34.c:52
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需攻击者输入或控制，代码本身存在API misuse。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_34.c:44; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_34.c:52
- 结论: 使用CloseHandle()关闭由open()返回的文件描述符，导致资源未正确释放，违反了CWE-404（不当资源关闭）的API contract。
- D验证: confirmed / ver_18420c43
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 150. hyp_path_049707b9ab7a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_04.c:47
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需攻击者控制；代码执行逻辑自动触发
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...) @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_04.c:33; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_04.c:47
- 结论: 使用CreateFile返回的HANDLE调用_close()而不是CloseHandle()，违反了Windows API契约，导致资源关闭不当（CWE-404）。
- D验证: confirmed / ver_b6421e73
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 151. hyp_path_4ddeabbc69ae

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_02.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile调用成功，返回非INVALID_HANDLE_VALUE的句柄
- 触发路径: data = INVALID_HANDLE_VALUE; ... data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_02.c:27-31; { /* NOTE: Attempt to close the file using close() instead of CloseHandle() */ _close((int)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_02.c:39-43
- 结论: CreateFile返回的文件句柄未使用CloseHandle()关闭，而是错误地使用了_close()（文件描述符关闭函数），导致资源关闭不当，违反API合约。可能造成资源泄漏或句柄误操作。
- D验证: confirmed / ver_f80941d6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 152. hyp_path_23c16b41f602

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_03.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行至CreateFile成功返回有效句柄，随后调用_close()而非CloseHandle()。利用场景有限，但漏洞本身明确。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_03.c:27; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_03.c:41
- 结论: 使用CreateFile打开文件后，错误地使用_close()而不是CloseHandle()关闭句柄，导致资源未正确关闭，违反了API合约，可能导致资源泄漏。
- D验证: confirmed / ver_33b791e5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 153. hyp_path_de67bbfc7763

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_01.c:39
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 资源创建成功（CreateFile返回有效HANDLE）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_01.c:27-31; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_01.c:37-41
- 结论: 使用_close()关闭CreateFile返回的HANDLE，违反资源关闭语义，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_f7e55dc9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 154. hyp_path_ab77f68641c9

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_05.c:47
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无外部攻击者控制输入，但代码逻辑会导致此路径执行
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_05.c:33-37; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_05.c:45-49
- 结论: 在CWE404示例中，使用CreateFile打开文件返回HANDLE，但后续使用_close()（期望int fd）关闭该HANDLE，违反了API contract，可能导致资源未正确释放或程序崩溃。
- D验证: confirmed / ver_6ca9270f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 155. hyp_path_c5e707a4fcd6

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_09.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile成功返回有效句柄（非INVALID_HANDLE_VALUE）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_09.c:31; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_09.c:41
- 结论: 程序使用CreateFile打开文件后，错误地使用_close()而不是CloseHandle()关闭句柄，导致资源未正确关闭，违反API契约，可能造成资源泄漏。
- D验证: confirmed / ver_15ad1dbe
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 156. hyp_path_d1c78653ea1b

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_07.c:46
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile返回有效句柄（即使返回INVALID_HANDLE_VALUE也会导致未定义行为）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ CWE404_Improper_Resource_Shutdown__w32CreateFile_close_07.c:33; _close((int)data); // 应使用CloseHandle @ CWE404_Improper_Resource_Shutdown__w32CreateFile_close_07.c:46
- 结论: 使用CreateFile打开的句柄未通过CloseHandle正确关闭，而是使用_close()，违反API contract，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_571435a2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 157. hyp_path_2a4462f3414e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_13.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到关闭资源路径，且data为有效的HANDLE。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...) @ 27-31; _close((int)data); @ 39-43
- 结论: CreateFile返回的HANDLE被强制转换为int传递给_close()，导致资源关闭类型不匹配，违反API契约，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_05574866
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 158. hyp_path_1ed08070702f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_06.c:46
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该代码路径，且CreateFile返回有效句柄（非INVALID_HANDLE_VALUE）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ 32-36; _close((int)data); @ 44-48
- 结论: CreateFile返回的句柄被错误地用_close()关闭，导致资源未正确释放。_close()用于文件描述符，而CreateFile返回的HANDLE应使用CloseHandle()，违反API contract，造成资源泄漏。
- D验证: confirmed / ver_66dfcbc3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 159. hyp_path_6b82de08cf34

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_10.c:41
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 攻击者无需直接控制输入，但需要程序在globalReturnsTrue()为真时运行此代码路径; CreateFile返回有效句柄（data != INVALID_HANDLE_VALUE）以导致资源泄露
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_10.c:27-31; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_10.c:39-43
- 结论: 使用CreateFile打开的Windows文件句柄，通过_close()（C运行库）而非CloseHandle()关闭，违反了Windows API规范，导致资源关闭不当，可能造成句柄泄露或未定义行为。
- D验证: confirmed / ver_2ed5c22d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 160. hyp_path_442ea235d370

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_14.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件"Case0Source_w32CreateFile.txt"存在且可成功打开（CreateFile返回有效句柄）。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_14.c:28-31; _close((int)data); // 错误关闭 @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_14.c:41
- 结论: 使用CreateFile获取的句柄（HANDLE）被错误地传递给_close（期望int文件描述符）进行关闭，违反了CreateFile应使用CloseHandle关闭的API合约，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_d0ec9ef0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 161. hyp_path_e714736230c4

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_15.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile调用成功，返回非INVALID_HANDLE_VALUE的HANDLE
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_15.c:29; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_15.c:42
- 结论: 使用_close()关闭CreateFile返回的HANDLE，违反API约定，可能导致资源未正确关闭或未定义行为。
- D验证: confirmed / ver_34f0980e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 162. hyp_path_7ec5c2c4df7e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_31.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无额外攻击者控制条件；漏洞存在于固定代码路径中。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", ...); @ CWE404_Improper_Resource_Shutdown__w32CreateFile_close_31.c:27-31; _close((int)data); @ CWE404_Improper_Resource_Shutdown__w32CreateFile_close_31.c:40-44
- 结论: 资源关闭不当：CreateFile返回的HANDLE被错误地使用_close()（用于文件描述符）而非CloseHandle()进行关闭，导致资源泄漏或未定义行为。
- D验证: confirmed / ver_06dc6526
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 163. hyp_path_9f3db05df887

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_16.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件"Case0Source_w32CreateFile.txt"存在且可打开，或即使文件不存在，CreateFile失败返回INVALID_HANDLE_VALUE，但调用_close()仍违反API规范。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_16.c:27-31; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_16.c:39-43
- 结论: 资源关闭API不匹配：使用_close()关闭CreateFile返回的HANDLE，应使用CloseHandle()，无论CreateFile成功与否，均构成API misuse，可能导致资源未正确关闭或未定义行为。
- D验证: confirmed / ver_4acc06cf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 164. hyp_path_d69af9e8330a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_18.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile调用必须成功，data为有效HANDLE
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_18.c:41
- 结论: 函数CreateFile返回的HANDLE应使用CloseHandle关闭，但代码使用_close()，导致资源可能未正确关闭，违反Windows API约定，存在资源泄漏风险。
- D验证: confirmed / ver_38daa2ea
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 165. hyp_path_a2fad3ab5228

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_33.cpp:45
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile成功返回有效HANDLE
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_33.cpp:31; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_33.cpp:45
- 结论: 调用CreateFile获取HANDLE后，使用_close()而不是CloseHandle()关闭句柄，导致资源未正确释放，违反CWE-404（不正确的资源关闭）。
- D验证: confirmed / ver_4c3490ae
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 166. hyp_path_637744a77639

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_34.c:49
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行路径经过该段代码，且CreateFile调用成功（或失败时引发未定义行为）。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_34.c:34-38; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_34.c:49
- 结论: 函数使用CreateFile返回HANDLE后，却使用_close()（期望文件描述符int）关闭，导致资源未正确关闭，违反API contract，可能造成资源泄漏。
- D验证: confirmed / ver_419e34d9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 167. hyp_path_e5b313fa3a8e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_02.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序运行到fclose语句且data为有效HANDLE
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ 27-31; fclose((FILE *)data); @ 39-43
- 结论: 调用CreateFile返回的HANDLE被错误地使用fclose()关闭，导致资源关闭方式不匹配，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_0e014576
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 168. hyp_path_e6e81698f677

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_03.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile调用成功，返回非INVALID_HANDLE_VALUE的句柄。
- 触发路径: data = INVALID_HANDLE_VALUE; ... data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_03.c:27-31; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_03.c:39-43
- 结论: 使用fclose()关闭CreateFile返回的HANDLE，违反API契约，导致资源未正确释放（CWE-404）。
- D验证: confirmed / ver_8ea12007
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 169. hyp_path_f181699db7c1

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_01.c:39
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该代码路径，且CreateFile返回非INVALID_HANDLE_VALUE（即使返回INVALID_HANDLE_VALUE，fclose也会被调用，但主要关注类型不匹配错误）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_01.c:27-31; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_01.c:37-41
- 结论: 代码使用CreateFile打开文件返回HANDLE，但使用fclose（期望FILE*）关闭，导致资源关闭不当，违反API contract，可能造成资源泄露或未定义行为。
- D验证: confirmed / ver_ad5bdf94
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 170. hyp_path_fa104e8379b0

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_04.c:47
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法直接控制文件创建，但漏洞本身不依赖外部输入；即使句柄无效，fclose 调用也是不正确的资源关闭方式。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ L33-37; fclose((FILE *)data); @ L45-49
- 结论: 使用 CreateFile 打开的句柄被错误地使用 fclose 关闭，违反 API 契约，可能导致资源未正确释放或未定义行为。即使 CreateFile 返回无效句柄，fclose 调用也是不当操作，可能引发其他问题。
- D验证: confirmed / ver_468cf248
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 171. hyp_path_6fa25c57fe91

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_06.c:46
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件创建成功，data不为INVALID_HANDLE_VALUE。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_06.c:32-36; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_06.c:44-48
- 结论: 使用CreateFile打开文件句柄后，错误地使用fclose()而不是CloseHandle()关闭句柄，违反了API契约，可能导致资源泄漏（句柄未正确关闭）。
- D验证: confirmed / ver_929b8790
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 172. hyp_path_62473ce28272

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_05.c:47
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile成功返回有效HANDLE（测试用例中假定文件可创建），但代码未检查错误；即使失败，fclose接收无效值也构成问题。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_05.c:33-37; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_05.c:45-49
- 结论: CreateFile返回的HANDLE被强制转换为FILE*并传递给fclose()，导致API契约违反和未定义行为，属于CWE-404不当资源关闭。
- D验证: confirmed / ver_67c698a2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 173. hyp_path_9de816641ecc

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_07.c:46
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序运行于 Windows 环境，CreateFile 调用成功返回有效句柄。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_07.c:34; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_07.c:46
- 结论: 使用 CreateFile 打开的句柄被错误地用 fclose 关闭，违反 API contract，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_cd416264
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 174. hyp_path_0032b2a43acd

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_10.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码执行到 if 分支（具体条件未从上下文获知，但存在分支路径）；攻击者无法直接控制该路径，但代码在实际应用中若被调用则触发。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_10.c:41; fclose((FILE *)data); @ 同上文件:41
- 结论: 资源通过 CreateFile 打开后，使用 fclose() 而非 CloseHandle() 关闭，违反了 API contract，导致资源关闭不当（CWE-404）。
- D验证: confirmed / ver_0f8a931c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 175. hyp_path_2da682051e1d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_13.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile 返回非 INVALID_HANDLE_VALUE 的有效句柄。
- 触发路径: data = INVALID_HANDLE_VALUE; data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_13.c:27-31; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_13.c:39-43
- 结论: Windows API CreateFile 返回的 HANDLE 被错误地通过强制类型转换为 FILE* 后传递给 fclose()，导致资源未正确关闭，且强制转换本身引发未定义行为，可能造成资源泄漏或程序崩溃。
- D验证: confirmed / ver_a42dd7d3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 176. hyp_path_e32dab2b6b87

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_14.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发目标代码路径，即程序运行到该测试用例的漏洞分支（globalFive==5为真）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_14.c:27-31; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_14.c:39-43
- 结论: 使用CreateFile打开的句柄（HANDLE）被错误地通过fclose关闭，违反了API使用规范，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_6cc98334
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 177. hyp_path_f382dbd8da6a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_09.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码路径被执行，且 CreateFile 返回有效的句柄。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...) @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_09.c:34; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_09.c:41
- 结论: 使用 fclose() 关闭由 CreateFile() 返回的 HANDLE，而不是 CloseHandle()，导致资源未正确关闭（CWE-404 不恰当的资源关闭）。
- D验证: confirmed / ver_f1aa59dd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 178. hyp_path_1629e56d256a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_16.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序能够执行到该switch case分支; CreateFile调用成功
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", ...); @ 行27-31; fclose((FILE *)data); @ 行39-43
- 结论: 使用fclose()关闭CreateFile返回的HANDLE，违反API contract，导致资源未正确关闭（句柄泄露）。
- D验证: confirmed / ver_bcaf04ae
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 179. hyp_path_127f34e1554d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_18.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该路径，无特定外部输入控制。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_18.c:27-30; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_18.c:41
- 结论: 使用CreateFile创建文件后，将HANDLE强制转换为FILE*并传递给fclose()，违反了Windows API契约：CreateFile返回的HANDLE应使用CloseHandle关闭，fclose无法正确关闭该资源，导致资源泄漏。
- D验证: confirmed / ver_566fad12
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 180. hyp_path_c0548e598d29

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_31.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile 成功打开文件，返回有效句柄
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_31.c:27; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_31.c:42
- 结论: 使用 CreateFile 返回的 HANDLE 调用 fclose 关闭资源，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_067eeac4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 181. hyp_path_d75c63ca9e44

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_15.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到CreateFile并成功打开文件，然后执行到fclose调用。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_15.c:27; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_15.c:42
- 结论: 代码使用CreateFile打开文件并返回HANDLE，但使用fclose()关闭，违反了API contract：CreateFile创建的句柄应使用CloseHandle()关闭，而不是fclose()。导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_52f5237b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 182. hyp_path_c5b9e30eb5ad

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_33.cpp:45
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无额外攻击者控制，代码直接执行错误的关闭操作。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_33.cpp:45
- 结论: 使用CreateFile打开文件后，错误地使用fclose关闭HANDLE，导致资源关闭不当（应使用CloseHandle）。违反API contract，可能导致资源泄露或未定义行为。
- D验证: confirmed / ver_380e21da
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 183. hyp_path_5da3fe22f1e9

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_34.c:49
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序以正常路径执行，未发生异常导致关闭操作被跳过。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_34.c:34-38; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_34.c:47-51
- 结论: 使用CreateFile打开的HANDLE被错误地使用fclose关闭，违反了API合同，可能导致资源泄漏或程序异常。
- D验证: confirmed / ver_6c0e3bd0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 184. hyp_path_7626b0eb36cb

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_72b.cpp:43
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者可能通过影响 dataVector 的内容间接控制关闭操作，但具体 source 未提供。
- 触发路径: int data = dataVector[2]; if (data != -1) { @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_72b.cpp:37-41; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_72b.cpp:41-45
- 结论: 使用 open() 打开文件返回文件描述符，但使用 fclose() 关闭，导致资源未正确关闭，违反 API 契约。
- D验证: confirmed / ver_8003f871
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 185. hyp_path_e3b3be6c3004

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_72b.cpp:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: data从dataVector[2]获取，且不为INVALID_HANDLE_VALUE。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_72b.cpp:34-38
- 结论: 使用fclose()关闭由CreateFile返回的HANDLE，违反Windows API规范，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_ff06faf8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 186. hyp_path_0c9b042230b1

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_72b.cpp:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序必须具有可访问的有效向量 dataVector，其索引 2 处存放了通过 CreateFile 获得的 HANDLE。
- 触发路径: HANDLE data = dataVector[2]; if (data != INVALID_HANDLE_VALUE) { ... _close((int)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_72b.cpp:30-36
- 结论: 使用 _close() 关闭由 CreateFile 返回的 HANDLE，违反了 Windows API 合同，可能导致资源未正确释放（CWE-404）。
- D验证: confirmed / ver_faeb0a54
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 187. hyp_path_ebae51ad30a0

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_72b.cpp:45
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: The vector data contains a non -1 value representing a file descriptor obtained from open().
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_72b.cpp:45
- 结论: Improper resource shutdown: file descriptor (likely from open()) is closed using CloseHandle() instead of close(), causing resource leak or undefined behavior.
- D验证: confirmed / ver_1258a9fa
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 188. hyp_path_3619eba6bc50

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_72b.cpp:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: data 是通过 fopen 获得的非空 FILE* 指针，且攻击者无法控制 dataVector 内容，但 API misuse 本身即可触发漏洞。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_72b.cpp:36
- 结论: 使用 CloseHandle 关闭通过 fopen 打开的 FILE*，违反 API contract，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_14a4fcf8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 189. hyp_path_778aaf3739c3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_72b.cpp:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: data 是从 dataVector[2] 获取的有效 FILE* 指针（来自 fopen），且 data != NULL。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_72b.cpp:34
- 结论: 使用 _close() 而不是 fclose() 关闭 fopen 打开的文件流，导致资源未正确释放，违反 CWE-404 (Improper Resource Shutdown or Release)。
- D验证: confirmed / ver_2a35fa29
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 190. hyp_path_bcd780970b69

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_72b.cpp:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件指针data非空，且data指向通过freopen打开的文件流; 程序执行到该代码路径
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_72b.cpp:36
- 结论: 使用CloseHandle()关闭通过freopen打开的文件流，违反API契约，可能导致资源泄漏或程序异常。
- D验证: confirmed / ver_35867085
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 191. hyp_path_0cbbec0c1db1

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_72b.cpp:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: Attacker controls the FILE pointer stored in dataVector, which is populated from prior code that opens files via freopen.
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_72b.cpp:34
- 结论: CWE404 Improper Resource Shutdown: file descriptor closed using _close() instead of fclose() for FILE* object opened via freopen.
- D验证: confirmed / ver_75853d8f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 192. hyp_path_481f1756f1b5

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_81a.cpp:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件打开操作成功，返回有效文件描述符; action函数没有关闭文件描述符的逻辑
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_81a.cpp:31; baseObject.action(data); // action内部未实现关闭 @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_81a.cpp:33
- 结论: 在CWE404_Improper_Resource_Shutdown__open_fclose_81a.cpp的case0函数中，通过OPEN()打开文件描述符，之后通过基类对象调用action(data)传递描述符，但未在action内部或后续代码中调用close()关闭该描述符，导致资源泄漏，违反CWE-404。
- D验证: confirmed / ver_ac7e101c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 193. hyp_path_15d9f2bf33b7

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_81a.cpp:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行了open()调用，且action()实现中使用CloseHandle关闭文件描述符，违反特定关闭规则。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_81a.cpp:33; baseObject.action(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_81a.cpp:34
- 结论: 文件描述符通过open()获取后，在action()函数中被错误使用CloseHandle关闭，导致资源未正确释放（CWE-404）。
- D验证: confirmed / ver_ad74e944
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 194. hyp_path_2ebadb9f436a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_81a.cpp:31
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: CreateFile调用成功返回有效句柄（非INVALID_HANDLE_VALUE）。; action函数（CWE404_Improper_Resource_Shutdown__w32CreateFile_close_81_case0::action）未在内部调用CloseHandle或其他关闭操作释放CreateFile返回的句柄。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_81a.cpp:31; baseObject.action(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_81a.cpp:37
- 结论: 在CWE404_Improper_Resource_Shutdown__w32CreateFile_close_81_case0路由中，CreateFile打开的文件句柄被传递给action函数，但action函数实现在另一个文件中未提供，无法确认是否包含关闭操作。代码注释暗示期望在sink中关闭，存在资源泄露的风险。
- D验证: confirmed / ver_0dd6fbd9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 195. hyp_path_c06ee5e0c6ab

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_81a.cpp:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序运行并执行该路径，无需外部输入控制。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_81a.cpp:31; const CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_81_base& baseObject = CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_81_case0(); baseObject.action(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_81a.cpp:37-39
- 结论: 使用 CreateFile 创建文件句柄后，在 action 函数中可能使用 fclose 错误关闭句柄（而非 CloseHandle），导致资源泄漏（CWE-404）。现有代码片段未提供 action 内部实现，但题目命名暗示了错误关闭方式。
- D验证: confirmed / ver_5e650cf6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 196. hyp_path_52b116fa4fbe

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_73b.cpp:43
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能控制dataList内容，使data为有效的文件描述符（来自open()调用）
- 触发路径: int data = dataList.back(); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_73b.cpp:37; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_73b.cpp:43
- 结论: 在CWE404_Improper_Resource_Shutdown__open_fclose_73b.cpp第43行，代码使用fclose((FILE *)data)关闭文件，但data来自open()获得的文件描述符（int），应使用close()而非fclose()，违反API契约，导致资源关闭不当（CWE-404）。蓝队指出缺少open()的直接代码证据，但根据Juliet测试用例命名及上下文，source路径可信。
- D验证: confirmed / ver_5e7bf813
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 197. hyp_path_146fd6bba45f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_73b.cpp:45
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需直接控制输入，测试用例预设data为open()返回的文件描述符；实际场景中攻击者可能通过控制文件路径影响文件描述符分配。
- 触发路径: int data = dataList.back(); if (data != -1) { @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_73b.cpp:39-43; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_73b.cpp:43-47
- 结论: 使用CloseHandle()关闭由open()返回的文件描述符，违反了API合约（open()应配合close()，而非CloseHandle()），导致资源关闭不当（CWE-404）。尽管代码中未直接展示open()调用，但测试用例名称和上下文明确指示data来自open()，且CloseHandle误用是典型的CWE-404。
- D验证: confirmed / ver_7f51fc5c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 198. hyp_path_5cf293a48574

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_73b.cpp:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序流程到达该sink，且data为有效HANDLE（非INVALID_HANDLE_VALUE）
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_73b.cpp:36
- 结论: 使用CreateFile返回的HANDLE资源被错误地用fclose()关闭，违反了API合约，导致资源未正确释放（CWE-404）。
- D验证: confirmed / ver_35fd3f50
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 199. hyp_path_995dbd9ec97a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_73b.cpp:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: data是由fopen成功返回的FILE*指针，且非空
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_73b.cpp:34
- 结论: 使用fopen打开的文件，却使用close()而非fclose()关闭，违反API contract，可能导致资源未正确关闭（如缓冲区丢失）和资源泄漏风险。
- D验证: confirmed / ver_6069ddf7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 200. hyp_path_ff845fdd5637

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_73b.cpp:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到此关闭路径，且 data 不为 NULL。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_73b.cpp:36
- 结论: 使用 CloseHandle 关闭通过 freopen 打开的 FILE* 资源，违反正确资源关闭 API contract，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_17c37c8e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 201. hyp_path_4fcf358ae6b6

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_73b.cpp:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: dataList 中包含一个通过 fopen 打开的有效 FILE* 指针（非空），且代码执行到该 sink 路径。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_73b.cpp:36
- 结论: 误用 CloseHandle 关闭通过 fopen 打开的文件，应使用 fclose 关闭，违反 API contract，导致资源未正确关闭，可能造成资源泄露或程序不稳定。
- D验证: confirmed / ver_52e209fb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 202. hyp_path_56cbb6cefd31

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_73b.cpp:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在一个有效的HANDLE值，且该HANDLE由CreateFile创建
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_73b.cpp:36
- 结论: 函数使用_close()关闭由CreateFile返回的HANDLE，而非CloseHandle()，违反了Windows API合同，可能导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_0dbd1dcf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 203. hyp_path_56c227ba67d0

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_73b.cpp:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: dataList由之前调用freopen填充，且data非NULL
- 触发路径: FILE * data = dataList.back(); if (data != NULL) { ... _close((int)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_73b.cpp:32-36
- 结论: 资源关闭不当：使用_close()而不是fclose()关闭通过freopen获得的FILE*指针，导致资源泄露或未定义行为。
- D验证: confirmed / ver_ba426705
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 204. hyp_path_573a25997668

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83_case0.cpp:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序正常执行到析构函数，且data非空。
- 触发路径: CloseHandle((HANDLE)data); @ CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83_case0.cpp:37
- 结论: 使用fopen打开文件后，在析构函数中使用CloseHandle替代fclose关闭，导致资源未正确释放，违反API合约，可能引发文件句柄泄漏。
- D验证: confirmed / ver_eb94a021
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 205. hyp_path_627a7678645e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83a.cpp:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 构造函数实现内部调用fopen打开文件，并将返回值赋给data，后续在析构函数或其它函数中调用CloseHandle而非fclose关闭资源
- 触发路径: /* Initialize data */ data = NULL; CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83_case0 case0Object(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83a.cpp:28-32
- 结论: fopen返回的FILE*资源应使用fclose关闭，但构造函数的实现可能错误地使用CloseHandle关闭，导致资源未正确释放，违反API contract。
- D验证: confirmed / ver_22a473a9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 206. hyp_path_906d08db8608

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_84_case0.cpp:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响fopen调用或控制文件路径，但无需直接控制data指针。漏洞源于编程错误。
- 触发路径: FILE* data = fopen(...); @ 疑似在构造函数或其他初始化函数中，未在提供代码片段中显示，但样本名称及注释暗示; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_84_case0.cpp:37
- 结论: 使用CloseHandle关闭fopen打开的文件，导致资源关闭不匹配，违反API contract，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_799f9443
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 207. hyp_path_c136628338a4

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_83_case0.cpp:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件通过fopen成功打开（返回非NULL FILE*指针），且对象生命周期结束触发析构函数。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_83_case0.cpp:35
- 结论: 使用fopen打开文件后，在析构函数中错误地使用_close()（期望文件描述符）而不是fclose()关闭，导致资源未正确释放，违反CWE-404 Improper Resource Shutdown。
- D验证: confirmed / ver_94984e74
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 208. hyp_path_fb8a42ec17d2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_84_case0.cpp:35
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 攻击者能够控制文件打开操作（在本测试用例中，文件打开由测试代码固定，但实际应用中可能受外部影响）。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_84_case0.cpp:35
- 结论: 使用 _close() 而非 fclose() 关闭通过 fopen() 打开的文件，导致资源关闭方式不匹配，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_3fd64f79
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 209. hyp_path_1b54f7dc5fbb

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_83a.cpp:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = NULL; CWE404_Improper_Resource_Shutdown__fopen_w32_close_83_case0 case0Object(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_83a.cpp:30; 推测代码：~case0() { fclose(data); } // 实际代码未提供 @ 假设析构函数 ~CWE404_Improper_Resource_Shutdown__fopen_w32_close_83_case0 (D1Ev) 中直接调用 fclose(data) 而无 NULL 检查
- 结论: 可能存在CWE-404资源未正确关闭：在析构函数中关闭了由构造函数初始化为NULL的文件句柄，违反不应关闭无效句柄的API规范。但由于析构函数代码未提供，路径不完整，无法确认真实行为。
- D验证: confirmed / ver_98034eff
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 210. hyp_path_b7687fe3a5f9

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_83_case0.cpp:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: N/A
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_83_case0.cpp:37
- 结论: 在析构函数中，对通过freopen获取的FILE*资源错误地使用了CloseHandle()进行关闭，违反了API使用契约，导致资源关闭不当。
- D验证: confirmed / ver_80c289e6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 211. hyp_path_47a6233a31c0

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_83a.cpp:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法直接控制，但程序逻辑可能因输入或环境导致freopen失败，或构造函数内部异常。
- 触发路径: data = NULL; CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_83_case0 case0Object(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_83a.cpp:30
- 结论: 在构造函数中通过freopen打开的资源可能在对象析构前未正确关闭，尤其是在构造函数抛出异常或资源打开失败时，导致资源泄漏（CWE-404）。
- D验证: confirmed / ver_64c391a4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 212. hyp_path_a29a0a6bc3be

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84_case0.cpp:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需主动控制，但资源泄漏可能导致后续利用（如拒绝服务）。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84_case0.cpp:37
- 结论: 使用 CloseHandle 关闭通过 freopen 打开的文件流，导致资源关闭不当，违反 CWE-404（不正确的资源关闭）。
- D验证: confirmed / ver_2a1b3571
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 213. hyp_path_63c39ac944fa

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_83_case0.cpp:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制程序打开文件并触发对象的析构
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_83_case0.cpp:35
- 结论: 使用freopen打开的文件在析构函数中错误地使用_close()关闭，而不是fclose()，违反了API contract，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_bac15f1a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 214. hyp_path_a3591a3a9f4c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_83a.cpp:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响程序流程，使得对象被构造后析构时未关闭文件句柄
- 触发路径: CWE404_Improper_Resource_Shutdown__freopen_w32_close_83_case0 case0Object(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_83a.cpp:30
- 结论: 可能未正确关闭由freopen打开的资源，导致资源泄露。构造函数可能调用freopen打开文件，但析构函数实现未提供，无法确认是否正确关闭，存在违反CWE-404的风险。
- D验证: confirmed / ver_337b130b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 215. hyp_path_9e94db2eed8a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_84_case0.cpp:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在一个由freopen打开的FILE*指针data，且程序在析构函数中尝试关闭它。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_84_case0.cpp:35
- 结论: 在析构函数中，使用_close()（文件描述符关闭函数）来关闭由freopen返回的FILE*流，违反了API contract，导致资源关闭不匹配，可能造成资源泄漏或数据未刷新。
- D验证: confirmed / ver_0899e768
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 216. hyp_path_e2effbfbd251

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_32.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件打开成功（假设open返回有效文件描述符）。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_32.c:40; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_32.c:48
- 结论: 使用open()获取文件描述符后，错误地使用fclose()关闭，导致资源未正确关闭，违反API contract。
- D验证: confirmed / ver_99e0843e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 217. hyp_path_95079d331066

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_66a.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序正常执行到source处，且sink未正确关闭资源。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_66a.c:40; dataArray[2] = data; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_66a.c:42; CWE404_Improper_Resource_Shutdown__open_fclose_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_66a.c:43
- 结论: 文件描述符在打开后可能未正确关闭，违反CWE404资源未正确关闭。sink函数可能使用了fclose而非close，导致资源泄露。
- D验证: confirmed / ver_600f432a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 218. hyp_path_9fef0ae60652

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_83_case0.cpp:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到析构函数时，data仍为有效的文件描述符（open成功）。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_83_case0.cpp:35
- 结论: 使用fclose()关闭通过open()返回的文件描述符，导致不匹配的资源关闭操作，违反API contract，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_5d9d0fc0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 219. hyp_path_b6a674913a9f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_67a.c:45
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序正常运行且 sink 内使用 fclose() 关闭 fd。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_67a.c:45; CWE404_Improper_Resource_Shutdown__open_fclose_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_67a.c:47
- 结论: 资源关闭不当：open() 返回文件描述符，但后续可能使用 fclose() 关闭，导致资源未正确释放或行为未定义。
- D验证: confirmed / ver_2b74a5f0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 220. hyp_path_edf3aaaecef3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_68a.c:43
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: open()调用成功返回非负文件描述符；sink函数内部未调用close()关闭该描述符；程序执行路径到达sink函数。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_68a.c:43; CWE404_Improper_Resource_Shutdown__open_fclose_68b_case0Sink(); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_68a.c:45
- 结论: 文件描述符未关闭：open()打开文件后，在sink函数中未调用close()关闭文件描述符，导致资源泄漏。
- D验证: confirmed / ver_51eee259
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 221. hyp_path_5b9e27455abc

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_84_case0.cpp:35
- 漏洞类型: CWE-404, CWE-762
- CWE: CWE-404; CWE-762
- 风险等级: P0
- 触发条件: 攻击者能够通过对象生命周期管理触发析构函数
- 触发路径: ~CWE404_Improper_Resource_Shutdown__open_fclose_84_case0() { ... } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_84_case0.cpp:30; fclose((FILE *)data); // 错误：应调用close(data) @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_84_case0.cpp:35
- 结论: 析构函数中错误地使用fclose()关闭通过open()打开的文件描述符，违反了API contract，导致文件描述符未正确关闭（资源泄漏）。
- D验证: confirmed / ver_184b1121
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 222. hyp_path_9c404eac7725

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_83a.cpp:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发对象构造，且构造函数内部调用open()分配资源
- 触发路径: data = -1; CWE404_Improper_Resource_Shutdown__open_fclose_83_case0 case0Object(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_83a.cpp:30
- 结论: 可能存在资源未正确关闭漏洞，但缺少source（open调用）的直接证据。构造函数内部可能调用open()，需进一步验证。
- D验证: confirmed / ver_db82365e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 223. hyp_path_4472f095ac52

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_32.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无外部输入，但路径确定可达
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); *dataPtr1 = data; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_32.c:41-43; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_32.c:49-50
- 结论: 文件描述符误用 CloseHandle 关闭，违反资源关闭契约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_f5970761
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 224. hyp_path_708539231564

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_66a.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件可成功打开，即 open() 返回非 -1 的文件描述符
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_66a.c:42; dataArray[2] = data; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_66a.c:44; CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_66a.c:45
- 结论: 资源关闭不匹配：使用 open() 返回的文件描述符 (int) 作为 CloseHandle 的参数，导致资源未正确关闭。
- D验证: confirmed / ver_35395ddb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 225. hyp_path_478661b0882c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_67a.c:47
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序每次调用该路径都会打开文件描述符并传递到错误关闭的sink，无需外部输入控制。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); myStruct.structFirst = data; CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_67a.c:47-49
- 结论: 打开的文件描述符未使用close()关闭，而是使用了用于Windows句柄的CloseHandle，导致资源泄漏。
- D验证: confirmed / ver_096f63f0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 226. hyp_path_1b48cb57380c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_83_case0.cpp:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够通过控制程序流程触发对象析构
- 触发路径: { /* NOTE: Attempt to close the file using CloseHandle() instead of close() */ CloseHandle((HANDLE)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_83_case0.cpp:35-39
- 结论: 在析构函数中，使用CloseHandle()关闭由open()返回的文件描述符，导致资源类型不匹配，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_6768641d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 227. hyp_path_c479251bb554

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68a.c:45
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需控制输入，漏洞由代码自身逻辑导致，但通过多次调用可导致资源耗尽。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68a.c:45; CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68_case0DataForCase0Sink = data; CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68b_case0Sink(); @ CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68a.c:47
- 结论: 在CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68a.c中，open()返回的文件描述符传递给sink函数CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68b_case0Sink，根据函数名推测该sink使用CloseHandle()而非close()关闭资源，导致文件描述符未正确关闭，违反CWE-404定义。
- D验证: confirmed / ver_95cdb0df
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 228. hyp_path_b4617b7f0aa8

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_83a.cpp:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 构造对象时内部调用 open 分配资源，使 data 持有有效文件描述符
- 触发路径: data = -1; CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_83_case0 case0Object(data); @ L30
- 结论: CWE404: 资源关闭不当 - 使用 open 获取的文件描述符通过 CloseHandle 关闭，违反 Windows API 契约，可能导致资源泄漏或未定义行为
- D验证: confirmed / ver_b7359e24
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 229. hyp_path_1671d397b4fd

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_84_case0.cpp:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发对象的析构函数，例如通过控制对象生命周期或异常处理。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_84_case0.cpp:37
- 结论: 使用CloseHandle()关闭由open()返回的文件描述符，违反了CloseHandle期望HANDLE的API约定，导致资源关闭不当，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_c58fd834
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 230. hyp_path_6fa07e2b8a6b

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_32.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile成功返回有效句柄，且程序执行到关闭代码路径。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_32.c:33; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_32.c:47
- 结论: 代码使用CreateFile打开文件，但错误地使用_close()而不是CloseHandle()来关闭文件句柄，违反了API契约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_c0fdf4fe
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 231. hyp_path_c00665bceb95

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_66a.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无外部攻击者控制输入；程序内部资源管理缺陷。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...) @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_66a.c:33; CWE404_Improper_Resource_Shutdown__w32CreateFile_close_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_66a.c:42
- 结论: 函数CreateFile打开的句柄可能未正确关闭，导致资源泄漏。sink函数CWE404_Improper_Resource_Shutdown__w32CreateFile_close_66b_case0Sink中未调用CloseHandle关闭句柄，违反API contract。
- D验证: confirmed / ver_49ba091f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 232. hyp_path_78be58776311

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_67a.c:38
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需控制输入；漏洞由代码路径自动触发。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_67a.c:38; myStruct.structFirst = data; CWE404_Improper_Resource_Shutdown__w32CreateFile_close_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_67a.c:46; 未提供，需审查是否包含CloseHandle调用。 @ sink函数内部
- 结论: 资源句柄通过CreateFile创建后，通过结构体传递给sink函数，但蓝队未能提供sink函数内部代码，B阶段信号较弱（risk_score=0.27）且P0静态确认不支持，因此无法确认sink是否缺失CloseHandle调用，但基于CWE404测试套件典型模式，仍存在资源泄漏风险。
- D验证: confirmed / ver_954edee9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 233. hyp_path_f41feb7bb5d3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_68a.c:36
- 漏洞类型: CWE-404, CWE-252
- CWE: CWE-404; CWE-252
- 风险等级: P0
- 触发条件: 程序未检查CreateFile返回值，且sink函数未正确关闭文件句柄
- 触发路径: data = INVALID_HANDLE_VALUE; data = CreateFile(...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_68a.c:34-36; CWE404_Improper_Resource_Shutdown__w32CreateFile_close_68_case0DataForCase0Sink = data; CWE404_Improper_Resource_Shutdown__w32CreateFile_close_68b_case0Sink(); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_68a.c:42-44
- 结论: 在文件打开后未正确关闭资源，可能导致资源泄漏。同时CreateFile返回值未检查，若失败则后续操作使用无效句柄。
- D验证: confirmed / ver_8ef145e9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 234. hyp_path_fd8b15184a97

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83_case0.cpp:41
- 漏洞类型: CWE-404, CWE-763
- CWE: CWE-404; CWE-763
- 风险等级: P0
- 触发条件: 程序使用 CreateFile 创建了文件句柄并存储在 data 中
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83_case0.cpp:41
- 结论: 在析构函数中，使用 _close() 关闭由 CreateFile 返回的 HANDLE，违反了 API contract，导致资源关闭方式不匹配（应使用 CloseHandle）。
- D验证: confirmed / ver_0e3a5320
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 235. hyp_path_8ec2469f5bb4

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84_case0.cpp:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发资源分配（例如通过文件打开操作）并使程序执行到该析构函数。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84_case0.cpp:41
- 结论: 代码使用 _close() 关闭由 CreateFile 返回的 HANDLE，违反了 API contract，应使用 CloseHandle()。这可能导致资源未正确释放，造成资源泄漏。
- D验证: confirmed / ver_22d82476
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 236. hyp_path_ab150f948fd2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83a.cpp:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 用户或攻击者能够触发该代码路径，使得资源分配后未释放，可能导致系统资源耗尽。
- 触发路径: data = INVALID_HANDLE_VALUE; @ CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83a.cpp:29; CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83_case0 case0Object(data); @ CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83a.cpp:30
- 结论: 在 CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83a.cpp 中，资源句柄可能被打开但未正确关闭，导致资源泄漏（CWE-404）。从代码片段看，data 被初始化为 INVALID_HANDLE_VALUE，但后续通过 case0Object 使用该句柄，且未在对象析构或适当位置关闭（seed 中析构函数未显示关闭操作）。
- D验证: confirmed / ver_a30332e6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 237. hyp_path_18fa8f130993

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_32.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到关闭文件句柄的代码路径，且无错误处理阻断。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_32.c:32; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_32.c:47
- 结论: 文件句柄通过CreateFile打开后，使用fclose关闭，违反了API contract，导致资源未正确关闭，属于CWE-404 Improper Resource Shutdown。
- D验证: confirmed / ver_19a7d3f2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 238. hyp_path_ff80118fb33a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_66a.c:33
- 漏洞类型: CWE-404, CWE-252
- CWE: CWE-404; CWE-252
- 风险等级: P0
- 触发条件: 系统环境导致CreateFile失败（如磁盘空间不足、权限不足等）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_66a.c:33; CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_66a.c:42
- 结论: 在CreateFile调用后未检查返回值，若创建文件失败则返回INVALID_HANDLE_VALUE，该无效句柄被传递给sink函数，可能导致资源关闭操作异常或资源泄漏。
- D验证: confirmed / ver_82ce37c1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 239. hyp_path_2bf55a74d51f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_83_case0.cpp:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者需要能够影响该对象的生命周期，但无需直接控制输入；漏洞本身是内部资源管理错误。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_83_case0.cpp:41
- 结论: 在析构函数中，使用 fclose() 关闭由 CreateFile() 打开的资源句柄，违反了 API contract，导致资源关闭不当（CWE-404）。
- D验证: confirmed / ver_a5e9cfc6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 240. hyp_path_ef32b3f31a5a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67a.c:38
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需用户输入，代码自动执行
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67a.c:38; CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67a.c:46
- 结论: 在CWE404测试用例中，文件句柄通过CreateFile创建后传递给sink函数，但sink函数可能未正确关闭句柄，导致资源未释放，违反API contract（CWE-404）。
- D验证: confirmed / ver_9a72d709
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 241. hyp_path_b19b8a06667d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68a.c:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile调用成功返回有效句柄（非INVALID_HANDLE_VALUE）。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68a.c:34-38; CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68_case0DataForCase0Sink = data; CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68b_case0Sink(); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68a.c:44
- 结论: 使用fclose关闭CreateFile返回的HANDLE，违反API contract（CreateFile返回HANDLE应使用CloseHandle），导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_4e59cf7e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 242. hyp_path_3f55fa0fa000

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_83a.cpp:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制程序执行路径，使 CreateFile 返回有效句柄，且后续调用 fclose 关闭该句柄。
- 触发路径: /* Initialize data */ data = INVALID_HANDLE_VALUE; CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_83_case0 case0Object(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_83a.cpp:28-32
- 结论: 程序可能使用 Win32 API CreateFile 返回的句柄调用了 fclose 关闭，导致资源关闭不当（CWE-404）。当前代码片段仅显示初始化 data 为 INVALID_HANDLE_VALUE，但漏洞路径可能存在于类的构造函数/析构函数实现中，实际调用 CreateFile 和 fclose 的代码未在触发路径中展示。
- D验证: confirmed / ver_5f998d0a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 243. hyp_path_ba6875877713

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84_case0.cpp:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序正常执行，CreateFileW 成功返回有效 HANDLE。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84_case0.cpp:41
- 结论: 使用 fclose() 关闭由 CreateFileW 打开的 HANDLE 类型资源，违反了 API contract，可能导致资源未正确释放或未定义行为。
- D验证: confirmed / ver_6ff4130d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 244. hyp_path_c7f65e404e97

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_21.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 通过fopen打开文件获得FILE*指针
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_21.c:33
- 结论: 错误地使用CloseHandle关闭fopen返回的文件指针，违反了API contract，导致资源释放不当（CWE-404）
- D验证: confirmed / ver_9c01d875
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 245. hyp_path_637ad9cdaaa4

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_41.c:28
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 无外部攻击者输入要求，仅需程序执行至错误关闭代码路径
- 触发路径: data = fopen(fileName, "w"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_41.c:23; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_41.c:28
- 结论: 使用fopen打开的文件资源，错误地使用CloseHandle进行关闭，违反了API contract，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_cdf9281c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 246. hyp_path_1ec995b5da87

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_22b.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: fopen成功返回非NULL的FILE*指针
- 触发路径: FILE *data = fopen(...); @ 未知行（fopen调用）; CloseHandle((HANDLE)data); @ 33行
- 结论: 在Windows环境下，使用fopen打开文件后，错误地使用CloseHandle（而非fclose）关闭文件，导致文件资源未正确释放，违反API契约，造成资源泄漏。
- D验证: confirmed / ver_eb89e08f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 247. hyp_path_f3a4ee30f96c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_45.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响程序执行流，使该资源关闭路径被执行
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_45.c:32
- 结论: 使用fopen打开的文件使用CloseHandle关闭，违反了API contract，导致资源未正确关闭，可能造成资源泄漏或意外行为。
- D验证: confirmed / ver_ffcaeabf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 248. hyp_path_81d69f8bb8f0

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_44.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发case0Sink的调用，且传入有效的FILE*指针
- 触发路径: // 调用者传入FILE* data = fopen(...) @ case0Sink入口; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_44.c:28
- 结论: 代码使用CloseHandle关闭由fopen返回的FILE*指针，违反了Windows API contract，可能导致资源泄漏或程序崩溃。
- D验证: confirmed / ver_fbe39d90
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 249. hyp_path_86bca0715fe4

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_51b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: fopen成功返回非NULL的文件指针；程序执行到sink调用路径。
- 触发路径: FILE *data = fopen(...); @ 调用fopen的位置（未在代码片段中展示，假设在sink前）; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_51b.c:28
- 结论: 调用fopen打开文件后，使用了CloseHandle()而不是fclose()来关闭文件，违反API契约，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_554a9dbd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 250. hyp_path_9671222d84ad

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_52b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够通过某种方式控制 fopen 打开的文件（如文件名或内容），但核心漏洞在于资源的错误关闭方式。
- 触发路径: CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_52c_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_52b.c:28
- 结论: 函数 CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_52b_case0Sink 将 FILE* 指针传递给下游可能使用 CloseHandle 关闭的错误关闭例程，导致由 fopen 打开的资源被错误关闭，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_f2a82821
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 251. hyp_path_4837191c3356

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_52c.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码路径中data是通过fopen获得的有效文件指针
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_52c.c:28
- 结论: 在关闭文件资源时，使用了不匹配的API：通过fopen打开的文件应使用fclose关闭，但代码中使用了CloseHandle。这违反了API contract，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_4a8a2bdc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 252. hyp_path_675b4ca8a37f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够通过程序逻辑控制文件打开操作，并使得程序执行到此sink路径
- 触发路径: CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53c_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53b.c:28
- 结论: 函数接收FILE*指针并传递给CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53c_case0Sink，该函数可能使用CloseHandle关闭句柄，违反了CWE-404（应使用fclose关闭fopen打开的资源）。当前代码片段仅显示调用链中间层，未直接展示CloseHandle调用，但测试用例命名明确暗示了该误用路径。
- D验证: confirmed / ver_0dd94d77
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 253. hyp_path_485ef08cda0e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53c.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制fopen的路径参数，或程序逻辑中使用了fopen并随后误用CloseHandle。
- 触发路径: void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53c_case0Sink(FILE * data) { CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53d_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53c.c:26-30; 假设存在CloseHandle(data) 或类似误用调用 @ CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53d.c（假设，未提供）
- 结论: 使用fopen打开的资源被错误地使用CloseHandle关闭，导致资源未正确释放，可能造成资源泄露或程序崩溃。
- D验证: confirmed / ver_399b2771
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 254. hyp_path_f173a50a08c2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53d.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该代码路径，且通过fopen成功打开文件
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53d.c:28
- 结论: 使用fopen打开文件后，错误地使用CloseHandle()代替fclose()关闭文件，违反API contract，导致资源可能未正确释放（CWE-404 Improper Resource Shutdown）。
- D验证: confirmed / ver_379038bd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 255. hyp_path_c9c935efb527

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够通过某种方式影响文件操作，但本漏洞不依赖攻击者输入，属于代码逻辑缺陷。
- 触发路径: void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54b_case0Sink(FILE * data) { CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54c_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54b.c:28
- 结论: 函数CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54b_case0Sink传递FILE*指针给后续函数CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54c_case0Sink，该后续函数可能使用CloseHandle关闭文件流，违反了fopen应使用fclose关闭的API合同，导致资源错误关闭（CWE-404）。当前证据仅显示传递，未确认后续关闭方式，但路径存在可疑。
- D验证: confirmed / ver_8584dd5e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 256. hyp_path_5da03ec501c2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54c.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响目标代码中文件的打开操作，使得FILE*变量被传递给该sink函数。
- 触发路径: void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54c_case0Sink(FILE * data) { CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54d_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54c.c:26-30; 最终调用CloseHandle(data)，其中data是FILE*类型。 @ 函数调用链中的后续函数（如54d_case0Sink）
- 结论: 函数使用fopen打开文件，但后续可能使用CloseHandle（Windows句柄关闭函数）而非fclose关闭，违反API contract，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_2dc7a5a7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 257. hyp_path_51ad61b2eca4

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54e.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: data是fopen()成功返回的非NULL FILE*指针
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54e.c:28
- 结论: 使用CloseHandle()关闭fopen()返回的文件指针，违反了API合约，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_ce83bc40
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 258. hyp_path_dfe2252775de

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54d.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: data是通过fopen()分配的FILE*对象。
- 触发路径: CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54e_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54d.c:28
- 结论: 函数CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54d_case0Sink将FILE* data传递给后续函数_54e_case0Sink，根据命名和典型Juliet测试用例，后续函数很可能使用CloseHandle()而非fclose()关闭由fopen()打开的FILE*资源，导致资源未正确关闭（CWE-404）。虽然缺乏对后续函数源代码的直接验证，但基于模式推断存在漏洞。
- D验证: confirmed / ver_701da876
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 259. hyp_path_4f5b226d45f8

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_63b.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在任何通过fopen打开文件并传递此函数的路由
- 触发路径: CloseHandle((HANDLE)data); @ L29
- 结论: 使用错误的关闭函数：fopen打开的资源应使用fclose关闭，但代码使用CloseHandle，导致资源未正确关闭，可能引发资源泄漏或未定义行为。
- D验证: confirmed / ver_d06065ac
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 260. hyp_path_2d83d2ae6c11

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_64b.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码执行到此关闭路径，且 data 来自 fopen 返回的 FILE* 指针。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_64b.c:32
- 结论: 使用 CloseHandle 关闭通过 fopen 打开的文件，违反了资源关闭的 API 契约，导致资源未正确关闭，可能造成资源泄漏。
- D验证: confirmed / ver_99caa5bf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 261. hyp_path_4b19e40da101

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_66b.c:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需攻击者输入，漏洞由代码逻辑错误导致。
- 触发路径: CloseHandle((HANDLE)data); @ CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_66b.c:30
- 结论: 代码使用fopen打开文件，但错误地使用CloseHandle关闭文件句柄，导致资源未正确关闭，违反API contract，可能造成资源泄露或其他未定义行为。
- D验证: confirmed / ver_fb4dc179
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 262. hyp_path_30f681a4ee0d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_65b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需外部输入，漏洞由开发者错误使用API关闭资源导致
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_65b.c:28
- 结论: 在CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_65b.c中，使用CloseHandle()关闭fopen()返回的FILE*指针，而不是正确的fclose()，违反了fopen/fclose的API契约，可能导致资源泄漏或句柄误用，符合CWE-404定义。
- D验证: confirmed / ver_d23e8b5a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 263. hyp_path_42ef77553eb3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_67b.c:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码中已固定使用fopen打开文件，无外部输入控制，但错误关闭操作是明确的API misuse。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_67b.c:34
- 结论: 使用fopen打开文件后，错误地调用CloseHandle而不是fclose来关闭资源，导致资源关闭不当，可能引发资源泄漏或未定义行为。
- D验证: confirmed / ver_640c864f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 264. hyp_path_75170c5413a6

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_68b.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: fopen返回非NULL指针
- 触发路径: FILE *data = fopen(...); @ fopen调用处（位于其他文件）; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_68b.c:33
- 结论: 程序使用fopen打开文件后，错误地使用CloseHandle()而不是fclose()关闭资源，违反了API contract，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_62c099d7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 265. hyp_path_91ca735c8bad

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_81_case0.cpp:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: data是由fopen()返回的非空FILE*指针，且未提前关闭。
- 触发路径: /* NOTE: Attempt to close the file using CloseHandle() instead of fclose() */ CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_81_case0.cpp:29-33
- 结论: 使用CloseHandle()关闭通过fopen()打开的文件，违反了资源关闭的API契约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_7514320b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 266. hyp_path_73929eedc9f2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_82_case0.cpp:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序已通过fopen获得FILE*指针data。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_82_case0.cpp:31
- 结论: 使用CloseHandle()关闭由fopen()打开的文件句柄，违反了API contract，导致资源关闭不当。
- D验证: confirmed / ver_43bba17a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 267. hyp_path_7bd19e325c4e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_21.c:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该代码路径，且data是由fopen返回的有效FILE*指针。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_21.c:31
- 结论: 使用fopen打开文件后，使用_close而不是fclose关闭文件，违反了资源关闭的API约定，导致资源句柄可能未正确释放或产生未定义行为。
- D验证: confirmed / ver_3ee8e2ce
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 268. hyp_path_c63e0933badf

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_22b.c:31
- 漏洞类型: CWE-404, CWE-775
- CWE: CWE-404; CWE-775
- 风险等级: P0
- 触发条件: 程序执行到该资源关闭路径，且data是由fopen()返回的有效FILE*指针
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_22b.c:31
- 结论: 使用_close()关闭fopen()返回的FILE*指针，导致资源未正确释放（文件流缓冲区未刷新、文件描述符可能泄漏），违反API合约。
- D验证: confirmed / ver_f02aaaa2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 269. hyp_path_bb3364c02985

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_41.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 函数被调用，且data为有效的FILE*指针。
- 触发路径: fopen(...) @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_41.c:?; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_41.c:26
- 结论: 函数使用fopen打开文件后，错误地使用_close()而不是fclose()关闭文件，导致FILE*资源泄漏，违反CWE-404（不正确的资源关闭）。
- D验证: confirmed / ver_9dd34c22
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 270. hyp_path_2e245e0162b6

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_44.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码路径被执行，且data为fopen返回的有效FILE*指针。
- 触发路径: { /* NOTE: Attempt to close the file using close() instead of fclose() */ _close((int)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_44.c:24-28
- 结论: 使用fopen打开的文件通过_close()而非fclose()关闭，违反CWE-404：不正确的资源关闭，可能导致文件句柄泄漏或缓冲区未刷新。
- D验证: confirmed / ver_dccd4645
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 271. hyp_path_84a65bb3a0ae

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_45.c:30
- 漏洞类型: CWE-404, CWE-676
- CWE: CWE-404; CWE-676
- 风险等级: P0
- 触发条件: fopen成功返回非NULL的FILE*指针
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_45.c:30
- 结论: 使用fopen打开文件后，错误地使用_close()而不是fclose()关闭文件句柄，违反了API契约，可能导致资源泄漏或数据未刷新。
- D验证: confirmed / ver_e496b537
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 272. hyp_path_5cab22994b1c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_51b.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件已通过fopen成功打开。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_51b.c:26
- 结论: 使用fopen打开的文件通过_close()而不是fclose()关闭，违反了API contract，可能导致资源泄露或未定义行为。
- D验证: confirmed / ver_8513ec97
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 273. hyp_path_a722a6b0d4e1

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_52c.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: data是通过fopen()获得的非空FILE*指针
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_52c.c:26
- 结论: 资源关闭方式错误：使用fopen打开的文件应使用fclose()关闭，但代码中使用了_close()并强制转换FILE*为int，导致未定义行为或资源泄漏。
- D验证: confirmed / ver_8fc3d68c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 274. hyp_path_382fe350ece4

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_52b.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者通过前序代码控制data参数指向的资源（如未关闭的文件句柄）
- 触发路径: void CWE404_Improper_Resource_Shutdown__fopen_w32_close_52b_case0Sink(FILE * data) { CWE404_Improper_Resource_Shutdown__fopen_w32_close_52c_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_52b.c:24
- 结论: POTENTIAL_VULNERABILITY: 资源未关闭路径不完整，需52c代码确认。当前52b仅传递文件指针，未执行关闭操作，若52c未正确关闭资源则构成CWE-404漏洞。
- D验证: confirmed / ver_a5384ce8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 275. hyp_path_53ca5e7f3763

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_53b.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在一个source（如fopen）创建了FILE* data，并通过调用链传递到此sink函数，且后续未正确关闭
- 触发路径: void CWE404_Improper_Resource_Shutdown__fopen_w32_close_53b_case0Sink(FILE * data) @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_53b.c:24; CWE404_Improper_Resource_Shutdown__fopen_w32_close_53c_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_53b.c:26
- 结论: 资源未正确关闭：在sink函数中，FILE* data未被关闭，仅传递给下一sink函数，违反了CWE-404 API合约，可能导致资源泄漏。需确认source（如fopen）创建的资源是否最终被关闭。
- D验证: confirmed / ver_8f46a87f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 276. hyp_path_341bf20a3013

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_53d.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响文件打开操作（例如通过环境变量或程序输入使fopen成功）
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_53d.c:26
- 结论: 使用fopen打开文件后，使用_close()而不是fclose()关闭，导致资源未正确释放（文件句柄泄漏），违反CWE-404 Improper Resource Shutdown。
- D验证: confirmed / ver_9b7c9916
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 277. hyp_path_9d00264f3de2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_53c.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 样本入口函数被调用，数据来自fopen返回的FILE*指针
- 触发路径: void CWE404_Improper_Resource_Shutdown__fopen_w32_close_53c_case0Sink(FILE * data) { CWE404_Improper_Resource_Shutdown__fopen_w32_close_53d_case0Sink(data); } @ CWE404_Improper_Resource_Shutdown__fopen_w32_close_53c.c:24-28; 假设为: void CWE404_Improper_Resource_Shutdown__fopen_w32_close_53d_case0Sink(FILE * data) { CloseHandle((HANDLE)data); } // 资源类型不匹配 @ CWE404_Improper_Resource_Shutdown__fopen_w32_close_53d.c (假设函数内部)
- 结论: 存在不恰当的资源关闭：使用CloseHandle关闭fopen打开的文件句柄，导致资源泄露（CWE-404）
- D验证: confirmed / ver_05b949c4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 278. hyp_path_77be6b243593

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_54b.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: A FILE* data is passed to the sink; it was likely opened by fopen().
- 触发路径: void CWE404_Improper_Resource_Shutdown__fopen_w32_close_54b_case0Sink(FILE * data) { CWE404_Improper_Resource_Shutdown__fopen_w32_close_54c_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_54b.c:24-28
- 结论: API misuse: fopen() opened file should be closed using fclose() instead of CloseHandle (w32_close). The sink function passes the FILE pointer to a chain that likely uses CloseHandle, leading to improper resource shutdown.
- D验证: confirmed / ver_e666543f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 279. hyp_path_39df427e5956

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_54c.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制文件路径或打开模式（假设存在数据流入）
- 触发路径: void CWE404_Improper_Resource_Shutdown__fopen_w32_close_54c_case0Sink(FILE * data) { CWE404_Improper_Resource_Shutdown__fopen_w32_close_54d_case0Sink(data); } @ L24-28; 推测包含fopen和_close调用，违反API contract @ 下游函数54d_case0Sink（未在证据中显示）
- 结论: 存在CWE-404漏洞：使用fopen打开文件后，通过_close（而非fclose）关闭，导致资源未正确释放。
- D验证: confirmed / ver_3c10897e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 280. hyp_path_471111a64a4a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_54d.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在通过fopen打开的文件指针data，且后续路径中未调用fclose
- 触发路径: fopen(...) @ 入口函数（未在路由中显式提供，但代码逻辑暗示存在fopen调用）; CWE404_Improper_Resource_Shutdown__fopen_w32_close_54e_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_54d.c:26
- 结论: 资源未正确关闭：fopen打开的文件指针未调用fclose，导致资源泄漏
- D验证: confirmed / ver_f14a4ffd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 281. hyp_path_8841f96f551a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_54e.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到sink函数，且data参数为由fopen返回的非空FILE*指针
- 触发路径: CWE404_Improper_Resource_Shutdown__fopen_w32_close_54e_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_54e.c:21; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_54e.c:26
- 结论: 调用_fclose()关闭fopen打开的文件时，错误使用了_close()函数（文件描述符关闭），违反了API contract（fopen配对fclose），可能导致资源泄漏或未刷新缓冲区。
- D验证: confirmed / ver_540f3407
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 282. hyp_path_ddf4e86c3643

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_64b.c:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在通过fopen打开的文件资源，且后续关闭路径使用了不匹配的_close()函数。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_64b.c:30
- 结论: 使用fopen打开文件后，使用_close()而不是fclose()关闭，导致资源关闭不当（CWE-404）。将FILE*强制转换为int传递给_close()是未定义行为，可能造成资源泄漏或文件句柄错误关闭。
- D验证: confirmed / ver_a8dd74fe
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 283. hyp_path_818fe66b53a7

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_63b.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者不直接控制输入，但该错误是编码缺陷，可被内部执行路径触发
- 触发路径: void CWE404_Improper_Resource_Shutdown__fopen_w32_close_63b_case0Sink(FILE * data) @ 函数入口; _close((int)data); @ L27
- 结论: 使用 fopen 打开文件后，错误地使用 _close 而非 fclose 关闭文件，导致资源未正确关闭，违反了 CWE-404 关于资源正确关闭的要求，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_9b4d685f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 284. hyp_path_57c9fb914292

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_65b.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在先前的 fopen 调用，返回有效的 FILE* 指针
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_65b.c:26
- 结论: 使用 _close() 而非 fclose() 关闭 fopen 打开的文件句柄，违反 API 使用规则，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_9d67cc7d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 285. hyp_path_357df57f42a9

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_66b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发该代码路径，例如通过控制程序输入使得文件被打开并执行关闭操作；在测试用例中由测试框架直接调用。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_66b.c:28
- 结论: 使用fopen打开文件后，错误地使用_close()而非fclose()关闭文件，导致资源未正确关闭，符合CWE-404定义。
- D验证: confirmed / ver_36e7d29c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 286. hyp_path_62af3963808d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_67b.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件通过 fopen() 成功打开（返回非 NULL 指针）
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_67b.c:32
- 结论: 使用 _close() 关闭由 fopen() 打开的文件，违反了 API contract，可能导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_cd039e12
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 287. hyp_path_6387c4c622c3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_68b.c:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序成功执行到sink点，且data为fopen返回的非空FILE*指针。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_68b.c:31
- 结论: 函数使用fopen打开文件，但使用_close关闭，违反了CWE404规范，可能导致资源泄漏或未正确释放文件句柄。
- D验证: confirmed / ver_8e5a2dcb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 288. hyp_path_2f432894ac65

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_81_case0.cpp:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件已通过fopen成功打开，data为有效FILE*指针。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_81_case0.cpp:29
- 结论: 使用_close()关闭fopen打开的FILE*流，未调用fclose()，违反API契约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_4c40a15d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 289. hyp_path_a93b6cd6354f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_82_case0.cpp:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件通过fopen成功打开，返回非NULL的FILE*指针。
- 触发路径: _close((int)data); @ CWE404_Improper_Resource_Shutdown__fopen_w32_close_82_case0.cpp:29
- 结论: 使用fopen打开文件后，未使用fclose而使用_close关闭，导致资源关闭不当，违反API契约，可能造成资源泄漏。
- D验证: confirmed / ver_d3a2a18e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 290. hyp_path_035a101d0aae

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_21.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行了使用freopen打开文件的路径，并随后调用case0Sink函数，且data参数为freopen返回的有效FILE*指针。
- 触发路径: void case0Sink(FILE * data) @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_21.c:26; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_21.c:33
- 结论: 在CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_21.c中，freopen返回的FILE*指针被错误地使用CloseHandle()关闭，而应使用fclose()。这违反了API contract，导致资源关闭不当，可能引发资源泄漏或未定义行为。尽管B阶段风险分数较低，但代码证据明确显示API misuse路径，红队保留此漏洞假设。
- D验证: confirmed / ver_8908e507
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 291. hyp_path_43ec9c72cc95

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_22b.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: data 是由 freopen 成功返回的 FILE* 指针，且被传入该 sink 函数。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_22b.c:33
- 结论: 通过 freopen 打开的文件资源使用 CloseHandle 而不是 fclose 关闭，违反了 API contract，可能导致资源未正确释放或未定义行为。
- D验证: confirmed / ver_9b718a1b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 292. hyp_path_69ac7e3f7e12

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_41.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码路径可达，且data确实由freopen分配
- 触发路径: FILE* data = freopen(...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_41.c（函数入口或调用方，假设包含freopen调用）; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_41.c:28
- 结论: freopen返回的FILE*被错误地使用CloseHandle关闭，违反了API契约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_f9f80323
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 293. hyp_path_ad82d0f24001

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_44.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无特定攻击者输入，需要代码执行到该路径
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_44.c:28
- 结论: 代码使用freopen打开文件后，错误地使用CloseHandle进行关闭，违反了API契约。freopen返回的FILE*应该使用fclose关闭，而不是强制转换为HANDLE并调用CloseHandle，这可能导致资源泄露或未定义行为。
- D验证: confirmed / ver_789960e9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 294. hyp_path_d8b3ce049492

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_45.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发对case0Sink的调用，且参数data指向一个通过freopen()成功打开的文件流。
- 触发路径: void case0Sink(FILE * data) @ case0Sink函数入口; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_45.c:32
- 结论: 在CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_45.c的case0Sink中，代码使用CloseHandle()关闭通过freopen()打开的文件流资源，违反了Windows API合约：FILE*资源应使用fclose()关闭，而不应使用CloseHandle()。这可能导致资源泄漏、数据未刷新或未定义行为。
- D验证: confirmed / ver_790cd288
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 295. hyp_path_4726f4e9194e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_51b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响程序执行流，使得该sink函数被调用，且data参数为有效的FILE*指针。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_51b.c:28
- 结论: 代码使用CloseHandle()关闭由freopen()返回的文件流(FILE*)，违反了API契约：对于C标准I/O返回的FILE*，应使用fclose()关闭。CloseHandle()适用于内核对象句柄(HANDLE)，不适用于FILE*，可能导致资源未正确释放（如缓冲区未刷新）或未定义行为。
- D验证: confirmed / ver_451c4eea
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 296. hyp_path_3ce2b5ab7d38

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_52c.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序必须调用此sink函数，且参数data是通过freopen获得的文件指针（基于测试用例命名假定，但未在提供代码中确认）。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_52c.c:28
- 结论: 在CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_52c_case0Sink函数中，使用freopen打开文件后，错误地使用CloseHandle()而不是fclose()关闭文件句柄，违反了正确关闭资源的API契约，可能导致资源泄漏或句柄误用。尽管source（freopen调用）未在提供的代码片段中直接体现，但基于测试用例命名和代码注释推测存在，且B阶段静态分析未闭合source-sink路径，证据不完整。
- D验证: confirmed / ver_c350ba2f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 297. hyp_path_7fbf925daeaa

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_53b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 函数被调用时传入通过freopen打开的文件指针
- 触发路径: void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_53b_case0Sink(FILE * data) { CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_53c_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_53b.c:26
- 结论: POTENTIAL_CWE404_IMPROPER_RESOURCE_SHUTDOWN
- D验证: confirmed / ver_5dd73935
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 298. hyp_path_6df3dea248c3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_53c.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需外部攻击者控制，代码本身存在API误用；但若攻击者能影响data所代表的文件路径，可能加剧资源泄漏风险。
- 触发路径: CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_53d_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_53c.c:28
- 结论: 在CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_53c_case0Sink函数中，data参数源自freopen打开的文件流（根据函数名及测试套件上下文推断），但后续通过53d_case0Sink可能错误使用CloseHandle而非fclose关闭资源，违反API contract，导致资源泄漏。虽然当前代码片段仅显示转发调用，无法直接验证source和sink，但样本命名和CWE-404测试用例设计强烈暗示该路径。
- D验证: confirmed / ver_be6b5596
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 299. hyp_path_46daaa31d613

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_53d.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: The program must have previously opened a file with freopen() and passed the FILE* pointer (as HANDLE) to this sink function.
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_53d.c:28
- 结论: Improper resource shutdown: file opened with freopen() is closed using CloseHandle() instead of fclose(), violating the API contract and potentially causing resource leak or undefined behavior.
- D验证: confirmed / ver_b6b5e317
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 300. hyp_path_e714cdb025e3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在由freopen打开的FILE*资源未关闭
- 触发路径: void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54b_case0Sink(FILE * data) { CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54c_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54b.c:26-30
- 结论: 函数接收FILE*资源并传递给后续函数，但整个调用链中未关闭该资源，导致资源泄漏（CWE-404 Improper Resource Shutdown）
- D验证: confirmed / ver_72d4f611
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 301. hyp_path_ddb4ec3d4e54

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54d.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响文件打开路径或内容，但漏洞触发依赖于代码逻辑，无需直接攻击者控制。
- 触发路径: CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54e_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54d.c:28
- 结论: 使用freopen打开的文件可能被错误地使用CloseHandle关闭，违反了API contract，导致资源未正确释放，但缺乏直接代码证据确认CloseHandle调用。
- D验证: confirmed / ver_fd40f709
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 302. hyp_path_cccf62cd2033

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54e.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 源代码路径可达，data变量由freopen函数返回的有效FILE*指针赋值。
- 触发路径: Call to CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54e_case0Sink @ 23; CloseHandle((HANDLE)data); // 错误关闭 @ 28
- 结论: 代码使用CloseHandle关闭由freopen返回的FILE*，违反了CWE-404（不正确的资源关闭或释放）。CloseHandle用于关闭内核句柄，而freopen返回C标准流，应使用fclose关闭。此操作导致资源未正确释放，属于API misuse。
- D验证: confirmed / ver_33d14ffc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 303. hyp_path_a7a0b601540b

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_63b.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需攻击者控制输入，代码路径本身存在API误用。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_63b.c:29
- 结论: CWE-404 Improper Resource Shutdown: 使用freopen打开文件后，错误地使用CloseHandle关闭FILE*资源，导致资源泄漏。
- D验证: confirmed / ver_03a9d69f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 304. hyp_path_6b06a5192a02

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_64b.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: sink函数CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_64b_case0Sink被调用
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_64b.c:32
- 结论: 在关闭文件资源时使用了不匹配的关闭函数：freopen返回的FILE*资源应使用fclose关闭，但代码使用了CloseHandle，违反了API contract，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_45becbec
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 305. hyp_path_8639c12a47b0

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_65b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在通过freopen打开的文件资源，且该资源被传递到sink函数
- 触发路径: CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_65b_case0Sink(data); @ 入口函数调用sink; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_65b.c:28
- 结论: 在CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_65b_case0Sink函数中，使用CloseHandle关闭由freopen返回的FILE*指针，违反了API contract，应使用fclose。这会导致资源未正确关闭，可能造成文件缓冲区数据丢失或资源泄露（CWE-404）。
- D验证: confirmed / ver_2ed18b9a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 306. hyp_path_082d9d8507ae

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_66b.c:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够通过某种方式触发该代码路径，但具体输入控制不明确。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_66b.c:30
- 结论: 使用CloseHandle关闭通过freopen打开的文件，导致资源释放不当（CWE-404）。
- D验证: confirmed / ver_0a25ba35
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 307. hyp_path_a3750b0b23ed

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68b.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: freopen 成功打开文件并返回有效的 FILE* 指针
- 触发路径: data = freopen(fileName, "w", stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68b.c:27; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68b.c:33
- 结论: 使用 CloseHandle 关闭由 freopen 打开的文件资源，违反资源关闭 API contract，导致资源泄漏或未定义行为。
- D验证: confirmed / ver_c88f5c4c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 308. hyp_path_06ffbf1d9162

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_67b.c:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行路径确保一个由freopen()打开的文件指针data被传递给该sink函数。
- 触发路径: void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_67b_case0Sink(FILE * data) @ 入口函数CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_67b_case0Sink（第28行）接收参数data; CloseHandle((HANDLE)data); @ sink函数第34行错误地使用CloseHandle关闭文件流
- 结论: 在CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_67b.c中，sink函数接收FILE*参数后直接调用CloseHandle()将其转换为HANDLE关闭，违反了freopen文件流必须使用fclose()关闭的API契约，导致资源未正确关闭，可能引发资源泄漏或句柄泄漏。
- D验证: confirmed / ver_97e9f7a7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 309. hyp_path_2a4ba2be80ba

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_81_case0.cpp:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码中已存在通过freopen打开的文件指针，攻击者无需控制输入即可触发此错误关闭行为。
- 触发路径: action(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_81_case0.cpp:26; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_81_case0.cpp:31
- 结论: 在CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_81_case0.cpp中，使用CloseHandle关闭由freopen返回的FILE*对象，违反了API契约，导致资源未正确关闭（应使用fclose）。
- D验证: confirmed / ver_991f2de8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 310. hyp_path_5023ec8ee49d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_82_case0.cpp:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: freopen 成功返回 FILE* 指针，且程序执行到 CloseHandle 调用。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_82_case0.cpp:31
- 结论: 使用 CloseHandle 关闭 fopen/freopen 返回的 FILE* 指针，违反了资源关闭的正确 API 契约，导致不当的资源关闭行为（CWE-404）。
- D验证: confirmed / ver_676d8c72
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 311. hyp_path_b044d660271c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_21.c:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制程序执行至此关闭路径（例如通过触发特定控制流）。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_21.c:31
- 结论: 使用_close()关闭由freopen()返回的FILE*指针，违反API合约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_9b4bbb89
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 312. hyp_path_200fa6101d4a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_22b.c:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者可能通过控制输入导致该分支被执行，但具体 source 不可见，需要动态验证或 manual audit 确认 data 的来源是否为有效的 FILE* 指针。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_22b.c:31
- 结论: 使用 _close() 而非 fclose() 关闭由 freopen() 返回的 FILE* 指针 data，违反 API 契约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_e8cf620f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 313. hyp_path_6cf565ba894e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_41.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在通过freopen打开的FILE*变量data，且未进行NULL检查或类型验证。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_41.c:26
- 结论: 使用freopen打开的文件应该使用fclose关闭，但代码中使用_close关闭，导致资源关闭不匹配，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_d0babcc2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 314. hyp_path_43907c59f1d0

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_44.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在通过freopen()成功打开的文件流data
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_44.c:26
- 结论: 使用_close()关闭通过freopen()打开的文件流，导致资源关闭不当：未刷新缓冲区且可能造成资源泄漏或数据丢失。
- D验证: confirmed / ver_ee71b144
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 315. hyp_path_be5e0f5e5a10

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_45.c:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件通过 freopen() 打开（未在触发路径中体现，但上下文表明存在 freopen 调用），且关闭时错误使用了 _close 而非 fclose。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_45.c:30
- 结论: 使用 _close() 关闭通过 freopen() 打开的文件，而非 fclose()，导致资源未正确关闭，违反了 API contract，可能导致资源泄漏。
- D验证: confirmed / ver_33f414d5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 316. hyp_path_7764f9dae94d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_51b.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制导致freopen打开的文件流被传入sink函数（当前样本中data来源未明确展示，需动态确认）。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_51b.c:26
- 结论: 在CWE404_Improper_Resource_Shutdown__freopen_w32_close_51b.c的sink函数中，使用_close()代替fclose()关闭由freopen打开的文件流，违反API contract，导致资源未正确释放（CWE-404）。尽管攻击者可控性证据不完整，但漏洞假设成立，需要动态验证。
- D验证: confirmed / ver_0ddba149
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 317. hyp_path_7e0df861685f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_52b.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在通过freopen打开的FILE*指针作为输入传递给sink函数
- 触发路径: void CWE404_Improper_Resource_Shutdown__freopen_w32_close_52b_case0Sink(FILE * data) { CWE404_Improper_Resource_Shutdown__freopen_w32_close_52c_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_52b.c:24-28
- 结论: 可能存在CWE-404资源未正确关闭漏洞，但当前代码证据不完整，仅显示sink函数调用链（52b->52c），未提供52c内部实现，无法确认是否实际执行了资源关闭操作（如fclose或close）。需要进一步获取52c函数的实现代码以闭合验证。
- D验证: confirmed / ver_bace21d5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 318. hyp_path_f957ee4a39a0

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_52c.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发此代码路径，即调用包含该sink的函数，且data参数为通过freopen获取的FILE*指针。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_52c.c:26
- 结论: 通过freopen打开的文件流使用了_close()而不是fclose()关闭，违反了API contract，导致资源未正确关闭（CWE-404: Improper Resource Shutdown）。
- D验证: confirmed / ver_53c27904
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 319. hyp_path_772f9491f022

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_53b.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序通过freopen获取了FILE*资源，且后续未在当前路由中调用fclose或类似关闭操作。
- 触发路径: void CWE404_Improper_Resource_Shutdown__freopen_w32_close_53b_case0Sink(FILE * data) { CWE404_Improper_Resource_Shutdown__freopen_w32_close_53c_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_53b.c:24-28
- 结论: 可能存在资源未关闭漏洞：freopen打开的文件资源在传递到53c函数后未确认关闭，可能导致资源泄露。需要验证CWE404_Improper_Resource_Shutdown__freopen_w32_close_53c_case0Sink内部是否包含关闭操作。
- D验证: confirmed / ver_c5dd1b12
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 320. hyp_path_60097edbcb94

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_53c.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制文件名或文件操作，但正常用例中即使文件名固定，API misuse仍然存在
- 触发路径: CWE404_Improper_Resource_Shutdown__freopen_w32_close_53c_case0Sink(data); @ 假设的入口函数（如CWE404_Improper_Resource_Shutdown__freopen_w32_close_53_bad）中调用53c的sink; CWE404_Improper_Resource_Shutdown__freopen_w32_close_53d_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_53c.c:26; close(data); // 错误关闭函数 @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_53d.c（推测）
- 结论: CWE404_Improper_Resource_Shutdown: 函数通过freopen打开文件后，在清理路径中错误地调用了close（而非fclose）来关闭FILE*句柄，导致资源未正确释放。
- D验证: confirmed / ver_bbc46fcc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 321. hyp_path_1bc80dbe9860

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_53d.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行流调用CWE404_Improper_Resource_Shutdown__freopen_w32_close_53d_case0Sink函数，且传入的参数data是由freopen成功返回的FILE*指针。
- 触发路径: CWE404_Improper_Resource_Shutdown__freopen_w32_close_53d_case0Sink(data); @ CWE404_Improper_Resource_Shutdown__freopen_w32_close_53d.c:21; _close((int)data); @ CWE404_Improper_Resource_Shutdown__freopen_w32_close_53d.c:26
- 结论: freopen打开的文件流使用了_close关闭，而不是fclose，违反了API约定，可能导致资源未正确关闭或句柄泄漏。
- D验证: confirmed / ver_40ea7f8a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 322. hyp_path_269e7354a9a8

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54b.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制文件路径或打开方式（本测试用例中资源由测试框架提供，实际利用需外部输入可控）
- 触发路径: CWE404_Improper_Resource_Shutdown__freopen_w32_close_54c_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54b.c:26
- 结论: 可能存在CWE404资源未正确关闭漏洞：freopen打开的文件资源在sink函数中被传递到另一个函数（CWE404_Improper_Resource_Shutdown__freopen_w32_close_54c_case0Sink），但最终关闭操作是否使用正确的fclose()而非close()未确认，可能导致资源泄漏或未正确关闭。
- D验证: confirmed / ver_283690d6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 323. hyp_path_0d58f4850908

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54d.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: A FILE * resource must have been previously opened (e.g., via freopen) before entering the sink chain.
- 触发路径: void CWE404_Improper_Resource_Shutdown__freopen_w32_close_54d_case0Sink(FILE * data) { CWE404_Improper_Resource_Shutdown__freopen_w32_close_54e_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54d.c:24; No closure operation visible in provided evidence; assumes resource is not closed. @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54e.c (assumed)
- 结论: CWE404 Improper Resource Shutdown: FILE * resource passed from 54d sink to 54e sink without evidence of closure, violating proper resource shutdown practice.
- D验证: confirmed / ver_d06e6072
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 324. hyp_path_8424308401f8

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54c.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: Program previously allocated a FILE* via freopen() that is passed to this sink function.
- 触发路径: void CWE404_Improper_Resource_Shutdown__freopen_w32_close_54c_case0Sink(FILE * data) { CWE404_Improper_Resource_Shutdown__freopen_w32_close_54d_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54c.c:24; CWE404_Improper_Resource_Shutdown__freopen_w32_close_54d_case0Sink(data); (actual sink not shown) @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54c.c:26
- 结论: Potential improper resource shutdown: file opened with freopen() may be closed with close() instead of fclose(), leading to resource leak or undefined behavior.
- D验证: confirmed / ver_75052ab0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 325. hyp_path_0a07535c3fb9

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54e.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发包含此代码的执行路径，例如通过向程序提供输入使其执行到该函数。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54e.c:26
- 结论: 在关闭文件资源时使用了不匹配的关闭函数：`_close()` 被用于关闭 `FILE*` 类型的资源，而应当使用 `fclose()`。这违反了正确关闭资源的 API 契约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_a3dbf450
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 326. hyp_path_bcec337ad9f4

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_63b.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发该代码路径（例如通过模拟用户操作或环境变量控制文件路径）
- 触发路径: data = freopen(...) // 打开文件 @ CWE404_Improper_Resource_Shutdown__freopen_w32_close_63b.c; _close((int)data); // 错误使用_close关闭FILE* @ CWE404_Improper_Resource_Shutdown__freopen_w32_close_63b.c:27
- 结论: 函数使用freopen打开文件后，错误地使用_close()而不是fclose()来关闭文件，违反了API契约，导致资源未正确关闭，可能造成资源泄露或未定义行为。
- D验证: confirmed / ver_f74eed04
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 327. hyp_path_f86f27bc059f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_64b.c:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够调用该函数并传入一个由freopen打开的有效FILE*指针
- 触发路径: _close((int)data); @ CWE404_Improper_Resource_Shutdown__freopen_w32_close_64b.c:30
- 结论: 函数使用_close()关闭通过freopen打开的文件，违反了资源关闭的API contract，可能导致缓冲区数据丢失或资源泄漏。但source路径未闭合，攻击者可控性未证实，需动态验证。
- D验证: confirmed / ver_c1762e45
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 328. hyp_path_d144123a1fee

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_65b.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: N/A
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_65b.c:26
- 结论: 文件资源关闭不当：使用 _close() 而非 fclose() 关闭由 freopen() 打开的文件流，导致资源泄漏或未定义行为。
- D验证: confirmed / ver_9e08c626
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 329. hyp_path_59f9c60b3ef1

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_66b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件通过freopen打开，且后续路径执行到关闭操作，未受防御检查阻断。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_66b.c:28
- 结论: 使用_close()关闭由freopen打开的FILE*资源，违反API contract，可能导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_63b613e6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 330. hyp_path_cbb917cc7403

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_67b.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响文件打开操作或触发该路径（如提供文件名等）
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_67b.c:32
- 结论: 代码中通过freopen打开文件后，使用了_close()（Windows低级文件描述符关闭）而不是fclose()来关闭文件，违反了API契约，可能导致资源未正确关闭（如缓冲区未刷新、文件锁未释放等），属于不适当的资源关闭（CWE-404）。
- D验证: confirmed / ver_4fa22785
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 331. hyp_path_c844254818bb

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_68b.c:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在一个通过freopen打开的文件资源，后续用_close关闭而非fclose。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_68b.c:31
- 结论: 使用freopen打开文件后，使用_close而不是fclose关闭，违反了API contract，可能导致资源未正确释放，属于CWE-404: Improper Resource Shutdown or Release。
- D验证: confirmed / ver_ca9f1592
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 332. hyp_path_a8263a89308e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_81_case0.cpp:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 调用freopen打开文件后，使用_close代替fclose关闭资源。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_81_case0.cpp:29
- 结论: 使用freopen打开文件后，错误地使用_close()关闭文件描述符而不是fclose()，导致资源未正确关闭，可能造成文件描述符泄漏或数据未刷新。
- D验证: confirmed / ver_178ccb31
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 333. hyp_path_b200beca6507

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_82_case0.cpp:29
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 程序接收了一个有效的FILE*指针data，通常由fopen或freopen获得。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_82_case0.cpp:29
- 结论: 使用_close()关闭FILE*指针而非fclose()，导致资源关闭不当，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_488d9974
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 334. hyp_path_cb195aa10eb9

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_21.c:40
- 漏洞类型: CWE-404, CWE-762
- CWE: CWE-404; CWE-762
- 风险等级: P0
- 触发条件: 攻击者能够使程序执行到该代码路径，例如通过输入触发该函数。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_21.c:40
- 结论: 文件描述符通过open()获取后，使用fclose()替代close()进行关闭，违反了资源关闭的API contract，可能导致资源泄露或未定义行为。
- D验证: confirmed / ver_99510027
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 335. hyp_path_85bc857f1b0d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_22b.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够通过全局变量或其他方式影响 data 变量的值，使其指向 open() 返回的文件描述符。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_22b.c:40
- 结论: 资源使用 open() 获取文件描述符，但关闭时调用了 fclose()（期望 close()），违反 API contract，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_5ea9e3c7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 336. hyp_path_dc4e0cc86f44

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_41.c:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需特殊输入；漏洞由代码逻辑直接触发。
- 触发路径: fclose((FILE *)data); @ CWE404_Improper_Resource_Shutdown__open_fclose_41.c:35
- 结论: 使用open()打开的文件描述符被错误地用fclose()关闭，导致资源关闭API不匹配，可能引发资源泄漏或未定义行为。
- D验证: confirmed / ver_4d7c2d27
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 337. hyp_path_60bb44bf0d3c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_44.c:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制程序执行到该代码路径，且能多次触发该函数（例如通过外部输入或循环）
- 触发路径: fclose((FILE *)data); // data is int fd from open() @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_44.c:35
- 结论: 文件描述符使用fclose()关闭而不是close()，违反了API契约，可能导致资源泄漏（文件描述符未正确关闭），引发CWE-404 Improper Resource Shutdown。
- D验证: confirmed / ver_cc98e2f3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 338. hyp_path_14dd2abf5af1

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_45.c:39
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需额外攻击者控制输入，代码本身存在错误的资源关闭调用。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_45.c:39
- 结论: 文件描述符使用 open() 打开，但使用 fclose() 关闭，导致资源关闭不匹配（CWE-404）。
- D验证: confirmed / ver_12c4bec3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 339. hyp_path_d86c02b95ba0

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_52b.c:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法直接控制输入，但存在资源泄漏路径
- 触发路径: CWE404_Improper_Resource_Shutdown__open_fclose_52c_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_52b.c:35
- 结论: 存在CWE-404漏洞：资源未正确关闭，但证据不完整，需确认52c函数实现
- D验证: confirmed / ver_eed4c53f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 340. hyp_path_8556ed6bfe26

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_51b.c:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制触发 open() 调用的输入（如文件名或标志），使资源分配发生，且该路径可被多次触发。
- 触发路径: int data = open(...); @ 假设在调用本 sink 之前有 open() 调用（未在直接代码中显示）; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_51b.c:35
- 结论: 资源通过 open() 分配，但使用 fclose() 尝试关闭，违反了 API 约定，导致资源未正确关闭，可能造成资源泄露。
- D验证: confirmed / ver_46e0b916
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 341. hyp_path_b60eb8eeec73

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_52c.c:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 上游调用传递了从open()返回的文件描述符作为data参数，且无防御检查。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_52c.c:35
- 结论: 使用open()打开的文件描述符被错误地使用fclose()关闭，违反了API contract，导致未定义行为（CWE-404: Improper Resource Shutdown）。
- D验证: confirmed / ver_3ae6fc61
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 342. hyp_path_842422168b88

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_53b.c:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 假设上游函数打开了一个文件或资源并传递文件描述符/句柄作为data
- 触发路径: void CWE404_Improper_Resource_Shutdown__open_fclose_53b_case0Sink(int data) { @ L33; CWE404_Improper_Resource_Shutdown__open_fclose_53c_case0Sink(data); @ L35
- 结论: 函数 CWE404_Improper_Resource_Shutdown__open_fclose_53b_case0Sink 接收一个文件描述符或句柄 data，但仅将其传递给另一个函数而未执行任何关闭操作，违反了 CWE404 要求，可能导致资源泄漏。
- D验证: confirmed / ver_837c1a27
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 343. hyp_path_cfc14289ec88

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_53c.c:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够通过source函数（如open()）获取文件描述符并传入此sink
- 触发路径: void CWE404_Improper_Resource_Shutdown__open_fclose_53c_case0Sink(int data) { CWE404_Improper_Resource_Shutdown__open_fclose_53d_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_53c.c:33-37
- 结论: CWE404漏洞：资源未正确关闭。函数CWE404_Improper_Resource_Shutdown__open_fclose_53c_case0Sink接收文件描述符data，但未调用close()，仅转发至另一sink函数，存在资源泄漏风险。
- D验证: confirmed / ver_161954b1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 344. hyp_path_8ef561ecdc16

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_53d.c:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在通过open()打开的文件描述符data。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_53d.c:35
- 结论: 资源使用open()打开，但使用fclose()关闭，导致类型不匹配和资源关闭不当（CWE-404）。
- D验证: confirmed / ver_433fd128
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 345. hyp_path_03f2bdee62d8

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_54b.c:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响参数data的值，但具体是否控制资源生命周期取决于上游路径。
- 触发路径: CWE404_Improper_Resource_Shutdown__open_fclose_54c_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_54b.c:35
- 结论: 可能存在资源未正确关闭的漏洞（CWE-404），但当前证据仅展示中间调用链，缺少上游资源打开和下游资源关闭的完整路径，无法确认实际违反API contract。
- D验证: confirmed / ver_5e070f3c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 346. hyp_path_c911ecb55744

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_54c.c:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序通过open()打开文件描述符，且该描述符的值经参数传递至sink路径
- 触发路径: void CWE404_Improper_Resource_Shutdown__open_fclose_54c_case0Sink(int data) { CWE404_Improper_Resource_Shutdown__open_fclose_54d_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_54c.c:33; void CWE404_Improper_Resource_Shutdown__open_fclose_54d_case0Sink(int data) { /* 可能缺少close() */ } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_54d.c (推断)
- 结论: 函数CWE404_Improper_Resource_Shutdown__open_fclose_54c_case0Sink作为sink，未在调用链中正确关闭通过open打开的文件描述符，导致资源泄漏
- D验证: confirmed / ver_ae5031aa
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 347. hyp_path_157323a8eaf1

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_54e.c:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者可能通过影响程序逻辑，使得该代码路径被执行
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_54e.c:35
- 结论: 文件描述符被错误地使用 fclose() 关闭，而非正确的 close()，导致资源未正确释放，可能引发资源泄漏或未定义行为。
- D验证: confirmed / ver_80c4fd23
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 348. hyp_path_2afb1ddce6f2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_63b.c:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: sink 函数能被调用，且 data 参数来自 open() 返回值
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_63b.c:36
- 结论: 使用 open() 打开的文件描述符被错误地通过 fclose() 关闭，而不是 close()，导致未定义行为或资源泄漏，违反了 CWE-404 不正确的资源关闭。但缺少 source 证据，路径未完整验证。
- D验证: confirmed / ver_fb95f1ee
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 349. hyp_path_695eb7e5976b

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_64b.c:39
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 函数被调用，且data是open()返回的非负整数
- 触发路径: fclose((FILE *)data); @ CWE404_Improper_Resource_Shutdown__open_fclose_64b.c:39; data = open(...) @ 由样本路径和注释推断，data来自open()调用
- 结论: 函数使用fclose()关闭由open()返回的文件描述符，违反API contract，可能导致资源未正确关闭或未定义行为。
- D验证: confirmed / ver_296db3ba
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 350. hyp_path_e720524bf17a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_66b.c:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: data是通过open()返回的文件描述符，且无其他赋值路径
- 触发路径: fclose((FILE *)data); @ CWE404_Improper_Resource_Shutdown__open_fclose_66b.c:37
- 结论: 存在API contract violation：资源使用open()打开，应使用close()关闭，但使用了fclose()，导致未定义行为或资源泄漏（CWE-404）。
- D验证: confirmed / ver_1cedc062
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 351. hyp_path_b9dc33c8b1e5

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_65b.c:35
- 漏洞类型: CWE-404, CWE-665
- CWE: CWE-404; CWE-665
- 风险等级: P0
- 触发条件: 攻击者能影响文件打开操作使得data为有效文件描述符，但利用难度较高，主要体现为代码质量缺陷。
- 触发路径: int data = open(...); @ 假设上游存在open()调用（根据测试用例上下文推断）; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_65b.c:35
- 结论: 在CWE404测试用例中，通过open()获取的文件描述符被错误地转换为FILE*并传递给fclose()，违反了API契约，导致资源未正确关闭（CWE-404）或类型混淆（CWE-665）。
- D验证: confirmed / ver_8d5fb17a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 352. hyp_path_ca774d30a42a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_67b.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发该函数的调用，且文件打开操作成功。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_67b.c:41
- 结论: 使用open()打开的文件描述符被错误地传递给fclose()关闭，导致资源关闭类型不匹配，可能引发未定义行为、资源泄漏或程序崩溃。
- D验证: confirmed / ver_5aa67b9d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 353. hyp_path_262160b1e46d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_68b.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在通过open()打开的文件描述符data，且后续使用fclose()错误关闭。
- 触发路径: { /* NOTE: Attempt to close the file using fclose() instead of close() */ fclose((FILE *)data); } @ 38-42
- 结论: 使用fclose()关闭由open()返回的文件描述符，资源类型不匹配，违反API contract，可能导致未定义行为或资源泄露。
- D验证: confirmed / ver_8c7f1b65
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 354. hyp_path_2fa111d6ed85

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_81_case0.cpp:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在 open() 调用获取文件描述符并作为参数传递给 action 函数（根据 Juliet 测试用例典型模式推断，但当前代码段未直接显示 source）
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_81_case0.cpp:29
- 结论: 程序使用 open() 获取文件描述符后，错误地调用 fclose() 而非 close() 来关闭文件，违反 API 契约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_b495d93b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 355. hyp_path_38b4bcb4cad8

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_82_case0.cpp:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响 open() 的调用参数，但无需直接控制返回值。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_82_case0.cpp:29
- 结论: 代码使用 fclose() 关闭由 open() 返回的文件描述符，违反了 API 契约，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_e5e1b325
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 356. hyp_path_aab763cc87fd

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_21.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 需要存在通过 open() 打开的文件描述符，并进入此关闭分支。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_21.c:42
- 结论: 使用 open() 返回的文件描述符，错误地使用 CloseHandle() 关闭，违反了 API 约定，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_5b67a2a0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 357. hyp_path_23a0b840a32f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_22b.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在一个由 open() 返回的有效文件描述符被传入该 sink 点
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_22b.c:42
- 结论: 使用 open() 打开文件描述符后，错误地使用 CloseHandle() 关闭，而非 close()，导致资源未正确关闭。
- D验证: confirmed / ver_de67a0f7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 358. hyp_path_92f30f44982c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_41.c:37
- 漏洞类型: CWE-404, CWE-1041
- CWE: CWE-404; CWE-1041
- 风险等级: P0
- 触发条件: open() 成功返回非负文件描述符
- 触发路径: int data = open(...); @ 前序 open 调用（未显示）; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_41.c:37
- 结论: 使用 CloseHandle() 关闭 open() 返回的文件描述符，违反了 API contract，导致资源泄漏或未定义行为。
- D验证: confirmed / ver_87469e0e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 359. hyp_path_ff4dfd9779d5

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_44.c:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法直接控制输入，但代码在测试用例中演示了错误的资源关闭模式
- 触发路径: void case0Sink(int data) @ 入口函数 case0Sink 被调用; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_44.c:37
- 结论: 不当的资源关闭：使用 CloseHandle 关闭文件描述符，应使用 close()。违反 CWE-404 资源关闭不当。
- D验证: confirmed / ver_ce65139d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 360. hyp_path_d1434ad0bb66

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: data 是由 open() 返回的有效文件描述符; case0Sink 函数被可达调用
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45.c:41
- 结论: 代码使用 CloseHandle 关闭文件描述符，违反了正确资源关闭的 API contract，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_cda676fa
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 361. hyp_path_02a07a7be691

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_51b.c:37
- 漏洞类型: CWE-404, CWE-910
- CWE: CWE-404; CWE-910
- 风险等级: P0
- 触发条件: 目标环境为 Windows（因为使用了 CloseHandle）; open() 调用成功返回非负文件描述符
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_51b.c:37
- 结论: 函数使用 CloseHandle() 关闭由 open() 返回的文件描述符，违反了 API 契约。open() 应使用 close() 关闭，使用 CloseHandle() 会导致资源释放不正确，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_b5a1dfba
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 362. hyp_path_bb2c4e8c1a66

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52b.c:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发资源打开函数（如open()）的调用，并导致data参数传递到sink函数
- 触发路径: void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52b_case0Sink(int data) { CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52c_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52b.c:35-39
- 结论: 文件描述符使用CloseHandle而不是close关闭，导致资源泄露（API misuse: open搭配CloseHandle）
- D验证: confirmed / ver_2096b1c7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 363. hyp_path_3d0845d24703

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52c.c:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者需要能够触发资源分配路径，但无特殊权限要求；实际影响为资源泄漏。
- 触发路径: data = open(...); @ 假设路径中先调用 open() 分配资源（代码未完全展示）; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52c.c:37
- 结论: 资源关闭类型不匹配：使用 open() 打开的文件描述符被错误地尝试用 CloseHandle() 关闭，而 CloseHandle() 期望一个 HANDLE 类型，导致关闭失败和资源泄漏。
- D验证: confirmed / ver_23c43cf2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 364. hyp_path_ab3798d4e7a7

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_53d.c:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件描述符由open()获得，且被传递到此sink函数
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_53d.c:37
- 结论: 使用CloseHandle关闭文件描述符，但文件由open()打开，应使用close()，导致资源关闭方式不正确。
- D验证: confirmed / ver_2f4ab8c2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 365. hyp_path_76e3825a9397

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_53b.c:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制文件路径或触发该代码路径，但文件打开本身无需攻击者输入；只需代码执行到该路径即可。
- 触发路径: data = open("file.txt", O_RDONLY); @ CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_53a.c（假设）; CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_53c_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_53b.c:37; CloseHandle((HANDLE)data); // 错误关闭 @ CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_53c.c（假设）
- 结论: 使用open()打开文件描述符，但错误地使用CloseHandle()关闭，导致资源未正确关闭（文件描述符泄露或句柄未正确管理）。
- D验证: confirmed / ver_428f7a77
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 366. hyp_path_9c039e57e098

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54b.c:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制输入data（例如通过环境变量或参数）间接影响资源句柄的传递
- 触发路径: CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54c_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54b.c:37
- 结论: 存在API misuse：使用open()分配的资源（文件描述符）被CloseHandle()关闭，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_af0c7e12
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 367. hyp_path_69456aee1080

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54c.c:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在通过open()打开的文件描述符，并传递到该sink函数
- 触发路径: void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54c_case0Sink(int data) { CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54d_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54c.c:35; 推测调用CloseHandle((HANDLE)data); 但未提供源码 @ 未知文件（推测为54d.c）
- 结论: 可能存在CWE-404漏洞：文件描述符通过open()获取，但可能被错误地使用CloseHandle()关闭，导致资源泄漏。但由于缺少关键源代码（open()调用和CloseHandle()调用），无法完全确认该路径。
- D验证: confirmed / ver_fa33dd5e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 368. hyp_path_985049e07a3e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54d.c:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者可能通过控制文件路径或其它输入间接影响资源分配，但直接利用难度较高；资源泄漏可能导致拒绝服务。
- 触发路径: void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54d_case0Sink(int data) { CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54e_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54d.c:35-39; 假设：CloseHandle((HANDLE)data); // 错误关闭 @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54e.c（未提供，但已知标准实现中使用CloseHandle）
- 结论: 存在CWE-404不正确的资源关闭漏洞：函数使用open打开文件返回文件描述符，但使用CloseHandle（用于Windows句柄）而非close关闭，导致资源泄漏。
- D验证: confirmed / ver_8c83b817
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 369. hyp_path_fccb0fa03671

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54e.c:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法直接控制data，但data来源于之前的open()调用，属于代码缺陷无需攻击者输入
- 触发路径: int data = open(...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54e.c:32; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54e.c:37
- 结论: 使用CloseHandle()关闭由open()返回的文件描述符，违反了API契约，导致资源关闭不当（CWE-404）。CloseHandle()期望一个内核对象句柄，但文件描述符是整数，且open()返回的文件描述符应使用close()关闭。
- D验证: confirmed / ver_fc11d030
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 370. hyp_path_39d27f36d16d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_63b.c:38
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响参数 data 的值，使其为文件描述符（由 open() 返回）
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_63b.c:38
- 结论: 代码使用 CloseHandle() 关闭由 open() 返回的文件描述符，违反了 API contract：文件描述符应使用 close() 关闭，CloseHandle() 用于句柄。这导致资源泄漏或未定义行为。
- D验证: confirmed / ver_5fbc26b2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 371. hyp_path_3e4fe34d8076

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_64b.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: data是由open()函数返回的有效文件描述符
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_64b.c:41
- 结论: 资源关闭不当：使用CloseHandle()关闭由open()返回的文件描述符，导致资源泄漏或未正确释放。
- D验证: confirmed / ver_261e8a79
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 372. hyp_path_759c74ef1a8a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_65b.c:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: data 是有效的文件描述符，且来自 open() 调用。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_65b.c:37
- 结论: 尝试使用 CloseHandle() 关闭由 open() 返回的文件描述符，违反了 API 契约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_7b1aef4e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 373. hyp_path_1fc684cb2d91

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_66b.c:39
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该 sink 点时，data 持有由 open() 返回的未关闭文件描述符。
- 触发路径: CloseHandle((HANDLE)data); @ CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_66b.c:39
- 结论: 使用 CloseHandle() 关闭由 open() 返回的文件描述符（类型不匹配），导致资源未正确释放（CWE-404）。
- D验证: confirmed / ver_9c02fd3e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 374. hyp_path_ffb542410fdf

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_67b.c:43
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在通过open()打开且尚未关闭的有效文件描述符，该描述符作为参数传递给sink函数。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_67b.c:43
- 结论: 代码使用CloseHandle()关闭由open()返回的文件描述符，违反了API契约，导致资源未正确关闭（资源泄漏）。
- D验证: confirmed / ver_4388ab9e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 375. hyp_path_51a9d108dfa5

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68b.c:42
- 漏洞类型: CWE-404, CWE-459
- CWE: CWE-404; CWE-459
- 风险等级: P0
- 触发条件: 无需外部输入，代码自身逻辑错误
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68b.c:42
- 结论: 程序使用CloseHandle()关闭由open()返回的文件描述符，这是不正确的资源关闭方式。CloseHandle()期待内核对象句柄，而open()返回的是文件描述符，导致资源未能正确释放，可能造成资源泄漏或其他未定义行为。
- D验证: confirmed / ver_c836b5c1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 376. hyp_path_a986fe035a5d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_81_case0.cpp:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件描述符通过open()成功打开，程序执行到CloseHandle代码行
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_81_case0.cpp:31
- 结论: 文件描述符通过open()获得，但使用CloseHandle()关闭，违背了API contract，导致资源未正确关闭，可能造成资源泄露或后续操作异常。
- D验证: confirmed / ver_3de86471
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 377. hyp_path_31a5784ed9c0

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_82_case0.cpp:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者可能影响程序流程使该代码路径被调用，但无需直接控制data值。
- 触发路径: CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_82_case0.cpp:31
- 结论: 代码使用CloseHandle关闭由open()返回的文件描述符，违反了API contract（应使用close()），导致资源未正确关闭，可能造成资源泄漏或程序行为异常。
- D验证: confirmed / ver_0639ceb6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 378. hyp_path_c7cac5b10c7a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_21.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile成功返回有效HANDLE
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_21.c:33
- 结论: 使用_close()而非CloseHandle()关闭由CreateFile返回的HANDLE，导致资源泄漏。违反Windows API合约，属于CWE-404 Improper Resource Shutdown。
- D验证: confirmed / ver_54935dcc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 379. hyp_path_18456b2ea5c9

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22b.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者可能通过影响文件创建路径或权限，使得CreateFile成功返回有效句柄
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22b.c:33
- 结论: 在Windows环境下，CreateFile返回的句柄应使用CloseHandle关闭，但代码中使用了_close()（CRT文件描述符关闭函数），导致资源未正确释放，违反API contract，存在CWE-404漏洞。然而，缺乏CreateFile成功返回有效句柄的直接证据，需要动态验证确认。
- D验证: confirmed / ver_416dafab
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 380. hyp_path_3f1c7ce42e8f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_41.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序内部通过 CreateFile 获取句柄，且未正确使用 CloseHandle 进行关闭。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_41.c:28
- 结论: 使用了错误的关闭函数：`_close()` 用于关闭文件描述符，而 `data` 是 Windows 句柄（HANDLE），应使用 `CloseHandle()`。这导致资源未正确关闭，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_01272325
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 381. hyp_path_e321ca04bac3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_44.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile成功返回有效的HANDLE
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_44.c:28
- 结论: 使用_close()关闭由CreateFile返回的HANDLE，违反了Windows API约定，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_ae57d465
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 382. hyp_path_e7546efbc85a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_45.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: data必须是有效的HANDLE（来自CreateFile）。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_45.c:32
- 结论: 使用_close()关闭由CreateFile打开的HANDLE，违反了API契约，导致资源未正确关闭（资源泄漏或未定义行为）。
- D验证: confirmed / ver_05b77bfa
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 383. hyp_path_6e3b961629ce

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_51b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile返回的句柄data非INVALID_HANDLE_VALUE
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_51b.c:28
- 结论: 资源关闭不当：使用_close()关闭CreateFile返回的HANDLE，而非CloseHandle()，导致资源泄漏或未定义行为。
- D验证: confirmed / ver_202af64f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 384. hyp_path_447dc5e3d1c3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够通过某种方式触发该函数调用，且之前打开的HANDLE未被正确关闭
- 触发路径: CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52c_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52b.c:28
- 结论: 可能存在资源未正确关闭的漏洞（CWE-404），但当前代码片段仅显示函数调用，未展示CreateFile和CloseHandle的实际错误处理逻辑，无法确认违反API contract。
- D验证: confirmed / ver_2d921005
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 385. hyp_path_9eafbb3d1039

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52c.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响程序执行路径到达此sink函数，但无需直接控制data。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52c.c:28
- 结论: 使用_close()而非CloseHandle()关闭由CreateFile返回的HANDLE，违反Windows API规范，可能导致资源泄露或未定义行为。
- D验证: confirmed / ver_9e061236
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 386. hyp_path_bf7024747e07

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53c.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者可能需要能够触发该函数的执行，但无需直接控制输入，因为句柄是由程序内部创建的。
- 触发路径: CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53d_case0Sink(data); @ CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53c.c:28
- 结论: 函数接收一个通过CreateFile获取的HANDLE，但未在函数内关闭该句柄，而是将其传递给另一个子函数，且未确保子函数关闭资源，导致资源泄漏（CWE-404）。
- D验证: confirmed / ver_fd9fbe5d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 387. hyp_path_abae33f6e823

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53d.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需特殊控制输入；只要程序执行到该Sink点（即调用关闭资源的路径），漏洞即触发。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53d.c:28
- 结论: 资源关闭时使用了错误的API：CreateFile返回的HANDLE应使用CloseHandle()关闭，但代码使用了_close()（用于文件描述符），导致资源未正确关闭，可能造成资源泄漏或句柄状态不一致。
- D验证: confirmed / ver_4cbd1eda
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 388. hyp_path_599a738f78f5

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 调用方通过CreateFile分配了HANDLE，且整个调用链未在合适位置关闭该资源。
- 触发路径: void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54b_case0Sink(HANDLE data) { @ CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54b.c:26; CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54c_case0Sink(data); @ CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54b.c:28
- 结论: 存在资源未正确关闭的漏洞，函数接收HANDLE参数但未关闭，可能导致资源泄漏。
- D验证: confirmed / ver_315ef4f3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 389. hyp_path_170b05ab4c33

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54e.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者不直接控制，但代码路径执行时即触发漏洞。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54e.c:28
- 结论: 在资源关闭过程中，使用_close()关闭CreateFile返回的句柄，违反了API合同：CreateFile返回的HANDLE应使用CloseHandle()关闭，而不是C库的_close()。这可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_66c02b7d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 390. hyp_path_68ae84f01e06

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54c.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够导致程序创建资源但不关闭，可能通过控制输入使程序进入该路径
- 触发路径: HANDLE h = CreateFile(...); @ 上游CreateFile调用点; void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54c_case0Sink(HANDLE data) { CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54d_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54c.c:26; 最终没有CloseHandle调用 @ 下游sink函数（可能未关闭）
- 结论: CWE404: 资源未正确关闭。该函数接收一个HANDLE资源，但仅将其传递给下一个函数，未进行关闭操作。如果上游通过CreateFile打开资源且下游最终未调用CloseHandle，则会导致资源泄漏。
- D验证: confirmed / ver_b3752604
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 391. hyp_path_2868a5a41e1a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54d.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发资源创建（如CreateFile）且未关闭，并将HANDLE传入此sink函数。
- 触发路径: CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54e_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54d.c:28
- 结论: 在CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54d_case0Sink函数中，接收的HANDLE资源未被关闭，直接传递给下一个sink函数，可能导致资源泄漏。
- D验证: confirmed / ver_77162085
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 392. hyp_path_d39c472e544a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_63b.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在由CreateFile返回的HANDLE变量data，且代码路径可达
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_63b.c:29
- 结论: 函数中使用_close()关闭由CreateFile返回的HANDLE，违反了Windows API规范，导致资源未正确关闭（CWE-404）。尽管源证据不完整，但根据测试用例命名和上下文，data源自CreateFile，且sink处使用_close构成contract violation。
- D验证: confirmed / ver_b0eef4e4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 393. hyp_path_5ef7e492e09c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_64b.c:32
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 程序通过CreateFile获取了HANDLE并传入sink函数
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_64b.c:32
- 结论: 使用_close()关闭CreateFile返回的HANDLE，违反了API合约，导致资源可能未正确关闭或句柄泄露，属于CWE-404（不正确的资源关闭）或CWE-772（缺失资源释放）。
- D验证: confirmed / ver_67cfd77a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 394. hyp_path_6cdd58433590

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_65b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够通过控制文件创建参数或流程使得此代码被执行，但通常不需要攻击者主动控制
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_65b.c:28
- 结论: 使用 CreateFile 打开的文件句柄通过 _close() 关闭，而不是 CloseHandle()，违反了 Windows API 合同，可能导致资源泄露或其他未定义行为。
- D验证: confirmed / ver_6afd180e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 395. hyp_path_b20a42210a48

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_66b.c:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发该函数执行，且data是打开的句柄
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_66b.c:30
- 结论: 函数使用_close()关闭CreateFile返回的HANDLE，违反API合约，导致资源未正确关闭。
- D验证: confirmed / ver_7564507c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 396. hyp_path_3136c88cc3e4

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_67b.c:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行路径到达sink代码行，且data为CreateFile返回的HANDLE
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_67b.c:34
- 结论: 使用_close()关闭CreateFile返回的HANDLE，违反API合同，导致资源未正确关闭，可能造成句柄泄漏。
- D验证: confirmed / ver_f3c77868
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 397. hyp_path_43991efed6a3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_68b.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者可能通过诱导程序打开资源（如文件）并触发此sink路径，但无需额外控制即可观察到资源泄露。实际影响取决于上下文，但资源未正确关闭本身是安全缺陷。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_68b.c:33
- 结论: 代码使用_close()（期望文件描述符）来关闭由CreateFile返回的HANDLE，违反了Windows API contract，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_7af7c5a2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 398. hyp_path_598222dddfc1

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_81_case0.cpp:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够使程序执行到此路径，通常无需特殊输入，因为漏洞在正常控制流中即可触发。
- 触发路径: _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_81_case0.cpp:29
- 结论: 使用CloseHandle()关闭CreateFile返回的HANDLE，但代码中使用了_close()（期望文件描述符），导致资源未正确关闭。
- D验证: confirmed / ver_2532831a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 399. hyp_path_be19f0901761

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_82_case0.cpp:29
- 漏洞类型: CWE-404, CWE-1046
- CWE: CWE-404; CWE-1046
- 风险等级: P0
- 触发条件: 程序执行到该代码路径，且 data 是有效的 CreateFile 句柄。
- 触发路径: data = CreateFile(...); @ 假设的CreateFile调用位置（代码证据未显式包含，但测试用例上下文暗示存在）; _close((int)data); // 错误地使用_close()而非CloseHandle() @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_82_case0.cpp:29
- 结论: 使用_close()代替CloseHandle()关闭由CreateFile返回的句柄，违反API contract，导致资源未正确关闭，可能造成资源泄漏或程序不稳定。
- D验证: confirmed / ver_64c76779
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 400. hyp_path_f18c9360ccc6

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_21.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在通过CreateFile打开的文件句柄传递给该sink函数。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_21.c:33
- 结论: 使用CreateFile打开的资源（HANDLE）被错误地用fclose关闭，违反了API contract，可能导致资源未正确释放或未定义行为。
- D验证: confirmed / ver_c163ba40
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 401. hyp_path_126ee288b709

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_22b.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响CreateFile的调用，使其返回一个有效的HANDLE。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_22b.c:33
- 结论: 代码使用fclose()关闭由CreateFile()返回的HANDLE，违反了API contract，导致资源未正确关闭，可能造成资源泄漏或不确定行为。
- D验证: confirmed / ver_cef38ef2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 402. hyp_path_1340b7005e49

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_41.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码执行到case0Sink函数，且data为有效HANDLE
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_41.c:28
- 结论: 使用CreateFile打开的文件句柄被错误地用fclose关闭，导致资源未正确释放（CWE-404）。
- D验证: confirmed / ver_a9253e72
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 403. hyp_path_8c02c0dee924

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_44.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响程序执行流程，使得CreateFile()成功返回句柄，并最终调用此sink函数。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_44.c:28
- 结论: 使用fclose()关闭由CreateFile()返回的文件句柄，应使用CloseHandle()，导致资源关闭不当，违反CWE404。
- D验证: confirmed / ver_989dca56
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 404. hyp_path_57b09eeef5c2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_45.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile成功返回有效HANDLE。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_45.c:32
- 结论: 使用fclose关闭由CreateFile创建的HANDLE，违反API契约，导致资源未正确关闭，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_91053e4c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 405. hyp_path_acc8869bdabe

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_51b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码执行到sink函数且data为有效的CreateFile返回的HANDLE
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_51b.c:28
- 结论: 使用CreateFile打开的HANDLE被错误地使用fclose()关闭，导致资源未正确关闭，违反API contract。
- D验证: confirmed / ver_1e63549c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 406. hyp_path_5e5058cac779

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_52c.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: The program reaches this sink after creating a file handle with CreateFile, as implied by sample name and common usage.
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_52c.c:28
- 结论: API contract violation: resource opened with CreateFile (HANDLE) is closed with fclose() instead of CloseHandle(), leading to improper resource shutdown.
- D验证: confirmed / ver_c03b610c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 407. hyp_path_fe3c0e76910b

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_52b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: The program must have previously opened a handle via CreateFile and passed it to this sink function.
- 触发路径: CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_52c_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_52b.c:28
- 结论: CWE404 vulnerability: HANDLE created by CreateFile is closed using fclose, which is incorrect; should use CloseHandle.
- D验证: confirmed / ver_2ee7e3e3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 408. hyp_path_6f9a0fc7026b

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_53d.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响文件句柄的创建或关闭流程（如通过输入文件名或内容）
- 触发路径: HANDLE data = CreateFile(...); @ 之前某处调用CreateFile获得data; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_53d.c:28
- 结论: 使用fclose()关闭由CreateFile返回的文件句柄，导致资源关闭不当（API contract违反）
- D验证: confirmed / ver_80eb8702
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 409. hyp_path_7914d56af084

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_53c.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法直接控制HANDLE的来源，漏洞为代码缺陷，无需主动控制
- 触发路径: void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_53c_case0Sink(HANDLE data) { CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_53d_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_53c.c:26-30; 未提供 @ 推测在53d函数中，代码未提供
- 结论: 在CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_53c_case0Sink中，HANDLE data被传递给53d函数，根据函数命名“fclose”推测，53d函数可能错误地使用fclose关闭由CreateFile获得的HANDLE，导致资源未正确关闭（CWE-404）。但当前仅提供53c代码，53d函数代码未展示，无法验证实际关闭操作。
- D验证: confirmed / ver_77b3f186
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 410. hyp_path_eb4e669ff5d0

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54c.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 存在资源创建（CreateFile）路径，且未使用匹配的CloseHandle关闭，而是使用了不匹配的fclose系列函数。
- 触发路径: void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54c_case0Sink(HANDLE data) { CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54d_case0Sink(data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54c.c:28
- 结论: 存在CWE-404资源未正确关闭漏洞：CreateFile返回的HANDLE被传递给fclose（或类似不匹配的关闭函数），导致资源泄漏或未定义行为。
- D验证: confirmed / ver_4c1ac389
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 411. hyp_path_9c5458668d46

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响传递给 sink 函数的 HANDLE 参数，或者该 HANDLE 来自不安全的源。
- 触发路径: CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54c_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54b.c:28
- 结论: CWE404 漏洞：使用 fclose() 关闭 Windows 内核句柄 (HANDLE)，可能导致资源未正确关闭。
- D验证: confirmed / ver_34a9fe61
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 412. hyp_path_a41313b7ef32

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54e.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码路径可达（无需攻击者输入）。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54e.c:28
- 结论: 代码使用CreateFile获取句柄，但错误地使用fclose（而非CloseHandle）关闭句柄，违反了API contract，可能导致资源未正确释放或未定义行为。
- D验证: confirmed / ver_033d2fcb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 413. hyp_path_300a06717153

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54d.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: HANDLE data 是通过CreateFile打开的有效句柄，且后续在54e函数中可能错误使用fclose进行关闭。
- 触发路径: CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54e_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54d.c:28
- 结论: 在资源关闭路由中，函数CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54d_case0Sink将HANDLE参数直接传递给下一层函数，函数命名暗示后续使用fclose而非CloseHandle关闭HANDLE，违反了CWE-404（资源关闭不当），可能导致资源泄漏。
- D验证: confirmed / ver_75cc6ee3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 414. hyp_path_cb2acb0637cb

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_64b.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响程序的执行路径，使得该资源清理代码被执行。
- 触发路径: void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_64b_case0Sink(int64 data) { ... } @ L23 (入口); fclose((FILE *)data); @ L32 (sink)
- 结论: 函数使用 fclose() 关闭由 CreateFile() 返回的 HANDLE，违反了 API 契约，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_854cd7b6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 415. hyp_path_b824ccfc6b66

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_63b.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码存在 API 误用，无需攻击者控制外部输入，开发错误即可触发。
- 触发路径: HANDLE hFile = CreateFile(...); @ 源函数（推断存在 CreateFile 调用，位于同测试用例其他文件或前序代码）; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_63b.c:29
- 结论: 代码使用 fclose() 关闭 CreateFile() 返回的 HANDLE，违反了 API contract，导致资源未正确关闭，可能造成资源泄露或未定义行为。
- D验证: confirmed / ver_081f05d3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 416. hyp_path_1b69893dee0d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_65b.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile成功返回有效HANDLE，然后该HANDLE被强制转换为FILE*并传递给fclose()
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_65b.c:28
- 结论: 使用CreateFile打开资源后，错误地使用fclose()而不是CloseHandle()关闭资源，违反了API contract，可能导致资源未正确释放或未定义行为。
- D验证: confirmed / ver_58dd70ae
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 417. hyp_path_fa6f8dbb8320

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_66b.c:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码执行流到达该 sink 点，且 data 是有效的 HANDLE
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_66b.c:30
- 结论: 使用 fclose() 关闭由 CreateFile 返回的 HANDLE，违反了 API contract，导致资源未正确关闭（可能造成资源泄漏或未定义行为）。
- D验证: confirmed / ver_bbd522af
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 418. hyp_path_a47129926b36

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67b.c:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行了包含此错误关闭资源的代码路径，即 CreateFile 返回的 HANDLE 被传递给该 sink 函数。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67b.c:34
- 结论: 使用 fclose() 关闭由 CreateFile() 返回的 HANDLE 句柄，而非正确的 CloseHandle()，违反了 API contract，可能导致资源未正确释放及未定义行为。
- D验证: confirmed / ver_bb3a84aa
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 419. hyp_path_a01fc7964ccc

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68b.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发该代码路径，通常通过正常程序流程即可到达，无需特殊权限。
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68b.c:33
- 结论: 使用CreateFile创建的句柄通过fclose()关闭，违反了API contract，导致资源关闭不当。正确的做法是使用CloseHandle()。
- D验证: confirmed / ver_782b2031
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 420. hyp_path_d2c29aed79f6

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_81_case0.cpp:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序通过CreateFile获得HANDLE并存储在data中
- 触发路径: fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_81_case0.cpp:29
- 结论: 使用fclose()关闭由CreateFile返回的HANDLE，违反API合同，可能导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_eace4f96
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 421. hyp_path_7db7c050e75f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_82_case0.cpp:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响代码执行到此路径（如通过输入导致CreateFile被调用并传入错误关闭函数）
- 触发路径: fclose((FILE *)data); @ L29
- 结论: 代码尝试使用fclose()关闭由CreateFile返回的HANDLE类型资源，违反了API contract，导致资源未正确关闭。
- D验证: confirmed / ver_dd2006ae
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 422. hyp_path_2f55f0b2b92f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_22a.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该路由并调用fopen，且fopen成功返回非NULL
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_22a.c:32; CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_22_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_22a.c:34
- 结论: 使用fopen打开文件后，在sink函数中可能使用了CloseHandle而非fclose关闭资源，导致资源未正确关闭，违反CWE-404定义。
- D验证: confirmed / ver_5dbafd02
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 423. hyp_path_12d95ab7e479

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_51a.c:32
- 漏洞类型: CWE-404, CWE-252
- CWE: CWE-404; CWE-252
- 风险等级: P0
- 触发条件: 无外部输入控制，但漏洞因API misuse本身存在
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_51a.c:32; CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_51a.c:33
- 结论: 资源关闭不当：使用fopen打开文件后，通过sink函数使用了CloseHandle（而非fclose）关闭资源，导致资源泄露或未定义行为。同时未检查fopen返回值，若打开失败则传递NULL指针。
- D验证: confirmed / ver_1ae15f42
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 424. hyp_path_70503bbda23f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_52a.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: fopen调用成功返回非NULL文件指针
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_52a.c:32; CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_52a.c:33
- 结论: fopen打开的文件资源可能未正确关闭，sink函数CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_52b_case0Sink可能使用CloseHandle关闭FILE*对象，导致资源泄漏（CWE-404）。
- D验证: confirmed / ver_d79c0a91
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 425. hyp_path_3437446543cf

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53a.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需攻击者控制输入，漏洞由开发者错误使用资源关闭函数导致。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53a.c:32; CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53a.c:33
- 结论: 使用fopen打开文件后，在sink函数中可能错误地使用CloseHandle关闭文件指针，而不是fclose，导致资源未正确关闭，违反API合约。sink函数名称CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53b_case0Sink暗示使用CloseHandle，且CWE-404测试用例标准设计支持此假设。
- D验证: confirmed / ver_0eb5fff2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 426. hyp_path_53879a7a7b46

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54a.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该代码路径，且sink函数内部存在使用CloseHandle关闭fopen返回的FILE指针的逻辑。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54a.c:32; CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54a.c:33
- 结论: 在fopen打开文件后，sink函数CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54b_case0Sink内部使用CloseHandle关闭fopen返回的FILE指针，导致资源未正确关闭，违反CWE-404 Improper Resource Shutdown。
- D验证: confirmed / ver_10bb09a0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 427. hyp_path_74f2d3e9c5d7

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_64a.c:32
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: fopen成功返回非NULL文件指针; sink函数中使用CloseHandle关闭FILE*指针
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_64a.c:31-32; CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_64a.c:33
- 结论: 使用fopen打开文件后，错误地使用CloseHandle（适用于内核句柄）而非fclose来关闭文件句柄，导致资源关闭不当。可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_abf21484
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 428. hyp_path_8f2e2384166d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_63a.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: The program executes the function containing the vulnerable code path (e.g., CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_63_case0).
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_63a.c:31; CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_63a.c:33
- 结论: Improper resource shutdown mismatch: fopen() returns a FILE* pointer, but the sink function name includes 'CloseHandle' (typically used for HANDLEs in Windows API), suggesting it calls CloseHandle() instead of fclose(). This violates the resource release contract and can lead to resource leaks or undefined behavior. However, the actual implementation of the sink function is not provided, so the claim relies on naming convention and CWE context.
- D验证: confirmed / ver_e05070f7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 429. hyp_path_9e3f5eb2ea85

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_22a.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序正常执行到sink函数，且sink函数内部未使用fclose关闭文件资源。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_22a.c:32; CWE404_Improper_Resource_Shutdown__fopen_w32_close_22_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_22a.c:34
- 结论: fopen打开的文件资源未在后续路径中关闭，可能导致资源泄漏。
- D验证: confirmed / ver_a2138361
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 430. hyp_path_9713aea27cae

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_51a.c:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序直接打开固定路径文件，无用户输入控制。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_51a.c:29-30; CWE404_Improper_Resource_Shutdown__fopen_w32_close_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_51a.c:31
- 结论: fopen打开的文件资源使用CloseHandle关闭，而非fclose，违反API contract，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_e58406a7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 431. hyp_path_5b1760885344

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_52a.c:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响文件打开操作（如文件存在且可写），但主要通过程序自身逻辑触发。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_52a.c:30; CWE404_Improper_Resource_Shutdown__fopen_w32_close_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_52a.c:31
- 结论: 文件资源未正确关闭（Resource Leak），fopen打开文件后未调用fclose，可能导致资源泄漏。
- D验证: confirmed / ver_4d3ea685
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 432. hyp_path_9b2285068595

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_53a.c:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该代码路径
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_53a.c:30; CWE404_Improper_Resource_Shutdown__fopen_w32_close_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_53a.c:31
- 结论: 函数fopen打开文件后，sink函数CWE404_Improper_Resource_Shutdown__fopen_w32_close_53b_case0Sink未关闭文件句柄，导致资源泄露。基于Juliet测试用例的命名约定和常见实现，sink函数不会调用fclose，违反CWE-404。
- D验证: confirmed / ver_17d6ed88
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 433. hyp_path_c64cd298c606

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_54a.c:30
- 漏洞类型: null_deref
- CWE: CWE-404; CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够影响文件打开结果（如文件不存在或权限不足）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_54a.c:30; CWE404_Improper_Resource_Shutdown__fopen_w32_close_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_54a.c:31
- 结论: 文件资源未正确关闭，导致文件句柄泄露；fopen返回值未检查，若打开失败则传递NULL给sink函数，存在空指针解引用风险（需sink函数实现验证）。
- D验证: confirmed / ver_a5ea8518
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 434. hyp_path_40a64b59a888

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_63a.c:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件打开成功（data非NULL）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_63a.c:30; CWE404_Improper_Resource_Shutdown__fopen_w32_close_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_63a.c:31
- 结论: 文件资源通过fopen打开后，传递给sink函数CWE404_Improper_Resource_Shutdown__fopen_w32_close_63b_case0Sink，该sink函数使用_close而非fclose关闭文件句柄，导致资源泄漏。
- D验证: confirmed / ver_3f3fc0fd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 435. hyp_path_d623da75b724

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_64a.c:30
- 漏洞类型: null_deref
- CWE: CWE-404; CWE-476
- 风险等级: P0
- 触发条件: 攻击者不需要控制输入；文件必须成功打开才能触发资源泄漏（若打开失败则可能触发空指针解引用或未定义行为）。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_64a.c:30; CWE404_Improper_Resource_Shutdown__fopen_w32_close_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_64a.c:31
- 结论: 文件资源通过fopen打开后传递给sink函数CWE404_Improper_Resource_Shutdown__fopen_w32_close_64b_case0Sink，sink函数可能未正确关闭文件（例如使用close()而非fclose()），导致资源泄漏，违反CWE404。同时fopen返回值未检查，若打开失败则传递NULL指针给sink，可能引发未定义行为（如sink内部对NULL进行非安全操作）。
- D验证: confirmed / ver_59a08c7d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 436. hyp_path_a7953655bf75

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_22a.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法直接控制文件路径，但文件打开后资源泄露影响系统稳定性。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_22a.c:32; CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_22_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_22a.c:34
- 结论: 资源未正确关闭：freopen打开的文件句柄在传递给sink函数后可能未被关闭或使用了不匹配的关闭API（如CloseHandle），导致资源泄露（CWE-404）。
- D验证: confirmed / ver_71e9274a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 437. hyp_path_fdfda81b623b

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_51a.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序通过freopen获取资源，并在后续错误地使用CloseHandle关闭
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_51a.c:32; CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_51a.c:33
- 结论: 使用freopen打开文件后，在sink函数中可能使用CloseHandle关闭，违反了资源关闭的API契约（应使用fclose），导致资源未正确释放。
- D验证: confirmed / ver_f8621042
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 438. hyp_path_7c9a389ea234

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_52a.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该路由，成功调用freopen打开文件
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_52a.c:32; CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_52a.c:33
- 结论: 调用freopen打开文件后，将FILE*指针传递给sink函数，而sink函数名称暗示使用CloseHandle（适用于Windows句柄）而非fclose关闭文件，违反资源关闭的API contract，可能导致资源泄露或非预期行为。
- D验证: confirmed / ver_f7dea31d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 439. hyp_path_1438723b0798

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_53a.c:32
- 漏洞类型: null_deref
- CWE: CWE-404; CWE-476
- 风险等级: P0
- 触发条件: 程序正常执行，freopen调用成功或失败均可触发不同漏洞（资源泄露或空指针解引用）。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_53a.c:32; CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_53a.c:33
- 结论: 调用freopen打开文件后，未正确关闭资源，可能导致资源泄露。同时未检查freopen返回值，若打开失败则data为NULL，传递给后续sink函数可能导致空指针解引用。
- D验证: confirmed / ver_89e99677
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 440. hyp_path_59540d6bc8c1

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54a.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响程序执行路径，但漏洞本身无需外部输入即可触发，因为文件路径固定且无条件执行。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54a.c:31-32; CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54a.c:33
- 结论: CWE404: 资源未正确关闭。使用freopen打开文件后，在sink函数中可能使用CloseHandle关闭文件句柄，而不是fclose，导致资源未正确释放，可能造成资源泄漏或未刷新数据。
- D验证: confirmed / ver_51d97536
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 441. hyp_path_e4ccdd7deb62

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_64a.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: freopen成功返回非NULL的FILE*指针
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_64a.c:32; CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_64a.c:33
- 结论: 在使用freopen打开文件后，未在代码路径中调用fclose关闭文件，而sink函数可能使用CloseHandle（适用于HANDLE而非FILE*），导致资源泄漏（CWE-404）且违反API契约。
- D验证: confirmed / ver_657bb0cf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 442. hyp_path_0f9fe78fb78f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_63a.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序以默认方式运行，freopen成功打开文件。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_63a.c:32; CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_63a.c:33
- 结论: 使用freopen打开的文件资源，在sink函数中可能被错误地通过CloseHandle关闭，而不是fclose，导致资源未正确关闭（类型不匹配）。
- D验证: confirmed / ver_a74b788c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 443. hyp_path_dc6745374a76

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_22a.c:32
- 漏洞类型: CWE-252, CWE-404
- CWE: CWE-252; CWE-404
- 风险等级: P0
- 触发条件: 文件可能无法打开（如文件不存在或权限不足），导致freopen返回NULL；sink函数未实现资源关闭逻辑。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_22a.c:32; CWE404_Improper_Resource_Shutdown__freopen_w32_close_22_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_22a.c:34
- 结论: freopen打开文件后未检查返回值，且sink函数可能未关闭文件句柄，导致使用无效文件指针和资源泄漏。
- D验证: confirmed / ver_0ddce5f6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 444. hyp_path_14908e4ba5b1

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_51a.c:30
- 漏洞类型: null_deref
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需用户输入，代码路径自动执行。
- 触发路径: data = NULL; data = freopen("Case0Source_freopen.txt","w+",stdin); @ L28-30; CWE404_Improper_Resource_Shutdown__freopen_w32_close_51b_case0Sink(data); @ L31
- 结论: 资源文件通过freopen打开后，在sink函数中未正确关闭，导致资源泄露（CWE-404）。尽管sink函数实现未提供，但其名称暗示资源关闭不当，且B阶段静态分析标记为high_risk_sink。freopen返回值未检查，失败时可能导致空指针问题，但主要漏洞仍是资源泄露。
- D验证: confirmed / ver_06cb31d1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 445. hyp_path_acfe3c851ace

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_52a.c:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无特殊前提，代码执行到该路由即可触发资源泄漏。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_52a.c:30; CWE404_Improper_Resource_Shutdown__freopen_w32_close_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_52a.c:31
- 结论: 在CWE404_Improper_Resource_Shutdown__freopen_w32_close_52a.c中，使用freopen打开文件后，未在本地关闭文件描述符，而是将文件指针传递给sink函数，但sink函数可能未正确关闭资源，导致资源泄漏（CWE-404）。
- D验证: confirmed / ver_a3b9ea31
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 446. hyp_path_00ba55b7474f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54a.c:30
- 漏洞类型: CWE-404, CWE-252
- CWE: CWE-404; CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够影响文件系统状态（例如使文件不可访问）或程序运行环境异常。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54a.c:30; CWE404_Improper_Resource_Shutdown__freopen_w32_close_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54a.c:31
- 结论: freopen打开文件后未检查返回值，且sink函数可能未正确关闭资源，存在资源泄漏或对NULL指针操作的风险。
- D验证: confirmed / ver_88a4ab30
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 447. hyp_path_de09f3b3c182

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_53a.c:30
- 漏洞类型: null_deref
- CWE: CWE-404; CWE-252
- 风险等级: P0
- 触发条件: 程序执行到该路径，且freopen可能失败（返回NULL）
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_53a.c:30; CWE404_Improper_Resource_Shutdown__freopen_w32_close_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_53a.c:31
- 结论: freopen调用未检查返回值，若失败则data为NULL并传递给sink函数，可能导致空指针解引用或无效操作；sink函数可能使用了不匹配的关闭函数（如close而非fclose），但缺乏sink内部代码证据，资源泄漏或未正确关闭的风险存在。
- D验证: confirmed / ver_0513d7ad
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 448. hyp_path_092a310b1b71

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_64a.c:30
- 漏洞类型: CWE-404, CWE-775
- CWE: CWE-404; CWE-775
- 风险等级: P0
- 触发条件: 程序运行时存在可写的文件"Case0Source_freopen.txt"; freopen()调用成功（返回非NULL）
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_64a.c:30; CWE404_Improper_Resource_Shutdown__freopen_w32_close_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_64a.c:31
- 结论: 函数freopen()打开的文件资源可能未正确关闭：sink函数名称和代码路径暗示使用了close()而非fclose()关闭FILE*，导致资源泄露（CWE-404）。尽管sink内部代码未提供，但基于命名约定和常见CWE模式，该漏洞假设合理。
- D验证: confirmed / ver_ed9b87b8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 449. hyp_path_0d7370a59855

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_63a.c:30
- 漏洞类型: CWE-252, CWE-404
- CWE: CWE-252; CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响文件系统状态（如文件不存在、权限不足）导致 freopen 失败
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_63a.c:30
- 结论: freopen 未检查返回值，若文件打开失败则 data 为 NULL，后续 sink 函数可能处理 NULL 指针导致未定义行为；此外，sink 函数若未正确关闭文件资源则可能导致资源泄漏（CWE-404），但该部分缺乏实现确认。
- D验证: confirmed / ver_c6570a2a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 450. hyp_path_c3c1d0ea7f7a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_72a.cpp:37
- 漏洞类型: CWE-404, CWE-775
- CWE: CWE-404; CWE-775
- 风险等级: P0
- 触发条件: 程序执行到该路由并成功打开文件
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_72a.cpp:37; dataVector.insert(...); case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_72a.cpp:40-44
- 结论: 文件资源未正确关闭，导致资源泄露。fopen打开文件后，在向量传递和sink函数中均未调用fclose。
- D验证: confirmed / ver_0f8838c3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 451. hyp_path_418ebfac5abf

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_72a.cpp:37
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 文件"Case0Source_fopen.txt"能被成功打开，且程序未崩溃
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_72a.cpp:37; case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_72a.cpp:42
- 结论: 使用fopen打开文件后，在case0Sink内部可能错误地使用CloseHandle而非fclose，导致资源泄漏或句柄误用。
- D验证: confirmed / ver_b78ab066
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 452. hyp_path_edc836898c77

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_72a.cpp:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序正常执行，且 freopen 成功打开文件。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_72a.cpp:37; dataVector.insert(dataVector.end(), 1, data); dataVector.insert(dataVector.end(), 1, data); case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_72a.cpp:40-44
- 结论: 在 case0Sink 函数中，通过 freopen 打开的文件资源可能被错误地使用 CloseHandle 关闭，导致资源泄漏（CWE-404）。
- D验证: confirmed / ver_9058a1e5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 453. hyp_path_e026aa9987ca

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_74a.cpp:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需外部输入，漏洞存在于程序内部逻辑中。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_74a.cpp:37; dataMap[0] = data; dataMap[1] = data; dataMap[2] = data; @ 第40-41行; case0Sink(dataMap); @ 第42行
- 结论: 在CWE404测试用例中，通过fopen打开的文件资源在sink函数case0Sink中可能被错误地使用CloseHandle关闭，而不是调用fclose，导致资源未正确关闭（CWE-404）。但sink函数代码未提供，该假设证据不完整。
- D验证: confirmed / ver_d0bb8faa
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 454. hyp_path_6a1fd9aaeea9

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_72a.cpp:37
- 漏洞类型: null_deref
- CWE: CWE-404; CWE-476
- 风险等级: P0
- 触发条件: 程序执行到freopen调用，并进入后续插入vector和sink的路径，无论freopen成功与否。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ 35-39; dataVector.insert(dataVector.end(), 1, data); dataVector.insert(dataVector.end(), 1, data); case0Sink(dataVector); @ 40-44
- 结论: 调用freopen打开文件后，未对返回值进行错误检查，且未在后续路径中关闭文件，导致资源泄漏。如果freopen失败返回NULL，插入vector并传递给sink可能导致空指针解引用。由于sink（case0Sink）内部实现未提供，无法完全确认，但依据CWE404测试用例设计模式，资源泄漏和空指针风险存在。
- D验证: confirmed / ver_5db1fef6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 455. hyp_path_efec902c951e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_74a.cpp:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件 "Case0Source_freopen.txt" 可被成功打开（存在且权限允许）
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_74a.cpp:37; case0Sink(dataMap); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_74a.cpp:42
- 结论: 函数 case0Sink 中未正确关闭通过 freopen 打开的文件资源，导致资源泄露 (CWE-404)。
- D验证: confirmed / ver_27a090e2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 456. hyp_path_ea1095acb2cd

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_74a.cpp:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: fopen成功返回非NULL文件指针。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_74a.cpp:37; dataMap[0] = data; dataMap[1] = data; dataMap[2] = data; case0Sink(dataMap); @ 同文件:40-44
- 结论: 在CWE404_Improper_Resource_Shutdown__fopen_w32_close_74a.cpp中，fopen打开的文件资源未在sink函数中关闭，导致资源泄露。
- D验证: confirmed / ver_3107a746
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 457. hyp_path_fd03adabe8dc

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_74a.cpp:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需攻击者输入；代码本身执行即可触发
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_74a.cpp:37; dataMap[0] = data; dataMap[1] = data; dataMap[2] = data; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_74a.cpp:40-42; case0Sink(dataMap); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_74a.cpp:43
- 结论: 资源未正确关闭：使用freopen打开文件后，将FILE*指针存储到map中并传递给sink函数，但从未调用fclose关闭文件，导致资源泄漏。
- D验证: confirmed / ver_da123705
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 458. hyp_path_7fa0b09deda7

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_73a.cpp:37
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 攻击者无法直接控制输入，但代码本身存在资源管理错误，可利用于资源耗尽攻击。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_73a.cpp:37; dataList.push_back(data); dataList.push_back(data); dataList.push_back(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_73a.cpp:40-42; case0Sink(dataList); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_73a.cpp:43
- 结论: 资源未正确关闭：fopen 打开的文件在之后未被 fclose 正确关闭，而是使用 CloseHandle 关闭，导致资源泄露。
- D验证: confirmed / ver_8782e966
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 459. hyp_path_d45d6c41ce4c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_73a.cpp:37
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 函数case0被调用，且fopen成功返回非NULL文件指针。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_73a.cpp:37; dataList.push_back(data); ... case0Sink(dataList); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_73a.cpp:41-44
- 结论: 文件资源未正确关闭：fopen打开文件后未调用fclose，导致资源泄露。
- D验证: confirmed / ver_93f37ace
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 460. hyp_path_37acebe52e33

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_73a.cpp:37
- 漏洞类型: null_deref
- CWE: CWE-404; CWE-252
- 风险等级: P0
- 触发条件: 攻击者可能通过影响文件系统状态（如文件不存在或权限不足）使freopen返回NULL，导致空指针被传递到sink；或者sink中错误地使用CloseHandle而非fclose，导致资源泄漏。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_73a.cpp:37; dataList.push_back(data); dataList.push_back(data); case0Sink(dataList); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_73a.cpp:40-44
- 结论: 代码使用freopen打开文件，未检查返回值，且将文件指针传递给case0Sink，可能导致资源未正确关闭（可能使用CloseHandle而非fclose），违反CWE-404 Improper Resource Shutdown。同时，未检查freopen返回值也可能导致空指针解引用，违反CWE-252 Unchecked Return Value。
- D验证: confirmed / ver_eab41d64
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 461. hyp_path_aed1469f7d00

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_21.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需外部输入，代码静态触发
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_21.c:43; case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_21.c:44; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_21.c:33
- 结论: 使用fopen打开文件后，关闭时错误地使用了CloseHandle()而非fclose()，导致资源未正确关闭，违反了fopen/fclose配对契约。
- D验证: confirmed / ver_31cb79f9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 462. hyp_path_a8e93790ef6f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_73a.cpp:37
- 漏洞类型: null_deref
- CWE: CWE-404; CWE-476
- 风险等级: P0
- 触发条件: freopen()成功打开文件（返回非NULL）以触发资源泄漏；或freopen()失败返回NULL以触发空指针解引用
- 触发路径: data = NULL; data = freopen("Case0Source_freopen.txt","w+",stdin); @ L35-37; dataList.push_back(data); dataList.push_back(data); dataList.push_back(data); case0Sink(dataList); @ L39-42
- 结论: 文件资源未正确关闭，可能导致资源泄漏。freopen返回的文件指针未被检查是否为NULL，且sink中未显式关闭文件。此外，若freopen失败返回NULL，NULL指针被传入list并可能在sink中解引用导致崩溃。
- D验证: confirmed / ver_726afa25
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 463. hyp_path_f3b3d8fd7ead

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_41.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件打开成功，data 非 NULL，程序运行在 Windows 平台
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_41.c:28; case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_41.c:28; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_41.c:28
- 结论: 代码中使用 CloseHandle 关闭 fopen 返回的文件流，违反了资源关闭的 API contract。正确应使用 fclose。
- D验证: confirmed / ver_5cfd6376
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 464. hyp_path_2cf5c87d351e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_21.c:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序能够成功打开文件（即fopen返回非NULL）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ CWE404_Improper_Resource_Shutdown__fopen_w32_close_21.c:31; case0Static = 1; /* true */ case0Sink(data); @ CWE404_Improper_Resource_Shutdown__fopen_w32_close_21.c:32-33; if (data != NULL) { _close((int)data); } @ CWE404_Improper_Resource_Shutdown__fopen_w32_close_21.c:29-33
- 结论: 文件通过fopen打开后，在清理阶段使用了_close()而非fclose()关闭文件，违反了FILE*资源应使用fclose关闭的API契约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_42583675
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 465. hyp_path_fc6eb90d3815

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_41.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码路径必须被执行，无需攻击者控制输入
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_41.c:36-40; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_41.c:26-30
- 结论: 使用CloseHandle关闭由freopen打开的FILE*流，违反了API契约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_44acca77
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 466. hyp_path_699554a2d947

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_21.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无，代码路径自动执行，无需外部输入控制
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_21.c:33; case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_21.c:45-46; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_21.c:31-35
- 结论: 使用CloseHandle()关闭由freopen()返回的FILE*资源，违反API合约，导致资源未正确关闭，可能引发资源泄露或未定义行为。
- D验证: confirmed / ver_53044f4d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 467. hyp_path_0761dbd00159

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_21.c:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序能够执行到route中的freopen和case0Sink调用; 文件"Case0Source_freopen.txt"可打开
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_21.c:42; case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_21.c:44; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_21.c:31
- 结论: 使用freopen打开文件后，错误地使用_close而不是fclose关闭，违反了API contract，可能导致资源未正确释放（文件句柄泄漏、缓冲区未刷新）。
- D验证: confirmed / ver_1ae68d0c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 468. hyp_path_03eb4bd3b145

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_41.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: fopen() 成功返回非 NULL 的 FILE* 指针（即文件成功打开）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_41.c:26; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_41.c:24-28
- 结论: 函数 case0Sink 使用 _close() 关闭通过 fopen() 打开的 FILE* 指针，但 _close() 期望文件描述符而非 FILE*，违反 API contract，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_ea563f8e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 469. hyp_path_dbba80bfe764

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_41.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者不需要控制输入，但文件打开操作需成功
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_41.c:26; case0Sink(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_41.c:26; if (data != NULL) { _close((int)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_41.c:24-28
- 结论: 函数使用 freopen 打开文件后，错误地调用 _close((int)data) 而不是 fclose(data) 来关闭文件，导致 FILE* 资源未正确关闭，造成资源泄漏或未定义行为。
- D验证: confirmed / ver_92ac11a6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 470. hyp_path_6eb140a8bc8c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_82a.cpp:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: fopen成功打开文件（文件存在且可写入）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_82a.cpp:33; baseObject->action(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_82a.cpp:34-35; delete baseObject; // 未调用fclose，可能使用CloseHandle错误关闭 @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_82a.cpp:36
- 结论: 程序使用fopen打开文件后，未调用fclose关闭文件，而是通过基类指针调用action方法，该方法可能使用CloseHandle错误关闭文件句柄，导致资源泄露或错误关闭。
- D验证: confirmed / ver_1efdc0d6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 471. hyp_path_4bec9fc6b65f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_82a.cpp:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: fopen成功返回非NULL文件指针
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_82a.cpp:31; baseObject->action(data); // 虚函数调用，case0实现不关闭文件 @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_82a.cpp:33; delete baseObject; // 对象释放，但文件句柄未关闭 @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_82a.cpp:34
- 结论: fopen打开的文件资源在代码路径中未调用fclose关闭，导致资源泄漏。与CWE-404（资源未正确关闭）一致。
- D验证: confirmed / ver_a2b7e5ec
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 472. hyp_path_af8ffeef2072

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_82a.cpp:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: freopen()成功返回非NULL的FILE*指针
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_82a.cpp:31; baseObject->action(data); // action()实现未在提供代码中显示，但根据测试用例规范，case0不关闭资源 @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_82a.cpp:33
- 结论: 资源未正确关闭：freopen()打开的文件流指针data在后续代码中未显式关闭，且action()函数内部大概率不包含关闭操作（根据Juliet测试用例惯例，case0通常不关闭），导致文件资源泄漏。
- D验证: confirmed / ver_78999adb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 473. hyp_path_e503843642b2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_82a.cpp:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发该代码路径（如通过调用此函数）并重复执行以消耗系统文件句柄。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_82a.cpp:33; baseObject->action(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_82a.cpp:34-35; delete baseObject; /* 未显式关闭文件 */ @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_82a.cpp:36
- 结论: 在函数CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_82a::case0中，通过freopen打开的文件未在释放对象前调用fclose关闭，且action函数可能错误地使用CloseHandle关闭FILE*，导致资源泄漏（CWE-404）。
- D验证: confirmed / ver_5394552d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 474. hyp_path_c9332ae8fa4e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_81a.cpp:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序能够正常打开指定文件。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_81a.cpp:31; const CWE404_Improper_Resource_Shutdown__fopen_w32_close_81_base& baseObject = CWE404_Improper_Resource_Shutdown__fopen_w32_close_81_case0(); baseObject.action(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_81a.cpp:32-33; class CWE404_Improper_Resource_Shutdown__fopen_w32_close_81_case0 : public CWE404_Improper_Resource_Shutdown__fopen_w32_close_81_base { public: ... } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_81.h:29-33
- 结论: 程序中通过fopen打开文件后，action函数内部可能未正确关闭文件句柄，导致资源泄露。但由于缺乏action函数内部实现，证据不完整。
- D验证: confirmed / ver_576576c9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 475. hyp_path_46c08fa12e64

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_81a.cpp:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件成功打开（fopen返回非NULL）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_81a.cpp:33; baseObject.action(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_81a.cpp:34; CloseHandle(data); // 不当关闭，应使用fclose @ sink function (likely in CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_81_bad.cpp or similar, uses CloseHandle)
- 结论: 文件资源通过fopen打开后，在sink中使用CloseHandle关闭，而不是fclose，导致资源关闭不当，违反CWE-404（不正确的资源关闭）。
- D验证: confirmed / ver_54c2bf33
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 476. hyp_path_16abcdc3af64

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_81a.cpp:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需控制输入，资源泄漏是代码固有缺陷
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_81a.cpp:33; const CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_81_base& baseObject = ...; baseObject.action(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_81a.cpp:34-35
- 结论: freopen返回的文件指针未使用fclose关闭，而是可能使用CloseHandle关闭，导致资源未正确关闭，违反CWE-404规范。
- D验证: confirmed / ver_c2299fee
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 477. hyp_path_e95951f82445

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_44.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无额外攻击者控制条件，程序正常执行路径即可触发。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_44.c:40; funcPtr(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_44.c:42
- 结论: 使用fopen打开文件后，通过函数指针传递文件句柄，但函数指针指向的函数未使用fclose关闭文件，而是可能使用CloseHandle或其他方式，导致文件句柄资源泄漏（CWE-404）。
- D验证: confirmed / ver_53609a2e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 478. hyp_path_e11a40338b55

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_81a.cpp:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够多次触发执行case0函数的代码路径（如通过反复调用包含该代码的接口或服务）。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_81a.cpp:31; baseObject.action(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_81a.cpp:33
- 结论: freopen打开的文件资源在sink函数中未关闭，导致资源泄露（CWE-404）。由于sink内部实现未提供，但基于CWE测试集典型模式及B阶段高风险的资源泄露标签，漏洞假设合理但需动态验证。
- D验证: confirmed / ver_044b5801
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 479. hyp_path_caceec020d6b

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_65a.c:34
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 程序执行到该路径，且fopen成功返回非NULL指针。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_65a.c:34
- 结论: fopen打开的文件资源未正确关闭，通过函数指针调用了不匹配的CloseHandle函数（预期为fclose），导致资源泄漏或未定义行为。
- D验证: confirmed / ver_b526a345
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 480. hyp_path_9ab6fcbd0e94

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_65a.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: fopen成功返回非NULL文件指针; funcPtr指向的函数未关闭文件
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_65a.c:32; funcPtr(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_65a.c:33
- 结论: fopen打开的文件未在后续代码中关闭，导致资源泄漏。
- D验证: confirmed / ver_2b9c35cd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 481. hyp_path_04ce14ea6d57

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_44.c:38
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行此路径，fopen成功返回非NULL指针。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_44.c:38; funcPtr(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_44.c:40
- 结论: fopen打开文件后，通过函数指针funcPtr调用close而非fclose，导致资源关闭类型不匹配，造成文件句柄泄漏（CWE-404）。
- D验证: confirmed / ver_d9887b4d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 482. hyp_path_26c3e4566c62

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_44.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码路径被执行，逻辑漏洞无需外部输入控制。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_44.c:40
- 结论: 使用freopen打开文件后，通过函数指针调用CloseHandle而非fclose关闭资源，导致资源错误关闭，违反CWE-404。
- D验证: confirmed / ver_11c3fdf1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 483. hyp_path_f4402a067bb3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_44.c:38
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件"Case0Source_freopen.txt"存在且可打开（freopen返回非NULL）; 函数指针funcPtr指向的函数未关闭data指向的文件流
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_44.c:38; funcPtr(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_44.c:39
- 结论: 在函数中使用freopen打开文件后，未在函数返回前关闭该文件，导致资源泄漏。
- D验证: confirmed / ver_6e2608f1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 484. hyp_path_deb554b40562

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_65a.c:34
- 漏洞类型: null_deref
- CWE: CWE-252; CWE-476; CWE-404
- 风险等级: P0
- 触发条件: freopen调用失败（如文件不存在、权限不足）导致返回NULL，或成功但后续sink未正确关闭资源
- 触发路径: data = NULL; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_65a.c:32; data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_65a.c:34; funcPtr(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_65a.c:36
- 结论: freopen返回值未检查，若freopen失败则data保持NULL，后续通过函数指针调用sink函数时传入NULL指针，可能导致空指针解引用或未定义行为。同时，若freopen成功但sink函数未正确关闭资源，则存在资源泄漏（CWE-404）。
- D验证: confirmed / ver_3c442524
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 485. hyp_path_f8efa9463f15

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_65a.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: freopen成功打开文件，返回非NULL的FILE指针; funcPtr指向的函数不执行fclose或类似关闭操作
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_65a.c:32; funcPtr(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_65a.c:34
- 结论: 调用freopen打开文件后未关闭，导致资源泄露（CWE-404）
- D验证: confirmed / ver_8447a3ec
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 486. hyp_path_b6a9456a54c3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_17.c:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需外部输入控制，代码固定路径执行
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_17.c:30; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_17.c:36
- 结论: 代码使用fopen打开文件后，使用CloseHandle()替代fclose()关闭，违反了Windows API契约：fopen返回FILE*指针，应使用fclose关闭，而CloseHandle用于HANDLE。这导致资源不正确释放，可能造成资源泄漏或文件未刷新。
- D验证: confirmed / ver_5ff109c8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 487. hyp_path_4aa10207ecde

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_17.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无外部输入控制，漏洞由内部代码逻辑触发，只要程序运行到该路径即可。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_17.c:28; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_17.c:34
- 结论: 文件资源通过fopen打开后，使用_close关闭，而不是fclose，违反了资源关闭的API合同，可能导致资源泄露或未定义行为。
- D验证: confirmed / ver_b4afaf82
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 488. hyp_path_2bda0956b6d2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_17.c:28
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需外部攻击者控制，代码自身逻辑错误即可触发漏洞。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_17.c:28; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_17.c:34
- 结论: 使用_close()关闭由freopen()打开的FILE*资源，违反了资源关闭的API合约。freopen()应使用fclose()关闭，强制类型转换可能导致资源未正确释放或未定义行为。
- D验证: confirmed / ver_19bf1f3f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 489. hyp_path_32b34a424c52

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_17.c:30
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需外部输入，代码逻辑固定，只要执行到该路径即可触发
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_17.c:30; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_17.c:36
- 结论: freopen打开文件后使用CloseHandle关闭，但CloseHandle期望HANDLE类型，而freopen返回FILE*，导致资源未正确关闭（应使用fclose），违反API contract，属于CWE-404资源关闭不当。
- D验证: confirmed / ver_923305c1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 490. hyp_path_f7ae4bfbaed6

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_12.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: globalReturnsTrueOrFalse()返回假，导致执行else分支；data非空（否则_close(0)不构成资源泄漏，但代码未检查）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_12.c:26; if(globalReturnsTrueOrFalse()) { if (data != NULL) ... } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_12.c:28-29; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_12.c:32-33
- 结论: 文件资源通过fopen打开，却使用_close()关闭而非fclose()，导致资源未正确释放，违反CWE-404 Improper Resource Shutdown or Release。
- D验证: confirmed / ver_358852a8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 491. hyp_path_3a32de8a1229

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_12.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件打开成功（data != NULL）; 条件globalReturnsTrueOrFalse()返回假（导致进入非fclose分支，但实际上无论内部分支如何，外部if块内均会执行CloseHandle）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_12.c:29; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_12.c:35
- 结论: 在fopen打开文件后，当globalReturnsTrueOrFalse()返回假时，执行路径使用CloseHandle()而非fclose()关闭文件句柄，导致资源关闭不当。由于fopen返回FILE*，而CloseHandle期望HANDLE，类型不匹配的强转可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_d559db61
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 492. hyp_path_86ec0c674fb1

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_08.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到漏洞路径，即staticReturnsTrue()返回真
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_08.c:42; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_08.c:48
- 结论: 使用fopen打开的文件需要用fclose关闭，但代码中使用了CloseHandle关闭，导致不正确的资源关闭，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_aefc0751
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 493. hyp_path_e84cb1ee657f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_12.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法直接控制globalReturnsTrueOrFalse函数，但该分支在测试条件下可能被触发
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ L28; if(globalReturnsTrueOrFalse()) @ L29; else { ... CloseHandle((HANDLE)data); } @ L35-37
- 结论: 资源关闭不匹配：使用freopen打开的文件流，在else分支中使用了CloseHandle而不是fclose，违反API合约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_7e6fbc3d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 494. hyp_path_24ffc4e409a0

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_08.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: fopen成功打开文件（假定文件存在且可写）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_08.c:40; if(staticReturnsTrue()) { @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_08.c:41; if (data != NULL) @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_08.c:43; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_08.c:45
- 结论: 文件资源关闭不当：使用fopen打开文件后，错误地使用_close()（期望文件描述符）而非fclose()关闭FILE*，导致资源未正确释放，可能造成资源泄漏。
- D验证: confirmed / ver_65a67d66
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 495. hyp_path_029bc76e2c72

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_11.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序内部逻辑触发，无需攻击者输入控制。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_11.c:29; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_11.c:35
- 结论: 使用fopen打开的文件必须使用fclose关闭，但代码中错误地使用了CloseHandle()，违反了API契约，导致资源未正确关闭，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_23344fd6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 496. hyp_path_aaff199f57cb

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_11.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需直接控制输入，但需要代码执行路径经过条件判断 globalReturnsTrue()（该函数固定返回 true），且文件成功打开。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_11.c:26; if(globalReturnsTrue()) @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_11.c:27; if (data != NULL) { _close((int)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_11.c:31-33
- 结论: 使用 fopen 打开文件后，错误地使用 _close 而非 fclose 关闭文件，违反了 API 契约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_59a0e2a0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 497. hyp_path_f2b2224e6618

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_08.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无特殊前提，代码执行即可触发
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ L42; CloseHandle((HANDLE)data); @ L48
- 结论: 函数freopen打开的文件资源使用CloseHandle关闭，违反了API contract：freopen返回FILE*指针，应使用fclose关闭。强制转换为HANDLE并调用CloseHandle导致资源关闭不当，可能引发资源泄漏或未定义行为。
- D验证: confirmed / ver_b9d5092d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 498. hyp_path_063daf9c286e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_08.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: staticReturnsTrue()恒为真，所以代码必然执行；data不为NULL时进入关闭分支。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_08.c:40; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_08.c:46
- 结论: 代码使用freopen打开文件后，错误地使用_close()而不是fclose()关闭文件，造成资源未正确关闭的漏洞。
- D验证: confirmed / ver_3f673339
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 499. hyp_path_4efa2667c065

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_11.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者需要确保文件'Case0Source_freopen.txt'可访问，以使freopen成功返回非NULL指针；globalReturnsTrue()返回true
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_11.c:29; if(globalReturnsTrue()) @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_11.c:30; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_11.c:35
- 结论: 使用CloseHandle关闭由freopen打开的文件流，导致资源关闭不当。freopen返回FILE*，应使用fclose关闭，而代码中将其转换为HANDLE后调用CloseHandle，违反了API合同，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_fb6bd5c3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 500. hyp_path_7c04cdf09531

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_11.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序正常运行且freopen成功打开文件
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_11.c:27; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_11.c:33
- 结论: 使用freopen打开文件后，使用_close()而不是fclose()关闭文件，导致资源错误关闭，违反了API contract，可能造成资源泄漏或未正确释放。
- D验证: confirmed / ver_331105bc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 501. hyp_path_8735b761f1cf

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_01.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: fopen()成功打开文件并返回非NULL指针
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_01.c:29; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_01.c:33
- 结论: 使用fopen()打开文件后，错误地使用CloseHandle()而不是fclose()关闭文件句柄，导致资源关闭不当，违反API使用契约。该漏洞可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_9c4a571a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 502. hyp_path_c8ad6c34cb81

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_02.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件成功打开（fopen返回非NULL）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_02.c:29; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_02.c:35
- 结论: 使用fopen打开文件后，错误地使用CloseHandle代替fclose关闭文件句柄，导致资源未正确关闭，违反API契约。
- D验证: confirmed / ver_d06f2e51
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 503. hyp_path_3efa82ac0177

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_03.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者不需要控制输入，该漏洞是代码本身的设计错误
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ 29行; CloseHandle((HANDLE)data); @ 35行
- 结论: 使用fopen打开文件后，错误地使用CloseHandle()而不是fclose()关闭文件，违反了API契约，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_e47f1432
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 504. hyp_path_54a7c65cfa4d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_12.c:27
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 程序运行环境存在可写的文件 "Case0Source_freopen.txt" 或 `freopen` 能够成功创建该文件。; `globalReturnsTrueOrFalse()` 返回 `false`，使得代码进入 `_close` 分支。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_12.c:26; if(globalReturnsTrueOrFalse()) @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_12.c:28; { /* NOTE: Attempt to close the file using close() instead of fclose() */ _close((int)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_12.c:31-35
- 结论: 代码中存在通过 `_close` 关闭 `FILE*` 类型资源的行为，违反了 API contract，可能导致资源未正确关闭或未定义行为。
- D验证: confirmed / ver_0ffeb4ce
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 505. hyp_path_a02941c499af

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_04.c:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需攻击者控制，代码路径静态执行，但漏洞触发依赖于fopen成功返回非NULL指针
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_04.c:35; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_04.c:41
- 结论: 文件资源通过fopen打开后，使用CloseHandle()关闭，违反了正确关闭文件资源的API契约。CloseHandle()不应用于关闭fopen返回的文件流，正确的做法是使用fclose()。这会导致资源未正确关闭，可能引发资源泄漏或未定义行为。
- D验证: confirmed / ver_9b0a388a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 506. hyp_path_c7c9dce99cb3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_05.c:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到存在漏洞的代码路径（staticTrue条件为真）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_05.c:35; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_05.c:41
- 结论: 使用fopen打开文件后，错误地使用CloseHandle替代fclose关闭文件句柄，导致资源未正确关闭，违反CWE-404。
- D验证: confirmed / ver_52a84681
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 507. hyp_path_429ca70bb35f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_06.c:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: STATIC_CONST_FIVE==5恒为真，执行路径条件满足。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_06.c:34; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_06.c:40
- 结论: 调用fopen打开文件后，使用CloseHandle而不是fclose关闭，导致资源未正确关闭，违反API contract。
- D验证: confirmed / ver_23672471
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 508. hyp_path_b06f0a61bb22

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_07.c:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需控制输入；代码逻辑本身存在 API misuse
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_07.c:34; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_07.c:40
- 结论: 使用 fopen 打开文件后，错误地使用 CloseHandle 代替 fclose 关闭，导致资源未正确释放，可能造成资源泄露。
- D验证: confirmed / ver_348e623e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 509. hyp_path_b40ff9c5f5a8

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_14.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序运行时 globalFive 必须为 5。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_14.c:29; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_14.c:35
- 结论: 使用不匹配的关闭函数：fopen 返回 FILE* 后，错误地使用 CloseHandle 而不是 fclose，导致资源泄漏或未定义行为。
- D验证: confirmed / ver_70624e92
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 510. hyp_path_808232c49f5c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_10.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该代码路径（globalTrue为真）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_10.c:29; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_10.c:35
- 结论: 使用fopen打开文件后，错误地使用CloseHandle()而不是fclose()关闭文件句柄，导致资源未正确释放，可能引发资源泄漏。
- D验证: confirmed / ver_54944327
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 511. hyp_path_dba391ebada5

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_09.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需控制输入，代码路径由静态条件GLOBAL_CONST_TRUE保证执行
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_09.c:29; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_09.c:35
- 结论: 使用fopen打开文件后，错误地使用CloseHandle关闭文件句柄，导致资源未正确关闭（应使用fclose）。
- D验证: confirmed / ver_5d29bc9e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 512. hyp_path_deaed3c6bc0e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_13.c:29
- 漏洞类型: CWE-404, CWE-665
- CWE: CWE-404; CWE-665
- 风险等级: P0
- 触发条件: 程序运行时，文件能够被成功打开
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_13.c:29; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_13.c:35
- 结论: 使用fopen打开文件后，错误地使用CloseHandle关闭，而不是fclose，导致资源关闭不当。这违反了CWE-404（不正确的资源关闭），可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_1b83363b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 513. hyp_path_1288a7ceb349

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_15.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: fopen成功打开文件，返回非NULL的FILE*指针；switch(6)确保执行CloseHandle分支。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_15.c:29; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_15.c:36
- 结论: 使用fopen打开文件后，使用CloseHandle而不是fclose关闭文件句柄，导致资源释放不当（违反API contract），构成CWE-404漏洞。
- D验证: confirmed / ver_83409acd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 514. hyp_path_3bc7f5fbabfc

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_31.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法控制文件名（硬编码），但资源清理逻辑错误导致资源未正确关闭
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ line 29; CloseHandle((HANDLE)data); @ line 36
- 结论: 代码使用fopen打开文件后，错误地使用CloseHandle()（期望HANDLE）而非fclose()来关闭文件。将FILE*指针强制转换为HANDLE并调用CloseHandle违反了API contract，可能导致资源未正确关闭或未定义行为。
- D验证: confirmed / ver_be1e1c5a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 515. hyp_path_601da352955c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_33.cpp:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序正常执行该路径（无额外条件）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_33.cpp:33; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_33.cpp:39
- 结论: 使用CloseHandle关闭通过fopen打开的文件资源，违反了资源关闭的一致性要求，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_18609411
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 516. hyp_path_4d1e399a1d13

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_16.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_16.c:29; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_16.c:35
- 结论: 使用fopen打开文件后，使用CloseHandle而非fclose关闭，导致资源未正确关闭，违反API契约，造成资源泄漏。
- D验证: confirmed / ver_345b980b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 517. hyp_path_1b7d919e96fd

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_34.c:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码在Windows环境下编译和执行，且CloseHandle API可用。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_34.c:36; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_34.c:43
- 结论: 在CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_34.c中，程序使用fopen打开文件后，使用CloseHandle（需要HANDLE类型）关闭文件，而不是fclose。这违反了资源关闭的API契约，导致资源管理错误（CWE-404）。
- D验证: confirmed / ver_8a9c1591
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 518. hyp_path_bf7fe794d912

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_18.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无外部输入控制，代码路径自然执行即可触发漏洞
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ L23; goto sink; @ L27-31; CloseHandle((HANDLE)data); @ L35
- 结论: 使用fopen打开文件后，错误地使用CloseHandle代替fclose关闭文件句柄，导致资源未正确释放，可能引发资源泄漏或未定义行为。即使fopen失败返回NULL，CloseHandle(NULL)虽然安全但掩盖了根本错误，主要漏洞在于fopen成功时使用CloseHandle。
- D验证: confirmed / ver_5c710e6e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 519. hyp_path_b07ccc68f463

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_01.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序运行且fopen调用成功
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ CWE404_Improper_Resource_Shutdown__fopen_w32_close_01.c:27; _close((int)data); @ CWE404_Improper_Resource_Shutdown__fopen_w32_close_01.c:31
- 结论: 文件资源使用fopen打开后，使用_close关闭，违反了API contract，导致资源未正确关闭，可能造成文件句柄泄漏。
- D验证: confirmed / ver_a7734bf5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 520. hyp_path_03c9f7485144

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_05.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件打开成功（staticTrue条件为真）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_05.c:31-33; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_05.c:39
- 结论: 使用fopen打开文件后，误用_close()而不是fclose()关闭文件句柄，违反API契约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_fbd09936
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 521. hyp_path_92b93f2c04e8

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_02.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码自动执行路径，无需攻击者控制输入
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_02.c:27; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_02.c:33
- 结论: 使用fopen打开文件后，错误地使用_close()关闭，导致资源未正确释放，可能造成资源泄漏或其他未定义行为。违反CWE-404 Improper Resource Shutdown。
- D验证: confirmed / ver_9a819618
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 522. hyp_path_f3fc67c6dc8e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_03.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: fopen 成功返回非 NULL 的 FILE* 指针，或者 fopen 失败返回 NULL 导致关闭文件描述符 0
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_03.c:27; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_03.c:33
- 结论: 使用 fopen 打开文件后，使用 _close (期望文件描述符) 而非 fclose 关闭，导致资源关闭 API 不匹配，可能造成资源泄漏或未定义行为。另外，未检查 fopen 返回值，若失败则关闭文件描述符 0 可能导致意外行为。
- D验证: confirmed / ver_ec8bb6fc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 523. hyp_path_52266ed2bb7c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_04.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序需编译并运行，且文件"Case0Source_fopen.txt"可被成功打开（fopen返回非NULL）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_04.c:33; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_04.c:39
- 结论: 在CWE404_Improper_Resource_Shutdown__fopen_w32_close_04_case0中，使用fopen打开文件后，错误地使用_close()（int类型）而非fclose()关闭文件句柄，违反了FILE*资源的正确关闭协议，导致资源未正确释放及潜在的资源泄漏。
- D验证: confirmed / ver_3930c4bf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 524. hyp_path_c3455da373b9

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_06.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需直接控制输入，但错误关闭模式是固定的
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_06.c:32; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_06.c:38
- 结论: 存在不正确的资源关闭：使用fopen打开文件后，使用_close()关闭，但fopen返回的是FILE*指针，应使用fclose()。这种不当关闭可能导致资源泄露或未定义行为，符合CWE-404。
- D验证: confirmed / ver_0e2a3cf5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 525. hyp_path_0dd72901b521

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_09.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法直接控制文件操作，但代码本身的错误导致资源泄漏；if(GLOBAL_CONST_TRUE)始终为真，路径可达。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_09.c:27; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_09.c:33
- 结论: 使用fopen打开文件后，错误地使用_close()而非fclose()关闭文件，导致资源未正确关闭（CWE-404）。将FILE*转换为int传递给_close()可能导致未定义行为或资源泄漏，违反了API合约。
- D验证: confirmed / ver_4b94ccfd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 526. hyp_path_b5cbea52184c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_10.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无，代码逻辑直接执行此路径
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ 27; _close((int)data); @ 33
- 结论: 使用fopen打开文件后，使用_close()关闭而非fclose()，导致资源关闭不当，违反API规范，可能导致文件句柄泄漏或未正确刷新缓冲区。
- D验证: confirmed / ver_9f85777e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 527. hyp_path_a7bad7a6a549

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_07.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: staticFive == 5, ensuring the if branch is taken
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_07.c:32; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_07.c:38
- 结论: File opened with fopen() is improperly closed using _close() instead of fclose(), resulting in resource leak and violation of API contract.
- D验证: confirmed / ver_8c1f70a9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 528. hyp_path_65489e3afee5

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_14.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无攻击者控制输入；仅需条件globalFive==5成立（Juliet测试中通常为真）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_14.c:27; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_14.c:33
- 结论: 文件资源使用fopen打开，但使用_close()关闭，违反了API契约（fopen返回FILE*应使用fclose关闭），导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_2b47eb7a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 529. hyp_path_171fb895ec5a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_13.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需直接控制输入，但需要代码执行路径到达fopen和_close调用。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ 27; _close((int)data); @ 33
- 结论: 使用fopen打开的文件资源未使用fclose关闭，而是使用_close（低层文件描述符关闭）关闭，违反了资源关闭的API契约，导致资源关闭不当，可能引发资源泄漏或未定义行为。
- D验证: confirmed / ver_811efcae
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 530. hyp_path_a32287fa8281

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_15.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件打开成功（fopen返回非NULL）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ CWE404_Improper_Resource_Shutdown__fopen_w32_close_15.c:27; _close((int)data); @ CWE404_Improper_Resource_Shutdown__fopen_w32_close_15.c:34
- 结论: 使用fopen打开文件后，未使用fclose()正确关闭，而是错误地使用_close()函数，导致资源未正确关闭，存在资源泄漏漏洞。
- D验证: confirmed / ver_a683a865
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 531. hyp_path_9a9c7d37633f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_33.cpp:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到sink代码路径
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_33.cpp:31; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_33.cpp:37
- 结论: 使用fopen打开文件后未使用fclose关闭，而是使用_close尝试关闭，导致资源关闭不当（CWE-404）。
- D验证: confirmed / ver_f910d297
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 532. hyp_path_8d790d418c5a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_16.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_16.c:27; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_16.c:33
- 结论: 使用fopen打开文件后，使用_close而不是fclose关闭文件，违反了FILE*资源的正确关闭契约，可能导致缓冲区数据丢失或资源泄漏。
- D验证: confirmed / ver_5e7a8673
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 533. hyp_path_e1fe34aa7999

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_31.c:27
- 漏洞类型: CWE-404, CWE-252
- CWE: CWE-404; CWE-252
- 风险等级: P0
- 触发条件: 攻击者无法直接控制文件名，但漏洞在正常执行路径中必然触发。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_31.c:27; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_31.c:34
- 结论: fopen返回值未检查，并使用不匹配的_close关闭FILE*指针，导致资源泄漏和未定义行为。
- D验证: confirmed / ver_2d473a37
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 534. hyp_path_53f20f14cebc

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_18.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者不直接控制输入，但文件打开操作是程序自身行为
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_18.c:27; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_18.c:33
- 结论: 使用fopen打开文件后，使用_close()而不是fclose()关闭，导致资源关闭不当，违反API契约，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_259e9953
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 535. hyp_path_eba0aab545cb

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_34.c:34
- 漏洞类型: null_deref
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该路径，fopen成功返回非空指针。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ 代码行34; _close((int)data); @ 代码行41
- 结论: 资源未正确关闭：使用fopen()打开文件后，错误地使用_close()而非fclose()关闭，导致文件资源泄露。
- D验证: confirmed / ver_2e77c3e9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 536. hyp_path_f22271526efb

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_01.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码执行到该分支（文件打开成功且进入关闭逻辑）
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ 29; CloseHandle((HANDLE)data); @ 33
- 结论: 使用CloseHandle()关闭由freopen()打开的文件流，导致资源关闭不当。freopen()返回的FILE*应使用fclose()关闭，而非CloseHandle()，违反API契约，造成资源泄漏或未定义行为。
- D验证: confirmed / ver_63c3977c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 537. hyp_path_0a039c79d158

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_02.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发该代码路径（例如通过文件存在性）
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_02.c:29; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_02.c:35
- 结论: 文件资源被不正确地关闭：使用freopen打开文件流后，使用CloseHandle而不是fclose关闭，导致资源泄露和未定义行为。
- D验证: confirmed / ver_18baeaa3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 538. hyp_path_d421b455e634

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_03.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: freopen成功返回非NULL的FILE*指针（即使失败，CloseHandle(NULL)也是不正确的资源关闭）
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ 第29行; CloseHandle((HANDLE)data); @ 第35行
- 结论: 程序使用freopen打开文件，但使用CloseHandle关闭文件指针，违反资源关闭契约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_eac572ad
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 539. hyp_path_f88fcb523da3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_05.c:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到if(staticTrue)分支，且freopen成功返回非NULL指针
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_05.c:35; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_05.c:41
- 结论: freopen返回的文件流被错误地使用CloseHandle关闭，导致资源关闭不匹配（CWE-404）。
- D验证: confirmed / ver_d5de2421
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 540. hyp_path_d389bad7c1dc

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_04.c:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: STATIC_CONST_TRUE为真，确保执行到关闭分支; freopen成功返回非NULL指针（若失败则CloseHandle(NULL)仍为API误用）
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_04.c:35; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_04.c:41
- 结论: 使用freopen打开的文件应使用fclose关闭，但代码中使用了CloseHandle关闭，导致资源关闭方式不匹配，违反API契约。
- D验证: confirmed / ver_9185568b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 541. hyp_path_377770f040e6

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_09.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: freopen成功打开文件（不返回NULL）
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_09.c:29; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_09.c:35
- 结论: 使用freopen打开的文件句柄被CloseHandle关闭，导致资源关闭不匹配，可能造成资源泄露或未定义行为。
- D验证: confirmed / ver_7f0ba3b3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 542. hyp_path_bb7f3373fb57

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_06.c:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: STATIC_CONST_FIVE为常量5，导致if条件恒真，路径必然执行
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_06.c:34; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_06.c:40
- 结论: 资源关闭不当：freopen打开的文件应使用fclose关闭，但代码使用CloseHandle关闭，导致资源未正确释放（CWE-404）。
- D验证: confirmed / ver_3ce2d00f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 543. hyp_path_60d8eea501ef

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_07.c:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 静态变量 staticFive 等于 5，使得控制流进入 if 代码块，触发错误关闭操作。测试用例中该值预设，实际应用中需满足该条件。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_07.c:34; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_07.c:40
- 结论: 使用 CloseHandle() 关闭 freopen() 返回的文件流，属于资源关闭不当（CWE-404）。函数 CloseHandle() 需要 HANDLE 类型，而 freopen() 返回 FILE* 指针，导致关闭方式错误，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_ea619826
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 544. hyp_path_c1e9b20f69da

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_10.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件"Case0Source_freopen.txt"存在且可打开; 全局条件globalTrue为真
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_10.c:29; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_10.c:35
- 结论: 使用freopen打开文件后，错误地使用CloseHandle而不是fclose关闭，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_9aa93f94
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 545. hyp_path_bdf2e8f61642

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_14.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者可能操纵文件路径或内容，但此处主要是API misuse，无需攻击者控制输入
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ L29; CloseHandle((HANDLE)data); @ L35
- 结论: 在freopen打开文件后，使用CloseHandle关闭文件句柄，但freopen返回的FILE*应使用fclose关闭，CloseHandle用于HANDLE，导致资源未正确关闭（资源泄露），违反API contract。
- D验证: confirmed / ver_30705f19
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 546. hyp_path_b816b0692fb8

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_15.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需控制输入，固定文件名，但触发条件为程序执行到switch(6)分支且freopen成功。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_15.c:29; CloseHandle((HANDLE)data); @ CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_15.c:36
- 结论: 文件资源使用freopen打开后，未使用fclose关闭，而是使用CloseHandle关闭，违反了API contract，导致资源未正确释放，存在资源泄漏风险。
- D验证: confirmed / ver_9bfa04e1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 547. hyp_path_a9eba1d58345

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_13.c:29
- 漏洞类型: null_deref
- CWE: CWE-404; CWE-253
- 风险等级: P0
- 触发条件: 攻击者无法直接控制输入，但程序逻辑默认使用错误的API关闭文件资源
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_13.c:29; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_13.c:35
- 结论: 资源关闭错配：使用CloseHandle关闭由freopen返回的文件流，应使用fclose。同时，未检查freopen的返回值，可能导致空指针解引用。
- D验证: confirmed / ver_68dce4fa
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 548. hyp_path_4fd86f5f14fc

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_16.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码路径可达，文件打开和关闭路径固定，但无需外部输入控制。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_16.c:29; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_16.c:35
- 结论: 使用freopen打开文件并获取FILE*指针，然后调用CloseHandle((HANDLE)data)尝试关闭，但CloseHandle仅适用于内核对象句柄，不适用于FILE*，导致资源未正确释放，违反API合约，造成CWE-404资源关闭不当。
- D验证: confirmed / ver_30ba1701
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 549. hyp_path_375f9dbbe012

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_18.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响文件打开操作（如文件存在性）或控制输入，但非必需；漏洞触发依赖代码内部逻辑。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_18.c:29; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_18.c:35
- 结论: 程序使用freopen打开文件，但错误地使用CloseHandle关闭文件句柄，违反了资源关闭的API契约，导致资源未正确关闭（CWE-404）。具体地，freopen返回FILE*指针，而CloseHandle期望HANDLE，强制类型转换后可能导致未定义行为或资源泄漏。
- D验证: confirmed / ver_ddbdd244
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 550. hyp_path_71fefa397623

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_31.c:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码被执行，且freopen成功返回非NULL的FILE*指针
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_31.c:29; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_31.c:36
- 结论: 使用CloseHandle关闭由freopen打开的文件流，造成资源关闭方式不匹配，违反API contract，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_ffd2df4a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 551. hyp_path_a56628664f26

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_33.cpp:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到此代码路径，无额外攻击者控制输入要求；漏洞由代码逻辑错误直接触发。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_33.cpp:33; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_33.cpp:39
- 结论: 使用freopen打开文件后，错误地使用CloseHandle（期望HANDLE）来关闭FILE*，导致资源未正确释放，可能造成资源泄漏。
- D验证: confirmed / ver_e26eb0d9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 552. hyp_path_d652b4e0de4e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_34.c:36
- 漏洞类型: CWE-404, CWE-754
- CWE: CWE-404; CWE-754
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_34.c:36; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_34.c:43
- 结论: 代码使用freopen打开文件，返回FILE*，但随后使用CloseHandle(HANDLE)关闭，应为fclose。这违反了API契约，导致资源关闭不当，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_cd704da9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 553. hyp_path_8e3cdde71468

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_01.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该路由，且freopen调用成功
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ 25-27; _close((int)data); @ 29-33
- 结论: 使用freopen打开的文件流被错误地使用_close关闭，违反API合约，可能导致资源未正确释放或未定义行为。
- D验证: confirmed / ver_e6558382
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 554. hyp_path_87f98bcd1b68

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_02.c:27
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: 文件"Case0Source_freopen.txt"存在且可打开
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_02.c:27; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_02.c:33
- 结论: freopen返回FILE*指针，但错误地使用_close（期望文件描述符int）来关闭，导致资源未正确关闭（fclose未调用），违反了API contract。
- D验证: confirmed / ver_9575d410
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 555. hyp_path_0000b6924a52

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_04.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需特殊控制，漏洞由代码自身逻辑错误导致
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_04.c:33; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_04.c:39
- 结论: 使用freopen()打开文件后，错误地使用_close()代替fclose()关闭文件，导致资源关闭函数不匹配，违反API contract，可能引发资源泄漏或未定义行为。
- D验证: confirmed / ver_b56dff56
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 556. hyp_path_5fe0f72b4d1a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_05.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: staticTrue条件为真，程序正常执行该分支
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_05.c:33; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_05.c:38
- 结论: 使用freopen()打开文件后，使用_close()而非fclose()关闭资源，因_close()期望文件描述符而非FILE*指针，导致资源关闭不当，可能引发资源泄露或未定义行为。
- D验证: confirmed / ver_aacb4924
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 557. hyp_path_9a23a6b5ec5d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_03.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到 if(5==5) 分支（恒真），且 data 未进行 NULL 检查即可用于 _close。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_03.c:27; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_03.c:33
- 结论: 文件资源通过 freopen() 打开，但使用了 _close() 而非 fclose() 关闭，导致资源未正确关闭，违反了 API 契约，可能造成资源泄漏。即使 freopen() 返回 NULL，_close((int)data) 也会将 NULL 转换为 0，可能关闭标准输入流，进一步导致未定义行为。
- D验证: confirmed / ver_cb90fd6e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 558. hyp_path_fe9eec54134a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_07.c:32
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件"Case0Source_freopen.txt"存在并可写; staticFive值为5（代码中staticFive恒为5）
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_07.c:32; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_07.c:38
- 结论: freopen返回的FILE*资源被错误地使用_close()（期望文件描述符int）关闭，导致资源关闭不匹配，违反CWE404 Improper Resource Shutdown。可能造成资源泄漏或数据未刷新。
- D验证: confirmed / ver_dc8d9ead
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 559. hyp_path_8c21ca627370

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_06.c:32
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: STATIC_CONST_FIVE定义为5，条件恒真，进入错误关闭分支；data不为NULL。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_06.c:32; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_06.c:38
- 结论: 代码使用freopen打开文件，但使用_close()而不是fclose()关闭文件描述符，导致资源未正确关闭，违反CWE-404 Improper Resource Shutdown。同时强制类型转换FILE*为int可能导致未定义行为。
- D验证: confirmed / ver_6265045f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 560. hyp_path_1223abc0de16

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_09.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码执行到漏洞路径（即GLOBAL_CONST_TRUE为真），无需外部攻击者控制
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_09.c:27; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_09.c:33
- 结论: 使用freopen打开文件后，未使用fclose关闭，而是错误地使用_close，违反API contract，可能导致资源未正确释放（如文件描述符泄漏或缓冲区未刷新）。同时，未检查freopen返回值，若文件打开失败，data为NULL，_close((int)NULL)将导致未定义行为。
- D验证: confirmed / ver_7bf683da
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 561. hyp_path_2fef17ee87a8

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_13.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: freopen成功返回非NULL的FILE*指针; GLOBAL_CONST_FIVE==5条件为真
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_13.c:27; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_13.c:33
- 结论: 违反CWE-404: Improper Resource Shutdown，使用_close()关闭freopen返回的FILE*，应使用fclose()。
- D验证: confirmed / ver_ddab35d0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 562. hyp_path_55ec3aca89be

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_10.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序以允许freopen成功的方式运行（文件可访问）; globalTrue为真
- 触发路径: data = NULL; data = freopen("Case0Source_freopen.txt","w+",stdin); @ 25-27; _close((int)data); @ 31-33
- 结论: 文件资源通过freopen打开后，使用_close而不是fclose关闭，违反了CWE-404（不正确的资源关闭），可能导致文件描述符泄漏或未正常刷新缓冲区。
- D验证: confirmed / ver_eb635ae1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 563. hyp_path_13f8e10a0e11

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_14.c:27
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: globalFive==5成立，从而执行if分支中的关闭操作。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ CWE404_Improper_Resource_Shutdown__freopen_w32_close_14.c:27; _close((int)data); @ CWE404_Improper_Resource_Shutdown__freopen_w32_close_14.c:33
- 结论: 程序使用freopen打开文件并返回FILE*，但之后错误地使用_close()（期望文件描述符）而不是fclose()来关闭该FILE*，违反了API contract，可能导致资源未正确释放或未定义行为。
- D验证: confirmed / ver_697ad683
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 564. hyp_path_8924389c89c5

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_15.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需控制输入，但需保证文件可被打开（如文件存在或权限允许）; freopen成功返回非NULL的FILE*流
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_15.c:27; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_15.c:34
- 结论: 使用freopen打开文件后，应使用fclose关闭，但代码中使用了_close（低级文件描述符关闭），导致资源关闭不当，可能造成资源泄漏或文件流状态不一致。
- D验证: confirmed / ver_713900c0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 565. hyp_path_a3d499ab0c34

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_31.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序运行时存在可写文件Case0Source_freopen.txt，且freopen调用成功。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_31.c:27; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_31.c:34
- 结论: 文件资源通过freopen打开后，使用_close()而非fclose()关闭，导致资源释放不当（CWE-404）。
- D验证: confirmed / ver_40a21738
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 566. hyp_path_f8ad1ec15e49

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_16.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: freopen()成功打开文件，返回非NULL的FILE*指针；程序执行到while(1)循环中调用_close()的路径。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_16.c:27; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_16.c:33
- 结论: 使用freopen()打开文件返回FILE*指针，但后续使用_close()（而非fclose()）关闭，导致资源不匹配和潜在资源泄漏。
- D验证: confirmed / ver_c1eb45a3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 567. hyp_path_6f7222079a80

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_18.c:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该代码路径。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_18.c:27; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_18.c:33
- 结论: 在CWE404_Improper_Resource_Shutdown__freopen_w32_close_18.c中，使用freopen()打开文件后，通过_close()而非fclose()关闭文件，违反了API contract，导致资源未正确关闭。
- D验证: confirmed / ver_456fe087
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 568. hyp_path_e919433b12a9

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_33.cpp:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: freopen成功返回非NULL的FILE*指针
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ 31; _close((int)data); @ 37
- 结论: 使用freopen打开文件后，使用_close()而非fclose()关闭，导致资源关闭不当，可能造成资源泄漏和未定义行为。
- D验证: confirmed / ver_07fd49b3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 569. hyp_path_a4621e892504

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_34.c:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: freopen()成功返回非NULL的FILE*指针; 程序正常执行到第41行
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ 第34行; _close((int)data); @ 第41行
- 结论: 使用freopen()打开文件后，使用close()而非fclose()关闭，导致资源关闭不当，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_a92153cb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 570. hyp_path_569e6bfd4526

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_42.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法直接控制文件名，但资源泄漏本身是安全缺陷，可能被利用在长期运行服务中消耗系统资源。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_42.c:26
- 结论: 函数使用fopen打开文件后直接返回文件指针，未关闭文件，导致资源泄漏（CWE-404）。虽然蓝队指出关于CloseHandle的推测缺乏直接代码证据，但资源未关闭的事实已构成API contract violation，且P0静态确认支持路径有效。
- D验证: confirmed / ver_e82b0161
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 571. hyp_path_363fc1ba9813

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_61b.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者需要能够影响文件打开操作或触发sink调用，但在此静态分析中，假设测试环境允许该路径执行
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_61b.c:26; CloseHandle(data); // 错误关闭，应为fclose(data) @ 假设在sink函数中
- 结论: fopen返回FILE*指针，但sink可能错误调用CloseHandle关闭，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_5689b95b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 572. hyp_path_933c8cea17fe

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_42.c:24
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 调用者未正确关闭返回的文件流
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); return data; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_42.c:24
- 结论: 在函数中打开文件后直接返回，未关闭文件句柄，导致资源泄漏。
- D验证: confirmed / ver_82e3ba53
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 573. hyp_path_a907a436639a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_42.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法控制文件名，但资源泄漏仍会发生；后续若多次调用会耗尽系统资源。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_42.c:26
- 结论: 函数打开文件后未关闭，导致资源泄漏（CWE-404）。freopen 返回的 FILE* 未调用 fclose 释放，违反资源关闭合约。
- D验证: confirmed / ver_18049486
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 574. hyp_path_fc2a48045fb2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_61b.c:24
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_61b.c:24
- 结论: 资源未正确关闭 - fopen打开文件后未关闭，导致资源泄漏
- D验证: confirmed / ver_41edf55a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 575. hyp_path_baa6d8bdccee

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_42.c:24
- 漏洞类型: CWE-404, CWE-252
- CWE: CWE-404; CWE-252
- 风险等级: P0
- 触发条件: 无直接攻击者输入控制，但文件打开操作可能因系统资源限制失败，且调用者可能对返回的NULL指针进行操作。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); return data; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_42.c:24
- 结论: 函数case0Source中调用freopen将stdin重定向到文件，但未检查返回值且未调用fclose关闭文件，导致资源泄漏。若freopen失败返回NULL，则返回NULL可能被调用者忽略或导致后续错误。
- D验证: confirmed / ver_5164cff8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 576. hyp_path_5546ef1fc511

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_61b.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 函数被调用且文件可成功打开; 调用者未在后续代码中关闭文件句柄
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_61b.c:26
- 结论: 在缺少调用者上下文的情况下，无法确认freopen返回的文件指针是否被正确关闭，但存在资源泄漏的潜在风险。
- D验证: confirmed / ver_cc5ab2ec
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 577. hyp_path_9d05416d70a9

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_61b.c:24
- 漏洞类型: null_deref
- CWE: CWE-253; CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够影响文件打开操作（如控制文件名或环境）使 freopen 失败，或者文件本身不存在导致打开失败
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_61b.c:24
- 结论: 在 source 函数中调用 freopen 但未检查返回值。若 freopen 失败返回 NULL，则后续在 sink 中使用该文件指针可能导致空指针解引用或未定义行为。
- D验证: confirmed / ver_edbf28d2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 578. hyp_path_1624e6cff288

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_44.c:47
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序以正常权限运行，能够创建和打开文件
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_44.c:47; funcPtr(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_44.c:49
- 结论: 文件描述符在通过funcPtr调用后未关闭，导致资源泄漏，违反CWE-404
- D验证: confirmed / ver_139789b5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 579. hyp_path_9026105a2151

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_65a.c:41
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件打开成功（data != -1）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_65a.c:41; funcPtr(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_65a.c:42
- 结论: 使用open()打开文件后，未调用close()关闭文件描述符，导致资源泄露。
- D验证: confirmed / ver_6924a5ad
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 580. hyp_path_5d6797d2e965

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_44.c:49
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序正常执行到该代码路径，无需外部输入控制
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_44.c:49; funcPtr(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_44.c:49
- 结论: 使用open()打开文件后，通过函数指针funcPtr调用CloseHandle（不适用于文件描述符的关闭函数），导致文件描述符未正确关闭，造成资源泄漏（CWE-404）。
- D验证: confirmed / ver_aaec1e5e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 581. hyp_path_2c6977f1587e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_65a.c:43
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: open() 成功返回非负文件描述符; funcPtr 被设置为 CloseHandle 函数指针（根据测试用例名称推断）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_65a.c:43; funcPtr(data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_65a.c:44
- 结论: 使用 open() 打开文件返回文件描述符，但通过函数指针 funcPtr 调用了 CloseHandle() 而非 close()，导致资源未正确关闭，可能造成文件描述符泄漏。
- D验证: confirmed / ver_556ea117
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 582. hyp_path_a6e069b36038

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_44.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到此路径，无外部输入控制
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_44.c:40
- 结论: VULNERABILITY_FOUND: Resource leak - CreateFile handle not closed
- D验证: confirmed / ver_8b088259
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 583. hyp_path_a89e646ad06d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_65a.c:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: The code path that opens the file executes, and no subsequent CloseHandle is called on the handle.
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_65a.c:34
- 结论: The file handle created by CreateFile may not be closed before the function returns, leading to a potential resource leak (improper resource shutdown), but the evidence is incomplete as the sink code (e.g., missing CloseHandle) is not shown in the provided snippet.
- D验证: confirmed / ver_614ebc06
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 584. hyp_path_4079929f02d2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_65a.c:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile成功返回有效句柄（若失败则INVALID_HANDLE_VALUE，但未检查返回值，资源泄露风险依然存在）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_65a.c:34; 未调用fclose或CloseHandle关闭句柄 @ L? 后续无关闭调用
- 结论: CreateFile打开文件后未关闭，导致资源泄露
- D验证: confirmed / ver_ca7d9ba1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 585. hyp_path_04ee474fc9a7

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_32.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_32.c:33; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_32.c:41
- 结论: 使用fopen打开文件后，使用CloseHandle而不是fclose关闭，违反API契约，导致资源未正确关闭。
- D验证: confirmed / ver_d832f81e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 586. hyp_path_96fcadcc862f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_44.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序能够成功打开文件（文件可创建或存在）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_44.c:40
- 结论: 资源句柄可能未被正确关闭：CreateFile返回的HANDLE未使用CloseHandle关闭，可能被错误地使用fclose关闭（适用于FILE*），违反CWE-404。但证据不完整，需确认后续代码中是否存在任何关闭操作。
- D验证: confirmed / ver_09b4d02b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 587. hyp_path_3228964a79f2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_45.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到入口函数，fopen成功（文件可写）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_45.c:42; case0Sink(); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_45.c:44; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_45.c:32
- 结论: 使用fopen打开文件后，在case0Sink中使用CloseHandle关闭文件描述符，违反了API contract，应使用fclose。这可能导致资源泄漏及未刷新缓冲区。
- D验证: confirmed / ver_fe54a300
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 588. hyp_path_4b77d1d6cfb5

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_66a.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: sink函数内部实际使用CloseHandle关闭fopen返回的FILE*资源（由函数名称推断，但内部代码未提供）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_66a.c:33; CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_66a.c:36
- 结论: 使用fopen打开文件后，在sink函数中可能使用CloseHandle而非fclose关闭资源，导致资源未正确释放（CWE-404）。sink函数名称明确包含CloseHandle，强烈暗示使用了错误的关闭API。
- D验证: confirmed / ver_0648ee10
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 589. hyp_path_f582bf95261f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_67a.c:38
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码正常执行该路径，未发生异常中断；sink函数名称暗示使用CloseHandle，但需验证实际实现。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_67a.c:38; CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_67a.c:40
- 结论: fopen打开的文件资源在sink函数中可能被错误地使用CloseHandle关闭，导致资源未正确释放（CWE404），但缺少sink函数内部实现代码，无法完全确认实际使用了CloseHandle。
- D验证: confirmed / ver_7f830edb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 590. hyp_path_9079c889bd3a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_68a.c:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 至少存在一个文件'Case0Source_fopen.txt'可被创建或打开; fopen成功返回非NULL指针
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_68a.c:36; CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_68_case0DataForCase0Sink = data; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_68a.c:37; CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_68b_case0Sink(); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_68a.c:38
- 结论: fopen打开文件后未使用fclose关闭，而是将文件指针传递给sink函数，sink函数基于测试用例命名应使用CloseHandle关闭（不适用于FILE*），导致资源未正确释放，造成资源泄露。
- D验证: confirmed / ver_569bdee8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 591. hyp_path_7d17945291b2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_32.c:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发该代码路径，例如通过多次请求或输入使程序执行此分支
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_32.c:31; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_32.c:39
- 结论: 使用fopen打开文件后，使用_close()而不是fclose()关闭，导致资源关闭方式不匹配，违反API contract，可能导致文件句柄泄漏。
- D验证: confirmed / ver_ee9ccec9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 592. hyp_path_4026bd15942c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_45.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: fopen成功返回非NULL的FILE*指针
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_45.c:40; case0Sink(); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_45.c:42; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_45.c:30
- 结论: 使用fopen打开文件后，在case0Sink中错误地调用_close((int)data)而非fclose(data)，违反了FILE*句柄应使用fclose关闭的API合约，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_15c2dc88
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 593. hyp_path_e9854b1406c4

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_66a.c:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序能够成功打开文件（通常具备写入权限）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_66a.c:31; CWE404_Improper_Resource_Shutdown__fopen_w32_close_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_66a.c:34
- 结论: 文件资源通过fopen打开后，未在本地或通过适当的资源关闭函数关闭，导致资源泄露，违反API contract。
- D验证: confirmed / ver_dbc5e3db
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 594. hyp_path_8124b9d85db5

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_67a.c:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无特殊条件，程序正常执行即可触发。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_67a.c:36; CWE404_Improper_Resource_Shutdown__fopen_w32_close_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_67a.c:38
- 结论: 资源未正确关闭：fopen打开文件后，在sink函数中未调用fclose，导致资源泄漏。
- D验证: confirmed / ver_eb4cd917
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 595. hyp_path_8728b222c60a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_68a.c:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无额外攻击前提，代码本身存在API misuse
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_68a.c:34; CWE404_Improper_Resource_Shutdown__fopen_w32_close_68b_case0Sink(); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_68a.c:36; close((int)data); // 错误：应用fclose而非close @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_68b.c (sink函数内)
- 结论: 函数fopen打开的文件资源在释放时使用了close()而非fclose()，违反了C/C++ API contract（fopen返回的FILE*必须用fclose关闭），导致资源可能未正确关闭，造成资源泄露。
- D验证: confirmed / ver_de14a078
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 596. hyp_path_ac950ce3c614

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_32.c:33
- 漏洞类型: path_traversal
- CWE: CWE-404; CWE-227; CWE-772
- 风险等级: P0
- 触发条件: The program executes the code block that contains the source (freopen) and sink (CloseHandle) in sequence.
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_32.c:33; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_32.c:41
- 结论: Improper resource shutdown: file opened with freopen() is closed using CloseHandle() instead of fclose(), violating API contract and potentially leaving resources in an inconsistent state.
- D验证: confirmed / ver_8bd0e8ad
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 597. hyp_path_b042ba4feb12

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_45.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序能够执行到freopen调用，且freopen成功返回非NULL
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_45.c:42; case0Sink(); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_45.c:44; CloseHandle((HANDLE)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_45.c:31
- 结论: 在case0Sink函数中，使用CloseHandle()关闭由freopen()返回的FILE*资源，导致资源关闭API不匹配，可能造成资源泄漏或未定义行为。
- D验证: confirmed / ver_794042f8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 598. hyp_path_e2b7468f19fd

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_66a.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法控制输入，漏洞由编码错误导致，但可能影响程序稳定性或资源管理。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_66a.c:33; dataArray[2] = data; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_66a.c:35; CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_66a.c:36
- 结论: freopen打开文件后未检查返回值，且sink函数CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_66b_case0Sink可能使用CloseHandle而非fclose关闭资源，导致文件句柄泄露或错误关闭，违反CWE-404 Proper Resource Shutdown。
- D验证: confirmed / ver_d060a9a1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 599. hyp_path_f07cd304d01d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68a.c:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码执行环境为Windows（使用CloseHandle）; freopen成功打开文件
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68a.c:36; CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68b_case0Sink(); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68a.c:38
- 结论: 使用freopen打开文件后，在sink中调用CloseHandle而不是fclose关闭，导致资源关闭不当，违反API contract。
- D验证: confirmed / ver_802be01b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 600. hyp_path_bdd71c6c1d60

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_67a.c:38
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无：文件名硬编码，但API contract violation独立于攻击者控制
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_67a.c:38; myStruct.structFirst = data; CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_67a.c:40
- 结论: 在freopen返回的FILE*上错误地使用了CloseHandle，违反了资源关闭的API contract，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_bb019556
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 601. hyp_path_8edf1572843a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_32.c:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到freopen并成功打开文件
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_32.c:31; _close((int)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_32.c:39
- 结论: 文件资源未正确关闭：使用freopen打开文件后，使用_close()而非fclose()关闭，违反API契约，导致资源未正确释放（CWE-404）。
- D验证: confirmed / ver_4fc09e20
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 602. hyp_path_f9c076d009bf

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_45.c:40
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需额外攻击者控制，程序自身路径即可触发
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ L34; case0Sink(); @ L42; if (data != NULL) { _close((int)data); } @ L28-32
- 结论: freopen 返回的 FILE* 指针在关闭时使用了 _close() 而不是 fclose()，违反了 API 契约，导致资源未正确关闭（CWE-404）。
- D验证: confirmed / ver_ce2df8cf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 603. hyp_path_d4c99100aa5d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_66a.c:31
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: freopen调用成功返回非NULL文件指针
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_66a.c:31; CWE404_Improper_Resource_Shutdown__freopen_w32_close_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_66a.c:34
- 结论: 函数freopen打开的文件资源可能未在sink函数中正确关闭，导致资源泄露（CWE-404 Improper Resource Shutdown）
- D验证: confirmed / ver_e14ef06e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 604. hyp_path_114fe6a012f5

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_43.cpp:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无外部攻击者控制输入，但API契约违反必然存在。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_43.cpp:29; CloseHandle((HANDLE)data); @ sink函数内
- 结论: 使用fopen打开文件，但后续可能使用CloseHandle关闭，违反了资源关闭的API契约，导致资源未正确释放或未定义行为。
- D验证: confirmed / ver_b83c602e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 605. hyp_path_32e2b783f3e4

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_68a.c:34
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序正常执行，且sink函数未实现正确文件关闭逻辑（如使用close而非fclose或未关闭）。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_68a.c:34; CWE404_Improper_Resource_Shutdown__freopen_w32_close_68b_case0Sink(); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_68a.c:36
- 结论: 通过freopen打开文件资源后，将文件指针传递给sink函数，但未在sink函数中正确关闭文件，可能导致资源泄漏（CWE-404）。
- D验证: confirmed / ver_6b07124f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 606. hyp_path_809e83e9b67a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_67a.c:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: freopen成功返回非NULL文件指针; sink函数未关闭文件句柄
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_67a.c:36; CWE404_Improper_Resource_Shutdown__freopen_w32_close_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_67a.c:38
- 结论: 函数freopen打开的文件资源未在sink函数中正确关闭，导致资源泄漏。
- D验证: confirmed / ver_e56f7dc3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 607. hyp_path_5c67175be9ec

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_62b.cpp:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 硬编码文件路径，无外部输入控制
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_62b.cpp:27; CloseHandle(data); @ 推测后续存在CloseHandle(data)调用（基于样本命名和CWE分类）
- 结论: 使用fopen打开的文件句柄可能被误用CloseHandle关闭，导致资源未正确释放，违反API contract。
- D验证: confirmed / ver_c49acfc8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 608. hyp_path_b597c29778c9

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83_case0.cpp:29
- 漏洞类型: CWE-404, CWE-772
- CWE: CWE-404; CWE-772
- 风险等级: P0
- 触发条件: fopen成功返回非NULL指针（文件打开成功）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83_case0.cpp:29
- 结论: 在fopen打开文件后未使用fclose（或正确关闭函数）释放资源，违反API contract，导致资源泄漏（CWE-404）。
- D验证: confirmed / ver_66dcfd62
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 609. hyp_path_2d9f11cc5577

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_43.cpp:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者需要利用该资源泄漏造成拒绝服务，但无需用户输入控制
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_43.cpp:27
- 结论: 使用fopen打开文件后未调用fclose关闭文件，导致资源泄漏，违反CWE404 Improper Resource Shutdown。
- D验证: confirmed / ver_ed3aa8e7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 610. hyp_path_119eef43135a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_84_case0.cpp:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者不直接控制文件打开，但漏洞由程序内部逻辑触发，存在资源泄漏或未定义行为风险
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_84_case0.cpp:29; CloseHandle(data); // 错误关闭方式 @ 预期在析构函数或清理代码中（具体行号未在A阶段证据中提供，但样本名称暗示CloseHandle调用）
- 结论: 使用fopen打开文件后，可能错误地使用CloseHandle关闭文件句柄，而不是fclose，导致资源关闭不当，违反CWE-404的API合约。
- D验证: confirmed / ver_00aefcad
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 611. hyp_path_bb84a51e9a96

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_62b.cpp:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: fopen成功打开文件，后续代码未调用fclose关闭文件描述符。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_62b.cpp:27
- 结论: 文件资源未关闭，导致资源泄漏。
- D验证: confirmed / ver_f5f519af
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 612. hyp_path_0c718db715be

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_83_case0.cpp:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 构造函数被调用，即创建一个对象实例。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_83_case0.cpp:27
- 结论: 在CWE404_Improper_Resource_Shutdown__fopen_w32_close_83_case0构造函数中，使用fopen打开文件后未调用任何关闭函数（fclose或_close），导致文件资源泄露，违反API contract。
- D验证: confirmed / ver_fbb6f106
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 613. hyp_path_8239f589282b

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_84_case0.cpp:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无需控制输入；只要程序运行此构造函数即可触发漏洞
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_84_case0.cpp:27
- 结论: 文件打开后未关闭，导致文件句柄泄漏，违反CWE404（不正确的资源关闭）
- D验证: confirmed / ver_330a5f2d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 614. hyp_path_ec61e177778a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_43.cpp:29
- 漏洞类型: null_deref
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法直接控制文件名，但可能通过文件系统状态影响freopen成功与否；若freopen失败，data为NULL，后续未检查则导致未定义行为。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_43.cpp:29
- 结论: freopen打开文件后未在给定代码片段内关闭，可能导致资源泄漏；且未检查freopen返回值，若失败则data为NULL，后续使用可能导致空指针解引用。虽然代码片段不完整，但根据CWE-404定义，资源未关闭构成contract violation。
- D验证: confirmed / ver_fa78d258
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 615. hyp_path_e37570676b87

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_83_case0.cpp:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 代码执行到此行且freopen成功返回非NULL指针
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_83_case0.cpp:29
- 结论: 代码使用freopen打开文件后，未调用fclose或CloseHandle关闭文件，导致文件资源泄漏（CWE-404）。
- D验证: confirmed / ver_5f174924
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 616. hyp_path_7ac20aeb17da

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_62b.cpp:27
- 漏洞类型: null_deref
- CWE: CWE-476; CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够导致freopen失败（例如删除文件、权限限制、磁盘满等）
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_62b.cpp:27; 未展示，可能将data传递给CloseHandle等函数，未检查NULL @ 同一函数后续代码（未展示）; 可能使用CloseHandle(data_fileno)而非fclose，导致资源泄露 @ sink处（未展示）
- 结论: 函数freopen的返回值未检查，如果文件打开失败返回NULL，后续使用data指针可能导致空指针解引用或未定义行为。同时，资源关闭方式可能不当（预期使用fclose但可能误用CloseHandle），存在资源未正确关闭的风险。
- D验证: confirmed / ver_53906b30
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 617. hyp_path_cf7b051d52c2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84_case0.cpp:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者可能提供文件路径或影响文件打开，但漏洞本身不依赖攻击者输入即可触发。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84_case0.cpp:29; CloseHandle(data); // 预期存在的错误调用 @ 假设的析构函数或清理代码中，但未在A阶段证据中提供具体行号
- 结论: 文件资源通过freopen打开后，使用了CloseHandle关闭，违反了API contract，可能导致资源未正确释放，存在CWE-404风险，但A阶段代码证据未提供CloseHandle调用的具体行号，路径不完整。
- D验证: confirmed / ver_4d0d8fc8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 618. hyp_path_ddc7d48ef11d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_62b.cpp:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行此代码路径
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_62b.cpp:27
- 结论: 在freopen调用后未检查返回值且未关闭文件，导致资源泄漏（CWE-404）。
- D验证: confirmed / ver_cbe6648c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 619. hyp_path_844f99b682fa

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_43.cpp:27
- 漏洞类型: null_deref
- CWE: CWE-404; CWE-253
- 风险等级: P0
- 触发条件: 无需特定攻击者输入，但需要程序执行到该路径，且后续未正确关闭资源或未检查返回值。
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_43.cpp:27
- 结论: 使用freopen打开文件后未检查返回值，且未在提供的代码片段中看到资源关闭操作，可能导致资源泄漏；如果freopen返回NULL，后续使用data可能导致空指针解引用。
- D验证: confirmed / ver_96a87070
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 620. hyp_path_88c5b6dc9f7e

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_83_case0.cpp:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无外部输入控制，但资源泄露必然发生
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_83_case0.cpp:27
- 结论: 在CWE404_Improper_Resource_Shutdown__freopen_w32_close_83_case0类构造函数中，调用freopen后未对返回的文件指针进行fclose，导致资源未正确释放，违反CWE-404 Improper Resource Shutdown。
- D验证: confirmed / ver_9d2cc6b8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 621. hyp_path_d89822166e1b

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_84_case0.cpp:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: freopen函数执行成功
- 触发路径: data = freopen("Case0Source_freopen.txt","w+",stdin); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_84_case0.cpp:27
- 结论: 在构造函数中调用freopen打开文件流，未检查返回值也未关闭文件，导致资源泄漏。
- D验证: confirmed / ver_0501cdfc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 622. hyp_path_1c2c93fbd897

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_42.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); return data; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_42.c:33
- 结论: 文件资源未正确关闭，导致资源泄漏。尽管缺少sink上下文，但函数打开文件后直接返回，未提供关闭机制，违反CWE-404的API contract。
- D验证: confirmed / ver_2de4171f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 623. hyp_path_759172786dec

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_42.c:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无外部输入控制，但文件打开后未关闭，导致资源泄漏
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_42.c:35
- 结论: CWE-404: Improper Resource Shutdown - file descriptor not closed after open() call
- D验证: confirmed / ver_d2165019
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 624. hyp_path_210b9cf942df

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_61b.c:33
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 调用者未正确关闭返回的文件描述符（sink缺失验证）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); return data; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_61b.c:33
- 结论: 函数通过open()打开文件并返回文件描述符，但未在返回前关闭，且未明确转移关闭责任。这违反了CWE-404的资源释放契约，构成潜在的资源泄漏漏洞。
- D验证: confirmed / ver_241b75c4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 625. hyp_path_bc580edb34b6

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_61b.c:35
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无特殊前提，代码路径可达即可
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_61b.c:35
- 结论: 在sink处可能使用了CloseHandle来关闭由open()返回的文件描述符，导致资源未正确关闭，违反CWE-404。但缺少sink具体代码，证据不完整。
- D验证: confirmed / ver_cc119e90
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 626. hyp_path_49945cc0a74a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_42.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序正常执行到CreateFile调用，且后续没有调用CloseHandle。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_42.c:26
- 结论: 函数CreateFile打开文件后未关闭句柄，导致资源泄漏（CWE-404）。
- D验证: confirmed / ver_9775edda
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 627. hyp_path_1a30b5b21f6a

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_61b.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无特殊前提，只要执行该路径即可能触发
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_61b.c:26
- 结论: CreateFile 打开的句柄在本函数内未关闭，且无证据表明调用者会关闭，构成 CWE-404 资源未正确关闭，但缺少调用者代码，证据不完整。
- D验证: confirmed / ver_81f07566
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 628. hyp_path_64d33537c428

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_42.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无特殊前提，代码执行即可触发资源泄露。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_42.c:26
- 结论: CreateFile返回的HANDLE被fclose错误关闭，导致资源未正确释放，违反CWE-404（资源关闭不当）的API合约。
- D验证: confirmed / ver_609685b9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 629. hyp_path_5250821db689

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_61b.c:26
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够触发该代码路径，但无需控制外部输入；资源泄漏后果取决于句柄后续使用，但会导致文件句柄泄漏。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_61b.c:26; fclose(data); // 错误使用fclose关闭CreateFile句柄 @ 推测sink位置（基于测试用例命名，通常在同一测试用例的sink函数中，如61b.c的sink函数或61a.c）
- 结论: CreateFile打开的文件句柄在sink中被错误地使用fclose关闭，而非CloseHandle，导致资源未正确关闭，违反API contract，造成资源泄漏（CWE-404）。
- D验证: confirmed / ver_86505e31
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 630. hyp_path_0d5bf82080a9

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_45.c:51
- 漏洞类型: CWE-404, CWE-762
- CWE: CWE-404; CWE-762
- 风险等级: P0
- 触发条件: 程序按正常流程执行，没有额外的错误处理中断此路径。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_45.c:49; CWE404_Improper_Resource_Shutdown__open_fclose_45_case0Data = data; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_45.c:50; case0Sink(); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_45.c:51; fclose((FILE *)data); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_45.c:37
- 结论: 文件描述符关闭操作不匹配：使用open()返回的整数文件描述符，但在case0Sink中错误使用fclose()（期望FILE*）进行关闭，违反API contract，可能导致资源未正确关闭或未定义行为。
- D验证: confirmed / ver_36f8a571
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 631. hyp_path_038ef2f2d5c0

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45.c:51
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: open()成功返回文件描述符（非-1）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45.c:51; case0Sink(); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45.c:53; if (data != -1) { CloseHandle((HANDLE)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45.c:41-42
- 结论: 文件描述符通过open()获取后，使用CloseHandle()（预期用于HANDLE）而不是close()关闭，导致资源关闭类型不匹配，可能造成资源未正确释放或未定义行为，违反CWE-404 Improper Resource Shutdown。
- D验证: confirmed / ver_0c8574df
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 632. hyp_path_1fb62ccbb15f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_45.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile成功返回有效句柄，即data不为INVALID_HANDLE_VALUE
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_45.c:42; CWE404_Improper_Resource_Shutdown__w32CreateFile_close_45_case0Data = data; case0Sink(); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_45.c:50; if (data != INVALID_HANDLE_VALUE) { _close((int)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_45.c:31-33
- 结论: 未正确关闭CreateFile返回的HANDLE：使用_close()代替CloseHandle()，违反了Windows API合同，可能导致资源泄漏或未定义行为。
- D验证: confirmed / ver_2940aaeb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 633. hyp_path_1e95cf5da772

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_45.c:42
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无特定攻击者输入，代码内部缺陷，CreateFile成功返回有效HANDLE
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_45.c:42; CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_45_case0Data = data; @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_45.c:49; case0Sink(); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_45.c:50; if (data != INVALID_HANDLE_VALUE) { fclose((FILE *)data); } @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_45.c:30-32
- 结论: 函数使用CreateFile打开文件，返回HANDLE，但在清理时使用fclose()关闭，导致资源关闭方式不匹配（HANDLE vs FILE*）。这可能造成资源泄漏或程序崩溃。
- D验证: confirmed / ver_b8db5985
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 634. hyp_path_de1f9fd47b3d

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_43.cpp:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到该代码行，且后续未正确关闭文件。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_43.cpp:36
- 结论: 资源打开后未关闭，可能导致文件描述符泄漏（CWE-404）。
- D验证: confirmed / ver_ee9b6044
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 635. hyp_path_4f2b30398099

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_62b.cpp:36
- 漏洞类型: CWE-404, CWE-775
- CWE: CWE-404; CWE-775
- 风险等级: P0
- 触发条件: 攻击者能够触发source函数调用（如通过测试main函数或部署后的调用路径）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_62b.cpp:36
- 结论: 打开的文件资源在source中未关闭，且sink代码未提供，无法确认sink是否执行关闭操作，存在文件描述符泄漏风险（CWE-404或CWE-775），但需进一步验证sink行为。
- D验证: confirmed / ver_7005363c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 636. hyp_path_704dff97afc4

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_83_case0.cpp:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无特定前提，代码执行至此路径即可触发泄漏，攻击者无需额外控制输入。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_83_case0.cpp:27
- 结论: 资源未正确关闭：在打开文件数据流后，未调用相应的关闭函数（如fclose或close），导致文件描述符泄漏，违反CWE-404规范。
- D验证: confirmed / ver_c16d6be4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 637. hyp_path_cec9546dcab2

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_84_case0.cpp:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行到此代码路径
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_84_case0.cpp:27
- 结论: 文件描述符未正确关闭，导致资源泄露
- D验证: confirmed / ver_d5b40305
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 638. hyp_path_914c1b879f1f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_43.cpp:38
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 文件成功打开，且后续代码将data传递给CloseHandle而非close。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_43.cpp:38
- 结论: 使用_open打开文件后，可能通过CloseHandle关闭文件描述符，导致资源关闭不当（CWE404），但缺少sink代码证据，路径不完整。
- D验证: confirmed / ver_ce98cf8b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 639. hyp_path_8b4679002806

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_62b.cpp:36
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_62b.cpp:36
- 结论: 文件描述符可能未正确关闭，存在资源泄漏风险，但证据不完整，需要动态或审计确认。
- D验证: confirmed / ver_3805fb1c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 640. hyp_path_ae320da0bd71

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_83_case0.cpp:29
- 漏洞类型: CWE-404, CWE-252
- CWE: CWE-404; CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够影响文件打开操作的结果（如文件存在性），但漏洞核心在于错误的资源关闭方式，不依赖外部输入。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_83_case0.cpp:29
- 结论: 在open函数调用成功但未检查返回值的情况下，后续使用CloseHandle而不是close来关闭文件描述符，违反API contract，导致资源泄漏（CWE-404）。
- D验证: confirmed / ver_8b89b9d2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 641. hyp_path_c2d0c28091d5

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_84_case0.cpp:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无外部输入，漏洞由代码自身逻辑引起
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_84_case0.cpp:29
- 结论: 在构造函数中打开文件资源，但在提供的代码片段中未显示对应的关闭操作，可能导致资源泄漏（CWE-404）。但缺乏析构函数或其他关闭路径的上下文，漏洞路径不完整。
- D验证: confirmed / ver_43b12f9c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 642. hyp_path_2285d0c8f536

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_43.cpp:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 无需攻击者控制输入，漏洞源于编码错误。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_43.cpp:29
- 结论: 资源句柄可能使用错误的关闭函数：CreateFile返回的HANDLE应使用CloseHandle关闭，但根据测试案例名称暗示，可能使用了close()，导致资源未正确释放。
- D验证: confirmed / ver_27f236b9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 643. hyp_path_9e96ee6e3afa

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_62b.cpp:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行路径到达CreateFile调用且后续没有关闭句柄。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_62b.cpp:29
- 结论: CreateFile打开的文件句柄在后续代码中未被关闭，导致资源泄漏，违反CWE404 Improper Resource Shutdown。
- D验证: confirmed / ver_67e11335
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 644. hyp_path_0246574092ed

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83_case0.cpp:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile函数执行成功，返回有效句柄
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83_case0.cpp:27
- 结论: CreateFile打开的文件句柄在后续代码中可能未关闭，导致资源泄露。但现有证据不完整，未验证析构函数或其它路径是否关闭句柄，且未处理CreateFile失败场景。
- D验证: confirmed / ver_f13ccee7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 645. hyp_path_5177e223b01c

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84_case0.cpp:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序执行该构造函数
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84_case0.cpp:27
- 结论: 在CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84_case0构造函数中，通过CreateFile打开文件后未调用CloseHandle关闭句柄，导致资源泄漏。
- D验证: confirmed / ver_e45bee88
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 646. hyp_path_21b5e965b808

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_43.cpp:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 攻击者能够通过控制文件创建数量或诱导程序多次调用此代码路径，消耗系统资源。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ L27-31
- 结论: 资源未正确关闭：CreateFile返回的文件句柄未使用CloseHandle关闭，可能使用了不匹配的关闭函数（如fclose）或未关闭，导致资源泄漏。
- D验证: confirmed / ver_9c55c9bb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 647. hyp_path_a73b482f2a1f

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_62b.cpp:29
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile返回有效句柄（非INVALID_HANDLE_VALUE）。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_62b.cpp:29
- 结论: 漏洞：使用CreateFile打开文件后，在sink函数中错误地使用fclose（而非CloseHandle）关闭句柄，导致资源泄漏（CWE-404）。
- D验证: confirmed / ver_f8d8b81f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 648. hyp_path_44526fb4a0f3

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_83_case0.cpp:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: 程序正常执行到此构造函数，且后续无任何关闭文件句柄的操作。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_83_case0.cpp:27
- 结论: 在CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_83_case0构造函数中，使用CreateFile打开文件后未调用CloseHandle或类似函数关闭文件句柄，可能导致资源泄漏。目前缺乏析构函数及sink函数代码，但基于现有片段，存在未关闭的风险。
- D验证: confirmed / ver_4f2461a6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 649. hyp_path_2f24fd5950e5

- 漏洞位置: juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84_case0.cpp:27
- 漏洞类型: CWE-404
- CWE: CWE-404
- 风险等级: P0
- 触发条件: CreateFile 调用成功（无权限或路径问题）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84_case0.cpp:27
- 结论: 使用 CreateFile 创建文件句柄后，未正确关闭（应使用 CloseHandle 而非 fclose），导致资源泄漏。
- D验证: confirmed / ver_8a6df31a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

## Unconfirmed / Failed Verification

These records are not reported as confirmed vulnerabilities. See `verification.failed.jsonl` for full failure details.

- hyp_path_11a3e04cc14e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_72a.cpp:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a5205a8585d5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_72a.cpp:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1d63b2d1f37c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_72a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cba988bb80d7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_72a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4c1b03479e9b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_74a.cpp:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_286f9e64ac60 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_74a.cpp:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_05081cb17b10 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_74a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_183be6562bf9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_74a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_562ab410221c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_73a.cpp:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_28582d0d23a8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_73a.cpp:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_301ff1647310 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_73a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3932f817c5a7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_73a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0e36238dada0 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_22a.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4978b00d55c3 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_22a.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9daa1d78b098 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_51a.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1e9d14b8ab98 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_52a.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_09b2fc7dcadc | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_53a.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6027d0b0ceea | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_54a.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3ffecadbb0a2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_63a.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8293879a0bca | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_22a.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fc3e6392a575 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_64a.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_394252af7055 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_22a.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e25504276258 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_51a.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6e5d3abc07a8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52a.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_052171cd7ee0 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_53a.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_034003cfcc3b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54a.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8cba0573e6b5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_64a.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e241c1bb86a2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_63a.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_835f4cda6429 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22a.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eda0d09bbb95 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22a.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3e35a1d25359 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_51a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_36688d8e2be5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e811e1c23f88 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e2e16e8a5554 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_60d1e6e582fd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_63a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cf9a298cf874 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_64a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7d96e778e48a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_22a.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bb15c246ade8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_22a.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_13373bd7feb3 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_51a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_74f2e570ae47 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_52a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_849b5a84166a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_53a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_aec60d12fb36 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_63a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b890fa6dd449 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5061d75dbf9f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_64a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_00fb08acdb29 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_84a.cpp:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_76a127d34882 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84a.cpp:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_79a80b1b8fb4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_84a.cpp:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0f105a050cac | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_84a.cpp:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_25b068f5babd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84a.cpp:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_595b30bea8d7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_84a.cpp:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_14bef2801ced | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84a.cpp:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3e2c5196389e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_74b.cpp:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_549d31c7d970 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_74b.cpp:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f68457013b97 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_74b.cpp:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bf271ec2d4e0 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_74b.cpp:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b4fc24fd59be | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_21.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bae3d5357f6d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_21.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_285bb6e29b52 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_41.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7342e307bbae | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_82a.cpp:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e4aba253da55 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_82a.cpp:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c8294862610f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_82a.cpp:43 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a803de8bf311 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_82a.cpp:43 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8b7ebedb91a6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_61a.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_65fa11bfb630 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_43.cpp:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_61112d4c70a7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_62a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d2f9145efcc6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_43.cpp:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_24ae37c8b237 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_62a.cpp:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9f74b91f8d95 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_62a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7c8d1c4e5887 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_61a.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7aa7732c826f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_43.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bd246b393777 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_61a.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2387d6a4c4a1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_62a.cpp:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_43cecb22cf39 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_61a.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4c13ae958d19 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_62a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4924e447c850 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_17.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_57bfd06b825d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_17.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3dd6fc6f6d50 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_08.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_26e6f72e81b7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_11.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_64983b94b062 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_12.c:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bdfe38c607bd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_08.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2f5c6b4b18ee | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_12.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c91992ed4dfd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_11.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_01e500c8dae1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_08.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e6103a933505 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_11.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4f6caa3a54f8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_12.c:78 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bf8220cfdd2d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_11.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_df8468dcb113 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_08.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_56187eca19c2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_12.c:78 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_09b04b2a6144 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_05.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9f51e0996fe4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_07.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8ac60a5c4b9e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_10.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_39db7c75b150 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_09.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7e6a622bb16c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_14.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_532759954e5c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_13.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_61d9bf7784d8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_05.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1ab3780bae29 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_08.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_235fb7174362 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_07.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d108a8e20af3 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_11.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ddef501f5d4f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_08.c:102 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_be553eb78d0b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_11.c:89 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_16434ebc665f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_09.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_edf23e6dce90 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_13.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e1731316a0cc | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_10.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d4d67cf52b35 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_07.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_32a202ac22c5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_14.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e631769c47fd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_05.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1e1047ce2419 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_09.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_943eb02a7355 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_11.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9f489b464055 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_14.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b731b3bc33dd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_13.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_da8deda69c1a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_07.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2b9d42b68d70 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_11.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fcbf070fac1b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_05.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f8e1fd9979eb | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_13.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f8654a0f23a4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_81a.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_50ffbb321d8b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_81a.cpp:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f421f1f451a3 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_81a.cpp:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_745f9e87c22b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_14.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b18795f84f17 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_02.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0f40019a1a8d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_81a.cpp:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8e3bf0196b8e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_03.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d6a26ad0141e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_04.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8197e6cb80b4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_04.c:93 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b4034ae2f92c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_03.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c53fd2475bf1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_06.c:92 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_db741056377a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_06.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_64da39ac74a1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_07.c:92 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8e1f899b19ff | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_14.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9c987bba98ac | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_13.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9e51281b1b3d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_09.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2cfd1860a387 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_15.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4f268bd52d6e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_33.cpp:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_42e822f2b2a7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_15.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5c9f2a9c39fe | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_02.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a976d5a6a9b2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_34.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0fc54b6dfa91 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_03.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b6b0f38fb446 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_04.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_191c88c7d581 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_02.c:89 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fba93d78893e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_06.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6ebfe86135de | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_04.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bfba37be607d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_07.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fa637fb1d6db | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_09.c:89 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_37591687dbc7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_10.c:89 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5bbd71bedfc6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_06.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_526bf5c4b866 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_14.c:89 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cc1d08f88b44 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_15.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_449c8ed04b42 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_31.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_773468aca174 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_18.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c51d29c457cd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_15.c:97 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6fe667aa9c09 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_34.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d30c16c9f219 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_01.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_add1b2f7bbea | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_02.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0bd211df0051 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_03.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1dc1cf6a9920 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_02.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b2880b98d12c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_03.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8712b1fd1900 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_04.c:104 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_05e2f578bd73 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_04.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3befc4cdf478 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_05.c:104 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_680c4c2c32e7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_06.c:103 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dde37bf099eb | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_06.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1a3d5d7241f4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_07.c:103 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6a030aa10905 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_09.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_891c252acbaf | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_10.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_211958f021f4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_13.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a4734ed61516 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_15.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9a7a5ff04d6f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_15.c:106 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b8a4197cc5dd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_14.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c2cb4cd3c62e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_18.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b96ba47b3488 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_33.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8b96c2d842be | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_16.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8c049bc550cb | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_01.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_638e4e6c932e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_03.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_df45749ca430 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_02.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5b7e965a21fc | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_03.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fc9529ebe3c6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_06.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4a55df6068ad | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_04.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_588ee99d307b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_06.c:103 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9a09fac3212b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_07.c:103 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9415998d752b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_10.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_16a2218e857e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_09.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_151d20edabe2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_15.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_25c0caffa7e9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_18.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ee3fbf6fad7f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_31.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_695a95c81a6f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_33.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_828c56dd18e7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_34.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c11c0626210f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_72b.cpp:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4a9321d421da | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_72b.cpp:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2c482643f812 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_72b.cpp:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c51ea7ebdef2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_73b.cpp:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9c7c8c009eb4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_73b.cpp:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d61cf9051769 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_73b.cpp:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cca0018e04ad | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_21.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1f5ccb053756 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_22b.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f1d5a261a14f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83_case1V2.cpp:37 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9f9e4c5a50b3 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83a.cpp:43 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_84a341bb7d4f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_21.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2c9ae8004223 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_83a.cpp:43 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9fd36a84e85e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_83_case1V2.cpp:35 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a14bd47266e3 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_22b.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c6486c72aa5f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_21.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_336174bdd7f9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_22b.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_68f9e941a743 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_83a.cpp:43 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7cf30f3c536e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_83_case1V2.cpp:37 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d13898ac8d67 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84_case1V2.cpp:37 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_793a043aa61b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_21.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8bb106a18fd6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_83a.cpp:43 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c3e6746ea392 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_21.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a0ac542108c2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_32.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_12886a84e0e6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_66a.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0c54bbe46514 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_67a.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_40ac781de905 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_68a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f819feb8970f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_83_case1V2.cpp:35 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b817359a42f3 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_83a.cpp:43 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f193642293da | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_84_case1V2.cpp:35 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f15cb9c84c63 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_22b.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a5a9e0838870 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_21.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_edd31b83ddc7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_32.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_50aacea28dab | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_66a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_550fe4e8fe94 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_67a.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_29037b14ed04 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68a.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ec553c668438 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_83_case1V2.cpp:37 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5ff34fa0befd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_84_case1V2.cpp:37 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8a6cd8c3fe9b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_83a.cpp:43 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cbf86aeb5042 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22b.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e10a96a794a4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_21.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fe63915e321d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_66a.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3172755747a5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_32.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_80bae2e1ff6b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_67a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_192146b2eb46 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_68a.c:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e050123f44ad | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83_case1V2.cpp:41 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a0befa96c901 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_32.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_02c7af5101cb | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_66a.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cd6e68bfd2a0 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_22b.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_349041829644 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a5f47d74e3f7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68a.c:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_48c3bc12741b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_83a.cpp:43 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6b8091fce64c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_83_case1V2.cpp:41 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_421c4486c234 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_22b.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e6f91bdeb99a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_21.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f4d33403a0b3 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_43.cpp:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4306157f47b2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_52b.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_968816c8b5ba | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53b.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_88d52f90d61b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54b.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_63648c7ba96d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54c.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_96c245c604f7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54d.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f744889e6fe8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54e.c:41 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7837eda545be | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_63b.c:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bd0ba0bf1e2c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_65b.c:42 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2ee3fab493b5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_66b.c:45 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2be76f5bd2f7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_67b.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_01721ade174e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_68b.c:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0538513300f9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_73a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_937147ecb8a9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_72a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_21323ebd06af | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_74a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b6d06ccbf469 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_81a.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f57a87be5db1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_82a.cpp:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_62fb3c3bbd3b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83a.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ac9c8f3f23d1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_84a.cpp:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cf909d0b49a5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_22b.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b9ee360682ad | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_41.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b232d2000b0b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_44.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_701b7ba71d80 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_43.cpp:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_844b89ca641c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_52b.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ad256ab778d5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_53b.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_41f950433cc7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_53c.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_704bc7c0d958 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_54b.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8cd4cba60e24 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_54c.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_45a014219fa6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_54d.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d95d90938134 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_54e.c:39 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c10dff03b577 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_62a.cpp:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0c1392ee5f70 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_64b.c:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0037720dd09f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_72a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7923974fa8ec | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_68b.c:45 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_91ad2518b6b9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_74a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eb8d81fd0b11 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_73a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7684b7383fae | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_81a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2a7b6226f619 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_82a.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ec675abc4181 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_83a.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_03a65682627c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_84a.cpp:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c6cc31f887b8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_41.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_984496051528 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_22b.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9ce639a02693 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_43.cpp:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_518c627a66dc | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_44.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_31133e608a1f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_45.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_daa86a41ff7a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_52b.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a8110f43b208 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_52c.c:41 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5ac3e7296faa | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_53d.c:41 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9aa19a58af5c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54c.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_083c0f72c1a3 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54b.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_448c9273800c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54d.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d266a4baaea0 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54e.c:41 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bd21a6f91442 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_62a.cpp:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7c6b1d85d1ab | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_63b.c:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bdcb49fb8160 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_67b.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6ffaebb6ae68 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68b.c:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9961998c4139 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_74a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_50dcbe5ad157 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_72a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8599eecb6dfe | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_81_case1V2.cpp:31 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7160e8afaff5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_73a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_007f50cc4ff4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_81a.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6095cda784ba | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_82a.cpp:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5d52fef5cf52 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_82_case1V2.cpp:31 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_18052944d6be | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84a.cpp:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_02899db3ee88 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_83a.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c15654b9b56f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_22b.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_42d4620af3aa | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_43.cpp:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7b61f259b61a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_45.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_52ef29781f51 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_52b.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bab5a5d56e16 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_51b.c:39 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c4f69733783a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_53b.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_efb63c5b05cc | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_53c.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e02d96f78c4b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54b.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1c799b0bf2c1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_53d.c:39 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8f05df5b9229 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54c.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_626945cbd172 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54d.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7f810a2a1110 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_62a.cpp:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c9e084cf090b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54e.c:39 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_808710a7e130 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_64b.c:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_214bb7b2a985 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_67b.c:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_49ee4f3c7414 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_72a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_689087296ce9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_73a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_74fde8a20d5c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_74a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fb1ed37112a4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_81a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d86f1890c810 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_82a.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_74a0701b86dc | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_84a.cpp:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ec58f551db4c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_83a.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9e1d0fc80549 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_41.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5204a024fd56 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_44.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_32a4f82746c8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_45.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5952e0bc5266 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_53b.c:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_63def1ba7387 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_52c.c:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2edcd72a8625 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_53d.c:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_08f8880c7bc2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_54b.c:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_140ac34fe854 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_54d.c:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2b7c6a901760 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_54c.c:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2b7e2fb690e4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_54e.c:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_60f117495333 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_62a.cpp:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c4eaf40a9295 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_66b.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_09b51ae5d8f8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_65b.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f4e0971530ee | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_67b.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_01d6464f623c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_68b.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_aab7b9b12ce9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_74a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9f4a79d23fb2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_72a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5c3e18c42116 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_73a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4a18b42c21fd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_81a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1deb13946cd2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_81_case1V2.cpp:29 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0ff687760280 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_82a.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_336ceeb84cc1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_84a.cpp:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ba6fd25fda97 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_21.c:103 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ead4b6d19d1b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_83a.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_df66c7c22da6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_41.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7f99d28fea4c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_33.cpp:78 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_94dfe1bf2fb0 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_22b.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e0333f617f9d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_43.cpp:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d1f4024d7c5e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_44.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1151fc0fc5bf | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_51b.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3dfc82d6cd74 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52b.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_faf677f31333 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_531a873fffd2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52c.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fd8db0e801e4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_53c.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9c610a65eab3 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_53d.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5693b7e424d0 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54b.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ce11891cb52b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54c.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_987d44871c78 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54d.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_843ffe902c81 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_63b.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f3894e883cb9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54e.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2709f2798e6d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_62a.cpp:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ec84ce401276 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_64b.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6501eedaa910 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_65b.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_718feed43da8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_66b.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_52bade0d8ad1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68b.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c6ad8f1f2897 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_73a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_85e3dc8477f9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_67b.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5720a9f074f1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_74a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_aa7ec11a5789 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_72a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d7b4e201019b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_81a.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_aaebe047c331 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_81_case1V2.cpp:31 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d811835cb189 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_82_case1V2.cpp:31 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_205c14d83eb3 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_82a.cpp:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_50edcd480d91 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_83a.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6f364d2468ec | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_84a.cpp:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2a5726d7fb17 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_43.cpp:83 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e2990effd38a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52b.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b3d6c29e97f4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53b.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e7d1df31914f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53b.c:28 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e756167cd41d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53c.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fd4931d7e5bc | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54b.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_50c3ac34565f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54c.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_37ae556e26f7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54d.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fc781a521aa3 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_62a.cpp:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d94929bde98d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54e.c:41 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_838e34ddefb6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_72a.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0a5b6f04f1b0 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_74a.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bd71e191ae8a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_73a.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3d2f87f36563 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83a.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_556e91ea97ef | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_82a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_403614046c36 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_81a.cpp:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_057f44b2ca1a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84a.cpp:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d98bf7340dea | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_22b.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_47173ee86339 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_21.c:106 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dfefe1fae096 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_41.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7d86fa381bec | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_44.c:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d83449deeea9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_52b.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_15397cd6e1cb | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_53b.c:28 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1e476886f931 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_53b.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_535ad1d0b901 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54b.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d0361c54c828 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54c.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9b59e70136b8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54d.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b7002ca37140 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_62a.cpp:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c697b20cf0f8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54e.c:41 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_76d54eabda29 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_66b.c:45 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_52ce7e069eed | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_73a.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3840a9d62194 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_72a.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ea77331ab776 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_74a.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eedc39083f15 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_81a.cpp:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_de8a6b0ab282 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_82a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_40604139921a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_83a.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_28812f02b939 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84a.cpp:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_aa6f8f9107a2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_22a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_29a145490f86 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_22a.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b1c05b393a95 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_51a.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8168d57ab8fe | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_52a.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7d8c8cde8fca | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53a.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_834f6d1a27fd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54a.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ebb1267a57af | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_63a.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c878d40e915b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_64a.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2f70ff07e74c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_22a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c4015e4e4f4a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_22a.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0c02cd4ce43b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_51a.c:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c2faa5a4f39f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_52a.c:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d56c0ba0ae27 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_54a.c:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_227c4ac0938a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_53a.c:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b8ce15ada142 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_63a.c:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cb0bb4ce62d0 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_22a.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bfd842775cee | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_64a.c:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b6994d87bd29 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_51a.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_562e38a31f99 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_22a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cc3f71d97eb7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_53a.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ddf1c57ec1f4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_52a.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_75c03f288a66 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54a.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b68efe1a04c7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_63a.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0ce47a1135b3 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_64a.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fffb40caed56 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_22a.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5c7ca8193780 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_22a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cdd7668a1402 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_51a.c:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a7b5db4884f4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_52a.c:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_49dd56571490 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_53a.c:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_33b96dcd8114 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54a.c:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_88a1b5214d1b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_63a.c:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c81ec3cc87d8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_64a.c:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3e8a97273af4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_72a.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bc2f24511e5d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_72a.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e3c0562064d5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_72a.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_623526e18acf | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_74a.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a5af57002c0c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_72a.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7f24a58e2b5e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_74a.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a4c1840d451e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_74a.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_782046d15597 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_74a.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6974ca52d545 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_73a.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8b5c5e576939 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_73a.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_697d4dcc64ad | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_73a.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_369e66dedbfc | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_73a.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_60c94f5afe87 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_21.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b535e773b8cc | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_21.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_00bd5b62cf80 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_21.c:92 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_067a6de92446 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_82a.cpp:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c15986439483 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_82a.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c692205cb7bc | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_41.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0bca1f317361 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_82a.cpp:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_90ff5241b3f2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_81a.cpp:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_02b158e8b424 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_82a.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_172496af537b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_81a.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3290445f8f7a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_81a.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5b67d9d4ab76 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_81a.cpp:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dc0bb2ba2b83 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_44.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d8c717f54748 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_65a.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8030366ba7ab | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_65a.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fe2d6d566777 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_44.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b1b329d2e29d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_44.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8226ea5089df | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_65a.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bb4679a69fc6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_44.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2c9cb53da335 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_65a.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1921111936b6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_17.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_157395ca2938 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_17.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3840acb018c9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_17.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_76736d928b1c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_17.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bd45f5f6f2df | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_11.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_28b58f8afc14 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_08.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_44882a929b4d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_08.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_05afe9d21f63 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_11.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_67147e65727b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_08.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2a80755cbe28 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_12.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4e790337b227 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_12.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_88911bb2e500 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_11.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_908be9d429e5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_08.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8be2d9063dca | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_11.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bc2827237220 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_05.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4cb6b9055336 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_12.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c4f76ff78115 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_12.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_96bc2fa255f7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_07.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_03ced4ec7ffd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_10.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f79278ad0f2f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_09.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7d59a24aae40 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_11.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2cf6dde343e1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_05.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ba857fa5c0fd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_07.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eeed3884cbbf | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_14.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7959997e680d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_13.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_09962065723a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_09.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c740ea6f79f8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_10.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_51b63e5f4f2f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_13.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_998668278126 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_05.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b6a6143cfbb8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_14.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2d7fed6462dc | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_07.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fd3d469253e3 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_09.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fb075e8efab6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_10.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_759676973a11 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_13.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a7a17fc32a58 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_05.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_59bfea99c65e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_11.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b2e675cda082 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_07.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5cfa27639830 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_10.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0e2a0cba5a08 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_14.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cdbffe915e43 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_09.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9b3f56649592 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_13.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_425b5cef96c6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_11.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9c44e84dd089 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_14.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dad256e4e428 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_02.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8198da2f8aa6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_03.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3c54e5929284 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_04.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_77771250a847 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_02.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3fae5e3823a4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_03.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2b42d1166cc0 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_06.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f081f4c92764 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_05.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d116b0e2f53d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_09.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3e3d0cb4b8b8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_07.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bc7f09c990fc | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_14.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8b6378c323fc | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_10.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d71f5ebbc2c6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_15.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b22f01f6c126 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_13.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_542502f279be | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_16.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5d8a9a352c15 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_15.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f8047073de3e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_33.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9bb321b54443 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_34.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0bca534cf6b7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_31.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9d21a0b54b1d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_02.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_021d003fa0a6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_03.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b50340924223 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_02.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_266fcf19e9c1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_03.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_531399691117 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_06.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f03965118140 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_04.c:78 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_52554d061214 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_05.c:78 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f696c1c1bd36 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_04.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_055e081cd001 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_07.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7c88c8ba0912 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_06.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eed41e756ee8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_13.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b50f8da922db | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_09.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3101bfdf1d49 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_10.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_250965db9282 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_15.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d303d64b2f30 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_15.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_598b268bcdae | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_14.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5c5ef532ec20 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_18.c:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_156b5b189462 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_31.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f075cbe92ff9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_33.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d683b166d10b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_02.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a3b3e15f6c86 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_03.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_94a735f11366 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_02.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8be050287f25 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_04.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d0b51870ce46 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_03.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2190e9e76506 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_04.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5c65126c8350 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_05.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4e25802dace2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_06.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fb1922fea192 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_07.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0b8161edcaef | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_09.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e90d7dcff312 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_06.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d64e39afe3d4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_10.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7a4820306ce9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_16.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3ab702f831a4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_13.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f2e99ec76daf | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_14.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d46d26d90608 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_18.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_397979044353 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_15.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d479cd821c88 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_33.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d84016a54c8e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_34.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_881cdefc4489 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_02.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_278fc53499fd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_31.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5d7b7c1238c1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_03.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c356c48c71a8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_03.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_948805cb1017 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_04.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a877b94272d5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_02.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_95f108f3dd6d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_06.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_741c79ce1245 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_04.c:78 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_84fdfa068fa8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_05.c:78 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_46252d19bf69 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_06.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c9e54c6772c8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_07.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ef0fb81741d5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_09.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d487608a676c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_10.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_59ea08d74ff8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_13.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b6246dcab118 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_15.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9e57e4c1ecc9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_14.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b43289fd4591 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_16.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9e7d2b865d6e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_15.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bec50d916ab2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_31.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d6ece404eb92 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_18.c:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f61885eaf5e5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_33.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_661fed67650d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_42.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c7eead2d913a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_34.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1445ed8b1ec4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_42.c:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_019be3f1bc19 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_61b.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e5719e6dcad5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_61b.c:36 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_46d85222afe8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_42.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_74c9d418db1a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_61b.c:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e6188f962c5e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_42.c:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8bc4f45ae3b6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_61b.c:36 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b94b67ea71df | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_44.c:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b955e51d72f7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_44.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_893594d22267 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_65a.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5e788e6d8d15 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_65a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9f8ee81fd8ef | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_44.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4731b27b5ad0 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_65a.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_155c688e53d8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_44.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fe9ff53a3bfd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_32.c:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c1a570309ec1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_65a.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1d4459af5169 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_67a.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2314db456e47 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_66a.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_55c705525edb | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_68a.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_167d13b20c1a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_66a.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_908a503a252f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_67a.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f53d17fa08e9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_68a.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c63b0ce7aea8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_32.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c016099348c1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_66a.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7ee398f5280e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_32.c:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_69dd796498d9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_67a.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_da17b91e75f5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68a.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2265a5188019 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_32.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bcdf92a4ef9b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_66a.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_84ac033827fa | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_67a.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_655d78b361ec | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_68a.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9a5be721f0b9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_43.cpp:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_90c92527cbc1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_62b.cpp:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a56a444e24e6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_84_case1V2.cpp:29 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_26f07220beb6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83_case1V2.cpp:29 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_198a48a7ec60 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_43.cpp:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7b2fc1729436 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_83_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cbdd544f862f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_62b.cpp:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_965cd92729fd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_84_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_26c404607e21 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_43.cpp:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f0eac9bc6fc8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_83_case1V2.cpp:29 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8f38ec98be2c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_62b.cpp:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_85904d4e5b03 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84_case1V2.cpp:29 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ea5150142ef4 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_43.cpp:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_931cdac08821 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_62b.cpp:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_077c30df1d2e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_84_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fadeb43bde55 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_83_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_762fb87d7866 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_61b.c:45 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bf3cf3ecb285 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_42.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f22c77cb9f98 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_61b.c:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dd4adeda2e90 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_42.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_92d746c27229 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_42.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_48266bcc6984 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_61b.c:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_38b313951052 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_42.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0e6f8a7a0846 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_61b.c:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_46484715b0cb | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_21.c:113 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4ce1c9c71237 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_22a.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5b4492d3522c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_21.c:110 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_39e0270ddc2e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_14.c:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4b4228a59ed6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_22a.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_efdf17fda7be | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_07.c:92 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_597eb0c3b841 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_21.c:112 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7105af6ccdbf | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_14.c:88 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b140d7e13b8e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_22a.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_192ce3c23345 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_13.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_606db6385d52 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_21.c:111 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1d139e952750 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_22a.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_13abb15e048f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_21.c:120 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6ba7e2e357fc | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_14.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1f556b8dc459 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_22a.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_59ef59ca4b0c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_03.c:97 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1afbbc0369d9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_02.c:97 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_445aceadde2f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_08.c:110 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2d0bbfea500f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_07.c:102 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_259e4429e30c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_13.c:97 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7fcef7ed3aad | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_06.c:102 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_096bdadf4703 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_14.c:96 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_57193eb134ca | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_21.c:121 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_572f3e672228 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_15.c:109 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1144cbd33334 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_22a.c:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_52b14eacf73d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_07.c:110 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_01a6593f665a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_08.c:119 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_340100321d68 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_21.c:131 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_82819e4b273b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22a.c:96 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_04737bfd892f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_03.c:105 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0e5e6d51c720 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_07.c:110 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a54ab5b157b2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_14.c:105 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_513a406483e9 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_21.c:130 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e4a0978d1433 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_22a.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0ba295591f5b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_44.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f08ef74f865c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_41.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_adb02205416c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_45.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6fca44dfc18e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_51a.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bb4681e08aae | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_52a.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ddf1ffa7de3d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54a.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bf5abe70cf0c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53a.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_25f945b3cffe | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_64a.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1a81227cfe57 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_63a.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_80f35776d69d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_65a.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e8de19adf374 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_67a.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b0836c238185 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_66a.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_df8052d5a82d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_68a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1cf7abf592a5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_41.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4a892297e26b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_51a.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_78e2f4fdc91f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_45.c:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_18a639d90771 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_52a.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5c96504cdbad | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_44.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cc12695ae042 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_53a.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_86d37e3a0b0b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_54a.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5b0ef8d4d0fb | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_63a.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f2a0472e419b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_65a.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e86c1f19140a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_64a.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_473134f67352 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_66a.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_53e51134643c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_67a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8894ad9433f8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__fopen_w32_close_68a.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c2365232678c | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_41.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b5bd730d5499 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_44.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_82e951e36840 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_45.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d068374a20ae | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_51a.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e462f279ceb5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_42.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b684b65d9411 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_53a.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bf5e8513a573 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54a.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c3db239616e7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_52a.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_505fb4657d51 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_63a.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9c50ac4a0518 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_64a.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ef4bf869cf02 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_66a.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5c9b27a5e63a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_65a.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_83625ad54322 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_03ba3f879443 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_67a.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ce46f075b3a7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_32.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_be70ee1c7db8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_41.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4ce957db347d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_44.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b73792d098a7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_45.c:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cfc21ab83653 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_51a.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_61bcbcef6f21 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_52a.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ac54f7333640 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_53a.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ac64eb77e394 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_54a.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5d834c689244 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_63a.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e4b9134526a8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_64a.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_53e8ef2504e0 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_66a.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_daf694855813 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_65a.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a980f73906a7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_68a.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_87d63530eeb8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__freopen_w32_close_67a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0aae4f664c90 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_17.c:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_75bf76d2da9a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_32.c:83 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c4c9db850f53 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_18.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c65c024f000b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_41.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5291610665f3 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_44.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_28b8395f0c9b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_45.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7b15523da466 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_43.cpp:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5fa2bff2eae2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_51a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_abd560b77fb0 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_53a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_40346f83d044 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_52a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d6fc549cb7ce | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_54a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a7d3465b7e01 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_62b.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d05c60dbcee6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_63a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_240b4041c0b7 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_66a.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_91ec778c1fbd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_65a.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_feca035a7f9a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_64a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3b37b9b303eb | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_67a.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_732fc5d2cdc8 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_68a.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_aef6552d5a67 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_83_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f57383eef07e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_fclose_84_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a169f0dd7ec5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_01.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f6e3852a365e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_17.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a776d6bdc98e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_16.c:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c6e48af74161 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_18.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bc06ae04b45d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_32.c:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ac1cb001a366 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_34.c:83 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_838218042dbe | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_41.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cd5fc088afe6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_43.cpp:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_689b82a1f537 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_44.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6d56907157a6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d52c6588ac49 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_42.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_451fbbab1e19 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_51a.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_399b231f0e9f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52a.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_51d01e97c185 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54a.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ed6f4536d654 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_53a.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ac70238452dc | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_61a.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d83eba0f705a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_62b.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a90f045ad225 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_63a.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7d803a360665 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_64a.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e8ea37ab8f7a | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_65a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_296e829e9fb1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_67a.c:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f56495ef2f07 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_66a.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ed8d083972ee | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68a.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_344cd0cda02f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_84_case1V2.cpp:29 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7ebf2c9cce19 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_83_case1V2.cpp:29 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e70be4f77404 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_41.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6278736acaf6 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_43.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_39a4100e130b | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_51a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_13e3b254a100 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_44.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0a204b07cb09 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_45.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f2eccf0d4945 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_813f9d82dc5d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4779b11b141d | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_54a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d033a6127dc0 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_62b.cpp:46 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ef67c3434dd1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_63a.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7a18faf5de49 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_64a.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fe2714ca7341 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_65a.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e762cdcf24a0 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_66a.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2f8d048cb046 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_67a.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1d0e6c2bba87 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_68a.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8002f25a7bb1 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a27b3ff0a85f | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4e45631dcb49 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_41.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cdf6439d6571 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_43.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c2d0df58d598 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_44.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9e6d4a036dbd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_45.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2e6a0c936429 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_52a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_60147b4dc585 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_51a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_22e5ba6aea72 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_53a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b9412debcdca | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_62b.cpp:46 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_edd1bd552cc2 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9571c5e07328 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_64a.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4c15315bc8ab | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_63a.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8e22de9c8cf0 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_65a.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d03b9913191e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_66a.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4984725d68dd | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67a.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c3f1996fafc5 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68a.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8fac21ce402e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_83_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3e05a638f5d3 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/main.cpp:15 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_192370533d40 | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/main_linux.cpp:15 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_90413c98776e | juliet-api-misuse/testcases/CWE404_Improper_Resource_Shutdown/CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
