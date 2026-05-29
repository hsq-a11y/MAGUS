/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_double_16.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-16.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize the source buffer using the size of a pointer
 * Case1Source: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    Case0Sink : Print then free data
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_16_case0()
{
    double * data;
    /* Initialize data */
    data = NULL;
    while(1)
    {
        /* INCIDENTAL: CWE-467 (Use of sizeof() on a pointer type) */
        /* NOTE: Using sizeof the pointer and not the data type in malloc() */
        data = (double *)malloc(sizeof(data));
        if (data == NULL) {exit(-1);}
        *data = 1.7E300;
        break;
    }
    /* NOTE: Attempt to use data, which may not have enough memory allocated */
    printDoubleLine(*data);
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() - use case1source and case0sink by changing the conditions on the while statements */
static void case1V1()
{
    double * data;
    /* Initialize data */
    data = NULL;
    while(1)
    {
        /* ALT: Using sizeof the data type in malloc() */
        data = (double *)malloc(sizeof(*data));
        if (data == NULL) {exit(-1);}
        *data = 1.7E300;
        break;
    }
    /* NOTE: Attempt to use data, which may not have enough memory allocated */
    printDoubleLine(*data);
    free(data);
}

void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_16_case1()
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
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_16_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_16_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
