# MAGUS Final Vulnerability Report

- generated_at: 2026-05-28T01:46:27Z
- reportable_vulnerabilities: 180
- d_confirmed_vulnerabilities: 28
- stage_c_preserved_vulnerabilities: 152
- failed_verifications: 1032
- source_confirmed: /home/sq_hu/MAGUS/d/memberD_verifier/02_run_with_C/output/CWE319_Cleartext_Tx_Sensitive_Info/verification.jsonl
- source_failed: /home/sq_hu/MAGUS/d/memberD_verifier/02_run_with_C/output/CWE319_Cleartext_Tx_Sensitive_Info/verification.failed.jsonl

## Confirmed Vulnerabilities

### 1. hyp_path_b93d63508ad7

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_41.c:199
- 漏洞类型: CWE-327, CWE-798
- CWE: CWE-327; CWE-798
- 风险等级: P1
- 触发条件: 攻击者能够嗅探网络流量获取十六进制编码的加密数据。
- 触发路径: recvResult = recv(acceptSocket, (char*)(password + passwordLen), ...); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_41.c:307; payloadBytes = decodeHexWChars(payload, sizeof(payload), password); @ case1V2Sink内; CryptHashData(hHash, (BYTE*)hashData, strlen(hashData), 0); // 使用固定的HASH_INPUT @ case1V2Sink内
- 结论: 密码（实际上是加密数据的十六进制编码）通过网络传输后，在解密过程中使用了硬编码的哈希输入（HASH_INPUT），导致密钥可预测，攻击者若捕获网络数据可解密，符合CWE-327（使用有风险的加密算法）和CWE-798（使用硬编码凭证）。
- D验证: stage_c_preserved / ver_6f81df38
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 2. hyp_path_f3a864edc1f5

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_73a.cpp:168
- 漏洞类型: CWE-253, CWE-319
- CWE: CWE-253; CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够发送网络数据导致recv失败或返回0，或通过中断连接触发。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_73a.cpp:173-177; passwordList.push_back(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_73a.cpp:177
- 结论: 在recv失败或返回0时，代码将password（可能未完全接收或无效）加入到密码列表，导致后续处理使用不完整或错误的密码数据，违反正常逻辑。同时密码以明文从网络接收并存储，存在信息泄露风险。
- D验证: stage_c_preserved / ver_24362b56
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 3. hyp_path_84858aed67bb

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_21.c:167
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够嗅探客户端与服务器之间的网络流量
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ line 267-271; case1V21Sink(password); payloadBytes = decodeHexChars(payload, sizeof(payload), password); @ line 165-169
- 结论: 通过未加密的网络连接接收敏感密码，导致明文传输敏感信息，违反CWE-319。
- D验证: stage_c_preserved / ver_4ce85a2a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 4. hyp_path_2756b0c28856

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_21.c:320
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够嗅探服务器与客户端之间的网络流量。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ L420-424 (recv调用); if (recvResult == SOCKET_ERROR || recvResult == 0) { ... case1V22Sink(password); } @ L422-424 (检查recvResult后调用sink); payloadBytes = decodeHexChars(payload, sizeof(payload), password); SecureZeroMemory(password, 100 * sizeof(char)); if(!CryptDecrypt(hKey, 0, 1, 0, payload, &payloadBytes)) @ L318-322 (sink中解码并解密)
- 结论: 敏感信息（密码的加密密文）通过明文TCP连接传输，攻击者可通过网络嗅探获取密文，并可能利用已知加密算法和固定密钥解密得到明文密码。
- D验证: stage_c_preserved / ver_b310eb89
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 5. hyp_path_18d20ce2c4a7

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_07.c:170
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够监听客户端与服务器之间的网络通信（如局域网嗅探或中间人攻击）。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_07.c:175-179
- 结论: 敏感信息（密码）通过明文网络传输，违反CWE-319。尽管代码中存在一个备选解密分支（staticFalse），但staticTrue恒为1，实际执行的是未加密的recv路径，密码以明文形式从网络接收并直接用于LogonUser。
- D验证: stage_c_preserved / ver_06753b87
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 6. hyp_path_596971ec760c

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_05.c:171
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够访问客户端与服务器之间的网络路径。
- 触发路径: if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR) { break; } @ L169-173; recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ L176-180; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ L177-181; if (connectSocket != INVALID_SOCKET) { closesocket(connectSocket); } @ L198-202
- 结论: 在网络上以明文传输敏感密码信息，攻击者可通过网络嗅探获取密码。
- D验证: stage_c_preserved / ver_68afa055
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 7. hyp_path_cfccd91e3d52

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_01.c:190
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够嗅探网络流量，截获明文密码。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ L195-199; payloadBytes = decodeHexChars(payload, sizeof(payload), password); @ L? 解码; if(!CryptDecrypt(hKey, 0, 1, 0, payload, &payloadBytes)) @ L? 解密
- 结论: 敏感密码通过明文网络传输，未加密，违反CWE-319 Cleartext Transmission of Sensitive Information。代码从网络接收密码（敏感数据）后直接使用，未进行加密传输。
- D验证: stage_c_preserved / ver_794c6f0e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 8. hyp_path_97b4d848bd21

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_04.c:171
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够访问TCP网络流量，例如位于同一网络进行嗅探或中间人攻击
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ L176-180; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ L177-181; if (connectSocket != INVALID_SOCKET) { closesocket(connectSocket); } @ L198-202
- 结论: 程序通过TCP套接字以明文方式接收密码等敏感信息，未使用加密传输，违反CWE-319，导致攻击者能够通过嗅探网络流量获取敏感数据。
- D验证: stage_c_preserved / ver_9b84e769
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 9. hyp_path_b03b5c0b08d9

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_18.c:192
- 漏洞类型: CWE-327, CWE-321
- CWE: CWE-327; CWE-321
- 风险等级: P1
- 触发条件: 攻击者能够嗅探网络流量获取十六进制密文; 攻击者能够获取或猜测加密密钥（如硬编码）
- 触发路径: recvResult = recv(acceptSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ L190-194; payloadBytes = decodeHexChars(payload, sizeof(payload), password); @ L238-242; if(!CryptDecrypt(hKey, 0, 1, 0, payload, &payloadBytes)) { break; } @ L? (CryptDecrypt)
- 结论: 网络传输加密数据的十六进制表示（非明文密码），但加密密钥来源不明；若密钥被硬编码或可预测，攻击者可解密获取敏感信息，仍构成CWE-327或CWE-321风险。
- D验证: stage_c_preserved / ver_831c81d9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 10. hyp_path_6fd9942d01e1

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_81a.cpp:79
- 漏洞类型: CWE-253, CWE-252
- CWE: CWE-253; CWE-252
- 风险等级: P0
- 触发条件: 攻击者能够导致accept()失败，例如通过网络中断、资源耗尽或发送大量连接请求使系统拒绝新连接。
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ L64; if (acceptSocket == SOCKET_ERROR) @ L64; recvResult = recv(acceptSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ L79
- 结论: 在accept()返回SOCKET_ERROR后，程序未退出或跳过后续操作，而是直接使用无效的acceptSocket调用recv()，导致未定义行为或崩溃，违反了API契约。
- D验证: stage_c_preserved / ver_6a19683a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 11. hyp_path_9a975f21bef5

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_21.c:167
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够嗅探网络流量或处于中间人位置; case1V21Static 为假（即非 benign 分支，默认配置下成立）
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_21.c:267-271; case1V21(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_21.c:233; payloadBytes = decodeHexWChars(payload, sizeof(payload), password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_21.c:165-169
- 结论: 密码以明文形式从网络接收（十六进制编码但未加密），可被中间人窃听，导致敏感信息泄露。代码通过 recv() 直接读取 wchar_t 类型密码，并在 case1V21Sink 中解码后用于解密操作，传输过程未加密，违反 CWE-319。
- D验证: stage_c_preserved / ver_bed7b6e3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 12. hyp_path_444100eb7be5

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_21.c:320
- 漏洞类型: CWE-319, CWE-253
- CWE: CWE-319; CWE-253
- 风险等级: P1
- 触发条件: 攻击者能够控制TCP连接（例如中间人）或嗅探网络流量。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ L420-L424; if (connectSocket != INVALID_SOCKET) { closesocket(connectSocket); } @ L440-L444; 注意：存在trace显示recv失败后调用case1V22Sink(password)，而非break，与guard矛盾。 @ L420-L424 + 后续; payloadBytes = decodeHexWChars(payload, sizeof(payload), password); SecureZeroMemory(password, 100 * sizeof(wchar_t)); @ L318-L322; CryptDecrypt(hKey, 0, 1, 0, payload, &payloadBytes) @ L442-L446
- 结论: 敏感数据（密码）通过未加密的TCP连接明文传输，违反CWE-319。此外，在recv()失败时存在可能调用case1V22Sink使用未初始化密码的路径，但guard代码（break）与trace存在矛盾，需进一步确认。
- D验证: stage_c_preserved / ver_abd342d1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 13. hyp_path_3257871bf4e7

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_43.cpp:323
- 漏洞类型: CWE-253, CWE-457
- CWE: CWE-253; CWE-457
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接并发送任意数据，使得recv返回正数
- 触发路径: recvResult = recv(acceptSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ case1V2Source函数内接收数据; if (recvResult == SOCKET_ERROR || recvResult == 0) payloadBytes = decodeHexWChars(payload, sizeof(payload), password); @ 错误的条件判断; if(!CryptDecrypt(hKey, 0, 1, 0, payload, &payloadBytes)) @ 使用未初始化的payload
- 结论: 在recv成功返回正数时，由于条件判断错误（仅当recvResult为SOCKET_ERROR或0时才解码），decodeHexWChars未执行，导致payload缓冲区未初始化，随后CryptDecrypt使用未初始化的payload，可能造成程序崩溃或信息泄露。同时，网络传输的敏感信息（密码）以明文形式接收，存在CWE-319风险，但核心漏洞为未初始化变量使用。
- D验证: stage_c_preserved / ver_ff57ea7c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 14. hyp_path_601606ea08b7

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_08.c:333
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够监听网络流量（如中间人攻击）
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ L338; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } // 成功则继续，未检测明文传输 @ L339; /* 密码随后用于LogonUser（注释提及），未加密存储或传输 */ @ L360-364
- 结论: 密码通过网络明文传输，攻击者可嗅探获取敏感凭据。
- D验证: stage_c_preserved / ver_66fc6b77
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 15. hyp_path_970dc4c1f675

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_14.c:165
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够嗅探或中间人攻击网络流量。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_14.c:170
- 结论: 程序通过未加密的套接字接收敏感密码数据，导致敏感信息明文传输。攻击者可监听网络获取密码。
- D验证: stage_c_preserved / ver_c9555c12
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 16. hyp_path_2ada47bbb60c

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_32.c:212
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够访问客户端与服务器之间的网络路径
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ L212; /* Use the password in LogonUser() to establish that it is "sensitive" */ @ L263+（LogonUser调用处）
- 结论: 程序使用明文TCP连接接收敏感密码，攻击者可通过网络嗅探获取密码，违反CWE-319（敏感信息明文传输）。
- D验证: stage_c_preserved / ver_afb57608
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 17. hyp_path_f0bf5374d772

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_72a.cpp:111
- 漏洞类型: CWE-259, CWE-319
- CWE: CWE-259; CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够访问网络流量或获得程序内存访问权限
- 触发路径: strcpy(password, "Password1234!"); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_72a.cpp:125-126; passwordVector.insert(passwordVector.end(), 1, password); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_72a.cpp:128-129; case1V1Sink(passwordVector); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_72a.cpp:131-132
- 结论: 硬编码密码（CWE-259）且可能通过明文传输（CWE-319），攻击者可通过中间人攻击或本地访问获取密码。
- D验证: stage_c_preserved / ver_0b937dab
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 18. hyp_path_47385ec5914f

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_72a.cpp:111
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够读取进程内存
- 触发路径: strcpy(password, "Password1234!"); passwordVector.insert(passwordVector.end(), 1, password); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_72a.cpp:138-142; case1V1Sink(passwordVector); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_72a.cpp:145
- 结论: 存在硬编码密码（CWE-259），但注释明确密码未通过网络发送，因此CWE-319不可达。硬编码密码可能通过本地内存泄露，影响较低。
- D验证: stage_c_preserved / ver_bb6a6f6b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 19. hyp_path_95a0f63f30d7

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_73a.cpp:443
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者无法直接控制密码内容，硬编码密码可能被逆向工程获取
- 触发路径: strcpy(password, "Password1234!"); passwordList.push_back(password); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_73a.cpp:138-142; passwordList.push_back(password); case1V1Sink(passwordList); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_73a.cpp:144
- 结论: 硬编码密码存储在列表中，但未通过网络发送；仅存在CWE-259硬编码密码漏洞，CWE-319证据不完整。
- D验证: stage_c_preserved / ver_914e9b5d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 20. hyp_path_e58d63842afa

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_72a.cpp:111
- 漏洞类型: CWE-259, CWE-319
- CWE: CWE-259; CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够观察到网络流量（若sink确实发送数据且未加密）。
- 触发路径: wcscpy(password, L"Password1234!"); passwordVector.insert(passwordVector.end(), 1, password); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_72a.cpp:138-142; case1V1Sink(passwordVector); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_72a.cpp:144-148
- 结论: 硬编码密码（CWE-259）通过vector传递给case1V1Sink，但sink函数实现未知，无法确认是否通过网络明文传输（CWE-319）。
- D验证: stage_c_preserved / ver_dd5f8067
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 21. hyp_path_2beb716a4875

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_73a.cpp:443
- 漏洞类型: CWE-259, CWE-319
- CWE: CWE-259; CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够监听网络流量（如果sink函数通过网络明文发送密码）；硬编码密码的存在使攻击者无需网络即可直接获取密码（CWE-259）。
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_73a.cpp:126; passwordList.push_back(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_73a.cpp:132; case1V1Sink(passwordList); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_73a.cpp:133
- 结论: 敏感信息（密码）以硬编码形式存储在列表中，并传递给sink函数，存在硬编码密码漏洞（CWE-259）。由于sink函数实现未提供，无法确认是否通过网络明文传输，但结合CWE319样本名称，明文传输风险较高（CWE-319），需验证sink函数行为。
- D验证: stage_c_preserved / ver_5cad09a5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 22. hyp_path_d8ddfaeb5044

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_72a.cpp:111
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够获取源代码或内存中的硬编码密码。
- 触发路径: wcscpy(password, L"Password1234!"); passwordVector.insert(passwordVector.end(), 1, password); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_72a.cpp:125-129; passwordVector.insert(passwordVector.end(), 1, password); case1V1Sink(passwordVector); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_72a.cpp:131-135
- 结论: 存在硬编码密码漏洞（CWE-259），但明文传输路径（CWE-319）因代码注释明确说明密码未通过网络发送，且sink函数实现未提供而证据不完整。
- D验证: stage_c_preserved / ver_3ec8c4c6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 23. hyp_path_8aeacc942ce5

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_73a.cpp:443
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够获取二进制文件以提取硬编码密码
- 触发路径: wcscpy(password, L"Password1234!"); passwordList.push_back(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_73a.cpp:138-142; passwordList.push_back(password); case1V1Sink(passwordList); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_73a.cpp:144-148
- 结论: 硬编码密码（CWE-259）存在于password变量中，但缺少sink函数case1V1Sink的实现，无法确认是否通过明文网络传输（CWE-319），因此仅确认CWE-259漏洞，CWE-319证据不足。
- D验证: stage_c_preserved / ver_bb18c0ae
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 24. hyp_path_4e2d890e8554

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_74a.cpp:464
- 漏洞类型: CWE-259, CWE-319
- CWE: CWE-259; CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够监听网络流量或访问通信信道，从而截获明文传输的密码。
- 触发路径: wcscpy(password, L"Password1234!"); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_74a.cpp:126; passwordMap[0] = password; ... passwordMap[2] = password; @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_74a.cpp:128-134; case1V1Sink(passwordMap); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_74a.cpp:135
- 结论: 硬编码密码存在于源代码中（CWE-259），且通过map传递给sink函数（case1V1Sink），该sink函数名称包含"connect_socket"且被B阶段标记为high_risk_sink，结合CWE319用例名，密码可能通过明文网络传输，导致敏感信息泄露。
- D验证: stage_c_preserved / ver_09b72ba8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 25. hyp_path_5c89ce91d936

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_74a.cpp:464
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问程序运行时的内存或通过逆向工程获取硬编码字符串
- 触发路径: void case1V1() { ... } @ case1V1函数入口 (L119); strcpy(password, "Password1234!"); @ strcpy硬编码密码 (L125-129); passwordMap[0] = password; ... case1V1Sink(passwordMap); @ 密码存入map并调用sink (L131-135)
- 结论: 存在硬编码密码（CWE-259）
- D验证: stage_c_preserved / ver_01ae93d5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 26. hyp_path_68f221198b5c

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_74a.cpp:464
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够获取二进制文件或进行内存读取，以提取硬编码密码
- 触发路径: wcscpy(password, L"Password1234!"); passwordMap[0] = password; @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_74a.cpp:138-142; passwordMap[2] = password; case1V1Sink(passwordMap); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_74a.cpp:144-148
- 结论: 硬编码密码（CWE-259）储存在map并传递给sink函数，虽然注释表明未通过网络发送，但硬编码密码本身构成安全漏洞，可能被本地攻击者利用。
- D验证: stage_c_preserved / ver_483e01f6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 27. hyp_path_1875c41c40ab

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_74a.cpp:464
- 漏洞类型: CWE-259, CWE-319
- CWE: CWE-259; CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够获取到map内容或截获case1V1Sink发送的数据（如果发送）
- 触发路径: strcpy(password, "Password1234!"); /* Put password in a map */ passwordMap[0] = password; @ L138-142 in CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_74a.cpp; passwordMap[2] = password; case1V1Sink(passwordMap); @ L144-148 in same file; unknown @ case1V1Sink implementation (not provided)
- 结论: 在CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_74a.cpp的case1V1路径中，硬编码密码('Password1234!')被strcpy复制并放入map后传递给case1V1Sink，存在硬编码密码漏洞(CWE-259)。由于case1V1Sink实现未提供，无法验证是否会通过不安全的网络发送，因此CWE-319路径不确定。
- D验证: stage_c_preserved / ver_407dce32
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 28. hyp_path_5a7db8ee850f

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22a.c:267
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 无外部输入依赖，代码路径自动执行
- 触发路径: strcpy(password, "Password1234!"); @ L267; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22_case1V1Sink(password); @ L269
- 结论: 存在硬编码密码漏洞（CWE-259），但无证据表明密码通过明文网络传输（CWE-319），因为注释明确说明密码未通过网络发送。
- D验证: stage_c_preserved / ver_b2f0070d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 29. hyp_path_21669c30c3eb

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_52a.c:119
- 漏洞类型: CWE-319, CWE-259
- CWE: CWE-319; CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够监听网络流量
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_52a.c:119; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_52b_case1V1Sink(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_52a.c:120
- 结论: 硬编码密码（CWE-259）通过sink函数传递，sink函数名称暗示明文传输敏感信息（CWE-319），但sink具体实现未提供，路径未完全闭合。
- D验证: stage_c_preserved / ver_00396540
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 30. hyp_path_ef775f93b3fb

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54a.c:119
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者需要能够读取进程内存或获取二进制文件以提取硬编码密码。
- 触发路径: strcpy(password, "Password1234!"); @ L119; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54b_case1V1Sink(password); @ L120
- 结论: 硬编码密码 'Password1234!' 存在于代码中，违反 CWE-259，但注释表明密码未通过网络发送，CWE-319 路径不成立。该硬编码密码可能被本地攻击者通过内存读取或二进制分析获取，影响较低。
- D验证: stage_c_preserved / ver_0605d367
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 31. hyp_path_a5c8d527aa28

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_53a.c:119
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问代码或二进制文件（获取硬编码密码）
- 触发路径: strcpy(password, "Password1234!"); @ L119; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_53b_case1V1Sink(password); @ L120
- 结论: 硬编码密码 'Password1234!' 通过 strcpy 赋值，构成 CWE-259 硬编码密码漏洞，但注释表明该密码未通过网络发送，因此不存在 CWE-319 明文传输路径。
- D验证: stage_c_preserved / ver_bc2c9b75
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 32. hyp_path_92f647715c9c

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_22a.c:306
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者需能访问sink函数实际发送数据的网络通道（sink实现未知）
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_22a.c:306; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_22_case1V1Sink(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_22a.c:308
- 结论: 硬编码密码（CWE-259）存在，但CWE-319路径不完整，sink函数内部未确认，无法断定明文传输。
- D验证: stage_c_preserved / ver_24441b9b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 33. hyp_path_9e8a26055009

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_51a.c:119
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够获取源代码（如通过源码泄露）
- 触发路径: strcpy(password, "Password1234!"); @ L119
- 结论: 硬编码密码（CWE-259）存在于代码中，但注释表明未通过网络发送，因此CWE-319不成立；硬编码密码本身是安全缺陷，虽影响较低但仍需修复。
- D验证: stage_c_preserved / ver_b81a94cc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 34. hyp_path_062571bc7dd4

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52a.c:132
- 漏洞类型: CWE-259, CWE-319
- CWE: CWE-259; CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够监听到网络通信或访问到内存中的密码明文; sink函数实际将密码通过未加密通道发送
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52a.c:132; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52b_case1V1Sink(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52a.c:133
- 结论: 代码使用硬编码密码（"Password1234!"）并通过sink函数传递，敏感信息以明文形式传输，违反了CWE-259和CWE-319。
- D验证: stage_c_preserved / ver_890a3fbe
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 35. hyp_path_f903f645e426

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_64a.c:132
- 漏洞类型: CWE-259, CWE-321
- CWE: CWE-259; CWE-321
- 风险等级: P1
- 触发条件: 攻击者能够访问二进制文件或具有调试权限。
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_64a.c:132
- 结论: 硬编码密码漏洞：代码中使用了硬编码的密码'Password1234!'，违反了CWE-259（硬编码密码）要求。攻击者可能通过逆向工程或读取二进制文件获取该密码，从而获得未授权访问。
- D验证: stage_c_preserved / ver_394cb746
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 36. hyp_path_bd855b5528e5

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_63a.c:119
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够监听网络通信（如中间人攻击），且sink函数确实通过网络明文发送密码
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_63a.c:119; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_63b_case1V1Sink(&password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_63a.c:120
- 结论: 代码包含硬编码密码（CWE-259），但明文传输（CWE-319）路径因sink函数内部实现未提供而未经证实，需要动态验证或查看sink代码以闭合证据链。
- D验证: stage_c_preserved / ver_fd0abfaa
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 37. hyp_path_9f49d93d5229

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_51a.c:132
- 漏洞类型: CWE-259, CWE-319
- CWE: CWE-259; CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够监听到网络通信（例如通过中间人攻击）
- 触发路径: strcpy(password, "Password1234!"); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_51a.c:132; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_51b_case1V1Sink(password); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_51a.c:133
- 结论: 硬编码密码直接传递给名为CWE319_Cleartext_Tx_Sensitive_Info的sink函数，该函数名称暗示明文传输敏感信息，可能导致密码以明文形式通过网络发送，违反CWE-259和CWE-319。
- D验证: stage_c_preserved / ver_962497bb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 38. hyp_path_61f6db539a0c

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_63a.c:132
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够读取进程内存或访问硬编码值（如通过逆向或本地访问）
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_63a.c:132; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_63b_case1V1Sink(&password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_63a.c:133
- 结论: 函数使用硬编码密码'Password1234!'，违反了CWE-259（硬编码密码），尽管注释表明密码未通过网络发送，但硬编码密码本身是安全弱点，可能被本地攻击者获得或通过其他路径泄露。
- D验证: stage_c_preserved / ver_fc1609fc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 39. hyp_path_f2b6e48a3aa4

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53a.c:132
- 漏洞类型: CWE-319, CWE-259
- CWE: CWE-319; CWE-259
- 风险等级: P1
- 触发条件: 函数被调用时，硬编码密码以明文形式传递到sink函数。
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53a.c:132; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53b_case1V1Sink(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53a.c:133
- 结论: 硬编码密码通过sink函数明文传输，违反CWE-259和CWE-319，但sink函数实际行为未静态确认，需动态验证。
- D验证: stage_c_preserved / ver_d1195668
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 40. hyp_path_eca4a1f5bdf3

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_51a.c:119
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够监控网络通信（前提是sink函数确实发送数据）
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_51a.c:119; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_51b_case1V1Sink(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_51a.c:120
- 结论: 代码中使用了硬编码密码（L"Password1234!"），并将其传递给sink函数。硬编码密码违反CWE-259。但sink函数内部实现未知，无法确认是否通过明文网络传输，因此CWE-319的证据不完整。
- D验证: stage_c_preserved / ver_c732a61e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 41. hyp_path_a53534f5287f

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52a.c:119
- 漏洞类型: CWE-259, CWE-319
- CWE: CWE-259; CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够监听网络流量（仅当sink内部有明文网络发送）
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52a.c:119; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52b_case1V1Sink(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52a.c:120
- 结论: 硬编码密码（CWE-259）存在，但sink函数内部实现未知，无法确认明文网络传输（CWE-319）。保留硬编码密码漏洞，CWE-319需动态验证。
- D验证: stage_c_preserved / ver_d14a7906
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 42. hyp_path_12e9a9a5c7a3

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54a.c:119
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够读取程序内存或二进制文件，或通过其他侧信道获取硬编码值。
- 触发路径: wcscpy(password, L"Password1234!"); @ L119; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54b_case1V1Sink(password); @ L120
- 结论: 代码中存在硬编码密码，违反CWE-259，但注释明确说明该密码未通过网络发送，因此CWE-319的触发路径证据不足。硬编码密码本身构成安全风险，但需进一步验证sink函数内部行为以确认是否在本地其他上下文中暴露。
- D验证: stage_c_preserved / ver_ceac61a1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 43. hyp_path_28f84fb1e919

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_22a.c:267
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 函数被调用，且sink函数实现可能在其他分支进行网络传输
- 触发路径: wcscpy(password, L"Password1234!"); @ L267; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_22_case1V1Global = 1; @ L268; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_22_case1V1Sink(password); // 但注释指明此分支未网络传输 @ L269
- 结论: 代码中存在硬编码密码（CWE-259），但注释表明此分支不通过网络传输，因此不构成CWE-319。硬编码密码本身是弱点，但当前路径下无法直接用于信息泄露，需要进一步验证sink函数行为是否存在其他传输分支。
- D验证: stage_c_preserved / ver_6cc20c40
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 44. hyp_path_c39e99d3e030

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_64a.c:119
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者需要访问源代码或二进制以提取硬编码密码。
- 触发路径: wcscpy(password, L"Password1234!"); @ L119
- 结论: 硬编码密码（CWE-259），但代码注释表明未通过网络传输，因此不涉及CWE-319明文传输敏感信息。
- D验证: stage_c_preserved / ver_06c55729
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 45. hyp_path_af8818887b91

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_63a.c:119
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者需要能够访问密码存储位置或后续使用路径，但当前代码未显示网络传输。
- 触发路径: wcscpy(password, L"Password1234!"); @ L119; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_63b_case1V1Sink(&password); @ L120
- 结论: 硬编码密码（CWE-259）被赋值并通过sink函数传递，但根据注释密码未通过网络发送，因此CWE-319路径不成立；硬编码密码本身仍是弱点，但可利用性取决于下游使用方式。
- D验证: stage_c_preserved / ver_31a6caa0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 46. hyp_path_1eeee23f1c7e

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_54a.c:132
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够读取内存或通过其他方式获取硬编码凭据（如调试、进程转储）
- 触发路径: strcpy(password, "Password1234!"); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_54a.c:132
- 结论: 代码中存在硬编码密码（"Password1234!"），违反CWE-259，尽管注释表明该密码未通过网络发送，但硬编码密码本身构成安全风险，可能被通过其他方式泄露（如内存 dump）。
- D验证: stage_c_preserved / ver_9d354781
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 47. hyp_path_68797f32f29e

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_53a.c:119
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够获取二进制文件以提取硬编码密码
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_53a.c:119; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_53b_case1V1Sink(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_53a.c:120
- 结论: 硬编码密码（CWE-259）被传递给sink函数，但注释表明密码未通过网络传输，因此CWE-319路径不成立。仅保留CWE-259硬编码密码漏洞，但可利用性较低（需攻击者获取二进制文件）。
- D验证: stage_c_preserved / ver_f3f11c28
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 48. hyp_path_1507b9b62741

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_51a.c:132
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 本地攻击者能够读取进程内存或通过其他方式获取硬编码密码。
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_51a.c:132
- 结论: 硬编码密码（CWE-259）存在，但注释明确声明该密码未通过网络发送，因此CWE-319路径不成立。硬编码密码本身可能被本地攻击者通过内存读取等方式获取，但缺乏明确的泄露路径，需要进一步分析sink函数实现是否将密码暴露给本地攻击者。
- D验证: stage_c_preserved / ver_d5360e80
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 49. hyp_path_f58208c82ac7

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_22a.c:306
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够获取二进制代码或内存中的硬编码密码字符串。
- 触发路径: wcscpy(password, L"Password1234!"); CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_22_case1V1Global = 1; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_22_case1V1Sink(password); @ L304-L308
- 结论: 存在硬编码密码（CWE-259），但明文传输（CWE-319）证据不足，注释表明密码未通过网络发送，需动态验证sink函数行为。
- D验证: stage_c_preserved / ver_e82832d4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 50. hyp_path_a8e5bb7cc48b

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54a.c:132
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问包含硬编码密码的二进制文件（如通过逆向工程或本地访问）。
- 触发路径: wcscpy(password, L"Password1234!"); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54a.c:132
- 结论: 代码中存在硬编码密码 (L"Password1234!")，违反CWE-259（硬编码密码）。该密码虽然注释说明未通过网络发送，但硬编码密码本身构成安全风险，攻击者可通过逆向工程获取。CWE-319（明文传输敏感信息）路径因缺乏网络传输证据未闭合。
- D验证: stage_c_preserved / ver_88529515
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 51. hyp_path_d0f7a29716a0

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_64a.c:132
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够本地访问内存或反编译二进制文件
- 触发路径: wcscpy(password, L"Password1234!"); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_64a.c:132; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_64b_case1V1Sink(&password); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_64a.c:133
- 结论: 函数中使用了硬编码密码（CWE-259），但未在网络中传输，因此CWE-319不成立。
- D验证: stage_c_preserved / ver_ccf91c26
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 52. hyp_path_3cefeb505bc6

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_52a.c:132
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够获取二进制或源代码，但无法直接通过网络利用此硬编码密码。
- 触发路径: wcscpy(password, L"Password1234!"); @ 行132; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_52b_case1V1Sink(password); @ 行133
- 结论: 硬编码密码存在于password缓冲区，违反CWE-259。但注释表明该密码未通过网络发送，且sink函数风险评分为0，因此CWE-319明文传输路径不成立。
- D验证: stage_c_preserved / ver_da18e387
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 53. hyp_path_aa40f18c5fbe

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_63a.c:132
- 漏洞类型: CWE-259, CWE-319
- CWE: CWE-259; CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够访问二进制文件或通过逆向工程获取硬编码密码，或通过网络嗅探获取sink函数发送的明文密码。
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_63a.c:132; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_63b_case1V1Sink(&password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_63a.c:133
- 结论: 硬编码密码被传递给明文传输敏感信息的sink函数，导致敏感信息明文传输漏洞（CWE-259和CWE-319）。
- D验证: stage_c_preserved / ver_621d4dd3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 54. hyp_path_d888a8c0793d

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53a.c:132
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够通过逆向工程或代码审计获取硬编码密码。
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53a.c:132; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53b_case1V1Sink(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53a.c:133
- 结论: 代码中存在硬编码密码（CWE-259），密码'Password1234!'通过wcscpy赋值并传递给sink函数；但缺乏sink函数内部实现，无法确认该密码是否以明文形式传输（CWE-319），且注释表明该密码并非通过网络获取，因此CWE-319的证据不完整。
- D验证: stage_c_preserved / ver_ed62c9d4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 55. hyp_path_1c04985f042b

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_82a.cpp:129
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够通过代码审计或逆向工程获取硬编码密码
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_82a.cpp:129
- 结论: 硬编码密码'Password1234!'存在于代码中，但注释明确说明密码未通过网络发送，因此不存在CWE-319明文传输敏感信息漏洞。但仍存在CWE-259硬编码密码漏洞，密码可能被用于其他安全敏感操作。
- D验证: stage_c_preserved / ver_484d48e4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 56. hyp_path_cae0f811594e

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_82a.cpp:116
- 漏洞类型: CWE-259, CWE-319
- CWE: CWE-259; CWE-319
- 风险等级: P1
- 触发条件: 硬编码密码存在于代码中; action函数可能使用密码进行网络发送（待验证）
- 触发路径: wcscpy(password, L"Password1234!"); @ L116; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_82_base* baseObject = new CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_82_case1V1; @ L117; baseObject->action(password); @ L118
- 结论: 硬编码密码被赋值并传递给action函数，存在CWE-259硬编码密码漏洞；但action函数的具体实现未提供，无法确认密码是否通过未加密通道传输（CWE-319）。由于CWE-259明显违反，保留漏洞假设，但需要进一步验证action的传输方式。
- D验证: stage_c_preserved / ver_250cfb38
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 57. hyp_path_d3784688a220

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_82a.cpp:116
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问进程内存或逆向工程获取硬编码密码
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_82a.cpp:116
- 结论: 代码存在硬编码密码（CWE-259），但注释明确表明该密码未通过网络发送，因此不构成CWE-319明文传输敏感信息。仅保留CWE-259，影响较低。
- D验证: stage_c_preserved / ver_b2a74da8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 58. hyp_path_9a5076819685

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_82a.cpp:129
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问编译后的二进制文件或反编译代码以提取硬编码密码
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_82a.cpp:129; baseObject->action(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_82a.cpp:131
- 结论: 代码中存在硬编码密码（CWE-259），密码'Password1234!'被直接写入password变量并传递给action函数。但缺少action函数实现证据，无法确认密码是否被明文传输或用于其他不安全操作，因此CWE-319未证实。
- D验证: stage_c_preserved / ver_2df0d85e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 59. hyp_path_1a5737729b84

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_81a.cpp:115
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问本地内存或存储以获取硬编码密码。
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_81a.cpp:115; baseObject.action(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_81a.cpp:117
- 结论: 存在硬编码密码（CWE-259），但注释表明密码未通过网络发送，因此CWE-319不成立；需动态验证action函数内部行为以确定敏感信息是否被明文传输。
- D验证: stage_c_preserved / ver_4a1a0df8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 60. hyp_path_aecdc83c89f4

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_81a.cpp:128
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够读取源代码或反编译二进制文件以提取硬编码密码。
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_81a.cpp:128
- 结论: 代码中使用硬编码密码 'Password1234!'，违反 CWE-259（硬编码密码），但注释明确说明密码未通过网络发送，因此 CWE-319（明文传输敏感信息）不成立。
- D验证: stage_c_preserved / ver_9f851611
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 61. hyp_path_ffa13e68d838

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_81a.cpp:128
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问应用程序二进制文件（逆向工程）
- 触发路径: wcscpy(password, L"Password1234!"); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_81a.cpp:128
- 结论: 硬编码密码'Password1234!'存在，违反CWE-259。CWE-319因缺乏网络传输证据被否定。
- D验证: stage_c_preserved / ver_9a29fc23
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 62. hyp_path_6f427eb0742e

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_81a.cpp:115
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问源代码或二进制文件以获取硬编码密码。
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_81a.cpp:115
- 结论: 硬编码密码'Password1234!'存在于源代码中，符合CWE-259；但缺乏证据表明该密码通过明文网络传输（CWE-319），注释表明'it was not sent over the network'且B阶段静态分析未闭合source-sink路径。因此保留CWE-259，CWE-319路径未闭合，需动态验证或审计action函数行为。
- D验证: stage_c_preserved / ver_7aa77b30
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 63. hyp_path_4639723ef1fc

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_73b.cpp:52
- 漏洞类型: null_deref
- CWE: CWE-476; CWE-690
- 风险等级: P1
- 触发条件: 攻击者能够控制传递给 case0Sink 的 passwordList 为空
- 触发路径: wchar_t * password = passwordList.back(); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_73b.cpp:36
- 结论: 在函数 case0Sink 中，从密码列表 passwordList 获取密码时，未检查列表是否为空，直接调用 back()。如果 passwordList 为空，则 back() 行为未定义，可能导致程序崩溃或拒绝服务，但影响局限于拒绝服务，且需攻击者能控制输入列表为空。
- D验证: stage_c_preserved / ver_97c03303
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 64. hyp_path_07253daf1ce5

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_73a.cpp:212
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够嗅探或中间人攻击网络流量，获取明文密码。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_73a.cpp:138-208
- 结论: 在 case1V2 函数中，通过 recv 从网络接收密码时未使用加密协议（如 SSL/TLS），导致敏感信息以明文形式传输，违反 CWE-319。
- D验证: stage_c_preserved / ver_e03051e4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 65. hyp_path_17d1a27de4ac

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_66a.c:123
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问包含硬编码密码的二进制文件或源码
- 触发路径: strcpy(password, "Password1234!"); @ L123; passwordArray[2] = password; @ L124; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_66b_case1V1Sink(passwordArray); @ L125
- 结论: 硬编码密码被复制到password数组并传递给sink函数，存在CWE-259硬编码密码漏洞；但sink函数后续是否通过明文网络传输尚不明确（注释否定网络发送），故CWE-319不成立。需动态确认sink函数行为。
- D验证: stage_c_preserved / ver_9637dcff
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 66. hyp_path_c5f789d8abe5

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_68a.c:128
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够获取二进制文件或通过调试读取内存中的硬编码密码
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_68a.c:126; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_68_case1V1Data = password; @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_68a.c:128; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_68b_case1V1Sink(); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_68a.c:129
- 结论: 硬编码密码 'Password1234!' 存在于全局变量中，构成 CWE-259（硬编码密码）漏洞；但根据注释，此路径未通过网络发送，CWE-319（明文传输敏感信息）不成立。需进一步审计 sink 函数在其他上下文中是否涉及网络发送。
- D验证: stage_c_preserved / ver_d650ae03
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 67. hyp_path_7ba787bc5e20

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_81a.cpp:192
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够控制网络中间节点或监听通信，从而获取接收到的密码
- 触发路径: case1V2()函数中通过recv从网络接收密码到password缓冲区 @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_81a.cpp:121-188; baseObject.action(password) - 推测存在明文传输，但action实现未知 @ line after break (baseObject.action(password)调用)
- 结论: 存在CWE-319明文传输敏感信息漏洞：case1V2函数通过recv从网络接收密码，并调用action(password)，但action函数的具体实现未提供，无法确认是否明文传输。基于代码路径，漏洞存在可能，但证据不完整。
- D验证: stage_c_preserved / ver_2227edaf
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 68. hyp_path_be54dbf9d024

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_82a.cpp:195
- 漏洞类型: CWE-319, CWE-259
- CWE: CWE-319; CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够监听或拦截网络流量（例如位于同一网络段或中间人位置）
- 触发路径: static void case1V2() { ... recv(connectSocket, (char*)(password + passwordLen), ...); ... } @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_82a.cpp:123-191; strcpy(password, "Password1234!"); @ case1V1
- 结论: 程序通过未加密的TCP套接字接收敏感密码（case1V2），且存在硬编码密码（case1V1），违反CWE-319和CWE-259。
- D验证: stage_c_preserved / ver_33b672c0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 69. hyp_path_2001b638bcb2

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_62a.cpp:190
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够监听网络流量，截获明文密码
- 触发路径: case1V1Source(password); @ case1V1Source(password) 调用处; if (LogonUserA(username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) @ LogonUserA调用
- 结论: CWE319: 敏感信息（密码）通过listen_socket以明文形式接收，并直接用于LogonUserA本地认证，导致密码在网络上明文暴露。
- D验证: confirmed / ver_7c70019b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 70. hyp_path_46534f590aeb

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_68a.c:141
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问编译后的二进制文件以提取硬编码密码。
- 触发路径: strcpy(password, "Password1234!"); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_68a.c:139; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_68_case1V1Data = password; @ CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_68a.c:141; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_68b_case1V1Sink(); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_68a.c:141
- 结论: 代码使用硬编码密码 'Password1234!'，违反CWE-259（硬编码密码）。虽然注释指出该密码未通过网络发送，但硬编码密码本身存在被逆向提取的风险，攻击者可获取该密码用于后续攻击。
- D验证: stage_c_preserved / ver_18302cc2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 71. hyp_path_2c0723b7f786

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_67a.c:140
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问包含此代码的系统（本地或通过其他途径）以读取硬编码密码。
- 触发路径: strcpy(password, "Password1234!"); @ L140; myStruct.structFirst = password; @ L141; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_67b_case1V1Sink(myStruct); @ L142
- 结论: 硬编码密码 'Password1234!' 被赋值给密码缓冲区，并通过结构体传递给 sink 函数。注释表明该分支未通过网络发送，但硬编码密码本身构成 CWE-259 漏洞，可能导致本地信息泄露或凭证复用。
- D验证: stage_c_preserved / ver_31e2a071
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 72. hyp_path_511ddae519cd

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_66a.c:136
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问编译后的二进制文件或源代码。
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_66a.c:136
- 结论: 硬编码密码'Password1234!'存在于源代码中，违反CWE-259（硬编码密码），攻击者可通过读取源代码或反编译获取密码。
- D验证: stage_c_preserved / ver_9aadcd7b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 73. hyp_path_37543441fc18

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_66a.c:123
- 漏洞类型: CWE-259, CWE-319
- CWE: CWE-259; CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够截获sink函数处理的数据，或能够访问sink函数产生的输出；sink函数应执行明文网络传输。
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_66a.c:123; passwordArray[2] = password; @ 同一文件行124; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_66b_case1V1Sink(passwordArray); @ 同一文件行125
- 结论: 函数使用硬编码密码（CWE-259），并通过passwordArray传递给sink函数（CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_66b_case1V1Sink），sink名称暗示网络传输，可能导致明文传输敏感信息（CWE-319）。
- D验证: stage_c_preserved / ver_3d684dfa
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 74. hyp_path_45625ea5115f

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_73a.cpp:239
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够获取程序二进制或静态分析逆向工程，但无需主动利用条件。
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_73a.cpp:138; case1V1Sink(passwordList); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_73a.cpp:144
- 结论: 函数case1V1中存在硬编码密码，违反CWE-259。
- D验证: stage_c_preserved / ver_d104e7fc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 75. hyp_path_10f5e8db6b3d

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67a.c:127
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够读取程序内存或静态分析获取硬编码密码，但无法通过网络嗅探获取，因为密码未在网络上传输。
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67a.c:127; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67b_case1V1Sink(myStruct); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67a.c:129
- 结论: 硬编码密码'Password1234!'通过结构体传递给sink函数，但代码注释说明密码未通过网络发送，sink函数内部实现未知，无法确认存在明文传输。因此仅存在CWE-259硬编码凭证漏洞，CWE-319明文传输漏洞不成立。
- D验证: stage_c_preserved / ver_30678dfb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 76. hyp_path_744b842c930d

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_68a.c:128
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者无需特殊条件，只需程序运行此代码路径即可利用硬编码密码
- 触发路径: wcscpy(password, L"Password1234!"); CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_68_case1V1Data = password; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_68b_case1V1Sink(); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_68a.c:126-128
- 结论: 硬编码密码：代码中直接使用固定字符串'Password1234!'作为密码，违反CWE-259（硬编码密码），可能导致密码泄露或未经授权访问。CWE-319不成立，因为注释表明密码未通过网络发送，且sink函数行为未知，但硬编码密码本身构成安全风险。
- D验证: stage_c_preserved / ver_38ac6ab9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 77. hyp_path_39443ab784c2

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_62a.cpp:189
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够嗅探或拦截网络流量（监听套接字）
- 触发路径: case1V1Source(password); // 未显示实现但根据CWE319样本是从网络接收 @ case1V1Source(password) 接收密码; if (LogonUserW(username, domain, password, ...) != 0) @ case1V1函数内
- 结论: 函数case1V1通过套接字监听接收密码明文，并直接用于LogonUserW身份验证，导致敏感信息以明文形式在网络中传输，违反了CWE319。
- D验证: confirmed / ver_4fe0be0c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 78. hyp_path_19c37e98c9be

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_68a.c:141
- 漏洞类型: CWE-259, CWE-319
- CWE: CWE-259; CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够监听sink函数发送的网络通信
- 触发路径: wcscpy(password, L"Password1234!"); @ L139; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_68_case1V1Data = password; @ L140; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_68b_case1V1Sink(); @ L141
- 结论: 存在硬编码密码（CWE-259），且通过全局变量传递给sink函数，sink函数可能以明文形式传输密码（CWE-319），但sink函数内部行为未知，证据不完整。
- D验证: stage_c_preserved / ver_bbc013e5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 79. hyp_path_330bf86f7645

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67a.c:140
- 漏洞类型: CWE-259, CWE-319
- CWE: CWE-259; CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够窃听网络流量（仅当sink函数确实进行明文网络传输时成立）
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67a.c:140; myStruct.structFirst = password; @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67a.c:141; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67b_case1V1Sink(myStruct); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67a.c:142
- 结论: 硬编码密码通过结构体传递给sink函数，sink函数可能以明文形式通过网络传输密码（CWE-319），但缺乏sink内部代码证据，需要动态验证。
- D验证: stage_c_preserved / ver_92908983
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 80. hyp_path_762bac7f7a73

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_72a.cpp:238
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够连接到本地监听端口（TCP_PORT）并发送包含密码的明文数据
- 触发路径: recvResult = recv(acceptSocket, (char*)password, 100 * sizeof(wchar_t), 0); @ case1V2函数内，recv调用处; passwordVector.insert(passwordVector.end(), 1, password); @ case1V2函数内，vector插入password; case1V2Sink(passwordVector); @ case1V2函数内，调用case1V2Sink
- 结论: 在CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_72a.cpp的case1V2函数中，通过网络明文接收密码（使用recv从TCP套接字读取），并将密码通过vector传递给sink函数，违反了CWE-319（敏感信息明文传输）。
- D验证: stage_c_preserved / ver_c0e60d81
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 81. hyp_path_46c7c08a2017

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_66a.c:136
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够获取代码或内存中的硬编码密码
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_66a.c:136
- 结论: 硬编码密码（CWE-259）存在，但无证据表明通过不安全的网络传输，CWE-319不成立。
- D验证: stage_c_preserved / ver_a64647bd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 82. hyp_path_6dfdf7be6306

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_52b.c:59
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够通过网络获取明文密码
- 触发路径: CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_52c_case1V2Sink(password); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_52b.c:59
- 结论: 密码通过明文传递给下一个函数，可能最终导致敏感信息明文传输（CWE-319）
- D验证: stage_c_preserved / ver_bd5bf2f8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 83. hyp_path_3271bb807c83

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_52b.c:39
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够控制或监听网络通信，获取传输中的密码数据。
- 触发路径: void CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_52b_case0Sink(char * password) { ... } @ 入口函数CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_52b_case0Sink; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_52c_case0Sink(password); @ 调用另一个sink函数
- 结论: 函数接收密码参数，但缺乏从source到sink的完整代码证据，无法确认是否存在CWE-319明文传输漏洞。潜在漏洞路径存在，但需要动态验证。
- D验证: stage_c_preserved / ver_e29ad1cb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 84. hyp_path_279df347e028

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_53c.c:59
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够控制password参数（例如通过connect_socket接收的密码）
- 触发路径: void CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_53c_case1V2Sink(char * password) { CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_53d_case1V2Sink(password); } @ L57-L61
- 结论: CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_53c_case1V2Sink 函数接收密码参数并传递给53d变体，可能构成明文传输敏感信息路径。由于缺乏53d函数体的代码，无法验证实际sink操作，但根据函数命名和Juliet测试用例背景，可能存在未加密的网络发送。
- D验证: stage_c_preserved / ver_c9b766f3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 85. hyp_path_8c1fcfb09cec

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54d.c:39
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够控制password输入或中间人能够截获网络通信
- 触发路径: CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54e_case0Sink(password); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54d.c:39
- 结论: 函数将密码参数直接传递给另一个函数，未进行任何加密或安全检查，可能导致敏感信息以明文形式传输（CWE-319）。但当前代码片段仅显示中间层调用，未直接证明明文传输行为；漏洞的完整触发依赖于后续函数的实现。
- D验证: stage_c_preserved / ver_59bb31a2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 86. hyp_path_22a44f1de32f

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53b.c:39
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够监听网络流量，或能够控制下游接收函数
- 触发路径: CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53c_case0Sink(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53b.c:39
- 结论: 密码数据以明文形式传递给下一个函数，未进行加密，可能导致敏感信息明文传输。
- D验证: stage_c_preserved / ver_910043b1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 87. hyp_path_292633079709

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53c.c:51
- 漏洞类型: CWE-312, CWE-319
- CWE: CWE-312; CWE-319
- 风险等级: P1
- 触发条件: 假设password参数包含敏感信息，但来源未确认；需要进一步验证是否存在网络输入或其他外部可控源
- 触发路径: CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53d_case1V1Sink(password); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53c.c:51
- 结论: 函数以明文形式传递password参数，但缺乏source证据表明密码来自外部可控源；当前代码仅显示函数间调用，未涉及网络传输。可能更符合CWE-312（明文存储）而非CWE-319（明文传输），但仍存在敏感信息泄露风险，需要动态验证完整路径。
- D验证: stage_c_preserved / ver_40784449
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 88. hyp_path_0ea6ec747cd1

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_54d.c:59
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够通过网络监听或中间人攻击截获明文密码
- 触发路径: void CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_54d_case1V2Sink(char * password) { CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_54e_case1V2Sink(password); } @ L59
- 结论: CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_54d_case1V2Sink 函数接收密码参数并直接传递给下一个sink，未进行加密处理，构成cleartext传输敏感信息漏洞。虽然当前代码片段仅显示函数调用链，但函数名称和项目背景暗示密码来源于监听套接字，且后续可能未经加密直接发送，违反CWE319要求。
- D验证: stage_c_preserved / ver_15b72816
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 89. hyp_path_fefc86de2dee

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52b.c:39
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够控制或获取password参数的值（例如通过输入注入或网络嗅探），且下层函数以明文形式传输此密码。
- 触发路径: CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52c_case0Sink(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52b.c:39
- 结论: 函数通过明文传递密码参数，可能违反CWE-319（明文传输敏感信息）。但证据仅止于中间调用，下层函数行为未验证，因此漏洞可能性依赖下层函数是否确实使用明文传输。当前为不完整假设。
- D验证: stage_c_preserved / ver_2572ac30
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 90. hyp_path_6fca803f8727

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_53c.c:39
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够访问网络通信路径
- 触发路径: CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_53d_case0Sink(password); @ 39行
- 结论: 密码参数以明文形式传递给后续函数，未进行任何加密处理，可能导致敏感信息通过明文传输泄露（CWE-319）
- D验证: stage_c_preserved / ver_05e06d4c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 91. hyp_path_b8064d5006d6

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53c.c:39
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够截获传输中的数据或访问sink函数处理后的结果; password参数包含敏感信息
- 触发路径: CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53d_case0Sink(password); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53c.c:39
- 结论: 函数CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53c_case0Sink将password参数直接传递给下游sink函数，未进行加密处理，可能导致明文传输敏感信息（CWE-319）。但下游函数具体实现未知，无法确认是否存在加密或安全传输，证据不完整。
- D验证: stage_c_preserved / ver_03521863
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 92. hyp_path_fed220c6a17f

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54b.c:39
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够控制或嗅探网络流量，前提是password确实来自网络且后续通过不安全的通道传输
- 触发路径: CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54c_case0Sink(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54b.c:39
- 结论: 密码明文传递给后续处理函数，基于样本主题和函数命名，可能违反CWE-319（敏感信息明文传输），但缺少source（密码来源）和sink（实际传输方式）的完整代码证据。
- D验证: stage_c_preserved / ver_e16e075b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 93. hyp_path_6b3a31d5e15c

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54b.c:51
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: password变量包含敏感信息; 下游函数将password通过明文网络传输
- 触发路径: void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54b_case1V1Sink(wchar_t * password) { CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54c_case1V1Sink(password); } @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54b.c:49-53
- 结论: 潜在敏感信息明文传输：password参数可能通过未加密通道传输，但当前代码片段仅显示函数调用，未直接证实传输行为。
- D验证: stage_c_preserved / ver_848b8f6c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 94. hyp_path_9e88c8939632

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_42.c:138
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者需要能够控制该函数的调用上下文，或通过其他方式获取函数返回的密码值。
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_42.c:138
- 结论: 函数返回硬编码密码，违反CWE-259，可能被调用者用于未授权访问，但缺乏从外部输入到该函数的明确攻击路径。
- D验证: stage_c_preserved / ver_a2973f6c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 95. hyp_path_4ad5a4c4f12a

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_61b.c:121
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够获取到编译后的二进制文件或源码，从而提取硬编码密码。
- 触发路径: strcpy(password, "Password1234!"); return password; @ L119-123
- 结论: 函数返回硬编码密码，存在CWE-259硬编码密码漏洞。代码中strcpy(password, "Password1234!")将固定字符串复制到password缓冲区并返回，攻击者可通过逆向工程获取该密码。
- D验证: stage_c_preserved / ver_36a60776
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 96. hyp_path_1d72322f2e91

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54d.c:59
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够监听网络流量以截获明文密码。
- 触发路径: CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54e_case1V2Sink(password); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54d.c:59
- 结论: 函数将密码参数直接传递给另一个sink函数，若该sink函数最终通过未加密的网络传输密码，则构成敏感信息明文传输漏洞。
- D验证: stage_c_preserved / ver_4618e9b8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 97. hyp_path_8342ec35e4dc

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_42.c:138
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问二进制可执行文件或源代码，提取硬编码密码
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_42.c:138
- 结论: 硬编码密码（CWE-259）：函数使用硬编码密码 'Password1234!'，注释说明未通过网络发送，但密码以明文形式存在于代码中，可能导致凭据泄露。
- D验证: stage_c_preserved / ver_57cffc44
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 98. hyp_path_25aac6351d9b

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_61b.c:108
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够截获网络流量（中间人攻击）
- 触发路径: wcscpy(password, L"Password1234!"); return password; @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_61b.c:108
- 结论: 函数返回硬编码密码，违反CWE-259（硬编码密码），但未发现明文传输路径，CWE-319（明文传输敏感信息）证据不足。
- D验证: stage_c_preserved / ver_1bd9ae4f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 99. hyp_path_5a01a15c8238

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_42.c:151
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问二进制文件或内存以获取硬编码密码
- 触发路径: strcpy(password, "Password1234!"); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_42.c:151
- 结论: 函数case1V1Source使用strcpy将硬编码密码"Password1234!"复制到password缓冲区并返回，存在硬编码密码问题（CWE-259）。虽然代码注释表明该密码未通过网络发送，但硬编码密码本身仍可被攻击者通过逆向工程或内存读取获取，构成安全风险。CWE-319路径因缺乏网络传输证据而不成立。
- D验证: stage_c_preserved / ver_fc1e4689
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 100. hyp_path_37d387eb85e5

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_65a.c:123
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者无需额外条件，硬编码密码直接赋值
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_65a.c:123
- 结论: 硬编码密码 'Password1234!' 被复制到 password 变量，并通过函数指针 funcPtr 传递，可能用于后续敏感操作。虽然存在 CWE-259 硬编码密码，但利用路径不完整（funcPtr 指向未明），需动态验证才能确认敏感信息泄露。
- D验证: stage_c_preserved / ver_defc797f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 101. hyp_path_7fe673fbeb0e

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_61b.c:121
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问程序的内存或通过网络截获返回值
- 触发路径: wcscpy(password, L"Password1234!"); return password; @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_61b.c:121
- 结论: 函数返回硬编码密码，违反CWE-259（硬编码密码），可能导致敏感信息泄露。
- D验证: stage_c_preserved / ver_89fdd8d1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 102. hyp_path_7f7d30c1bd18

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_44.c:183
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问源代码（如通过逆向工程、代码泄露、调试等）或执行环境。
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_44.c:183
- 结论: 硬编码密码（CWE-259）: 代码通过strcpy将硬编码字符串"Password1234!"赋值给password，并通过函数指针funcPtr传递。但funcPtr的具体目标函数未在代码片段中体现，无法确认该密码是否用于敏感操作或是否可被外部攻击者利用。
- D验证: stage_c_preserved / ver_10b69ce3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 103. hyp_path_ddea88ea8352

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_44.c:170
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问程序二进制文件或源代码；程序执行到该代码路径。
- 触发路径: strcpy(password, "Password1234!"); @ L170
- 结论: 存在硬编码密码漏洞：程序在L170处使用硬编码的密码"Password1234!"，并通过函数指针funcPtr传递给后续使用。攻击者若获取二进制或源代码，可得到该密码，可能导致敏感信息泄露。
- D验证: stage_c_preserved / ver_980b1074
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 104. hyp_path_32ca12a655bc

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_44.c:183
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: Attacker can obtain the binary and reverse engineer it to extract the hardcoded password.
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_44.c:183
- 结论: Hardcoded password vulnerability: password is set to a fixed string 'Password1234!' using wcscpy, which can be extracted from the binary by an attacker.
- D验证: stage_c_preserved / ver_f2bc866c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 105. hyp_path_5bee48763c96

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_44.c:170
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够获取到编译后的二进制文件或源代码。
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_44.c:170
- 结论: 代码使用硬编码密码 'Password1234!'，违反了 CWE-259 (Hard-coded Password) 定义。
- D验证: stage_c_preserved / ver_1af15298
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 106. hyp_path_3675a60be839

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_21.c:492
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问到二进制代码或源代码，即可提取硬编码密码。
- 触发路径: wcscpy(password, L"Password1234!"); @ case1V1函数，第490-492行
- 结论: 函数case1V1中使用硬编码密码（L"Password1234!"），违反了CWE-259（硬编码密码）。密码以明文形式存在于代码中，可被攻击者逆向获取，可能导致未授权访问。
- D验证: stage_c_preserved / ver_53bfa854
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 107. hyp_path_0fe181c0a98d

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_65a.c:123
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问二进制文件或内存
- 触发路径: wcscpy(password, L"Password1234!"); @ L123
- 结论: 代码中存在硬编码密码（CWE-259），但注释表明密码未通过网络发送，因此CWE-319不成立。硬编码密码可能通过本地访问或逆向工程泄露，影响较低。
- D验证: stage_c_preserved / ver_5e5eabc9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 108. hyp_path_8cb3e29bad73

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_21.c:492
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P0
- 触发条件: 攻击者能够访问或反编译源代码，从而获取硬编码密码。
- 触发路径: strcpy(password, "Password1234!"); @ case1V1函数中，第492行; case1V1Sink(password); @ case1V1函数中，第494行; if (LogonUserA( username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) @ case1V1Sink函数中，第467行
- 结论: 函数case1V1中使用了硬编码密码'Password1234!'，并将其传递给LogonUserA进行身份验证，违反了CWE-259（硬编码密码）。
- D验证: confirmed / ver_959ba221
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 109. hyp_path_05b2396442c8

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_65a.c:136
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问程序二进制或源代码。
- 触发路径: strcpy(password, "Password1234!"); funcPtr(password); @ line 136
- 结论: 代码中使用硬编码密码 'Password1234!'，违反了 CWE-259（硬编码密码）。尽管 funcPtr 的具体行为未闭合，但硬编码密码的存在本身构成安全风险，攻击者可通过逆向工程获取。
- D验证: stage_c_preserved / ver_8434f7be
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 110. hyp_path_a3edb3c3b64f

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_42.c:151
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够触发函数执行并获取返回的密码
- 触发路径: wcscpy(password, L"Password1234!"); return password; @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_42.c:151
- 结论: 函数返回硬编码密码，攻击者可获取敏感凭据。
- D验证: stage_c_preserved / ver_d17c9b7c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 111. hyp_path_2b3b6a917d66

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_21.c:531
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P0
- 触发条件: 攻击者能够访问可执行文件或源代码以提取硬编码密码。; 目标系统上存在使用该密码的账户（User/Domain）。
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_21.c:531; case1V1Sink(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_21.c:533; if (LogonUserA( username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_21.c:502-511
- 结论: 硬编码密码：在代码中使用了硬编码字符串"Password1234!"作为密码，并用于LogonUserA函数进行身份验证。攻击者可以通过逆向工程或读取源代码获取该密码，从而可能导致未授权访问。
- D验证: confirmed / ver_980d91e5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 112. hyp_path_7ee35cac0d78

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_41.c:166
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P0
- 触发条件: 攻击者能够获取到编译后的二进制文件或源代码，从而提取硬编码密码。
- 触发路径: strcpy(password, "Password1234!"); @ L166; case1V1Sink(password); @ L167; LogonUserA(username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) @ case1V1Sink内L144?
- 结论: 代码中存在硬编码密码，密码值'Password1234!'被直接传递给LogonUserA，违反了CWE-259（硬编码密码）。攻击者通过逆向工程或源代码访问可获取该密码，进而可能导致未授权访问。
- D验证: confirmed / ver_2dcbe3c4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 113. hyp_path_8d8d6894919f

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_41.c:179
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P0
- 触发条件: 攻击者能够获取到程序二进制文件或源代码，从而提取硬编码密码
- 触发路径: strcpy(password, "Password1234!"); @ case1V1函数; if (LogonUserA(username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) @ case1V1Sink函数
- 结论: 硬编码密码被用于LogonUserA认证，攻击者可通过逆向工程获取密码，可能导致未授权访问。
- D验证: confirmed / ver_ba9a2619
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 114. hyp_path_6b56bd8499df

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_05.c:530
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够访问网络路径，嗅探或获取明文数据。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ case1V22或case1V21中recv调用; if (LogonUserA( username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) @ case1V12中LogonUserA调用
- 结论: 密码通过明文网络传输（recv未加密），然后用于身份验证（LogonUserA），导致敏感信息泄露。
- D验证: confirmed / ver_1798fa1a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 115. hyp_path_3a6b4b523a3f

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_02.c:525
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够嗅探目标主机与服务器之间的网络流量; 服务器使用明文协议发送密码
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ case1V22中recv调用; connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR @ case1V22中连接建立; if (LogonUserA( username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) @ case1V11/case1V12中LogonUserA使用密码
- 结论: 敏感信息（密码）通过明文网络传输，攻击者可嗅探获取密码，违反CWE-319（敏感信息明文传输）。
- D验证: confirmed / ver_d2b1012f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 116. hyp_path_3672008b357e

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_21.c:531
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P0
- 触发条件: 攻击者无需控制任何输入即可利用该硬编码密码。
- 触发路径: wcscpy(password, L"Password1234!"); @ L531; case1V1Sink(password); @ L533; if (LogonUserW(username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) @ L505-506
- 结论: 硬编码密码（CWE-259）被用于 LogonUserW 认证，攻击者可利用该固定密码进行身份冒充。
- D验证: confirmed / ver_56a878f5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 117. hyp_path_09c187e2b97f

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_41.c:166
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P0
- 触发条件: 攻击者能够访问程序二进制文件或源代码以提取硬编码密码
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_41.c:166; case1V1Sink(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_41.c:167; if (LogonUserW(username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_41.c:140-150
- 结论: 硬编码密码漏洞：密码被硬编码为字符串'Password1234!'，并传递给LogonUserW函数用于身份验证，攻击者可获取该密码并用于未授权访问。
- D验证: confirmed / ver_01e2320d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 118. hyp_path_0047d38b2cfc

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_41.c:179
- 漏洞类型: CWE-259, CWE-798
- CWE: CWE-259; CWE-798
- 风险等级: P0
- 触发条件: 攻击者能够获取程序二进制文件或源代码，密码未加密存储。
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_41.c:179; case1V1Sink(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_41.c:180; if (LogonUserW( username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_41.c:153-163
- 结论: 函数 case1V1Sink 使用硬编码密码 "Password1234!" 进行用户认证，攻击者可通过逆向工程获取密码，可能导致未授权访问。
- D验证: confirmed / ver_9f23c32b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 119. hyp_path_1a881b178cd1

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_07.c:531
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: Attacker can intercept or control the network traffic to the target host on the specified port.
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ case1V21() at line ~139
- 结论: CWE319 Cleartext Transmission of Sensitive Information: In case1V21(), password buffer is filled with data received from the network via recv() without encryption. Although later overwritten by hardcoded password, the sensitive data is transmitted in cleartext over the network.
- D验证: stage_c_preserved / ver_6eea6d29
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 120. hyp_path_35ccc2df1526

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_13.c:525
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够访问客户端与服务端之间的网络路径，并能捕获或修改TCP数据包。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ case1V22()中recv调用; password = passwordBuffer; @ case1V22()中的密码存储; LogonUserA( username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle); @ 后续case1V11()使用密码（但硬编码，实际应为网络接收的密码）
- 结论: 通过网络明文接收敏感密码信息，可能导致中间人攻击窃取密码。
- D验证: confirmed / ver_184b8612
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 121. hyp_path_5d28b613dcba

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_14.c:525
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够在客户端和服务端之间的网络路径上进行中间人攻击或被动监听
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ L299-300
- 结论: 密码通过明文 TCP 连接接收，未使用加密协议（如 TLS），导致敏感信息在网络上以明文形式传输，可能被中间人窃听。
- D验证: stage_c_preserved / ver_3b1e1d6a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 122. hyp_path_5ef1126dd0fc

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_04.c:529
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够监听目标主机与远程服务器之间的网络流量（例如在同一子网或具有中间人能力）。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_04.c:275-284
- 结论: case1V21函数通过recv从网络接收密码，未使用任何加密（如SSL/TLS），导致密码以明文形式在网络上传输，符合CWE-319定义。尽管接收的密码未在后续敏感操作中使用，但明文传输过程本身已暴露敏感信息，攻击者可嗅探网络获取密码。
- D验证: stage_c_preserved / ver_c43c19ad
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 123. hyp_path_06398db473fe

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_03.c:525
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够嗅探或中间人攻击网络通信。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ case1V21: recv调用; if (LogonUserA( username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) @ case1V11/case1V12: LogonUserA调用
- 结论: 在CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_03.c中，case1V21函数通过recv从网络接收明文密码到passwordBuffer，随后passwordBuffer被传递给LogonUserA（通过case1V11或case1V12），但密码在传输过程中未加密，违反CWE-319。尽管后续可能被硬编码覆盖，但明文接收行为本身构成安全风险。
- D验证: confirmed / ver_0ca39ad0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 124. hyp_path_12b9d782f640

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_15.c:575
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够访问客户端与服务端之间的网络通信路径，并能够嗅探或拦截明文数据包。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ case1V22 函数内 recv 调用
- 结论: 函数 case1V22 通过 recv 从网络明文接收密码（敏感信息），构成 CWE-319 明文传输敏感信息。攻击者可嗅探网络流量获取密码。
- D验证: stage_c_preserved / ver_5a106801
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 125. hyp_path_1f4b11ae688a

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_04.c:570
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P0
- 触发条件: 攻击者能够访问应用程序二进制文件或运行时内存以提取硬编码密码
- 触发路径: strcpy(password, "Password1234!"); @ case1V11, L484-525; LogonUserA(username, domain, password, ...); @ case1V11, L484-525; strcpy(password, "Password1234!"); @ case1V12, L528-564; LogonUserA(username, domain, password, ...); @ case1V12, L528-564
- 结论: 硬编码密码漏洞：case1V11和case1V12中，passwordBuffer通过strcpy赋值为固定字符串'Password1234!'，并直接用于LogonUserA调用，攻击者可通过逆向工程获取该密码，违反CWE-259。
- D验证: confirmed / ver_ef70be04
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 126. hyp_path_6cefb0af80da

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_09.c:523
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够嗅探到客户端与服务端之间的网络流量。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ case1V21 函数内; if (LogonUserA( username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) @ case1V11 或 case1V12 函数内
- 结论: 密码通过网络明文传输（recv 接收）后直接用于 LogonUserA 认证，攻击者可嗅探网络获取敏感信息。
- D验证: confirmed / ver_ee8708c7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 127. hyp_path_3bcb8993ac45

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_04.c:531
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标程序发送恶意密码数据
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ case1V21函数内recv调用; if (LogonUserW( username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) @ case1V11函数内LogonUserW调用
- 结论: 代码从网络接收密码（明文）后未加密，但随后使用的密码是硬编码值，而非网络接收值。如果存在数据流将网络接收的密码传递给LogonUser，则构成CWE-319明文传输敏感信息漏洞。当前代码中数据流不连通，但作为测试用例，意图展示漏洞模式。
- D验证: confirmed / ver_d635f3e2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 128. hyp_path_12aaa3b989d4

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_09.c:523
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够控制网络通信路径，能够监听或修改流量。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ case1V21/case1V22 函数内; 密码明文存储在passwordBuffer中 @ case1V21/case1V22 函数内; LogonUserW(username, domain, password, ...) 使用明文密码 @ case1V12 或 case1V11
- 结论: 敏感信息（密码）通过明文网络传输，违反CWE319。代码中case1V21和case1V22函数通过recv从网络接收密码，未使用加密，之后密码被用于LogonUser，导致敏感信息暴露。
- D验证: confirmed / ver_bbafaf2b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 129. hyp_path_2ab869f61b0c

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_09.c:565
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P0
- 触发条件: 无，硬编码密码总是执行
- 触发路径: strcpy(password, "Password1234!"); @ case1V12 函数内，密码赋值; if (LogonUserA(username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) @ LogonUserA 调用
- 结论: 硬编码密码用于身份验证（CWE-259）
- D验证: confirmed / ver_0f0e8d3d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 130. hyp_path_3fc59eb9395a

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_05.c:530
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够嗅探或拦截客户端与服务器之间的网络通信。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ case1V22
- 结论: 函数case1V22通过未加密TCP连接接收密码数据，存在明文传输敏感信息的漏洞（CWE-319）。虽然接收的密码未被后续函数使用，但网络传输行为本身已违反安全规范。
- D验证: stage_c_preserved / ver_bfebc865
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 131. hyp_path_b18592391b81

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_02.c:563
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够嗅探或拦截网络流量（如在同一网络、中间人攻击等）
- 触发路径: recv(acceptSocket, (char*)password, 100, 0); @ case1V22函数内; password = passwordBuffer; // 接收的数据存入passwordBuffer @ case1V22函数内; LogonUserW(username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle); // 使用明文密码 @ case1V12函数内（推断）
- 结论: 密码通过网络明文传输，攻击者可通过监听网络获取敏感密码，导致CWE-319漏洞。
- D验证: confirmed / ver_8afabb2a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 132. hyp_path_8d174ceba904

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_08.c:537
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够监听目标机器与服务器之间的网络流量
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_08.c:302-449 (case1V22)
- 结论: 存在CWE-319漏洞：密码通过未加密的套接字接收（case1V22中的recv），但接收的密码未用于任何敏感操作（如认证），因此影响较低。实际利用需要攻击者能够嗅探网络，但密码未被系统使用，仅作为信息泄露。
- D验证: stage_c_preserved / ver_86d6e8a6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 133. hyp_path_0af542305e28

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_03.c:523
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够嗅探TCP连接上的网络流量
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ L134-286 (case1V21); recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ L289-436 (case1V22)
- 结论: 密码通过明文TCP连接从网络接收，未使用加密协议，导致敏感信息（密码）在网络上明文传输，违反了CWE-319。但网络接收的密码并未在后续敏感操作（如LogonUserW）中使用，因此影响较低，需要动态验证确认实际传播路径。
- D验证: confirmed / ver_63766bee
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 134. hyp_path_5851eaa2b35d

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_13.c:525
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够拦截网络通信（如中间人攻击）或监听同一网络
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ case1V21函数中; recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ case1V22函数中
- 结论: 应用程序通过明文网络传输敏感密码，违反了CWE-319，尽管接收的密码未传递给后续认证函数，但明文接收本身构成敏感信息泄露。
- D验证: stage_c_preserved / ver_7e0ff875
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 135. hyp_path_223a1a8b12fd

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_21.c:500
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够访问程序与服务器之间的网络路径（如中间人攻击或网络嗅探）
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ case1V21/case1V22 函数内
- 结论: 程序通过明文网络（TCP）接收密码，导致敏感信息在传输过程中泄露，攻击者可嗅探获取密码。
- D验证: stage_c_preserved / ver_c046b05b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 136. hyp_path_828dbeca78a0

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_18.c:319
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够与目标建立TCP连接，并发送密码到指定端口
- 触发路径: recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ L132-277
- 结论: 通过网络明文接收密码，违反CWE-319，导致敏感信息泄露
- D验证: stage_c_preserved / ver_1bbf486e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 137. hyp_path_ac97aabfc4ee

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_21.c:501
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够嗅探或中间人攻击，截获TCP连接中的数据包
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ case1V21函数内; recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ case1V22函数内
- 结论: 函数case1V21和case1V22使用recv从网络接收密码数据（wchar_t类型）时未采用加密通道（如TLS），导致敏感信息以明文形式传输，符合CWE-319 Cleartext Transmission of Sensitive Information。
- D验证: stage_c_preserved / ver_bb292b5d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 138. hyp_path_cc4dc073acad

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_12.c:586
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够访问网络链路，并能够拦截或嗅探TCP连接中的数据
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ case1V2函数内，recv调用
- 结论: 从网络接收密码时使用了明文传输（CWE-319），敏感信息在网络上以明文形式传输，即使密码未实际用于认证，但传输过程暴露了敏感数据。
- D验证: stage_c_preserved / ver_8ee8956e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 139. hyp_path_dbce78dfc196

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_31.c:319
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够窃听目标主机与服务器之间的网络通信。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ L169-314（case1V2函数）
- 结论: 在case1V2函数中，通过recv函数从网络接收敏感密码到局部缓冲区，密码未加密以明文形式传输，攻击者可通过窃听网络流量获取密码，违反CWE-319。
- D验证: stage_c_preserved / ver_7483d1f0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 140. hyp_path_5dcdca4df721

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_45.c:173
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P0
- 触发条件: 攻击者能够获取到程序二进制文件或源代码，从而读取硬编码的密码字符串
- 触发路径: case1V1 入口 @ L166; strcpy(password, "Password1234!"); @ L171-173; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_45_case1V1Data = password; @ L174; case1V1Sink(); @ L175; if (LogonUserA( username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) @ L154-157
- 结论: 硬编码密码（Password1234!）被用于LogonUserA认证，攻击者可获取该密码并冒充用户登录。
- D验证: confirmed / ver_207e4935
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 141. hyp_path_73ef36302dff

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_44.c:326
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够控制或访问与目标主机相同的网络段，能够嗅探TCP连接上的数据
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ case1V2函数内
- 结论: 通过网络以明文形式接收密码，导致敏感信息在传输过程中暴露，可能被中间人攻击者窃取。
- D验证: stage_c_preserved / ver_92699841
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 142. hyp_path_987ca2197df8

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_01.c:307
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够嗅探或拦截目标主机与远程服务器之间的网络流量。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ L174-L178; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ L179
- 结论: 在case1V2中，密码通过网络以明文形式接收（recv），未使用加密通道（如TLS），导致敏感信息可能被中间人攻击者窃听。
- D验证: stage_c_preserved / ver_293975ff
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 143. hyp_path_00bda61fbf76

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_32.c:334
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够执行中间人攻击或嗅探网络流量，获取连接套接字上传输的明文密码。
- 触发路径: recvResult = recv(connectSocket, (char*)password, 100 - 1, 0); @ case1V2 do-while 循环内
- 结论: CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_32 案例中，case1V2 函数通过 recv 从网络套接字接收密码明文，未进行加密，导致敏感信息在传输过程中暴露，违反 CWE-319。
- D验证: stage_c_preserved / ver_cb9cd377
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 144. hyp_path_6353bc984ade

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_41.c:322
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够监听网络流量（如中间人攻击）
- 触发路径: recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ L251-317
- 结论: 通过网络接收敏感密码时未使用加密，导致明文传输，但该密码后续未被用于敏感操作（sink），影响较低。
- D验证: stage_c_preserved / ver_7b902115
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 145. hyp_path_b9d996eaa426

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_52a.c:197
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够访问同一网络段并嗅探流量
- 触发路径: static void case1V2() { ... recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); } @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_52a.c:126-192
- 结论: 应用程序通过未加密的TCP连接接收密码，导致密码以明文形式在网络上传输，攻击者可以嗅探获取密码。
- D验证: stage_c_preserved / ver_6b07c34f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 146. hyp_path_1c442a9a8fd1

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_53a.c:197
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够监听网络流量，从而截获通过 recv 接收的明文密码。
- 触发路径: static void case1V2() { ... } @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_53a.c:126-192; recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_53a.c:150-160
- 结论: 在 case1V2 中，敏感密码通过 recv 从网络以明文形式接收，未使用加密（如 TLS），违反 CWE-319。但接收的密码未在后续代码中使用，因此实际影响较低。
- D验证: stage_c_preserved / ver_019eb67f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 147. hyp_path_0b809cbdeeee

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_18.c:345
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务，并发送包含密码的明文数据
- 触发路径: recvResult = recv(acceptSocket, password, 100, 0); // 假设存在 @ case1V2中网络接收部分; if (LogonUserA(username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) @ case1V1中调用LogonUserA
- 结论: 函数case1V2通过网络接收密码（明文），然后case1V1使用该密码调用LogonUserA，导致敏感信息明文传输。
- D验证: confirmed / ver_3f852709
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 148. hyp_path_24ca17a8e99c

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_65a.c:201
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够嗅探目标网络流量或处于中间人位置
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ case1V2函数内 recv调用; funcPtr(password); @ case1V2函数内 调用sink函数
- 结论: 在case1V2中，密码通过recv以明文形式从网络接收，未使用任何加密，随后被传递给sink函数。即使sink函数行为未知，recv明文接收敏感信息本身已构成CWE-319明文传输敏感信息漏洞，可能导致攻击者嗅探到密码。
- D验证: stage_c_preserved / ver_b287316d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 149. hyp_path_5c133f6d77b4

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54a.c:197
- 漏洞类型: CWE-259, CWE-319
- CWE: CWE-259; CWE-319
- 风险等级: P1
- 触发条件: 攻击者能嗅探网络流量（CWE-319）; 攻击者能逆向工程获取硬编码密码（CWE-259）
- 触发路径: strcpy(password, "Password1234!"); CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54b_case1V1Sink(password); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54a.c:112-121; recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54a.c:126-192
- 结论: case1V1中存在硬编码密码（CWE-259）并传递给未知sink函数，可能造成凭据泄露；case1V2中密码通过recv明文接收（CWE-319）但后续未使用，证据不完整。
- D验证: stage_c_preserved / ver_75ce3680
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 150. hyp_path_2d366373c0fb

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_14.c:562
- 漏洞类型: CWE-319, CWE-259
- CWE: CWE-319; CWE-259
- 风险等级: P1
- 触发条件: 攻击者能监听网络流量时，可截获明文密码（CWE-319）; 攻击者获取二进制文件后，可发现硬编码密码（CWE-259）
- 触发路径: recv(acceptSocket, (char*)password, 100, 0); @ case1V21或case1V22内; wcscpy(password, L"Password1234!"); @ case1V12内
- 结论: 程序存在两个漏洞：1) 密码通过明文TCP套接字接收（CWE-319），但接收后的敏感操作（如LogonUser）未在当前函数中直接体现，证据链不完整；2) 存在硬编码密码（CWE-259），在case1V12中直接使用"Password1234!"进行LogonUser。
- D验证: stage_c_preserved / ver_e24621b6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 151. hyp_path_b36ba52f63c6

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_42.c:351
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够嗅探网络流量，监听明文传输的密码
- 触发路径: password = case1V1Source(password); 或 password = case1V2Source(password); @ case1V1Source或case1V2Source; if (LogonUserA(username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) @ LogonUserA调用
- 结论: 敏感信息（密码）通过明文网络传输，攻击者可通过网络监听获取密码，进而进行身份伪造。
- D验证: confirmed / ver_dc370e0b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 152. hyp_path_0c98b7b327f7

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_45.c:188
- 漏洞类型: CWE-259, CWE-321
- CWE: CWE-259; CWE-321
- 风险等级: P0
- 触发条件: 攻击者能够获取程序的二进制文件或源代码，以提取硬编码密码
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_45.c:186; CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_45_case1V1Data = password; @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_45.c:187; case1V1Sink(); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_45.c:188; if (LogonUserA(username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) { ... } @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_45.c:160-167
- 结论: 硬编码密码漏洞：代码在186行使用strcpy硬编码密码'Password1234!'，并通过全局变量传递给case1V1Sink函数，最终在LogonUserA中用于身份验证。攻击者可通过逆向工程获取密码，导致未授权登录。
- D验证: confirmed / ver_9e9e07c4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 153. hyp_path_2a51e3ddcde0

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53a.c:222
- 漏洞类型: CWE-798
- CWE: CWE-798
- 风险等级: P1
- 触发条件: 攻击者能够访问二进制文件或通过逆向工程获取硬编码密码。
- 触发路径: static void case1V1() { char * password; char passwordBuffer[100] = ""; password = passwordBuffer; strcpy(password, "Password1234!"); CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53b_case1V1Sink(password); } @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53a.c:125-128
- 结论: 硬编码密码'Password1234!'存在于case1V1中，违反CWE-798（硬编码密码），但未发现有网络明文传输路径（CWE-319路径不成立）。
- D验证: stage_c_preserved / ver_cb835cc4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 154. hyp_path_a1b515de0610

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_45.c:175
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P0
- 触发条件: 攻击者能够获取到应用程序的二进制文件或源代码。
- 触发路径: wcscpy(password, L"Password1234!"); @ L173; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_45_case1V1Data = password; @ L174; case1V1Sink(); @ L175; case1V1Sink中使用password调用LogonUserW。 @ L139-164
- 结论: 代码中存在硬编码密码（'Password1234!'）被用于LogonUserW身份验证，违反CWE-259。
- D验证: confirmed / ver_29de1fc0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 155. hyp_path_1482d03b5fb5

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_42.c:325
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够嗅探网络流量
- 触发路径: password = case1V1Source(password); password = case1V2Source(password); @ case1V1或case1V2内password = case1V1Source(password)或case1V2Source(password) (行号未明确，位于函数内); if (LogonUserW(username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) @ LogonUserW(username, domain, password, ...) (位于case1V1或case1V2)
- 结论: 密码可能通过网络明文传输，攻击者能够截获敏感凭证。
- D验证: confirmed / ver_7febc8b3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 156. hyp_path_317bc1ba3e99

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_31.c:319
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P0
- 触发条件: 攻击者能够控制或访问网络路径，监听TCP通信。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ case1V2函数内
- 结论: 密码通过recv()从网络明文接收，但后续未用于敏感操作（如LogonUserW），仅传输过程泄露敏感信息，影响较低。
- D验证: confirmed / ver_d2f035a2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 157. hyp_path_3c1e5da55cfe

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52a.c:197
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够访问同一网络段，可嗅探 TCP 连接
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ case1V2 函数, recv 调用处
- 结论: 在 case1V2 函数中，通过 recv 从网络接收密码，未使用加密通道（如 TLS），导致敏感信息在网络上明文传输，违反 CWE-319。
- D验证: stage_c_preserved / ver_5030111c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 158. hyp_path_643f7cfa87a5

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_34.c:328
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够控制网络流量，可执行中间人攻击或嗅探。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ case1V2函数内; 通过TCP明文传输，未加密 @ 网络传输
- 结论: 在case1V2函数中，通过connectSocket使用recv接收密码时，数据以明文形式传输，未使用TLS/SSL加密，导致敏感信息（密码）可能在网络中被窃听，违反CWE-319 Cleartext Transmission of Sensitive Information。
- D验证: stage_c_preserved / ver_62363eef
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 159. hyp_path_152ff27f55c5

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_18.c:344
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够嗅探或监听网络流量（例如在同一网络段或中间人位置）。
- 触发路径: recvResult = recv(acceptSocket, (char*)password, passwordLen, 0); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_18.c:145-303 (case1V2)
- 结论: 敏感信息（密码）通过明文网络传输，攻击者可嗅探获取密码。
- D验证: stage_c_preserved / ver_3653f171
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 160. hyp_path_01ff25d9803e

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_68a.c:203
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够嗅探网络流量或中间人攻击。
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_68a.c:174
- 结论: 通过网络明文接收密码，未进行加密传输，导致敏感信息泄露。
- D验证: stage_c_preserved / ver_db71def9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 161. hyp_path_57e1b7c8985a

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_63a.c:196
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够嗅探客户端与服务器之间的网络流量，或实施中间人攻击。
- 触发路径: void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_63_case1() { case1V1(); case1V2(); } @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_63a.c:194; static void case1V2() { ... recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); ... } @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_63a.c:126-192
- 结论: 在 case1V2 中，密码通过未加密的 TCP 连接从网络接收，导致敏感信息以明文形式传输，违反 CWE-319（明文传输敏感信息）。
- D验证: stage_c_preserved / ver_1996fb32
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 162. hyp_path_4f4e748f07f9

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_51a.c:197
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够执行中间人攻击或嗅探网络流量，以捕获明文密码
- 触发路径: recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0); @ case1V2函数中的recv调用
- 结论: 该代码通过网络明文接收密码敏感信息，构成CWE-319明文传输敏感信息漏洞。
- D验证: stage_c_preserved / ver_332c5a4c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 163. hyp_path_598e8925f76b

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_45.c:357
- 漏洞类型: CWE-319
- CWE: CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接受害者的监听端口，并发送包含密码的数据包。
- 触发路径: recv(acceptSocket, (char*)password, passwordLen * sizeof(wchar_t), 0); @ case1V2 函数内 recv 调用处; case1V2Sink(); @ sink 函数调用处（未完全显示，但依据典型 Juliet 结构存在）
- 结论: 在 case1V2 函数中，密码通过网络接收（recv），随后可能被传递给 sink 函数进行明文传输，违反了 CWE-319（明文传输敏感信息）。尽管 B 阶段静态确认支持为 false，但源代码中存在从网络 source 到疑似明文传输 sink 的路径，且缺乏充分防御。
- D验证: stage_c_preserved / ver_d9d67a8c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 164. hyp_path_b1129e77c7c0

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_45.c:188
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P0
- 触发条件: 攻击者能够访问包含硬编码密码的二进制文件或源代码，或能够读取进程内存
- 触发路径: wcscpy(password, L"Password1234!"); @ L186; CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_45_case1V1Data = password; @ L187; case1V1Sink(); @ L188; if (LogonUserW( username, domain, password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &pHandle) != 0) @ L158-160
- 结论: 硬编码密码（CWE-259）被直接用于LogonUserW调用，密码为固定字符串"Password1234!"，未涉及网络传输，因此不构成CWE-319。漏洞路径真实可达，但利用需攻击者能访问二进制或内存。
- D验证: confirmed / ver_deba503e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 165. hyp_path_33654f07ff3b

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_43.cpp:153
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问可执行文件或源代码，或通过逆向工程获取硬编码密码。
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_43.cpp:153
- 结论: 代码中使用硬编码密码'Password1234!'，违反CWE-259（硬编码密码）安全原则，但未展示密码后续用于敏感操作或网络传输，实际可利用性较低，需要动态验证。
- D验证: stage_c_preserved / ver_303e2b5b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 166. hyp_path_08658973e1b8

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_83_case1V1.cpp:41
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问二进制文件或内存转储，但密码未被传输，利用受限。
- 触发路径: strcpy(password, "Password1234!"); @ L41
- 结论: 硬编码密码存在于代码中，违反CWE-259，但注释表明密码未通过网络发送，且B阶段未发现闭合的source-sink路径，因此漏洞可用性较低，需要进一步动态验证是否存在其他使用场景。
- D验证: stage_c_preserved / ver_2db9461a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 167. hyp_path_cb75721b7fb2

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_63a.c:222
- 漏洞类型: CWE-259, CWE-319
- CWE: CWE-259; CWE-319
- 风险等级: P1
- 触发条件: 攻击者能够获取源代码或进行逆向工程（针对CWE-259）; 针对CWE-319，需要监听网络流量或进行中间人攻击，但前提是sink函数存在明文发送
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_63a.c:131
- 结论: CWE-259硬编码密码存在于case1V1中，但密码是否通过明文网络传输的sink函数代码缺失，路径未闭合；此外没有证据表明case1V2中的网络接收数据被用于敏感信息明文传输。建议针对sink函数进行动态分析以确认是否存在CWE-319漏洞。
- D验证: stage_c_preserved / ver_fa496014
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 168. hyp_path_c6b70c330f41

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_84_case1V1.cpp:41
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者需要能够访问内存或后续代码可能将密码用于不安全操作，但本示例中无后续操作，利用难度高。
- 触发路径: strcpy(password, "Password1234!"); @ L41
- 结论: 硬编码密码（CWE-259）存在，但未发现网络传输路径，CWE-319不成立。
- D验证: stage_c_preserved / ver_25da67f7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 169. hyp_path_3cd220a11fdd

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_62b.cpp:106
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问程序二进制文件或运行时内存以提取硬编码密码
- 触发路径: strcpy(password, "Password1234!"); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_62b.cpp:106
- 结论: 程序存在硬编码密码漏洞（CWE-259），密码字符串直接赋值，可被攻击者通过二进制逆向或内存转储提取。
- D验证: stage_c_preserved / ver_79f19d5b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 170. hyp_path_1d13eafbe03f

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_43.cpp:140
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够通过逆向工程或内存转储获取硬编码字符串。
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_43.cpp:140
- 结论: 硬编码密码：strcpy(password, "Password1234!") 将固定密码写入缓冲区，违反CWE-259（硬编码密码），攻击者可逆向获取密码。
- D验证: stage_c_preserved / ver_b25e210a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 171. hyp_path_b9a0611f3373

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_83_case1V1.cpp:41
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问二进制文件或内存以提取硬编码密码
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_83_case1V1.cpp:41
- 结论: 硬编码密码（'Password1234!'）被复制到password缓冲区，违反CWE-259。虽然未发现传输或利用路径，但硬编码密码本身构成安全弱点，可能被攻击者获取或利用。
- D验证: stage_c_preserved / ver_927f6dec
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 172. hyp_path_e232f0fffee0

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_62b.cpp:119
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问程序二进制或源代码以获取硬编码密码。
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_62b.cpp:119
- 结论: 函数将硬编码密码复制到password缓冲区，存在CWE-259硬编码密码问题，但未显示后续明文传输sink，证据不闭合。
- D验证: stage_c_preserved / ver_2014dc10
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 173. hyp_path_e41ef991213b

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_84_case1V1.cpp:41
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问程序二进制文件或运行内存，提取硬编码密码; 密码被用于后续未加密的网络传输或身份验证调用
- 触发路径: strcpy(password, "Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_84_case1V1.cpp:41
- 结论: 硬编码密码漏洞：使用固定密码 'Password1234!' 通过 strcpy 赋值给 password 变量，违反 CWE-259，但缺乏后续使用路径，证据不完整。
- D验证: stage_c_preserved / ver_d959427f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 174. hyp_path_84dc10adc6b9

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_84_case1V1.cpp:41
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够获取二进制或源代码，并通过静态分析发现硬编码密码。但密码后续使用路径未在证据中闭合，需进一步逆向分析或动态验证。
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_84_case1V1.cpp:41
- 结论: 代码中硬编码了密码 'Password1234!'，违反了CWE-259（硬编码密码）原则。攻击者可通过逆向工程获取该密码，但后续是否用于敏感操作（如网络传输）未在A阶段证据中闭合，路径不完整。
- D验证: stage_c_preserved / ver_ea40053b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 175. hyp_path_4b1d76c12d5b

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_83_case1V1.cpp:41
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够获取到该二进制文件或源代码（如通过逆向工程或代码泄露）。
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_83_case1V1.cpp:41
- 结论: 代码中使用了硬编码密码，违反了CWE-259（硬编码密码）的安全要求，可能导致攻击者通过逆向工程获取密码，进而访问受保护资源。
- D验证: stage_c_preserved / ver_a4e63f1a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 176. hyp_path_9edd14bcbb99

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_84_case1V1.cpp:41
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够获取到该二进制文件或源代码（如通过逆向工程、源码泄露等）。
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_84_case1V1.cpp:41
- 结论: 硬编码密码（CWE-259）存在于代码中，密码'Password1234!'被直接写入password缓冲区，攻击者可通过逆向工程或访问源代码获取该密码，进而可能导致认证绕过或敏感信息泄露。
- D验证: stage_c_preserved / ver_533f7fb3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 177. hyp_path_044d94974d0e

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_83_case1V1.cpp:41
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 无外部输入控制，代码直接执行硬编码赋值。
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_83_case1V1.cpp:41
- 结论: 在构造函数中，硬编码密码 'Password1234!' 被复制到 password 缓冲区，导致硬编码凭据漏洞（CWE-259）。
- D验证: stage_c_preserved / ver_6885ac00
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 178. hyp_path_d8695ddcb2c9

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_62b.cpp:119
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: N/A
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_62b.cpp:119
- 结论: 函数 case1V1Source 将硬编码的密码 L"Password1234!" 复制到 password 缓冲区，导致敏感凭证泄漏（凭据可被静态分析提取）。
- D验证: stage_c_preserved / ver_9ee72371
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 179. hyp_path_6f8bfc6cdb5b

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_43.cpp:140
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问编译后的二进制文件或通过反汇编获取硬编码字符串，或者通过其他途径获得该密码。
- 触发路径: wcscpy(password, L"Password1234!"); @ CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_43.cpp:140
- 结论: 函数case1V1Source将硬编码密码'Password1234!'通过wcscpy复制到password中，违反了CWE-259（硬编码密码），但缺少password后续用于敏感操作的直接证据，路径未完全闭合，可利用性不明确，需动态验证。
- D验证: stage_c_preserved / ver_62a9b6a3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 180. hyp_path_9490b35cd0b3

- 漏洞位置: juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_43.cpp:153
- 漏洞类型: CWE-259
- CWE: CWE-259
- 风险等级: P1
- 触发条件: 攻击者能够访问包含该代码的二进制文件或源代码
- 触发路径: wcscpy(password, L"Password1234!"); @ juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_43.cpp:153
- 结论: 函数中存在硬编码密码，违反了CWE-259（使用硬编码密码）的要求。密码'Password1234!'被直接复制到password缓冲区，可能被攻击者获取并用于未授权访问。
- D验证: stage_c_preserved / ver_5954d858
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

## Unconfirmed / Failed Verification

These records are not reported as confirmed vulnerabilities. See `verification.failed.jsonl` for full failure details.

- hyp_path_0de22ef2b40b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_12.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eb6c42e8c403 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_74a.cpp:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3dd5d23a777d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_72a.cpp:159 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6682a71dd538 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_74a.cpp:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_350250c898b8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_74a.cpp:197 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_067c8eee107d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_74a.cpp:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b6fc1be5b458 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_74a.cpp:197 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_85af609df432 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_74a.cpp:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_136b229ba6aa | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_12.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0ded1e810c20 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_72a.cpp:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_39cd372f40a4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_72a.cpp:159 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d34297272d39 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_74a.cpp:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_48cd00d30c16 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_74a.cpp:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5ec4b3359840 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_72a.cpp:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_399e8cbb9cbb | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_72a.cpp:173 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_60ff87d35cbd | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_72a.cpp:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2b7729185240 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_12.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f49592115567 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_72a.cpp:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_21636d546b70 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_72a.cpp:173 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_77b9a258ca2a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_12.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d5a6ac9a8518 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_73a.cpp:197 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f7a1ba076a7a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_73a.cpp:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0449bf7ff120 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_73a.cpp:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c3dfcff703df | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_41.c:186 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1046b9df61ed | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_73a.cpp:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0456286e6a4b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_41.c:186 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_1f47a9204eb3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_51a.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_00d2115ab2c3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_73a.cpp:197 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1cbdc6484343 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_41.c:199 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_071270bce686 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_22a.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d866dbcea903 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_22a.c:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d76534453e3e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_73a.cpp:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ba85df0caeb7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_73a.cpp:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_272e16b17979 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52a.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_328cb1eacac6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_82a.cpp:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c44430c497cc | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_51a.c:184 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8fb696284426 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_22a.c:259 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fa94fbd3acdf | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53a.c:184 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_49ce3bf32252 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52a.c:184 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6f1c0ec2ed90 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53a.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5ac8314af70b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_54a.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bd130d333f54 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_54a.c:184 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_22bf472c02c7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_63a.c:184 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b3176a511477 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_82a.cpp:181 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_91c97fc988f1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_21.c:111 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eb167f799245 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_41.c:105 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d5e437c56cec | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_64a.c:184 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_53cc61a82ea0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_17.c:167 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d2da4ac7607b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_64a.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_445fcc37cd1a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_21.c:180 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e9a4197c67a1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_82a.cpp:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7353cacca3a4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_63a.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c4e28cfa0832 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22a.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7325a0c194f4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_82a.cpp:152 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b5b3c1829f0b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_17.c:196 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eadf4e1c6398 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_52a.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dcfd80ab6130 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_53a.c:155 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2d788ade92c0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_51a.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_668de861fc3b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_51a.c:155 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_58e4234269ff | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_53a.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f3f149411f29 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_52a.c:155 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5c0533e03895 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22a.c:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6476c94aedbd | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54a.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_07b187ab415b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54a.c:155 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5eea1ed72d5e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22a.c:217 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2a353f11a5b9 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_63a.c:155 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_aaaedd842302 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_17.c:196 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f7e21ddc1d1e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_21.c:346 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_904aef5e34cd | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_64a.c:155 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_89af72f3e1f7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_41.c:89 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2a2d83b6809f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_21.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_72d813de0d2a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_17.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_369e86e167a3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_63a.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ea093fa6d036 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_64a.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b4847db85e58 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_21.c:111 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_82c6f3611bf8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_21.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6c8957f8af51 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_41.c:105 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_229f8bcb320f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_17.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a22856d78053 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_17.c:167 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3aaa7ee98e32 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_82a.cpp:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_89b1e2dc3787 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_41.c:89 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c52fa7286553 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_17.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0169382973cc | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_82a.cpp:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_16866b19ce92 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_82a.cpp:181 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f8d2764ddd51 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_08.c:207 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7904b26baa2e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_12.c:281 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8cef3dce2b32 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_12.c:281 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b9174b23c9fd | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_17.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_05bf501b352c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_82a.cpp:152 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0a35d08f1c30 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_05.c:200 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d729c5b03b45 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_11.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_28c9eeb593d6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_07.c:199 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_274ab8b2014e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_12.c:259 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fa97eb2ee488 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_10.c:194 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_26d5ca74a87c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_11.c:194 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a6bfa58a7df1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_11.c:362 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_623785ef0510 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_08.c:333 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3c5a2fc1d24b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_01.c:219 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_816b12fe4c40 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_14.c:194 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e37aa158c88b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_09.c:194 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fe908b90fc8a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_08.c:375 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a4b53411fa3e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_08.c:178 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cbf64e168425 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_13.c:194 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b2615e1af42a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_03.c:194 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_57e6c184b709 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_02.c:194 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2420d13ae7cb | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_06.c:199 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4ee93eed57ba | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_07.c:367 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1d892be36718 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_05.c:368 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8b13ae66c074 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_03.c:362 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_75326ece2606 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_02.c:362 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_38c54afd73a5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_31.c:227 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_39330c4b870b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_11.c:320 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dd06c8de0439 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_14.c:362 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_863c961a645d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_15.c:207 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3bf0efe64306 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_15.c:382 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_29ff2a5112d7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_09.c:362 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_64316e0ad27c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_06.c:367 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_47dc48d778be | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_10.c:362 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_404c11ea07f3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_04.c:368 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0766b2bdefea | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_09.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b109c7658f8d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_02.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_19ef00843693 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_04.c:200 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1bbc66904a2f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_13.c:362 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2237de97559e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_14.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_736e9883528f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_13.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d5b66ebb2104 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_34.c:236 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e37c1897d22b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_10.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c56ea7e06577 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_16.c:196 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fccfb36cdd9c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_02.c:320 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7370353f6aa0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_03.c:320 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9415c887c39a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_06.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8a7113ef326d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_33.cpp:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_008ad5be52a0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_05.c:326 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bcf7acce693a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_07.c:325 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b132cb34e0d9 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_18.c:163 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_61bd04de96be | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_06.c:325 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_762b4a657ea7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_04.c:326 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_26c96f50b3e8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_03.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_370e8cd2107c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_34.c:207 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_24b5fd14bc7a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_33.cpp:202 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_14ae57287589 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_09.c:320 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_08a23ed99b4b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_31.c:198 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0bd3d1ee6203 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_14.c:320 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d136b7b12fa1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_16.c:167 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a0c36f5eb82d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_22a.c:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2267c06a68d6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_13.c:320 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_a5b1f6c2a3ef | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_22a.c:259 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_790655713903 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_51a.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b5904816d16b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_15.c:178 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_e9eace69cc45 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_15.c:340 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_195f64e6ce86 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_10.c:320 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9920926e985f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_52a.c:184 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e56176e6b3cf | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_51a.c:184 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8ea8e202f0cc | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54a.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_199de9969667 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_12.c:259 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f762a44c93fa | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_21.c:180 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_094b63c5d34e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_63a.c:184 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e4bf4b6c3b45 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_52a.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ce9a8f2c5082 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_64a.c:184 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9921a9eceacc | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54a.c:184 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c71a3a5555f3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53a.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c7ad375ca031 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_63a.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_de7db1a3cfe4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_44.c:314 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_94c74b42d264 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_64a.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bf9b4efa289e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_21.c:346 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d0b6ec3172cc | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53a.c:184 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7352d63339cf | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_22a.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7264f6f211a9 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_81a.cpp:179 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_38fdb52d8534 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_22a.c:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_da236cb85aac | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_65a.c:189 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_48be212abd4a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_22a.c:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bd39aaaa8467 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_53a.c:155 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6e1196afbce5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_51a.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6ffcc77a68b8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_63a.c:155 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ba4fd6187af2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_22a.c:217 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c5f1a4b66578 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54a.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_93d3ce727ce7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52a.c:155 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d70a1923cb86 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_51a.c:155 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a773f016c806 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54a.c:155 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c063313ef76c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52a.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c24da05528f1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_63a.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_94ba6f11aef0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_64a.c:155 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_67332119b1ee | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_64a.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_585549d8b80f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_53a.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_67223f7ea8d3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_81a.cpp:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_187e4007146b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_43.cpp:308 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ad1a60c4c584 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_65a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ff6dd2c6e658 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_08.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7217492e0e23 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_65a.c:160 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e86ecfe0e82c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_44.c:285 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_65d6392f14b9 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_08.c:375 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2a0905d93392 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_81a.cpp:150 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_154dc1153875 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_44.c:91 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9cb1197003d2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_65a.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_01c8f15508f9 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_11.c:194 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6857ebc4ce27 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_43.cpp:297 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e8bc7d4540db | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_11.c:362 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9a5caca38043 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_11.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3832dbe50f2a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_43.cpp:282 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_354c8d400a11 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_08.c:207 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5aa751acc07d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_11.c:320 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d79e94696e28 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_08.c:178 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9556c0ef1668 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_10.c:194 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_aae65b9b0689 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_07.c:199 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0bf2304e0870 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_13.c:194 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c364f1e589b0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_05.c:200 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_50fce2311810 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_11.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_edcbee35a17c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_02.c:194 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_890affc984ce | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_09.c:194 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0de17d2aa555 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_03.c:194 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9f280e773bcf | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_04.c:200 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6c06ebaaa9d1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_14.c:194 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_40b5f5bd33f9 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_03.c:362 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d32eb63e8d4c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_02.c:362 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3e18faf0582c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_06.c:199 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_472c4c4c6520 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_06.c:367 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cb9e066b2b0e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_05.c:368 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d515ccd79978 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_04.c:368 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_38df1a5b8493 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_09.c:362 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_54f02fa1796a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_10.c:362 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b4b5f8886872 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_14.c:362 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1ffcd46f4262 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_05.c:171 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cdbc6bc2e9fa | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_15.c:382 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fdb45836f148 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_07.c:367 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f02a13ec82fe | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_13.c:362 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0e314da405a7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_15.c:207 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8111ad264b6b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_18.c:192 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2f5454ac077c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_01.c:219 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_407bc53f4ecf | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_07.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1ab41de8ea1c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_09.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f1229a81a23d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_10.c:165 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_78b14f0cc7c3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_01.c:190 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_0e61296be3a2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_03.c:320 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_48358aa53caa | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_05.c:326 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ba5582420f90 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_02.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d0416b135226 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_03.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_56b6dcb8eeca | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_16.c:196 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5ab2def8af6e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_04.c:326 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_372132417831 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_13.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_20ee707f59b5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_06.c:325 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_8d0e62cc7f8a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_02.c:320 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1fce2ba7f4c6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_10.c:320 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_25b00224b81e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_09.c:320 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9103b8f5b405 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_18.c:163 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_79e6c39d515e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_04.c:171 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a23573384c70 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_07.c:325 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ed4ed57238df | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_06.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cb40d1df7aaa | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_13.c:320 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_556771525d0f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_16.c:167 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_02813e8a9092 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_14.c:320 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_34cf58f9a825 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_15.c:178 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c6d52f5693ba | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_42.c:228 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e3dc3c74a9cf | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_15.c:340 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_d6335eae356d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_61b.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_783bc7c4929f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_08.c:78 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_99b9f40d8a1a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_02.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9a7a4ce469cc | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_05.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1a1650bc5796 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_01.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_816040ef7a07 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_04.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d834af8be9db | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_03.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_587b5d761849 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_61b.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2dad95e2ae01 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_11.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8d4a9e7f1574 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_06.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_135cebc8a525 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_07.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_23fc6694f25b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_10.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7175cf7a2e0e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_16.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_292aa284ffea | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_14.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_607ae744f29e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_42.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_94020c555850 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_09.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8a8bc3161366 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_13.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2526b70136a3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_11.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c18f2526dadd | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_15.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f847f833bb09 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_33.cpp:83 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_10b366690c01 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_08.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d22aa5bd93e4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_34.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d1dc4cfb7f90 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_18.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1026ddd080eb | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_42.c:199 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bcdec03075fe | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_31.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_139780668f4b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_61b.c:139 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_51b81e855080 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_31.c:227 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5d352d1aaf17 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_02.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ae73ac674b9b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_04.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9afe29b4d0b6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_61b.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fde0d639e700 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_10.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b8feeb2cbd8b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_01.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fc2c9d4bb7d2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_33.cpp:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f47bbec7d0ca | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_05.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b446f0d4bd49 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_03.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_36192efbd5b6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_06.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dbe918937226 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_07.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bf38ce40ac3d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_34.c:236 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_59d5247d807d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_13.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d7ec696fa2dd | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_09.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c5f36f35a28d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_42.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8b2b2622a127 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_16.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5bd9946efec2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_34.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_947c2c92feca | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_15.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3d8d2ff947af | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_18.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c901acbd716e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_31.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fbbc6eb89445 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_33.cpp:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_056c325f4152 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_31.c:198 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_041aa80a1311 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_14.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8fe5ac6c4a4f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_33.cpp:202 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5690ebc05d70 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_08.c:78 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3a737b691af9 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_04.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7bbfc7d757cb | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_03.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a8e2f6535b7d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_11.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d3bc6b215617 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_01.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c9d3406d9fcf | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_10.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_478706cd2663 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_02.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_681def79cace | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_06.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5c6270d02758 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_34.c:207 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_f294d6d14a0d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_13.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b84c1c7c1290 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_09.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b430ea43c088 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_16.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a43a5a11b1b8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_14.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0c318081da65 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_01.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8ed97c1e8b98 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_05.c:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_425951ab5d62 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_15.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ddb5a2705710 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_04.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_81cbe47995c1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_05.c:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3b2b27c77729 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_03.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e56ccc4a36c5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_18.c:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6a2f2922f947 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_02.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6736d7bbeb46 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_09.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_10edb791bc13 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_06.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f065631732ee | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_07.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5beec96c5841 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_13.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5a0c8a5f3f2d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_32.c:212 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_287914290a3e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_14.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f151524a7bd8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_15.c:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eadffe751f8b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_07.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_157cb075e65f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_18.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dac1f52aab81 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_32.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_416c27d75a68 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_16.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f8d156104cb9 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_44.c:314 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a2c7354365d7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_81a.cpp:179 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_000cc1cbf493 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_81a.cpp:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_be86184bd7e7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_32.c:217 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_49bfbd88452e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_32.c:217 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3d1827a97c62 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_32.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_13b45a13dbc4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_34.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2745918ce15e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_31.c:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a49aa0050875 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_44.c:107 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_28d233f66929 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_32.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dfbe2e207e24 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_65a.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1f70e03884f3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_10.c:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_26245cf90974 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_65a.c:189 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_aa4c08c67746 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_45.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_aea78531297a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_67a.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_727bf0f70343 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_45.c:294 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_210a0e4554ad | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_67a.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9022665f7d0b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_68a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_55625b941ba1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_68a.c:166 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b2e7136634d8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_66a.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_342c773e5250 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_81a.cpp:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_66ed89b4228a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_43.cpp:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_732821efcf8e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_33.cpp:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9af72fa56f3c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_81a.cpp:150 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cf58d83882a7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_34.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d8c39dbafe4d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_33.cpp:83 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0354538a4580 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_43.cpp:205 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bd11230fc0a2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_31.c:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a3d532bfcb64 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_84_case0.cpp:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c8b15810bed1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_62b.cpp:141 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c5b27d066d51 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_66a.c:166 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3eb84b1d129f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_62b.cpp:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2ba9292dcbfa | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_83_case0.cpp:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b00e622ac021 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_83_case1V2.cpp:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_665f07b558f1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_44.c:285 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6b4c8b1eda73 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_84_case1V2.cpp:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_69e686007461 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_45.c:86 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2b6d2b0a5712 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_66a.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f692c2d13517 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_45.c:289 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_222a8708997e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_44.c:91 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ce75ccadd6c3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_45.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b613114f6f72 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_65a.c:160 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d353f086b375 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_65a.c:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3b5a37cb898d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_66a.c:161 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_52da85b55086 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_67a.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bc9cb19c981e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_68a.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6a3b3e9763bc | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_67a.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b7af5c83b87f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67a.c:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8f6bb7d66ccc | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_68a.c:161 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_896377483143 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_66a.c:166 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d43f7f16a903 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_45.c:294 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6999062c36a2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67a.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9e5e52e623c5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_66a.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c2844cfb3401 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_62b.cpp:136 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_27fe24955132 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_42.c:228 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b2ac0ab36244 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_68a.c:166 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6abf2e4951cd | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_43.cpp:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_680e3de282a7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_83_case0.cpp:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4076c60212fb | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_42.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6117f001e55f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_61b.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5b2c41708a7d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_61b.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_34ad11e3a0e4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_83_case1V2.cpp:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_864c0ad0e505 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_84_case0.cpp:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e066f75fccd2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_68a.c:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2a78f75c046b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_84_case1V2.cpp:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bbfd40b1ffe3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_62b.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_98d46a8d9906 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_43.cpp:200 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f5edd8e7e508 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_83_case1V2.cpp:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_23a0f07a8bc7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_43.cpp:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a4b2d6b6f7e2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_84_case1V2.cpp:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b9635ca3ab74 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_43.cpp:205 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4e1d6abcdcf6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_83_case0.cpp:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7c76694422f3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_42.c:199 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_365e3108a413 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_84_case0.cpp:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_68bd3b760e69 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_42.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7b91a1cbd230 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_61b.c:139 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c79a416b7f6f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_32.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e2d98ca883a5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_45.c:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_29d445120468 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_66a.c:161 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_260c7eeb89eb | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67a.c:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9d6df3c0ef1d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_61b.c:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8599315905df | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_68a.c:161 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c0b5798a7f93 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_45.c:289 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_19091a38d5f6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_66a.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b6df3ab9d46b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_68a.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_194aff571df3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_62b.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_233ce54ece5a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_62b.cpp:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_054d24d5e8d2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_62b.cpp:136 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_32ea9fc03e8e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_43.cpp:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a4d1939519a5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67a.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ad863eec818f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_62b.cpp:141 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c782850baf5e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_84_case1V2.cpp:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ce13d208d585 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_83_case1V2.cpp:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fff2439311d6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_84_case0.cpp:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_51e8aabe2b73 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_43.cpp:200 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_65bda4e3c15b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_83_case0.cpp:63 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_828e3121e666 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_43.cpp:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9bbe117ffef0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_43.cpp:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c3abdc02117b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_73a.cpp:443 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_31177e52ebc6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_42.c:297 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b7951ac03b1d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_43.cpp:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0f3f2bd7dd08 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_42.c:327 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ba57b258b3cb | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_43.cpp:79 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a9bdccb8a5ed | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_42.c:282 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_57fce2c05031 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_42.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a0e85447b5a9 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_42.c:67 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1d9a2e5627d6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_62a.cpp:147 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3fc8dc24df50 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_62a.cpp:166 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_210faf04a298 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_61a.c:166 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c4e730614c87 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_61a.c:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e57ef54c1540 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_42.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5ac8936c3db4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_61a.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2fbc4fb3fb89 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_42.c:323 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_03c50f56a6b2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_62a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ea58747c854a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_42.c:76 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e6926d73bff3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_61a.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_28eee9a9ea48 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_62a.cpp:166 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a7100cab9783 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_61a.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a381fef0a73b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_61a.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8396858aa540 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_61a.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6b87c0382581 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_62a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e7d20a0dc7e3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_62a.cpp:91 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8c873cac9556 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_61a.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ed4d4112c347 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_61a.c:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d91af443f0da | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_62a.cpp:91 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f450edcd384f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_43.cpp:177 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2cefaffcd8c7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_62a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a91b112a1ba0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_62a.cpp:91 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2315e2349433 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_62a.cpp:91 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_62e5a97f1de2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_43.cpp:164 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6b7e149fc293 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_61a.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8b708dbce88c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_61a.c:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_590e81000b03 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_62a.cpp:147 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_25a75806fc62 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_73b.cpp:150 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_908016501e18 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_43.cpp:177 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_229eb66b7947 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_62a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_274dfea609b4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_73b.cpp:135 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_420ee4496db8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_74b.cpp:154 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8105fee0cd73 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_73b.cpp:150 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2aa3f476bce5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_74b.cpp:150 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_862f6b03ef4e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_74b.cpp:154 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a1b77bd5963d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_64a.c:119 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_21a770738de1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_74b.cpp:135 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1df6ca4e7b3c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_72b.cpp:150 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1377c1f12870 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_72b.cpp:154 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1365ea08f0c4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_84_case1V2.cpp:156 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_06e3f23af5ae | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_22b.c:116 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_31ff4f82fe0a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_21.c:220 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5ff764ca7540 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_84_case1V2.cpp:154 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_85144faab754 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_51b.c:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0f52339ba566 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_21.c:345 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_124c8048c72b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22b.c:215 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_333ac117cee4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_84_case1V2.cpp:141 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2c79389bf37b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_53d.c:147 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1249f5969661 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_81_case1V2.cpp:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1de7908bf26e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_64b.c:159 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0d35298caa7e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_41.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1d9e851deb8b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54e.c:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1558920d79b7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_63b.c:150 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2bef064a3203 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_66b.c:136 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1d886e23df69 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_41.c:239 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_08d05d6cb91c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_21.c:390 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_17fd0910682d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_68b.c:158 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4171bacbb1c7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_52c.c:147 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_29a94f5fce5e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_22b.c:200 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0b7b6866b52b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52c.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9695e51ab4cd | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_45.c:233 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6a947dd7e0e3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53d.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_308e99317483 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_81_case1V2.cpp:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6557f363c685 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_82_case1V2.cpp:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_181a825d8093 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_64b.c:163 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_512ed7338381 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_44.c:234 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cbaed252ded6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_54e.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6a8355a2f9a2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_67b.c:155 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2299d12dd5ae | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_51b.c:147 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1bdd38b963d9 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52c.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_11fe2dfdfd23 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_51b.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_62f67fa3bb74 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_65b.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2d48dc536c83 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_52c.c:147 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0011899e4761 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_53d.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a6b5b5944692 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54e.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6226e13a9dc7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_66b.c:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2135b5f02c6e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54e.c:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_270a3b64daff | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_63b.c:135 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b075a5f16211 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_41.c:239 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4f89384251c0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_84a.cpp:45 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_18de90467a3f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_82_case1V2.cpp:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2a8e69e32b7b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_84a.cpp:45 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5508d04c900e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_22b.c:215 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7f284c159c5b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_84a.cpp:45 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_93a3d4698f85 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53d.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9c0a66a7ed15 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_68b.c:158 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_790401ae571a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_82_case1V2.cpp:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_df8670f036c0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_74b.cpp:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4c78e887c194 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_45.c:252 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_30f085b85d00 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67b.c:140 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_26fea0177ff5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_81_case1V2.cpp:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_daa68a7e4f18 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_74b.cpp:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3b7a01f61a8a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_74b.cpp:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b158f05224d7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_74b.cpp:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b2aef85d54f1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_74b.cpp:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bbb29f14c450 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_74b.cpp:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7da3d51e3a2e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_74b.cpp:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3513606736e1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_74b.cpp:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_87199ae3bcdd | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_17.c:315 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1c5d9af27a52 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_42.c:176 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ca9d14b20b8c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_17.c:341 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_634018f71b52 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_11.c:472 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b0d9ab93eee8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_12.c:588 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_61c1e54895f2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_17.c:341 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d0bf764869ee | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_17.c:315 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_43c367d6eae7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_12.c:574 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7ecb551f686e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_42.c:176 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c05f6292d2e5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_08.c:485 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5ec5b005c32c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_12.c:588 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_982ba5e2cc18 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_11.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_77c94ba51856 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_11.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b8153b7df967 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_12.c:549 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c1ebdbbc8395 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_11.c:550 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_19a1f392de4b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_11.c:472 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1b2b8bb14a53 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_08.c:485 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_be8fe4a5586b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_08.c:563 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b18a1956dd19 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_08.c:524 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e30a26525e1d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_08.c:524 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_34d807fd5441 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_11.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_32d115e2c81d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_08.c:524 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1f52129c6684 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_10.c:472 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bb44d32a9814 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_05.c:478 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_140273405dc1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_13.c:472 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1b9bed0c18d9 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_08.c:524 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_698c51781e7b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_07.c:477 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ff38fc379289 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_13.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_034b71eef46a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_09.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f59f766aafd0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_11.c:550 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5ce218185857 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_14.c:472 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4fecb777ede4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_05.c:517 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bd3c635f45a1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_14.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_01505009392a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_05.c:478 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_51261e7d084e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_10.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9a56dce665ee | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_09.c:472 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_875363eba69e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_09.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8c94338db687 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_09.c:472 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d3d23193f8ac | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_07.c:516 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_01ee3015a29b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_07.c:516 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0205220e6970 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_07.c:477 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f70a2d6031ae | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_13.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_436b0f52cb79 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_10.c:472 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_af1fad85cdc0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_14.c:472 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9b4e4ff354c5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_03.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_db7da4185998 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_13.c:472 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7d3d53ad0b04 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_05.c:517 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7cfed2eee86f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_01.c:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4790f6dc6ce6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_08.c:563 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f312661f796d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_02.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f00772165372 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_14.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_90f5e1e60dac | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_05.c:517 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d057a66e8e2e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_10.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2398c059f7f4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_04.c:517 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2e4ed5807e11 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_04.c:478 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_14c167f65e0e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_02.c:472 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_53aa840c3358 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_06.c:516 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e7cb99dccc0a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_03.c:472 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_24c6e017de4d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_07.c:516 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_43ecb2d906c9 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_10.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ba4ac478a3cb | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_13.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_72e21bf147d2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_06.c:477 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d84499735d7b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_01.c:164 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b567ab456281 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_15.c:505 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d70a2ec835e8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_16.c:317 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_51f629f25e92 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_18.c:307 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_420fec67c4ac | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_03.c:550 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fe9ace0606a2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_14.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_70fb1235009f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_09.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f17dd9cf26ef | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_15.c:556 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_16910ef510dc | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_06.c:555 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_961f380b64fa | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_04.c:556 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_777829b16f26 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_03.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ef06a856da16 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_04.c:517 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f655d4c2cfba | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_02.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_34f831952b0b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_09.c:550 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_32d713308e4f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_06.c:516 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_aa129980e101 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_02.c:550 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_941555cc3705 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_05.c:556 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2c858c899be2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_10.c:550 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_188b7e62969a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_15.c:544 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6a92dac48639 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_01.c:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a4a6ae8c6274 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_03.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1d0aedad6ff1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_13.c:550 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c63011f2947d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_06.c:516 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c6b60d0f7010 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_07.c:555 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c959bdd18184 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_16.c:343 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3e59fcd894c2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_02.c:472 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9174d67bf6a1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_15.c:595 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d28315b78675 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_05.c:517 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_da08b2707d26 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_14.c:550 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_72d7e3f4cd50 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_02.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2e5002cf5ba5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_04.c:517 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_34d954ae6a99 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_06.c:477 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e4e022b5debf | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_03.c:472 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_359af4c9289a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_18.c:333 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eb9d0612a500 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_04.c:478 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5988127c56fc | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_07.c:516 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5faf40c659e8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_09.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ab4beb48cdd8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_03.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_aa1158525660 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_13.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dc51edf19cec | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_10.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_86973a83e9a3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_18.c:307 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a3a9f5de93f3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_02.c:550 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1483e085aaa8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_15.c:556 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3af92a1f6b4e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_05.c:556 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f672d0cad5e4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_06.c:555 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2d92f470d4c7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_15.c:505 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bc10dc8354a1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_03.c:550 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cadf3152d466 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_01.c:164 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a4260421bccf | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_02.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c58dde808e44 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_04.c:517 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_784fb60ab6c9 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_14.c:511 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a4889f712f08 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_06.c:516 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_341e7af74250 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_16.c:317 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_88edee2864df | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_04.c:556 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_620c7a5e23da | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_31.c:158 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c7eef4b3debd | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_15.c:595 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_39961eb2c479 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_14.c:550 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cb6be8145b41 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_09.c:550 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_540778d12dbd | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_33.cpp:161 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c7d3be3e3aec | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_18.c:333 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3522a3fac841 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_15.c:544 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dfd74b8dd0ca | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_10.c:550 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7621f2e3b92d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_16.c:343 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eb39c6349c1b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_34.c:166 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_20e9fda2b967 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_34.c:179 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_92d14d5b5529 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_33.cpp:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6d3fc80417ec | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_31.c:171 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8d21e965fd82 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_13.c:550 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d939cb84d0b2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_31.c:171 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3fc1c07d1c25 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_33.cpp:161 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_90e5a157a365 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_83_case0.cpp:118 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b35ac1823140 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_72b.cpp:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cfe98c579f6c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_84_case1V1.cpp:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d37710c96252 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_34.c:179 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_18fc42ec4287 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_84_case0.cpp:118 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_04cea56deeed | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_73b.cpp:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e99caa96d448 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_73b.cpp:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5571d3b41445 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_07.c:555 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a8bdc79f5944 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_83_case1V1.cpp:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cf6c12d153df | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_72b.cpp:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_70b237fb5167 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_32.c:181 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_084898dad1c6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_83_case1V1.cpp:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c5a4b94a53f5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_73b.cpp:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7a2ae84bedef | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_32.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_08772776b2d1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_72b.cpp:84 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_64e9cd795eab | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_83_case0.cpp:131 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1ef5a280bdbe | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_73b.cpp:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8b75b19120f1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_33.cpp:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b10254bad353 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_72b.cpp:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4f648f3bfcf0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_72b.cpp:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ca859e04a3fd | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_84_case0.cpp:131 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9b87e40c2b1b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_84_case1V1.cpp:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_196a638d161a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_84_case1V1.cpp:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6008bc86830c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_72b.cpp:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7f3123328f89 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_83_case1V1.cpp:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c6a266016e3f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_32.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f4dc7f952eea | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_83_case0.cpp:118 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1df9e4d1197f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_73b.cpp:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6d5e56315c3e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_84_case0.cpp:118 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5aaebcedc038 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_33.cpp:322 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2599d8547e87 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_73b.cpp:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_47503dd019ed | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_72b.cpp:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_165345c54a03 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_84_case0.cpp:131 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f233fcc5f953 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_84_case1V1.cpp:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6721f147a104 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_83_case1V1.cpp:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4141122041d8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_73b.cpp:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b7c566ce5779 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_32.c:181 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_598b5d5cd2c4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_83_case0.cpp:131 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a33318e3e909 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_72a.cpp:213 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d08762168ae6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_72b.cpp:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_10fffbcc36a5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_67a.c:127 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4d8ee06696e4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_74a.cpp:213 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_00f8cf202590 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_43.cpp:324 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e190667c0b40 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_83a.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_33d639ccd948 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_83a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_08906a8c12ff | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_83a.cpp:31 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_1d513dbcd51a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_33.cpp:347 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7b3ab42803c0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_84a.cpp:62 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3ddbf7bfd80d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_62a.cpp:190 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4eda7af59a00 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_43.cpp:351 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8dc617dddd2e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_83a.cpp:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_20aa940617fd | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_72a.cpp:238 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5798e6105fda | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_84a.cpp:61 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8dc8f05b4a7b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_81a.cpp:219 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_878b701f57e0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_83a.cpp:31 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2f0b2a25e05e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_33.cpp:321 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_77c089fc551a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_82a.cpp:221 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_320d79778060 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_62a.cpp:190 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b795a1c008d2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_74a.cpp:238 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_120cff121464 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_43.cpp:325 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_64b583d23d28 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_73a.cpp:212 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_54af806143e8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_72a.cpp:212 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e00e4d904416 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_83a.cpp:45 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_ccb9fa4e02a5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_74a.cpp:212 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_21040262a89e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_82a.cpp:196 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d8cb02651586 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_43.cpp:351 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b20148b9421c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_83a.cpp:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_322da1af613b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_83a.cpp:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2a303134d325 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_81a.cpp:192 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6a1b6924c53b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_21.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4ffca98a8911 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_82a.cpp:222 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6994540efe43 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_83a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_166368f8d6ad | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_74a.cpp:239 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3ffbba48e2c3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_81a.cpp:219 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_62e79e687a7d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22b.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b8976f9c379c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_41.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1765ff1bd033 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_84a.cpp:62 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_5a878bd301dd | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_33.cpp:348 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_725a5212ca17 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_73a.cpp:239 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5b22d767aa04 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_44.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5bb6479cf165 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_45.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0dc84a3e954f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_44.c:153 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_04077eda2ed5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_21.c:475 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e4bae235c03c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_45.c:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f906a87a7876 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22b.c:261 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4997fb292055 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_41.c:150 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b2423c5065d2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_52c.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d33317d39bc4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_52c.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6fff3b05edc4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_51b.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c90d7be23892 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_51b.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d6fb328d8b6c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_64b.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_77cbb3e1ea17 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_53d.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f6c0c5aa4817 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_53d.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d82c19f7b711 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_64b.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cab4bacbeb02 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_63b.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_beeb7272fa86 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_68b.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0ad4cd90f7e9 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_63b.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e2adfb76c1c2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54e.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_67b01e5ce8d7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_66b.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_deed54d5582a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_81_case1V1.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b2d14407a1fb | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_67b.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5b511b258a83 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_65b.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eafc26980086 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_65b.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2012cd774735 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_67b.c:89 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2610e6c132bc | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54e.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e4956438fb9e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_66b.c:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_31de4729cac4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_68b.c:88 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bb41b468e5e9 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_21.c:514 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_57b56173c4b2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_21.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4679ab2cea6c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_81_case0.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_115acee36159 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_82_case1V1.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9bfbd976dde1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_22b.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b53594c78d34 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_22b.c:261 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_02ecbada3731 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_41.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_51c041a4648e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_41.c:163 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a13bf549cf03 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_54e.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f40d08fa4df3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52c.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_982ab40c16d4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53d.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_55563b8feff3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_44.c:166 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0d90f1fb4bc0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_82_case0.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8190e13c046f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_45.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4462ca57d896 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52c.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cf67d828f87e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_51b.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_da7c44652826 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_44.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0cb65c6a4cd3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53d.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e6422ae84001 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_51b.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_91aad1b3461b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_45.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c23ec9a78862 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_63b.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cdadabba8729 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_54e.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ee539f2e41cf | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_63b.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a5f85697a10e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_64b.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d688b0214863 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_64b.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_31290b5ac393 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_66b.c:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a492ecfdce57 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_68b.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_699014174f56 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_65b.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cc2cfd3dd953 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_66b.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5cc3551563b9 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_81_case0.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b486fa4a0ae9 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_21.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6dcd3be233bd | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_67b.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_01d5e220cb03 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_67b.c:89 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_13cd9a8f48da | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_81_case1V1.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_95a1aa3f0cbc | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_22b.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1ede6e6bc781 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_41.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_161fba9306a5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_82_case1V1.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c2400437e1dc | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_65b.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8d4830c4631c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_82_case0.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bc3591ec8c71 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_21.c:475 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8195446776f6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_68b.c:88 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c74183a77624 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_22b.c:261 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7b78b5d0a9e1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_44.c:153 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b315eac58518 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_45.c:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3f3e9846bd72 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_41.c:150 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7d9201f05f15 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_53d.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c4afdb68c728 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_45.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5e3e111b183f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_44.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b2ce0dd68752 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_51b.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_82428853b20d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_51b.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_24bde52f0b97 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52c.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_68da94e67818 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_65b.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9aa35b0a51a8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_65b.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_27758c31408b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_63b.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_304d617ea287 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_66b.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6c336f918566 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52c.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_afec369b8198 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54e.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a396b21e2d52 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54e.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_24011079a5b5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_64b.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7fb2c4299264 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_64b.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_73730ef5e6c1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_66b.c:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d6dd1562cd5a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_53d.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_65e713f969b6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_68b.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cc8729233a15 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_68b.c:88 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f06e5db7f210 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_82_case0.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c658d2d764cf | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67b.c:89 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_82bc6b5c4384 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_81_case1V1.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ba5b556ffc81 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_63b.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d24d150ffa2c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67b.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_afd1b0ba020e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_21.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ff6f3b64a396 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_41.c:163 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7a62ca051389 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_82_case1V1.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b53e773144af | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_81_case0.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7f9b119e2455 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_44.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7ea3c92d9d6b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_21.c:514 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_955ef7552f39 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_41.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_59fc81378aba | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_44.c:166 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_045bd569975c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_51b.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f8375faad0bb | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_52c.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d933b39f350b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_22b.c:49 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9735848143f6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_52c.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_abd7e7684e60 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_51b.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_09d4a521596a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_45.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cd2d2b066a46 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_22b.c:261 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f0552e37f71c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54e.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f78a3145e9d3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_45.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b504812b7e00 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54e.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_40f588c7e348 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53d.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bdae6a031ca2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_63b.c:52 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8bc374d52d2a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53d.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_557e05950c7d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_64b.c:55 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a39ce86a3978 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_65b.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ed3293b949dd | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67b.c:57 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_588515338b17 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_66b.c:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eb1a66193bd7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_64b.c:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_87829a513e61 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_63b.c:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e458796ddd1d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67b.c:89 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bbb4c36e1014 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_65b.c:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_39d455d07845 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_66b.c:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f843d0856841 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_68b.c:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ac990a00eecc | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_68b.c:88 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6b1ca55b0582 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_81_case1V1.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_06a5ef7f436b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_81_case0.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e4113393e11e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_53b.c:51 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_06940a2b66b5 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_82_case0.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d50aa98e27c9 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_82_case1V1.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d18a1153c4f7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_53b.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_12a6cf7216b0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54b.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b138787e79c6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54b.c:51 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_9765616d5073 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54c.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9edb16f064c2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_53c.c:39 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_eb605e3cbe7b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54c.c:39 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6047f439e51f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52b.c:51 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_699ceac4c503 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54b.c:39 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_6edb05ccd903 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52b.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b12e2e8bd0c4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54c.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_af1f492b4fc0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_54d.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_883b2cd15e7d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_53c.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_25c71c35e48b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_54d.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bf91a09baf4a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_53c.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_8b2842dd6a43 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_54c.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_1596c855ab23 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_54b.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_bc853ab23c2a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_53b.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_af0a489a56fc | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_54b.c:39 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_44739cdc55e1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52b.c:51 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_d0dcc16902ec | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_54c.c:39 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8249f227b620 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_53c.c:51 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_bc5b265144ce | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_54d.c:39 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_f623fe256a98 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_53b.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b049792166a0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54b.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_abade6bf3b17 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_53c.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_94e157e55652 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54d.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_8be7beb8aab4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54b.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d62ba28a8e49 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54c.c:59 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f59056f91888 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54c.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6eed467df6c1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54d.c:39 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_344957589434 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54c.c:39 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_bb0b0780dbb8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53b.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_eb6239fde204 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_52b.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2b89976eb1cd | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53b.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_832660d3d124 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53c.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5a48807db90c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54c.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_175e2aa93055 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54d.c:39 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c420973a0ea1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54b.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_bd6dd18539df | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53c.c:59 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_40e5479b9356 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_61b.c:108 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_70046597b7ac | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54c.c:51 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cb4054f489e8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_65a.c:136 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_42324513044b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_06.c:528 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_402fd02d4523 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_08.c:538 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0bb737ea9686 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_11.c:523 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0e4a7a0d44e4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_10.c:525 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0d91b3c39ceb | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_06.c:567 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5a9fdc51fb2a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_02.c:562 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_143a4a682761 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_14.c:564 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_06298811c62d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_03.c:563 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0e5d54667f28 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_07.c:567 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_46228d1aff9d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_08.c:578 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0888a87951bb | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_13.c:564 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1471d768bc4b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_11.c:563 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_411ce8af208f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_05.c:569 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_75667b0ec11f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_15.c:613 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_511b2fa81b3e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_10.c:564 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_06c0da4db21b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_06.c:528 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_48db52c232d3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_15.c:573 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7cb8c625941a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_02.c:525 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1bcc4a3fce81 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_14.c:524 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1a492995c7df | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_10.c:523 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_020de59a6b85 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_05.c:569 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1755a3787e1b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_08.c:578 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_285883bef6c6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_03.c:564 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1468c0fcad52 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_11.c:524 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_01650d1c8287 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_06.c:567 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_27127246d6a7 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_07.c:528 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4cb2ac9f6b03 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_11.c:563 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_869a7315982b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_21.c:539 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9da3512ae94e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22a.c:276 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_6e05fb4205ea | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_09.c:563 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0151b597c912 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_07.c:570 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_26c57596d172 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_15.c:614 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_308f83ab7734 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_22a.c:314 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9f5c1155f25f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_17.c:327 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_753b81a1e402 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_22a.c:276 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_25bda7d49cce | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_22a.c:314 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a40f2f7fb260 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_45.c:332 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2508db617fda | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_13.c:562 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a35b74d77d51 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_16.c:331 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_67ba392f33e1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_51a.c:197 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_564416a92efe | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_42.c:325 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1995f64168db | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_34.c:327 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_14908251aef2 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_61a.c:193 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_18a41175c329 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_63a.c:197 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4ee7638dde88 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_64a.c:196 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_90a58125e01c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_17.c:354 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_51716ea5e19d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_12.c:625 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_56876035e886 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_31.c:345 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4c17222dc860 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_66a.c:203 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_565078f29d9a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_01.c:332 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_9a157466dc35 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_68a.c:204 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_66b042e5c733 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_16.c:357 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5cb7186da07f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_67a.c:208 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_69370f104cc3 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_32.c:360 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2765a0caf7fb | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_34.c:353 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_044de4aea707 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_45.c:358 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_2c112e95fdc6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52a.c:223 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8db7beb61eee | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_44.c:353 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0028afb0708b | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_41.c:348 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_173aa8415a42 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_51a.c:222 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8bbabc2533c0 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_54a.c:222 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1b89bf055c33 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_65a.c:228 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_09341a307c13 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_61a.c:193 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_337c106ed5e4 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_66a.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7fbb418fd30f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_68a.c:229 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8bd088eb1ba8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_12.c:586 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d1228d13791d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_18.c:319 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_098966ef8a03 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_01.c:307 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_937d4a8cb05e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_67a.c:233 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_71d17e672acf | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_64a.c:223 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9fd513eb3746 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_41.c:322 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_191891e31172 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_17.c:328 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_409eaab7bd7c | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_63a.c:223 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3e3dfde01c6a | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_44.c:326 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_31e6b938c686 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_32.c:334 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_84da21fa1a2e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_16.c:330 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_44885b6d6cbd | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54a.c:197 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_aa72c7647565 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_45.c:331 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_27c9dc8f44df | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67a.c:208 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_48a5c3ad8b32 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_12.c:625 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d35e253102db | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_65a.c:202 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_79c989583b65 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_01.c:332 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7753a47cd20f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_66a.c:204 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5e764bece899 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_53a.c:196 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3a222479a334 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_32.c:359 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_203012474290 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_61a.c:194 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3cfd6565f514 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_64a.c:196 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_671d624b4307 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_41.c:348 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_253149ee5c97 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_16.c:357 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_8c8d8d7fc8a8 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_17.c:354 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_df8b186790ee | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_44.c:353 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1558ccf25196 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_42.c:350 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a23aab729b55 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_64a.c:223 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_85b52d79777e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53a.c:223 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_732f0c94f3f1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_67a.c:234 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0ba107de934f | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_31.c:345 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_15da6f7c476e | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_34.c:354 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_48c7a9a85158 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_65a.c:228 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3b9ca2a47561 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_61a.c:193 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_05c9c5b4b2f1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_66a.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d9de956423fe | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54a.c:222 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1f3281005d09 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_51a.c:223 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c2db5b891e4d | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_52a.c:223 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_97e94da01936 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_68a.c:229 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7b3bf363a4a6 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_62b.cpp:106 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_00062ff8dec1 | juliet-api-misuse/testcases/CWE319_Cleartext_Tx_Sensitive_Info/main.cpp:259 | NOT_ROUTE_BOUND | payload did not satisfy oracle
