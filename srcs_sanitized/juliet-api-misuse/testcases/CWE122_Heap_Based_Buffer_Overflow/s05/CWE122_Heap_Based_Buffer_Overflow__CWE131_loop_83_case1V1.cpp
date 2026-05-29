/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_83_case1V1.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory without using sizeof(int)
 * Case1Source: Allocate memory using sizeof(int)
 * Sinks: loop
 *    Case0Sink : Copy array to data using a loop
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_83.h"

namespace CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_83
{
CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_83_case1V1::CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_83_case1V1(int * dataCopy)
{
    data = dataCopy;
    /* ALT: Allocate memory using sizeof(int) */
    data = (int *)malloc(10*sizeof(int));
    if (data == NULL) {exit(-1);}
}

CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_83_case1V1::~CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_83_case1V1()
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
#endif /* OMITCASE1 */
