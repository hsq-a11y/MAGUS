/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE391_Unchecked_Error_Condition__strtol_15.c
Label Definition File: CWE391_Unchecked_Error_Condition.label.xml
Template File: point-note-15.tmpl.c
*/
/*
 * @description
 * CWE: 391 Unchecked Error Condition
 * Sinks: strtol
 *    Case1Sink: Perform error checks and handling
 *    Case0Sink : Do not check if strtol() failed
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <errno.h>

#ifndef OMITCASE0

void CWE391_Unchecked_Error_Condition__strtol_15_case0()
{
    switch(6)
    {
    case 6:
    {
        long longNumber;
        longNumber = strtol("0xfffffffff", NULL, 0);
        /* NOTE: Do not check to see if strtol() failed */
        printf("%li\n", longNumber);
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
        long longNumber;
        errno = 0; /* set errno to zero before calling strtol(), which can change its value */
        longNumber = strtol("0xfffffffff", NULL, 0);
        /* ALT: Check errno to see if strtol() failed */
        if (errno == ERANGE)
        {
            printLine("strtol() failed");
            exit(1);
        }
        printf("%li\n", longNumber);
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
        long longNumber;
        errno = 0; /* set errno to zero before calling strtol(), which can change its value */
        longNumber = strtol("0xfffffffff", NULL, 0);
        /* ALT: Check errno to see if strtol() failed */
        if (errno == ERANGE)
        {
            printLine("strtol() failed");
            exit(1);
        }
        printf("%li\n", longNumber);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE391_Unchecked_Error_Condition__strtol_15_case1()
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
    CWE391_Unchecked_Error_Condition__strtol_15_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE391_Unchecked_Error_Condition__strtol_15_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
