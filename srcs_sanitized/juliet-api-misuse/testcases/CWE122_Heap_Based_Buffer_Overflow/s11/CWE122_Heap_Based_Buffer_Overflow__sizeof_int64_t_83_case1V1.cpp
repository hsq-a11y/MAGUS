/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_83_case1V1.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize the source buffer using the size of a pointer
 * Case1Source: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_83.h"

namespace CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_83
{
CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_83_case1V1::CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_83_case1V1(int64_t * dataCopy)
{
    data = dataCopy;
    /* ALT: Using sizeof the data type in malloc() */
    data = (int64_t *)malloc(sizeof(*data));
    if (data == NULL) {exit(-1);}
    *data = 2147483643LL;
}

CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_83_case1V1::~CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_83_case1V1()
{
    /* NOTE: Attempt to use data, which may not have enough memory allocated */
    printLongLongLine(*data);
    free(data);
}
}
#endif /* OMITCASE1 */
