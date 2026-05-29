/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cpy_84_case1V1.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_src.label.xml
Template File: sources-sink-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize data as a large string
 * Case1Source: Initialize data as a small string
 * Sinks: cpy
 *    Case0Sink : Copy data to string using wcscpy
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cpy_84.h"

namespace CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cpy_84
{
CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cpy_84_case1V1::CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cpy_84_case1V1(wchar_t * dataCopy)
{
    data = dataCopy;
    /* ALT: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
    wmemset(data, L'A', 50-1); /* fill with L'A's */
    data[50-1] = L'\0'; /* null terminate */
}

CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cpy_84_case1V1::~CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cpy_84_case1V1()
{
    {
        wchar_t dest[50] = L"";
        /* NOTE: Possible buffer overflow if data is larger than dest */
        wcscpy(dest, data);
        printWLine(data);
        free(data);
    }
}
}
#endif /* OMITCASE1 */
