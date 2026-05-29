/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__w32CreateFile_09.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource__w32CreateFile.label.xml
Template File: sources-sinks-09.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source:  Open and close a file using CreateFile() and CloseHandle()
 * Case1Source: Open a file using CreateFile()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITCASE0

void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_09_case0()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    if(GLOBAL_CONST_TRUE)
    {
        data = CreateFile("Case0Source_w32CreateFile.txt",
                          (GENERIC_WRITE|GENERIC_READ),
                          0,
                          NULL,
                          OPEN_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
        /* NOTE: Close the file in the source */
        CloseHandle(data);
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* NOTE: Close the file in the sink (it may have been closed in the Source) */
        CloseHandle(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V21() - use case0source and case1sink by changing the second GLOBAL_CONST_TRUE to GLOBAL_CONST_FALSE */
static void case1V21()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    if(GLOBAL_CONST_TRUE)
    {
        data = CreateFile("Case0Source_w32CreateFile.txt",
                          (GENERIC_WRITE|GENERIC_READ),
                          0,
                          NULL,
                          OPEN_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
        /* NOTE: Close the file in the source */
        CloseHandle(data);
    }
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* Do nothing */
        /* ALT: Don't close the file in the sink */
        ; /* empty statement needed for some flow variants */
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the second if */
static void case1V22()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    if(GLOBAL_CONST_TRUE)
    {
        data = CreateFile("Case0Source_w32CreateFile.txt",
                          (GENERIC_WRITE|GENERIC_READ),
                          0,
                          NULL,
                          OPEN_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
        /* NOTE: Close the file in the source */
        CloseHandle(data);
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* Do nothing */
        /* ALT: Don't close the file in the sink */
        ; /* empty statement needed for some flow variants */
    }
}

/* case1V11() - use case1source and case0sink by changing the first GLOBAL_CONST_TRUE to GLOBAL_CONST_FALSE */
static void case1V11()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Open, but do not close the file in the source */
        data = CreateFile("Case1Source_w32CreateFile.txt",
                          (GENERIC_WRITE|GENERIC_READ),
                          0,
                          NULL,
                          OPEN_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* NOTE: Close the file in the sink (it may have been closed in the Source) */
        CloseHandle(data);
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the first if */
static void case1V12()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    if(GLOBAL_CONST_TRUE)
    {
        /* ALT: Open, but do not close the file in the source */
        data = CreateFile("Case1Source_w32CreateFile.txt",
                          (GENERIC_WRITE|GENERIC_READ),
                          0,
                          NULL,
                          OPEN_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* NOTE: Close the file in the sink (it may have been closed in the Source) */
        CloseHandle(data);
    }
}

void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_09_case1()
{
    case1V21();
    case1V22();
    case1V11();
    case1V12();
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
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_09_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_09_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
