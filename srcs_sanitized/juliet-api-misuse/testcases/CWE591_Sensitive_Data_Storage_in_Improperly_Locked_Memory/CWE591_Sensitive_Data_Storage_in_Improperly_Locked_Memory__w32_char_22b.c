/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22b.c
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-22b.tmpl.c
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

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
extern int CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case0Global;

char * CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case0Source(char * password)
{
    if(CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case0Global)
    {
        password = (char *)malloc(100*sizeof(char));
        if (password == NULL)
        {
            printLine("Memory could not be allocated");
            exit(1);
        }
        /* NOTE: Do not lock the memory */
        /* INCIDENTAL NOTE: CWE-259 Hardcoded Password */
        strcpy(password, "Password1234!");
    }
    return password;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case1V11Global;
extern int CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case1V12Global;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
char * CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case1V11Source(char * password)
{
    if(CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
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
    }
    return password;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
char * CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case1V12Source(char * password)
{
    if(CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_22_case1V12Global)
    {
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
    }
    return password;
}

#endif /* OMITCASE1 */
