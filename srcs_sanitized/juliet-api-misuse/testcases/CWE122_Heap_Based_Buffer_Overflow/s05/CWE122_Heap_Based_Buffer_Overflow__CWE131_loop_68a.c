/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory without using sizeof(int)
 * Case1Source: Allocate memory using sizeof(int)
 * Sink: loop
 *    Case0Sink : Copy array to data using a loop
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

int * CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68_case0Data;
int * CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68_case1V1Data;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68b_case0Sink();

void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68_case0()
{
    int * data;
    data = NULL;
    /* NOTE: Allocate memory without using sizeof(int) */
    data = (int *)malloc(10);
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68_case0Data = data;
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68b_case0Sink();
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declarations */
void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68b_case1V1Sink();

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    int * data;
    data = NULL;
    /* ALT: Allocate memory using sizeof(int) */
    data = (int *)malloc(10*sizeof(int));
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68_case1V1Data = data;
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68b_case1V1Sink();
}

void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68_case1()
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
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
