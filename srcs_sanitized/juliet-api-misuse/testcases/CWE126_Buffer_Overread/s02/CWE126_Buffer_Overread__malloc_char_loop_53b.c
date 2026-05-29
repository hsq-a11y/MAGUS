/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__malloc_char_loop_53b.c
Label Definition File: CWE126_Buffer_Overread__malloc.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * Case0Source:  Use a small buffer
 * Case1Source: Use a large buffer
 * Sink: loop
 *    Case0Sink : Copy data to string using a loop
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE126_Buffer_Overread__malloc_char_loop_53c_case0Sink(char * data);

void CWE126_Buffer_Overread__malloc_char_loop_53b_case0Sink(char * data)
{
    CWE126_Buffer_Overread__malloc_char_loop_53c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE126_Buffer_Overread__malloc_char_loop_53c_case1V1Sink(char * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE126_Buffer_Overread__malloc_char_loop_53b_case1V1Sink(char * data)
{
    CWE126_Buffer_Overread__malloc_char_loop_53c_case1V1Sink(data);
}

#endif /* OMITCASE1 */
