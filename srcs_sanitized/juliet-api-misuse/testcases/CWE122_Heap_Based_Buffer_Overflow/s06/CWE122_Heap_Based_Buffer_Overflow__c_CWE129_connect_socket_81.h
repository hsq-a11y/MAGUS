/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE129_connect_socket_81.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE129.label.xml
Template File: sources-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE129_connect_socket_81
{

class CWE122_Heap_Based_Buffer_Overflow__c_CWE129_connect_socket_81_base
{
public:
    /* pure virtual function */
    virtual void action(int data) const = 0;
};

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__c_CWE129_connect_socket_81_case0 : public CWE122_Heap_Based_Buffer_Overflow__c_CWE129_connect_socket_81_base
{
public:
    void action(int data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__c_CWE129_connect_socket_81_case1V1 : public CWE122_Heap_Based_Buffer_Overflow__c_CWE129_connect_socket_81_base
{
public:
    void action(int data) const;
};

class CWE122_Heap_Based_Buffer_Overflow__c_CWE129_connect_socket_81_case1V2 : public CWE122_Heap_Based_Buffer_Overflow__c_CWE129_connect_socket_81_base
{
public:
    void action(int data) const;
};

#endif /* OMITCASE1 */

}
