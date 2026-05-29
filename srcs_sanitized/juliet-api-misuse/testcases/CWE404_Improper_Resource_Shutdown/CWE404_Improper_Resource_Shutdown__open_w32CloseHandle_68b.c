/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using open()
 * Sinks: w32CloseHandle
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Close the file using CloseHandle
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define OPEN _open
#define CLOSE _close
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#endif

#include <windows.h>

extern int CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68_case0DataForCase0Sink;

extern int CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68_case0DataForCase1Sink;

#ifndef OMITCASE0

void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68b_case0Sink()
{
    int data = CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68_case0DataForCase0Sink;
    if (data != -1)
    {
        /* NOTE: Attempt to close the file using CloseHandle() instead of close() */
        CloseHandle((HANDLE)data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68b_case1V2Sink()
{
    int data = CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_68_case0DataForCase1Sink;
    if (data != -1)
    {
        /* ALT: Close the file using close() */
        CLOSE(data);
    }
}

#endif /* OMITCASE1 */
