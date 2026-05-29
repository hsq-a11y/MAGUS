/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__wchar_t_declare_memcpy_52b.c
Label Definition File: CWE124_Buffer_Underwrite.stack.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sink: memcpy
 *    Case0Sink : Copy string to data using memcpy
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE124_Buffer_Underwrite__wchar_t_declare_memcpy_52c_case0Sink(wchar_t * data);

void CWE124_Buffer_Underwrite__wchar_t_declare_memcpy_52b_case0Sink(wchar_t * data)
{
    CWE124_Buffer_Underwrite__wchar_t_declare_memcpy_52c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE124_Buffer_Underwrite__wchar_t_declare_memcpy_52c_case1V1Sink(wchar_t * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE124_Buffer_Underwrite__wchar_t_declare_memcpy_52b_case1V1Sink(wchar_t * data)
{
    CWE124_Buffer_Underwrite__wchar_t_declare_memcpy_52c_case1V1Sink(data);
}

#endif /* OMITCASE1 */
