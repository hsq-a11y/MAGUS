/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84_case1V2.cpp
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen.label.xml
Template File: source-sinks-84_case1V2.tmpl.cpp
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
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84.h"

namespace CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84
{
CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84_case1V2::CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84_case1V2(FILE * dataCopy)
{
    data = dataCopy;
    /* NOTE: Create a file handle using fopen() that may not be closed properly */
    data = fopen("Case0Source_fopen.txt", "w+");
}

CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84_case1V2::~CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_84_case1V2()
{
    /* ALT: Close the file from the source before pointing data to a new file handle */
    if (data != NULL)
    {
        fclose(data);
    }
    data = fopen("Case1Sink_fopen.txt", "w+");
    /* avoid incidental for not closing the file handle */
    if (data != NULL)
    {
        fclose(data);
    }
}
}
#endif /* OMITCASE1 */
