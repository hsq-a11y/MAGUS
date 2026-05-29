/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_listen_socket_ifstream_84.h
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-84.tmpl.h
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Use a fixed file name
 * Sinks: ifstream
 *    Case0Sink : Open the file named in data using ifstream::open()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH L"c:\\temp\\"
#else
#include <wchar.h>
#define BASEPATH L"/tmp/"
#endif

namespace CWE23_Relative_Path_Traversal__wchar_t_listen_socket_ifstream_84
{

#ifndef OMITCASE0

class CWE23_Relative_Path_Traversal__wchar_t_listen_socket_ifstream_84_case0
{
public:
    CWE23_Relative_Path_Traversal__wchar_t_listen_socket_ifstream_84_case0(wchar_t * dataCopy);
    ~CWE23_Relative_Path_Traversal__wchar_t_listen_socket_ifstream_84_case0();

private:
    wchar_t * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE23_Relative_Path_Traversal__wchar_t_listen_socket_ifstream_84_case1V1
{
public:
    CWE23_Relative_Path_Traversal__wchar_t_listen_socket_ifstream_84_case1V1(wchar_t * dataCopy);
    ~CWE23_Relative_Path_Traversal__wchar_t_listen_socket_ifstream_84_case1V1();

private:
    wchar_t * data;
};

#endif /* OMITCASE1 */

}
