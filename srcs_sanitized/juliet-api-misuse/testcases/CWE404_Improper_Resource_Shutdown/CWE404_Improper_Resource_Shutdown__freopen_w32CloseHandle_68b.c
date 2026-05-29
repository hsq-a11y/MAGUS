/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68b.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: freopen Open a file using freopen()
 * Sinks: w32CloseHandle
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using CloseHandle
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

extern FILE * CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68_case0DataForCase0Sink;

extern FILE * CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68_case0DataForCase1Sink;

#ifndef OMITCASE0

void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68b_case0Sink()
{
    FILE * data = CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68_case0DataForCase0Sink;
    if (data != NULL)
    {
        /* NOTE: Attempt to close the file using CloseHandle() instead of fclose() */
        CloseHandle((HANDLE)data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68b_case1V2Sink()
{
    FILE * data = CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68_case0DataForCase1Sink;
    if (data != NULL)
    {
        /* ALT: Close the file using fclose() */
        fclose(data);
    }
}

#endif /* OMITCASE1 */
