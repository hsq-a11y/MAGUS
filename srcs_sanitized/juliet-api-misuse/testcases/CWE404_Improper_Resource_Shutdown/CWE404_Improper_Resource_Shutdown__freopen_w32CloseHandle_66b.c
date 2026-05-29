/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_66b.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-66b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: freopen Open a file using freopen()
 * Sinks: w32CloseHandle
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using CloseHandle
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITCASE0

void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_66b_case0Sink(FILE * dataArray[])
{
    /* copy data out of dataArray */
    FILE * data = dataArray[2];
    if (data != NULL)
    {
        /* NOTE: Attempt to close the file using CloseHandle() instead of fclose() */
        CloseHandle((HANDLE)data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_66b_case1V2Sink(FILE * dataArray[])
{
    FILE * data = dataArray[2];
    if (data != NULL)
    {
        /* ALT: Close the file using fclose() */
        fclose(data);
    }
}

#endif /* OMITCASE1 */
