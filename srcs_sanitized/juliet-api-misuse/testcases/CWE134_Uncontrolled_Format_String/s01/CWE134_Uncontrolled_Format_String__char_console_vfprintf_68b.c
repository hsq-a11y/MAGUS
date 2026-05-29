/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_console_vfprintf_68b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: console Read input from the console
 * Case1Source: Copy a fixed string into data
 * Sinks: vfprintf
 *    Case1Sink: vfprintf with a format string
 *    Case0Sink : vfprintf without a format string
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

extern char * CWE134_Uncontrolled_Format_String__char_console_vfprintf_68_case0Data;
extern char * CWE134_Uncontrolled_Format_String__char_console_vfprintf_68_case1V1Data;
extern char * CWE134_Uncontrolled_Format_String__char_console_vfprintf_68_case1V2Data;

#ifndef OMITCASE0

static void case0VaSink(char * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* NOTE: Do not specify the format allowing a possible format string vulnerability */
        vfprintf(stdout, data, args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__char_console_vfprintf_68b_case0Sink()
{
    char * data = CWE134_Uncontrolled_Format_String__char_console_vfprintf_68_case0Data;
    case0VaSink(data, data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1VaSink(char * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* NOTE: Do not specify the format allowing a possible format string vulnerability */
        vfprintf(stdout, data, args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__char_console_vfprintf_68b_case1V1Sink()
{
    char * data = CWE134_Uncontrolled_Format_String__char_console_vfprintf_68_case1V1Data;
    case1V1VaSink(data, data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
static void case1V2VaSink(char * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* ALT: Specify the format disallowing a format string vulnerability */
        vfprintf(stdout, "%s", args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__char_console_vfprintf_68b_case1V2Sink()
{
    char * data = CWE134_Uncontrolled_Format_String__char_console_vfprintf_68_case1V2Data;
    case1V2VaSink(data, data);
}

#endif /* OMITCASE1 */
