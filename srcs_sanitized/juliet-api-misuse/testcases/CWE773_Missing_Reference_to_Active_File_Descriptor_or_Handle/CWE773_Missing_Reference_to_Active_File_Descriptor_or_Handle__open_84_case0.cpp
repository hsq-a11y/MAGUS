/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84_case0.cpp
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open.label.xml
Template File: source-sinks-84_case0.tmpl.cpp
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
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84.h"

namespace CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84
{
CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84_case0::CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84_case0(int dataCopy)
{
    data = dataCopy;
    /* NOTE: Create a file descriptor using open() that may not be closed properly */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
}

CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84_case0::~CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_84_case0()
{
    /* NOTE: Assign data to another file descriptor without closing the descriptor from the source */
    data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    /* avoid incidental for not closing the file */
    if (data != -1)
    {
        CLOSE(data);
    }
}
}
#endif /* OMITCASE0 */
