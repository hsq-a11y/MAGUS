/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_loop_84_case1V1.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.label.xml
Template File: sources-sink-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using new[] and set data pointer to a small buffer
 * Case1Source: Allocate using new[] and set data pointer to a large buffer
 * Sinks: loop
 *    Case0Sink : Copy int array to data using a loop
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_loop_84.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_loop_84
{
CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_loop_84_case1V1::CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_loop_84_case1V1(int * dataCopy)
{
    data = dataCopy;
    /* ALT: Allocate using new[] and point data to a large buffer that is at least as large as the large buffer used in the sink */
    data = new int[100];
}

CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_loop_84_case1V1::~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_loop_84_case1V1()
{
    {
        int source[100] = {0}; /* fill with 0's */
        {
            size_t i;
            /* NOTE: Possible buffer overflow if data < 100 */
            for (i = 0; i < 100; i++)
            {
                data[i] = source[i];
            }
            printIntLine(data[0]);
            delete [] data;
        }
    }
}
}
#endif /* OMITCASE1 */
