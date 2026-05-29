/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__fopen_81_case1V2.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-81_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: fopen Open data with fopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE690_NULL_Deref_From_Return__fopen_81.h"

namespace CWE690_NULL_Deref_From_Return__fopen_81
{

void CWE690_NULL_Deref_From_Return__fopen_81_case1V2::action(FILE * data) const
{
    /* ALT: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

}
#endif /* OMITCASE1 */
