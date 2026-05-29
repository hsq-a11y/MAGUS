/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_int64_t_declare_53b.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: declare Data buffer is declared on the stack
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
void CWE590_Free_Memory_Not_on_Heap__free_int64_t_declare_53c_case0Sink(int64_t * data);

void CWE590_Free_Memory_Not_on_Heap__free_int64_t_declare_53b_case0Sink(int64_t * data)
{
    CWE590_Free_Memory_Not_on_Heap__free_int64_t_declare_53c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE590_Free_Memory_Not_on_Heap__free_int64_t_declare_53c_case1V1Sink(int64_t * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE590_Free_Memory_Not_on_Heap__free_int64_t_declare_53b_case1V1Sink(int64_t * data)
{
    CWE590_Free_Memory_Not_on_Heap__free_int64_t_declare_53c_case1V1Sink(data);
}

#endif /* OMITCASE1 */
