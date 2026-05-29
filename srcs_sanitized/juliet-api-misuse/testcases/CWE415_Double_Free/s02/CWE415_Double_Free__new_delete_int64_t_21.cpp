/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_int64_t_21.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-21.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using new and Deallocae data using delete
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 21 Control flow: Flow controlled by value of a static global variable. All functions contained in one file.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_int64_t_21
{

#ifndef OMITCASE0

/* The static variable below is used to drive control flow in the sink function */
static int case0Static = 0;

static void case0Sink(int64_t * data)
{
    if(case0Static)
    {
        /* NOTE: Possibly deleting memory twice */
        delete data;
    }
}

void case0()
{
    int64_t * data;
    /* Initialize data */
    data = NULL;
    data = new int64_t;
    /* NOTE: delete data in the source - the case0 sink deletes data as well */
    delete data;
    case0Static = 1; /* true */
    case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The static variables below are used to drive control flow in the sink functions. */
static int case1V21Static = 0;
static int case1V22Static = 0;
static int case1G2bStatic = 0;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
static void case1V21Sink(int64_t * data)
{
    if(case1V21Static)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* do nothing */
        /* ALT: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
}

static void case1V21()
{
    int64_t * data;
    /* Initialize data */
    data = NULL;
    data = new int64_t;
    /* NOTE: delete data in the source - the case0 sink deletes data as well */
    delete data;
    case1V21Static = 0; /* false */
    case1V21Sink(data);
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
static void case1V22Sink(int64_t * data)
{
    if(case1V22Static)
    {
        /* do nothing */
        /* ALT: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
}

static void case1V22()
{
    int64_t * data;
    /* Initialize data */
    data = NULL;
    data = new int64_t;
    /* NOTE: delete data in the source - the case0 sink deletes data as well */
    delete data;
    case1V22Static = 1; /* true */
    case1V22Sink(data);
}

/* case1V1() - use case1source and case0sink */
static void case1V1Sink(int64_t * data)
{
    if(case1G2bStatic)
    {
        /* NOTE: Possibly deleting memory twice */
        delete data;
    }
}

static void case1V1()
{
    int64_t * data;
    /* Initialize data */
    data = NULL;
    data = new int64_t;
    /* ALT: Do NOT delete data in the source - the case0 sink deletes data */
    case1G2bStatic = 1; /* true */
    case1V1Sink(data);
}

void case1()
{
    case1V21();
    case1V22();
    case1V1();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE415_Double_Free__new_delete_int64_t_21; /* so that we can use case1 and case0 easily */

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
