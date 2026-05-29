/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_68a.c
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * Case0Source:  Allocate memory for sensitive data without using VirtualLock() to lock the buffer into memory
 * Case1Source: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * Sink:
 *    Case0Sink : Authenticate the user using LogonUserA()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <windows.h>

#pragma comment(lib, "advapi32.lib")

char * CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_68_case0Data;
char * CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_68_case1V1Data;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_68b_case0Sink();

void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_68_case0()
{
    char * password;
    /* Initialize Data */
    password = "";
    password = (char *)malloc(100*sizeof(char));
    if (password == NULL)
    {
        printLine("Memory could not be allocated");
        exit(1);
    }
    /* NOTE: Do not lock the memory */
    /* INCIDENTAL NOTE: CWE-259 Hardcoded Password */
    strcpy(password, "Password1234!");
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_68_case0Data = password;
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_68b_case0Sink();
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declarations */
void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_68b_case1V1Sink();

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    char * password;
    /* Initialize Data */
    password = "";
    password = (char *)malloc(100*sizeof(char));
    if (password == NULL)
    {
        printLine("Memory could not be allocated");
        exit(1);
    }
    /* ALT: Use VirtualLock() to lock the buffer into memory */
    if(!VirtualLock(password, 100*sizeof(char)))
    {
        printLine("Memory could not be locked");
        exit(1);
    }
    /* INCIDENTAL NOTE: CWE-259 Hardcoded Password */
    strcpy(password, "Password1234!");
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_68_case1V1Data = password;
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_68b_case1V1Sink();
}

void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_68_case1()
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
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_68_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_68_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
