/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_82.h
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close.label.xml
Template File: source-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using CreateFile()
 * Sinks:
 *    Case1Sink: Close the file using CloseHandle()
 *    Case0Sink : Do not close file
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#include <windows.h>

namespace CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_82
{

class CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_82_base
{
public:
    /* pure virtual function */
    virtual void action(HANDLE data) = 0;
};

#ifndef OMITCASE0

class CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_82_case0 : public CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_82_base
{
public:
    void action(HANDLE data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_82_case1V2 : public CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_82_base
{
public:
    void action(HANDLE data);
};

#endif /* OMITCASE1 */

}
