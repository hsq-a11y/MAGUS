/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__char_declare_memcpy_54c.c
Label Definition File: CWE127_Buffer_Underread.stack.label.xml
Template File: sources-sink-54c.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
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
void CWE127_Buffer_Underread__char_declare_memcpy_54d_case0Sink(char * data);

void CWE127_Buffer_Underread__char_declare_memcpy_54c_case0Sink(char * data)
{
    CWE127_Buffer_Underread__char_declare_memcpy_54d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE127_Buffer_Underread__char_declare_memcpy_54d_case1V1Sink(char * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE127_Buffer_Underread__char_declare_memcpy_54c_case1V1Sink(char * data)
{
    CWE127_Buffer_Underread__char_declare_memcpy_54d_case1V1Sink(data);
}

#endif /* OMITCASE1 */
