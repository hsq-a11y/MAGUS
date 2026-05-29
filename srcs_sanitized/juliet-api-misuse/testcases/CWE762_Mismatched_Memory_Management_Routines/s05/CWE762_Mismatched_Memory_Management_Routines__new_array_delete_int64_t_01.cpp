/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_delete_int64_t_01.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_delete.label.xml
Template File: sources-sinks-01.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new []
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: Deallocate data using delete []
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_int64_t_01
{

#ifndef OMITCASE0

void case0()
{
    int64_t * data;
    /* Initialize data*/
    data = NULL;
    /* NOTE: Allocate memory with a function that requires delete [] to free the memory */
    data = new int64_t[100];
    /* NOTE: Deallocate memory using delete - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    delete data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    int64_t * data;
    /* Initialize data*/
    data = NULL;
    /* ALT: Allocate memory from the heap using new */
    data = new int64_t;
    /* NOTE: Deallocate memory using delete - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    delete data;
}

/* case1V2 uses the Case0Source with the Case1Sink */
static void case1V2()
{
    int64_t * data;
    /* Initialize data*/
    data = NULL;
    /* NOTE: Allocate memory with a function that requires delete [] to free the memory */
    data = new int64_t[100];
    /* ALT: Deallocate the memory using delete [] */
    delete [] data;
}

void case1()
{
    case1V1();
    case1V2();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_int64_t_01; /* so that we can use case1 and case0 easily */

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
