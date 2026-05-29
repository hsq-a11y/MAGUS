/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53c.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen.label.xml
Template File: source-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * Case0Source:  Create a file handle using fopen()
 * Sinks:
 *    Case1Sink: Close the file handle before reusing it
 *    Case0Sink : Reassign the file handle before closing it
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53d_case0Sink(FILE * data);

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53c_case0Sink(FILE * data)
{
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53d_case1V2Sink(FILE * data);

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53c_case1V2Sink(FILE * data)
{
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53d_case1V2Sink(data);
}

#endif /* OMITCASE1 */
