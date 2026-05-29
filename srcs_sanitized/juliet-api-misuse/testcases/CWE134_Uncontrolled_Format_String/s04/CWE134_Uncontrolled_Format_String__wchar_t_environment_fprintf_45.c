/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_45.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Copy a fixed string into data
 * Sinks: fprintf
 *    Case1Sink: fwprintf with "%s" as the second argument and data as the third
 *    Case0Sink : fwprintf with data as the second argument
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

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

static wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_45_case0Data;
static wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_45_case1V1Data;
static wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_45_case1V2Data;

#ifndef OMITCASE0

static void case0Sink()
{
    wchar_t * data = CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_45_case0Data;
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    fwprintf(stdout, data);
}

void CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_45_case0()
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
    CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_45_case0Data = data;
    case0Sink();
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1Sink()
{
    wchar_t * data = CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_45_case1V1Data;
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    fwprintf(stdout, data);
}

static void case1V1()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* ALT: Use a fixed string that does not contain a format specifier */
    wcscpy(data, L"fixedstringtest");
    CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_45_case1V1Data = data;
    case1V1Sink();
}

/* case1V2() uses the Case0Source with the Case1Sink */
static void case1V2Sink()
{
    wchar_t * data = CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_45_case1V2Data;
    /* ALT: Specify the format disallowing a format string vulnerability */
    fwprintf(stdout, L"%s\n", data);
}

static void case1V2()
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
    CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_45_case1V2Data = data;
    case1V2Sink();
}

void CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_45_case1()
{
    case1V1();
    case1V2();
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
    CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_45_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_45_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
