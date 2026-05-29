/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_84_case0.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-84_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory without using sizeof(int)
 * Case1Source: Allocate memory using sizeof(int)
 * Sinks: loop
 *    Case0Sink : Copy array to data using a loop
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_84.h"

namespace CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_84
{
CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_84_case0::CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_84_case0(int * dataCopy)
{
    data = dataCopy;
    /* NOTE: Allocate memory without using sizeof(int) */
    data = (int *)malloc(10);
    if (data == NULL) {exit(-1);}
}

CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_84_case0::~CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_84_case0()
{
    {
        int source[10] = {0};
        size_t i;
        /* NOTE: Possible buffer overflow if data was not allocated correctly in the source */
        for (i = 0; i < 10; i++)
        {
            data[i] = source[i];
        }
        printIntLine(data[0]);
        free(data);
    }
}
}
#endif /* OMITCASE0 */
