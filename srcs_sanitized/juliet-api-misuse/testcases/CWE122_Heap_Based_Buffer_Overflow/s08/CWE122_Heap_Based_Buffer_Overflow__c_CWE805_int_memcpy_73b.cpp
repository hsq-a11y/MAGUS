/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memcpy_73b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.label.xml
Template File: sources-sink-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using malloc() and set data pointer to a small buffer
 * Case1Source: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: memcpy
 *    Case0Sink : Copy int array to data using memcpy
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

using namespace std;

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memcpy_73
{

#ifndef OMITCASE0

void case0Sink(list<int *> dataList)
{
    /* copy data out of dataList */
    int * data = dataList.back();
    {
        int source[100] = {0}; /* fill with 0's */
        /* NOTE: Possible buffer overflow if data < 100 */
        memcpy(data, source, 100*sizeof(int));
        printIntLine(data[0]);
        free(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(list<int *> dataList)
{
    int * data = dataList.back();
    {
        int source[100] = {0}; /* fill with 0's */
        /* NOTE: Possible buffer overflow if data < 100 */
        memcpy(data, source, 100*sizeof(int));
        printIntLine(data[0]);
        free(data);
    }
}

#endif /* OMITCASE1 */

} /* close namespace */
