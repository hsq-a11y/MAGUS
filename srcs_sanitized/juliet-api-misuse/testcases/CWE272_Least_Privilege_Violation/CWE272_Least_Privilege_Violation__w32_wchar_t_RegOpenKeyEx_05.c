/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_wchar_t_RegOpenKeyEx_05.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-note-05.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: RegOpenKeyEx
 *    Case1Sink: Open a registry key using RegOpenKeyExW() and HKEY_CURRENT_USER
 *    Case0Sink : Open a registry key using RegOpenKeyExW() and HKEY_LOCAL_MACHINE
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "advapi32" )

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

#ifndef OMITCASE0

void CWE272_Least_Privilege_Violation__w32_wchar_t_RegOpenKeyEx_05_case0()
{
    if(staticTrue)
    {
        {
            wchar_t * keyName = L"TEST\\TestKey";
            HKEY hKey;
            /* NOTE: Call RegOpenKeyExW() with HKEY_LOCAL_MACHINE violating the least privilege principal */
            if (RegOpenKeyExW(
                        HKEY_LOCAL_MACHINE,
                        keyName,
                        0,
                        KEY_WRITE,
                        &hKey) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be opened");
            }
            else
            {
                printLine("Registry key opened successfully");
                RegCloseKey(hKey);
            }
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses if(staticFalse) instead of if(staticTrue) */
static void case11()
{
    if(staticFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            wchar_t * keyName = L"TEST\\TestKey";
            HKEY hKey;
            /* ALT: Call RegOpenKeyExW() with HKEY_CURRENT_USER */
            if (RegOpenKeyExW(
                        HKEY_CURRENT_USER,
                        keyName,
                        0,
                        KEY_WRITE,
                        &hKey) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be opened");
            }
            else
            {
                printLine("Registry key opened successfully");
                RegCloseKey(hKey);
            }
        }
    }
}

/* case12() reverses the bodies in the if statement */
static void case12()
{
    if(staticTrue)
    {
        {
            wchar_t * keyName = L"TEST\\TestKey";
            HKEY hKey;
            /* ALT: Call RegOpenKeyExW() with HKEY_CURRENT_USER */
            if (RegOpenKeyExW(
                        HKEY_CURRENT_USER,
                        keyName,
                        0,
                        KEY_WRITE,
                        &hKey) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be opened");
            }
            else
            {
                printLine("Registry key opened successfully");
                RegCloseKey(hKey);
            }
        }
    }
}

void CWE272_Least_Privilege_Violation__w32_wchar_t_RegOpenKeyEx_05_case1()
{
    case11();
    case12();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE272_Least_Privilege_Violation__w32_wchar_t_RegOpenKeyEx_05_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE272_Least_Privilege_Violation__w32_wchar_t_RegOpenKeyEx_05_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
