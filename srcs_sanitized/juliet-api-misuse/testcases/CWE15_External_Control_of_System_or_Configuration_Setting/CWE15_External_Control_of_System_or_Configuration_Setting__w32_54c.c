/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE15_External_Control_of_System_or_Configuration_Setting__w32_54c.c
Label Definition File: CWE15_External_Control_of_System_or_Configuration_Setting__w32.label.xml
Template File: sources-sink-54c.tmpl.c
*/
/*
 * @description
 * CWE: 15 External Control of System or Configuration Setting
 * Case0Source:  Get the hostname from a network socket
 * Case1Source: Get the hostname from a string literal
 * Sink:
 *    Case0Sink : Set the hostname
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <winsock2.h>
#pragma comment(lib, "ws2_32")

#define LISTEN_PORT 999
#define LISTEN_BACKLOG 5

#include <windows.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE15_External_Control_of_System_or_Configuration_Setting__w32_54d_case0Sink(char * data);

void CWE15_External_Control_of_System_or_Configuration_Setting__w32_54c_case0Sink(char * data)
{
    CWE15_External_Control_of_System_or_Configuration_Setting__w32_54d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE15_External_Control_of_System_or_Configuration_Setting__w32_54d_case1V1Sink(char * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE15_External_Control_of_System_or_Configuration_Setting__w32_54c_case1V1Sink(char * data)
{
    CWE15_External_Control_of_System_or_Configuration_Setting__w32_54d_case1V1Sink(data);
}

#endif /* OMITCASE1 */
