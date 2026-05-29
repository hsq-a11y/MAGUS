/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_81_case0.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.label.xml
Template File: sources-sink-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using malloc() and set data pointer to a small buffer
 * Case1Source: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: memmove
 *    Case0Sink : Copy int64_t array to data using memmove
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_81.h"

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_81
{

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_81_case0::action(int64_t * data) const
{
    {
        int64_t source[100] = {0}; /* fill with 0's */
        /* NOTE: Possible buffer overflow if data < 100 */
        memmove(data, source, 100*sizeof(int64_t));
        printLongLongLine(data[0]);
        free(data);
    }
}

}
#endif /* OMITCASE0 */
