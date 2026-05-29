/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_listen_socket_ofstream_82_case0.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-82_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Full path and file name
 * Sinks: ofstream
 *    Case0Sink : Open the file named in data using ofstream::open()
 * Flow Variant: 82 Data flow: data passed in a parameter to a virtual method called via a pointer
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE36_Absolute_Path_Traversal__char_listen_socket_ofstream_82.h"

#include <fstream>
using namespace std;

namespace CWE36_Absolute_Path_Traversal__char_listen_socket_ofstream_82
{

void CWE36_Absolute_Path_Traversal__char_listen_socket_ofstream_82_case0::action(char * data)
{
    {
        ofstream outputFile;
        /* NOTE: Possibly opening a file without validating the file name or path */
        outputFile.open((char *)data);
        outputFile.close();
    }
}

}
#endif /* OMITCASE0 */
