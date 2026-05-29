/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_console_vfprintf_84_case1V1.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: console Read input from the console
 * Case1Source: Copy a fixed string into data
 * Sinks: vfprintf
 *    Case1Sink: vfprintf with a format string
 *    Case0Sink : vfprintf without a format string
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include <stdarg.h>
#include "std_testcase.h"
#include "CWE134_Uncontrolled_Format_String__char_console_vfprintf_84.h"

namespace CWE134_Uncontrolled_Format_String__char_console_vfprintf_84
{
CWE134_Uncontrolled_Format_String__char_console_vfprintf_84_case1V1::CWE134_Uncontrolled_Format_String__char_console_vfprintf_84_case1V1(char * dataCopy)
{
    data = dataCopy;
    /* ALT: Use a fixed string that does not contain a format specifier */
    strcpy(data, "fixedstringtest");
}

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

CWE134_Uncontrolled_Format_String__char_console_vfprintf_84_case1V1::~CWE134_Uncontrolled_Format_String__char_console_vfprintf_84_case1V1()
{
    case1V1VaSink(data, data);
}
}
#endif /* OMITCASE1 */
