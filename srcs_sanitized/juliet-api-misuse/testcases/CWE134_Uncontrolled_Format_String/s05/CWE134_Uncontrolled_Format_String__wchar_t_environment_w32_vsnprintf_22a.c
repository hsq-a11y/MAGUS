/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22a.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Copy a fixed string into data
 * Sinks: w32_vsnprintf
 *    Case1Sink: _vsnwprintf with a format string
 *    Case0Sink : _vsnwprintf without a format string
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
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

/* The global variable below is used to drive control flow in the sink function */
int CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case0Global = 0;

void CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case0VaSink(wchar_t * data, ...);

void CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case0()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
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
    CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case0Global = 1; /* true */
    CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case0VaSink(data, data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
int CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case1V21Global = 0;
int CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case1V22Global = 0;
int CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case1V1Global = 0;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case1V21_vasink(wchar_t * data, ...);

static void case1V21()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
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
    CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case1V21Global = 0; /* false */
    CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case1V21_vasink(data, data);
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case1V22_vasink(wchar_t * data, ...);

static void case1V22()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
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
    CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case1V22Global = 1; /* true */
    CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case1V22_vasink(data, data);
}

/* case1V1() - use case1source and case0sink */
void CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case1V1VaSink(wchar_t * data, ...);

static void case1V1()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* ALT: Use a fixed string that does not contain a format specifier */
    wcscpy(data, L"fixedstringtest");
    CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case1V1Global = 1; /* true */
    CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case1V1VaSink(data, data);
}

void CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case1()
{
    case1V21();
    case1V22();
    case1V1();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
