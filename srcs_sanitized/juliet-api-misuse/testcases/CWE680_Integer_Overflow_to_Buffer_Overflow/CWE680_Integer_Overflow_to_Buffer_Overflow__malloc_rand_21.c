/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_21.c
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-21.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Small number greater than zero that will not cause an integer overflow in the sink
 * Sink:
 *    Case0Sink : Attempt to allocate array using length value from source
 * Flow Variant: 21 Control flow: Flow controlled by value of a static global variable. All functions contained in one file.
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* The static variable below is used to drive control flow in the source function */
static int case0Static = 0;

static int case0Source(int data)
{
    if(case0Static)
    {
        /* NOTE: Set data to a random value */
        data = RAND32();
    }
    return data;
}

void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_21_case0()
{
    int data;
    /* Initialize data */
    data = -1;
    case0Static = 1; /* true */
    data = case0Source(data);
    {
        size_t i;
        int *intPointer;
        /* NOTE: if data * sizeof(int) > SIZE_MAX, overflows to a small value
         * so that the for loop doing the initialization causes a buffer overflow */
        intPointer = (int*)malloc(data * sizeof(int));
        if (intPointer == NULL) {exit(-1);}
        for (i = 0; i < (size_t)data; i++)
        {
            intPointer[i] = 0; /* Potentially writes beyond the boundary of intPointer */
        }
        printIntLine(intPointer[0]);
        free(intPointer);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The static variables below are used to drive control flow in the source functions. */
static int case1V11Static = 0;
static int case1V12Static = 0;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
static int case1V11Source(int data)
{
    if(case1V11Static)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Set data to a relatively small number greater than zero */
        data = 20;
    }
    return data;
}

static void case1V11()
{
    int data;
    /* Initialize data */
    data = -1;
    case1V11Static = 0; /* false */
    data = case1V11Source(data);
    {
        size_t i;
        int *intPointer;
        /* NOTE: if data * sizeof(int) > SIZE_MAX, overflows to a small value
         * so that the for loop doing the initialization causes a buffer overflow */
        intPointer = (int*)malloc(data * sizeof(int));
        if (intPointer == NULL) {exit(-1);}
        for (i = 0; i < (size_t)data; i++)
        {
            intPointer[i] = 0; /* Potentially writes beyond the boundary of intPointer */
        }
        printIntLine(intPointer[0]);
        free(intPointer);
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
static int case1V12Source(int data)
{
    if(case1V12Static)
    {
        /* ALT: Set data to a relatively small number greater than zero */
        data = 20;
    }
    return data;
}

static void case1V12()
{
    int data;
    /* Initialize data */
    data = -1;
    case1V12Static = 1; /* true */
    data = case1V12Source(data);
    {
        size_t i;
        int *intPointer;
        /* NOTE: if data * sizeof(int) > SIZE_MAX, overflows to a small value
         * so that the for loop doing the initialization causes a buffer overflow */
        intPointer = (int*)malloc(data * sizeof(int));
        if (intPointer == NULL) {exit(-1);}
        for (i = 0; i < (size_t)data; i++)
        {
            intPointer[i] = 0; /* Potentially writes beyond the boundary of intPointer */
        }
        printIntLine(intPointer[0]);
        free(intPointer);
    }
}

void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_21_case1()
{
    case1V11();
    case1V12();
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
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_21_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_21_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
