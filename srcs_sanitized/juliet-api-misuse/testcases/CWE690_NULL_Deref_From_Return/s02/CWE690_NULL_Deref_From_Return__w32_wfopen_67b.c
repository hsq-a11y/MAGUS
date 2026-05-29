/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_67b.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE690_NULL_Deref_From_Return__w32_wfopen_67_structType
{
    FILE * structFirst;
} CWE690_NULL_Deref_From_Return__w32_wfopen_67_structType;

#ifndef OMITCASE0

void CWE690_NULL_Deref_From_Return__w32_wfopen_67b_case0Sink(CWE690_NULL_Deref_From_Return__w32_wfopen_67_structType myStruct)
{
    FILE * data = myStruct.structFirst;
    /* NOTE: if the fopen failed, data will be NULL here */
    fclose(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE690_NULL_Deref_From_Return__w32_wfopen_67b_case1V2Sink(CWE690_NULL_Deref_From_Return__w32_wfopen_67_structType myStruct)
{
    FILE * data = myStruct.structFirst;
    /* ALT: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

#endif /* OMITCASE1 */
