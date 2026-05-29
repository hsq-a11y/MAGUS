/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ofstream_83_case1V1.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-83_case1V1.tmpl.cpp
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
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ofstream_83.h"

#include <fstream>
using namespace std;

namespace CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ofstream_83
{
CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ofstream_83_case1V1::CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ofstream_83_case1V1(wchar_t * dataCopy)
{
    data = dataCopy;
#ifdef _WIN32
    /* ALT: Use a fixed, full path and file name */
    wcscat(data, L"c:\\temp\\file.txt");
#else
    /* ALT: Use a fixed, full path and file name */
    wcscat(data, L"/tmp/file.txt");
#endif
}

CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ofstream_83_case1V1::~CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ofstream_83_case1V1()
{
    {
        ofstream outputFile;
        /* NOTE: Possibly opening a file without validating the file name or path */
        outputFile.open((char *)data);
        outputFile.close();
    }
}
}
#endif /* OMITCASE1 */
