/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_65a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory without using sizeof(int)
 * Case1Source: Allocate memory using sizeof(int)
 * Sinks: memcpy
 *    Case0Sink : Copy array to data using memcpy()
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_65b_case0Sink(int * data);

void CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_65_case0()
{
    int * data;
    /* define a function pointer */
    void (*funcPtr) (int *) = CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_65b_case0Sink;
    data = NULL;
    /* NOTE: Allocate memory without using sizeof(int) */
    data = (int *)malloc(10);
    if (data == NULL) {exit(-1);}
    /* use the function pointer */
    funcPtr(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_65b_case1V1Sink(int * data);

static void case1V1()
{
    int * data;
    void (*funcPtr) (int *) = CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_65b_case1V1Sink;
    data = NULL;
    /* ALT: Allocate memory using sizeof(int) */
    data = (int *)malloc(10*sizeof(int));
    if (data == NULL) {exit(-1);}
    funcPtr(data);
}

void CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_65_case1()
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
    CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_65_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_65_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
