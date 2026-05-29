/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__CWE839_connect_socket_82.h
Label Definition File: CWE127_Buffer_Underread__CWE839.label.xml
Template File: sources-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 127 Buffer Underread
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking to see if the value is negative
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

namespace CWE127_Buffer_Underread__CWE839_connect_socket_82
{

class CWE127_Buffer_Underread__CWE839_connect_socket_82_base
{
public:
    /* pure virtual function */
    virtual void action(int data) = 0;
};

#ifndef OMITCASE0

class CWE127_Buffer_Underread__CWE839_connect_socket_82_case0 : public CWE127_Buffer_Underread__CWE839_connect_socket_82_base
{
public:
    void action(int data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE127_Buffer_Underread__CWE839_connect_socket_82_case1V1 : public CWE127_Buffer_Underread__CWE839_connect_socket_82_base
{
public:
    void action(int data);
};

class CWE127_Buffer_Underread__CWE839_connect_socket_82_case1V2 : public CWE127_Buffer_Underread__CWE839_connect_socket_82_base
{
public:
    void action(int data);
};

#endif /* OMITCASE1 */

}
