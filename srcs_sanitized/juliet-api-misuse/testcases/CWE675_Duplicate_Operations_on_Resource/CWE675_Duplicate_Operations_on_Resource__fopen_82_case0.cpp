/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_82_case0.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-82_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: fopen Open and close a file using fopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE675_Duplicate_Operations_on_Resource__fopen_82.h"

namespace CWE675_Duplicate_Operations_on_Resource__fopen_82
{

void CWE675_Duplicate_Operations_on_Resource__fopen_82_case0::action(FILE * data)
{
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

}
#endif /* OMITCASE0 */
