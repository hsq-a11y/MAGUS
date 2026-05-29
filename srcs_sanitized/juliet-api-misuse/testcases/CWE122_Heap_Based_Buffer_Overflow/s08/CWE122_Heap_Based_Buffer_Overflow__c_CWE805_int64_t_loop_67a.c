/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_67a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using malloc() and set data pointer to a small buffer
 * Case1Source: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: loop
 *    Case0Sink : Copy int64_t array to data using a loop
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_67_structType
{
    int64_t * structFirst;
} CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_67_structType;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_67b_case0Sink(CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_67_structType myStruct);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_67_case0()
{
    int64_t * data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_67_structType myStruct;
    data = NULL;
    /* NOTE: Allocate and point data to a small buffer that is smaller than the large buffer used in the sinks */
    data = (int64_t *)malloc(50*sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    myStruct.structFirst = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_67b_case0Sink(myStruct);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_67b_case1V1Sink(CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_67_structType myStruct);

static void case1V1()
{
    int64_t * data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_67_structType myStruct;
    data = NULL;
    /* ALT: Allocate and point data to a large buffer that is at least as large as the large buffer used in the sink */
    data = (int64_t *)malloc(100*sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    myStruct.structFirst = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_67b_case1V1Sink(myStruct);
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_67_case1()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_67_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_67_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
