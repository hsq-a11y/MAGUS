/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_free_char_43.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_free.label.xml
Template File: sources-sinks-43.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: Deallocate data using delete
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 43 Data flow: data flows using a C++ reference from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_free_char_43
{

#ifndef OMITCASE0

void case0Source(char * &data)
{
    /* NOTE: Allocate memory with a function that requires delete to free the memory */
    data = new char;
}

void case0()
{
    char * data;
    /* Initialize data*/
    data = NULL;
    case0Source(data);
    /* NOTE: Deallocate memory using free() - the source memory allocation function may
     * require a call to delete to deallocate the memory */
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1Source(char * &data)
{
    /* ALT: Allocate memory from the heap using malloc() */
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
}

static void case1V1()
{
    char * data;
    /* Initialize data*/
    data = NULL;
    case1V1Source(data);
    /* NOTE: Deallocate memory using free() - the source memory allocation function may
     * require a call to delete to deallocate the memory */
    free(data);
}

/* case1V2() uses the Case0Source with the Case1Sink */
static void case1V2Source(char * &data)
{
    /* NOTE: Allocate memory with a function that requires delete to free the memory */
    data = new char;
}

static void case1V2()
{
    char * data;
    /* Initialize data*/
    data = NULL;
    case1V2Source(data);
    /* ALT: Deallocate the memory using delete */
    delete data;
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

using namespace CWE762_Mismatched_Memory_Management_Routines__new_free_char_43; /* so that we can use case1 and case0 easily */

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
