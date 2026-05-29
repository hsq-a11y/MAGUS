/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__char_alloca_ncpy_52b.c
Label Definition File: CWE124_Buffer_Underwrite.stack.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sink: ncpy
 *    Case0Sink : Copy string to data using strncpy
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE124_Buffer_Underwrite__char_alloca_ncpy_52c_case0Sink(char * data);

void CWE124_Buffer_Underwrite__char_alloca_ncpy_52b_case0Sink(char * data)
{
    CWE124_Buffer_Underwrite__char_alloca_ncpy_52c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE124_Buffer_Underwrite__char_alloca_ncpy_52c_case1V1Sink(char * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE124_Buffer_Underwrite__char_alloca_ncpy_52b_case1V1Sink(char * data)
{
    CWE124_Buffer_Underwrite__char_alloca_ncpy_52c_case1V1Sink(data);
}

#endif /* OMITCASE1 */
