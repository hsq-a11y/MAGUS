/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32_close_53d.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-53d.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: fopen Open a file using fopen()
 * Sinks: w32_close
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using close()
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

void CWE404_Improper_Resource_Shutdown__fopen_w32_close_53d_case0Sink(FILE * data)
{
    if (data != NULL)
    {
        /* NOTE: Attempt to close the file using close() instead of fclose() */
        _close((int)data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

void CWE404_Improper_Resource_Shutdown__fopen_w32_close_53d_case1V2Sink(FILE * data)
{
    if (data != NULL)
    {
        /* ALT: Close the file using fclose() */
        fclose(data);
    }
}

#endif /* OMITCASE1 */
