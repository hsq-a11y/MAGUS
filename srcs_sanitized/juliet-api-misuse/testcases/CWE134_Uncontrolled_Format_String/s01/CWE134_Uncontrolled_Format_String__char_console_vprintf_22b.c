/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_console_vprintf_22b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: console Read input from the console
 * Case1Source: Copy a fixed string into data
 * Sinks: vprintf
 *    Case1Sink: vprintf with a format string
 *    Case0Sink : vprintf without a format string
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
extern int CWE134_Uncontrolled_Format_String__char_console_vprintf_22_case0Global;

void CWE134_Uncontrolled_Format_String__char_console_vprintf_22_case0VaSink(char * data, ...)
{
    if(CWE134_Uncontrolled_Format_String__char_console_vprintf_22_case0Global)
    {
        {
            va_list args;
            va_start(args, data);
            /* NOTE: Do not specify the format allowing a possible format string vulnerability */
            vprintf(data, args);
            va_end(args);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE134_Uncontrolled_Format_String__char_console_vprintf_22_case1V21Global;
extern int CWE134_Uncontrolled_Format_String__char_console_vprintf_22_case1V22Global;
extern int CWE134_Uncontrolled_Format_String__char_console_vprintf_22_case1V1Global;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE134_Uncontrolled_Format_String__char_console_vprintf_22_case1V21_vasink(char * data, ...)
{
    if(CWE134_Uncontrolled_Format_String__char_console_vprintf_22_case1V21Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            va_list args;
            va_start(args, data);
            /* ALT: Specify the format disallowing a format string vulnerability */
            vprintf("%s", args);
            va_end(args);
        }
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE134_Uncontrolled_Format_String__char_console_vprintf_22_case1V22_vasink(char * data, ...)
{
    if(CWE134_Uncontrolled_Format_String__char_console_vprintf_22_case1V22Global)
    {
        {
            va_list args;
            va_start(args, data);
            /* ALT: Specify the format disallowing a format string vulnerability */
            vprintf("%s", args);
            va_end(args);
        }
    }
}

/* case1V1() - use case1source and case0sink */
void CWE134_Uncontrolled_Format_String__char_console_vprintf_22_case1V1VaSink(char * data, ...)
{
    if(CWE134_Uncontrolled_Format_String__char_console_vprintf_22_case1V1Global)
    {
        {
            va_list args;
            va_start(args, data);
            /* NOTE: Do not specify the format allowing a possible format string vulnerability */
            vprintf(data, args);
            va_end(args);
        }
    }
}

#endif /* OMITCASE1 */
