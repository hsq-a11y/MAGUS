/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_wchar_t_environment_22b.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Use a fixed string
 * Sink:
 *    Case0Sink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
extern int CWE90_LDAP_Injection__w32_wchar_t_environment_22_case0Global;

wchar_t * CWE90_LDAP_Injection__w32_wchar_t_environment_22_case0Source(wchar_t * data)
{
    if(CWE90_LDAP_Injection__w32_wchar_t_environment_22_case0Global)
    {
        {
            /* Append input from an environment variable to data */
            size_t dataLen = wcslen(data);
            wchar_t * environment = GETENV(ENV_VARIABLE);
            /* If there is data in the environment variable */
            if (environment != NULL)
            {
                /* NOTE: Read data from an environment variable */
                wcsncat(data+dataLen, environment, 256-dataLen-1);
            }
        }
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE90_LDAP_Injection__w32_wchar_t_environment_22_case1V11Global;
extern int CWE90_LDAP_Injection__w32_wchar_t_environment_22_case1V12Global;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
wchar_t * CWE90_LDAP_Injection__w32_wchar_t_environment_22_case1V11Source(wchar_t * data)
{
    if(CWE90_LDAP_Injection__w32_wchar_t_environment_22_case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Use a fixed file name */
        wcscat(data, L"Doe, XXXXX");
    }
    return data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
wchar_t * CWE90_LDAP_Injection__w32_wchar_t_environment_22_case1V12Source(wchar_t * data)
{
    if(CWE90_LDAP_Injection__w32_wchar_t_environment_22_case1V12Global)
    {
        /* ALT: Use a fixed file name */
        wcscat(data, L"Doe, XXXXX");
    }
    return data;
}

#endif /* OMITCASE1 */
