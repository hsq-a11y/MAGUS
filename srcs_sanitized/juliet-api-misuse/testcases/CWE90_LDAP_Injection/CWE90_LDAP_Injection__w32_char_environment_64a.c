/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_char_environment_64a.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-64a.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Use a fixed string
 * Sinks:
 *    Case0Sink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

#include <windows.h>
#include <Winldap.h>

#pragma comment(lib, "wldap32")

#ifndef OMITCASE0

/* case0 function declaration */
void CWE90_LDAP_Injection__w32_char_environment_64b_case0Sink(void * dataVoidPtr);

void CWE90_LDAP_Injection__w32_char_environment_64_case0()
{
    char * data;
    char dataBuffer[256] = "";
    data = dataBuffer;
    {
        /* Append input from an environment variable to data */
        size_t dataLen = strlen(data);
        char * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            /* NOTE: Read data from an environment variable */
            strncat(data+dataLen, environment, 256-dataLen-1);
        }
    }
    CWE90_LDAP_Injection__w32_char_environment_64b_case0Sink(&data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE90_LDAP_Injection__w32_char_environment_64b_case1V1Sink(void * dataVoidPtr);

static void case1V1()
{
    char * data;
    char dataBuffer[256] = "";
    data = dataBuffer;
    /* ALT: Use a fixed file name */
    strcat(data, "Doe, XXXXX");
    CWE90_LDAP_Injection__w32_char_environment_64b_case1V1Sink(&data);
}

void CWE90_LDAP_Injection__w32_char_environment_64_case1()
{
    case1V1();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE90_LDAP_Injection__w32_char_environment_64_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE90_LDAP_Injection__w32_char_environment_64_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
