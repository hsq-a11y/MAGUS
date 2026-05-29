/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_console_snprintf_68b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: console Read input from the console
 * Case1Source: Copy a fixed string into data
 * Sinks: snprintf
 *    Case1Sink: snprintf with "%s" as the third argument and data as the fourth
 *    Case0Sink : snprintf with data as the third argument
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define SNPRINTF _snprintf
#else
#define SNPRINTF snprintf
#endif

extern char * CWE134_Uncontrolled_Format_String__char_console_snprintf_68_case0Data;
extern char * CWE134_Uncontrolled_Format_String__char_console_snprintf_68_case1V1Data;
extern char * CWE134_Uncontrolled_Format_String__char_console_snprintf_68_case1V2Data;

#ifndef OMITCASE0

void CWE134_Uncontrolled_Format_String__char_console_snprintf_68b_case0Sink()
{
    char * data = CWE134_Uncontrolled_Format_String__char_console_snprintf_68_case0Data;
    {
        char dest[100] = "";
        /* NOTE: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printLine(dest);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE134_Uncontrolled_Format_String__char_console_snprintf_68b_case1V1Sink()
{
    char * data = CWE134_Uncontrolled_Format_String__char_console_snprintf_68_case1V1Data;
    {
        char dest[100] = "";
        /* NOTE: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printLine(dest);
    }
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE134_Uncontrolled_Format_String__char_console_snprintf_68b_case1V2Sink()
{
    char * data = CWE134_Uncontrolled_Format_String__char_console_snprintf_68_case1V2Data;
    {
        char dest[100] = "";
        /* ALT: Specify the format disallowing a format string vulnerability */
        SNPRINTF(dest, 100-1, "%s", data);
        printLine(dest);
    }
}

#endif /* OMITCASE1 */
