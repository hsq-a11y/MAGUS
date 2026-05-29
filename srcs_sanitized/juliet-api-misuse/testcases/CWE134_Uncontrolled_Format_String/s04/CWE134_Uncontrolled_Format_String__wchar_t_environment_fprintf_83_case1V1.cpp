/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_83_case1V1.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Copy a fixed string into data
 * Sinks: fprintf
 *    Case1Sink: fwprintf with "%s" as the second argument and data as the third
 *    Case0Sink : fwprintf with data as the second argument
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_83.h"

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif

namespace CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_83
{
CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_83_case1V1::CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_83_case1V1(wchar_t * dataCopy)
{
    data = dataCopy;
    /* ALT: Use a fixed string that does not contain a format specifier */
    wcscpy(data, L"fixedstringtest");
}

CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_83_case1V1::~CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_83_case1V1()
{
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    fwprintf(stdout, data);
}
}
#endif /* OMITCASE1 */
