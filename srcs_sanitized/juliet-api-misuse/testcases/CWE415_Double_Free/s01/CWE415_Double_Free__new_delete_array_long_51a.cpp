/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_long_51a.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-51a.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using new and Deallocae data using delete
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_array_long_51
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink(long * data);

void case0()
{
    long * data;
    /* Initialize data */
    data = NULL;
    data = new long[100];
    /* NOTE: delete the array data in the source - the case0 sink deletes the array data as well */
    delete [] data;
    case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declarations */
void case1V1Sink(long * data);
void case1V2Sink(long * data);

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    long * data;
    /* Initialize data */
    data = NULL;
    data = new long[100];
    /* ALT: Do NOT delete the array data in the source - the case0 sink deletes the array data */
    case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
static void case1V2()
{
    long * data;
    /* Initialize data */
    data = NULL;
    data = new long[100];
    /* NOTE: delete the array data in the source - the case0 sink deletes the array data as well */
    delete [] data;
    case1V2Sink(data);
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

using namespace CWE415_Double_Free__new_delete_array_long_51; /* so that we can use case1 and case0 easily */

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
