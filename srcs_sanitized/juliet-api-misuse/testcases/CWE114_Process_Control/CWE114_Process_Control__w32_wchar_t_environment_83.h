/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_environment_83.h
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 114 Process Control
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Hard code the full pathname to the library
 * Sinks:
 *    Case0Sink : Load a dynamic link library
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE114_Process_Control__w32_wchar_t_environment_83
{

#ifndef OMITCASE0

class CWE114_Process_Control__w32_wchar_t_environment_83_case0
{
public:
    CWE114_Process_Control__w32_wchar_t_environment_83_case0(wchar_t * dataCopy);
    ~CWE114_Process_Control__w32_wchar_t_environment_83_case0();

private:
    wchar_t * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE114_Process_Control__w32_wchar_t_environment_83_case1V1
{
public:
    CWE114_Process_Control__w32_wchar_t_environment_83_case1V1(wchar_t * dataCopy);
    ~CWE114_Process_Control__w32_wchar_t_environment_83_case1V1();

private:
    wchar_t * data;
};

#endif /* OMITCASE1 */

}
