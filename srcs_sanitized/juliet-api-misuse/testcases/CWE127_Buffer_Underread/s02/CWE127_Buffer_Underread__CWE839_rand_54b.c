/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__CWE839_rand_54b.c
Label Definition File: CWE127_Buffer_Underread__CWE839.label.xml
Template File: sources-sinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Underread
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking to see if the value is negative
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE127_Buffer_Underread__CWE839_rand_54c_case0Sink(int data);

void CWE127_Buffer_Underread__CWE839_rand_54b_case0Sink(int data)
{
    CWE127_Buffer_Underread__CWE839_rand_54c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE127_Buffer_Underread__CWE839_rand_54c_case1V1Sink(int data);

void CWE127_Buffer_Underread__CWE839_rand_54b_case1V1Sink(int data)
{
    CWE127_Buffer_Underread__CWE839_rand_54c_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE127_Buffer_Underread__CWE839_rand_54c_case1V2Sink(int data);

void CWE127_Buffer_Underread__CWE839_rand_54b_case1V2Sink(int data)
{
    CWE127_Buffer_Underread__CWE839_rand_54c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
