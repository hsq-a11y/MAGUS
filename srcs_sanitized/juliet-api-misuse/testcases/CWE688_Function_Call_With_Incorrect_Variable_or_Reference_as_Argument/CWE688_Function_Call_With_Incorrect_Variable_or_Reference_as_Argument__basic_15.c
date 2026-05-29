/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument__basic_15.c
Label Definition File: CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument__basic.label.xml
Template File: point-note-15.tmpl.c
*/
/*
 * @description
 * CWE: 688 Function Call With Incorrect Variable or Reference as Argument
 * Sinks:
 *    Case1Sink: Use the correct format to print a string
 *    Case0Sink : Use a string format to print an int
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#define DEST_SIZE 100

#ifndef OMITCASE0

void CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument__basic_15_case0()
{
    switch(6)
    {
    case 6:
    {
        char dest[DEST_SIZE];
        int intFive = 5;
        /* NOTE: int argument passed, expecting string argument */
        sprintf(dest, "%s", intFive);
        printLine(dest);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() changes the switch to switch(5) */
static void case11()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    default:
    {
        char dest[DEST_SIZE];
        int intFive = 5;
        /* ALT: use the correct format string */
        sprintf(dest, "%d", intFive);
        printLine(dest);
    }
    break;
    }
}

/* case12() reverses the blocks in the switch */
static void case12()
{
    switch(6)
    {
    case 6:
    {
        char dest[DEST_SIZE];
        int intFive = 5;
        /* ALT: use the correct format string */
        sprintf(dest, "%d", intFive);
        printLine(dest);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument__basic_15_case1()
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
    CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument__basic_15_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument__basic_15_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
