/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__int64_t_calloc_53b.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: calloc Allocate data using calloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* case0 function declaration */
void CWE401_Memory_Leak__int64_t_calloc_53c_case0Sink(int64_t * data);

void CWE401_Memory_Leak__int64_t_calloc_53b_case0Sink(int64_t * data)
{
    CWE401_Memory_Leak__int64_t_calloc_53c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE401_Memory_Leak__int64_t_calloc_53c_case1V1Sink(int64_t * data);

void CWE401_Memory_Leak__int64_t_calloc_53b_case1V1Sink(int64_t * data)
{
    CWE401_Memory_Leak__int64_t_calloc_53c_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE401_Memory_Leak__int64_t_calloc_53c_case1V2Sink(int64_t * data);

void CWE401_Memory_Leak__int64_t_calloc_53b_case1V2Sink(int64_t * data)
{
    CWE401_Memory_Leak__int64_t_calloc_53c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
