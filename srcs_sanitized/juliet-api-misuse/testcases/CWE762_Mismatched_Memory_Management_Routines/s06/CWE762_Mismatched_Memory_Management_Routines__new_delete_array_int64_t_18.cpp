/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_delete_array_int64_t_18.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_delete_array.label.xml
Template File: sources-sinks-18.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using delete
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 18 Control flow: goto statements
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_int64_t_18
{

#ifndef OMITCASE0

void case0()
{
    int64_t * data;
    /* Initialize data*/
    data = NULL;
    goto source;
source:
    /* NOTE: Allocate memory with a function that requires delete to free the memory */
    data = new int64_t;
    goto sink;
sink:
    /* NOTE: Deallocate memory using delete [] - the source memory allocation function may
     * require a call to delete to deallocate the memory */
    delete [] data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() - use case0source and case1sink by reversing the blocks on the second goto statement */
static void case1V2()
{
    int64_t * data;
    /* Initialize data*/
    data = NULL;
    goto source;
source:
    /* NOTE: Allocate memory with a function that requires delete to free the memory */
    data = new int64_t;
    goto sink;
sink:
    /* ALT: Deallocate the memory using delete */
    delete data;
}

/* case1V1() - use case1source and case0sink by reversing the blocks on the first goto statement */
static void case1V1()
{
    int64_t * data;
    /* Initialize data*/
    data = NULL;
    goto source;
source:
    /* ALT: Allocate memory from the heap using new [] */
    data = new int64_t[100];
    goto sink;
sink:
    /* NOTE: Deallocate memory using delete [] - the source memory allocation function may
     * require a call to delete to deallocate the memory */
    delete [] data;
}

void case1()
{
    case1V2();
    case1V1();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_int64_t_18; /* so that we can use case1 and case0 easily */

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
