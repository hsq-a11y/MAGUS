/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22a.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource__w32CreateFile.label.xml
Template File: sources-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source:  Open and close a file using CreateFile() and CloseHandle()
 * Case1Source: Open a file using CreateFile()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
int CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case0Global = 0;

void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case0Sink(HANDLE data);

void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case0()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    data = CreateFile("Case0Source_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    /* NOTE: Close the file in the source */
    CloseHandle(data);
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case0Global = 1; /* true */
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
int CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V21Global = 0;
int CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V22Global = 0;
int CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V1Global = 0;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V21Sink(HANDLE data);

static void case1V21()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    data = CreateFile("Case0Source_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    /* NOTE: Close the file in the source */
    CloseHandle(data);
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V21Global = 0; /* false */
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V21Sink(data);
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V22Sink(HANDLE data);

static void case1V22()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    data = CreateFile("Case0Source_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    /* NOTE: Close the file in the source */
    CloseHandle(data);
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V22Global = 1; /* true */
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V22Sink(data);
}

/* case1V1() - use case1source and case0sink */
void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V1Sink(HANDLE data);

static void case1V1()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    /* ALT: Open, but do not close the file in the source */
    data = CreateFile("Case1Source_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V1Global = 1; /* true */
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V1Sink(data);
}

void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1()
{
    case1V21();
    case1V22();
    case1V1();
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
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
