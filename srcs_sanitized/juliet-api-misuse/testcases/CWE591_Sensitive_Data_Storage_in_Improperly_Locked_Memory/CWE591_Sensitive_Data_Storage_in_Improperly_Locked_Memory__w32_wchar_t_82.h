/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_82.h
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-82.tmpl.h
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * Case0Source:  Allocate memory for sensitive data without using VirtualLock() to lock the buffer into memory
 * Case1Source: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 *    Case0Sink : Authenticate the user using LogonUserW()
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <windows.h>

namespace CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_82
{

class CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_82_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * password) = 0;
};

#ifndef OMITCASE0

class CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_82_case0 : public CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_82_base
{
public:
    void action(wchar_t * password);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_82_case1V1 : public CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_82_base
{
public:
    void action(wchar_t * password);
};

#endif /* OMITCASE1 */

}
