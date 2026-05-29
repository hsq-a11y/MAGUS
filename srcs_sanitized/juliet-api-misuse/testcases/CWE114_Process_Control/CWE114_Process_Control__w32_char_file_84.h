/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_file_84.h
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-84.tmpl.h
*/
/*
 * @description
 * CWE: 114 Process Control
 * Case0Source: file Read input from a file
 * Case1Source: Hard code the full pathname to the library
 * Sinks:
 *    Case0Sink : Load a dynamic link library
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE114_Process_Control__w32_char_file_84
{

#ifndef OMITCASE0

class CWE114_Process_Control__w32_char_file_84_case0
{
public:
    CWE114_Process_Control__w32_char_file_84_case0(char * dataCopy);
    ~CWE114_Process_Control__w32_char_file_84_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE114_Process_Control__w32_char_file_84_case1V1
{
public:
    CWE114_Process_Control__w32_char_file_84_case1V1(char * dataCopy);
    ~CWE114_Process_Control__w32_char_file_84_case1V1();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
