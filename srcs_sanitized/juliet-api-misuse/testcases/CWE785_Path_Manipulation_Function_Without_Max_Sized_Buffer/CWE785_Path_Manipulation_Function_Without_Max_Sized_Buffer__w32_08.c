/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32_08.c
Label Definition File: CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32.label.xml
Template File: point-note-08.tmpl.c
*/
/*
 * @description
 * CWE: 785 Path Manipulation Function Without Max Sized Buffer
 * Sinks:
 *    Case1Sink: Ensure the path parameter is MAX_PATH
 *    Case0Sink : Use PathAppend() with a buffer that is less than MAX_PATH
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <shlwapi.h>

#pragma comment(lib, "shlwapi")

#define CASE0_PATH_SIZE (MAX_PATH / 2) /* maintenance note: must be < MAX_PATH in order for 'case0' to be 'case0' */

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

#ifndef OMITCASE0

void CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32_08_case0()
{
    if(staticReturnsTrue())
    {
        {
            char path[CASE0_PATH_SIZE];
            DWORD length;
            length = GetCurrentDirectoryA(CASE0_PATH_SIZE, path);
            if (length == 0 || length >= CASE0_PATH_SIZE) /* failure conditions for this API call */
            {
                exit(1);
            }
            /* NOTE: PathAppend assumes the 'path' parameter is MAX_PATH */
            /* INCIDENTAL: CWE 121 stack based buffer overflow, which is intrinsic to
             * this example identified on the CWE webpage */
            if (!PathAppendA(path, "AAAAAAAAAAAA"))
            {
                exit(1);
            }
            printSizeTLine(strlen(path));
            printIntLine(CASE0_PATH_SIZE);
            printLine(path);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses if(staticReturnsFalse()) instead of if(staticReturnsTrue()) */
static void case11()
{
    if(staticReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            /* ALT: ensure MAX_PATH allocated in 'path' */
            char path[MAX_PATH];
            DWORD length;
            length = GetCurrentDirectoryA(MAX_PATH, path);
            if (length == 0 || length >= MAX_PATH)
            {
                exit(1); /* failure conditions for this API call */
            }
            if (!PathAppendA(path, "AAAAAAAAAAAA"))
            {
                exit(1);
            }
            printLine(path);
        }
    }
}

/* case12() reverses the bodies in the if statement */
static void case12()
{
    if(staticReturnsTrue())
    {
        {
            /* ALT: ensure MAX_PATH allocated in 'path' */
            char path[MAX_PATH];
            DWORD length;
            length = GetCurrentDirectoryA(MAX_PATH, path);
            if (length == 0 || length >= MAX_PATH)
            {
                exit(1); /* failure conditions for this API call */
            }
            if (!PathAppendA(path, "AAAAAAAAAAAA"))
            {
                exit(1);
            }
            printLine(path);
        }
    }
}

void CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32_08_case1()
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
    CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32_08_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32_08_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
