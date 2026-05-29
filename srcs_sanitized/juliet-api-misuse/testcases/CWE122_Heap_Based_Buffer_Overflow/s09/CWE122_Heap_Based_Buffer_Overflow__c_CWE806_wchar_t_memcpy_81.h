/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_memcpy_81.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE806.label.xml
Template File: sources-sink-81.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize data as a large string
 * Case1Source: Initialize data as a small string
 * Sinks: memcpy
 *    Case0Sink : Copy data to string using memcpy
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_memcpy_81
{

class CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_memcpy_81_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) const = 0;
};

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_memcpy_81_case0 : public CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_memcpy_81_base
{
public:
    void action(wchar_t * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_memcpy_81_case1V1 : public CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_memcpy_81_base
{
public:
    void action(wchar_t * data) const;
};

#endif /* OMITCASE1 */

}
