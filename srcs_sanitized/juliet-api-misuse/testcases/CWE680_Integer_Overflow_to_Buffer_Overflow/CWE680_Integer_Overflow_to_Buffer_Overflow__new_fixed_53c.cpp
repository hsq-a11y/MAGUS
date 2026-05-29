/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__new_fixed_53c.cpp
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__new.label.xml
Template File: sources-sink-53c.tmpl.cpp
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * Case0Source: fixed Fixed value that will cause an integer overflow in the sink
 * Case1Source: Small number greater than zero that will not cause an integer overflow in the sink
 * Sink:
 *    Case0Sink : Attempt to allocate array using length value from source
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE680_Integer_Overflow_to_Buffer_Overflow__new_fixed_53
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink_d(int data);

void case0Sink_c(int data)
{
    case0Sink_d(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink_d(int data);

void case1V1Sink_c(int data)
{
    case1V1Sink_d(data);
}

#endif /* OMITCASE1 */

} /* close namespace */
