/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__wchar_t_rename_14.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-note-14.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: rename
 *    Case1Sink: Check if rename() fails
 *    Case0Sink : Do not check if rename() fails
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define RENAME _wrename
#else
#define RENAME rename
#endif

#define OLD_CASE0_FILE_NAME L"oldcase0filename.txt"
#define OLD_CASE1_FILE_NAME L"oldcase1filename.txt"

#ifndef OMITCASE0

void CWE252_Unchecked_Return_Value__wchar_t_rename_14_case0()
{
    if(globalFive==5)
    {
        /* NOTE: Do not check the return value */
        RENAME(OLD_CASE0_FILE_NAME, L"newcase0filename.txt");
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
        if (RENAME(OLD_CASE1_FILE_NAME, L"newcase1filename.txt") != 0)
        {
            printLine("rename failed!");
        }
    }
}

/* case12() reverses the bodies in the if statement */
static void case12()
{
    if(globalFive==5)
    {
        /* ALT: check the return value */
        if (RENAME(OLD_CASE1_FILE_NAME, L"newcase1filename.txt") != 0)
        {
            printLine("rename failed!");
        }
    }
}

void CWE252_Unchecked_Return_Value__wchar_t_rename_14_case1()
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
    CWE252_Unchecked_Return_Value__wchar_t_rename_14_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE252_Unchecked_Return_Value__wchar_t_rename_14_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
