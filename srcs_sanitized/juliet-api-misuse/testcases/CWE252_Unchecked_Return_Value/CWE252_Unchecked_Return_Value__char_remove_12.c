/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__char_remove_12.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-note-12.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: remove
 *    Case1Sink: Check if remove() fails
 *    Case0Sink : Do not check if remove() fails
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
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

void CWE252_Unchecked_Return_Value__char_remove_12_case0()
{
    if(globalReturnsTrueOrFalse())
    {
        /* NOTE: Do not check the return value */
        REMOVE("removemecase0.txt");
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

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses the Case1Sink on both sides of the "if" statement */
static void case11()
{
    if(globalReturnsTrueOrFalse())
    {
        /* ALT: check the return value */
        if (REMOVE("removemecase1.txt") != 0)
        {
            printLine("remove failed!");
        }
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

void CWE252_Unchecked_Return_Value__char_remove_12_case1()
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
    CWE252_Unchecked_Return_Value__char_remove_12_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE252_Unchecked_Return_Value__char_remove_12_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
