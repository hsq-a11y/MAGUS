/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__char_system_83_case1V1.cpp
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * Case0Source:  Don't specify the full path in the OS command
 * Case1Source: Specify the full path in the OS command
 * Sinks: system
 *    Case0Sink : Execute the system function
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE426_Untrusted_Search_Path__char_system_83.h"

#ifdef _WIN32
#define SYSTEM system
#else /* NOT _WIN32 */
#define SYSTEM system
#endif

namespace CWE426_Untrusted_Search_Path__char_system_83
{
CWE426_Untrusted_Search_Path__char_system_83_case1V1::CWE426_Untrusted_Search_Path__char_system_83_case1V1(char * dataCopy)
{
    data = dataCopy;
    /* ALT: full path is specified */
    strcpy(data, CASE1_OS_COMMAND);
}

CWE426_Untrusted_Search_Path__char_system_83_case1V1::~CWE426_Untrusted_Search_Path__char_system_83_case1V1()
{
    /* NOTE: Executing the system() function without specifying the full path to the executable
     * can allow an attacker to run their own program */
    if (SYSTEM(data) <= 0)
    {
        printLine("command execution failed!");
        exit(1);
    }
}
}
#endif /* OMITCASE1 */
