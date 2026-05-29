/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_63b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-63b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using open()
 * Sinks: w32CloseHandle
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Close the file using CloseHandle
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
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

void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_63b_case0Sink(int * dataPtr)
{
    int data = *dataPtr;
    if (data != -1)
    {
        /* NOTE: Attempt to close the file using CloseHandle() instead of close() */
        CloseHandle((HANDLE)data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_63b_case1V2Sink(int * dataPtr)
{
    int data = *dataPtr;
    if (data != -1)
    {
        /* ALT: Close the file using close() */
        CLOSE(data);
    }
}

#endif /* OMITCASE1 */
