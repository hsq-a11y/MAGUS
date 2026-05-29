/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__fopen_61b.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: fopen Open data with fopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

FILE * CWE690_NULL_Deref_From_Return__fopen_61b_case0Source(FILE * data)
{
    /* NOTE: Open a file without checking the return value for NULL */
    data = fopen("file.txt", "w+");
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() uses the Case0Source with the Case1Sink */
FILE * CWE690_NULL_Deref_From_Return__fopen_61b_case1V2Source(FILE * data)
{
    /* NOTE: Open a file without checking the return value for NULL */
    data = fopen("file.txt", "w+");
    return data;
}

#endif /* OMITCASE1 */
