/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE15_External_Control_of_System_or_Configuration_Setting__w32_61a.c
Label Definition File: CWE15_External_Control_of_System_or_Configuration_Setting__w32.label.xml
Template File: sources-sink-61a.tmpl.c
*/
/*
 * @description
 * CWE: 15 External Control of System or Configuration Setting
 * Case0Source:  Get the hostname from a network socket
 * Case1Source: Get the hostname from a string literal
 * Sinks:
 *    Case0Sink : Set the hostname
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <winsock2.h>
#pragma comment(lib, "ws2_32")

#define LISTEN_PORT 999
#define LISTEN_BACKLOG 5

#include <windows.h>

#ifndef OMITCASE0

/* case0 function declaration */
char * CWE15_External_Control_of_System_or_Configuration_Setting__w32_61b_case0Source(char * data);

void CWE15_External_Control_of_System_or_Configuration_Setting__w32_61_case0()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    data = CWE15_External_Control_of_System_or_Configuration_Setting__w32_61b_case0Source(data);
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
char * CWE15_External_Control_of_System_or_Configuration_Setting__w32_61b_case1V1Source(char * data);

static void case1V1()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    data = CWE15_External_Control_of_System_or_Configuration_Setting__w32_61b_case1V1Source(data);
    /* NOTE: set the hostname to data obtained from a potentially external source */
    if (!SetComputerNameA(data))
    {
        printLine("Failure setting computer name");
        exit(1);
    }
}

void CWE15_External_Control_of_System_or_Configuration_Setting__w32_61_case1()
{
    case1V1();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE15_External_Control_of_System_or_Configuration_Setting__w32_61_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE15_External_Control_of_System_or_Configuration_Setting__w32_61_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
