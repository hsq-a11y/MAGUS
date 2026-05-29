/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84_case1V2.cpp
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open.label.xml
Template File: source-sinks-84_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * Case0Source:  Create a file descriptor using open()
 * Sinks:
 *    Case1Sink: Close the file before reusing the file descriptor
 *    Case0Sink : Reassign the file descriptor before closing the file
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84.h"

namespace CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84
{
CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84_case1V2::CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84_case1V2(int dataCopy)
{
    data = dataCopy;
    /* NOTE: Create a file descriptor using open() that may not be closed properly */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
}

CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84_case1V2::~CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84_case1V2()
{
    /* ALT: Close the file from the source before reassigning data to a new file descriptor */
    if (data != -1)
    {
        CLOSE(data);
    }
    data = OPEN("Case1Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    /* avoid incidental for not closing the file */
    if (data != -1)
    {
        CLOSE(data);
    }
}
}
#endif /* OMITCASE1 */
