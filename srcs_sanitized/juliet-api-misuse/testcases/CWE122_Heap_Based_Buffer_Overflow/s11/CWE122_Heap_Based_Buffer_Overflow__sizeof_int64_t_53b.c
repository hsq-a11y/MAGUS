/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_53b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize the source buffer using the size of a pointer
 * Case1Source: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    Case0Sink : Print then free data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_53c_case0Sink(int64_t * data);

void CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_53b_case0Sink(int64_t * data)
{
    CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_53c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_53c_case1V1Sink(int64_t * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_53b_case1V1Sink(int64_t * data)
{
    CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_53c_case1V1Sink(data);
}

#endif /* OMITCASE1 */
