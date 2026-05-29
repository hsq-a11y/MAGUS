/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_console_printf_22b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: console Read input from the console
 * Case1Source: Copy a fixed string into data
 * Sinks: printf
 *    Case1Sink: wprintf with "%s" as the first argument and data as the second
 *    Case0Sink : wprintf with only data as an argument
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
extern int CWE134_Uncontrolled_Format_String__wchar_t_console_printf_22_case0Global;

void CWE134_Uncontrolled_Format_String__wchar_t_console_printf_22_case0Sink(wchar_t * data)
{
    if(CWE134_Uncontrolled_Format_String__wchar_t_console_printf_22_case0Global)
    {
        /* NOTE: Do not specify the format allowing a possible format string vulnerability */
        wprintf(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE134_Uncontrolled_Format_String__wchar_t_console_printf_22_case1V21Global;
extern int CWE134_Uncontrolled_Format_String__wchar_t_console_printf_22_case1V22Global;
extern int CWE134_Uncontrolled_Format_String__wchar_t_console_printf_22_case1V1Global;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE134_Uncontrolled_Format_String__wchar_t_console_printf_22_case1V21Sink(wchar_t * data)
{
    if(CWE134_Uncontrolled_Format_String__wchar_t_console_printf_22_case1V21Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Specify the format disallowing a format string vulnerability */
        wprintf(L"%s\n", data);
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE134_Uncontrolled_Format_String__wchar_t_console_printf_22_case1V22Sink(wchar_t * data)
{
    if(CWE134_Uncontrolled_Format_String__wchar_t_console_printf_22_case1V22Global)
    {
        /* ALT: Specify the format disallowing a format string vulnerability */
        wprintf(L"%s\n", data);
    }
}

/* case1V1() - use case1source and case0sink */
void CWE134_Uncontrolled_Format_String__wchar_t_console_printf_22_case1V1Sink(wchar_t * data)
{
    if(CWE134_Uncontrolled_Format_String__wchar_t_console_printf_22_case1V1Global)
    {
        /* NOTE: Do not specify the format allowing a possible format string vulnerability */
        wprintf(data);
    }
}

#endif /* OMITCASE1 */
