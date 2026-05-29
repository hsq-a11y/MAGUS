/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__malloc_wchar_t_memcpy_54d.c
Label Definition File: CWE126_Buffer_Overread__malloc.label.xml
Template File: sources-sink-54d.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * Case0Source:  Use a small buffer
 * Case1Source: Use a large buffer
 * Sink: memcpy
 *    Case0Sink : Copy data to string using memcpy
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE126_Buffer_Overread__malloc_wchar_t_memcpy_54e_case0Sink(wchar_t * data);

void CWE126_Buffer_Overread__malloc_wchar_t_memcpy_54d_case0Sink(wchar_t * data)
{
    CWE126_Buffer_Overread__malloc_wchar_t_memcpy_54e_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE126_Buffer_Overread__malloc_wchar_t_memcpy_54e_case1V1Sink(wchar_t * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE126_Buffer_Overread__malloc_wchar_t_memcpy_54d_case1V1Sink(wchar_t * data)
{
    CWE126_Buffer_Overread__malloc_wchar_t_memcpy_54e_case1V1Sink(data);
}

#endif /* OMITCASE1 */
