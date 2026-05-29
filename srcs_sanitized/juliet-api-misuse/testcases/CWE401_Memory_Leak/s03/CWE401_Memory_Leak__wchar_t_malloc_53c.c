/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__wchar_t_malloc_53c.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: malloc Allocate data using malloc()
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
void CWE401_Memory_Leak__wchar_t_malloc_53d_case0Sink(wchar_t * data);

void CWE401_Memory_Leak__wchar_t_malloc_53c_case0Sink(wchar_t * data)
{
    CWE401_Memory_Leak__wchar_t_malloc_53d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE401_Memory_Leak__wchar_t_malloc_53d_case1V1Sink(wchar_t * data);

void CWE401_Memory_Leak__wchar_t_malloc_53c_case1V1Sink(wchar_t * data)
{
    CWE401_Memory_Leak__wchar_t_malloc_53d_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE401_Memory_Leak__wchar_t_malloc_53d_case1V2Sink(wchar_t * data);

void CWE401_Memory_Leak__wchar_t_malloc_53c_case1V2Sink(wchar_t * data)
{
    CWE401_Memory_Leak__wchar_t_malloc_53d_case1V2Sink(data);
}

#endif /* OMITCASE1 */
