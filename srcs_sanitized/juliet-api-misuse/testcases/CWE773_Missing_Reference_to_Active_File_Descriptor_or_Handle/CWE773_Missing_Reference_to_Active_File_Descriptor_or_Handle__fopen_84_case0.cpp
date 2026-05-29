/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84_case0.cpp
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen.label.xml
Template File: source-sinks-84_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * Case0Source:  Create a file handle using fopen()
 * Sinks:
 *    Case1Sink: Close the file handle before reusing it
 *    Case0Sink : Reassign the file handle before closing it
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84.h"

namespace CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84
{
CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84_case0::CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84_case0(FILE * dataCopy)
{
    data = dataCopy;
    /* NOTE: Create a file handle using fopen() that may not be closed properly */
    data = fopen("Case0Source_fopen.txt", "w+");
}

CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84_case0::~CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84_case0()
{
    /* NOTE: Point data to another file handle without closing the handle from the source */
    data = fopen("Case0Sink_fopen.txt", "w+");
    /* avoid incidental for not closing the file handle */
    if (data != NULL)
    {
        fclose(data);
    }
}
}
#endif /* OMITCASE0 */
