/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE832_Unlock_of_Resource_That_is_Not_Locked__basic_09.c
Label Definition File: CWE832_Unlock_of_Resource_That_is_Not_Locked__basic.label.xml
Template File: point-note-09.tmpl.c
*/
/*
 * @description
 * CWE: 832 Unlock Of Resource That Is Not Locked
 * Sinks:
 *    Case1Sink: Acquire a lock before releasing it
 *    Case0Sink : Release the lock before acquiring it
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include "std_thread.h"

#ifndef OMITCASE0

void CWE832_Unlock_of_Resource_That_is_Not_Locked__basic_09_case0()
{
    if(GLOBAL_CONST_TRUE)
    {
        {
            static stdThreadLock case0Lock = NULL;
            printLine("Creating lock...");
            if (!stdThreadLockCreate(&case0Lock))
            {
                printLine("Could not create lock");
                exit(1);
            }
            /* NOTE: Release the lock before acquiring it */
            printLine("Releasing lock...");
            stdThreadLockRelease(case0Lock);
            printLine("Destroying lock...");
            stdThreadLockDestroy(case0Lock);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses if(GLOBAL_CONST_FALSE) instead of if(GLOBAL_CONST_TRUE) */
static void case11()
{
    if(GLOBAL_CONST_FALSE)
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
            /* ALT: Acquire the lock before attempting to release it */
            printLine("Acquiring lock...");
            stdThreadLockAcquire(case1Lock);
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
    if(GLOBAL_CONST_TRUE)
    {
        {
            static stdThreadLock case1Lock = NULL;
            printLine("Creating lock...");
            if (!stdThreadLockCreate(&case1Lock))
            {
                printLine("Could not create lock");
                exit(1);
            }
            /* ALT: Acquire the lock before attempting to release it */
            printLine("Acquiring lock...");
            stdThreadLockAcquire(case1Lock);
            printLine("Releasing lock...");
            stdThreadLockRelease(case1Lock);
            printLine("Destroying lock...");
            stdThreadLockDestroy(case1Lock);
        }
    }
}

void CWE832_Unlock_of_Resource_That_is_Not_Locked__basic_09_case1()
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
    CWE832_Unlock_of_Resource_That_is_Not_Locked__basic_09_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE832_Unlock_of_Resource_That_is_Not_Locked__basic_09_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
