/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_large_61b.c
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Case0Source: large Large index value that is greater than 10-1
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

int CWE126_Buffer_Overread__CWE129_large_61b_case0Source(int data)
{
    /* NOTE: Use an invalid index */
    data = 10;
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
int CWE126_Buffer_Overread__CWE129_large_61b_case1V1Source(int data)
{
    /* ALT: Use a value greater than 0, but less than 10 to avoid attempting to
     * access an index of the array in the sink that is out-of-bounds */
    data = 7;
    return data;
}

/* case1V2() uses the Case0Source with the Case1Sink */
int CWE126_Buffer_Overread__CWE129_large_61b_case1V2Source(int data)
{
    /* NOTE: Use an invalid index */
    data = 10;
    return data;
}

#endif /* OMITCASE1 */
