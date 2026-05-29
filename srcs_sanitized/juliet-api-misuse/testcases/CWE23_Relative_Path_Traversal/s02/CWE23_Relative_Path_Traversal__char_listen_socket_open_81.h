/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_listen_socket_open_81.h
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-81.tmpl.h
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Use a fixed file name
 * Sinks: open
 *    Case0Sink : Open the file named in data using open()
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH "c:\\temp\\"
#else
#include <wchar.h>
#define BASEPATH "/tmp/"
#endif

namespace CWE23_Relative_Path_Traversal__char_listen_socket_open_81
{

class CWE23_Relative_Path_Traversal__char_listen_socket_open_81_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) const = 0;
};

#ifndef OMITCASE0

class CWE23_Relative_Path_Traversal__char_listen_socket_open_81_case0 : public CWE23_Relative_Path_Traversal__char_listen_socket_open_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE23_Relative_Path_Traversal__char_listen_socket_open_81_case1V1 : public CWE23_Relative_Path_Traversal__char_listen_socket_open_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE1 */

}
