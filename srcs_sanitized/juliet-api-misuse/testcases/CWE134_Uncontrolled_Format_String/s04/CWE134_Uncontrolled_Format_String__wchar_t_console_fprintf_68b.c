/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_console_fprintf_68b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: console Read input from the console
 * Case1Source: Copy a fixed string into data
 * Sinks: fprintf
 *    Case1Sink: fwprintf with "%s" as the second argument and data as the third
 *    Case0Sink : fwprintf with data as the second argument
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

extern wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_console_fprintf_68_case0Data;
extern wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_console_fprintf_68_case1V1Data;
extern wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_console_fprintf_68_case1V2Data;

#ifndef OMITCASE0

void CWE134_Uncontrolled_Format_String__wchar_t_console_fprintf_68b_case0Sink()
{
    wchar_t * data = CWE134_Uncontrolled_Format_String__wchar_t_console_fprintf_68_case0Data;
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    fwprintf(stdout, data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE134_Uncontrolled_Format_String__wchar_t_console_fprintf_68b_case1V1Sink()
{
    wchar_t * data = CWE134_Uncontrolled_Format_String__wchar_t_console_fprintf_68_case1V1Data;
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    fwprintf(stdout, data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE134_Uncontrolled_Format_String__wchar_t_console_fprintf_68b_case1V2Sink()
{
    wchar_t * data = CWE134_Uncontrolled_Format_String__wchar_t_console_fprintf_68_case1V2Data;
    /* ALT: Specify the format disallowing a format string vulnerability */
    fwprintf(stdout, L"%s\n", data);
}

#endif /* OMITCASE1 */
