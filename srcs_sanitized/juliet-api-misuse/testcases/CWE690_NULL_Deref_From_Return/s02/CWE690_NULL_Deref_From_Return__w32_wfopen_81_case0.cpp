/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_81_case0.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE690_NULL_Deref_From_Return__w32_wfopen_81.h"

namespace CWE690_NULL_Deref_From_Return__w32_wfopen_81
{

void CWE690_NULL_Deref_From_Return__w32_wfopen_81_case0::action(FILE * data) const
{
    /* NOTE: if the fopen failed, data will be NULL here */
    fclose(data);
}

}
#endif /* OMITCASE0 */
