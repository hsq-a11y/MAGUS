/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_file_w32_vsnprintf_83_case1V1.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: file Read input from a file
 * Case1Source: Copy a fixed string into data
 * Sinks: w32_vsnprintf
 *    Case1Sink: _vsnwprintf with a format string
 *    Case0Sink : _vsnwprintf without a format string
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include <stdarg.h>
#include "std_testcase.h"
#include "CWE134_Uncontrolled_Format_String__wchar_t_file_w32_vsnprintf_83.h"

namespace CWE134_Uncontrolled_Format_String__wchar_t_file_w32_vsnprintf_83
{
CWE134_Uncontrolled_Format_String__wchar_t_file_w32_vsnprintf_83_case1V1::CWE134_Uncontrolled_Format_String__wchar_t_file_w32_vsnprintf_83_case1V1(wchar_t * dataCopy)
{
    data = dataCopy;
    /* ALT: Use a fixed string that does not contain a format specifier */
    wcscpy(data, L"fixedstringtest");
}

static void case1V1VaSink(wchar_t * data, ...)
{
    {
        wchar_t dest[100] = L"";
        va_list args;
        va_start(args, data);
        /* NOTE: Do not specify the format allowing a possible format string vulnerability */
        _vsnwprintf(dest, 100-1, data, args);
        va_end(args);
        printWLine(dest);
    }
}

CWE134_Uncontrolled_Format_String__wchar_t_file_w32_vsnprintf_83_case1V1::~CWE134_Uncontrolled_Format_String__wchar_t_file_w32_vsnprintf_83_case1V1()
{
    case1V1VaSink(data, data);
}
}
#endif /* OMITCASE1 */
