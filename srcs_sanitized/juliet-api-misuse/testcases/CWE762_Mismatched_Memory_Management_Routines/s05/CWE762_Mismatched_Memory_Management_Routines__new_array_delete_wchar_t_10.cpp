/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_delete_wchar_t_10.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_delete.label.xml
Template File: sources-sinks-10.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new []
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: Deallocate data using delete []
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_wchar_t_10
{

#ifndef OMITCASE0

void case0()
{
    wchar_t * data;
    /* Initialize data*/
    data = NULL;
    if(globalTrue)
    {
        /* NOTE: Allocate memory with a function that requires delete [] to free the memory */
        data = new wchar_t[100];
    }
    if(globalTrue)
    {
        /* NOTE: Deallocate memory using delete - the source memory allocation function may
         * require a call to delete [] to deallocate the memory */
        delete data;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V21() - use case0source and case1sink by changing the second globalTrue to globalFalse */
static void case1V21()
{
    wchar_t * data;
    /* Initialize data*/
    data = NULL;
    if(globalTrue)
    {
        /* NOTE: Allocate memory with a function that requires delete [] to free the memory */
        data = new wchar_t[100];
    }
    if(globalFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Deallocate the memory using delete [] */
        delete [] data;
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the second if */
static void case1V22()
{
    wchar_t * data;
    /* Initialize data*/
    data = NULL;
    if(globalTrue)
    {
        /* NOTE: Allocate memory with a function that requires delete [] to free the memory */
        data = new wchar_t[100];
    }
    if(globalTrue)
    {
        /* ALT: Deallocate the memory using delete [] */
        delete [] data;
    }
}

/* case1V11() - use case1source and case0sink by changing the first globalTrue to globalFalse */
static void case1V11()
{
    wchar_t * data;
    /* Initialize data*/
    data = NULL;
    if(globalFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Allocate memory from the heap using new */
        data = new wchar_t;
    }
    if(globalTrue)
    {
        /* NOTE: Deallocate memory using delete - the source memory allocation function may
         * require a call to delete [] to deallocate the memory */
        delete data;
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the first if */
static void case1V12()
{
    wchar_t * data;
    /* Initialize data*/
    data = NULL;
    if(globalTrue)
    {
        /* ALT: Allocate memory from the heap using new */
        data = new wchar_t;
    }
    if(globalTrue)
    {
        /* NOTE: Deallocate memory using delete - the source memory allocation function may
         * require a call to delete [] to deallocate the memory */
        delete data;
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

using namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_wchar_t_10; /* so that we can use case1 and case0 easily */

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
