/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__fopen_53d.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-53d.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: fopen Open data with fopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

void CWE690_NULL_Deref_From_Return__fopen_53d_case0Sink(FILE * data)
{
    /* NOTE: if the fopen failed, data will be NULL here */
    fclose(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

void CWE690_NULL_Deref_From_Return__fopen_53d_case1V2Sink(FILE * data)
{
    /* ALT: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

#endif /* OMITCASE1 */
