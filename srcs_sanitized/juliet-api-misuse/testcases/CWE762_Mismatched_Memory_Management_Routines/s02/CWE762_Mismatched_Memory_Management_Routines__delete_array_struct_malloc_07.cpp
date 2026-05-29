/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_malloc_07.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-07.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: malloc Allocate data using malloc()
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

#include "std_testcase.h"

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int staticFive = 5;

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_malloc_07
{

#ifndef OMITCASE0

void case0()
{
    twoIntsStruct * data;
    /* Initialize data*/
    data = NULL;
    if(staticFive==5)
    {
        /* NOTE: Allocate memory with a function that requires free() to free the memory */
        data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
        if (data == NULL) {exit(-1);}
    }
    if(staticFive==5)
    {
        /* NOTE: Deallocate memory using delete [] - the source memory allocation function may
         * require a call to free() to deallocate the memory */
        delete [] data;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V21() - use case0source and case1sink by changing the second staticFive==5 to staticFive!=5 */
static void case1V21()
{
    twoIntsStruct * data;
    /* Initialize data*/
    data = NULL;
    if(staticFive==5)
    {
        /* NOTE: Allocate memory with a function that requires free() to free the memory */
        data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
        if (data == NULL) {exit(-1);}
    }
    if(staticFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Free memory using free() */
        free(data);
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the second if */
static void case1V22()
{
    twoIntsStruct * data;
    /* Initialize data*/
    data = NULL;
    if(staticFive==5)
    {
        /* NOTE: Allocate memory with a function that requires free() to free the memory */
        data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
        if (data == NULL) {exit(-1);}
    }
    if(staticFive==5)
    {
        /* ALT: Free memory using free() */
        free(data);
    }
}

/* case1V11() - use case1source and case0sink by changing the first staticFive==5 to staticFive!=5 */
static void case1V11()
{
    twoIntsStruct * data;
    /* Initialize data*/
    data = NULL;
    if(staticFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Allocate memory using new [] */
        data = new twoIntsStruct[100];
    }
    if(staticFive==5)
    {
        /* NOTE: Deallocate memory using delete [] - the source memory allocation function may
         * require a call to free() to deallocate the memory */
        delete [] data;
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the first if */
static void case1V12()
{
    twoIntsStruct * data;
    /* Initialize data*/
    data = NULL;
    if(staticFive==5)
    {
        /* ALT: Allocate memory using new [] */
        data = new twoIntsStruct[100];
    }
    if(staticFive==5)
    {
        /* NOTE: Deallocate memory using delete [] - the source memory allocation function may
         * require a call to free() to deallocate the memory */
        delete [] data;
    }
}

void case1()
{
    case1V21();
    case1V22();
    case1V11();
    case1V12();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_malloc_07; /* so that we can use case1 and case0 easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
