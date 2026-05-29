/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_console_ofstream_81_case0.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * Case0Source: console Read input from the console
 * Case1Source: Use a fixed file name
 * Sinks: ofstream
 *    Case0Sink : Open the file named in data using ofstream::open()
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE23_Relative_Path_Traversal__char_console_ofstream_81.h"

#include <fstream>
using namespace std;

namespace CWE23_Relative_Path_Traversal__char_console_ofstream_81
{

void CWE23_Relative_Path_Traversal__char_console_ofstream_81_case0::action(char * data) const
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
