/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_52b.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen.label.xml
Template File: source-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * Case0Source:  Create a file handle using fopen()
 * Sinks:
 *    Case1Sink: Close the file handle before reusing it
 *    Case0Sink : Reassign the file handle before closing it
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_52c_case0Sink(FILE * data);

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_52b_case0Sink(FILE * data)
{
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_52c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_52c_case1V2Sink(FILE * data);

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_52b_case1V2Sink(FILE * data)
{
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_52c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
