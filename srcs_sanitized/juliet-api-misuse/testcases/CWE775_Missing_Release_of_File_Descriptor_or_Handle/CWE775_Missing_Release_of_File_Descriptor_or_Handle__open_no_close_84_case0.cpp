/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84_case0.cpp
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close.label.xml
Template File: source-sinks-84_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using open()
 * Sinks:
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Do not close file
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84.h"

namespace CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84
{
CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84_case0::CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84_case0(int dataCopy)
{
    data = dataCopy;
    /* NOTE: Open a file without closing it */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
}

CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84_case0::~CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84_case0()
{
    /* NOTE: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}
}
#endif /* OMITCASE0 */
