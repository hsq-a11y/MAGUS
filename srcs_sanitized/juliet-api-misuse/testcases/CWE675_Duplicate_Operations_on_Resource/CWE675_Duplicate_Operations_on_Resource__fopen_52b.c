/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_52b.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: fopen Open and close a file using fopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE675_Duplicate_Operations_on_Resource__fopen_52c_case0Sink(FILE * data);

void CWE675_Duplicate_Operations_on_Resource__fopen_52b_case0Sink(FILE * data)
{
    CWE675_Duplicate_Operations_on_Resource__fopen_52c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE675_Duplicate_Operations_on_Resource__fopen_52c_case1V1Sink(FILE * data);

void CWE675_Duplicate_Operations_on_Resource__fopen_52b_case1V1Sink(FILE * data)
{
    CWE675_Duplicate_Operations_on_Resource__fopen_52c_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE675_Duplicate_Operations_on_Resource__fopen_52c_case1V2Sink(FILE * data);

void CWE675_Duplicate_Operations_on_Resource__fopen_52b_case1V2Sink(FILE * data)
{
    CWE675_Duplicate_Operations_on_Resource__fopen_52c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
