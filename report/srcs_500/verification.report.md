# MAGUS Final Vulnerability Report

- generated_at: 2026-05-24T13:53:33Z
- reportable_vulnerabilities: 98
- d_confirmed_vulnerabilities: 75
- stage_c_preserved_vulnerabilities: 23
- failed_verifications: 2
- source_confirmed: /home/lxz/MAGUS/d/memberD_verifier/02_run_with_C/output/verification.jsonl
- source_failed: /home/lxz/MAGUS/d/memberD_verifier/02_run_with_C/output/verification.failed.jsonl

## Confirmed Vulnerabilities

### 1. hyp_path_2d23e3798398

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_73a.cpp:103
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到服务端套接字; 服务端成功接受连接并调用recv; recv接收的数据长度至少为1字节; sink函数中使用了列表中的数据进行进程控制操作（如LoadLibrary）
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_73a.cpp:103; dataList.push_back(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_73a.cpp:106-108; CWE114_Process_Control__w32_char_listen_socket_73::case0Sink(dataList); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_73a.cpp:73 (sink函数调用)
- 结论: 程序通过socket接收外部输入数据，并将数据存储到std::list中传递给sink函数，可能用于LoadLibrary等进程控制操作，攻击者可控制加载的库路径，导致任意代码执行。
- D验证: stage_c_preserved / ver_fb27f0e5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 2. hyp_path_aae05588e6df

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_72a.cpp:88
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接向目标发送任意数据; 目标程序在Windows平台上运行
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_72a.cpp:93-97; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ 同一文件，条件判断后; dataVector.insert(dataVector.end(), 1, data); @ 同一文件，数据插入vector; case0Sink(dataVector); @ 同一文件，调用sink函数（符号：_ZN50CWE114_Process_Control__w32_char_connect_socket_729case0SinkESt6vectorIPcSaIS1_EE）
- 结论: 存在外部可控数据通过网络接收后传递给进程控制sink函数，可能导致CWE114 Process Control漏洞
- D验证: stage_c_preserved / ver_5884cc31
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 3. hyp_path_44a642005829

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_74a.cpp:88
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够连接到目标系统的socket端口并发送数据; 目标系统上的服务使用了该socket接收路径，且启用了进程控制功能
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_74a.cpp:88; dataMap[0] = data; @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_74a.cpp:98; case0Sink(dataMap); // sink函数预期调用进程控制API @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_74a.cpp (via case0Sink)
- 结论: 远程攻击者可以通过网络连接发送恶意数据，这些数据被存储在dataMap中，随后作为参数传递给case0Sink函数，该函数预期调用进程控制API（如LoadLibrary）导致任意代码执行。
- D验证: stage_c_preserved / ver_3b2a70e9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 4. hyp_path_7441589a9244

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_74a.cpp:103
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到服务器的监听端口，并发送特制的字符串数据。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_74a.cpp:103; dataMap[0] = data; @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_74a.cpp:127-131; 基于map中的data调用进程控制API（如LoadLibrary，代码未完全提供但由sink函数名称和CWE-114上下文推断） @ sink函数内部（函数名: _ZN49CWE114_Process_Control__w32_char_listen_socket_749case0SinkESt3mapIiPcSt4lessIiESaISt4pairIKiS1_EEE）
- 结论: 在CWE114_Process_Control测试用例中，从网络接收的数据被存储到map中，并传递给sink函数（_ZN49CWE114_Process_Control__w32_char_listen_socket_749case0SinkESt3mapIiPcSt4lessIiESaISt4pairIKiS1_EEE），该sink函数可能将用户控制的数据用作进程控制（如LoadLibrary），导致任意代码执行或库加载风险。
- D验证: stage_c_preserved / ver_1de58155
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 5. hyp_path_5da6d8de3640

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_72a.cpp:103
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够连接至服务器的socket端口; 攻击者能够发送任意数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_72a.cpp:103; dataVector.insert(dataVector.end(), 1, data); @ 同文件insert调用处（代码片段显示在recv后）; _ZN49CWE114_Process_Control__w32_char_listen_socket_729case0SinkESt6vectorIPcSaIS1_EE(dataVector); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_72a.cpp:sink函数调用
- 结论: 通过网络接收的数据被插入vector并传递给sink函数，存在进程控制漏洞（CWE-114）。具体路径：recv接收数据到栈缓冲区data，然后dataVector.insert(dataVector.end(), 1, data)将data指针插入vector，最后sink函数（如LoadLibrary）使用该指针，可能加载攻击者控制的库。
- D验证: stage_c_preserved / ver_60f5e32e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 6. hyp_path_c6d8bd5b009b

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_12.c:96
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接至目标程序的监听端口，并发送任意数据作为DLL路径
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_12.c:73; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_12.c:96; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_12.c:116
- 结论: 程序通过网络接收数据，并直接作为库名传递给LoadLibraryA，攻击者可以控制加载任意DLL，导致进程控制漏洞。
- D验证: confirmed / ver_6d34499e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 7. hyp_path_679c441293bd

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_12.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够访问目标监听的TCP端口并发送构造的DLL路径字符串
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_12.c:86-90; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_12.c:108
- 结论: 未经验证的外部网络输入直接传递给LoadLibraryA函数，导致攻击者可以加载任意DLL，实现代码执行。
- D验证: confirmed / ver_e44e7131
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 8. hyp_path_f6584c863b2a

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_12.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够控制服务器端，向目标程序发送恶意DLL路径数据（程序作为客户端主动连接服务器）
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_12.c:81; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_12.c:96
- 结论: 程序从网络socket接收数据作为库名，并直接传递给LoadLibraryW，攻击者可以控制加载任意DLL，实现代码执行（程序作为客户端主动连接服务器，攻击者需控制服务器端发送恶意数据）。
- D验证: confirmed / ver_38b51c36
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 9. hyp_path_2e0eb4d18df6

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_73a.cpp:88
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络向目标主机发送任意数据; 目标主机上的该程序监听了端口并接受连接
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_73a.cpp:93-97; dataList.push_back(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_73a.cpp:99（近似）; sink函数调用，推测使用dataList进行进程控制操作 @ sink函数case0Sink内（源码未提供）
- 结论: 该程序从网络socket接收数据并存入列表，随后可能将数据传递给进程控制函数（如LoadLibrary或CreateProcess），攻击者可通过发送恶意数据控制程序加载或执行任意代码，构成CWE-114漏洞。但sink函数具体实现未提供，证据不完整。
- D验证: stage_c_preserved / ver_a00bbf28
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 10. hyp_path_18ab5b90e44b

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_41.c:54
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标发送任意数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_41.c:111-115; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_41.c:52-56
- 结论: 通过网络接收用户输入，并直接将其作为参数传递给LoadLibraryA，导致任意代码执行。
- D验证: confirmed / ver_94fb6766
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 11. hyp_path_d230d1b90d2f

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_54a.c:97
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够向目标主机的监听端口发起TCP连接并发送任意数据; 目标程序未对接收到的数据进行任何安全验证直接传递给进程控制函数
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_54a.c:97; CWE114_Process_Control__w32_char_listen_socket_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_54a.c:107（推测）
- 结论: 程序通过socket接收数据，并将接收到的数据作为参数传递给外部进程控制函数，可能导致远程攻击者通过发送特制数据实现任意代码执行。
- D验证: stage_c_preserved / ver_93fe791c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 12. hyp_path_31223b55f118

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_52a.c:97
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到服务端的监听socket; 攻击者能够发送任意字符串数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_52a.c:97; data[dataLen + recvResult / sizeof(char)] = '\0'; @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_52a.c:105; CWE114_Process_Control__w32_char_listen_socket_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_52a.c:112
- 结论: 存在过程控制漏洞，攻击者通过网络发送的数据被直接用于控制后续加载的库或执行进程的路径，可能导致任意代码执行或权限提升。
- D验证: stage_c_preserved / ver_e560b442
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 13. hyp_path_b4f796666557

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_51a.c:97
- 漏洞类型: CWE-114, CWE-20
- CWE: CWE-114; CWE-20
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到目标监听的socket; 攻击者能够控制发送的数据内容，使其包含恶意DLL路径
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_51a.c:97; CWE114_Process_Control__w32_char_listen_socket_51b_case0Sink(data); @ CWE114_Process_Control__w32_char_listen_socket_51b_case0Sink调用，实际位置未在提供代码中明确，但在51a.c中有调用语句
- 结论: 网络接收的数据经recv读取到缓冲区data后，传递给进程控制相关sink函数CWE114_Process_Control__w32_char_listen_socket_51b_case0Sink，该sink内部可能使用LoadLibrary加载攻击者控制的DLL路径，导致任意DLL加载。虽然sink函数内部代码未提供，但结合CWE114上下文和B阶段high_risk_sink标签，该漏洞路径存在合理可能性。
- D验证: stage_c_preserved / ver_b96e8b5e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 14. hyp_path_6ed688d2826a

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_53a.c:97
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标主机的监听端口; 攻击者能够发送任意数据到该端口; sink函数内部未对输入进行消毒
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_53a.c:97; CWE114_Process_Control__w32_char_listen_socket_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_53a.c（末尾）或53b.c中
- 结论: 通过网络socket接收外部数据，未经充分消毒直接传递给sink函数CWE114_Process_Control__w32_char_listen_socket_53b_case0Sink，可能导致攻击者控制进程执行（如加载恶意库或执行命令）。
- D验证: stage_c_preserved / ver_166ed6fb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 15. hyp_path_9dacfdd0d657

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_63a.c:97
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到监听 socket 并发送特制数据; 接收到的数据长度不超过缓冲区大小（100 字节）; sink 函数将输入数据作为进程名或库路径执行（需验证）
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_63a.c:97; CWE114_Process_Control__w32_char_listen_socket_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_63b.c (文件未提供)
- 结论: 网络接收的数据经由未经验证的 recv 读取后，传递给外部 sink 函数 (CWE114_Process_Control__w32_char_listen_socket_63b_case0Sink)，该 sink 很可能将输入作为进程名或库路径执行，导致任意代码执行。虽然 sink 函数内部实现未提供，但 P0 静态确认支持为 true 表明高风险 sink 类别。
- D验证: stage_c_preserved / ver_4c79abd3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 16. hyp_path_04ebc0ba1f54

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_64a.c:97
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够访问监听端口并建立TCP连接。; sink函数被调用时，data内容被用作外部进程路径或参数。
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); ... bind(listenSocket, ...); listen(listenSocket, 5); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_64a.c:72-76; acceptSocket = accept(listenSocket, NULL, NULL); @ 同上:83; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ 同上:97; data[dataLen + recvResult/sizeof(char)] = '\0'; @ 同上:103; CWE114_Process_Control__w32_char_listen_socket_64b_case0Sink(&data); @ 同上:115
- 结论: 该程序通过socket接收外部输入，并将数据直接传递给CWE114_Process_Control__w32_char_listen_socket_64b_case0Sink函数，攻击者可控制输入导致执行任意进程。
- D验证: stage_c_preserved / ver_cd14e7df
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 17. hyp_path_b682c9dd1827

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_41.c:54
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够访问目标服务的socket端口; 目标服务未对输入进行验证或净化
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_41.c:103-107; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_41.c:45-62
- 结论: 函数通过socket接收外部数据，并将其直接作为参数传递给LoadLibraryA，攻击者可以控制加载的库路径，导致任意DLL加载，可能执行恶意代码。
- D验证: confirmed / ver_07920e88
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 18. hyp_path_db95c8879a85

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_82a.cpp:95
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到目标服务的监听socket，并发送特制的字符串数据。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_82a.cpp:95; baseObject->action(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_82a.cpp:109
- 结论: 从网络socket接收的数据被传入baseObject->action(data)，根据CWE-114测试用例设计，action内部可能直接或间接调用进程控制函数（如LoadLibrary），攻击者可通过控制网络输入指定加载的库或执行的命令，导致进程控制漏洞。
- D验证: stage_c_preserved / ver_7a6f8003
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 19. hyp_path_bc70f6edde08

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_51a.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够与目标服务器的socket建立连接，并发送特制的字符串payload。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_51a.c:82; replace = strchr(data, '\r'); ... *replace = '\0'; replace = strchr(data, '\n'); ... *replace = '\0'; @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_51a.c:100-106; CWE114_Process_Control__w32_char_connect_socket_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_51a.c:112
- 结论: 用户通过socket接收的数据未经过充分验证直接被传递给进程控制函数（如system或LoadLibrary），可能导致远程代码执行或任意代码加载。
- D验证: stage_c_preserved / ver_ab32e738
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 20. hyp_path_380bcffc7c17

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_52a.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务器的指定TCP端口并发送恶意构造的数据。
- 触发路径: 创建套接字并连接到指定IP和端口。 @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_52a.c:73-84; recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0) 从网络接收数据到data缓冲区。 @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_52a.c:82; 调用CWE114_Process_Control__w32_char_connect_socket_52b_case0Sink(data)将接收到的数据传递给sink函数。 @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_52a.c:109-113
- 结论: 通过套接字接收网络数据，并将该数据直接传递给过程控制类的sink函数（CWE114_Process_Control__w32_char_connect_socket_52b_case0Sink），该sink函数会使用接收到的数据执行动态库加载（如LoadLibrary），导致攻击者可能控制动态库加载或命令执行。
- D验证: stage_c_preserved / ver_e88cf523
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 21. hyp_path_f04d2a3ff641

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_53a.c:82
- 漏洞类型: CWE-114, CWE-20
- CWE: CWE-114; CWE-20
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到目标程序的socket（IP和端口固定或可预测）; 攻击者能够发送任意数据payload; sink函数确实执行了进程控制操作（根据函数命名及Juliet测试用例定义，假设为system或LoadLibrary）
- 触发路径: service.sin_addr.s_addr = inet_addr(IP_ADDRESS); service.sin_port = htons(TCP_PORT); if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_53a.c:73-84; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_53a.c:87-91; data[dataLen + recvResult / sizeof(char)] = '\0'; ... replace = strchr(data, '\n'); if (replace) { *replace = '\0'; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_53a.c:93-96; CWE114_Process_Control__w32_char_connect_socket_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_53a.c:98
- 结论: 存在CWE-114过程控制漏洞：从网络socket接收的数据未经充分验证直接传递给进程控制函数，攻击者可以发送恶意数据导致执行任意命令或加载恶意库。
- D验证: stage_c_preserved / ver_0156b265
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 22. hyp_path_4924f046a75b

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_17.c:74
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标主机的监听端口; 攻击者能够发送精心构造的数据作为库名称
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_17.c:83; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_17.c:97; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_17.c:106
- 结论: 代码通过套接字接收外部输入数据，并将其作为参数传递给LoadLibraryA函数，攻击者可以控制加载的库，导致任意代码执行。
- D验证: confirmed / ver_43a3144a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 23. hyp_path_bbe3b914342a

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_63a.c:82
- 漏洞类型: command_injection
- CWE: CWE-114; CWE-78
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到目标服务并发送恶意负载，负载大小不超过缓冲区剩余空间。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_63a.c:87-91; data[dataLen + recvResult / sizeof(char)] = '\0'; ... replace = strchr(data, '\r'); ... replace = strchr(data, '\n'); ... @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_63a.c:99-101; CWE114_Process_Control__w32_char_connect_socket_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_63a.c:103
- 结论: 从网络套接字接收的数据未经过充分验证，直接传递给进程控制函数（CWE114_Process_Control__w32_char_connect_socket_63b_case0Sink），该函数内部很可能调用LoadLibrary或CreateProcess，导致攻击者通过网络发送恶意负载实现代码执行。
- D验证: stage_c_preserved / ver_ab2b7360
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 24. hyp_path_68019ab69a9b

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_64a.c:82
- 漏洞类型: CWE-114, CWE-20
- CWE: CWE-114; CWE-20
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标主机的服务端口; 目标系统运行的进程具有加载库的权限; sink函数内部确实调用LoadLibraryA且无有效过滤
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_64a.c:82; CWE114_Process_Control__w32_char_connect_socket_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_64a.c:109 (sink调用); LoadLibraryA(data); @ CWE114_Process_Control__w32_char_connect_socket_64b_case0Sink (假设内部)
- 结论: 从网络接收的数据通过sink函数传递给LoadLibraryA，导致任意DLL加载，可能实现任意代码执行。
- D验证: confirmed / ver_464f2e7c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 25. hyp_path_6b505a1b7abc

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_54a.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够控制与客户端建立连接的服务器，并发送特制的网络数据以触发漏洞。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_54a.c:82; CWE114_Process_Control__w32_char_connect_socket_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_54a.c:95（推断）
- 结论: 该代码从网络接收数据（通过recv），未进行任何净化或验证便传递给CWE114_Process_Control__w32_char_connect_socket_54b_case0Sink函数，该函数很可能将数据用于进程控制（如system或LoadLibrary），攻击者可利用此漏洞加载任意库或执行恶意代码。
- D验证: stage_c_preserved / ver_dfc8af2d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 26. hyp_path_0b5ab567af73

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_82a.cpp:80
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够连接到目标程序的socket服务并发送数据; 目标程序未对输入数据进行有效的白名单或黑名单过滤; action函数内部使用data作为参数调用库加载API（如LoadLibrary）
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_82a.cpp:80; data[dataLen + recvResult / sizeof(char)] = '\0'; @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_82a.cpp:85-89; baseObject->action(data); // action函数定义在其他文件中，预期调用LoadLibrary @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_82a.cpp:107-111（实际为关闭socket，但action函数调用发生在之前或之后）
- 结论: 存在潜在安全漏洞：攻击者可通过网络向目标程序发送恶意数据，数据随后通过action函数传递，可能被用作动态库加载路径，导致任意代码执行（过程控制漏洞）。但当前代码片段未展示action函数的具体实现，缺乏直接的库加载API调用证据。
- D验证: stage_c_preserved / ver_84dbb3cc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 27. hyp_path_31321ee41d1f

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_01.c:71
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够访问程序监听的网络端口并发送任意数据。
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_01.c:86-90; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_01.c:92-96; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_01.c:114-118
- 结论: 代码从网络socket接收数据，未经验证直接作为参数传递给LoadLibraryA，攻击者可以控制加载任意DLL，导致进程控制漏洞。
- D验证: confirmed / ver_a21cd1e1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 28. hyp_path_9123a6bdc357

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_08.c:87
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序的监听端口; 攻击者能构造并发送一个合法的DLL路径或名称字符串
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_08.c:85-89; acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_08.c:102-106; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_08.c:108-112; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_08.c:130-134
- 结论: 从网络socket接收的数据未经验证直接作为参数传递给LoadLibraryA，导致攻击者可以加载任意DLL，实现远程代码执行。
- D验证: confirmed / ver_be07bb0d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 29. hyp_path_02c35e17633f

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_17.c:73
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够控制目标服务器并向程序发送恶意DLL路径字符串
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_17.c:87-91; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_17.c:128
- 结论: 从socket接收数据后直接作为参数调用LoadLibraryA，攻击者可控制加载任意DLL，导致任意代码执行。
- D验证: confirmed / ver_8cbcc9ec
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 30. hyp_path_80bb54c58712

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_11.c:73
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络访问目标机器的监听端口; 攻击者能够发送特制的DLL名称或路径到该端口
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ L88-92; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ L94-98; hModule = LoadLibraryA(data); @ L116-120
- 结论: 通过socket接收用户输入并直接作为LoadLibraryA的参数，导致进程控制漏洞，允许攻击者加载任意DLL。
- D验证: confirmed / ver_c3d6c88c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 31. hyp_path_7c03e3ea87a0

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_06.c:77
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到服务端并发送特制的payload作为DLL路径
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_06.c:92; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_06.c:98-100; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_06.c:103-104
- 结论: 通过网络接收数据后，未经验证直接作为参数调用LoadLibraryA，攻击者可控制加载任意DLL，导致代码执行。
- D验证: confirmed / ver_e5ea42d5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 32. hyp_path_a2b6e28e6c78

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_05.c:80
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务端并发送任意数据
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_05.c:95; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_05.c:103; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_05.c:111
- 结论: 代码通过套接字接收网络数据，并将数据作为参数直接传递给LoadLibraryA函数，攻击者可以控制加载的DLL，导致任意代码执行。
- D验证: confirmed / ver_3cbd314c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 33. hyp_path_2c24166977cf

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_03.c:73
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向监听socket发送恶意数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_03.c:94; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_03.c:117
- 结论: 代码从网络socket接收数据后，直接作为参数传递给LoadLibraryA，攻击者可以控制加载的DLL路径，导致任意代码执行。
- D验证: confirmed / ver_5bcfc431
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 34. hyp_path_e89197c43099

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_04.c:80
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够访问目标主机的网络端口; 攻击者可以发送恶意构造的DLL路径字符串
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ L78-82; acceptSocket = accept(listenSocket, NULL, NULL); @ L95-99; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ L101-104; hModule = LoadLibraryA(data); @ L123附近（约L124-127）
- 结论: 存在过程控制漏洞：程序通过套接字接收用户数据，并直接将其作为参数传递给LoadLibraryA函数，导致攻击者可以控制加载的库路径，实现任意代码执行。
- D验证: confirmed / ver_358e9ef3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 35. hyp_path_d66c6870626e

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_10.c:73
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到服务器监听的TCP端口并发送任意数据。; 服务器未对接收的数据进行任何消毒或路径验证。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_10.c:94-96; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_10.c:110-113
- 结论: 代码从网络接收数据并直接传递给LoadLibraryA，允许攻击者通过发送恶意DLL路径实现任意代码加载，属于CWE-114 Process Control漏洞。路径可达，无防御检查。
- D验证: confirmed / ver_8d9f54d4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 36. hyp_path_958f5908d47a

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_09.c:73
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务器的指定TCP端口并发送任意数据。
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_09.c:88-92; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_09.c:94-98; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_09.c:116-120
- 结论: 程序通过套接字接收外部数据，并直接作为参数传递给LoadLibraryA加载动态库，未对输入进行任何验证或过滤，攻击者可远程加载任意DLL，导致代码执行。
- D验证: confirmed / ver_22369c0f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 37. hyp_path_e46f94c0a71e

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_07.c:79
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与监听端口建立TCP连接，并发送恶意数据。
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_07.c:94-98; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_07.c:100-104; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_07.c:122-126
- 结论: 程序通过TCP socket接收数据，并将接收到的字符串直接作为参数调用LoadLibraryA加载动态链接库。攻击者可以连接监听端口并发送恶意DLL路径或名称，导致加载任意DLL，实现代码执行。
- D验证: confirmed / ver_e1e2c0ad
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 38. hyp_path_b2c21d5c88c4

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_02.c:73
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接目标程序并发送特制的库名字符串
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_02.c:96; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_02.c:? (LoadLibraryA调用行)
- 结论: 代码从网络socket接收数据到缓冲区data，然后直接使用LoadLibraryA将接收到的数据作为库名加载，存在进程控制漏洞（Process Control）。攻击者可以远程发送恶意的库名，导致加载任意DLL，实现远程代码执行。
- D验证: confirmed / ver_43b4213d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 39. hyp_path_4f87f47af120

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_13.c:73
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够访问目标主机的监听端口; 攻击者能够构造并发送包含恶意库路径的字符串
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_13.c:73; acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_13.c:82; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_13.c:94-96; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_13.c:116
- 结论: 程序从网络接收数据后直接调用LoadLibraryA，攻击者可以控制加载的库路径，导致任意代码执行。
- D验证: confirmed / ver_33ca1ad9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 40. hyp_path_c22bd7c627f3

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_16.c:73
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接至目标主机的监听端口
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ L88; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ L94; hModule = LoadLibraryA(data); @ L114
- 结论: 通过网络接收用户输入，并直接作为LoadLibraryA的参数，导致攻击者可以加载任意DLL，实现代码执行。
- D验证: confirmed / ver_3529be90
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 41. hyp_path_21cee6d0e4f2

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_14.c:73
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标主机的监听端口; 攻击者发送的数据满足recv接收条件，且最终data字符串有效
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_14.c:73; bind(listenSocket, ...); listen(listenSocket, 5); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_14.c:82; acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_14.c:89; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_14.c:95; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_14.c:116
- 结论: 程序使用LoadLibraryA加载从网络接收的字符串，攻击者可以控制加载的DLL路径，导致任意代码执行。
- D验证: confirmed / ver_9d9f7c72
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 42. hyp_path_92158a65c809

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_18.c:73
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与目标服务建立TCP连接; 攻击者能够发送构造的库路径数据（最多99个字符）
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_18.c:82; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_18.c:96; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_18.c:107
- 结论: 代码通过网络接收数据后直接作为参数调用LoadLibraryA，攻击者可以控制加载的库，导致任意DLL加载和执行。
- D验证: confirmed / ver_7570c68a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 43. hyp_path_8caaedaa4bc7

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_17.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标程序的监听端口，并发送特制的DLL路径或名称字符串
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_17.c:82; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_17.c:128
- 结论: 程序从网络socket接收数据后，直接作为参数调用LoadLibraryW，导致攻击者可以控制加载任意DLL，执行任意代码。
- D验证: confirmed / ver_966c79c1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 44. hyp_path_be7d449b2530

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_11.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与目标建立TCP连接; 攻击者可以发送任意字节
- 触发路径: connect(connectSocket, ...) @ 79-83; recvResult = recv(connectSocket, (char *)(data + dataLen), ...); @ 86-90; hModule = LoadLibraryA(data); @ 108-112
- 结论: 通过socket接收外部数据并直接作为LoadLibraryA参数，导致不可信库加载漏洞（CWE-114）
- D验证: confirmed / ver_60efa962
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 45. hyp_path_c39456dd7de5

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_15.c:74
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够访问目标主机的监听端口并发送TCP数据; 目标程序以足够权限运行以加载库
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ 74; bind(listenSocket, ...); listen(listenSocket, 5); @ 83; acceptSocket = accept(listenSocket, NULL, NULL); @ 89; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ 95-99; hModule = LoadLibraryA(data); @ 117-121
- 结论: 程序通过套接字接收外部数据，直接将数据作为参数传入LoadLibraryA函数，导致任意库加载漏洞。攻击者可利用此漏洞加载恶意DLL，执行任意代码。
- D验证: confirmed / ver_2242bf77
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 46. hyp_path_0482415f2ae1

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_08.c:95
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序监听的TCP端口，并发送特制的字符串作为库路径。
- 触发路径: connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ 第86行; service.sin_addr.s_addr = inet_addr(IP_ADDRESS); service.sin_port = htons(TCP_PORT); if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR) @ 第93-95行; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ 第100-104行; hModule = LoadLibraryA(data); @ 第122-126行
- 结论: 该代码通过socket接收外部输入作为库名称，并调用LoadLibraryA加载该库，攻击者可以控制库名称导致加载任意DLL，存在过程控制漏洞。
- D验证: confirmed / ver_54cd1e21
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 47. hyp_path_1edcb9ab0f0b

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_01.c:79
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务，并发送恶意数据到socket。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_01.c:79; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_01.c:91
- 结论: 代码从网络socket接收数据后，未经验证直接作为参数传递给LoadLibraryA，导致攻击者可以加载任意DLL，实现代码执行。
- D验证: confirmed / ver_8ce965dc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 48. hyp_path_6a94b7ced18c

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_02.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标程序发送任意数据
- 触发路径: connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) @ line 79-83; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ line 86-90; hModule = LoadLibraryA(data); @ line 108-112
- 结论: 程序从网络socket接收数据作为动态库名称，然后调用LoadLibraryA加载该库。攻击者可以控制网络输入，指定任意DLL路径，导致任意代码执行。
- D验证: confirmed / ver_fa58294f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 49. hyp_path_afcf74aa2ccf

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_04.c:88
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标程序监听的TCP端口并发送恶意数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ CWE114_Process_Control__w32_char_connect_socket_04.c:93-97; hModule = LoadLibraryA(data); @ CWE114_Process_Control__w32_char_connect_socket_04.c:100-101
- 结论: 程序从网络接收数据后直接作为库名调用LoadLibraryA，攻击者可控制加载任意DLL，导致任意代码执行。
- D验证: confirmed / ver_f158a90e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 50. hyp_path_3b5e1dd1e14e

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_03.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务（假设IP_ADDRESS指向攻击者控制的地址或本地地址可被利用），并发送精心构造的DLL路径字符串
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_03.c:86-90; hModule = LoadLibraryA(data); if (hModule != NULL) { FreeLibrary(hModule); } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_03.c:118-122
- 结论: 程序通过socket接收数据，并将接收到的数据直接作为参数传递给LoadLibraryA函数，导致攻击者可以控制加载任意DLL，实现代码执行。
- D验证: confirmed / ver_5446203f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 51. hyp_path_f38ed0dc389a

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_05.c:88
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标主机的指定端口并发送精心构造的DLL路径数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_05.c:88; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_05.c:115
- 结论: 程序通过socket接收外部输入数据，并将其直接作为参数传递给LoadLibraryA函数，导致攻击者可以控制加载的库路径，从而执行任意代码。
- D验证: confirmed / ver_cfb64e09
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 52. hyp_path_6ba248748349

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_09.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标发送特制数据，且该数据未被充分验证直接用于LoadLibraryA调用。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_09.c:81; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_09.c:108-112
- 结论: 该代码存在不可信数据注入到LoadLibraryA的漏洞，攻击者可通过网络控制加载任意DLL，导致任意代码执行。
- D验证: confirmed / ver_6f502946
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 53. hyp_path_9af1bd87628f

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_06.c:85
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与目标程序建立网络连接并发送特制的DLL路径字符串。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_06.c:85-90; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_06.c:96
- 结论: 存在安全漏洞：通过socket接收数据后直接调用LoadLibraryA加载库，攻击者可控制加载任意DLL，导致进程控制。
- D验证: confirmed / ver_10dfe426
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 54. hyp_path_25f0f0767479

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_07.c:87
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与目标主机建立TCP连接，并发送特定的数据（DLL名称或路径）。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_07.c:87; if (connectSocket != INVALID_SOCKET) { CLOSE_SOCKET(connectSocket); } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_07.c:114-118; hModule = LoadLibraryA(data); if (hModule != NULL) { FreeLibrary(hModule); } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_07.c:120-127
- 结论: 通过网络接收的数据被直接传递给LoadLibraryA，导致可能加载任意DLL，实现远程代码执行。
- D验证: confirmed / ver_c12704df
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 55. hyp_path_c3a4c8ebe75d

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_14.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标程序监听的端口，并发送特制的库名数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_14.c:86; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_14.c:96
- 结论: 程序通过网络接收外部数据，并直接作为参数传递给LoadLibraryA函数，攻击者可控制加载任意库，导致代码执行漏洞。
- D验证: confirmed / ver_75a54112
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 56. hyp_path_38d9f8c96850

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_10.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与受害主机建立TCP连接; 受害主机运行此程序且未对网络输入进行限制
- 触发路径: connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_10.c:72; service.sin_addr.s_addr = inet_addr(IP_ADDRESS); service.sin_port = htons(TCP_PORT); if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_10.c:79-83; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_10.c:86-90; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_10.c:106
- 结论: 程序从网络socket接收数据后，未经验证直接作为LoadLibraryA参数，允许攻击者加载任意DLL，导致任意代码执行。
- D验证: confirmed / ver_96046198
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 57. hyp_path_87e1bc10ad27

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_13.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标socket（IP和端口已知）; 程序未对接收到的数据进行充分验证或过滤; 发送的数据长度不超过100字节（缓冲区大小）
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_13.c:86-90; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_13.c:108
- 结论: 进程控制漏洞：攻击者可通过网络连接向程序发送恶意数据，该数据作为参数传递给LoadLibraryA，导致加载并执行任意DLL，实现远程代码执行。
- D验证: confirmed / ver_1d9a831e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 58. hyp_path_f95f3d8633a2

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_16.c:81
- 漏洞类型: CWE-114, CWE-426
- CWE: CWE-114; CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够建立网络连接并发送恶意payload，使data包含攻击者控制的DLL路径。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_16.c:86-90; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_16.c:96; if (hModule != NULL) { FreeLibrary(hModule); } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_16.c:108-112
- 结论: 程序从网络接收数据，未经充分验证直接作为LoadLibraryA的参数，攻击者可通过控制网络输入加载任意DLL，导致远程代码执行。
- D验证: confirmed / ver_211a16d9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 59. hyp_path_c016f2974737

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_15.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够访问目标主机并建立网络连接; 攻击者能控制发送的数据内容
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_15.c:82; hModule = LoadLibraryA(data); @ 同文件第109-113行附近（实际LoadLibraryA调用行）
- 结论: 该代码存在CWE-114进程控制漏洞，通过recv从网络接收数据后直接作为参数传递给LoadLibraryA，攻击者可以控制加载的DLL路径，从而实现任意代码执行。
- D验证: confirmed / ver_7ffb0457
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 60. hyp_path_3b60c04fae25

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_18.c:81
- 漏洞类型: CWE-114, CWE-73
- CWE: CWE-114; CWE-73
- 风险等级: P0
- 触发条件: 攻击者能够控制服务端连接的远程主机（如通过ARP欺骗或控制IP_ADDRESS指向的主机），发送恶意数据到该服务端; 服务端未对输入进行任何验证或过滤，data直接传递给LoadLibraryA
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_18.c:86; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_18.c:95
- 结论: 存在CWE-114过程控制漏洞：程序通过网络接收数据，并将该数据直接作为参数传递给LoadLibraryA函数，加载攻击者可控的DLL。攻击者可利用此漏洞加载恶意库，实现远程代码执行。
- D验证: confirmed / ver_35766ab6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 61. hyp_path_13b5183f8bdc

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_43.cpp:144
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与监听套接字建立连接并发送数据; 攻击者能够使recv成功接收数据且非错误
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_43.cpp:92-96; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_43.cpp:139-143
- 结论: 程序通过recv从网络接收数据，直接将数据作为路径参数调用LoadLibraryA加载DLL，攻击者可以控制加载的库路径，导致任意代码执行。
- D验证: confirmed / ver_db453f69
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 62. hyp_path_2ea9b37dd5d1

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_43.cpp:132
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够运行一个服务器在目标程序连接的IP地址和端口（TCP_PORT）上，并发送恶意载荷。; 攻击者发送的载荷包含以null结尾的DLL路径，以确保LoadLibraryA正确解析。
- 触发路径: hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_43.cpp:127; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_43.cpp:86
- 结论: 存在Process Control漏洞：攻击者通过控制远程服务器，向目标程序的socket连接发送恶意DLL路径，目标程序通过recv接收并传递给LoadLibraryA，导致DLL被加载，其入口点执行任意代码。尽管加载后立即释放，但DLL入口点已在LoadLibraryA调用时执行，构成代码执行风险。
- D验证: confirmed / ver_3277d47c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 63. hyp_path_857d4b9bdc7e

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_41.c:54
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接向目标发送恶意构造的DLL路径字符串
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_41.c:103-107; CWE114_Process_Control__w32_wchar_t_connect_socket_41_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_41.c:64; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_41.c:45-53
- 结论: 该函数通过socket接收数据，并将接收到的数据直接作为参数传递给LoadLibraryW，攻击者可以控制接收到的数据从而加载任意DLL，导致远程代码执行。
- D验证: confirmed / ver_b14b230f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 64. hyp_path_a1b02df17552

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_81a.cpp:80
- 漏洞类型: CWE-114, CWE-20
- CWE: CWE-114; CWE-20
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接目标服务; 攻击者能够发送特制数据（如DLL路径或命令字符串）
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_81a.cpp:85-89; baseObject.action(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_81a.cpp:108-111
- 结论: 外部可控数据通过recv接收，未经充分验证即传递给进程控制函数action()，可能导致任意库加载或命令执行（CWE-114）。
- D验证: stage_c_preserved / ver_faf38648
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 65. hyp_path_01fdee57d77f

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_65a.c:99
- 漏洞类型: buffer_overflow
- CWE: CWE-121; CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标监听套接字并发送精心构造的载荷
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_65a.c:97-101; HMODULE hModule = LoadLibraryA(data); // 假设存在 @ 推测后续代码
- 结论: 通过监听套接字接收数据并追加到固定大小缓冲区（100字节），若初始数据长度计算错误或之前已填充数据，可能导致栈缓冲区溢出。后续数据可能作为LoadLibraryA的参数，实现任意DLL加载，造成进程控制漏洞。
- D验证: confirmed / ver_de8033a9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 66. hyp_path_0ad1e431e59a

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_51a.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接目标主机的指定TCP端口; 攻击者发送的数据可以被目标程序接收并处理
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_51a.c:82; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; replace = wcschr(data, L'\r'); ... replace = wcschr(data, L'\n'); ... @ 同文件行84-86; CWE114_Process_Control__w32_wchar_t_connect_socket_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_51a.c:89 (sink调用)
- 结论: 网络接收的数据直接传递给进程控制函数，导致攻击者可以控制加载的库路径，执行任意代码。
- D验证: stage_c_preserved / ver_5b6068da
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 67. hyp_path_e7041ae1d936

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_11.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标程序发送自定义数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ srcs_500/sample_path_e7041ae1d936/juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_11.c:81; hModule = LoadLibraryW(data); @ srcs_500/sample_path_e7041ae1d936/juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_11.c:108-112
- 结论: 从网络接收的数据直接作为参数传递给LoadLibraryW函数，导致任意代码加载漏洞。攻击者可以通过控制发送的数据加载恶意库。
- D验证: confirmed / ver_26bde05e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 68. hyp_path_37d3bb87febb

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_08.c:95
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接向服务端发送恶意数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ 第95行附近; hModule = LoadLibraryW(data); @ 第122行附近（根据trace证据）
- 结论: 代码从网络接收数据后直接作为参数调用LoadLibraryW加载DLL，攻击者可通过控制网络数据加载任意DLL，导致代码执行。
- D验证: confirmed / ver_d320bea7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 69. hyp_path_be5dae794de3

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_01.c:79
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标服务端口并发送任意数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_01.c:84-88; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_01.c:102
- 结论: 程序从网络socket接收数据，未经过滤直接作为参数传递给LoadLibraryW，导致攻击者可以控制加载任意DLL，实现远程代码执行。
- D验证: confirmed / ver_783cf211
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 70. hyp_path_0f29cf4b1f0a

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_03.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到服务端（IP地址为常量但模拟中可达）并发送特制的库路径数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_03.c:86-89; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_03.c:107
- 结论: 代码通过socket接收外部输入，并直接作为参数调用LoadLibraryW，攻击者可以控制加载的库，导致任意代码执行。
- D验证: confirmed / ver_8e6dd7b5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 71. hyp_path_a9add5feb670

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_02.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够运行服务器并监听在程序连接的固定IP地址（IP_ADDRESS）和端口（TCP_PORT）上，并发送一个合法的DLL路径字符串（宽字符）
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_02.c:81; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_02.c:108-112
- 结论: 客户端程序通过socket主动连接到外部服务器，接收攻击者控制的DLL路径字符串，未经验证直接传递给LoadLibraryW，导致攻击者可以控制加载任意DLL，造成代码执行。
- D验证: confirmed / ver_67c89f2d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 72. hyp_path_24705e6cfaba

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_04.c:88
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与目标程序建立网络连接; 目标程序使用Windows系统并运行在至少Windows 2000以上版本; 接收的数据包含null终止符（攻击者可控制）
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_04.c:93-97; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_04.c:99-103
- 结论: 程序从网络套接字接收数据，并直接作为参数调用LoadLibraryW，攻击者可控制接收的数据加载任意DLL，导致远程代码执行或权限提升。
- D验证: confirmed / ver_3e1c0ec2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 73. hyp_path_1e5accc7d211

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_05.c:88
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标socket发送任意数据
- 触发路径: connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_05.c:86-90; recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0) @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_05.c:93-97; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_05.c:115-119
- 结论: 通过socket接收不可信数据作为库名，直接调用LoadLibraryW，可能导致加载任意恶意DLL，实现任意代码执行。
- D验证: confirmed / ver_a9f6e82b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 74. hyp_path_f71b3d504cf4

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_09.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者可以访问目标主机的指定TCP端口; 目标主机上存在Winsock环境且能成功建立连接; 攻击者能够发送恶意DLL路径字符串并被recv成功接收
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ CWE114_Process_Control__w32_wchar_t_connect_socket_09.c:81; hModule = LoadLibraryW(data); @ CWE114_Process_Control__w32_wchar_t_connect_socket_09.c:110
- 结论: 从socket接收的数据未经验证直接用作LoadLibraryW的参数，导致攻击者可以加载任意DLL，实现远程代码执行。
- D验证: confirmed / ver_f4c6da63
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 75. hyp_path_f1b2a29790d2

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_07.c:87
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够向目标应用程序的socket发送数据; 目标应用程序的socket配置为接收外部连接
- 触发路径: connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_07.c:85-89; recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0) @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_07.c:92-96; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_07.c:114-118
- 结论: 应用程序从socket接收数据后直接作为参数传递给LoadLibraryW，攻击者可以控制接收的数据从而加载任意库，导致代码执行。
- D验证: confirmed / ver_aa270262
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 76. hyp_path_35da801cd88f

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_06.c:85
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与目标程序建立网络连接; 攻击者能够发送任意数据到目标程序的socket
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ L90-94; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } ... hModule = LoadLibraryW(data); @ L95-100
- 结论: 通过socket接收外部输入，然后直接作为参数调用LoadLibraryW加载动态库，攻击者可控制加载的库路径，导致任意代码执行。
- D验证: confirmed / ver_f14c2088
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 77. hyp_path_7df7e9549f3a

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_13.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与目标建立TCP连接并发送包含恶意DLL名称或路径的数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_13.c:81; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_13.c:113
- 结论: 通过socket接收的外部可控数据直接传递给LoadLibraryW，攻击者可以加载任意DLL，导致进程控制漏洞。
- D验证: confirmed / ver_3603dfad
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 78. hyp_path_c85516419084

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_10.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过socket连接发送恶意构造的wchar_t字符串，该字符串作为DLL路径
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ CWE114_Process_Control__w32_wchar_t_connect_socket_10.c:86; hModule = LoadLibraryW(data); @ CWE114_Process_Control__w32_wchar_t_connect_socket_10.c:108
- 结论: 代码从网络接收数据后直接作为参数传递给LoadLibraryW，未经验证或限制，攻击者可控制加载任意DLL，导致任意代码执行。
- D验证: confirmed / ver_7c6913a4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 79. hyp_path_0951cfc8db49

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_14.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接目标主机; 目标程序运行在Windows平台
- 触发路径: connect(connectSocket, ...) 建立连接 @ 72-83; recv(connectSocket, (char *)(data + dataLen), ...) 接收数据 @ 86-90; hModule = LoadLibraryW(data); 加载外部库 @ 108-112
- 结论: 程序通过socket接收外部数据作为LoadLibraryW的参数，攻击者可加载任意DLL，导致代码执行。
- D验证: confirmed / ver_8c4a226b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 80. hyp_path_75292b3f6728

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_43.cpp:132
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标服务; 服务端使用recv从套接字读取数据并存储到data缓冲区; data被用于LoadLibraryW调用
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ case0Source 函数内 84-88 行; hModule = LoadLibraryW(data); @ 130-134 行; FreeLibrary(hModule); @ 132 行
- 结论: 通过网络接收的攻击者可控数据作为参数传递给LoadLibraryW，可能加载恶意DLL，导致任意代码执行。
- D验证: confirmed / ver_5b1f479e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 81. hyp_path_3793cabc36ca

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_18.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: Attacker can send data to the target socket.; Network connection must be established (connect succeeds).; recv must succeed (no SOCKET_ERROR or connection close).
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_18.c:86-90; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_18.c:108-112
- 结论: The program receives a library name from a socket and passes it directly to LoadLibraryW, allowing an attacker to load a malicious DLL. This is a classic CWE-114 (Process Control) vulnerability.
- D验证: confirmed / ver_02a8b059
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 82. hyp_path_de9ebdd299ec

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_15.c:82
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够访问目标应用程序监听的TCP端口; 攻击者能够构造一个合法的库文件路径（如DLL路径）并通过网络发送
- 触发路径: service.sin_addr.s_addr = inet_addr(IP_ADDRESS); service.sin_port = htons(TCP_PORT); if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_15.c:80-84; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_15.c:87-91; hModule = LoadLibraryW(data); if (hModule != NULL) { FreeLibrary(hModule); } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_15.c:119-123; if (connectSocket != INVALID_SOCKET) { CLOSE_SOCKET(connectSocket); } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_15.c:109-113
- 结论: 程序从网络socket接收数据后，未经任何验证直接作为LoadLibraryW的参数，导致攻击者可通过发送恶意DLL路径加载任意库，属于CWE-114 Process Control漏洞。
- D验证: confirmed / ver_17d1571e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 83. hyp_path_d5af7ee7660e

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_44.c:100
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与目标主机的监听端口建立TCP连接；目标程序未对接收数据做安全检查（如白名单或验证库路径合法性）。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_44.c:105-109; 数据被传递给LoadLibraryW或类似函数（假设存在，因为CWE114案例） @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_44.c:?
- 结论: 进程控制漏洞：程序从网络套接字接收数据，并将该数据用作加载库的路径，攻击者可利用此漏洞加载任意恶意库，导致远程代码执行。
- D验证: confirmed / ver_db2f08f8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 84. hyp_path_82ddd1224712

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_16.c:81
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够访问服务监听的网络端口; 发送的数据能够被完整接收并存储在data变量中
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_16.c:86-90; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_16.c:108-112
- 结论: 应用程序通过套接字接收外部数据，并直接作为参数调用LoadLibraryW加载动态链接库，攻击者可控制加载的库路径，导致任意代码执行。
- D验证: confirmed / ver_53a2e8a1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 85. hyp_path_52f5d765f134

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_34.c:78
- 漏洞类型: CWE-114, CWE-73
- CWE: CWE-114; CWE-73
- 风险等级: P0
- 触发条件: 攻击者能够与目标主机的监听端口建立TCP连接; 目标程序已启动并处于监听状态
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_34.c:76-80; acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_34.c:94-97; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_34.c:99-103; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_34.c:121-125
- 结论: 代码通过socket接收外部数据，然后直接作为参数调用LoadLibraryA加载库，攻击者可控制加载任意DLL，导致进程控制漏洞。
- D验证: confirmed / ver_d69a09a4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 86. hyp_path_bf34d6412f6c

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_32.c:75
- 漏洞类型: CWE-114, CWE-427
- CWE: CWE-114; CWE-427
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序的监听套接字; 攻击者发送的字符串在缓冲区大小限制内（最多100字符）
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ 73-77; acceptSocket = accept(listenSocket, NULL, NULL); @ 90-94; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ 96-100; hModule = LoadLibraryA(data); @ 118-122
- 结论: 程序通过socket接收外部输入数据，然后直接作为LoadLibraryA的参数加载库，攻击者可利用此漏洞加载任意恶意DLL，导致任意代码执行。
- D验证: confirmed / ver_7b7f7d12
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 87. hyp_path_bcb99a8551d2

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_31.c:71
- 漏洞类型: CWE-114, CWE-426
- CWE: CWE-114; CWE-426
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序监听的端口。; 目标程序使用默认或可预测的TCP端口。; 攻击者能够将恶意DLL放置在程序可访问的路径（如当前目录或系统路径）
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ 69-73; acceptSocket = accept(listenSocket, NULL, NULL); @ 80-90; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ 92-96; hModule = LoadLibraryA(data); @ 114-118
- 结论: 存在安全漏洞：通过监听socket接收数据后直接调用LoadLibraryA加载动态库，攻击者可控制库路径加载恶意DLL，导致任意代码执行。
- D验证: confirmed / ver_0ee9e408
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 88. hyp_path_61f871da5d4f

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_34.c:86
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够与目标建立TCP连接并发送构造的库路径字符串。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ L86; hModule = LoadLibraryW(data); @ L114附近
- 结论: 通过socket接收外部数据后直接作为LoadLibraryW参数加载库，攻击者可控制加载任意动态链接库，属于Process Control漏洞。
- D验证: confirmed / ver_dd5d3570
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 89. hyp_path_22dfc36d8dcd

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_33.cpp:75
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标主机的监听端口（TCP_PORT），并发送任意数据作为库路径
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_33.cpp:75; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_33.cpp:96; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_33.cpp:118
- 结论: 存在安全漏洞：程序通过套接字接收外部输入数据，并将其直接作为参数传递给LoadLibraryA函数，攻击者可以控制加载的库路径，导致任意代码执行或DLL劫持。
- D验证: confirmed / ver_a38448b2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 90. hyp_path_70551fdd8386

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_31.c:79
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: Attacker can connect to the target socket (address/port assumed to be reachable).; Attacker sends a crafted payload ending with a null terminator.
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_31.c:79; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_31.c:106-110
- 结论: The program receives a library name via network socket and passes it directly to LoadLibraryA() without validation, allowing an attacker to load an arbitrary DLL, leading to code execution.
- D验证: confirmed / ver_785e5f87
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 91. hyp_path_859f8d574c13

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_33.cpp:83
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够控制目标程序连接的固定IP地址上的服务，或能通过中间人攻击等方式拦截和篡改通信; 攻击者发送的负载为有效的库路径（本地路径或UNC路径）; 系统环境允许加载来自指定路径的库，未实施额外限制（如SafeDllSearchMode）
- 触发路径: 创建socket并连接到固定IP（IP_ADDRESS为宏定义常量） @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_33.cpp:74-81; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_33.cpp:88-92; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_33.cpp:113; if (hModule != NULL) { FreeLibrary(hModule); } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_33.cpp:125-130
- 结论: 程序从网络socket接收数据，并直接作为参数传递给LoadLibraryW函数。尽管连接的目标IP是固定常量（如127.0.0.1），但攻击者若能够控制该IP地址上的服务，即可发送恶意路径到recv，导致任意DLL加载（CWE-114进程控制漏洞）。
- D验证: confirmed / ver_1e06bb0e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 92. hyp_path_321ec068ff85

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_31.c:79
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够控制目标IP_ADDRESS所指向的服务器，或能进行中间人攻击以篡改网络数据。; recv调用成功接收数据且未触发错误检查分支（即recvResult不为SOCKET_ERROR且不为0）。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_31.c:79; hModule = LoadLibraryW(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_wchar_t_connect_socket_31.c:103（推断）; 加载恶意DLL后执行任意代码。 @ （可选）
- 结论: 通过socket接收的数据直接作为LoadLibraryW的参数，攻击者可以控制该数据来加载任意DLL，导致进程控制漏洞。即使目标IP由固定宏定义，攻击者仍可通过控制该IP对应的服务器或进行中间人攻击实现利用。
- D验证: confirmed / ver_d7793f1b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 93. hyp_path_a531ef003d11

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_33.cpp:83
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够建立到目标主机的socket连接并发送数据
- 触发路径: service.sin_addr.s_addr = inet_addr(IP_ADDRESS); service.sin_port = htons(TCP_PORT); if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_33.cpp:74-78; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_33.cpp:88-92; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_33.cpp:109
- 结论: 程序从网络接收数据作为动态库路径加载，攻击者可控制路径导致加载恶意库，存在进程控制漏洞。
- D验证: confirmed / ver_c2b1f93f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 94. hyp_path_02b9cbc8e82c

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_32.c:83
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标程序发送数据（即能够建立socket连接并发送任意内容）; 目标程序能够访问攻击者指定的库文件（如网络共享或本地文件系统）
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_32.c:83; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_32.c:110
- 结论: 代码从网络socket接收数据后直接作为参数调用LoadLibraryA，未进行任何验证或过滤，攻击者可发送恶意库路径导致加载任意库。
- D验证: confirmed / ver_42104a68
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 95. hyp_path_6750009749d8

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_34.c:86
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够向目标主机的指定TCP端口发送数据，并且程序能够成功建立连接并接收数据。; 目标程序运行在Windows平台上，并具有加载DLL的权限。; 攻击者能够将恶意DLL放置在攻击者可控的路径，或者通过网络共享等方式使路径可访问。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_34.c:86; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_34.c:113
- 结论: 代码通过socket接收外部输入，直接作为参数传递给LoadLibraryA加载DLL，攻击者可以控制加载的库路径，实现任意DLL加载，属于CWE-114 Process Control漏洞。
- D验证: confirmed / ver_3c1b2fbe
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 96. hyp_path_732f0f51bd9f

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_45.c:94
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务（任意端口）; 目标服务运行并处于监听状态
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_45.c:94; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_45.c:117; hModule = LoadLibraryA(data); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_45.c:48-66
- 结论: 程序通过套接字接收外部数据，并将数据直接作为LoadLibraryA的参数，攻击者可以控制加载的库路径，导致任意代码执行。
- D验证: confirmed / ver_b22c7680
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 97. hyp_path_20c5ea6bc747

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_66a.c:75
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到监听socket，并发送任意数据。
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_66a.c:90; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ same file:96; CWE114_Process_Control__w32_char_listen_socket_66b_case0Sink(dataArray); @ same file:118-122 (dataArray[2]=data; 调用sink)
- 结论: 程序通过socket接收外部数据，并传递给外部进程控制函数（CWE114_Process_Control__w32_char_listen_socket_66b_case0Sink），该sink函数未提供具体实现，但根据B阶段高sink分数（0.90）及标签（high_risk_sink、memory_sink、network_sink），很可能执行危险的库加载或命令执行。攻击者可控制接收数据导致任意代码执行。
- D验证: stage_c_preserved / ver_7d588c61
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 98. hyp_path_849232d617a8

- 漏洞位置: juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_67a.c:80
- 漏洞类型: CWE-114
- CWE: CWE-114
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到目标主机的监听端口; 攻击者能够发送任意字符串作为攻击载荷; sink函数将用户控制的数据用作库加载路径
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); ... bind(listenSocket, ...); listen(listenSocket, 5); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_67a.c:74-80; acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_67a.c:95-99; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_67a.c:101-105; data[dataLen + recvResult / sizeof(char)] = '\0'; @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_67a.c:108-110; CWE114_Process_Control__w32_char_listen_socket_67b_case0Sink(data); // 该sink可能调用LoadLibrary或类似函数 @ juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_67b_case0Sink (推测调用点)
- 结论: 该代码存在外部控制关键资源漏洞（CWE-114）。攻击者可通过网络连接发送任意字符串，该字符串最终被用作库加载路径，可能导致恶意DLL加载。
- D验证: stage_c_preserved / ver_47dc1c54
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

## Unconfirmed / Failed Verification

These records are not reported as confirmed vulnerabilities. See `verification.failed.jsonl` for full failure details.

- hyp_path_fe155ac0f205 | juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_listen_socket_44.c:115 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_48dadbaf1ab8 | juliet-api-misuse/testcases/CWE114_Process_Control/CWE114_Process_Control__w32_char_connect_socket_44.c:100 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
