/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_large_53b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129.label.xml
Template File: sources-sinks-53b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source: large Large index value that is greater than 10-1
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_large_53
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink_c(int data);

void case0Sink_b(int data)
{
    case0Sink_c(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink_c(int data);

void case1V1Sink_b(int data)
{
    case1V1Sink_c(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink_c(int data);

void case1V2Sink_b(int data)
{
    case1V2Sink_c(data);
}

#endif /* OMITCASE1 */

} /* close namespace */
