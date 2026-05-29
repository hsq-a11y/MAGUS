/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cat_53c.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_src.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize data as a large string
 * Case1Source: Initialize data as a small string
 * Sink: cat
 *    Case0Sink : Copy data to string using wcscat
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cat_53d_case0Sink(wchar_t * data);

void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cat_53c_case0Sink(wchar_t * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cat_53d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cat_53d_case1V1Sink(wchar_t * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cat_53c_case1V1Sink(wchar_t * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cat_53d_case1V1Sink(data);
}

#endif /* OMITCASE1 */
