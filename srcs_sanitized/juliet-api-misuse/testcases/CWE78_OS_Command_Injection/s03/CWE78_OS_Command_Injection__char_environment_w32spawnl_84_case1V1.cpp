/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_environment_w32spawnl_84_case1V1.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Fixed string
 * Sinks: w32spawnl
 *    Case0Sink : execute command with spawnl
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__char_environment_w32spawnl_84.h"

#include <process.h>

namespace CWE78_OS_Command_Injection__char_environment_w32spawnl_84
{
CWE78_OS_Command_Injection__char_environment_w32spawnl_84_case1V1::CWE78_OS_Command_Injection__char_environment_w32spawnl_84_case1V1(char * dataCopy)
{
    data = dataCopy;
    /* ALT: Append a fixed string to data (not user / external input) */
    strcat(data, "*.*");
}

CWE78_OS_Command_Injection__char_environment_w32spawnl_84_case1V1::~CWE78_OS_Command_Injection__char_environment_w32spawnl_84_case1V1()
{
    /* spawnl - specify the path where the command is located */
    /* NOTE: Execute command without validating input possibly leading to command injection */
    _spawnl(_P_WAIT, COMMAND_INT_PATH, COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL);
}
}
#endif /* OMITCASE1 */
