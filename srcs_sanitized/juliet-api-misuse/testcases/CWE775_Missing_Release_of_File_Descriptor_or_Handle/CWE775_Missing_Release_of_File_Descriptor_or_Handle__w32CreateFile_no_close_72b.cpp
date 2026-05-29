/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_72b.cpp
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close.label.xml
Template File: source-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using CreateFile()
 * Sinks:
 *    Case1Sink: Close the file using CloseHandle()
 *    Case0Sink : Do not close file
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#include <windows.h>

using namespace std;

namespace CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_72
{

#ifndef OMITCASE0

void case0Sink(vector<HANDLE> dataVector)
{
    /* copy data out of dataVector */
    HANDLE data = dataVector[2];
    /* NOTE: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(vector<HANDLE> dataVector)
{
    HANDLE data = dataVector[2];
    /* ALT: If the file is still opened, close it */
    if (data != INVALID_HANDLE_VALUE)
    {
        CloseHandle(data);
    }
}

#endif /* OMITCASE1 */

} /* close namespace */
