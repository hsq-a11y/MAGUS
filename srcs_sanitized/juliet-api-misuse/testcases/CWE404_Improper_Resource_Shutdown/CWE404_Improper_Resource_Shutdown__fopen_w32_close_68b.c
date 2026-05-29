/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32_close_68b.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: fopen Open a file using fopen()
 * Sinks: w32_close
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using close()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern FILE * CWE404_Improper_Resource_Shutdown__fopen_w32_close_68_case0DataForCase0Sink;

extern FILE * CWE404_Improper_Resource_Shutdown__fopen_w32_close_68_case0DataForCase1Sink;

#ifndef OMITCASE0

void CWE404_Improper_Resource_Shutdown__fopen_w32_close_68b_case0Sink()
{
    FILE * data = CWE404_Improper_Resource_Shutdown__fopen_w32_close_68_case0DataForCase0Sink;
    if (data != NULL)
    {
        /* NOTE: Attempt to close the file using close() instead of fclose() */
        _close((int)data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

void CWE404_Improper_Resource_Shutdown__fopen_w32_close_68b_case1V2Sink()
{
    FILE * data = CWE404_Improper_Resource_Shutdown__fopen_w32_close_68_case0DataForCase1Sink;
    if (data != NULL)
    {
        /* ALT: Close the file using fclose() */
        fclose(data);
    }
}

#endif /* OMITCASE1 */
