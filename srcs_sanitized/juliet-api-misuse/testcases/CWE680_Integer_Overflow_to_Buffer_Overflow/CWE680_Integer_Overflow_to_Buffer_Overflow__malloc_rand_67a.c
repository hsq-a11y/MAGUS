/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67a.c
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    Case0Sink : Attempt to allocate array using length value from source
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67_structType
{
    int structFirst;
} CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67_structType;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67b_case0Sink(CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67_structType myStruct);

void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67_case0()
{
    int data;
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67_structType myStruct;
    /* Initialize data */
    data = -1;
    /* NOTE: Set data to a random value */
    data = RAND32();
    myStruct.structFirst = data;
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67b_case0Sink(myStruct);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67b_case1V1Sink(CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67_structType myStruct);

static void case1V1()
{
    int data;
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67_structType myStruct;
    /* Initialize data */
    data = -1;
    /* ALT: Set data to a relatively small number greater than zero */
    data = 20;
    myStruct.structFirst = data;
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67b_case1V1Sink(myStruct);
}

void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67_case1()
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
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
