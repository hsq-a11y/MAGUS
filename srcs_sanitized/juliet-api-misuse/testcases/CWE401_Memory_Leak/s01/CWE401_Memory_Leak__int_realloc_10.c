/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__int_realloc_10.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-10.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: realloc Allocate data using realloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

void CWE401_Memory_Leak__int_realloc_10_case0()
{
    int * data;
    data = NULL;
    if(globalTrue)
    {
        /* NOTE: Allocate memory on the heap */
        data = (int *)realloc(data, 100*sizeof(int));
        if (data == NULL) {exit(-1);}
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
    }
    if(globalTrue)
    {
        /* NOTE: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V21() - use case0source and case1sink by changing the second globalTrue to globalFalse */
static void case1V21()
{
    int * data;
    data = NULL;
    if(globalTrue)
    {
        /* NOTE: Allocate memory on the heap */
        data = (int *)realloc(data, 100*sizeof(int));
        if (data == NULL) {exit(-1);}
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
    }
    if(globalFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Deallocate memory */
        free(data);
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the second if */
static void case1V22()
{
    int * data;
    data = NULL;
    if(globalTrue)
    {
        /* NOTE: Allocate memory on the heap */
        data = (int *)realloc(data, 100*sizeof(int));
        if (data == NULL) {exit(-1);}
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
    }
    if(globalTrue)
    {
        /* ALT: Deallocate memory */
        free(data);
    }
}

/* case1V11() - use case1source and case0sink by changing the first globalTrue to globalFalse */
static void case1V11()
{
    int * data;
    data = NULL;
    if(globalFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Use memory allocated on the stack with ALLOCA */
        data = (int *)ALLOCA(100*sizeof(int));
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
    }
    if(globalTrue)
    {
        /* NOTE: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the first if */
static void case1V12()
{
    int * data;
    data = NULL;
    if(globalTrue)
    {
        /* ALT: Use memory allocated on the stack with ALLOCA */
        data = (int *)ALLOCA(100*sizeof(int));
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
    }
    if(globalTrue)
    {
        /* NOTE: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

void CWE401_Memory_Leak__int_realloc_10_case1()
{
    case1V21();
    case1V22();
    case1V11();
    case1V12();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE401_Memory_Leak__int_realloc_10_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE401_Memory_Leak__int_realloc_10_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
