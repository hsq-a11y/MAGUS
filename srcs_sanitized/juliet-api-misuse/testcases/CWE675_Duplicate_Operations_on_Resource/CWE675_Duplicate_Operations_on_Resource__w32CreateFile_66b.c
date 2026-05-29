/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__w32CreateFile_66b.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource__w32CreateFile.label.xml
Template File: sources-sinks-66b.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source:  Open and close a file using CreateFile() and CloseHandle()
 * Case1Source: Open a file using CreateFile()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITCASE0

void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_66b_case0Sink(HANDLE dataArray[])
{
    /* copy data out of dataArray */
    HANDLE data = dataArray[2];
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    CloseHandle(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_66b_case1V1Sink(HANDLE dataArray[])
{
    HANDLE data = dataArray[2];
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    CloseHandle(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_66b_case1V2Sink(HANDLE dataArray[])
{
    HANDLE data = dataArray[2];
    /* Do nothing */
    /* ALT: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE1 */
