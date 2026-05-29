/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_83_case0.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-83_case0.tmpl.cpp
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
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_83.h"

namespace CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_83
{
CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_83_case0::CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_83_case0(twoIntsStruct * dataCopy)
{
    data = dataCopy;
    /* INCIDENTAL: CWE-467 (Use of sizeof() on a pointer type) */
    /* NOTE: Using sizeof the pointer and not the data type in malloc() */
    data = (twoIntsStruct *)malloc(sizeof(data));
    if (data == NULL) {exit(-1);}
    data->intOne = 1;
    data->intTwo = 2;
}

CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_83_case0::~CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_83_case0()
{
    /* NOTE: Attempt to use data, which may not have enough memory allocated */
    printStructLine(data);
    free(data);
}
}
#endif /* OMITCASE0 */
