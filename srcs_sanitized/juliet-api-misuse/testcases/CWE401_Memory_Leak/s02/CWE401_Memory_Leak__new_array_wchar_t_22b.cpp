/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_wchar_t_22b.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-22b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using new[]
 * Case1Source: Point data to a stack buffer
 * Sinks:
 *    Case1Sink: call delete[] on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_array_wchar_t_22
{

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function. Since it is in
a C++ namespace, it doesn't need a globally unique name. */
extern int case0Global;

void case0Sink(wchar_t * data)
{
    if(case0Global)
    {
        /* NOTE: No deallocation */
        ; /* empty statement needed for some flow variants */
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
void case1V21Sink(wchar_t * data)
{
    if(case1V21Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Deallocate memory */
        delete[] data;
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void case1V22Sink(wchar_t * data)
{
    if(case1V22Global)
    {
        /* ALT: Deallocate memory */
        delete[] data;
    }
}

/* case1V11() - use case1source and case0sink */
void case1V11Sink(wchar_t * data)
{
    if(case1V11Global)
    {
        /* NOTE: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITCASE1 */

} /* close namespace */
