/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22a.c
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * Case0Source:  Allocate memory for sensitive data without using VirtualLock() to lock the buffer into memory
 * Case1Source: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * Sink:
 *    Case0Sink : Authenticate the user using LogonUserA()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <windows.h>

#pragma comment(lib, "advapi32.lib")

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
int CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case0Global = 0;

char * CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case0Source(char * password);

void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case0()
{
    char * password;
    /* Initialize Data */
    password = "";
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case0Global = 1; /* true */
    password = CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case0Source(password);
    {
        HANDLE pHandle;
        char * username = "User";
        char * domain = "Domain";
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserA(
                    username,
                    domain,
                    password,
                    LOGON32_LOGON_NETWORK,
                    LOGON32_PROVIDER_DEFAULT,
                    &pHandle) != 0)
        {
            printLine("User logged in successfully.");
            CloseHandle(pHandle);
        }
        else
        {
            printLine("Unable to login.");
        }
        /* NOTE: Sensitive data possibly improperly locked */
        free(password);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
int CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case1V11Global = 0;
int CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case1V12Global = 0;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
char * CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case1V11Source(char * password);

static void case1V11()
{
    char * password;
    /* Initialize Data */
    password = "";
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case1V11Global = 0; /* false */
    password = CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case1V11Source(password);
    {
        HANDLE pHandle;
        char * username = "User";
        char * domain = "Domain";
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserA(
                    username,
                    domain,
                    password,
                    LOGON32_LOGON_NETWORK,
                    LOGON32_PROVIDER_DEFAULT,
                    &pHandle) != 0)
        {
            printLine("User logged in successfully.");
            CloseHandle(pHandle);
        }
        else
        {
            printLine("Unable to login.");
        }
        /* NOTE: Sensitive data possibly improperly locked */
        free(password);
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
char * CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case1V12Source(char * password);

static void case1V12()
{
    char * password;
    /* Initialize Data */
    password = "";
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case1V12Global = 1; /* true */
    password = CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case1V12Source(password);
    {
        HANDLE pHandle;
        char * username = "User";
        char * domain = "Domain";
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserA(
                    username,
                    domain,
                    password,
                    LOGON32_LOGON_NETWORK,
                    LOGON32_PROVIDER_DEFAULT,
                    &pHandle) != 0)
        {
            printLine("User logged in successfully.");
            CloseHandle(pHandle);
        }
        else
        {
            printLine("Unable to login.");
        }
        /* NOTE: Sensitive data possibly improperly locked */
        free(password);
    }
}

void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case1()
{
    case1V11();
    case1V12();
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
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
