/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_16.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value__w32.label.xml
Template File: point-note-16.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: ImpersonateSelf
 *    Case1Sink: Correctly check if ImpersonateSelf() fails
 *    Case0Sink : Incorrectly check if ImpersonateSelf() fails
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment(lib, "advapi32")

#ifndef OMITCASE0

void CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_16_case0()
{
    while(1)
    {
        /* NOTE: ImpersonateSelf() could fail and would return 0 (false), but we are checking to see
         * if the return value is greater than zero (true) */
        if (ImpersonateSelf(SecurityImpersonation) > 0)
        {
            exit(1);
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
        /* ALT: check for the correct return value */
        if (!ImpersonateSelf(SecurityImpersonation))
        {
            exit(1);
        }
        break;
    }
}

void CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_16_case1()
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
    CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_16_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_16_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
