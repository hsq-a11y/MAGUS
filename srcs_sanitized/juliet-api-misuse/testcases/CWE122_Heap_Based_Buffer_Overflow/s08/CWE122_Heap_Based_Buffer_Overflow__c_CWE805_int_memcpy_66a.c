/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memcpy_66a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using malloc() and set data pointer to a small buffer
 * Case1Source: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: memcpy
 *    Case0Sink : Copy int array to data using memcpy
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memcpy_66b_case0Sink(int * dataArray[]);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memcpy_66_case0()
{
    int * data;
    int * dataArray[5];
    data = NULL;
    /* NOTE: Allocate and point data to a small buffer that is smaller than the large buffer used in the sinks */
    data = (int *)malloc(50*sizeof(int));
    if (data == NULL) {exit(-1);}
    /* put data in array */
    dataArray[2] = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memcpy_66b_case0Sink(dataArray);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memcpy_66b_case1V1Sink(int * dataArray[]);

static void case1V1()
{
    int * data;
    int * dataArray[5];
    data = NULL;
    /* ALT: Allocate and point data to a large buffer that is at least as large as the large buffer used in the sink */
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
    dataArray[2] = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memcpy_66b_case1V1Sink(dataArray);
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memcpy_66_case1()
{
    case1V1();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memcpy_66_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memcpy_66_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
