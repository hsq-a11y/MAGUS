/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_environment_vfprintf_83_case0.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Copy a fixed string into data
 * Sinks: vfprintf
 *    Case1Sink: vfwprintf with a format string
 *    Case0Sink : vfwprintf without a format string
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include <stdarg.h>
#include "std_testcase.h"
#include "CWE134_Uncontrolled_Format_String__wchar_t_environment_vfprintf_83.h"

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif

namespace CWE134_Uncontrolled_Format_String__wchar_t_environment_vfprintf_83
{
CWE134_Uncontrolled_Format_String__wchar_t_environment_vfprintf_83_case0::CWE134_Uncontrolled_Format_String__wchar_t_environment_vfprintf_83_case0(wchar_t * dataCopy)
{
    data = dataCopy;
    {
        /* Append input from an environment variable to data */
        size_t dataLen = wcslen(data);
        wchar_t * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            /* NOTE: Read data from an environment variable */
            wcsncat(data+dataLen, environment, 100-dataLen-1);
        }
    }
}

static void case0VaSink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* NOTE: Do not specify the format allowing a possible format string vulnerability */
        vfwprintf(stdout, data, args);
        va_end(args);
    }
}

CWE134_Uncontrolled_Format_String__wchar_t_environment_vfprintf_83_case0::~CWE134_Uncontrolled_Format_String__wchar_t_environment_vfprintf_83_case0()
{
    case0VaSink(data, data);
}
}
#endif /* OMITCASE0 */
