/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_file_system_81.h
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-81.tmpl.h
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: file Read input from a file
 * Case1Source: Fixed string
 * Sinks: system
 *    Case0Sink : Execute command in data using system()
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FULL_COMMAND "dir "
#else
#include <unistd.h>
#define FULL_COMMAND "ls "
#endif

namespace CWE78_OS_Command_Injection__char_file_system_81
{

class CWE78_OS_Command_Injection__char_file_system_81_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) const = 0;
};

#ifndef OMITCASE0

class CWE78_OS_Command_Injection__char_file_system_81_case0 : public CWE78_OS_Command_Injection__char_file_system_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE78_OS_Command_Injection__char_file_system_81_case1V1 : public CWE78_OS_Command_Injection__char_file_system_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE1 */

}
