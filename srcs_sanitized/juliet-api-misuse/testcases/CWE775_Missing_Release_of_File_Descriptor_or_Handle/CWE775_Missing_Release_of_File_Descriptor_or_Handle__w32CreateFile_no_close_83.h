/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83.h
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close.label.xml
Template File: source-sinks-83.tmpl.h
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

#include "std_testcase.h"

#include <windows.h>

namespace CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83
{

#ifndef OMITCASE0

class CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83_case0
{
public:
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83_case0(HANDLE dataCopy);
    ~CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83_case0();

private:
    HANDLE data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83_case1V2
{
public:
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83_case1V2(HANDLE dataCopy);
    ~CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_83_case1V2();

private:
    HANDLE data;
};

#endif /* OMITCASE1 */

}
