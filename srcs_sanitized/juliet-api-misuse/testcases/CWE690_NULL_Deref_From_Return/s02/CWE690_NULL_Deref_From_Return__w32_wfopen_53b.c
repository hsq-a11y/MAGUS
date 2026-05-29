/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_53b.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE690_NULL_Deref_From_Return__w32_wfopen_53c_case0Sink(FILE * data);

void CWE690_NULL_Deref_From_Return__w32_wfopen_53b_case0Sink(FILE * data)
{
    CWE690_NULL_Deref_From_Return__w32_wfopen_53c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE690_NULL_Deref_From_Return__w32_wfopen_53c_case1V2Sink(FILE * data);

void CWE690_NULL_Deref_From_Return__w32_wfopen_53b_case1V2Sink(FILE * data)
{
    CWE690_NULL_Deref_From_Return__w32_wfopen_53c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
