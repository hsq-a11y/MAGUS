/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE135_82.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Void pointer to a wchar_t array
 * Case1Source: Void pointer to a char array
 * Sinks:
 *    Case1Sink: Allocate memory using wcslen() and copy data
 *    Case0Sink : Allocate memory using strlen() and copy data
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE122_Heap_Based_Buffer_Overflow__CWE135_82
{

class CWE122_Heap_Based_Buffer_Overflow__CWE135_82_base
{
public:
    /* pure virtual function */
    virtual void action(void * data) = 0;
};

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__CWE135_82_case0 : public CWE122_Heap_Based_Buffer_Overflow__CWE135_82_base
{
public:
    void action(void * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__CWE135_82_case1V1 : public CWE122_Heap_Based_Buffer_Overflow__CWE135_82_base
{
public:
    void action(void * data);
};

class CWE122_Heap_Based_Buffer_Overflow__CWE135_82_case1V2 : public CWE122_Heap_Based_Buffer_Overflow__CWE135_82_base
{
public:
    void action(void * data);
};

#endif /* OMITCASE1 */

}
