/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__CWE839_negative_61b.c
Label Definition File: CWE127_Buffer_Underread__CWE839.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Underread
 * Case0Source: negative Negative index value
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking to see if the value is negative
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

int CWE127_Buffer_Underread__CWE839_negative_61b_case0Source(int data)
{
    /* NOTE: Use an invalid index */
    data = -5;
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
int CWE127_Buffer_Underread__CWE839_negative_61b_case1V1Source(int data)
{
    /* ALT: Use a value greater than 0, but less than 10 to avoid attempting to
     * access an index of the array in the sink that is out-of-bounds */
    data = 7;
    return data;
}

/* case1V2() uses the Case0Source with the Case1Sink */
int CWE127_Buffer_Underread__CWE839_negative_61b_case1V2Source(int data)
{
    /* NOTE: Use an invalid index */
    data = -5;
    return data;
}

#endif /* OMITCASE1 */
