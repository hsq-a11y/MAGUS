/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_22b.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
extern int CWE690_NULL_Deref_From_Return__w32_wfopen_22_case0Global;

void CWE690_NULL_Deref_From_Return__w32_wfopen_22_case0Sink(FILE * data)
{
    if(CWE690_NULL_Deref_From_Return__w32_wfopen_22_case0Global)
    {
        /* NOTE: if the fopen failed, data will be NULL here */
        fclose(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE690_NULL_Deref_From_Return__w32_wfopen_22_case1V21Global;
extern int CWE690_NULL_Deref_From_Return__w32_wfopen_22_case1V22Global;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE690_NULL_Deref_From_Return__w32_wfopen_22_case1V21Sink(FILE * data)
{
    if(CWE690_NULL_Deref_From_Return__w32_wfopen_22_case1V21Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: check the return value */
        if (data != NULL)
        {
            fclose(data);
        }
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE690_NULL_Deref_From_Return__w32_wfopen_22_case1V22Sink(FILE * data)
{
    if(CWE690_NULL_Deref_From_Return__w32_wfopen_22_case1V22Global)
    {
        /* ALT: check the return value */
        if (data != NULL)
        {
            fclose(data);
        }
    }
}

#endif /* OMITCASE1 */
