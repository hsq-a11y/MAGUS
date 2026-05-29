/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_61b.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close.label.xml
Template File: source-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using fopen()
 * Sinks:
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Do not close file
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

FILE * CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_61b_case0Source(FILE * data)
{
    /* NOTE: Open a file without closing it */
    data = fopen("Case0Source_fopen.txt", "w+");
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() uses the Case0Source with the Case1Sink */
FILE * CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_61b_case1V2Source(FILE * data)
{
    /* NOTE: Open a file without closing it */
    data = fopen("Case0Source_fopen.txt", "w+");
    return data;
}

#endif /* OMITCASE1 */
