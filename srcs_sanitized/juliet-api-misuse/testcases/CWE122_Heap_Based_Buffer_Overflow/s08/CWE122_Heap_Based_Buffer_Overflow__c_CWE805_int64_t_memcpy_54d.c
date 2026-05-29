/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_54d.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.label.xml
Template File: sources-sink-54d.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using malloc() and set data pointer to a small buffer
 * Case1Source: Allocate using malloc() and set data pointer to a large buffer
 * Sink: memcpy
 *    Case0Sink : Copy int64_t array to data using memcpy
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_54e_case0Sink(int64_t * data);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_54d_case0Sink(int64_t * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_54e_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_54e_case1V1Sink(int64_t * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_54d_case1V1Sink(int64_t * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_54e_case1V1Sink(data);
}

#endif /* OMITCASE1 */
