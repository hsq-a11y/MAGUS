/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_68b.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: fopen Open and close a file using fopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern FILE * CWE675_Duplicate_Operations_on_Resource__fopen_68_case0Data;
extern FILE * CWE675_Duplicate_Operations_on_Resource__fopen_68_case1V1Data;
extern FILE * CWE675_Duplicate_Operations_on_Resource__fopen_68_case1V2Data;

#ifndef OMITCASE0

void CWE675_Duplicate_Operations_on_Resource__fopen_68b_case0Sink()
{
    FILE * data = CWE675_Duplicate_Operations_on_Resource__fopen_68_case0Data;
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE675_Duplicate_Operations_on_Resource__fopen_68b_case1V1Sink()
{
    FILE * data = CWE675_Duplicate_Operations_on_Resource__fopen_68_case1V1Data;
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE675_Duplicate_Operations_on_Resource__fopen_68b_case1V2Sink()
{
    FILE * data = CWE675_Duplicate_Operations_on_Resource__fopen_68_case1V2Data;
    /* Do nothing */
    /* ALT: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE1 */
