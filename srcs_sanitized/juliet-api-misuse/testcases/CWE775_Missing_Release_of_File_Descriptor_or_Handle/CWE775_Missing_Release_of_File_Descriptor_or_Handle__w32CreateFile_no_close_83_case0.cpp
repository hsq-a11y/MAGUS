/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83_case0.cpp
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close.label.xml
Template File: source-sinks-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using CreateFile()
 * Sinks:
 *    Case1Sink: Close the file using CloseHandle()
 *    Case0Sink : Do not close file
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83.h"

namespace CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83
{
CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83_case0::CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83_case0(HANDLE dataCopy)
{
    data = dataCopy;
    /* NOTE: Open a file without closing it */
    data = CreateFile("Case0Source_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
}

CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83_case0::~CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83_case0()
{
    /* NOTE: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}
}
#endif /* OMITCASE0 */
