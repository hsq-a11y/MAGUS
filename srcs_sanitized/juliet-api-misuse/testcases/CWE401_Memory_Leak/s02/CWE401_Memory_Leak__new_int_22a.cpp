/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_int_22a.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-22a.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call delete on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_int_22
{

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function. Since it is in
a C++ namespace, it doesn't need a globally unique name. */
int case0Global = 0;

void case0Sink(int * data);

void case0()
{
    int * data;
    data = NULL;
    /* NOTE: Allocate memory on the heap */
    data = new int;
    /* Initialize and make use of data */
    *data = 5;
    printIntLine(*data);
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
void case1V21Sink(int * data);

static void case1V21()
{
    int * data;
    data = NULL;
    /* NOTE: Allocate memory on the heap */
    data = new int;
    /* Initialize and make use of data */
    *data = 5;
    printIntLine(*data);
    case1V21Global = 0; /* false */
    case1V21Sink(data);
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void case1V22Sink(int * data);

static void case1V22()
{
    int * data;
    data = NULL;
    /* NOTE: Allocate memory on the heap */
    data = new int;
    /* Initialize and make use of data */
    *data = 5;
    printIntLine(*data);
    case1V22Global = 1; /* true */
    case1V22Sink(data);
}

/* case1V11() - use case1source and case0sink */
void case1V11Sink(int * data);

static void case1V11()
{
    int * data;
    data = NULL;
    /* ALT: Use memory allocated on the stack */
    int dataCase1Buffer;
    data = &dataCase1Buffer;
    /* Initialize and make use of data */
    *data = 5;
    printIntLine(*data);
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

using namespace CWE401_Memory_Leak__new_int_22; /* so that we can use case1 and case0 easily */

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
