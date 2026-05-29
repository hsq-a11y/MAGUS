/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_67b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Copy a fixed string into data
 * Sinks: w32_vsnprintf
 *    Case1Sink: _vsnwprintf with a format string
 *    Case0Sink : _vsnwprintf without a format string
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
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

typedef struct _CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_67_structType
{
    wchar_t * structFirst;
} CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_67_structType;

#ifndef OMITCASE0

static void case0VaSink(wchar_t * data, ...)
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

void CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_67b_case0Sink(CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    case0VaSink(data, data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
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

void CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_67b_case1V1Sink(CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    case1V1VaSink(data, data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
static void case1V2VaSink(wchar_t * data, ...)
{
    {
        wchar_t dest[100] = L"";
        va_list args;
        va_start(args, data);
        /* ALT: Specify the format disallowing a format string vulnerability */
        _vsnwprintf(dest, 100-1, L"%s", args);
        va_end(args);
        printWLine(dest);
    }
}

void CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_67b_case1V2Sink(CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    case1V2VaSink(data, data);
}

#endif /* OMITCASE1 */
