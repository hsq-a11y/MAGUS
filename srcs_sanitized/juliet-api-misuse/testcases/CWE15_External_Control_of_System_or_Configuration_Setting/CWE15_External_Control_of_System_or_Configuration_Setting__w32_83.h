/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE15_External_Control_of_System_or_Configuration_Setting__w32_83.h
Label Definition File: CWE15_External_Control_of_System_or_Configuration_Setting__w32.label.xml
Template File: sources-sink-83.tmpl.h
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

#include "std_testcase.h"

namespace CWE15_External_Control_of_System_or_Configuration_Setting__w32_83
{

#ifndef OMITCASE0

class CWE15_External_Control_of_System_or_Configuration_Setting__w32_83_case0
{
public:
    CWE15_External_Control_of_System_or_Configuration_Setting__w32_83_case0(char * dataCopy);
    ~CWE15_External_Control_of_System_or_Configuration_Setting__w32_83_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE15_External_Control_of_System_or_Configuration_Setting__w32_83_case1V1
{
public:
    CWE15_External_Control_of_System_or_Configuration_Setting__w32_83_case1V1(char * dataCopy);
    ~CWE15_External_Control_of_System_or_Configuration_Setting__w32_83_case1V1();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
