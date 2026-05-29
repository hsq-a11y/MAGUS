/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__char_remove_14.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-note-14.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: remove
 *    Case1Sink: Check if remove() fails
 *    Case0Sink : Do not check if remove() fails
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define REMOVE remove
#else
#define REMOVE remove
#endif

#ifndef OMITCASE0

void CWE252_Unchecked_Return_Value__char_remove_14_case0()
{
    if(globalFive==5)
    {
        /* NOTE: Do not check the return value */
        REMOVE("removemecase0.txt");
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses if(globalFive!=5) instead of if(globalFive==5) */
static void case11()
{
    if(globalFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: check the return value */
        if (REMOVE("removemecase1.txt") != 0)
        {
            printLine("remove failed!");
        }
    }
}

/* case12() reverses the bodies in the if statement */
static void case12()
{
    if(globalFive==5)
    {
        /* ALT: check the return value */
        if (REMOVE("removemecase1.txt") != 0)
        {
            printLine("remove failed!");
        }
    }
}

void CWE252_Unchecked_Return_Value__char_remove_14_case1()
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
    CWE252_Unchecked_Return_Value__char_remove_14_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE252_Unchecked_Return_Value__char_remove_14_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
