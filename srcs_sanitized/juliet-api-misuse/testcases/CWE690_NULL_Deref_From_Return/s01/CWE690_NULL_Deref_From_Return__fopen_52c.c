/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__fopen_52c.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-52c.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: fopen Open data with fopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

void CWE690_NULL_Deref_From_Return__fopen_52c_case0Sink(FILE * data)
{
    /* NOTE: if the fopen failed, data will be NULL here */
    fclose(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

void CWE690_NULL_Deref_From_Return__fopen_52c_case1V2Sink(FILE * data)
{
    /* ALT: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

#endif /* OMITCASE1 */
