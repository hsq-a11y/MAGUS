/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_double_82_case0.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-82_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize the source buffer using the size of a pointer
 * Case1Source: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__sizeof_double_82.h"

namespace CWE122_Heap_Based_Buffer_Overflow__sizeof_double_82
{

void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_82_case0::action(double * data)
{
    /* NOTE: Attempt to use data, which may not have enough memory allocated */
    printDoubleLine(*data);
    free(data);
}

}
#endif /* OMITCASE0 */
