/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memmove_82.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.string.label.xml
Template File: sources-sink-82.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using malloc() and set data pointer to a small buffer
 * Case1Source: Allocate using malloc() and set data pointer to a large buffer
 *    Case0Sink : Copy string to data using memmove
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memmove_82
{

class CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memmove_82_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) = 0;
};

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memmove_82_case0 : public CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memmove_82_base
{
public:
    void action(char * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memmove_82_case1V1 : public CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memmove_82_base
{
public:
    void action(char * data);
};

#endif /* OMITCASE1 */

}
