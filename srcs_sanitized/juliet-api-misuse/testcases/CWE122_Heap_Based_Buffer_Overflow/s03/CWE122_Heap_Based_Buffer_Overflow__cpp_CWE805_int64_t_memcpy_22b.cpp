/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_memcpy_22b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.label.xml
Template File: sources-sink-22b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using new[] and set data pointer to a small buffer
 * Case1Source: Allocate using new[] and set data pointer to a large buffer
 * Sink: memcpy
 *    Case0Sink : Copy int64_t array to data using memcpy
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_memcpy_22
{

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function. Since it is in
a C++ namespace, it doesn't need a globally unique name. */
extern int case0Global;

int64_t * case0Source(int64_t * data)
{
    if(case0Global)
    {
        /* NOTE: Allocate using new[] and point data to a small buffer that is smaller than the large buffer used in the sinks */
        data = new int64_t[50];
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. Since they are in
a C++ namespace, they don't need globally unique names. */
extern int case1V11Global;
extern int case1V12Global;

/* case1V11() - use case1source and case0sink by setting the global variable to false instead of true */
int64_t * case1V11Source(int64_t * data)
{
    if(case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Allocate using new[] and point data to a large buffer that is at least as large as the large buffer used in the sink */
        data = new int64_t[100];
    }
    return data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
int64_t * case1V12Source(int64_t * data)
{
    if(case1V12Global)
    {
        /* ALT: Allocate using new[] and point data to a large buffer that is at least as large as the large buffer used in the sink */
        data = new int64_t[100];
    }
    return data;
}

#endif /* OMITCASE1 */

} /* close namespace */
