/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE391_Unchecked_Error_Condition__strtol_11.c
Label Definition File: CWE391_Unchecked_Error_Condition.label.xml
Template File: point-note-11.tmpl.c
*/
/*
 * @description
 * CWE: 391 Unchecked Error Condition
 * Sinks: strtol
 *    Case1Sink: Perform error checks and handling
 *    Case0Sink : Do not check if strtol() failed
 * Flow Variant: 11 Control flow: if(globalReturnsTrue()) and if(globalReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <errno.h>

#ifndef OMITCASE0

void CWE391_Unchecked_Error_Condition__strtol_11_case0()
{
    if(globalReturnsTrue())
    {
        {
            long longNumber;
            longNumber = strtol("0xfffffffff", NULL, 0);
            /* NOTE: Do not check to see if strtol() failed */
            printf("%li\n", longNumber);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses if(globalReturnsFalse()) instead of if(globalReturnsTrue()) */
static void case11()
{
    if(globalReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
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
    }
}

/* case12() reverses the bodies in the if statement */
static void case12()
{
    if(globalReturnsTrue())
    {
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
    }
}

void CWE391_Unchecked_Error_Condition__strtol_11_case1()
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
    CWE391_Unchecked_Error_Condition__strtol_11_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE391_Unchecked_Error_Condition__strtol_11_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
