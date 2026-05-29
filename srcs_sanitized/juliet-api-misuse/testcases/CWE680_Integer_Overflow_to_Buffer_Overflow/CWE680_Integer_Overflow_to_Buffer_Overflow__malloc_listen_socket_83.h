/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_listen_socket_83.h
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    Case0Sink : Attempt to allocate array using length value from source
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

namespace CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_listen_socket_83
{

#ifndef OMITCASE0

class CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_listen_socket_83_case0
{
public:
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_listen_socket_83_case0(int dataCopy);
    ~CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_listen_socket_83_case0();

private:
    int data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_listen_socket_83_case1V1
{
public:
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_listen_socket_83_case1V1(int dataCopy);
    ~CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_listen_socket_83_case1V1();

private:
    int data;
};

#endif /* OMITCASE1 */

}
