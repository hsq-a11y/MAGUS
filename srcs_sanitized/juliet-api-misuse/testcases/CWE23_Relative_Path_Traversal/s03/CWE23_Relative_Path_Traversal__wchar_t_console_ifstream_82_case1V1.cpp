/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_console_ifstream_82_case1V1.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-82_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * Case0Source: console Read input from the console
 * Case1Source: Use a fixed file name
 * Sinks: ifstream
 *    Case0Sink : Open the file named in data using ifstream::open()
 * Flow Variant: 82 Data flow: data passed in a parameter to a virtual method called via a pointer
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE23_Relative_Path_Traversal__wchar_t_console_ifstream_82.h"

#include <fstream>
using namespace std;

namespace CWE23_Relative_Path_Traversal__wchar_t_console_ifstream_82
{

void CWE23_Relative_Path_Traversal__wchar_t_console_ifstream_82_case1V1::action(wchar_t * data)
{
    {
        ifstream inputFile;
        /* NOTE: Possibly opening a file without validating the file name or path */
        inputFile.open((char *)data);
        inputFile.close();
    }
}

}
#endif /* OMITCASE1 */
