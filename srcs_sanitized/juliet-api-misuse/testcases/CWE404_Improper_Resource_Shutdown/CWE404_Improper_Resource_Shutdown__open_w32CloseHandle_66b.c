/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_66b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-66b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using open()
 * Sinks: w32CloseHandle
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Close the file using CloseHandle
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
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

#ifndef OMITCASE0

void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_66b_case0Sink(int dataArray[])
{
    /* copy data out of dataArray */
    int data = dataArray[2];
    if (data != -1)
    {
        /* NOTE: Attempt to close the file using CloseHandle() instead of close() */
        CloseHandle((HANDLE)data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_66b_case1V2Sink(int dataArray[])
{
    int data = dataArray[2];
    if (data != -1)
    {
        /* ALT: Close the file using close() */
        CLOSE(data);
    }
}

#endif /* OMITCASE1 */
