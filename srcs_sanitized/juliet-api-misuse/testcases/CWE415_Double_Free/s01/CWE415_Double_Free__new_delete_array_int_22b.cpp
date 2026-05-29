/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_int_22b.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-22b.tmpl.cpp
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

namespace CWE415_Double_Free__new_delete_array_int_22
{

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function. Since it is in
a C++ namespace, it doesn't need a globally unique name. */
extern int case0Global;

void case0Sink(int * data)
{
    if(case0Global)
    {
        /* NOTE: Possibly deleting memory twice */
        delete [] data;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The static variables below are used to drive control flow in the sink functions. Since they are in
a C++ namespace, they don't need globally unique names. */
extern int case1V21Global;
extern int case1V22Global;
extern int case1V11Global;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void case1V21Sink(int * data)
{
    if(case1V21Global)
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

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void case1V22Sink(int * data)
{
    if(case1V22Global)
    {
        /* do nothing */
        /* ALT: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
}

/* case1V11() - use case1source and case0sink */
void case1V11Sink(int * data)
{
    if(case1V11Global)
    {
        /* NOTE: Possibly deleting memory twice */
        delete [] data;
    }
}

#endif /* OMITCASE1 */

} /* close namespace */
