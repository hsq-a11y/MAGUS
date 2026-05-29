/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_console_ofstream_82.h
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-82.tmpl.h
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * Case0Source: console Read input from the console
 * Case1Source: Use a fixed file name
 * Sinks: ofstream
 *    Case0Sink : Open the file named in data using ofstream::open()
 * Flow Variant: 82 Data flow: data passed in a parameter to a virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH "c:\\temp\\"
#else
#include <wchar.h>
#define BASEPATH "/tmp/"
#endif

namespace CWE23_Relative_Path_Traversal__char_console_ofstream_82
{

class CWE23_Relative_Path_Traversal__char_console_ofstream_82_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) = 0;
};

#ifndef OMITCASE0

class CWE23_Relative_Path_Traversal__char_console_ofstream_82_case0 : public CWE23_Relative_Path_Traversal__char_console_ofstream_82_base
{
public:
    void action(char * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE23_Relative_Path_Traversal__char_console_ofstream_82_case1V1 : public CWE23_Relative_Path_Traversal__char_console_ofstream_82_base
{
public:
    void action(char * data);
};

#endif /* OMITCASE1 */

}
