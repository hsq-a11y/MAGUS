/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE135_84.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-84.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Void pointer to a wchar_t array
 * Case1Source: Void pointer to a char array
 * Sinks:
 *    Case1Sink: Allocate memory using wcslen() and copy data
 *    Case0Sink : Allocate memory using strlen() and copy data
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE122_Heap_Based_Buffer_Overflow__CWE135_84
{

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__CWE135_84_case0
{
public:
    CWE122_Heap_Based_Buffer_Overflow__CWE135_84_case0(void * dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__CWE135_84_case0();

private:
    void * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__CWE135_84_case1V1
{
public:
    CWE122_Heap_Based_Buffer_Overflow__CWE135_84_case1V1(void * dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__CWE135_84_case1V1();

private:
    void * data;
};

class CWE122_Heap_Based_Buffer_Overflow__CWE135_84_case1V2
{
public:
    CWE122_Heap_Based_Buffer_Overflow__CWE135_84_case1V2(void * dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__CWE135_84_case1V2();

private:
    void * data;
};

#endif /* OMITCASE1 */

}
