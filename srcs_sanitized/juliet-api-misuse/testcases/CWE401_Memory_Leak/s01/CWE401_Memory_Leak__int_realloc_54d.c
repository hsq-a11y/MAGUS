/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__int_realloc_54d.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: realloc Allocate data using realloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* case0 function declaration */
void CWE401_Memory_Leak__int_realloc_54e_case0Sink(int * data);

void CWE401_Memory_Leak__int_realloc_54d_case0Sink(int * data)
{
    CWE401_Memory_Leak__int_realloc_54e_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE401_Memory_Leak__int_realloc_54e_case1V1Sink(int * data);

void CWE401_Memory_Leak__int_realloc_54d_case1V1Sink(int * data)
{
    CWE401_Memory_Leak__int_realloc_54e_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE401_Memory_Leak__int_realloc_54e_case1V2Sink(int * data);

void CWE401_Memory_Leak__int_realloc_54d_case1V2Sink(int * data)
{
    CWE401_Memory_Leak__int_realloc_54e_case1V2Sink(data);
}

#endif /* OMITCASE1 */
