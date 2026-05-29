/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_52b.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE690_NULL_Deref_From_Return__w32_wfopen_52c_case0Sink(FILE * data);

void CWE690_NULL_Deref_From_Return__w32_wfopen_52b_case0Sink(FILE * data)
{
    CWE690_NULL_Deref_From_Return__w32_wfopen_52c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE690_NULL_Deref_From_Return__w32_wfopen_52c_case1V2Sink(FILE * data);

void CWE690_NULL_Deref_From_Return__w32_wfopen_52b_case1V2Sink(FILE * data)
{
    CWE690_NULL_Deref_From_Return__w32_wfopen_52c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
