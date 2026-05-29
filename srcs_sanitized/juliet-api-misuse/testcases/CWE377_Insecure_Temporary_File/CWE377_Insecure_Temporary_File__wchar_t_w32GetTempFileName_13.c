/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE377_Insecure_Temporary_File__wchar_t_w32GetTempFileName_13.c
Label Definition File: CWE377_Insecure_Temporary_File.label.xml
Template File: point-note-13.tmpl.c
*/
/*
 * @description
 * CWE: 377 Insecure Temporary File
 * Sinks: w32GetTempFileName
 *    Case1Sink: Create and open a temporary file, created with GetTempFileNameW(), more securely
 *    Case0Sink : Create and open a temporary file, created with GetTempFileNameW(), insecurely
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifndef _WIN32
#include <unistd.h>
#endif

#include <windows.h>

#define OPEN _wopen
#define CLOSE _close
#define O_RDWR _O_RDWR
#define O_CREAT _O_CREAT
#define O_EXCL _O_EXCL
#define S_IREAD _S_IREAD
#define S_IWRITE _S_IWRITE

#ifndef OMITCASE0

void CWE377_Insecure_Temporary_File__wchar_t_w32GetTempFileName_13_case0()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        {
            wchar_t filename[MAX_PATH] = L"";
            int fileDesc;
            /* NOTE: Passing 0 in for uUnique tells GetTempFileName to create and then close the file,
            * leading to an inescapable race condition when we try to open it again. */
            if (GetTempFileNameW(L".", L"case0", 0, filename) == 0)
            {
                exit(1);
            }
            printWLine(filename);
            /* NOTE: Open a temporary file using open() and flags that do not prevent a race condition */
            fileDesc = OPEN(filename, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
            if (fileDesc != -1)
            {
                printLine("Temporary file was opened...now closing file");
                CLOSE(fileDesc);
            }
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses if(GLOBAL_CONST_FIVE!=5) instead of if(GLOBAL_CONST_FIVE==5) */
static void case11()
{
    if(GLOBAL_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            wchar_t filename[MAX_PATH] = L"";
            int fileDesc;
            /* ALT: Passing a non-zero value in for uUnique prevents GetTempFileName from creating
             * and then closing the file, at the cost of no longer guaranteeing the name is unique. */
            /* INCIDENTAL CWE338 Weak PRNG - use of rand() as a PRNG */
            if (GetTempFileNameW(L".", L"case1", rand() + 1, filename) == 0)
            {
                exit(1);
            }
            printWLine(filename);
            /* ALT: Open a temporary file using open() and the O_CREAT and O_EXCL flags
            * NOTE: This is not a perfect solution, but it is the base case scenario */
            fileDesc = OPEN(filename, O_RDWR|O_CREAT|O_EXCL, S_IREAD|S_IWRITE);
            if (fileDesc != -1)
            {
                printLine("Temporary file was opened...now closing file");
                CLOSE(fileDesc);
            }
        }
    }
}

/* case12() reverses the bodies in the if statement */
static void case12()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        {
            wchar_t filename[MAX_PATH] = L"";
            int fileDesc;
            /* ALT: Passing a non-zero value in for uUnique prevents GetTempFileName from creating
             * and then closing the file, at the cost of no longer guaranteeing the name is unique. */
            /* INCIDENTAL CWE338 Weak PRNG - use of rand() as a PRNG */
            if (GetTempFileNameW(L".", L"case1", rand() + 1, filename) == 0)
            {
                exit(1);
            }
            printWLine(filename);
            /* ALT: Open a temporary file using open() and the O_CREAT and O_EXCL flags
            * NOTE: This is not a perfect solution, but it is the base case scenario */
            fileDesc = OPEN(filename, O_RDWR|O_CREAT|O_EXCL, S_IREAD|S_IWRITE);
            if (fileDesc != -1)
            {
                printLine("Temporary file was opened...now closing file");
                CLOSE(fileDesc);
            }
        }
    }
}

void CWE377_Insecure_Temporary_File__wchar_t_w32GetTempFileName_13_case1()
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
    CWE377_Insecure_Temporary_File__wchar_t_w32GetTempFileName_13_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE377_Insecure_Temporary_File__wchar_t_w32GetTempFileName_13_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
