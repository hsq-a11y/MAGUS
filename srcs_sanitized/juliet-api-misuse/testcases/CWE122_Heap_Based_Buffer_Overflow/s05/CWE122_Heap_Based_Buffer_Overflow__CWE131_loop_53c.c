/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_53c.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory without using sizeof(int)
 * Case1Source: Allocate memory using sizeof(int)
 * Sink: loop
 *    Case0Sink : Copy array to data using a loop
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_53d_case0Sink(int * data);

void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_53c_case0Sink(int * data)
{
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_53d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_53d_case1V1Sink(int * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_53c_case1V1Sink(int * data)
{
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_53d_case1V1Sink(data);
}

#endif /* OMITCASE1 */
