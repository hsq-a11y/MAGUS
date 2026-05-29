/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_loop_83_case1V1.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.label.xml
Template File: sources-sink-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using new[] and set data pointer to a small buffer
 * Case1Source: Allocate using new[] and set data pointer to a large buffer
 * Sinks: loop
 *    Case0Sink : Copy TwoIntsClass array to data using a loop
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_loop_83.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_loop_83
{
CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_loop_83_case1V1::CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_loop_83_case1V1(TwoIntsClass * dataCopy)
{
    data = dataCopy;
    /* ALT: Allocate using new[] and point data to a large buffer that is at least as large as the large buffer used in the sink */
    data = new TwoIntsClass[100];
}

CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_loop_83_case1V1::~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_loop_83_case1V1()
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
        {
            size_t i;
            /* NOTE: Possible buffer overflow if data < 100 */
            for (i = 0; i < 100; i++)
            {
                data[i] = source[i];
            }
            printIntLine(data[0].intOne);
            delete [] data;
        }
    }
}
}
#endif /* OMITCASE1 */
