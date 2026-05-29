/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_82_case1V2.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-82_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE690_NULL_Deref_From_Return__w32_wfopen_82.h"

namespace CWE690_NULL_Deref_From_Return__w32_wfopen_82
{

void CWE690_NULL_Deref_From_Return__w32_wfopen_82_case1V2::action(FILE * data)
{
    /* ALT: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

}
#endif /* OMITCASE1 */
