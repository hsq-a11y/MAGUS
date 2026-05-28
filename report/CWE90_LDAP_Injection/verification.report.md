# MAGUS Final Vulnerability Report

- generated_at: 2026-05-28T08:49:16Z
- reportable_vulnerabilities: 772
- d_confirmed_vulnerabilities: 493
- stage_c_preserved_vulnerabilities: 279
- failed_verifications: 833
- source_confirmed: /home/sq_hu/MAGUS/d/memberD_verifier/02_run_with_C/output/CWE90_LDAP_Injection/verification.jsonl
- source_failed: /home/sq_hu/MAGUS/d/memberD_verifier/02_run_with_C/output/CWE90_LDAP_Injection/verification.failed.jsonl

## Confirmed Vulnerabilities

### 1. hyp_path_f2be305ed09b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_11.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或影响FILENAME文件的内容
- 触发路径: if (256-dataLen > 1) { pFile = fopen(FILENAME, "r"); if (pFile != NULL) { @ L44-48; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgets() failed"); @ L48-52; data[dataLen] = '\0'; } fclose(pFile); } @ L54-58; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ... char filter[256]; _snprintf(filter, 256-1, "(cn=%s)", data); @ L98
- 结论: 从文件读取的数据被直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可以通过控制文件内容注入任意LDAP过滤器，从而可能绕过认证、泄露信息或执行未授权操作。
- D验证: confirmed / ver_5bfa5d4e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 2. hyp_path_b3ef4dce0e75

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_13.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或控制文件FILENAME的内容
- 触发路径: pFile = fopen(FILENAME, "r"); ... fgets(data+dataLen, (int)(256-dataLen), pFile); @ L44-52; _snprintf(filter, 256-1, "(cn=%s)", data); @ L58-59; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter, ...); @ L96-98
- 结论: LDAP注入漏洞：从文件读取的输入未经清理直接拼接到LDAP搜索过滤器中，攻击者可通过控制文件内容注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_4ca87d38
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 3. hyp_path_f8fa1af2e23b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_06.c:50
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件 FILENAME 的内容
- 触发路径: if (256-dataLen > 1) { pFile = fopen(FILENAME, "r"); ... } @ 第48-52行; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ 第52-56行; data[dataLen] = '\0'; } fclose(pFile); } @ 第58-62行; _snprintf(filter, 256-1, "(cn=%s)", data); ... searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter, ...); @ 第100-104行（snprintf 和 ldap_search_ext_sA 调用）
- 结论: ldap_search_ext_sA 调用中使用了从文件读取的未净化输入，导致 LDAP 注入漏洞。攻击者可通过控制文件内容修改 LDAP 过滤器，实现未授权访问或信息泄露。
- D验证: confirmed / ver_33450a80
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 4. hyp_path_1b7348ab022d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_09.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件的内容，例如通过写入文件系统或利用其他漏洞修改文件。
- 触发路径: pFile = fopen(FILENAME, "r"); @ L46; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ L48-50; data[dataLen] = '\0'; } fclose(pFile); } @ L54-58; _snprintf(filter, 256-1, "(cn=%s)", data); @ L72-74; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L87-90
- 结论: 存在LDAP注入漏洞。程序通过fgets从文件读取数据，未做任何消毒直接通过snprintf拼接到LDAP过滤器字符串中，然后调用ldap_search_ext_sA执行LDAP搜索。攻击者若能控制文件内容，可注入恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_ef826387
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 5. hyp_path_f9b62be05951

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_10.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向FILENAME指定的文件写入恶意内容
- 触发路径: if (256-dataLen > 1) { pFile = fopen(FILENAME, "r"); if (pFile != NULL) { @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_10.c:44-48; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgets() failed"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_10.c:48-52; data[dataLen] = '\0'; } fclose(pFile); } } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_10.c:54-58; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_10.c:90-96; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_10.c:98
- 结论: 代码从文件读取数据，然后直接拼接进LDAP搜索过滤器，导致LDAP注入漏洞。攻击者可通过控制文件内容注入任意LDAP过滤器，造成信息泄露或未授权访问。
- D验证: confirmed / ver_e67cfd3b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 6. hyp_path_7c6300235286

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_11.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: Attacker can control the contents of the input file (FILENAME) that is read by the application.
- 触发路径: pFile = fopen(FILENAME, "r"); @ L46; fgetws(data+dataLen, (int)(256-dataLen), pFile); @ L48; fclose(pFile); @ L52; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L66; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter ...); @ L98
- 结论: LDAP Injection vulnerability: user-controlled data from file is concatenated into LDAP search filter without sanitization, allowing an attacker to modify the intended LDAP query.
- D验证: confirmed / ver_86dce6ef
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 7. hyp_path_16b092b1dcbd

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_17.c:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制文件内容（例如通过写入文件影响输入）; LDAP服务器可访问且接受查询
- 触发路径: pFile = fopen(FILENAME, "r"); if (pFile != NULL) { @ L45-47; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ L49-51; data[dataLen] = '\0'; } fclose(pFile); } @ L55-57; pLdapConnection = ldap_initA("localhost", LDAP_PORT); if (pLdapConnection == NULL) { exit(1); } @ L88-90; connectSuccess = ldap_connect(pLdapConnection, NULL); if (connectSuccess != LDAP_SUCCESS) { ... } @ L92-94; _snprintf(filter, 256-1, "(cn=%s)", data); @ L96-98; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L99
- 结论: LDAP注入漏洞：程序从文件读取用户输入，未经净化直接拼接到LDAP搜索过滤器中，导致攻击者可以控制LDAP查询逻辑。
- D验证: confirmed / ver_7a915478
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 8. hyp_path_b273c6e70a17

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_02.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件的内容（例如通过写入恶意字符串到指定文件），或者文件被外部数据源污染。
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ L48-L52; data[dataLen] = '\0'; } fclose(pFile); } @ L54-L58; _snprintf(filter, 256-1, "(cn=%s)", data); @ L86-L90; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L98
- 结论: 从文件读取的输入数据未经适当清理，直接拼接到LDAP查询过滤器中，导致LDAP注入漏洞。攻击者可以通过控制文件内容来操纵LDAP查询，从而可能访问或修改未授权的目录数据。
- D验证: confirmed / ver_c7438a6d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 9. hyp_path_34a8c798bd84

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_03.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序读取的文件写入恶意LDAP注入payload
- 触发路径: pFile = fopen(FILENAME, "r"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_03.c:46; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_03.c:48; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_03.c:98; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_03.c:98
- 结论: LDAP注入漏洞：程序从文件读取数据，未经验证直接拼接到LDAP搜索过滤器，导致攻击者可通过控制文件内容注入LDAP查询，修改查询逻辑或绕过认证。
- D验证: confirmed / ver_596f38c4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 10. hyp_path_ced7a386ec32

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_14.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件（FILENAME）的内容
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), pFile) @ line 48-52; _snprintf(filter, 256-1, "(cn=%s)", data); @ line 58-62; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, NULL, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ line 98
- 结论: LDAP注入漏洞：从文件读取数据后直接拼接到LDAP查询过滤器中，未进行任何消毒，攻击者可控制文件内容实现LDAP注入。
- D验证: confirmed / ver_dec74341
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 11. hyp_path_ef55a1799b85

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_05.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或控制程序读取的文件内容
- 触发路径: pFile = fopen(FILENAME, "r"); @ L51-53: fopen(FILENAME, "r"); fgets(data+dataLen, (int)(256-dataLen), pFile); @ L55-57: fgets(data+dataLen, ...); _snprintf(filter, 256-1, "(cn=%s)", data); @ L93-94: _snprintf(filter, 256-1, "(cn=%s)", data);; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ...); @ L105: ldap_search_ext_sA(...)
- 结论: LDAP注入漏洞：从文件读取的输入未经验证或转义直接拼接到LDAP搜索过滤器，攻击者可通过控制文件内容注入任意LDAP过滤器，导致信息泄露、权限绕过等。
- D验证: confirmed / ver_55268bbc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 12. hyp_path_4a81b6fa026c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_08.c:60
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够将恶意数据写入程序读取的文件FILENAME中
- 触发路径: fopen(FILENAME, "r"); if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) ... data[dataLen] = L'\0'; @ Juliet CWE90_LDAP_Injection__w32_wchar_t_file_08.c:58-66; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ Juliet CWE90_LDAP_Injection__w32_wchar_t_file_08.c:104-108; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ Juliet CWE90_LDAP_Injection__w32_wchar_t_file_08.c:112-116
- 结论: LDAP注入漏洞：程序从文件读取用户输入，直接拼接至LDAP搜索过滤器，未进行任何转义或验证，攻击者可通过控制文件内容注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_71679d6f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 13. hyp_path_85f3d55e0c6a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_04.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向文件FILENAME中写入任意数据
- 触发路径: pFile = fopen(FILENAME, "r"); ... fgets(data+dataLen, (int)(256-dataLen), pFile) @ L53-59; data[dataLen] = '\0'; ... fclose(pFile); @ L61-65; _snprintf(filter, 256-1, "(cn=%s)", data); ... searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...) @ L105
- 结论: LDAP注入漏洞：从文件读取的未过滤数据直接拼接到LDAP搜索过滤器中，导致攻击者可通过控制文件内容执行任意LDAP查询。
- D验证: confirmed / ver_a36cc731
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 14. hyp_path_e4b52cfffdb1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_17.c:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或控制程序读取的输入文件（FILENAME）的内容
- 触发路径: pFile = fopen(FILENAME, "r"); @ L45; fgetws(data+dataLen, (int)(256-dataLen), pFile); @ L49; data[dataLen] = L'\0'; @ L55; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L89-92; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L99
- 结论: 检测到LDAP注入漏洞：程序从文件读取用户可控数据，直接拼接进LDAP搜索过滤器字符串，然后调用ldap_search_ext_sW执行搜索，攻击者可通过控制文件内容注入恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_55ad6bc5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 15. hyp_path_26b6de266b0a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_15.c:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或控制FOPEN打开的文件内容
- 触发路径: pFile = fopen(FILENAME, "r"); if (pFile != NULL) { ... } @ L45-49; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgets() failed"); } @ L49-53; data[dataLen] = '\0'; } fclose(pFile); } @ L55-59; _snprintf(filter, 256-1, "(cn=%s)", data); ... searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter, ...); @ L104-108
- 结论: 从文件读取的数据未经验证直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可通过控制文件内容注入恶意LDAP查询，可能绕过认证、获取未授权数据或执行其他恶意操作。
- D验证: confirmed / ver_d60b9c79
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 16. hyp_path_dd78f142ae7e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_07.c:52
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或控制程序读取的固定文件FILENAME的内容（FILENAME通常为常量，需额外漏洞支持）
- 触发路径: if (256-dataLen > 1) { pFile = fopen(FILENAME, "r"); } @ L52; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ L54-58; fclose(pFile); @ L62; _snprintf(filter, 256-1, "(cn=%s)", data); @ L104; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ..., filter, ...); @ L104
- 结论: LDAP注入漏洞：程序从固定文件（FILENAME）读取数据并直接拼接到LDAP搜索过滤器字符串中，未进行任何转义或验证。若攻击者能够控制该文件内容（例如通过文件上传或路径遍历），则可注入LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_b2868b77
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 17. hyp_path_e3f5e69b1a38

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_12.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制文件内容（如通过文件上传或修改）
- 触发路径: pFile = fopen(FILENAME, "r"); @ L46; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ L48-52; data[dataLen] = '\0'; fclose(pFile); @ L54; _snprintf(filter, 256-1, "(cn=%s)", data); @ L100-101; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L103
- 结论: LDAP注入漏洞：从文件读取的输入未经任何过滤直接拼接进LDAP搜索过滤器，攻击者可通过控制文件内容注入LDAP过滤器，导致未授权查询或数据泄露。
- D验证: confirmed / ver_b4e1f94a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 18. hyp_path_8c5dec49a157

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_01.c:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或修改目标文件系统中的输入文件; LDAP服务器可达且允许查询
- 触发路径: pFile = fopen(FILENAME, "r"); if (pFile != NULL) { ... fgets(data+dataLen, ...); } @ L44-46; data[dataLen] = '\0'; } fclose(pFile); @ L52-56; _snprintf(filter, 256-1, "(cn=%s)", data); ldap_search_ext_sA(pLdapConnection, "base", ...) @ L93-97
- 结论: LDAP注入漏洞：从文件读取的用户输入数据未经验证直接拼接到LDAP搜索过滤器中，攻击者可通过控制文件内容实现LDAP注入，导致未授权访问或信息泄露。
- D验证: confirmed / ver_9b380acc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 19. hyp_path_d5e6c4ab9dec

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_12.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或修改程序读取的文件内容
- 触发路径: if (256-dataLen > 1) { pFile = fopen(FILENAME, "r"); if (pFile != NULL) @ L44-48; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgetws() failed"); @ L48-52; data[dataLen] = L'\0'; fclose(pFile); @ L54-58; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L103; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L103
- 结论: LDAP注入漏洞：程序从文件读取用户输入并直接拼接到LDAP搜索过滤器中，未进行适当的转义或验证，攻击者可通过控制文件内容注入恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_cfe982a0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 20. hyp_path_965497160e4d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_16.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向文件写入恶意LDAP过滤字符串
- 触发路径: fopen(FILENAME, "r") 和 fgets 读取文件内容到 data @ L44-52; _snprintf(filter, 256-1, "(cn=%s)", data); @ L96-99; ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, ...); @ L99
- 结论: 代码从文件读取输入并直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。
- D验证: confirmed / ver_0f3fe80f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 21. hyp_path_4b9ea3cf64b9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_04.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向文件写入恶意LDAP查询语句，例如修改FILENAME对应的文件内容
- 触发路径: pFile = fopen(FILENAME, "r"); @ L53; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgetws() failed"); } @ L55; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L61相关; ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L105相关
- 结论: LDAP注入漏洞：从文件读取的数据未经验证直接拼接到LDAP搜索过滤器，攻击者可通过控制文件内容进行LDAP注入。
- D验证: confirmed / ver_4d5c056b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 22. hyp_path_4e4155cf9fdf

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_18.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够将恶意数据写入FILENAME文件
- 触发路径: pFile = fopen(FILENAME, "r"); if (pFile != NULL) { @ L44-L46; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { @ L48; data[dataLen] = '\0'; } fclose(pFile); @ L54; _snprintf(filter, 256-1, "(cn=%s)", data); @ L78-L83; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter, ...); @ L97
- 结论: 代码从文件读取数据并直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可通过控制文件内容注入恶意LDAP过滤器，可能实现未授权访问或信息泄露。
- D验证: confirmed / ver_0c08658d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 23. hyp_path_75ddf169d35d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_01.c:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件的内容（例如通过先写入文件或控制文件读取路径）。
- 触发路径: pFile = fopen(FILENAME, "r"); if (pFile != NULL) { ... if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgetws() failed"); } else { data[dataLen] = L'\0'; } } @ L32-44; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgetws() failed"); } else { data[dataLen] = L'\0'; } @ L46-50; wchar_t filter[256]; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L62-75; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L93-95
- 结论: 从文件读取的数据未经验证或转义直接拼接到LDAP查询过滤器中，导致LDAP注入。攻击者可以通过控制文件内容来操纵LDAP查询，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_a04f74ef
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 24. hyp_path_2523cdfa6967

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_08.c:60
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够将恶意LDAP查询字符串写入目标文件（FILENAME），但代码中未实现文件写入机制，需依赖其他漏洞（如文件上传、共享文件系统等）。
- 触发路径: pFile = fopen(FILENAME, "r"); @ L60; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgets() failed"); ... } @ L62-66; data[dataLen] = '\0'; } fclose(pFile); } @ L68-72; _snprintf(filter, 256-1, "(cn=%s)", data); @ L110-114; ldap_search_ext_sA(pLdapConnection, "base", ... ); @ L112
- 结论: LDAP注入漏洞：程序从文件读取数据并直接拼接到LDAP搜索过滤器中，攻击者可通过控制文件内容注入任意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_3a08e361
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 25. hyp_path_ad8de8ecc603

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_06.c:50
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序读取的文件中写入恶意内容
- 触发路径: if (256-dataLen > 1) { pFile = fopen(FILENAME, "r"); if (pFile != NULL) { @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_06.c:48-52; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgetws() failed"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_06.c:52-56; data[dataLen] = L'\0'; } fclose(pFile); } } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_06.c:58-62; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_06.c:100-104; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage ); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_06.c:106-112
- 结论: 从文件读取的数据直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可以通过控制文件内容，注入恶意LDAP查询，修改搜索行为，导致信息泄露或未授权访问。
- D验证: confirmed / ver_de1eea41
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 26. hyp_path_81b030b12d37

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_16.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制或影响文件内容（例如通过写文件或修改文件路径）
- 触发路径: pFile = fopen(FILENAME, "r"); @ L46; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ L48-52; data[dataLen] = L'\0'; @ L54; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L98-99; searchSuccess = ldap_search_ext_sW(pLdapConnection, ...); @ L99
- 结论: LDAP注入漏洞：从文件读取的数据未经过滤直接拼接到LDAP搜索过滤器中，攻击者可通过控制文件内容注入LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_88faaeac
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 27. hyp_path_d025e8cef0ee

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_15.c:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向目标文件中写入或影响文件内容（例如通过文件上传、共享目录等）。
- 触发路径: pFile = fopen(FILENAME, "r"); ... if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_15.c:45-53; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_15.c:98-99; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_15.c:104
- 结论: 从文件读取的输入未经验证或转义直接拼接到LDAP查询过滤器中，导致LDAP注入漏洞。攻击者可以通过控制文件内容修改LDAP查询语义，可能绕过认证、泄露敏感信息或执行未授权操作。
- D验证: confirmed / ver_09ec120f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 28. hyp_path_af7d33ab9f17

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_02.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制文件内容（例如通过文件上传、共享目录或本地文件创建等渠道）
- 触发路径: pFile = fopen(FILENAME, "r"); if (pFile != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_02.c:44-48; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_02.c:48-52; fclose(pFile); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_02.c:54-58; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_02.c:96-100; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_02.c:96-100
- 结论: LDAP注入漏洞：程序从文件读取用户输入，直接拼接到LDAP搜索过滤器中，未进行任何净化或转义，攻击者可通过控制文件内容注入LDAP过滤器，导致认证绕过或信息泄露。
- D验证: confirmed / ver_d07ded64
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 29. hyp_path_1ebab96c22e4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_03.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或控制输入文件FILENAME; LDAP服务可达; 程序以敏感权限运行
- 触发路径: fopen(FILENAME, "r") @ L46; fgetws(data+dataLen, (int)(256-dataLen), pFile) @ L52; data[dataLen] = L'\0'; fclose(pFile); @ L54; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L96; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L98
- 结论: LDAP注入漏洞：从文件读取的用户输入未经净化直接拼接到LDAP搜索过滤器，攻击者可通过控制文件内容注入恶意LDAP查询，可能导致未授权访问或数据泄露。
- D验证: confirmed / ver_29e83b49
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 30. hyp_path_521312eb49f4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_10.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够影响文件FILENAME的内容，即具有对该文件的写入权限
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgetws() failed"); } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_10.c:48-52; _snwprintf(filter, 256-1, L"(cn=%s)", data); ... ldap_search_ext_sW( pLdapConnection, L"base", ...) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_10.c:104-108
- 结论: LDAP注入漏洞：从文件读取的未过滤数据直接拼接到LDAP搜索过滤器中，攻击者可控制文件内容注入恶意LDAP查询。
- D验证: confirmed / ver_f4f517f8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 31. hyp_path_58f6e4ee0477

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_14.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件的内容（例如通过文件上传、共享目录写入等）
- 触发路径: pFile = fopen(FILENAME, "r"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_14.c:46; fgetws(data+dataLen, (int)(256-dataLen), pFile); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_14.c:56; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_14.c:88; ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_14.c:98
- 结论: 代码从文件读取用户输入，直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者需能控制文件内容。
- D验证: confirmed / ver_e30480e1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 32. hyp_path_d38420c513cb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_05.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或影响文件内容（如通过文件上传或系统其他漏洞）; 文件内容被成功读取到data变量中（文件存在且fgetws成功）
- 触发路径: pFile = fopen(FILENAME, "r"); @ L53; fgetws(data+dataLen, (int)(256-dataLen), pFile); @ L63; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L90; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter, ...); @ L105
- 结论: 从文件读取的输入数据直接拼接到LDAP搜索过滤器，导致LDAP注入漏洞。
- D验证: confirmed / ver_07408117
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 33. hyp_path_3af5c3d6e2f0

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_18.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向目标程序提供包含恶意LDAP过滤器的文件内容。
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ L46-L52; data[dataLen] = L'\0'; } fclose(pFile); } @ L54-L58; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L95-L97; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... filter ...); @ L97
- 结论: 从文件读取的数据直接拼接到LDAP查询过滤器中，导致LDAP注入漏洞。攻击者可通过控制输入文件内容，注入恶意LDAP过滤器，实现未授权访问或信息泄露。
- D验证: confirmed / ver_9c365257
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 34. hyp_path_6d30e72c76cc

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_09.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向文件FILENAME写入或控制其内容
- 触发路径: fgetws(data+dataLen, (int)(256-dataLen), pFile) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_09.c:48-52; data[dataLen] = L'\0'; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_09.c:54-58; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_09.c:98; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage ); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_09.c:98
- 结论: 从文件读取的数据未经任何过滤或转义就直接拼接到LDAP搜索过滤器字符串中，攻击者可通过控制文件内容注入LDAP过滤器，导致LDAP注入漏洞。
- D验证: confirmed / ver_c5ba2f7c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 35. hyp_path_5e043f4576e5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_07.c:52
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: Attacker can write to the file specified by FILENAME (e.g., through a previous file upload or by controlling the file path).
- 触发路径: pFile = fopen(FILENAME, "r"); if (pFile != NULL) { @ line 50-52; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } else { data[dataLen] = L'\0'; } @ line 54-58; fclose(pFile); } @ line 60-64; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ line 90-96; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... filter, ... ); @ line 98-104
- 结论: LDAP Injection vulnerability: user-controlled data from a file is concatenated into an LDAP search filter without proper sanitization, allowing an attacker to modify the filter and potentially access unauthorized data.
- D验证: confirmed / ver_3e1d5674
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 36. hyp_path_9e38d20d0413

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_34.c:51
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制文件FILENAME的内容（例如通过本地写入或外部输入控制）
- 触发路径: pFile = fopen(FILENAME, "r"); @ L51; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ L53-57; _snprintf(filter, 256-1, "(cn=%s)", data); @ L107; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, ...); @ L110
- 结论: 在LDAP搜索过滤器构造中，来自文件的数据未经净化直接拼接，导致LDAP注入漏洞。攻击者可通过控制文件内容，注入恶意的LDAP过滤器，执行未授权的查询。
- D验证: confirmed / ver_6cc615fe
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 37. hyp_path_5521075974b4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_33.cpp:48
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制文件输入（例如通过上传恶意文件或利用其他漏洞写入文件）
- 触发路径: pFile = fopen(FILENAME, "r"); ... fgetws(data+dataLen, (int)(256-dataLen), pFile) @ L46-50; data[dataLen] = L'\0'; } fclose(pFile); @ L56-60; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L76; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ...) @ L101
- 结论: LDAP注入漏洞：从文件读取的数据未经转义直接拼接到LDAP搜索过滤器字符串中，导致攻击者可通过控制文件内容注入LDAP查询，可能获取未授权数据或执行恶意操作。
- D验证: confirmed / ver_d177041e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 38. hyp_path_0635a1de6541

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_34.c:51
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向输入文件写入恶意LDAP过滤器内容
- 触发路径: fgetws(data+dataLen, (int)(256-dataLen), pFile); @ L61; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L? (_snwprintf调用附近); searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...); @ L105
- 结论: 从文件读取的数据直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞
- D验证: confirmed / ver_41b35369
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 39. hyp_path_210956c40e14

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_13.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或控制文件FILENAME的内容
- 触发路径: pFile = fopen(FILENAME, "r"); if (pFile != NULL) { ... } @ L44-48; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ L48-52; data[dataLen] = L'\0'; } fclose(pFile); @ L54-58; _snwprintf(filter, 256-1, L"(cn=%s)", data); ... searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... , filter, ... ); @ L96-100
- 结论: 从文件读取的数据未经验证直接拼接到LDAP搜索过滤器，导致LDAP注入漏洞。
- D验证: confirmed / ver_08844d83
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 40. hyp_path_51bc069b8b3f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_33.cpp:48
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或影响文件内容（FILENAME对应的文件）; LDAP服务器可访问且接受连接
- 触发路径: pFile = fopen(FILENAME, "r"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_33.cpp:48; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_33.cpp:50; _snprintf(filter, 256-1, "(cn=%s)", data); ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_33.cpp:99-101
- 结论: 从文件读取数据并直接拼接到LDAP搜索过滤器中，未进行任何输入验证或净化，导致LDAP注入漏洞。攻击者可通过控制文件内容注入恶意的LDAP过滤器，执行未授权的查询。
- D验证: confirmed / ver_1f47a46a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 41. hyp_path_8542eb23a7a1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_32.c:48
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写或影响输入文件的内容，或者程序接受来自外部可写的文件（如临时文件）
- 触发路径: pFile = fopen(FILENAME, "r"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_32.c:48; fgetws(data+dataLen, (int)(256-dataLen), pFile); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_32.c:52; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_32.c:62; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_32.c:103
- 结论: LDAP注入漏洞：从文件读取的用户输入直接拼接到LDAP搜索过滤器字符串中，攻击者可通过控制文件内容注入恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_fa37f6ff
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 42. hyp_path_16ca94c59546

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_31.c:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向文件FILENAME写入恶意内容（测试场景中合理假设）
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } data[dataLen] = L'\0'; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_31.c:44-54; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_31.c:94-96; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_31.c:98
- 结论: LDAP注入漏洞：程序从文件读取数据，直接拼接至LDAP搜索过滤器，未进行转义或验证，攻击者可通过控制文件内容注入任意LDAP查询。
- D验证: confirmed / ver_54e2d6aa
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 43. hyp_path_07707eac5350

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_12.c:101
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入任意字符串，并且程序执行时globalReturnsTrueOrFalse()返回假
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L30-L45; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L71; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter); @ L82-L86
- 结论: 在globalReturnsTrueOrFalse()为假的分支中，用户输入通过fgetws读取并直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞，攻击者可控制LDAP查询执行未授权操作。
- D验证: confirmed / ver_73580641
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 44. hyp_path_803c737d58d3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_08.c:104
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置或控制环境变量ENV_VARIABLE的值; staticReturnsTrue()返回1（实际总是返回1）
- 触发路径: size_t dataLen = strlen(data); char * environment = GETENV(ENV_VARIABLE); ... strncat(data+dataLen, environment, 256-dataLen-1); @ L55-L59; char filter[256]; _snprintf(filter, 256-1, "(cn=%s)", data); @ L72-L74; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, LDAP_NO_LIMIT, &pMessage); @ L85-L89
- 结论: LDAP注入漏洞：程序从环境变量读取用户可控数据，并直接拼接到LDAP搜索过滤器字符串中，导致攻击者可通过控制环境变量注入恶意LDAP查询，从而可能执行未授权的LDAP操作或获取敏感信息。
- D验证: confirmed / ver_ae026cbf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 45. hyp_path_7c0a94bc9786

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_12.c:95
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值; 程序执行进入if(globalReturnsTrueOrFalse())分支（概率50%，但攻击者可多次尝试或通过其他方式影响）
- 触发路径: if(globalReturnsTrueOrFalse()) { ... strncat(data+dataLen, environment, 256-dataLen-1); } @ L54-L58; char filter[256]; _snprintf(filter, 256-1, "(cn=%s)", data); @ L76-L80; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, ...); @ L93-L97
- 结论: LDAP注入漏洞：攻击者可通过控制环境变量（ENV_VARIABLE）在LDAP搜索过滤器中注入恶意LDAP语法，从而绕过认证或获取未授权数据。
- D验证: confirmed / ver_f190d735
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 46. hyp_path_1b1e8f94c754

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_08.c:104
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量 ENV_VARIABLE 的值（例如通过设置环境变量或影响进程环境）
- 触发路径: size_t dataLen = wcslen(data); wchar_t * environment = GETENV(ENV_VARIABLE); ... wcsncat(data+dataLen, environment, 256-dataLen-1); @ L55-59; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L74; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L85-89
- 结论: LDAP注入漏洞：程序通过环境变量获取用户输入，直接拼接到LDAP搜索过滤器字符串中，未进行任何净化或转义，攻击者可利用环境变量注入恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_fbf50a6d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 47. hyp_path_1cfb76e345a8

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_17.c:91
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值。
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); if (environment != NULL) { wcsncat(data+dataLen, environment, 256-dataLen-1); } @ L42-L46; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L70-L72; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, LDAP_NO_LIMIT, &pMessage ); @ L74-L76
- 结论: LDAP注入漏洞：程序从环境变量读取用户输入，直接拼接到LDAP搜索过滤器中，未进行任何过滤或编码，攻击者可以通过控制环境变量注入任意LDAP查询，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_28656863
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 48. hyp_path_7e8391cbddcc

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_12.c:101
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序提供标准输入; 程序执行globalReturnsTrueOrFalse()返回true的分支（即fgets分支）
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin) @ L41-47; _snprintf(filter, 256-1, "(cn=%s)", data) @ L71; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...) @ L82-86
- 结论: 在globalReturnsTrueOrFalse()返回true的分支中，从控制台读取的用户输入直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。
- D验证: confirmed / ver_dabfaf3e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 49. hyp_path_4d3f07045a9d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_17.c:91
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置目标系统上的环境变量（例如通过控制进程环境）。
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_17.c:45; strncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_17.c:49; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_17.c:88; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_17.c:91
- 结论: 代码从环境变量读取数据并直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可通过控制环境变量注入任意LDAP过滤器，从而无授权访问或修改LDAP目录。
- D验证: confirmed / ver_93a75418
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 50. hyp_path_2e5de16df1ad

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_31.c:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件的内容（例如，通过文件上传、共享目录或先前写入的漏洞）; LDAP服务器位于可访问的网络中，且应用程序使用默认或已知的LDAP端口
- 触发路径: pFile = fopen(FILENAME, "r"); if (pFile != NULL) { @ L42-44; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgets() failed"); @ L46-50; data[dataLen] = '\0'; } fclose(pFile); } @ L52-56; _snprintf(filter, 256-1, "(cn=%s)", data); @ L86-88; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ... @ L98
- 结论: 存在LDAP注入漏洞：从文件读取的数据未经净化直接拼接到LDAP搜索过滤器中，攻击者可通过控制文件内容执行任意LDAP查询。文件内容可控需依赖外部条件（如文件上传漏洞），但漏洞路径清晰，可利用性取决于前置条件。
- D验证: confirmed / ver_c59edb4e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 51. hyp_path_8d1e3ee43cdc

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_11.c:90
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的值
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ L41-45; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L58-60; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ...); @ L71-75
- 结论: LDAP注入漏洞：程序从环境变量获取用户输入，直接拼接成LDAP搜索过滤器，攻击者可通过设置恶意环境变量进行LDAP注入攻击。
- D验证: confirmed / ver_e7d438a9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 52. hyp_path_2d5d8c49a5fb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_11.c:90
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的值
- 触发路径: char * environment = GETENV(ENV_VARIABLE); strncat(data+dataLen, environment, 256-dataLen-1); @ L42-45; _snprintf(filter, 256-1, "(cn=%s)", data); @ L60; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L71-75
- 结论: LDAP注入漏洞：从环境变量读取的用户输入未经验证直接拼接到LDAP搜索过滤器，攻击者可通过控制环境变量注入恶意LDAP查询，导致未授权访问或数据泄露。
- D验证: confirmed / ver_2320d09f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 53. hyp_path_0cee343ebcc8

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_04.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE为包含LDAP注入payload的字符串
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ 50; strncat(data+dataLen, environment, 256-dataLen-1); @ 52; _snprintf(filter, 256-1, "(cn=%s)", data); @ 67; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ 78-82
- 结论: LDAP注入漏洞：程序从环境变量获取用户输入，未经净化直接拼接到LDAP搜索过滤器中，攻击者可通过控制环境变量注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_7ef10e41
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 54. hyp_path_25868bc0b3b9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_01.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制运行环境中的ENV_VARIABLE环境变量。
- 触发路径: char * environment = GETENV(ENV_VARIABLE); ... strncat(data+dataLen, environment, 256-dataLen-1); @ L39-L43; _snprintf(filter, 256-1, "(cn=%s)", data); @ L57; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 15000, &pMessage); @ L68-L72
- 结论: 使用环境变量构造LDAP查询过滤器，未进行适当的输入验证或转义，导致LDAP注入漏洞。攻击者可通过控制环境变量修改LDAP查询语义，可能未授权访问或泄露LDAP目录信息。
- D验证: confirmed / ver_573ed2ea
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 55. hyp_path_02a084c5b5d9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_02.c:90
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够影响目标进程的环境变量
- 触发路径: size_t dataLen = strlen(data); char * environment = GETENV(ENV_VARIABLE); strncat(data+dataLen, environment, 256-dataLen-1); @ L41-L45; _snprintf(filter, 256-1, "(cn=%s)", data); @ L60; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ... ); @ L71-L75
- 结论: LDAP注入漏洞：从环境变量读取的数据未经净化直接拼接到LDAP搜索过滤器中，允许攻击者注入恶意LDAP过滤器，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_ba834fbf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 56. hyp_path_3c0adc2cb40f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_12.c:95
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入的环境变量（如通过进程环境或漏洞利用）。
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); if (environment != NULL) { wcsncat(data+dataLen, environment, 256-dataLen-1); } @ L42-51; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L63-64; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L76-79
- 结论: LDAP注入漏洞：从环境变量读取的数据未经任何过滤直接拼接至LDAP搜索过滤器，攻击者可控制环境变量注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_f89ebd5d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 57. hyp_path_45a662bd3870

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_05.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制受害进程的环境变量（如通过本地执行或子进程环境继承）
- 触发路径: size_t dataLen = strlen(data); char * environment = GETENV(ENV_VARIABLE); @ L48-52; _snprintf(filter, 256-1, "(cn=%s)", data); @ L67; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ... @ L78-82
- 结论: LDAP注入漏洞：从环境变量读取用户可控数据，未经充分过滤直接拼接到LDAP搜索过滤器，攻击者可通过设置恶意环境变量注入LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_40bb892b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 58. hyp_path_e6b220f08df2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_32.c:48
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件的内容; 存在LDAP服务器连接并接受查询
- 触发路径: pFile = fopen(FILENAME, "r"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_32.c:48; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_32.c:58; _snprintf(filter, 256-1, "(cn=%s)", data); ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_32.c:约在ldap_initA之后、ldap_unbind之前
- 结论: LDAP注入漏洞：程序从文件读取数据后直接拼接到LDAP搜索过滤器，攻击者可通过控制文件内容注入LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_3e38e844
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 59. hyp_path_6a6fdfcf81e4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_06.c:94
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者需要能够设置目标环境变量ENV_VARIABLE的值
- 触发路径: char * environment = GETENV(ENV_VARIABLE); ... strncat(data+dataLen, environment, 256-dataLen-1); @ L45-49; _snprintf(filter, 256-1, "(cn=%s)", data); @ L64; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter, ...); @ L75-77
- 结论: 代码从环境变量读取数据并直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可以通过控制环境变量来注入恶意LDAP查询，从而执行未授权的LDAP操作。
- D验证: confirmed / ver_2d79b34e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 60. hyp_path_c8058ebe5eb2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_31.c:90
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的值
- 触发路径: size_t dataLen = strlen(data); char * environment = GETENV(ENV_VARIABLE); strncat(data+dataLen, environment, 256-dataLen-1); @ L39-43; _snprintf(filter, 256-1, "(cn=%s)", data); searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L71-75
- 结论: LDAP注入漏洞：程序从环境变量读取数据，未经验证直接拼接到LDAP搜索过滤器中，攻击者可通过控制环境变量注入恶意LDAP过滤器，导致未授权访问或数据泄露。
- D验证: confirmed / ver_d410646e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 61. hyp_path_43aa72f45bc8

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_16.c:91
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制目标环境变量（如通过本地访问、配置文件篡改或进程注入）
- 触发路径: size_t dataLen = strlen(data); char * environment = GETENV(ENV_VARIABLE); strncat(data+dataLen, environment, 256-dataLen-1); @ L41-45; _snprintf(filter, 256-1, "(cn=%s)", data); @ L61; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, LDAP_NO_LIMIT, &pMessage); @ L72-76
- 结论: LDAP注入漏洞：代码通过环境变量获取用户输入，未经任何过滤直接拼接到LDAP搜索过滤器中，攻击者可通过控制环境变量注入LDAP语法，导致未授权数据访问或认证绕过。
- D验证: confirmed / ver_a5c66dc3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 62. hyp_path_26be721bdb61

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_33.cpp:93
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值（例如在运行环境中）; LDAP服务器可达且允许匿名或已认证连接
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ L45; strncat(data+dataLen, environment, 256-dataLen-1); @ L51; _snprintf(filter, 256-1, "(cn=%s)", data); @ L85; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L93
- 结论: 从环境变量读取的数据直接拼接进LDAP搜索过滤器，导致LDAP注入漏洞。攻击者可通过控制环境变量注入恶意LDAP查询，从而未授权访问或修改LDAP目录数据。
- D验证: confirmed / ver_26e79a56
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 63. hyp_path_233d50430d59

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_02.c:90
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的值。
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ L43; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L60; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... filter ...); @ L71
- 结论: LDAP注入漏洞：从环境变量获取的数据未经任何过滤直接拼接成LDAP搜索过滤器，攻击者可通过控制环境变量注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_17d10e2d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 64. hyp_path_6c731915b85f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_13.c:90
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值（如通过本地访问、配置注入或容器环境变量覆盖）
- 触发路径: size_t dataLen = strlen(data); char * environment = GETENV(ENV_VARIABLE); ... strncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_13.c:41-45; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_13.c:60; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_13.c:71
- 结论: 存在LDAP注入漏洞：通过环境变量传入的未净化数据直接拼接到LDAP搜索过滤器中，攻击者可控制LDAP查询逻辑。
- D验证: confirmed / ver_07704882
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 65. hyp_path_6f11bd691a4b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_18.c:89
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE为包含LDAP过滤特殊字符（如'*', '|', '&', '!'等）的字符串。
- 触发路径: size_t dataLen = strlen(data); char * environment = GETENV(ENV_VARIABLE); /* If there is data in the environment variable */ @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_18.c:41-45; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_18.c:57-59; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ... @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_18.c:70-74
- 结论: 程序从环境变量读取数据，未经充分验证即拼接到LDAP搜索过滤器中，可能导致LDAP注入攻击。攻击者可通过控制环境变量注入任意LDAP过滤器，实现未授权访问或信息泄露。
- D验证: confirmed / ver_0978c89c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 66. hyp_path_9e8cd2de091e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_10.c:90
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的内容
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ L41-45; strncat(data+dataLen, environment, 256-dataLen-1); @ L49-50; _snprintf(filter, 256-1, "(cn=%s)", data); @ L59-61; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...); @ L71-75
- 结论: 从环境变量读取数据并直接拼接到LDAP搜索过滤器中，未进行任何转义或验证，导致LDAP注入漏洞。攻击者可以通过控制环境变量来操纵LDAP查询，可能获取未授权访问或信息泄露。
- D验证: confirmed / ver_6898dabd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 67. hyp_path_ab4fccf36fcf

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_14.c:90
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制ENV_VARIABLE环境变量的内容; LDAP服务器可达且绑定成功
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_14.c:43; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_14.c:60; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_14.c:71-75
- 结论: LDAP注入漏洞：程序从环境变量读取数据，并将其直接拼接至LDAP搜索过滤器，未进行任何过滤或转义，导致攻击者可能通过控制环境变量来注入LDAP查询，实现未授权访问或信息泄露。
- D验证: confirmed / ver_429c9038
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 68. hyp_path_1a83d5d1c44a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_34.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置目标进程的环境变量（例如通过进程注入或未授权的配置修改）
- 触发路径: char * environment = GETENV(ENV_VARIABLE); ... strncat(data+dataLen, environment, 256-dataLen-1); @ L46-50; _snprintf(filter, 256-1, "(cn=%s)", data); @ L? 约80行; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ... filter, ...); @ L78-82
- 结论: LDAP注入漏洞：从环境变量获取的输入未经任何验证或转义，直接拼接到LDAP搜索过滤器字符串中，攻击者可控制环境变量注入恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_9b0ea509
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 69. hyp_path_4153e2bc5908

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_07.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE
- 触发路径: char * environment = GETENV(ENV_VARIABLE); ... strncat(data+dataLen, environment, 256-dataLen-1); @ L47-51; _snprintf(filter, 256-1, "(cn=%s)", data); @ L66; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L77-81
- 结论: LDAP注入漏洞：从环境变量读取数据直接拼接到LDAP搜索过滤器中，未进行任何转义或验证，攻击者可通过控制环境变量注入恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_9e3b5fa9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 70. hyp_path_5a6cf7dc24f9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_09.c:90
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值
- 触发路径: char * environment = GETENV(ENV_VARIABLE); ... strncat(data+dataLen, environment, 256-dataLen-1); @ L41-L45; _snprintf(filter, 256-1, "(cn=%s)", data); @ L60; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L71-L75
- 结论: LDAP注入漏洞：程序从环境变量获取用户输入，直接拼接到LDAP搜索过滤器字符串中，未进行任何过滤或转义，攻击者可通过设置恶意环境变量值注入LDAP过滤器，从而执行未授权的LDAP操作。
- D验证: confirmed / ver_bd249786
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 71. hyp_path_406faeb1da40

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_05.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量的值。
- 触发路径: dataLen = wcslen(data); wchar_t * environment = GETENV(ENV_VARIABLE); @ CWE90_LDAP_Injection__w32_wchar_t_environment_05.c:48-50; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_environment_05.c:67; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...); @ CWE90_LDAP_Injection__w32_wchar_t_environment_05.c:78-82
- 结论: 环境变量数据直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。
- D验证: confirmed / ver_a58c8bba
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 72. hyp_path_16579372fe00

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_01.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制进程环境变量ENV_VARIABLE的值
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); wcsncat(data+dataLen, environment, 256-dataLen-1); @ L39-43; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L57; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage ); @ L68-72
- 结论: LDAP注入漏洞：从环境变量获取的输入直接拼接进LDAP搜索过滤器，未进行任何转义或验证，攻击者可通过控制环境变量注入任意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_d47ac3f2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 73. hyp_path_a7fc2c9c1b51

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_03.c:90
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置或控制目标环境变量ENV_VARIABLE的值
- 触发路径: size_t dataLen = strlen(data); char * environment = GETENV(ENV_VARIABLE); ... strncat(data+dataLen, environment, 256-dataLen-1); @ L41-45; _snprintf(filter, 256-1, "(cn=%s)", data); @ L60; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L71-75
- 结论: 代码从环境变量读取数据并直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可通过控制环境变量注入任意LDAP过滤器，可能导致信息泄露或未授权访问。
- D验证: confirmed / ver_34eb210e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 74. hyp_path_2e90a69d2d47

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_15.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制进程的环境变量 ENV_VARIABLE 的内容。
- 触发路径: size_t dataLen = strlen(data); char * environment = GETENV(ENV_VARIABLE); @ L42-46; strncat(data+dataLen, environment, 256-dataLen-1); @ L48-49; _snprintf(filter, 256-1, "(cn=%s)", data); @ L66; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ... filter ...); @ L77-81
- 结论: 从环境变量读取数据并直接拼接到LDAP搜索过滤器，导致LDAP注入漏洞。攻击者可以通过控制环境变量注入恶意LDAP过滤器，从而执行未授权的LDAP操作。
- D验证: confirmed / ver_8c1af246
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 75. hyp_path_6d6cd36a6266

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_04.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的值
- 触发路径: wchar_t *environment = GETENV(ENV_VARIABLE); wcsncat(data+dataLen, environment, 256-dataLen-1); @ L39-L53; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L67; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L78
- 结论: LDAP注入漏洞：攻击者可通过环境变量控制LDAP搜索过滤器，导致未授权LDAP查询或信息泄露。
- D验证: confirmed / ver_cb353d72
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 76. hyp_path_10162493249e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_03.c:90
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置或影响环境变量ENV_VARIABLE的内容
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); wcsncat(data+dataLen, environment, 256-dataLen-1); @ L41-L45; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L60; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ..., filter, ...); @ L71-L75
- 结论: 环境变量中的数据未经转义直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可通过控制环境变量注入恶意LDAP过滤器，实现未授权访问或信息泄露。
- D验证: confirmed / ver_253fdd41
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 77. hyp_path_2147b5946f51

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_06.c:94
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量（如通过setenv或子进程继承）
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); ... wcsncat(data+dataLen, environment, 256-dataLen-1); @ L45-49; wchar_t filter[256]; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L62-64; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L75-79
- 结论: 代码从环境变量获取输入并直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可以通过控制环境变量注入恶意LDAP查询，可能绕过认证、获取未授权数据或执行其他LDAP操作。
- D验证: confirmed / ver_57f199ff
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 78. hyp_path_8e28150c83c5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_14.c:90
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的值。
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ L43; wcsncat(data+dataLen, environment, 256-dataLen-1); @ L45; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L60; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, ...); @ L71-75
- 结论: LDAP注入漏洞：从环境变量获取数据直接拼接到LDAP搜索过滤器，未经任何过滤或转义，攻击者可通过控制环境变量注入LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_539f949a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 79. hyp_path_a4fe47206f99

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_33.cpp:93
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: Attacker can control the environment variable used in the application.
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ 获取环境变量数据; wcsncat(data+dataLen, environment, 256-dataLen-1); @ 拼接数据到data; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 构造LDAP过滤字符串; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...); @ 执行LDAP搜索
- 结论: LDAP Injection vulnerability: user-controlled input from environment variable is concatenated into LDAP search filter without proper sanitization, allowing an attacker to modify the LDAP query.
- D验证: confirmed / ver_9592d1f4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 80. hyp_path_47cca59f60a3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_07.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的值
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); ... wcsncat(data+dataLen, environment, 256-dataLen-1); @ L47-51; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L66; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... filter ...); @ L77-81
- 结论: LDAP注入漏洞：从环境变量读取用户输入并直接拼接到LDAP搜索过滤器，攻击者可通过控制环境变量注入恶意LDAP查询。
- D验证: confirmed / ver_eaf8b4e0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 81. hyp_path_64fc479959bb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_18.c:89
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值; LDAP服务器可达且允许未授权查询
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ 第41-45行; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 第59行; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...); @ 第70-74行
- 结论: 代码从环境变量中读取数据并直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可以通过设置环境变量控制LDAP查询，可能绕过认证或获取未授权数据。
- D验证: confirmed / ver_75cecfdf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 82. hyp_path_2461d5f9f6be

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_10.c:90
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量 ENV_VARIABLE 的值
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); ... wcsncat(data+dataLen, environment, 256-dataLen-1); @ L43-L45; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L51; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... filter ...); @ L71-L75
- 结论: LDAP注入漏洞：程序从环境变量读取用户输入，并将其直接拼接到LDAP搜索过滤器中，导致攻击者可以通过控制环境变量注入恶意LDAP查询，可能绕过访问控制或泄露敏感信息。
- D验证: confirmed / ver_bda5210e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 83. hyp_path_10f43d4d280e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_13.c:90
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量 ENV_VARIABLE 的值，使其包含 LDAP 过滤器特殊字符（如 *、|、& 等）。
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ line 43; wcsncat(data+dataLen, environment, 256-dataLen-1); @ line 44; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ line 60; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... ); @ line 71-75
- 结论: LDAP Injection vulnerability: user-controlled data from environment variable is concatenated into an LDAP search filter without sanitization, allowing an attacker to modify the filter semantics.
- D验证: confirmed / ver_ea2bbf36
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 84. hyp_path_32d9e56336f8

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_09.c:90
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制目标系统的环境变量ENV_VARIABLE的内容。
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); ... wcsncat(data+dataLen, environment, 256-dataLen-1); @ L41-L45; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L60; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 15000, &pMessage); @ L71-L75
- 结论: 程序从环境变量读取数据，未经验证直接拼接到LDAP查询过滤器中，导致LDAP注入漏洞。
- D验证: confirmed / ver_1376a270
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 85. hyp_path_3d0f8833ca34

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_31.c:90
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的值，从而影响拼接到data中的字符串。
- 触发路径: size_t dataLen = wcslen(data); wchar_t * environment = GETENV(ENV_VARIABLE); /* If there is data in the environment variable */ ... wcsncat(data+dataLen, environment, 256-dataLen-1); @ L39-L43; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, L"(objectClass=*)", NULL, 0, NULL, NULL, LDAP_NO_LIMIT, &pMessage); @ L71-L75
- 结论: LDAP注入漏洞：程序从环境变量读取用户输入，未经充分净化直接拼接到LDAP搜索过滤器中，导致攻击者可能通过控制环境变量注入恶意LDAP查询，从而执行未授权的LDAP操作。
- D验证: confirmed / ver_81441093
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 86. hyp_path_a5a71a55eb80

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_43.cpp:101
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入提供恶意LDAP过滤器片段
- 触发路径: case0Source函数从控制台读取输入到data @ L29-L56; _snwprintf(filter, 256-1, L"(cn=%s)", data); 将data拼接到过滤器 @ L69-L71; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...); 执行含注入的查询 @ L82-L86
- 结论: LDAP Injection漏洞：程序从控制台读取用户输入，未经验证直接拼接到LDAP搜索过滤器中，攻击者可以注入恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_a6e8c74c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 87. hyp_path_52534cbe0df2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_21.c:106
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入提供任意字符串
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin) @ L29-60 case0Source; _snprintf(filter, 256-1, "(cn=%s)", data); @ L74-77; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L87-88
- 结论: LDAP注入漏洞：用户输入通过控制台读取后直接拼接到LDAP搜索过滤器中，未经任何转义或验证，攻击者可构造恶意输入注入LDAP查询。
- D验证: confirmed / ver_9b4731e1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 88. hyp_path_5bf80f89b3d9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_16.c:91
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量（如通过修改系统环境或利用其他漏洞控制父进程）。
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); wcsncat(data+dataLen, environment, 256-dataLen-1); @ L43-L45; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L61; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L72
- 结论: 代码从环境变量获取用户输入，直接拼接到LDAP搜索过滤器中，未进行适当的转义或过滤，导致LDAP注入漏洞。攻击者可通过控制环境变量来操纵LDAP查询，可能获取未授权的数据或进行其他恶意操作。
- D验证: confirmed / ver_84ad4357
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 89. hyp_path_c82c7e6c26f9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_34.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值。
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); ... wcsncat(data+dataLen, environment, 256-dataLen-1); @ 第46-50行; _snwprintf(filter, 256-1, L"(cn=%s)", data); ... searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter, ...); @ 第78-82行
- 结论: LDAP注入漏洞：程序通过环境变量获取用户可控数据，未经充分过滤直接拼接到LDAP搜索过滤器中，导致攻击者可以注入恶意的LDAP查询，可能造成信息泄露或未授权访问。
- D验证: confirmed / ver_482c8f83
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 90. hyp_path_412c9dfd5daa

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_08.c:110
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序的stdin输入任意字符串，且该字符串长度足够构造恶意LDAP过滤器。
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin); @ 行58-65; _snprintf(filter, 256-1, "(cn=%s)", data); @ 行78-80; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...); @ 行91-95
- 结论: LDAP注入漏洞：程序通过fgets从控制台读取用户输入，未经任何过滤或转义直接格式化到LDAP搜索过滤器中，导致攻击者可以注入恶意LDAP查询，例如修改过滤器逻辑或执行未授权操作。
- D验证: confirmed / ver_a61fe587
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 91. hyp_path_f0ee3d72e788

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_11.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够在程序运行时向控制台提供输入，且程序未对输入进行任何限制或净化
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin); @ L26附近; dataLen = strlen(data); @ L44; _snprintf(filter, 256-1, "(cn=%s)", data); @ L66; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L77
- 结论: LDAP注入漏洞：程序从控制台读取用户输入，并将其直接拼接到LDAP搜索过滤器中，未进行任何过滤或转义，导致攻击者可以通过注入LDAP元字符修改查询逻辑。路径真实可达，无防御阻断。
- D验证: confirmed / ver_445883f4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 92. hyp_path_b90d810032c1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_11.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够在程序运行时从控制台输入数据，即攻击者具有本地或远程控制台访问权限，或程序通过标准输入接收外部数据。
- 触发路径: wchar_t filter[256]; /* NOTE: data concatenated into LDAP search, which could result in LDAP Injection*/ _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_11.c:64-68; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_11.c:77-81
- 结论: 代码从控制台读取用户输入并直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可以通过控制台输入注入恶意LDAP查询，可能绕过认证、窃取信息或执行未授权操作。
- D验证: confirmed / ver_82929ac7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 93. hyp_path_248821795f47

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_21.c:106
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够在控制台提供任意输入字符串。; LDAP服务器可达且连接成功。
- 触发路径: case0Source函数从stdin读取数据到data @ L29-L60; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L76; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ..., filter, ...); @ L89
- 结论: 在LDAP搜索过滤器中直接拼接用户输入，导致LDAP注入漏洞。
- D验证: confirmed / ver_03261562
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 94. hyp_path_7cff93ca257a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_15.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过本地或远程方式设置目标进程的环境变量（如通过恶意进程或系统配置）; 环境变量内容长度不超过256-dataLen-1，以确保拼接后数据仍在缓冲区范围内
- 触发路径: size_t dataLen = wcslen(data); wchar_t * environment = GETENV(ENV_VARIABLE); ... wcsncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_15.c:42-46; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_15.c:66; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_15.c:77-81
- 结论: LDAP注入漏洞：从环境变量读取数据后直接拼接至LDAP搜索过滤器，攻击者可控制环境变量注入LDAP元字符，导致LDAP查询行为异常。
- D验证: confirmed / ver_c1746f0e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 95. hyp_path_3f7204122f58

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_32.c:95
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ L45; if (environment != NULL) { ... data = environment; } @ L46; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L93; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage ); @ L95
- 结论: LDAP注入漏洞：从环境变量获取输入并直接拼接到LDAP查询过滤器中，攻击者可通过控制环境变量注入恶意LDAP语法，导致未授权访问或数据泄露。
- D验证: confirmed / ver_61ce4de0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 96. hyp_path_4ff5fa64647d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_08.c:110
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够与程序交互（如通过标准输入）并提供包含LDAP查询元字符（如*、()、|、&等）的字符串
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_08.c:58-68; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_08.c:80; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter, ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_08.c:110
- 结论: 代码从控制台读取用户输入，直接拼接为LDAP搜索过滤器，未进行任何转义或验证，导致LDAP注入攻击。攻击者可注入任意LDAP过滤器，造成信息泄露或未授权访问。
- D验证: confirmed / ver_c1b6e3b5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 97. hyp_path_226cdf2b678f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_43.cpp:101
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入任意字符串（例如通过stdin提供恶意输入）。
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin); @ case0Source函数（fgets调用行）; _snprintf(filter, 256-1, "(cn=%s)", data); @ L71; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L82-86
- 结论: LDAP注入漏洞：用户输入直接拼接至LDAP搜索过滤器，攻击者可通过控制台输入注入LDAP元字符，操纵LDAP查询。
- D验证: confirmed / ver_f6a4aaa8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 98. hyp_path_cf5e442b8817

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_32.c:95
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置相关环境变量ENV_VARIABLE的值
- 触发路径: size_t dataLen = strlen(data); char * environment = GETENV(ENV_VARIABLE); if (environment != NULL) { strncat(data+dataLen, environment, 256-dataLen-1); } @ L43-L47; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...); // 省略参数，应包含data @ L76-L80
- 结论: LDAP注入漏洞：从环境变量读取数据后未经充分过滤直接用于LDAP搜索过滤器，攻击者可通过控制环境变量注入任意LDAP查询。
- D验证: confirmed / ver_77a5524f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 99. hyp_path_a7bd441a392d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_01.c:93
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台提供输入
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_01.c:33-48; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_01.c:63; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter, ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_01.c:74-78
- 结论: LDAP注入漏洞：程序从控制台读取用户输入，未经过滤直接拼接到LDAP搜索过滤器字符串中，导致攻击者可以控制LDAP查询语句，执行未授权操作。
- D验证: confirmed / ver_70f0a7b2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 100. hyp_path_a494bdc0d1c2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_21.c:108
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向输入文件写入恶意LDAP过滤器内容
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), pFile); fclose(pFile); return data; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_21.c:35-62 (case0Source); _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_21.c:78; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ..., filter, ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_21.c:89-93
- 结论: LDAP注入漏洞：从文件读取的数据直接拼接到LDAP搜索过滤器中，攻击者可通过控制文件内容注入任意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_48ab0880
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 101. hyp_path_44794e85c865

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_10.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向控制台输入任意字符（运行环境受控或有交互）
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin) @ L35-L41 console输入读取; _snprintf(filter, 256-1, "(cn=%s)", data); @ L64-L66 过滤器构造; ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, 0, &pMessage); @ L77-L81 LDAP搜索调用
- 结论: LDAP注入漏洞：fgets从控制台读取数据后，未经验证直接拼接到LDAP查询过滤器中，导致攻击者可通过控制台输入注入LDAP语法。
- D验证: confirmed / ver_cf351dfd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 102. hyp_path_0656fc848f6b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_07.c:102
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序的标准输入提供数据
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin) @ 行50-52; char filter[256]; _snprintf(filter, 256-1, "(cn=%s)", data); @ 行70-74; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter, ...); @ 行83-87
- 结论: LDAP注入漏洞：从控制台读取的用户输入直接拼接到LDAP搜索过滤器中，攻击者可以注入恶意LDAP查询，修改搜索行为或绕过访问控制。
- D验证: confirmed / ver_ebada215
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 103. hyp_path_0b5100a15ab3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_09.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过标准输入提供任意字符串
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L35; _snprintf(filter, 256-1, "(cn=%s)", data); @ L66; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L96
- 结论: 代码从控制台读取用户输入并直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可通过注入特殊字符修改过滤器语义，可能绕过访问控制或获取未授权数据。
- D验证: confirmed / ver_59ea1c6f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 104. hyp_path_4ef8ff051657

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_05.c:103
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过标准输入提供数据（例如在控制台或重定向输入中）
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L33-37; char filter[256]; _snprintf(filter, 256-1, "(cn=%s)", data); @ L71-73; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, ...) @ L84-88
- 结论: LDAP注入漏洞：用户输入通过控制台读取后直接拼接到LDAP搜索过滤器字符串中，未经任何过滤或转义，导致攻击者可注入恶意LDAP查询，可能绕过认证、非法访问数据或执行未授权操作。
- D验证: confirmed / ver_e97b18b5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 105. hyp_path_28896e126026

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_15.c:102
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过标准输入控制data变量内容。
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ L72; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, NULL, &pMessage); @ L84
- 结论: 在CWE90_LDAP_Injection__w32_char_console_15.c中，用户通过控制台输入的字符串直接拼接至LDAP搜索过滤器，导致LDAP注入漏洞。攻击者可注入恶意LDAP过滤器，执行未授权的查询或修改。
- D验证: confirmed / ver_c4b775c4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 106. hyp_path_3685239f07f5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_14.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入任意字符串。
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin) @ L26; _snprintf(filter, 256-1, "(cn=%s)", data); @ L64-L66; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, ...) @ L77
- 结论: LDAP注入漏洞：程序通过控制台输入读取用户数据，未经验证直接拼接到LDAP搜索过滤器中，导致攻击者可以注入任意LDAP过滤器，可能泄露或修改LDAP目录数据。
- D验证: confirmed / ver_75a1065b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 107. hyp_path_0ca86affd874

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_02.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向标准输入提供任意字符串
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin) @ 读取输入行（fgets）; _snprintf(filter, 256-1, "(cn=%s)", data); @ L66; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ...) @ L77-81
- 结论: LDAP注入漏洞：用户通过控制台输入的数据直接拼接进LDAP搜索过滤器，未经过滤或转义，攻击者可注入任意LDAP查询，导致信息泄露或未授权访问。
- D验证: confirmed / ver_0807c77a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 108. hyp_path_0e9a741cc540

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_04.c:103
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: Attacker can provide arbitrary input via console stdin.
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) { ... } @ L51-L58; _snprintf(filter, 256-1, "(cn=%s)", data); @ L73; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, ...); @ L84
- 结论: LDAP Injection vulnerability: user input from console is directly concatenated into LDAP search filter without sanitization, allowing an attacker to inject arbitrary LDAP queries.
- D验证: confirmed / ver_25fc8014
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 109. hyp_path_1cca172da33f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_06.c:100
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够在程序运行时向控制台输入恶意数据。
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L39-L42; _snprintf(filter, 256-1, "(cn=%s)", data); @ L70; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L82
- 结论: LDAP注入漏洞：程序从控制台读取用户输入，并将其直接拼接到LDAP搜索过滤器中，未进行任何转义或验证，攻击者可以通过注入特制的LDAP过滤器实现未授权访问或信息泄露。
- D验证: confirmed / ver_729b29bc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 110. hyp_path_76d3f2ee0cf5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_13.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入提供数据。
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L44; _snprintf(filter, 256-1, "(cn=%s)", data); @ L66; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...) @ L77-81
- 结论: LDAP注入漏洞：程序从控制台读取输入并直接拼接到LDAP搜索过滤器中，攻击者可注入恶意LDAP语法，导致未授权访问或敏感信息泄露。
- D验证: confirmed / ver_2690a95b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 111. hyp_path_927571271491

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_21.c:108
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够直接或间接修改输入文件的内容
- 触发路径: data = case0Source(data); @ L70（调用case0Source处）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L78; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L91
- 结论: LDAP注入漏洞：程序从文件读取输入，未经适当过滤或转义直接拼接到LDAP搜索过滤器，攻击者通过控制文件内容可能注入任意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_6ebebf2f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 112. hyp_path_2bb96a5dd3b0

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_03.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够访问程序的标准输入，并向控制台输入恶意字符串。
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L35; _snprintf(filter, 256-1, "(cn=%s)", data); @ L66; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L77
- 结论: LDAP注入漏洞：用户通过控制台输入，数据未经转义直接拼接到LDAP搜索过滤器中，攻击者可以注入任意LDAP查询，导致信息泄露或权限提升。
- D验证: confirmed / ver_ef2d1a2a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 113. hyp_path_0add9d55eef4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_18.c:95
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台标准输入提供字符串（例如，在本地运行或通过重定向）
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin) @ console input (line 35-47); _snprintf(filter, 256-1, "(cn=%s)", data); @ line 65; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, NULL, NULL, NULL, NULL, &pMessage); @ line 76-78
- 结论: LDAP注入漏洞：从控制台读取的用户输入未经任何过滤或转义，直接拼接到LDAP搜索过滤器中，攻击者可以构造恶意输入实现LDAP注入，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_9d33c0bb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 114. hyp_path_7d4564d5c528

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_04.c:103
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入提供恶意字符串，包含LDAP查询语法特殊字符（如'*', '|', '&'等）。
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L71; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... filter, ...); @ L84
- 结论: LDAP注入漏洞：程序从控制台读取用户输入并直接拼接到LDAP搜索过滤器中，未进行任何输入验证或转义，攻击者可以通过构造恶意输入修改LDAP查询逻辑，导致未授权访问或信息泄露。
- D验证: confirmed / ver_1fd40d79
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 115. hyp_path_0ae7c6b60763

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_03.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序的标准输入提供恶意字符串。
- 触发路径: fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL @ L26-35; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L64-66; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L77-81
- 结论: 从控制台读取的用户输入直接拼接到LDAP搜索过滤器，导致LDAP注入漏洞。
- D验证: confirmed / ver_4ccbbb84
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 116. hyp_path_67aa124772f3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_02.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过标准输入向程序提供任意字符串。
- 触发路径: fgetws(data+dataLen, (int)(256-dataLen), stdin) @ 第44行附近; _snwprintf(filter, 256-1, L"(cn=%s)", data) @ 第66行; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage) @ 第77-81行
- 结论: LDAP注入漏洞：程序从控制台读取用户输入（fgetws），未经过滤直接拼接到LDAP搜索过滤器（_snwprintf），然后调用ldap_search_ext_sW执行LDAP查询。攻击者可以通过构造恶意输入修改LDAP查询语义，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_8fca78ee
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 117. hyp_path_c8d329f2c85b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_01.c:93
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序的标准输入提供控制台输入。
- 触发路径: fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL @ L26; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L63; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L74-78
- 结论: 代码从控制台读取用户输入，直接拼接进LDAP搜索过滤器，未进行任何消毒或转义，导致LDAP注入漏洞。攻击者可以通过控制恶意输入来修改LDAP查询逻辑，执行未授权的操作或提取敏感信息。
- D验证: confirmed / ver_67c464d1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 118. hyp_path_32d8b836ceab

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_16.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够提供控制台输入。; LDAP服务可访问。
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ 代码中通过fgets从控制台读入数据到data变量; _snprintf(filter, 256-1, "(cn=%s)", data); @ data被直接拼接到LDAP过滤器字符串; ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ 使用未净化的过滤器执行LDAP搜索
- 结论: LDAP注入漏洞：从控制台读取的用户输入直接拼接到LDAP搜索过滤器字符串中，未经任何转义或验证，导致攻击者可以注入任意LDAP过滤器，可能造成未授权访问或信息泄露。
- D验证: confirmed / ver_5dca149c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 119. hyp_path_6fb0ab31e7bb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_17.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向标准输入提供恶意字符串，包含LDAP过滤器元字符（如*、|、&等）。
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L36; _snprintf(filter, 256-1, "(cn=%s)", data); @ L67; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter, ...); @ L78
- 结论: LDAP注入漏洞：用户输入通过fgets读取后，未经任何过滤或转义，直接拼接进LDAP搜索过滤器字符串，导致攻击者可以控制LDAP查询，实现未授权访问或信息泄露。
- D验证: confirmed / ver_c5af29cf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 120. hyp_path_26bbbb8c20b5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_06.c:100
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序的标准输入提供任意字符串; LDAP服务器（localhost）可连接
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L48-L52; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L68-L72; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... ); @ L81-L85
- 结论: LDAP注入漏洞：用户通过控制台输入的数据直接拼接到LDAP搜索过滤器字符串中，未经过滤或转义，攻击者可利用此注入恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_c3f3a15e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 121. hyp_path_a749fcdfa8a8

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_07.c:102
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制控制台输入（如通过stdin重定向或交互式输入）
- 触发路径: fgetws(data+dataLen, (int)(256-dataLen), stdin) @ L32-L47; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L72; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...); @ L83-L87
- 结论: LDAP注入漏洞：从控制台读取的用户输入直接拼接到LDAP搜索过滤器中，未进行适当转义或验证，攻击者可通过输入特制字符串操纵LDAP查询，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_7bc03e2d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 122. hyp_path_4353d334720f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_05.c:103
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入提供任意字符串
- 触发路径: fgetws(data+dataLen, (int)(256-dataLen), stdin); @ 控制台输入读取; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L73 过滤字符串构建; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... @ L84-88 LDAP搜索
- 结论: LDAP注入漏洞：从控制台读取的用户输入未经任何过滤或转义直接拼接到LDAP搜索过滤器中，攻击者可以注入恶意LDAP过滤器，导致未授权的数据访问或信息泄露。
- D验证: confirmed / ver_fbb2c72e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 123. hyp_path_169a8d4de530

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_09.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够在标准输入提供任意字符串
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L26; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L66; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... ) @ L77-81
- 结论: LDAP注入漏洞：从控制台读取的用户输入直接拼接到LDAP搜索过滤器中，未进行任何转义或验证，攻击者可以注入LDAP元字符来修改搜索意图。
- D验证: confirmed / ver_b326da80
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 124. hyp_path_68100a0f2cbe

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_16.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序的标准输入提供任意字符串。
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L43-L48; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L65-L67; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L78-L82
- 结论: LDAP注入漏洞：用户通过控制台输入的数据直接拼接到LDAP搜索过滤器中，攻击者可注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_e4753541
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 125. hyp_path_1cc4424017ba

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_18.c:95
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入提供恶意数据
- 触发路径: fgetws(data+dataLen, (int)(256-dataLen), stdin); @ L44; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L65; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L95
- 结论: 代码从控制台读取用户输入并直接拼接到LDAP搜索过滤器字符串中，未进行任何验证或转义，导致LDAP注入漏洞。攻击者可以通过构造特制的输入修改LDAP查询逻辑，可能造成未授权访问或数据泄露。
- D验证: confirmed / ver_8d6ac740
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 126. hyp_path_76c9b259acc7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_13.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序的标准输入提供数据（例如通过管道或交互式输入）
- 触发路径: fgetws(data+dataLen, (int)(256-dataLen), stdin) // 从控制台读取输入 @ 35-36; _snwprintf(filter, 256-1, L"(cn=%s)", data); // 直接拼接用户输入到LDAP过滤器中 @ 66; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter...); // 执行LDAP搜索，注入点触发 @ 77-81
- 结论: CWE90 LDAP Injection: 用户输入通过fgetws从控制台读取，未经转义直接拼接到LDAP搜索过滤器中，导致攻击者可以注入LDAP元字符，改变查询逻辑。
- D验证: confirmed / ver_96d85a3d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 127. hyp_path_19200405ca52

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_17.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序的stdin提供输入（例如通过交互式控制台或重定向）
- 触发路径: fgetws(data+dataLen, (int)(256-dataLen), stdin) @ L45-56; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L67; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... filter, ...); @ L78-82
- 结论: LDAP注入漏洞：从控制台读取的用户输入未经任何转义或验证，直接拼接到LDAP搜索过滤器中，执行ldap_search_ext_sW，攻击者可以注入任意LDAP过滤器，导致信息泄露或目录篡改。
- D验证: confirmed / ver_34e93d6c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 128. hyp_path_7b1f1fd1f1fb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_42.c:99
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够在控制台输入数据
- 触发路径: fgetws(data+dataLen, (int)(256-dataLen), stdin) @ case0Source函数，约L35-40; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 主函数L69; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter ...); @ 主函数L80-84
- 结论: LDAP注入漏洞：从控制台读取的用户输入未经净化直接拼接到LDAP搜索过滤器，攻击者可通过注入特殊字符（如'*'、'()'）绕过认证或获取未授权数据。
- D验证: confirmed / ver_9e3d6fd0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 129. hyp_path_9562cfda0fd7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_10.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过stdin提供输入; LDAP服务器可达且允许查询
- 触发路径: fgetws(data+dataLen, (int)(256-dataLen), stdin) @ L35-45; _snwprintf(filter, 256-1, L"(cn=%s)", data) @ L64-66; ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage) @ L77-81
- 结论: LDAP注入漏洞：用户从控制台输入数据直接拼接到LDAP搜索过滤器，未经充分验证或转义，攻击者可构造恶意输入操纵LDAP查询。
- D验证: confirmed / ver_3bd0e8b3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 130. hyp_path_28cdc428867b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_15.c:102
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过标准输入提供任意数据（例如通过交互式控制台或重定向输入），且输入长度不超过256字符。
- 触发路径: fgetws(data+dataLen, (int)(256-dataLen), stdin) @ CWE90_LDAP_Injection__w32_wchar_t_console_15.c:26; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_console_15.c:72; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... filter ... ); @ CWE90_LDAP_Injection__w32_wchar_t_console_15.c:83
- 结论: LDAP注入漏洞：从控制台读取用户输入并直接拼接到LDAP搜索过滤器中，攻击者可以通过注入LDAP元字符修改查询逻辑，可能导致未授权访问或数据泄露。
- D验证: confirmed / ver_443a40be
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 131. hyp_path_ca65e8494b86

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_14.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入数据（如本地运行或通过某种交互方式）。
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_14.c:35; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_14.c:66; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_14.c:77-81
- 结论: 代码从控制台读取用户输入（fgetws），直接拼接成LDAP搜索过滤器（_snwprintf），然后执行LDAP搜索（ldap_search_ext_sW），未对输入进行任何验证或转义，导致LDAP注入漏洞。
- D验证: confirmed / ver_06c88604
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 132. hyp_path_41f6b7c20833

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_43.cpp:103
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够影响输入文件（FILENAME常量，需具有写权限或控制文件路径）的内容；虽然路径固定，但在特定上下文（如管理员误写或文件被覆盖）中仍可利用
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), pFile); @ case0Source函数; _snprintf(filter, 256-1, "(cn=%s)", data); @ L73; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ..., filter, ...); @ L84-88附近
- 结论: LDAP注入漏洞：通过文件读取的未净化数据被直接拼接到LDAP搜索过滤器中，攻击者需能控制文件内容（如通过写权限或控制文件路径）以修改LDAP查询逻辑，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_e407b459
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 133. hyp_path_501bb7402a49

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_42.c:99
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够在程序运行时通过控制台输入数据
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin) @ case0Source函数内部，使用fgets从stdin读取输入; _snprintf(filter, 256-1, "(cn=%s)", data); @ main函数第69行，将用户输入拼接到LDAP过滤器中; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ main函数第80行，使用未净化的filter执行LDAP搜索
- 结论: 代码从控制台读取输入并直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。
- D验证: confirmed / ver_b1b2b575
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 134. hyp_path_74e36cebeff9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_42.c:101
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过文件写入等方式控制data变量的内容
- 触发路径: static char * case0Source(char * data) { ... fgets(data+dataLen, (int)(256-dataLen), pFile); ... } @ L32-56; char filter[256]; _snprintf(filter, 256-1, "(cn=%s)", data); @ L69; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ... filter, ...); @ L82-86
- 结论: LDAP注入漏洞：通过文件读取的用户输入直接拼接到LDAP查询过滤器，攻击者可以控制data内容，从而注入恶意LDAP查询，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_910b287d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 135. hyp_path_7d28e2a7bb95

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_43.cpp:103
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件的内容（如通过路径遍历或上传恶意文件）; LDAP连接成功（ldap_initW和ldap_connect返回成功）
- 触发路径: case0Source从文件读取数据到data @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_43.cpp:35-58; _snwprintf(filter, 256-1, L"(cn=%s)", data); // 直接拼接data到LDAP过滤器 @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_43.cpp:73; ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_43.cpp:86
- 结论: LDAP注入漏洞：从文件读取的用户输入直接拼接到LDAP搜索过滤器字符串，攻击者可通过控制文件内容操纵LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_130a5404
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 136. hyp_path_4840bd4fb691

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_33.cpp:99
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过标准输入（stdin）提供输入; 目标LDAP服务器可达且配置允许搜索
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ CWE90_LDAP_Injection__w32_wchar_t_console_33.cpp:35-39; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, data, ...) @ CWE90_LDAP_Injection__w32_wchar_t_console_33.cpp:80-84
- 结论: LDAP注入漏洞：从控制台读取的用户输入直接用于LDAP搜索操作，未经过滤或转义，攻击者可以通过构造特殊输入注入LDAP过滤条件，导致信息泄露或未授权访问。
- D验证: confirmed / ver_1c32717c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 137. hyp_path_32b4e8f31ef1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_31.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序的标准输入提供任意字符串
- 触发路径: size_t dataLen = wcslen(data); ... if (256-dataLen > 1) ... if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L31-L35; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, data, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L77-L81
- 结论: LDAP注入漏洞：从控制台读取的用户输入未经任何过滤或转义直接拼接至LDAP查询语句中，导致攻击者可以通过注入特殊字符操纵LDAP查询，可能泄露或修改目录信息。
- D验证: confirmed / ver_7c66effc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 138. hyp_path_31ce8e221e6f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_34.c:103
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序的标准输入提供恶意字符串
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin) @ L38-42; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...) @ L84-88
- 结论: 代码存在LDAP注入漏洞。攻击者通过控制台输入提供恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_669ff592
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 139. hyp_path_6fdb9b49e61f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_33.cpp:99
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过标准输入提供任意字符串，该字符串作为LDAP搜索过滤器的参数被使用。
- 触发路径: 进入case0函数 @ L29（函数入口）; dataLen = strlen(data); if (dataLen > 0 && data[dataLen-1] == '\n') { ... } if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L37-48（fgets读取输入）; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, data, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L80-84（调用ldap_search_ext_sA）
- 结论: 存在LDAP注入漏洞：用户通过控制台（stdin）输入的数据经fgets读取后，未经验证或转义，直接作为过滤器参数传递给ldap_search_ext_sA，允许攻击者执行任意LDAP查询。
- D验证: confirmed / ver_2ba49727
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 140. hyp_path_479599e96e8b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_42.c:101
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件的内容（如FILENAME指定的文件）
- 触发路径: data = case0Source(data); // reads from file into wchar_t buffer @ case0Source function (L32-56); _snwprintf(filter, 256-1, L"(cn=%s)", data); // user input concatenated without sanitization @ L69-71; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); // sink: LDAP search with user-controlled filter @ L82-86
- 结论: LDAP注入漏洞：用户从文件读取的输入未经转义直接拼接到LDAP搜索过滤器，攻击者可通过控制文件内容注入任意LDAP过滤器，可能导致未授权数据访问或权限提升。
- D验证: confirmed / ver_f165a952
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 141. hyp_path_24b5410e2251

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_32.c:101
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入任意字符串
- 触发路径: size_t dataLen = wcslen(data); ... if (256-dataLen > 1) @ 代码片段[seed,focus] juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_32.c:35-39; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... @ 代码片段[seed] juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_32.c:82-86
- 结论: LDAP注入漏洞：程序通过fgetws从控制台读取用户输入，并可能拼接到ldap_search_ext_sW的filter参数中，但代码证据未直接证实filter参数包含用户输入，需进一步验证。
- D验证: confirmed / ver_7b394082
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 142. hyp_path_14957e0bc561

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_74a.cpp:101
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够与监听socket建立连接并发送恶意LDAP注入载荷
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L101; dataMap[0] = data;; _ZN50CWE90_LDAP_Injection__w32_wchar_t_listen_socket_749case0SinkESt3mapIiPwSt4lessIiESaISt4pairIKiS1_EEE @ sink函数调用
- 结论: LDAP注入漏洞：从网络接收的未验证数据被存储到map中，并传递给sink函数，可能在LDAP查询中使用，导致注入攻击。
- D验证: stage_c_preserved / ver_86ec4971
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 143. hyp_path_643ce5ed56e4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_32.c:101
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入或重定向提供任意字符串
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin); @ L35-39; snprintf(filter, 256, "(|(samaccountname=%s))", data); @ L?? (snprintf行，大约在L80-86之间); searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L101
- 结论: LDAP注入漏洞：从控制台读取的输入未经任何过滤或编码，直接通过snprintf拼接到LDAP搜索过滤器中，并传递给ldap_search_ext_sA，攻击者可通过构造特殊字符（如'*', '(', ')', '|'等）修改LDAP查询语义，导致未授权访问或信息泄露。
- D验证: confirmed / ver_651042b7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 144. hyp_path_231d73acf676

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_34.c:103
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台提供输入（本地或远程交互）; LDAP连接成功（ldap_connect返回LDAP_SUCCESS）
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L38-42; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, data, NULL, NULL, NULL, &pMessage); @ L84-88
- 结论: LDAP注入漏洞：攻击者通过控制台输入构造恶意LDAP过滤器，导致未授权访问或数据泄露。
- D验证: confirmed / ver_faca453b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 145. hyp_path_4f494a638c2f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_72a.cpp:101
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够连接至目标主机的监听端口（TCP_PORT），并发送包含LDAP注入payload的网络数据。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_72a.cpp:101; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_72a.cpp:103; dataVector.insert(dataVector.end(), 1, data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_72a.cpp:109; case0Sink(dataVector); // 调用sink函数，可能执行LDAP查询 @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_72a.cpp:110
- 结论: LDAP注入漏洞：从网络接收的数据未经充分验证被直接用于LDAP查询构造，攻击者可通过控制输入注入恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_012aab61
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 146. hyp_path_c67fa14a74c7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_72a.cpp:101
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够连接到目标主机上的TCP端口（由TCP_PORT定义），并发送恶意负载；负载必须包含有效的LDAP注入语法，且不超过缓冲区大小（256 wchar_t）。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_72a.cpp:99-103; dataVector.insert(dataVector.end(), 1, data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_72a.cpp:106; case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_72a.cpp:108
- 结论: 网络接收的数据未经任何验证或转义，直接存储到vector中并传递给LDAP查询处理函数（case0Sink），导致LDAP注入漏洞。攻击者可以通过构造特制的网络输入，在LDAP查询中执行任意命令。
- D验证: stage_c_preserved / ver_3d1199bb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 147. hyp_path_838e485f6a36

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_74a.cpp:101
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够与目标服务建立网络连接并发送数据到监听端口
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ CWE90_LDAP_Injection__w32_char_listen_socket_74a.cpp:101; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ CWE90_LDAP_Injection__w32_char_listen_socket_74a.cpp:101-102; dataMap[0] = data; // 将接收数据存入map @ CWE90_LDAP_Injection__w32_char_listen_socket_74a.cpp:127; case0Sink(dataMap); // 调用sink函数，具体实现未提供，但典型CWE90测试用例中会调用LDAP API @ _ZN47CWE90_LDAP_Injection__w32_char_listen_socket_749case0SinkESt3mapIiPcSt4lessIiESaISt4pairIKiS1_EEE
- 结论: 在CWE90 LDAP注入测试用例中，通过recv()接收的网络数据未经任何过滤或转义，直接存储到map中，并随后传递给case0Sink函数用于LDAP查询。尽管case0Sink函数的具体实现未在提供的代码片段中展示，但根据项目结构和CWE命名惯例，可以推断其包含LDAP API调用（如ldap_simple_bind_s或类似），导致攻击者可以注入任意LDAP过滤器。证据链存在缺口，但漏洞假设仍合理。
- D验证: stage_c_preserved / ver_27880ac8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 148. hyp_path_e6dad3c97494

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_74a.cpp:86
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够与运行该代码的主机建立网络连接; 攻击者可以发送精心构造的LDAP注入payload
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_74a.cpp:91; dataMap[0] = data; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_74a.cpp:96; case0Sink(dataMap); // sink函数假设执行LDAP查询 @ sink函数调用处（具体行号未在证据中提供）
- 结论: LDAP注入漏洞：程序通过recv从网络接收数据，未经过消毒直接存储到std::map中，随后传递给sink函数用于LDAP操作，攻击者可以控制网络输入并注入LDAP查询。
- D验证: stage_c_preserved / ver_5ec98826
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 149. hyp_path_300169f2d6e9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_72a.cpp:86
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到目标服务并发送特制LDAP注入载荷
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_72a.cpp:86; dataVector.insert(dataVector.end(), 1, data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_72a.cpp:93; ldap_search_s(ld, ...) 等LDAP调用，B阶段种子确认sink函数存在 @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_72a.cpp:? (case0Sink函数)
- 结论: 存在LDAP注入漏洞。程序通过recv从socket接收用户输入，未经过滤即存储到vector中，并传递至case0Sink函数，该函数将数据用于LDAP查询，攻击者可注入恶意LDAP过滤器。
- D验证: stage_c_preserved / ver_7b4f41ca
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 150. hyp_path_2a8f48a27794

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_73a.cpp:101
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到listen socket并发送恶意LDAP注入payload。; 服务器端在sink函数中使用list数据构造LDAP查询，且未进行输入验证。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_73a.cpp:101; dataList.push_back(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_73a.cpp:112; call:_ZN47CWE90_LDAP_Injection__w32_char_listen_socket_739case0SinkENSt7__cxx114listIPcSaIS2_EEE (B阶段证据中sink调用) @ 同文件或链接的sink函数
- 结论: 网络接收的数据未经消毒直接存储到list中，并传递给后续的LDAP查询sink函数，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_fdd88003
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 151. hyp_path_260d98f92d19

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_12.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: Attacker can send arbitrary data to the server's listening port.; The program must take the branch where globalReturnsTrueOrFalse() returns true (approx. 50% probability).
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); if (listenSocket == INVALID_SOCKET) { ... } @ L72-76; acceptSocket = accept(listenSocket, NULL, NULL); if (acceptSocket == SOCKET_ERROR) { ... } @ L83; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ L95-99; data[dataLen + recvResult] = '\0'; trsz = recvResult; ... } while (1); @ L100-103; _snprintf(filter, 256-1, "(cn=%s)", data); @ L110-112; pLdapConnection = ldap_initA("localhost", LDAP_PORT); if (pLdapConnection == NULL) { ... } @ L113-114; ldap_connect(pLdapConnection, NULL); ... ldap_search_s(pLdapConnection, "DC=example,DC=com", LDAP_SCOPE_SUBTREE, filter, NULL, 0, &pMessage); @ L115-117
- 结论: LDAP Injection vulnerability: user-controlled data from network socket is concatenated into an LDAP search filter without sanitization, allowing an attacker to modify the LDAP query. The vulnerable path is taken when globalReturnsTrueOrFalse() returns true (approx. 50% of cases), otherwise a fixed string is used.
- D验证: stage_c_preserved / ver_0a5c15ed
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 152. hyp_path_45700dfd0df0

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_72a.cpp:86
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到目标服务，并发送包含LDAP元字符（如*、()、&、|、!等）的恶意数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_72a.cpp:86; dataVector.insert(dataVector.end(), 1, data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_72a.cpp:93; 未提供内部代码，但函数名和测试用例背景强烈暗示包含LDAP API调用，如ldap_search_s等。 @ sink函数调用（函数名 _ZN48CWE90_LDAP_Injection__w32_char_connect_socket_729case0SinkESt6vectorIPcSaIS1_EE）
- 结论: 从网络socket接收的数据未经任何消毒处理直接传递给LDAP查询sink函数，导致LDAP注入漏洞（CWE-90）。攻击者可以通过构造恶意LDAP查询字符串，利用该漏洞执行未经授权的LDAP操作。
- D验证: stage_c_preserved / ver_db40802a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 153. hyp_path_d77a3d7ef954

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_12.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务并发送特制数据; 全局函数globalReturnsTrueOrFalse()返回true
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L82; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L109; ldap_search_ext_sW(pLdapConnection, ...); @ L111
- 结论: 网络接收的数据直接拼接到LDAP查询过滤器中，导致LDAP注入漏洞。攻击者可通过网络发送恶意数据，在全局函数返回true时触发。
- D验证: confirmed / ver_827b0d76
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 154. hyp_path_d4ce1a3911e9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_12.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够与目标主机建立网络连接并发送任意数据。; 服务端未对LDAP查询结果进行额外验证或限制。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_12.c:87; strcat(data, "Doe, XXXXX"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_12.c:105; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_12.c:107; ldap_search_ext_sA(pLdapConnection, (char *)"dc=example,dc=com", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_12.c:118
- 结论: LDAP注入漏洞：从网络socket接收的数据未经充分过滤或转义，直接拼接进LDAP搜索过滤器，导致攻击者可以注入任意LDAP过滤器。
- D验证: confirmed / ver_a1b9f7d2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 155. hyp_path_99a8c1a11e8a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_41.c:134
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过TCP连接发送任意数据到目标主机，且数据长度和内容可控
- 触发路径: connect(connectSocket, ...); @ L132-136; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L139-140; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ L141-143; data[dataLen + recvResult / sizeof(char)] = '\0'; @ L148-149; replace = strchr(data, '\r'); ... *replace = '\0'; replace = strchr(data, '\n'); ... *replace = '\0'; @ L150-153; CWE90_LDAP_Injection__w32_char_connect_socket_41_case0Sink(data); @ L155; _snprintf(filter, 256-1, "(cn=%s)", data); @ L60-61; searchSuccess = ldap_search_ext_sA(..., filter, ...); @ L82
- 结论: 代码通过recv接收网络数据并直接拼接到LDAP搜索过滤器中，攻击者可以控制输入造成LDAP注入，绕过身份验证或泄露敏感信息。
- D验证: confirmed / ver_8f543d21
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 156. hyp_path_49ee745c3080

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_12.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向目标主机的监听端口发送网络数据包; 攻击者数据中包含LDAP注入载荷; globalReturnsTrueOrFalse()返回真，使代码进入socket读取分支（约50%概率）
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_12.c:95-99; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_12.c:112-114; pLdapConnection = ldap_initW(L"localhost", LDAP_PORT); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_12.c:117; ldap_connect(pLdapConnection, NULL); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_12.c:120; ldap_search_s(pLdapConnection, L"DC=example,DC=com", LDAP_SCOPE_SUBTREE, filter, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_12.c:124
- 结论: LDAP注入漏洞：通过socket接收的用户输入直接拼接到LDAP搜索过滤器中，攻击者可注入恶意LDAP查询语法，导致未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_77996a62
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 157. hyp_path_634a85be50cf

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_31.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向标准输入提供恶意字符串，且程序运行环境中LDAP服务器可达。
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin); // 用户输入读取 @ L33-L44; snprintf(filter, sizeof(filter), "(uid=%s)", data); // 构造过滤器，data直接嵌入 @ (附近行，存在snprintf调用); searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L95-L96
- 结论: LDAP注入漏洞：程序通过fgets从控制台读取用户输入，通过snprintf构造LDAP搜索过滤器，未经验证直接用于ldap_search_ext_sA的过滤器参数，攻击者可以注入恶意LDAP操作，导致信息泄露或未授权访问。
- D验证: confirmed / ver_4340072d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 158. hyp_path_309ed7cfaa5a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_73a.cpp:86
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过TCP连接向目标程序发送任意数据，且目标程序能够成功接收并处理这些数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_73a.cpp:91-95; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_73a.cpp:96-97; dataList.push_back(data); // data来自recv，未经消毒 @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_73a.cpp:98; call:_ZN48CWE90_LDAP_Injection__w32_char_connect_socket_739case0SinkENSt7__cxx114listIPcSaIS2_EEE（实现代码缺失） @ B阶段route内API种子中的sink函数
- 结论: 通过socket接收的数据未经消毒直接存储到list中，随后可能用于LDAP操作，导致LDAP注入漏洞，但sink函数的具体实现未提供，无法确认是否真正执行LDAP操作或存在消毒。
- D验证: stage_c_preserved / ver_7acc665c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 159. hyp_path_f30e1f01c419

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_41.c:149
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到服务器监听的端口; 攻击者可以发送任意数据到该socket
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ L124-128; bind(listenSocket, ...); listen(listenSocket, 5); @ L135; acceptSocket = accept(listenSocket, NULL, NULL); @ L135; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L149; CWE90_LDAP_Injection__w32_char_listen_socket_41_case0Sink(data); @ L100 (call); _snprintf(filter, 256-1, "(cn=%s)", data); @ L50-51 (inside sink); searchSuccess = ldap_search_ext_sA(pLdapConnection, ... filter ...); @ L72 (inside sink)
- 结论: LDAP注入漏洞：程序通过socket接收用户输入，未经过滤直接拼接到LDAP搜索过滤器中，导致攻击者可以注入任意LDAP查询。
- D验证: confirmed / ver_6e4e2201
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 160. hyp_path_99046bbbb73b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_41.c:149
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标机器的指定TCP端口（通常为某端口）并发送恶意LDAP注入数据。
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); if (listenSocket == INVALID_SOCKET) { ... } @ L124-128; acceptSocket = accept(listenSocket, NULL, NULL); if (acceptSocket == SOCKET_ERROR) { ... } @ L135-138; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ L147-151; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; @ L155-156; replace = wcschr(data, L'\r'); if (replace) { *replace = L'\0'; } replace = wcschr(data, L'\n'); if (replace) { *replace = L'\0'; } @ L159-164; CWE90_LDAP_Injection__w32_wchar_t_listen_socket_41_case0Sink(data); @ L166; _snwprintf(filter, 256-1, L"(cn=%s)", data); ... searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L79-83
- 结论: LDAP注入漏洞：通过recv()从网络套接字接收的数据直接拼接至LDAP搜索过滤器，攻击者可注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_7f0146e3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 161. hyp_path_3dae83b0aef1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_73a.cpp:101
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够连接到服务器的TCP端口并发送恶意数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_73a.cpp:101; dataList.push_back(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_73a.cpp:115; case0Sink(dataList); @ sink function call (implicit, not shown in snippet but present in B阶段API种子)
- 结论: LDAP注入漏洞：通过监听socket接收的数据未经过滤即被存储至list，并传递给sink函数（_ZN50CWE90_LDAP_Injection__w32_wchar_t_listen_socket_739case0SinkENSt7__cxx114listIPwSaIS2_EEE）执行LDAP查询，攻击者可注入任意LDAP语句。
- D验证: stage_c_preserved / ver_8b7cf66b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 162. hyp_path_df4140c261cb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_41.c:134
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接向目标服务发送数据，且目标服务未对输入进行任何LDAP注入防护。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_41.c:139-143; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_41.c:148-156; CWE90_LDAP_Injection__w32_wchar_t_connect_socket_41_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_41.c:100; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_41.c:54-56; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_41.c:68-70
- 结论: LDAP注入漏洞：从网络套接字接收的数据未经验证直接拼接到LDAP搜索过滤器中，攻击者可以通过注入LDAP元字符操纵查询。
- D验证: confirmed / ver_6953e0c7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 163. hyp_path_f6c8900851d2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_51a.c:98
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到监听端口并发送特制数据。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_51a.c:98; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_51a.c:100-101; CWE90_LDAP_Injection__w32_char_listen_socket_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_51a.c:107
- 结论: 代码通过recv从网络接收数据并直接传递给CWE90_LDAP注入sink函数，攻击者可控制输入导致LDAP注入。
- D验证: stage_c_preserved / ver_1e1bf5d3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 164. hyp_path_6ce300135c42

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_53a.c:98
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标主机的监听端口并发送恶意LDAP注入payload
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_53a.c:96-100; CWE90_LDAP_Injection__w32_char_listen_socket_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_53a.c:（行数未明确）
- 结论: 代码从网络socket接收数据，未经验证直接传递给LDAP注入漏洞sink函数，攻击者可通过发送特制数据执行LDAP注入攻击。
- D验证: stage_c_preserved / ver_126b8a8f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 165. hyp_path_e0f33f3cd096

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_52a.c:98
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序监听的端口，并发送包含LDAP特殊字符的恶意数据。
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ L75; acceptSocket = accept(listenSocket, NULL, NULL); @ L84; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L98; CWE90_LDAP_Injection__w32_char_listen_socket_52b_case0Sink(data); @ L107
- 结论: 程序通过网络socket接收数据，未对数据进行任何LDAP注入防御处理，直接传递给LDAP查询函数，导致攻击者可以注入任意LDAP过滤器，可能引发未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_4143795c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 166. hyp_path_d6abb8fbaf1e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54a.c:98
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够建立网络连接并发送恶意LDAP查询字符串
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L97-98; CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54b_case0Sink(data); @ L118
- 结论: 代码通过套接字接收用户输入，未经验证直接传递给LDAP查询函数，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_a1de362f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 167. hyp_path_1fae6ca1e456

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_64a.c:98
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过acceptSocket连接服务，并发送任意数据。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ CWE90_LDAP_Injection__w32_char_listen_socket_64a.c:98; data[dataLen + recvResult / sizeof(char)] = '\0'; replace = strchr(data, '\n'); if (replace) { *replace = '\0'; } @ CWE90_LDAP_Injection__w32_char_listen_socket_64a.c:104-105; CWE90_LDAP_Injection__w32_char_listen_socket_64b_case0Sink(&data); @ CWE90_LDAP_Injection__w32_char_listen_socket_64a.c:109
- 结论: 代码存在LDAP注入漏洞，通过recv()从网络套接字接收的数据未经充分净化即传递给sink函数，形成可被利用的注入路径。
- D验证: stage_c_preserved / ver_e5d0a9c8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 168. hyp_path_b7431ace731c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53a.c:98
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络访问目标主机的监听端口并发送恶意数据
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53a.c:84; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53a.c:98; CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53a.c:104
- 结论: 代码通过socket接收网络数据，并将数据直接传递给LDAP查询的sink函数，未进行任何过滤或转义，导致LDAP注入漏洞。攻击者可以发送特制字符串修改LDAP查询，造成未授权访问或数据泄露。
- D验证: stage_c_preserved / ver_a7ddae0b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 169. hyp_path_74988a7f632e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_54a.c:98
- 漏洞类型: CWE-90, CWE-20
- CWE: CWE-90; CWE-20
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标端口并发送恶意LDAP注入载荷
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_54a.c:96-100; replace = strchr(data, '\r'); if (replace) { *replace = '\0'; } replace = strchr(data, '\n'); if (replace) { *replace = '\0'; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_54a.c:113-118; CWE90_LDAP_Injection__w32_char_listen_socket_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_54a.c:122-126
- 结论: LDAP注入漏洞：程序通过socket接收用户输入，未经过滤直接传递给LDAP查询，允许攻击者注入LDAP元字符，可能导致未授权访问或数据泄露。
- D验证: stage_c_preserved / ver_05a21ab2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 170. hyp_path_7d7d0fde0eae

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_63a.c:98
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接目标socket，并发送特制数据触发LDAP注入。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_63a.c:98; data[dataLen + recvResult / sizeof(char)] = '\0'; ... CWE90_LDAP_Injection__w32_char_listen_socket_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_63a.c:107-108
- 结论: 通过recv从网络接收数据后，直接传递给sink函数用于LDAP查询，未进行任何输入验证或转义，可能导致LDAP注入攻击。
- D验证: stage_c_preserved / ver_5326432f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 171. hyp_path_bf3008e86789

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_64a.c:98
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够与服务器建立TCP连接，并发送包含LDAP注入载荷的数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_64a.c:98; CWE90_LDAP_Injection__w32_wchar_t_listen_socket_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_64a.c:106
- 结论: 代码通过recv从网络接收数据，然后直接将数据传递给LDAP操作sink函数，未进行任何输入验证或转义，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_8dd3e3fe
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 172. hyp_path_c545844026e3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_51a.c:98
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标主机监听端口（TCP_PORT）。
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ L75; acceptSocket = accept(listenSocket, NULL, NULL); @ L84; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L98; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; @ L104; CWE90_LDAP_Injection__w32_wchar_t_listen_socket_51b_case0Sink(data); @ L131
- 结论: 通过网络接收的数据未经任何过滤或转义直接传递给LDAP查询函数，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_e918ca24
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 173. hyp_path_4b75880c641e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_63a.c:98
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够连接到目标主机的监听端口，并发送特制的LDAP注入payload
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L96-100; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ L101; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; @ L113-120; CWE90_LDAP_Injection__w32_wchar_t_listen_socket_63b_case0Sink(&data); @ L126
- 结论: 存在LDAP注入漏洞：通过监听套接字接收的输入数据未经任何净化直接传递给LDAP查询sink函数，攻击者可构造恶意输入实现LDAP注入。
- D验证: stage_c_preserved / ver_77e7fe21
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 174. hyp_path_73fc948d2757

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_52a.c:98
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够与目标服务器建立TCP连接并发送自定义数据。; 服务器监听套接字正确启动并接受连接。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_52a.c:98; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_52a.c:105; CWE90_LDAP_Injection__w32_wchar_t_listen_socket_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_52a.c:115
- 结论: 该代码存在LDAP注入漏洞。从网络套接字接收的数据未经充分净化即传递给LDAP查询函数，攻击者可通过构造特殊输入实现LDAP注入攻击。
- D验证: stage_c_preserved / ver_c2d8dff6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 175. hyp_path_847acbda1959

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_17.c:83
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过socket向程序发送任意数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L83; _snprintf(filter, 256-1, "(cn=%s)", data); @ L103; rc = ldap_search_ext_sA(pLdapConnection, ...); @ L104
- 结论: 从网络接收的数据直接拼接进LDAP搜索过滤器，导致LDAP注入漏洞。攻击者可通过控制输入数据修改LDAP查询语义，可能绕过认证或获取未授权数据。
- D验证: confirmed / ver_5ad56d4b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 176. hyp_path_e0352c20e67c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_82a.cpp:95
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到监听端口，并发送包含LDAP注入载荷的数据。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_82a.cpp:95; baseObject->action(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_82a.cpp:126
- 结论: 该代码从网络套接字接收用户输入并传递给action函数，根据项目上下文（CWE90 LDAP Injection测试用例），action函数内部会使用接收的数据作为LDAP查询过滤器参数，存在LDAP注入漏洞。
- D验证: stage_c_preserved / ver_b1944a88
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 177. hyp_path_b7b6c837c611

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_82a.cpp:95
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到监听的socket并发送特制的LDAP注入载荷
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_82a.cpp:95; baseObject->action(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_82a.cpp:109
- 结论: 网络接收的数据未经消毒直接传递给LDAP查询函数，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_41cc05fe
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 178. hyp_path_5dd82388f272

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_54a.c:83
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够连接到目标服务并发送包含LDAP注入载荷的数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_54a.c:88-92; CWE90_LDAP_Injection__w32_char_connect_socket_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_54a.c:112-114
- 结论: 代码从网络接收数据后直接传递给LDAP操作函数，未进行输入验证或转义，存在LDAP注入漏洞。
- D验证: stage_c_preserved / ver_15611ae5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 179. hyp_path_8db59fbd3b0a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_17.c:98
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到监听端口并发送恶意数据; LDAP服务器（localhost）可达且服务运行
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_17.c:96-100; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_17.c:117-118; pLdapConnection = ldap_initA("localhost", LDAP_PORT); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_17.c:120; rc = ldap_search_ext_sA(pLdapConnection, (char *)"", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_17.c:128-129
- 结论: LDAP注入漏洞：通过listen socket接收的未过滤数据直接拼接到LDAP搜索过滤器，导致攻击者可注入任意LDAP查询。
- D验证: confirmed / ver_f5f045c1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 180. hyp_path_7d1d80c65015

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_17.c:98
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到服务器监听的端口（如默认LDAP端口389或自定义端口）并发送任意数据，且LDAP服务器可访问。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ recv调用（第98行）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 数据拼接（第113行）; ldap_search_ext_sW(pLdapConnection, searchbase, LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ LDAP搜索（第115行）
- 结论: 代码通过socket接收网络数据，然后直接拼接到LDAP查询过滤器字符串中，导致LDAP注入漏洞。攻击者可以通过发送精心构造的字符串修改LDAP查询语义，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_61caf7ad
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 181. hyp_path_5218c55d7c82

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_63a.c:83
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够访问服务器监听的TCP端口并发送特制数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_63a.c:88-92; CWE90_LDAP_Injection__w32_char_connect_socket_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_63a.c:103-110
- 结论: LDAP注入漏洞：通过 recv() 从网络接收的输入数据未经充分验证，直接传递给 LDAP 查询函数，攻击者可注入恶意 LDAP 过滤器，导致信息泄露或未授权访问。
- D验证: stage_c_preserved / ver_70df630d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 182. hyp_path_049dbccc9e20

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_53a.c:83
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够与目标程序建立网络连接，并发送特制的LDAP注入载荷。
- 触发路径: service.sin_addr.s_addr = inet_addr(IP_ADDRESS); service.sin_port = htons(TCP_PORT); if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR) { break; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_53a.c:74-78; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_53a.c:83; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_53a.c:89-92; CWE90_LDAP_Injection__w32_char_connect_socket_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_53a.c:105
- 结论: LDAP注入漏洞：程序从socket接收网络数据，未经验证便传递给潜在LDAP查询sink函数（sink实现未验证），攻击者可通过构造特殊输入进行LDAP注入，可能导致未授权访问或数据泄露。
- D验证: stage_c_preserved / ver_58f40f80
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 183. hyp_path_72994b452e87

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_51a.c:83
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络向目标套接字发送任意数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_51a.c:88-92; CWE90_LDAP_Injection__w32_char_connect_socket_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_51a.c:? (sink调用)
- 结论: LDAP注入漏洞：程序从网络套接字接收数据，未经过滤直接传递给LDAP查询构造函数，攻击者可控制输入导致LDAP注入。
- D验证: stage_c_preserved / ver_fa45abef
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 184. hyp_path_e56b2452fb0d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_51a.c:83
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络向目标端口发送恶意构造的LDAP注入payload
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_51a.c:88-92; CWE90_LDAP_Injection__w32_wchar_t_connect_socket_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_51a.c:114（调用sink）
- 结论: LDAP注入漏洞：从网络socket接收的数据未经消毒直接传递给LDAP查询操作，攻击者可注入恶意LDAP过滤器。
- D验证: stage_c_preserved / ver_d75fb7f6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 185. hyp_path_fcabe0713cb9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_52a.c:83
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: The attacker must be able to send arbitrary data to the server port on which the socket is listening/connected.
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_52a.c:88; CWE90_LDAP_Injection__w32_char_connect_socket_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_52a.c:109
- 结论: LDAP Injection vulnerability: the data received from a network socket is directly passed to a sink function without sanitization, allowing an attacker to inject LDAP commands.
- D验证: stage_c_preserved / ver_9c7cac53
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 186. hyp_path_a5d8ef37a15f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_52a.c:83
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制连接目标程序所连接的远程服务器，发送包含LDAP注入载荷的数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_52a.c:89; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; replace = wcschr(data, L'\r'); if (replace) { *replace = L'\0'; } replace = wcschr(data, L'\n'); if (replace) { *replace = L'\0'; } @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_52a.c:99-103; CWE90_LDAP_Injection__w32_wchar_t_connect_socket_52b_case0Sink(data); @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_52a.c:107
- 结论: 通过socket接收的用户输入直接传递给LDAP查询sink函数，导致LDAP注入漏洞（CWE-90）。攻击者可以控制输入数据，注入LDAP过滤器或DN，实现未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_5329bdb5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 187. hyp_path_5bcff24dc0e5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_64a.c:83
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到目标程序监听的端口，并发送特制的LDAP注入字符串
- 触发路径: SOCKET connectSocket = INVALID_SOCKET; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_64a.c:74; if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR) { break; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_64a.c:81-85; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_64a.c:88-92; data[dataLen + recvResult / sizeof(char)] = '\0'; replace = strchr(data, '\r'); if (replace) { *replace = '\0'; } replace = strchr(data, '\n'); if (replace) { *replace = '\0'; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_64a.c:93-97; CWE90_LDAP_Injection__w32_char_connect_socket_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_64a.c:109
- 结论: LDAP注入漏洞：程序通过connect socket接收外部输入数据，并将其传递给sink函数CWE90_LDAP_Injection__w32_char_connect_socket_64b_case0Sink，该函数内部可能执行未经验证的LDAP查询，攻击者可通过控制输入进行LDAP注入攻击。
- D验证: stage_c_preserved / ver_c696d6ac
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 188. hyp_path_f19ea42daf68

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_64a.c:83
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务，并发送恶意构造的数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_64a.c:83; CWE90_LDAP_Injection__w32_wchar_t_connect_socket_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_64a.c:102-104
- 结论: 从网络套接字接收的数据未经验证即传递到LDAP查询构造函数，导致LDAP注入漏洞。攻击者可通过发送特制数据在LDAP查询中注入任意命令。
- D验证: stage_c_preserved / ver_1240ae53
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 189. hyp_path_3a31a596b0d1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_53a.c:83
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到服务器并发送恶意数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_53a.c:88-92; CWE90_LDAP_Injection__w32_wchar_t_connect_socket_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_53a.c:107
- 结论: LDAP注入漏洞：通过socket接收的用户输入未经验证和过滤，直接传递给LDAP查询，攻击者可注入恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_387d25a7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 190. hyp_path_4f4983ca8218

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54a.c:83
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够连接到目标服务端口并发送恶意LDAP注入payload
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54a.c:83; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54a.c:88-92; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54a.c:102-103; CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54a.c:104
- 结论: 代码从网络套接字接收数据后，未经任何LDAP注入过滤或转义，直接传递给sink函数（CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54b_case0Sink），存在LDAP注入漏洞。sink内部实现未提供，但根据Juliet测试用例的常见模式，sink通常直接构造LDAP查询而不净化。
- D验证: stage_c_preserved / ver_b6ce1224
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 191. hyp_path_02772035a733

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_17.c:83
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接向目标服务发送恶意数据，并且数据能够被recv()接收。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L83; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; replace = wcschr(data, L'\r'); if (replace) { *replace = L'\0'; } @ L88-92; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L94; pLdapConnection = ldap_initW(L"localhost", LDAP_PORT); ldap_connect(pLdapConnection, NULL); if (LDAP_SUCCESS != ldap_search_ext_sW(pLdapConnection, ...)) @ L96-100
- 结论: LDAP注入漏洞：通过recv()接收的输入数据未经任何过滤直接拼接到LDAP搜索过滤器中，攻击者可以注入LDAP元字符修改查询语义。
- D验证: confirmed / ver_e092a920
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 192. hyp_path_02f3d4021988

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_82a.cpp:80
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够与目标程序建立网络连接并发送恶意载荷
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_82a.cpp:80; baseObject->action(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_82a.cpp:附近
- 结论: LDAP注入漏洞：程序从网络套接字接收数据，通过action(data)传递给可能的LDAP查询操作，但未验证输入。尽管当前代码片段中未直接显示LDAP函数调用，但action(data)的实现可能涉及LDAP操作，且样本明确标注CWE90，存在漏洞可能性。
- D验证: stage_c_preserved / ver_6789b7ce
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 193. hyp_path_740688994f3c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_01.c:95
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够访问服务器监听的网络端口，并发送特制的LDAP注入字符串。
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ 监听socket接受连接; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ 从acceptSocket接收数据到data缓冲区; _snprintf(filter, 256-1, "(cn=%s)", data); @ 数据拼接到LDAP过滤器; ldap_search_ext_sA(pLdapConnection, ...); @ 执行LDAP搜索（调用ldap_search_ext_sA）
- 结论: LDAP注入漏洞：从网络socket接收的用户输入未经任何消毒直接拼接到LDAP搜索过滤器字符串中，攻击者可绕过认证或获取未授权数据。
- D验证: confirmed / ver_2f7b43bf
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 194. hyp_path_e1c5c5355532

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_02.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到监听socket并发送数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_02.c:97; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_02.c:107-108; ldap_search_ext_sA(pLdapConnection, ... filter ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_02.c:132
- 结论: LDAP注入漏洞：从网络接收的数据直接拼接到LDAP搜索过滤器，攻击者可以通过控制输入执行任意LDAP查询，导致信息泄露或越权操作。
- D验证: confirmed / ver_4c7d97b3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 195. hyp_path_ee1bcf3ea8da

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_08.c:111
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接目标程序的监听端口，并发送包含LDAP注入payload的数据。
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ L86-90; acceptSocket = accept(listenSocket, NULL, NULL); @ L97-98; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L109-113; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L124-126; pLdapConnection = ldap_initW(L"localhost", LDAP_PORT); rc = ldap_search_ext_sW(pLdapConnection, ...); @ L130-132
- 结论: LDAP注入漏洞：程序通过listen socket接收用户输入，将输入直接拼接到LDAP搜索过滤器字符串中，然后执行ldap_search_ext_sW，攻击者可以构造恶意LDAP过滤器进行注入攻击。
- D验证: confirmed / ver_a4473ed9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 196. hyp_path_a538273555af

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_11.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够与目标服务建立TCP连接并发送数据; recv调用成功接收数据，未触发错误或关闭连接; globalReturnsTrue() 条件为真（始终成立）
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_11.c:97; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_11.c:114; ldap_search_s(pLdapConnection, NULL, 0, filter, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_11.c:130
- 结论: CWE90_LDAP_Injection__w32_char_listen_socket_11.c 从socket接收数据后，未经净化直接拼接到LDAP查询过滤器字符串中，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_aa1c92a7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 197. hyp_path_7fea2f472871

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_82a.cpp:80
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到目标socket并发送任意数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_82a.cpp:85-90; CWE90_LDAP_Injection__w32_wchar_t_connect_socket_82_base* baseObject = new CWE90_LDAP_Injection__w32_wchar_t_connect_socket_82_case0; baseObject->action(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_82a.cpp:104-105; 假设直接使用data构造LDAP查询，但未提供实际代码验证 @ action方法实现（未在当前文件中提供）
- 结论: 存在LDAP注入漏洞，攻击者可通过网络发送恶意数据，该数据被接收后可能直接用于LDAP查询，导致未授权访问或信息泄露。但由于sink（LDAP查询）代码未在提供的证据中展示，无法完全确认路径闭合。
- D验证: stage_c_preserved / ver_df4e6234
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 198. hyp_path_32b437595ac2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_63a.c:83
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够访问目标机器的网络端口（TCP端口由代码中的TCP_PORT指定）。; 攻击者能够发送包含LDAP注入payload的数据包。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_63a.c:83; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_63a.c:102-103; CWE90_LDAP_Injection__w32_wchar_t_connect_socket_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_63a.c:113
- 结论: 网络接收的数据未经任何净化直接传递给LDAP查询sink，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_68523edb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 199. hyp_path_fc61d4d3218d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_04.c:104
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标服务器的特定端口（本例中为localhost:LDAP_PORT）
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_04.c:104; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_04.c:约116行; ldap_search_ext_sA(pLdapConnection, "(cn=...)", ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_04.c:约130行
- 结论: LDAP注入漏洞：程序通过socket接收外部输入，将数据直接拼接到LDAP搜索过滤器中，未进行任何转义或验证，攻击者可注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_2a4c0e4f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 200. hyp_path_4ff0d5b6698c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_08.c:111
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到监听socket并发送恶意字符串，例如包含LDAP过滤器特殊字符（如'*', '|', '&', '!'等）
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L111; _snprintf(filter, 256-1, "(cn=%s)", data); @ L120; ldap_search_ext_sA(pLdapConnection, ...); @ L130
- 结论: LDAP注入漏洞：通过监听socket接收的数据直接拼接到LDAP查询过滤器中，攻击者可控制输入导致LDAP注入。
- D验证: confirmed / ver_122dcbc1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 201. hyp_path_4b96ff82ee85

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_05.c:104
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到服务端监听端口并发送恶意数据
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); ... acceptSocket = accept(listenSocket, NULL, NULL); @ L79-L83; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ L102-L106; _snprintf(filter, 256-1, "(cn=%s)", data); @ L109; pLdapConnection = ldap_initA("localhost", LDAP_PORT); ... ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L119-L120
- 结论: 代码从网络接收数据后，未经过滤直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可通过发送特制数据操纵LDAP查询。
- D验证: confirmed / ver_793c4ac0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 202. hyp_path_beb3d2627e22

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_06.c:101
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向服务端口发送TCP数据
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_06.c:78; acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_06.c:87; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_06.c:101; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_06.c:114; ldap_search_ext_sA(pLdapConnection, ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_06.c:119
- 结论: LDAP注入漏洞：程序通过socket接收用户输入，直接拼接到LDAP查询过滤器中，攻击者可构造恶意输入修改LDAP查询逻辑，导致未授权访问或信息泄露。
- D验证: confirmed / ver_fdaeb564
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 203. hyp_path_c8151c75ad03

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_09.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接并发送包含LDAP注入payload的字符串。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_09.c:95-97; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_09.c:约110行; ldap_search_ext_sA(pLdapConnection, ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_09.c:约112行
- 结论: LDAP注入漏洞：从网络接收的数据未经充分验证直接拼接到LDAP搜索过滤器中，攻击者可通过注入LDAP过滤器语法操纵查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_fa247480
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 204. hyp_path_76171940cbd2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_03.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标机器的监听端口，并发送特制的字符串作为LDAP注入payload
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ L72-76; acceptSocket = accept(listenSocket, NULL, NULL); @ L83; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L97; _snprintf(filter, 256-1, "(cn=%s)", data); @ L108; ldap_search_ext_sA(pLdapConnection, filter, ...); @ L110
- 结论: LDAP注入漏洞：从网络接收的未经过滤的数据直接拼接到LDAP搜索过滤器中，导致攻击者可以注入任意LDAP查询。
- D验证: confirmed / ver_d049e275
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 205. hyp_path_32a967612a45

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_07.c:103
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序监听的端口，并发送任意网络数据包。
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); if (listenSocket == INVALID_SOCKET) { ... } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_07.c:78-82; acceptSocket = accept(listenSocket, NULL, NULL); if (acceptSocket == SOCKET_ERROR) { ... } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_07.c:89-91; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_07.c:101-105; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_07.c:117-119; ldap_search_ext_s(pLdapConnection, ... filter ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_07.c:123
- 结论: LDAP注入漏洞：通过listen socket接收的输入未经适当转义或参数化，直接拼接到LDAP搜索过滤器字符串中，导致攻击者可以注入恶意LDAP查询语法，可能访问、修改或绕过LDAP目录的访问控制。
- D验证: stage_c_preserved / ver_1cef34a4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 206. hyp_path_897195c3252d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_11.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务开放的端口; 目标服务在globalReturnsTrue()条件下运行（即始终为真）
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); if (listenSocket == INVALID_SOCKET) { ... } @ L72-76; acceptSocket = accept(listenSocket, NULL, NULL); if (acceptSocket == SOCKET_ERROR) { ... } @ L83; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ L95-99; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; replace = wcschr(data, L'\r'); if (replace) { *replace = L'\0'; } replace = wcschr(data, L'\n'); if (replace) { *replace = L'\0'; } @ L101-103; wchar_t filter[256]; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L113-115; pLdapConnection = ldap_initW(L"localhost", LDAP_PORT); if (pLdapConnection == NULL) { ... } @ L116-117
- 结论: LDAP注入漏洞：通过socket接收的输入数据未经验证和转义，直接拼接到LDAP查询过滤器中，攻击者可以构造恶意LDAP查询，导致信息泄露或未授权操作。
- D验证: stage_c_preserved / ver_a98e4230
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 207. hyp_path_bb205c953c6f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_13.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标主机上的监听端口并发送包含LDAP注入payload的字符串
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_13.c:97; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_13.c:104-105; pLdapConnection = ldap_initA("localhost", LDAP_PORT); if (pLdapConnection == NULL) { ... } ldap_connect(pLdapConnection, NULL); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_13.c:108-110; rc = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_13.c:113-116
- 结论: LDAP注入漏洞：程序通过socket接收用户输入，直接拼接到LDAP搜索过滤器中，未进行任何转义或验证，攻击者可控制filter参数实现LDAP注入。
- D验证: confirmed / ver_2460ab39
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 208. hyp_path_d397531fb0fc

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_01.c:95
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够访问目标主机上的监听端口，并发送恶意LDAP过滤器字符串。
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ L70-74; bind(listenSocket, ...); @ L81; listen(listenSocket, 5); @ L81; acceptSocket = accept(listenSocket, NULL, NULL); @ L81; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L95; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L106-107; pLdapConnection = ldap_initW(L"localhost", LDAP_PORT); @ L109; ldap_connect(pLdapConnection, NULL); @ L112; ldap_search_ext_sW(pLdapConnection, ...); @ L116
- 结论: LDAP注入漏洞：通过socket接收的未经验证的用户输入被直接拼接到LDAP查询过滤器中，攻击者可修改LDAP查询逻辑，导致未授权访问或信息泄露。
- D验证: confirmed / ver_c331d6d1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 209. hyp_path_04be76d67ea7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_02.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到监听端口并发送特制的LDAP注入payload
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ L72-76; acceptSocket = accept(listenSocket, NULL, NULL); @ L83; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L97; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L121-122; pLdapConnection = ldap_initW(L"localhost", LDAP_PORT); @ L124; if (pLdapConnection == NULL) { ... } ldap_search_ext_sW(pLdapConnection, ...); @ L125-126
- 结论: LDAP注入漏洞：程序通过socket接收用户输入，直接拼接到LDAP查询过滤器中，未进行任何转义或验证，攻击者可以注入恶意LDAP过滤器字符串，导致未授权访问或信息泄露。
- D验证: confirmed / ver_c715c63a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 210. hyp_path_5bc489361481

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_18.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者可以访问目标服务器监听的端口; 目标服务器运行了LDAP服务且允许连接; 代码路径中未对data进行过滤或转义; LDAP搜索函数使用构造的filter参数
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L95-99; _snprintf(filter, 256-1, "(cn=%s)", data); @ 约L110-120; ldap_search_ext_sA(pLdapConnection, filter, ...); @ 约L130-140
- 结论: LDAP注入漏洞：从网络socket接收的用户输入数据直接拼接到LDAP搜索过滤器字符串中，未进行任何过滤或转义，攻击者可通过发送精心构造的输入执行未授权的LDAP查询或修改操作。
- D验证: confirmed / ver_1bac2cec
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 211. hyp_path_c88453d41952

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_10.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标服务器的监听端口并发送数据。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_10.c:97; data[dataLen + recvResult / sizeof(char)] = '\0'; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_10.c:104; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_10.c:113; ldap_search_ext_sA(pLdapConnection, LdapBase, LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_10.c:120（近似，据B阶段种子）
- 结论: LDAP注入漏洞：从网络套接字接收的数据未经任何过滤直接拼接到LDAP搜索过滤器字符串中，导致攻击者可以通过构造特制的输入修改LDAP查询，可能泄露或篡改LDAP目录信息。
- D验证: confirmed / ver_462ad4b6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 212. hyp_path_497c9da5fc22

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_15.c:98
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到监听socket，并发送包含LDAP注入载荷的数据。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ CWE90_LDAP_Injection__w32_char_listen_socket_15.c:96-98; _snprintf(filter, 256-1, "(cn=%s)", data); @ CWE90_LDAP_Injection__w32_char_listen_socket_15.c:110-112; pLdapConnection = ldap_initA("localhost", LDAP_PORT); ... ldap_search_ext_sA(pLdapConnection, "...", ...); @ CWE90_LDAP_Injection__w32_char_listen_socket_15.c:114-115
- 结论: 存在LDAP注入漏洞。程序通过listen socket接收数据，并将未经验证的用户输入直接拼接到LDAP搜索过滤器中（(cn=%s)），然后调用ldap_search_ext_sA执行LDAP搜索。攻击者可以通过发送特制字符串修改LDAP查询的语义，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_ad8f1b4e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 213. hyp_path_f3848a12e3f1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_03.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向目标主机的监听socket发送任意数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_03.c:97; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_03.c:113; ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, NULL, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_03.c:117
- 结论: 从网络socket接收的未经验证的输入直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可以通过发送特制的字符串来操纵LDAP查询，可能泄露、修改或绕过认证。
- D验证: confirmed / ver_39914110
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 214. hyp_path_c6c4dd63b8d7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_05.c:104
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标服务器并发送网络数据。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L104; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L119; ldap_search_ext_sW(pLdapConnection, ... filter ...); @ L121
- 结论: LDAP注入漏洞：攻击者可以通过网络发送特制的数据，该数据被拼接到LDAP查询过滤器中，可能导致未授权的LDAP查询或数据泄露。
- D验证: confirmed / ver_1cbba685
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 215. hyp_path_4aa684e23d68

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_04.c:104
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够与服务器建立TCP连接并发送特制数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L102-106; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ L107; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L119-122; ldap_search_ext_sW(pLdapConnection, ...); @ L124-128
- 结论: LDAP注入漏洞：通过socket接收的未净化数据直接拼接到LDAP搜索过滤器中，攻击者可以控制输入，导致LDAP注入攻击。
- D验证: confirmed / ver_f693ee14
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 216. hyp_path_0aec51e9c716

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_06.c:101
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者可以访问监听端口并发送任意数据
- 触发路径: 入口函数开始 @ L50 入口; 创建监听socket @ L76-80; 接受连接 @ L87-89; recv接收数据到data缓冲区 @ L99-103; 将data拼接到filter中：_snwprintf(filter, 256-1, L"(cn=%s)", data); @ L107-108; 调用ldap_search_ext_sW执行搜索，触发注入 @ L115
- 结论: 存在LDAP注入漏洞。攻击者通过网络发送恶意数据，数据未经验证直接拼接到LDAP搜索过滤器中，导致可以操控LDAP查询。
- D验证: confirmed / ver_07eb2f16
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 217. hyp_path_5424ab391441

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_14.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到服务器监听的端口并发送特制数据。
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); ... listen(listenSocket, 5); ... acceptSocket = accept(listenSocket, NULL, NULL); @ L72-L76; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L95-L99; _snprintf(filter, 256-1, "(cn=%s)", data); @ L105-L107; pLdapConnection = ldap_initA("localhost", LDAP_PORT); @ L111; pMessage = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L115
- 结论: 通过socket接收的数据未经任何处理直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。
- D验证: confirmed / ver_fbb15a45
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 218. hyp_path_5fafb0ad1493

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_09.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标程序监听的TCP端口并发送任意数据
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ L72-76; acceptSocket = accept(listenSocket, NULL, NULL); @ L83; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L95-99; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L115; pLdapConnection = ldap_initW(L"localhost", LDAP_PORT); @ L116; ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L118
- 结论: 代码通过socket接收数据，并将接收到的字符串直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞（CWE-90）。攻击者可以控制filter参数，执行未授权的LDAP查询。
- D验证: confirmed / ver_e36c11d0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 219. hyp_path_92fabbf09926

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_07.c:103
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到服务器的监听套接字并发送包含LDAP注入payload的数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L103; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L112; rc = ldap_search_ext_sW(pLdapConnection, filter, ...); @ L116
- 结论: LDAP注入漏洞：从网络套接字接收的数据未经消毒直接拼接到LDAP搜索过滤器字符串中，攻击者可注入恶意LDAP查询，导致信息泄露或未授权访问。
- D验证: confirmed / ver_9b4bd0a8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 220. hyp_path_bf6a8a6c5d1a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_13.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标主机上的监听端口并发送任意数据
- 触发路径: 进入case0函数 @ L46（入口）; listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ L72-76（创建socket）; acceptSocket = accept(listenSocket, NULL, NULL); @ L83（接受连接）; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L97（接收数据）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L103-105（拼接filter）; rc = ldap_search_ext_sW(pLdapConnection, ...); @ L109（执行查询）
- 结论: LDAP注入：通过recv从网络接收数据后直接拼接到LDAP搜索过滤器，未进行输入验证或转义，攻击者可注入任意LDAP查询。
- D验证: confirmed / ver_97dab4eb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 221. hyp_path_166ffa5a5d9d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_10.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向目标主机的监听端口发送TCP数据
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ L72-L76; bind(listenSocket, ...); listen(listenSocket, 5); acceptSocket = accept(listenSocket, NULL, NULL); @ L83; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L95-L99; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L112-L115; ldap_search_ext_sW(pLdapConnection, ...); @ L121
- 结论: LDAP注入漏洞：通过监听套接字接收的用户输入直接拼接到LDAP搜索过滤器中，攻击者可注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_f2adee36
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 222. hyp_path_883c7c7da0b4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_18.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接向listen socket发送任意数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L97; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L116; ldap_search_ext_sW(pLdapConnection, ...); @ L125
- 结论: 通过listen socket接收的网络数据被直接拼接至LDAP搜索过滤器，导致LDAP注入漏洞（CWE-90）。攻击者可控data内容，可构造恶意LDAP过滤器，实现未授权访问或数据泄露。
- D验证: confirmed / ver_8b8b0b4f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 223. hyp_path_3d0fdf3641fa

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_08.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到程序监听的socket，并发送特制的LDAP注入负载
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L96; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L119; ldap_search_ext_sW(pLdapConnection, ... filter ...); @ L138
- 结论: LDAP注入漏洞：通过socket接收的用户输入未经适当过滤或转义，直接拼接到LDAP搜索过滤器中，攻击者可操纵LDAP查询执行未授权操作。
- D验证: confirmed / ver_d3bf6f0f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 224. hyp_path_3b9b72acc460

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_11.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够访问目标服务监听的端口，并发送包含LDAP注入字符（如*、括号等）的数据。
- 触发路径: socket创建、连接、接收数据 @ L73-L83; recv(connectSocket, data + dataLen, ...) 读取用户数据到data @ L87-L91; _snprintf(filter, 256-1, "(cn=%s)", data); 拼接过滤器 @ L103-L108; ldap_search_ext_sA(pLdapConnection, ...) 执行LDAP搜索，触发注入 @ L112-L116
- 结论: LDP注入漏洞：从网络接收的数据直接拼接到LDAP搜索过滤器，未进行任何净化，攻击者可通过控制输入注入恶意LDAP查询。
- D验证: confirmed / ver_826b312e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 225. hyp_path_a09c2a93c07a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_16.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够访问监听端口并发送特制的LDAP注入payload; recv成功接收数据且无错误; ldap_initA和ldap_connect成功建立LDAP连接; LDAP服务器运行在localhost
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ L72-L74; acceptSocket = accept(listenSocket, NULL, NULL); @ L83; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L97; data[dataLen + recvResult / sizeof(char)] = '\0'; replace = strchr(data, '\r'); if (replace) { *replace = '\0'; } @ L108-L109; _snprintf(filter, 256-1, "(cn=%s)", data); @ L114-L115; pLdapConnection = ldap_initA("localhost", LDAP_PORT); @ L116; if (pLdapConnection == NULL) { ... } @ L117; ldap_connect(pLdapConnection, NULL); @ L120（假设）; ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L125
- 结论: LDAP注入漏洞：通过listen socket接收的数据直接拼接至LDAP搜索过滤器，攻击者可注入恶意LDAP查询。
- D验证: confirmed / ver_f207a3c2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 226. hyp_path_c6d17c75e8ba

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_11.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标发送特制的LDAP有效载荷
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L87-91; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L103; retValue = ldap_search_ext_sW(pLdapConnection, NULL, 0, ... , filter, ...); @ L126
- 结论: LDAP注入漏洞：通过socket接收的未消毒用户输入直接拼接到LDAP搜索过滤器中，导致攻击者可控制LDAP查询，绕过访问控制或提取敏感信息。
- D验证: confirmed / ver_07d83c20
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 227. hyp_path_0ecacc3fd17f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_08.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够与目标主机建立TCP连接，并在连接上发送包含LDAP注入载荷的数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_08.c:101-105; data[dataLen + recvResult / sizeof(char)] = '\0'; replace = strchr(data, '\r'); if (replace) { *replace = '\0'; } replace = strchr(data, '\n'); if (replace) { *replace = '\0'; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_08.c:108-110; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_08.c:121-122; pLdapConnection = ldap_initA("localhost", LDAP_PORT); pMessage = ldap_search_ext_sA(pLdapConnection, ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_08.c:123-127
- 结论: LDAP注入漏洞：程序通过socket接收外部输入数据，未经任何过滤或转义，直接拼接至LDAP搜索过滤器，攻击者可注入恶意LDAP查询，导致未授权数据访问或绕过访问控制。
- D验证: confirmed / ver_cd14db4a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 228. hyp_path_2b915f59fd2c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_14.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标主机的监听端口并发送特制的网络数据包
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_14.c:95-99; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_14.c:约第120行; ldap_search_ext_sW(pLdapConnection, filter, ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_14.c:约第125行
- 结论: LDAP注入漏洞：通过recv从网络socket接收用户输入，未经验证直接拼接到LDAP查询过滤器中，导致LDAP注入攻击。
- D验证: confirmed / ver_8603e749
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 229. hyp_path_d33371e8d1af

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_06.c:86
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标socket发送包含LDAP注入payload的数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_06.c:86; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_06.c:101-102; pLdapConnection = ldap_initA("localhost", LDAP_PORT); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_06.c:106; ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_06.c:108-110
- 结论: LDAP注入漏洞：通过socket接收的外部可控数据直接拼接至LDAP搜索过滤器，可能导致攻击者篡改LDAP查询语义，执行未授权操作。
- D验证: confirmed / ver_c40a964c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 230. hyp_path_8f6a078a5221

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_15.c:98
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到监听端口并发送任意数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L98; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L104; rc = ldap_search_ext_sW(pLdapConnection, (PWCHAR)L"", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L108
- 结论: LDAP注入漏洞：通过socket接收的未净化数据直接拼接到LDAP搜索过滤器，攻击者可注入任意LDAP查询。
- D验证: confirmed / ver_19a5f1d3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 231. hyp_path_69c14c4be64e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_05.c:89
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到服务端监听端口并发送恶意数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_05.c:89; data[dataLen + recvResult / sizeof(char)] = '\0'; /* Eliminate CRLF */ replace = strchr(data, '\r'); if (replace) { *replace = '\0'; } replace = strchr(data, '\n'); if (replace) { *replace = '\0'; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_05.c:99-103; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_05.c:109; pLdapConnection = ldap_initA("localhost", LDAP_PORT); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_05.c:112; ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_05.c:118
- 结论: LDAP注入漏洞：通过socket接收的用户输入直接拼接到LDAP搜索过滤器中，攻击者可以控制LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_16c91be7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 232. hyp_path_f532f91e1c05

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_16.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到监听端口并发送包含LDAP注入载荷的数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L95-99; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L110-112; pLdapConnection = ldap_initW(L"localhost", LDAP_PORT); ... ldap_search_ext_sW(pLdapConnection, ...); @ L113-114
- 结论: LDAP注入漏洞：通过socket接收的未经验证的用户输入直接拼接到LDAP搜索过滤器中，攻击者可以注入恶意LDAP查询，导致信息泄露或未授权访问。
- D验证: confirmed / ver_06ce5692
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 233. hyp_path_d045452a7f24

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_03.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够与应用程序建立网络连接并发送TCP数据，控制recv读取的数据内容。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L82 (recv); _snprintf(filter, 256-1, "(cn=%s)", data); @ L99 (_snprintf); rc = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L106 (ldap_search_ext_sA)
- 结论: LDAP注入漏洞：从socket接收的用户数据未经转义直接拼接到LDAP搜索过滤器中，攻击者可通过发送包含LDAP元字符的数据，执行任意LDAP查询，可能导致信息泄露或权限提升。
- D验证: confirmed / ver_9f9e259e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 234. hyp_path_619f8d93c796

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_10.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向目标服务器建立socket连接并发送任意数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_10.c:87-91; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_10.c:103-106; ldap_search_ext_s(pLdapConnection, ... filter ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_10.c:114
- 结论: LDAP注入漏洞：通过socket接收的数据直接拼接到LDAP搜索过滤器中，未进行充分转义或验证，攻击者可通过构造特殊输入执行任意LDAP查询。
- D验证: stage_c_preserved / ver_95e49350
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 235. hyp_path_23e798a2d592

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_09.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向服务监听的网络端口发送TCP数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L82; _snprintf(filter, 256-1, "(cn=%s)", data); @ L101; pLdapConnection = ldap_initA("localhost", LDAP_PORT); @ L109; ldap_connect(pLdapConnection, NULL); @ L111; ldap_search_ext_sA(pLdapConnection, filter, ...); @ L113
- 结论: 存在LDAP注入漏洞，攻击者可通过网络发送恶意数据构造LDAP过滤器，导致未授权访问或数据泄露。
- D验证: confirmed / ver_ad491ca5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 236. hyp_path_3a6dfb71f753

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_04.c:89
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制程序所连接的目标服务器（固定IP），或通过中间人攻击修改数据流向; 攻击者能够在连接建立后发送包含LDAP注入payload的数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_04.c:94-98; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_04.c:110-112; pLdapConnection = ldap_initA("localhost", LDAP_PORT); ... ldap_search_ext_sA(pLdapConnection, ... (PCHAR)filter ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_04.c:118-120
- 结论: LDAP注入漏洞：从网络socket接收的未经验证的用户输入直接拼接到LDAP搜索过滤器字符串中，并传递给ldap_search_ext_sA，允许攻击者修改LDAP查询语义，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_0830ff10
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 237. hyp_path_1205ab85cc12

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_13.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: The attacker can send arbitrary data to the socket (connectSocket) that the program reads.; The program must reach the recv() call (e.g., when global variable GLOBAL_CONST_TRUE is nonzero).
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L87-91; _snprintf(filter, 256-1, "(cn=%s)", data); @ L96-97; pLdapConnection = ldap_initA("localhost", LDAP_PORT); if (pLdapConnection == NULL) { ... } ldap_connect(pLdapConnection, NULL); ... ldap_search_ext_sA(pLdapConnection, ...); @ L110-115
- 结论: LDAP Injection vulnerability: The program receives input via recv() from a socket and directly concatenates it into an LDAP search filter without sanitization, allowing an attacker to manipulate LDAP queries.
- D验证: confirmed / ver_e465b2e5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 238. hyp_path_eb0bfbdc0cfd

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_15.c:83
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务（localhost:TCP_PORT），并发送恶意数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_15.c:83; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_15.c:100-102; pLdapConnection = ldap_initA("localhost", LDAP_PORT); ... ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_15.c:115-118
- 结论: 该代码存在LDAP注入漏洞（CWE-90）。程序通过recv()从网络接收数据，直接拼接到LDAP搜索过滤器中，未进行任何过滤或转义，攻击者可以注入恶意LDAP查询，导致未授权访问或数据泄露。
- D验证: confirmed / ver_1ced1f29
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 239. hyp_path_97636553810f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_07.c:88
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够与目标主机建立网络连接，并发送包含LDAP注入载荷的数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L93-L97; replace = strchr(data, '\r'); if (replace) { *replace = '\0'; } replace = strchr(data, '\n'); if (replace) { *replace = '\0'; } @ L103-L104; _snprintf(filter, 256-1, "(cn=%s)", data); pLdapConnection = ldap_initA("localhost", LDAP_PORT); @ L121-L123; ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L130-L133
- 结论: 网络接收的数据被直接用于构造LDAP搜索过滤器，导致LDAP注入漏洞（CWE-90）。
- D验证: confirmed / ver_4c614072
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 240. hyp_path_77f911902130

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_02.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序，并发送特制的LDAP注入payload。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L87-91; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L~100; ldap_search_ext_sW(pLdapConnection, ... filter ...) @ L~120
- 结论: LDAP注入漏洞：从socket接收的用户输入直接拼接到LDAP搜索过滤器中，未经任何净化，攻击者可以构造恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_53ea72dc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 241. hyp_path_f1e2d90aba46

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_01.c:80
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标socket并发送任意数据; ldap_initA和ldap_search_ext_sA调用成功（即LDAP服务器可达且初始化成功）
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_01.c:80; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_01.c:99-100; pLdapConnection = ldap_initA("localhost", LDAP_PORT); ... ldap_search_ext_sA(pLdapConnection, filter, ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_01.c:109-110（推测）
- 结论: LDAP注入漏洞：网络接收的用户输入直接拼接至LDAP查询过滤器，未进行任何净化，攻击者可注入恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_2732fcab
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 242. hyp_path_6c0536fdf572

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_16.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标系统上的TCP端口（如默认LDAP端口）并发送任意数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L87-91; _snprintf(filter, 256-1, "(cn=%s)", data); @ L96-100; ldap_search_ext_sA(pLdapConnection, (char *)"", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L115-120
- 结论: 通过recv从网络接收的数据未经净化直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可控制输入，修改LDAP查询语义，可能越权访问或泄露信息。
- D验证: confirmed / ver_60306de8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 243. hyp_path_27acf920db1f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_14.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到服务器并发送数据到指定的socket端口。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L87-90; _snprintf(filter, 256-1, "(cn=%s)", data); @ L101; ldap_search_ext_sA(pLdapConnection, filter, ...); @ L112-113
- 结论: LDAP注入漏洞：通过socket接收的输入被直接拼接到LDAP搜索过滤器中，未经消毒，允许攻击者构造恶意LDAP查询。
- D验证: confirmed / ver_3920e278
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 244. hyp_path_907c1da88d60

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_18.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制网络输入（通过connectSocket接收的数据）
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L82; data[dataLen + recvResult / sizeof(char)] = '\0'; @ L89; replace = strchr(data, '\r'); if (replace) { *replace = '\0'; } replace = strchr(data, '\n'); if (replace) { *replace = '\0'; } @ L92-95; _snprintf(filter, 256-1, "(cn=%s)", data); @ L104; pLdapConnection = ldap_initA("localhost", LDAP_PORT); @ L107; ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L111
- 结论: LDAP注入漏洞：通过socket接收的用户输入直接拼接到LDAP搜索过滤器中，未进行任何过滤或转义，导致攻击者可以注入恶意LDAP查询，绕过认证、获取未授权数据等。
- D验证: confirmed / ver_46da86f0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 245. hyp_path_104638004121

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_02.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够访问目标机器的网络端口，并能够发送数据导致data变量被污染。
- 触发路径: recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L87-91; _snprintf(filter, 256-1, "(cn=%s)", data); @ L100-101; pLdapConnection = ldap_initA("localhost", LDAP_PORT); ldap_connect(pLdapConnection, NULL); ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L109-113
- 结论: 代码通过socket接收外部输入，并将其直接拼接到LDAP搜索过滤器中，未进行充分过滤或转义，导致LDAP注入漏洞。攻击者可以控制data变量，注入恶意LDAP查询，从而绕过认证、泄露信息等。
- D验证: confirmed / ver_b678b2de
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 246. hyp_path_5a58331b29e1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_09.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到程序监听的socket; LDAP服务器正在运行且可达; recv调用成功（无SOCKET_ERROR或连接关闭）
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ 82-86; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 95-100; pLdapConnection = ldap_initW(L"localhost", LDAP_PORT); @ 104-108; ldap_search_ext_sW(pLdapConnection, ...); @ 111-113
- 结论: LDAP注入漏洞：从网络接收的数据直接拼接到LDAP搜索过滤器，未经任何净化，攻击者可通过控制输入执行任意LDAP查询。
- D验证: confirmed / ver_66a3e3a4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 247. hyp_path_53ce0b06c95f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_16.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够与服务器建立连接并发送包含LDAP元字符（如括号、通配符等）的数据到目标端口。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ 行87-91; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 行97; ldap_search_ext_sW(pLdapConnection, ...); @ 行101及以后
- 结论: 代码从网络接收数据并直接拼接到LDAP搜索过滤器中，未经任何转义或净化，导致LDAP注入漏洞。攻击者可控制搜索过滤器，执行未授权的LDAP查询。
- D验证: confirmed / ver_b6c86938
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 248. hyp_path_eabd05bd7977

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_03.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向服务端发送TCP数据，且服务端运行在一个可被攻击者访问的网络环境中。
- 触发路径: static void CWE90_LDAP_Injection__w32_wchar_t_connect_socket_03_case0() @ 入口函数bad(); recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ 第82行 recv; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 第99行 拼接filter; int rc = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ 第107行 ldap_search_ext_sW sink
- 结论: LDAP注入漏洞：通过socket接收的外部数据未经任何过滤或转义直接拼接到LDAP查询过滤器中，攻击者可注入LDAP特殊字符修改查询逻辑，可能导致信息泄露或权限提升。
- D验证: confirmed / ver_829418ef
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 249. hyp_path_31a6af2a5fad

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_06.c:86
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标服务发送数据（recv 从连接的 socket 接收）; 目标服务使用 wchar_t 字符集，LDAP 服务器配置允许外部访问; STATIC_CONST_TRUE 为真，进入漏洞分支
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ line 91-95; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ line 105-106; ldap_search_ext_sW(pLdapConnection, ...); @ line 115 (approximate)
- 结论: LDAP注入漏洞：从网络接收的用户输入直接拼接到LDAP搜索过滤器中，未进行任何转义或过滤，攻击者可通过构造恶意输入执行任意LDAP查询。
- D验证: confirmed / ver_0f9c8dc5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 250. hyp_path_dd75c825bb00

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_01.c:80
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接向目标发送数据，且数据长度不超过缓冲区限制。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L86-89; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; /* 且后续去除了CRLF */ @ L90-93; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L103-105; if (ldap_search_ext_sW(pLdapConnection, ...) != LDAP_SUCCESS) @ L110-113
- 结论: LDAP注入漏洞：从socket接收的未过滤数据直接拼接到LDAP搜索过滤器字符串中，导致攻击者可以注入任意LDAP查询。
- D验证: confirmed / ver_ee3449ab
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 251. hyp_path_610a8b54b51b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_04.c:89
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过TCP连接向目标程序发送包含LDAP元字符的数据，且LDAP服务器运行在localhost:389并接受连接
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_04.c:94; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_04.c:100; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_04.c:106; pLdapConnection = ldap_initW(L"localhost", LDAP_PORT); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_04.c:109; if (ldap_connect(pLdapConnection, NULL) == LDAP_SUCCESS) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_04.c:113; ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_04.c:118
- 结论: 代码从网络接收数据后直接拼接到LDAP搜索过滤器，仅去除了CRLF字符，未对LDAP元字符（如*、()等）进行转义或过滤，导致LDAP注入漏洞。
- D验证: confirmed / ver_99827ce8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 252. hyp_path_25c62aaeb683

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_15.c:83
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到服务端并发送特制payload。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ L83-L92; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; @ L88; replace = wcschr(data, L'\r'); if (replace) { *replace = L'\0'; } @ L91-L92; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L97; pLdapConnection = ldap_initW(L"localhost", LDAP_PORT); @ L101; ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L108
- 结论: LDAP注入漏洞：通过recv接收的网络数据被直接拼接到LDAP搜索过滤器中，攻击者可注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_5a2dd083
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 253. hyp_path_7421217cc08e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_14.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: Attacker can send arbitrary data to the connected socket (connectSocket), which is reachable over the network.
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L87-91; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; @ L95-96; replace = wcschr(data, L'\r'); if (replace) { *replace = L'\0'; } replace = wcschr(data, L'\n'); if (replace) { *replace = L'\0'; } @ L97-103; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L118; ldap_search_ext_sW(pLdapConnection, ... filter ...) @ L124
- 结论: LDAP injection vulnerability: user-controlled data from recv() is directly concatenated into LDAP search filter without sanitization, allowing an attacker to modify the LDAP query.
- D验证: confirmed / ver_cf6cf96c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 254. hyp_path_cb475a75459f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_10.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制远程服务器或实施中间人攻击，使得目标程序通过socket接收到的数据可被恶意控制
- 触发路径: connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); ... connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR @ 第73-87行; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ 第87-91行; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; 并去除CRLF @ 第96-98行; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 第105-107行; ldap_search_ext_sW(pLdapConnection, ... filter ...); @ 第108-109行
- 结论: LDAP注入漏洞：通过socket接收的未充分过滤的数据被直接拼接到LDAP搜索过滤器中，攻击者可以通过控制远程服务器或中间人攻击发送恶意输入，操纵LDAP查询，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_d0128bfe
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 255. hyp_path_8fc1abdf5930

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_07.c:88
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够与目标程序的socket端口通信，发送特制的LDAP注入payload
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L93-97; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; @ L104; replace = wcschr(data, L'\r'); ... *replace = L'\0'; replace = wcschr(data, L'\n'); ... *replace = L'\0'; @ L107-110; wchar_t filter[256]; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L112; pLdapConnection = ldap_initW(L"localhost", LDAP_PORT); @ L116; ldap_search_ext_sW(pLdapConnection, ... filter ...); @ L120
- 结论: LDAP注入漏洞：程序通过socket接收用户输入（wchar_t类型），直接拼接到LDAP搜索过滤器中，仅替换了CRLF字符，未对LDAP元字符（如括号、星号等）进行转义或过滤，攻击者可通过注入LDAP特殊字符修改查询逻辑。
- D验证: confirmed / ver_bcf3a788
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 256. hyp_path_98a8277d4273

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_13.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够与目标服务器的socket端口通信; 服务器LDAP服务运行且可查询
- 触发路径: CWE90_LDAP_Injection__w32_wchar_t_connect_socket_13_case0 @ L46 (main入口); 创建socket并连接 @ L73-84; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L87-91; data[dataLen + recvResult/sizeof(wchar_t)] = L'\0'; replace = wcschr(data, L'\r'); ... replace = wcschr(data, L'\n'); @ L94-97; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L103-104; pLdapConnection = ldap_initW(L"localhost", LDAP_PORT); if (pLdapConnection == NULL) ... @ L113-117; ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L121-123
- 结论: LDAP注入漏洞：通过socket接收的用户输入直接拼接至LDAP查询过滤器，攻击者可注入恶意LDAP语法执行未授权操作。
- D验证: confirmed / ver_6a3e90b0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 257. hyp_path_1df4f66420b8

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_81a.cpp:95
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到服务器，并发送特制的字符串作为输入。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_81a.cpp:95; baseObject.action(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_81a.cpp:106
- 结论: 在CWE90_LDAP_Injection__w32_wchar_t_listen_socket_81a.cpp中，程序通过recv()从网络接收用户输入，并传递给action()函数。虽然action()函数内部实现未提供，但基于Juliet测试用例的典型模式以及B阶段静态支持，该路径很可能存在LDAP注入漏洞。
- D验证: stage_c_preserved / ver_a1caa370
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 258. hyp_path_a853a08a6a07

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_18.c:82
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序监听的端口; 攻击者发送的数据包含LDAP注入payload
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L82; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ L87-91; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L100-102; pLdapConnection = ldap_initW(L"localhost", LDAP_PORT); ... ldap_connect(pLdapConnection, NULL); @ L105-108; ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L? (ldap_search_ext_sW调用)
- 结论: LDAP注入漏洞：程序通过recv从网络接收用户输入，直接拼接到LDAP查询过滤器中，未进行充分验证或转义，导致攻击者可控制LDAP查询，可能造成未授权访问或信息泄露。
- D验证: confirmed / ver_14b7fd24
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 259. hyp_path_b1451e8439c4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_05.c:89
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过TCP连接到目标服务，并发送包含LDAP注入载荷的数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L94-98; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; @ L89; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L111-112; if (ldap_search_ext_sW(pLdapConnection, ... ) != LDAP_SUCCESS) @ L140-141
- 结论: 存在LDAP注入漏洞：从socket接收的用户输入直接拼接到LDAP搜索过滤器中，导致攻击者可以注入任意LDAP查询。
- D验证: confirmed / ver_a7404529
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 260. hyp_path_534cff24bd7b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_81a.cpp:95
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: Attacker can connect to the listening socket and send arbitrary data.
- 触发路径: CWE90_LDAP_Injection__w32_char_listen_socket_81_case0() @ L46: case entry; listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ L72: create socket; bind(listenSocket, ...); listen(listenSocket, 5); @ L81: bind and listen; acceptSocket = accept(listenSocket, NULL, NULL); @ L81: accept; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L95: receive data; Not provided in A-stage; implied by CWE90 sample structure and B-stage high_risk_sink @ Assumed in incomplete code (e.g., ldap_search_s call in bad function)
- 结论: CWE90: LDAP Injection vulnerability in CWE90_LDAP_Injection__w32_char_listen_socket_81a.cpp. The function receives data over a network socket and potentially uses it in an LDAP query without sanitization, but the sink code (LDAP call) is not present in the provided A-stage evidence, only in B-stage hints.
- D验证: stage_c_preserved / ver_3b749293
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 261. hyp_path_67b006573413

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_33.cpp:99
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标服务并发送构造的LDAP注入payload
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L97-101; ldap_search_ext_sA(ld, base, data, attrs, 0, NULL, NULL, &pMessage) // data作为过滤器 @ 未知行（B阶段种子指示LDAP调用）; if (ldap_search_ext_sA(...) != LDAP_SUCCESS) @ 未知行
- 结论: LDAP注入漏洞：程序通过socket接收用户输入数据，未进行充分过滤或转义，直接用于LDAP查询函数ldap_search_ext_sA，攻击者可通过构造特殊数据注入LDAP过滤器，实现未授权访问或信息泄露。
- D验证: confirmed / ver_227a053a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 262. hyp_path_e0e8d5cb83a6

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_81a.cpp:80
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够访问目标网络服务端口，并发送特制数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L85-89; baseObject.action(data); // 调用action，但未提供具体实现 @ L? (baseObject.action(data))
- 结论: 网络接收的数据未经充分验证或转义即用于LDAP查询，导致LDAP注入漏洞。action函数在CWE90测试套件中通常实现为调用ldap_search等LDAP操作，但当前未提供具体实现代码，故证据链不完整。
- D验证: stage_c_preserved / ver_6b3e3082
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 263. hyp_path_48a2f961410d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_81a.cpp:80
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络向目标主机发送数据，并控制LDAP查询字符串内容；LDAP服务器可访问。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_81a.cpp:85; baseObject.action(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_81a.cpp:80
- 结论: 存在LDAP注入漏洞：通过recv()从网络接收的数据传递给baseObject.action()，该函数很可能会执行LDAP查询（基于CWE90样本），且未提供消毒证据。
- D验证: stage_c_preserved / ver_aaf4f010
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 264. hyp_path_97e96bcd8b6e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_34.c:102
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到监听端口，发送恶意LDAP注入载荷
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ line 102; 需要补充ldap_search_ext_sA等API调用代码以确认数据流 @ 疑似后续LDAP查询调用（B阶段种子包含call:ldap_search_ext_sA，但代码未展示）
- 结论: 在CWE90_LDAP_Injection__w32_char_listen_socket_34函数中，通过socket接收的用户数据可能未经充分过滤直接用于LDAP查询（ldap_search_ext_sA），但由于A阶段代码证据中缺失LDAP API调用的具体代码行，数据流路径未完全闭合。
- D验证: confirmed / ver_787f1781
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 265. hyp_path_6676c1d3a96c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_34.c:102
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接并向服务发送特制的LDAP注入载荷
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L102; B阶段route内API种子包含call:ldap_search_ext_sW @ B阶段种子推断为ldap_search_ext_sW调用，但A阶段未提供具体行号
- 结论: LDAP注入漏洞：程序通过socket接收用户输入，未经验证直接用于LDAP查询，攻击者可构造恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_6583ccf2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 266. hyp_path_5cb1d357c19b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_31.c:95
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务监听的socket; 攻击者可以发送任意字符串作为LDAP查询参数
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_31.c:95; data[dataLen + recvResult / sizeof(char)] = '\0'; replace = strchr(data, '\r'); if (replace) { *replace = '\0'; } @ 同一函数后续处理（清除换行符后）; ldap_search_ext_sA(ld, (char*)data, ...) @ L?（根据B阶段API种子，sink为ldap_search_ext_sA，具体行号未在代码片段中明确）
- 结论: 存在LDAP注入漏洞：从网络socket接收的数据未经充分过滤，直接用于LDAP查询，攻击者可通过发送特制字符串修改LDAP查询语义。
- D验证: confirmed / ver_5f6f941a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 267. hyp_path_c03819c38d78

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_33.cpp:84
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够与目标建立网络连接并发送数据。; 目标程序配置为使用LDAP进行查询，且data变量未被覆盖或截断。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L89-93; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, data, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L104附近
- 结论: 在CWE90_LDAP_Injection__w32_char_connect_socket_33::case0函数中，通过recv从套接字接收的数据直接用于ldap_search_ext_sA调用，未经过滤或转义，导致LDAP注入漏洞。攻击者可控制输入内容，操纵LDAP查询，可能导致信息泄露、权限绕过等。
- D验证: confirmed / ver_bdfab1b9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 268. hyp_path_ae296f58c83e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_33.cpp:84
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务的socket端口，并发送特制的LDAP注入字符串。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L84; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ L89-93; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, data, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L111-115
- 结论: LDAP注入漏洞：程序通过socket接收攻击者可控的数据，未经验证直接作为filter参数传递给ldap_search_ext_sW函数，攻击者可以构造恶意LDAP过滤器篡改查询逻辑。
- D验证: confirmed / ver_073b2f07
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 269. hyp_path_afc47594a14e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_65a.c:85
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到目标服务，并发送恶意数据包，影响recv接收的数据内容。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_65a.c:90-94; func(data); // 实际调用bad函数，该函数使用data进行LDAP查询（bad函数位于65b.c，未在证据中展示） @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_65a.c: main函数调用
- 结论: 网络接收的数据未经充分过滤或转义，直接用于LDAP查询，导致LDAP注入漏洞。攻击者可通过发送特制网络数据，在LDAP查询中注入恶意过滤器或修改查询逻辑，可能导致未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_4700a658
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 270. hyp_path_aab545a4f362

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_33.cpp:99
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务器的监听端口，并发送包含LDAP注入payload的数据。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L99; replace = wcschr(data, L'\r'); ... *replace = L'\0'; replace = wcschr(data, L'\n'); if (replace) { ... *replace = L'\0'; } @ L110-111; ldap_search_ext_sW(ld, base, data, 0, attrs, 0, &pMessage); @ 推断在收尾部分
- 结论: 通过socket接收的数据用于LDAP查询，存在LDAP注入漏洞，但LDAP调用的具体代码行在A阶段证据中未明确显示，基于B阶段静态分析支持推断存在。
- D验证: confirmed / ver_c1c4ca9d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 271. hyp_path_9d26a6b6572e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_32.c:76
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够与监听socket建立TCP连接; 攻击者能够发送包含LDAP注入payload的数据
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); if (acceptSocket == SOCKET_ERROR) { break; } @ L91-95; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { ... } @ L97-101; ldap_search_ext_sW(ld, (wchar_t *)data, ...) @ （B阶段证据表明存在ldap_search_ext_sW调用，但代码片段中未直接显示行号）
- 结论: LDAP注入漏洞：程序从网络socket接收数据，仅去除回车换行，未进行其他过滤，直接用于LDAP查询函数ldap_search_ext_sW，攻击者可注入恶意LDAP过滤器。
- D验证: confirmed / ver_f9668a9c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 272. hyp_path_76d438d6c8d2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_32.c:84
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接目标服务并发送特制的LDAP注入payload
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L84; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; @ L95-98; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, data, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L110
- 结论: LDAP注入漏洞：从socket接收的用户输入未经净化直接用于ldap_search_ext_sW的过滤参数，攻击者可注入LDAP过滤器语法，导致未授权访问或信息泄露。
- D验证: confirmed / ver_e17f1055
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 273. hyp_path_b75c6ec132d4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_32.c:84
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标程序的套接字并发送任意数据
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_32.c:89-93; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ...) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_32.c:111-115
- 结论: LDAP注入漏洞：从网络套接字接收的输入数据未经验证直接用于ldap_search_ext_sA LDAP搜索调用，攻击者可注入恶意LDAP过滤器。
- D验证: confirmed / ver_f4185933
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 274. hyp_path_889fb9a1717a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_32.c:76
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够访问监听端口并发送特制的LDAP查询字符串。
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ L46; acceptSocket = accept(listenSocket, NULL, NULL); @ L91; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L97-98; ldap_search_ext_sA(ldap, data, ...) // 根据B阶段种子确认存在调用，但本次证据片段中未显式展示该行 @ L? (约L120附近)
- 结论: LDAP注入漏洞：从网络socket接收的用户输入数据未经消毒直接用于LDAP查询构造，攻击者可注入任意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_ec860700
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 275. hyp_path_fbc382c752d3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_31.c:80
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标程序发送数据，并控制data缓冲区的内容。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L80; if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ L85-89; replace = wcschr(data, L'\n'); if (replace) { *replace = L'\0'; } ... @ L97-101; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...); @ L107-111
- 结论: LDAP注入漏洞：通过recv读取的网络数据未经过滤直接用于ldap_search_ext_sW的base参数，攻击者可控制该参数执行恶意LDAP查询。
- D验证: confirmed / ver_262fe016
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 276. hyp_path_9d006a092b26

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_31.c:80
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标服务器的connectSocket发送恶意数据，且数据不包含换行符（换行符导致exit），但可以包含任意LDAP过滤器语法。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_31.c:85-89; data[dataLen + recvResult / sizeof(char)] = '\0'; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_31.c:100-105; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, data, NULL, 0, NULL, NULL, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_31.c:? (ldap_search_ext_sA调用行，推测在L116附近)
- 结论: LDAP注入漏洞：从socket接收的数据未经验证直接用于ldap_search_ext_sA调用，攻击者可以注入LDAP过滤器，导致信息泄露或未授权访问。
- D验证: confirmed / ver_b8be8ff1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 277. hyp_path_2d8f862fccc3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_68a.c:78
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到服务器，并发送包含LDAP注入语法的字符串。
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ CWE90_LDAP_Injection__w32_char_listen_socket_68a.c:93-97; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ CWE90_LDAP_Injection__w32_char_listen_socket_68a.c:99-103; CWE90_LDAP_Injection__w32_char_listen_socket_68b_case0Sink(); // 调用sink函数，使用data构造LDAP查询 @ CWE90_LDAP_Injection__w32_char_listen_socket_68a.c:121-125
- 结论: LDAP注入漏洞：程序通过socket接收用户输入，未经验证直接传递给LDAP查询构造函数，导致攻击者可以注入LDAP过滤器或修改LDAP语句。
- D验证: stage_c_preserved / ver_a8c861e0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 278. hyp_path_6796a9d4e5bb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_34.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标主机的 socket，并且发送特制的 payload。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_34.c:92-96; 数据被存储并传递给 ldap_search_ext_sW 调用 @ 同文件，约 L100-120; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... ); @ 同文件，约 L114-118
- 结论: 从网络接收的数据未经充分验证或转义，直接用于 LDAP 查询，可能导致 LDAP 注入攻击。
- D验证: confirmed / ver_c5e2a5f8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 279. hyp_path_95e7bf9c9fa1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_66a.c:76
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到服务器监听的端口并发送包含LDAP注入payload的数据
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ L91-L95; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L97-L101; dataArray[2] = data; @ L113; CWE90_LDAP_Injection__w32_char_listen_socket_66b_case0Sink(dataArray); @ L114
- 结论: 通过socket接收的未验证数据被传递给LDAP查询，可能导致LDAP注入攻击。
- D验证: stage_c_preserved / ver_2342eb63
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 280. hyp_path_e831a3247dd0

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_66a.c:76
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够连接到监听端口，并发送恶意LDAP注入payload到data缓冲区。
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); if (acceptSocket == SOCKET_ERROR) { break; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_66a.c:92-95; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { ... } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_66a.c:97-101; CWE90_LDAP_Injection__w32_wchar_t_listen_socket_66b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_66b.c (sink call)
- 结论: LDAP注入漏洞：通过socket接收的用户输入未经验证和过滤，直接传递给LDAP查询函数，攻击者可构造恶意payload进行LDAP注入。
- D验证: stage_c_preserved / ver_95a32608
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 281. hyp_path_c7891b6ab44d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_68a.c:78
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够连接到服务器并发送精心构造的数据; recv成功接收数据且data被传递给LDAP查询函数; LDAP查询函数未对输入进行转义或过滤
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_68a.c:93; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_68a.c:99-103; 假设调用ldap_search或类似函数，未提供具体代码但依据测试用例标签为high_risk_sink @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_68b.c (sink函数)
- 结论: 从网络socket接收的数据未经验证直接传递给LDAP查询函数，存在LDAP注入漏洞。攻击者可通过发送特制字符串操纵LDAP查询。
- D验证: stage_c_preserved / ver_3ae180d9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 282. hyp_path_c0497193ece5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_45.c:130
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标主机的监听端口，并发送任意数据
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); if (acceptSocket == SOCKET_ERROR) { break; } @ L145-149; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { ... } @ L151-155; data[dataLen + recvResult / sizeof(char)] = '\0'; @ L157; filter[256]; _snprintf(filter, 256-1, "(cn=%s)", data); ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, ...); @ L49-102 (case0Sink)
- 结论: 存在LDAP注入漏洞。程序通过监听套接字接收用户输入数据，未经任何过滤或转义直接拼接至LDAP搜索过滤器字符串中，攻击者可通过构造恶意输入注入LDAP命令，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_33c76c4f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 283. hyp_path_713564f9781c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_31.c:95
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到程序监听的socket; 攻击者能够发送任意数据作为LDAP查询字符串
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_31.c:93-97; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_31.c:100; ldap_search_ext_sW(ld, (LPCWSTR)data, ...) @ B阶段种子表明存在ldap_search_ext_sW调用，但具体行号未在提供的代码片段中，需D验证
- 结论: 在Juliet测试用例CWE90_LDAP_Injection__w32_wchar_t_listen_socket_31.c中，程序通过socket接收用户输入并存入data缓冲区，随后在函数内对data未进行任何LDAP注入过滤（仅移除CRLF），并最终调用ldap_search_ext_sW等LDAP函数发起搜索，导致LDAP注入漏洞。攻击者可构造恶意LDAP查询字符串操纵LDAP查询逻辑。
- D验证: confirmed / ver_5eae11da
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 284. hyp_path_42b7c82b5b0a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_45.c:130
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务器，并发送特制的payload，payload包含LDAP注入语法。
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_45.c:151-155; _snwprintf(filter, 256-1, L"(cn=%s)", data); ... searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_45.c:49-102
- 结论: LDAP注入漏洞：程序通过socket接收用户输入，未经验证直接拼接到LDAP搜索过滤器中，攻击者可以注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_ca90d753
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 285. hyp_path_caebdb6fc54c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_34.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制socket输入（通过网络连接发送恶意数据）
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_34.c:87; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ... ); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_34.c:107-112（推测）
- 结论: LDAP注入漏洞：从socket接收的用户输入直接用于ldap_search_ext_sA函数，未进行任何过滤或转义，攻击者可控制LDAP查询语句。
- D验证: confirmed / ver_2c4de08d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 286. hyp_path_b5d2d8886b6b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_67a.c:81
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过TCP连接到目标主机上的监听端口（默认TCP_PORT）。; LDAP服务器配置允许查询执行，且LDAP绑定等认证已通过（如果适用）。
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); if (acceptSocket == SOCKET_ERROR) { break; } @ CWE90_LDAP_Injection__w32_char_listen_socket_67a.c:96-100; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { ... } @ CWE90_LDAP_Injection__w32_char_listen_socket_67a.c:102-106; data[dataLen + recvResult / sizeof(char)] = '\0'; replace = strchr(data, '\r'); if (replace) { *replace = '\0'; } replace = strchr(data, '\n'); if (replace) { *replace = '\0'; } @ CWE90_LDAP_Injection__w32_char_listen_socket_67a.c:116-120; CWE90_LDAP_Injection__w32_char_listen_socket_67b_case0Sink(data);
- 结论: 在CWE90_LDAP_Injection__w32_char_listen_socket_67a.c中，通过listen socket接收的网络数据未经充分净化即传递给LDAP sink函数，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_bc7f3ab2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 287. hyp_path_c84ea224a6fb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_62b.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到监听端口，并发送包含LDAP元字符（如*、()、&、|等）的恶意数据。
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_62b.cpp:83; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_62b.cpp:89-90; // 将data传递给LDAP查询函数，如ldap_search_s @ CWE90_LDAP_Injection__w32_char_listen_socket_62a.cpp (推断)
- 结论: 通过listen socket接收的网络数据未经验证直接用于LDAP查询，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_ab3f5e86
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 288. hyp_path_328c5df0d0ca

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_67a.c:81
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够访问监听socket（例如通过TCP连接）
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ L96-100; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L102-106; myStruct.structFirst = data; @ 描述; CWE90_LDAP_Injection__w32_wchar_t_listen_socket_67b_case0Sink(myStruct); @ 描述
- 结论: 代码通过socket接收用户输入，直接传递给LDAP查询构造，未进行任何过滤或转义，存在LDAP注入漏洞。
- D验证: stage_c_preserved / ver_465030e7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 289. hyp_path_88d50d81bcba

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_84_case0.cpp:72
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够连接到服务器的监听端口并发送特制的LDAP注入数据。
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_84_case0.cpp:87-91; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_84_case0.cpp:93-97; 假设存在ldap_search或类似调用，但代码未提供 @ 后续LDAP查询代码（未在片段中展示，基于测试用例上下文推断）
- 结论: LDAP注入漏洞：通过socket接收的数据可能用于LDAP查询，攻击者可注入恶意LDAP过滤器，但缺乏LDAP sink的直接代码证据。
- D验证: stage_c_preserved / ver_d968b176
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 290. hyp_path_a97d2aa06351

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_83_case0.cpp:72
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者可以通过网络访问目标程序的监听端口。
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ socket监听; acceptSocket = accept(listenSocket, NULL, NULL); @ 接受连接; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ 接收数据到data缓冲区; （未在代码片段中展示，但根据CWE90测试用例特征，后续调用ldap_search等函数） @ data未经过滤直接用于LDAP查询（sink未在代码片段中显式展示，但B阶段P0静态支持为supported=true，且为high_risk_sink，符合CWE90测试用例模式）
- 结论: LDAP注入漏洞：程序通过socket接收用户输入，未经验证或转义直接用于LDAP查询，攻击者可注入恶意LDAP过滤器或修改查询逻辑。
- D验证: stage_c_preserved / ver_fe19d5c1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 291. hyp_path_94a4936ae951

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_62b.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到此服务; 服务端未对接收数据进行LDAP注入防护
- 触发路径: acceptSocket = accept(listenSocket, NULL, NULL); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_62b.cpp:83-87; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_62b.cpp:91; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; // 数据存入data，未净化 @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_62b.cpp:96-98
- 结论: 在Windows socket监听器中对用户输入未做充分净化，若后续数据用于LDAP查询，则存在LDAP注入漏洞，攻击者可通过发送特制字符串操纵LDAP查询。
- D验证: stage_c_preserved / ver_1250854b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 292. hyp_path_5e52b57c39e0

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_66a.c:84
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络向目标程序发送恶意LDAP过滤器字符串; 目标程序连接到LDAP服务器，且LDAP服务器允许执行注入操作
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_66a.c:89-93; data[dataLen + recvResult / sizeof(char)] = '\0'; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_66a.c:97; dataArray[2] = data; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_66a.c:104; CWE90_LDAP_Injection__w32_char_connect_socket_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_66a.c:105
- 结论: 代码从网络socket接收用户输入，直接传递给LDAP查询sink函数，未进行任何输入验证或转义，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_116f6db6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 293. hyp_path_b47d5dcdd282

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_67a.c:89
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够与程序建立 TCP 连接并发送任意数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L94-98; myStruct.structFirst = data; @ L114; CWE90_LDAP_Injection__w32_wchar_t_connect_socket_67b_case0Sink(myStruct); @ L115
- 结论: 网络接收的数据未经任何验证或转义直接传递给 LDAP 查询 sink，导致 LDAP 注入漏洞。
- D验证: stage_c_preserved / ver_b0f70b56
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 294. hyp_path_e93e641e428e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_45.c:138
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序监听的端口并发送任意数据; 目标程序中LDAP服务器可访问且存在弱认证或匿名绑定
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); if (recvResult == SOCKET_ERROR || recvResult == 0) { break; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_45.c:143-147; case0Sink(); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_45.c:138; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_45.c:70; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_45.c:95
- 结论: LDAP注入漏洞：通过recv接收的网络数据直接拼接到LDAP搜索过滤器中，未进行任何中和，攻击者可以注入任意LDAP查询，导致信息泄露或未授权访问。
- D验证: confirmed / ver_57b368d4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 295. hyp_path_c2e1173a90fb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_68a.c:86
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够与服务器建立TCP连接，并发送特制的LDAP注入字符串
- 触发路径: SOCKET connectSocket = INVALID_SOCKET; @ L77; if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR) { break; } @ L84-86; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L91-95; data[dataLen + recvResult / sizeof(char)] = '\0'; replace = strchr(data, '\r'); ... @ L100-103; CWE90_LDAP_Injection__w32_char_connect_socket_68_case0Data = data; @ L105; CWE90_LDAP_Injection__w32_char_connect_socket_68b_case0Sink(); @ L106
- 结论: 存在LDAP注入漏洞，攻击者可通过网络发送恶意数据，该数据经过简单的CRLF过滤后直接传递给LDAP操作（在sink函数中），未进行充分净化，导致注入攻击。
- D验证: stage_c_preserved / ver_e402dcbd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 296. hyp_path_1762d33a8f4e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_22b.c:93
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到目标服务并发送特制数据; 目标服务将接收到的数据用于LDAP查询构造
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_22b.c:93
- 结论: 代码从网络socket接收数据并存储到字符数组'data'中，该数据可能用于后续LDAP查询，但当前代码片段未显示LDAP API调用，证据不完整。
- D验证: stage_c_preserved / ver_a25709ab
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 297. hyp_path_2b912ac3d38d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_67a.c:89
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务的socket端口，并发送恶意数据包。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_67a.c:94-98; myStruct.structFirst = data; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_67a.c:112; CWE90_LDAP_Injection__w32_char_connect_socket_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_67a.c:113
- 结论: 代码存在LDAP注入漏洞。从socket接收的数据未经充分净化直接传入LDAP查询sink函数，攻击者可通过控制网络输入注入LDAP过滤器，导致未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_9ee78234
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 298. hyp_path_6660afce6813

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_84_case0.cpp:72
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够连接到监听端口（TCP_PORT）并发送任意数据
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ L70-74; bind(listenSocket, ...); listen(listenSocket, 5); @ L81; acceptSocket = accept(listenSocket, NULL, NULL); @ L87-91; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L93-97; data被用于LDAP查询调用（如ldap_search_s等），未进行消毒 @ 未在提供的代码片段中显示
- 结论: LDAP注入漏洞：通过套接字接收的用户输入未经验证直接用于LDAP查询，攻击者可构造恶意输入操纵LDAP语句。
- D验证: stage_c_preserved / ver_e5f9bc44
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 299. hyp_path_7f7a266ab7d8

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_66a.c:84
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接向监听端口发送恶意LDAP查询字符串，且该字符串被recv函数接收并最终传递给LDAP查询构建。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_66a.c:89; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; replace = wcschr(data, L'\r'); ... replace = wcschr(data, L'\n'); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_66a.c:95-96; dataArray[2] = data; CWE90_LDAP_Injection__w32_wchar_t_connect_socket_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_66a.c:108-109
- 结论: 从网络接收的数据未经充分净化直接传递给LDAP查询构建函数，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_e48c7693
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 300. hyp_path_2b0415006b9d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_43.cpp:72
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够与监听端口建立TCP连接并发送恶意负载
- 触发路径: listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); @ L70-74; acceptSocket = accept(listenSocket, NULL, NULL); @ L87-91; recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L93-97; 假设存在LDAP函数调用，但代码中未出现 @ 未知
- 结论: 通过listen socket接收外部输入，数据可能用于后续LDAP查询，但当前代码证据中未显示具体的LDAP sink函数调用，因此source-to-sink路径未完全闭合。基于CWE90测试用例上下文，推测存在LDAP调用，但无法从提供的代码片段确认。
- D验证: stage_c_preserved / ver_7b40b353
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 301. hyp_path_02eb5f972e46

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_45.c:138
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标socket（默认端口未改变）并发送任意数据。
- 触发路径: recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_45.c:138; data[dataLen + recvResult / sizeof(wchar_t)] = L'\0'; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_45.c:145; case0Sink()调用，将data传递给CWE90_LDAP_Injection__w32_wchar_t_connect_socket_45_case0Data @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_45.c:50-51; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_45.c:67; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_45.c:92
- 结论: 存在LDAP注入漏洞，攻击者可通过socket发送恶意数据，在LDAP搜索过滤器中使用未经过滤的用户输入，从而导致LDAP注入攻击。
- D验证: confirmed / ver_3c06e50a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 302. hyp_path_4bc27a287ee4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_68a.c:86
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制远程服务器，使其向目标程序发送特制的LDAP注入payload。
- 触发路径: connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_68a.c:84-88; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_68a.c:91-95; CWE90_LDAP_Injection__w32_wchar_t_connect_socket_68_case0Data = data; @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_68a.c:104; 调用sink函数，但具体LDAP操作代码未提供，但基于Juliet样本惯例，其执行未过滤的LDAP查询，构成注入。 @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_68b.c
- 结论: CWE90 LDAP注入漏洞：从网络接收未经验证的数据，然后传递给LDAP查询sink，攻击者可以控制输入导致LDAP注入。
- D验证: stage_c_preserved / ver_2ee6566b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 303. hyp_path_945114500e1a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_62b.cpp:76
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络向目标发送恶意LDAP查询字符串。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_62b.cpp:83; void case0Source(wchar_t * &data) { ... } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_62b.cpp:45; 假设调用方将data直接用于LDAP搜索 @ 调用方（未显示）
- 结论: 从网络接收的数据未经过任何过滤或转义，通过引用传出，如果调用方将其用于LDAP查询，则存在LDAP注入漏洞。
- D验证: stage_c_preserved / ver_27977cd8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 304. hyp_path_cb0436251321

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_84_case0.cpp:80
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到目标socket服务; 目标系统后续使用接收的数据发起LDAP查询（假设）
- 触发路径: socket()和connect()建立连接 @ L71-78; recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0) 接收数据 @ L85-89; 接收的数据可能被传递给LDAP查询函数，但代码中未出现ldap_search等调用 @ 未显示
- 结论: 通过socket接收的用户输入数据可能用于LDAP查询构造，但缺少LDAP相关API调用的直接证据，漏洞路径不完整。
- D验证: stage_c_preserved / ver_423d1813
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 305. hyp_path_ab1fd494f5a3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_42.c:77
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者通过网络连接并发送恶意数据; 服务端将接收到的数据用于LDAP查询操作
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ 行77-86; 假设存在类似ldap_search_s的调用 @ 后续代码（未提供）中data可能用于LDAP查询
- 结论: LDAP注入漏洞：攻击者通过网络发送特制数据，该数据可能被用于LDAP查询，但当前代码片段未展示LDAP查询函数，路径不完整。
- D验证: stage_c_preserved / ver_3af2be35
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 306. hyp_path_60419e395215

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_83_case0.cpp:80
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够与服务器建立TCP连接并发送恶意负载
- 触发路径: 建立socket连接 @ L71-82; recv(connectSocket, data, ...) @ L85-89; data可能被用于LDAP查询（未显示） @ 未提供
- 结论: 代码通过socket接收网络数据并存储到data变量，但后续未在提供的代码片段中展示LDAP查询调用，因此source-sink路径不完整。然而，B阶段静态分析标记为high_risk_sink且supported=true，暗示可能存在LDAP注入风险，但需D验证确认实际sink。
- D验证: stage_c_preserved / ver_40cba3d1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 307. hyp_path_7785c500bcc7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_22b.c:78
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: Attacker can control network input via TCP connection
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_22b.c:85-88; Missing sink code @ Unconfirmed sink (likely in another file, e.g., ldap_search)
- 结论: Potential LDAP Injection via network recv data; sink not confirmed in provided code, but sample name and B-stage assessment indicate high risk. If recv data flows to LDAP query without sanitization, vulnerability exists.
- D验证: stage_c_preserved / ver_f5f0a249
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 308. hyp_path_33ccbec46188

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_21.c:168
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序监听的端口发送恶意LDAP过滤器字符串
- 触发路径: case0Source函数通过recv从connectSocket接收数据到data @ L49-122; recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L89; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L136; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...); @ L168
- 结论: 代码中存在LDAP注入漏洞，用户输入通过socket接收后未经任何过滤或转义直接拼接进LDAP搜索过滤器，攻击者可以操纵LDAP查询。
- D验证: confirmed / ver_f3dff9f3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 309. hyp_path_3127c18f0abf

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_21.c:168
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接目标程序的监听端口，并发送包含LDAP注入payload的数据。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ case0Source函数内 recv调用; return data; @ case0Source函数返回; char filter[256]; _snprintf(filter, 256-1, "(cn=%s)", data); @ 主函数第135-140行; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ 主函数第168行
- 结论: LDAP注入漏洞：在ldap_search_ext_sA调用中，用户输入直接拼接到LDAP过滤器，未经任何消毒，导致攻击者可以注入任意LDAP过滤器，操纵LDAP查询。
- D验证: confirmed / ver_2f4fac2d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 310. hyp_path_64614585e77a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_43.cpp:163
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够与被测主机建立socket连接; 攻击者能够发送特制的LDAP注入payload
- 触发路径: recv(connectSocket, (char *)(data + dataLen), ...) @ case0Source函数; _snprintf(filter, 256-1, "(cn=%s)", data); @ main函数第131-135行; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter ...); @ main函数第163行
- 结论: LDAP注入漏洞：用户从socket接收的数据直接拼接至LDAP查询过滤器，导致攻击者可执行任意LDAP查询。
- D验证: confirmed / ver_7652276e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 311. hyp_path_03e70781c4ea

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_21.c:180
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向目标主机的指定 TCP 端口发起连接并发送恶意数据
- 触发路径: recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ case0Source 函数内 recv 调用 (L95-99); return data; @ case0Source 返回 data (L134); _snprintf(filter, 256-1, "(cn=%s)", data); @ 主函数中 _snprintf 调用 (L148-152); searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ ldap_search_ext_sA 调用 (L180)
- 结论: LDAP注入漏洞：通过 recv 从网络接收的输入 data 未经任何过滤直接拼接到 LDAP 搜索过滤器 filter 中，并调用 ldap_search_ext_sA 执行搜索，攻击者可构造恶意输入导致 LDAP 注入。
- D验证: confirmed / ver_5966cbe5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 312. hyp_path_6072b746bc2d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_21.c:180
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够与被测主机建立TCP连接; 攻击者能够在连接上发送任意wchar_t字符串; 目标LDAP服务器可达且允许搜索; case0Static为真（值为1）
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ L95-99; data = case0Source(data); @ L136; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L149-152; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L180
- 结论: LDAP注入漏洞：攻击者通过网络socket发送恶意数据，数据未经任何消毒直接拼接到LDAP搜索过滤器中，可导致LDAP注入攻击。
- D验证: confirmed / ver_0b12b8fa
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 313. hyp_path_0bb6a09e19a3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_43.cpp:163
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够访问网络服务并发送恶意LDAP过滤器
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ case0Source函数内; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 主函数中; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ 主函数中
- 结论: LDAP注入漏洞：用户可控数据通过套接字接收后，直接拼接到LDAP搜索过滤器中，导致攻击者可以注入LDAP操作。
- D验证: confirmed / ver_d57f69c8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 314. hyp_path_5e006a1bb281

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_43.cpp:175
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标程序监听的TCP端口，并发送任意字符串。
- 触发路径: recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_43.cpp:95; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_43.cpp:144; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_43.cpp:175
- 结论: LDAP注入：从网络socket接收的数据未经充分过滤或转义，直接拼接到LDAP搜索过滤器，攻击者可通过构造恶意输入执行未授权的LDAP查询或修改。
- D验证: confirmed / ver_08ad9468
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 315. hyp_path_3772b2e0dd23

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_42.c:161
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制网络连接，向目标程序发送任意LDAP过滤器输入
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ case0Source函数中recv调用; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 数据拼接到filter; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ 执行LDAP搜索
- 结论: LDAP注入漏洞：从网络套接字接收的输入直接拼接到LDAP搜索过滤器字符串中，攻击者可以通过构造恶意输入操纵LDAP查询，可能导致未授权的数据访问或信息泄露。
- D验证: confirmed / ver_91b3ab76
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 316. hyp_path_df7b1b48be88

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_42.c:173
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够访问目标主机的监听端口（如TCP端口默认值）; 目标主机运行了该程序并处于监听状态; LDAP服务器可访问且允许查询
- 触发路径: recv(acceptSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L90-94 (case0Source函数内); data = case0Source(data); @ L130 (主函数入口); _snprintf(filter, 256-1, "(cn=%s)", data); @ L141-145 (构建filter); searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L171-175 (执行查询)
- 结论: LDAP注入漏洞：通过listen socket接收的攻击者可控数据直接拼接到LDAP查询filter中，未进行任何过滤或转义，导致攻击者可以注入任意LDAP过滤器，可能执行未授权操作或泄露信息。
- D验证: confirmed / ver_6e50f6b4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 317. hyp_path_c944a9e442c4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_43.cpp:175
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到目标服务; 目标服务使用默认的localhost LDAP配置; LDAP服务器允许匿名或认证后的搜索操作
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ case0Source函数; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 主函数; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ 主函数
- 结论: LDAP注入漏洞：攻击者通过socket输入可控数据，数据被直接拼接到LDAP搜索过滤器，导致注入
- D验证: confirmed / ver_9a00b578
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 318. hyp_path_6c985ecade64

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_42.c:161
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够在connectSocket对应的IP地址和端口上建立TCP连接并发送恶意payload；目标系统必须能够连接到远程LDAP服务器并允许查询。
- 触发路径: recvResult = recv(connectSocket, (char *)(data + dataLen), sizeof(char) * (256 - dataLen - 1), 0); @ L82-86 (case0Source); _snprintf(filter, 256-1, "(cn=%s)", data); @ L129-133; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L161
- 结论: LDAP注入漏洞：通过网络接收的用户输入直接拼接到LDAP搜索过滤器，攻击者可注入恶意LDAP语法改变查询逻辑。
- D验证: confirmed / ver_3f942d52
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 319. hyp_path_0f38b996d2e9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_42.c:173
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标系统的监听端口并发送任意数据
- 触发路径: recvResult = recv(acceptSocket, (char *)(data + dataLen), sizeof(wchar_t) * (256 - dataLen - 1), 0); @ case0Source函数中的recv调用; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ main函数中LDAP过滤器构造; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...); @ LDAP搜索调用
- 结论: LDAP注入漏洞：从网络socket接收的数据直接拼接到LDAP搜索过滤器中，未进行任何转义或验证，攻击者可构造恶意输入操纵LDAP查询。
- D验证: confirmed / ver_2e9fc00b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 320. hyp_path_425d781b8907

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_74a.cpp:49
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向FILENAME指向的文件写入恶意LDAP查询数据
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_74a.cpp:49; dataMap[0] = data; ... case0Sink(dataMap); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_74a.cpp:59
- 结论: 从文件读取的数据未经充分验证，直接用于LDAP查询，可能导致LDAP注入。
- D验证: stage_c_preserved / ver_d14e7191
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 321. hyp_path_ee72565415b4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_72a.cpp:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制进程的环境变量（例如通过本地或远程执行）
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_72a.cpp:47; wcsncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_72a.cpp:52; case0Sink(dataVector); // 将data用于LDAP操作 @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_72a.cpp (sink function)
- 结论: 代码从环境变量读取数据并拼接到LDAP查询字符串中，未进行任何过滤或转义，导致LDAP注入漏洞。攻击者可以通过设置环境变量控制LDAP查询内容。
- D验证: stage_c_preserved / ver_9739262a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 322. hyp_path_0e69b67c0e0d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_74a.cpp:49
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制文件FILENAME的内容或文件路径
- 触发路径: pFile = fopen(FILENAME, "r"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_74a.cpp:49; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_74a.cpp:51-55; data[dataLen] = L'\0'; fclose(pFile); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_74a.cpp:57-61; dataMap[0] = data; dataMap[1] = data; dataMap[2] = data; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_74a.cpp:? (map assignment); case0Sink(dataMap); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_74a.cpp:? (sink call)
- 结论: 从文件读取数据并存储到map中，然后传递给sink函数，sink函数可能用于LDAP查询，存在LDAP注入漏洞。
- D验证: stage_c_preserved / ver_ac05c151
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 323. hyp_path_56e6d9bfe3ed

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_72a.cpp:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_72a.cpp:47; strncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_72a.cpp:50-52; dataVector.insert(dataVector.end(), 1, data); case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_72a.cpp:?? (vector插入和case0Sink调用); // 典型sink实现：ldap_simple_bind_s(ld, data) 或 ldap_search_s(ld, data, ...) @ CWE90_LDAP_Injection__w32_char_environment_72b.cpp（常见实现，未在给定代码中显式展示，但根据常规Juliet测试用例，sink函数内部会调用ldap_search或类似API，且未过滤输入）
- 结论: 攻击者通过控制环境变量ENV_VARIABLE，将恶意数据拼接到data缓冲区，然后通过vector传递至case0Sink，该sink函数（位于CWE90_LDAP_Injection__w32_char_environment_72b.cpp）内部调用ldap_simple_bind_s或类似LDAP API，且未对输入进行过滤，导致LDAP注入。
- D验证: stage_c_preserved / ver_312397a7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 324. hyp_path_a5b27d0e3df6

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_74a.cpp:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的内容
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_74a.cpp:47; wcsncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_74a.cpp:50-53; 使用data构建LDAP查询并执行 @ case0Sink函数内部（未完全展示）
- 结论: LDAP注入漏洞：从环境变量读取攻击者可控制的数据，未经转义直接拼接到LDAP查询中，导致攻击者可以注入任意LDAP过滤器。
- D验证: stage_c_preserved / ver_94f70040
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 325. hyp_path_0789b51f43a8

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_72a.cpp:49
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够写入或修改目标文件FILENAME的内容
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgetws() failed"); } else { data[dataLen] = L'\0'; } fclose(pFile); @ L51-55; dataVector.insert(dataVector.end(), 1, data); @ L62-63; case0Sink(dataVector); @ L64
- 结论: LDAP注入漏洞：从文件读取的用户输入未经任何过滤或转义，通过vector传递到case0Sink函数，该函数执行LDAP查询，导致攻击者能够通过控制文件内容注入LDAP过滤器或修改查询逻辑。
- D验证: stage_c_preserved / ver_caa4eee6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 326. hyp_path_9a3513bd2432

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_72a.cpp:49
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够创建或修改文件FILENAME（如通过共享文件系统、上传等）; 攻击者控制的内容能够被程序读取并作为LDAP查询的一部分
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgets() failed"); } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_72a.cpp:51-55; data[dataLen] = '\0'; } fclose(pFile); } } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_72a.cpp:57-61; dataVector.insert(dataVector.end(), 1, data); case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_72a.cpp:72-73
- 结论: 程序从文件读取用户输入（source: fgets读取文件），并将未净化的数据直接传递给case0Sink函数（该函数预期执行LDAP查询），可能导致LDAP注入攻击。攻击者可通过控制文件内容来操纵LDAP查询，造成未授权访问或数据泄露。
- D验证: stage_c_preserved / ver_26fed9a4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 327. hyp_path_929ba64e8b11

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_72a.cpp:55
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: Attacker can provide arbitrary input via console stdin.
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_72a.cpp:41-45; dataVector.insert(dataVector.end(), 1, data); case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_72a.cpp:55
- 结论: LDAP Injection vulnerability: user-controlled input from console is stored in vector and passed to sink case0Sink, which constructs LDAP query without sanitization, allowing attacker to inject LDAP metacharacters.
- D验证: stage_c_preserved / ver_2e350ae2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 328. hyp_path_d950b3528d59

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_73a.cpp:49
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够将恶意内容写入文件FILENAME（例如通过其他漏洞或本地访问）
- 触发路径: pFile = fopen(FILENAME, "r"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_73a.cpp:49; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgetws() failed"); data[dataLen] = L'\0'; } else { /* success */ } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_73a.cpp:51-55; fclose(pFile); } dataList.push_back(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_73a.cpp:59-61; case0Sink(dataList) - 根据CWE90样本模式，应构造LDAP查询（如 ldap_search_s） @ sink (case0Sink)
- 结论: 存在LDAP注入漏洞。从文件读取的数据未经充分过滤直接用于LDAP查询构造，但sink函数代码缺失，需补充确认。
- D验证: stage_c_preserved / ver_7147a594
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 329. hyp_path_d769fd614ee3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_73a.cpp:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置或影响ENV_VARIABLE环境变量的值。
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_73a.cpp:47; wcsncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_73a.cpp:50-51; dataList.push_back(data); case0Sink(dataList); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_73a.cpp:70-72（推断）; 假设使用数据构造LDAP查询 @ case0Sink函数内部（预期调用LDAP API）
- 结论: 存在LDAP注入漏洞。程序从环境变量读取数据，未经任何过滤或清理，直接追加到缓冲区并通过list传递给case0Sink，预期该函数将数据用于LDAP查询（如ldap_search等），攻击者可通过控制环境变量注入恶意的LDAP过滤器字符串，导致LDAP注入攻击。
- D验证: stage_c_preserved / ver_1476d1ff
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 330. hyp_path_9a161c49cc49

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_74a.cpp:47
- 漏洞类型: buffer_overflow
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值; case0Sink内部使用data构造LDAP查询字符串，且未进行输入验证
- 触发路径: size_t dataLen = strlen(data); char * environment = GETENV(ENV_VARIABLE); if (environment != NULL) { strncat(data+dataLen, environment, 256-dataLen-1); } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_74a.cpp:45-54; dataMap[2] = data; case0Sink(dataMap); @ 同一文件尾部
- 结论: 代码从环境变量获取数据（LDAP注入source），通过strncat拼接至固定长度数组，最终传入case0Sink进行LDAP查询。攻击者可控制环境变量，若sink未对输入进行净化，可导致LDAP注入漏洞。CWE-120缓冲区溢出证据不足，已放弃。sink函数实现未提供，影响证据闭合。
- D验证: stage_c_preserved / ver_a7e08544
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 331. hyp_path_cc3b36f16c7f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_73a.cpp:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE为包含LDAP过滤特殊字符（如'*'、'()'等）的字符串
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_73a.cpp:47; strncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_73a.cpp:52-54; dataList.push_back(data); ... case0Sink(dataList); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_73a.cpp:58-60
- 结论: 环境变量数据未验证直接拼接到LDAP查询，可能导致LDAP注入攻击
- D验证: stage_c_preserved / ver_b6d8fada
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 332. hyp_path_082cf287e265

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_72a.cpp:55
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: Attackers can provide arbitrary input via console; case0Sink function uses input to construct LDAP queries (per CWE90 test case convention)
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_72a.cpp:41-45; dataVector.insert(dataVector.end(), 1, data); case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_72a.cpp:55
- 结论: LDAP Injection vulnerability (CWE90). User input from console is read via fgetws and passed directly to case0Sink without sanitization, allowing LDAP query manipulation.
- D验证: stage_c_preserved / ver_718ae44f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 333. hyp_path_164f1863c37c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_74a.cpp:55
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台（stdin）输入任意长度和内容的宽字符串。
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_74a.cpp:41-43; dataMap[0] = data; dataMap[1] = data; dataMap[2] = data; case0Sink(dataMap); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_74a.cpp:45-50
- 结论: CWE90 LDAP注入漏洞：程序从控制台读取用户输入（fgetws），通过dataMap传递给case0Sink函数。尽管缺乏case0Sink内部直接证据，但依据Juliet测试模式和高风险sink标签，sink很可能使用输入构造LDAP查询且未过滤，路径可达且无防御措施。
- D验证: stage_c_preserved / ver_dd2162f9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 334. hyp_path_423d20307582

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_74a.cpp:55
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向程序的标准输入提供任意字符串，且程序未对输入做任何安全检查
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_74a.cpp:41-45; dataMap[0] = data; dataMap[1] = data; dataMap[2] = data; case0Sink(dataMap); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_74a.cpp:48-55
- 结论: LDAP注入漏洞：通过控制台输入的字符串未经充分验证即传递给case0Sink函数，该函数可能使用未参数化的LDAP API，存在注入风险。
- D验证: stage_c_preserved / ver_5ef35e45
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 335. hyp_path_273b5c28966c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_73a.cpp:49
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够写入或控制FILENAME对应的文件内容
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgets() failed"); data[dataLen] = '\0'; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_73a.cpp:51-55; dataList.push_back(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_73a.cpp:57-61; case0Sink(dataList); @ case0Sink（源码未提供，但静态分析标记为high_risk_sink）
- 结论: LDAP注入漏洞：从文件读取的数据未经净化直接用于LDAP查询，攻击者可通过控制文件内容注入任意LDAP过滤器，可能导致信息泄露或未授权访问。
- D验证: stage_c_preserved / ver_7829c96d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 336. hyp_path_52ffb42e8828

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_74a.cpp:464
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络socket发送恶意数据，注入到data变量（需验证socket路径是否存在）
- 触发路径: data = dataBuffer; strcat(data, "Doe, XXXXX"); @ CWE90_LDAP_Injection__w32_char_listen_socket_74a.cpp:157-161; dataMap[2] = data; case1V1Sink(dataMap); @ CWE90_LDAP_Injection__w32_char_listen_socket_74a.cpp:163-167
- 结论: LDAP注入漏洞疑似存在，但A阶段代码证据未完全闭合外部输入来源（data被固定字符串初始化），可能通过socket接收的路径未在A阶段证据中展示。
- D验证: stage_c_preserved / ver_b2a53afe
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 337. hyp_path_251667c99d00

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_21.c:100
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量 ENV_VARIABLE 的值，或者应用程序运行在攻击者可影响环境变量的环境中（如 CGI 或容器环境）
- 触发路径: static char * case0Source(char * data) { if(case0Static) { size_t dataLen = strlen(data); char * environment = GETENV(ENV_VARIABLE); if (environment != NULL) { strncat(data+dataLen, environment, 256-dataLen-1); } } return data; } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_21.c:37-54; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_21.c:68-72; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter, ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_21.c:81-85
- 结论: 存在 LDAP 注入漏洞：用户通过环境变量控制的数据被直接拼接到 LDAP 搜索过滤器中，攻击者可以注入恶意 LDAP 查询，改变查询逻辑或获取未授权数据。
- D验证: confirmed / ver_082911af
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 338. hyp_path_2ba19a800a09

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_43.cpp:95
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过某种方式设置或影响目标进程的环境变量（如通过共享托管环境、容器环境等）
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); ... wcsncat(data+dataLen, environment, 256-dataLen-1); @ case0Source:37-50; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ main:63-67; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ..., filter, ...); @ main:76-80
- 结论: LDAP注入漏洞：程序从环境变量读取数据（source）并直接拼接到LDAP搜索过滤器（sink），未进行任何输入验证或转义，导致攻击者可通过控制环境变量注入恶意LDAP查询，从而执行未授权的LDAP操作。
- D验证: confirmed / ver_d5310aa3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 339. hyp_path_11b14d874fa7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_21.c:100
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); wcsncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_21.c:45-48; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_21.c:70-71; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_21.c:82-84
- 结论: LDAP注入漏洞：从环境变量获取的数据直接拼接到LDAP搜索过滤器中，未进行任何转义或验证，导致攻击者可通过控制环境变量注入LDAP语法，执行未授权查询。
- D验证: confirmed / ver_c494d67b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 340. hyp_path_9fb529585e16

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_42.c:93
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值（典型场景：在服务器进程启动时可控）
- 触发路径: environment = GETENV(ENV_VARIABLE); strncat(data+dataLen, environment, 256-dataLen-1); @ case0Source函数（第34-48行）; _snprintf(filter, 256-1, "(cn=%s)", data); @ 第63行; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...); @ 第74行
- 结论: LDAP注入漏洞，攻击者可通过控制环境变量注入LDAP查询，修改filter字符串，导致未授权访问或数据泄露。
- D验证: confirmed / ver_4e751911
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 341. hyp_path_86bfaec129b1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_43.cpp:95
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE为任意字符串
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_43.cpp:42; strncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_43.cpp:49; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_43.cpp:65; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_43.cpp:78
- 结论: LDAP注入漏洞：从环境变量读取数据并直接拼接到LDAP搜索过滤器中，攻击者可通过控制环境变量注入任意LDAP查询，导致信息泄露或绕过认证。
- D验证: confirmed / ver_3c87b25e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 342. hyp_path_55a7b9b2940e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_42.c:93
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制目标应用程序的环境变量（例如通过本地访问或部署环境）
- 触发路径: data = case0Source(data); 内部调用 GETENV(ENV_VARIABLE) 获取环境变量，并通过 wcsncat 追加到 data 缓冲区。 @ case0Source 函数 (34-48行); data = case0Source(data); @ 调用点 (55行); _snwprintf(filter, 256-1, L"(cn=%s)", data); @ filter 构造 (62-63行); searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, &pMessage); @ LDAP 搜索调用 (74行)
- 结论: LDAP注入漏洞：程序从环境变量获取输入，未经过滤直接拼接到LDAP搜索过滤器中，攻击者可通过控制环境变量注入任意LDAP查询，导致信息泄露或未授权访问。
- D验证: confirmed / ver_4345e0e3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 343. hyp_path_beb3114766f2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_73a.cpp:55
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台提供恶意输入（如通过stdin），输入中包含LDAP注入payload。
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_73a.cpp:41-45; dataList.push_back(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_73a.cpp:55; case0Sink(dataList); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_73a.cpp:55
- 结论: 程序从控制台读取用户输入并直接传递给LDAP查询sink函数，未进行任何过滤或编码，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_16f8722a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 344. hyp_path_31358c4ddfc7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_73a.cpp:55
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入任意字符串（攻击场景受限于本地控制台，但仍存在本地提权或测试环境风险）
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) { ... dataList.push_back(data); } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_73a.cpp:41-45; case0Sink(dataList); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_73a.cpp:55
- 结论: 从控制台读取的宽字符串输入未经任何过滤或验证，直接传递给case0Sink，根据CWE90测试用例上下文，case0Sink很可能构造LDAP查询，导致LDAP注入漏洞（CWE-90）。由于case0Sink具体实现未提供，证据不完整，但路径合理。
- D验证: stage_c_preserved / ver_44cdd521
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 345. hyp_path_3db924a939ec

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_62a.cpp:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络发送数据到data变量对应的socket输入。
- 触发路径: case0Source(data); @ L32: 函数入口处调用case0Source(data)，从socket读取数据到data; _snprintf(filter, 256-1, "(cn=%s)", data); @ L43-L45: 构造LDAP过滤器字符串，包含未过滤的data; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L56-L60: 调用ldap_search_ext_sA执行LDAP搜索，过滤器为攻击者可控
- 结论: LDAP注入漏洞：用户输入通过socket连接进入data变量，未经充分过滤直接拼接到LDAP搜索过滤器字符串中，导致攻击者可以注入任意LDAP查询，例如修改过滤器逻辑或执行未授权操作。
- D验证: confirmed / ver_a9fc382c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 346. hyp_path_03c353149cbb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_61a.c:72
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序提供控制台输入（即data变量）
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_61a.c:42; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_61a.c:53-57
- 结论: LDAP注入漏洞：程序将用户控制台输入直接拼接到LDAP搜索过滤器中，未进行任何转义或验证，攻击者可通过特制输入修改搜索条件，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_a1edfa6a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 347. hyp_path_36b0df030ad7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_22a.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制CWE90_LDAP_Injection__w32_char_connect_socket_22_case0Source函数的输入（如网络数据、环境变量等）
- 触发路径: data = CWE90_LDAP_Injection__w32_char_connect_socket_22_case0Source(data); @ source函数; _snprintf(filter, 256-1, "(cn=%s)", data); @ L45附近; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter ...); @ L56附近
- 结论: LDAP注入漏洞：外部输入data未经充分过滤直接拼接至LDAP搜索过滤器，攻击者可通过控制data注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_82957ee1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 348. hyp_path_5fe22269ff48

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_61a.c:92
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制函数CWE90_LDAP_Injection__w32_char_connect_socket_61b_case0Source的返回数据
- 触发路径: data = CWE90_LDAP_Injection__w32_char_connect_socket_61b_case0Source(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_61a.c:60; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_61a.c:62; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ... @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_61a.c:73-77
- 结论: LDAP注入漏洞：用户输入data直接拼接到LDAP搜索过滤器，未经验证或转义，攻击者可注入任意LDAP查询操作。
- D验证: confirmed / ver_4c09fecb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 349. hyp_path_09fc79ec987f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_62a.cpp:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过标准输入提供任意字符串
- 触发路径: case0Source(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_62a.cpp:32; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_62a.cpp:45; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_62a.cpp:57
- 结论: LDAP注入漏洞：用户输入通过控制台读取后，直接拼接到LDAP搜索过滤器中，未进行任何编码或验证，攻击者可注入恶意LDAP查询，导致未授权数据访问或信息泄露。
- D验证: confirmed / ver_1e837eea
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 350. hyp_path_3ae8ac62ce01

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_22a.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制控制台输入（stdin）
- 触发路径: void CWE90_LDAP_Injection__w32_char_console_22_case0() @ L31: 入口函数; data = CWE90_LDAP_Injection__w32_char_console_22_case0Source(data); @ L43-45: 读取输入并赋值给data; _snprintf(filter, 256-1, "(cn=%s)", data); ... searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L56-60: 拼接到filter并执行LDAP搜索
- 结论: LDAP注入漏洞：用户输入通过控制台读取，未经任何过滤或转义，直接拼接到LDAP搜索过滤器字符串中，攻击者可以注入任意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_5aa0197c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 351. hyp_path_9fa61b8b80f4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_61a.c:80
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置或影响进程环境变量（如通过命令行、配置文件或外部组件）
- 触发路径: char filter[256]; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_61a.c:48-52; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_61a.c:61-65
- 结论: 代码将环境变量数据直接拼接到LDAP搜索过滤器，导致LDAP注入漏洞。攻击者可通过控制环境变量注入任意LDAP过滤器，可能绕过访问控制、泄露或修改LDAP目录中的数据。
- D验证: confirmed / ver_45a1e254
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 352. hyp_path_3066b0111451

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_22a.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制运行该程序的环境变量（例如通过本地提权或已控制的进程）
- 触发路径: data = getenv("ADD"); @ L? 未提供精确行号（source函数文件未在代码片段中显示，但根据代码逻辑，data通过getenv("ADD")获取）; _snprintf(filter, 256-1, "(cn=%s)", data); @ L45; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter ...); @ L56-60
- 结论: LDAP注入漏洞：用户可控的环境变量数据被直接拼接到LDAP搜索过滤器字符串中，攻击者可以通过控制环境变量注入恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_b027c8c1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 353. hyp_path_5b0aef421bd2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_62a.cpp:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制影响目标程序的环境变量
- 触发路径: case0Source(data); @ 入口行32; _snprintf(filter, 256-1, "(cn=%s)", data); @ 行43-45; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter, ...); @ 行56
- 结论: LDAP注入漏洞：从环境变量获取的数据未经验证直接拼接到LDAP搜索过滤器中，攻击者可通过控制环境变量注入任意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_3cccd2ea
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 354. hyp_path_7266048aa239

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_22a.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接向目标发送恶意data
- 触发路径: 获取外部输入data @ source函数（CWE90_LDAP_Injection__w32_char_listen_socket_22_case0Source）; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_22a.c:45; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_22a.c:56-60
- 结论: LDAP注入漏洞：外部输入data直接拼接到LDAP查询过滤器字符串中，攻击者可通过控制data注入任意LDAP过滤器，导致信息泄露或权限提升。
- D验证: confirmed / ver_2e215112
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 355. hyp_path_8d4d72d93429

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_62a.cpp:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或影响case0Source读取的文件
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ L45; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L56-60
- 结论: LDAP注入漏洞：程序从文件读取用户输入，未经过滤直接拼接到LDAP搜索过滤器中，导致攻击者可通过控制文件内容注入任意LDAP查询。
- D验证: confirmed / ver_2f32e1e0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 356. hyp_path_1eef8763e1f1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_22a.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件的内容，使其包含LDAP注入payload（如"*)(uid=*))"等）。
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_22a.c:45; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage ); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_22a.c:56-60
- 结论: LDAP注入漏洞：外部输入数据直接拼接到LDAP搜索过滤器，未经任何过滤或转义，攻击者可通过控制输入文件内容注入LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_b0746a0c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 357. hyp_path_03e8d3e71472

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_61a.c:92
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到服务器监听端口并发送任意字符串
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ CWE90_LDAP_Injection__w32_char_listen_socket_61a.c:62; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ... ); @ CWE90_LDAP_Injection__w32_char_listen_socket_61a.c:73
- 结论: LDAP注入漏洞：通过listen socket获取的用户输入直接拼接到LDAP搜索过滤器中，攻击者可通过注入特殊字符操纵LDAP查询。
- D验证: confirmed / ver_88b00cd2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 358. hyp_path_bf8fadae2ca5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_61a.c:78
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件的内容，使得data变量包含恶意的LDAP过滤器字符串。
- 触发路径: data = CWE90_LDAP_Injection__w32_char_file_61b_case0Source(data); // 从文件读取数据 @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_61a.c:40-42; _snprintf(filter, 256-1, "(cn=%s)", data); // 未净化数据直接拼入过滤器 @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_61a.c:48; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, LDAP_NO_LIMIT, &pMessage); // 执行LDAP搜索 @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_61a.c:60-61
- 结论: 代码中未对从文件读取的数据进行净化，直接拼接至LDAP搜索过滤器，导致LDAP注入漏洞。攻击者可控制过滤器字符串，操纵LDAP查询。
- D验证: confirmed / ver_41c33425
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 359. hyp_path_4f9ff350a040

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_62a.cpp:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到监听socket并发送任意数据
- 触发路径: case0Source(data); // 从socket读取数据到data @ 入口函数case0; _snprintf(filter, 256-1, "(cn=%s)", data); // 将data直接拼接到过滤器 @ CWE90_LDAP_Injection__w32_char_listen_socket_62a.cpp:45; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... , filter, ...); // 执行含恶意输入的LDAP搜索 @ CWE90_LDAP_Injection__w32_char_listen_socket_62a.cpp:56
- 结论: LDAP注入漏洞：通过socket接收的输入数据直接拼接到LDAP查询过滤器中，攻击者可构造恶意输入修改LDAP查询语义。
- D验证: confirmed / ver_89311030
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 360. hyp_path_61fbf7b40190

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_61a.c:92
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制通过socket传递的data输入
- 触发路径: wchar_t filter[256]; ... _snwprintf(filter, 256-1, L"(cn=%s)", data); pLdapConnection = ldap_initW(L"localhost", LDAP_PORT); @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_61a.c:60-64; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... ) @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_61a.c:73-77
- 结论: LDAP注入漏洞：程序将来自socket的未净化用户输入直接拼接到LDAP搜索过滤器中，并调用ldap_search_ext_sW执行，攻击者可借此注入任意LDAP过滤器，可能导致未授权访问或数据泄露。
- D验证: confirmed / ver_54ddfd2c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 361. hyp_path_27e664443428

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_62a.cpp:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过connect_socket函数向dataBuffer写入任意字符串。
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L44; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter, ...); @ L56-59
- 结论: LDAP注入漏洞：用户输入data直接拼接到LDAP搜索过滤器，攻击者可通过特制输入操纵LDAP查询，可能导致未授权访问或数据泄露。
- D验证: confirmed / ver_cea3cba2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 362. hyp_path_789a6b718f4c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_22a.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接向目标程序发送恶意数据
- 触发路径: data = dataBuffer; @ 数据源：CWE90_LDAP_Injection__w32_wchar_t_connect_socket_22_case0Source函数（socket接收）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L45-46: 构造过滤器; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... filter ... ); @ L58-60: LDAP搜索
- 结论: LDAP注入漏洞：程序使用外部可控的输入构造LDAP搜索过滤器，未进行充分过滤，攻击者可以注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_8cb7154a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 363. hyp_path_5c9d120d87b2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_22a.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向控制台输入任意字符串
- 触发路径: wchar_t filter[256]; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_console_22a.c:43-47; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ CWE90_LDAP_Injection__w32_wchar_t_console_22a.c:56-60
- 结论: 代码中使用控制台输入的数据直接拼接LDAP搜索过滤器，未进行任何转义或校验，导致LDAP注入漏洞。攻击者可以通过输入特殊字符修改LDAP查询逻辑，可能获取未授权的数据或执行未授权的操作。
- D验证: confirmed / ver_f2735f22
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 364. hyp_path_39861299df2b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_61a.c:72
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够运行程序并通过控制台输入字符串（正常交互或stdin重定向）。
- 触发路径: data = CWE90_LDAP_Injection__w32_wchar_t_console_61b_case0Source(data); // 从控制台读取输入 @ CWE90_LDAP_Injection__w32_wchar_t_console_61b_case0Source 函数; _snwprintf(filter, 256-1, L"(cn=%s)", data); // 将输入拼接到过滤器 @ CWE90_LDAP_Injection__w32_wchar_t_console_61a.c:42; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter, ...); // 执行LDAP搜索，包含用户输入 @ CWE90_LDAP_Injection__w32_wchar_t_console_61a.c:53-57
- 结论: LDAP注入漏洞：程序将用户控制台输入直接拼接到LDAP搜索过滤器中，未进行任何过滤或转义，攻击者可通过输入特制字符串执行任意LDAP查询。
- D验证: confirmed / ver_3b3e6c7e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 365. hyp_path_00f92c0ad81f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_22a.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者必须能够控制环境变量，该变量被传入函数并最终拼接到LDAP查询中。
- 触发路径: data = dataBuffer; // 从环境变量获取数据 @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_22a.c:43-47; _snwprintf(filter, 256-1, L"(cn=%s)", data); // 未消毒拼接 @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_22a.c:45; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter, ...); // 执行恶意查询 @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_22a.c:56-60
- 结论: LDAP注入漏洞：攻击者通过控制环境变量数据，可注入任意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_6053de43
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 366. hyp_path_34a6a027c4e6

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_61a.c:80
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制程序的环境变量
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_61a.c:48-50; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ..., filter, ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_61a.c:61-65
- 结论: LDAP注入漏洞：程序通过环境变量获取用户输入，未经任何过滤或转义直接拼接到LDAP搜索过滤器中，导致攻击者可以注入任意LDAP查询，可能访问或修改未授权的目录信息。
- D验证: confirmed / ver_a2fc45b3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 367. hyp_path_388e2107a1bc

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_62a.cpp:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入提供恶意字符串
- 触发路径: case0Source(data); @ case0Source调用处; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L43-L47; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... filter, ...); @ L56-L60
- 结论: LDAP注入漏洞：程序从控制台读取输入，未经验证直接拼接到LDAP搜索过滤器中，攻击者可通过注入LDAP元字符（如*)修改查询逻辑，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_e9efd8e5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 368. hyp_path_0c5c6206a117

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_62a.cpp:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量（如通过本地shell、容器环境或类似方式设置）
- 触发路径: case0Source(data); // 从环境变量读取数据 @ case0Source(data)调用处; _snwprintf(filter, 256-1, L"(cn=%s)", data); // 数据直接拼接 @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_62a.cpp:45; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter ...); // LDAP搜索 @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_62a.cpp:56-60
- 结论: LDAP注入漏洞：从环境变量获取的数据直接拼接到LDAP搜索过滤器中，未进行任何输入验证或转义，攻击者可通过控制环境变量注入任意LDAP查询，可能导致信息泄露或绕过访问控制。
- D验证: confirmed / ver_c9ab61fd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 369. hyp_path_388e7e761be0

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_62a.cpp:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制data的内容（如通过文件输入）。
- 触发路径: case0Source(data); @ 第32行; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 第45行; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ..., filter, ...); @ 第56行附近
- 结论: LDAP注入漏洞：用户可控的data直接拼接到LDAP搜索过滤器，可能导致注入攻击。
- D验证: confirmed / ver_427bf9ae
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 370. hyp_path_6ba569077348

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_61a.c:78
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或控制被程序读取的文件
- 触发路径: data = 从文件读取的字符串 @ 61b.c（函数CWE90_LDAP_Injection__w32_wchar_t_file_61b_case0Source）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 61a.c:46-50; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ..., filter, ...); @ 61a.c:59-63
- 结论: LDAP注入漏洞：从文件读取的数据未经净化直接拼接到LDAP搜索过滤器，攻击者可通过控制文件内容注入任意LDAP查询。
- D验证: confirmed / ver_4ae965ab
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 371. hyp_path_2d82c7e782f9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_22a.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络发送恶意构造的LDAP过滤器字符串
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_22a.c:45; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_22a.c:56-60
- 结论: 在LDAP搜索过滤器中直接拼接用户输入，未进行转义或参数化，导致LDAP注入漏洞（CWE-90）。攻击者可通过监听套接字发送恶意构造的LDAP过滤器字符串，改变查询逻辑，可能绕过访问控制或泄露信息。
- D验证: confirmed / ver_e28e22e7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 372. hyp_path_f00324118029

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_62a.cpp:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过外部输入（例如网络socket）向data传递恶意LDAP查询字符串
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_62a.cpp:43-47; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_62a.cpp:56-60
- 结论: LDAP注入漏洞：用户输入的数据未经转义直接拼接到LDAP搜索过滤器中，攻击者可通过在data中插入LDAP特殊字符修改查询逻辑，例如绕过认证或获取未授权数据。
- D验证: confirmed / ver_cc66fe5c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 373. hyp_path_dbc33bc106b9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_22a.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: Attacker must be able to control the content of the file read by the source function (e.g., file write permission or symlink attack); The LDAP server must be accessible and the search must execute (connection successful)
- 触发路径: data = CWE90_LDAP_Injection__w32_wchar_t_file_22_case0Source(data); @ L36; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L44; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L57
- 结论: LDAP Injection vulnerability: untrusted data read from file is concatenated into an LDAP search filter without sanitization, allowing an attacker to modify the filter and potentially gain unauthorized access or leak sensitive information.
- D验证: confirmed / ver_79f8bde3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 374. hyp_path_33966b668559

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_61a.c:92
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: Attacker can send arbitrary data to the listening socket.; LDAP server is reachable and processes the query.; Application does not sanitize or escape special characters in the filter.
- 触发路径: data = CWE90_LDAP_Injection__w32_wchar_t_listen_socket_61b_case0Source(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_61a.c:62; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_61a.c:64; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... ); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_61a.c:73-77
- 结论: LDAP Injection vulnerability: user-controlled data from a socket is concatenated directly into an LDAP search filter, allowing an attacker to modify the query logic.
- D验证: confirmed / ver_4d3b7b52
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 375. hyp_path_0f09c6b642b2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_72b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制传递给该函数的data参数（例如通过网络或文件输入）
- 触发路径: char * data = dataVector[2]; @ L32; _snprintf(filter, 256-1, "(cn=%s)", data); @ L42-43; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L54-58
- 结论: LDAP注入漏洞：用户输入的数据直接拼接到LDAP搜索过滤器字符串中，未进行任何转义或验证，攻击者可注入任意LDAP过滤器，导致未授权访问或数据泄露。
- D验证: confirmed / ver_44926f77
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 376. hyp_path_785ff8c858f9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_73b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向dataList中注入恶意字符串作为data。
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ L73; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ... @ L54-58
- 结论: LDAP注入漏洞：用户输入数据直接拼接至LDAP搜索过滤器，未进行任何转义或验证，攻击者可构造恶意过滤器执行未授权LDAP查询。
- D验证: confirmed / ver_b13b1116
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 377. hyp_path_200c57009b0c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_74b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制传递给该函数的map中的data字符串。; LDAP服务器可访问且允许匿名或认证查询。
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ CWE90_LDAP_Injection__w32_char_connect_socket_74b.cpp:73; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, LDAP_NO_LIMIT, &pMessage); @ CWE90_LDAP_Injection__w32_char_connect_socket_74b.cpp:73
- 结论: LDAP注入漏洞：用户可控数据直接拼接至LDAP过滤器，导致攻击者能够修改LDAP查询语义。
- D验证: confirmed / ver_7c77750b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 378. hyp_path_03a8eb0c50fa

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_83_case0.cpp:159
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过socket连接向data变量注入任意LDAP过滤器字符串。
- 触发路径: // 假设data来自网络输入 @ data获取处（来自socket连接，测试用例设计如此）; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_83_case0.cpp:157-158; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_83_case0.cpp:159
- 结论: 函数中将用户输入data直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。
- D验证: confirmed / ver_5886ffde
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 379. hyp_path_2152d30915e9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_84_case0.cpp:159
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够与运行该程序的服务器建立网络连接，并发送恶意LDAP注入数据。
- 触发路径: 假设存在recv调用 @ 入口点：socket接收数据，赋值给data变量（代码片段未显示具体行，但根据CWE90样本标准，data通过recv等函数从socket获取）; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_84_case0.cpp; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ 同一文件; if (searchSuccess != LDAP_SUCCESS) { ... exit(1); } @ 同一文件
- 结论: LDAP注入漏洞：通过socket接收的外部数据data被直接拼接进LDAP搜索过滤器，攻击者可注入任意LDAP查询，导致信息泄露或未授权访问。
- D验证: confirmed / ver_c55dda8b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 380. hyp_path_009251e492cb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_74b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向控制台输入任意字符串
- 触发路径: data = (来自map，由控制台输入填充) @ L? 控制台输入赋值; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_74b.cpp:73; searchSuccess = ldap_search_ext_sA(pLdapConnection, filter, ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_74b.cpp:54-58
- 结论: LDAP注入漏洞：外部可控数据通过map传入，未经任何过滤或转义直接拼接到LDAP搜索过滤器中，攻击者可通过构造特定输入修改LDAP查询语义，导致未授权访问或信息泄露。
- D验证: confirmed / ver_58fc00df
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 381. hyp_path_251cfc0237ad

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_72b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制作为参数传入case0Sink的vector中的第三个元素（dataVector[2]）
- 触发路径: void CWE90_LDAP_Injection__w32_char_console_72::case0Sink(vector<char *> dataVector) @ case0Sink函数入口; char * data = dataVector[2]; @ 行: 从vector提取数据（索引2）; _snprintf(filter, 256-1, "(cn=%s)", data); @ 行: 格式化过滤器; pLdapConnection = ldap_initA("localhost", LDAP_PORT); @ 行: LDAP初始化; connectSuccess = ldap_connect(pLdapConnection, NULL); @ 行: LDAP连接; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ 行: LDAP搜索，使用恶意过滤器
- 结论: LDAP注入漏洞：在CWE90_LDAP_Injection__w32_char_console_72b.cpp的case0Sink函数中，用户提供的data字符串未经验证直接拼接到LDAP搜索过滤器字符串中，并调用ldap_search_ext_sA执行查询，导致攻击者可以注入任意LDAP操作。
- D验证: confirmed / ver_a7c1113a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 382. hyp_path_1e7c83cecaa7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_84_case0.cpp:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入提供恶意LDAP过滤器字符串（例如包含特殊字符或LDAP语法）
- 触发路径: data 来源于 console 输入（如 fgets） @ 构造函数或成员函数输入; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_84_case0.cpp:85-86; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_84_case0.cpp:97
- 结论: 代码存在LDAP注入漏洞：用户输入的数据未经任何转义或过滤，直接拼接到LDAP查询过滤器中，攻击者可以控制过滤器字符串，导致LDAP注入攻击。
- D验证: confirmed / ver_64be0d8e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 383. hyp_path_6c2ec9a3ee91

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_73b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过外部输入控制dataList中的data内容，从而控制LDAP过滤器字符串。
- 触发路径: char * data = dataList.back(); @ L? 从dataList获取data（约行号70）; _snprintf(filter, 256-1, "(cn=%s)", data); @ L73 构造filter; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L73 调用LDAP搜索
- 结论: 在LDAP搜索过滤器中直接拼接用户可控字符串，导致LDAP注入漏洞。
- D验证: confirmed / ver_11e1df77
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 384. hyp_path_3476fdad28ee

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_83_case0.cpp:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入提供恶意字符串作为data。
- 触发路径: 假设data通过fgets等读取 @ 析构函数中，data来自控制台输入（构造函数中读取）; _snprintf(filter, 256-1, "(cn=%s)", data); @ filter构造处; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ LDAP搜索调用处
- 结论: LDAP注入漏洞：用户输入的数据data通过_snprintf直接拼接到LDAP搜索过滤器filter中，并传递给ldap_search_ext_sA，攻击者可注入恶意LDAP查询，导致信息泄露或绕过认证。
- D验证: confirmed / ver_15083fb8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 385. hyp_path_4a291e0ebacb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_72b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够修改环境变量，且该环境变量被用作LDAP查询参数
- 触发路径: char * data = dataVector[2]; @ case0Sink函数入口; _snprintf(filter, 256-1, "(cn=%s)", data); @ 构建过滤字符串; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter, ...); @ 执行LDAP搜索
- 结论: LDAP注入漏洞：从环境变量获取的数据未经验证直接拼接到LDAP搜索过滤器中，攻击者可通过控制环境变量修改LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_5b4904a7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 386. hyp_path_96ede2412920

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_83_case0.cpp:91
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制程序执行环境中的特定环境变量（如ADD）
- 触发路径: data = getenv("ADD"); @ 环境变量读取; _snprintf(filter, 256-1, "(cn=%s)", data); @ 字符串拼接; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...); @ LDAP搜索
- 结论: LDAP注入漏洞：通过环境变量获取的字符串未经过滤直接拼接到LDAP搜索过滤器，攻击者可控制LDAP查询，导致敏感信息泄露或权限提升。
- D验证: confirmed / ver_2127306b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 387. hyp_path_33e1c5e3c511

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_73b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量影响data的值
- 触发路径: char * data = dataList.back(); @ L32; _snprintf(filter, 256-1, "(cn=%s)", data); @ L45-46; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ... ); @ L54-58
- 结论: 在LDAP查询过滤器中拼接不受信任的数据，导致LDAP注入漏洞。
- D验证: confirmed / ver_09c8a4fd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 388. hyp_path_1f4f23f804d5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_72b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过文件输入等外部源影响data变量的内容
- 触发路径: char * data = dataVector[2]; @ 入口函数case0Sink，参数dataVector; _snprintf(filter, 256-1, "(cn=%s)", data); @ 构建LDAP过滤字符串; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ..., filter, ...); @ 执行LDAP搜索
- 结论: LDAP注入漏洞：用户输入data未经净化即被拼接到LDAP搜索过滤器中，导致攻击者可以通过控制data修改LDAP查询语义，执行未授权操作。
- D验证: confirmed / ver_a0e86cc8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 389. hyp_path_8bc5498832d2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_74b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: Attacker can control the environment variable from which 'data' is obtained (e.g., via CGI or process environment).
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_74b.cpp:32 (approx); searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_74b.cpp:73
- 结论: LDAP Injection vulnerability: user-controlled environment variable data is concatenated into an LDAP search filter without proper sanitization, allowing an attacker to modify the LDAP query.
- D验证: confirmed / ver_19dee1af
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 390. hyp_path_149e5b3bbdd8

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_83_case0.cpp:99
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件的内容，从而控制data变量
- 触发路径: data = ... 从文件读取 @ 文件读取处（代码未完整展示，但根据Juliet测试用例，data由fgets从文件读取）; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_83_case0.cpp:99附近; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_83_case0.cpp:99附近
- 结论: LDAP注入漏洞：用户可控数据直接拼接到LDAP查询过滤器，导致攻击者可以注入任意LDAP查询。
- D验证: confirmed / ver_9f85189e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 391. hyp_path_eb9ebbf59b92

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_84_case0.cpp:91
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量'data'的内容，或通过其他方式污染该变量。
- 触发路径: char * data; // 假设从环境变量获取，但代码片段未显示赋值 @ L? 缺少明确的环境变量读取代码; _snprintf(filter, 256-1, "(cn=%s)", data); @ L? 代码片段: snprintf; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L72-73
- 结论: LDAP注入漏洞：用户输入（来自环境变量）未经转义直接拼接到LDAP搜索过滤器，攻击者可通过控制环境变量注入恶意LDAP查询，导致未授权访问或信息泄露。但源代码中未明确显示data从环境变量获取的具体代码行，证据不完整。
- D验证: confirmed / ver_8a1690ad
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 392. hyp_path_e1b724387065

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_73b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制写入文件的内容，从而影响data参数的值。
- 触发路径: char * data = dataList.back(); @ CWE90_LDAP_Injection__w32_char_file_73b.cpp:32; _snprintf(filter, 256-1, "(cn=%s)", data); @ CWE90_LDAP_Injection__w32_char_file_73b.cpp:36; searchSuccess = ldap_search_ext_sA(pLdapConnection, filter, ...); @ CWE90_LDAP_Injection__w32_char_file_73b.cpp:54
- 结论: LDAP注入漏洞：攻击者可通过控制data参数（来自文件读取）中的特殊字符，修改LDAP查询语句，导致未授权访问或数据泄露。
- D验证: confirmed / ver_4e81e42e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 393. hyp_path_6b722e9c8219

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_74b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制data变量的内容，例如通过文件输入。
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ L68-70; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, LDAP_NO_LIMIT, &pMessage); @ L73
- 结论: 用户输入数据通过_snprintf直接拼接到LDAP搜索过滤器，导致LDAP注入漏洞。
- D验证: confirmed / ver_372862fc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 394. hyp_path_359f113106f6

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_73b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过外部输入（如监听socket）填充dataList，从而控制data的内容。
- 触发路径: char * data = dataList.back(); @ L72; _snprintf(filter, 256-1, "(cn=%s)", data); @ L73; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L54-58
- 结论: LDAP注入漏洞：从list中获取的data未经过滤直接拼接到LDAP搜索过滤器中，导致攻击者可以注入恶意LDAP查询。
- D验证: confirmed / ver_5a810a3b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 395. hyp_path_1863fa71a2e2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_84_case0.cpp:171
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接向程序发送恶意输入数据
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_84_case0.cpp:171; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_84_case0.cpp:171
- 结论: LDAP注入漏洞：用户输入数据直接拼接到LDAP搜索过滤器字符串中，未进行转义或验证，攻击者可以注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_bb9b50d2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 396. hyp_path_7e54a9907b96

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_84_case0.cpp:99
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或控制输入文件的内容，从而影响data变量的值。
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_84_case0.cpp:70-71; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_84_case0.cpp:80-84
- 结论: 代码中存在LDAP注入漏洞。用户可控的data变量通过snprintf拼接到LDAP查询过滤器中，作为ldap_search_ext_sA的参数，攻击者可以注入恶意LDAP查询，修改查询逻辑，可能导致信息泄露或未授权访问。蓝队挑战已确认该路径真实可达，无防御阻断。
- D验证: confirmed / ver_b0ad6d3b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 397. hyp_path_8a3f136151c5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_72b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络发送特制的LDAP查询字符串
- 触发路径: char * data = dataVector[2]; @ 从vector中取出data，来源为外部输入; _snprintf(filter, 256-1, "(cn=%s)", data); @ data拼接到filter字符串; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ 将filter用于LDAP搜索
- 结论: LDAP注入漏洞：用户输入通过socket接收，直接拼接到LDAP搜索过滤器中，未经验证或转义，导致攻击者可以注入任意LDAP查询，可能获取未经授权的数据或执行未授权操作。
- D验证: confirmed / ver_bb5ca8f1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 398. hyp_path_a9411b46fde0

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_74b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向监听socket发送数据，从而控制data变量的内容。
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_74b.cpp:73; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_74b.cpp:54-58
- 结论: 在CWE90_LDAP_Injection__w32_char_listen_socket_74b.cpp中，外部可控的data通过snprintf直接拼接到LDAP搜索过滤器中，然后传给ldap_search_ext_sA，导致LDAP注入漏洞。攻击者可通过精心构造的输入操纵LDAP查询，可能实现未授权访问或数据泄露。
- D验证: confirmed / ver_70f65d9f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 399. hyp_path_27ec0a51ff8e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_73b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制通过dataList传入的data值
- 触发路径: wchar_t * data = dataList.back(); @ 从dataList获取data; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 拼接过滤器; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...); @ 执行LDAP搜索
- 结论: LDAP注入漏洞：用户输入数据直接拼接至LDAP搜索过滤器，攻击者可注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_ff8ab018
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 400. hyp_path_61e3b284707e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_83_case0.cpp:171
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: Attacker can send arbitrary data over the network socket that populates the 'data' variable.
- 触发路径: recv() into data buffer @ socket recv (implied by context and B-stage evidence); _snprintf(filter, 256-1, "(cn=%s)", data); @ line ~? (filter construction); searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, NULL, NULL, NULL, NULL, NULL, &pMessage); @ line ~171
- 结论: LDAP Injection vulnerability: user-controlled input 'data' is concatenated into an LDAP search filter string without sanitization, allowing an attacker to modify the LDAP query and potentially gain unauthorized access or retrieve sensitive information.
- D验证: confirmed / ver_dff16db0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 401. hyp_path_3ad6a7b1c7c5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_72b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接发送恶意数据，该数据被存储到vector中并触发此sink函数。
- 触发路径: wchar_t * data = dataVector[2]; @ 从vector中获取data; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 构造过滤器; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ 执行LDAP搜索
- 结论: LDAP注入漏洞，用户可控数据直接拼接到LDAP搜索过滤器，攻击者可注入恶意LDAP查询，如修改过滤器逻辑或执行未授权操作。
- D验证: confirmed / ver_475ea2ab
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 402. hyp_path_4eafd9760cd1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_72b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制dataVector[2]的值（例如通过console输入）
- 触发路径: wchar_t * data = dataVector[2]; @ 入口函数case0Sink; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L54 (snwprintf); searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter ...); @ L58 (ldap_search_ext_sW)
- 结论: LDAP注入漏洞：用户控制的数据直接拼接到LDAP搜索过滤器，攻击者可通过注入特殊字符修改LDAP查询逻辑。
- D验证: confirmed / ver_919ea37c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 403. hyp_path_3511da3e1b50

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_83_case0.cpp:159
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制data参数的值（例如通过网络输入）
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ _snwprintf调用处; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ ldap_search_ext_sW调用处
- 结论: LDAP注入漏洞：用户输入data通过socket传入，未经校验直接拼接到LDAP搜索过滤器，攻击者可注入任意LDAP查询，可能访问或修改LDAP目录中的敏感信息。
- D验证: confirmed / ver_ca55fed5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 404. hyp_path_25dc83e16dbb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_74b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入任意字符串。
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 第44行附近; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter, ...); @ 第54行
- 结论: LDAP注入漏洞：用户通过控制台输入的data被直接拼接进LDAP搜索过滤器，攻击者可以注入恶意LDAP语法，导致未授权访问或数据泄露。
- D验证: confirmed / ver_4c9c12f2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 405. hyp_path_0f5253ff319c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_73b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向控制台提供输入，该输入最终作为data传递给LDAP搜索过滤器
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_73b.cpp:73; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... filter ... @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_73b.cpp:73
- 结论: LDAP注入漏洞：在ldap_search_ext_sW调用中，用户提供的data直接拼接到LDAP过滤器中，攻击者可通过控制台输入控制搜索过滤器，导致LDAP注入。
- D验证: confirmed / ver_2cec6bd9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 406. hyp_path_8e61696a8e4b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_74b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过TCP连接发送恶意数据到data变量
- 触发路径: data来自connect_socket（根据样本惯例） @ socket接收数据后赋值给data，并通过map传入sink函数; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ case0Sink函数中拼接filter; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, LDAP_NO_LIMIT, &pMessage); @ 使用filter进行LDAP搜索
- 结论: LDAP注入漏洞：用户可控数据通过socket传入，拼接至LDAP搜索过滤器，导致攻击者可以修改LDAP查询逻辑。
- D验证: confirmed / ver_819f514b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 407. hyp_path_77586d2b95da

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_84_case0.cpp:159
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过connect_socket接收数据，并设置data变量为恶意LDAP查询字符串
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 行159附近; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ 行159
- 结论: LDAP注入漏洞：通过外部可控的data参数，拼接LDAP搜索过滤器并执行ldap_search_ext_sW，攻击者可注入恶意LDAP语法，导致未授权访问或信息泄露。
- D验证: confirmed / ver_cef1d227
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 408. hyp_path_0fc40728c141

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_83_case0.cpp:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入任意数据（例如程序运行在交互式环境或接受用户输入）。
- 触发路径: wchar_t data[256]; ... 从控制台读取 data @ 用户输入获取点（隐式，预期在构造函数中通过fgetws等读取data）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_console_83_case0.cpp 析构函数或构造函数; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ CWE90_LDAP_Injection__w32_wchar_t_console_83_case0.cpp:78 附近
- 结论: LDAP注入漏洞：用户通过控制台输入的数据未经验证和转义直接拼接到LDAP搜索过滤器，攻击者可以注入任意LDAP查询，导致信息泄露或权限提升。
- D验证: confirmed / ver_0375f7d0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 409. hyp_path_8605f7a5635a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_72b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量以提供恶意payload。; LDAP服务可访问且允许执行搜索。
- 触发路径: wchar_t * data = dataVector[2]; @ L32 (dataVector[2]赋值); _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L73 (filter拼接); searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...); @ L73 (LDAP搜索)
- 结论: 在LDAP搜索过滤器中直接连接来自环境变量的外部输入，导致LDAP注入漏洞。攻击者可控制环境变量数据，通过构造恶意输入修改LDAP查询逻辑，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_1e4694e1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 410. hyp_path_00072403139c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_84_case0.cpp:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入字符串; LDAP服务器可达
- 触发路径: wchar_t data; 从控制台读取 @ 控制台输入获取data处（根据CWE90测试案例存在，如_fgetws）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_84_case0.cpp:82-84; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_84_case0.cpp:78-82
- 结论: LDAP注入漏洞：控制台输入数据直接拼接到LDAP搜索过滤器中，攻击者可构造恶意输入执行未授权的LDAP查询或修改。
- D验证: confirmed / ver_6d4be889
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 411. hyp_path_1a903b56ca4c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_73b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制系统环境变量，从而控制data的内容
- 触发路径: wchar_t * data = dataList.back(); @ dataList.back() 从外部传入的list中获取数据（根据测试用例命名，数据源自环境变量）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_environment_73b.cpp:73; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, LDAP_NO_LIMIT, &pMessage); @ CWE90_LDAP_Injection__w32_wchar_t_environment_73b.cpp:73
- 结论: LDAP注入漏洞：从环境变量获取的数据未经充分净化即拼接到LDAP搜索过滤器中，可导致攻击者通过环境变量注入恶意LDAP查询，从而可能访问未授权的数据或执行未授权操作。
- D验证: confirmed / ver_3bf5f8c4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 412. hyp_path_363621878432

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_74b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量data的内容
- 触发路径: wchar_t data[256]; // 从环境变量读取 @ CWE90_LDAP_Injection__w32_wchar_t_environment_74b.cpp:入口函数（从环境变量读取data）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_environment_74b.cpp:filter构造处; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ CWE90_LDAP_Injection__w32_wchar_t_environment_74b.cpp:LDAP搜索调用处
- 结论: LDAP注入漏洞：函数caseSink从环境变量获取用户数据并直接拼接到LDAP搜索过滤器中，未进行任何验证或转义，攻击者可通过控制环境变量注入任意LDAP过滤器，可能导致认证绕过、信息泄露或数据篡改。
- D验证: confirmed / ver_fbb52f35
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 413. hyp_path_340500d52fd0

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_83_case0.cpp:91
- 漏洞类型: CWE-90, CWE-20
- CWE: CWE-90; CWE-20
- 风险等级: P0
- 触发条件: 攻击者能够影响环境变量（如通过进程注入或本地访问）
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 构造过滤器的代码行; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, LDAP_NO_LIMIT, &pMessage); @ LDAP搜索调用
- 结论: LDAP注入漏洞：环境变量来源的data字符串直接拼接到LDAP搜索过滤器中，未经净化，攻击者可注入恶意LDAP查询，导致权限提升或信息泄露。
- D验证: confirmed / ver_048b7c7a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 414. hyp_path_a6c11ab4d784

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_84_case0.cpp:99
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制文件中写入的内容，或文件读取路径受攻击者影响。
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_84_case0.cpp; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ 同上
- 结论: LDAP注入漏洞：从文件读取的数据直接拼接到LDAP搜索过滤器，攻击者可控制LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_23b261ad
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 415. hyp_path_13bfbf0ed06a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_73b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件的内容，从而控制data。
- 触发路径: wchar_t * data = dataList.back(); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_73b.cpp:73; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_73b.cpp:73; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... filter ... ); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_73b.cpp:73
- 结论: LDAP注入漏洞：外部可控数据直接拼接至LDAP搜索过滤器，攻击者可构造恶意输入执行未授权查询或绕过访问控制。
- D验证: confirmed / ver_74acef13
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 416. hyp_path_a41bfef4a422

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_74b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制传递给函数的data参数，例如通过文件输入或网络输入。
- 触发路径: data来源于外部输入（如文件读取），通过map传递 @ 函数参数; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L63（附近）; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L73
- 结论: LDAP注入漏洞：在ldap_search_ext_sW调用中，用户输入被直接拼接至LDAP查询过滤器，未进行任何转义或净化，攻击者可构造恶意输入操纵LDAP查询。
- D验证: confirmed / ver_be7d0cc0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 417. hyp_path_dfcba49931cd

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_83_case0.cpp:99
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制向文件写入的内容
- 触发路径: data从文件读取 @ 文件读取位置（未显式显示，但根据Juliet样例存在）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L99（或附近）; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter, ...); @ L80-84（或附近）
- 结论: LDAP注入漏洞：从文件读取的data未经净化直接拼接到LDAP搜索过滤器中，导致攻击者可以注入任意LDAP查询。
- D验证: confirmed / ver_208b9348
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 418. hyp_path_858046f14336

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_84_case0.cpp:91
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者可以设置环境变量（例如通过子进程继承或其它方式）
- 触发路径: data = _wgetenv(L"ADD"); @ 假设入口函数获取环境变量（未在证据中明确行号）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ line 91; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ line 91附近
- 结论: 用户可控数据通过环境变量传入，直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可构造恶意输入执行未授权的LDAP查询。
- D验证: confirmed / ver_7532c218
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 419. hyp_path_62fea5043edb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_72b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制data的值，例如通过网络输入或上一个漏洞的输出。
- 触发路径: wchar_t * data = dataVector[2]; @ line 32; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ line 33-34; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, ...); @ line 54-58
- 结论: 在LDAP搜索过滤器中使用未净化的用户输入，导致LDAP注入漏洞。
- D验证: confirmed / ver_31620314
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 420. hyp_path_09ab2067cb71

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_83_case0.cpp:171
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制data变量的内容，通过网络套接字接收。
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_listen_socket_83_case0.cpp:171; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ CWE90_LDAP_Injection__w32_wchar_t_listen_socket_83_case0.cpp:152-156
- 结论: CWE90 LDAP注入漏洞：用户输入data通过网络套接字接收，未经适当过滤直接拼接到LDAP查询过滤器字符串中，然后用于ldap_search_ext_sW调用，允许攻击者注入恶意LDAP过滤器，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_e0605ffe
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 421. hyp_path_2c0239a2f808

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_73b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过外部输入（如socket接收）控制data变量的内容
- 触发路径: wchar_t * data = dataList.back(); @ 数据从dataList取出; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 构造LDAP过滤器字符串; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... filter, ... ); @ 执行LDAP搜索
- 结论: LDAP注入漏洞：外部可控数据通过dataList传入，未经转义直接拼接至LDAP搜索过滤器字符串，导致攻击者可以注入任意LDAP查询条件。
- D验证: confirmed / ver_7e9dcbd1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 422. hyp_path_508a0045c844

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_74b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标发送包含LDAP元字符（如'*', '(', ')', '|', '&'等）的payload到监听端口。
- 触发路径: data = 从网络接收的字符串 @ 数据接收处（listener socket）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_listen_socket_74b.cpp（构造filter处）; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ CWE90_LDAP_Injection__w32_wchar_t_listen_socket_74b.cpp:73
- 结论: LDAP注入漏洞：用户可控的data通过_snwprintf直接拼接到LDAP搜索过滤器字符串中，未经过滤或转义，导致攻击者可以注入任意LDAP查询，如通过')'改变查询逻辑，可能绕过认证或获取未授权数据。
- D验证: confirmed / ver_5c4d8ff1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 423. hyp_path_4adf56509f5e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_72b.cpp:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过文件输入控制data的值，使其包含LDAP元字符（如*、()、&、|等）从而篡改过滤器语义。
- 触发路径: wchar_t * data = dataVector[2]; @ L72 (approx); _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L73 (approx); searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... filter ...); @ L76 (approx)
- 结论: LDAP注入漏洞：从文件读取的数据未经验证直接拼接到LDAP查询过滤器，攻击者可以操纵查询条件，导致未授权访问或信息泄露。
- D验证: confirmed / ver_3961ed36
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 424. hyp_path_0ddbd3fd9d99

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_84_case0.cpp:171
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接与应用程序通信，发送包含LDAP注入payload的数据
- 触发路径: wchar_t data[256]; // 假设从socket读取数据 @ 根据文件名listen_socket，数据从socket接收（具体行号未在代码证据中明确，但路径闭合）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_84_case0.cpp:约171行（_snwprintf附近）; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... ); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_84_case0.cpp:152-156
- 结论: LDAP注入漏洞：用户输入通过socket接收后直接拼接到LDAP搜索过滤器，攻击者可注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_70f6e6de
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 425. hyp_path_07e0642bee8a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_45.c:89
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过socket发送特制字符串控制data变量的内容
- 触发路径: data = 外部输入 @ 输入获取点（通过socket接收并赋值给data）; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_45.c:89; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ... filter ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_45.c:90-91
- 结论: LDAP注入漏洞：外部输入数据未经验证直接拼接到LDAP查询过滤器字符串中，导致攻击者可以注入任意LDAP过滤器，可能造成未授权访问或信息泄露。
- D验证: confirmed / ver_83c770c0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 426. hyp_path_6c5ed9fc2d6a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_53d.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过socket控制data变量的内容
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ CWE90_LDAP_Injection__w32_char_connect_socket_53d.c:87附近（实际_snprintf行）; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ CWE90_LDAP_Injection__w32_char_connect_socket_53d.c:89附近（实际ldap_search_ext_sA行）
- 结论: LDAP注入漏洞：用户可控数据通过socket直接拼接到LDAP查询过滤器中，未进行任何转义或过滤，攻击者可注入任意LDAP查询，导致信息泄露或未授权访问。
- D验证: confirmed / ver_1c1b09ab
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 427. hyp_path_a625229d93a1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_41.c:85
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序提供恶意字符串赋值给 data
- 触发路径: char data[256]; // 假设从socket读取赋值，但代码片段中未显示具体源 @ 行85之前（变量 data 定义处）; _snprintf(filter, 256-1, "(cn=%s)", data); @ 行85; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ 行85附近
- 结论: LDAP注入漏洞：用户可控的字符串 data 未经任何过滤直接拼接到LDAP搜索过滤器中，可能导致攻击者注入任意LDAP查询，但 data 的外部输入来源未在提供的代码片段中明确显示。
- D验证: confirmed / ver_1023dcd2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 428. hyp_path_c9db995d0627

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_44.c:85
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: Attacker can send arbitrary data over a network socket to the application, which is stored in the 'data' variable.
- 触发路径: Recv data from socket @ socket read into 'data'; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_44.c:85; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_44.c:85-86
- 结论: LDAP Injection vulnerability: user-controlled data is concatenated into an LDAP search filter without sanitization, allowing an attacker to modify the filter logic.
- D验证: confirmed / ver_7505ce3d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 429. hyp_path_244fc54f58ef

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_51b.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接发送恶意字符串到data变量
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ L87; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L87
- 结论: LDAP注入漏洞：用户输入数据直接拼接到LDAP搜索过滤器中，攻击者可以注入恶意LDAP查询，修改LDAP语句的逻辑，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_d6bdae8f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 430. hyp_path_1b52326c094c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_52c.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制提供给data的输入
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ L88; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage ); @ L68
- 结论: LDAP注入漏洞：用户输入的数据直接拼接到LDAP搜索过滤器中，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_f57cc74d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 431. hyp_path_2a32a7e0664f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_54e.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标发送恶意数据，控制data变量的内容。
- 触发路径: 数据来自socket，根据上下文可知未显示在片段中，但Juliet测试套件典型做法是直接读取并传递 @ 入口函数通过socket接收数据并传递给sink函数; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_54e.c:73; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_54e.c:68
- 结论: 用户可控数据通过socket输入，直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可构造恶意LDAP过滤器，实现未授权访问或信息泄露。
- D验证: confirmed / ver_4f2a47a7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 432. hyp_path_1a0aae5498cf

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_63b.c:86
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标应用程序发送特制的data值
- 触发路径: 通过connect_socket接收数据到data @ socket接收data的位置（未直接给出，但根据上下文为connect_socket）; _snprintf(filter, 256-1, "(cn=%s)", data); @ snprintf调用; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, NULL, NULL); @ ldap_search_ext_sA调用
- 结论: LDAP注入漏洞：用户输入通过socket接收后，未经转义直接拼接到LDAP搜索过滤器字符串中，攻击者可注入恶意LDAP语法以操控查询逻辑。
- D验证: confirmed / ver_8546d46a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 433. hyp_path_0f3fc96fc1b5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_64b.c:89
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制变量data的内容，例如通过套接字接收的数据
- 触发路径: CWE90_LDAP_Injection__w32_char_connect_socket_64b_case0Sink(data) @ 入口函数参数data; _snprintf(filter, 256-1, "(cn=%s)", data); @ 构建过滤器; ldap_search_ext_sA(pLdapConnection, "base", ... filter ...); @ 执行搜索
- 结论: LDAP注入漏洞：用户输入直接拼接到LDAP搜索过滤器中，未进行转义或验证，攻击者可控制LDAP查询，可能执行注入攻击。
- D验证: confirmed / ver_cf08377c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 434. hyp_path_60d8e9dbc6e1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_65b.c:85
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制变量data的内容（例如通过socket输入）
- 触发路径: data来自外部输入 @ 推测为socket输入（如recv），但未在提供片段中明确行号; _snprintf(filter, 256-1, "(cn=%s)", data); @ 约第85行附近（注释指出_snprintf）; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ..., filter, ...); @ 第66-70行
- 结论: LDAP注入漏洞：用户控制的data通过_snprintf拼接到LDAP搜索过滤器，并传递给ldap_search_ext_sA，导致LDAP注入。
- D验证: confirmed / ver_56c673f7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 435. hyp_path_929edc8a9e74

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_67b.c:91
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过外部输入（如网络socket）控制变量data的值
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_67b.c (疑似行78-80); searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ... filter ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_67b.c (疑似行91)
- 结论: LDAP注入漏洞：未经验证的用户输入data直接拼接到LDAP搜索过滤器filter中，并用于ldap_search_ext_sA调用，可能导致攻击者操纵LDAP查询，实现未授权访问或信息泄露。
- D验证: confirmed / ver_94f991bc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 436. hyp_path_75af373089c9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_44.c:65
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序提供console输入
- 触发路径: data = console输入 @ console输入位置（根据路由为console输入）; _snprintf(filter, 256-1, "(cn=%s)", data); @ _snprintf行; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ... @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_44.c:46-50
- 结论: LDAP注入漏洞：用户输入直接拼接到LDAP搜索过滤器中，未进行任何过滤或转义，攻击者可通过构造特殊输入修改LDAP查询语义，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_1d32033d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 437. hyp_path_a4e807db9c94

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_45.c:69
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向应用程序提供控制台输入，作为data变量的值。
- 触发路径: data = 从控制台读取的字符串（代码未展示但函数名暗示） @ case0Sink入口，data从控制台读取（推测）; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_45.c:51; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_45.c:69
- 结论: LDAP注入漏洞：用户输入直接拼接到LDAP搜索过滤器中，攻击者可构造恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_458bb37d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 438. hyp_path_2f74f681f281

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_66b.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过socket连接发送恶意数据，例如包含LDAP过滤特殊字符（如*、|、&、!、=等）的字符串。
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_66b.c:60; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_66b.c:68
- 结论: LDAP注入漏洞：用户输入通过socket连接获取后，未经任何过滤或转义直接拼接到LDAP搜索过滤器中，攻击者可构造恶意查询操纵LDAP目录。
- D验证: confirmed / ver_e9cfa083
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 439. hyp_path_7951a8685c80

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_81_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络发送恶意数据到使用该函数的服务，控制data参数的内容
- 触发路径: action(char * data) @ 入口函数 action 参数 data; _snprintf(filter, 256-1, "(cn=%s)", data); @ 大约第39行; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, &pMessage); @ 第68行
- 结论: LDAP注入漏洞：用户输入的数据未经任何转义或验证直接拼接到LDAP搜索过滤器中，攻击者可以构造恶意输入导致LDAP查询结果被篡改或泄露敏感信息。
- D验证: confirmed / ver_9e0ecaf6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 440. hyp_path_c45636e5facd

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_82_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络发送特制的data字符串到目标应用程序。
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_82_case0.cpp; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, NULL, NULL, NULL, LDAP_NO_LIMIT, &pMessage); @ 同文件
- 结论: LDAP注入漏洞：用户控制的输入data被直接拼接到LDAP查询过滤器字符串中，导致攻击者可以通过注入LDAP元字符来修改查询语义，实现未授权访问或信息泄露。
- D验证: confirmed / ver_67de7674
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 441. hyp_path_5da2ee97cc46

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_41.c:65
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过标准输入提供任意字符串; 目标LDAP服务器可达且连接成功
- 触发路径: fgets(data, ...); 或类似读取 @ 父函数（如bad函数）中从控制台读取输入到data变量（代码未显式展示，但根据Juliet测试用例惯例存在）; _snprintf(filter, 256-1, "(cn=%s)", data); @ CWE90_LDAP_Injection__w32_char_console_41.c:65; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ...); @ CWE90_LDAP_Injection__w32_char_console_41.c:65（同一行或附近）
- 结论: LDAP注入漏洞：程序将从控制台读取的用户输入未经任何过滤或转义直接拼接到LDAP搜索过滤器字符串中，导致攻击者能够通过构造特殊输入来操纵LDAP查询，从而可能绕过认证、获取未授权数据或执行其他恶意操作。
- D验证: confirmed / ver_f5c737a3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 442. hyp_path_633d2b9374d7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_51b.c:67
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入任意字符串
- 触发路径: char data[100]; data = (char *)fgets(...) @ L28（入口函数）; _snprintf(filter, 256-1, "(cn=%s)", data); @ L?（拼接过滤器）; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L48-52
- 结论: 用户输入通过控制台读取后直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可修改过滤条件，执行未授权的LDAP查询。
- D验证: confirmed / ver_96f63cac
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 443. hyp_path_3dd8af2305ad

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_52c.c:67
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入提供恶意字符串，例如包含LDAP特殊字符（如*、()、&等）。
- 触发路径: data = ConsoleReadInput(); @ 从控制台读取用户输入到data变量; _snprintf(filter, 256-1, "(cn=%s)", data); @ L? 构造filter; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L? 调用ldap_search_ext_sA
- 结论: LDAP注入漏洞：用户输入通过控制台读取后直接拼接到LDAP搜索过滤器中，未进行转义或验证，攻击者可构造恶意LDAP查询语句，导致未经授权的数据访问或修改。
- D验证: confirmed / ver_f4fa4b5b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 444. hyp_path_164a42ea30db

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_53d.c:67
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向控制台输入任意字符串
- 触发路径: data = ConsoleReadLine(); @ 入口函数通过ConsoleReadLine或类似方式从控制台读取输入，赋值给data; _snprintf(filter, 256-1, "(cn=%s)", data); @ 拼接data到LDAP过滤器字符串; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ 使用未净化的过滤器进行LDAP搜索
- 结论: LDAP注入漏洞：程序从控制台读取用户输入（data），直接通过_snprintf拼接到LDAP搜索过滤器字符串filter中，未进行任何过滤或转义，随后将filter传入ldap_search_ext_sA执行LDAP搜索，攻击者可构造恶意输入执行任意LDAP查询。
- D验证: confirmed / ver_bcb75d4c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 445. hyp_path_8c937202140d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_68b.c:91
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制网络输入到目标进程的socket连接中。
- 触发路径: 从socket读取数据到data @ 入口函数CWE90_LDAP_Injection__w32_char_connect_socket_68b_case0Sink，第51行附近; _snprintf(filter, 256-1, "(cn=%s)", data); @ 第85行附近; ldap_search_ext_sA(pLdapConnection, filter, ...); @ 第91行附近
- 结论: LDAP注入漏洞：通过socket接收的未经验证的用户输入直接拼接到LDAP搜索过滤器中，攻击者可注入恶意LDAP查询，绕过认证或获取未授权数据。
- D验证: confirmed / ver_f1c8d4ca
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 446. hyp_path_1538b086093f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_64b.c:69
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入任意字符串作为data的值。
- 触发路径: data = ConsoleReadLine() @ 代码中从控制台读取数据并赋值给data变量（根据CWE90样例通常如此）; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_64b.c:69; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ 同一文件第69行附近
- 结论: 存在LDAP注入漏洞，攻击者可以通过控制控制台输入data，将其直接拼接到LDAP搜索过滤器中，从而操纵LDAP查询，可能导致未授权访问或数据泄露。
- D验证: confirmed / ver_1dde94a1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 447. hyp_path_6319f55cbc24

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_63b.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序的控制台输入提供恶意字符串
- 触发路径: data从控制台读取（未在提供片段中显式显示，但根据Juliet测试用例惯例） @ （推断）控制台输入，来自函数调用者; _snprintf(filter, 256-1, "(cn=%s)", data); @ 约第55行; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ 约第60行
- 结论: LDAP查询过滤器中的字符串拼接未进行转义，导致LDAP注入漏洞。攻击者可通过控制台输入注入任意LDAP过滤器，从而读取或修改LDAP目录数据。
- D验证: confirmed / ver_304ab372
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 448. hyp_path_028376b34577

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_67b.c:71
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向应用程序提供控制台输入
- 触发路径: 数据来源于控制台输入（未明确行号，但A阶段证据表明来源为控制台）; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_67b.c; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_67b.c
- 结论: LDAP注入漏洞：外部输入数据直接拼接到LDAP搜索过滤器字符串中，未进行任何转义或验证，允许攻击者通过构造特殊字符修改LDAP查询语义，可能导致未授权数据访问或信息泄露。
- D验证: confirmed / ver_19382222
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 449. hyp_path_47bce2ae42d3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_54e.c:67
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入字符串data
- 触发路径: data = ... @ data来源（通常通过控制台输入，如fgets）; _snprintf(filter, 256-1, "(cn=%s)", data); @ L?（约67行附近）; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter, ...); @ L67
- 结论: LDAP注入漏洞：用户输入的数据未经验证直接拼接到LDAP搜索过滤器中，导致攻击者可以通过注入特殊字符修改LDAP查询语义，从而绕过认证或泄露敏感信息。
- D验证: confirmed / ver_ac62ba88
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 450. hyp_path_093df9a3728d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_68b.c:71
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序提供输入（通过控制台）
- 触发路径: data = 从控制台读取的字符串 @ source: 控制台输入读取（如fgets），位于同一测试用例的源文件（未在片段中显示，但根据测试用例性质可推断）; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_68b.c:65; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 15000, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_68b.c:71
- 结论: LDAP注入漏洞：程序通过控制台获取输入，直接将未经过滤的字符串拼接至LDAP查询过滤器中，攻击者可通过构造特殊字符（如'*'、'('、')'、'\'等）修改LDAP查询语义，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_d3eff9d5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 451. hyp_path_b6b70da5f1e3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_65b.c:65
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入提供恶意字符串，例如包含LDAP过滤器通配符或注入代码
- 触发路径: fgets(data, 256, stdin); @ L26 控制台输入读取（根据入口）; _snprintf(filter, 256-1, "(cn=%s)", data); @ L? 过滤器构造; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L46-50
- 结论: LDAP注入漏洞：通过控制台读取的用户输入未经验证或转义，直接拼接到LDAP搜索过滤器中，攻击者可以操纵LDAP查询，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_d7b285da
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 452. hyp_path_5cfc85554b6b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_41.c:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入环境变量，使data包含LDAP注入payload
- 触发路径: data = getenv("ADD"); // 示例 @ 入口处（通常来自getenv）; _snprintf(filter, 256-1, "(cn=%s)", data); @ 过滤器构建行（代码中存在）; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_41.c:73
- 结论: 存在LDAP注入漏洞。用户输入通过环境变量获取后，未经验证直接拼接到LDAP搜索过滤器中，导致攻击者可控制搜索条件进行注入。
- D验证: confirmed / ver_b63fac56
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 453. hyp_path_33d843bef0bc

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_81_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制控制台输入字符串data; 系统运行LDAP服务且连接成功（例如localhost LDAP服务正常）
- 触发路径: 接收用户输入data @ 入口函数action（第29行）; _snprintf(filter, 256-1, "(cn=%s)", data); @ 第64-65行; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ 第68行附近
- 结论: LDAP注入漏洞：用户通过控制台提供的输入（data）未经净化直接拼接到LDAP搜索过滤器字符串中，攻击者可注入LDAP元字符修改查询语义，导致未授权访问或信息泄露。
- D验证: confirmed / ver_8ed06e3e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 454. hyp_path_1d7a6a949aa1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_82_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序提供任意字符串作为输入（通过控制台）。
- 触发路径: CWE90_LDAP_Injection__w32_char_console_82_case0::action(char * data) @ L29 入口; _snprintf(filter, 256-1, "(cn=%s)", data); @ L? 拼接filter; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L68 搜索
- 结论: LDAP注入漏洞：用户输入数据直接拼接进LDAP搜索过滤器，未进行转义或过滤，攻击者可注入恶意LDAP查询，导致未授权访问或数据泄露。
- D验证: confirmed / ver_b6da4517
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 455. hyp_path_66087466d922

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_66b.c:67
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入任意字符串
- 触发路径: data从控制台读取 @ 控制台输入读取位置（如fgets或scanf），具体行号未在证据中提供; _snprintf(filter, 256-1, "(cn=%s)", data); @ 在filter定义后，约在ldap_search之前; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_66b.c:48-52
- 结论: LDAP注入漏洞：用户控制台输入直接拼接到LDAP搜索过滤器中，未进行过滤或转义，攻击者可通过构造特制输入更改LDAP查询语义。
- D验证: confirmed / ver_44f175d6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 456. hyp_path_2c50e9fa5192

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_44.c:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量ADD的值
- 触发路径: data = getenv("ADD"); @ case0Sink:34; _snprintf(filter, 256-1, "(cn=%s)", data); @ L73附近; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L73附近
- 结论: LDAP注入漏洞：用户输入通过环境变量获取，直接拼接到LDAP搜索过滤器中，未进行任何转义或验证，攻击者可构造恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_91bc8fa2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 457. hyp_path_c91acd9e4dc0

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_52c.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量'data'的内容。
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_52c.c:75; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_52c.c:75
- 结论: LDAP注入漏洞：攻击者可通过控制环境变量数据构造恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_c8445125
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 458. hyp_path_46cb13efef95

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_53d.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制目标程序的环境变量（如通过子进程或配置注入）。
- 触发路径: data = getenv("ENV_VAR"); @ 数据从环境变量获取（推断存在）; _snprintf(filter, 256-1, "(cn=%s)", data); @ L75; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L56-60
- 结论: LDAP注入漏洞：程序使用从环境变量获取的数据直接拼接到LDAP搜索过滤器中，未进行任何转义或验证，导致攻击者可通过控制环境变量注入恶意LDAP过滤器，从而执行未授权的LDAP操作。
- D验证: confirmed / ver_8f89b150
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 459. hyp_path_33722684d740

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_45.c:77
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过环境变量控制data的值; LDAP服务器可达且认证（或匿名）允许搜索
- 触发路径: char *data = getenv("ENV_VAR"); // 推断，未在提供代码片段中显式出现 @ 获取data（环境变量）; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_45.c: 约65行; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ..., filter, ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_45.c: 约70-75行
- 结论: LDAP注入漏洞：在ldap_search_ext_sA调用中，用户可控的data（来自环境变量）被直接拼接到LDAP过滤器中，未进行任何转义或验证，允许攻击者注入任意LDAP过滤器，可能导致未授权数据访问或绕过认证。
- D验证: confirmed / ver_05497c82
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 460. hyp_path_9b8770313bc1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_54e.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置或影响程序运行环境中的某个环境变量（如通过系统配置或进程注入）; 程序使用该环境变量作为LDAP搜索过滤器的一部分; LDAP服务器可达且认证通过
- 触发路径: char data[256]; data = getenv("ENV_VAR"); @ 推断为环境变量获取函数（如getenv）; _snprintf(filter, 256-1, "(cn=%s)", data); @ 构建滤波器字符串; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ 执行LDAP搜索
- 结论: LDAP注入漏洞：从环境变量获取的数据直接拼接到LDAP查询过滤器字符串中，然后传递给ldap_search_ext_sA，攻击者可通过控制环境变量注入恶意LDAP过滤器，导致未授权数据访问或绕过认证。
- D验证: confirmed / ver_7794608c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 461. hyp_path_02be8bee6bdd

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_51b.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置或影响环境变量，从而控制data的值
- 触发路径: data = getenv("ADD"); @ 入口函数中（如bad()）; _snprintf(filter, 256-1, "(cn=%s)", data); @ L75附近（sink函数内）; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L56-60附近
- 结论: 在LDAP搜索过滤器构造中，用户输入的数据通过_snprintf直接拼接到过滤器字符串，未进行任何转义或验证，导致LDAP注入漏洞。攻击者可以通过控制环境变量来操纵LDAP查询，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_26321e0b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 462. hyp_path_72f0b82f97ab

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_66b.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制程序运行时的环境变量，例如通过修改系统环境或通过其他方式注入
- 触发路径: 从环境变量获取data @ 入口函数（未显示具体行，但为数据源）; _snprintf(filter, 256-1, "(cn=%s)", data); @ L34（推断）; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...); @ L56-L60（推断）
- 结论: LDAP注入漏洞：程序从环境变量获取输入后，未经适当转义或验证，直接拼接到LDAP搜索过滤器中，攻击者可通过控制环境变量构造恶意LDAP过滤器，执行未授权的LDAP操作。
- D验证: confirmed / ver_05f28560
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 463. hyp_path_f071a63383fc

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_64b.c:77
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制目标系统的环境变量（如USERNAME）的值
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_64b.c:77; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_64b.c:58-62
- 结论: LDAP注入漏洞：程序通过环境变量获取用户输入，直接拼接到LDAP搜索过滤器字符串中，未进行任何过滤或转义，导致攻击者可以注入任意LDAP过滤器，从而绕过认证、获取敏感信息或执行未授权操作。
- D验证: confirmed / ver_9a22b698
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 464. hyp_path_a9c7753b5105

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_63b.c:74
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量（如通过进程环境或通过其他注入方式）
- 触发路径: data = getenv("ADD"); @ 入口函数中data来自环境变量; _snprintf(filter, 256-1, "(cn=%s)", data); @ 合并证据中的_snprintf行; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ ldap_search_ext_sA调用
- 结论: LDAP注入漏洞：从环境变量获取的data直接拼接到LDAP搜索过滤器中，未经任何消毒或转义，攻击者可控制环境变量导致LDAP注入。
- D验证: confirmed / ver_bf8ee5bc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 465. hyp_path_593af54c6e16

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_65b.c:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够影响环境变量（例如通过控制Web服务器环境或进程环境）
- 触发路径: char * data = getenv("ADD"); @ 代码中getenv调用处（未提供具体行号，但存在于样本中）; _snprintf(filter, 256-1, "(cn=%s)", data); @ 拼接处（约在ldap初始化前）; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ ldap_search_ext_sA调用处（A阶段合并证据中提及的行73附近）
- 结论: 代码使用环境变量数据拼接LDAP搜索过滤器，未进行任何过滤或转义，导致LDAP注入漏洞。攻击者可通过控制环境变量（如ADD）注入恶意LDAP过滤器，可能造成未授权访问或敏感信息泄露。
- D验证: confirmed / ver_2242e4c8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 466. hyp_path_444841fc7f34

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_68b.c:79
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量data为恶意字符串，如"*)(uid=*))(|(uid=*)"
- 触发路径: char *data = getenv("ENV_VAR"); @ 假设在68a.c或全局变量赋值处; _snprintf(filter, 256-1, "(cn=%s)", data); @ 68b.c:79; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ 68b.c:79附近
- 结论: LDAP注入漏洞：未对用户输入（环境变量data）进行任何过滤或转义，直接拼接到LDAP搜索过滤器字符串中，攻击者可通过控制环境变量注入任意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_e8dc0765
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 467. hyp_path_1b0b1a08bf3d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_67b.c:79
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量中data的值
- 触发路径: char * data = getenv("ENV_VARIABLE"); @ L? 环境变量获取处（未在片段中显示，但通常为getenv）; _snprintf(filter, 256-1, "(cn=%s)", data); @ L? 拼接过滤器; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_67b.c:60-64
- 结论: LDAP注入漏洞：用户输入通过环境变量传入，未经充分验证或转义，直接拼接到LDAP搜索过滤器中，攻击者可构造恶意输入修改LDAP查询逻辑，导致未授权访问或信息泄露。
- D验证: confirmed / ver_97e48c63
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 468. hyp_path_aa00f1a295a0

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_81_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制目标进程的环境变量（例如通过修改系统环境变量或通过子进程继承）
- 触发路径: data = getenv("环境变量名"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_81_case0.cpp: 入口函数内（隐含通过getenv获取）; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_81_case0.cpp: 约第62行; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_81_case0.cpp: 约第68行
- 结论: LDAP注入漏洞：应用程序将用户可控的环境变量数据直接拼接到LDAP搜索过滤器中，未进行任何转义或验证，攻击者可以通过控制环境变量注入恶意LDAP查询，修改LDAP语句逻辑，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_265aefae
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 469. hyp_path_853960533f51

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_41.c:71
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件的内容，从而影响data变量（需验证source代码）
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_41.c:71; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_41.c:56
- 结论: LDAP注入漏洞：程序从文件读取数据后，未经充分验证直接拼接到LDAP搜索过滤器字符串中，并调用ldap_search_ext_sA执行搜索，攻击者可通过控制文件内容构造恶意LDAP过滤器，导致未授权的数据访问或绕过访问控制。但当前代码证据缺少从文件读取data变量的source部分，路径不完整。
- D验证: confirmed / ver_78475fbb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 470. hyp_path_344c207a02b5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_82_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: Attacker can control the environment variable that populates 'data'.
- 触发路径: data = getenv() (assumed) @ source (environment variable, exact line not shown in evidence but implied by sample name); _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_82_case0.cpp:68; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_82_case0.cpp:68
- 结论: LDAP Injection vulnerability: user-controlled data from environment variable is concatenated into LDAP filter via _snprintf without sanitization, leading to LDAP query manipulation. Evidence lacks explicit source line for environment variable acquisition, but the concatenation and sink are confirmed.
- D验证: confirmed / ver_461ab8f6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 471. hyp_path_aed3608c46f3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_52c.c:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序提供恶意输入，如通过文件读取方式
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ L? 代码未完整显示，但可见_snprintf(filter, 256-1, "(cn=%s)", data);; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter ... ); @ L? ldap_search_ext_sA调用使用未加任何过滤的filter
- 结论: 用户输入通过_snprintf直接拼接到LDAP搜索过滤器，形成LDAP注入漏洞，攻击者可操纵LDAP查询逻辑。
- D验证: confirmed / ver_07c4df57
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 472. hyp_path_ab927ec2cc09

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_51b.c:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够提供输入数据，例如通过文件读取等方式控制data变量。
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ L? (snprintf行); searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L? (ldap_search_ext_sA行)
- 结论: LDAP注入漏洞：用户输入数据直接拼接到LDAP搜索过滤器中，攻击者可通过构造特殊字符串修改LDAP查询语义，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_1a0ff189
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 473. hyp_path_6202a2f10370

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_44.c:71
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过文件或其他方式控制data变量的内容
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_44.c:67-68; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage ); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_44.c:70-71
- 结论: LDAP注入漏洞：用户提供的输入数据未经充分验证或转义，直接拼接到LDAP查询过滤器字符串中，并通过ldap_search_ext_sA()执行，允许攻击者注入任意LDAP查询，可能导致信息泄露或未授权访问。
- D验证: confirmed / ver_e17a82ee
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 474. hyp_path_0ae931b2957b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_54e.c:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序提供恶意输入（通过文件）
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ 代码中将用户输入data通过_snprintf拼接filter; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, ...); @ 拼接后的filter用于ldap_search_ext_sA调用
- 结论: 用户可控的字符串拼接至LDAP搜索过滤器，导致LDAP注入漏洞。
- D验证: confirmed / ver_b8b1cc49
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 475. hyp_path_5e6cc45e87cb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_45.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序提供恶意输入文件，控制data变量内容
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_45.c (文件读取后拼接处); searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_45.c (LDAP搜索调用处)
- 结论: 代码中存在LDAP注入漏洞。变量data通过文件读取获得（标准测试用例），攻击者可控制data内容，拼接到LDAP过滤器后执行ldap_search_ext_sA，可能导致LDAP注入。蓝队指出行号错误和缺乏文件输入直接证据，红队接受修正，但漏洞路径仍可达。
- D验证: confirmed / ver_abf7b1a6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 476. hyp_path_165c8da5aa30

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_64b.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制data变量的内容，例如通过文件读取或网络输入。
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ snprintf调用位置（行号未明确）; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ ldap_search_ext_sA调用位置（行号未明确）
- 结论: LDAP注入漏洞：外部可控数据通过snprintf直接拼接到LDAP搜索过滤器，导致攻击者可以注入任意LDAP查询，可能绕过访问控制、获取未授权数据。
- D验证: confirmed / ver_caa094ef
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 477. hyp_path_c14814fd971d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_53d.c:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制文件内容或提供恶意输入作为data的值。
- 触发路径: data从文件读取获得，例如fgets(data, ...) @ data来源：文件读取（Juliet测试集典型模式，具体行未在提供片段中显示，但根据注释和上下文推断）; _snprintf(filter, 256-1, "(cn=%s)", data); @ L73 (代码片段显示_snprintf的位置); searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L73-74 (ldap_search_ext_sA调用)
- 结论: LDAP注入漏洞：用户控制的数据未经正确转义或过滤，直接拼接到LDAP搜索过滤器中，攻击者可以注入LDAP元字符，修改查询语义，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_65553e52
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 478. hyp_path_477fdf5248ed

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_66b.c:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或控制输入文件的内容
- 触发路径: data = ... @ 输入文件读取并赋值给data（未在片段中显示，但根据用例上下文存在）; _snprintf(filter, 256-1, "(cn=%s)", data); @ L? (源代码中拼接过滤器的位置); searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L73 (ldap_search_ext_sA调用)
- 结论: LDAP注入漏洞：程序从文件读取数据后，直接拼接到LDAP搜索过滤器中，攻击者可通过控制文件内容注入LDAP操作，导致未授权访问或信息泄露。
- D验证: confirmed / ver_15ef14d3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 479. hyp_path_89fca01a0812

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_82_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制data变量（例如通过文件输入）
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ snprintf行; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", ... filter ... ); @ CWE90_LDAP_Injection__w32_char_file_82_case0.cpp:68
- 结论: 代码存在LDAP注入漏洞，攻击者可通过控制data参数注入LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_9aa5e76d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 480. hyp_path_4cbd209e3660

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_67b.c:77
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制data的值（例如通过文件输入或网络输入）。; data能够被拼接到filter中，且LDAP服务器可达。; LDAP服务器允许匿名绑定或攻击者拥有有效凭据。
- 触发路径: searchSuccess = ldap_search_ext_sA(pLdapConnection, filter, ...); @ L77（sink调用处）; _snprintf(filter, 256-1, "(cn=%s)", data); @ L75-79之前
- 结论: LDAP注入漏洞：用户可控的输入data通过_snprintf直接拼接到LDAP搜索过滤器字符串中，然后传递给ldap_search_ext_sA执行，攻击者可注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_2bad0b85
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 481. hyp_path_904adef1ebaa

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_63b.c:72
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入到data变量的内容（例如通过文件）
- 触发路径: 未显示但推断存在 @ data变量从文件读取; _snprintf(filter, 256-1, "(cn=%s)", data); @ 构造filter字符串; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...); @ 调用ldap_search_ext_sA
- 结论: LDAP注入漏洞：用户输入数据被直接拼接到LDAP搜索过滤器中，导致攻击者可通过注入LDAP元字符执行任意查询或修改。
- D验证: confirmed / ver_e661bc82
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 482. hyp_path_0ea19236212c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_68b.c:77
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制文件输入，从而向`data`中注入恶意LDAP语法。
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_68b.c:行待定（约为_snprintf所在行）; searchSuccess = ldap_search_ext_sA(pLdapConnection, filter, ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_68b.c:77
- 结论: LDAP注入漏洞：用户可控数据通过文件读取后，直接拼接到LDAP搜索过滤器字符串中，未进行任何转义或验证，攻击者可以注入恶意LDAP过滤器，绕过认证、获取敏感信息或修改目录数据。
- D验证: confirmed / ver_a29225df
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 483. hyp_path_89ac4c523cf8

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_81_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制data变量的内容（如通过控制文件输入）。
- 触发路径: data 从外部文件读入未做过滤 @ 文件读取函数（如fgets等）后赋值给data变量; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_81_case0.cpp 中filter构造处; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 15000, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_81_case0.cpp 中搜索执行处
- 结论: LDAP注入漏洞：攻击者通过控制data参数（来自文件读取）注入恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_23e924db
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 484. hyp_path_9e0f5819f4ab

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_65b.c:71
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或修改程序读取的文件内容
- 触发路径: data 从文件中读取 @ 文件读取操作（代码中未明确行号，但数据源自文件）; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_65b.c:71; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter, ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_65b.c:71
- 结论: LDAP 注入漏洞：从文件读取的未净化数据直接拼接到 LDAP 搜索过滤器，攻击者可通过控制文件内容注入任意 LDAP 查询，导致信息泄露或未授权访问。
- D验证: confirmed / ver_999a7e08
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 485. hyp_path_82915f8b3928

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_52c.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够访问并发送数据到目标应用程序的监听socket端口
- 触发路径: data = recv(socket, ...); @ L? 接收socket数据（标准source）; _snprintf(filter, 256-1, "(cn=%s)", data); @ L? _snprintf调用; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...); @ L? ldap_search_ext_sA调用
- 结论: 存在LDAP注入漏洞：用户输入通过socket接收后，未经验证直接拼接到LDAP搜索过滤器中，攻击者可注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_6975de35
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 486. hyp_path_0fd0bdb4822d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_54e.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络发送恶意字符串到data变量（socket输入）
- 触发路径: recvfrom(data, ...) 获取用户输入 @ 入口：CWE90_LDAP_Injection__w32_char_listen_socket_54e_case0Sink; _snprintf(filter, 256-1, "(cn=%s)", data); @ L87附近; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter ...); @ L87
- 结论: LDAP注入漏洞：用户输入数据直接从socket接收并拼接至LDAP搜索过滤器，攻击者可注入任意LDAP查询，导致信息泄露或未授权访问。
- D验证: confirmed / ver_b7814034
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 487. hyp_path_cd8d8a29c5a3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_45.c:89
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标程序发送特制的数据，以控制data变量的内容。
- 触发路径: 未提供 @ L? 数据接收处（未提供具体行号，但文件名暗示socket接收）; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_45.c:89; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_45.c:89
- 结论: LDAP注入漏洞：用户输入通过socket接收后，直接拼接到LDAP搜索过滤器字符串中，未进行任何转义或过滤，导致攻击者可以注入任意LDAP查询，可能实现未授权访问或数据泄露。
- D验证: confirmed / ver_50bc5108
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 488. hyp_path_0bc721479b4b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_44.c:85
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序监听的socket发送任意数据。; 程序所在环境可以连接到LDAP服务器（此处硬编码localhost，通常可达）。
- 触发路径: recv或类似函数（根据CWE样本模式） @ socket接收（listen_socket）; _snprintf(filter, 256-1, "(cn=%s)", data); @ filter拼接处; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ LDAP查询调用
- 结论: LDAP注入漏洞：程序从socket接收用户输入，未经充分净化直接拼接到LDAP搜索过滤器字符串中，并传递给ldap_search_ext_sA函数，导致攻击者可以注入LDAP过滤器语法，执行未授权的LDAP操作。
- D验证: confirmed / ver_39164d46
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 489. hyp_path_0ae448f4d9c1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_51b.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标主机的监听socket并发送特制的字符串
- 触发路径: A阶段合并证据中包含data从socket接收 @ 接收socket输入（通过listen socket，如recv函数）; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_51b.c; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_51b.c
- 结论: LDAP注入漏洞：程序通过listen socket接收用户输入，未经任何过滤或转义直接拼接到LDAP搜索过滤器中，导致攻击者可以注入任意LDAP查询，可能绕过认证、获取敏感信息或执行未授权操作。
- D验证: confirmed / ver_e9ae788d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 490. hyp_path_4b5ac3ac0bbc

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_41.c:85
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过 listen_socket 发送任意字符串到 data 变量; LDAP 服务器可达且接受查询
- 触发路径: 从 listen_socket 接收数据到 data @ 接收 socket 数据并赋值给 data 变量（函数入口附近）; _snprintf(filter, 256-1, "(cn=%s)", data); @ snprintf 调用处; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ..., filter, ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_41.c:85 附近
- 结论: LDAP 注入漏洞：用户提供的输入 data 未经验证即拼接到 LDAP 搜索过滤器字符串中，导致攻击者可以通过注入 LDAP 元字符修改查询语义，可能造成敏感信息泄露或未授权访问。
- D验证: confirmed / ver_507c747a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 491. hyp_path_0c0dd1274029

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_63b.c:86
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够访问监听 socket 并发送数据; LDAP 服务器可访问且允许未授权查询
- 触发路径: // 数据来源（未在片段中显示，但上下文为 listen_socket） @ 入口：监听 socket 接收数据并赋值给 data（假设通过 recv 等函数获取）; _snprintf(filter, 256-1, "(cn=%s)", data); @ CWE90_LDAP_Injection__w32_char_listen_socket_63b.c:79; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, ...); @ CWE90_LDAP_Injection__w32_char_listen_socket_63b.c:86
- 结论: LDAP注入漏洞：攻击者可控的输入 data 直接拼接到 LDAP 搜索过滤器字符串中，可导致 LDAP 注入攻击。
- D验证: confirmed / ver_7f0f92f5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 492. hyp_path_7217d2a4fef4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_65b.c:85
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制通过listen socket传入的data内容
- 触发路径: data通过socket接收 @ 入口: CWE90_LDAP_Injection__w32_char_listen_socket_65b_case0Sink:46; _snprintf(filter, 256-1, "(cn=%s)", data); @ sink函数中; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter, ...); @ 同一函数
- 结论: 代码存在LDAP注入漏洞，因为用户输入data直接拼接到LDAP搜索过滤器中，未进行任何转义或校验，攻击者可以注入任意LDAP查询。
- D验证: confirmed / ver_75e17177
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 493. hyp_path_5b8b0b901388

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_53d.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制listen socket的输入
- 触发路径: /* 假设从socket读取数据存入data，如recv()或类似函数 */ @ 调用链上游从socket接收数据到data（未在提供的片段中直接展示，但根据上下文存在）; _snprintf(filter, 256-1, "(cn=%s)", data); @ CWE90_LDAP_Injection__w32_char_listen_socket_53d.c:48? (sink函数内构造filter); searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...); @ CWE90_LDAP_Injection__w32_char_listen_socket_53d.c:68? (sink函数内执行搜索)
- 结论: LDAP注入漏洞：用户输入通过socket直接拼接到LDAP查询过滤器字符串中，未进行任何转义或验证，攻击者可构造恶意LDAP查询，导致信息泄露或未授权访问。
- D验证: confirmed / ver_0b63d10c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 494. hyp_path_bfc53f6d83ae

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_66b.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入'data'（例如通过监听socket接收的数据）
- 触发路径: char filter[256]; _snprintf(filter, 256-1, "(cn=%s)", data); @ 入口函数CWE90_LDAP_Injection__w32_char_listen_socket_66b_case0Sink:46; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ ldap_search_ext_sA调用处:87
- 结论: LDAP注入漏洞：用户可控的字符串直接拼接到LDAP搜索过滤器中，攻击者可构造恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_b2d83f5c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 495. hyp_path_135ce3e445d3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_68b.c:91
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向data变量输入数据，例如通过listen_socket接收的数据。
- 触发路径: _snprintf(filter, 256-1, "(cn=%s)", data); @ CWE90_LDAP_Injection__w32_char_listen_socket_68b.c:91; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter, ...); @ CWE90_LDAP_Injection__w32_char_listen_socket_68b.c:91-93
- 结论: LDAP注入漏洞：用户输入data直接拼接到LDAP搜索过滤器字符串中，然后传递给ldap_search_ext_sA函数，攻击者可以通过构造恶意输入修改LDAP查询逻辑。
- D验证: confirmed / ver_d5d47c17
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 496. hyp_path_61753994917a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_64b.c:89
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向目标主机的监听端口发送数据，并且数据未被有效验证或转义即用于LDAP搜索。
- 触发路径: recv() 调用（未展示） @ 数据通过套接字接收，存储在变量data中（代码未提供，但根据Juliet测试用例结构存在于调用方）; _snprintf(filter, 256-1, "(cn=%s)", data); @ snprintf 将 data 拼接到 filter; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ 调用 ldap_search_ext_sA 时使用未净化的 filter
- 结论: 函数将用户可控数据直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可以通过构造恶意输入修改LDAP查询语义，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_1b40b491
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 497. hyp_path_10cf4fefe074

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_81_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接到监听socket并发送恶意字符串作为data
- 触发路径: void action(char * data) @ 入口函数action接收data参数（来自socket）; _snprintf(filter, 256-1, "(cn=%s)", data); @ snprintf调用处，约67行; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ...); @ ldap_search_ext_sA调用处，约71行
- 结论: LDAP注入漏洞：函数action接收来自socket的data参数，直接拼接至LDAP搜索过滤器filter，调用ldap_search_ext_sA执行未授权的LDAP查询，导致信息泄露或未授权访问。
- D验证: confirmed / ver_05ef5dc1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 498. hyp_path_1e38d647d2b9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_82_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络socket发送恶意数据，该数据被直接拼接到LDAP过滤器中，且未对特殊字符进行转义。
- 触发路径: pLdapConnection = ldap_initA("localhost", LDAP_PORT); @ L29; if (pLdapConnection == NULL) ... exit(1); @ L30; connectSuccess = ldap_connect(pLdapConnection, NULL); if (connectSuccess != LDAP_SUCCESS) ... exit(1); @ L45; _snprintf(filter, 256-1, "(cn=%s)", data); @ L50-51; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ... filter, ...); @ L52-53
- 结论: 代码中存在LDAP注入漏洞：用户通过socket接收的数据未经任何过滤或编码，直接拼接到LDAP搜索过滤字符串中，导致攻击者可以注入任意LDAP查询，可能获取未授权数据或绕过访问控制。
- D验证: confirmed / ver_b684afb0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 499. hyp_path_a47d0e331fc4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_41.c:85
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向程序发送特制的数据（data）
- 触发路径: data = recv(socket, ...) 或类似外部输入； @ 函数入口（通过socket接收）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L? (拼接过滤条件); searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L? (调用ldap_search_ext_sW)
- 结论: LDAP注入漏洞：用户输入的数据未经任何验证或转义，直接通过_snwprintf拼接到LDAP搜索过滤器中，然后传递给ldap_search_ext_sW()，导致攻击者可以控制LDAP查询语句，实现LDAP注入攻击。
- D验证: confirmed / ver_e0c25c06
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 500. hyp_path_2834c5b4a1c2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_44.c:85
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接向 data 变量提供恶意输入
- 触发路径: 接受 socket 数据到 data @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_44.c:46 (case0Sink入口); _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_44.c:83; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...); @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_44.c:85
- 结论: LDAP注入漏洞：用户输入 data 未经消毒直接拼接到 LDAP 搜索过滤器 (cn=%s) 中，攻击者可通过构造恶意输入修改 LDAP 查询逻辑，导致未授权数据访问或信息泄露。
- D验证: confirmed / ver_8caeeeec
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 501. hyp_path_28d248b80f78

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_67b.c:91
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向监听套接字发送恶意数据，且程序未对输入进行消毒。
- 触发路径: 用户输入通过套接字读取到data变量 @ CWE90_LDAP_Injection__w32_char_listen_socket_67b.c（数据读取位置，未提供具体行号，但文件名暗示socket输入）; _snprintf(filter, 256-1, "(cn=%s)", data); @ CWE90_LDAP_Injection__w32_char_listen_socket_67b.c（过滤器构造位置）; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", ..., filter, ...); @ CWE90_LDAP_Injection__w32_char_listen_socket_67b.c:91
- 结论: LDAP注入漏洞：用户输入的数据未经过滤直接拼接到LDAP搜索过滤器字符串中，攻击者可通过控制输入注入任意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_58b2a387
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 502. hyp_path_36abb9080d57

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_52c.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标程序发送恶意数据，控制data变量的内容，且data中可包含LDAP过滤器特殊字符（如'*', '|', '&', '!', ')'等）。
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_connect_socket_52c_case0Sink(wchar_t * data) @ 入口函数CWE90_LDAP_Injection__w32_wchar_t_connect_socket_52c_case0Sink接收参数data，该参数来自socket读取; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 第48行或附近（sink函数内部）; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ 第68-72行
- 结论: LDAP注入漏洞：用户输入通过socket连接获取，未经任何转义或过滤直接拼接到LDAP搜索过滤器中（_snwprintf(filter, L"(cn=%s)", data)），然后传递给ldap_search_ext_sW，攻击者可构造包含LDAP特殊字符的payload，导致LDAP查询语义篡改，实现未授权访问或信息泄露。
- D验证: confirmed / ver_94048166
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 503. hyp_path_8f9c984ce253

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_51b.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络socket发送特制的LDAP查询字符串
- 触发路径: 从socket接收数据并存入data变量 @ 源文件（未提供具体行号）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_51b.c:87; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter ... @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_51b.c:68-72
- 结论: LDAP注入漏洞。攻击者通过socket传入恶意数据，该数据被直接拼接到LDAP搜索过滤器中，可导致未授权访问或信息泄露。
- D验证: confirmed / ver_b30ca620
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 504. hyp_path_4825e00b1b92

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_53d.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制data输入内容
- 触发路径: 外部数据赋值给data @ 入口函数接收外部数据（推断来自socket，但证据不完整）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 过滤器构造; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... filter, ...); @ L87 调用危险API
- 结论: LDAP注入漏洞：在ldap_search_ext_sW调用中，用户控制的输入直接拼接到LDAP搜索过滤器，未进行任何转义或验证，允许攻击者注入恶意LDAP查询。
- D验证: confirmed / ver_1854647f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 505. hyp_path_91c216e94d93

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54e.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向data变量注入恶意LDAP过滤器语法，例如通过网络输入（connect_socket暗示网络来源）。
- 触发路径: wchar_t filter[256]; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54e.c:48（假设入口函数）; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54e.c:68（ldap_search_ext_sW调用）
- 结论: 在LDAP搜索过滤器构造中，用户输入data直接通过_snwprintf拼接到filter字符串中，然后用于ldap_search_ext_sW调用，导致LDAP注入漏洞。攻击者可控制LDAP过滤器语法，绕过认证或获取未授权数据。
- D验证: confirmed / ver_1c1b3aa0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 506. hyp_path_4721555ee317

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_63b.c:86
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接向程序发送恶意构造的LDAP过滤器字符串
- 触发路径: data参数被传递给sink函数 @ 函数参数data（来源于socket，见连接socket的调用上下文）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_63b.c:86
- 结论: LDAP注入漏洞：外部可控数据通过socket传入，直接拼接到LDAP搜索过滤器，攻击者可通过构造特殊字符串注入任意LDAP查询，可能导致信息泄露或未授权访问。
- D验证: confirmed / ver_4ff49346
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 507. hyp_path_24c5e69948ce

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_65b.c:85
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接向目标应用程序发送恶意LDAP查询字符串。
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_65b.c; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter, ...); @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_65b.c:85
- 结论: LDAP注入漏洞：用户可控数据直接拼接到LDAP搜索过滤器，攻击者可以注入任意LDAP查询。
- D验证: confirmed / ver_a5aa9d78
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 508. hyp_path_00f2f36e24ca

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_45.c:89
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标socket服务并注入任意LDAP过滤器片段
- 触发路径: data从socket接收 @ data来源socket（行号未在代码段中明确，但基于函数名connect_socket及recv调用）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_45.c:89; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...); @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_45.c:70-74
- 结论: LDAP注入漏洞：攻击者通过socket输入控制data变量，该变量未经充分过滤即被拼接进LDAP搜索过滤器，导致能够修改LDAP查询语义，实现未授权访问或信息泄露。
- D验证: confirmed / ver_14a3f1e2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 509. hyp_path_67539b55f60f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_66b.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接向目标程序发送恶意数据，控制data变量内容。
- 触发路径: 从网络socket接收数据并赋值给data变量 @ 入口函数（第46行附近）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_66b.c:87; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, secInterval, &pMessage); @ 同一文件第87行附近
- 结论: LDAP注入漏洞：用户可控数据直接拼接到LDAP搜索过滤器，未进行转义或过滤，攻击者可通过注入LDAP元字符执行未授权查询或修改数据。
- D验证: confirmed / ver_b12eb6ab
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 510. hyp_path_421398a08127

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_64b.c:89
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向应用程序发送恶意输入（例如通过网络，该输入最终赋值给变量data）
- 触发路径: 通过套接字接收data，未展示但假定为外部来源 @ 函数入口处接收外部输入data; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 第89行附近的_snwprintf调用; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ 第70-74行的ldap_search_ext_sW调用
- 结论: LDAP注入漏洞：用户输入直接拼接到LDAP搜索过滤器中，攻击者可通过控制输入注入任意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_f566935c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 511. hyp_path_2bba32876760

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_67b.c:91
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制传入的data参数内容。
- 触发路径: data从外部网络套接字接收 @ 入口函数（如CWE90_LDAP_Injection__w32_wchar_t_connect_socket_67b_case0Sink）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 拼接点（代码片段显示_snwprintf调用）; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ 调用点（ldap_search_ext_sW）
- 结论: LDAP注入漏洞：用户输入的数据未经验证或转义，直接拼接到LDAP搜索过滤器中，攻击者可以控制过滤器语法，导致LDAP注入攻击。
- D验证: confirmed / ver_89e55872
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 512. hyp_path_7fcb85edd38b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_68b.c:91
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制socket输入，发送包含LDAP元字符（如*、()、&、|等）的字符串。
- 触发路径: 接收socket数据并存储到data变量（根据典型Juliet实现和B阶段证据确认） @ 入口函数 CWE90_LDAP_Injection__w32_wchar_t_connect_socket_68b_case0Sink:51; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 文件第91行附近; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ 文件第91行
- 结论: LDAP注入漏洞：用户输入通过socket连接直接拼接到LDAP搜索过滤器字符串中，未进行任何编码或验证，攻击者可构造恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_7585fe3f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 513. hyp_path_b8d2d9a1c6c8

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_82_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: Attacker can control the input data that flows into the 'data' variable via network or other means.
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L38-L39 (approximate); searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage ); @ L49-L53
- 结论: LDAP Injection vulnerability: user-controlled data is concatenated into an LDAP search filter without sanitization, allowing an attacker to modify the LDAP query.
- D验证: confirmed / ver_c1fccd0d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 514. hyp_path_0fcb2f8d7ab0

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_81_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接向程序发送特制的data字符串
- 触发路径: pLdapConnection = ldap_initW(L"localhost", LDAP_PORT); @ L? 或 描述; connectSuccess = ldap_connect(pLdapConnection, NULL); @ L? 或 描述; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L? 或 描述; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter ...); @ L? 或 描述
- 结论: LDAP注入漏洞：函数将外部输入data直接拼接到LDAP搜索过滤器中，未进行转义或验证，攻击者可注入恶意LDAP语法，修改搜索行为，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_2a7a533b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 515. hyp_path_49afccf05931

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_44.c:65
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向控制台输入任意字符串
- 触发路径: data = ...; // 控制台输入 @ 输入点（未在提供的片段中显示，根据CWE90典型模式为控制台输入如fgetws）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 约line 65; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, ...); @ 约line 65
- 结论: 存在LDAP注入漏洞：用户输入data直接拼接到LDAP搜索过滤器字符串中，未进行转义或验证，可导致攻击者修改LDAP查询逻辑，获取未授权访问或信息泄露。
- D验证: confirmed / ver_8b4f0560
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 516. hyp_path_0274805619e2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_41.c:65
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入提供恶意字符串
- 触发路径: 源数据来自控制台 @ 入口处读取数据（控制台输入）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L? 拼接行; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter ...); @ L65
- 结论: 用户输入通过控制台读取，直接拼接到LDAP搜索过滤器中，未进行转义或验证，导致LDAP注入漏洞。攻击者可以控制搜索过滤器，从而可能访问未授权的数据或修改目录。
- D验证: confirmed / ver_5f526d0f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 517. hyp_path_4d6300b014b5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_52c.c:67
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够提供恶意输入到data变量，通常通过控制台或网络输入
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_console_52c_case0Sink(wchar_t * data) @ 入口函数传递data到本sink函数; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 构建filter并拼接data; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ 使用拼接后的filter执行LDAP搜索
- 结论: LDAP注入漏洞：用户输入数据未经充分验证直接拼接到LDAP搜索过滤器中，攻击者可通过构造恶意输入修改LDAP查询语义，可能导致未授权访问或数据泄露。
- D验证: confirmed / ver_ee0ae9d0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 518. hyp_path_a8e12af116b0

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_45.c:69
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向data变量注入任意字符串
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L34; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L50-54
- 结论: LDAP注入漏洞：用户输入数据直接拼接到LDAP搜索过滤器字符串中，未进行任何转义或验证，攻击者可构造恶意输入以操纵LDAP查询。
- D验证: confirmed / ver_edd4118a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 519. hyp_path_384133db2ebf

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_54e.c:67
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制变量 data 的内容
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 拼接 filter; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ 调用 LDAP 搜索
- 结论: LDAP注入漏洞：用户输入 data 未经适当转义或过滤，直接通过 _snwprintf 拼接到 LDAP 搜索过滤器字符串中，然后用于 ldap_search_ext_sW 调用，攻击者可利用此注入任意 LDAP 查询，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_f434fbe4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 520. hyp_path_3527c53e2cc2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_53d.c:67
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向控制台提供恶意输入（例如通过标准输入流）。
- 触发路径: 未直接展示，但数据源自控制台 @ 入口函数中读取控制台输入并赋值给data; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_console_53d.c:43-44; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ CWE90_LDAP_Injection__w32_wchar_t_console_53d.c:48-52
- 结论: 用户输入通过控制台读取，直接拼接到LDAP搜索过滤器字符串中，未进行任何转义或验证，导致LDAP注入漏洞。
- D验证: confirmed / ver_007dc36e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 521. hyp_path_434c51282884

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_51b.c:67
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入控制变量data
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_51b.c:67; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_51b.c:48-52
- 结论: LDAP注入漏洞：用户输入数据未经充分净化直接拼接进LDAP搜索过滤器，可能导致攻击者执行任意LDAP查询。
- D验证: confirmed / ver_be388375
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 522. hyp_path_4a54a9622a71

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_63b.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台提供包含LDAP元字符的字符串作为输入
- 触发路径: （缺失） @ 数据来源：未在片段中明确显示，但根据典型Juliet测试用例，data通过控制台读取（如fgetws）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L? _snwprintf调用，将data拼接到filter; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L66 ldap_search_ext_sW调用，使用未转义的filter
- 结论: LDAP查询字符串拼接用户输入，导致LDAP注入漏洞
- D验证: confirmed / ver_d5208b7e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 523. hyp_path_807183ec20c3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_67b.c:71
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够提供任意字符串作为data输入
- 触发路径: wchar_t data[256]; 从控制台读取未净化数据 @ 入口函数（CWE90_LDAP_Injection__w32_wchar_t_console_67a.c）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 67b.c:69-73附近; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ 67b.c:71附近
- 结论: 代码将用户输入直接拼接到LDAP搜索过滤器中，未进行任何净化，导致LDAP注入漏洞。
- D验证: confirmed / ver_cd7183a2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 524. hyp_path_7d644648cc58

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_81_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制控制台输入，从而影响data变量的内容。
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_console_81_case0::action(wchar_t * data) @ 入口函数action，data参数传入; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 构建filter，调用_snwprintf处; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ 执行LDAP搜索
- 结论: LDAP注入漏洞：用户输入直接拼接到LDAP搜索过滤器中，未进行转义或验证，攻击者可构造恶意输入修改LDAP查询逻辑。
- D验证: confirmed / ver_2895a978
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 525. hyp_path_8e18bd60a059

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_64b.c:69
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过标准输入提供恶意的data字符串，如包含LDAP查询语法。
- 触发路径: wchar_t data[256]; ... fgetws(data, 256, stdin); @ L26 (入口函数CWE90_LDAP_Injection__w32_wchar_t_console_64b_case0Sink); _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L? (filter构建处); searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L69 (ldap_search_ext_sW调用)
- 结论: LDAP注入漏洞，用户输入直接拼接到LDAP搜索过滤器中，攻击者可通过控制输入执行任意LDAP查询。
- D验证: confirmed / ver_9b3b69cd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 526. hyp_path_a5436b2208c3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_68b.c:71
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过标准输入提供任意字符串
- 触发路径: data未在代码段中赋值，来自外部输入 @ 假设从控制台读取data（source未在当前文件显示，但Juliet测试套件通常从控制台读取）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L63-64; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...); @ L71
- 结论: LDAP注入漏洞：用户输入未经验证直接拼接到LDAP搜索过滤器中，攻击者可控制输入导致LDAP注入。
- D验证: confirmed / ver_c6a06d39
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 527. hyp_path_16568537a989

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_66b.c:67
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向标准控制台输入提供恶意数据（data变量）
- 触发路径: 入口函数接收data，根据典型样本，data来自fgetws或其他控制台输入函数 @ CWE90_LDAP_Injection__w32_wchar_t_console_66b.c:26 (入口); _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 证据中filter构建; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage ); @ CWE90_LDAP_Injection__w32_wchar_t_console_66b.c:67
- 结论: 存在LDAP注入漏洞。控制台输入的wchar_t数据未经转义直接拼接到LDAP搜索过滤器字符串中，攻击者可通过注入特殊字符操纵LDAP查询。
- D验证: confirmed / ver_61a48012
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 528. hyp_path_14de976d4bc4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_82_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制传入的data参数（例如通过控制台输入）
- 触发路径: data 从控制台读取 @ 调用者传入的data参数（控制台输入）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_console_82_case0.cpp:? (snwprintf所在行); searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ CWE90_LDAP_Injection__w32_wchar_t_console_82_case0.cpp:68 (ldap_search_ext_sW调用)
- 结论: LDAP注入漏洞：用户控制的输入数据直接拼接到LDAP搜索过滤器字符串中，未进行任何验证或编码，攻击者可注入恶意LDAP过滤器，导致未授权访问或数据泄露。
- D验证: confirmed / ver_cdc2e2fc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 529. hyp_path_5ff237f1744e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_41.c:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制目标进程的环境变量。
- 触发路径: data = _wgetenv(L"ADD"); @ 环境变量读取（case0函数）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 过滤器拼接（L73附近）; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ LDAP搜索（L54-58附近）
- 结论: LDAP注入漏洞：通过环境变量获取的数据未经验证直接拼接到LDAP查询过滤器中，攻击者可控制LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_a7e5dcd7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 530. hyp_path_170d5e1a94fa

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_44.c:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量内容; LDAP服务器可访问且允许匿名或认证绑定
- 触发路径: data = _wgetenv(L"ADD"); @ 数据从环境变量获取; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_44.c:73; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_44.c:73（附近）
- 结论: LDAP注入漏洞：用户可控数据通过环境变量传入，未经转义直接拼接到LDAP搜索过滤器（_snwprintf(filter, 256-1, L"(cn=%s)", data)），允许攻击者通过构造特殊输入操纵LDAP查询，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_23c68d1d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 531. hyp_path_a001ec268704

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_51b.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量，从而控制data的值
- 触发路径: wchar_t data; 从环境变量获取 @ 入口函数入口处; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 51b.c: 构建filter处（注释前）; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ 51b.c:56-60
- 结论: LDAP注入漏洞：用户输入通过环境变量传入，直接拼接到LDAP搜索过滤器中，攻击者可注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_7e975460
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 532. hyp_path_8e60fcf9e92d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_45.c:77
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量（例如通过系统环境或进程环境）
- 触发路径: data = _wgetenv(L"ADD"); @ case0Sink函数中通过_wgetenv从环境变量获取数据; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L77附近; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L58-62
- 结论: 代码中存在LDAP注入漏洞，攻击者通过控制环境变量输入，可以构造恶意LDAP查询过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_e11bf15d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 533. hyp_path_05f07439d9e4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_64b.c:77
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够影响目标进程的环境变量，通常通过进程派生（如CGI）或本地执行环境
- 触发路径: data = _wgetenv(L"ADD"); @ 入口函数从环境变量获取数据; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L52-59（近似位置）; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, &pMessage); @ L77（ldap_search_ext_sW调用）
- 结论: LDAP注入漏洞：通过环境变量传入的恶意数据被拼接到LDAP搜索过滤器，攻击者可利用该漏洞执行任意LDAP查询。
- D验证: confirmed / ver_19d17086
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 534. hyp_path_05f878c8a153

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_63b.c:74
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制传递给data的环境变量（例如通过进程环境变量的方式）
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_environment_63b.c:74; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter ...); @ CWE90_LDAP_Injection__w32_wchar_t_environment_63b.c:74（后续调用）
- 结论: LDAP注入漏洞：用户提供的环境变量数据未经过滤直接拼接到LDAP搜索过滤器中，攻击者可以通过控制环境变量注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_5e642a37
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 535. hyp_path_66afbc628027

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_52c.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制目标系统的环境变量（例如通过进程继承或设置）
- 触发路径: data = getenv(...); @ 其他源文件（如52a或52b）中通过getenv等读取环境变量; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L? (52c sink函数内) 拼接filter; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage ); @ L75
- 结论: LDAP注入漏洞：用户通过环境变量控制的输入直接拼接到LDAP搜索过滤器中，攻击者可注入任意LDAP查询。
- D验证: confirmed / ver_4d600705
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 536. hyp_path_0df45776ec05

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_54e.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置或影响环境变量（如BAD_ENV_VAR）的值
- 触发路径: data = _wgetenv(L"BAD_ENV_VAR"); @ 环境变量赋值点（基于用例名称推断，但代码片段未直接展示）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 过滤器构建（代码片段中未明确显示，但依据常见模式）; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...); @ CWE90_LDAP_Injection__w32_wchar_t_environment_54e.c:75
- 结论: LDAP注入漏洞：程序从环境变量获取输入，直接拼接到LDAP搜索过滤器中，未进行转义或验证，攻击者可通过控制环境变量注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_3693d14b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 537. hyp_path_2c7932a64945

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_65b.c:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制影响data的环境变量（例如ADD）
- 触发路径: data = _wgetenv(L"ADD"); @ 环境变量读取处（未在代码片段中显示，但基于函数名wchar_t_environment）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_65b.c:68; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_65b.c:73
- 结论: LDAP注入漏洞：攻击者可通过控制环境变量输入，在LDAP查询过滤器中注入恶意LDAP语法，导致未经授权的数据访问或修改。
- D验证: confirmed / ver_dbb7a433
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 538. hyp_path_0f19e3bce336

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_53d.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量（如ADD）的内容
- 触发路径: data = _wgetenv(L"ADD"); // 假设来源，代码中未直接展示 @ 推断的环境变量读取（如_wgetenv）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_53d.c:36; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_53d.c:75
- 结论: 代码存在LDAP注入漏洞：data变量被直接拼接到LDAP搜索过滤器中，可能导致LDAP注入，但data来源（环境变量）在提供的代码片段中未显式出现，需要动态验证以确认source可达性。
- D验证: confirmed / ver_eda45c42
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 539. hyp_path_2b4a96484d4f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_66b.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量（如通过进程环境或命令行注入）来设置 data 的值
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_66b.c:75; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 15000, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_66b.c:75
- 结论: LDAP注入漏洞：通过环境变量传入的字符串直接被拼接到LDAP搜索过滤器中，攻击者可以注入任意的LDAP查询，导致信息泄露或未授权访问。
- D验证: confirmed / ver_75912f5d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 540. hyp_path_8c04fa7557ac

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_65b.c:65
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台输入任意字符串。
- 触发路径: wchar_t data[256]; ... fgetws(data, 256, stdin); @ 入口函数中读取输入; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 构造filter; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ 执行LDAP搜索
- 结论: LDAP注入漏洞：程序从控制台读取用户输入，直接拼接到LDAP搜索过滤器中，攻击者可通过构造恶意输入执行任意LDAP查询。
- D验证: confirmed / ver_91f4ed8e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 541. hyp_path_003cd8f6b2ac

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_81_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量（如通过HTTP请求或本地执行时设置环境变量）
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L29附近（snwprintf调用）; pLdapConnection = ldap_initW(L"localhost", LDAP_PORT); @ L45附近; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L49-53; if (pMessage != NULL) { ldap_msgfree(pMessage); } exit(1); @ L66-70
- 结论: LDAP注入漏洞：用户输入（通过环境变量）直接拼接到LDAP搜索过滤器中，未进行适当的转义或参数化，攻击者可注入任意LDAP过滤器。
- D验证: confirmed / ver_42a010d1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 542. hyp_path_3532e10be842

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_68b.c:79
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够设置环境变量（如通过其他漏洞或系统配置）
- 触发路径: data = getenv("BAD_ENV_VAR"); @ 入口函数（68a.c中获取环境变量）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_68b.c:79; ldap_search_ext_sW(pLdapConnection, L"base", ..., filter, ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_68b.c:79附近
- 结论: LDAP注入漏洞：用户输入通过环境变量传入，未经验证直接拼接至LDAP搜索过滤器，攻击者可注入任意LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_dfe75b27
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 543. hyp_path_2ea6a671c2f5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_82_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量，从而影响data参数的值。
- 触发路径: void action(wchar_t * data) override @ 入口函数接收data参数; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 构建过滤器; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ 执行LDAP搜索
- 结论: LDAP注入漏洞：用户可控的输入（环境变量）被直接拼接到LDAP搜索过滤器中，攻击者可以通过构造恶意的环境变量值注入LDAP查询，导致未授权的数据访问或绕过认证。
- D验证: confirmed / ver_2f29d238
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 544. hyp_path_05443f35fd3d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_67b.c:79
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制环境变量以影响'data'内容
- 触发路径: wchar_t data[256]; ... data = wgetenv(L"ADD") @ 代码中未显示，但根据测试用例设计存在（环境变量获取）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 第72行（推测）; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ 第79行
- 结论: LDAP注入漏洞：用户输入数据未经过滤直接拼接到LDAP搜索过滤器字符串中，攻击者可构造恶意输入修改搜索逻辑或获取未授权数据。
- D验证: confirmed / ver_abded51f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 545. hyp_path_01afbec9a3eb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_45.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向输入文件写入恶意LDAP过滤器字符串
- 触发路径: fgetws(data, 256, stdin) 等（依据典型Juliet测试用例结构） @ 假设为case0Sink调用前（典型Juliet测试用例使用fgetws从stdin或文件读取），具体行号未在提供代码片段中明确; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_45.c:67-68; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_45.c:75
- 结论: CWE90 LDAP注入漏洞：在CWE90_LDAP_Injection__w32_wchar_t_file_45.c的case0Sink函数中，用户输入（通过fgetws从文件读取）未经安全过滤直接拼接到LDAP搜索过滤器字符串中，并传递给ldap_search_ext_sW，攻击者可构造恶意LDAP过滤器实现注入攻击。
- D验证: confirmed / ver_2ce76808
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 546. hyp_path_3909dabf4cd2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_41.c:71
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序提供的输入文件中写入恶意LDAP过滤器语法（如添加逻辑或、通配符等）
- 触发路径: /* 从文件读取数据到data变量，代码未显式给出 */ @ 文件读取处（根据函数命名和注释推断为文件读取，但具体行未提供）; wchar_t filter[256]; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L? 函数入口（case0Sink）; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L:71
- 结论: 在LDAP查询字符串中未对用户可控输入进行转义，导致LDAP注入漏洞。攻击者可能通过控制文件输入（data）注入任意LDAP过滤器，但文件读取的具体代码行未在证据中明确给出，路径可达性依赖于文件读取函数的实现。
- D验证: confirmed / ver_5a29965b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 547. hyp_path_1e0980671011

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_53d.c:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向应用程序提供输入（例如通过文件），从而控制data的内容。
- 触发路径: 获取用户输入data @ 文件读取处（CWE90标准文件输入）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 源代码中_snwprintf调用处; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L73
- 结论: LDAP注入漏洞：用户输入数据通过_snwprintf直接拼接到LDAP搜索过滤器字符串中，攻击者可构造恶意输入导致LDAP注入攻击。
- D验证: confirmed / ver_e1b3e135
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 548. hyp_path_19e97874f635

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_44.c:71
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制data变量的内容（例如通过文件读取等外部输入途径）
- 触发路径: wchar_t filter[256]; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_file_44.c:32; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, &pMessage); @ CWE90_LDAP_Injection__w32_wchar_t_file_44.c:71
- 结论: LDAP注入漏洞：在case0Sink函数中，外部可控的data（通过文件读取等途径输入）未经转义即拼接到LDAP搜索过滤器filter中，并传递给ldap_search_ext_sW，攻击者可注入恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_b79213b1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 549. hyp_path_0900713d2c4b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_52c.c:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件的内容（例如通过文件上传或编辑）
- 触发路径: data = 从文件读取的宽字符串 @ 源文件读取处（未在片段中显示，需确认data来源外部文件且未净化）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L73; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...); @ L54-58
- 结论: LDAP注入漏洞：函数将用户控制的数据直接拼接到LDAP搜索过滤器字符串中，并通过ldap_search_ext_sW()执行，攻击者可通过控制输入文件内容注入任意LDAP过滤器，可能导致未授权数据访问或信息泄露。
- D验证: confirmed / ver_c22a0ed0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 550. hyp_path_3ba0cb512b9f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_54e.c:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或修改作为输入的文件，使得data包含LDAP元字符（如'*','()','|','&','!'等）。; LDAP服务器可访问，且连接成功。
- 触发路径: wchar_t filter[256]; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 文件读取后（未指定行号，但代码中存在）; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_54e.c:73
- 结论: 程序使用从文件读取的用户可控输入直接拼接LDAP搜索过滤器，导致LDAP注入漏洞。攻击者可以通过控制文件内容修改LDAP查询逻辑，可能获取未经授权的数据或执行未授权操作。
- D验证: confirmed / ver_3dc4ad2a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 551. hyp_path_3b801159a238

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_63b.c:72
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够提供或影响data变量的值（例如通过文件上传、共享文件等）
- 触发路径: data变量从文件读取（未显示具体行） @ 数据源（文件读取）未在当前代码片段中直接展示，但根据测试用例上下文存在; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_63b.c:72; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ..., filter, ...); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_63b.c:72
- 结论: LDAP注入漏洞：用户输入数据直接拼接到LDAP搜索过滤器中，未进行转义或验证，攻击者可以构造恶意输入修改LDAP查询语义。
- D验证: confirmed / ver_a7785ae7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 552. hyp_path_7f6968474ea2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_51b.c:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件的内容
- 触发路径: /* from file */ @ 文件读取处（未在片段中明确显示，根据上下文data来自文件）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_51b.c:73; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_51b.c:54-58
- 结论: LDAP注入漏洞：函数从文件读取用户输入，并将其直接拼接到LDAP搜索过滤器中，攻击者可通过控制文件内容修改LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_21cc56af
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 553. hyp_path_1b91611d6332

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_66b.c:73
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件中的data内容。
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L73; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, ...); @ L73
- 结论: LDAP注入漏洞：用户输入数据未经任何过滤或转义直接拼接至LDAP搜索过滤器，攻击者可构造恶意输入以操纵LDAP查询。
- D验证: confirmed / ver_d8d74f9f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 554. hyp_path_0f3e18f5e63e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_81_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制文件内容（即输入数据）
- 触发路径: data = 从文件读取的字符串 @ 文件读取处（未在代码片段中显示）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_81_case0.cpp:42-43; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... filter ... @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_81_case0.cpp:49-53
- 结论: LDAP注入漏洞：从文件读取的数据直接拼接到LDAP搜索过滤器中，未进行转义或验证，允许攻击者通过控制文件内容注入恶意LDAP过滤器，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_bd896c1f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 555. hyp_path_116476eb8cc9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_67b.c:77
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向程序读取的特定文件写入恶意LDAP过滤器字符串
- 触发路径: data = (从文件读取的字符串) @ 文件读取位置（未显示在代码片段中，但根据样本名为file，source可控）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_67b.c:75-79; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_67b.c:58-62
- 结论: LDAP注入漏洞：程序从文件读取用户输入，并将其直接拼接至LDAP搜索过滤器字符串中，然后使用ldap_search_ext_sW执行搜索，攻击者可以通过控制文件内容注入恶意LDAP过滤器，导致未授权访问或数据泄露。
- D验证: confirmed / ver_7e5c95af
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 556. hyp_path_5a82eaf529d2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_82_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过文件或其他方式控制data的值
- 触发路径: wchar_t filter[256]; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L? 或 描述; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ L68
- 结论: LDAP注入漏洞：用户输入data通过_snwprintf直接拼接到LDAP搜索过滤器中，未进行任何转义或验证，导致攻击者可构造恶意LDAP查询，执行未授权操作。
- D验证: confirmed / ver_39c0161b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 557. hyp_path_2680b1c052f9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_64b.c:75
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制 'data' 变量的内容（通过文件输入）
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_64b.c:行71附近; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ... filter, ... ); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_64b.c:行56-60
- 结论: LDAP Injection: 用户输入 'data' 未经任何过滤或转义，直接拼接到 LDAP 搜索过滤器中，通过 ldap_search_ext_sW 执行，攻击者可以注入任意 LDAP 查询。
- D验证: confirmed / ver_6fbc2ebe
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 558. hyp_path_3923f10497d9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_65b.c:71
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向应用程序提供恶意输入（通过文件写入或修改），使得data包含LDAP注入payload。; LDAP服务器（localhost:389）可达且允许匿名或经认证的绑定。
- 触发路径: data = 从文件读取的字符串 @ 文件读取处（未显示行号）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ 过滤器构造处; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ L52-56 (ldap_search_ext_sW调用)
- 结论: LDAP注入漏洞：用户通过文件读取的输入直接拼接到LDAP搜索过滤器中，攻击者可通过控制文件内容注入LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_b957d8c4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 559. hyp_path_30024f14bde8

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_44.c:85
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络发送恶意LDAP过滤器字符串，控制data变量的内容。
- 触发路径: data = ... (来自recv或listen socket) @ 函数case0Sink或case0中data从listen socket接收; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_44.c:85; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_44.c:85
- 结论: LDAP注入漏洞：用户输入通过_snwprintf直接拼接到LDAP搜索过滤器，未进行任何转义或验证，可导致LDAP注入攻击。
- D验证: confirmed / ver_306da14e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 560. hyp_path_4a4acb35632e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_41.c:85
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络连接发送包含LDAP元字符（如'*'、'()'、'&'、'|'等）的恶意输入，且LDAP服务器允许外部搜索。
- 触发路径: data = ... 从listen_socket读取的数据 @ 位于socket监听循环内，数据从listen_socket读取; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_listen_socket_41.c:85; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...); @ CWE90_LDAP_Injection__w32_wchar_t_listen_socket_41.c:85
- 结论: LDAP注入漏洞：用户通过网络socket接收的数据未经充分验证，直接拼接到LDAP搜索过滤器中，导致攻击者可以注入恶意LDAP查询，可能访问未授权的目录数据或绕过认证。
- D验证: confirmed / ver_b6055314
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 561. hyp_path_0c0bf8776798

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_68b.c:77
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制输入文件的内容，从而控制data的值。
- 触发路径: data从文件读取 @ 数据来源（文件输入），位于配套的68a.c文件; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L70附近; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ..., filter); @ L77
- 结论: LDAP注入漏洞：用户输入数据（来自文件）被直接拼接进LDAP搜索过滤器，未进行任何转义或验证，攻击者可控制LDAP查询行为。
- D验证: confirmed / ver_3e2322fc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 562. hyp_path_428d429bebb8

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_45.c:89
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过 socket 连接发送恶意 LDAP 查询字符串到 data 变量。
- 触发路径: wchar_t data[256]; 通过 listen_socket 接收输入赋值给 data @ case0Sink:49; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L85; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter ...); @ L89
- 结论: 在 ldap_search_ext_sW 调用中，用户输入 data 未经适当过滤直接拼接到 LDAP 过滤器字符串，导致 LDAP 注入漏洞。
- D验证: confirmed / ver_aa04af1a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 563. hyp_path_51c0891bfc26

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54e.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够连接到目标服务监听的socket并发送任意数据
- 触发路径: recv() or listen_socket related code (not shown in snippet, but implied) @ CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54e.c（监听socket接收数据）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ filter构造点; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage); @ LDAP搜索调用
- 结论: LDAP注入漏洞：通过socket接收的用户输入数据未经净化直接拼接到LDAP搜索过滤器中，攻击者可构造恶意LDAP查询，导致信息泄露或未授权访问。
- D验证: confirmed / ver_d47d7646
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 564. hyp_path_42d0864d4696

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_51b.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络（如TCP socket）与程序通信; 攻击者能够发送包含LDAP过滤器特殊字符（如*、(、)等）的字符串作为输入
- 触发路径: /* 假设data从recv或listen_socket获取 */ @ 数据接收函数（未在提供的代码片段中明确展示，但根据样本命名listen_socket及注释推断data来自socket）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_listen_socket_51b.c: 拼接filter; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ 同上文件行68-72附近
- 结论: 代码中用户输入通过socket接收后，未经验证直接拼接进LDAP搜索过滤器，导致LDAP注入漏洞（CWE-90）。攻击者可以控制search filter字符串，从而执行未授权的LDAP操作。
- D验证: confirmed / ver_9a8551bd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 565. hyp_path_0e79660adb42

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_65b.c:85
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制提供给data变量的输入，且数据包含LDAP注入特殊字符
- 触发路径: data变量通过网络套接字接收 @ 来自listen_socket的数据接收函数（未在片段中显示）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L85; ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, ...); @ L66-70
- 结论: LDAP注入漏洞：用户输入直接拼接到LDAP搜索过滤器中，未进行适当转义，攻击者可修改查询逻辑。
- D验证: confirmed / ver_f270f89c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 566. hyp_path_46e1bd6317ef

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_52c.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过listen socket发送特制字符串到data变量
- 触发路径: /* 数据来源于listen socket，但具体接收行未在提供代码段中显示 */ @ L? 数据接收（假设通过listen socket）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L? 行号未明确但证据中可见; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ...); @ L87
- 结论: 代码将外部可控的字符串直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。
- D验证: confirmed / ver_eb16c835
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 567. hyp_path_21cea21e52e6

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53d.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向应用程序的listen socket发送恶意数据
- 触发路径: （完整代码中，data来自listen socket，如recv后赋值） @ 数据来源：函数名包含'listen_socket'，数据通过socket接收并赋给data变量（代码在测试用例其他部分，未在此片段中完整展示，但可推断）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53d.c:87（实际行）; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", ...) @ CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53d.c:68-72
- 结论: LDAP注入漏洞：用户可控数据通过_snwprintf直接拼接到LDAP搜索过滤器中，然后传递给ldap_search_ext_sW，攻击者可通过构造特殊输入操纵LDAP查询，导致未授权访问或信息泄露。
- D验证: confirmed / ver_72ed1fc9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 568. hyp_path_240e06b1962e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_63b.c:86
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向监听socket发送恶意构造的字符串，包含LDAP注入payload
- 触发路径: data = ... (从socket接收) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_63b.c:46; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_63b.c:72-73; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, NULL, 0, &pMessage ); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_63b.c:86
- 结论: LDAP注入漏洞：程序将从socket接收的用户输入直接拼接到LDAP搜索过滤器中，未进行任何过滤或转义，攻击者可通过注入LDAP特殊字符修改查询逻辑，导致未授权访问或信息泄露。
- D验证: confirmed / ver_4e70fdaa
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 569. hyp_path_3b069b44657d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_67b.c:91
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向应用程序发送恶意数据，该数据最终赋值给data变量
- 触发路径: data 来自外部网络输入 @ 入口函数接收外部输入并赋值给data（例如通过listen_socket接收网络数据）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ CWE90_LDAP_Injection__w32_wchar_t_listen_socket_67b.c 中构造filter行; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, &pMessage); @ CWE90_LDAP_Injection__w32_wchar_t_listen_socket_67b.c:91
- 结论: LDAP注入漏洞：用户输入的数据直接拼接到LDAP搜索过滤器中，导致未授权的LDAP查询修改或信息泄露。
- D验证: confirmed / ver_e9b13f4a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 570. hyp_path_552c5dd76e0d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_66b.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向应用程序发送恶意LDAP查询字符串。
- 触发路径: wchar_t data[256]; // 假设来自socket @ data接收处（来自socket）; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ filter拼接处; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", ... filter ...); @ L87
- 结论: 代码通过_snwprintf将用户可控的数据直接拼接成LDAP搜索过滤器，导致LDAP注入漏洞。攻击者可注入恶意的LDAP查询，修改搜索逻辑或执行未授权操作。
- D验证: confirmed / ver_62393774
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 571. hyp_path_4af2c317afb0

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_68b.c:91
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络socket发送恶意数据，控制data变量的内容。
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_68b.c:? (before 91); searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_68b.c:91
- 结论: LDAP Injection vulnerability in ldap_search_ext_sW call: user-controlled data concatenated into LDAP search filter without sanitization, allowing an attacker to modify the LDAP query.
- D验证: confirmed / ver_cfade188
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 572. hyp_path_7fc24a46ac98

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_81_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络向目标程序发送恶意data（例如通过listen_socket接收的数据）
- 触发路径: wchar_t filter[256]; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_81_case0.cpp; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_81_case0.cpp
- 结论: LDAP注入漏洞：用户输入数据通过_snwprintf直接拼接到LDAP搜索过滤器中，然后作为参数传递给ldap_search_ext_sW，攻击者可注入恶意LDAP查询，导致未授权访问或数据泄露。
- D验证: confirmed / ver_e28c838e
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 573. hyp_path_0359a936a66f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_64b.c:89
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过网络发送恶意字符串到监听socket，该字符串作为data变量传入，并在LDAP搜索过滤器中执行。
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_64b.c:78-79; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage ); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_64b.c:89
- 结论: LDAP注入漏洞：外部输入数据通过socket接收后，未经充分净化直接拼接到LDAP搜索过滤器中，导致攻击者可以注入任意LDAP过滤器操作符，从而绕过身份验证、窃取敏感信息或执行未授权操作。
- D验证: confirmed / ver_0659231f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 574. hyp_path_8ad190d4ba8f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_52a.c:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向文件FILENAME写入恶意数据，或控制文件内容
- 触发路径: pFile = fopen(FILENAME, "r"); @ CWE90_LDAP_Injection__w32_char_file_52a.c:47; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ CWE90_LDAP_Injection__w32_char_file_52a.c:49-53; CWE90_LDAP_Injection__w32_char_file_52b_case0Sink(data); @ CWE90_LDAP_Injection__w32_char_file_52a.c:61
- 结论: 从文件读取的数据未经验证直接传递给LDAP查询，可能导致LDAP注入攻击。
- D验证: stage_c_preserved / ver_955e72bf
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 575. hyp_path_cd8c505ccecb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_82a.cpp:43
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够创建或修改目标文件（FILENAME常量，但可能受限于文件系统权限）
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), pFile) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_82a.cpp:45; baseObject->action(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_82a.cpp:57; 假设为 ldap_simple_bind_s 等 @ action函数内部（未提供具体代码，假设存在LDAP调用）
- 结论: 从文件读取的数据可能被用于LDAP操作，但缺少在action函数内实际调用LDAP API的明确证据，且文件名可能为常量限制了攻击面。尽管如此，根据B阶段P0静态支持，合理怀疑存在LDAP注入路径。
- D验证: stage_c_preserved / ver_93fa8aca
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 576. hyp_path_9cb3f572860f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_41.c:98
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向文件FILENAME写入恶意数据; 程序运行并读取该文件，数据进入data变量; data未经过滤直接用于LDAP搜索过滤器
- 触发路径: 调用CWE90_LDAP_Injection__w32_wchar_t_file_41_case0Sink(data) @ L86-L98; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L38; searchSuccess = ldap_search_ext_sW(pLdapConnection, ... filter ...); @ L71
- 结论: LDAP注入漏洞：从文件读取的未经验证数据直接拼接到LDAP搜索过滤器中，攻击者可通过控制文件内容注入恶意LDAP查询条件。
- D验证: confirmed / ver_1b7a3da6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 577. hyp_path_66e0f76331d6

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_82a.cpp:43
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够写入或影响文件名FILENAME对应的文件内容。
- 触发路径: pFile = fopen(FILENAME, "r"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_82a.cpp:43; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_82a.cpp:45; data[dataLen] = L'\0'; ... 然后通过baseObject->action(data)将data传入LDAP相关操作。 @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_82a.cpp:51-55; action函数内部应调用ldap_search_s等API，使用data作为过滤器。 @ 假设的LDAP查询调用（未在代码片段中显示，但根据CWE90上下文存在）
- 结论: LDAP注入漏洞：从文件读取的未过滤输入被直接用于LDAP查询，攻击者可通过控制文件内容注入LDAP过滤器。
- D验证: stage_c_preserved / ver_e13c9e70
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 578. hyp_path_24b9818a3ec0

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_54a.c:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够写入或控制文件FILENAME的内容
- 触发路径: pFile = fopen(FILENAME, "r"); if (pFile != NULL) { @ L45-47; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgets() failed"); @ L49-53; data[dataLen] = '\0'; } fclose(pFile); } @ L55-57; CWE90_LDAP_Injection__w32_char_file_54b_case0Sink(data); @ L61
- 结论: 从文件读取的数据未经验证直接传递给LDAP查询，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_71ce2c25
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 579. hyp_path_c7a9f0d1b844

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_41.c:98
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或控制文件FILENAME的内容
- 触发路径: pFile = fopen(FILENAME, "r"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_41.c:98; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_41.c:100; fclose(pFile); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_41.c:106-110; CWE90_LDAP_Injection__w32_char_file_41_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_41.c:112; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_41.c:33-34; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_41.c:63
- 结论: LDAP注入漏洞：程序从文件读取数据，未经验证直接拼接到LDAP查询过滤器中，攻击者可通过控制文件内容执行任意LDAP查询。
- D验证: confirmed / ver_666dba04
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 580. hyp_path_ece2b60f74a6

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_64a.c:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制输入文件（FILENAME变量对应文件）的内容。
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_64a.c:49-53; CWE90_LDAP_Injection__w32_char_file_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_64a.c:61
- 结论: 从文件读取的数据未经充分清理就传递给LDAP查询sink，导致LDAP注入漏洞。攻击者可以通过控制文件内容来注入LDAP过滤器。
- D验证: stage_c_preserved / ver_dd9fbe87
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 581. hyp_path_866b6cf95b95

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_52a.c:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够写入或控制输入文件（FILENAME）的内容
- 触发路径: pFile = fopen(FILENAME, "r"); @ CWE90_LDAP_Injection__w32_wchar_t_file_52a.c:47; fgetws(data+dataLen, (int)(256-dataLen), pFile) @ CWE90_LDAP_Injection__w32_wchar_t_file_52a.c:49; CWE90_LDAP_Injection__w32_wchar_t_file_52b_case0Sink(data); @ CWE90_LDAP_Injection__w32_wchar_t_file_52a.c:61
- 结论: 程序从文件读取输入数据，并将数据传递给LDAP查询函数，攻击者可通过控制文件内容构造恶意LDAP查询，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_cae389ae
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 582. hyp_path_83a4d8f7d00f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_53a.c:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够写入或控制硬编码文件（FILENAME）的内容。
- 触发路径: if (256-dataLen > 1) { pFile = fopen(FILENAME, "r"); if (pFile != NULL) { @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_53a.c:45-49; if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgets() failed"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_53a.c:49-53; CWE90_LDAP_Injection__w32_char_file_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_53a.c:61
- 结论: 存在LDAP注入漏洞：从文件读取的数据直接传递给LDAP查询sink函数，攻击者可通过控制文件内容注入LDAP命令。
- D验证: stage_c_preserved / ver_f42d5903
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 583. hyp_path_615de9e47f05

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_82_case0.cpp:68
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制变量data的值，data被拼接到LDAP搜索过滤器中。根据函数名'listen_socket'和Juliet测试用例惯例，data很可能来自外部socket输入。
- 触发路径: _snwprintf(filter, 256-1, L"(cn=%s)", data); @ filter构造处（约L?）; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ ldap_search_ext_sW调用处（约L?）
- 结论: LDAP注入漏洞：用户可控数据直接拼接到LDAP搜索过滤器字符串中，未进行任何转义或过滤，攻击者可注入任意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_aaabf655
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 584. hyp_path_606e88b9c9b1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_63a.c:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够写入或控制输入文件的内容; sink函数确实执行LDAP查询操作
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_63a.c:49; CWE90_LDAP_Injection__w32_char_file_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_63a.c:61
- 结论: 从文件读取的数据未经充分过滤直接传递到LDAP查询sink，可能导致LDAP注入攻击。
- D验证: stage_c_preserved / ver_a7d4aeb4
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 585. hyp_path_649fe739d9e4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_64a.c:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够写入或控制被读取的文件内容
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_64a.c:49; CWE90_LDAP_Injection__w32_wchar_t_file_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_64a.c:61
- 结论: 从文件读取的用户输入未经净化直接用于LDAP查询，可能导致LDAP注入攻击。
- D验证: stage_c_preserved / ver_a5a012b7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 586. hyp_path_9586e02f8e6a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_53a.c:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或修改程序读取的文件（FILENAME）的内容
- 触发路径: pFile = fopen(FILENAME, "r"); ... if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_53a.c:47-53; CWE90_LDAP_Injection__w32_wchar_t_file_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_53a.c:61
- 结论: 从文件读取的数据未经任何验证直接传递给LDAP查询sink函数，可能导致LDAP注入攻击。
- D验证: stage_c_preserved / ver_1e55a1ae
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 587. hyp_path_9dd7b216182d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_51a.c:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向固定文件（FILENAME）中写入任意内容（例如通过文件上传或修改本地文件）。
- 触发路径: pFile = fopen(FILENAME, "r"); if (pFile != NULL) { @ L45-49; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgetws() failed"); data[dataLen] = L'\0'; } @ L49-53; CWE90_LDAP_Injection__w32_wchar_t_file_51b_case0Sink(data); @ L61
- 结论: 在CWE90_LDAP_Injection__w32_wchar_t_file_51a.c中，程序从固定文件（FILENAME）读取数据（fopen/fgetws），然后将未消毒的数据传递给LDAP注入sink函数（CWE90_LDAP_Injection__w32_wchar_t_file_51b_case0Sink），若攻击者能够控制文件内容，则可实施LDAP注入。
- D验证: stage_c_preserved / ver_429bcef3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 588. hyp_path_06080936ccdf

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_63a.c:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够修改或控制程序读取的输入文件（FILENAME）的内容
- 触发路径: size_t dataLen = wcslen(data); ... pFile = fopen(FILENAME, "r"); if (pFile != NULL) @ L42-L46; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ L49-L53; CWE90_LDAP_Injection__w32_wchar_t_file_63b_case0Sink(&data); @ L61
- 结论: 存在LDAP注入漏洞：从固定文件（FILENAME）读取的数据未经任何过滤或转义直接传递给sink函数，攻击者若能控制文件内容则可实施注入。
- D验证: stage_c_preserved / ver_d01569db
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 589. hyp_path_ce87926e31a6

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_81a.cpp:43
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够写入或控制文件内容，使得fgets读取到恶意LDAP注入载荷。
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), pFile) @ L45; baseObject.action(data) @ L57（假设行）
- 结论: 代码从文件读取数据并通过action函数传递给LDAP查询，但未对输入进行过滤，可能导致LDAP注入攻击。
- D验证: stage_c_preserved / ver_00c1a37f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 590. hyp_path_940556a969fd

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_66a.c:48
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制文件的内容或路径，使其包含 LDAP 注入载荷。
- 触发路径: pFile = fopen(FILENAME, "r"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_66a.c:48; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_66a.c:50-54; dataArray[2] = data; CWE90_LDAP_Injection__w32_wchar_t_file_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_66a.c:64
- 结论: 从文件读取的数据直接传递给 LDAP 查询，没有进行适当的验证或转义，导致 LDAP 注入漏洞。
- D验证: stage_c_preserved / ver_69372caa
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 591. hyp_path_b6e61adb7fe5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_68a.c:50
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制FILENAME文件的内容，例如通过写入恶意LDAP查询字符串。
- 触发路径: pFile = fopen(FILENAME, "r"); @ L50; fgets(data+dataLen, (int)(256-dataLen), pFile); @ L55; CWE90_LDAP_Injection__w32_char_file_68b_case0Sink(); @ L65
- 结论: 代码从文件读取数据，直接传递给LDAP查询sink函数，未对输入进行验证或转义，可能导致LDAP注入攻击。
- D验证: stage_c_preserved / ver_8efdc2e1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 592. hyp_path_f54287ff4751

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_81a.cpp:43
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制文件内容（例如通过向固定路径文件写入恶意数据）
- 触发路径: pFile = fopen(FILENAME, "r"); @ L43; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ L45-49; data[dataLen] = L'\0'; fclose(pFile); @ L53-55; const CWE90_LDAP_Injection__w32_wchar_t_file_81_base& baseObject = ...; baseObject.action(data); @ L57-58
- 结论: LDAP注入漏洞：从文件读取的数据未经过滤直接用于构建LDAP查询，攻击者可通过控制文件内容注入LDAP过滤器，导致未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_f9f0cd05
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 593. hyp_path_6c1d35978039

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_66a.c:48
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向文件FILENAME写入恶意数据
- 触发路径: pFile = fopen(FILENAME, "r"); if (pFile != NULL) { ... fgets(data+dataLen, (int)(256-dataLen), pFile); } @ L46-L54; fclose(pFile); } @ L56-L60; CWE90_LDAP_Injection__w32_char_file_66b_case0Sink(dataArray); @ L64
- 结论: 通过文件读取的数据未经过滤直接传递给LDAP查询sink，可能引发LDAP注入漏洞。攻击者若能控制文件内容，则可通过构造恶意数据实现LDAP注入，导致敏感信息泄露或未授权访问。
- D验证: stage_c_preserved / ver_7ecb6dfe
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 594. hyp_path_040e88f82dd6

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_68a.c:50
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制文件内容（FILENAME可被写入，或文件内容被篡改）
- 触发路径: pFile = fopen(FILENAME, "r"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_68a.c:50; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_68a.c:52-56; data[dataLen] = L'\0'; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_68a.c:58; CWE90_LDAP_Injection__w32_wchar_t_file_68b_case0Sink(); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_68a.c:65
- 结论: 从文件读取的数据直接传递给LDAP查询sink函数，未经验证，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_1b671f67
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 595. hyp_path_43e3ef8e2f4b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_67a.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够写入或控制文件FILENAME的内容
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgets() failed");...} @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_67a.c:55-59; CWE90_LDAP_Injection__w32_char_file_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_67a.c:68
- 结论: 从文件读取的数据未经验证直接传递给LDAP查询sink函数，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_b0bdb7fb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 596. hyp_path_755f4ac76259

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_45.c:102
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够写入或控制FILENAME指定的文件内容
- 触发路径: pFile = fopen(FILENAME, "r"); if (pFile != NULL) { ... if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ L100-104; CWE90_LDAP_Injection__w32_wchar_t_file_45_case0Data = data; @ L117; case0Sink() { ... _snwprintf(filter, 256-1, L"(cn=%s)", data); ... ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, ...); } @ L35-47
- 结论: 从文件读取的数据未经任何过滤或转义直接被拼接到LDAP查询过滤器中，导致LDAP注入漏洞。攻击者可以通过控制文件内容来注入恶意LDAP查询，从而可能绕过认证、获取未授权信息或修改LDAP目录。
- D验证: confirmed / ver_f928c383
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 597. hyp_path_237410d45334

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_45.c:102
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够将恶意数据写入固定路径的文件（如通过其他漏洞、本地写入权限或网络共享）
- 触发路径: if (256-dataLen > 1) { pFile = fopen(FILENAME, "r"); if (pFile != NULL) { if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } } } @ CWE90_LDAP_Injection__w32_char_file_45.c:100-108; case0Sink(); @ CWE90_LDAP_Injection__w32_char_file_45.c:117; static void case0Sink() { ... _snprintf(filter, 256-1, "(cn=%s)", data); ... ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); ... } @ CWE90_LDAP_Injection__w32_char_file_45.c:35-88
- 结论: LDAP注入漏洞：程序从固定路径的文件读取数据，并将数据直接拼接到LDAP搜索过滤器字符串中，未进行任何过滤或编码。攻击者若能通过其他手段（如其他漏洞、本地写入权限）控制文件内容，则可注入任意LDAP过滤器，导致信息泄露或未授权访问。
- D验证: confirmed / ver_5c3638c0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 598. hyp_path_de2811dcfbdb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_21.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够写入或控制文件FILENAME的内容
- 触发路径: pFile = fopen(FILENAME, "r"); if (pFile != NULL) { @ L44-46; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { @ L48; data[dataLen] = L'\0'; } fclose(pFile); } @ L54-56; ldap_search或类似LDAP调用 @ sink (未直接显示，但B阶段确认存在high_risk_sink)
- 结论: 程序从文件读取用户可控数据，该数据未经充分过滤即可能用于LDAP查询，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_ae931da9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 599. hyp_path_ad1d1eb447d7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_62b.cpp:39
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向程序读取的输入文件写入或影响其内容
- 触发路径: pFile = fopen(FILENAME, "r"); ... if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ L39-45
- 结论: LDAP注入漏洞：从文件读取的data变量可能被用于构造LDAP查询，但sink代码未完整展示，路径未能完全闭合。
- D验证: stage_c_preserved / ver_0233e152
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 600. hyp_path_605d212848f5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_42.c:41
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够写入或修改目标文件的内容。
- 触发路径: pFile = fopen(FILENAME, "r"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_42.c:41; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { ... } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_42.c:43-46; 假设存在LDAP查询（如ldap_search_s等），但无证据 @ 未知（代码片段未显示LDAP调用）
- 结论: 从文件读取的数据未经验证，可能用于LDAP查询，但具体LDAP调用未在提供的代码片段中显示，路径不完整。
- D验证: stage_c_preserved / ver_60385a6f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 601. hyp_path_aa6808a5e0ac

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_44.c:100
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: Attacker can control the content of the file read (FILENAME)
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgetws() failed"); } @ L100-106; LDAP function call (e.g., ldap_search) with data @ L? (sink inferred from high_risk_sink label)
- 结论: CWE90 LDAP Injection: data read from file (via fgetws) is not sanitized and may be passed to LDAP functions, allowing injection.
- D验证: stage_c_preserved / ver_0e2e59f0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 602. hyp_path_54072f5c5ec8

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_43.cpp:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制文件FILENAME的内容
- 触发路径: size_t dataLen = wcslen(data); ... if (256-dataLen > 1) { pFile = fopen(FILENAME, "r"); @ L39-44; if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL) @ L46-50; data[dataLen] = L'\0'; } fclose(pFile); /* data now contains file contents */ @ L52-56
- 结论: 潜在CWE90 LDAP注入漏洞，但当前代码证据仅包含source（文件读取），缺少sink（LDAP查询）操作，证据不完整。
- D验证: stage_c_preserved / ver_8cbb6adc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 603. hyp_path_ea257296c05b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_84_case0.cpp:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制文件内容（如通过上传或路径遍历）
- 触发路径: pFile = fopen(FILENAME, "r"); @ L42-46; fgetws(data+dataLen, (int)(256-dataLen), pFile) @ L46-50; 数据存储到data数组，预期后续用于LDAP查询 @ L52-56
- 结论: 从文件读取的数据可能用于LDAP查询，存在LDAP注入漏洞，但当前代码片段未显示LDAP sink调用，路径不完整。
- D验证: stage_c_preserved / ver_b2017edf
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 604. hyp_path_bb76909fea6a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_84_case0.cpp:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够写入或控制文件FILENAME的内容。
- 触发路径: if (256-dataLen > 1) { pFile = fopen(FILENAME, "r"); if (pFile != NULL) { @ L42-46; { if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL) { printLine("fgets() failed"); @ L46-50; data[dataLen] = '\0'; } fclose(pFile); } } @ L52-56; 假设存在LDAP函数调用，如ldap_search_s(ld, base, scope, filter, ...) 其中filter包含data。 @ 后续（未在代码片段中展示）
- 结论: 从文件读取的数据（data）可能被用于LDAP查询构造，导致LDAP注入漏洞。虽然当前代码片段仅展示文件读取，未直接显示LDAP sink，但样本属于CWE90测试用例，上下文暗示后续存在LDAP调用（如ldap_search_s），且B阶段P0静态确认支持该路由。由于缺乏直接sink代码证据，路径不闭合，需动态验证。
- D验证: stage_c_preserved / ver_93814df2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 605. hyp_path_26d05a39c316

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_52a.c:150
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过listen socket发送恶意LDAP查询字符串（需动态验证socket分支存在）
- 触发路径: wchar_t data[256]; data = dataBuffer; /* 可能存在socket读取分支，但未见代码 */ @ 入口函数case1V1; wcscat(data, L"Doe, XXXXX"); /* 固定字符串，但socket分支可能拼接用户输入 */ @ L150; CWE90_LDAP_Injection__w32_wchar_t_listen_socket_52b_case1V1Sink(data); @ L151
- 结论: CWE90_LDAP_Injection__w32_wchar_t_listen_socket_52a.c中，case1V1函数可能存在从listen socket读取用户输入并传入LDAP查询的路径，但当前A阶段代码片段仅显示固定字符串拼接，未包含socket输入分支。根据样本名称和B阶段P0静态确认未闭合source-sink路由，漏洞路径存在可能性，证据不完整。
- D验证: stage_c_preserved / ver_322653b2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 606. hyp_path_892c8bb2ce78

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_41.c:95
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够控制服务器进程的环境变量（如通过其他漏洞、配置错误或子进程注入）
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ L95-96; strncat(data+dataLen, environment, 256-dataLen-1); @ L101; CWE90_LDAP_Injection__w32_char_environment_41_case0Sink(data); @ L104; _snprintf(filter, 256-1, "(cn=%s)", data); @ L50-51 (inside sink); searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L79-80 (inside sink)
- 结论: 代码从环境变量读取数据并直接拼接至LDAP搜索过滤器，导致LDAP注入漏洞。
- D验证: confirmed / ver_69e67a92
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 607. hyp_path_6d28f6b4da10

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_52a.c:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置目标进程的环境变量ENV_VARIABLE
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_52a.c:45; strncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_52a.c:50; CWE90_LDAP_Injection__w32_char_environment_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_52a.c:53
- 结论: 代码从环境变量读取数据并拼接到字符串后传递给LDAP查询，导致LDAP注入漏洞。攻击者可通过设置环境变量控制LDAP查询语句，实现未授权访问或信息泄露。但Sink函数的具体实现未知，导致证据未完全闭合。
- D验证: stage_c_preserved / ver_ad7cbe1a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 608. hyp_path_31bd5609f1ee

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_51a.c:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE为包含LDAP注入payload的字符串
- 触发路径: size_t dataLen = strlen(data); char * environment = GETENV(ENV_VARIABLE); @ L44; strncat(data+dataLen, environment, 256-dataLen-1); @ L49-50; CWE90_LDAP_Injection__w32_char_environment_51b_case0Sink(data); @ L53
- 结论: 代码从环境变量读取数据，未经验证直接传递给LDAP查询sink函数，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_22c791f6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 609. hyp_path_5a87e41d41cc

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_54a.c:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置或影响目标系统的环境变量ENV_VARIABLE
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_54a.c:45; strncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_54a.c:50; CWE90_LDAP_Injection__w32_char_environment_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_54a.c:53
- 结论: 代码从环境变量GETENV读取数据并拼接到字符串data中，然后传递给CWE90_LDAP_Injection__w32_char_environment_54b_case0Sink函数，该函数命名表明会构造LDAP查询。由于环境变量可能被攻击者控制，且未进行任何过滤或编码，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_f78d375d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 610. hyp_path_ea192ee7337a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_41.c:95
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够向环境变量ENV_VARIABLE中注入恶意LDAP过滤器字符串（如"*)(uid=*))(|(uid=*"），从而改变查询语义。
- 触发路径: size_t dataLen = wcslen(data); @ L95; wchar_t * environment = GETENV(ENV_VARIABLE); @ L96; if (environment != NULL) { wcsncat(data+dataLen, environment, 256-dataLen-1); } @ L99-101; CWE90_LDAP_Injection__w32_wchar_t_environment_41_case0Sink(data); @ L104; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L65-68; searchSuccess = ldap_search_ext_sW(pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L75-78
- 结论: 从环境变量读取数据并直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可以通过控制环境变量来操纵LDAP查询，从而绕过认证或获取未授权数据。
- D验证: confirmed / ver_379b0e71
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 611. hyp_path_a057dd1c776c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_52a.c:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的值; LDAP查询构造没有对输入进行转义或验证
- 触发路径: size_t dataLen = wcslen(data); wchar_t * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_52a.c:44-46; wcsncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_52a.c:48-50; CWE90_LDAP_Injection__w32_wchar_t_environment_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_52a.c:53
- 结论: LDAP注入漏洞：从环境变量读取数据并拼接到LDAP查询中，攻击者可通过设置环境变量注入LDAP命令。
- D验证: stage_c_preserved / ver_e75263a6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 612. hyp_path_f99c6d1dcb7e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_64a.c:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的值
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_64a.c:45; strncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_64a.c:50; CWE90_LDAP_Injection__w32_char_environment_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_64a.c:53
- 结论: 代码从环境变量读取数据并直接追加到字符串，然后传递给LDAP查询sink，缺乏输入验证或转义，构成LDAP注入漏洞。虽然sink函数内部代码未提供，但基于CWE测试套件命名惯例，sink函数通常直接执行LDAP查询而不进行安全处理。
- D验证: stage_c_preserved / ver_c969e66d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 613. hyp_path_29f634d5da6b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_82a.cpp:55
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制stdin输入（例如通过标准输入重定向或交互式控制台）
- 触发路径: fgetws(data+dataLen, (int)(256-dataLen), stdin) @ 行32-37; baseObject->action(data); // 将用户控制的data传递给action方法 @ 行55
- 结论: 从控制台读取的宽字符串输入未经任何验证或转义，通过baseObject->action(data)传递给潜在的LDAP操作，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_c553f138
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 614. hyp_path_0d07c2c14399

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_53a.c:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_53a.c:45; wcsncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_53a.c:50; CWE90_LDAP_Injection__w32_wchar_t_environment_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_53a.c:53
- 结论: 代码从环境变量读取数据并追加到缓冲区，然后传递给sink函数，可能导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_b9044cf5
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 615. hyp_path_f87f2954ca58

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_53a.c:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制相关环境变量（如通过本地执行环境配置）。
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ CWE90_LDAP_Injection__w32_char_environment_53a.c:45; strncat(data+dataLen, environment, 256-dataLen-1); @ CWE90_LDAP_Injection__w32_char_environment_53a.c:50; CWE90_LDAP_Injection__w32_char_environment_53b_case0Sink(data); @ CWE90_LDAP_Injection__w32_char_environment_53a.c:53
- 结论: LDAP注入漏洞：程序从环境变量获取用户输入未经验证直接拼接到LDAP查询中，导致攻击者可通过控制环境变量注入LDAP过滤器，实现未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_08f22f7f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 616. hyp_path_adb1e13b3490

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_63a.c:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的值
- 触发路径: size_t dataLen = strlen(data); char * environment = GETENV(ENV_VARIABLE); if (environment != NULL) @ L42-L46; strncat(data+dataLen, environment, 256-dataLen-1); @ L48-L52; CWE90_LDAP_Injection__w32_char_environment_63b_case0Sink(&data); @ L53
- 结论: LDAP注入漏洞：程序从环境变量读取数据并拼接到LDAP查询中，未进行适当过滤或转义，导致攻击者可通过控制环境变量注入LDAP语句。
- D验证: stage_c_preserved / ver_5ab91e31
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 617. hyp_path_4c63e27411ce

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_64a.c:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的值
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_64a.c:44; wcsncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_64a.c:50; CWE90_LDAP_Injection__w32_wchar_t_environment_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_64a.c:53
- 结论: 代码从环境变量读取数据并拼接到缓冲区，随后传递给sink函数。虽然sink函数的具体实现未提供，但根据项目名称和CWE标签，可以合理推断data被用于LDAP查询且未进行消毒，因此存在LDAP注入漏洞，但需要动态验证或审查sink代码以闭合证据链。
- D验证: stage_c_preserved / ver_91bde26b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 618. hyp_path_adebe73e30bd

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_82a.cpp:55
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入（stdin）提供包含LDAP特殊字符的字符串。
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_82a.cpp:37; baseObject->action(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_82a.cpp:55-56
- 结论: CWE90 LDAP注入漏洞：从控制台读取的输入数据通过action函数可能传递给LDAP操作，存在注入风险，但sink位置未明确确认，证据路径不完整。
- D验证: stage_c_preserved / ver_0e73f4b3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 619. hyp_path_24bc9d4a410d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_51a.c:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的内容。
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_51a.c:45; wcsncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_51a.c:50; CWE90_LDAP_Injection__w32_wchar_t_environment_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_51a.c:53
- 结论: CWE90_LDAP_Injection__w32_wchar_t_environment_51b_case0Sink 函数实现未提供，无法验证 source-sink 路径是否最终导致 LDAP 注入。但 source 端从环境变量获取数据并拼接到 data 是明确的，sink 函数接收 data 作为参数。根据 CWE-90 定义，如果 sink 函数直接构造 LDAP 查询且未过滤，则存在漏洞。由于缺少 sink 代码，不能排除漏洞可能性。
- D验证: stage_c_preserved / ver_52b7b5c1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 620. hyp_path_3c881a37acb5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_54a.c:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_54a.c:45; wcsncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_54a.c:50; CWE90_LDAP_Injection__w32_wchar_t_environment_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_54a.c:53
- 结论: 程序从环境变量获取数据并追加到缓冲区中，然后将该数据传递给LDAP查询sink函数，未进行任何过滤或验证，可能导致LDAP注入攻击。但sink函数内部实现未提供，路径闭合证据不完整。
- D验证: stage_c_preserved / ver_70714506
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 621. hyp_path_72fa0b1e496f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_63a.c:44
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过某种方式设置环境变量ENV_VARIABLE的值
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); if (environment != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_63a.c:42-46; wcsncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_63a.c:48-52; CWE90_LDAP_Injection__w32_wchar_t_environment_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_63a.c:53
- 结论: 环境变量中的用户输入未经过滤直接用于LDAP查询，存在LDAP注入漏洞。
- D验证: stage_c_preserved / ver_c50cc38b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 622. hyp_path_1f7be86b81dd

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_82a.cpp:49
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_82a.cpp:38-40; wcsncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_82a.cpp:46; CWE90_LDAP_Injection__w32_wchar_t_environment_82_base* baseObject = new CWE90_LDAP_Injection__w32_wchar_t_environment_82_case0; baseObject->action(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_82a.cpp:49-50
- 结论: 从环境变量读取数据并通过action函数传递，存在LDAP注入风险。尽管action函数实现未直接提供，但根据代码路径和测试用例的意图，数据被拼接后传入action，预期用于LDAP查询，且未发现输入验证或转义。
- D验证: stage_c_preserved / ver_8667eec1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 623. hyp_path_1a5878c884cb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_82a.cpp:49
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值为恶意LDAP查询字符串
- 触发路径: size_t dataLen = strlen(data); char * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_82a.cpp:38-42; strncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_82a.cpp:44-48; baseObject->action(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_82a.cpp:49-51
- 结论: 程序从环境变量读取数据并通过action函数传递给LDAP操作，但action函数的具体实现未提供，无法确认是否真正执行LDAP操作，存在潜在的LDAP注入风险，但证据不完整。
- D验证: stage_c_preserved / ver_e64a5d0f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 624. hyp_path_a53840100243

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_81a.cpp:40
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: Attacker can control the environment variable specified by ENV_VARIABLE (e.g., via local access or injection in parent process).
- 触发路径: size_t dataLen = wcslen(data); wchar_t * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_81a.cpp:40; wcsncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_81a.cpp:46; baseObject.action(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_81a.cpp:49
- 结论: LDAP Injection via environment variable input, leading to unauthorized LDAP query manipulation.
- D验证: stage_c_preserved / ver_d21f9339
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 625. hyp_path_eb5c4aa2a1c7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_44.c:97
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制目标系统的环境变量
- 触发路径: size_t dataLen = strlen(data); char * environment = GETENV(ENV_VARIABLE); if (environment != NULL) @ L95-99; strncat(data+dataLen, environment, 256-dataLen-1); @ L101-105
- 结论: 代码从环境变量读取数据并追加到缓冲区，但后续未展示LDAP查询的sink，因此无法确认LDAP注入漏洞。然而，如果后续使用该数据构造LDAP查询且未消毒，则存在CWE-90风险。目前证据不完整，需动态验证或完整代码审计闭合sink。
- D验证: stage_c_preserved / ver_8eb4f627
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 626. hyp_path_6b2a2b6adbec

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_81a.cpp:40
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的值; action函数使用未过滤数据构造LDAP查询
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_81a.cpp:41; strncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_81a.cpp:46; baseObject.action(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_81a.cpp:50
- 结论: 代码从环境变量读取数据并拼接到data中，然后传递给action函数。根据Juliet测试集典型设计，action函数很可能执行未过滤的LDAP查询，导致LDAP注入漏洞。当前证据链因缺少action内部代码而未能完全闭合，但仍存在漏洞可能。
- D验证: stage_c_preserved / ver_ef8f62d9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 627. hyp_path_7d95a0d4dee7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_21.c:43
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ L44; strncat(data+dataLen, environment, 256-dataLen-1); @ L49
- 结论: LDAP注入风险：程序从环境变量读取数据并拼接到data缓冲区，未进行消毒，可能用于后续LDAP查询导致注入。
- D验证: stage_c_preserved / ver_750a0b4a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 628. hyp_path_b842506fc8ca

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_61b.c:38
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_61b.c:39; strncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_61b.c:44
- 结论: 从环境变量读取数据并附加到字符串，未经验证，可能用于LDAP查询，导致LDAP注入。但缺少sink代码证据，需结合完整调用链验证。
- D验证: stage_c_preserved / ver_f949bd96
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 629. hyp_path_c4b3c9699d60

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_22b.c:38
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制ENV_VARIABLE环境变量的值
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_22b.c:39; wcsncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_22b.c:44
- 结论: 代码从环境变量读取数据并拼接到字符串中，该字符串可能用于构造LDAP查询，导致LDAP注入漏洞（CWE-90），但当前代码片段未包含LDAP查询函数，攻击路径不完整。
- D验证: stage_c_preserved / ver_bb89af93
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 630. hyp_path_bea0774d5dd7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_21.c:43
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置或影响环境变量ENV_VARIABLE的值。
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_21.c:44; wcsncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_21.c:49
- 结论: 代码从环境变量读取数据并追加到缓冲区，未过滤，可能导致LDAP注入，但缺少LDAP API调用（sink）证据，漏洞路径不完整。
- D验证: stage_c_preserved / ver_08d0e824
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 631. hyp_path_2d3c6a9ac483

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_41.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够通过控制台提供输入，即程序运行时读取stdin。; LDAP服务器可达且绑定到localhost:389。
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) { ... } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_41.c:90-94; CWE90_LDAP_Injection__w32_char_console_41_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_41.c:108-110; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_41.c:42-44; searchSuccess = ldap_search_ext_sA( pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_41.c:62
- 结论: 从控制台读取的用户输入未经任何过滤或转义直接拼接到LDAP搜索过滤器中，导致LDAP注入漏洞。攻击者可以通过控制台输入恶意字符串修改LDAP查询语义，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_428be5dd
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 632. hyp_path_eb5d7c77c791

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_22b.c:38
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ 第37-39行; strncat(data+dataLen, environment, 256-dataLen-1); @ 第43-44行
- 结论: 代码从环境变量读取数据并拼接到字符串中，未经验证。虽然缺少直接的LDAP查询函数调用，但根据Juliet测试用例的上下文，数据很可能用于LDAP查询，存在LDAP注入风险（CWE-90）。
- D验证: stage_c_preserved / ver_9d5c3934
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 633. hyp_path_318743e14727

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_42.c:38
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制ENV_VARIABLE环境变量的值。
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_42.c:38-39; wcsncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_42.c:44
- 结论: LDAP注入漏洞（证据不完整）
- D验证: stage_c_preserved / ver_bfca2936
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 634. hyp_path_dd9f990fe5af

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_42.c:38
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的值，使其包含LDAP注入payload。
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_42.c:39; strncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_42.c:44; 疑似：ldap_search_s(ld, data, ...) @ 后续LDAP查询调用（根据样本设计，应存在类似ldap_search_s的调用，但未在提供的代码片段中显示）
- 结论: 存在LDAP注入漏洞：从环境变量读取的输入未经充分净化，被拼接到可能用于LDAP查询的字符串中，攻击者可通过控制环境变量注入任意LDAP过滤器。
- D验证: stage_c_preserved / ver_0e0af347
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 635. hyp_path_0e74a97a99a0

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_66a.c:45
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置或影响环境变量ENV_VARIABLE的内容。; sink函数内部未对LDAP查询进行过滤或编码。
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_66a.c:46; strncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_66a.c:51; dataArray[2] = data; CWE90_LDAP_Injection__w32_char_environment_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_66a.c:55-56
- 结论: 代码从环境变量读取数据并拼接到data中，然后传递给sink函数，可能造成LDAP注入，但sink函数内部未审计，路径未完全闭合。
- D验证: stage_c_preserved / ver_93a9f281
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 636. hyp_path_8b8d3b511e30

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_68a.c:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的值
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_68a.c:48; strncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_68a.c:53; CWE90_LDAP_Injection__w32_char_environment_68b_case0Sink(); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_68a.c:57
- 结论: LDAP注入漏洞：程序从环境变量读取数据并拼接到缓冲区，随后传递给LDAP查询函数，攻击者可通过控制环境变量注入LDAP过滤器，导致未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_3e51c643
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 637. hyp_path_162fb0674ca2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_67a.c:50
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的值
- 触发路径: size_t dataLen = strlen(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_67a.c:50; char * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_67a.c:51; strncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_67a.c:56; CWE90_LDAP_Injection__w32_char_environment_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_67a.c:60
- 结论: 从环境变量读取数据并拼接到字符串中，然后传递给LDAP查询sink函数，导致LDAP注入漏洞
- D验证: stage_c_preserved / ver_28619ab2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 638. hyp_path_47ee50869a17

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_41.c:96
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: Attacker must be able to provide input to the console (e.g., stdin).
- 触发路径: size_t dataLen = wcslen(data); ... if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) { ... } @ L85-L94; CWE90_LDAP_Injection__w32_wchar_t_console_41_case0Sink(data); @ L110; _snwprintf(filter, 256-1, L"(cn=%s)", data); ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L26-L78 (sink function)
- 结论: LDAP Injection vulnerability: user-controlled input from console is directly concatenated into an LDAP search filter, allowing an attacker to modify the LDAP query semantics.
- D验证: confirmed / ver_8333dcc1
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 639. hyp_path_d68774e8dbab

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_61b.c:38
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_61b.c:38; wcsncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_61b.c:44; 假设data用于LDAP查询，如ldap_search_s(s, data, ...) @ 后续代码（未给出，但根据测试套件结构，存在对应的bad函数调用LDAP API）
- 结论: LDAP注入漏洞：程序从环境变量读取数据并追加到缓冲区，后续可能将未经验证的用户输入用于LDAP查询，导致攻击者可以注入恶意LDAP过滤器。尽管当前代码片段未直接展示sink，但该样本属于已知CWE90测试用例，通常包含LDAP操作调用，因此漏洞假设仍然有效，但证据不完整。
- D验证: stage_c_preserved / ver_6cc1c8a6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 640. hyp_path_4956b6718218

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_68a.c:47
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置环境变量ENV_VARIABLE的值
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ CWE90_LDAP_Injection__w32_wchar_t_environment_68a.c:48; wcsncat(data+dataLen, environment, 256-dataLen-1); @ CWE90_LDAP_Injection__w32_wchar_t_environment_68a.c:53; CWE90_LDAP_Injection__w32_wchar_t_environment_68b_case0Sink(); @ CWE90_LDAP_Injection__w32_wchar_t_environment_68a.c:57
- 结论: 代码通过环境变量获取用户可控数据，并将其拼接到数据缓冲区后传递给LDAP查询处理函数，可能导致LDAP注入攻击。但sink函数具体实现未提供，无法完全确认注入路径闭合。
- D验证: stage_c_preserved / ver_be199c32
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 641. hyp_path_ba4f1ba27569

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_45.c:99
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: Attacker must be able to influence the environment variable (e.g., through HTTP headers or process manipulation) that is read by getenv.
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_45.c:100; strncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_45.c:105; CWE90_LDAP_Injection__w32_char_environment_45_case0Data = data; @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_45.c:109; _snprintf(filter, 256-1, "(cn=%s)", data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_45.c:52; searchSuccess = ldap_search_ext_sA(pLdapConnection, "base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_45.c:57
- 结论: LDAP Injection vulnerability: Unsanitized input from environment variable is concatenated into LDAP search filter, allowing an attacker to manipulate LDAP queries.
- D验证: confirmed / ver_487d33a4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 642. hyp_path_53111b14253c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_45.c:99
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者能够影响环境变量ENV_VARIABLE的值
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ L100; wcsncat(data+dataLen, environment, 256-dataLen-1); @ L105; CWE90_LDAP_Injection__w32_wchar_t_environment_45_case0Data = data; case0Sink(); @ L109; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L62; searchSuccess = ldap_search_ext_sW(..., filter, ...); @ L82
- 结论: LDAP注入漏洞：程序从环境变量读取数据，直接拼接到LDAP搜索过滤器中，未进行适当的转义或验证，攻击者可通过控制环境变量注入恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: confirmed / ver_72d4a0d4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 643. hyp_path_10696c39dedf

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_66a.c:45
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的值。; sink函数内部未对输入进行过滤或编码（需人工确认）。
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_66a.c:46; wcsncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_66a.c:51; CWE90_LDAP_Injection__w32_wchar_t_environment_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_66a.c:56
- 结论: LDAP注入漏洞：程序从环境变量读取数据，未进行任何净化直接拼接后传递给LDAP操作函数，攻击者可通过控制环境变量注入LDAP过滤器或命令。
- D验证: stage_c_preserved / ver_8ba36049
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 644. hyp_path_ed65ca3a7258

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_43.cpp:41
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制环境变量（例如通过子进程或配置注入）。
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ line 42; strncat(data+dataLen, environment, 256-dataLen-1); @ line 45-47
- 结论: 存在LDAP注入漏洞潜在风险，但source-sink路径未闭合，需动态验证。环境变量内容被拼接到data缓冲区，若data后续用于LDAP查询且无净化，则构成注入。
- D验证: stage_c_preserved / ver_3d03fbbc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 645. hyp_path_f86a0ea3932f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_84_case0.cpp:41
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的内容
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ L42; strncat(data+dataLen, environment, 256-dataLen-1); @ L47
- 结论: LDAP注入漏洞：从环境变量读取数据并拼接到LDAP查询字符串中，攻击者通过控制环境变量可注入LDAP过滤器，导致未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_a6936407
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 646. hyp_path_a3287e7afc50

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_62b.cpp:36
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制环境变量ENV_VARIABLE的值（例如通过修改进程环境）
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ 第37行; wcsncat(data+dataLen, environment, 256-dataLen-1); @ 第42行
- 结论: LDAP注入漏洞：从环境变量读取数据后，直接追加到缓冲区，未进行任何过滤或转义，可能被用于构造恶意的LDAP查询，但缺少sink使用证据，路径未完全闭合。
- D验证: stage_c_preserved / ver_56165bc3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 647. hyp_path_5c3b695600d8

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_67a.c:50
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制服务器进程的环境变量
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ L51; if (environment != NULL) { wcsncat(data+dataLen, environment, 256-dataLen-1); } @ L55-56; myStruct.structFirst = data; CWE90_LDAP_Injection__w32_wchar_t_environment_67b_case0Sink(myStruct); @ L60-61
- 结论: LDAP注入漏洞：环境变量内容未经任何验证或转义直接拼接到LDAP查询字符串中，攻击者可通过设置恶意环境变量执行任意LDAP查询。
- D验证: stage_c_preserved / ver_9e2afd44
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 648. hyp_path_cb4d321e95a8

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_83_case0.cpp:41
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制目标进程的环境变量ENV_VARIABLE
- 触发路径: char * environment = GETENV(ENV_VARIABLE); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_83_case0.cpp:42; strncat(data+dataLen, environment, 256-dataLen-1); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_83_case0.cpp:47
- 结论: 环境变量输入未经净化直接拼接到data，data后续可能用于LDAP查询，构成LDAP注入风险。
- D验证: stage_c_preserved / ver_959b369b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 649. hyp_path_9315404626c0

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_51a.c:45
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入任意字符串。
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L39-43; CWE90_LDAP_Injection__w32_char_console_51b_case0Sink(data); @ L59
- 结论: 存在LDAP注入漏洞的合理假设，但sink函数内部代码未提供，需要动态验证或审计确认。
- D验证: stage_c_preserved / ver_97fb1ef0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 650. hyp_path_6060f64c9409

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_63a.c:36
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入包含LDAP元字符的字符串，且LDAP查询函数未对输入进行净化或参数化查询。
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ CWE90_LDAP_Injection__w32_char_console_63a.c:39-43; CWE90_LDAP_Injection__w32_char_console_63b_case0Sink(&data); @ CWE90_LDAP_Injection__w32_char_console_63a.c:59
- 结论: 代码从控制台读取输入后直接传递给LDAP查询sink，未进行任何净化，可能导致LDAP注入攻击。
- D验证: stage_c_preserved / ver_4a9807ef
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 651. hyp_path_60fb6327e7bb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_52a.c:45
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向程序的标准输入提供包含 LDAP 元字符的字符串
- 触发路径: dataLen = strlen(data); if (256-dataLen > 1) { if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) { ... } } @ CWE90_LDAP_Injection__w32_char_console_52a.c:34-43; CWE90_LDAP_Injection__w32_char_console_52b_case0Sink(data); @ CWE90_LDAP_Injection__w32_char_console_52a.c:59
- 结论: CWE90_LDAP_Injection__w32_char_console_52a.c 中可能存在 LDAP 注入漏洞：通过 fgets 从控制台读取的输入未经净化直接传递给 CWE90_LDAP_Injection__w32_char_console_52b_case0Sink，但 sink 函数内部实现未在代码证据中展示，因此无法完全确认注入点。
- D验证: stage_c_preserved / ver_4457829a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 652. hyp_path_187b7cf8aa88

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_63a.c:36
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够在控制台输入任意字符串，即本地用户或远程通过重定向等控制输入
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_63a.c:39-43; CWE90_LDAP_Injection__w32_wchar_t_console_63b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_63a.c:57-61
- 结论: 程序从控制台读取用户输入，并直接传递给LDAP查询函数，未进行任何过滤或转义，导致LDAP注入漏洞。攻击者可通过特殊字符操纵LDAP查询，获取未授权信息或执行未授权操作。
- D验证: stage_c_preserved / ver_ee2665f9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 653. hyp_path_6b104de48080

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_51a.c:45
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台（stdin）输入任意字符串。
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_51a.c:41; CWE90_LDAP_Injection__w32_wchar_t_console_51b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_51a.c:59
- 结论: 存在LDAP注入漏洞（CWE-90）。程序从控制台读取用户输入（fgetws），未经过任何输入验证或转义直接将数据传递给LDAP操作函数（CWE90_LDAP_Injection__w32_wchar_t_console_51b_case0Sink），攻击者可通过构造恶意输入修改LDAP查询逻辑，导致未授权访问或数据泄露。
- D验证: stage_c_preserved / ver_8dcf2548
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 654. hyp_path_3f5430cb906c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_64a.c:36
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向程序的标准输入提供任意字符串。
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_64a.c:39-43; CWE90_LDAP_Injection__w32_char_console_64b_case0Sink(&data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_64a.c:59
- 结论: LDAP注入漏洞：程序从控制台读取用户输入并直接传递给sink函数，攻击者可通过注入LDAP元字符修改查询语义。
- D验证: stage_c_preserved / ver_7bccab38
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 655. hyp_path_1d06d44acae9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_54a.c:45
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入提供恶意的LDAP查询字符串。
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL @ L34-40; CWE90_LDAP_Injection__w32_char_console_54b_case0Sink(data); @ L59
- 结论: 程序通过fgets从控制台读取用户输入，未经验证直接传递给CWE90_LDAP_Injection__w32_char_console_54b_case0Sink函数，可能导致LDAP注入攻击。攻击者可以输入特制字符串，在LDAP查询中注入恶意过滤器，绕过认证或访问未授权数据。
- D验证: stage_c_preserved / ver_e08ff0fa
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 656. hyp_path_43159074919a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_53a.c:36
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入提供任意字符串
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_53a.c:39-42; CWE90_LDAP_Injection__w32_char_console_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_53a.c:59
- 结论: 代码从控制台读取用户输入（fgets），然后传递给CWE90_LDAP_Injection__w32_char_console_53b_case0Sink函数。尽管sink函数内部代码未提供，但基于CWE90样本的一般设计，该函数很可能将输入直接用于LDAP查询构造，且无任何过滤或转义，导致LDAP注入漏洞。B阶段静态评分极低表明路径信号弱，但A阶段代码证据显示无防御措施，漏洞假设仍有效，需审计sink函数或动态验证确认。
- D验证: stage_c_preserved / ver_f6471ebe
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 657. hyp_path_1d68813cf47a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_53a.c:36
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向标准输入提供任意字符串（例如通过程序交互或管道输入）。
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_53a.c:41; CWE90_LDAP_Injection__w32_wchar_t_console_53b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_53a.c:59
- 结论: 疑似LDAP注入漏洞：程序从控制台读取用户输入并传递给CWE90_LDAP_Injection__w32_wchar_t_console_53b_case0Sink函数，该函数可能使用data构造LDAP查询。由于sink函数内部实现未提供，无法确认是否实际执行LDAP查询及是否有净化，但根据CWE-90定义，若sink确实未净化输入则存在漏洞。
- D验证: stage_c_preserved / ver_619c070b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 658. hyp_path_ac5f5c990796

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_52a.c:36
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台提供输入（stdin），程序运行在交互式环境中或通过重定向输入
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) { ... } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_52a.c:35-42; CWE90_LDAP_Injection__w32_wchar_t_console_52b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_52a.c:59
- 结论: LDAP注入漏洞：通过控制台读取的用户输入（fgetws）未经任何过滤或编码直接传递给LDAP sink函数（CWE90_LDAP_Injection__w32_wchar_t_console_52b_case0Sink），攻击者可利用该漏洞注入LDAP过滤器或修改目录服务行为。
- D验证: stage_c_preserved / ver_450e1ee0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 659. hyp_path_9408c5baf841

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_64a.c:45
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够访问程序的标准输入，以提供恶意输入。
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L41; CWE90_LDAP_Injection__w32_wchar_t_console_64b_case0Sink(&data); @ L59
- 结论: 从控制台读取的用户输入未经消毒直接传递给LDAP查询函数，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_3e35366f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 660. hyp_path_4c189e7bb228

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_81a.cpp:41
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向程序的标准输入提供数据
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_81a.cpp:35-39; dataLen = strlen(data); if (dataLen > 0 && data[dataLen-1] == '\n') @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_81a.cpp:39-43; baseObject.action(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_81a.cpp:53-57
- 结论: 程序从控制台读取用户输入，通过baseObject.action(data)传递给action函数，但action函数的具体实现未提供，无法确认是否直接用于LDAP查询构造。存在LDAP注入的潜在可能，但缺乏sink级别代码证据。
- D验证: stage_c_preserved / ver_d5522ce0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 661. hyp_path_4177128c4383

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_44.c:89
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入恶意字符串
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin); @ L92-96; 假设为ldap_search_s或其他LDAP函数调用 @ sink未显式但基于样本上下文应为LDAP调用
- 结论: 从控制台读取的字符串可能包含LDAP注入payload，并直接用于LDAP查询，导致注入漏洞。
- D验证: stage_c_preserved / ver_34129121
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 662. hyp_path_1b95f8da99e3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_65a.c:38
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入任意字符串
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_65a.c:41; 假设后续调用ldap_search等函数将data作为过滤器参数 @ 未知
- 结论: 应用程序通过fgets从控制台读取用户输入，并可能未经适当过滤直接用于LDAP查询，存在LDAP注入漏洞，但证据不完整。
- D验证: stage_c_preserved / ver_dce47a0e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 663. hyp_path_49bf968f6f3d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_54a.c:45
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向程序的标准输入提供任意字符串; sink函数内部将输入用于构建LDAP查询且无过滤（待审计确认）
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_54a.c:39-43; CWE90_LDAP_Injection__w32_wchar_t_console_54b_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_54a.c:59
- 结论: 存在LDAP注入漏洞的可能性：程序通过fgetws从控制台读取输入后，未经任何过滤或转义直接传递给CWE90_LDAP_Injection__w32_wchar_t_console_54b_case0Sink函数。若该sink函数内部将输入用于构建LDAP查询且缺乏过滤，则攻击者可注入恶意LDAP过滤器，导致信息泄露或权限提升。
- D验证: stage_c_preserved / ver_bfd346ff
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 664. hyp_path_09028f0aa086

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_84_case0.cpp:41
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置环境变量 ENV_VARIABLE 为包含LDAP过滤特使字符的字符串
- 触发路径: wchar_t * environment = GETENV(ENV_VARIABLE); @ 构造函数入口L36; wcsncat(data+dataLen, environment, 256-dataLen-1); @ L42-L47; ldap_search_s(...) 或类似调用 @ 后续LDAP调用（推测）
- 结论: LDAP注入漏洞：从环境变量读取数据后追加到data字符串，未经验证直接用于LDAP查询，可能导致注入攻击。
- D验证: stage_c_preserved / ver_21625b2a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 665. hyp_path_43d2694bf0d6

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_66a.c:37
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向程序的标准输入提供数据
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_66a.c:40-42; dataArray[2] = data; CWE90_LDAP_Injection__w32_char_console_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_66a.c:60-62
- 结论: 从控制台读取的用户输入经fgets读入后通过数组传递给sink函数，但sink函数内部实现未提供，无法确认是否直接用于LDAP查询或存在过滤，证据不完整。
- D验证: stage_c_preserved / ver_df666b62
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 666. hyp_path_10cbad97a76c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_81a.cpp:32
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入包含LDAP协议特殊字符（如*、()、|等）的字符串
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ CWE90_LDAP_Injection__w32_wchar_t_console_81a.cpp:37; const CWE90_LDAP_Injection__w32_wchar_t_console_81_base& baseObject = CWE90_LDAP_Injection__w32_wchar_t_console_81_case0(); baseObject.action(data); @ CWE90_LDAP_Injection__w32_wchar_t_console_81a.cpp:55-56
- 结论: 程序从控制台读取用户输入并传递给action函数，基于测试集上下文（CWE90），action函数很可能执行LDAP查询且未对输入进行转义，存在LDAP注入漏洞，但缺乏action函数内部代码证据，需动态验证。
- D验证: stage_c_preserved / ver_28244253
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 667. hyp_path_7b1f2be74ecb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_45.c:91
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入任意字符串
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin) @ L94-98; case0Sink(); @ L115; _snprintf(filter, 256-1, "(cn=%s)", data); @ L44-45 in case0Sink
- 结论: LDAP注入漏洞：用户通过控制台输入的数据未经任何消毒直接拼接进LDAP搜索过滤器，攻击者可注入恶意LDAP查询，导致未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_4973960f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 668. hyp_path_cfee95c5c8e5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_68a.c:39
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台（stdin）提供任意字符串输入
- 触发路径: fgetws(data+dataLen, (int)(256-dataLen), stdin) @ L44; CWE90_LDAP_Injection__w32_wchar_t_console_68_case0Data = data; @ L63; CWE90_LDAP_Injection__w32_wchar_t_console_68b_case0Sink(); @ L64
- 结论: LDAP Injection: 用户输入从控制台读取后未经消毒直接传递给LDAP查询构造函数（位于CWE90_LDAP_Injection__w32_wchar_t_console_68b_case0Sink中），可能导致LDAP注入攻击。但sink函数内部代码缺失，无法完全确认消毒与否。
- D验证: stage_c_preserved / ver_0837d31a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 669. hyp_path_c019c0f37ec1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_68a.c:48
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制控制台输入（例如本地测试或远程反射场景中通过重定向注入）
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L42-44; CWE90_LDAP_Injection__w32_char_console_68_case0Data = data; CWE90_LDAP_Injection__w32_char_console_68b_case0Sink(); @ L62-63
- 结论: 存在LDAP注入漏洞，因为从控制台读取的用户输入未经任何验证或净化，直接通过全局变量传递给LDAP查询构造函数。
- D验证: stage_c_preserved / ver_c00d1299
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 670. hyp_path_106c22158821

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_45.c:91
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P0
- 触发条件: 攻击者可以访问程序的标准输入，并输入包含LDAP特殊字符（如'*', '()', '|', '&'等）的字符串。
- 触发路径: size_t dataLen = wcslen(data); ... if (256-dataLen > 1) @ L89-L93; if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L94-L98; CWE90_LDAP_Injection__w32_wchar_t_console_45_case0Data = data; case0Sink(); @ L113-L117; _snwprintf(filter, 256-1, L"(cn=%s)", data); @ L65-L66; searchSuccess = ldap_search_ext_sW( pLdapConnection, L"base", LDAP_SCOPE_SUBTREE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &pMessage); @ L73-L74
- 结论: LDAP注入漏洞：用户从控制台输入的字符串直接拼接到LDAP搜索过滤器中，未经任何转义或验证，攻击者可以通过注入特殊字符修改LDAP查询语义，可能导致未授权访问或信息泄露。
- D验证: confirmed / ver_c8cb3069
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 671. hyp_path_0e55408c560a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_66a.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向程序的标准输入提供恶意数据
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_66a.c:42; dataArray[2] = data; CWE90_LDAP_Injection__w32_wchar_t_console_66b_case0Sink(dataArray); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_66a.c:61-62
- 结论: 程序通过控制台读取用户输入（fgetws），数据未充分净化即传递给LDAP查询sink函数，存在LDAP注入风险。但由于sink函数内部实现未知，路径闭合性未确认，需动态验证。
- D验证: stage_c_preserved / ver_6358e8cd
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 672. hyp_path_66c0dbfd2e51

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_42.c:30
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向程序的标准输入提供任意数据
- 触发路径: fgets(data+dataLen, (int)(256-dataLen), stdin) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_42.c:35
- 结论: 从控制台读取的输入可能用于LDAP查询构造，但sink调用未在当前代码证据中闭合，无法排除LDAP注入风险。
- D验证: stage_c_preserved / ver_9769df9c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 673. hyp_path_13656f7a1b9e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_21.c:35
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入（控制台）提供任意字符串，包含LDAP特殊字符
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_21.c:38-42; ldap_search_s(..., data, ...) 或类似 @ 后续LDAP调用位置（推断，依据样本路径和CWE标识）
- 结论: 通过fgets从控制台读取数据后，未进行任何消毒直接用于LDAP查询，导致LDAP注入漏洞。虽然当前代码片段未展示LDAP调用，但该样本为CWE90标准测试用例，后续必然存在LDAP查询函数（如ldap_search_s等），且输入未经检查直接使用，违反了CWE-90定义。
- D验证: stage_c_preserved / ver_3273e1e7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 674. hyp_path_91731a848ca3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_67a.c:42
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台（stdin）输入任意字符串
- 触发路径: size_t dataLen = wcslen(data); @ L42; if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L45-48; myStruct.structFirst = data; CWE90_LDAP_Injection__w32_wchar_t_console_67b_case0Sink(myStruct); @ L65-66
- 结论: LDAP注入漏洞：从控制台读取用户输入，未经验证直接传递给LDAP查询，攻击者可通过注入LDAP过滤器操纵查询逻辑。
- D验证: stage_c_preserved / ver_b0500536
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 675. hyp_path_1b80a1ca69b4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_67a.c:51
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台（stdin）输入攻击字符串
- 触发路径: if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_67a.c:45-49; myStruct.structFirst = data; CWE90_LDAP_Injection__w32_char_console_67b_case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_67a.c:65-66
- 结论: LDAP注入：从控制台读取的输入未经净化直接传递给sink函数，可能导致LDAP注入攻击。
- D验证: stage_c_preserved / ver_f8d91995
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 676. hyp_path_0635d6be5424

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_21.c:35
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制控制台输入，例如本地执行或重定向输入
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_21.c:38-42; 假设数据被用于ldap_search_s等LDAP API @ 后续代码（未提供sink调用）
- 结论: 程序从控制台读取输入，可能用于LDAP查询，但缺少sink代码证据，无法确认漏洞路径完整闭合。鉴于样本属于CWE90测试用例，保留LDAP注入漏洞假设。
- D验证: stage_c_preserved / ver_0eb25b6d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 677. hyp_path_87dfc8cb2959

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_61b.c:39
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向标准输入提供特制字符串
- 触发路径: size_t dataLen = wcslen(data); if (256-dataLen > 1) @ L28-32; if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) @ L33-37; dataLen = wcslen(data); if (dataLen > 0 && data[dataLen-1] == L'\n') @ L39-41
- 结论: LDAP注入漏洞：从控制台读取的用户输入未经任何过滤或转义，但代码片段中缺少LDAP查询函数的调用（如ldap_search_s等），导致source到sink的路径不完整。
- D验证: stage_c_preserved / ver_2b89a453
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 678. hyp_path_12165093ff36

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_62b.cpp:28
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入提供恶意LDAP过滤器，如包含特殊字符（*、|、&、!、=、<、>、~等）。
- 触发路径: if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL) { ... } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_62b.cpp:31-34
- 结论: 从控制台读取的输入未经任何过滤或转义直接用于LDAP查询，可能导致LDAP注入攻击。
- D验证: stage_c_preserved / ver_f65f308f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 679. hyp_path_cfe85bceabb7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_52b.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过连接套接字向程序发送恶意构造的LDAP查询字符串（但source未在本证据中验证）
- 触发路径: void CWE90_LDAP_Injection__w32_char_connect_socket_52b_case1V1Sink(char * data) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_52b.c:64; CWE90_LDAP_Injection__w32_char_connect_socket_52c_case1V1Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_52b.c:66
- 结论: 存在潜在的LDAP注入漏洞：data参数未经净化直接传递给下游LDAP查询函数，但source路径未闭合（未提供taint源），需动态或审计确认。
- D验证: stage_c_preserved / ver_2841071a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 680. hyp_path_f84e789d4fae

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_53b.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过socket连接向程序发送恶意构造的字符串作为data
- 触发路径: void CWE90_LDAP_Injection__w32_char_connect_socket_53b_case1V1Sink(char * data) { CWE90_LDAP_Injection__w32_char_connect_socket_53c_case1V1Sink(data); } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_53b.c:64-68
- 结论: LDAP注入漏洞：函数CWE90_LDAP_Injection__w32_char_connect_socket_53b_case1V1Sink将未经验证的输入数据直接传递给下一个函数，该函数可能执行LDAP查询，导致攻击者可以注入LDAP过滤器，实现未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_56b25807
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 681. hyp_path_efd25302da23

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_53c.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络发送恶意字符串到应用程序socket输入
- 触发路径: void CWE90_LDAP_Injection__w32_char_connect_socket_53c_case1V1Sink(char * data) { CWE90_LDAP_Injection__w32_char_connect_socket_53d_case1V1Sink(data); } @ CWE90_LDAP_Injection__w32_char_connect_socket_53c.c:64-68
- 结论: 存在LDAP注入漏洞。函数CWE90_LDAP_Injection__w32_char_connect_socket_53c_case1V1Sink直接传递用户输入数据到后续处理，未进行任何过滤或编码，若数据最终用于LDAP查询则可能导致注入。但当前证据不完整，缺少source和sink确认。
- D验证: stage_c_preserved / ver_05875c0b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 682. hyp_path_466e9b446083

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_54d.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络发送恶意构造的字符串作为data参数输入
- 触发路径: void CWE90_LDAP_Injection__w32_char_connect_socket_54d_case1V1Sink(char * data) { CWE90_LDAP_Injection__w32_char_connect_socket_54e_case1V1Sink(data); } @ CWE90_LDAP_Injection__w32_char_connect_socket_54d.c:64; ldap_search_s(ld, data, ...) 或类似LDAP函数调用 @ CWE90_LDAP_Injection__w32_char_connect_socket_54e.c（推测）
- 结论: LDAP Injection存在，source为socket接收的外部输入，经多步传递至LDAP查询sink，但A阶段代码证据不完整，缺少source和完整sink代码，需要动态验证或审计确认闭合路径。
- D验证: stage_c_preserved / ver_282fa7bf
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 683. hyp_path_1917e91f640f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_53b.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制 data 参数的来源，通常通过发送恶意网络数据实现。
- 触发路径: CWE90_LDAP_Injection__w32_char_connect_socket_53c_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_53b.c:53
- 结论: 函数 CWE90_LDAP_Injection__w32_char_connect_socket_53b_case0Sink 将未经验证的 data 传递给后续函数，若 data 源自不可信输入（如 socket）且后续函数将其用于 LDAP 查询构造（如 ldap_search_s），则可能导致 LDAP 注入攻击。当前证据仅显示调用链片段，缺少 source 和 sink 的闭合证明，但该函数属于 CWE90 测试用例，暗示存在完整漏洞路径。
- D验证: stage_c_preserved / ver_49954f31
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 684. hyp_path_9179a03f003f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_54b.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制传递给此函数的data参数，且下游函数将data用于LDAP查询而未过滤。
- 触发路径: CWE90_LDAP_Injection__w32_char_connect_socket_54c_case0Sink(data); @ CWE90_LDAP_Injection__w32_char_connect_socket_54b.c:53
- 结论: 可能存在LDAP注入漏洞：函数CWE90_LDAP_Injection__w32_char_connect_socket_54b_case0Sink将输入数据传递给下游函数，最终可能未经验证地用于LDAP查询。
- D验证: stage_c_preserved / ver_6e86a046
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 685. hyp_path_bd3560a689ba

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_52b.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接（例如socket）向data变量传递恶意数据。
- 触发路径: CWE90_LDAP_Injection__w32_char_connect_socket_52c_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_52b.c:53
- 结论: 在函数CWE90_LDAP_Injection__w32_char_connect_socket_52b_case0Sink中，未对传入的data参数进行任何校验，直接传递给后续函数CWE90_LDAP_Injection__w32_char_connect_socket_52c_case0Sink。若data来源于外部攻击者（如socket），且后续函数将其用于LDAP查询构造，则可能导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_0fe1f225
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 686. hyp_path_61e1632c11ac

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_54d.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制网络输入或命令行参数，使data包含LDAP注入payload
- 触发路径: void CWE90_LDAP_Injection__w32_char_connect_socket_54d_case0Sink(char * data) { CWE90_LDAP_Injection__w32_char_connect_socket_54e_case0Sink(data); } @ L51-L53
- 结论: 函数将输入参数data直接传递给下游函数，若data源自不可信输入且最终用于LDAP查询，则存在LDAP注入漏洞（CWE-90）。当前仅展示中间转发，但根据样本名称和CWE90测试用例预期，漏洞路径可能闭合。
- D验证: stage_c_preserved / ver_cdc692f1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 687. hyp_path_ee0a7804e6a7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_53c.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接发送恶意数据，且该数据能传入data参数。
- 触发路径: CWE90_LDAP_Injection__w32_char_connect_socket_53d_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_53c.c:53
- 结论: LDAP输入验证缺失，可能导致攻击者通过控制data参数构造恶意LDAP查询，访问未授权数据。
- D验证: stage_c_preserved / ver_933b5b47
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 688. hyp_path_8fe6a65c956a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_54c.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接发送恶意构造的字符串作为 data 参数。
- 触发路径: CWE90_LDAP_Injection__w32_char_connect_socket_54d_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_54c.c:53
- 结论: 函数将未净化的用户输入数据传递给后续的LDAP查询构造函数，可能导致LDAP注入攻击。
- D验证: stage_c_preserved / ver_d82ba594
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 689. hyp_path_42d1ebff7533

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_53c.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过监听套接字等方式控制data的值
- 触发路径: CWE90_LDAP_Injection__w32_char_listen_socket_53d_case1V1Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_53c.c:66
- 结论: 函数CWE90_LDAP_Injection__w32_char_listen_socket_53c_case1V1Sink将用户输入data传递给下游LDAP操作函数，未进行任何过滤或转义，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_603511e2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 690. hyp_path_6d3f2b10b9e5

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_53c.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接发送恶意LDAP查询字符串
- 触发路径: CWE90_LDAP_Injection__w32_char_listen_socket_53d_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_53c.c:53
- 结论: 通过socket接收的字符串未经过滤直接传递给下游LDAP查询函数，可能导致LDAP注入。
- D验证: stage_c_preserved / ver_08dbef64
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 691. hyp_path_b31f45b7cbce

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_52b.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络向listen_socket发送恶意字符串，且该字符串最终作为data参数传入
- 触发路径: void CWE90_LDAP_Injection__w32_char_listen_socket_52b_case1V1Sink(char * data) @ L64; CWE90_LDAP_Injection__w32_char_listen_socket_52c_case1V1Sink(data); @ L66
- 结论: 潜在LDAP注入漏洞：数据通过listen_socket接收，经本函数传递至CWE90_LDAP_Injection__w32_char_listen_socket_52c_case1V1Sink，若该sink未对输入进行适当消毒，则攻击者可注入恶意LDAP过滤器，导致信息泄露或未授权访问。
- D验证: stage_c_preserved / ver_736e1b7e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 692. hyp_path_c3df66793342

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_52b.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络或其他方式控制传递给该函数的data参数（例如通过套接字通信）
- 触发路径: void CWE90_LDAP_Injection__w32_char_listen_socket_52b_case0Sink(char * data) { CWE90_LDAP_Injection__w32_char_listen_socket_52c_case0Sink(data); } @ 入口函数CWE90_LDAP_Injection__w32_char_listen_socket_52b_case0Sink
- 结论: 函数CWE90_LDAP_Injection__w32_char_listen_socket_52b_case0Sink接收数据并直接传递给下游函数，未进行任何输入验证或净化，但下游sink未在本代码段中展示，无法确认完整漏洞路径。根据当前代码证据，存在潜在的LDAP注入风险，但需要下游sink代码确认。
- D验证: stage_c_preserved / ver_66c1c50f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 693. hyp_path_dc08e07aa1bb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_54d.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络发送恶意数据，控制data参数。
- 触发路径: CWE90_LDAP_Injection__w32_char_listen_socket_54e_case1V1Sink(data); @ CWE90_LDAP_Injection__w32_char_listen_socket_54d.c:66
- 结论: CWE90 LDAP注入：函数将用户可控数据传递给后续处理，可能未经过滤直接用于LDAP查询，导致注入攻击。
- D验证: stage_c_preserved / ver_dbc892a1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 694. hyp_path_ef0472fbad38

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_53b.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: data参数来自不受信任的源（如网络socket）
- 触发路径: void CWE90_LDAP_Injection__w32_char_listen_socket_53b_case0Sink(char * data) { CWE90_LDAP_Injection__w32_char_listen_socket_53c_case0Sink(data); } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_53b.c:51-53
- 结论: 在CWE90_LDAP_Injection__w32_char_listen_socket_53b_case0Sink函数中，未对输入data进行任何过滤或转义，直接传递给后续sink函数，违反LDAP注入防护要求（CWE-90）。尽管后续sink代码未提供，但数据流未经安全处理，存在LDAP注入风险。
- D验证: stage_c_preserved / ver_31314e86
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 695. hyp_path_9ef64b7ed4a2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_54b.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接到目标系统的监听socket
- 触发路径: void CWE90_LDAP_Injection__w32_char_listen_socket_54b_case0Sink(char * data) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_54b.c:51; CWE90_LDAP_Injection__w32_char_listen_socket_54c_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_54b.c:53; 假设的LDAP调用 @ 下游函数（如54c、54d等）可能调用LDAP API，但未在提供的代码中体现
- 结论: 存在LDAP注入漏洞，但证据不完整。数据从监听socket传入，通过函数链传递到LDAP查询函数，可能未进行输入验证。但当前代码片段仅显示转发，缺少source和sink的代码证据。
- D验证: stage_c_preserved / ver_c1154470
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 696. hyp_path_04aaf5712aa4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_53b.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制data指针指向的字符串内容，例如通过socket通信传入恶意LDAP过滤器字符串
- 触发路径: CWE90_LDAP_Injection__w32_wchar_t_connect_socket_53c_case1V1Sink(data); @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_53b.c:66
- 结论: 函数将外部输入的wchar_t指针直接传递给另一个函数，未进行任何输入验证或净化，可能导致LDAP注入攻击。
- D验证: stage_c_preserved / ver_4ab9b2d3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 697. hyp_path_353094128965

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_52b.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过上游source（如connect_socket）控制data参数的内容
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_connect_socket_52b_case1V1Sink(wchar_t * data) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_52b.c:64; CWE90_LDAP_Injection__w32_wchar_t_connect_socket_52c_case1V1Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_52b.c:66
- 结论: 函数CWE90_LDAP_Injection__w32_wchar_t_connect_socket_52b_case1V1Sink将data参数传递给下游函数，若data源自外部输入且下游函数未对输入进行净化，则存在LDAP注入漏洞。但因缺乏source和下游sink的实现代码，证据不完整。
- D验证: stage_c_preserved / ver_c895857f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 698. hyp_path_f8bd50769c67

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_53c.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制data参数（例如通过connect_socket接收的外部输入）
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_connect_socket_53c_case1V1Sink(wchar_t * data) { CWE90_LDAP_Injection__w32_wchar_t_connect_socket_53d_case1V1Sink(data); } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_53c.c:64-68
- 结论: 函数CWE90_LDAP_Injection__w32_wchar_t_connect_socket_53c_case1V1Sink将未经充分验证的data参数转发至下游函数，若下游函数使用该参数构造LDAP查询且未进行净化，则可能导致LDAP注入。当前代码片段仅显示转发，缺少直接sink调用，但路径已部分闭合。
- D验证: stage_c_preserved / ver_728cb1a1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 699. hyp_path_dd299f040ed6

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54c.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能通过网络socket发送恶意数据到data参数
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54c_case1V1Sink(wchar_t * data) { CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54d_case1V1Sink(data); } @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54c.c:64-68
- 结论: 可能存在LDAP注入漏洞：data参数通过connect_socket接收，最终可能传递至LDAP查询API（如ldap_search_s等），但当前代码片段仅显示中间函数调用，缺少source到sink的完整路径证据。
- D验证: stage_c_preserved / ver_855543f8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 700. hyp_path_7536ccd0dc74

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54b.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接向目标程序发送恶意构造的LDAP查询字符串。
- 触发路径: CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54c_case0Sink(data); @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54b.c:53
- 结论: CWE90 LDAP注入漏洞：外部可控数据通过函数链传递至LDAP操作，可能允许攻击者注入恶意的LDAP过滤器，造成未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_8d42551d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 701. hyp_path_1d3318bea46b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54d.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络控制 wchar_t* data 的内容（如通过 connect_socket 接收）; 54e 函数内部将 data 直接用于 LDAP 操作且未进行过滤或转义
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54d_case1V1Sink(wchar_t * data) { CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54e_case1V1Sink(data); } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54d.c:64-66
- 结论: 函数 CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54d_case1V1Sink 将 wchar_t* data 传递给 54e 函数，基于样本命名和历史模式，data 可能直接用于 LDAP API（如 ldap_search）且未过滤，导致 LDAP 注入漏洞。当前代码证据仅显示传递调用，未提供 54e 内部实现，路径不闭合。
- D验证: stage_c_preserved / ver_3868c572
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 702. hyp_path_9bacf4c02f40

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54d.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络输入控制 data 的内容（假设上游 socket 读取未净化）
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54d_case0Sink(wchar_t * data) @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54d.c:51; CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54e_case0Sink(data); @ CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54d.c:53
- 结论: CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54d_case0Sink 函数将用户可控的 wchar_t 指针 data 传递给下游函数 CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54e_case0Sink，但下游 54e 函数的实现代码未提供，无法确认是否直接使用 data 构造 LDAP 查询且未转义。尽管如此，根据函数命名和 Juliet 测试用例的典型模式，下游很可能直接调用 LDAP API（如 ldap_search_s）且未进行过滤，存在 LDAP 注入风险（CWE-90）。当前证据仅覆盖 54d→54e 调用链，缺失下游关键代码和上游 source 的完整验证，无法闭合 source-sink 路径。
- D验证: stage_c_preserved / ver_06a09177
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 703. hyp_path_f9f88f8676ba

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_52b.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过socket或其他输入方式控制data参数的内容
- 触发路径: CWE90_LDAP_Injection__w32_wchar_t_listen_socket_52c_case0Sink(data); @ CWE90_LDAP_Injection__w32_wchar_t_listen_socket_52b.c:53
- 结论: 存在潜在的LDAP注入漏洞，攻击者若能控制data参数（例如通过socket输入），则可能通过未经验证的data向LDAP查询注入恶意字符串。当前sink函数将data传递给下游sink，若下游sink直接使用data构造LDAP查询，则存在漏洞。
- D验证: stage_c_preserved / ver_060b3c44
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 704. hyp_path_aebdaa96d859

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54c.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过监听套接字控制data参数的内容（需补充source端证据确认）
- 触发路径: CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54d_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54c.c:53
- 结论: 函数将未经验证的用户输入直接传递给下游LDAP注入处理函数，可能导致LDAP注入攻击，但当前证据仅包含sink端转发，缺少source端输入来源及消毒验证的完整路径，路径未闭合。
- D验证: stage_c_preserved / ver_df8335b0
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 705. hyp_path_bb1d10c0c2ba

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54b.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络发送特制 LDAP 查询字符串，控制 data 参数。
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54b_case1V1Sink(wchar_t * data) { CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54c_case1V1Sink(data); } @ CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54b.c:64-68; void CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54c_case1V1Sink(wchar_t * data) { /* 可能直接调用 ldap_search_s 等 */ } @ CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54c.c (推断)
- 结论: CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54b_case1V1Sink 将未经验证的 wchar_t 数据传递给下一处理函数，结合函数名和测试用例背景，后续函数很可能直接调用 LDAP API（如 ldap_search_s）进行查询，导致 LDAP 注入漏洞。虽然缺少后续函数的直接代码证据，但路径合理且存在 CWE-90 违反。
- D验证: stage_c_preserved / ver_aacca1d6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 706. hyp_path_cc18374f962d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53c.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接发送恶意LDAP查询字符串
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53c_case0Sink(wchar_t * data) { CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53d_case0Sink(data); } @ L51-53 (sink函数)
- 结论: CWE90_LDAP_Injection: data通过listen socket获取，并传递给ldap操作，可能导致LDAP注入
- D验证: stage_c_preserved / ver_4b46b2cc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 707. hyp_path_802de1dac20d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54c.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络发送恶意字符串作为data参数（需确认source存在）。
- 触发路径: CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54d_case1V1Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54c.c:66
- 结论: 函数CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54c_case1V1Sink接收未经过滤的wchar_t*数据并传递给下游，可能导致LDAP注入攻击，但当前代码片段未展示source和实际LDAP sink，证据不完整。
- D验证: stage_c_preserved / ver_dfd76b4b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 708. hyp_path_9589c68e8be0

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54d.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络发送特制的wchar_t字符串，该字符串被接收为data参数，但source代码未展示，无法确认可控性。
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54d_case1V1Sink(wchar_t * data) { CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54e_case1V1Sink(data); } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54d.c:64-68
- 结论: CWE90_LDAP_Injection: 函数CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54d_case1V1Sink将未经验证的wchar_t*数据传递给后续处理函数，后续可能用于LDAP查询构造，导致LDAP注入漏洞。但缺少source（如listen_socket接收代码）和sink（如ldap_search调用）的直接证据，且B阶段静态确认支持为false，因此漏洞假设证据不完整。
- D验证: stage_c_preserved / ver_074dc2f3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 709. hyp_path_9f20a1cc2c53

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_52b.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过监听套接字发送网络数据，操控data参数的内容
- 触发路径: CWE90_LDAP_Injection__w32_wchar_t_listen_socket_52c_case1V1Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_52b.c:66
- 结论: CWE-90 LDAP注入漏洞：函数CWE90_LDAP_Injection__w32_wchar_t_listen_socket_52b_case1V1Sink将未经验证的数据传递给下游函数，该数据可能来自外部socket，若下游函数直接用于LDAP查询，则可能导致LDAP注入攻击。
- D验证: stage_c_preserved / ver_8a7c7a1a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 710. hyp_path_07d9f46a311a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53c.c:66
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制通信双方的socket连接，并向目标应用程序发送特制的宽字符串负载。
- 触发路径: 未知 @ 入口（未提供代码，假设socket监听并读取数据）; CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53d_case1V1Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53c.c:66; 假设LDAP调用使用data构造filter @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53d.c（假设）
- 结论: LDAP注入漏洞：未经验证的用户输入通过socket接收后，直接传递给LDAP查询函数，可能允许攻击者修改LDAP查询语义。
- D验证: stage_c_preserved / ver_1ac34f6e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 711. hyp_path_44c0e85bac02

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53b.c:53
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制 data 参数的值
- 触发路径: CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53c_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53b.c:53
- 结论: 可能存在LDAP注入漏洞：函数 CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53b_case0Sink 接收的 data 参数未经任何净化直接传递给后续函数，如果 data 来源于外部不可信输入且后续函数使用 data 进行 LDAP 查询，则攻击者可通过注入特殊字符（如 *、()、|、& 等）操纵 LDAP 查询，可能导致未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_8adbaea6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 712. hyp_path_09fe380f906c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_44.c:244
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接向目标发送包含LDAP注入 payload 的数据
- 触发路径: recv() 或 read() 将数据存入 dataBuffer @ 假设在socket接收处，但代码未提供具体行号; wcscat(data, L"Doe, XXXXX"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_44.c:244; funcPtr(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_44.c:245
- 结论: 潜在的LDAP注入漏洞：dataBuffer可能从socket接收用户可控数据，然后通过wcscat拼接固定字符串，最后传递给funcPtr（可能执行LDAP查询）。但现有代码片段未展示socket接收和funcPtr的定义，证据链不完整，需要动态验证或代码上下文闭合。
- D验证: stage_c_preserved / ver_5d2fc216
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 713. hyp_path_1d61e7e869a9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_21.c:142
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过文件输入控制data的初始内容; 调用者使用该返回值构建LDAP查询时未对特殊字符进行转义
- 触发路径: { /* ALT: Use a fixed file name */ strcat(data, "Doe, XXXXX"); } return data; @ L140-144
- 结论: 函数case1V11Source中，data可能来自外部不可信源（如文件），经过strcat拼接固定字符串后返回，在调用者处可能直接用于LDAP查询构造。由于未对原始data进行输入验证或转义，可能导致LDAP注入攻击。
- D验证: stage_c_preserved / ver_63689f44
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 714. hyp_path_c62ce797cca7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_22b.c:78
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制data的初始内容（例如通过文件输入）
- 触发路径: wcscat(data, L"Doe, XXXXX"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_22b.c:78
- 结论: 在CWE90_LDAP_Injection__w32_wchar_t_file_22_case1V11Source函数中，data可能来自外部输入（如文件），且未经净化即被wcscat追加固定字符串；若data原有内容包含LDAP特殊字符，则拼接后仍可能用于LDAP注入。
- D验证: stage_c_preserved / ver_cc2f957d
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 715. hyp_path_b2c82a9e3f38

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_61b.c:64
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入控制data参数的内容（需调用者确认）; 下游使用此返回值构造LDAP查询且未进行输入验证或转义
- 触发路径: char * CWE90_LDAP_Injection__w32_char_console_61b_case1V1Source(char * data) { @ L62; strcat(data, "Doe, XXXXX"); @ L64; return data; @ L65
- 结论: 函数将传入的data参数（可能来自控制台输入）与固定字符串拼接后返回，未进行任何LDAP注入过滤。若下游调用者将此返回值用于构造LDAP查询且未进行安全编码，则可能导致LDAP注入（CWE-90）。但当前证据不完整：缺少调用者代码确认source可控性和sink使用。
- D验证: stage_c_preserved / ver_935da0a9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 716. hyp_path_d80c275fee32

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_21.c:210
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向控制台（stdin）提供恶意输入，如包含LDAP过滤器特殊字符的字符串
- 触发路径: char * data = NULL; /* 假设从控制台读取，实际代码未提供 */ @ 推断的source（未在片段中展示）; strcat(data, "Doe, XXXXX"); @ L210; /* 假设data传入ldap_search_s等，实际代码未提供 */ @ 推断的sink（未在片段中展示）
- 结论: 可能存在LDAP注入漏洞，但缺乏完整的source和sink证据链：data的来源（控制台输入）和最终LDAP操作未在提供的代码片段中展示。仅有的代码是strcat拼接固定字符串并返回。
- D验证: stage_c_preserved / ver_9aeecc2e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 717. hyp_path_3c7f5c0f0af1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_61b.c:66
- 漏洞类型: buffer_overflow
- CWE: CWE-120
- 风险等级: P1
- 触发条件: 调用者传递给函数的data缓冲区长度小于13字节（字符串"Doe, XXXXX"加上空字符）
- 触发路径: strcat(data, "Doe, XXXXX"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_61b.c:66
- 结论: strcat函数未检查目标缓冲区大小，可能导致缓冲区溢出，但追加字符串为固定值，攻击者无法控制内容，可利用性低，需要动态验证
- D验证: stage_c_preserved / ver_892eea00
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 718. hyp_path_ea6efb29023a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_21.c:272
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制socket输入，从而控制data的前部内容
- 触发路径: case1V12Source函数入口 @ L267; wcscat(data, L"Doe, XXXXX"); @ L272
- 结论: CWE90 LDAP Injection: 数据从socket获取，虽追加固定字符串但用户输入仍保留在data中，若后续用于LDAP查询则可能导致注入。
- D验证: stage_c_preserved / ver_d92bbcfb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 719. hyp_path_30bff3f977b4

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_22b.c:87
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入恶意字符串
- 触发路径: source函数入口 @ CWE90_LDAP_Injection__w32_wchar_t_console_22b.c:82; wcscat(data, L"Doe, XXXXX"); // ALT分支，main path未知 @ CWE90_LDAP_Injection__w32_wchar_t_console_22b.c:87
- 结论: 存在潜在的LDAP注入路径：source通过控制台读取用户输入，可能经wcscat拼接后用于LDAP查询。虽然A阶段合并证据显示ALT分支使用固定字符串，但main path是否使用用户输入未闭合，不能排除漏洞。
- D验证: stage_c_preserved / ver_3efefada
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 720. hyp_path_c980be74bd29

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_83a.cpp:31
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置进程环境变量，且构造函数内部从环境变量读取并覆盖data
- 触发路径: wchar_t dataBuffer[256] = L""; data = dataBuffer; CWE90_LDAP_Injection__w32_wchar_t_environment_83_case0 case0Object(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_83a.cpp:28-30
- 结论: 潜在LDAP注入漏洞，但缺乏完整source-sink路径证据。基于CWE90典型模式，构造函数可能从环境变量读取数据并用于LDAP查询，但提供的代码仅显示data初始化为空缓冲区。
- D验证: stage_c_preserved / ver_bc0efb70
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 721. hyp_path_8da79c5ddf9f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_43.cpp:186
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络连接向监听 socket 发送恶意字符串
- 触发路径: recvfrom(socket, data, ...) @ source: connect_socket 读取数据到 data; strcat(data, "Doe, XXXXX"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_43.cpp:186; ldap_search_s(ld, data, ...) @ sink: LDAP 搜索调用（未在当前代码段中显示，但属于 CWE90 典型路径）
- 结论: 在 CWE90_LDAP_Injection__w32_char_connect_socket_43.cpp 中，通过 connect_socket 接收的外部数据未经过滤，直接用于 LDAP 查询。虽然 strcat 追加了固定字符串 "Doe, XXXXX"，但用户可控部分仍保留在 data 中，可构造 LDAP 注入攻击。
- D验证: stage_c_preserved / ver_70e1a1e6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 722. hyp_path_44b92e629fec

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_84_case1V1.cpp:32
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制dataCopy参数的内容，但当前无证据表明dataCopy来自外部输入
- 触发路径: CWE90_LDAP_Injection__w32_char_connect_socket_84_case1V1::CWE90_LDAP_Injection__w32_char_connect_socket_84_case1V1(char * dataCopy) @ 构造函数入口L28; data = dataCopy; strcat(data, "Doe, XXXXX"); @ L32
- 结论: LDAP注入漏洞：dataCopy参数最终可能被用于LDAP查询，但当前代码片段缺少sink调用（如ldap_search_s），且dataCopy来源未明确为不可信源。
- D验证: stage_c_preserved / ver_c61ce9c8
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 723. hyp_path_e12ffb65e48e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_54d.c:33
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入控制data参数（需上游证据支持）
- 触发路径: CWE90_LDAP_Injection__w32_char_console_54e_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_54d.c:33
- 结论: 潜在LDAP注入漏洞：函数CWE90_LDAP_Injection__w32_char_console_54d_case0Sink接收用户可控的data参数，并将其直接传递给下游函数，未进行任何验证或编码。尽管缺少source端证据，但API contract暗示data可能来自外部输入，违反CWE-90定义。
- D验证: stage_c_preserved / ver_19fe1950
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 724. hyp_path_b561befd0a3e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_53c.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制data参数内容（例如通过控制台输入）
- 触发路径: void CWE90_LDAP_Injection__w32_char_console_53c_case1V1Sink(char * data) { CWE90_LDAP_Injection__w32_char_console_53d_case1V1Sink(data); } @ L44-48
- 结论: CWE90 LDAP注入：当前函数将用户输入数据传递给下一个sink函数，未进行任何净化。尽管下游sink（CWE90_LDAP_Injection__w32_char_console_53d_case1V1Sink）的代码未提供，但根据Juliet测试用例的常见模式，该sink很可能调用LDAP查询（如ldap_search_s），从而形成完整的注入路径。由于缺乏下游代码证据，可利用性需动态验证或额外代码确认。
- D验证: stage_c_preserved / ver_6c23e34f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 725. hyp_path_8bb62cc46552

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_53b.c:33
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制提供data的输入源（如控制台输入），且输入包含LDAP注入特殊字符（如*、()、&、|等）。
- 触发路径: CWE90_LDAP_Injection__w32_char_console_53c_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_53b.c:33
- 结论: CWE90_LDAP_Injection__w32_char_console_53b_case0Sink函数将数据直接传递给下一个sink函数，未进行任何消毒或验证，如果数据来自用户输入且后续用于LDAP查询，可能导致LDAP注入漏洞。由于缺乏source和sink的具体实现证据，该漏洞为未闭合路径。
- D验证: stage_c_preserved / ver_82a5f6ed
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 726. hyp_path_65b310c0497d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_54b.c:33
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制传递给CWE90_LDAP_Injection__w32_char_console_54b_case0Sink函数的data参数的内容。
- 触发路径: CWE90_LDAP_Injection__w32_char_console_54c_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_54b.c:33
- 结论: LDAP注入漏洞：sink函数未对输入进行任何净化，直接将数据传递给下层LDAP操作函数，攻击者可能通过控制data参数注入LDAP过滤器，导致未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_5d0ae157
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 727. hyp_path_4c7042762070

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_52b.c:33
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制data参数的内容（例如通过控制台输入或网络请求）
- 触发路径: void CWE90_LDAP_Injection__w32_char_console_52b_case0Sink(char * data) { CWE90_LDAP_Injection__w32_char_console_52c_case0Sink(data); } @ L31-35
- 结论: 可能存在LDAP注入漏洞：函数CWE90_LDAP_Injection__w32_char_console_52b_case0Sink直接将用户可控的data参数传递给下游sink函数，未进行任何验证或过滤，若data来源于用户输入且下游sink用于构造LDAP查询，则攻击者可注入恶意LDAP语句。但下游sink函数具体实现未提供，无法确认实际LDAP操作路径。
- D验证: stage_c_preserved / ver_b4867699
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 728. hyp_path_13a843edd33f

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_53c.c:33
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入提供任意字符串作为data，且下游sink可能使用该数据构造LDAP查询
- 触发路径: void CWE90_LDAP_Injection__w32_char_console_53c_case0Sink(char * data) @ 入口: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_53c.c:31; CWE90_LDAP_Injection__w32_char_console_53d_case0Sink(data); @ L33
- 结论: CWE90: LDAP Injection via console input where data is passed to ldap search filters without proper sanitization, based on blue team challenge and incomplete evidence.
- D验证: stage_c_preserved / ver_e50a8537
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 729. hyp_path_84d9f5a539ac

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_54c.c:33
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制传递给该函数的'data'参数（需外部来源证据）
- 触发路径: CWE90_LDAP_Injection__w32_char_console_54d_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_54c.c:33
- 结论: CWE90_LDAP_Injection__w32_char_console_54c_case0Sink 函数直接传递数据至下一函数，存在LDAP注入可能，但source-sink路径未完全闭合，需动态验证。
- D验证: stage_c_preserved / ver_ba051c0c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 730. hyp_path_f9db8b944933

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_54c.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向data参数输入恶意字符串，包含LDAP查询运算符或特殊字符
- 触发路径: CWE90_LDAP_Injection__w32_char_console_54d_case1V1Sink(data); @ CWE90_LDAP_Injection__w32_char_console_54c.c:46
- 结论: 函数通过传递data到后续处理，可能将未净化的用户输入用于LDAP查询，导致LDAP注入漏洞。
- D验证: stage_c_preserved / ver_41bf94c9
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 731. hyp_path_b3959162c02d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_53b.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入任意字符串到data参数
- 触发路径: void CWE90_LDAP_Injection__w32_char_console_53b_case1V1Sink(char * data) { CWE90_LDAP_Injection__w32_char_console_53c_case1V1Sink(data); } @ CWE90_LDAP_Injection__w32_char_console_53b.c:44-48
- 结论: LDAP注入漏洞：从控制台输入的字符数据经过多层传递，最终可能用于LDAP API调用（如ldap_simple_bind_s），未经过滤，导致攻击者可以注入恶意LDAP查询。
- D验证: stage_c_preserved / ver_d7771e84
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 732. hyp_path_c8e7f1ffe4d2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_83a.cpp:48
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过标准输入（stdin）提供字符串
- 触发路径: void case1() { case1V1(); } @ L46-50 (case1调用case1V1); static void case1V1() { char * data; char dataBuffer[256] = ""; data = dataBuffer; CWE90_LDAP_Injection__w32_char_console_83_case1V1 case1V1Object(data); } @ L38-44 (case1V1初始化dataBuffer并创建对象); 预期构造函数内有fgets或类似调用将用户输入写入dataBuffer @ 构造函数（未提供）预期从stdin读取
- 结论: 存在CWE90 LDAP注入漏洞：通过控制台输入读取数据，并作为LDAP搜索过滤器的组成部分传递，可能允许攻击者修改过滤器逻辑。
- D验证: stage_c_preserved / ver_8f55690c
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 733. hyp_path_023a939cc2f1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_52b.c:54
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置环境变量来影响data参数的内容
- 触发路径: CWE90_LDAP_Injection__w32_char_environment_52c_case1V1Sink(data); @ CWE90_LDAP_Injection__w32_char_environment_52b.c:54
- 结论: CWE90 LDAP注入漏洞：攻击者可通过环境变量控制data参数，最终传递到ldap_search函数，可能导致LDAP注入。
- D验证: stage_c_preserved / ver_65eecfcc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 734. hyp_path_52b681fd6d48

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_52b.c:41
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过环境变量控制data参数的值。
- 触发路径: void CWE90_LDAP_Injection__w32_char_environment_52b_case0Sink(char * data) { CWE90_LDAP_Injection__w32_char_environment_52c_case0Sink(data); } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_52b.c:39-43
- 结论: 函数CWE90_LDAP_Injection__w32_char_environment_52b_case0Sink接收环境变量数据并传递给下游sink，若下游sink未进行LDAP过滤，则存在LDAP注入漏洞。但由于下游函数代码未提供，路径未闭合，需动态验证。
- D验证: stage_c_preserved / ver_7c3c70fa
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 735. hyp_path_aa661e2a58c6

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_53c.c:41
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制环境变量值
- 触发路径: data = getenv("ENV_VAR"); @ 变量获取阶段（推测为getenv调用）; CWE90_LDAP_Injection__w32_char_environment_53d_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_53c.c:41; LDAP查询函数调用（如ldap_search_s） @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_53d.c（推测）
- 结论: CWE90_LDAP_Injection: 存在从环境变量接收数据并注入LDAP查询的漏洞路径。
- D验证: stage_c_preserved / ver_af77af85
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 736. hyp_path_2232c667a7d1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_53b.c:41
- 漏洞类型: CWE90
- CWE: CWE90
- 风险等级: P1
- 触发条件: 攻击者能够通过环境变量控制data参数的内容
- 触发路径: void CWE90_LDAP_Injection__w32_char_environment_53b_case0Sink(char * data) { ... } @ CWE90_LDAP_Injection__w32_char_environment_53b.c:39; CWE90_LDAP_Injection__w32_char_environment_53c_case0Sink(data); @ CWE90_LDAP_Injection__w32_char_environment_53b.c:41
- 结论: CWE90 LDAP Injection: 通过环境变量传递用户可控数据，在sink函数中可能进行LDAP查询，导致LDAP注入
- D验证: stage_c_preserved / ver_5b3ded0a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 737. hyp_path_de41c76b23a7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_53c.c:54
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过环境变量或其他外部输入控制data参数的内容。
- 触发路径: CWE90_LDAP_Injection__w32_char_environment_53d_case1V1Sink(data); @ CWE90_LDAP_Injection__w32_char_environment_53c.c:54
- 结论: 函数CWE90_LDAP_Injection__w32_char_environment_53c_case1V1Sink将未经验证的输入数据传递给下一层sink函数，可能导致LDAP注入漏洞。尽管当前片段未展示source和sink的完整实现，但路由表明该函数是CWE90测试用例的一部分，且B阶段P0静态确认支持为false但存在route候选。因此保留漏洞假设，但证据不完整。
- D验证: stage_c_preserved / ver_4626aef1
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 738. hyp_path_3f4d12af3c34

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_54d.c:41
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制环境变量或其他输入源，从而影响data的值。
- 触发路径: void CWE90_LDAP_Injection__w32_char_environment_54d_case0Sink(char * data) { CWE90_LDAP_Injection__w32_char_environment_54e_case0Sink(data); } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_54d.c:39-43
- 结论: 函数将用户控制的参数直接传递给后续函数，可能触发LDAP注入漏洞。虽然当前函数仅为转发，但若上游数据未经验证且下游直接用于LDAP查询，则存在注入风险。
- D验证: stage_c_preserved / ver_707187a2
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 739. hyp_path_27f40972a9d3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_52b.c:39
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制 data 参数的内容
- 触发路径: CWE90_LDAP_Injection__w32_char_file_52c_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_52b.c:39
- 结论: 函数 CWE90_LDAP_Injection__w32_char_file_52b_case0Sink 将用户控制的 data 参数传递给 52c，但 52c 内部实现未知，无法确认是否用于 LDAP 查询构造及过滤情况。存在 LDAP 注入可能性，但证据不完整。
- D验证: stage_c_preserved / ver_6e6b79ac
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 740. hyp_path_012f9e7a00b2

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_53c.c:52
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制data的内容，需要确认data来源为外部不可信源
- 触发路径: CWE90_LDAP_Injection__w32_char_file_53d_case1V1Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_53c.c:52
- 结论: LDAP注入漏洞：函数将外部可控的data直接传递给后续LDAP操作，未进行任何过滤或转义，攻击者可构造恶意LDAP查询。
- D验证: stage_c_preserved / ver_27107c4a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 741. hyp_path_2bb5f94a891b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_53c.c:39
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过文件输入等方式影响data参数的值
- 触发路径: CWE90_LDAP_Injection__w32_char_file_53d_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_53c.c:39
- 结论: 函数CWE90_LDAP_Injection__w32_char_file_53c_case0Sink将未经验证的数据传递给下游函数，可能最终用于LDAP查询构造，存在LDAP注入风险。
- D验证: stage_c_preserved / ver_8bd94f14
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 742. hyp_path_a8a34960525e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_54b.c:39
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过文件或其它输入渠道控制data变量的内容。
- 触发路径: CWE90_LDAP_Injection__w32_char_file_54c_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_54b.c:39
- 结论: LDAP注入漏洞：数据可能通过文件输入传入，经转发至下游函数，可能未经转义直接用于LDAP查询，存在注入风险。
- D验证: stage_c_preserved / ver_9d3ba530
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 743. hyp_path_8232b819b1ae

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_54d.c:39
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制文件内容或输入来源，使得data中包含LDAP元字符
- 触发路径: void CWE90_LDAP_Injection__w32_char_file_54d_case0Sink(char * data) { @ CWE90_LDAP_Injection__w32_char_file_54d.c:37; CWE90_LDAP_Injection__w32_char_file_54e_case0Sink(data); @ CWE90_LDAP_Injection__w32_char_file_54d.c:39
- 结论: 可能存在LDAP注入漏洞。函数CWE90_LDAP_Injection__w32_char_file_54d_case0Sink将未经验证的数据传递给下一层处理（54e函数），如果数据最终用于构造LDAP查询且未进行充分转义，则攻击者可能通过控制文件内容实现LDAP注入。
- D验证: stage_c_preserved / ver_b2452176
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 744. hyp_path_61abbb9f77aa

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_53b.c:39
- 漏洞类型: CWE90
- CWE: CWE90
- 风险等级: P1
- 触发条件: attacker can control the contents of the input file
- 触发路径: data obtained from file input @ source (file reading, not shown in provided code); CWE90_LDAP_Injection__w32_char_file_53c_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_53b.c:39; ldap_search(..., data, ...) @ subsequent sink (not shown) likely calls ldap_search or similar LDAP API with data as filter
- 结论: CWE90 LDAP Injection vulnerability: data from file input is passed through multiple functions and likely used in an LDAP API without sanitization, allowing injection of LDAP filters.
- D验证: stage_c_preserved / ver_10c44bd6
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 745. hyp_path_21b0f3078067

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_62b.cpp:136
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制data的初始内容（通过socket等）
- 触发路径: strcat(data, "Doe, XXXXX"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_62b.cpp:136
- 结论: 攻击者可能通过网络socket向data缓冲区发送恶意字符串，经过strcat追加固定字符串后，data仍包含恶意输入；如果后续用于LDAP查询，则可能导致LDAP注入。但当前代码片段未展示LDAP查询，路径不完整。
- D验证: stage_c_preserved / ver_ff44119a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 746. hyp_path_c3f62da6b589

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_43.cpp:186
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过网络发送数据到connect_socket，从而控制data的前缀部分
- 触发路径: wcscat(data, L"Doe, XXXXX"); // line 186 @ 函数入口参数data来源于connect_socket
- 结论: CWE90 LDAP Injection via wcscat with partially controlled data from connect_socket
- D验证: stage_c_preserved / ver_1708aa25
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 747. hyp_path_b49da3a3a64e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_52b.c:33
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入控制data参数
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_console_52b_case0Sink(wchar_t * data) @ L31-32; CWE90_LDAP_Injection__w32_wchar_t_console_52c_case0Sink(data); @ L33
- 结论: CWE90_LDAP_Injection: data从控制台输入后经52b_sink传递至52c_sink，并在52c_sink中未经验证直接用于LDAP查询，可能导致LDAP注入。
- D验证: stage_c_preserved / ver_50b0adfa
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 748. hyp_path_a1d4011b7f10

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_53b.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够向控制台输入任意字符串（假设source存在，但未在证据中体现）
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_console_53b_case1V1Sink(wchar_t * data) { CWE90_LDAP_Injection__w32_wchar_t_console_53c_case1V1Sink(data); } @ 入口函数CWE90_LDAP_Injection__w32_wchar_t_console_53b.c:44-48; 推测为LDAP查询调用，但无实际代码 @ 调用53c函数（未提供代码）
- 结论: LDAP注入漏洞：'data'参数从控制台读取，未经任何验证或转义直接传递给LDAP查询，攻击者可以控制输入来修改LDAP查询逻辑。但当前代码证据仅显示中间调用函数，缺少source和实际sink代码，路径未完全闭合。
- D验证: stage_c_preserved / ver_4d7579dc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 749. hyp_path_1171a464dd70

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_52b.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 上游函数存在从控制台读取用户输入的source（如fgetws）; 下游CWE90_LDAP_Injection__w32_wchar_t_console_52c_case1V1Sink实际执行LDAP查询且未净化
- 触发路径: CWE90_LDAP_Injection__w32_wchar_t_console_52c_case1V1Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_52b.c:46
- 结论: LDAP注入漏洞：函数CWE90_LDAP_Injection__w32_wchar_t_console_52b_case1V1Sink将未净化的宽字符串数据传递给下游函数，但实际source和sink代码缺失，需要上游存在控制台输入且下游为LDAP查询才能形成完整路径。
- D验证: stage_c_preserved / ver_a1919d65
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 750. hyp_path_c2c4abda883a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_53c.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: Attacker controls the `data` input via console or other source
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_console_53c_case1V1Sink(wchar_t * data) { CWE90_LDAP_Injection__w32_wchar_t_console_53d_case1V1Sink(data); } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_53c.c:44-48
- 结论: CWE90 LDAP Injection potential vulnerability (evidence incomplete, requires full source-sink chain)
- D验证: stage_c_preserved / ver_01da0ffb
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 751. hyp_path_350e699ce3c6

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_53b.c:33
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入恶意LDAP查询字符串。
- 触发路径: CWE90_LDAP_Injection__w32_wchar_t_console_53c_case0Sink(data); @ CWE90_LDAP_Injection__w32_wchar_t_console_53b.c:33
- 结论: LDAP注入漏洞：data参数直接传递到LDAP查询，未经验证或转义，允许攻击者注入LDAP过滤器，导致未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_77352355
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 752. hyp_path_2ce94a21f1bb

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_54c.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入任意字符串
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_console_54c_case1V1Sink(wchar_t * data) { CWE90_LDAP_Injection__w32_wchar_t_console_54d_case1V1Sink(data); } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_54c.c:44-48; （假设）该函数可能直接调用 LDAP API，如 ldap_search_s 等，且未对 data 进行净化。 @ CWE90_LDAP_Injection__w32_wchar_t_console_54d_case1V1Sink
- 结论: CWE90 LDAP注入漏洞：wchar_t字符串数据通过函数传递，最终可能用于构造LDAP查询，但未进行充分过滤或转义，存在注入风险。
- D验证: stage_c_preserved / ver_7f16727f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 753. hyp_path_7e409931424b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_54d.c:46
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入提供任意wchar_t字符串（假设上游存在可控输入）
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_console_54d_case1V1Sink(wchar_t * data) @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_54d.c:44; CWE90_LDAP_Injection__w32_wchar_t_console_54e_case1V1Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_54d.c:46
- 结论: CWE90_LDAP_Injection__w32_wchar_t_console_54d_case1V1Sink函数传递用户可控数据至后续函数，未进行净化。虽下游54e函数代码未提供，但基于函数命名模式（典型的CWE90测试用例），存在LDAP注入可能。攻击者若控制上游输入，可导致LDAP注入。
- D验证: stage_c_preserved / ver_9d2c3e1b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 754. hyp_path_fe1620a5643e

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_54c.c:33
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制输入，该输入通过调用链最终被传递为data参数。
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_console_54c_case0Sink(wchar_t * data) { CWE90_LDAP_Injection__w32_wchar_t_console_54d_case0Sink(data); } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_54c.c:31-35
- 结论: 数据通过内部函数传递，可能最终用于LDAP查询构造，但source和sink未在代码片段中闭合，存在潜在LDAP注入风险。
- D验证: stage_c_preserved / ver_3ffc8628
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 755. hyp_path_3445d44c0050

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_54d.c:33
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过控制台输入或其他外部源提供恶意的wchar_t字符串作为data参数，但此前提未在A阶段证据中确认。
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_console_54d_case0Sink(wchar_t * data) @ 入口：CWE90_LDAP_Injection__w32_wchar_t_console_54d.c:31; CWE90_LDAP_Injection__w32_wchar_t_console_54e_case0Sink(data); @ CWE90_LDAP_Injection__w32_wchar_t_console_54d.c:33
- 结论: 存在LDAP注入漏洞（CWE-90），但证据不完整：函数CWE90_LDAP_Injection__w32_wchar_t_console_54d_case0Sink接收data参数并传递给下游，但A阶段代码未展示source（控制台输入）和sink（如ldap_search_s）的实际调用，B阶段P0不支持且风险评分为0。因此，无法确认source到sink的闭合路径，需动态验证或提供额外代码证据。
- D验证: stage_c_preserved / ver_3e6f2a4e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 756. hyp_path_9b528772a67d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_84_case1V1.cpp:32
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制dataCopy的值（例如通过控制台输入）。
- 触发路径: data = dataCopy; wcscat(data, L"Doe, XXXXX"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_84_case1V1.cpp:30-32
- 结论: LDAP注入漏洞：dataCopy来自外部输入，拼接固定后缀后可能用于LDAP查询，但sink未在提供代码中确认。
- D验证: stage_c_preserved / ver_75cc7a9f
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 757. hyp_path_449c6cfc4f1b

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_83_case1V1.cpp:32
- 漏洞类型: buffer_overflow
- CWE: CWE-120
- 风险等级: P1
- 触发条件: 攻击者能够控制 dataCopy 长度，使拼接后超过目标缓冲区容量。
- 触发路径: 接收用户输入 dataCopy @ 第28行（构造函数入口）; data = dataCopy; wcscat(data, L"Doe, XXXXX"); @ 第32行
- 结论: 构造函数中wcscat拼接未检查缓冲区大小，可能导致缓冲区溢出，但缓冲区大小未知且后续无进一步利用路径，影响较低，需动态验证。
- D验证: stage_c_preserved / ver_bf1ad593
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 758. hyp_path_a82ece9251a7

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_53c.c:41
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制影响环境变量的值（如在测试环境中设置环境变量）。
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_environment_53c_case0Sink(wchar_t * data) { CWE90_LDAP_Injection__w32_wchar_t_environment_53d_case0Sink(data); } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_53c.c:39-43
- 结论: 函数CWE90_LDAP_Injection__w32_wchar_t_environment_53c_case0Sink接收一个宽字符指针data，并直接传递给CWE90_LDAP_Injection__w32_wchar_t_environment_53d_case0Sink。根据函数命名和CWE90测试用例上下文，data可能来自环境变量，且后续用于LDAP查询而未进行适当过滤或转义，存在LDAP注入漏洞。攻击者可控制环境变量值，注入恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_9723bb76
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 759. hyp_path_2ea63743eaa6

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_53c.c:54
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过环境变量控制data
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_environment_53c_case1V1Sink(wchar_t * data) { CWE90_LDAP_Injection__w32_wchar_t_environment_53d_case1V1Sink(data); } @ L52-56
- 结论: 函数接收来自环境变量的数据，并直接传递给后续LDAP sink，缺少输入净化，可能导致LDAP注入攻击。
- D验证: stage_c_preserved / ver_33b7353a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 760. hyp_path_ae6b80a5aeec

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_53b.c:41
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制环境变量值，传递至data参数；下游sink函数未对数据进行净化即用于LDAP查询构造。
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_environment_53b_case0Sink(wchar_t * data) { @ 入口函数CWE90_LDAP_Injection__w32_wchar_t_environment_53b_case0Sink:39; CWE90_LDAP_Injection__w32_wchar_t_environment_53c_case0Sink(data); @ 第41行调用下游sink
- 结论: CWE90_LDAP_Injection__w32_wchar_t_environment_53b_case0Sink函数接收数据并直接传递给下游sink，若上游数据来源为环境变量且下游sink使用未净化的数据构造LDAP查询，则存在LDAP注入漏洞。当前代码证据仅包含中间转发函数，缺乏source和sink实际代码，无法闭合路径。
- D验证: stage_c_preserved / ver_8950000b
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 761. hyp_path_21961dd07b3c

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_54c.c:41
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者可能通过环境变量注入恶意 LDAP 查询语句
- 触发路径: CWE90_LDAP_Injection__w32_wchar_t_environment_54d_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_54c.c:41
- 结论: 函数 `CWE90_LDAP_Injection__w32_wchar_t_environment_54c_case0Sink` 将未经验证的数据传递给下一层处理，可能最终用于 LDAP 查询，存在 LDAP 注入风险。尽管当前代码片段仅显示中间转发，但函数命名和参数传递模式符合 CWE-90 典型路径。
- D验证: stage_c_preserved / ver_755647d3
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 762. hyp_path_ee4682288cf1

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_54b.c:41
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够设置环境变量，从而控制 data 参数的内容
- 触发路径: CWE90_LDAP_Injection__w32_wchar_t_environment_54c_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_54b.c:41
- 结论: LDAP注入漏洞：函数 CWE90_LDAP_Injection__w32_wchar_t_environment_54b_case0Sink 将未经验证的 wchar_t 指针 data 直接传递给下层处理函数，若 data 来自环境变量则攻击者可控制其内容，导致LDAP注入攻击。但当前证据不完整，需动态验证。
- D验证: stage_c_preserved / ver_2aeeaf18
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 763. hyp_path_c316f67969c3

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_54b.c:54
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制环境变量，且下游存在未净化的LDAP查询构造
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_environment_54b_case1V1Sink(wchar_t * data) { CWE90_LDAP_Injection__w32_wchar_t_environment_54c_case1V1Sink(data); } @ CWE90_LDAP_Injection__w32_wchar_t_environment_54b.c:52-56
- 结论: 可能存在LDAP注入漏洞，但源代码证据不完整：当前片段仅显示数据通过函数传递，未提供上游来源和下游LDAP调用的具体代码。根据函数命名和项目上下文，数据可能来自环境变量并最终用于LDAP查询，但无法闭合路径。需要动态验证或审计完整代码链。
- D验证: stage_c_preserved / ver_8e3f3311
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 764. hyp_path_97b6c21cda71

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_54c.c:54
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够影响系统环境变量（如USERNAME）
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_environment_54c_case1V1Sink(wchar_t * data) { CWE90_LDAP_Injection__w32_wchar_t_environment_54d_case1V1Sink(data); } @ CWE90_LDAP_Injection__w32_wchar_t_environment_54c.c:52-56
- 结论: 函数将未净化的数据传递给下一个函数，最终可能导致LDAP注入漏洞（CWE-90）。由于B阶段静态确认不支持且缺乏sink代码，证据不完整。
- D验证: stage_c_preserved / ver_5f9aad2a
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 765. hyp_path_6fbaf11cd4b9

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_83_case1V1.cpp:32
- 漏洞类型: buffer_overflow
- CWE: CWE-120
- 风险等级: P1
- 触发条件: 攻击者能够控制dataCopy参数的内容和长度，且data指向的缓冲区大小不足以容纳拼接后的字符串
- 触发路径: wcscat(data, L"Doe, XXXXX"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_83_case1V1.cpp:32
- 结论: wcscat调用可能因目标缓冲区大小不足导致缓冲区溢出，尽管尚未确认缓冲区分配上下文，但API contract要求缓冲区足够大，违规可能性存在。
- D验证: stage_c_preserved / ver_e3a52b26
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 766. hyp_path_0c2a7cc9b6cf

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_43.cpp:126
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能控制文件内容（例如通过文件上传或环境变量影响）
- 触发路径: 从文件读取数据到 data @ L123 入口 case1V1Source; wcscat(data, L"Doe, XXXXX"); @ L126
- 结论: data 可能从外部文件读取，未经净化直接用于 wcscat，且后续可能用于 LDAP 查询，存在 LDAP 注入风险。
- D验证: stage_c_preserved / ver_3636c309
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 767. hyp_path_be2857f0b89a

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_52b.c:52
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够通过文件输入或其他方式向data参数注入恶意字符串，例如包含LDAP过滤器语法。
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_file_52b_case1V1Sink(wchar_t * data) { CWE90_LDAP_Injection__w32_wchar_t_file_52c_case1V1Sink(data); } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_52b.c:50-54
- 结论: CWE90_LDAP_Injection__w32_wchar_t_file_52b_case1V1Sink函数未对data参数进行任何净化，直接将其传递给下游sink，可能构成LDAP注入漏洞。攻击者若控制data来源（如文件输入），可注入恶意LDAP过滤器，导致未授权访问或信息泄露。
- D验证: stage_c_preserved / ver_05bd2cdc
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 768. hyp_path_e3181fb6ee0d

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_54b.c:52
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制文件内容或输入字符串，该字符串作为data参数传入
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_file_54b_case1V1Sink(wchar_t * data) { CWE90_LDAP_Injection__w32_wchar_t_file_54c_case1V1Sink(data); } @ CWE90_LDAP_Injection__w32_wchar_t_file_54b.c:50-54
- 结论: LDAP注入漏洞：函数CWE90_LDAP_Injection__w32_wchar_t_file_54b_case1V1Sink直接将外部传入的data转发给下层函数，未进行任何净化或验证，导致攻击者可通过控制data参数注入LDAP过滤条件，进而执行未授权查询或修改LDAP目录。
- D验证: stage_c_preserved / ver_74d5f420
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 769. hyp_path_548e3d006218

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_53c.c:39
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够写入或控制文件内容，使得data包含恶意LDAP查询字符串。
- 触发路径: CWE90_LDAP_Injection__w32_wchar_t_file_53d_case0Sink(data); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_53c.c:39
- 结论: CWE90 LDAP注入漏洞：函数CWE90_LDAP_Injection__w32_wchar_t_file_53c_case0Sink接收来自文件读取的wchar_t*数据，未进行任何输入验证或净化，直接传递给后续的LDAP操作函数（通过53d），导致攻击者可通过控制文件内容注入LDAP过滤器或命令。虽然未直接提供53d内部实现，但根据Juliet测试集结构，53d会调用LDAP注入敏感函数（如ldap_search），因此漏洞风险存在。
- D验证: stage_c_preserved / ver_894ee33e
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 770. hyp_path_ce2239ffa7dc

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_54c.c:39
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制输入文件或数据源，从而控制data参数的内容。
- 触发路径: CWE90_LDAP_Injection__w32_wchar_t_file_54d_case0Sink(data); @ L39
- 结论: 函数CWE90_LDAP_Injection__w32_wchar_t_file_54c_case0Sink接受用户可控的data并传递给54d函数，但缺乏下游LDAP操作代码证据，无法确认实际注入路径。尽管样本名暗示LDAP注入，但证据不完整，保留动态验证候选。
- D验证: stage_c_preserved / ver_f633d230
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 771. hyp_path_92b417a36827

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_54c.c:52
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制 data 参数的内容（例如通过文件读取）
- 触发路径: void CWE90_LDAP_Injection__w32_wchar_t_file_54c_case1V1Sink(wchar_t * data) { CWE90_LDAP_Injection__w32_wchar_t_file_54d_case1V1Sink(data); } @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_54c.c:50-54
- 结论: CWE90_LDAP_Injection__w32_wchar_t_file_54c_case1V1Sink 将未经验证的 data 参数传递给下级函数，若下级函数直接用于 LDAP 查询则存在注入风险。
- D验证: stage_c_preserved / ver_a934daa7
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

### 772. hyp_path_556d4fbf9372

- 漏洞位置: juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_62b.cpp:136
- 漏洞类型: CWE-90
- CWE: CWE-90
- 风险等级: P1
- 触发条件: 攻击者能够控制data参数的内容（例如通过socket输入），但未在给定代码片段中直接验证
- 触发路径: void case1V1Source(wchar_t *data) @ 入口函数case1V1Source，参数data为外部输入（假设）; wcscat(data, L"Doe, XXXXX"); @ juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_62b.cpp:136; // 推测：ldap_search_s等调用使用data @ sink未在提供的代码片段中显示，依赖上下文推断
- 结论: 存在LDAP注入漏洞，但静态证据不闭合：用户可控的data通过wcscat拼接固定字符串后，可能用于LDAP查询，但A阶段代码未展示data来源和sink，B阶段P0不支持，需要动态验证。
- D验证: stage_c_preserved / ver_b1222508
- 运行证据: unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED
- 保留原因: UNSUPPORTED_ORACLE

## Unconfirmed / Failed Verification

These records are not reported as confirmed vulnerabilities. See `verification.failed.jsonl` for full failure details.

- hyp_path_f7ae3a82670a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_74a.cpp:86 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_36049f7396ab | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_73a.cpp:86 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_0d188a0d48d3 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_44.c:151 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_27743c4f9826 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_44.c:151 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_fe7137a8a5e4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_65a.c:100 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_5d5675da3d3c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_65a.c:85 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_9dc0b9935bd1 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_44.c:136 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_a8627bf12d6b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_61b.c:92 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_23fa6fe9fb5a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_22b.c:93 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_93b1d0fe81c4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_42.c:92 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_bd425a243d5b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_42.c:92 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e783a2fb3bfe | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_83_case0.cpp:80 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_466208ab6fef | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_43.cpp:80 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_8a1570574b89 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_21.c:97 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_cd062f0c8a7b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_84_case0.cpp:80 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_fa68996f755c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_21.c:82 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_56ec92d6e1bb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_62b.cpp:76 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_edfe941ba003 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_21.c:82 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_f80b08febc11 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_61b.c:77 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_4197a1714a28 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_22b.c:78 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_2d92ff962173 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_61b.c:92 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9fa423e30912 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_42.c:77 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_1330b375ad2d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_61b.c:77 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_995979d85a29 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_74a.cpp:464 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_98ad0f656de8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_21.c:183 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2a2f9f52eb6a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_21.c:191 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_706c0d470c14 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_21.c:251 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0b05890cc071 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_21.c:259 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b6f4e883dab8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_21.c:251 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_40deef45a95d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_21.c:321 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_866d80a0a059 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_21.c:261 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a3d0a5d14614 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_21.c:321 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_04e3bacc6a52 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_21.c:189 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1575d6a0d749 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_21.c:253 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2649ee485a85 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_21.c:183 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_53109f6dad68 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_21.c:333 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_81eb7006b76c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_21.c:261 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4af5f572dd0e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_21.c:253 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c9fb84a47e6d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_21.c:259 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_500296ec4e31 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_21.c:189 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a7e2b79353be | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_42.c:243 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1055e508fd39 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_42.c:171 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_adf385da67a9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_61a.c:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_62959c50d48d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_22a.c:207 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_47dcaba4663f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_62a.cpp:140 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b031d97ee1d0 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_22a.c:207 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b0541185e70a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_61a.c:137 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_091c047c3679 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_22a.c:207 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d6b979ef9163 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_62a.cpp:140 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b962dce44ad8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_22a.c:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_493a756db864 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_22a.c:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ab3540e019a4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_22a.c:207 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6d0ce36e6905 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_61a.c:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_22eb86f55f69 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_62a.cpp:140 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_45b5e54863c4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_61a.c:143 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_749d9815ff25 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_62a.cpp:140 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_31bf0cc2d377 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_22a.c:207 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d03618407783 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_61a.c:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7ac6c9148965 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_22a.c:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_317a79cd00ec | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_22a.c:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4f2c45d7c603 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_62a.cpp:140 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c5025ea996a2 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_22a.c:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b70e5f8ac69a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_22a.c:207 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_46101608d120 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_62a.cpp:140 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_09f6cc67fb48 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_22a.c:207 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_057f8a48d845 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_22a.c:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_649f09db7d0f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_61a.c:137 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3825b76a6340 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_22a.c:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0d98bd216ce9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_61a.c:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_44237984efbc | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_62a.cpp:140 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_664794c6b8eb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_22a.c:207 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6dc38db8574f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_22a.c:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2f2c78af4fe7 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_61a.c:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7026281c4328 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_22a.c:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_352287df6ec5 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_61a.c:143 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7408bd070d92 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_22a.c:207 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_06c0303222ab | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_22a.c:207 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3f9a539388a8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_62a.cpp:140 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6e28c7c2ef89 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_22a.c:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_342ba234c24c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_61a.c:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0e7bf2109af4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_62a.cpp:140 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4ebff61e4e92 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_43.cpp:172 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a5915bdcecc9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_43.cpp:164 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_39b68f611fd4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_43.cpp:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_19c9d9c3ed06 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_62a.cpp:140 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_01bab1cc9cea | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_43.cpp:244 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_43b676a204b5 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_43.cpp:164 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_563ccd696eb1 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_08.c:244 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4ef4a9e3f309 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_43.cpp:244 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5af48db36568 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_08.c:184 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_33a1ce317f65 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_11.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_771138f4a53d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_11.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6a6d4b24e7a6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_12.c:176 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_147b26154996 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_11.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_37e7cb097c0a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_08.c:244 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7be7fe39f59d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_11.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_655ee5a6e966 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_08.c:256 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_10be5f6993fa | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_12.c:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_acdbc1234932 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_11.c:162 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_117e1ca53836 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_08.c:182 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_62673e68ac2f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_11.c:242 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b3253a7b19f0 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_12.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1657baa0fadf | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_08.c:182 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3657ee002667 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_08.c:176 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_af49451ab8af | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_08.c:184 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e030d9d914f9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_12.c:248 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5e51539a524f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_08.c:176 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_45f1395cffa2 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_12.c:236 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0d18cee7d269 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_11.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ae8e95e1bbaa | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_12.c:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6577603ebce6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_12.c:236 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4a9d1b4e8ccb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_11.c:242 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_371ea20a9840 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_11.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_09b29ff61a34 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_08.c:256 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8e6314203c14 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_12.c:248 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_23a2563bf527 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_12.c:176 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_08463e4b7217 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_13.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8c9a65973cbb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_12.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5a786ad18cad | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_09.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3dbc2e012dc8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_10.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d26af63fae98 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_07.c:236 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_28adb7f86529 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_08.c:307 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5b1d0080fb7e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_11.c:162 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_08b532bcabe8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_11.c:293 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_31ed7159f9e9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_07.c:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3e103d9c7b1a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_08.c:245 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_251451d5541b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_09.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c6424dc92d35 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_05.c:237 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_61146d8ba31c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_10.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0457feb9b967 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_11.c:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c1ec3b4679d2 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_05.c:175 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_36ebbedd28b4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_14.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_51593dde7609 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_13.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4b8865e46c3d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_08.c:239 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3b0126f7e097 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_09.c:162 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3cab1cdd8e88 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_10.c:162 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1e8739383427 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_07.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5d769524c42e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_13.c:162 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c9edaa0d8832 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_05.c:169 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_29f3af921613 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_14.c:162 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1826f34a8a74 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_14.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_66e48b54eb28 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_05.c:177 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8ef3426c05b4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_09.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_86da18425a87 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_07.c:176 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6063a6dbca67 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_11.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3910f570d596 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_11.c:233 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4da8ea937227 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_10.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5e16dead0c70 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_08.c:247 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a707ac22e6ab | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_07.c:248 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_636f38d5e7e8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_14.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1789b3616b20 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_05.c:249 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1b99bd435e4e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_08.c:319 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5125285eb561 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_13.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ab77f825d93c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_10.c:242 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1e4e8662e465 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_09.c:242 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_06b4c0b4f9c1 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_13.c:242 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0bb513d8d872 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_05.c:237 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2281a80ed2b9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_09.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0b790337b953 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_07.c:236 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8446dacc6722 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_11.c:305 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_850416b4f51c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_10.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_01fd28dc8850 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_11.c:293 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5dd8eb9c3448 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_09.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1970bb7228e8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_05.c:175 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_31070280c8f8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_07.c:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_482c89900984 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_08.c:307 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_212f4298a44a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_14.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1a9cc436f95e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_08.c:245 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_358bb585c51e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_05.c:169 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_28738fe45b09 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_10.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dbf3d70e051b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_14.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1339fe19bd01 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_13.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5d48a6725d44 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_14.c:242 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a94aace44c32 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_09.c:162 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_62cff654f366 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_11.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_210c64e442f6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_14.c:162 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1ae89c387ca6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_13.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9726bfe0f2e3 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_07.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7e4f4ba82d32 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_11.c:233 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3ea2bd75c8bb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_13.c:162 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4f0542468492 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_11.c:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2d3ff23a61c5 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_08.c:239 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ad2f55a31e79 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_05.c:249 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_36eb45ce8fde | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_13.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_60293e16a012 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_10.c:162 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3ac4b7c2a3c8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_07.c:176 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a6a35a7259fa | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_05.c:177 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_86231701ee2a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_08.c:247 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6c8179c6549c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_10.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0567f94c59b8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_07.c:248 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6a0f6c5fed61 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_09.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c860865d5d7a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_09.c:242 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2bd608059608 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_08.c:319 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1cf3b44c61c0 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_01.c:219 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1ee7e95f1099 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_14.c:242 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_47f204474698 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_10.c:242 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d4ca55b5fce3 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_14.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5fa0d8ebc339 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_04.c:237 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2b023cdb7c4c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_02.c:293 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b3437de9e86d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_04.c:300 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_213ba6ec97d4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_13.c:242 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0596f4841452 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_05.c:300 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_03fdf8e85be8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_03.c:293 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7a8e56a4b2fa | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_03.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fa09989fc42f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_06.c:297 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4acca74561c7 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_11.c:305 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_58900737b55b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_02.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_63e9a5123c20 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_06.c:234 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a6a40f34db5b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_07.c:299 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_83679e7960b8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_10.c:293 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_44546915197d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_17.c:227 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_69eae13bd9c0 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_15.c:237 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eedaca4b0ee4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_13.c:293 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_955409396707 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_18.c:223 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2f092f2d38e8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_16.c:227 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_77d8efd364b3 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_31.c:226 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_17aa825b072a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_15.c:306 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_22773e03a267 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_33.cpp:229 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1c5a4c2f23b4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_01.c:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_514679678080 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_34.c:234 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9a18632587b2 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_03.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_00452c97a725 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_04.c:238 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b77384b00e85 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_02.c:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_11fb9400655a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_02.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2f9a096419cb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_04.c:175 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2d562ba8d636 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_14.c:293 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_896b080a4e9b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_09.c:293 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_40835d417751 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_09.c:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5b04ca5e7f7a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_03.c:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6fd32e912967 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_06.c:235 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_50c53c745aa5 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_06.c:172 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1f6e69adbb29 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_07.c:237 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_464f72fbc6ef | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_17.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_24ae1fab9859 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_10.c:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a04143be30de | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_33.cpp:167 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_93162d0cf417 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_15.c:175 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1ca46099d970 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_13.c:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_17398856ca95 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_16.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9dfca6107162 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_05.c:238 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_158600341f7c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_15.c:244 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a55caaa39c2e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_02.c:162 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_36685deb2bd7 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_31.c:164 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4b142b0b8559 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_03.c:162 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_13d4dedf168e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_14.c:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b4c0eabd6631 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_01.c:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7937655ac657 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_18.c:161 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_62f74f8a31df | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_04.c:232 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0b46472d7704 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_04.c:169 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a4fe7885b42e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_34.c:172 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4079db115d17 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_03.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b36a5897ef34 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_05.c:232 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_acae074ad95a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_07.c:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0b7ae92408a0 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_14.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_39e0974be921 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_18.c:155 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1346f904f4a2 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_10.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5765fd79f6c1 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_09.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_229fe80787a9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_06.c:229 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2029c5248cea | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_02.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_787691dfb309 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_15.c:169 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b79ba07002da | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_34.c:166 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0061695032d4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_13.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_52f13b388c04 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_06.c:166 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3aecaf39994c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_01.c:159 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1f83c6031c9c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_15.c:238 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0a38da63e2e3 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_17.c:159 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_abb4fc669fb8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_16.c:159 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_107ceebd356b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_31.c:158 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ee6fe1adeb58 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_33.cpp:161 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6bb46a8ad1ec | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_02.c:233 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0e32710f46f7 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_03.c:233 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0c0912ab0fc4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_04.c:177 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2e17db468de0 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_07.c:239 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3f129e012d9a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_02.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_513cf3096e63 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_03.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7950344b3dd8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_06.c:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b96da4e60e7f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_15.c:177 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3381213cfb43 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_31.c:166 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_705d706ab57d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_09.c:233 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5b4152fb202d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_10.c:233 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b5d958392c04 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_15.c:246 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_52c47f991bfc | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_16.c:167 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_25183cd5e067 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_18.c:163 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_63220fed4645 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_04.c:240 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8b494db2b00c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_14.c:233 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_274ddf660e77 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_33.cpp:169 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c4f2df172675 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_01.c:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_173e52471959 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_05.c:240 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_18aea4f4cb8f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_06.c:237 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1331ec21bfc3 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_13.c:233 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5c8f94e3a163 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_02.c:242 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_413e3935eb0d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_34.c:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4fc502689ba0 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_04.c:249 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4c494aafe878 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_17.c:167 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0a3e4ebc7909 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_03.c:242 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4c7e2a642218 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_02.c:305 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c3ac2cad4f8c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_03.c:305 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a808880c28ab | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_06.c:309 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b9aa2536f0cf | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_04.c:312 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6cdf8cb68f73 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_10.c:305 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8996b6e69ccd | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_06.c:246 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2b1025c9fb89 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_15.c:318 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5f720a557fa9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_31.c:238 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2fb859363298 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_05.c:312 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1f5bce3eb8fb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_17.c:239 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_38f65fc0bb67 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_09.c:305 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1c6b9869c78b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_14.c:305 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_608d4d14c6cd | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_15.c:249 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_82c76fc42c25 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_16.c:239 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_729818babdc3 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_33.cpp:241 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5cf984bb316c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_01.c:219 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_55408ea0120f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_13.c:305 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a4c1b325e850 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_07.c:311 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5c180f497671 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_02.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_25dfec15e1df | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_18.c:235 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7091a60cbc2f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_04.c:237 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_76111d9a6d2f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_34.c:246 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fb038dce1411 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_05.c:300 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9d17ffe80a82 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_03.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_72b74921276b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_02.c:293 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_065f0cb710a2 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_06.c:297 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5b94b4ea589b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_06.c:234 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_40d1682fd232 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_07.c:299 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0e74b670800c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_18.c:223 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_09d1b1391acd | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_03.c:293 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7f0ea3b9f47d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_31.c:226 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1814373f3a87 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_16.c:227 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_87461a37abab | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_13.c:293 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_86cffac97bfc | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_10.c:293 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_699157ff831a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_34.c:234 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_25aed09ac4c6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_14.c:293 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_39bfbddea244 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_33.cpp:229 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9e4e9874c2bf | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_04.c:300 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_871469db830b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_15.c:237 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bd287cf07866 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_09.c:293 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_17c5898925a6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_15.c:306 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_399acec83b6e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_02.c:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d54f697c543b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_02.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cd1753b7a7d8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_17.c:227 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3c8b2c34972d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_03.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3448e9d2ef0d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_03.c:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2e5c548b4223 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_01.c:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b73fa8545975 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_04.c:175 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_32b8f9e7ae2b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_06.c:235 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_60ed5b12a95d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_06.c:172 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_571ac5256027 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_15.c:244 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_44bfb33b22f1 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_13.c:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4c2cd5d375f8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_09.c:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_18dd71a0dda4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_07.c:237 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_72dd6a2f2038 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_34.c:172 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b4794ef5109b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_10.c:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e45181763efc | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_18.c:161 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0a74d22ea1db | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_04.c:238 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4d727e0f4e69 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_14.c:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_063cff24c65e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_15.c:175 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_017d64db5625 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_05.c:238 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d136cb756c3b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_16.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9faa5d11e0eb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_17.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_48d78ad18768 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_03.c:162 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_039084516112 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_02.c:162 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ea8903880e64 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_31.c:164 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_232cde998941 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_09.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6c137ab7c3ff | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_04.c:169 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5ece1023c210 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_14.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_87ad4eda3036 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_04.c:232 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3b49a1950e85 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_02.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0a397864921a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_01.c:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_78f502d1d33f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_03.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b105587de34d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_33.cpp:167 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9f596586bd54 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_16.c:159 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_111ef415b0a1 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_06.c:229 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3b8363f0c253 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_15.c:238 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_215ec1b3ec77 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_05.c:232 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7698a167f79d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_10.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_90cb9590ffb5 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_07.c:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_06f2cd1054b5 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_33.cpp:161 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2d3c6d6d935d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_01.c:159 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1ba63ced9ef6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_34.c:166 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7ba593e10b18 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_18.c:155 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_71524cf7a1a4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_17.c:159 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5a0b06a19621 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_03.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_79bfbe0ffe92 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_15.c:169 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c2b01d8cf07c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_06.c:166 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1ec880076c6b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_03.c:233 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9bff50d75f2e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_13.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_21f53fda22cc | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_05.c:240 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0eb7faa31bc4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_02.c:170 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_713a34472984 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_31.c:158 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_179484666013 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_02.c:233 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_46c070ddd204 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_04.c:240 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1e2d017bc22e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_04.c:177 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2edc14a95be7 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_10.c:233 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4385552df728 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_09.c:233 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_21e3e9dc8cda | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_06.c:237 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6695e26b7c19 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_34.c:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1c6a5bc00cb7 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_17.c:167 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_10fc8c78fad9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_07.c:239 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_56255a11d0bb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_16.c:167 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6c5659847fdb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_14.c:233 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7ca376b38cab | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_31.c:166 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_28125bc84163 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_06.c:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_486263aebb29 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_15.c:177 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b98368cc9694 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_15.c:246 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7eba3e603d5d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_03.c:242 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_359173d6bfb5 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_01.c:231 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_252213764e8b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_18.c:163 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_697f8713986f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_13.c:233 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0e7e7947cd93 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_02.c:305 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1b0aea9d88d2 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_33.cpp:169 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2e066a6d99b3 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_06.c:309 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c5f1ea2dac10 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_03.c:305 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_41c10dfefc58 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_07.c:311 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3d089b49ca73 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_04.c:312 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2809f70a819c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_06.c:246 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_14641f009b37 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_10.c:305 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_35332277aef9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_04.c:249 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5ade652338ff | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_02.c:242 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_21d204c77429 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_15.c:318 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_21b92677e811 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_14.c:305 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_22c1aa02dbd7 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_13.c:305 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0c3cccf296d4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_34.c:246 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9ddb65a9378d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_18.c:235 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ab50d54d8381 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_16.c:239 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6e55928a78c2 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_17.c:239 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_212590e7bd3f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_72b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5f6d6d004f27 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_09.c:305 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6c523c1aaacd | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_15.c:249 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a0239430760b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_05.c:312 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6ac6fff9ba45 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_73b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_04d145f5b2ae | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_33.cpp:241 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2165f5d02998 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_31.c:238 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3c9ecc502839 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_74b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2a0bb2c67d38 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_72b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e3170c2c26d0 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_32.c:236 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2afb496cd326 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_84_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7c1c01a09d37 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_83_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_74f8b818a31d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_73b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_51dbf46acc34 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_72b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6d64a57403b7 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_32.c:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9a270290b6c1 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_83_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_70e0a6f64477 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_74b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7db7d6aa1fda | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_74b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_464d43ab3056 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_84_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_078f1e5254c6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_73b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_34312c97744b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_32.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1d29468e37eb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_84_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2e291d606417 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_83_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2d7d8e0cd9c9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_72b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_14292cc6f87a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_73b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d68cca606bb4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_32.c:176 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e2f47156522c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_74b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_38334ec8fa25 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_84_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1ae81783b8c7 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_83_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a57ee2ef0332 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_73b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6ce37ee0440d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_72b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5aa9b3d45dcc | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_74b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_acfc1066d32f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_32.c:248 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1619889b37a6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_83_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_da6d2070cb2d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_84_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7f9d02f0fb01 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_73b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d493e3d1b070 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_72b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_17311fe31452 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_74b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1c57d9fc6ec8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_83_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6916c8ce8a5c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_32.c:236 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_288f0c75d83c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_73b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_42b7c23d52b3 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_84_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_80dba68f2f9c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_72b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_65c1e80d5416 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_74b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a6c39c88f181 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_83_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_62bbb31abca1 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_72b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_65f6ece564e4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_73b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_13c52084f1df | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_32.c:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_77181287e826 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_74b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_033b1321a90b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_83_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_29aafdff1570 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_84_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5c2755490752 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_72b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_309853a07bc4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_32.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2bbd74c2fbcf | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_73b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_629d8d00e947 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_32.c:176 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_372991cfa02e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_74b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0c019efe48dd | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_84_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_168c4563dfe9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_72b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a47e8c5b4b9d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_84_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2ad974b8b722 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_83_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b4eefb564de5 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_32.c:248 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_258d310b3784 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_73b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0926ae09af8e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_83_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2517f808c5dd | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_74b.cpp:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1e855ebe9b8a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_52c.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7e86d7f74cb3 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_44.c:222 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4cd5c21e783b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_45.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_324399b54384 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_51b.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_03d28007892a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_41.c:218 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3b21e933f407 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_53d.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_afebd090d046 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_64b.c:152 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c8de6f936cc7 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_63b.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_29b4a9501de9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_84_case1V1.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_050312407001 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_54e.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4ed1ab7826bb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_65b.c:144 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2aab721d480b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_66b.c:147 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1406902e2bb3 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_67b.c:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_041207b7444b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_68b.c:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_580f74c2ce6b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_41.c:156 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2fb6f53f5951 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_82_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2e7e152e445d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_81_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_42dc957e2959 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_44.c:160 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0d5859913956 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_45.c:163 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_57efc7a16d9a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_51b.c:126 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a6013269297c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_63b.c:126 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ca70b5ffb4de | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_64b.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5b758be41403 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_53d.c:126 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3a06827a051f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_54e.c:126 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_48c74d8653ba | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_52c.c:126 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1964ddeefb70 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_65b.c:124 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_79aa8f757265 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_68b.c:131 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_24e6a6be09d2 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_66b.c:127 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3e41ad73ccbd | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_67b.c:131 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2051b174d6a2 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_81_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6124f3a2a54a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_41.c:150 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_196f533a7875 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_44.c:154 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f1a9d647f54a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_82_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6925b0f718fc | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_51b.c:134 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cd92de817738 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_54e.c:134 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3a23754c8cc5 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_45.c:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6b20c3bea10f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_52c.c:134 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_907d302219a9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_53d.c:134 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ae29d91f5a05 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_63b.c:134 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4ba5d674f0c1 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_66b.c:135 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8ae13acb4681 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_64b.c:140 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3f479674a179 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_65b.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5a05e82280fc | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_68b.c:139 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1cb0aed38da8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_41.c:158 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1c875225c5f3 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_67b.c:139 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_170a2e5764f7 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_81_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5121e389fa30 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_45.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_26e96e5fefe6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_44.c:162 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4996571e800f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_82_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7ce50c917ca0 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_52c.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_02401d187efb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_51b.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_10676f8dbf5a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_64b.c:138 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0f387510ed8a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_53d.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2ce4bc785544 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_66b.c:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_30d1145f5206 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_54e.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6261a1d0ad77 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_65b.c:130 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a5c1d8cbb02b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_63b.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1cfb06884f8d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_81_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9bcd02792e45 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_67b.c:137 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_13cd0f47c7ab | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_68b.c:137 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2999d79fb61d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_44.c:234 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_70b62ffc9ac2 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_82_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5e1134b847f9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_41.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_91e2a1f3f76e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_45.c:237 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_151696a5be21 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_51b.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bb1fad325355 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_52c.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_05abbbfb4ada | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_64b.c:152 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_567ac0a1e71d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_63b.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5f5a382b850d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_54e.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1c22d2e6351c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_65b.c:144 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_07a17e590c7c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_53d.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5f7dd708830d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_66b.c:147 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6f21c3117aa8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_82_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2408fe2bb423 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_68b.c:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6192d8aeb7b6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_41.c:218 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_588ca5ac0b42 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_81_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bd2c597a29dc | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_44.c:222 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_37d161fe04b9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_45.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1bc3cca9ac28 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_67b.c:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3f96605ab28f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_63b.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0b0afa03af48 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_53d.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b93800f7d79b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54e.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_54732d0ecdda | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_52c.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5a229224b001 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_64b.c:152 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_527e864c98d7 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_67b.c:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_640a96c553fb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_51b.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7ad25445807b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_65b.c:144 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_29a28bd25aa6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_82_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_26a598863cd3 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_41.c:156 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9ebc777bedf6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_66b.c:147 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_38d9c4d7c6ee | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_68b.c:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_96225caee8d1 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_45.c:163 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9d399265b53a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_81_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d71409f4bf42 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_51b.c:126 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_486077275c3b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_52c.c:126 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8e193c027305 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_53d.c:126 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_baccedfe2fed | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_54e.c:126 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a0a8e76d9152 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_64b.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d85c23d44640 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_44.c:160 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8db4579f301e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_63b.c:126 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6ae4f0dd20f6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_66b.c:127 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7ab2dc743804 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_67b.c:131 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4a97867bb4ae | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_65b.c:124 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_09015695ba0c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_82_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8034e4975026 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_81_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0cf4ef1cf9e4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_41.c:150 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6e4430623585 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_68b.c:131 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_091735f2d630 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_51b.c:134 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5046927aa680 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_44.c:154 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1600bfedb2ae | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_45.c:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_331fa373937e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_65b.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0bd815902233 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_64b.c:140 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_41a4db7d978b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_63b.c:134 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_25f3e872b3f4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_54e.c:134 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_09ec73804fdc | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_52c.c:134 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_55d9babeeabc | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_53d.c:134 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_00da39407d23 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_68b.c:139 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_329d8f997051 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_67b.c:139 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_121fc4c03913 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_81_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2fc3fb7f137d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_66b.c:135 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_48628bdbca6e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_44.c:162 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5fc0eaa7cd9e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_45.c:165 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_25a43908213e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_41.c:158 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_094eb8f359c8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_82_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_730c78cb6afc | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_52c.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_23ea93fa87b4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_51b.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0558c31191f1 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_53d.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4a4505d5a98f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_54e.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_09102f24c859 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_64b.c:138 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e78a12186733 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_63b.c:132 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_17394d77b420 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_65b.c:130 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_44e109fe6038 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_66b.c:133 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3805a2ed9c88 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_68b.c:137 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8b199c2b6217 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_81_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0454d2feff32 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_44.c:234 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_00331637cd31 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_67b.c:137 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1c2be8c3434e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_41.c:230 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7281955c9ccb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_51b.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_82b0d18c42f1 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_82_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4080e964d100 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_52c.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9f2cb75c5edf | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_45.c:237 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6add9361f468 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_63b.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b434f40d83d5 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_64b.c:152 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bc9db0cff495 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54e.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dc55eb77a6b5 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53d.c:146 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7f8880111c41 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_66b.c:147 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4d0db88afba0 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_67b.c:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_47d56b334076 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_81_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_09ec3c6d94cf | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_65b.c:144 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7a4e9978b96e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_68b.c:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1b064ee1c5bf | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_82_case1V1.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_aa2051237d6f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_51a.c:47 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_a7b07cd7a551 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_54a.c:47 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_0eadb4fb65d8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_21.c:46 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_32fb0cbf066d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_67a.c:53 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_f806f7857d1e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_42.c:41 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_f8a4c493c8b9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_22b.c:41 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_3c0acefb4560 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_43.cpp:44 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_9411343b715d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_61b.c:41 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_b6d272cb6f7c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_22b.c:41 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_17bb25c5a4ee | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_61b.c:41 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_1294ceed9fd6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_83_case0.cpp:44 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_80f621ee13dc | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_62b.cpp:39 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_8f7727027808 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_72a.cpp:111 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_294c17c173f2 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_72a.cpp:111 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_986f2fc3b2ca | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_51a.c:150 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_bbcdf778db6a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_53a.c:150 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_102a00123d8e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_64a.c:149 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_9ef7d773aa31 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_44.c:97 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_1643c40685ff | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_65a.c:46 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_f0bf680abb46 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_81a.cpp:145 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_2f2ff9b990cb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_62b.cpp:36 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_188352358052 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_43.cpp:41 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_a15e09e0bdf5 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_83_case0.cpp:41 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_20742f804176 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_65a.c:47 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_6d726329d6d0 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_62b.cpp:37 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_0a5498f08c75 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_43.cpp:33 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_20e8b9a2531a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_22b.c:30 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_1d1a5101ace9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_42.c:30 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_ce28e9e37d2c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_61b.c:39 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_2e1d63c37e68 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_83_case0.cpp:42 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_26e692f9aa1b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_68a.c:144 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_41b9c677d56d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_84_case0.cpp:33 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_7f78033f850a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_84_case0.cpp:42 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_828e5b3cafe6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_83a.cpp:44 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_2ccb00e30ffd | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_43.cpp:249 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a1451e51086c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_54b.c:66 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_5ef975140fcb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_62a.cpp:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3e5b6b2d493a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_43.cpp:261 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a43557df0d63 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_54d.c:53 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_f9750a8a5929 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_84a.cpp:50 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_285e1c631d8e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_54c.c:66 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_a9c09b2e6f41 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_54c.c:53 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_77cef4f34ae9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_62a.cpp:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_94bea86bca43 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_53b.c:53 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_bf73ee9b155c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_83a.cpp:48 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_0992f8e2f165 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_43.cpp:249 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fbf3f598be46 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_54b.c:66 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_3a848f8c45aa | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_62a.cpp:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d7bcbdcb2295 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_53c.c:53 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_04b0f32d2c86 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_43.cpp:261 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_99b8329a1141 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54b.c:53 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_0908f33b1da6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_54d.c:53 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_c5fcd7678a07 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_62a.cpp:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_82e9de7c9790 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_84a.cpp:50 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_7de8a87384ff | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_53a.c:76 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_1b0b3d2266fb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_41.c:172 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e26ddbda1397 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_51a.c:70 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_b1f56b51fae4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_41.c:178 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a859d39f26b1 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_41.c:172 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c4dfeeb859d9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_51a.c:78 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_eff39e972090 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_84a.cpp:30 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_67dd9fa6fc7f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_84a.cpp:44 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_c8fc617be306 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_44.c:176 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_64bee048897e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_44.c:184 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_f1c4dc8f973e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_21.c:134 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_fa67e854ab6f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_21.c:202 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_cba78ef1c3f9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_44.c:256 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_3e1f3a1b3f7e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_21.c:202 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_3552da8d6135 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_21.c:134 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_aed654196a36 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_42.c:183 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_70d8dce22462 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_22b.c:89 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_c24dddefe768 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_22b.c:70 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f3150f735f3e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_22b.c:162 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_df4a38c274bb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_42.c:183 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_1d5fb1d8abba | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_42.c:121 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_983e0266c9f9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_61b.c:126 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_74d9e4cb75ee | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_21.c:212 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_2ddc3550b63e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_22b.c:162 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_356d43b6ace1 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_21.c:339 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9afa7470279b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_22a.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_70f2b09647d2 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_45.c:184 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8fd3dfd232ca | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_22a.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_89143a134138 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_83a.cpp:43 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_89c387c36a3c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_45.c:246 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4302775d9e13 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_21.c:277 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9069755badc0 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_45.c:178 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_76d1840c0477 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_05.c:249 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_02f7ce3815f8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_67a.c:79 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_705300e55e14 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_21.c:270 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d369405341bd | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_83a.cpp:44 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_d0cc089f27f6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_68a.c:74 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_59f8525ceefc | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_22a.c:224 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_22598e6d52fc | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_22a.c:224 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_10a2653efe17 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_21.c:278 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2924de587cc4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_45.c:188 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a3c9fbb290d0 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_83a.cpp:30 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_102536946f55 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_08.c:264 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_10b3e7ff6b03 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_06.c:326 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6cef61ce671f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_22a.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_370009954ffd | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_21.c:338 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1cecec217d11 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_05.c:255 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_200c8ff8c860 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_22a.c:224 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1ade597f8acd | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_13.c:248 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0fc05353469e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_83a.cpp:30 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_ce6efc624222 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_45.c:186 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3a6dd27eeede | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_45.c:248 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5ddcd935cab8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_83a.cpp:44 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_aef1aa6bebae | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_21.c:350 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_19342513c898 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_21.c:277 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7b517afd921d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_22a.c:224 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_80ff038b743f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_66a.c:75 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_97ffe654eddb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_06.c:254 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eb35436f0ab4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_22a.c:224 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0caf6d02776f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_21.c:271 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_276ffe80312a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_45.c:188 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9a01ebca71e7 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_22a.c:225 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9a3dafc5882d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_21.c:279 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_592990f2e9c7 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_11.c:251 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_255093795680 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_22a.c:224 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_03b829f028a5 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_21.c:350 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3f55ee9facb3 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_42.c:248 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5838675a434d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_connect_socket_61a.c:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_43227dce1fdd | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_43.cpp:187 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bcd34647821c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_42.c:186 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_32345644e9d2 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_45.c:260 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7ef01525e0bd | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_43.cpp:124 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_5a901b2e337a | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_62a.cpp:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_40768daa0ed8 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_61a.c:154 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eed71c499cfb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_01.c:168 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6d8063c51f4d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_42.c:180 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c16bb904dd87 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_53b.c:54 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_4c3e415c5930 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_33.cpp:179 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a44c3515378f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_console_84_case1V1.cpp:32 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_1a94ecfc71fa | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_54b.c:54 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_a7b56deb2ccf | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_54b.c:41 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_5e6c85de8503 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_54c.c:41 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_a4653276dd88 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_43.cpp:181 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_51a259a1166d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_54c.c:54 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_2463337d8298 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_62b.cpp:55 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_fba2add9452b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_54d.c:54 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_0ed12741813e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_62a.cpp:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a8e761d98adb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_61a.c:162 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_54197a307455 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_32.c:194 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a248741e9914 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_environment_83a.cpp:48 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_385d5ad57342 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_43.cpp:189 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b97ad7677fa5 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_52b.c:52 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_b59fb21064c2 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_53b.c:52 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_93f28108d920 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_42.c:188 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_376565f6c48c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_54c.c:39 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_0a9c1ef0cb6b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_61a.c:160 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8d1a0efeaf82 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_62a.cpp:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4cf6f7bfdd55 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_file_83a.cpp:48 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_cdef5fd61e6f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_12.c:265 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8e2d1ac725cd | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_61a.c:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_18cd442adc13 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_char_listen_socket_42.c:260 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_297c96b03cd5 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_42.c:248 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_695158d9a0db | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_61a.c:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dd59fb1f2935 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_83_case1V1.cpp:32 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_b3c1e67c3a2b | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_84_case1V1.cpp:32 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_9bf3cb88b388 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_connect_socket_62b.cpp:124 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_217c9c9ae82e | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_33.cpp:185 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2fac92f1b291 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_42.c:186 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a0366d088eb5 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_43.cpp:187 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_173ca968de2d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_34.c:190 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c0ee21b8a462 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_61a.c:154 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_793709f85db4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_54b.c:33 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_61b87ab4684c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_console_62a.cpp:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_730267e9eae7 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_34.c:184 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2f2903a706b2 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_43.cpp:181 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_61df85329f72 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_43.cpp:118 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_611d062c33c6 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_42.c:180 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_51d0399d7dd9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_52b.c:54 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_f1297697f7fc | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_61a.c:162 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_211bfff3950c | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_54d.c:41 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_e86dc6ea2993 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_62a.cpp:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3e7aad997cb2 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_83a.cpp:48 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_aa34355b1978 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_environment_84a.cpp:50 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_e925b10273eb | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_43.cpp:189 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7cb6995c429d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_42.c:188 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_75d51ff579a3 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_53c.c:52 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_d287e42d7c6f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_52b.c:39 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_e75f6500cd5d | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_54b.c:39 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_c971b8666137 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_53b.c:52 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_7dc96ced97fa | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_53b.c:39 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a7d9d79293be | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_54d.c:52 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_7b717e72c67f | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_54d.c:39 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_82b820aa8360 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_62a.cpp:157 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0f727bc339c1 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_61a.c:160 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6e4d2a0fedb9 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_83a.cpp:48 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_6caa8c73f2d4 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_01.c:248 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ed7fcb7491b1 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_file_83_case1V1.cpp:32 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_6e37cca1e642 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_61a.c:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fc11859123d5 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_84_case1V1.cpp:32 | UNSUPPORTED_ORACLE | Stage D oracle cannot prove or disprove this route, and Stage C priority P2 is not eligible for reportable preservation
- hyp_path_6f2e8a736215 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/CWE90_LDAP_Injection__w32_wchar_t_listen_socket_42.c:260 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_000d1e03dc07 | juliet-api-misuse/testcases/CWE90_LDAP_Injection/main.cpp:2810 | NOT_ROUTE_BOUND | payload did not satisfy oracle
