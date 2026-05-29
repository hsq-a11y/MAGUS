/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_83_case1V1.cpp
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * Case0Source: fscanf Read data from the console using fscanf()
 * Case1Source: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    Case0Sink : Attempt to allocate array using length value from source
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_83.h"

namespace CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_83
{
CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_83_case1V1::CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_83_case1V1(int dataCopy)
{
    data = dataCopy;
    /* ALT: Set data to a relatively small number greater than zero */
    data = 20;
}

CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_83_case1V1::~CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_83_case1V1()
{
    {
        size_t i;
        int *intPointer;
        /* NOTE: if data * sizeof(int) > SIZE_MAX, overflows to a small value
         * so that the for loop doing the initialization causes a buffer overflow */
        intPointer = (int*)malloc(data * sizeof(int));
        if (intPointer == NULL) {exit(-1);}
        for (i = 0; i < (size_t)data; i++)
        {
            intPointer[i] = 0; /* Potentially writes beyond the boundary of intPointer */
        }
        printIntLine(intPointer[0]);
        free(intPointer);
    }
}
}
#endif /* OMITCASE1 */
