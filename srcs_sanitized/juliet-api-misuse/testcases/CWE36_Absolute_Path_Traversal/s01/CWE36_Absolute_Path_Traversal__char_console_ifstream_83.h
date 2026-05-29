/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_console_ifstream_83.h
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * Case0Source: console Read input from the console
 * Case1Source: Full path and file name
 * Sinks: ifstream
 *    Case0Sink : Open the file named in data using ifstream::open()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE36_Absolute_Path_Traversal__char_console_ifstream_83
{

#ifndef OMITCASE0

class CWE36_Absolute_Path_Traversal__char_console_ifstream_83_case0
{
public:
    CWE36_Absolute_Path_Traversal__char_console_ifstream_83_case0(char * dataCopy);
    ~CWE36_Absolute_Path_Traversal__char_console_ifstream_83_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE36_Absolute_Path_Traversal__char_console_ifstream_83_case1V1
{
public:
    CWE36_Absolute_Path_Traversal__char_console_ifstream_83_case1V1(char * dataCopy);
    ~CWE36_Absolute_Path_Traversal__char_console_ifstream_83_case1V1();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
