/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_ncpy_22b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193.label.xml
Template File: sources-sink-22b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory for a string, but do not allocate space for NULL terminator
 * Case1Source: Allocate enough memory for a string and the NULL terminator
 * Sink: ncpy
 *    Case0Sink : Copy string to data using wcsncpy()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_ncpy_22
{

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function. Since it is in
a C++ namespace, it doesn't need a globally unique name. */
extern int case0Global;

wchar_t * case0Source(wchar_t * data)
{
    if(case0Global)
    {
        /* NOTE: Did not leave space for a null terminator */
        data = new wchar_t[10];
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
wchar_t * case1V11Source(wchar_t * data)
{
    if(case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Allocate space for a null terminator */
        data = new wchar_t[10+1];
    }
    return data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
wchar_t * case1V12Source(wchar_t * data)
{
    if(case1V12Global)
    {
        /* ALT: Allocate space for a null terminator */
        data = new wchar_t[10+1];
    }
    return data;
}

#endif /* OMITCASE1 */

} /* close namespace */
