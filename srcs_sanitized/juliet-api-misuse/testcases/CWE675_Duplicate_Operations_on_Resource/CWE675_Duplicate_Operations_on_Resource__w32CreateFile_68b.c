/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__w32CreateFile_68b.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource__w32CreateFile.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source:  Open and close a file using CreateFile() and CloseHandle()
 * Case1Source: Open a file using CreateFile()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

extern HANDLE CWE675_Duplicate_Operations_on_Resource__w32CreateFile_68_case0Data;
extern HANDLE CWE675_Duplicate_Operations_on_Resource__w32CreateFile_68_case1V1Data;
extern HANDLE CWE675_Duplicate_Operations_on_Resource__w32CreateFile_68_case1V2Data;

#ifndef OMITCASE0

void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_68b_case0Sink()
{
    HANDLE data = CWE675_Duplicate_Operations_on_Resource__w32CreateFile_68_case0Data;
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    CloseHandle(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_68b_case1V1Sink()
{
    HANDLE data = CWE675_Duplicate_Operations_on_Resource__w32CreateFile_68_case1V1Data;
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    CloseHandle(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_68b_case1V2Sink()
{
    HANDLE data = CWE675_Duplicate_Operations_on_Resource__w32CreateFile_68_case1V2Data;
    /* Do nothing */
    /* ALT: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE1 */
