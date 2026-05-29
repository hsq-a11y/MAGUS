/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_long_22a.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-22a.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using new and Deallocae data using delete
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_long_22
{

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function. Since it is in
a C++ namespace, it doesn't need a globally unique name. */
int case0Global = 0;

void case0Sink(long * data);

void case0()
{
    long * data;
    /* Initialize data */
    data = NULL;
    data = new long;
    /* NOTE: delete data in the source - the case0 sink deletes data as well */
    delete data;
    case0Global = 1; /* true */
    case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. Since they are in
a C++ namespace, they don't need globally unique names. */
int case1V21Global = 0;
int case1V22Global = 0;
int case1V11Global = 0;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void case1V21Sink(long * data);

static void case1V21()
{
    long * data;
    /* Initialize data */
    data = NULL;
    data = new long;
    /* NOTE: delete data in the source - the case0 sink deletes data as well */
    delete data;
    case1V21Global = 0; /* false */
    case1V21Sink(data);
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void case1V22Sink(long * data);

static void case1V22()
{
    long * data;
    /* Initialize data */
    data = NULL;
    data = new long;
    /* NOTE: delete data in the source - the case0 sink deletes data as well */
    delete data;
    case1V22Global = 1; /* true */
    case1V22Sink(data);
}

/* case1V11() - use case1source and case0sink */
void case1V11Sink(long * data);

static void case1V11()
{
    long * data;
    /* Initialize data */
    data = NULL;
    data = new long;
    /* ALT: Do NOT delete data in the source - the case0 sink deletes data */
    case1V11Global = 1; /* true */
    case1V11Sink(data);
}

void case1()
{
    case1V21();
    case1V22();
    case1V11();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE415_Double_Free__new_delete_long_22; /* so that we can use case1 and case0 easily */

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
