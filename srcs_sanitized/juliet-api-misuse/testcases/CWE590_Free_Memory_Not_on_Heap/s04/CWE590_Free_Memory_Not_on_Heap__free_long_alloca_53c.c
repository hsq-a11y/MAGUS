/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_long_alloca_53c.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: alloca Data buffer is allocated on the stack with alloca()
 * Case1Source: Allocate memory on the heap
 * Sink:
 *    Case0Sink : Print then free data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE590_Free_Memory_Not_on_Heap__free_long_alloca_53d_case0Sink(long * data);

void CWE590_Free_Memory_Not_on_Heap__free_long_alloca_53c_case0Sink(long * data)
{
    CWE590_Free_Memory_Not_on_Heap__free_long_alloca_53d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE590_Free_Memory_Not_on_Heap__free_long_alloca_53d_case1V1Sink(long * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE590_Free_Memory_Not_on_Heap__free_long_alloca_53c_case1V1Sink(long * data)
{
    CWE590_Free_Memory_Not_on_Heap__free_long_alloca_53d_case1V1Sink(data);
}

#endif /* OMITCASE1 */
