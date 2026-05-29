/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_83.h
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * Case0Source:  Allocate memory for sensitive data without using VirtualLock() to lock the buffer into memory
 * Case1Source: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * Sinks:
 *    Case0Sink : Authenticate the user using LogonUserW()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <windows.h>

namespace CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_83
{

#ifndef OMITCASE0

class CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_83_case0
{
public:
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_83_case0(wchar_t * passwordCopy);
    ~CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_83_case0();

private:
    wchar_t * password;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_83_case1V1
{
public:
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_83_case1V1(wchar_t * passwordCopy);
    ~CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_83_case1V1();

private:
    wchar_t * password;
};

#endif /* OMITCASE1 */

}
