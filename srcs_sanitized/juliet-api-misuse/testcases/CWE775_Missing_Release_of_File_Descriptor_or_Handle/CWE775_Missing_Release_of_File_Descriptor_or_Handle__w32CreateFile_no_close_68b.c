/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68b.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using CreateFile()
 * Sinks:
 *    Case1Sink: Close the file using CloseHandle()
 *    Case0Sink : Do not close file
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

extern HANDLE CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68_case0DataForCase0Sink;

extern HANDLE CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68_case0DataForCase1Sink;

#ifndef OMITCASE0

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68b_case0Sink()
{
    HANDLE data = CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68_case0DataForCase0Sink;
    /* NOTE: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68b_case1V2Sink()
{
    HANDLE data = CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68_case0DataForCase1Sink;
    /* ALT: If the file is still opened, close it */
    if (data != INVALID_HANDLE_VALUE)
    {
        CloseHandle(data);
    }
}

#endif /* OMITCASE1 */
