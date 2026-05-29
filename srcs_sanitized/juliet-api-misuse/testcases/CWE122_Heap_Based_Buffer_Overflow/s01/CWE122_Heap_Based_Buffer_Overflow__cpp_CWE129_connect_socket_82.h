/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_82.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129.label.xml
Template File: sources-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_82
{

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_82_base
{
public:
    /* pure virtual function */
    virtual void action(int data) = 0;
};

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_82_case0 : public CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_82_base
{
public:
    void action(int data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_82_case1V1 : public CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_82_base
{
public:
    void action(int data);
};

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_82_case1V2 : public CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_connect_socket_82_base
{
public:
    void action(int data);
};

#endif /* OMITCASE1 */

}
