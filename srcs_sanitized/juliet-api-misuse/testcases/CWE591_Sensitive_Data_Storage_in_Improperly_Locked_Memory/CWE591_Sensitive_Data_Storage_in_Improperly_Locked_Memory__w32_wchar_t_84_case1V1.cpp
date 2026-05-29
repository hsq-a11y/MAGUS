/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_84_case1V1.cpp
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * Case0Source:  Allocate memory for sensitive data without using VirtualLock() to lock the buffer into memory
 * Case1Source: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * Sinks:
 *    Case0Sink : Authenticate the user using LogonUserW()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_84.h"

#pragma comment(lib, "advapi32.lib")

namespace CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_84
{
CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_84_case1V1::CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_84_case1V1(wchar_t * passwordCopy)
{
    password = passwordCopy;
    password = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (password == NULL)
    {
        printLine("Memory could not be allocated");
        exit(1);
    }
    /* ALT: Use VirtualLock() to lock the buffer into memory */
    if(!VirtualLock(password, 100*sizeof(wchar_t)))
    {
        printLine("Memory could not be locked");
        exit(1);
    }
    /* INCIDENTAL NOTE: CWE-259 Hardcoded Password */
    wcscpy(password, L"Password1234!");
}

CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_84_case1V1::~CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_84_case1V1()
{
    {
        HANDLE pHandle;
        wchar_t * username = L"User";
        wchar_t * domain = L"Domain";
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserW(
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
}
#endif /* OMITCASE1 */
