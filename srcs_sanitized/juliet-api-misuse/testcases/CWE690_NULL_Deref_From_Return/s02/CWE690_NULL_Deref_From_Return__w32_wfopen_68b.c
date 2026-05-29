/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_68b.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern FILE * CWE690_NULL_Deref_From_Return__w32_wfopen_68_case0DataForCase0Sink;

extern FILE * CWE690_NULL_Deref_From_Return__w32_wfopen_68_case0DataForCase1Sink;

#ifndef OMITCASE0

void CWE690_NULL_Deref_From_Return__w32_wfopen_68b_case0Sink()
{
    FILE * data = CWE690_NULL_Deref_From_Return__w32_wfopen_68_case0DataForCase0Sink;
    /* NOTE: if the fopen failed, data will be NULL here */
    fclose(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

void CWE690_NULL_Deref_From_Return__w32_wfopen_68b_case1V2Sink()
{
    FILE * data = CWE690_NULL_Deref_From_Return__w32_wfopen_68_case0DataForCase1Sink;
    /* ALT: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

#endif /* OMITCASE1 */
