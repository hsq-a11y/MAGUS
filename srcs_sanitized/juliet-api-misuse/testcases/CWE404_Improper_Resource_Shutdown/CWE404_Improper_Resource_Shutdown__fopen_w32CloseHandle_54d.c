/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54d.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: fopen Open a file using fopen()
 * Sinks: w32CloseHandle
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using CloseHandle
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITCASE0

/* case0 function declaration */
void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54e_case0Sink(FILE * data);

void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54d_case0Sink(FILE * data)
{
    CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54e_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54e_case1V2Sink(FILE * data);

void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54d_case1V2Sink(FILE * data)
{
    CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_54e_case1V2Sink(data);
}

#endif /* OMITCASE1 */
