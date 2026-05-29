/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53b.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close.label.xml
Template File: source-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using CreateFile()
 * Sinks:
 *    Case1Sink: Close the file using CloseHandle()
 *    Case0Sink : Do not close file
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITCASE0

/* case0 function declaration */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53c_case0Sink(HANDLE data);

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53b_case0Sink(HANDLE data)
{
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53c_case1V2Sink(HANDLE data);

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53b_case1V2Sink(HANDLE data)
{
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_53c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
