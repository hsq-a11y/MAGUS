/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32_close_22b.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: fopen Open a file using fopen()
 * Sinks: w32_close
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using close()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
extern int CWE404_Improper_Resource_Shutdown__fopen_w32_close_22_case0Global;

void CWE404_Improper_Resource_Shutdown__fopen_w32_close_22_case0Sink(FILE * data)
{
    if(CWE404_Improper_Resource_Shutdown__fopen_w32_close_22_case0Global)
    {
        if (data != NULL)
        {
            /* NOTE: Attempt to close the file using close() instead of fclose() */
            _close((int)data);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE404_Improper_Resource_Shutdown__fopen_w32_close_22_case1V21Global;
extern int CWE404_Improper_Resource_Shutdown__fopen_w32_close_22_case1V22Global;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE404_Improper_Resource_Shutdown__fopen_w32_close_22_case1V21Sink(FILE * data)
{
    if(CWE404_Improper_Resource_Shutdown__fopen_w32_close_22_case1V21Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        if (data != NULL)
        {
            /* ALT: Close the file using fclose() */
            fclose(data);
        }
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE404_Improper_Resource_Shutdown__fopen_w32_close_22_case1V22Sink(FILE * data)
{
    if(CWE404_Improper_Resource_Shutdown__fopen_w32_close_22_case1V22Global)
    {
        if (data != NULL)
        {
            /* ALT: Close the file using fclose() */
            fclose(data);
        }
    }
}

#endif /* OMITCASE1 */
