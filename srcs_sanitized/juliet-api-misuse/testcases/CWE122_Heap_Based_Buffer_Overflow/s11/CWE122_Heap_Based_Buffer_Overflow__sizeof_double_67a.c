/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize the source buffer using the size of a pointer
 * Case1Source: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67_structType
{
    double * structFirst;
} CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67_structType;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67b_case0Sink(CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67_structType myStruct);

void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67_case0()
{
    double * data;
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67_structType myStruct;
    /* Initialize data */
    data = NULL;
    /* INCIDENTAL: CWE-467 (Use of sizeof() on a pointer type) */
    /* NOTE: Using sizeof the pointer and not the data type in malloc() */
    data = (double *)malloc(sizeof(data));
    if (data == NULL) {exit(-1);}
    *data = 1.7E300;
    myStruct.structFirst = data;
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67b_case0Sink(myStruct);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67b_case1V1Sink(CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67_structType myStruct);

static void case1V1()
{
    double * data;
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67_structType myStruct;
    /* Initialize data */
    data = NULL;
    /* ALT: Using sizeof the data type in malloc() */
    data = (double *)malloc(sizeof(*data));
    if (data == NULL) {exit(-1);}
    *data = 1.7E300;
    myStruct.structFirst = data;
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67b_case1V1Sink(myStruct);
}

void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67_case1()
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
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
