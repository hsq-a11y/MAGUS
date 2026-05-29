/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32_close_52b.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: freopen Open a file using freopen()
 * Sinks: w32_close
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using close()
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE404_Improper_Resource_Shutdown__freopen_w32_close_52c_case0Sink(FILE * data);

void CWE404_Improper_Resource_Shutdown__freopen_w32_close_52b_case0Sink(FILE * data)
{
    CWE404_Improper_Resource_Shutdown__freopen_w32_close_52c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE404_Improper_Resource_Shutdown__freopen_w32_close_52c_case1V2Sink(FILE * data);

void CWE404_Improper_Resource_Shutdown__freopen_w32_close_52b_case1V2Sink(FILE * data)
{
    CWE404_Improper_Resource_Shutdown__freopen_w32_close_52c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
