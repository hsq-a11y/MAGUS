/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_console_vfprintf_81_case1V2.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-81_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: console Read input from the console
 * Case1Source: Copy a fixed string into data
 * Sinks: vfprintf
 *    Case1Sink: vfprintf with a format string
 *    Case0Sink : vfprintf without a format string
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE1

#include <stdarg.h>
#include "std_testcase.h"
#include "CWE134_Uncontrolled_Format_String__char_console_vfprintf_81.h"

namespace CWE134_Uncontrolled_Format_String__char_console_vfprintf_81
{

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

void CWE134_Uncontrolled_Format_String__char_console_vfprintf_81_case1V2::action(char * data) const
{
    case1V2VaSink(data, data);
}

}
#endif /* OMITCASE1 */
