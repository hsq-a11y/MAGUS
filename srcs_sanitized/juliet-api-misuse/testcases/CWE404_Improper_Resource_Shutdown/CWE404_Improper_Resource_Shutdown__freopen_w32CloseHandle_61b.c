/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_61b.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: freopen Open a file using freopen()
 * Sinks: w32CloseHandle
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using CloseHandle
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITCASE0

FILE * CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_61b_case0Source(FILE * data)
{
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = freopen("Case0Source_freopen.txt","w+",stdin);
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() uses the Case0Source with the Case1Sink */
FILE * CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_61b_case1V2Source(FILE * data)
{
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = freopen("Case0Source_freopen.txt","w+",stdin);
    return data;
}

#endif /* OMITCASE1 */
