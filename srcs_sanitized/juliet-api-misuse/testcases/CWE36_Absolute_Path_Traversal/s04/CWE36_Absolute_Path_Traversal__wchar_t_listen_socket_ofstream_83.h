/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ofstream_83.h
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Full path and file name
 * Sinks: ofstream
 *    Case0Sink : Open the file named in data using ofstream::open()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ofstream_83
{

#ifndef OMITCASE0

class CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ofstream_83_case0
{
public:
    CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ofstream_83_case0(wchar_t * dataCopy);
    ~CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ofstream_83_case0();

private:
    wchar_t * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ofstream_83_case1V1
{
public:
    CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ofstream_83_case1V1(wchar_t * dataCopy);
    ~CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ofstream_83_case1V1();

private:
    wchar_t * data;
};

#endif /* OMITCASE1 */

}
