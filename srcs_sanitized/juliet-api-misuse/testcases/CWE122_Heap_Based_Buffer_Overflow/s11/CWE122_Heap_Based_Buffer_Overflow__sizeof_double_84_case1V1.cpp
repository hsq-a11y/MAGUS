/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_double_84_case1V1.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize the source buffer using the size of a pointer
 * Case1Source: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__sizeof_double_84.h"

namespace CWE122_Heap_Based_Buffer_Overflow__sizeof_double_84
{
CWE122_Heap_Based_Buffer_Overflow__sizeof_double_84_case1V1::CWE122_Heap_Based_Buffer_Overflow__sizeof_double_84_case1V1(double * dataCopy)
{
    data = dataCopy;
    /* ALT: Using sizeof the data type in malloc() */
    data = (double *)malloc(sizeof(*data));
    if (data == NULL) {exit(-1);}
    *data = 1.7E300;
}

CWE122_Heap_Based_Buffer_Overflow__sizeof_double_84_case1V1::~CWE122_Heap_Based_Buffer_Overflow__sizeof_double_84_case1V1()
{
    /* NOTE: Attempt to use data, which may not have enough memory allocated */
    printDoubleLine(*data);
    free(data);
}
}
#endif /* OMITCASE1 */
