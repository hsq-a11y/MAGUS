/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__wchar_t_remove_10.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-note-10.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: remove
 *    Case1Sink: Check if remove() fails
 *    Case0Sink : Do not check if remove() fails
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define REMOVE _wremove
#else
#define REMOVE remove
#endif

#ifndef OMITCASE0

void CWE252_Unchecked_Return_Value__wchar_t_remove_10_case0()
{
    if(globalTrue)
    {
        /* NOTE: Do not check the return value */
        REMOVE(L"removemecase0.txt");
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses if(globalFalse) instead of if(globalTrue) */
static void case11()
{
    if(globalFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: check the return value */
        if (REMOVE(L"removemecase1.txt") != 0)
        {
            printLine("remove failed!");
        }
    }
}

/* case12() reverses the bodies in the if statement */
static void case12()
{
    if(globalTrue)
    {
        /* ALT: check the return value */
        if (REMOVE(L"removemecase1.txt") != 0)
        {
            printLine("remove failed!");
        }
    }
}

void CWE252_Unchecked_Return_Value__wchar_t_remove_10_case1()
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
    CWE252_Unchecked_Return_Value__wchar_t_remove_10_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE252_Unchecked_Return_Value__wchar_t_remove_10_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
