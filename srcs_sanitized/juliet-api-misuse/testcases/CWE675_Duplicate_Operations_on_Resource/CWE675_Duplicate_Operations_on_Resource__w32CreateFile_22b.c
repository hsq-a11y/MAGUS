/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22b.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource__w32CreateFile.label.xml
Template File: sources-sinks-22b.tmpl.c
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
extern int CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case0Global;

void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case0Sink(HANDLE data)
{
    if(CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case0Global)
    {
        /* NOTE: Close the file in the sink (it may have been closed in the Source) */
        CloseHandle(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V21Global;
extern int CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V22Global;
extern int CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V1Global;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V21Sink(HANDLE data)
{
    if(CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V21Global)
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

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V22Sink(HANDLE data)
{
    if(CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V22Global)
    {
        /* Do nothing */
        /* ALT: Don't close the file in the sink */
        ; /* empty statement needed for some flow variants */
    }
}

/* case1V1() - use case1source and case0sink */
void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V1Sink(HANDLE data)
{
    if(CWE675_Duplicate_Operations_on_Resource__w32CreateFile_22_case1V1Global)
    {
        /* NOTE: Close the file in the sink (it may have been closed in the Source) */
        CloseHandle(data);
    }
}

#endif /* OMITCASE1 */
