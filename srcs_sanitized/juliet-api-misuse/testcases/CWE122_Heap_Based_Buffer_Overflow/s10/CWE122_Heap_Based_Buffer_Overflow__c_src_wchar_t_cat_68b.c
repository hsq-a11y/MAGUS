/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cat_68b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_src.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize data as a large string
 * Case1Source: Initialize data as a small string
 * Sink: cat
 *    Case0Sink : Copy data to string using wcscat
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern wchar_t * CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cat_68_case0Data;
extern wchar_t * CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cat_68_case1V1Data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cat_68b_case0Sink()
{
    wchar_t * data = CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cat_68_case0Data;
    {
        wchar_t dest[50] = L"";
        /* NOTE: Possible buffer overflow if data is larger than sizeof(dest)-wcslen(dest)*/
        wcscat(dest, data);
        printWLine(data);
        free(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cat_68b_case1V1Sink()
{
    wchar_t * data = CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cat_68_case1V1Data;
    {
        wchar_t dest[50] = L"";
        /* NOTE: Possible buffer overflow if data is larger than sizeof(dest)-wcslen(dest)*/
        wcscat(dest, data);
        printWLine(data);
        free(data);
    }
}

#endif /* OMITCASE1 */
