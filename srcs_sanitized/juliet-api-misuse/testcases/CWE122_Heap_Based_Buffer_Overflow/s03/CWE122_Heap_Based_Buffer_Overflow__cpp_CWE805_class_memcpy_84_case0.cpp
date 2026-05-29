/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_memcpy_84_case0.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.label.xml
Template File: sources-sink-84_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using new[] and set data pointer to a small buffer
 * Case1Source: Allocate using new[] and set data pointer to a large buffer
 * Sinks: memcpy
 *    Case0Sink : Copy TwoIntsClass array to data using memcpy
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_memcpy_84.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_memcpy_84
{
CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_memcpy_84_case0::CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_memcpy_84_case0(TwoIntsClass * dataCopy)
{
    data = dataCopy;
    /* NOTE: Allocate using new[] and point data to a small buffer that is smaller than the large buffer used in the sinks */
    data = new TwoIntsClass[50];
}

CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_memcpy_84_case0::~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_memcpy_84_case0()
{
    {
        TwoIntsClass source[100];
        {
            size_t i;
            /* Initialize array */
            for (i = 0; i < 100; i++)
            {
                source[i].intOne = 0;
                source[i].intTwo = 0;
            }
        }
        /* NOTE: Possible buffer overflow if data < 100 */
        memcpy(data, source, 100*sizeof(TwoIntsClass));
        printIntLine(data[0].intOne);
        delete [] data;
    }
}
}
#endif /* OMITCASE0 */
