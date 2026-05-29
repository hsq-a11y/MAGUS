/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__wchar_t_declare_memmove_53b.c
Label Definition File: CWE127_Buffer_Underread.stack.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sink: memmove
 *    Case0Sink : Copy data to string using memmove
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE127_Buffer_Underread__wchar_t_declare_memmove_53c_case0Sink(wchar_t * data);

void CWE127_Buffer_Underread__wchar_t_declare_memmove_53b_case0Sink(wchar_t * data)
{
    CWE127_Buffer_Underread__wchar_t_declare_memmove_53c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE127_Buffer_Underread__wchar_t_declare_memmove_53c_case1V1Sink(wchar_t * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE127_Buffer_Underread__wchar_t_declare_memmove_53b_case1V1Sink(wchar_t * data)
{
    CWE127_Buffer_Underread__wchar_t_declare_memmove_53c_case1V1Sink(data);
}

#endif /* OMITCASE1 */
