/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_fscanf_83_case1V2.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129.label.xml
Template File: sources-sinks-83_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source: fscanf Read data from the console using fscanf()
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_fscanf_83.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_fscanf_83
{
CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_fscanf_83_case1V2::CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_fscanf_83_case1V2(int dataCopy)
{
    data = dataCopy;
    /* NOTE: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
}

CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_fscanf_83_case1V2::~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_fscanf_83_case1V2()
{
    {
        int i;
        int * buffer = new int[10];
        /* initialize buffer */
        for (i = 0; i < 10; i++)
        {
            buffer[i] = 0;
        }
        /* ALT: Properly validate the array index and prevent a buffer overflow */
        if (data >= 0 && data < (10))
        {
            buffer[data] = 1;
            /* Print the array values */
            for(i = 0; i < 10; i++)
            {
                printIntLine(buffer[i]);
            }
        }
        else
        {
            printLine("ERROR: Array index is out-of-bounds");
        }
        delete[] buffer;
    }
}
}
#endif /* OMITCASE1 */
