/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE15_External_Control_of_System_or_Configuration_Setting__w32_83_case1V1.cpp
Label Definition File: CWE15_External_Control_of_System_or_Configuration_Setting__w32.label.xml
Template File: sources-sink-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 15 External Control of System or Configuration Setting
 * Case0Source:  Get the hostname from a network socket
 * Case1Source: Get the hostname from a string literal
 * Sinks:
 *    Case0Sink : Set the hostname
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE15_External_Control_of_System_or_Configuration_Setting__w32_83.h"

#include <windows.h>

namespace CWE15_External_Control_of_System_or_Configuration_Setting__w32_83
{
CWE15_External_Control_of_System_or_Configuration_Setting__w32_83_case1V1::CWE15_External_Control_of_System_or_Configuration_Setting__w32_83_case1V1(char * dataCopy)
{
    data = dataCopy;
    /* ALT: get the hostname from a string literal */
    strcpy(data, "hostname");
}

CWE15_External_Control_of_System_or_Configuration_Setting__w32_83_case1V1::~CWE15_External_Control_of_System_or_Configuration_Setting__w32_83_case1V1()
{
    /* NOTE: set the hostname to data obtained from a potentially external source */
    if (!SetComputerNameA(data))
    {
        printLine("Failure setting computer name");
        exit(1);
    }
}
}
#endif /* OMITCASE1 */
