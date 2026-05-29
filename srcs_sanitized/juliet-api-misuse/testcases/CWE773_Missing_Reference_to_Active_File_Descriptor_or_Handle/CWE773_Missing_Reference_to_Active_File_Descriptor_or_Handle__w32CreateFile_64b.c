/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_64b.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile.label.xml
Template File: source-sinks-64b.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * Case0Source:  Create a file handle using CreateFile()
 * Sinks:
 *    Case1Sink: Close the file handle before reusing it
 *    Case0Sink : Reassign the file handle before closing it
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITCASE0

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_64b_case0Sink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    HANDLE * dataPtr = (HANDLE *)dataVoidPtr;
    /* dereference dataPtr into data */
    HANDLE data = (*dataPtr);
    /* NOTE: Point data to another file handle without closing the handle from the source */
    data = CreateFile("Case0Sink_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    /* avoid incidental for not closing the file handle */
    if (data != INVALID_HANDLE_VALUE)
    {
        CloseHandle(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_64b_case1V2Sink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    HANDLE * dataPtr = (HANDLE *)dataVoidPtr;
    /* dereference dataPtr into data */
    HANDLE data = (*dataPtr);
    /* ALT: Close the file from the source before pointing data to a new file handle */
    if (data != INVALID_HANDLE_VALUE)
    {
        CloseHandle(data);
    }
    data = CreateFile("Case1Sink_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    /* avoid incidental for not closing the file handle */
    if (data != INVALID_HANDLE_VALUE)
    {
        CloseHandle(data);
    }
}

#endif /* OMITCASE1 */
