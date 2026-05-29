/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__new_fixed_61b.cpp
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__new.label.xml
Template File: sources-sink-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * Case0Source: fixed Fixed value that will cause an integer overflow in the sink
 * Case1Source: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    Case0Sink : Attempt to allocate array using length value from source
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE680_Integer_Overflow_to_Buffer_Overflow__new_fixed_61
{

#ifndef OMITCASE0

int case0Source(int data)
{
    /* NOTE: Set data to a value that will cause an integer overflow in the call to new[] in the sink */
    data = INT_MAX / 2 + 2; /* 1073741825 */
    /* NOTE: This value will cause the sink to only allocate 4 bytes of memory, however
     * the for loop will attempt to access indices 0-1073741824 */
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
int case1V1Source(int data)
{
    /* ALT: Set data to a relatively small number greater than zero */
    data = 20;
    return data;
}

#endif /* OMITCASE1 */

} /* close namespace */
