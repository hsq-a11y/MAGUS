/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_char_RegOpenKeyEx_16.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-note-16.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: RegOpenKeyEx
 *    Case1Sink: Open a registry key using RegOpenKeyExA() and HKEY_CURRENT_USER
 *    Case0Sink : Open a registry key using RegOpenKeyExA() and HKEY_LOCAL_MACHINE
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "advapi32" )

#ifndef OMITCASE0

void CWE272_Least_Privilege_Violation__w32_char_RegOpenKeyEx_16_case0()
{
    while(1)
    {
        {
            char * keyName = "TEST\\TestKey";
            HKEY hKey;
            /* NOTE: Call RegOpenKeyExA() with HKEY_LOCAL_MACHINE violating the least privilege principal */
            if (RegOpenKeyExA(
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
        break;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses the Case1SinkBody in the while loop */
static void case11()
{
    while(1)
    {
        {
            char * keyName = "TEST\\TestKey";
            HKEY hKey;
            /* ALT: Call RegOpenKeyExA() with HKEY_CURRENT_USER */
            if (RegOpenKeyExA(
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
        break;
    }
}

void CWE272_Least_Privilege_Violation__w32_char_RegOpenKeyEx_16_case1()
{
    case11();
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
    CWE272_Least_Privilege_Violation__w32_char_RegOpenKeyEx_16_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE272_Least_Privilege_Violation__w32_char_RegOpenKeyEx_16_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
