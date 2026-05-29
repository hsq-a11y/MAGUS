/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_long_malloc_82a.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-82a.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: malloc Allocate data using malloc()
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__delete_array_long_malloc_82.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_long_malloc_82
{

#ifndef OMITCASE0

void case0()
{
    long * data;
    /* Initialize data*/
    data = NULL;
    /* NOTE: Allocate memory with a function that requires free() to free the memory */
    data = (long *)malloc(100*sizeof(long));
    if (data == NULL) {exit(-1);}
    CWE762_Mismatched_Memory_Management_Routines__delete_array_long_malloc_82_base* baseObject = new CWE762_Mismatched_Memory_Management_Routines__delete_array_long_malloc_82_case0;
    baseObject->action(data);
    delete baseObject;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    long * data;
    /* Initialize data*/
    data = NULL;
    /* ALT: Allocate memory using new [] */
    data = new long[100];
    CWE762_Mismatched_Memory_Management_Routines__delete_array_long_malloc_82_base* baseObject = new CWE762_Mismatched_Memory_Management_Routines__delete_array_long_malloc_82_case1V1;
    baseObject->action(data);
    delete baseObject;
}

/* case1V2 uses the Case0Source with the Case1Sink */
static void case1V2()
{
    long * data;
    /* Initialize data*/
    data = NULL;
    /* NOTE: Allocate memory with a function that requires free() to free the memory */
    data = (long *)malloc(100*sizeof(long));
    if (data == NULL) {exit(-1);}
    CWE762_Mismatched_Memory_Management_Routines__delete_array_long_malloc_82_base* baseObject = new CWE762_Mismatched_Memory_Management_Routines__delete_array_long_malloc_82_case1V2;
    baseObject->action(data);
    delete baseObject;
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

using namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_long_malloc_82; /* so that we can use case1 and case0 easily */

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
