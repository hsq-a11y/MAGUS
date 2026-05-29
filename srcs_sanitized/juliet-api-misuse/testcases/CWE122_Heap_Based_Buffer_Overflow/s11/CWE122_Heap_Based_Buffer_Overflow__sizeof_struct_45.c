/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_45.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize the source buffer using the size of a pointer
 * Case1Source: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static twoIntsStruct * CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_45_case0Data;
static twoIntsStruct * CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_45_case1V1Data;

#ifndef OMITCASE0

static void case0Sink()
{
    twoIntsStruct * data = CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_45_case0Data;
    /* NOTE: Attempt to use data, which may not have enough memory allocated */
    printStructLine(data);
    free(data);
}

void CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_45_case0()
{
    twoIntsStruct * data;
    /* Initialize data */
    data = NULL;
    /* INCIDENTAL: CWE-467 (Use of sizeof() on a pointer type) */
    /* NOTE: Using sizeof the pointer and not the data type in malloc() */
    data = (twoIntsStruct *)malloc(sizeof(data));
    if (data == NULL) {exit(-1);}
    data->intOne = 1;
    data->intTwo = 2;
    CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_45_case0Data = data;
    case0Sink();
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1Sink()
{
    twoIntsStruct * data = CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_45_case1V1Data;
    /* NOTE: Attempt to use data, which may not have enough memory allocated */
    printStructLine(data);
    free(data);
}

static void case1V1()
{
    twoIntsStruct * data;
    /* Initialize data */
    data = NULL;
    /* ALT: Using sizeof the data type in malloc() */
    data = (twoIntsStruct *)malloc(sizeof(*data));
    if (data == NULL) {exit(-1);}
    data->intOne = 1;
    data->intTwo = 2;
    CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_45_case1V1Data = data;
    case1V1Sink();
}

void CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_45_case1()
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
    CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_45_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_45_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
