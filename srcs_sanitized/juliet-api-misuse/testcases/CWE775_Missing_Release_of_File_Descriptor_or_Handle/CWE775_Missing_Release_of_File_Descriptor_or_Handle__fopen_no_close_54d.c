/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54d.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close.label.xml
Template File: source-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using fopen()
 * Sinks:
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Do not close file
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54e_case0Sink(FILE * data);

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54d_case0Sink(FILE * data)
{
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54e_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54e_case1V2Sink(FILE * data);

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54d_case1V2Sink(FILE * data)
{
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_54e_case1V2Sink(data);
}

#endif /* OMITCASE1 */
