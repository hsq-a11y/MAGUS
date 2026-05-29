/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__CWE839_negative_54d.c
Label Definition File: CWE124_Buffer_Underwrite__CWE839.label.xml
Template File: sources-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source: negative Negative index value
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the lower bound
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE124_Buffer_Underwrite__CWE839_negative_54e_case0Sink(int data);

void CWE124_Buffer_Underwrite__CWE839_negative_54d_case0Sink(int data)
{
    CWE124_Buffer_Underwrite__CWE839_negative_54e_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE124_Buffer_Underwrite__CWE839_negative_54e_case1V1Sink(int data);

void CWE124_Buffer_Underwrite__CWE839_negative_54d_case1V1Sink(int data)
{
    CWE124_Buffer_Underwrite__CWE839_negative_54e_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE124_Buffer_Underwrite__CWE839_negative_54e_case1V2Sink(int data);

void CWE124_Buffer_Underwrite__CWE839_negative_54d_case1V2Sink(int data)
{
    CWE124_Buffer_Underwrite__CWE839_negative_54e_case1V2Sink(data);
}

#endif /* OMITCASE1 */
