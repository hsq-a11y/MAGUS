/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_double_34.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize the source buffer using the size of a pointer
 * Case1Source: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

typedef union
{
    double * unionFirst;
    double * unionSecond;
} CWE122_Heap_Based_Buffer_Overflow__sizeof_double_34_unionType;

#ifndef OMITCASE0

void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_34_case0()
{
    double * data;
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_34_unionType myUnion;
    /* Initialize data */
    data = NULL;
    /* INCIDENTAL: CWE-467 (Use of sizeof() on a pointer type) */
    /* NOTE: Using sizeof the pointer and not the data type in malloc() */
    data = (double *)malloc(sizeof(data));
    if (data == NULL) {exit(-1);}
    *data = 1.7E300;
    myUnion.unionFirst = data;
    {
        double * data = myUnion.unionSecond;
        /* NOTE: Attempt to use data, which may not have enough memory allocated */
        printDoubleLine(*data);
        free(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1()
{
    double * data;
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_34_unionType myUnion;
    /* Initialize data */
    data = NULL;
    /* ALT: Using sizeof the data type in malloc() */
    data = (double *)malloc(sizeof(*data));
    if (data == NULL) {exit(-1);}
    *data = 1.7E300;
    myUnion.unionFirst = data;
    {
        double * data = myUnion.unionSecond;
        /* NOTE: Attempt to use data, which may not have enough memory allocated */
        printDoubleLine(*data);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_34_case1()
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
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_34_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_34_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
