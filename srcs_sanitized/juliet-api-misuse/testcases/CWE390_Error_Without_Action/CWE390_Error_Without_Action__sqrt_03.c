/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__sqrt_03.c
Label Definition File: CWE390_Error_Without_Action.label.xml
Template File: point-note-03.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: sqrt
 *    Case1Sink: Check to see if sqrt() failed and handle errors properly
 *    Case0Sink : Check to see if sqrt() failed, but fail to handle errors
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#include <math.h>
#include <errno.h>

#ifndef OMITCASE0

void CWE390_Error_Without_Action__sqrt_03_case0()
{
    if(5==5)
    {
        {
            double doubleNumber;
            errno = 0; /* set errno to zero before calling sqrt(), which can change its value */
            doubleNumber = (double)sqrt((double)-1);
            /* NOTE: Check errno to see if sqrt() failed, but do not handle errors */
            if (errno == EDOM)
            {
                /* do nothing */
            }
            printDoubleLine(doubleNumber);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses if(5!=5) instead of if(5==5) */
static void case11()
{
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            double doubleNumber;
            errno = 0; /* set errno to zero before calling sqrt(), which can change its value */
            doubleNumber = (double)sqrt((double)-1);
            /* ALT: Check errno to see if sqrt() failed and handle errors properly */
            if (errno == EDOM)
            {
                printLine("sqrt() failed");
                exit(1);
            }
            printDoubleLine(doubleNumber);
        }
    }
}

/* case12() reverses the bodies in the if statement */
static void case12()
{
    if(5==5)
    {
        {
            double doubleNumber;
            errno = 0; /* set errno to zero before calling sqrt(), which can change its value */
            doubleNumber = (double)sqrt((double)-1);
            /* ALT: Check errno to see if sqrt() failed and handle errors properly */
            if (errno == EDOM)
            {
                printLine("sqrt() failed");
                exit(1);
            }
            printDoubleLine(doubleNumber);
        }
    }
}

void CWE390_Error_Without_Action__sqrt_03_case1()
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
    CWE390_Error_Without_Action__sqrt_03_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE390_Error_Without_Action__sqrt_03_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
