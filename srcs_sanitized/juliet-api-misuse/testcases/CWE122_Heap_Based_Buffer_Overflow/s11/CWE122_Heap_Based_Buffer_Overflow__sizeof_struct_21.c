/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_21.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-21.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize the source buffer using the size of a pointer
 * Case1Source: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    Case0Sink : Print then free data
 * Flow Variant: 21 Control flow: Flow controlled by value of a static global variable. All functions contained in one file.
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* The static variable below is used to drive control flow in the source function */
static int case0Static = 0;

static twoIntsStruct * case0Source(twoIntsStruct * data)
{
    if(case0Static)
    {
        /* INCIDENTAL: CWE-467 (Use of sizeof() on a pointer type) */
        /* NOTE: Using sizeof the pointer and not the data type in malloc() */
        data = (twoIntsStruct *)malloc(sizeof(data));
        if (data == NULL) {exit(-1);}
        data->intOne = 1;
        data->intTwo = 2;
    }
    return data;
}

void CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_21_case0()
{
    twoIntsStruct * data;
    /* Initialize data */
    data = NULL;
    case0Static = 1; /* true */
    data = case0Source(data);
    /* NOTE: Attempt to use data, which may not have enough memory allocated */
    printStructLine(data);
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The static variables below are used to drive control flow in the source functions. */
static int case1V11Static = 0;
static int case1V12Static = 0;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
static twoIntsStruct * case1V11Source(twoIntsStruct * data)
{
    if(case1V11Static)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Using sizeof the data type in malloc() */
        data = (twoIntsStruct *)malloc(sizeof(*data));
        if (data == NULL) {exit(-1);}
        data->intOne = 1;
        data->intTwo = 2;
    }
    return data;
}

static void case1V11()
{
    twoIntsStruct * data;
    /* Initialize data */
    data = NULL;
    case1V11Static = 0; /* false */
    data = case1V11Source(data);
    /* NOTE: Attempt to use data, which may not have enough memory allocated */
    printStructLine(data);
    free(data);
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
static twoIntsStruct * case1V12Source(twoIntsStruct * data)
{
    if(case1V12Static)
    {
        /* ALT: Using sizeof the data type in malloc() */
        data = (twoIntsStruct *)malloc(sizeof(*data));
        if (data == NULL) {exit(-1);}
        data->intOne = 1;
        data->intTwo = 2;
    }
    return data;
}

static void case1V12()
{
    twoIntsStruct * data;
    /* Initialize data */
    data = NULL;
    case1V12Static = 1; /* true */
    data = case1V12Source(data);
    /* NOTE: Attempt to use data, which may not have enough memory allocated */
    printStructLine(data);
    free(data);
}

void CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_21_case1()
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
    CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_21_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_21_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
