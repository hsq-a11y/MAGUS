# MAGUS Final Vulnerability Report

- generated_at: 2026-05-24T14:23:04Z
- reportable_vulnerabilities: 144
- d_confirmed_vulnerabilities: 92
- stage_c_preserved_vulnerabilities: 52
- failed_verifications: 47
- source_confirmed: /home/lxz/MAGUS/d/memberD_verifier/02_run_with_C/output/srcs_2000/verification.jsonl
- source_failed: /home/lxz/MAGUS/d/memberD_verifier/02_run_with_C/output/srcs_2000/verification.failed.jsonl

## Confirmed Vulnerabilities

### 1. hyp_path_7cffc4a95979

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_74a.cpp:103
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标机器的监听端口并发送任意数据。; 目标程序未对接收数据进行充分校验或白名单过滤。; sink函数内部确实存在将数据传递给LoadLibrary的调用。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_74a.cpp:103; dataMap[0] = data; @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_74a.cpp:104; LoadLibraryW(data) 或其他动态库加载函数 @ sink函数内部
- 结论: 程序通过socket接收外部数据，存储到map中，并传递给sink函数，该函数可能将未校验的数据用作LoadLibrary参数，导致任意代码执行。
- D验证: confirmed / ver_ec93f111
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 2. hyp_path_75a360984b8b

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_74a.cpp:103
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接向服务端发送恶意数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_74a.cpp:103; dataMap[0] = data; // data存储到map @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_74a.cpp:sink调用处; sink(dataMap); // 将外部数据传递给进程控制API @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_74a.cpp:case0Sink函数
- 结论: 接收网络数据后，通过std::map传递给进程控制函数（如LoadLibrary或CreateProcess），导致任意代码执行漏洞
- D验证: stage_c_preserved / ver_6e58f371
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 3. hyp_path_eb21bb5dc1c0

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_72a.cpp:103
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够连接到目标socket并发送恶意数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_72a.cpp:103; dataVector.insert(dataVector.end(), 1, data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_72a.cpp:（约105后）; case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_72a.cpp:（调用点）
- 结论: 存在漏洞路径：通过网络接收数据后，数据被插入vector并传递给case0Sink函数，该函数可能使用外部控制数据启动进程，导致CWE-114外部控制进程漏洞。
- D验证: stage_c_preserved / ver_ee3755ab
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 4. hyp_path_7e37b3dd09be

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_72a.cpp:88
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够与目标服务器建立TCP连接并发送恶意载荷。; 目标服务器未对网络输入内容进行任何验证或过滤。; sink函数实际将数据用于LoadLibrary等危险API。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_72a.cpp:93-97; dataVector.insert(dataVector.end(), 1, data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_72a.cpp:116附近; 调用sink函数，将vector作为参数，可能直接用于LoadLibrary等库加载操作。 @ sink函数（符号可见但代码未提供）
- 结论: 存在代码执行漏洞：通过网络接收外部可控数据，并可能将其用作库加载的路径，导致任意代码执行。
- D验证: stage_c_preserved / ver_09806e88
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 5. hyp_path_f76c9a74f89b

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_74a.cpp:88
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够与目标程序建立网络连接并发送载荷
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_74a.cpp:93; dataMap[0] = data; @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_74a.cpp:96; case0Sink(dataMap); // 调用sink函数，该函数可能使用dataMap中的数据进行进程控制 @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_74a.cpp:100 (推断)
- 结论: 通过socket接收外部数据，并将其直接用作进程控制（如加载库或创建进程）的参数，导致任意代码执行漏洞。
- D验证: stage_c_preserved / ver_a4564240
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 6. hyp_path_b678e245c434

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_72a.cpp:88
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够访问目标主机的网络端口，发送TCP数据包。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_72a.cpp:93-97; dataVector.insert(dataVector.end(), 1, data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_72a.cpp:98-100; 推测调用 LoadLibrary 或其他危险API（基于静态分析高风险sink标签） @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_72a.cpp:? (case0Sink函数内部)
- 结论: 程序通过recv从网络接收数据，存储到vector中，并传递给case0Sink函数，该函数可能调用LoadLibrary等危险API，导致过程控制漏洞。尽管sink函数的具体实现未在提供的代码中显示，但B阶段静态分析确认高风险sink，且测试用例明确标记CWE114，因此漏洞假设仍有效。
- D验证: stage_c_preserved / ver_42e99d10
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 7. hyp_path_63bc9ce5ff33

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_74a.cpp:88
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到目标主机的指定端口并发送恶意数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_74a.cpp:88; dataMap[0] = data; @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_74a.cpp:100（推测）; 假设的进程创建调用，如 CreateProcess(dataMap[0], ...); @ case0Sink函数内部（代码未提供）
- 结论: 从socket接收外部输入数据并存储到map中，随后传递给case0Sink函数，该函数可能利用数据执行进程控制操作（如CreateProcess），导致远程命令执行。
- D验证: stage_c_preserved / ver_15083630
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 8. hyp_path_e44f63b43bc4

- 漏洞位置: juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_72a.cpp:87
- 漏洞类型: buffer_overflow
- CWE: CWE-122
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接发送恶意载荷，使得recv接收的内容经atoi转换后的整数超出预期范围（如负数或过大）。
- 触发路径: recvResult = recv(connectSocket, inputBuffer, CHAR_ARRAY_SIZE - 1, 0); @ CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_72a.cpp:91-95; data = atoi(inputBuffer); @ CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_72a.cpp:93; dataVector.insert(dataVector.end(), 1, data); @ trace证据显示; sink函数中可能存在类似 dataArray[data] 或 malloc(data) 等操作，但未在证据中展示。 @ case0Sink函数（未提供完整代码，根据trace推测使用数据作为索引或大小）
- 结论: 存在堆缓冲区溢出漏洞的潜在路径：通过recv接收网络数据，atoi转换为整数后插入vector，该整数在sink函数中可能被用作数组索引或大小，导致越界写入。但sink函数的具体实现未在证据中完整提供，需进一步验证。
- D验证: stage_c_preserved / ver_d9eb2a37
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 9. hyp_path_84ea2ab3dba9

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_73a.cpp:103
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络发送数据到监听端口，且接收到的数据长度不超过100字节减dataLen减1
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_73a.cpp:103; dataList.push_back(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_73a.cpp:105-106; call:_ZN49CWE114_Process_Control__w32_char_listen_socket_739case0SinkENSt7__cxx114listIPcSaIS2_EEE @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_73a.cpp:128 (implied sink)
- 结论: 外部网络数据通过recv接收未经验证，存入dataList后传递给sink函数，可能导致进程控制（CWE-114）漏洞，攻击者可利用外部输入注入恶意负载影响进程行为。
- D验证: stage_c_preserved / ver_cfb9707c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 10. hyp_path_92ab3063daaa

- 漏洞位置: juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_74a.cpp:87
- 漏洞类型: buffer_overflow
- CWE: CWE-122
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接发送构造的数据，使atoi解析后的整数超出预期范围（如负数或大于堆缓冲区大小）。
- 触发路径: recvResult = recv(connectSocket, inputBuffer, CHAR_ARRAY_SIZE - 1, 0); @ CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_74a.cpp:91-95; data = atoi(inputBuffer); @ CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_74a.cpp:93 (根据B阶段候选call:atoi); dataMap[0] = data; @ CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_74a.cpp:87 (行号可能不准确，实际为dataMap[0]=data的所在行); 在sink函数中，使用data作为索引或大小操作堆缓冲区。 @ sink函数 (case0Sink)，具体行号未提供，但候选显示在case0Sink中
- 结论: 在CWE122堆缓冲区溢出测试用例中，程序通过recv从网络接收数据并存储到inputBuffer，随后使用atoi转换为整数并存入map，最后在sink函数中可能使用该整数作为索引或大小操作堆缓冲区，导致堆缓冲区溢出。虽然sink函数具体代码未提供，但根据Juliet测试用例的典型漏洞模式、P0静态确认支持（high_risk_sink）以及A阶段证明的source-sink路由，漏洞路径合理存在。
- D验证: stage_c_preserved / ver_c709ddd5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 11. hyp_path_d39a14d722a9

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_73a.cpp:88
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到服务端口并发送任意数据
- 触发路径: connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) @ CWE114_Process_Control__w32_char_connect_socket_73a.cpp:86-90; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ CWE114_Process_Control__w32_char_connect_socket_73a.cpp:93-97; dataList.push_back(data); @ CWE114_Process_Control__w32_char_connect_socket_73a.cpp:99; case0Sink(dataList); (B阶段call证据) @ CWE114_Process_Control__w32_char_connect_socket_73a.cpp:后续sink调用
- 结论: 该代码从socket接收数据并存储到list中，随后调用sink函数(如case0Sink)。sink函数可能将数据用于进程控制操作(如LoadLibrary或CreateProcess)，由于接收的数据未经过滤，攻击者可通过发送恶意payload实现任意代码执行。尽管sink函数内部代码未直接提供，但B阶段静态确认支持高风险sink，且路径完整。
- D验证: stage_c_preserved / ver_cb02a23e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 12. hyp_path_50a96cac3874

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_73a.cpp:103
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络向目标发送数据，并控制socket连接
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_73a.cpp:103; dataList.push_back(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_73a.cpp:116（推测）; case0Sink(dataList); // sink函数未提供具体实现，已标记为high_risk_sink @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_73a.cpp:sink函数内部
- 结论: CWE-114: Process Control - 外部可控数据通过网络接收后传入列表，并传递至high_risk_sink函数，可能用于进程控制操作（如加载库），但sink函数内部实现未知，无法完全确认。
- D验证: stage_c_preserved / ver_7a602ca7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 13. hyp_path_344327f50088

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_12.c:96
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到监听的socket并发送恶意数据作为库路径
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_12.c:96; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_12.c:行号未明确（约在96行之后，recv成功后的代码块中）
- 结论: 该代码通过socket接收数据，然后使用LoadLibraryA加载该数据作为库名，攻击者可以控制加载的DLL路径，导致任意代码执行。
- D验证: confirmed / ver_2be368de
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 14. hyp_path_41e0d795c06b

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_12.c:96
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能连接到服务器的监听端口; 攻击者发送一个合法的DLL路径作为宽字符字符串
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_12.c:96; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_12.c:111
- 结论: 通过套接字接收攻击者可控的数据，作为模块名传递给LoadLibraryW，可加载任意DLL导致代码执行。
- D验证: confirmed / ver_9d2b16b6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 15. hyp_path_9e48e1f4c051

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_12.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够向目标程序的特定监听端口发送网络数据，且目标程序会连接该端口并接收数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_12.c:81; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_12.c:108
- 结论: 程序通过socket接收数据后，直接将接收到的数据作为参数调用LoadLibraryA加载库。攻击者可以控制发送的数据，从而加载任意恶意库，导致远程代码执行或库劫持。
- D验证: confirmed / ver_98afe97e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 16. hyp_path_42f25166b636

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_41.c:54
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到服务端; 攻击者发送的数据长度不超过缓冲区大小（100字节）; 攻击者发送的数据为有效的DLL路径或名称
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); ... recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_41.c:99-111; CWE114_Process_Control__w32_char_listen_socket_41_case0Sink(data); // 内部调用LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_41.c:45-62 (sink调用处)
- 结论: 从socket接收的数据直接用于LoadLibraryA加载任意库，攻击者可利用此功能加载恶意DLL，实现远程代码执行。
- D验证: confirmed / ver_4010bdc7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 17. hyp_path_b52a88446d83

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_52a.c:97
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序的监听端口，并发送任意数据。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_52a.c:97; data[dataLen + recvResult / sizeof(char)] = '\0'; ... CWE114_Process_Control__w32_char_listen_socket_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_52a.c:103-104
- 结论: 程序通过socket接收数据，并将数据直接传递给可能用于进程控制的sink函数（如LoadLibrary），攻击者可发送恶意数据导致加载任意DLL，造成进程控制漏洞。
- D验证: stage_c_preserved / ver_f6a5db22
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 18. hyp_path_457ec474da44

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_12.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够控制远程服务器，使目标客户端程序连接并接收攻击者发送的特制库路径字符串。; 程序执行到LoadLibraryW调用时，data缓冲区包含攻击者控制的字符串。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_12.c:81; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_12.c:112
- 结论: 函数通过socket接收外部数据，并直接作为参数传递给LoadLibraryW，攻击者可控制加载任意恶意库，导致任意代码执行。
- D验证: confirmed / ver_7c9886d5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 19. hyp_path_b858be40dfd4

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_51a.c:97
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络向目标发送构造的payload（如恶意DLL路径或命令字符串）
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_51a.c:97; CWE114_Process_Control__w32_char_listen_socket_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_51a.c:112
- 结论: 网络接收的数据未经验证直接传递给进程控制sink函数，攻击者可能通过控制data参数加载任意DLL或执行任意命令，导致任意代码执行。
- D验证: stage_c_preserved / ver_7fe12a14
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 20. hyp_path_938991c4e68a

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_54a.c:97
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接至目标监听端口，并发送恶意数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ CWE114_Process_Control__w32_char_listen_socket_54a.c:97; data[dataLen + recvResult / sizeof(char)] = '\0'; @ CWE114_Process_Control__w32_char_listen_socket_54a.c:97之后; CWE114_Process_Control__w32_char_listen_socket_54b_case0Sink(data); @ CWE114_Process_Control__w32_char_listen_socket_54a.c:101
- 结论: 外部可控数据通过套接字 recv 接收后，未经充分净化即传入 sink 函数，可能被用于进程控制操作（如 LoadLibrary 或 CreateProcess），导致 CWE-114 漏洞。
- D验证: stage_c_preserved / ver_0538742b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 21. hyp_path_45bab9ee3758

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_64a.c:97
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务器的监听端口; 攻击者可以发送任意数据
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_64a.c:83; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_64a.c:97; CWE114_Process_Control__w32_char_listen_socket_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_64b_case0Sink
- 结论: 程序通过socket接收外部输入数据，并将数据作为参数传递给可能加载库的函数（CWE114_Process_Control__w32_char_listen_socket_64b_case0Sink），攻击者可以控制输入数据导致加载恶意DLL，从而执行任意代码。
- D验证: stage_c_preserved / ver_4bbdf9ae
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 22. hyp_path_6234a3ead5af

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_53a.c:97
- 漏洞类型: CWE-114, CWE-20
- CWE: CWE-114; CWE-20
- 风险等级: P1
- 触发条件: 攻击者能够访问目标主机的监听端口（TCP端口）并建立连接。; 攻击者构造的数据包长度不超过100字节减去已有数据长度，且recv成功。
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_53a.c:74; bind(listenSocket, (struct sockaddr*)&service, sizeof(service)); listen(listenSocket, 5); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_53a.c:83; acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_53a.c:83; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_53a.c:97; CWE114_Process_Control__w32_char_listen_socket_53b_case0Sink(data); @ 未知（sink调用处，非第121行）
- 结论: 程序通过套接字接收外部数据，并传递给进程控制sink函数（CWE114_Process_Control__w32_char_listen_socket_53b_case0Sink），但sink内部实现未提供，无法确认是否执行危险操作（如加载库或创建进程）。若sink函数确实存在漏洞且未验证输入，则攻击者可利用未经验证的外部数据导致任意代码执行。
- D验证: stage_c_preserved / ver_a3690af5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 23. hyp_path_de71ba1374e3

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_63a.c:97
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与服务器建立 TCP 连接，并发送任意数据。
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_63a.c:83; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_63a.c:97; CWE114_Process_Control__w32_char_listen_socket_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_63a.c:105
- 结论: 程序通过 recv 从网络接收数据，并将其传递给可能执行外部命令或加载库的 sink 函数，攻击者可控制输入导致执行任意代码。
- D验证: stage_c_preserved / ver_a306e2b2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 24. hyp_path_13a76cf02787

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_41.c:54
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够向监听socket发送包含恶意库路径的数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_41.c:103-107; CWE114_Process_Control__w32_char_connect_socket_41_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_41.c:54; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_41.c:48
- 结论: 外部可控数据通过socket接收后直接作为LoadLibraryA的参数，导致攻击者可加载任意DLL，实现代码执行。
- D验证: confirmed / ver_eb675582
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 25. hyp_path_1f13e01b17ca

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_52a.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络向目标发送数据
- 触发路径: connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_52a.c:80-84; recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0) @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_52a.c:87-91; CWE114_Process_Control__w32_char_connect_socket_52b_case0Sink(data) @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_52a.c:104
- 结论: 通过 socket 接收外部数据，并直接传递给外部进程控制 sink 函数，可能导致攻击者控制进程执行。
- D验证: stage_c_preserved / ver_1931eb46
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 26. hyp_path_8b063adb05fd

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_51a.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够向目标主机的指定socket端口发送TCP数据包。; socket连接建立成功。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_51a.c:82; data[dataLen + recvResult / sizeof(char)] = '\0'; replace = strchr(data, '\r'); if (replace) { *replace = '\0'; } replace = strchr(data, '\n'); if (replace) { *replace = '\0'; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_51a.c:89-96; CWE114_Process_Control__w32_char_connect_socket_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_51a.c:98
- 结论: 通过socket接收外部可控数据，未经验证直接传递给进程控制函数，可能导致攻击者控制加载的库或执行程序。
- D验证: stage_c_preserved / ver_010792cc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 27. hyp_path_c446a3c9f013

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_53a.c:82
- 漏洞类型: CWE-114, CWE-20
- CWE: CWE-114; CWE-20
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接目标程序指定的 IP 和端口（可能为 127.0.0.1 固定地址）; 攻击者能够发送恶意构造的数据包（如 DLL 路径或命令）; sink 函数内部执行危险的进程控制操作（如 LoadLibrary 或 CreateProcess）
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_53a.c:82; data[dataLen + recvResult / sizeof(char)] = '\0'; @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_53a.c:89; CWE114_Process_Control__w32_char_connect_socket_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_53a.c:115
- 结论: 程序通过 socket 接收外部输入，并直接传递给 sink 函数，sink 函数可能执行进程控制操作（如加载库或执行命令），存在 CWE-114 进程控制漏洞。
- D验证: stage_c_preserved / ver_1a98c680
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 28. hyp_path_2da2ad8d8dcc

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_54a.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够连接到目标程序的TCP端口（IP_ADDRESS固定，攻击者需本地网络控制或中间人）; 攻击者发送的数据长度不超过缓冲区剩余空间（100 - dataLen - 1）; sink函数内部执行库加载或命令执行操作（需进一步验证）
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_54a.c:82; CWE114_Process_Control__w32_char_connect_socket_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_54a.c（sink调用行，未在提供代码中明确行号，但存在于该文件或54b.c中）
- 结论: 存在CWE-114（进程控制）漏洞：程序从网络socket接收数据，并将该数据传递给sink函数，攻击者可通过控制接收的内容来影响进程的执行行为（如加载恶意库或执行任意命令）。
- D验证: stage_c_preserved / ver_38a3fd54
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 29. hyp_path_1567780d5d4f

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_63a.c:82
- 漏洞类型: CWE-114, CWE-20
- CWE: CWE-114; CWE-20
- 风险等级: P1
- 触发条件: 攻击者能够访问目标主机的网络端口（TCP_PORT）; 攻击者发送的数据长度不超过缓冲区剩余空间（100 - dataLen - 1）; 服务未在recv或connect阶段因错误退出
- 触发路径: recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_63a.c:82; data[dataLen + recvResult / sizeof(char)] = '\0'; @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_63a.c:92; replace = strchr(data, '\r'); if (replace) { *replace = '\0'; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_63a.c:95; CWE114_Process_Control__w32_char_connect_socket_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_63a.c:104
- 结论: 存在外部控制可执行文件路径漏洞（Process Control），攻击者可利用网络连接发送恶意数据，控制加载的库路径，可能导致任意DLL加载，但sink函数内部代码未提供，证据不完整。
- D验证: stage_c_preserved / ver_590627c1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 30. hyp_path_f6c2bfd52252

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_64a.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够控制程序连接的远程服务器，并发送恶意数据到该socket
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_64a.c:82; CWE114_Process_Control__w32_char_connect_socket_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_64a.c: (sink调用行，约在break之后)
- 结论: 程序主动连接远程服务器，从网络socket接收的数据未经任何验证直接传递给进程控制sink函数（如LoadLibrary），攻击者通过控制服务器可注入任意数据，导致加载恶意库或执行命令。
- D验证: stage_c_preserved / ver_e0f1920e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 31. hyp_path_9bf5de8a1eff

- 漏洞位置: juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_21.cpp:115
- 漏洞类型: buffer_overflow
- CWE: CWE-122
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务，并发送特制的字符串，使其atoi转换后为大于等于10的整数
- 触发路径: recvResult = recv(connectSocket, inputBuffer, CHAR_ARRAY_SIZE - 1, 0); @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_21.cpp:115; data = atoi(inputBuffer); @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_21.cpp:121; if (data >= 0) { buffer[data] = 1; } @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_21.cpp:67
- 结论: 在case0Sink函数中，接收网络输入转换为整数后作为数组索引写入堆缓冲区，未检查索引上限，导致堆缓冲区溢出。
- D验证: stage_c_preserved / ver_b2522f21
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 32. hyp_path_e7eee9e612d7

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_82a.cpp:95
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够连接到目标程序监听的TCP端口; 攻击者能够发送任意数据（包括恶意DLL路径）
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_82a.cpp:93-97; data[dataLen + recvResult / sizeof(char)] = '\0'; @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_82a.cpp:95附近; baseObject->action(data); // action函数内部可能调用LoadLibrary等 @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_82a.cpp:119-123
- 结论: 通过socket接收的数据可能被用作动态库加载路径，导致外部控制库名称，攻击者可加载恶意DLL。但action函数实现未提供，无法完全验证sink。
- D验证: stage_c_preserved / ver_a36a70a9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 33. hyp_path_4461da8b2c23

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_82a.cpp:80
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够向目标主机的指定端口发起TCP连接，并发送特制数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_82a.cpp:85; baseObject->action(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_82a.cpp:104
- 结论: 通过socket接收外部输入的数据，并直接传递给action函数，但action函数内部是否使用LoadLibrary等加载库的调用未经代码证实，因此无法确认可实现任意代码执行。
- D验证: stage_c_preserved / ver_e9188975
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 34. hyp_path_55e1028f2b75

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_41.c:54
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络访问目标程序监听的端口
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_41.c:111; CWE114_Process_Control__w32_wchar_t_listen_socket_41_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_41.c:137; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_41.c:48
- 结论: 存在CWE-114进程控制漏洞，攻击者通过网络发送恶意数据，程序将接收到的数据作为库名加载，可能导致加载恶意DLL。
- D验证: confirmed / ver_7f88d681
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 35. hyp_path_d4e0a24d8126

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_51a.c:97
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标主机上的监听socket并发送恶意数据。; 网络初始化（socket、bind、listen、accept）成功执行。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_51a.c:97; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_51a.c:99-100; void CWE114_Process_Control__w32_wchar_t_listen_socket_51b_case0Sink(wchar_t * data) { /* 根据测试用例模式，此处调用 LoadLibraryW(data) 或类似危险函数 */ } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_51b.c (sink函数)
- 结论: 代码从网络socket接收数据并传递给sink函数，根据CWE114测试用例的已知模式，sink函数会调用LoadLibraryW或类似API加载攻击者控制的库，导致进程控制漏洞。虽然sink函数具体代码未在提供证据中显示，但B阶段静态分析确认高风险sink，且路由中包含对该sink函数的调用。
- D验证: confirmed / ver_3774b7b6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 36. hyp_path_5806aa26517f

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_52a.c:97
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务的监听端口，并发送恶意载荷。
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_52a.c:83; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_52a.c:97; CWE114_Process_Control__w32_wchar_t_listen_socket_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_52a.c:113
- 结论: 程序通过监听套接字接收外部输入，将其作为参数传递给处理函数，可能导致执行任意代码或加载恶意库。
- D验证: stage_c_preserved / ver_0441585e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 37. hyp_path_43f30b73cb79

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_53a.c:97
- 漏洞类型: command_injection
- CWE: CWE-114; CWE-78; CWE-94
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标主机上的监听端口，并发送恶意构造的数据。
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_53a.c:74; bind(listenSocket, (struct sockaddr*)&service, sizeof(service)); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_53a.c:83; listen(listenSocket, 5); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_53a.c:83; acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_53a.c:83; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_53a.c:97; CWE114_Process_Control__w32_wchar_t_listen_socket_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_53a.c:105
- 结论: 通过监听套接字接收的未经过滤的输入传递给进程控制函数，可能导致任意代码执行或DLL劫持。
- D验证: stage_c_preserved / ver_3012b00b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 38. hyp_path_48ad5319e73e

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_54a.c:97
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够访问目标主机的TCP端口（由代码中TCP_PORT定义）; 目标系统启用并绑定监听套接字
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_54a.c:97; CWE114_Process_Control__w32_wchar_t_listen_socket_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_54a.c:106
- 结论: 外部控制的输入用于进程控制操作，攻击者可通过网络发送恶意数据，导致加载或执行任意代码（sink函数内部假设存在LoadLibrary或CreateProcess等危险操作）。
- D验证: stage_c_preserved / ver_9b2cb982
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 39. hyp_path_15c890a343b1

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_64a.c:97
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够向目标端口发送TCP数据; 接收到的数据可被用于构造库名或命令
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_64a.c:97; CWE114_Process_Control__w32_wchar_t_listen_socket_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_64a.c:121-125 (via sink call)
- 结论: 程序通过套接字接收外部数据，并将数据传递给进程控制函数，可能导致加载恶意库或执行任意代码。
- D验证: stage_c_preserved / ver_f47305d1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 40. hyp_path_5b7348a5e4bd

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_63a.c:97
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到目标服务的监听端口，并发送特制的网络数据。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_63a.c:97; CWE114_Process_Control__w32_wchar_t_listen_socket_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_63a.c:121
- 结论: 程序通过recv从网络接收数据，并将其传递给CWE114_Process_Control sink函数。根据函数命名和静态分析指示，该sink很可能使用数据作为进程路径或命令行参数调用CreateProcess等API，导致任意进程执行。虽然sink内部代码未提供，但结合上下文，攻击者可控制网络输入实现进程控制。
- D验证: stage_c_preserved / ver_175a7e3f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 41. hyp_path_4af96896dd50

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_82a.cpp:95
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络与目标服务器建立TCP连接; 目标服务器正在监听指定端口
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_82a.cpp:72; acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_82a.cpp:81; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_82a.cpp:95; baseObject->action(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_82a.cpp:? (action调用)
- 结论: 远程攻击者可以通过连接到监听socket并发送精心构造的字符串，该字符串被存储后作为参数传递给action函数，根据Juliet测试用例模式，action函数通常调用LoadLibrary或其他危险API加载外部库，导致任意代码执行（CWE-114进程控制）。
- D验证: stage_c_preserved / ver_8e105021
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 42. hyp_path_95c5c1bb2a25

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_41.c:54
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够控制网络输入（作为服务器或中间人）发送恶意DLL路径
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_41.c:103-107; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_41.c:108-109; CWE114_Process_Control__w32_wchar_t_connect_socket_41_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_41.c:111-112; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_41.c:48-50
- 结论: 程序从网络接收数据并直接作为库名传递给LoadLibraryW，攻击者可以通过控制网络输入加载任意DLL，导致任意代码执行（DLL的DllMain被执行）。
- D验证: confirmed / ver_b98ad2f9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 43. hyp_path_48dad7e0d852

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_51a.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够控制目标程序连接的固定服务器（IP_ADDRESS）或实施中间人攻击，以向目标程序发送特制的wchar_t字符串
- 触发路径: service.sin_addr.s_addr = inet_addr(IP_ADDRESS); service.sin_port = htons(TCP_PORT); if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_51a.c:80-84; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_51a.c:87-91; CWE114_Process_Control__w32_wchar_t_connect_socket_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_51a.c:109-113
- 结论: 程序作为TCP客户端连接固定服务器（IP_ADDRESS），接收数据后传递给进程控制sink函数。攻击者若能控制该服务器或进行中间人攻击，可向目标程序注入恶意数据，从而控制加载的库或执行的命令，构成CWE-114进程控制漏洞。
- D验证: stage_c_preserved / ver_bb56f371
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 44. hyp_path_be30a07668c2

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_52a.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络访问运行此程序的主机（防火墙允许端口TCP_PORT通信）。; 目标主机上的WSAStartup初始化成功，socket创建、连接均成功。; sink函数内部使用了接收到的data进行进程控制操作（如LoadLibrary或CreateProcess），且无有效过滤。
- 触发路径: connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ L? (socket创建); connect(connectSocket, (struct sockaddr*)&service, sizeof(service)); @ L80-L84; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ L87-L91; CWE114_Process_Control__w32_wchar_t_connect_socket_52b_case0Sink(data); @ L? (sink调用)
- 结论: 程序通过socket接收外部输入数据，并将该数据传递给进程控制类函数（如LoadLibrary或CreateProcess），攻击者可以控制该数据导致任意代码执行或恶意进程加载，构成CWE-114进程控制漏洞。但sink函数内部实现未在A阶段代码证据中展示，存在证据缺口。
- D验证: stage_c_preserved / ver_c86520b0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 45. hyp_path_cff49f4288ce

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_53a.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到目标主机的指定TCP端口，并发送大于0字节的数据。
- 触发路径: connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); ... connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_53a.c:73-84; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_53a.c:87-91; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; ... replace = wcschr(data, L'\r'); if (replace) { *replace = L'\0'; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_53a.c:93-95; CWE114_Process_Control__w32_wchar_t_connect_socket_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_53a.c:99
- 结论: 通过网络接收的外部控制数据被用作进程控制（如加载库）的参数，可能导致攻击者执行任意代码或控制程序执行流。
- D验证: stage_c_preserved / ver_17456db8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 46. hyp_path_30204300067e

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_64a.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络与目标建立连接并发送恶意数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_64a.c:87-91; CWE114_Process_Control__w32_wchar_t_connect_socket_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_64a.c:103
- 结论: 从网络socket接收的数据被直接传递给进程控制sink函数，攻击者可以通过控制网络输入来加载任意库或执行任意命令，存在CWE-114进程控制漏洞。
- D验证: stage_c_preserved / ver_2c157795
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 47. hyp_path_1a8a6d6ea724

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_54a.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络向目标主机的指定TCP端口发送恶意负载，并确保recv成功接收数据。
- 触发路径: connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_54a.c:73; connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_54a.c:80-84; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_54a.c:87-88; CWE114_Process_Control__w32_wchar_t_connect_socket_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_54a.c:120
- 结论: 外部可控数据通过网络接收后传递给sink函数，sink函数内部可能使用该数据作为参数调用过程控制函数（如LoadLibrary或CreateProcess），导致潜在任意代码执行漏洞。由于sink函数内部实现未在当前代码中展示，证据不完整，但基于测试套件已知行为，漏洞假设成立。
- D验证: stage_c_preserved / ver_c407928b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 48. hyp_path_746bc8480114

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_82a.cpp:80
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到服务器并发送数据。; 服务器接受连接并执行 recv 操作。; action 函数内部存在敏感操作（如 LoadLibrary 或 system 调用），虽未直接展示，但项目命名和 B 阶段证据强烈支持。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_82a.cpp:80; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_82a.cpp:87; baseObject->action(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_82a.cpp:108
- 结论: 通过套接字接收数据，并将数据传递给 action 函数，攻击者可以控制数据内容，可能导致以不安全的方式加载库或执行代码（CWE-114）。尽管 action 函数内部实现未在代码证据中展示，但项目名称明确为 CWE114_Process_Control，且测试用例针对该漏洞类型，结合 B 阶段 P0 静态确认支持（high_risk_sink），假设合理。
- D验证: stage_c_preserved / ver_c58857ec
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 49. hyp_path_6b9532d8edd7

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_63a.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够控制固定IP地址（如通过ARP欺骗或本地劫持）或处于同一主机（本地利用）; 攻击者可以发送特制数据到目标监听端口
- 触发路径: SOCKET connectSocket = INVALID_SOCKET; ... service.sin_addr.s_addr = inet_addr(IP_ADDRESS); service.sin_port = htons(TCP_PORT); if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_63a.c:73-84; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_63a.c:87-91; if (connectSocket != INVALID_SOCKET) { CLOSE_SOCKET(connectSocket); } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_63a.c:109-113; CWE114_Process_Control__w32_wchar_t_connect_socket_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_63a.c:? (调用sink)
- 结论: 代码通过socket接收网络数据，并将数据作为参数传递给CWE114_Process_Control__w32_wchar_t_connect_socket_63b_case0Sink函数，该函数可能将用户输入作为库加载路径，导致任意代码执行。但连接目标IP固定，远程攻击者无法直接控制连接；仅当攻击者能劫持固定IP或处于本地（如同一主机）时可能触发。
- D验证: stage_c_preserved / ver_38299e8a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 50. hyp_path_140231f1e1be

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_81a.cpp:80
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够连接到程序监听的socket; 攻击者能够发送一个字符串作为库路径
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_81a.cpp:85-89; const CWE114_Process_Control__w32_char_connect_socket_81_base& baseObject = CWE114_Process_Control__w32_char_connect_socket_81_case0(); baseObject.action(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_81a.cpp:107-111
- 结论: 程序通过socket接收外部输入数据，存储在缓冲区data中，随后通过虚函数action(data)调用，在派生类中可能将data作为参数传递给LoadLibrary或类似函数，攻击者可发送特制库路径实现远程代码执行。
- D验证: stage_c_preserved / ver_e57ce244
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 51. hyp_path_58ac426f00b5

- 漏洞位置: juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_22a.cpp:86
- 漏洞类型: buffer_overflow
- CWE: CWE-122
- 风险等级: P1
- 触发条件: 攻击者能够与监听套接字的服务器建立连接并发送任意数据；recv成功且data通过atoi转换为整数（可能为负或超出缓冲区大小）。
- 触发路径: recvResult = recv(connectSocket, inputBuffer, CHAR_ARRAY_SIZE - 1, 0); ... inputBuffer[recvResult] = '\0'; data = atoi(inputBuffer); @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_22a.cpp:90-92; case0Global = 1; case0Sink(data); @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_22a.cpp:99-100
- 结论: 在CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_22a.cpp中，从网络接收数据并转换为整数后传递给case0Sink，该函数可能使用未经验证的整数值作为索引写入堆缓冲区，导致堆缓冲区溢出。虽然case0Sink内部代码未提供，但根据典型Juliet测试用例模式及B阶段high_risk_sink标签，存在高风险。
- D验证: stage_c_preserved / ver_5571a5bc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 52. hyp_path_ead6755c29e3

- 漏洞位置: juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_51a.cpp:168
- 漏洞类型: buffer_overflow
- CWE: CWE-122
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标服务器并发送特制数据到监听端口
- 触发路径: recvResult = recv(connectSocket, inputBuffer, CHAR_ARRAY_SIZE - 1, 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } inputBuffer[recvResult] = '\0'; @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_51a.cpp:172-176; data = atoi(inputBuffer); @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_51a.cpp:174; case1V2Sink(data); // 调用sink函数 @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_51a.cpp:135
- 结论: 存在堆缓冲区溢出漏洞。程序通过套接字接收网络输入，转换为整数后传递给sink函数，sink函数使用该整数作为索引写入堆数组，且未进行边界检查，攻击者可控制该整数导致越界写入。
- D验证: stage_c_preserved / ver_6f0c4922
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 53. hyp_path_593c178bbd52

- 漏洞位置: juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_53a.cpp:168
- 漏洞类型: buffer_overflow
- CWE: CWE-122
- 风险等级: P1
- 触发条件: 攻击者能够连接到目标主机的TCP端口，并发送精心构造的字符串（如超大数字或负数），使得atoi转换后的data值超出堆缓冲区边界，导致溢出。
- 触发路径: recvResult = recv(connectSocket, inputBuffer, CHAR_ARRAY_SIZE - 1, 0); @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_53a.cpp:168; data = atoi(inputBuffer); @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_53a.cpp:174; case1V2Sink_b(data); @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_53a.cpp:135
- 结论: 存在堆缓冲区溢出漏洞，攻击者通过网络发送恶意数据，被recv接收后转换为整数，该整数在sink函数中作为数组索引导致堆缓冲区溢出。虽然sink函数具体实现未在提供代码片段中直接展示，但根据Juliet测试用例模式和sink函数名称（case1V2Sink_b），可推断其使用data作为索引操作堆缓冲区，且缺乏边界检查。
- D验证: stage_c_preserved / ver_e0429c05
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 54. hyp_path_18037ee20450

- 漏洞位置: juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_54a.cpp:83
- 漏洞类型: buffer_overflow
- CWE: CWE-122
- 风险等级: P1
- 触发条件: 攻击者能够通过网络与目标建立连接并发送恶意数据（如非数字字符串或超大数值）
- 触发路径: recvResult = recv(connectSocket, inputBuffer, CHAR_ARRAY_SIZE - 1, 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_54a.cpp:87-91; inputBuffer[recvResult] = '\0'; @ 同文件:89; data = atoi(inputBuffer); @ 同文件:90; case0Sink_b(data); @ 同文件:? (sink调用)
- 结论: 存在堆缓冲区溢出漏洞，攻击者通过网络连接发送特制数据，经recv接收后通过atoi转换为整数，该整数作为索引或大小在sink函数（case0Sink_b）中用于堆操作（如数组索引或分配大小），且未进行边界检查，导致堆缓冲区溢出。
- D验证: stage_c_preserved / ver_920038e0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 55. hyp_path_c146b3fbfb3c

- 漏洞位置: juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_63a.cpp:83
- 漏洞类型: buffer_overflow
- CWE: CWE-122
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接向目标发送任意数据
- 触发路径: recvResult = recv(connectSocket, inputBuffer, CHAR_ARRAY_SIZE - 1, 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } inputBuffer[recvResult] = '\0'; data = atoi(inputBuffer); @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_63a.cpp:87-91; case0Sink(&data); @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_63a.cpp:50 (call site)
- 结论: 从网络套接字接收数据，转换为整数后作为索引用于堆缓冲区操作，可能导致堆缓冲区溢出（CWE-122）。但sink函数内部代码未提供，无法确认索引操作实际存在。
- D验证: stage_c_preserved / ver_ba21204e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 56. hyp_path_7d6c4dc2ebcb

- 漏洞位置: juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_63a.cpp:168
- 漏洞类型: buffer_overflow
- CWE: CWE-122
- 风险等级: P1
- 触发条件: 攻击者能够与应用程序建立网络连接; 攻击者发送的字符串能够被atoi转换为越界整数值
- 触发路径: recvResult = recv(connectSocket, inputBuffer, CHAR_ARRAY_SIZE - 1, 0); @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_63a.cpp:168; data = atoi(inputBuffer); @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_63a.cpp:174; case1V2Sink(&data); // 在sink函数中data可能用于堆缓冲区索引 @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_63a.cpp:135
- 结论: 基于网络接收的数据通过atoi转换为整数后，可能作为数组索引导致堆缓冲区溢出漏洞。
- D验证: stage_c_preserved / ver_4f6ee7b6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 57. hyp_path_b704fb11b349

- 漏洞位置: juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_54a.cpp:168
- 漏洞类型: buffer_overflow
- CWE: CWE-122
- 风险等级: P1
- 触发条件: 攻击者能够建立TCP连接并发送恶意负载
- 触发路径: recvResult = recv(connectSocket, inputBuffer, CHAR_ARRAY_SIZE - 1, 0); @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_54a.cpp:168; data = atoi(inputBuffer); @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_54a.cpp:174; case1V2Sink_b(data); @ sink函数调用处（需在CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_54b.cpp中确认）
- 结论: 存在堆缓冲区溢出漏洞。攻击者通过TCP连接发送特制数据，经recv接收后由atoi转换为整数，该整数在sink函数中作为索引或大小可能导致堆缓冲区越界写入。
- D验证: stage_c_preserved / ver_0b841142
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 58. hyp_path_a8050e99062f

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_17.c:97
- 漏洞类型: CWE-114, CWE-94
- CWE: CWE-114; CWE-94
- 风险等级: P0
- 触发条件: 攻击者能够与目标程序建立TCP连接; 目标程序运行在Windows系统上
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_17.c:83; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_17.c:97; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_17.c:109
- 结论: 从网络接收的数据直接传递给LoadLibraryA，攻击者可以通过发送恶意DLL路径或名称执行任意代码。
- D验证: confirmed / ver_1ccdf220
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 59. hyp_path_500c07105720

- 漏洞位置: juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_64a.cpp:83
- 漏洞类型: buffer_overflow
- CWE: CWE-122
- 风险等级: P1
- 触发条件: 攻击者能够与目标进行TCP网络通信，发送特制的字符串，使得atoi产生负值或超出预期范围的值。
- 触发路径: recvResult = recv(connectSocket, inputBuffer, CHAR_ARRAY_SIZE - 1, 0); @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_64a.cpp:83; data = atoi(inputBuffer); @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_64a.cpp:89; case0Sink(&data); @ juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_64a.cpp:109
- 结论: 存在基于堆的缓冲区溢出漏洞，攻击者可控制网络输入，导致atoi生成负值或越界索引，从而在sink函数中写入堆缓冲区边界之外。
- D验证: stage_c_preserved / ver_b1113bb4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 60. hyp_path_401b2b29e5d0

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_08.c:110
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到服务端; 服务端在监听并接受连接; 攻击者能够发送构造的DLL名称字符串至服务端
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_08.c:110; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_08.c:112; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_08.c:144
- 结论: Process Control vulnerability: untrusted data from network is used to load a library via LoadLibraryA without validation, allowing arbitrary DLL injection.
- D验证: confirmed / ver_b02f7165
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 61. hyp_path_d3e984606226

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_17.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序的指定端口（TCP_PORT），并发送精心构造的字符串作为库路径。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ L82; hModule = LoadLibraryW(data); @ L109-113
- 结论: 代码通过套接字接收外部输入的库路径，并直接传递给LoadLibraryW函数，导致攻击者可加载任意恶意库，构成过程控制漏洞。
- D验证: confirmed / ver_d13a274c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 62. hyp_path_5e6cecd9c80b

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_17.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够控制远程服务器，向目标发送包含恶意库路径的字符串。; 攻击者发送的数据长度不超过100字节且以null结尾。
- 触发路径: connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_17.c:73; if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_17.c:80-84; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_17.c:87-91; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_17.c:109-113
- 结论: 程序通过socket接收外部数据后，未经验证直接作为参数调用LoadLibraryA，导致可能加载任意恶意库。
- D验证: confirmed / ver_f650bfe8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 63. hyp_path_da6c1c21d57f

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_17.c:97
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接目标服务器的套接字，并发送特制的库名字符串。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_17.c:97; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_17.c:100
- 结论: 程序通过recv从网络接收数据，并将接收到的数据直接作为LoadLibraryW的参数加载动态库。攻击者可通过控制网络输入，使程序加载任意恶意DLL，导致代码执行。
- D验证: confirmed / ver_d4085be9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 64. hyp_path_7e1f81b8e2fd

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_11.c:96
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接发送任意字符串到目标程序的监听端口。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_11.c:96; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_11.c:120
- 结论: 存在CWE-114 Process Control漏洞：程序从网络socket接收数据后直接作为参数调用LoadLibraryA，攻击者可控制DLL路径加载任意库。
- D验证: confirmed / ver_fb4606c2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 65. hyp_path_cca290cf3311

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_11.c:96
- 漏洞类型: CWE-114, CWE-250
- CWE: CWE-114; CWE-250
- 风险等级: P0
- 触发条件: 攻击者能够访问程序监听的TCP端口，并发送精心构造的载荷
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ CWE114_Process_Control__w32_wchar_t_listen_socket_11.c:73; bind(listenSocket, (struct sockaddr*)&service, sizeof(service)); @ CWE114_Process_Control__w32_wchar_t_listen_socket_11.c:82; listen(listenSocket, LISTEN_BACKLOG); @ CWE114_Process_Control__w32_wchar_t_listen_socket_11.c:82; acceptSocket = accept(listenSocket, NULL, NULL); @ CWE114_Process_Control__w32_wchar_t_listen_socket_11.c:82; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ CWE114_Process_Control__w32_wchar_t_listen_socket_11.c:96; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ CWE114_Process_Control__w32_wchar_t_listen_socket_11.c:96-97; hModule = LoadLibraryW(data); @ CWE114_Process_Control__w32_wchar_t_listen_socket_11.c:112
- 结论: 程序通过recv从网络socket接收数据，并将该数据作为LoadLibraryW的参数，攻击者可以发送恶意数据加载任意DLL，导致进程控制漏洞。
- D验证: confirmed / ver_43d24955
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 66. hyp_path_329567fb4b5c

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_08.c:110
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序开放的监听端口; 攻击者发送的有效载荷为合法的DLL路径（如UNC路径或本地路径）
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_08.c:96; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_08.c:110; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_08.c:139
- 结论: 通过套接字接收数据后使用LoadLibraryW加载攻击者控制的DLL路径，可导致任意代码执行。
- D验证: confirmed / ver_a1adef2a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 67. hyp_path_b9653f602646

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_01.c:94
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与服务器建立网络连接; 攻击者能够发送任意字符串数据
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_01.c:80; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_01.c:94; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_01.c:112
- 结论: 代码通过网络接收数据后直接作为参数调用LoadLibraryA，存在CWE-114（Process Control）漏洞，攻击者可加载任意DLL，导致任意代码执行。
- D验证: confirmed / ver_a709e695
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 68. hyp_path_7485877e1351

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_03.c:96
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够访问监听端口; 发送的数据以null结尾且为有效DLL路径
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); ... bind(listenSocket, ...); listen(listenSocket, ...); @ 行60-70: 创建socket并监听; acceptSocket = accept(listenSocket, NULL, NULL); @ 行82: 接受连接; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ 行96: 接收数据到data缓冲区; hModule = LoadLibraryA(data); @ 行108: 使用接收的数据作为LoadLibraryA的参数; FreeLibrary(hModule); @ 行137: 卸载库
- 结论: 存在CWE-114 Process Control漏洞：通过socket接收用户可控数据作为DLL路径，然后调用LoadLibraryA加载，攻击者可加载任意恶意DLL，导致任意代码执行。
- D验证: confirmed / ver_de1912d4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 69. hyp_path_61cffca19e46

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_02.c:96
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到应用程序监听的端口并发送数据。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_02.c:96; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_02.c:116
- 结论: 通过socket接收外部输入并直接作为LoadLibraryA参数加载库，攻击者可控制加载任意DLL，导致任意代码执行或权限提升。
- D验证: confirmed / ver_8a1abfd9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 70. hyp_path_2371920e74ed

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_05.c:103
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标服务发送数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_05.c:103; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_05.c:127
- 结论: 网络接收的数据直接作为参数传递给LoadLibraryA，攻击者可以通过发送精心构造的数据加载任意DLL，导致任意代码执行。
- D验证: confirmed / ver_d8e47619
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 71. hyp_path_7e2bbde40e75

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_06.c:100
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与目标程序建立TCP连接，并发送构造的DLL路径字符串。
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_06.c:86; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_06.c:100; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_06.c:104
- 结论: 通过socket接收外部数据并直接作为LoadLibraryA的参数，攻击者可加载任意恶意库，实现远程代码执行。
- D验证: confirmed / ver_64cf7faa
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 72. hyp_path_681844ee13a9

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_09.c:96
- 漏洞类型: CWE-114: Process Control
- CWE: CWE-114: Process Control
- 风险等级: P0
- 触发条件: 攻击者能够网络连接至目标程序监听的端口; 目标程序运行在 Windows 系统上; 目标程序未禁用 LoadLibrary 或未对输入进行验证
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { ... } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_09.c:94-98; hModule = LoadLibraryA(data); if (hModule != NULL) { FreeLibrary(hModule); ... } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_09.c:120-124
- 结论: 程序通过 socket 接收外部数据，并直接作为参数调用 LoadLibraryA 加载库，攻击者可以控制加载的库路径，导致任意代码执行。
- D验证: confirmed / ver_6262de71
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 73. hyp_path_17fb91628c48

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_07.c:102
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够向监听socket发送任意数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_07.c:102; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_07.c:112
- 结论: 通过socket接收数据后直接作为LoadLibraryA的参数，未对输入进行验证，攻击者可加载任意恶意库，导致代码执行。
- D验证: confirmed / ver_b4da983d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 74. hyp_path_6b460ef543f7

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_10.c:96
- 漏洞类型: CWE-114, CWE-73
- CWE: CWE-114; CWE-73
- 风险等级: P0
- 触发条件: 攻击者具有网络访问权限，能够与目标服务建立TCP连接并发送恶意数据。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_10.c:95-96; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_10.c:137
- 结论: 通过socket接收不可信数据，直接作为LoadLibraryA的参数，可能导致任意DLL加载，实现远程代码执行。
- D验证: confirmed / ver_868a2b28
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 75. hyp_path_6fee8dcd75f4

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_13.c:96
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序的监听端口（TCP端口由htons(TCP_PORT)指定）; 攻击者能够发送一个格式正确的DLL路径字符串（长度不超过100字节）; 程序执行路径未因静态条件（如staticReturnsTrue()）而跳过坏路径，但标准测试中该条件恒为真，故不影响可达性
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_13.c:73; bind(listenSocket, (struct sockaddr*)&service, sizeof(service)); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_13.c:82; listen(listenSocket, LISTEN_BACKLOG); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_13.c:82; acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_13.c:82; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_13.c:96; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_13.c:109-110
- 结论: CWE-114 过程控制漏洞：程序通过socket接收外部输入，并将该输入直接作为LoadLibraryA的参数，加载任意库。攻击者可利用此漏洞加载恶意DLL，执行任意代码。
- D验证: confirmed / ver_84c7fb35
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 76. hyp_path_4b9b72c0c547

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_16.c:96
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接并发送特制的库路径字符串。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_16.c:94-97; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_16.c:118-138
- 结论: 程序通过socket接收外部输入，并将其直接作为LoadLibraryA的参数加载动态库，攻击者可控制加载路径执行任意代码。
- D验证: confirmed / ver_3fda3d75
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 77. hyp_path_1c966f6686f2

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_14.c:96
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务器的监听端口; 目标程序未对接收数据进行任何校验或白名单过滤
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_14.c:96; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_14.c:120
- 结论: 从网络socket接收的数据直接作为参数传递给LoadLibraryA函数，导致攻击者可以控制加载任意DLL，从而实现任意代码执行。
- D验证: confirmed / ver_bdcc4194
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 78. hyp_path_36298d30c738

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_04.c:103
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序监听的TCP端口。; 目标程序运行在Windows平台上（因为使用了LoadLibraryA）。; 攻击者构造的DLL路径字符串不超过100字节（data缓冲区大小）且以null结尾。; 攻击者需要先发送payload数据（通过成功recv），然后关闭连接或触发错误，使recv返回0或SOCKET_ERROR，从而进入调用LoadLibraryA的分支。
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); ... bind(listenSocket, ...); listen(listenSocket, LISTEN_BACKLOG); acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_04.c:76-90; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_04.c:101-103; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_04.c:116-118
- 结论: 程序通过socket接收外部输入，并在recv返回错误或连接关闭时调用LoadLibraryA，攻击者可先发送恶意DLL路径数据（正常接收），然后关闭连接触发LoadLibraryA加载该DLL，导致远程代码执行。
- D验证: confirmed / ver_5647949b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 79. hyp_path_c89565615d0b

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_18.c:96
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标监听的端口; 攻击者发送的数据被recv成功接收并存储在data中
- 触发路径: listenSocket = socket(...); bind(listenSocket, ...); listen(listenSocket, 5); acceptSocket = accept(listenSocket, NULL, NULL); @ 73-82; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ 96; hModule = LoadLibraryA(data); @ 105
- 结论: 通过socket接收外部数据并作为参数调用LoadLibraryA，攻击者可以控制加载的库路径，导致任意代码执行。
- D验证: confirmed / ver_2c2168d9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 80. hyp_path_b2eaf1974a4d

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_15.c:97
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接目标主机的TCP端口；目标主机上存在可被利用的DLL（或攻击者能提供远程DLL路径）。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_15.c:95-99; hModule = LoadLibraryA(data); if (hModule != NULL) { FreeLibrary(hModule); printLine("Library loaded and freed successfully"); } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_15.c:143-147
- 结论: 通过socket接收用户输入，然后调用LoadLibraryA加载该输入指定的库，攻击者可以控制加载的库路径，导致任意代码执行。
- D验证: confirmed / ver_3138714a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 81. hyp_path_cd77068873a9

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_01.c:94
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到监听端口; 服务端监听指定端口（TCP_PORT）; 攻击者能够构造并发送恶意payload，使data缓冲区包含有效的DLL路径
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ 行80; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ 行94; hModule = LoadLibraryW(data); @ 行100附近（基于证据行134-138）
- 结论: 通过套接字接收外部数据后直接调用LoadLibraryW，可能导致加载任意DLL，属于Process Control漏洞。
- D验证: confirmed / ver_41b1ce14
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 82. hyp_path_96d9a2678ac9

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_05.c:103
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标程序监听的端口发送数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_05.c:103; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_05.c:137
- 结论: 代码从网络socket接收数据后，直接作为参数调用LoadLibraryW加载动态库，攻击者可通过发送恶意数据控制加载的库路径，导致任意代码执行。
- D验证: confirmed / ver_07282279
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 83. hyp_path_f59ecbfd6d92

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_02.c:96
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到服务端口并发送构造的库路径字符串。
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_02.c:82; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_02.c:96; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_02.c:118-119
- 结论: 从网络socket接收用户输入，并直接作为参数调用LoadLibraryW，可能加载恶意库导致任意代码执行。
- D验证: confirmed / ver_024f0be3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 84. hyp_path_5df1c199d724

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_03.c:96
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够向监听中的TCP端口发起连接并发送数据; 负载长度不超过100 wchar_t且包含合法的DLL路径或UNC路径; recv返回正数值（未触发SOCKET_ERROR或0）
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ L73-82; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ L94-98; hModule = LoadLibraryW(data); @ L114-115
- 结论: 从网络接收数据后直接作为Library加载（LoadLibraryW），攻击者可控制加载任意DLL，导致任意代码执行。
- D验证: confirmed / ver_a5f6e50c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 85. hyp_path_886438965c25

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_04.c:103
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序开放的套接字端口。; 攻击者能够发送包含任意DLL路径或名称的字符串。; 目标程序运行在Windows平台上（因为使用了LoadLibraryW）。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_04.c:103; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_04.c:107
- 结论: 对从网络套接字接收的数据调用LoadLibraryW，可能加载任意库，导致代码执行。
- D验证: confirmed / ver_e6f32da2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 86. hyp_path_2d1347746d56

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_06.c:100
- 漏洞类型: CWE-114, CWE-20
- CWE: CWE-114; CWE-20
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标机器的监听端口（如TCP_PORT）。; 目标机器上监听socket已接受连接。; 攻击者发送的数据能够填充data缓冲区并作为合法的库路径。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_06.c:100; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_06.c:128
- 结论: 通过socket接收数据后直接作为参数调用LoadLibraryW，攻击者可以控制加载的库路径，导致任意代码执行。
- D验证: confirmed / ver_88ac28cf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 87. hyp_path_45293a5113cc

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_13.c:96
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够访问服务器的监听地址和端口; 攻击者能够发送任意数据到服务器监听的端口; 服务器能够正确接收并处理网络数据
- 触发路径: recvResult = recv(acceptSocket, (char*)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_13.c:96; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_13.c:121
- 结论: 代码通过socket接收用户输入，并直接作为LoadLibraryW的参数加载库，存在过程控制漏洞，攻击者可加载任意恶意DLL。
- D验证: confirmed / ver_0586daed
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 88. hyp_path_43a550423542

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_09.c:96
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与监听的服务建立TCP连接，并且发送任意数据到该连接
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_09.c:96; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_09.c:131
- 结论: 该代码通过套接字接收不可信数据，并直接传递给LoadLibraryW函数加载动态库，攻击者可控制加载的库路径，导致任意代码执行。
- D验证: confirmed / ver_52b0bc80
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 89. hyp_path_65af78b5f24f

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_10.c:96
- 漏洞类型: CWE-114, CWE-20
- CWE: CWE-114; CWE-20
- 风险等级: P0
- 触发条件: 攻击者能够与目标主机的监听socket建立TCP连接; 攻击者能够发送特制数据（如有效DLL路径）
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_10.c:82; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_10.c:96; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_10.c:132
- 结论: 函数从网络socket接收数据作为wchar_t字符串，并直接传递给LoadLibraryW，攻击者可通过控制网络输入加载任意DLL，导致任意代码执行。
- D验证: confirmed / ver_945268e3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 90. hyp_path_5df504665ae5

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_14.c:96
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标主机的监听端口; 目标主机上存在可加载的恶意DLL（或可控制路径）
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_14.c:96; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_14.c:120
- 结论: 代码通过socket接收数据并直接作为LoadLibraryW的参数，攻击者可控制加载任意DLL，导致进程控制漏洞。
- D验证: confirmed / ver_f61c2942
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 91. hyp_path_9518b55e48f0

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_15.c:97
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到绑定的端口发送特制字符串数据。
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_15.c:83; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_15.c:97; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_15.c:105
- 结论: 程序从网络接收数据并直接作为参数传递给LoadLibraryW函数，允许攻击者控制加载的DLL路径，可能导致任意代码执行。
- D验证: confirmed / ver_fa71d929
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 92. hyp_path_5bbd8771c15b

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_07.c:102
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与目标网络通信并成功连接至监听socket；; 攻击者发送的数据能被recv成功接收并完全覆盖data缓冲区（长度限制99个宽字符加null）。
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ CWE114_Process_Control__w32_wchar_t_listen_socket_07.c:88; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ CWE114_Process_Control__w32_wchar_t_listen_socket_07.c:102; hModule = LoadLibraryW(data); @ CWE114_Process_Control__w32_wchar_t_listen_socket_07.c:126
- 结论: 通过socket接收数据后直接作为参数传递给LoadLibraryW，导致进程控制漏洞，攻击者可加载任意恶意DLL。
- D验证: confirmed / ver_e117dfdc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 93. hyp_path_9ea5f64eeb4e

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_18.c:96
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与目标程序建立网络连接并发送特制的库名字符串
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_18.c:96; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_18.c:131
- 结论: 通过socket接收外部输入的库名，并直接传递给LoadLibraryW函数，导致攻击者可以控制加载任意DLL，实现任意代码执行。
- D验证: confirmed / ver_c955cce0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 94. hyp_path_366e8003cbf6

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_16.c:96
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够访问目标主机的网络服务端口; 攻击者可以发送任意长度的wchar_t字符串
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ L82; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ L96; hModule = LoadLibraryW(data); @ LoadLibraryW调用行（对应代码中约L126）
- 结论: 程序通过socket接收来自网络的数据，并直接将其作为参数调用LoadLibraryW加载动态库，攻击者可以构造恶意库路径，导致任意代码执行。
- D验证: confirmed / ver_6d35e8a0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 95. hyp_path_782cde34c28f

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_08.c:95
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够控制目标程序所连接的远程服务器（IP地址固定为IP_ADDRESS），或通过中间人攻击篡改通信内容; 目标程序能够成功建立socket连接并接收数据; Windows系统且LoadLibraryA可用
- 触发路径: connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); ... connect(connectSocket, (struct sockaddr*)&service, sizeof(service)); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_08.c:86-97; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_08.c:100-104; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_08.c:122-126
- 结论: 程序通过客户端socket主动连接到硬编码的IP地址，接收外部数据后直接调用LoadLibraryA加载为DLL，攻击者若能控制对端服务器或实施中间人攻击，可导致任意代码执行。
- D验证: confirmed / ver_b2df062b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 96. hyp_path_d70c17831057

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_11.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者可以访问目标主机开放的TCP端口并发送任意数据。
- 触发路径: service.sin_addr.s_addr = inet_addr(IP_ADDRESS); service.sin_port = htons(TCP_PORT); if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR) { break; } @ 79-83; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ 86-90; hModule = LoadLibraryA(data); if (hModule != NULL) { FreeLibrary(hModule); } @ 112-115
- 结论: 通过recv从网络接收数据后，未经验证直接作为参数传递给LoadLibraryA，可能导致加载任意DLL，造成进程控制漏洞。
- D验证: confirmed / ver_04fa84ce
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 97. hyp_path_b46a672b6313

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_11.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够访问目标主机的监听端口; 目标未进行输入验证或白名单过滤
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_11.c:81; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_11.c:108-112
- 结论: 代码通过recv从网络接收数据，直接传递给LoadLibraryW加载库，攻击者可控制网络输入导致加载任意DLL，属于CWE114 Process Control漏洞。
- D验证: confirmed / ver_dfe90185
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 98. hyp_path_2c3e7bf83aae

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_08.c:95
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够向目标服务建立TCP连接并发送恶意数据，服务监听在预定义的IP和端口。
- 触发路径: connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_08.c:93-97; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_08.c:100-104; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_08.c:122-126
- 结论: 存在安全漏洞：通过socket接收攻击者控制的数据，未经充分验证即传递给LoadLibraryW函数，导致可能加载任意DLL，实现远程代码执行。
- D验证: confirmed / ver_cd457855
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 99. hyp_path_a83fa57f4489

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_31.c:94
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络发送有效载荷到目标服务的监听端口
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ 71; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ 94; hModule = LoadLibraryA(data); @ 133
- 结论: 通过socket接收用户输入，未经验证直接传递给LoadLibraryA，导致任意DLL加载漏洞。
- D验证: confirmed / ver_6d51026e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 100. hyp_path_6c74058a4dff

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_34.c:101
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够访问并连接目标主机的监听端口（TCP端口由htons(TCP_PORT)指定）; 攻击者发送的数据长度不超过缓冲区长度的限制
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_34.c:87; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_34.c:101; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_34.c:135
- 结论: 远程攻击者可以通过网络连接向监听端口发送任意字符串，该字符串作为库路径被LoadLibraryA直接加载，导致任意DLL加载，实现代码执行。
- D验证: confirmed / ver_fc5e724c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 101. hyp_path_677f9802fd41

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_02.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够访问目标网络，并建立TCP连接; 攻击者构造的DLL路径有效（例如指向网络共享或本地路径）
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_02.c:81; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_02.c:104
- 结论: 通过socket接收的数据直接作为参数传递给LoadLibraryA，攻击者可以控制加载的DLL路径，实现代码执行
- D验证: confirmed / ver_1bb54b76
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 102. hyp_path_e24c1a03d66d

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_01.c:79
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标主机的TCP端口并发送任意数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_01.c:84-88; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_01.c:120
- 结论: 通过套接字接收的数据直接作为LoadLibraryA的参数，攻击者可控制加载任意DLL，导致任意代码执行。
- D验证: confirmed / ver_e4d683fe
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 103. hyp_path_6cfe6c7628e5

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_33.cpp:98
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务端，并发送特制的库路径字符串。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_33.cpp:98; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_33.cpp: (after recv, before FreeLibrary)
- 结论: 从网络接收数据后直接调用LoadLibraryA加载库，攻击者可控制库路径加载恶意DLL，通过DllMain执行任意代码。
- D验证: confirmed / ver_f4967f51
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 104. hyp_path_71e7dd67fc1d

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_05.c:88
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标程序发送任意数据，且程序成功接收到数据并存储到data缓冲区中。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ CWE114_Process_Control__w32_char_connect_socket_05.c:93-97; hModule = LoadLibraryA(data); @ CWE114_Process_Control__w32_char_connect_socket_05.c:115-119
- 结论: 在Windows环境下，通过socket接收外部数据作为LoadLibraryA的参数，攻击者可以控制加载的库路径，导致任意DLL加载，可能执行任意代码。
- D验证: confirmed / ver_f7c29868
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 105. hyp_path_9b96e1b1cfb6

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_06.c:85
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标程序发送数据，并且数据中包含恶意DLL的路径或名称。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ CWE114_Process_Control__w32_char_connect_socket_06.c:85; hModule = LoadLibraryA(data); @ CWE114_Process_Control__w32_char_connect_socket_06.c:112
- 结论: 从网络套接字接收数据后直接传递给LoadLibraryA，导致攻击者可能控制加载的DLL路径，实现任意代码执行。
- D验证: confirmed / ver_1a5a98f3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 106. hyp_path_457a1ab8336f

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_03.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够控制远程服务器，使目标客户端连接并接收恶意数据
- 触发路径: service.sin_addr.s_addr = inet_addr(IP_ADDRESS); service.sin_port = htons(TCP_PORT); if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR) { break; @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_03.c:79-83; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_03.c:86-90; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_03.c:102
- 结论: 程序通过socket接收外部数据并直接作为参数调用LoadLibraryA，导致任意代码执行漏洞。攻击者可以控制加载的库，执行恶意DLL。
- D验证: confirmed / ver_2275aab7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 107. hyp_path_a3f4984b9fa6

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_07.c:87
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标服务并发送特制的DLL路径字符串。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_07.c:92-96; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_07.c:114-118 (approximate)
- 结论: 从网络接收的数据未经充分验证即直接传递给LoadLibraryA函数，导致任意DLL加载，可能被利用执行任意代码。
- D验证: confirmed / ver_45b442f2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 108. hyp_path_e1b37d12fc68

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_09.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标程序监听的TCP端口，并发送任意数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_09.c:81; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_09.c:89; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_09.c:104
- 结论: 函数从网络socket接收数据，并直接作为LoadLibraryA的参数，攻击者可控制加载任意DLL，导致任意代码执行。
- D验证: confirmed / ver_05e643ae
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 109. hyp_path_0ac40f16902d

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_10.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够访问服务端口并发送特制数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_10.c:86; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_10.c:108-112
- 结论: 网络接收的数据直接传递给LoadLibraryA加载动态库，攻击者可控制加载的库路径，导致任意代码执行。
- D验证: confirmed / ver_ae04f516
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 110. hyp_path_f49a538d20c3

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_04.c:88
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够向目标socket发送数据; 目标程序使用LoadLibraryA加载外部库
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_04.c:93-97; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_04.c (recv之后的可执行路径)
- 结论: 网络接收的数据未经验证直接传递给LoadLibraryA，可能导致攻击者加载任意恶意DLL，实现进程控制。
- D验证: confirmed / ver_69a56ea3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 111. hyp_path_c1aeed9ffc6c

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_14.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与服务器建立TCP连接; 攻击者能够发送任意数据到服务器的特定端口
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_14.c:81; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_14.c:108
- 结论: 通过socket接收外部数据并直接作为参数传递给LoadLibraryA，攻击者可以控制加载的DLL路径，实现任意代码执行。
- D验证: confirmed / ver_b36b03eb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 112. hyp_path_4c02717e8460

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_15.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者网络可达，能够向目标地址发送TCP数据。
- 触发路径: service.sin_addr.s_addr = inet_addr(IP_ADDRESS); ... connect(connectSocket, ...) @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_15.c:80-84; recvResult = recv(connectSocket, (char *)(data + dataLen), ...); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_15.c:87-91; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_15.c:109-113
- 结论: 外部控制的字符串直接传递给LoadLibraryA，攻击者可通过网络发送恶意DLL路径，导致任意代码执行。
- D验证: confirmed / ver_e60017ce
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 113. hyp_path_b3c022e01f55

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_13.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标程序发送特制数据（即DLL路径或名称）。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ line 86-90; hModule = LoadLibraryA(data); @ line 122-126 (approximate)
- 结论: 程序通过网络套接字接收外部可控数据，并直接将其作为参数传递给LoadLibraryA函数，导致任意DLL加载。攻击者可利用此漏洞加载恶意库，实现远程代码执行。
- D验证: confirmed / ver_92b9911f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 114. hyp_path_f290fcd96466

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_18.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务，并发送构造的DLL路径字符串
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_18.c:81; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_18.c:108
- 结论: 程序通过socket接收外部数据，并直接作为参数传递给LoadLibraryA，导致攻击者可以加载任意恶意DLL，实现任意代码执行。
- D验证: confirmed / ver_530a3fcb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 115. hyp_path_4b5e318c2da5

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_01.c:79
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到程序的监听端口并发送恶意库路径数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_01.c:79; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_01.c:91
- 结论: 从网络接收数据后直接作为参数调用LoadLibraryW，允许攻击者控制加载的库路径，可能导致任意代码执行。
- D验证: confirmed / ver_1eeee1a5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 116. hyp_path_d34dcf1dfe99

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_16.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与目标进行网络通信，并发送精心构造的DLL路径字符串。
- 触发路径: service.sin_addr.s_addr = inet_addr(IP_ADDRESS); service.sin_port = htons(TCP_PORT); if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR) { break;} @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_16.c:79-83; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break;} @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_16.c:86-90; if (connectSocket != INVALID_SOCKET) { CLOSE_SOCKET(connectSocket); } ... if (connectSocket != INVALID_SOCKET) { hModule = LoadLibraryA(data); if (hModule != NULL) FreeLibrary(hModule); } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_16.c:108-112; if (hModule != NULL) FreeLibrary(hModule); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_16.c:112
- 结论: 程序通过socket接收外部数据，然后使用LoadLibraryA加载该数据作为库名，攻击者可以控制库路径导致加载恶意DLL，实现任意代码执行。
- D验证: confirmed / ver_207ab373
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 117. hyp_path_0f724d2a8faa

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_03.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务; 攻击者能够发送任意数据到接收缓冲区; 目标系统存在LoadLibraryW可被调用的环境
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ CWE114_Process_Control__w32_wchar_t_connect_socket_03.c:86-90; hModule = LoadLibraryW(data); @ CWE114_Process_Control__w32_wchar_t_connect_socket_03.c:108-112
- 结论: 通过网络接收不可信数据并直接作为参数传递给LoadLibraryW，攻击者可加载任意恶意库，实现代码执行。
- D验证: confirmed / ver_a7a76361
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 118. hyp_path_61a7ff1fa968

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_04.c:88
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够控制程序连接的服务器（IP_ADDRESS指向的机器），或能实施中间人攻击，以向socket发送恶意库路径数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_04.c:93; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_04.c:109
- 结论: 通过socket接收外部数据，并直接作为参数传递给LoadLibraryW，导致攻击者可控制加载任意库，属于进程控制漏洞。攻击者需控制程序连接的远程服务器或能实施中间人攻击以发送恶意数据。
- D验证: confirmed / ver_b32687ba
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 119. hyp_path_e31087980413

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_06.c:85
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标服务器的指定端口并发送任意数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_06.c:90; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_06.c:112-116
- 结论: 从网络接收的不可信数据直接用作LoadLibraryW的参数，可能导致加载恶意DLL，造成远程代码执行。
- D验证: confirmed / ver_3c5f2397
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 120. hyp_path_345cf1fc5239

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_07.c:87
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务，并发送特制的DLL路径字符串。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_07.c:92-96; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_07.c:100
- 结论: 从网络接收数据后直接作为LoadLibraryW的参数，攻击者可以控制加载任意DLL，导致任意代码执行。
- D验证: confirmed / ver_946d6806
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 121. hyp_path_d9fac3edf1a3

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_02.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序监听的socket并发送数据，数据内容为恶意库的路径（可包含null终止符以符合宽字符串要求）。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_02.c:86-90; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_02.c:108-112
- 结论: 程序通过recv从网络接收数据并直接作为参数传递给LoadLibraryW，攻击者可以控制加载的库路径，导致任意代码执行。
- D验证: confirmed / ver_b72b8121
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 122. hyp_path_31d071cd7d06

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_09.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标发送任意数据包。; 目标应用程序在Windows环境下运行。; 攻击者能够使目标访问恶意DLL（例如通过SMB共享或将被攻击者控制的路径写入本地文件）。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_09.c:86-90; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_09.c:108-112
- 结论: 网络接收的用户输入直接传递给LoadLibraryW，导致任意库加载，攻击者可加载恶意DLL实现远程代码执行。
- D验证: confirmed / ver_96155f98
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 123. hyp_path_a7589de05ce2

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_10.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务并发送恶意数据
- 触发路径: connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_10.c:72; if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_10.c:79-81; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_10.c:86-90; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_10.c:104
- 结论: 程序从网络socket接收数据，并直接作为参数传递给LoadLibraryW函数，允许攻击者远程加载任意DLL。
- D验证: confirmed / ver_3bd5c0ca
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 124. hyp_path_27b247b9fd8c

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_14.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与目标建立网络连接并发送恶意数据，使data包含恶意DLL路径或名称。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_14.c:81; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_14.c:97
- 结论: 通过网络接收不可信数据并直接用于LoadLibraryW调用，可能导致任意DLL加载，属于CWE-114 Process Control漏洞。
- D验证: confirmed / ver_69c12a19
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 125. hyp_path_bf6504850a83

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_13.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与目标程序建立网络连接并发送恶意负载。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_13.c:86-90; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_13.c:108-112
- 结论: 从网络socket接收的数据直接传递给LoadLibraryW，导致任意库加载漏洞（进程控制）。攻击者可以控制输入数据，加载恶意的DLL，从而执行任意代码。
- D验证: confirmed / ver_5e696d27
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 126. hyp_path_fb3f7418a560

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_05.c:88
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够控制 connectSocket 连接的服务器（固定 IP_ADDRESS 和 TCP_PORT），或进行中间人攻击，以注入恶意宽字符串数据。; 接收到的数据长度不超过缓冲区大小（100个wchar_t），且未进行任何内容校验。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_05.c:93-97; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_05.c:约96行
- 结论: 套接字接收的数据直接作为 LoadLibraryW 的参数，攻击者可通过控制网络输入加载任意库，导致任意代码执行。
- D验证: confirmed / ver_d4c21097
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 127. hyp_path_f676f5f3bc62

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_15.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序的监听端口; 目标程序以管理员或高权限运行，导致加载恶意DLL后权限提升
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_15.c:82; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_15.c:96
- 结论: 程序从socket接收数据后，未经验证直接作为参数传递给LoadLibraryW函数，导致可能加载恶意DLL，造成过程控制漏洞。
- D验证: confirmed / ver_9a3edc39
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 128. hyp_path_b60cc69a2486

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_16.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到程序监听的TCP端口; 攻击者能够发送任意字节作为库路径
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_16.c:86-90; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_16.c:95
- 结论: 通过socket接收外部输入，然后直接作为参数调用LoadLibraryW，攻击者可加载任意DLL，导致任意代码执行。
- D验证: confirmed / ver_fc4d5cf4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 129. hyp_path_70506311954c

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_18.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与目标程序建立 TCP 连接并发送数据
- 触发路径: connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_18.c:72; connect(connectSocket, (struct sockaddr*)&service, sizeof(service)); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_18.c:79-83; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_18.c:86-90; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_18.c:108
- 结论: 攻击者可通过网络连接向目标程序发送恶意数据，数据被 recv 接收后直接传递给 LoadLibraryW 加载为库，导致任意代码执行。
- D验证: confirmed / ver_3495b5ca
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 130. hyp_path_bbde5b2ff50b

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_81a.cpp:95
- 漏洞类型: CWE-114, CWE-20
- CWE: CWE-114; CWE-20
- 风险等级: P1
- 触发条件: 攻击者能够连接到服务监听的TCP端口; 攻击者能够发送任意wchar_t字符串作为库路径
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_81a.cpp:70; listen(listenSocket, 5); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_81a.cpp:81; acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_81a.cpp:81; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_81a.cpp:95; baseObject.action(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_81a.cpp:119
- 结论: 通过网络接收数据作为库加载路径，攻击者可以控制加载任意DLL，导致进程控制漏洞。
- D验证: stage_c_preserved / ver_f048af54
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 131. hyp_path_d0ef78cbd683

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_43.cpp:132
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接并发送数据到程序的socket（默认IP和端口由宏定义，攻击者需知道或能控制）。; 程序未对输入数据进行充分验证或清理，直接作为库路径。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_43.cpp:84-88; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_43.cpp:127-131; if (hModule != NULL) { FreeLibrary(hModule); printLine("Library loaded and freed successfully"); } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_43.cpp:130-134
- 结论: 存在CWE-114过程控制漏洞，攻击者可通过网络向程序发送恶意数据，该数据被用作LoadLibraryA的参数，从而加载任意DLL，可能导致远程代码执行。
- D验证: confirmed / ver_d81bc370
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 132. hyp_path_f5691c59119c

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_43.cpp:144
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到监听socket并发送恶意库路径; 目标系统能够访问攻击者控制的DLL（如通过UNC路径或替换合法DLL）
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_43.cpp:92-95; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_43.cpp:139-140; if (hModule != NULL) { FreeLibrary(hModule); printLine("Library loaded and freed successfully"); } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_43.cpp:142-146
- 结论: 通过recv接收网络数据作为LoadLibraryA的参数，未经验证即可加载任意DLL，导致任意代码执行。
- D验证: confirmed / ver_d6c53817
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 133. hyp_path_42d9304bf5f7

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_43.cpp:132
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接发送任意数据到目标程序监听的端口。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_43.cpp:84-88; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_43.cpp:127-131
- 结论: 程序从网络接收数据作为库名称，并直接调用LoadLibraryW加载该库，攻击者可以控制输入数据，加载任意恶意DLL，导致远程代码执行。
- D验证: confirmed / ver_4d19eb55
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 134. hyp_path_5a541e5d65ab

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_43.cpp:144
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标应用的监听端口; 目标应用未对输入进行充分验证或过滤
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ L92-96; hModule = LoadLibraryW(data); @ L139; if (hModule != NULL) { FreeLibrary(hModule); } @ L142-146
- 结论: 存在不受控制的库加载漏洞，攻击者通过网络连接到监听socket，发送恶意数据作为库路径，经过recv写入data缓冲后，直接作为LoadLibraryW参数加载，可导致任意DLL加载与远程代码执行。
- D验证: confirmed / ver_90b9a8a4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 135. hyp_path_26f02364375a

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_32.c:98
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接目标主机的监听端口（由socket、bind、listen、accept创建）。; 攻击者能够发送构造的恶意dll路径字符串。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_32.c:96-100; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_32.c:122-126
- 结论: 程序通过网络接收数据后，将数据作为路径传递给LoadLibraryA，攻击者可以控制加载的库，实现任意代码执行。
- D验证: confirmed / ver_971625a5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 136. hyp_path_52e981f3d63d

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_33.cpp:83
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序; 目标程序未对接收的路径进行任何校验或限制
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ 83; hModule = LoadLibraryA(data); @ 128
- 结论: 代码从网络接收数据后直接作为参数传递给LoadLibraryA，攻击者可控制加载任意DLL，导致任意代码执行或DLL劫持。
- D验证: confirmed / ver_39fe3e4f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 137. hyp_path_d872a0f73573

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_34.c:86
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够控制网络输入，且目标程序监听了可访问的端口
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_34.c:86; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_34.c:113
- 结论: 外部可控的字符串通过LoadLibraryA加载，可能导致恶意DLL加载（Process Control漏洞）
- D验证: confirmed / ver_11eb8387
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 138. hyp_path_610d0ef8b4ac

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_31.c:79
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: Attacker controls a server that the client connects to, or can perform man-in-the-middle to inject data.; The client successfully connects and receives data without errors.
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_31.c:79; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_31.c:106-110
- 结论: Process control vulnerability: externally-controlled library path loaded via LoadLibraryA. An attacker can send a crafted library path over the network, leading to arbitrary DLL loading.
- D验证: confirmed / ver_75c03086
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 139. hyp_path_286f62bff84b

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_32.c:83
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与目标进行网络通信，并发送任意数据填充接收缓冲区。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_32.c:83; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_32.c:104-106
- 结论: 代码从网络接收数据并直接传递给LoadLibraryA，攻击者可能通过构造恶意的库路径导致加载任意DLL，造成代码执行。
- D验证: confirmed / ver_d7bb0657
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 140. hyp_path_c09fe819bfa5

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_45.c:117
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接发送恶意构造的DLL路径字符串。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_45.c:117; CWE114_Process_Control__w32_char_listen_socket_45_case0Data = data; case0Sink(); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_45.c:68; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_45.c:53
- 结论: 进程控制漏洞：通过套接字接收的输入直接传递给LoadLibraryA，攻击者可以加载任意DLL，导致代码执行。
- D验证: confirmed / ver_401e7108
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 141. hyp_path_5ede9c24caaf

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_81a.cpp:80
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够向服务端监听的TCP端口发起连接并发送网络数据。; 服务端成功接收数据并存储到data缓冲区。; action函数在派生类中实现为LoadLibraryW(data)，且未经验证。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_81a.cpp:87; baseObject.action(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_81a.cpp:110
- 结论: 从网络接收的数据被用作进程控制参数，在派生类实现中会调用LoadLibraryW(data)，攻击者可以通过发送恶意字符串加载任意库，导致代码执行。
- D验证: confirmed / ver_3bc8e458
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 142. hyp_path_0776a4285e0e

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_66a.c:98
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够连接到目标TCP端口; 攻击者能够发送任意字符串payload
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_66a.c:73; acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_66a.c:84; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_66a.c:98; CWE114_Process_Control__w32_char_listen_socket_66b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_66a.c:106 (假设sink调用)
- 结论: 存在CWE-114进程控制漏洞的可能性，但缺少sink函数内部实现代码，无法完全确认数据是否直接传递给危险函数（如LoadLibrary或system）。
- D验证: stage_c_preserved / ver_941aa3cc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 143. hyp_path_ff87d72e7c79

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_67a.c:103
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够连接到目标监听的套接字; 攻击者能够发送构造的恶意数据
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_67a.c:78; acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_67a.c:89; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_67a.c:103; CWE114_Process_Control__w32_char_listen_socket_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_67a.c:127-131
- 结论: 程序通过套接字接收外部数据，并将数据作为参数传递给CWE114_Process_Control__w32_char_listen_socket_67b_case0Sink函数。该sink函数很可能使用数据执行进程控制操作（如加载库或执行命令），而数据来源于网络，攻击者可控制，导致进程控制漏洞。
- D验证: stage_c_preserved / ver_c23af640
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 144. hyp_path_3bfc3a230571

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_68a.c:100
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到目标监听的socket，并发送精心构造的数据（如恶意DLL路径）。
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); bind(listenSocket, ...); listen(listenSocket, LISTEN_BACKLOG); acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_68a.c:75-86; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_68a.c:98-102; CWE114_Process_Control__w32_char_listen_socket_68_case0Data = data; CWE114_Process_Control__w32_char_listen_socket_68b_case0Sink(); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_68a.c:113
- 结论: 通过监听socket接收用户输入，并将数据传递给后续的Process Control sink函数，可能被用于控制程序加载的库路径，导致任意代码执行。但sink函数内部实现未提供，无法完全确认。
- D验证: stage_c_preserved / ver_34c471d8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

## Unconfirmed / Failed Verification

These records are not reported as confirmed vulnerabilities. See `verification.failed.jsonl` for full failure details.

- hyp_path_0da1a6dd4dea | juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_listen_socket_72a.cpp:103 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_0f117b210c75 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_72a.cpp:187 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_231be470f8be | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_74a.cpp:102 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_77cd9a7570da | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_72a.cpp:102 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e2b0d506e3a2 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_72a.cpp:182 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_fdfd2e7e8641 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_74a.cpp:210 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2d729a30fc8a | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_74a.cpp:182 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ae4a73016829 | juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_73a.cpp:88 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_dd9744ab5d42 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_73a.cpp:210 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a34cebba9b9d | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_73a.cpp:102 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6c490c33de62 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_73a.cpp:182 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_75ea850de29e | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_73a.cpp:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b8e2ffe1f74b | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_21.cpp:130 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_df1f3e119a33 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_41.cpp:124 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_781773412d47 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_41.cpp:109 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fd30e68fc05d | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_21.cpp:226 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_e18ba96ac25e | juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_44.c:115 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_a39abd56f967 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_22a.cpp:101 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_485ec266da38 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_51a.cpp:196 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_478a9250b6d8 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_22a.cpp:273 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d18dbcf70ed4 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_22a.cpp:192 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_052402e11a2a | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_51a.cpp:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7b643cb094ed | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_52a.cpp:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f1a3678b2fd8 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_52a.cpp:196 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9bb90940aa6d | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_53a.cpp:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_add21adcb6a6 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_53a.cpp:196 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c7a81a2f6677 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_54a.cpp:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dbdcb8a590e2 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_63a.cpp:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_322ecb5d08e9 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_54a.cpp:196 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cb16b73f7f6b | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_63a.cpp:196 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d3cb3cf7af0d | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_64a.cpp:196 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c51d47370df5 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_64a.cpp:98 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_33cb8cfe4fef | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_22a.cpp:164 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_09104fd76f10 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_22a.cpp:232 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2a925f4a9016 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_51a.cpp:83 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0d8c3bb819cd | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_52a.cpp:83 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d02131ebe1ca | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_53a.cpp:83 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_219759044cd1 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_52a.cpp:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7a33688bf7e2 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_64a.cpp:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_511b8f223101 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_17.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2e2e730ab836 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_17.cpp:187 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_641b87aa13b7 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_82a.cpp:194 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f3f7208adaa4 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_listen_socket_82a.cpp:96 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0b518da37fa6 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_17.cpp:173 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_001212ac8244 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_17.cpp:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4a2f3ac31fa0 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_82a.cpp:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6acaf14249d4 | juliet-api-misuse/testcases/CWE122_Heap_Based_Buffer_Overflow/s01/CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_82a.cpp:166 | NOT_EXPLOITABLE | payload did not satisfy oracle
