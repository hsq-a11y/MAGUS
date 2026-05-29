/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__CWE839_fgets_53b.c
Label Definition File: CWE124_Buffer_Underwrite__CWE839.label.xml
Template File: sources-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source: fgets Read data from the console using fgets()
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the lower bound
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

#ifndef OMITCASE0

/* case0 function declaration */
void CWE124_Buffer_Underwrite__CWE839_fgets_53c_case0Sink(int data);

void CWE124_Buffer_Underwrite__CWE839_fgets_53b_case0Sink(int data)
{
    CWE124_Buffer_Underwrite__CWE839_fgets_53c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE124_Buffer_Underwrite__CWE839_fgets_53c_case1V1Sink(int data);

void CWE124_Buffer_Underwrite__CWE839_fgets_53b_case1V1Sink(int data)
{
    CWE124_Buffer_Underwrite__CWE839_fgets_53c_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE124_Buffer_Underwrite__CWE839_fgets_53c_case1V2Sink(int data);

void CWE124_Buffer_Underwrite__CWE839_fgets_53b_case1V2Sink(int data)
{
    CWE124_Buffer_Underwrite__CWE839_fgets_53c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
