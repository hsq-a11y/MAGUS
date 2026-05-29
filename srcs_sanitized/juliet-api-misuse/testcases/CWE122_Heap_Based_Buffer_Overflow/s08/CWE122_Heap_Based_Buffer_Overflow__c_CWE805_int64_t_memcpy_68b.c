/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_68b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using malloc() and set data pointer to a small buffer
 * Case1Source: Allocate using malloc() and set data pointer to a large buffer
 * Sink: memcpy
 *    Case0Sink : Copy int64_t array to data using memcpy
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern int64_t * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_68_case0Data;
extern int64_t * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_68_case1V1Data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_68b_case0Sink()
{
    int64_t * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_68_case0Data;
    {
        int64_t source[100] = {0}; /* fill with 0's */
        /* NOTE: Possible buffer overflow if data < 100 */
        memcpy(data, source, 100*sizeof(int64_t));
        printLongLongLine(data[0]);
        free(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_68b_case1V1Sink()
{
    int64_t * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_68_case1V1Data;
    {
        int64_t source[100] = {0}; /* fill with 0's */
        /* NOTE: Possible buffer overflow if data < 100 */
        memcpy(data, source, 100*sizeof(int64_t));
        printLongLongLine(data[0]);
        free(data);
    }
}

#endif /* OMITCASE1 */
