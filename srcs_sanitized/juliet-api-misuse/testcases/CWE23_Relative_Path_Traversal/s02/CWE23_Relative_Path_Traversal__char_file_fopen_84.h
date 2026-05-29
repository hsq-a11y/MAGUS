/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_file_fopen_84.h
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-84.tmpl.h
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * Case0Source: file Read input from a file
 * Case1Source: Use a fixed file name
 * Sinks: fopen
 *    Case0Sink : Open the file named in data using fopen()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH "c:\\temp\\"
#else
#include <wchar.h>
#define BASEPATH "/tmp/"
#endif

namespace CWE23_Relative_Path_Traversal__char_file_fopen_84
{

#ifndef OMITCASE0

class CWE23_Relative_Path_Traversal__char_file_fopen_84_case0
{
public:
    CWE23_Relative_Path_Traversal__char_file_fopen_84_case0(char * dataCopy);
    ~CWE23_Relative_Path_Traversal__char_file_fopen_84_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE23_Relative_Path_Traversal__char_file_fopen_84_case1V1
{
public:
    CWE23_Relative_Path_Traversal__char_file_fopen_84_case1V1(char * dataCopy);
    ~CWE23_Relative_Path_Traversal__char_file_fopen_84_case1V1();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
