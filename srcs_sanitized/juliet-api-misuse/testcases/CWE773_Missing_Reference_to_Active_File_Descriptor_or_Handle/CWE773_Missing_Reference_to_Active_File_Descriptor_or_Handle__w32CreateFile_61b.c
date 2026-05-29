/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61b.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile.label.xml
Template File: source-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * Case0Source:  Create a file handle using CreateFile()
 * Sinks:
 *    Case1Sink: Close the file handle before reusing it
 *    Case0Sink : Reassign the file handle before closing it
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITCASE0

HANDLE CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61b_case0Source(HANDLE data)
{
    /* NOTE: Create a file handle using CreateFile() that may not be closed properly */
    data = CreateFile("Case0Source_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() uses the Case0Source with the Case1Sink */
HANDLE CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61b_case1V2Source(HANDLE data)
{
    /* NOTE: Create a file handle using CreateFile() that may not be closed properly */
    data = CreateFile("Case0Source_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    return data;
}

#endif /* OMITCASE1 */
