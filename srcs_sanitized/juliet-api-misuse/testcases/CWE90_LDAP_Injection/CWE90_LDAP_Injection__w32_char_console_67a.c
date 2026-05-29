/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_char_console_67a.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * Case0Source: console Read input from the console
 * Case1Source: Use a fixed string
 * Sinks:
 *    Case0Sink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <Winldap.h>

#pragma comment(lib, "wldap32")

typedef struct _CWE90_LDAP_Injection__w32_char_console_67_structType
{
    char * structFirst;
} CWE90_LDAP_Injection__w32_char_console_67_structType;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE90_LDAP_Injection__w32_char_console_67b_case0Sink(CWE90_LDAP_Injection__w32_char_console_67_structType myStruct);

void CWE90_LDAP_Injection__w32_char_console_67_case0()
{
    char * data;
    CWE90_LDAP_Injection__w32_char_console_67_structType myStruct;
    char dataBuffer[256] = "";
    data = dataBuffer;
    {
        /* Read input from the console */
        size_t dataLen = strlen(data);
        /* if there is room in data, read into it from the console */
        if (256-dataLen > 1)
        {
            /* NOTE: Read data from the console */
            if (fgets(data+dataLen, (int)(256-dataLen), stdin) != NULL)
            {
                /* The next few lines remove the carriage return from the string that is
                 * inserted by fgets() */
                dataLen = strlen(data);
                if (dataLen > 0 && data[dataLen-1] == '\n')
                {
                    data[dataLen-1] = '\0';
                }
            }
            else
            {
                printLine("fgets() failed");
                /* Restore NUL terminator if fgets fails */
                data[dataLen] = '\0';
            }
        }
    }
    myStruct.structFirst = data;
    CWE90_LDAP_Injection__w32_char_console_67b_case0Sink(myStruct);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE90_LDAP_Injection__w32_char_console_67b_case1V1Sink(CWE90_LDAP_Injection__w32_char_console_67_structType myStruct);

static void case1V1()
{
    char * data;
    CWE90_LDAP_Injection__w32_char_console_67_structType myStruct;
    char dataBuffer[256] = "";
    data = dataBuffer;
    /* ALT: Use a fixed file name */
    strcat(data, "Doe, XXXXX");
    myStruct.structFirst = data;
    CWE90_LDAP_Injection__w32_char_console_67b_case1V1Sink(myStruct);
}

void CWE90_LDAP_Injection__w32_char_console_67_case1()
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
    CWE90_LDAP_Injection__w32_char_console_67_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE90_LDAP_Injection__w32_char_console_67_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
