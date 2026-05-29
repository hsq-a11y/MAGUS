/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_53c.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Copy a fixed string into data
 * Sinks: w32_vsnprintf
 *    Case1Sink: _vsnwprintf with a format string
 *    Case0Sink : _vsnwprintf without a format string
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif

#ifndef OMITCASE0

/* case0 function declaration */
void CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_53d_case0Sink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_53c_case0Sink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_53d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_53d_case1V1Sink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_53c_case1V1Sink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_53d_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_53d_case1V2Sink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_53c_case1V2Sink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_53d_case1V2Sink(data);
}

#endif /* OMITCASE1 */
