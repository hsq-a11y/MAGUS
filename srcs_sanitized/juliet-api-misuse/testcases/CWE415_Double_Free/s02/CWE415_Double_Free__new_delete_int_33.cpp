/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_int_33.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-33.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using new and Deallocae data using delete
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 33 Data flow: use of a C++ reference to data within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_int_33
{

#ifndef OMITCASE0

void case0()
{
    int * data;
    int * &dataRef = data;
    /* Initialize data */
    data = NULL;
    data = new int;
    /* NOTE: delete data in the source - the case0 sink deletes data as well */
    delete data;
    {
        int * data = dataRef;
        /* NOTE: Possibly deleting memory twice */
        delete data;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1()
{
    int * data;
    int * &dataRef = data;
    /* Initialize data */
    data = NULL;
    data = new int;
    /* ALT: Do NOT delete data in the source - the case0 sink deletes data */
    {
        int * data = dataRef;
        /* NOTE: Possibly deleting memory twice */
        delete data;
    }
}

/* case1V2() uses the Case0Source with the Case1Sink */
static void case1V2()
{
    int * data;
    int * &dataRef = data;
    /* Initialize data */
    data = NULL;
    data = new int;
    /* NOTE: delete data in the source - the case0 sink deletes data as well */
    delete data;
    {
        int * data = dataRef;
        /* do nothing */
        /* ALT: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
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

using namespace CWE415_Double_Free__new_delete_int_33; /* so that we can use case1 and case0 easily */

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
