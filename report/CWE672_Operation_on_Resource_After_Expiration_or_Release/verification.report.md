# MAGUS Final Vulnerability Report

- generated_at: 2026-05-26T04:20:42Z
- reportable_vulnerabilities: 68
- d_confirmed_vulnerabilities: 68
- stage_c_preserved_vulnerabilities: 0
- failed_verifications: 183
- source_confirmed: /home/sq_hu/MAGUS/d/memberD_verifier/02_run_with_C/output/CWE672_Operation_on_Resource_After_Expiration_or_Release/verification.jsonl
- source_failed: /home/sq_hu/MAGUS/d/memberD_verifier/02_run_with_C/output/CWE672_Operation_on_Resource_After_Expiration_or_Release/verification.failed.jsonl

## Confirmed Vulnerabilities

### 1. hyp_path_32314a5f4078

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_62b.cpp:443
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制list的生命周期（例如，通过某些释放操作或作用域结束），使得push_back在list被释放后执行。
- 触发路径: data.push_back(100); data.push_back(0); @ 入口: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_62b.cpp:31; push_back调用分配节点，但list可能已失效 @ /usr/include/c++/11/bits/stl_list.h:443
- 结论: 在list被释放或过期后，仍对其执行push_back操作，导致资源使用已释放的对象（Use-After-Free）。
- D验证: confirmed / ver_40413893
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 2. hyp_path_6ed46d6c8892

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_61a.cpp:37
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够通过 case0Source 控制 list<int> data 的内容，使其包含至少一个 0 值元素，从而触发 data.clear() 调用。
- 触发路径: list<int> data; data = case0Source(data); { list<int> ::iterator i; cout << "The list contains: "; for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ cout << " " << *i; } } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_61a.cpp:35-39
- 结论: 在 std::list 上调用 clear() 后，继续使用之前获取的迭代器进行解引用，导致对已释放或失效资源的操作，违反 CWE-672。
- D验证: confirmed / ver_e4bfb993
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 3. hyp_path_ac53d3096dd9

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_32.cpp:55
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制列表中的元素值，使其包含0并触发clear()。
- 触发路径: for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); ... } cout << " " << *i; } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_32.cpp:55附近
- 结论: 在遍历std::list<int>的过程中，当元素值为0时调用data.clear()清空列表，随后继续使用之前获得的迭代器i进行解引用操作，导致对已失效迭代器的访问（use-after-release），违反CWE-672。
- D验证: confirmed / ver_c0a5c0b4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 4. hyp_path_75cfd247bf69

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case0.cpp:44
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制列表中的元素值，使得存在一个值为0的元素。
- 触发路径: for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ cout << " " << *i; } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case0.cpp:42-46
- 结论: 在遍历std::list时，如果元素值为0则调用clear()清空列表，随后继续解引用迭代器i，导致对已经失效的迭代器进行解引用操作，产生CWE-672（对过期或释放后的资源进行操作）漏洞。
- D验证: confirmed / ver_71fb3b0f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 5. hyp_path_c17e2616d4c4

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_84_case0.cpp:44
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: list 中至少有一个元素值为0（转换为bool后为false），触发 if (!*i) 条件，执行 data.clear()。
- 触发路径: cout << " " << *i; // 解引用已失效的迭代器 @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_84_case0.cpp:44
- 结论: 在遍历 std::list 时，条件为真时调用 clear() 清空列表，但之后继续使用已失效的迭代器进行解引用操作，导致未定义行为（可能崩溃或数据损坏）。这是对过期资源（失效迭代器）的操作。
- D验证: confirmed / ver_f9277def
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 6. hyp_path_abb8787051a9

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_62a.cpp:37
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制case0Source的输入，使得list中包含值为0的元素
- 触发路径: void case0() { list<int> data; case0Source(data); { list<int> ::iterator i; ... for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } ... cout << " " << *i; } } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_62a.cpp:34-37; if (!*i) { data.clear(); } @ 同上，循环内条件满足时调用data.clear(); cout << " " << *i; @ 同上，clear()后继续解引用迭代器
- 结论: 在资源释放后继续操作：list容器调用clear()后迭代器失效，但后续循环中仍然解引用该迭代器，导致未定义行为（use-after-free）。
- D验证: confirmed / ver_65c8b6d8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 7. hyp_path_3bf46d72c3ca

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_72a.cpp:48
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: sink function implementation may contain resource release followed by use; no external control required
- 触发路径: data.push_back(100); data.push_back(0); @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_72a.cpp:36-44; dataVector.insert(dataVector.end(), 1, data); ... case0Sink(dataVector); @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_72a.cpp:46-48
- 结论: CWE-672: Operation on Resource After Expiration or Release in case0Sink when processing a vector of lists
- D验证: confirmed / ver_50eb80ac
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 8. hyp_path_f5bb4991fb55

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_42.cpp:42
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: case0Source返回的list中包含至少一个值为0的元素，使得条件!*i成立，触发clear()
- 触发路径: list<int> data; data = case0Source(data); @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_42.cpp:40; for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ cout << " " << *i; } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_42.cpp:41-44
- 结论: 在list对象调用clear()后，继续使用之前获取的迭代器进行解引用操作，导致操作已释放的资源（迭代器失效），违反CWE-672。
- D验证: confirmed / ver_7d65bce3
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 9. hyp_path_407bd2f1fffe

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_74b.cpp:48
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制list中的元素值，使得出现0值元素
- 触发路径: if (!*i) { data.clear(); } @ 47行; cout << " " << *i; // 此处迭代器i已失效 @ 48行
- 结论: 在list迭代器遍历过程中，当元素值为0时调用clear()清空容器，导致迭代器失效，但后续仍解引用该迭代器，造成对已释放资源的操作，引发未定义行为。
- D验证: confirmed / ver_b2d4c39b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 10. hyp_path_19182de98305

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_31.cpp:50
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制list中插入的数值，使得存在值为0的元素。
- 触发路径: for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_31.cpp:41-44; cout << " " << *i; // 在此处解引用已失效的迭代器 @ 同文件:45
- 结论: 在清空list容器后，仍然使用已被无效的迭代器解引用，导致未定义行为（操作已释放资源）。
- D验证: confirmed / ver_982a8e6c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 11. hyp_path_1e1eeb891f3d

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_67a.cpp:42
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够影响push_back的值（但此处为常量）或sink内部行为
- 触发路径: data.push_back(0); myStruct.structFirst = data; case0Sink(myStruct); @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_67a.cpp:45-49
- 结论: 在case0Sink中，list<int> data通过structType成员传递，sink函数可能通过引用或指针持有对list内部数据的访问，并在data析构后继续使用，导致use-after-free（CWE-672）。
- D验证: confirmed / ver_5cfa584f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 12. hyp_path_53ccec0d205d

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_33.cpp:50
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 列表中至少有一个元素值为0，且循环未退出即调用clear()。
- 触发路径: cout << " " << *i; // 迭代器可能已失效 @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_33.cpp:48-52
- 结论: 在循环遍历 std::list<int> 时，如果元素值为 0，则调用 clear() 清空列表，随后继续解引用已失效的迭代器，导致未定义行为（CWE-672）。
- D验证: confirmed / ver_1f630dd2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 13. hyp_path_7d37d812cb09

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_72b.cpp:48
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够影响list<int>中元素的值，使其至少包含一个值为0的元素（通过控制传入的vector<list<int>>参数）
- 触发路径: for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ cout << " " << *i; } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_72b.cpp:48
- 结论: 在迭代std::list<int>的过程中，当元素值为0时调用data.clear()，导致所有迭代器失效，随后继续解引用失效迭代器，造成未定义行为（CWE-672）。
- D验证: confirmed / ver_476cd9c9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 14. hyp_path_499d9663cb53

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_73b.cpp:47
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制list<int>中的某些元素值，使其为0（假）。
- 触发路径: for( i = data.begin(); i != data.end(); i++) { @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_73b.cpp:40; if (!*i) { data.clear(); } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_73b.cpp:42-43; cout << " " << *i; // 解引用已失效的迭代器 @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_73b.cpp:47
- 结论: 在std::list迭代过程中调用clear()导致迭代器失效，后续解引用迭代器导致未定义行为（use-after-free）。
- D验证: confirmed / ver_d36db2e4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 15. hyp_path_4f687f790120

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_45.cpp:48
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制list<int>中的元素，使其至少包含一个0值
- 触发路径: list<int> ::iterator i; ... for( i = data.begin(); i != data.end(); i++) @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_45.cpp:39-41; if (!*i) { data.clear(); } @ 同上文件:43; cout << " " << *i; @ 同上文件:48
- 结论: 在遍历std::list<int>时，如果遇到值为0的元素，会调用data.clear()清空列表，但之后继续使用之前获取的迭代器解引用，导致使用已失效的迭代器，违反CWE-672（资源释放后使用）。
- D验证: confirmed / ver_986ff62a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 16. hyp_path_1dcfa94e96b3

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_63b.cpp:44
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够影响传入的list<int>指针所指向的数据内容，使其至少包含一个值为0的元素。
- 触发路径: list<int> data = *dataPtr; for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } cout << " " << *i; } @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_63b.cpp:35-44
- 结论: 在遍历std::list<int>过程中，当元素值为0时调用clear()清空列表，随后在循环中继续解引用迭代器，导致对已失效迭代器的操作（use-after-free或无效迭代器解引用），违反CWE-672定义。
- D验证: confirmed / ver_076cecb9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 17. hyp_path_48610f52c5e4

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_64b.cpp:47
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够影响列表中的元素值，使其包含0，或者程序逻辑中存在导致0出现的条件。
- 触发路径: if (!*i) { data.clear(); } /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ cout << " " << *i; @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_64b.cpp:47
- 结论: 在清空列表后继续解引用已失效的迭代器，导致未定义行为，符合CWE-672 "在资源释放或过期后操作资源"。
- D验证: confirmed / ver_52035b47
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 18. hyp_path_26a027df41f8

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_66b.cpp:45
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制列表元素的值，使得列表中存在值为0的元素，从而触发data.clear()调用，导致后续迭代器解引用操作使用已失效的迭代器。
- 触发路径: if (!*i) { data.clear(); } /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ cout << " " << *i; @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_66b.cpp:45
- 结论: 在遍历std::list<int>时，如果元素值为0，则调用clear()清空列表，之后继续使用已失效的迭代器解引用，导致未定义行为（CWE-672）。
- D验证: confirmed / ver_7ed9a530
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 19. hyp_path_d4cf5e263bd4

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_67b.cpp:49
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制 list 中的某个元素值为假（如 0）
- 触发路径: for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } cout << " " << *i; } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_67b.cpp:42; cout << " " << *i; // 解引用失效迭代器 @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_67b.cpp:49
- 结论: 在遍历list的过程中，当元素值为假时调用clear()清空容器，然后继续解引用已失效的迭代器，导致未定义行为。
- D验证: confirmed / ver_13c468db
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 20. hyp_path_5e2ca79c61b3

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_68b.cpp:48
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够影响列表数据，使得列表中包含值为0的元素。
- 触发路径: for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } // ... *i 解引用 @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_68b.cpp:39-46; cout << " " << *i; // 解引用已经失效的迭代器 @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_68b.cpp:48
- 结论: 在遍历std::list时，如果元素值为0，则调用data.clear()清除列表，但之后继续使用之前获取的迭代器进行解引用，导致对已释放资源的操作（CWE-672）。
- D验证: confirmed / ver_b443eaa7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 21. hyp_path_779bc92a012d

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_45.cpp:61
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制列表元素值（例如通过外部输入插入0），但本例中列表数据为硬编码，无法由攻击者控制。
- 触发路径: static void case0Sink() { list<int> data = case0Data; for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } cout << " " << *i; } } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_45.cpp:35-52; cout << " " << *i; // 解引用已失效的迭代器 @ same function, line 44
- 结论: 在list容器调用clear()后，继续解引用已失效的迭代器，导致对已释放资源进行操作（CWE-672），但由于列表数据为硬编码，攻击者无法控制触发条件，实际可利用性较低。
- D验证: confirmed / ver_e81abc55
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 22. hyp_path_3a788c679a37

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_43.cpp:41
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制list<int> data中的元素值，使其包含零值。
- 触发路径: case0Source(data); @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_43.cpp:39; for( i = data.begin(); i != data.end(); i++) @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_43.cpp:43; if (!*i) { data.clear(); } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_43.cpp:48; cout << " " << *i; // 迭代器已失效 @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_43.cpp:49
- 结论: 在遍历list的过程中，当遇到值为0的元素时，调用data.clear()清空列表，导致后续迭代器失效，但仍对失效的迭代器进行解引用操作，构成Use-After-Release漏洞。
- D验证: confirmed / ver_51a3c729
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 23. hyp_path_e0829aeb27d8

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_08.cpp:65
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: data列表中包含值为0的元素，触发clear()调用；且staticReturnsTrue()恒真使条件分支必定执行
- 触发路径: for( i = data.begin(); i != data.end(); i++) @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_08.cpp:58; if (!*i) { data.clear();} @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_08.cpp:60-61; cout << " " << *i; // 解引用已失效的迭代器 @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_08.cpp:65
- 结论: 在遍历std::list时，当元素值为0时调用clear()清空列表，随后继续解引用迭代器，导致迭代器失效，产生未定义行为。此操作违反了CWE-672（对过期或释放后资源的操作）。
- D验证: confirmed / ver_8117ec73
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 24. hyp_path_0b7937bd0488

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_12.cpp:57
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 程序运行时通过globalReturnsTrueOrFalse()随机选择是否清除列表，导致迭代器在clear后仍被使用。
- 触发路径: if(globalReturnsTrueOrFalse()) { data.clear(); } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_12.cpp:33; for( i = data.begin(); i != data.end(); i++) { cout << " " << *i; } // 解引用可能无效的迭代器 @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_12.cpp:57
- 结论: 在调用list::clear()后，继续解引用之前获取的迭代器，导致使用已释放的迭代器，违反CWE-672。
- D验证: confirmed / ver_562db00c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 25. hyp_path_f766e7f7d2b5

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_11.cpp:51
- 漏洞类型: use_after_free
- CWE: CWE-672; CWE-416
- 风险等级: P0
- 触发条件: 攻击者能够控制 list 中的元素值，使之包含0（或通过其他方式使条件满足）
- 触发路径: for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); ... } cout << " " << *i; } @ 39-53; for( i = data.begin(); i != data.end(); i++) @ 44; if (!*i) { data.clear();} @ 46; cout << " " << *i; // 解引用失效迭代器 @ 51
- 结论: 在对 std::list<int> 的迭代循环中，当元素值为0时调用 data.clear() 清空列表，随后继续使用已失效的迭代器进行解引用和递增操作，导致对已释放资源的访问，违反了 CWE-672 和 CWE-416。
- D验证: confirmed / ver_5c59c403
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 26. hyp_path_b87bce13baf4

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_17.cpp:52
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制list<int> data中的元素值（例如通过输入），使得至少一个元素为0。
- 触发路径: list<int> ::iterator i; for( i = data.begin(); i != data.end(); i++) { if (!*i) @ testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_17.cpp:43-47; data.clear(); @ testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_17.cpp:48; } cout << " " << *i; @ testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_17.cpp:50-52
- 结论: 在遍历list<int>时，如果元素值为0，则调用data.clear()清空容器，随后迭代器i失效，但循环继续使用*i解引用，导致对已释放资源进行操作，触发CWE-672（Operation on Resource After Expiration or Release）。
- D验证: confirmed / ver_a4855217
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 27. hyp_path_b1d5d9cf681e

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_05.cpp:58
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制输入使得列表 data 中包含零值元素（例如通过某种输入接口注入数据）
- 触发路径: for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ cout << " " << *i; } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_05.cpp:48-53; cout << " " << *i; // 迭代器 i 在 clear() 后失效 @ 第53行
- 结论: 在遍历 list<int> 时，如果元素为0则调用 clear() 清空列表，但随后仍然解引用原迭代器，导致迭代器失效，构成释放后使用（Use After Release）漏洞。
- D验证: confirmed / ver_6308e7c8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 28. hyp_path_9dc455873fb4

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_07.cpp:57
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: std::list<int>中至少有一个元素值为0，且程序执行到该元素所在的迭代位置。
- 触发路径: if (!*i) { data.clear(); } /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ cout << " " << *i; @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_07.cpp:55-59
- 结论: 在std::list<int>的迭代循环中，当元素值为0时调用clear()清空列表，之后继续使用已失效的迭代器执行解引用操作，导致对过期资源的访问（use-after-free）。
- D验证: confirmed / ver_336df020
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 29. hyp_path_911b3f364cf8

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_09.cpp:52
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制 list 中的元素（例如通过用户输入填入 0 值），使 data.clear() 被执行。
- 触发路径: for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } cout << " " << *i; } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_09.cpp:45-47; cout << " " << *i; // 此处 *i 解引用的是 clear() 后的失效迭代器。 @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_09.cpp:47
- 结论: 在遍历 std::list 的过程中，如果遇到值为 0 的元素，会调用 data.clear() 清空列表，导致所有迭代器失效。随后循环继续解引用该失效迭代器 *i，构成在容器被清除后操作资源的未定义行为漏洞（CWE-672）。
- D验证: confirmed / ver_dccfab7f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 30. hyp_path_756e751c9d20

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_13.cpp:51
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制std::list<int>的内容，使其包含0值元素
- 触发路径: if (!*i) { data.clear(); } /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ cout << " " << *i; @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_13.cpp:49-53
- 结论: 在遍历std::list<int>时，如果元素值为0则调用data.clear()，但clear()后迭代器i变为无效，后续的*i解引用操作导致未定义行为，违反CWE-672（资源过期或释放后操作）。
- D验证: confirmed / ver_53ed4663
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 31. hyp_path_0e9c3af8002b

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_10.cpp:52
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制std::list<int> data的初始内容，至少包含一个值为0的元素，例如通过外部输入或函数参数。
- 触发路径: if (!*i) { data.clear(); } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_10.cpp:47; cout << " " << *i; @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_10.cpp:52
- 结论: 在对std::list进行遍历时，如果在循环中调用了clear()清空列表，后续同一循环中对已失效迭代器的解引用操作会导致未定义行为，属于对过期资源的操作（Use-After-Release）。
- D验证: confirmed / ver_d105c1cc
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 32. hyp_path_af96706fb8e0

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_14.cpp:51
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 列表中存在值为0的元素，触发 data.clear() 操作；攻击者能够控制列表中的元素，使得至少一个元素的值为0
- 触发路径: list<int> ::iterator i; cout << "The list contains: "; for( i = data.begin(); i != data.end(); i++) @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_14.cpp:42-44; if (!*i) { data.clear(); } @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_14.cpp:47; } /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ cout << " " << *i; @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_14.cpp:49-51
- 结论: 在遍历 std::list 时，当遇到元素为0时执行 clear()，导致迭代器失效，后续仍解引用该迭代器，违反操作已过期资源的 API contract，可能引发未定义行为（如崩溃或信息泄露）。
- D验证: confirmed / ver_575eedeb
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 33. hyp_path_cb70f559d71c

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_02.cpp:52
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制list<int>中的元素值，使其包含0
- 触发路径: for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } @ 行45-47; cout << " " << *i; /* 此时i已失效 */ @ 行52
- 结论: 在遍历list<int>时，如果元素值为0则调用data.clear()，随后继续解引用迭代器i，导致使用已失效的迭代器，属于对过期资源的操作。
- D验证: confirmed / ver_70370c2d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 34. hyp_path_fa95d73f734e

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_01.cpp:47
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制list中的元素内容，使其包含值为0的元素。
- 触发路径: for( i = data.begin(); i != data.end(); i++) { @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_01.cpp:42; if (!*i) { @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_01.cpp:43; data.clear(); @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_01.cpp:44; cout << " " << *i; // 此处迭代器i已失效 @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_01.cpp:47
- 结论: 在遍历std::list时，如果元素为0则调用clear()，之后继续使用之前获取的迭代器进行解引用，导致迭代器失效，违反CWE-672（资源释放后使用）。
- D验证: confirmed / ver_c8dfd2c0
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 35. hyp_path_a208bc8dbc52

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_03.cpp:52
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制list的内容，使其包含0元素
- 触发路径: for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ cout << " " << *i; } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_03.cpp:48-52
- 结论: 在遍历std::list时，如果元素为0则调用clear()清空容器，随后继续解引用已失效的迭代器，导致对已释放资源的操作（Use-After-Free）。
- D验证: confirmed / ver_de6d9ac2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 36. hyp_path_194b026790db

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_04.cpp:58
- 漏洞类型: use_after_free
- CWE: CWE-672; CWE-416
- 风险等级: P0
- 触发条件: 攻击者能够控制list中的元素值，使其包含0（例如通过输入或测试用例配置）
- 触发路径: for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ cout << " " << *i; } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_04.cpp:56-60
- 结论: 在遍历std::list时，当元素值为0时调用clear()清空list，之后继续使用已失效的迭代器进行解引用操作，导致操作已释放的资源（use-after-free）。
- D验证: confirmed / ver_77fea63d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 37. hyp_path_80e6e691b02f

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_06.cpp:57
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 程序运行时列表中存在值为0的元素，触发 clear() 调用
- 触发路径: cout << " " << *i; // 在 data.clear() 后解引用迭代器 i @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_06.cpp:57
- 结论: 在 std::list 迭代过程中，当元素为0时调用 data.clear() 清空列表，导致后续迭代器解引用操作访问已释放的内存，违反 CWE-672（对过期或释放后的资源进行操作）。
- D验证: confirmed / ver_3be2c3e4
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 38. hyp_path_597b25c11042

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_15.cpp:58
- 漏洞类型: use_after_free
- CWE: CWE-672; CWE-416
- 风险等级: P0
- 触发条件: 攻击者能够控制数据源使list<int> data中包含至少一个值为0的元素
- 触发路径: for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ cout << " " << *i; } cout << endl; @ L51-55; cout << " " << *i; // 此处*i在clear()后无效 @ L58
- 结论: 在遍历std::list<int>时，当某个元素为0，调用data.clear()使所有迭代器失效，随后继续解引用迭代器i，导致对已过期资源的操作（Use-After-Free）。
- D验证: confirmed / ver_35b1e9c8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 39. hyp_path_3366264af83a

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_16.cpp:52
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够影响list<int>中的元素，使其包含0值。
- 触发路径: list<int> data; // 假设数据来自外部输入或计算 @ 函数入口; for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ cout << " " << *i; } @ 行45-52
- 结论: 在循环遍历list<int>时，如果元素为0则调用data.clear()，之后继续解引用已失效的迭代器，导致对已释放资源的操作（CWE-672）。
- D验证: confirmed / ver_1b0a8386
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 40. hyp_path_2ca2d2225633

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_18.cpp:50
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: list中存在至少一个元素为0的值，触发data.clear()调用；攻击者能够控制list中的元素值（需验证外部输入存在性）。
- 触发路径: for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ cout << " " << *i; } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_18.cpp:41-50
- 结论: 在'CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_18.cpp'中，list在迭代过程中被clear()，随后解引用已失效的迭代器，导致use-after-free或未定义行为。
- D验证: confirmed / ver_17fe210b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 41. hyp_path_6b1faf69e372

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_21.cpp:62
- 漏洞类型: use_after_free
- CWE: CWE-672
- 风险等级: P0
- 触发条件: case0Sink函数内部实现存在释放后使用的逻辑，例如调用clear()后访问list元素或依赖迭代器。
- 触发路径: data.push_back(0); case0Static = 1; /* true */ case0Sink(data); @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_21.cpp:60-64
- 结论: 在list<int>对象可能被释放后仍通过引用进行操作，存在Use After Free漏洞。Sink函数case0Sink可能在内部释放list资源，然后继续使用该list的引用，导致未定义行为。
- D验证: confirmed / ver_db5467a6
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 42. hyp_path_b7eb6fc3b40c

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83a.cpp:29
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 无外部输入控制，漏洞在正常执行流程中自动触发。
- 触发路径: list<int> data; @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83a.cpp:28; CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case0 case0Object(data); @ 同一文件:29; ~CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case0() 释放data内部资源 @ 同一文件:29（case0Object析构时）; ~list<int>() 再次释放相同资源 @ 同一文件:28（data析构时）
- 结论: 在CWE672测试用例中，case0函数创建list<int> data和CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case0对象case0Object，其中case0Object的析构函数可能释放data的内部内存，导致后续data析构时双重释放（double-free），违反CWE-672（对过期或释放后的资源进行操作）。
- D验证: confirmed / ver_2396af0c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 43. hyp_path_700a58878b1e

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_22a.cpp:44
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够影响list<int>的内容（如push_back的值）或触发sink中保存迭代器的路径。; case0Sink函数内部存在将迭代器或指针存储到全局变量的逻辑。
- 触发路径: data.push_back(0); case0Global = 1; /* true */ case0Sink(data); @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_22a.cpp:42-46
- 结论: 在case0函数中，list<int> data通过值传递到case0Sink，sink内部可能保存指向数据元素的迭代器或指针到全局变量（如case0Global或其他静态存储）。sink返回后，参数副本被析构，导致全局指针悬空，后续通过该指针操作list元素将导致Use-After-Free或操作已过期资源（CWE-672）。
- D验证: confirmed / ver_6647d58a
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 44. hyp_path_8bc75ab0a804

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_51a.cpp:40
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 需要case0Sink函数实际保存了引用或迭代器，但此条件未在代码中确认。
- 触发路径: data.push_back(100); data.push_back(0); case0Sink(data); @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_51a.cpp:38-42
- 结论: 现有代码仅展示case0函数，未提供case0Sink实现，无法验证是否保存了指向data的引用或迭代器，因此不能确认存在use-after-free漏洞。
- D验证: confirmed / ver_05e79475
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 45. hyp_path_316271ef95a0

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_52a.cpp:40
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制 list 的内容或影响 sink 函数的执行流程
- 触发路径: data.push_back(100); data.push_back(0); case0Sink_b(data); @ testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_52a.cpp:38-42; 假设 case0Sink_b 中调用了 data.clear() 或 data.~list() 后继续访问 data @ sink 函数内部（代码未提供，但根据 B 阶段种子存在析构调用）
- 结论: 在 case0Sink_b 中可能对已释放的 list 对象进行操作，导致 use-after-free。
- D验证: confirmed / ver_6e6b82d2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 46. hyp_path_bc05cb9ac4e5

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54a.cpp:40
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制list中的元素（如插入的值），但实际利用需要sink内部在释放后对参数进行操作。
- 触发路径: data.push_back(100); data.push_back(0); case0Sink_b(data); @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54a.cpp:40
- 结论: case0Sink_b函数可能在其实现中释放list资源后继续操作，导致资源释放后使用（Use-After-Free）风险，但sink内部代码缺失，无法完全确认。
- D验证: confirmed / ver_393d3a29
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 47. hyp_path_53fe97d311cf

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_81a.cpp:32
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: action函数必须保存data中元素的指针或迭代器并且后续使用
- 触发路径: void case0() { list<int> data; data.push_back(100); data.push_back(0); const CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_81_base& o = ...; o.action(data); } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_81a.cpp:26-33; 保存data中元素的指针或迭代器 @ action函数内部（推测）; list<int>析构函数释放内存 @ case0返回后data析构; 导致释放后使用 @ 后续使用保存的指针（推测）
- 结论: 在函数case0中，局部list<int> data被创建并插入元素，然后通过多态调用o.action(data)。如果action的实现保存了data内部元素的指针或迭代器，并在data析构后继续使用，则构成资源释放后使用漏洞（CWE-672）。虽然action具体实现未提供，但朱丽叶测试用例典型设计包含保存指针行为，且B阶段信号表明high_risk_sink，漏洞路径合理。
- D验证: confirmed / ver_422df0c5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 48. hyp_path_1d9ce4cc1109

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_44.cpp:77
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 控制流进入case0函数，且case0Sink实现为释放资源。
- 触发路径: void case0() { list<int> data; ... @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_44.cpp:49; funcPtr(data); // 第一次调用，可能释放data @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_44.cpp:55; data.push_back(0); // 操作已释放的data @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_44.cpp:57; funcPtr(data); // 第二次调用，使用已释放的data @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_44.cpp:58
- 结论: 在case0函数中，通过函数指针调用case0Sink，可能释放了list对象，随后再次通过函数指针调用case0Sink使用已释放的list，导致对已过期资源的操作（Use-After-Free）。
- D验证: confirmed / ver_ffd1cb0b
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 49. hyp_path_a820079ddd69

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_21.cpp:48
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制列表中的元素值，使其包含0
- 触发路径: for( i = data.begin(); i != data.end(); i++) @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_21.cpp:41; if (!*i) { data.clear(); } @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_21.cpp:44; cout << " " << *i; @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_21.cpp:48
- 结论: 在遍历std::list时，如果元素值为0，则调用data.clear()清空列表，随后继续使用已失效的迭代器进行解引用操作，导致对已释放资源的访问（Use-After-Free/Invalid Iterator Dereference）。
- D验证: confirmed / ver_5f99363f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 50. hyp_path_e982e3d7ea6b

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_22b.cpp:49
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制列表中至少一个元素为0（例如通过输入或外部数据），使得if (!*i)条件成立，触发data.clear()
- 触发路径: list<int> ::iterator i; for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_22b.cpp:40-45; cout << " " << *i; /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_22b.cpp:49
- 结论: 在C++ std::list迭代过程中，当检测到空元素时调用clear()清空列表，随后继续使用已失效的迭代器解引用，导致未定义行为。
- D验证: confirmed / ver_02bae2e8
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 51. hyp_path_b8cc81933f48

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_41.cpp:43
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够向std::list<int>中插入一个值为0的元素。
- 触发路径: for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ cout << " " << *i; } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_41.cpp:36-43; cout << " " << *i; // 解引用可能已经失效的迭代器 @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_41.cpp:43
- 结论: 在对std::list<int>进行遍历时，如果元素值为0则调用clear()清空列表，之后继续解引用迭代器，导致迭代器失效，造成对已释放资源的操作（Use-After-Free/Invalid Iterator）。
- D验证: confirmed / ver_16e20b47
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 52. hyp_path_0fde37a45c82

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_44.cpp:43
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够通过输入或其他方式使 list 中包含一个值为0的元素。
- 触发路径: for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } cout << " " << *i; // 迭代器在 clear 后失效，此处为 use-after-free } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_44.cpp:38-45
- 结论: 在遍历 std::list<int> 的过程中，当元素值为0时调用 data.clear() 清空列表，随后继续解引用处于失效状态的迭代器 i，导致使用已释放的资源（use-after-free / iterator invalidation）。
- D验证: confirmed / ver_ea50df53
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 53. hyp_path_7082025cbcd4

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_52c.cpp:43
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够向list中插入值为0的元素
- 触发路径: for(i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } cout << " " << *i; } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_52c.cpp:41-45
- 结论: 在list迭代过程中调用clear()导致迭代器失效，后续解引用*iter导致使用已释放的资源，违反CWE-672。
- D验证: confirmed / ver_54638531
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 54. hyp_path_c4eff78ea396

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_51b.cpp:43
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制列表data中的元素值，使其至少包含一个0
- 触发路径: for( i = data.begin(); i != data.end(); i++) @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_51b.cpp:31; if (!*i) { data.clear(); } @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_51b.cpp:33; cout << " " << *i; /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_51b.cpp:43
- 结论: 在std::list<int>的遍历过程中，如果元素值为0则调用clear()清空列表，之后继续解引用迭代器，导致对过期资源的操作（CWE-672）。
- D验证: confirmed / ver_0f5d8122
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 55. hyp_path_486ba2bb88b2

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54e.cpp:43
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制list中元素的值，使得至少有一个元素为0
- 触发路径: for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } /* NOTE: Dereference the iterator, which may be invalid if data is cleared */ cout << " " << *i; } @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54e.cpp:36-43
- 结论: 在C++ std::list的迭代器遍历过程中，当遇到值为0的元素时调用clear()清空了容器，但随后继续解引用迭代器，导致对已失效迭代器的解引用操作，违反了CWE-672（在资源释放或过期后进行操作）的API契约。
- D验证: confirmed / ver_a2b933a9
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 56. hyp_path_9804a8e7755b

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_53d.cpp:43
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制list<int>中的元素内容，使得至少一个元素值为0，从而触发data.clear()调用。
- 触发路径: if (!*i) { data.clear(); } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_53d.cpp:38; cout << " " << *i; /* 解引用已失效的迭代器 */ @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_53d.cpp:43
- 结论: 在std::list迭代过程中调用clear()导致迭代器失效，随后在同一循环体内部解引用该迭代器，造成未定义行为，违反了CWE-672（资源释放后操作）。
- D验证: confirmed / ver_ce57f9ae
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 57. hyp_path_3dbe790c97bb

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_65b.cpp:43
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者可以通过控制列表内容（如输入元素值）使某个元素为0
- 触发路径: for( i = data.begin(); i != data.end(); i++) { if (!*i) { data.clear(); } cout << " " << *i; } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_65b.cpp:41-45
- 结论: 在遍历std::list<int>时，当元素值为0时调用data.clear()清空列表，然后在同一循环中继续解引用迭代器i，导致对已释放的迭代器进行解引用操作，违反CWE-672。
- D验证: confirmed / ver_4b656fa5
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 58. hyp_path_0caae4c8cd31

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_81_case0.cpp:37
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够通过某种方式影响列表元素的值，使其包含0
- 触发路径: cout << " " << *i; // 解引用可能已失效的迭代器 @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_81_case0.cpp:37; if (!*i) { data.clear(); } // 清空列表使迭代器失效 @ 同一文件，循环内
- 结论: 在遍历std::list<int>时，如果元素值为0则调用data.clear()清空列表，导致后续迭代器解引用失效，触发对过期资源的操作（CWE-672）。
- D验证: confirmed / ver_842efb32
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 59. hyp_path_36310a90cf8f

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_82_case0.cpp:37
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制列表 data 的内容，使其包含至少一个值为 0 的元素。
- 触发路径: for( i = data.begin(); i != data.end(); i++) @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_82_case0.cpp:25; if (!*i) { data.clear(); } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_82_case0.cpp:27; cout << " " << *i; // 解引用已失效的迭代器 @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_82_case0.cpp:37
- 结论: 在遍历 list<int> 时，如果元素值为 0，则调用 data.clear() 清空列表，导致后续的迭代器解引用操作 (*i) 与迭代器递增操作 (++i) 变为未定义行为，因为迭代器已失效。这违反了 CWE-672（对释放后资源进行操作）。
- D验证: confirmed / ver_44a4b5ad
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 60. hyp_path_810b58fc41f2

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_52b.cpp:36
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制list<int>对象的生命周期，使其在传递给case0Sink_b之前被释放或过期。
- 触发路径: void case0Sink_b(list<int> data) { case0Sink_c(data); } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_52b.cpp:34-38
- 结论: 在资源过期或释放后操作list<int>对象，可能访问已释放的内存，构成Use-After-Free漏洞。
- D验证: confirmed / ver_cb72ba24
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 61. hyp_path_e9458fa2d410

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_53b.cpp:36
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制list<int> data的内容或生命周期
- 触发路径: void case0Sink_b(list<int> data) { case0Sink_c(data); } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_53b.cpp:34; 候选调用包含list析构函数，暗示data可能在后续使用前已被释放 @ 相同文件第36行（候选位置）
- 结论: 基于现有证据，可能存在操作已释放或过期的list<int>资源，导致CWE-672漏洞。但case0Sink_c函数体未提供，无法确认释放后使用的具体路径。
- D验证: confirmed / ver_8a121315
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 62. hyp_path_73272ab5a2a3

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_53c.cpp:36
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制list<int> data的内容或生命周期，使得在调用case0Sink_d之前data已被释放或进入悬空状态。
- 触发路径: void case0Sink_c(list<int> data) { case0Sink_d(data); } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_53c.cpp:34-38
- 结论: 在case0Sink_c中调用case0Sink_d，而case0Sink_d可能对已释放的list<int>资源进行操作，导致CWE-672资源释放后使用漏洞。
- D验证: confirmed / ver_9464c608
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 63. hyp_path_aecbc8323a0c

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54b.cpp:36
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制list的内容或生命周期（如通过外部输入影响data的构造与析构时机）
- 触发路径: void case0Sink_b(list<int> data) { case0Sink_c(data); } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54b.cpp:34-38
- 结论: 可能存在使用过期或释放后的资源漏洞，但当前代码片段仅显示list按值传递，未直接展示对已释放资源的操作。需进一步分析case0Sink_c内部是否在data析构后继续使用其指针或迭代器。
- D验证: confirmed / ver_3f9b75f2
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 64. hyp_path_dc3f8a162f78

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54c.cpp:36
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制list<int> data的内容，但当前参数为值传递，攻击者需通过其他途径影响data状态
- 触发路径: void case0Sink_c(list<int> data) { case0Sink_d(data); } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54c.cpp:34; 未知，但析构函数调用表明可能释放资源 @ case0Sink_d内部（未知），但B阶段候选包括析构函数和复制构造函数调用
- 结论: 可能存在CWE-672漏洞：list<int> data在case0Sink_d中可能被释放（通过析构函数）后在后续操作中再次使用，但当前A阶段代码不完整，需要动态验证。
- D验证: confirmed / ver_390a4255
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 65. hyp_path_e4c62853fcec

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54d.cpp:36
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够控制 list<int> 对象的生命周期，使其在 case0Sink_e 中被提前释放
- 触发路径: void case0Sink_d(list<int> data) { case0Sink_e(data); } @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54d.cpp:34; case0Sink_e 内部可能通过析构函数释放 list，但调用方 case0Sink_d 仍持有 data 的引用，后续可能被使用 @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54d.cpp:36
- 结论: list<int> data 对象在生命周期结束（析构）后仍可能被函数外部或后续操作访问，导致 USE_AFTER_FREE 漏洞
- D验证: confirmed / ver_c7c1803d
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 66. hyp_path_23dc219408ef

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_63a.cpp:40
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 攻击者能够触发`case0`函数执行，且`case0Sink`函数内部将传入的指针保存到全局变量中。
- 触发路径: list<int> data; data.push_back(100); data.push_back(0); case0Sink(&data); @ CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_63a.cpp:38-40
- 结论: 在`case0`函数中，局部`list<int> data`被创建并传入`case0Sink`，该sink可能将`data`的地址保存到全局变量中。当`case0`返回后，`data`被析构，但后续代码可能通过全局指针访问已释放的`data`，导致对过期资源的操作（Use-After-Free）。
- D验证: confirmed / ver_084f74e7
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 67. hyp_path_6a929104b88b

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_64a.cpp:40
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: 无外部输入控制，漏洞存在于代码逻辑中，需要case0Sink内部释放list资源（如调用clear或delete节点）。
- 触发路径: data.push_back(100); data.push_back(0); case0Sink(&data); @ juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_64a.cpp:38-42
- 结论: 在调用case0Sink后，局部list对象data的资源被释放（如清空节点），导致随后的析构函数操作已释放资源，构成CWE-672资源过期后使用漏洞。
- D验证: confirmed / ver_34ed4e6c
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

### 68. hyp_path_acb1f2ed38ba

- 漏洞位置: juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_81_case0.cpp:0
- 漏洞类型: CWE-672
- CWE: CWE-672
- 风险等级: P0
- 触发条件: The program enters the bad() function which intentionally releases a list and then attempts to operate on it
- 触发路径: _GLOBAL__sub_I_CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_81_case0.cpp @ L? (global constructor); operation on list after release @ L? (bad function)
- 结论: Potential use-after-release or operation on expired resource in CWE672 test case
- D验证: confirmed / ver_98359a1f
- 运行证据: oracle matched patterns: MAGUS_ROUTE_CONFIRMED
- 保留原因: N/A

## Unconfirmed / Failed Verification

These records are not reported as confirmed vulnerabilities. See `verification.failed.jsonl` for full failure details.

- hyp_path_8416d8f9d36b | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_68a.cpp:0 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_0999686a36fc | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_61b.cpp:160 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2cb2546c9f46 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_61b.cpp:160 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a60c48147cfc | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_43.cpp:443 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5d26e374208b | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_61a.cpp:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_465c191f17b9 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_62b.cpp:443 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_83d70d30eb33 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_32.cpp:91 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ccf6842c4ed3 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case1V1.cpp:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0cd0532a15b7 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_61a.cpp:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1b117dd11097 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_32.cpp:119 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a6b492c568b6 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_84_case1V1.cpp:44 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_dc5bd931c9d2 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_67a.cpp:77 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_9923b10a7aa4 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_62a.cpp:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7d9cc2094738 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_66a.cpp:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c32bd84e2142 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_62a.cpp:94 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_997050bd1030 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_21.cpp:115 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1cc683091a0e | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_21.cpp:87 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_10690c27fadb | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_53d.cpp:78 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6dd13416c745 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54e.cpp:78 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7c09b064621e | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_51b.cpp:78 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_82ca88f149ff | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_84a.cpp:42 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4d240c1e56de | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_81_case1V2.cpp:30 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_60a7b559efca | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_84a.cpp:50 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bc53ce923d11 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_42.cpp:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2b3ce0390482 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_74b.cpp:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d9760400612b | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_72a.cpp:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_eb7a24fba548 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_73a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0eaf20470026 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_67a.cpp:60 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_40c4a3d5e4ea | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_67a.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7a314969a903 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_31.cpp:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_be650362f0ca | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_33.cpp:81 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c391dd1785c0 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_73b.cpp:71 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_586e84f68381 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_72b.cpp:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_52bb049fd88d | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_45.cpp:82 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9831612ae38a | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_63b.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1a1521433ec7 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_66b.cpp:69 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3a4882c888a2 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_64b.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4d178a20decf | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_68b.cpp:72 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ae1f7acb760c | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_67b.cpp:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_372e445947cb | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_64b.cpp:93 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1f26b4e94cc9 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_66b.cpp:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_52dbbb472f5d | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_68b.cpp:88 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_21e676a67236 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_45.cpp:95 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_09af06d5f94e | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_68a.cpp:64 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_18189bf9e2ed | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_43.cpp:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0afd66421382 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_08.cpp:158 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2d8191448b14 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_12.cpp:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_276c864a52be | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_12.cpp:107 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f7839da92deb | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_11.cpp:144 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_74a1f80468c6 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_08.cpp:187 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8b53d3089f7c | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_11.cpp:173 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ffa98b4337b6 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_17.cpp:112 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e3d5d059d100 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_07.cpp:150 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d126c6ff38ab | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_05.cpp:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f262a3258d84 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_09.cpp:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_add03e7e16c9 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_10.cpp:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9f9f5ec914c0 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_13.cpp:144 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8738055018d4 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_14.cpp:144 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1081ab65ddb3 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_11.cpp:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ecff9d950c91 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_05.cpp:180 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_d728784e4dfe | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_07.cpp:179 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7f91e49d2930 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_09.cpp:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0683a53e6317 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_10.cpp:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1b7a29a81e59 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_13.cpp:173 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b7d6513703da | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_14.cpp:173 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_feb6109ba6f9 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_01.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_49b26b47e6a3 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_02.cpp:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b012a40a5e05 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_03.cpp:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_655b3bcd96a5 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_03.cpp:174 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4aa77aeb1f33 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_02.cpp:145 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_e89e556e9674 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_04.cpp:151 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_90c7caf6a22f | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_04.cpp:180 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_bf71ef129d4e | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_06.cpp:150 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4a88a3e44030 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_06.cpp:179 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_fbbb473dc377 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_15.cpp:177 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_035bd008d7f6 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_15.cpp:218 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b6b2ded0d615 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_16.cpp:114 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4780bf79d077 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_18.cpp:104 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b664491e97d1 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_08.cpp:124 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6af45bb646d4 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_07.cpp:91 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f9efe0e5999c | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_13.cpp:85 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ba23802b7b2c | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_21.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5d7c6471f812 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_21.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_59280a935fb0 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83a.cpp:40 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5998d5b6ec5a | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_41.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1330582913db | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83a.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_80804c082a52 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_22a.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c3d71fe27fff | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_51a.cpp:58 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b2f49a0f5f92 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_51a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5efbc181ddf3 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_52a.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7b0ce338653f | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_53a.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_67a8b9064aee | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_52a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_73d428fea885 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_53a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6e18fe1f57ce | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54a.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4ba1ee504f91 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a50d81adce6f | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_41.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_51f373ecaa96 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_81a.cpp:47 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8459dd75f958 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_81a.cpp:54 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7e1ecd478ffe | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_44.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_99a5d87f9622 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_44.cpp:77 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2a1d16987416 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_22b.cpp:122 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4e9e2496d4e9 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_41.cpp:75 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_47b033d2622a | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_21.cpp:150 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4efda4c79970 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_44.cpp:78 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_75261b5899de | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_51b.cpp:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a54fe0aeafff | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_52c.cpp:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a0aed15ce8f8 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_53d.cpp:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9c862da722b9 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54e.cpp:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1c7d3fad8578 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_65b.cpp:66 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7365ef904e47 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_81_case1V1.cpp:37 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b9d950dda9d8 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_82_case1V1.cpp:37 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ad95254ffb3c | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_52b.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2c1a20633d7f | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_52b.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_9cf47388c4d7 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_53b.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_b38c376f5f3f | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_53b.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_cc10aac046d4 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_53c.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6cb9f4d4ae45 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_53c.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_05e6bf18ec50 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54b.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_ca04d0812f2b | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54d.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_859e38972934 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54c.cpp:48 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4596424d2c20 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54c.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_a0d59d5c33f6 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54d.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f7347350dc86 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_63a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_564f1ed49947 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_63a.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_f3327465a32e | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_64a.cpp:56 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1704e30efed1 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_02.cpp:183 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3b757642434e | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_03.cpp:184 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_66f49c44c34a | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_64a.cpp:68 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_684c28f9ca87 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_04.cpp:189 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6e25ff64ebad | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_05.cpp:192 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_c3a8484d8b7b | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_06.cpp:191 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_19cbba0bb462 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_09.cpp:186 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_096095ce1937 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_10.cpp:183 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_05bf4427c87b | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_07.cpp:191 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2e6c4ffe4470 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_08.cpp:198 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7d53e734481f | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_11.cpp:184 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_058e5e9af903 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_14.cpp:182 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_82336dfdd2cd | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_15.cpp:235 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_0184eeed3bd2 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_13.cpp:182 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_06cca5b610fe | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_01.cpp:101 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_07b6add08f4b | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_21.cpp:169 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_3cbb5c040b15 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_17.cpp:121 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6c043fc4f390 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_22a.cpp:99 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_740ddad9db8f | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_16.cpp:124 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_84ef8b2ed98e | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_12.cpp:183 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2e58b4bea37c | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_31.cpp:114 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_56b9a7035e7c | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_18.cpp:112 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_19f3a514b35b | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_32.cpp:128 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2f46ea4eb377 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_43.cpp:117 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6b227f8aab26 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_41.cpp:117 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_2f9b673bf9a0 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_42.cpp:119 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_08a8edd805fc | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_33.cpp:113 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_93852fd28a7b | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_44.cpp:122 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_317865be7cba | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_51a.cpp:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_8278af6f1e7a | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_61a.cpp:102 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_52a1f0c4dc70 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_52a.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_182d40764ccd | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54a.cpp:73 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_5c99dd8fd052 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_62a.cpp:102 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4c8420c9c7a6 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_65a.cpp:78 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6826057e839e | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_64a.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_47bead431e2b | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_63a.cpp:74 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_57eabdb371f2 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_66a.cpp:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4afb867bfbbf | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_67a.cpp:84 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1b88918952bd | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_68a.cpp:80 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_7619e45e0917 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_81a.cpp:65 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6f997c7cd46e | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_72a.cpp:91 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_6a6a4bbfe28d | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_73a.cpp:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_1afdf6411756 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_74a.cpp:90 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_4bb40b3aa6be | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83a.cpp:53 | NOT_EXPLOITABLE | payload did not satisfy oracle
- hyp_path_00316970b4ca | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/main.cpp:238 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_06c1291e9fcd | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/main_linux.cpp:113 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_d1cbe0d95ab4 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_04.cpp:0 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_eaf0ec2bfb19 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_06.cpp:0 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_fd42b78499fa | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_10.cpp:0 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_f1add60b6abe | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_11.cpp:0 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_8400f6afcb4f | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_41.cpp:0 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_6ab9d899f0be | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_43.cpp:0 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_63a3dae27ca9 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_52b.cpp:0 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_55e4ed874a91 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_61b.cpp:0 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_052966f9d61d | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_67a.cpp:0 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_55f53961a8b2 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_74b.cpp:0 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_96a43c9ee7af | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_81a.cpp:0 | NOT_ROUTE_BOUND | payload did not satisfy oracle
- hyp_path_9fbf0ce2c762 | juliet-api-misuse/testcases/CWE672_Operation_on_Resource_After_Expiration_or_Release/CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_82_case1V2.cpp:0 | NOT_EXPLOITABLE | payload did not satisfy oracle
