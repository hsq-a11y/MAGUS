# MAGUS Final Vulnerability Report

- generated_at: 2026-05-23T10:23:07Z
- reportable_vulnerabilities: 220
- d_confirmed_vulnerabilities: 220
- stage_c_preserved_vulnerabilities: 0
- failed_verifications: 240
- source_confirmed: /home/sq_hu/MAGUS/d/memberD_verifier/02_run_with_C/output/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/verification.jsonl
- source_failed: /home/sq_hu/MAGUS/d/memberD_verifier/02_run_with_C/output/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/verification.failed.jsonl

## Confirmed Vulnerabilities

### 1. hyp_path_e0354592e4ef

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_74a.cpp:464
- 漏洞类型: CWE-773, CWE-404
- CWE: CWE-773; CWE-404
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_74a.cpp:44-48; dataMap[0] = data; dataMap[1] = data; dataMap[2] = data; case0Sink(dataMap); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_74a.cpp:50-54
- 结论: 文件描述符未关闭，导致资源泄露。open()创建的文件描述符被放入map后从未关闭，可能耗尽系统文件描述符资源。
- D验证: confirmed / ver_f4376167
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 2. hyp_path_d9e50da1d9d8

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_72a.cpp:111
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者可能需要控制CreateFile的文件路径参数（但本例中为硬编码字符串），或影响程序流程以触发此代码路径。
- 触发路径: data = INVALID_HANDLE_VALUE; /* NOTE: Create a file handle using CreateFile() that may not be closed properly */ data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_72a.cpp:37-41; dataVector.insert(dataVector.end(), 1, data); case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_72a.cpp:49-53
- 结论: 文件句柄通过CreateFile创建后，未正确关闭，导致资源泄漏（Missing Reference to Active File Descriptor or Handle）。
- D验证: confirmed / ver_a41a29f0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 3. hyp_path_a9cd86757869

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_72a.cpp:111
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能触发该代码路径的执行，例如通过输入控制函数调用。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_72a.cpp:44-46; dataVector.insert(dataVector.end(), 1, data); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_72a.cpp:48; case0Sink(dataVector); // 内部未关闭文件描述符 @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_72a.cpp:50-54
- 结论: 文件描述符泄漏：调用open()创建的文件描述符存储在data中，通过vector传递至case0Sink，但全程未调用close()，导致资源泄漏。
- D验证: confirmed / ver_45874988
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 4. hyp_path_75032181bfae

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_74a.cpp:464
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: CreateFile返回有效句柄（非INVALID_HANDLE_VALUE）; sink函数内未关闭句柄
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_74a.cpp:32-36; dataMap[2] = data; case0Sink(dataMap); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_74a.cpp:49-53
- 结论: 文件句柄泄漏：CreateFile创建的文件句柄被放入map后未关闭，导致资源泄露。
- D验证: confirmed / ver_7f153623
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 5. hyp_path_5f5e2cb0617e

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_73a.cpp:443
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: CreateFile 调用成功返回有效句柄。; 程序继续执行而未在适当位置关闭句柄。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...) @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_73a.cpp:37-41; dataList.push_back(data); case0Sink(dataList); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_73a.cpp:49-53
- 结论: 文件句柄通过 CreateFile 创建后未关闭，导致资源泄漏。
- D验证: confirmed / ver_b877a150
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 6. hyp_path_fb39e1ffefbb

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_73a.cpp:443
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者无需直接控制输入，漏洞在正常执行路径中即可触发。
- 触发路径: data = -1; data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); dataList.push_back(data); @ CWE773_open_73a.cpp:44-48; dataList.push_back(data); case0Sink(dataList); @ CWE773_open_73a.cpp:50-54; 假设未调用close(data)，导致泄漏。 @ case0Sink函数内部（未提供实现）
- 结论: 文件描述符泄漏：open()返回的文件描述符被复制到列表后，在程序结束前未调用close()关闭，导致文件描述符泄漏。原始变量data未被覆盖，但始终未关闭。
- D验证: confirmed / ver_f55ab56b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 7. hyp_path_a9736d9d26df

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_74b.cpp:45
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: dataMap中索引2存储的是有效的文件描述符（非-1）; 调用者能够影响dataMap中的值（例如通过之前的函数调用）
- 触发路径: int data = dataMap[2]; /* NOTE: Assign data to another file descriptor without closing the descriptor from the source */ data = OPEN(...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_74b.cpp:39-41
- 结论: 函数case0Sink中，从dataMap取出文件描述符（存储在变量data）后，未关闭该旧描述符就直接用open()覆盖变量data，导致原文件描述符泄漏。仅对新打开的描述符执行了close()。
- D验证: confirmed / ver_ec2784e5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 8. hyp_path_9eb049f72575

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_21.c:42
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 第一次open()成功返回非-1的文件描述符; case0Static变量为true（静态初始化为1）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_21.c:42; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); // 覆盖了之前的文件描述符 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_21.c:35
- 结论: 存在文件描述符泄漏漏洞。函数case0Sink中第二次调用open()覆盖了变量data，导致第一次打开的文件描述符未被关闭，丢失对活动文件描述符的引用。
- D验证: confirmed / ver_54e0759f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 9. hyp_path_f5bb6f93530b

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_74b.cpp:44
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: dataMap[2]包含一个有效的HANDLE（非INVALID_HANDLE_VALUE）; 函数case0Sink被调用且执行了从dataMap获取句柄并覆盖的操作
- 触发路径: HANDLE data = dataMap[2]; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_74b.cpp:30-34; data = CreateFile("Case0Sink_w32CreateFile.txt", ...); // 覆盖而不关闭原句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_74b.cpp:32-36; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } // 仅关闭新句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_74b.cpp:42-46
- 结论: 在函数case0Sink中，从dataMap[2]获取一个有效的HANDLE后，未先关闭该句柄就直接用CreateFile覆盖，导致原始文件句柄泄漏。这是一种资源泄漏漏洞，符合CWE-773。
- D验证: confirmed / ver_01441def
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 10. hyp_path_35d3120254f8

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_41.c:36
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无需特殊攻击前提，代码逻辑自然导致泄漏。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_41.c:36; case0Sink(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_41.c:53; data = CreateFile("Case0Sink_w32CreateFile.txt", ...); // 未关闭原data句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_41.c:26-27
- 结论: 在函数case0Sink中，对传入的文件句柄data重新赋值（CreateFile创建新句柄）而未先关闭原来的句柄，导致原始文件句柄泄漏（Missing Reference to Active File Descriptor or Handle）。
- D验证: confirmed / ver_d2ac9dcb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 11. hyp_path_4e2125ac19c9

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_41.c:37
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序能够执行到open()调用，且文件打开成功。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_41.c:37; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_41.c:31; if (data != -1) { CLOSE(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_41.c:36
- 结论: 文件描述符泄漏：调用open()创建文件描述符后未关闭，而是重新赋值，导致原始描述符丢失引用。
- D验证: confirmed / ver_277f9dfd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 12. hyp_path_22e8da5ef2cc

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_21.c:41
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: CreateFile调用成功，返回有效句柄
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", ...); @ L41 (source); data = CreateFile("Case0Sink_w32CreateFile.txt", ...); // 覆盖前一个句柄 @ L31 (sink)
- 结论: 文件句柄泄漏：在case0Sink函数中，前一个由CreateFile创建的句柄未被关闭就被新句柄覆盖，导致对活动文件描述符的引用丢失。
- D验证: confirmed / ver_ff6b24f3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 13. hyp_path_76af1c224978

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_43.cpp:50
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无需外部输入，漏洞代码本身可触发
- 触发路径: static void case0Source(int &data) { data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_43.cpp:33-37; case0Source(data); data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_43.cpp:44-48
- 结论: 文件描述符泄漏：case0Source函数通过open()分配文件描述符并赋值给data，随后在case0函数中直接覆盖data为另一个open()的结果，未关闭之前的文件描述符，导致资源泄漏。
- D验证: confirmed / ver_9ecf3ada
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 14. hyp_path_0436324eac70

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_43.cpp:55
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无需攻击者输入，程序正常执行此路径即发生句柄泄漏；多次调用可耗尽系统句柄资源。
- 触发路径: case0Source(data); // 创建句柄（内部CreateFile） @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_43.cpp:43; data = CreateFile("Case0Sink_w32CreateFile.txt", ...); // 覆盖句柄，前一个句柄泄露 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_43.cpp:45; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } // 只关闭了第二个句柄，第一个句柄未关闭 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_43.cpp:53-57
- 结论: 文件句柄泄漏：调用case0Source函数创建文件句柄后，未关闭该句柄，直接覆盖data变量为另一个CreateFile返回的句柄，导致第一个句柄泄漏。
- D验证: confirmed / ver_9f83e758
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 15. hyp_path_2348bccc59b2

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61a.c:43
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者无需特殊输入；该漏洞在正常调用时即可触发，导致句柄泄漏。
- 触发路径: data = CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61b_case0Source(data); /* NOTE: Point data to another file handle without closing the handle from the source */ data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61a.c:31-35; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61a.c:41-45
- 结论: 文件句柄泄漏：调用CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61b_case0Source获取句柄后，未关闭该句柄，直接覆盖为新句柄（CreateFile），导致原句柄泄漏。
- D验证: confirmed / ver_81e2ed83
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 16. hyp_path_cd6194f988f3

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_62a.cpp:46
- 漏洞类型: CWE-773, CWE-404
- CWE: CWE-773; CWE-404
- 风险等级: P0
- 触发条件: 攻击者无法直接控制case0Source（测试用例固定），但在实际场景中，若case0Source的行为受外部输入影响，则可能存在利用；本样本中case0Source总是分配有效句柄，漏洞触发条件满足。
- 触发路径: /* Initialize data */ data = INVALID_HANDLE_VALUE; case0Source(data); /* NOTE: Point data to another file handle without closing the handle from the source */ data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_62a.cpp:32-36; data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); // 覆盖data，未关闭旧句柄 @ 同文件:46; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } // 仅关闭新句柄 @ 同文件:44-48
- 结论: 在调用case0Source后，data被赋予一个有效的文件句柄（非INVALID_HANDLE_VALUE），随后未关闭该句柄即被CreateFile的新句柄覆盖，导致原始句柄泄漏，属于CWE-773 Missing Reference to Active File Descriptor or Handle。
- D验证: confirmed / ver_7ddf0a1d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 17. hyp_path_2c58377c1795

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_42.c:48
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无需攻击者输入，漏洞由代码逻辑本身导致
- 触发路径: static int case0Source(int data) { data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); return data; } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_42.c:30-35; data = case0Source(data); data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_42.c:42-44; if (data != -1) { CLOSE(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_42.c:46-50
- 结论: 丢失对活动文件描述符的引用：函数case0Source打开文件描述符并返回，但调用者未关闭该描述符就将其覆盖，导致文件描述符泄漏。
- D验证: confirmed / ver_741d14d2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 18. hyp_path_2a76e644af7e

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_61a.c:44
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行路径经过该代码块；source函数返回一个有效的文件描述符。
- 触发路径: data = CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_61b_case0Source(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_61a.c:38; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_61a.c:40; if (data != -1) { CLOSE(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_61a.c:42-46
- 结论: 程序在获取文件描述符后，没有关闭它就直接将其覆盖为新的文件描述符，导致前一个文件描述符丢失引用，从而造成资源泄漏（未关闭的文件句柄）。
- D验证: confirmed / ver_19f66b1c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 19. hyp_path_6bd89d1d12b1

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_62a.cpp:47
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够影响case0Source的行为，使其返回一个有效文件描述符（例如通过控制输入或环境）。
- 触发路径: case0Source(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_62a.cpp:41; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_62a.cpp:43-44; if (data != -1) { CLOSE(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_62a.cpp:45-46
- 结论: 在函数case0中，通过case0Source获取一个文件描述符后，未关闭该描述符即重新赋值给另一个文件描述符，导致原先的文件描述符泄漏（缺少对活动文件描述符的引用）。
- D验证: confirmed / ver_b3620603
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 20. hyp_path_093c3b21b680

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_42.c:53
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 函数正常执行即可触发泄漏，无需攻击者控制
- 触发路径: data = case0Source(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_42.c:41; data = CreateFile("Case0Sink_w32CreateFile.txt", ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_42.c:42; CloseHandle(data); // 仅关闭第二个句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_42.c:53
- 结论: 文件句柄泄漏：在case0Source中创建的文件句柄未关闭，导致资源泄漏。
- D验证: confirmed / ver_cba0fbfe
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 21. hyp_path_bf929daa49dd

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_12.c:44
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行至任意一次OPEN调用且未关闭之前保存在同一变量中的文件描述符
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_12.c:35; data = OPEN("...", ...); // 覆盖前未关闭之前的data文件描述符 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_12.c:39 或 52; if (data != -1) { CLOSE(data); } // 只关闭最新打开的，之前的已丢失 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_12.c:42-44 或 54-56
- 结论: 文件描述符在重新赋值前未关闭，导致资源泄露（CWE-773）。无论globalReturnsTrueOrFalse()结果如何，后续的OPEN覆盖操作均会导致先前打开的文件描述符丢失引用，无法关闭。
- D验证: confirmed / ver_3ce1d854
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 22. hyp_path_854a2467b3c8

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_12.c:49
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行globalReturnsTrueOrFalse()返回真的分支。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ 27-31; if(globalReturnsTrueOrFalse()) { /* NOTE: Point data to another file handle without closing the handle from the source */ @ 34-38; data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ 37-41
- 结论: 在条件分支globalReturnsTrueOrFalse()为真的情况下，程序直接为data赋新句柄而未关闭之前打开的句柄，导致文件句柄泄露。
- D验证: confirmed / ver_cc8f5724
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 23. hyp_path_c7fe1db0125e

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_17.c:45
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 代码执行到第一个open()调用且成功返回非-1文件描述符
- 触发路径: data = -1; /* NOTE: Create a file descriptor using open() that may not be closed properly */ data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_17.c:35-39; /* NOTE: Assign data to another file descriptor without closing the descriptor from the source */ data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); /* avoid incidental for not closing the file */ if (data != -1) ... data = -1; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_17.c:39-43
- 结论: 文件描述符泄漏：第一次调用open()打开'Case0Source_open.txt'后，未关闭该文件描述符，随后在for循环中有条件再次调用open()覆盖变量data，导致第一个文件描述符引用丢失，从而泄漏。
- D验证: confirmed / ver_f57ac5a5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 24. hyp_path_cd58537e8de0

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_17.c:50
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = INVALID_HANDLE_VALUE; data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_17.c:28-32; data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_17.c:38-42; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_17.c:48-52
- 结论: 文件句柄泄漏：第一次调用CreateFile打开的文件句柄（source）在重新赋值给另一个文件句柄（sink）前未关闭，导致资源泄漏。
- D验证: confirmed / ver_643c0c73
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 25. hyp_path_711f9129d2af

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_11.c:44
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: globalReturnsTrue()返回true使覆盖分支执行
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_11.c:35-36; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); // 覆盖第一个文件描述符，未关闭 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_11.c:40-41; if (data != -1) { CLOSE(data); } // 仅关闭第二个文件描述符，第一个泄漏 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_11.c:44
- 结论: 代码中首先通过open()创建文件描述符，随后在if(globalReturnsTrue())分支中再次调用open()赋值给同一变量data，导致第一个文件描述符丢失引用且未被关闭，造成资源泄漏。
- D验证: confirmed / ver_d2cf4ed7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 26. hyp_path_a5794c618690

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_11.c:49
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: globalReturnsTrue()返回真
- 触发路径: data = INVALID_HANDLE_VALUE; /* NOTE: Create a file handle using CreateFile() that may not be closed properly */ data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... @ 第27-31行; FILE_ATTRIBUTE_NORMAL, NULL); if(globalReturnsTrue()) { /* NOTE: Point data to another file handle without closing the handle from the source */ @ 第34-38行; data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... @ 第37-41行; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } } @ 第47-51行
- 结论: 在CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_11.c中，当globalReturnsTrue()返回真时，程序在未关闭第一个文件句柄的情况下，将data指针重新指向第二个CreateFile返回的句柄，导致第一个句柄泄漏。
- D验证: confirmed / ver_077497a9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 27. hyp_path_7b5eb7735794

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_08.c:62
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无需外部输入，staticReturnsTrue()始终返回1导致分支必然执行；两次CreateFile在测试场景下均成功返回有效句柄。
- 触发路径: data = INVALID_HANDLE_VALUE; data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_08.c:40-44; if(staticReturnsTrue()) { data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_08.c:47-51; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_08.c:60-64
- 结论: 文件句柄泄漏：第一个CreateFile返回的句柄被第二个CreateFile覆盖且未关闭，导致句柄泄漏。
- D验证: confirmed / ver_5d7fffb5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 28. hyp_path_6cdc983d1cd0

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_08.c:57
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 代码按预设路径执行，staticReturnsTrue() 返回真（始终返回1）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ 行47-49; if(staticReturnsTrue()) { data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); } @ 行48-55; if (data != -1) { CLOSE(data); } // 仅关闭第二个描述符，第一个泄漏 @ 行55-57
- 结论: 在 staticReturnsTrue() 始终返回真时，第一个打开的文件描述符未关闭即被覆盖，导致文件描述符泄漏，符合 CWE-773。
- D验证: confirmed / ver_90a903d8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 29. hyp_path_0948a7a5781e

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_04.c:50
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: STATIC_CONST_TRUE为真（典型值为1），确保第二次open及后续关闭分支被执行；第一次open()成功返回非-1；第二次open()成功返回非-1。
- 触发路径: data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_04.c:44; if (data != -1) { /* 未关闭 */ } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_04.c:46; data = -1; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_04.c:40; data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_04.c:41; if (data != -1) { CLOSE(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_04.c:48-50
- 结论: 在CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_04.c中，文件描述符data在第一次调用open()后未被关闭，随即又被第二次open()覆盖，导致第一个文件描述符丢失引用，造成资源泄漏（文件描述符未释放）。
- D验证: confirmed / ver_02aa24f1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 30. hyp_path_58f1fa8af072

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_01.c:42
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行到第一个open()语句，且open()成功返回非-1的文件描述符（由于硬编码文件名和O_CREAT，几乎总是成功）。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_01.c:42; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); /* 覆盖前一个文件描述符，导致泄漏 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_01.c:42; if (data != -1) { CLOSE(data); } /* 仅关闭第二个文件描述符 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_01.c:40-44
- 结论: 在文件描述符操作中，对open()返回的文件描述符进行赋值时，未关闭前一个文件描述符，导致文件描述符泄漏（CWE-773）。
- D验证: confirmed / ver_636ee5fe
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 31. hyp_path_3f0cec30ad26

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_02.c:44
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行到第一个open()和第二个open()之间的路径（if(1)恒真），且两次open()均成功返回有效文件描述符。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_02.c:35-36; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); // 覆盖文件描述符 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_02.c:40
- 结论: 存在文件描述符泄漏漏洞：第一个open()创建的文件描述符未关闭就被第二个open()覆盖，导致文件描述符泄漏。
- D验证: confirmed / ver_f224644d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 32. hyp_path_63c61892e9dd

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_03.c:44
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 代码执行到 if(5==5) 分支（条件恒真）
- 触发路径: data = -1; data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_03.c:34-38; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_03.c:38-42; if (data != -1) { CLOSE(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_03.c:42-46
- 结论: 文件描述符泄漏：在打开 Case0Source_open.txt 后未关闭文件描述符，随后覆盖 data 变量导致原描述符丢失引用。
- D验证: confirmed / ver_b97d0a19
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 33. hyp_path_2283252c51e7

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_07.c:49
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: staticFive变量的值为5，使if分支被执行
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_07.c:41; if(staticFive==5) { data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_07.c:43-45
- 结论: 在staticFive==5的分支中，第一次打开的文件描述符被第二次打开的文件描述符覆盖，导致第一个文件描述符丢失引用，无法关闭，造成资源泄漏。
- D验证: confirmed / ver_b60c5c7a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 34. hyp_path_01192033e552

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_05.c:50
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者无需控制输入；staticTrue通常为1，条件自动满足。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_05.c:41; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_05.c:46
- 结论: 文件描述符泄露：在将新打开的文件描述符赋值给变量data之前，未关闭先前的文件描述符，导致资源泄露。
- D验证: confirmed / ver_b938a784
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 35. hyp_path_ccdfecdbd077

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_10.c:44
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: globalTrue为真（测试用例中通常为1），且第一个open()成功返回非-1的文件描述符。
- 触发路径: data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_10.c:38; data = -1; /* NOTE: Create a file descriptor using open() that may not be closed properly */ data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_10.c:42-43
- 结论: 在函数中，先通过open()创建了第一个文件描述符并赋值给data，然后未关闭该描述符就直接用第二个open()的结果覆盖data，导致第一个文件描述符无法被关闭，造成文件描述符泄漏。
- D验证: confirmed / ver_ac6b4006
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 36. hyp_path_993b27fe8138

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_06.c:49
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序正常执行，无异常中断；两个open()均成功返回有效文件描述符；STATIC_CONST_FIVE==5为真。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_06.c:41; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ 同一文件:45; CLOSE(data); // 只关闭第二个文件描述符 @ 同一文件:49
- 结论: 文件描述符泄漏：第一次open()返回的文件描述符在第二次open()中被覆盖而未关闭，导致资源泄漏。
- D验证: confirmed / ver_91ade8a3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 37. hyp_path_116c0d639867

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_15.c:45
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序按照switch(6)分支执行（硬编码为6，必然进入）
- 触发路径: data = -1; /* NOTE: Create a file descriptor using open() that may not be closed properly */ data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); switch(6) { @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_15.c:34-38; case 6: /* NOTE: Assign data to another file descriptor without closing the descriptor from the source */ data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); /* avoid incidental for not closing the file */ if (data != -1) @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_15.c:39-42; if (data != -1) { CLOSE(data); } break; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_15.c:43-47
- 结论: 在switch case 6中，先通过open()创建文件描述符并赋值给data，然后再次调用open()重新赋值data，导致第一个文件描述符没有关闭，造成文件描述符泄漏。
- D验证: confirmed / ver_9068efaa
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 38. hyp_path_0067d2bf5315

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_13.c:44
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够改变GLOBAL_CONST_FIVE的值使其不等于5（例如通过修改全局常量或利用外部配置），且两个open()调用成功返回非-1文件描述符。
- 触发路径: data = -1; data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_13.c:35-37; if(GLOBAL_CONST_FIVE==5) { /* 条件不成立时跳过关闭 */ } @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_13.c:38; data = -1; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_13.c:39-41; if (data != -1) { CLOSE(data); } /* 只关闭了第二个，第一个未关闭 */ @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_13.c:42-46
- 结论: 在特定条件下，第一个open()创建的文件描述符可能未被关闭，导致资源泄露（CWE-773）。当GLOBAL_CONST_FIVE不等于5时，if分支不执行，第一个文件描述符不会关闭，随后data被重置并打开第二个文件，覆盖了第一个描述符，导致引用丢失。
- D验证: confirmed / ver_ee01f1bf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 39. hyp_path_5b2e554643b5

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_09.c:44
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: GLOBAL_CONST_TRUE为真（非零），使if分支执行；第一次open()成功返回有效文件描述符（非-1）；第二次open()成功返回有效文件描述符。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_09.c:35; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); // 覆盖前一个文件描述符，未关闭 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_09.c:43; if (data != -1) { CLOSE(data); } // 只关闭了第二个文件描述符 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_09.c:44
- 结论: 文件描述符泄漏：在将data变量赋值为第二个open()的结果之前，未关闭第一个open()返回的文件描述符，导致第一个文件描述符泄漏。
- D验证: confirmed / ver_ff73b5fb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 40. hyp_path_137237612e04

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_18.c:44
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 代码执行到source处的open()调用并goto sink，且sink中的open()成功返回非-1（即文件打开成功）。
- 触发路径: data = -1; /* NOTE: Create a file descriptor using open() that may not be closed properly */ data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); goto sink; sink: @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_18.c:34-38; sink: /* NOTE: Assign data to another file descriptor without closing the descriptor from the source */ data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); /* avoid incidental for not closing the file */ if (data != -1) @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_18.c:38-42; if (data != -1) { CLOSE(data); } } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_18.c:42-46
- 结论: 文件描述符泄漏：source中通过open()创建文件描述符后，直接goto sink，sink中再次open()赋值给同一变量，原始文件描述符未被关闭，造成资源泄漏。
- D验证: confirmed / ver_b7913f3b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 41. hyp_path_9a6dc636affa

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_32.c:50
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无外部输入依赖，代码内部直接触发
- 触发路径: int data = *dataPtr1; data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); *dataPtr1 = data; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_32.c:38-42; int data = *dataPtr2; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_32.c:44-48; if (data != -1) { CLOSE(data); } // 只关闭了第二个描述符 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_32.c:48-52
- 结论: 文件描述符泄露：第一个open()创建的文件描述符被第二个open()覆盖，导致前一个文件描述符未被关闭，造成资源泄露。
- D验证: confirmed / ver_2799b063
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 42. hyp_path_67955a34268a

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_14.c:44
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序运行时全局变量 globalFive 等于 5。
- 触发路径: data = -1; data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_14.c:34-37; if(globalFive==5) { @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_14.c:38; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); /* 覆盖第一个文件描述符，造成泄漏 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_14.c:44; if (data != -1) { CLOSE(data); } /* 只关闭了第二个文件描述符 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_14.c:45-46
- 结论: 当全局变量 globalFive 等于 5 时，第一个文件描述符在第二次调用 open() 之前未关闭，导致文件描述符泄漏。
- D验证: confirmed / ver_b6386dfc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 43. hyp_path_64870897294c

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_16.c:44
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无需外部输入，代码逻辑本身导致文件描述符泄露
- 触发路径: data = -1; /* NOTE: Create a file descriptor using open() that may not be closed properly */ data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ L34-36; while(1) { ... } 内部没有关闭data，随后执行data = OPEN("Case0Sink_open.txt", ...); 覆盖了旧的data。 @ L37-40; if (data != -1) { CLOSE(data); } break; // 只关闭了新的data，旧的文件描述符丢失。 @ L42-46
- 结论: 在while循环中，首先打开文件"Case0Source_open.txt"并赋值给data，然后在未关闭该文件描述符的情况下，再次打开"Case0Sink_open.txt"覆盖data，最后仅关闭data（此时指向Sink文件），导致源文件描述符泄露，无法被关闭。
- D验证: confirmed / ver_5f5c0f7e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 44. hyp_path_40cc7c6e319a

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_31.c:45
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无需外部攻击者控制输入；代码执行路径自然触发
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_31.c:35; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_31.c:42; if (data != -1) { CLOSE(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_31.c:45
- 结论: 缺少对活动文件描述符的引用：第一个打开的文件描述符（来自"Case0Source_open.txt"）在重新赋值给另一个文件描述符后丢失引用，导致文件描述符泄漏。
- D验证: confirmed / ver_cd9d36ba
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 45. hyp_path_afa48bc0d8be

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_72b.cpp:45
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: dataVector[2] 包含一个之前打开且未关闭的文件描述符
- 触发路径: int data = dataVector[2]; @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_72b.cpp:39-40; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_72b.cpp:40-41; if (data != -1) { CLOSE(data); } // 只关闭了新打开的描述符，原描述符未关闭 @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_72b.cpp:43-47
- 结论: 文件描述符泄漏：从dataVector获取一个打开的文件描述符，然后在未关闭的情况下直接使用新打开的文件描述符覆盖，导致原文件描述符丢失且无法关闭。
- D验证: confirmed / ver_c7093d05
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 46. hyp_path_b56215b7f8d4

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_33.cpp:48
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无特殊攻击前提，代码本身存在缺陷，只需程序执行到相关路径即可触发。
- 触发路径: data = -1; data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ L38-40; { int data = dataRef; /* 重新声明局部变量隐藏外部data */ @ L40-42; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); /* 赋值给局部变量 */ @ L42-44; if (data != -1) { CLOSE(data); } /* 仅关闭第二个文件描述符 */ @ L46-50
- 结论: 存在文件描述符泄漏漏洞：通过引入内层作用域并重新声明'data'变量，第一个打开的文件描述符（Case0Source_open.txt）的引用丢失，导致无法关闭，造成资源泄漏。
- D验证: confirmed / ver_81cbacfd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 47. hyp_path_2d0db4501bb2

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_34.c:52
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 第一次open()调用成功返回非-1的文件描述符; 第二次open()调用成功覆盖data，导致第一次的文件描述符引用丢失
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_34.c:42; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_34.c:48; CLOSE(data); // 仅关闭第二次打开的描述符，第一次的未关闭 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_34.c:52
- 结论: 在函数CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_34_case0中，第一次通过open()创建的文件描述符被赋值给联合体成员unionFirst，随后从联合体取出并立即被第二次open()调用覆盖，导致第一个文件描述符失去引用且未被关闭，造成资源泄漏。
- D验证: confirmed / ver_8866a449
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 48. hyp_path_1b3452f8162c

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_02.c:49
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 第一个CreateFile（source）调用成功返回有效句柄。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_02.c:30-31; data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_02.c:40-41; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_02.c:47-48
- 结论: 在创建文件句柄后未关闭，直接覆盖句柄变量导致前一个句柄泄漏。具体为：首先在27-31行创建文件句柄（source），未保存引用；接着在37-41行创建另一个文件句柄（sink）并覆盖变量，导致前一个句柄泄漏；最后在47-51行关闭的是后一个句柄，前一个句柄未被关闭。
- D验证: confirmed / ver_4b1c697f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 49. hyp_path_2eaea0327932

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_04.c:55
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无额外攻击者控制条件，漏洞由程序固有逻辑触发
- 触发路径: data = INVALID_HANDLE_VALUE; data = CreateFile("Case0Source_w32CreateFile.txt", ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_04.c:33-37; data = CreateFile("Case0Sink_w32CreateFile.txt", ...); /* 覆盖前未关闭第一个句柄 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_04.c:43-47; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } /* 仅关闭第二个句柄 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_04.c:53-57
- 结论: 程序在创建第一个文件句柄后，未关闭该句柄就直接覆盖到第二个文件句柄，导致第一个句柄泄漏（缺少引用），违反了CWE-773。
- D验证: confirmed / ver_4ea6d164
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 50. hyp_path_175f0fe94a3b

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_73b.cpp:45
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: dataList中包含一个或多个未关闭的文件描述符。; 程序执行路径进入sink函数。
- 触发路径: int data = dataList.back(); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_73b.cpp:42; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_73b.cpp:43
- 结论: 从list中获取文件描述符后，未关闭原描述符即覆盖为新打开的描述符，导致文件描述符泄漏。
- D验证: confirmed / ver_52a785cc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 51. hyp_path_48e5aa290848

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_01.c:47
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 第一个CreateFile调用成功返回有效句柄；攻击者无需控制输入。
- 触发路径: data = INVALID_HANDLE_VALUE; data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...) @ line 27-31; data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...) @ line 35-39; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ line 45-49
- 结论: 文件句柄泄漏：在创建新文件句柄前未关闭前一个句柄，导致资源泄漏。
- D验证: confirmed / ver_4b3b49c8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 52. hyp_path_74bd50b71656

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_03.c:49
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行到该代码路径即可触发漏洞，无需外部输入控制。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_03.c:29-30; data = INVALID_HANDLE_VALUE; // 覆盖前未关闭上一句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_03.c:31; data = CreateFile("Case0Sink_w32CreateFile.txt", ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_03.c:37-38; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } // 仅关闭了第二个句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_03.c:47-49
- 结论: 文件句柄泄漏：在重新赋值前未关闭由CreateFile打开的句柄，导致资源泄漏。
- D验证: confirmed / ver_7241ead5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 53. hyp_path_7cfd62d66af4

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_05.c:55
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够触发执行该代码路径（通常通过正常程序流程即可触发，无需特殊输入）
- 触发路径: data = INVALID_HANDLE_VALUE; data = CreateFile("Case0Source_w32CreateFile.txt", ...); @ line 33-37; data = CreateFile("Case0Sink_w32CreateFile.txt", ...); @ line 43-47; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ line 53-57
- 结论: 在CreateFile分配文件句柄后，未关闭原句柄就直接覆盖，导致资源泄露。具体地，代码中首先调用CreateFile创建文件句柄（data），随后再次调用CreateFile覆盖data变量而未关闭前一个句柄，最后仅关闭了后一个句柄，前一个句柄泄露。
- D验证: confirmed / ver_c818dca2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 54. hyp_path_143afadb1718

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_06.c:54
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 第一个CreateFile调用成功，返回有效句柄（非INVALID_HANDLE_VALUE）; 第二个CreateFile调用成功，返回有效句柄并覆盖data变量; 在函数返回前，第一个句柄未被显式关闭
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...) @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_06.c:34; data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...) @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_06.c:44; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } // 只关闭了第二个句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_06.c:54
- 结论: 文件句柄泄漏：在CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_06函数中，第一个CreateFile创建的句柄被第二个CreateFile覆盖，导致第一个句柄未被关闭，造成句柄泄漏。
- D验证: confirmed / ver_83035e13
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 55. hyp_path_1944d61912f6

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_13.c:49
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无需外部输入控制，只要程序执行该路径即可
- 触发路径: data = INVALID_HANDLE_VALUE; data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ L27-31; data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ L37-41; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ L47-51
- 结论: 文件句柄泄露：两次调用CreateFile但没有关闭第一次打开的句柄，导致资源泄露。
- D验证: confirmed / ver_f9b79f0c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 56. hyp_path_2ecbe3eb63c3

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_07.c:54
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无特殊攻击前提，但需要CreateFile调用成功返回有效句柄
- 触发路径: data = INVALID_HANDLE_VALUE; data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_07.c:32-36; data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_07.c:42-46; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_07.c:52-56
- 结论: 文件句柄泄漏：程序创建第一个文件句柄后，未关闭就直接用第二个句柄覆盖，导致第一个句柄丢失引用，最终无法关闭，造成资源泄漏。
- D验证: confirmed / ver_f385a618
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 57. hyp_path_3e706db2dea0

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_09.c:49
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行到source处的CreateFile并分配句柄，然后执行到sink处的CreateFile而未在中间关闭第一个句柄，且两个CreateFile均成功返回有效句柄。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_09.c:29; data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_09.c:39; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_09.c:48-49
- 结论: 在创建第一个文件句柄后未关闭即重新赋值，导致文件句柄泄漏。
- D验证: confirmed / ver_daf87dba
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 58. hyp_path_0921dcee4992

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_14.c:49
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行到相关代码分支（全局条件globalTrue等），攻击者无法直接控制输入但漏洞逻辑存在
- 触发路径: data = INVALID_HANDLE_VALUE; /* NOTE: Create a file handle using CreateFile() that may not be closed properly */ data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_14.c:27-31; /* NOTE: Point data to another file handle without closing the handle from the source */ data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_14.c:37-41; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } /* 仅关闭第二个句柄，第一个泄漏 */ @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_14.c:47-51
- 结论: 缺少对活动文件描述符的引用（句柄泄漏），第一个文件句柄在重新赋值前未关闭，导致资源泄漏。
- D验证: confirmed / ver_1179d38d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 59. hyp_path_35cda7b8cd9e

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_10.c:49
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够触发代码执行路径，使得第一次CreateFile成功返回有效句柄。
- 触发路径: data = INVALID_HANDLE_VALUE; /* NOTE: Create a file handle using CreateFile() that may not be closed properly */ data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...) @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_10.c:27-31; /* NOTE: Point data to another file handle without closing the handle from the source */ data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...) @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_10.c:37-41; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_10.c:47-51
- 结论: 在重新给文件句柄变量赋值前未关闭之前的句柄，导致文件句柄泄漏。
- D验证: confirmed / ver_037d4761
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 60. hyp_path_8c3af727bd2e

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_18.c:49
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无特殊攻击者控制输入，代码本身固有漏洞
- 触发路径: data = INVALID_HANDLE_VALUE; data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_18.c:27-31; data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_18.c:37-41; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_18.c:47-51
- 结论: 在函数中，先通过CreateFile打开文件句柄并赋值给data，然后未关闭该句柄，又通过CreateFile打开另一个文件句柄覆盖data，导致第一个文件句柄丢失引用，造成资源泄漏（文件句柄泄漏）。最后虽然对data调用CloseHandle，但仅关闭了第二个句柄。
- D验证: confirmed / ver_e94697a4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 61. hyp_path_5dab3f29a8ca

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_16.c:49
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无外部输入控制，漏洞由代码自身逻辑引入，无需攻击者输入
- 触发路径: data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_16.c:37-41; data = INVALID_HANDLE_VALUE; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_16.c:27-31; data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_16.c:27-31; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_16.c:47-51
- 结论: 在 switch-case 结构中，先通过 CreateFile 打开一个文件句柄并赋值给 data，随后立即将 data 覆盖为 INVALID_HANDLE_VALUE，再通过另一个 CreateFile 打开新句柄。第一个句柄未在覆盖前关闭，导致文件句柄泄漏（丢失对活动文件描述符的引用）。
- D验证: confirmed / ver_7c00d463
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 62. hyp_path_37057c27cf35

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_31.c:50
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行到第38行创建第二个句柄时，第一个句柄仍保持打开状态；由于文件路径固定，程序正常执行即可触发该路径。
- 触发路径: data = INVALID_HANDLE_VALUE; data = CreateFile("Case0Source_w32CreateFile.txt", ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_31.c:27-31; HANDLE data = dataCopy; data = CreateFile("Case0Sink_w32CreateFile.txt", ...); /* 未关闭之前的句柄 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_31.c:38-42; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } /* 仅关闭最后一个句柄，前一个泄漏 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_31.c:48-52
- 结论: 在创建新文件句柄前未关闭之前的文件句柄，导致文件句柄泄漏。
- D验证: confirmed / ver_d3db0eee
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 63. hyp_path_8502a56062a5

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_33.cpp:53
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 代码本身存在逻辑缺陷，无需攻击者控制输入
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_33.cpp:33; data = CreateFile("Case0Sink_w32CreateFile.txt", ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_33.cpp:43; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_33.cpp:53
- 结论: 文件句柄泄漏：第一个CreateFile创建的句柄在第二次CreateFile赋值后丢失引用，未关闭。
- D验证: confirmed / ver_99a51bde
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 64. hyp_path_93ce71227663

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_72b.cpp:44
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: dataVector[2]中包含一个之前打开的有效HANDLE（由源函数提供），且未在重新赋值前关闭。
- 触发路径: HANDLE data = dataVector[2]; /* NOTE: Point data to another file handle without closing the handle from the source */ data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...) @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_72b.cpp:32-34; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_72b.cpp:42-46
- 结论: 在函数中，从vector中取出一个HANDLE后，没有先关闭该句柄就直接用CreateFile返回的新句柄覆盖，导致原句柄泄漏（文件描述符泄漏）。
- D验证: confirmed / ver_348921af
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 65. hyp_path_1de89aa6ba46

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_34.c:57
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序以正常方式执行，无需攻击者特殊输入；两个 CreateFile 调用均成功返回有效句柄（非 INVALID_HANDLE_VALUE）。
- 触发路径: data = INVALID_HANDLE_VALUE; /* NOTE: Create a file handle using CreateFile() that may not be closed properly */ data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ 第34-38行; HANDLE data = myUnion.unionSecond; /* NOTE: Point data to another file handle without closing the handle from the source */ data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); // 重新声明 data，隐藏外部句柄 @ 第45-49行; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } /* 只关闭了内部 data 对应的第二个句柄，外部句柄泄漏 */ @ 第55-59行
- 结论: 代码在内部作用域重新声明了同名局部变量 data，隐藏了外部作用域中先前通过 CreateFile 创建的句柄，导致外部句柄无法关闭，造成资源泄漏。
- D验证: confirmed / ver_40447b54
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 66. hyp_path_1fa74c316e27

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_15.c:50
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序必须进入case 6分支，该条件在测试用例中由固定值保证，实际攻击场景可能无法控制，但路径本身可达
- 触发路径: case 6: /* NOTE: Point data to another file handle without closing the handle from the source */ data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_15.c:38-40; data = INVALID_HANDLE_VALUE; /* NOTE: Create a file handle using CreateFile() that may not be closed properly */ data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_15.c:42-44; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } break; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_15.c:48-50
- 结论: 文件句柄泄漏：在case 6中，先调用CreateFile打开文件'Case0Sink_w32CreateFile.txt'并将句柄赋给data，随后立即将data赋值为INVALID_HANDLE_VALUE，导致第一个句柄丢失而未关闭；之后再次调用CreateFile打开'Case0Source_w32CreateFile.txt'并赋给data，最后只关闭了第二个句柄。第一个句柄未被关闭，造成资源泄漏。
- D验证: confirmed / ver_0da87b10
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 67. hyp_path_3c5b70db56d6

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_32.c:55
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行至此路径，无需外部输入控制
- 触发路径: HANDLE data = *dataPtr1; data = CreateFile("Case0Source_w32CreateFile.txt", ...); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_32.c:33; HANDLE data = *dataPtr2; data = CreateFile("Case0Sink_w32CreateFile.txt", ...); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_32.c:43; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_32.c:55
- 结论: 文件句柄泄露：第一次CreateFile创建的句柄（第33行）在后续被第二次CreateFile覆盖时未关闭，导致句柄泄漏。
- D验证: confirmed / ver_0e782a86
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 68. hyp_path_ae2a69af44da

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_73b.cpp:44
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: dataList不为空，且其中的HANDLE是有效打开的文件句柄
- 触发路径: HANDLE data = dataList.back(); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_73b.cpp:32-33; data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_73b.cpp:34; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } // 只关闭新句柄，旧句柄泄漏 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_73b.cpp:44
- 结论: 函数从list中取出一个HANDLE，但未关闭该句柄就直接用CreateFile创建的新句柄覆盖，导致原句柄泄漏。
- D验证: confirmed / ver_b195c5e0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 69. hyp_path_e745e484d771

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22b.c:42
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 变量 data 在进入 sink 函数前已经持有某个已打开的文件描述符
- 触发路径: /* NOTE: Assign data to another file descriptor without closing the descriptor from the source */ data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ L36-40; if (data != -1) { CLOSE(data); } @ L42
- 结论: 潜在漏洞：在重新分配文件描述符之前未关闭之前的描述符，导致文件描述符泄漏（CWE-773）。
- D验证: confirmed / ver_7911a344
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 70. hyp_path_04c0690a1769

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52c.c:37
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 调用者向此sink函数传入一个已打开的有效文件描述符，且该描述符未被调用者或此函数关闭。
- 触发路径: data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52c.c:37; if (data != -1) { CLOSE(data); } // 仅关闭新打开的描述符，原始描述符未关闭 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52c.c:38-39
- 结论: 函数打开新文件描述符并赋值给同一变量，导致原始文件描述符丢失引用而未关闭，造成资源泄漏。
- D验证: confirmed / ver_c4064954
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 71. hyp_path_e0de01d28e5f

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_45.c:41
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无需攻击者控制输入；代码本身在赋值前未关闭旧的全局变量所引用的文件描述符。
- 触发路径: int data = CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_45_case0Data; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_45.c:35; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_45.c:41; // 赋值后，旧文件描述符（来自 case0Data）丢失引用，未被关闭 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_45.c:41
- 结论: 在覆盖全局变量中存储的文件描述符前未关闭旧描述符，导致文件描述符泄漏。
- D验证: confirmed / ver_00ee6cd1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 72. hyp_path_15f7e4f7240b

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_63b.c:38
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 函数被调用时，dataPtr指向一个有效的、已打开且未关闭的文件描述符。
- 触发路径: int data = *dataPtr; @ testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_63b.c:32; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_63b.c:34
- 结论: 函数从dataPtr读取旧文件描述符后，未关闭旧描述符即将其覆盖为新打开的文件描述符，导致旧文件描述符泄漏。无论新打开是否成功，旧描述符均丢失。
- D验证: confirmed / ver_3f65e7ee
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 73. hyp_path_7ae573f39336

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_54e.c:37
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 存在先前未关闭的文件描述符与本次open关联
- 触发路径: data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); if (data != -1) { CLOSE(data); } @ L31-37
- 结论: 可能存在之前未关闭的文件描述符导致的泄漏，但当前代码片段仅展示了一次open/close，无法确认完整泄漏路径
- D验证: confirmed / ver_f959b8b4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 74. hyp_path_e9c78fd45f68

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_64b.c:41
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够控制调用此sink函数时的参数，使其指向一个已打开的文件描述符。
- 触发路径: int data = (*dataPtr); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_64b.c:35; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_64b.c:41; if (data != -1) { CLOSE(data); } // 仅关闭新描述符，原描述符未关闭 @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_64b.c:41-43
- 结论: 函数接收一个文件描述符指针，解引用后直接覆盖该描述符（重新打开新文件），但未先关闭原描述符，导致原文件描述符泄露（资源泄露）。
- D验证: confirmed / ver_8fb82422
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 75. hyp_path_a0b310f9c488

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_67b.c:43
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 结构体 myStruct 中的 structFirst 包含一个之前打开的有效文件描述符，且该描述符在赋值前未被关闭。
- 触发路径: int data = myStruct.structFirst; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_67b.c:37; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_67b.c:39
- 结论: CWE-773: Missing Reference to Active File Descriptor or Handle - 文件描述符泄露
- D验证: confirmed / ver_fb9b9ab1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 76. hyp_path_405baf0ebee0

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_66b.c:39
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够控制dataArray的内容或触发此sink函数执行
- 触发路径: int data = dataArray[2]; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_66b.c:33-37; if (data != -1) { CLOSE(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_66b.c:37-41
- 结论: 在文件描述符操作中，原始文件描述符（来自dataArray[2]）未被关闭就被覆盖，导致资源泄漏。
- D验证: confirmed / ver_c2bce199
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 77. hyp_path_eb0cfa7755c2

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_81_case0.cpp:31
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 参数data在调用时为有效的文件描述符（如来自前序未关闭的打开操作）
- 触发路径: data = OPEN(...); // 打开新文件，覆盖原始描述符 @ action函数入口; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ L25-29; if (data != -1) { CLOSE(data); } // 仅关闭新描述符，原始描述符未关闭 @ L29-33
- 结论: 在action函数中，参数data可能代表一个已经打开的文件描述符，但函数中将其重新赋值为新打开的文件描述符，未先关闭原始描述符，导致原始描述符泄漏。
- D验证: confirmed / ver_bde87e5b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 78. hyp_path_f1e13811d945

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68b.c:42
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: source函数（如CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68a_case0Source）已执行，通过open()打开文件描述符并存入全局变量。
- 触发路径: int data = CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68_case0DataForCase0Sink; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68b.c:36; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); /* 覆盖data，未关闭原文件描述符 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68b.c:38; if (data != -1) { CLOSE(data); } /* 只关闭新打开的描述符，原描述符泄漏 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68b.c:40-42
- 结论: 在sink函数中，从全局变量获取一个已打开的文件描述符后，未关闭该描述符就直接覆盖其值，导致原文件描述符泄漏。
- D验证: confirmed / ver_eb15727e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 79. hyp_path_c64907e7f486

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_21.c:41
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行路径中data变量在重新赋值前已持有一个有效的文件句柄
- 触发路径: /* 先前的句柄（未显示） */ @ L29-33 (隐含先前的句柄获取); data = CreateFile("Case0Sink_w32CreateFile.txt", ...); @ L41; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } // 只关闭新句柄，旧句柄泄漏 @ L39-43
- 结论: 存在CWE-773：文件句柄泄漏。代码中data在重新赋值前未关闭之前打开的文件句柄。注释明确指示存在先前的句柄，但仅关闭新句柄，导致旧句柄泄漏。
- D验证: confirmed / ver_4f07bf7a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 80. hyp_path_c9418ebf47d4

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_82_case0.cpp:31
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 调用者传入一个有效的已打开文件描述符作为参数data; 传入的data在函数入口处未被检查或关闭即被覆盖
- 触发路径: data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_82_case0.cpp:25; if (data != -1) { CLOSE(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_82_case0.cpp:31
- 结论: CWE-773: Missing Reference to Active File Descriptor or Handle - 函数action覆盖传入的文件描述符data而未先关闭旧描述符，导致旧描述符泄漏。
- D验证: confirmed / ver_389be680
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 81. hyp_path_14174de1116b

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22b.c:41
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 函数接收一个有效句柄作为参数
- 触发路径: HANDLE data = 传入参数 @ 函数入口; data = CreateFile(...) @ 29-33行
- 结论: CWE-773: Missing Reference to Active File Descriptor or Handle - 在sink函数中，传入的句柄data被CreateFile返回值覆盖而未先关闭，导致原句柄泄漏。
- D验证: confirmed / ver_8ea6d243
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 82. hyp_path_cd9ae02c9ebc

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_45.c:40
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序以默认方式执行该函数，无需特殊攻击者输入。
- 触发路径: HANDLE data = CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_45_case0Data; /* NOTE: Point data to another file handle without closing the handle from the source */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_45.c:28-30; data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...) @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_45.c:30-31; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_45.c:38-42
- 结论: 在函数case0Sink中，HANDLE变量data从一个源句柄重新赋值为新创建的文件句柄，但未关闭之前的句柄，导致文件句柄泄漏（CWE-773）。
- D验证: confirmed / ver_0d67e38e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 83. hyp_path_c6e4e141ea7b

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_41.c:36
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 存在两次连续的CreateFile调用，第一次返回的句柄被第二次覆盖而未调用CloseHandle
- 触发路径: data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ L24-28; 存在第二次CreateFile调用，如 data = CreateFile(...)，但未先关闭第一次句柄 @ 推测在L28之后、L34之前; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } // 仅关闭最后打开的句柄 @ L34-38
- 结论: 在case0Sink函数中，通过重新赋值变量data而不关闭前一个句柄，导致文件句柄泄漏，符合CWE-773
- D验证: confirmed / ver_a2e79482
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 84. hyp_path_c19b1c0dfe13

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_51b.c:36
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 调用者需要先打开一个文件句柄并存储在data中，然后调用此sink函数；或者通过某种方式使data包含一个未关闭的句柄（如循环调用）。
- 触发路径: data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); // 覆盖旧句柄，未关闭 @ line 36; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } // 仅关闭新句柄 @ line 34-38
- 结论: 在未关闭先前打开的文件句柄的情况下重新赋值变量data，导致文件句柄泄漏。尽管调用者代码未提供，但函数注释明确指示了漏洞意图，且sink函数内部仅关闭新句柄，未处理旧句柄。
- D验证: confirmed / ver_6080b26c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 85. hyp_path_2dbde3b4b891

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_54e.c:36
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 存在一个之前已打开的文件句柄保存在data中
- 触发路径: data = CreateFile(...); // 假设之前已赋值 @ L? (之前打开的句柄，未在片段中显示); data = CreateFile("Case0Sink_w32CreateFile.txt", ...); // 重新赋值，丢失旧句柄 @ L24-25; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } // 仅关闭新句柄 @ L34-38
- 结论: 检测到CWE-773：缺少对活动文件描述符或句柄的引用。代码注释明确指出将data指向另一个文件句柄而不关闭源句柄，导致资源泄漏。
- D验证: confirmed / ver_e419174d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 86. hyp_path_1982b79bd247

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_53d.c:36
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 调用方传递一个已打开的文件句柄给sink函数; 攻击者能够通过多次调用该函数或类似函数来累积未关闭句柄，最终耗尽系统资源
- 触发路径: void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_53d_case0Sink(HANDLE data) { ... } @ 函数入口 (CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_53d_case0Sink); /* NOTE: Point data to another file handle without closing the handle from the source */ data = CreateFile(...); @ 函数内第24-28行; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ 函数内第34-38行
- 结论: 在函数入口处，data参数可能已持有来自调用方的打开句柄，但函数内部直接覆盖data而未先关闭旧句柄，导致句柄泄漏。
- D验证: confirmed / ver_e45d3b5c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 87. hyp_path_82bfec0645be

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_44.c:36
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够通过外部输入或其他方式使程序在调用case0Sink之前打开一个文件句柄，并将该句柄作为参数data传入。
- 触发路径: void case0Sink(HANDLE data) @ 函数入口（参数data）; /* NOTE: Point data to another file handle without closing the handle from the source */ data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_44.c:24-28; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } // 仅关闭新创建的句柄，原句柄泄漏 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_44.c:34-38
- 结论: 在函数case0Sink中，传入的句柄data被重新赋值为新创建的文件句柄（CreateFile），但原句柄未关闭，导致文件描述符泄漏（CWE-773）。
- D验证: confirmed / ver_3046206e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 88. hyp_path_9223b3875511

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_65b.c:36
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 调用者传入一个已打开的有效 HANDLE 给 data
- 触发路径: 函数入口，data 为传入的 HANDLE 参数 @ L23 (入口); data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ L36; CloseHandle(data); // 仅关闭新句柄，未关闭原句柄 @ L38
- 结论: 在函数入口处 data 可能持有来自调用者的已打开文件句柄，但在重新赋值给 CreateFile 返回的新句柄之前未关闭原句柄，导致原句柄泄漏。
- D验证: confirmed / ver_1b41b5cc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 89. hyp_path_71cac9bb4dce

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_52c.c:36
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 函数入口时data参数包含一个有效的文件句柄（来自上层调用），但被CreateFile覆盖而未关闭。
- 触发路径: data = CreateFile(...); // 覆盖原句柄而不关闭 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_52c.c:36; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } // 只关闭新句柄，原始句柄泄漏 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_52c.c:34-38
- 结论: 存在文件描述符泄漏漏洞：在重新分配文件句柄之前未关闭原始句柄，导致原始文件描述符未关闭。
- D验证: confirmed / ver_b16ae546
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 90. hyp_path_12065cc19fd9

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_66b.c:38
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: dataArray[2]中包含一个已打开的HANDLE（由调用者传入且未在其他位置关闭）
- 触发路径: HANDLE data = dataArray[2]; /* NOTE: Point data to another file handle without closing the handle from the source */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_66b.c:26-27; data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_66b.c:28-30; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_66b.c:36-40
- 结论: 文件句柄泄漏漏洞：从dataArray[2]获取旧句柄后未关闭即重新赋值，导致旧句柄泄漏。
- D验证: confirmed / ver_6e43bc4a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 91. hyp_path_eb4279fded60

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_63b.c:37
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够控制函数参数dataPtr，使其指向一个之前已打开但未关闭的文件句柄。
- 触发路径: HANDLE data = *dataPtr; /* NOTE: Point data to another file handle without closing the handle from the source */ data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_63b.c:25-29
- 结论: 在函数中，通过指针获取文件句柄后，直接覆盖该句柄变量，导致原始句柄未被关闭，造成文件句柄泄漏（Missing Reference to Active File Descriptor or Handle）。
- D验证: confirmed / ver_9f03f651
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 92. hyp_path_7d18e3a1bbf8

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_67b.c:42
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 调用者必须提前打开一个有效文件句柄并存入myStruct.structFirst。
- 触发路径: HANDLE data = myStruct.structFirst; @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_67b.c:30; data = CreateFile(...); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_67b.c:32; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } // 仅关闭新句柄，原始句柄未关闭 @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_67b.c:40-44
- 结论: 在CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_67b_case0Sink函数中，从结构体获取的原始文件句柄（myStruct.structFirst）被CreateFile返回的新句柄覆盖，而未在覆盖前关闭原始句柄，导致文件描述符泄漏。
- D验证: confirmed / ver_28928b88
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 93. hyp_path_5416d2994120

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_64b.c:40
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够控制dataPtr参数，使其指向一个已打开但未关闭的文件句柄。; 调用sink函数前，存在一个对应的source函数创建了该句柄且未关闭。
- 触发路径: HANDLE data = (*dataPtr); /* NOTE: Point data to another file handle without closing the handle from the source */ data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_64b.c:28-32; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_64b.c:38-42
- 结论: 在sink函数中，从传入指针获取文件句柄后，直接通过CreateFile覆盖该句柄，导致原句柄丢失引用而未被关闭，造成资源泄露（CWE-773 Missing Reference to Active File Descriptor or Handle）。
- D验证: confirmed / ver_e6e581ac
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 94. hyp_path_083fcb7c379a

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_81_case0.cpp:37
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者需要能够控制文件创建过程（但本例中文件名固定，漏洞更多是资源泄漏而非直接攻击利用）
- 触发路径: /* NOTE: Point data to another file handle without closing the handle from the source */ data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... @ 25-29行; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ 35-39行
- 结论: 存在文件句柄泄漏漏洞：在重新赋值句柄变量前未关闭之前打开的文件句柄，导致句柄资源泄漏。
- D验证: confirmed / ver_5eb80570
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 95. hyp_path_3bc05fadbb7f

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68b.c:41
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 全局变量中存储的原始句柄有效且未关闭
- 触发路径: HANDLE data = CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68_case0DataForCase0Sink; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68b.c:29-31; data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68b.c:31-33; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68b.c:39-43
- 结论: 代码中在重新赋值句柄前未关闭之前的文件句柄，导致文件句柄泄漏（资源泄漏）。
- D验证: confirmed / ver_310cf14c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 96. hyp_path_b5c410967015

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84_case0.cpp:33
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行了构造函数中的open操作，且未在析构函数覆盖前关闭原描述符; 攻击者能够反复创建和销毁对象以耗尽文件描述符
- 触发路径: data = OPEN("source.txt", O_RDWR); // 打开文件 @ 构造函数（假设存在）; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); // 覆盖data，丢失原描述符引用 @ 析构函数 L31; if (data != -1) { CLOSE(data); } // 仅关闭新描述符，原描述符未关闭 @ 析构函数 L37
- 结论: 在构造函数中打开的文件描述符在析构函数中被覆盖而未关闭，导致资源泄漏。
- D验证: confirmed / ver_acfef169
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 97. hyp_path_aad631b0059a

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_83_case0.cpp:39
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 在进入析构函数前，data变量已经持有从source（如之前CreateFile调用）获取的有效文件句柄。
- 触发路径: data = CreateFile(...); // 获得旧句柄 @ 构造函数或其他初始化函数（假设位置）; /* NOTE: Point data to another file handle without closing the handle from the source */ data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_83_case0.cpp:37-41; if (data != INVALID_HANDLE_VALUE) { CloseHandle(data); } // 仅关闭新句柄，未关闭旧句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_83_case0.cpp:47-51
- 结论: 在析构函数中，重新给data赋值新文件句柄而未先关闭旧句柄，导致对之前活跃的文件句柄丢失引用，造成资源泄漏。source步骤假设在构造函数或初始化函数中data通过CreateFile获得有效句柄（测试用例设计如此），但代码证据未提供具体行号。
- D验证: confirmed / ver_ed217604
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 98. hyp_path_af4e0e4fda0d

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_84_case0.cpp:39
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: data成员变量在析构函数调用前已持有从CreateFile或类似函数返回的有效句柄（例如在构造函数中打开）。
- 触发路径: data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_84_case0.cpp:39; /* NOTE: Point data to another file handle without closing the handle from the source */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_84_case0.cpp:39（注释）
- 结论: 在析构函数中，data成员变量可能已持有有效文件句柄（来自构造函数或其他成员函数），但代码未先关闭旧句柄，直接覆盖为新句柄，导致旧句柄泄漏，符合CWE-773特征。
- D验证: confirmed / ver_5da6e484
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 99. hyp_path_f031b7879fd4

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_72a.cpp:36
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: fopen调用成功，返回非NULL文件指针
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_72a.cpp:36; dataVector.insert(dataVector.end(), 1, data); ... case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_72a.cpp:40-44
- 结论: 在CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_72a.cpp中，文件句柄通过fopen打开后未被关闭，而是被放入vector中传递到case0Sink函数；基于典型Juliet badSink实现，case0Sink不会关闭句柄，且vector析构不释放FILE*，导致文件描述符泄漏。
- D验证: confirmed / ver_8cf14c2a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 100. hyp_path_01714de2c38f

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_83_case0.cpp:33
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无需攻击者控制输入；漏洞由代码逻辑缺陷自动触发。
- 触发路径: data = OPEN(...) // 第一次打开，赋值给成员data @ 构造函数（未提供）; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); // 第二次打开，覆盖原值 @ 析构函数 line 33; if (data != -1) { CLOSE(data); } // 只关闭新描述符，旧描述符泄漏 @ 析构函数 line 37
- 结论: 在CWE773测试用例中，析构函数将成员变量'data'重新赋值为新打开的文件描述符，而未关闭先前构造函数中打开的描述符，导致文件描述符泄漏。
- D验证: confirmed / ver_303cd3d3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 101. hyp_path_5cd37f34064e

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_22a.c:31
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者无直接输入控制，但程序执行fopen后未关闭句柄即可导致漏洞
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_22a.c:31; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_22_case0Sink(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_22a.c:33
- 结论: 文件句柄未关闭，导致资源泄漏。
- D验证: confirmed / ver_22649360
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 102. hyp_path_ec106c857444

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53a.c:29
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: fopen()成功打开文件，返回非NULL句柄；sink函数内部不执行fclose()
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53a.c:28; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53b_case0Sink(data); // 未关闭句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53a.c:29
- 结论: 文件句柄未关闭，导致资源泄漏。fopen()打开文件后，未调用fclose()关闭句柄，直接传递到sink函数，造成文件描述符泄漏。
- D验证: confirmed / ver_1639c7a8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 103. hyp_path_94281c7e2b3c

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_51a.c:29
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 系统允许打开文件（fopen成功），且sink函数未对文件句柄进行关闭操作。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_51a.c:29; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_51a.c:30
- 结论: 文件句柄未正确关闭，导致文件描述符泄漏（资源泄漏），可能耗尽系统文件描述符资源。
- D验证: confirmed / ver_f4d368a4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 104. hyp_path_57aacb8f8495

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_52a.c:29
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够控制程序执行此路径（单次执行即可导致一个文件描述符泄露）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_52a.c:29; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_52a.c:30
- 结论: 调用fopen打开文件后未关闭文件句柄，导致文件描述符资源泄露，即使单次执行也会造成资源未释放。
- D验证: confirmed / ver_2906846c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 105. hyp_path_3a82112e3641

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_54a.c:29
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 文件路径为硬编码，fopen可能成功；无需攻击者输入控制
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_54a.c:29; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_54b_case0Sink(data); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_54a.c:30
- 结论: 文件句柄泄漏：使用fopen()打开文件后，未调用fclose()关闭文件句柄，导致文件描述符资源泄漏。
- D验证: confirmed / ver_401c78e2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 106. hyp_path_453dae42a9e7

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_63a.c:29
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 文件"Case0Source_fopen.txt"可正常打开，fopen返回非NULL。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_63a.c:29; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_63b_case0Sink(&data); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_63a.c:30
- 结论: 文件打开后未关闭，导致文件描述符泄漏。
- D验证: confirmed / ver_f3b392c4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 107. hyp_path_89c14d0e8b63

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_74a.cpp:36
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够触发该代码路径的执行（如通过输入控制程序流程）或程序本身自动执行该路径导致资源耗尽。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_74a.cpp:36; dataMap[0] = data; dataMap[1] = data; dataMap[2] = data; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_74a.cpp:37-41; case0Sink(dataMap); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_74a.cpp:42; 未调用fclose() @ sink函数内部（未显示关闭操作）
- 结论: 文件句柄未关闭，导致资源泄露，最终可能耗尽系统文件描述符。
- D验证: confirmed / ver_8acc9fbe
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 108. hyp_path_635b42c6cb02

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_64a.c:29
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者无需输入控制，仅需程序运行即可导致文件描述符泄露；若攻击者可影响文件操作次数，可加速资源耗尽。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_64a.c:29; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_64a.c:30
- 结论: 程序使用fopen打开文件后，未在适当位置关闭文件句柄，导致文件描述符泄露，可能引发资源耗尽或拒绝服务。
- D验证: confirmed / ver_12953918
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 109. hyp_path_d010b8d8d540

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_81a.cpp:30
- 漏洞类型: null_deref
- CWE: CWE-773
- 风险等级: P0
- 触发条件: fopen()调用成功返回非空指针; 程序未提供任何关闭文件句柄的操作; action函数内部未关闭文件句柄
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_81a.cpp:30; baseObject.action(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_81a.cpp:32
- 结论: 文件句柄未关闭导致文件描述符泄漏。代码中调用fopen()打开文件，但未调用fclose()关闭，且将文件指针传递给action函数，可能导致句柄资源无法释放。
- D验证: confirmed / ver_a9da5c7c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 110. hyp_path_36bee6aa2278

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_73a.cpp:36
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无特殊攻击前提条件，为代码自身缺陷；若持续调用该函数可耗尽系统文件描述符。
- 触发路径: data = NULL; data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_73a.cpp:36; dataList.push_back(data); dataList.push_back(data); dataList.push_back(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_73a.cpp:40-42; case0Sink(dataList); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_73a.cpp:43
- 结论: 文件句柄使用fopen()创建后未调用fclose()关闭，导致文件描述符泄漏，符合CWE-773 Missing Reference to Active File Descriptor or Handle。
- D验证: confirmed / ver_63e95fee
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 111. hyp_path_746429dd8440

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_82a.cpp:30
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序在调用action后未关闭文件句柄，且未传递句柄给其他关闭操作。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_82a.cpp:30; baseObject->action(data); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_82a.cpp:31
- 结论: 文件句柄未关闭，导致资源泄露漏洞。
- D验证: confirmed / ver_a3f41229
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 112. hyp_path_995e4fe6856a

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_21.c:33
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 代码执行到case0Sink且case0Static为真
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_21.c:33; data = fopen("Case0Sink_fopen.txt", "w+"); /* 未先关闭原data */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_21.c:26-28; if (data != NULL) { fclose(data); } /* 仅关闭新句柄，原句柄泄漏 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_21.c:29-30
- 结论: 文件描述符泄漏：在case0Sink函数中，将data重新指向新打开的文件，而没有先关闭之前的文件句柄，导致原文件句柄泄漏。
- D验证: confirmed / ver_97acd544
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 113. hyp_path_e84b108784af

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_44.c:39
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序正常执行到此路径，fopen 成功返回非 NULL 句柄。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ 39; funcPtr(data); // 文件句柄传递后未关闭 @ 40
- 结论: 文件描述符泄露：fopen() 打开的文件句柄未关闭，可能导致文件描述符耗尽。
- D验证: confirmed / ver_462fe6f6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 114. hyp_path_d37c57fcce62

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_41.c:28
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序能成功执行到case0Sink函数，且fopen调用成功。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_41.c:27; case0Sink(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_41.c:29; data = fopen("Case0Sink_fopen.txt", "w+"); // 重新赋值，丢失前一个文件句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_41.c:23
- 结论: 在函数case0Sink中，通过重新赋值丢失了源文件句柄的引用，导致前一个fopen打开的文件句柄未关闭，造成文件描述符泄漏（CWE-773）。
- D验证: confirmed / ver_df1e9cdd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 115. hyp_path_2aa21d8edf46

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_65a.c:31
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: fopen() 调用成功返回非NULL文件指针
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_65a.c:31; funcPtr(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_65a.c:33
- 结论: 文件句柄未关闭，导致资源泄漏，可能耗尽系统文件描述符（但需确认 funcPtr 实现是否包含 fclose）
- D验证: confirmed / ver_99073cb5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 116. hyp_path_d31a87e77ce0

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52a.c:39
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者无法控制输入，但测试用例中路径自动可达
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52a.c:39; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52a.c:40
- 结论: 打开文件描述符后未关闭，导致文件描述符泄漏，可能耗尽系统资源。
- D验证: confirmed / ver_9ceabf4e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 117. hyp_path_f70b88ab5407

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_51a.c:39
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无外部输入控制，但代码本身即触发漏洞
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_51a.c:39; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_51b_case0Sink(data); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_51a.c:40
- 结论: 函数打开文件描述符后未关闭，且未检查open()返回值，可能导致文件描述符耗尽（FD泄漏）。
- D验证: confirmed / ver_8f5b3480
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 118. hyp_path_e60a715a6cf1

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22a.c:41
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序逻辑导致文件描述符泄漏，无需攻击者输入控制。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22a.c:41; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_case0Sink(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22a.c:43
- 结论: 文件描述符在打开后未正确关闭，导致资源泄漏（Missing Reference to Active File Descriptor or Handle）。
- D验证: confirmed / ver_ab736ce6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 119. hyp_path_be8147746d30

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_54a.c:39
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无外部输入控制，代码自动执行；漏洞依赖sink函数实现是否关闭文件描述符。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_54a.c:39; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_54b_case0Sink(data); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_54a.c:40
- 结论: 文件描述符可能未正确关闭，存在资源泄漏风险（CWE-773），但sink函数实现未知，路径不闭合。
- D验证: confirmed / ver_bbb207b5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 120. hyp_path_dde827e73e8c

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_53a.c:39
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序以默认或可写权限创建文件，且后续未关闭文件描述符。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_53a.c:39; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_53a.c:40
- 结论: 程序通过open()创建文件描述符后，传递给sink函数，但未在sink函数内或后续代码中关闭该文件描述符，导致资源泄漏（缺少对活动文件描述符的引用）。
- D验证: confirmed / ver_66b4947b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 121. hyp_path_8ea6dc9b2fce

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_64a.c:39
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序以可写模式创建文件，但无需攻击者控制输入；文件描述符泄漏属于资源管理问题。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_64a.c:38; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_64b_case0Sink(&data); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_64a.c:39
- 结论: 在CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_64a.c中，通过open()创建的文件描述符被传递给sink函数，但sink函数的具体实现未提供，依据Juliet测试模式，文件描述符可能未被关闭，导致泄漏。
- D验证: confirmed / ver_b769ab18
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 122. hyp_path_c181ab13491d

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22a.c:34
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行到创建文件句柄的代码路径（无需外部输入控制，路径顺序可达）
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22a.c:34; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22_case0Sink(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22a.c:42
- 结论: 文件句柄在创建后未被关闭，导致资源泄漏，可能被攻击者利用造成拒绝服务。
- D验证: confirmed / ver_75ca673d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 123. hyp_path_ad02ea62c67e

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_63a.c:39
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: open()调用成功返回有效文件描述符（非-1）。; 攻击者能够触发该代码路径（正常程序流程）。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_63a.c:38-39; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_63a.c:40
- 结论: 文件描述符泄漏：open()创建文件描述符后，通过指针传递给sink函数，sink函数很可能未关闭该描述符，导致资源泄漏。
- D验证: confirmed / ver_2fe4dddf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 124. hyp_path_55b44f7805cd

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_51a.c:32
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: CreateFile调用成功返回有效句柄（非INVALID_HANDLE_VALUE）; sink函数内部未调用CloseHandle或其他关闭操作
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ...); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_51a.c:32; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_51a.c:39
- 结论: 文件句柄未关闭导致资源泄漏
- D验证: confirmed / ver_11b23013
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 125. hyp_path_51bdaeda09d8

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_52a.c:32
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无特殊前提，只需正常执行被审计函数即可触发句柄泄漏。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_52a.c:32; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_52a.c:39
- 结论: 在 CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_52a.c 中，通过 CreateFile 创建的文件句柄 data 被传递给 sink 函数后，未调用 CloseHandle 关闭句柄，导致文件句柄泄漏。sink 函数实现未提供，但根据 Juliet 测试用例的预期行为，该 sink 函数内部不会关闭句柄，符合 CWE-773 漏洞特征。
- D验证: confirmed / ver_39a3b365
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 126. hyp_path_832ddd1ac102

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_54a.c:32
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者无需特殊控制，只要程序执行此路径即可触发句柄泄漏
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_54a.c:32; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_54a.c:39
- 结论: 文件句柄在创建后未正确关闭，可能导致资源泄露（句柄泄漏），符合CWE-773。但由于sink函数内部实现未公开，需进一步验证。
- D验证: confirmed / ver_69d17c71
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 127. hyp_path_e27f0e16c4cf

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_63a.c:32
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: CreateFile成功返回有效句柄; sink函数内部不关闭句柄且不持久化句柄以便后续关闭
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_63a.c:32; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_63a.c:39
- 结论: 文件句柄创建后未关闭，可能导致资源泄漏（Missing Reference to Active File Descriptor or Handle）
- D验证: confirmed / ver_84009204
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 128. hyp_path_4c31d69a84d3

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_53a.c:32
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行到CreateFile调用，且文件打开成功（返回有效句柄）。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_53a.c:32; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_53a.c:39
- 结论: 文件句柄未关闭，导致资源泄漏。
- D验证: confirmed / ver_6d4c5297
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 129. hyp_path_425de918e862

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_62a.cpp:33
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 函数case0Source内部使用fopen等函数打开文件句柄并写入data所指地址，且调用者未在赋值前关闭该句柄。
- 触发路径: FILE * data; data = NULL; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_62a.cpp:29; case0Source(data); /* 该函数内打开了文件句柄并赋值给data */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_62a.cpp:31; data = fopen("Case0Sink_fopen.txt", "w+"); /* 覆盖data，之前的句柄未被关闭 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_62a.cpp:33
- 结论: 文件描述符泄漏：在重新赋值FILE指针前未关闭之前的文件句柄，导致文件描述符资源泄漏。
- D验证: confirmed / ver_12b9a5ec
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 130. hyp_path_c67111d8d5d8

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_42.c:34
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无特定输入要求；函数自动执行fopen调用。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_42.c:23; data = case0Source(data); /* ... */ data = fopen("Case0Sink_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_42.c:34
- 结论: 在函数case0Source中通过fopen打开的文件句柄未被关闭，随后文件指针被覆盖，导致原始文件句柄丢失引用，造成资源泄漏。
- D验证: confirmed / ver_81bde374
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 131. hyp_path_1a3eff48bfdf

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_64a.c:32
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者可以触发代码路径多次（例如重复调用），导致文件句柄不断创建而不关闭。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... FILE_ATTRIBUTE_NORMAL, NULL); @ L30-34; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_64b_case0Sink(&data); @ L39
- 结论: 函数CreateFile创建的文件句柄被传递给CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_64b_case0Sink，但该sink函数是否关闭句柄未知。若未关闭，则多次调用会导致句柄泄漏，可能耗尽系统资源。
- D验证: confirmed / ver_49786372
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 132. hyp_path_b7ce469426b1

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_43.cpp:36
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无特定攻击输入，代码本身存在资源管理缺陷
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); // 在case0Source中打开，未关闭 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_43.cpp:26; data = fopen("Case0Sink_fopen.txt", "w+"); // 重新赋值，前一个句柄丢失引用 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_43.cpp:36
- 结论: 在函数case0Source中，通过fopen打开文件句柄后未关闭，随后主函数又将data指针重新赋值给另一个fopen打开的文件，导致第一个文件句柄丢失引用，造成文件描述符泄漏（CWE-773）。
- D验证: confirmed / ver_cd7e5ae6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 133. hyp_path_5cdacf17eda5

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_61a.c:30
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: Source函数（CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_61b_case0Source）成功打开一个文件并返回非空句柄。
- 触发路径: data = CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_61b_case0Source(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_61a.c:28; data = fopen("Case0Sink_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_61a.c:30
- 结论: 文件描述符泄漏：在调用Source函数获取文件句柄后，未关闭该句柄就直接覆盖data变量，导致文件描述符泄漏。
- D验证: confirmed / ver_dd2c33f8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 134. hyp_path_fd6f207d6ddd

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84a.cpp:30
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 构造函数内部可能调用open函数创建文件描述符，但析构函数未关闭它。
- 触发路径: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84_case0 * case0Object = new CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84_case0(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84a.cpp:30; delete case0Object; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84a.cpp:31
- 结论: 在CWE773测试用例中，构造函数可能打开文件描述符但未在析构函数中正确关闭，导致文件描述符泄漏。
- D验证: confirmed / ver_685e2b8e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 135. hyp_path_7d3644ec7d72

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_12.c:26
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: globalReturnsTrueOrFalse()函数返回真，使代码进入if分支。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_12.c:26; data = fopen("Case0Sink_fopen.txt", "w+"); // 未关闭前一个句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_12.c:30
- 结论: 文件描述符泄漏：在重新赋值前未关闭先前打开的fopen句柄。
- D验证: confirmed / ver_874e7f60
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 136. hyp_path_3304fa80643c

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_17.c:31
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行到第26行且fopen成功，返回非NULL指针
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_17.c:26; data = fopen("Case0Sink_fopen.txt", "w+"); // 覆盖data，未关闭前一个句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_17.c:31
- 结论: 文件描述符泄漏：第一个fopen打开的文件句柄被覆盖而未关闭，导致资源泄漏。
- D验证: confirmed / ver_552203c8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 137. hyp_path_9f26dbc9f083

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_82a.cpp:31
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 代码被执行；无需外部输入控制；action()函数内部未关闭文件描述符（待确认）。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_82a.cpp:31; baseObject->action(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_82a.cpp:33; delete baseObject; // 未在可见代码中关闭data文件描述符 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_82a.cpp:34
- 结论: 缺失活动文件描述符或句柄的引用，导致文件描述符泄漏。open()打开文件后未在可见代码中调用close()，但action()内部是否关闭未知。
- D验证: confirmed / ver_f0e6dfc1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 138. hyp_path_80a74d413e49

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_81a.cpp:31
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: open()调用成功，返回有效文件描述符（非-1）
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_81a.cpp:30; baseObject.action(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_81a.cpp:33
- 结论: 在CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_81a.cpp中，open()创建文件描述符后通过baseObject.action(data)传递，但未在可见范围内调用close()，且action函数可能未关闭文件描述符，存在文件描述符泄漏风险。
- D验证: confirmed / ver_ee828aa4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 139. hyp_path_c4d9b1ecd2b6

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_81a.cpp:31
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: CreateFile调用成功，返回有效句柄。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, ... FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_81a.cpp:31; baseObject.action(data); @ 同一文件:38; 函数返回前未调用CloseHandle或类似操作。 @ 同一文件:38之后
- 结论: 在函数case0中，使用CreateFile创建了一个文件句柄，但未在函数返回前关闭该句柄，导致文件描述符泄漏。
- D验证: confirmed / ver_6274b413
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 140. hyp_path_f22063e47322

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_44.c:49
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无特殊攻击前提，仅需程序执行到指定代码路径。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_44.c:49
- 结论: 调用open()后未关闭文件描述符，导致资源泄漏。
- D验证: confirmed / ver_6a129fa1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 141. hyp_path_57ffec6ca684

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_65a.c:41
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能影响程序多次执行此代码路径。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_65a.c:41; funcPtr(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_65a.c:42
- 结论: 文件描述符泄漏：调用open()创建文件描述符后未确认关闭，通过函数指针funcPtr传递，但funcPtr的实际行为未知，存在泄漏风险。
- D验证: confirmed / ver_bb79edb0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 142. hyp_path_9386718c7b5c

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_44.c:48
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无额外攻击前提，代码直接执行即可触发漏洞。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_44.c:48
- 结论: 在文件句柄创建后未关闭，导致资源泄漏。
- D验证: confirmed / ver_5f6bd619
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 143. hyp_path_a92c4efe0602

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_08.c:39
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无额外攻击前提，代码本身缺陷
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ 39; if(staticReturnsTrue()) { @ 40; data = fopen("Case0Sink_fopen.txt", "w+"); // 覆盖data，丢失对第一个文件句柄的引用 @ 43
- 结论: 文件句柄泄漏：第一次fopen打开的文件句柄被覆盖，未调用fclose关闭，导致资源泄漏。
- D验证: confirmed / ver_469d0f06
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 144. hyp_path_82ed27604eb0

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_65a.c:34
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者可通过多次调用此函数或触发循环来耗尽系统资源，但无需直接控制输入
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_65a.c:34
- 结论: 文件句柄未关闭导致资源泄漏：CreateFile创建的文件句柄可能未在函数返回前关闭，导致句柄泄漏，多次调用可能耗尽系统资源。但代码证据不完整，后续可能存在CloseHandle。
- D验证: confirmed / ver_067b494e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 145. hyp_path_639270722b89

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_11.c:26
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: globalReturnsTrue()返回真
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_11.c:26; data = fopen("Case0Sink_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_11.c:29; if (data != NULL) { fclose(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_11.c:33-34
- 结论: 函数fopen打开文件后没有关闭文件描述符，导致资源泄露。第一个fopen返回的文件指针被覆盖，未调用fclose。
- D验证: confirmed / ver_2b85e319
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 146. hyp_path_03a359c2b59b

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_02.c:30
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无额外攻击者输入，程序自身逻辑导致资源泄漏
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_02.c:26; data = fopen("Case0Sink_fopen.txt", "w+"); // 覆盖指针，未关闭前一个句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_02.c:30
- 结论: 函数fopen返回的文件句柄被丢失，未关闭导致资源泄漏。第一次调用fopen打开文件'Case0Source_fopen.txt'后，未关闭句柄，直接再次调用fopen覆盖data指针，导致原句柄无法关闭。
- D验证: confirmed / ver_f8df409d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 147. hyp_path_a641730f5d4b

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_03.c:26
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者无需控制输入，但需要前一次fopen成功返回非NULL文件指针
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_03.c:26; data = fopen("Case0Sink_fopen.txt", "w+"); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_03.c:30
- 结论: 文件句柄泄漏：第一次fopen返回的文件句柄在第二次fopen赋值给同一变量前未关闭，导致第一个句柄丢失引用，无法关闭。
- D验证: confirmed / ver_591b98ab
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 148. hyp_path_5dcedf8c3ab5

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_01.c:28
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = NULL; @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_01.c:24; data = fopen("Case0Source_fopen.txt", "w+"); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_01.c:26; data = fopen("Case0Sink_fopen.txt", "w+"); /* 覆盖data，未关闭前一个句柄 */ @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_01.c:28
- 结论: 缺失文件描述符释放：程序使用fopen()打开文件后，未关闭文件句柄就将其覆盖，导致资源泄漏。第一个fopen返回的文件指针被第二个fopen覆盖，第一个文件句柄丢失，无法关闭。
- D验证: confirmed / ver_c7876acd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 149. hyp_path_c70397bae41d

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_04.c:36
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: STATIC_CONST_TRUE 为真（Juliet测试用例中恒为真），代码路径必执行。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_04.c:32; data = fopen("Case0Sink_fopen.txt", "w+"); // 未关闭之前的句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_04.c:36; fclose(data); // 只关闭了后者 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_04.c:40
- 结论: 文件描述符泄漏：在重新赋值文件指针前未关闭先前打开的文件句柄，导致第一个文件句柄丢失引用，造成资源泄漏。
- D验证: confirmed / ver_2898762d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 150. hyp_path_3b7fc86fade4

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_05.c:36
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: staticTrue恒为真，条件分支始终执行
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_05.c:32; data = fopen("Case0Sink_fopen.txt", "w+"); /* 未关闭前一个句柄即覆盖 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_05.c:36; fclose(data); /* 仅关闭新句柄，旧句柄泄漏 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_05.c:40
- 结论: 程序在关闭第一个文件句柄之前将其覆盖，导致第一个文件句柄泄漏。
- D验证: confirmed / ver_aef055ac
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 151. hyp_path_645b47838b15

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_06.c:31
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序正常执行，STATIC_CONST_FIVE值为5（编译期常量），使得if条件恒真，路径可达。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_06.c:31; data = fopen("Case0Sink_fopen.txt", "w+"); /* 重新赋值，丢失第一个句柄 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_06.c:35
- 结论: 代码中存在文件句柄泄露：第一次调用fopen打开文件'Case0Source_fopen.txt'后未关闭，随后将指针重新赋值给另一个fopen返回的句柄，导致原始文件句柄丢失，无法关闭。
- D验证: confirmed / ver_121b8f06
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 152. hyp_path_517e6691afb9

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_09.c:30
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: GLOBAL_CONST_TRUE 为真（通常定义为1）
- 触发路径: data = NULL; data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_09.c:24-28; data = fopen("Case0Sink_fopen.txt", "w+"); /* 未关闭之前的句柄 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_09.c:28-32; if (data != NULL) { fclose(data); } /* 仅关闭新句柄，源句柄泄漏 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_09.c:32-36
- 结论: 在第二次调用fopen时，未关闭之前已打开的文件句柄，导致文件描述符泄漏（CWE-773）。
- D验证: confirmed / ver_64950e52
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 153. hyp_path_41130a147016

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_10.c:26
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者不需要控制任何输入，因为文件名是硬编码的；但漏洞触发依赖于globalTrue为真的条件（代码中固定为真）。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ L26 (juliet-api-misuse/testcases/.../CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_10.c:26); data = fopen("Case0Sink_fopen.txt", "w+"); @ L30 (同一文件:30); if (data != NULL) { fclose(data); } // 只关闭第二个句柄，第一个句柄泄露 @ L34 (同一文件:34)
- 结论: 文件描述符资源泄露：在if(globalTrue)分支中，fopen打开的文件句柄在被覆盖前未关闭，导致前一个文件句柄丢失，符合CWE-773缺失对活跃文件描述符的引用。
- D验证: confirmed / ver_93ccef0d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 154. hyp_path_b4e9243ac527

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_07.c:31
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者无法直接控制文件名（硬编码），但可能导致资源耗尽
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_07.c:31; data = fopen("Case0Sink_fopen.txt", "w+"); // 覆盖指针，未关闭前一个句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_07.c:35
- 结论: 文件句柄泄漏：第一个fopen打开的文件句柄被第二个fopen覆盖，未关闭，导致资源泄漏。
- D验证: confirmed / ver_e8b1c0e1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 155. hyp_path_c89ef500b926

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_13.c:30
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 代码执行到该路径，无需攻击者控制输入
- 触发路径: data = NULL; data = fopen("Case0Source_fopen.txt", "w+"); @ 24-26; data = fopen("Case0Sink_fopen.txt", "w+"); // 未关闭之前的文件句柄 @ 30
- 结论: 在重新赋值文件指针之前未关闭先前打开的文件句柄，导致文件描述符泄漏。
- D验证: confirmed / ver_12adc12e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 156. hyp_path_5d42c46b9606

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_14.c:26
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_14.c:26; data = fopen("Case0Sink_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_14.c:30; fclose(data); // 仅关闭第二个句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_14.c:34
- 结论: 在globalFive==5条件下，先使用fopen打开文件句柄赋值给data，随后未关闭该句柄，直接再次使用fopen覆盖data，导致第一个文件句柄丢失引用，造成资源泄漏（文件描述符泄漏）。
- D验证: confirmed / ver_30556fc5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 157. hyp_path_a226d6571312

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_15.c:31
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行到switch语句，且switch表达式为6（代码中直接写为6，必然进入case 6）
- 触发路径: data = NULL; data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_15.c:26-27; case 6: data = fopen("Case0Sink_fopen.txt", "w+"); /* 覆盖data，前一个句柄丢失 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_15.c:31
- 结论: 在switch case 6中，先通过fopen打开文件Case0Source_fopen.txt，然后立即在同一变量data上再次调用fopen打开Case0Sink_fopen.txt，覆盖了前一个文件句柄，导致第一个句柄无法关闭，造成文件描述符泄露。
- D验证: confirmed / ver_dc4e23db
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 158. hyp_path_107c77b8d0c0

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_16.c:30
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行到该代码路径（无外部控制输入，硬编码文件名）
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_16.c:26; data = fopen("Case0Sink_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_16.c:30
- 结论: 文件描述符泄漏：在循环中，先使用fopen打开文件句柄并赋值给data，随后再次使用fopen打开另一个文件，覆盖了data指针，导致前一个文件句柄丢失引用，无法关闭，造成资源泄漏。
- D验证: confirmed / ver_548fea65
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 159. hyp_path_b1a588a33977

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_18.c:26
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者无需控制输入，漏洞由代码逻辑自动触发
- 触发路径: data = NULL; ... data = fopen("Case0Source_fopen.txt", "w+"); goto sink; @ 24-27; sink: ... data = fopen("Case0Sink_fopen.txt", "w+"); @ 28-30; if (data != NULL) { fclose(data); } // 仅关闭第二个句柄 @ 32-34
- 结论: 在CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_18.c中，程序先通过fopen打开文件Case0Source_fopen.txt，然后通过goto跳转到sink标签，在sink处再次调用fopen打开Case0Sink_fopen.txt并覆盖文件指针data，导致第一个文件句柄没有关闭，造成文件描述符泄漏。
- D验证: confirmed / ver_8bfcfbb8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 160. hyp_path_9d25b68d06cf

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_31.c:31
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无需外部输入，代码本身存在缺陷
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_31.c:26; { FILE * dataCopy = data; @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_31.c:28; data = fopen("Case0Sink_fopen.txt", "w+"); /* NOTE: Point data to another file handle without closing the handle from the source */ @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_31.c:31
- 结论: 存在文件描述符泄露漏洞：程序在未关闭前一个文件句柄的情况下，将指针重新赋值为另一个文件句柄，导致前一个文件句柄丢失引用，无法关闭，造成资源泄露。
- D验证: confirmed / ver_1b699aa0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 161. hyp_path_4327d879ac69

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_33.cpp:30
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无需外部输入；程序自然执行到该代码路径即可触发
- 触发路径: data = NULL; data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_33.cpp:28-30; data = fopen("Case0Sink_fopen.txt", "w+"); // 覆盖data，未关闭前一个句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_33.cpp:34
- 结论: CWE-773: Missing Reference to Active File Descriptor or Handle - 文件句柄未关闭即被覆盖，导致资源泄漏
- D验证: confirmed / ver_d5b0c92f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 162. hyp_path_8ffde19250eb

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_32.c:36
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: fopen函数成功返回非NULL指针
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_32.c:30; *dataPtr1 = data; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_32.c:31; data = fopen("Case0Sink_fopen.txt", "w+"); /* 未关闭先前句柄 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_32.c:36
- 结论: 存在文件句柄泄漏漏洞：在重新赋值文件指针前未关闭已打开的文件句柄，导致资源泄漏。
- D验证: confirmed / ver_67748fbd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 163. hyp_path_93044ce7d83d

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_72b.cpp:32
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 函数被调用时，dataVector[2]包含一个之前通过fopen打开的FILE*指针。
- 触发路径: FILE * data = dataVector[2]; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_72b.cpp:32; data = fopen("Case0Sink_fopen.txt", "w+"); // 覆盖了之前的句柄，未关闭 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_72b.cpp:32
- 结论: 存在文件句柄泄漏漏洞：从dataVector获取FILE指针后，未关闭原始句柄就重新赋值，导致原始句柄丢失引用，无法关闭，造成资源泄漏。
- D验证: confirmed / ver_12f39dbf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 164. hyp_path_6e1bf4f08e7f

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_34.c:33
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够影响程序执行路径，使得两次fopen调用均成功（例如通过环境控制文件存在或权限）。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_34.c:32; data = fopen("Case0Sink_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_34.c:38; fclose(data); // 只关闭了第二个句柄，第一个句柄未被关闭 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_34.c:42
- 结论: 在函数中两次调用fopen()，第二次调用前未关闭第一次打开的文件句柄，导致第一个文件句柄丢失引用，造成资源泄漏。
- D验证: confirmed / ver_eeee8169
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 165. hyp_path_f8adc8d642e5

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_73b.cpp:32
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者不需要控制输入；漏洞由编程逻辑错误直接触发
- 触发路径: FILE * data = dataList.back(); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_73b.cpp:30; data = fopen("Case0Sink_fopen.txt", "w+"); // 原data指向的文件句柄丢失 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_73b.cpp:32
- 结论: 文件描述符泄漏：在从list中获取FILE*指针后，重新赋值fopen结果之前未关闭原文件句柄，导致资源泄漏。
- D验证: confirmed / ver_71eb3ca0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 166. hyp_path_3d4600b83f20

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_74b.cpp:32
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够影响dataMap的内容，使得dataMap[2]指向一个已打开的文件。
- 触发路径: FILE * data = dataMap[2]; @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_74b.cpp:30; data = fopen("Case0Sink_fopen.txt", "w+"); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_74b.cpp:32
- 结论: 在函数CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_74b.cpp的Sink中，从dataMap获取文件指针data后，未关闭原始文件句柄就直接覆盖为新的fopen返回，导致文件描述符泄漏。
- D验证: confirmed / ver_a41e6677
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 167. hyp_path_e570f6743723

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_41.c:24
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够控制source，使其提供一个已打开的文件句柄，并在sink中触发资源泄漏。
- 触发路径: void case0Sink(FILE * data) @ 入口函数case0Sink; data = fopen("Case0Sink_fopen.txt", "w+"); @ 第24行; if (data != NULL) { fclose(data); } // 关闭的是新句柄，旧句柄泄漏 @ 第28行
- 结论: 在打开新文件句柄之前未关闭已有的文件句柄，导致文件描述符泄漏（CWE-773）。
- D验证: confirmed / ver_41d737f1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 168. hyp_path_2b41e9460e75

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_21.c:29
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 在调用case0Sink之前，data变量已经通过fopen获取了一个有效的文件句柄且未关闭。
- 触发路径: data = fopen("previous.txt", "r"); @ 假设的先前fopen点（调用方或本函数之前的代码）; data = fopen("Case0Sink_fopen.txt", "w+"); /* 未关闭旧句柄 */ @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_21.c:29; if (data != NULL) { fclose(data); } /* 只关闭新句柄 */ @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_21.c:33
- 结论: 存在文件描述符泄漏漏洞（CWE-773），在case0Sink函数中，data变量被重新赋值给一个新的fopen返回的文件句柄，但先前的文件句柄未被关闭，导致资源泄漏。虽然当前代码片段未显示先前的fopen，但注释和测试用例设计明确表明存在源句柄。
- D验证: confirmed / ver_83ae6daa
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 169. hyp_path_0021afa426f3

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_22b.c:29
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 在调用sink函数之前，data已通过fopen分配了一个文件句柄。
- 触发路径: data = fopen("Case0Sink_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_22b.c:29
- 结论: 在sink函数中，先前的文件句柄未被关闭即被新句柄覆盖，导致文件句柄泄漏（丢失引用）。
- D验证: confirmed / ver_de46394d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 170. hyp_path_c49ef2ef3b6a

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45.c:28
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 全局变量 CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45_case0Data 在进入 case0Sink 前已由 source 函数设置为指向一个打开的 FILE 句柄。
- 触发路径: FILE * data = CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45_case0Data; @ 26; data = fopen("Case0Sink_fopen.txt", "w+"); @ 28; if (data != NULL) { fclose(data); } @ 30-34
- 结论: 在重新赋值文件指针前未关闭先前打开的文件句柄，导致文件描述符泄漏。
- D验证: confirmed / ver_2748bb20
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 171. hyp_path_9af2f29b14f9

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_51b.c:24
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够将任意打开的文件句柄作为参数传递给该函数（或函数被调用时传入的文件句柄未被关闭）
- 触发路径: 函数入口，接收文件指针data @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_51b.c:21; data = fopen("Case0Sink_fopen.txt", "w+"); // 重新打开文件，覆盖原指针 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_51b.c:24; fclose(data); // 仅关闭新打开的文件句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_51b.c:28
- 结论: 函数内部将文件指针重新指向另一个文件，而未关闭之前的文件句柄，导致原文件描述符泄漏。
- D验证: confirmed / ver_cb84a248
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 172. hyp_path_73850de756ca

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_52c.c:24
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够在调用此函数之前使得data变量指向一个已打开的文件（例如通过修改全局状态或控制函数调用链）。
- 触发路径: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_52c_case0Sink(data); @ 调用点; data = fopen("Case0Sink_fopen.txt", "w+"); // 覆盖之前的句柄，未关闭旧句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_52c.c:24; if (data != NULL) { fclose(data); } // 只关闭了新句柄，旧句柄泄漏 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_52c.c:28
- 结论: 在CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_52c_case0Sink函数中，存在文件描述符泄漏漏洞：之前打开的文件句柄在未关闭的情况下被覆盖，导致资源泄漏。
- D验证: confirmed / ver_a98e3341
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 173. hyp_path_eb546b9e8ec4

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53d.c:24
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够控制程序流程，使得sink函数被调用且传入的data参数预先指向一个已打开的文件句柄。
- 触发路径: data = fopen(...); // 假设在调用者中已打开文件 @ 调用者调用sink函数时; data = fopen("Case0Sink_fopen.txt", "w+"); // 重新赋值data，原句柄丢失 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53d.c:24; fclose(data); // 只关闭了新句柄，原句柄未关闭 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53d.c:28
- 结论: 函数中重新赋值文件句柄指针data而未关闭先前的句柄，导致文件描述符泄漏。如果调用者传入的data指向一个已打开的文件句柄，则此句柄不会被关闭，造成资源泄漏。
- D验证: confirmed / ver_d2679ecc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 174. hyp_path_b4a34103e3d1

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_44.c:24
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: source函数必须首先打开一个文件并赋值给data变量（全局或参数），然后调用sink函数。
- 触发路径: data = fopen(/* source file */, "r"); @ source函数中（未在提供的片段中显示，但A阶段合并证据注释表明存在）; data = fopen("Case0Sink_fopen.txt", "w+"); /* 覆盖原始句柄 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_44.c:24; fclose(data); /* 仅关闭新句柄，原始句柄未关闭 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_44.c:28
- 结论: 文件描述符泄漏：在sink函数中，将data指针重新赋值给另一个fopen打开的文件句柄，而未关闭先前由source函数打开的原始文件句柄，导致文件描述符泄漏。
- D验证: confirmed / ver_a1574ecb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 175. hyp_path_c3dc6ac8c78e

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_54e.c:24
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够通过参数传入一个已打开的文件句柄，或程序执行前已有打开的文件句柄被赋值给data
- 触发路径: 接收参数data（可能指向已打开文件） @ 入口函数CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_54e_case0Sink; data = fopen("Case0Sink_fopen.txt", "w+"); /* 重新赋值，未关闭原句柄 */ @ 第24行; fclose(data); /* 仅关闭新句柄 */ @ 第28行
- 结论: 存在CWE-773漏洞：在重新赋值文件指针前未关闭原有文件句柄，导致文件描述符泄漏。
- D验证: confirmed / ver_219b09af
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 176. hyp_path_10d9ad386acb

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_64b.c:28
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 调用者传入一个已打开的文件句柄（通过dataPtr）。
- 触发路径: FILE * data = (*dataPtr); @ 26; data = fopen("Case0Sink_fopen.txt", "w+"); @ 28; if (data != NULL) { fclose(data); } @ 30-34
- 结论: 在函数CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_64b_case0Sink中，从dataPtr获取的文件指针data在未关闭原句柄的情况下被fopen覆盖，导致原文件描述符泄漏。
- D验证: confirmed / ver_2e85f489
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 177. hyp_path_375eeacfadeb

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_65b.c:24
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者无法直接控制此漏洞，属于编程逻辑缺陷；但若原句柄来自外部可控制的文件打开操作，可能间接影响资源占用。
- 触发路径: /* NOTE: Point data to another file handle without closing the handle from the source */ data = fopen("Case0Sink_fopen.txt", "w+"); /* avoid incidental for not closing the file handle */ if (data != NULL) @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_65b.c:22-26; fclose(data); // 只关闭了新句柄，未关闭原句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_65b.c:28
- 结论: 函数在重新赋值文件句柄前未关闭原有句柄，导致资源泄漏（文件描述符未释放）。传入的data参数指向的文件句柄在函数内被覆盖，原始句柄未被关闭。
- D验证: confirmed / ver_516fdda1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 178. hyp_path_a7a920f0215c

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_67b.c:30
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够控制结构体 myStruct 中 structFirst 的值，使其指向一个已打开的文件句柄。
- 触发路径: FILE * data = myStruct.structFirst; /* NOTE: Point data to another file handle without closing the handle from the source */ @ 28; data = fopen("Case0Sink_fopen.txt", "w+"); /* avoid incidental for not closing the file handle */ @ 30
- 结论: 函数从结构体中获取文件指针 data，然后未关闭该文件句柄就将其重新赋值为 fopen 打开的新文件句柄，导致前一个文件句柄泄漏（CWE-773）。
- D验证: confirmed / ver_d311628f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 179. hyp_path_7551da8d1399

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68b.c:29
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 全局变量CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68_case0DataForCase0Sink包含一个已打开且未关闭的文件句柄。
- 触发路径: FILE * data = CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68_case0DataForCase0Sink; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68b.c:27; data = fopen("Case0Sink_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68b.c:29
- 结论: 函数中先获取全局文件句柄赋值给data，然后立即覆盖为fopen返回的新句柄，导致原始文件句柄丢失引用无法关闭，造成文件描述符泄漏。
- D验证: confirmed / ver_6fcfdcdb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 180. hyp_path_e7a7ae05e2d4

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_82_case0.cpp:27
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够触发对action函数的多次调用（例如通过外部输入驱动的循环）
- 触发路径: data = fopen("Case0Sink_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_82_case0.cpp:27
- 结论: 在函数CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_82_case0::action中，未关闭前一个文件句柄就将其指向另一个文件句柄，导致文件描述符泄漏。攻击者可通过多次调用该函数消耗系统文件描述符资源，造成拒绝服务。
- D验证: confirmed / ver_144726aa
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 181. hyp_path_425b414ecd52

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_63b.c:25
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够影响source端以打开一个文件并传递其句柄到此sink函数。
- 触发路径: FILE * data = *dataPtr; @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_63b.c:23; data = fopen("Case0Sink_fopen.txt", "w+"); // 覆盖data，未关闭原句柄 @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_63b.c:25; if (data != NULL) { fclose(data); } // 仅关闭新打开的文件 @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_63b.c:28-29
- 结论: 未关闭原始文件句柄导致资源泄漏（CWE-773）。函数从指针获取FILE*，然后直接将data指向新文件，未关闭原始句柄，造成文件描述符泄漏。
- D验证: confirmed / ver_18af5245
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 182. hyp_path_918761b60b73

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_66b.c:26
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 存在之前通过fopen打开的文件句柄存储在dataArray[2]中且未关闭。
- 触发路径: FILE * data = dataArray[2]; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_66b.c:24; data = fopen("Case0Sink_fopen.txt", "w+"); /* 未关闭之前句柄直接覆盖 */ @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_66b.c:26
- 结论: 函数CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_66b_case0Sink中，通过dataArray[2]获取文件指针后，直接使用fopen覆盖data变量而未先关闭原句柄，导致原文件描述符泄漏（丢失引用）。
- D验证: confirmed / ver_1c0a60e3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 183. hyp_path_9d130faaa970

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_81_case0.cpp:27
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 调用action之前，data参数指向一个通过fopen打开且未关闭的文件句柄。
- 触发路径: data = fopen("Case0Sink_fopen.txt", "w+"); // 覆盖data，可能未关闭之前的句柄 @ L25-29
- 结论: 在函数action中，data参数在进入时可能指向一个由调用者打开且未关闭的文件句柄，但函数内部将data重新赋值为fopen返回的新句柄，未关闭先前的句柄，导致文件描述符泄露。
- D验证: confirmed / ver_eabce803
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 184. hyp_path_dfe0386bb618

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_42.c:24
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无特殊前提，只要运行至此代码路径即可触发。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); return data; @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_42.c:24
- 结论: 文件句柄未正确关闭，可能导致资源泄漏（文件描述符漏洞），但缺少调用方代码确认调用者是否关闭句柄。
- D验证: confirmed / ver_179a9f40
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 185. hyp_path_d8669fff049f

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84_case0.cpp:33
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 类对象在析构前已通过fopen打开文件句柄并存储于data成员中（构造函数或其他成员函数中）。
- 触发路径: ~CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84_case0() 入口 @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84_case0.cpp:30; data = fopen("Case0Sink_fopen.txt", "w+"); /* 重新赋值导致原句柄丢失引用 */ @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84_case0.cpp:33; fclose(data); /* 只关闭了新句柄，未关闭原句柄 */ @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84_case0.cpp:37
- 结论: 在CWE773测试用例中，类析构函数将成员变量data（原指向通过fopen打开的文件句柄）重新赋值给另一个fopen返回的句柄，而未先关闭原句柄，导致原文件描述符泄漏。这违反了CWE-773（活动文件描述符或句柄缺失引用），可能造成资源耗尽。
- D验证: confirmed / ver_a671096f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 186. hyp_path_120e43b6fa8d

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_61b.c:24
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 调用者未调用fclose关闭返回的文件句柄
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); return data; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_61b.c:22-26
- 结论: 函数创建文件句柄后未关闭，导致文件描述符泄漏。
- D验证: confirmed / ver_90fd2257
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 187. hyp_path_dc4469c964e9

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45.c:41
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 代码执行路径自然触发，无需外部输入控制
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45.c:41; data = fopen("Case0Sink_fopen.txt", "w+"); // 覆盖data，未关闭前一个句柄 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45.c:43
- 结论: 在case0Sink函数中，通过全局变量data获取先前fopen打开的文件句柄后，未关闭即重新赋值，导致前一个文件句柄泄漏。
- D验证: confirmed / ver_7bb1995a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 188. hyp_path_437a9b4edecb

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_83_case0.cpp:33
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够影响文件操作流程，但无需直接控制输入参数，漏洞由代码逻辑自身缺陷导致。
- 触发路径: 假设存在先前fopen赋值给data @ 构造函数（未在代码片段中显示）; data = fopen("Case0Sink_fopen.txt", "w+"); // 覆盖前一个句柄且未关闭 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_83_case0.cpp:33
- 结论: 文件句柄泄露：在覆盖指向文件句柄的指针前未关闭先前打开的句柄，导致文件描述符泄漏。
- D验证: confirmed / ver_b8d7fc83
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 189. hyp_path_50f7097e69b9

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_67a.c:35
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者无需特殊控制，但可能通过反复触发该路径消耗文件描述符
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_67a.c:35; myStruct.structFirst = data; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_67a.c:36; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_67a.c:37
- 结论: 文件句柄泄漏：调用fopen()打开文件后，在sink函数内部可能未关闭文件句柄，导致资源泄漏。由于sink函数内部代码未提供，证据不完整，但常见Juliet测试床中此类sink函数不执行关闭操作，漏洞存在可能性高。
- D验证: confirmed / ver_3e6e6e29
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 190. hyp_path_a39fae354c32

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_66a.c:30
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无额外攻击前提条件，程序正常执行即可触发
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_66a.c:30; dataArray[2] = data; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_66a.c:31; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_66a.c:33
- 结论: 文件描述符未关闭，导致资源泄露
- D验证: confirmed / ver_61cbdb22
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 191. hyp_path_bd76711c1097

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_43.cpp:27
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者无需特殊权限，仅需程序执行到此代码路径即可触发漏洞。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_43.cpp:27
- 结论: 文件句柄未正确关闭，导致文件描述符泄露，可能耗尽系统文件描述符资源。
- D验证: confirmed / ver_67963b3b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 192. hyp_path_3b3dfeb4d603

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68a.c:33
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行到 fopen 调用，且后续未关闭文件
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68a.c:33; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68b_case0Sink(); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68a.c:35
- 结论: 文件描述符未正确关闭导致资源泄漏
- D验证: confirmed / ver_0daef1f1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 193. hyp_path_7467f2ddb709

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_62b.cpp:27
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序运行并调用case0Source函数。
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_62b.cpp:27
- 结论: 在函数case0Source中，通过fopen()打开文件句柄后未进行关闭，导致文件描述符泄漏，可能耗尽系统资源。
- D验证: confirmed / ver_c6df5753
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 194. hyp_path_24b11465d393

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84_case0.cpp:27
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无需攻击者控制输入，漏洞由代码本身的缺陷导致
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84_case0.cpp:27
- 结论: 文件句柄泄露：构造函数中fopen()打开文件后，未在任何位置（包括析构函数）调用fclose()关闭文件句柄，导致文件描述符泄漏。
- D验证: confirmed / ver_1da303bf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 195. hyp_path_c73b007a406e

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_83_case0.cpp:27
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = fopen("Case0Source_fopen.txt", "w+"); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_83_case0.cpp:27
- 结论: 在构造函数中通过fopen打开文件后没有在任何路径（包括析构函数）中调用fclose关闭文件句柄，导致文件描述符泄漏。
- D验证: confirmed / ver_67692e18
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 196. hyp_path_0a89e98077a7

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_61b.c:33
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 调用方接收文件描述符后未调用 close()
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); return data; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_61b.c:33
- 结论: 函数返回由 open() 创建的文件描述符，但未在 source 函数内关闭，若调用方未正确关闭则导致资源泄漏（CWE-773）。当前证据仅展示 source 函数，未提供调用方上下文，无法确认调用方是否关闭了文件描述符，因此路径不闭合。
- D验证: confirmed / ver_aa7a07ea
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 197. hyp_path_fba2480bb746

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_42.c:26
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无外部输入，函数内部固定文件名操作
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_42.c:26
- 结论: 文件句柄通过CreateFile创建后未关闭，导致文件描述符泄漏（CWE-773）
- D验证: confirmed / ver_d12bfeac
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 198. hyp_path_740b621fa7ca

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_42.c:33
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无外部输入要求，仅需调用 case0Source 函数且不关闭返回的文件描述符。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); return data; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_42.c:33
- 结论: 在函数 case0Source 中，使用 open() 创建文件描述符后直接返回，未在函数内部或调用侧确保关闭，导致文件描述符泄漏（CWE-773）。
- D验证: confirmed / ver_687f6093
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 199. hyp_path_aea52aecbcfc

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61b.c:26
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无需外部输入，代码固定创建文件句柄后未释放。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61b.c:26
- 结论: 在CreateFile打开文件句柄后，可能没有调用CloseHandle关闭句柄，导致文件句柄泄漏（资源未释放）。当前代码片段仅显示CreateFile调用，缺失后续关闭代码，且缺少错误处理，导致资源泄漏风险。
- D验证: confirmed / ver_58e65c50
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 200. hyp_path_122f63d38e21

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_83a.cpp:29
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: The constructor internally calls fopen (common in Juliet bad variants) and stores handle; destructor omits fclose.
- 触发路径: FILE * data; data = NULL; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_83_case0 case0Object(data); @ L25 (entry); call to constructor with data=NULL @ L29 (constructor call); call to destructor (assumed no fclose) @ L30 (destructor call)
- 结论: Potential file descriptor leak (CWE-773) due to missing fclose in destructor; constructor may open a file despite passing NULL.
- D验证: confirmed / ver_e8d94e5e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 201. hyp_path_5f38f47947bc

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_45.c:51
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无需攻击者输入，正常执行路径即可触发资源泄漏。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_45.c:51; data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); if (data != -1) { CLOSE(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_45.c:33-43
- 结论: 文件描述符泄漏：在case0Sink函数中，重新打开文件并关闭了新文件，但未关闭原始打开的文件描述符，导致资源泄漏。
- D验证: confirmed / ver_8b069e83
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 202. hyp_path_149e126d4f20

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_67a.c:45
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行到当前函数路径，且open()调用成功返回有效文件描述符。
- 触发路径: data = -1; ... data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); myStruct.structFirst = data; @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_67a.c:43-45; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_67b_case0Sink(myStruct); @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_67a.c:47
- 结论: 文件描述符泄露：open()打开文件后未关闭，导致文件描述符泄漏。
- D验证: confirmed / ver_673c07dc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 203. hyp_path_70acde5e4160

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_66a.c:43
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行路径包含source（open）和sink（未close），无需攻击者输入控制
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_66a.c:40; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_66a.c:43; sink函数中未调用close()，导致文件描述符泄漏 @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_66b.c（推断）
- 结论: 文件描述符泄漏：open()打开文件后未调用close()，导致文件描述符资源泄漏。
- D验证: confirmed / ver_5eeb0d45
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 204. hyp_path_443a6929884d

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68a.c:43
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: open()调用成功返回有效文件描述符
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68a.c:43; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68_case0DataForCase0Sink = data; @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68a.c:44; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68b_case0Sink(); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68a.c:45
- 结论: 文件描述符未关闭导致资源泄漏（Missing Reference to Active File Descriptor or Handle），但缺乏sink函数内部实现确认
- D验证: confirmed / ver_9f95a4d7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 205. hyp_path_9248e7a0bf3b

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_45.c:58
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无外部输入控制，但漏洞在程序正常执行路径中自然发生，前提是source中的CreateFile成功返回有效句柄。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ source函数第50行; data = CreateFile("Case0Sink_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); @ sink函数第34行
- 结论: 在case0Source中通过CreateFile创建的文件句柄未被关闭，随后在case0Sink中创建的新句柄覆盖了同一个全局变量，导致前一个句柄泄漏。
- D验证: confirmed / ver_dab4ba78
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 206. hyp_path_1233db8607e2

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_66a.c:42
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: N/A
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ L33; dataArray[2] = data; @ L42; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_66b_case0Sink(dataArray); @ L42
- 结论: 存在CWE-773漏洞：CreateFile创建的句柄未关闭，导致资源泄露。
- D验证: confirmed / ver_56f299e1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 207. hyp_path_6b3f830c78ac

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_67a.c:46
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: CreateFile调用成功（返回非INVALID_HANDLE_VALUE）; sink函数内部不关闭句柄
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_67a.c:38; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_67a.c:46
- 结论: 文件句柄未关闭导致资源泄露（假设sink函数内部未关闭句柄且CreateFile成功）
- D验证: confirmed / ver_d6c9b13b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 208. hyp_path_6262c6563513

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68a.c:44
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序运行并执行到main函数中的路径，且sink函数按预期不执行关闭操作。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68a.c:36; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68b_case0Sink(); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68a.c:44; 推断：sink函数内未调用CloseHandle(data)（基于测试用例设计，但具体行未提供） @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68b.c
- 结论: 文件句柄未正确关闭，导致活动文件描述符或句柄的引用丢失（Handle Leak）。尽管sink函数内部代码未直接提供，但根据Juliet测试用例的设计意图和命名惯例，sink函数应缺失CloseHandle调用。
- D验证: confirmed / ver_cbbf944e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 209. hyp_path_5b0d0cb792b0

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53c.c:26
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 假设调用栈上层存在fopen()调用并成功打开文件
- 触发路径: void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53c_case0Sink(FILE * data) { CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53d_case0Sink(data); } @ CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53c.c:24-28
- 结论: 函数'CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53c_case0Sink'未关闭文件句柄，可能导致文件描述符泄漏。但缺乏source端（如fopen）证据，路径不完整。
- D验证: confirmed / ver_ff2a1a92
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 210. hyp_path_0cbeb5ac3ac6

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_43.cpp:36
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够促使该函数被多次调用（例如通过持续的网络请求或用户操作）。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_43.cpp:36
- 结论: 文件描述符通过open()创建后未正确关闭，可能造成文件描述符泄漏，最终导致拒绝服务。但静态证据不完整，缺少close()调用的确认。
- D验证: confirmed / ver_81de5840
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 211. hyp_path_04eb5c2f8d74

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52b.c:35
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行路径到达该sink链，且上游存在未关闭的文件描述符
- 触发路径: void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52b_case0Sink(int data) { CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52c_case0Sink(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52b.c:33; 假设上游调用open()后未关闭，直接传入sink链 @ 上游未提供源码
- 结论: 函数CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52b_case0Sink未关闭文件描述符，导致资源泄漏。
- D验证: confirmed / ver_f4797cfe
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 212. hyp_path_1e07f738890a

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_53c.c:35
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: A file descriptor is opened (e.g., via open()) and passed to the sink without being closed afterwards.
- 触发路径: void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_53c_case0Sink(int data) { CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_53d_case0Sink(data); } @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_53c.c:33-37; CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_53d_case0Sink likely does not close the file descriptor. @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_53d.c (inferred)
- 结论: File descriptor leak due to missing close after open; the sink function forwards the descriptor without closing, and the caller is expected to have opened the file without subsequent close.
- D验证: confirmed / ver_8b115dfc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 213. hyp_path_deefbd1e8ef2

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_62b.cpp:36
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序在open()调用后未调用close()关闭文件描述符，且该描述符在函数返回后不再可用。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_62b.cpp:36
- 结论: 在CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_62b.cpp中，通过open()创建的文件描述符未在后续代码中关闭，导致文件描述符泄漏。
- D验证: confirmed / ver_13585a00
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 214. hyp_path_07ed61c29771

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_83_case0.cpp:27
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 文件"Case0Source_open.txt"可创建或打开; open()调用成功返回有效文件描述符（非-1）; 文件描述符在对象生命周期内未被关闭
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_83_case0.cpp:27
- 结论: 在构造函数中调用open()打开文件后未关闭，导致文件描述符泄漏，可能耗尽系统资源或导致句柄被误用。
- D验证: confirmed / ver_50ae0233
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 215. hyp_path_6b01afbc72f1

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84_case0.cpp:27
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 无特定攻击者控制输入，只需程序正常执行该路径即可触发漏洞。
- 触发路径: data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84_case0.cpp:27
- 结论: 文件描述符泄漏：通过open()打开文件后，未在任何地方关闭文件描述符data，导致资源泄漏。可能被攻击者利用以消耗系统文件描述符资源，造成拒绝服务。
- D验证: confirmed / ver_cd98449b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 216. hyp_path_72c78340d571

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_43.cpp:29
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 代码执行到该函数，且没有中断
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_43.cpp:29
- 结论: 文件句柄未关闭，导致资源泄露（Missing Reference to Active File Descriptor or Handle）。
- D验证: confirmed / ver_9f5be05f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 217. hyp_path_bf17a81265e1

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_54b.c:28
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者能够控制某个输入导致句柄被创建且未关闭，并传递到此sink
- 触发路径: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_54c_case0Sink(data); @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_54b.c:28
- 结论: 可能存在未关闭的文件句柄漏洞，但当前证据仅显示sink函数间的传递，缺少source和完整调用链。如果上游存在CreateFile等操作且未关闭句柄，则存在CWE-773漏洞。
- D验证: confirmed / ver_9e980a93
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 218. hyp_path_fb50a391e4e0

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_62b.cpp:29
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 攻击者可以触发该函数的执行，但路径为硬编码，无可控输入。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_62b.cpp:29
- 结论: 函数case0Source中通过CreateFile创建文件句柄后，可能未正确关闭，导致文件描述符泄漏。但缺少调用者关闭操作的直接证据，需动态验证或审计完整调用链。
- D验证: confirmed / ver_0f06cb9b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 219. hyp_path_ebee33a9aa61

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_83_case0.cpp:27
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: 程序执行到 CreateFile 调用处，且文件创建成功。
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_83_case0.cpp:27
- 结论: 文件句柄未正确关闭，导致资源泄漏。CreateFile 返回的句柄被赋值给 data，但后续没有调用 CloseHandle 关闭句柄。
- D验证: confirmed / ver_d4a64ddb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 220. hyp_path_ee5ff5d1e418

- 漏洞位置: juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_84_case0.cpp:27
- 漏洞类型: CWE-773
- CWE: CWE-773
- 风险等级: P0
- 触发条件: CreateFile成功执行并返回句柄; 后续代码未调用CloseHandle或其他关闭操作
- 触发路径: data = CreateFile("Case0Source_w32CreateFile.txt", (GENERIC_WRITE|GENERIC_READ), 0, @ juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_84_case0.cpp:27
- 结论: 使用CreateFile创建文件句柄后未关闭，导致文件句柄泄漏（Missing Reference to Active File Descriptor or Handle）。
- D验证: confirmed / ver_79f03ecb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

## Unconfirmed / Failed Verification

These records are not reported as confirmed vulnerabilities. See `verification.failed.jsonl` for full failure details.

- hyp_path_087c9b67005f | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_72a.cpp:111 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_175beae3889a | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_72a.cpp:111 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c22385414a4d | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_74a.cpp:464 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_89aafef3b8dd | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_73a.cpp:443 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7cecd39b9067 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_74a.cpp:464 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dfe37c3aded2 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_73a.cpp:443 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2c5077a58e29 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_12.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_adca6c62b849 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_17.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4af32a015217 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_12.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b8989141a7c5 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_17.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9fd51baea4a5 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_08.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cde98dea9f2a | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_05.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b95f0467e366 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_08.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_37401bc4130f | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_11.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_aa91029ef8e5 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_09.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c11d14d4d25e | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_11.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_367fd03dbc7c | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_13.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2e0b3bf399e3 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_14.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cf7aa7eeeee7 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_10.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cb24d0d9646d | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_05.c:88 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_417614e21b29 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_07.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_22f6b792b787 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_11.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bd7abd760cba | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_09.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_85a8459d0c7b | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_11.c:118 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2210c3ecf3be | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_13.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_128ebc775e7f | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_03.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_57d71967e8f7 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_10.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6dad0430e9cc | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_04.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a8c1d29ca7d2 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_02.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bc2a7399814e | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_14.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b04cb167a18d | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_06.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0de001718247 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_04.c:101 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_19a1aa8b4197 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_06.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bcdad548a175 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_05.c:101 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6dfb32fb4c97 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_07.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_87df3bec6a51 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_14.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_26dc6e762df5 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_09.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7a71e1d26d4d | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_15.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1241ce22e9fc | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_13.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6d8e4571e5cd | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_15.c:103 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_be227d864d3f | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_10.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6f739fec5caf | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_33.cpp:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_602433293259 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_04.c:88 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_81e8467e3a5f | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_03.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8f50dcc446b2 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_06.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2d8bd76ac06b | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_07.c:123 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c332057112f9 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_14.c:118 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_402647d4a93e | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_15.c:126 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fe82ba4688ea | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_16.c:78 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4ac6ab4807d3 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_73b.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_070f028aadda | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_32.c:89 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_35df81c905ce | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22b.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_30a2280b637e | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_21.c:126 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bf40426abd3a | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_45.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_beaa4ee8380f | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_44.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a4510d800171 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_54e.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3696afa61e49 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_67b.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_250e0ced3ae0 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_65b.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9ef7835244cb | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_66b.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6b08fac7e924 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_81_case1V2.cpp:29 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3312ed2f7041 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_83_case1V2.cpp:35 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c675e090595a | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_72a.cpp:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_70fe36579b24 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_22a.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d05ca822b9b1 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_51a.c:46 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_027e20b2fdf3 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_52a.c:46 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_81fcbac0dc45 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_22a.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_877f94af708b | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53a.c:46 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b869be30b143 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_63a.c:45 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_508d0ec068ff | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_64a.c:45 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6da6ae368da3 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_54a.c:46 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4a3cf806e4da | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_73a.cpp:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_145989206558 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_74a.cpp:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_05edeb2879d2 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_81a.cpp:45 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_39b0bcb76d53 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_82a.cpp:46 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_122937c59629 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_44.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9b1b51c37c68 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_65a.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d43ade9e6c30 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_41.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a9ee5fbb85de | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_19c782eed12e | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22a.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5066a8eff8f8 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_51a.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a6cea824e318 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_53a.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bc880dd94b0d | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_54a.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e3a513157e56 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_63a.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_27a69b0d0e1e | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52a.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6d28756e41ae | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_64a.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cc250e4cb3ce | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_51a.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a07ed2a62488 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22a.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_56905921cf83 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7c56c6d90028 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_52a.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3e370a3da6eb | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_53a.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b13690ef7589 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_54a.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_71f319982b8c | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_64a.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_87f6d51c865a | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_63a.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e49d705d8a93 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84a.cpp:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7ceb7266725f | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84a.cpp:42 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_096b9f91dbb6 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_08.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9ceb0a690e96 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_84a.cpp:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_23f2ef3f216e | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_17.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_50e50470c432 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_12.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1dfc94927ede | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_05.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_132406912514 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_09.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_96da3c2ffa3c | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_10.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d536b9de7b87 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_11.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fae9f0e066e2 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_11.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9a63a86d9376 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_08.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b2169e67a7b3 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_07.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3dece466f717 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_02.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_38e8725f6caa | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_14.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a99bb786bd14 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_04.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8504367c0e18 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_13.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d8575ddeaa55 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_03.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7026622bef3e | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_04.c:83 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d429ee59188f | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_05.c:83 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f8b008983105 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_03.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2207f5ef74bf | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_06.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_09c98a8bc33f | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_09.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_730968fea6e3 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_06.c:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ede518970248 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_13.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9a681d9a0c76 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_07.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cad1e8b4dcae | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_10.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_58793558e543 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_14.c:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e0b6a04f6fc0 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_15.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5d79ffae2cf3 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_16.c:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a046c0d66cfe | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_33.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_90851c3c7505 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_73b.cpp:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_561c64580187 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_22b.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7bdf62c28945 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_32.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b78eb0dc0a01 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_67b.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8274778bf069 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_82a.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7c1ab2f6689f | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_82a.cpp:31 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b3c76b0d2564 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_82a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6adfcafba7e5 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_81a.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7b66c1416905 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_82_case1V2.cpp:29 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_41c4d06cf733 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_81a.cpp:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_867978caa682 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_44.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6091051559f4 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_65a.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c717bbcb8bd5 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_44.c:92 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e64400758bd0 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_65a.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c19c60de8341 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_42.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_52e8ff5d1cd7 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_61b.c:36 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_62a4d479b65f | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_67a.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3cc3e8cbdcea | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_66a.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9874c4fb1d4d | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68a.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_74812c48ccb8 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_43.cpp:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e7204bf679f3 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_83_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_325690fdec93 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_62b.cpp:38 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9836ad456204 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_61b.c:45 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_77305f5c5e3a | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_42.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_69987ada4741 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_42.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_12a9c233df0e | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4c154e4e0f8b | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61b.c:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bab84f6ddf5b | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_08.c:110 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8cd6d0a5ce4f | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_14.c:97 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_34c7bd1a16e7 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_21.c:122 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_24bab7ee4f63 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_22a.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_54cf2b007329 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_11.c:108 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3e5bb555b9c4 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_21.c:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_82d924087b47 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22a.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_68a2540da5b7 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_66a.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_43df17db4639 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_14.c:108 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0985ff0eb77e | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6dda783f9d5b | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_67a.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_63fbe6c8250d | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_07.c:143 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_27de3ea5feb6 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_21.c:163 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5f2bd445b75a | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22a.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4afb07dd8382 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_66a.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b70439d38569 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_67a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_127fc97f793c | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68a.c:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_89f493a7cdca | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_83a.cpp:43 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2400cb34f8d8 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_41.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5f3a2c02f2ce | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_44.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e8eb9d391a95 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cbe8ffee31ef | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_51a.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f99bcc5932c8 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_52a.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8f009f738f04 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_43.cpp:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c4e71c6a0896 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53a.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_418e306c7f5f | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_54a.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_098071370e05 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_63a.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3fab15349ff6 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_62a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_362b3e4bbe32 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_65a.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_62e5699041ca | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_64a.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_18de56832659 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_67a.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dfdd06ebed7a | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_73a.cpp:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_240841d49d64 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_72a.cpp:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_88ac1ad7fce2 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_66a.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9501d8b98c38 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68a.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_94bc1c46a83c | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_81a.cpp:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fde88c0e9869 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_74a.cpp:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1a6de85c6eff | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_82a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0cac39d4020d | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_41.c:83 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1672eb4ee5d0 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_43.cpp:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_35c98a431ae9 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_44.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_87e1cafa0f66 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_45.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ab14f3043dc5 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4c00cc57cc01 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_51a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_75530a8f4598 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_53a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1796217f3519 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_54a.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_626287c0a109 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_63a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cf005f9e1eeb | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_62b.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b9dbd7ac51a3 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_64a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9f63929eb8be | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_65a.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4ac6bf30726c | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_66a.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0c5b17bec850 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_62a.cpp:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a2be6f135580 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_67a.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_67acaaa67074 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_73a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a185a155e8aa | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68a.c:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b0590d25060d | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_72a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e9100f8af134 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_74a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1da148889aca | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_81a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c799607a498f | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_82a.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dd972b60c44b | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_83_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e45d51c62d54 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_881d4dd7e99e | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_17.c:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_000e5bbe4e25 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_41.c:100 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7934968a07e4 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_44.c:104 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_93ba9cccc089 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_43.cpp:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9c43b5fd57fa | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_51a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0762cbf42e30 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_45.c:107 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c7864a296d18 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_52a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9de02f8cd808 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_53a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7c3b0280b216 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_54a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9b9537159cf4 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_54b.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0385d2e0c11c | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_54c.c:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b5e775494005 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_54d.c:28 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d4be346320ff | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_62b.cpp:46 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e91b9ddd0ad6 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_65a.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8d3b8c9da4e2 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_63a.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cbff7aa53538 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_64a.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1232de21907b | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_66a.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cb30f5e1fcdc | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_67a.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_06b7f3ad30a1 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68a.c:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fbdcf5ba97ca | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_72a.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9ac237881bb0 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_74a.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5401c99546fb | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_73a.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_62412639af2d | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_81a.cpp:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_110ca8f6c916 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_82a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7313c43dbc9d | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_83_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9ab63a4a815c | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_84_case1V2.cpp:27 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_01205bcffe67 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/main.cpp:896 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_ea1da50c1c56 | juliet-api-misuse/testcases/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle/CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_84a.cpp:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
