/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE667_Improper_Locking__basic_05.c
Label Definition File: CWE667_Improper_Locking__basic.label.xml
Template File: point-note-05.tmpl.c
*/
/*
 * @description
 * CWE: 667 Improper Locking
 * Sinks:
 *    Case1Sink: Acquire a lock before releasing it
 *    Case0Sink : Release the lock before acquiring it
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

#include "std_thread.h"

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

#ifndef OMITCASE0

void CWE667_Improper_Locking__basic_05_case0()
{
    if(staticTrue)
    {
        {
            static stdThreadLock case0Lock = NULL;
            printLine("Creating lock...");
            if (!stdThreadLockCreate(&case0Lock))
            {
                printLine("Could not create lock");
                exit(1);
            }
            printLine("Acquiring lock...");
            stdThreadLockAcquire(case0Lock);
            /* NOTE: Do not release the lock */
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
            static stdThreadLock case1Lock = NULL;
            printLine("Creating lock...");
            if (!stdThreadLockCreate(&case1Lock))
            {
                printLine("Could not create lock");
                exit(1);
            }
            printLine("Acquiring lock...");
            stdThreadLockAcquire(case1Lock);
            /* ALT: Release and destroy the lock */
            printLine("Releasing lock...");
            stdThreadLockRelease(case1Lock);
            printLine("Destroying lock...");
            stdThreadLockDestroy(case1Lock);
        }
    }
}

/* case12() reverses the bodies in the if statement */
static void case12()
{
    if(staticTrue)
    {
        {
            static stdThreadLock case1Lock = NULL;
            printLine("Creating lock...");
            if (!stdThreadLockCreate(&case1Lock))
            {
                printLine("Could not create lock");
                exit(1);
            }
            printLine("Acquiring lock...");
            stdThreadLockAcquire(case1Lock);
            /* ALT: Release and destroy the lock */
            printLine("Releasing lock...");
            stdThreadLockRelease(case1Lock);
            printLine("Destroying lock...");
            stdThreadLockDestroy(case1Lock);
        }
    }
}

void CWE667_Improper_Locking__basic_05_case1()
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
    CWE667_Improper_Locking__basic_05_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE667_Improper_Locking__basic_05_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
