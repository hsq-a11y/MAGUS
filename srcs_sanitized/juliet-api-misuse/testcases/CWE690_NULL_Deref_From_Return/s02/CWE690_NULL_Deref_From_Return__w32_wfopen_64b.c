/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_64b.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-64b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

void CWE690_NULL_Deref_From_Return__w32_wfopen_64b_case0Sink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    FILE * * dataPtr = (FILE * *)dataVoidPtr;
    /* dereference dataPtr into data */
    FILE * data = (*dataPtr);
    /* NOTE: if the fopen failed, data will be NULL here */
    fclose(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE690_NULL_Deref_From_Return__w32_wfopen_64b_case1V2Sink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    FILE * * dataPtr = (FILE * *)dataVoidPtr;
    /* dereference dataPtr into data */
    FILE * data = (*dataPtr);
    /* ALT: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

#endif /* OMITCASE1 */
