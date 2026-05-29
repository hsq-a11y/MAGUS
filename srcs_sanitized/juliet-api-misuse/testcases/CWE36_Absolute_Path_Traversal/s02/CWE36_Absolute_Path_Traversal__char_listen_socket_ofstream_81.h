/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_listen_socket_ofstream_81.h
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-81.tmpl.h
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Full path and file name
 * Sinks: ofstream
 *    Case0Sink : Open the file named in data using ofstream::open()
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE36_Absolute_Path_Traversal__char_listen_socket_ofstream_81
{

class CWE36_Absolute_Path_Traversal__char_listen_socket_ofstream_81_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) const = 0;
};

#ifndef OMITCASE0

class CWE36_Absolute_Path_Traversal__char_listen_socket_ofstream_81_case0 : public CWE36_Absolute_Path_Traversal__char_listen_socket_ofstream_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE36_Absolute_Path_Traversal__char_listen_socket_ofstream_81_case1V1 : public CWE36_Absolute_Path_Traversal__char_listen_socket_ofstream_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE1 */

}
