/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE242_Use_of_Inherently_Dangerous_Function__basic_01.c
Label Definition File: CWE242_Use_of_Inherently_Dangerous_Function__basic.label.xml
Template File: point-note-01.tmpl.c
*/
/*
 * @description
 * CWE: 242 Use of Inherently Dangerous Function
 * Sinks:
 *    Case1Sink: Use fgets() for bounded user input
 *    Case0Sink : Use gets() for user input
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#define DEST_SIZE 10

#ifndef OMITCASE0

void CWE242_Use_of_Inherently_Dangerous_Function__basic_01_case0()
{
    {
        char dest[DEST_SIZE];
        char *result;
        /* NOTE: gets is inherently dangerous and cannot be used safely. */
        /* INCIDENTAL CWE120 Buffer Overflow since gets is inherently dangerous and is
         * an unbounded copy. */
        result = gets(dest);
        /* Verify return value */
        if (result == NULL)
        {
            /* error condition */
            printLine("Error Condition: alter control flow to indicate action taken");
            exit(1);
        }
        dest[DEST_SIZE-1] = '\0';
        printLine(dest);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

static void case11()
{
    {
        char dest[DEST_SIZE];
        char *result;
        /* ALT: use fgets for bounded read from stdin*/
        result = fgets(dest, DEST_SIZE, stdin);
        /* Verify return value */
        if (result == NULL)
        {
            /* error condition */
            printLine("Error Condition: alter control flow to indicate action taken");
            exit(1);
        }
        dest[DEST_SIZE-1] = '\0';
        printLine(dest);
    }
}

void CWE242_Use_of_Inherently_Dangerous_Function__basic_01_case1()
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
    CWE242_Use_of_Inherently_Dangerous_Function__basic_01_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE242_Use_of_Inherently_Dangerous_Function__basic_01_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
