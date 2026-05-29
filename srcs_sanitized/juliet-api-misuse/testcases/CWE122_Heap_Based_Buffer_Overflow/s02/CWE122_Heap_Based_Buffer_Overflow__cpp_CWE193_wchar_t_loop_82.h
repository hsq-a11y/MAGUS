/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_loop_82.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193.label.xml
Template File: sources-sink-82.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory for a string, but do not allocate space for NULL terminator
 * Case1Source: Allocate enough memory for a string and the NULL terminator
 * Sinks: loop
 *    Case0Sink : Copy array to data using a loop
 * Flow Variant: 82 Data flow: data passed in a parameter to a virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_loop_82
{

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_loop_82_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) = 0;
};

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_loop_82_case0 : public CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_loop_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_loop_82_case1V1 : public CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_loop_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE1 */

}
