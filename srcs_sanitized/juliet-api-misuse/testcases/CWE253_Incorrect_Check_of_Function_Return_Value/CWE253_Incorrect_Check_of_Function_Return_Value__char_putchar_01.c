/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_01.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-note-01.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: putchar
 *    Case1Sink: Correctly check if putchar() failed
 *    Case0Sink : Incorrectly check if putchar() failed
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITCASE0

void CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_01_case0()
{
    /* NOTE: putchar() might fail, in which case the return value will be EOF (-1), but
     * we are checking to see if the return value is 0 */
    if (putchar((int)'A') == 0)
    {
        printLine("putchar failed!");
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

static void case11()
{
    /* ALT: check for the correct return value */
    if (putchar((int)'A') == EOF)
    {
        printLine("putchar failed!");
    }
}

void CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_01_case1()
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
    CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_01_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE253_Incorrect_Check_of_Function_Return_Value__char_putchar_01_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
