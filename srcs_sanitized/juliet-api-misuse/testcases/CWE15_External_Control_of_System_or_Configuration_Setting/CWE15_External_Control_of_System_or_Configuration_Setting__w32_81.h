/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE15_External_Control_of_System_or_Configuration_Setting__w32_81.h
Label Definition File: CWE15_External_Control_of_System_or_Configuration_Setting__w32.label.xml
Template File: sources-sink-81.tmpl.h
*/
/*
 * @description
 * CWE: 15 External Control of System or Configuration Setting
 * Case0Source:  Get the hostname from a network socket
 * Case1Source: Get the hostname from a string literal
 * Sinks:
 *    Case0Sink : Set the hostname
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

namespace CWE15_External_Control_of_System_or_Configuration_Setting__w32_81
{

class CWE15_External_Control_of_System_or_Configuration_Setting__w32_81_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) const = 0;
};

#ifndef OMITCASE0

class CWE15_External_Control_of_System_or_Configuration_Setting__w32_81_case0 : public CWE15_External_Control_of_System_or_Configuration_Setting__w32_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE15_External_Control_of_System_or_Configuration_Setting__w32_81_case1V1 : public CWE15_External_Control_of_System_or_Configuration_Setting__w32_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE1 */

}
