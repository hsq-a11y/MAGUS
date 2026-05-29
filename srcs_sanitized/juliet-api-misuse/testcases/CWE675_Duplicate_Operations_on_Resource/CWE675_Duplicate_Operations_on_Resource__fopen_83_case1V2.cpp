/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_83_case1V2.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-83_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: fopen Open and close a file using fopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE675_Duplicate_Operations_on_Resource__fopen_83.h"

namespace CWE675_Duplicate_Operations_on_Resource__fopen_83
{
CWE675_Duplicate_Operations_on_Resource__fopen_83_case1V2::CWE675_Duplicate_Operations_on_Resource__fopen_83_case1V2(FILE * dataCopy)
{
    data = dataCopy;
    data = fopen("Case0Source_fopen.txt", "w+");
    /* NOTE: Close the file in the source */
    fclose(data);
}

CWE675_Duplicate_Operations_on_Resource__fopen_83_case1V2::~CWE675_Duplicate_Operations_on_Resource__fopen_83_case1V2()
{
    /* Do nothing */
    /* ALT: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}
}
#endif /* OMITCASE1 */
