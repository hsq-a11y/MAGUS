/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_65b.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-65b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: freopen Open a file using freopen()
 * Sinks: w32CloseHandle
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using CloseHandle
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITCASE0

void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_65b_case0Sink(FILE * data)
{
    if (data != NULL)
    {
        /* NOTE: Attempt to close the file using CloseHandle() instead of fclose() */
        CloseHandle((HANDLE)data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_65b_case1V2Sink(FILE * data)
{
    if (data != NULL)
    {
        /* ALT: Close the file using fclose() */
        fclose(data);
    }
}

#endif /* OMITCASE1 */
