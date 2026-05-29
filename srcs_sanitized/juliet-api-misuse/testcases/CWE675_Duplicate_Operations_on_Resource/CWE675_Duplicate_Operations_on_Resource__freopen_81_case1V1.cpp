/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__freopen_81_case1V1.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-81_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: freopen Open and close a file using freopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE675_Duplicate_Operations_on_Resource__freopen_81.h"

namespace CWE675_Duplicate_Operations_on_Resource__freopen_81
{

void CWE675_Duplicate_Operations_on_Resource__freopen_81_case1V1::action(FILE * data) const
{
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

}
#endif /* OMITCASE1 */
