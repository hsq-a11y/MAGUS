/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__new_connect_socket_83_case1V1.cpp
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__new.label.xml
Template File: sources-sink-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    Case0Sink : Attempt to allocate array using length value from source
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE680_Integer_Overflow_to_Buffer_Overflow__new_connect_socket_83.h"

namespace CWE680_Integer_Overflow_to_Buffer_Overflow__new_connect_socket_83
{
CWE680_Integer_Overflow_to_Buffer_Overflow__new_connect_socket_83_case1V1::CWE680_Integer_Overflow_to_Buffer_Overflow__new_connect_socket_83_case1V1(int dataCopy)
{
    data = dataCopy;
    /* ALT: Set data to a relatively small number greater than zero */
    data = 20;
}

CWE680_Integer_Overflow_to_Buffer_Overflow__new_connect_socket_83_case1V1::~CWE680_Integer_Overflow_to_Buffer_Overflow__new_connect_socket_83_case1V1()
{
    {
        size_t dataBytes,i;
        int *intPointer;
        /* NOTE: dataBytes may overflow to a small value */
        dataBytes = data * sizeof(int); /* sizeof array in bytes */
        intPointer = (int*)new char[dataBytes];
        for (i = 0; i < (size_t)data; i++)
        {
            intPointer[i] = 0; /* may write beyond limit of intPointer if integer overflow occured above */
        }
        printIntLine(intPointer[0]);
        delete [] intPointer;
    }
}
}
#endif /* OMITCASE1 */
