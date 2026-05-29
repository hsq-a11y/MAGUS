/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_memcpy_81.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.string.label.xml
Template File: sources-sink-81.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using new[] and set data pointer to a small buffer
 * Case1Source: Allocate using new[] and set data pointer to a large buffer
 * Sinks: memcpy
 *    Case0Sink : Copy string to data using memcpy
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_memcpy_81
{

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_memcpy_81_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) const = 0;
};

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_memcpy_81_case0 : public CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_memcpy_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_memcpy_81_case1V1 : public CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_memcpy_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE1 */

}
