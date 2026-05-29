/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__wchar_t_alloca_memmove_52b.c
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * Case0Source:  Set data pointer to a small buffer
 * Case1Source: Set data pointer to a large buffer
 * Sink: memmove
 *    Case0Sink : Copy data to string using memmove
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE126_Buffer_Overread__wchar_t_alloca_memmove_52c_case0Sink(wchar_t * data);

void CWE126_Buffer_Overread__wchar_t_alloca_memmove_52b_case0Sink(wchar_t * data)
{
    CWE126_Buffer_Overread__wchar_t_alloca_memmove_52c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE126_Buffer_Overread__wchar_t_alloca_memmove_52c_case1V1Sink(wchar_t * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE126_Buffer_Overread__wchar_t_alloca_memmove_52b_case1V1Sink(wchar_t * data)
{
    CWE126_Buffer_Overread__wchar_t_alloca_memmove_52c_case1V1Sink(data);
}

#endif /* OMITCASE1 */
