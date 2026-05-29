/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_console_fprintf_54b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: console Read input from the console
 * Case1Source: Copy a fixed string into data
 * Sinks: fprintf
 *    Case1Sink: fprintf with "%s" as the second argument and data as the third
 *    Case0Sink : fprintf with data as the second argument
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITCASE0

/* case0 function declaration */
void CWE134_Uncontrolled_Format_String__char_console_fprintf_54c_case0Sink(char * data);

void CWE134_Uncontrolled_Format_String__char_console_fprintf_54b_case0Sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_console_fprintf_54c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE134_Uncontrolled_Format_String__char_console_fprintf_54c_case1V1Sink(char * data);

void CWE134_Uncontrolled_Format_String__char_console_fprintf_54b_case1V1Sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_console_fprintf_54c_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE134_Uncontrolled_Format_String__char_console_fprintf_54c_case1V2Sink(char * data);

void CWE134_Uncontrolled_Format_String__char_console_fprintf_54b_case1V2Sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_console_fprintf_54c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
