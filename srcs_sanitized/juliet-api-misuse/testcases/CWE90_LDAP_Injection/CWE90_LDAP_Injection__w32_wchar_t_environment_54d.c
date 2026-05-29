/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_wchar_t_environment_54d.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-54d.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Use a fixed string
 * Sink:
 *    Case0Sink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif

#include <windows.h>
#include <Winldap.h>

#pragma comment(lib, "wldap32")

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE90_LDAP_Injection__w32_wchar_t_environment_54e_case0Sink(wchar_t * data);

void CWE90_LDAP_Injection__w32_wchar_t_environment_54d_case0Sink(wchar_t * data)
{
    CWE90_LDAP_Injection__w32_wchar_t_environment_54e_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE90_LDAP_Injection__w32_wchar_t_environment_54e_case1V1Sink(wchar_t * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE90_LDAP_Injection__w32_wchar_t_environment_54d_case1V1Sink(wchar_t * data)
{
    CWE90_LDAP_Injection__w32_wchar_t_environment_54e_case1V1Sink(data);
}

#endif /* OMITCASE1 */
