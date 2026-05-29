/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68b.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * Case0Source:  Create a file handle using fopen()
 * Sinks:
 *    Case1Sink: Close the file handle before reusing it
 *    Case0Sink : Reassign the file handle before closing it
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern FILE * CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68_case0DataForCase0Sink;

extern FILE * CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68_case0DataForCase1Sink;

#ifndef OMITCASE0

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68b_case0Sink()
{
    FILE * data = CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68_case0DataForCase0Sink;
    /* NOTE: Point data to another file handle without closing the handle from the source */
    data = fopen("Case0Sink_fopen.txt", "w+");
    /* avoid incidental for not closing the file handle */
    if (data != NULL)
    {
        fclose(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68b_case1V2Sink()
{
    FILE * data = CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68_case0DataForCase1Sink;
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

#endif /* OMITCASE1 */
