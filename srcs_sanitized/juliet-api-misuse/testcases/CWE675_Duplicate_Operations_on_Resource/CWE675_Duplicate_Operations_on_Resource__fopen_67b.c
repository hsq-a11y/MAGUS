/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_67b.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: fopen Open and close a file using fopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE675_Duplicate_Operations_on_Resource__fopen_67_structType
{
    FILE * structFirst;
} CWE675_Duplicate_Operations_on_Resource__fopen_67_structType;

#ifndef OMITCASE0

void CWE675_Duplicate_Operations_on_Resource__fopen_67b_case0Sink(CWE675_Duplicate_Operations_on_Resource__fopen_67_structType myStruct)
{
    FILE * data = myStruct.structFirst;
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE675_Duplicate_Operations_on_Resource__fopen_67b_case1V1Sink(CWE675_Duplicate_Operations_on_Resource__fopen_67_structType myStruct)
{
    FILE * data = myStruct.structFirst;
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE675_Duplicate_Operations_on_Resource__fopen_67b_case1V2Sink(CWE675_Duplicate_Operations_on_Resource__fopen_67_structType myStruct)
{
    FILE * data = myStruct.structFirst;
    /* Do nothing */
    /* ALT: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE1 */
