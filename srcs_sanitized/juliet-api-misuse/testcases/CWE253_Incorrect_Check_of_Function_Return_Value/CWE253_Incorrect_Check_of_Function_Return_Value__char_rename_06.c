/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_06.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-note-06.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: rename
 *    Case1Sink: Correctly check if rename() failed
 *    Case0Sink : Incorrectlycheck if rename() failed
 * Flow Variant: 06 Control flow: if(STATIC_CONST_FIVE==5) and if(STATIC_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define RENAME rename
#else
#define RENAME rename
#endif

#define OLD_CASE0_FILE_NAME "oldcase0filename.txt"
#define OLD_CASE1_FILE_NAME "oldcase1filename.txt"
#define NEW_CASE0_FILE_NAME "newcase0filename.txt"
#define NEW_CASE1_FILE_NAME "newcase1filename.txt"

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int STATIC_CONST_FIVE = 5;

#ifndef OMITCASE0

void CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_06_case0()
{
    if(STATIC_CONST_FIVE==5)
    {
        /* NOTE: rename() might fail, in which case the return value will be non-zero, but
         * we are checking to see if the return value is 0 */
        if (RENAME(OLD_CASE0_FILE_NAME, NEW_CASE0_FILE_NAME) == 0)
        {
            printLine("rename failed!");
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses if(STATIC_CONST_FIVE!=5) instead of if(STATIC_CONST_FIVE==5) */
static void case11()
{
    if(STATIC_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: check for the correct return value */
        if (RENAME(OLD_CASE1_FILE_NAME, NEW_CASE1_FILE_NAME) != 0)
        {
            printLine("rename failed!");
        }
    }
}

/* case12() reverses the bodies in the if statement */
static void case12()
{
    if(STATIC_CONST_FIVE==5)
    {
        /* ALT: check for the correct return value */
        if (RENAME(OLD_CASE1_FILE_NAME, NEW_CASE1_FILE_NAME) != 0)
        {
            printLine("rename failed!");
        }
    }
}

void CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_06_case1()
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
    CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_06_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE253_Incorrect_Check_of_Function_Return_Value__char_rename_06_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
