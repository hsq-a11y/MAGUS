/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_listen_socket_81.h
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Sinks:
 *    Case1Sink: free() memory correctly at the start of the buffer
 *    Case0Sink : free() memory not at the start of the buffer
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_listen_socket_81
{

class CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_listen_socket_81_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) const = 0;
};

#ifndef OMITCASE0

class CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_listen_socket_81_case0 : public CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_listen_socket_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_listen_socket_81_case1V2 : public CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_listen_socket_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE1 */

}
