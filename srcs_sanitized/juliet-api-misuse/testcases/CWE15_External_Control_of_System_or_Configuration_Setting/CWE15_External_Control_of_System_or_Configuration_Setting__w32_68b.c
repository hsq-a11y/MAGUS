/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE15_External_Control_of_System_or_Configuration_Setting__w32_68b.c
Label Definition File: CWE15_External_Control_of_System_or_Configuration_Setting__w32.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 15 External Control of System or Configuration Setting
 * Case0Source:  Get the hostname from a network socket
 * Case1Source: Get the hostname from a string literal
 * Sink:
 *    Case0Sink : Set the hostname
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <winsock2.h>
#pragma comment(lib, "ws2_32")

#define LISTEN_PORT 999
#define LISTEN_BACKLOG 5

#include <windows.h>

extern char * CWE15_External_Control_of_System_or_Configuration_Setting__w32_68_case0Data;
extern char * CWE15_External_Control_of_System_or_Configuration_Setting__w32_68_case1V1Data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

void CWE15_External_Control_of_System_or_Configuration_Setting__w32_68b_case0Sink()
{
    char * data = CWE15_External_Control_of_System_or_Configuration_Setting__w32_68_case0Data;
    /* NOTE: set the hostname to data obtained from a potentially external source */
    if (!SetComputerNameA(data))
    {
        printLine("Failure setting computer name");
        exit(1);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE15_External_Control_of_System_or_Configuration_Setting__w32_68b_case1V1Sink()
{
    char * data = CWE15_External_Control_of_System_or_Configuration_Setting__w32_68_case1V1Data;
    /* NOTE: set the hostname to data obtained from a potentially external source */
    if (!SetComputerNameA(data))
    {
        printLine("Failure setting computer name");
        exit(1);
    }
}

#endif /* OMITCASE1 */
