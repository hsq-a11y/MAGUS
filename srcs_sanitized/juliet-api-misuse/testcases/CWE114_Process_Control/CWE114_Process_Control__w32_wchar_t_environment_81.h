/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_environment_81.h
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-81.tmpl.h
*/
/*
 * @description
 * CWE: 114 Process Control
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Hard code the full pathname to the library
 * Sinks:
 *    Case0Sink : Load a dynamic link library
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE114_Process_Control__w32_wchar_t_environment_81
{

class CWE114_Process_Control__w32_wchar_t_environment_81_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) const = 0;
};

#ifndef OMITCASE0

class CWE114_Process_Control__w32_wchar_t_environment_81_case0 : public CWE114_Process_Control__w32_wchar_t_environment_81_base
{
public:
    void action(wchar_t * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE114_Process_Control__w32_wchar_t_environment_81_case1V1 : public CWE114_Process_Control__w32_wchar_t_environment_81_base
{
public:
    void action(wchar_t * data) const;
};

#endif /* OMITCASE1 */

}
