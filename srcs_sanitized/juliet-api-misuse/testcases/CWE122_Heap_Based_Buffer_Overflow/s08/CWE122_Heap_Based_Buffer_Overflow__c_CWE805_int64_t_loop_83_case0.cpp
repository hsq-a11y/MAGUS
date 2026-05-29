/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_83_case0.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.label.xml
Template File: sources-sink-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using malloc() and set data pointer to a small buffer
 * Case1Source: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: loop
 *    Case0Sink : Copy int64_t array to data using a loop
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_83.h"

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_83
{
CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_83_case0::CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_83_case0(int64_t * dataCopy)
{
    data = dataCopy;
    /* NOTE: Allocate and point data to a small buffer that is smaller than the large buffer used in the sinks */
    data = (int64_t *)malloc(50*sizeof(int64_t));
    if (data == NULL) {exit(-1);}
}

CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_83_case0::~CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_83_case0()
{
    {
        int64_t source[100] = {0}; /* fill with 0's */
        {
            size_t i;
            /* NOTE: Possible buffer overflow if data < 100 */
            for (i = 0; i < 100; i++)
            {
                data[i] = source[i];
            }
            printLongLongLine(data[0]);
            free(data);
        }
    }
}
}
#endif /* OMITCASE0 */
