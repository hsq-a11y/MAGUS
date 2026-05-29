/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22b.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile.label.xml
Template File: source-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * Case0Source:  Create a file handle using CreateFile()
 * Sinks:
 *    Case1Sink: Close the file handle before reusing it
 *    Case0Sink : Reassign the file handle before closing it
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
extern int CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22_case0Global;

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22_case0Sink(HANDLE data)
{
    if(CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22_case0Global)
    {
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
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22_case1V21Global;
extern int CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22_case1V22Global;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22_case1V21Sink(HANDLE data)
{
    if(CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22_case1V21Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
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
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22_case1V22Sink(HANDLE data)
{
    if(CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22_case1V22Global)
    {
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
}

#endif /* OMITCASE1 */
