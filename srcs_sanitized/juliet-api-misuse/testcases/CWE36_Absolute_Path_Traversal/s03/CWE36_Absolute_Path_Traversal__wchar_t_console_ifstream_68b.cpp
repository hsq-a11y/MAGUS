/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_console_ifstream_68b.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * Case0Source: console Read input from the console
 * Case1Source: Full path and file name
 * Sink: ifstream
 *    Case0Sink : Open the file named in data using ifstream::open()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#include <fstream>
using namespace std;

extern wchar_t * CWE36_Absolute_Path_Traversal__wchar_t_console_ifstream_68_case0Data;
extern wchar_t * CWE36_Absolute_Path_Traversal__wchar_t_console_ifstream_68_case1V1Data;

namespace CWE36_Absolute_Path_Traversal__wchar_t_console_ifstream_68
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

void case0Sink()
{
    wchar_t * data = CWE36_Absolute_Path_Traversal__wchar_t_console_ifstream_68_case0Data;
    {
        ifstream inputFile;
        /* NOTE: Possibly opening a file without validating the file name or path */
        inputFile.open((char *)data);
        inputFile.close();
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink()
{
    wchar_t * data = CWE36_Absolute_Path_Traversal__wchar_t_console_ifstream_68_case1V1Data;
    {
        ifstream inputFile;
        /* NOTE: Possibly opening a file without validating the file name or path */
        inputFile.open((char *)data);
        inputFile.close();
    }
}

#endif /* OMITCASE1 */

} /* close namespace */
