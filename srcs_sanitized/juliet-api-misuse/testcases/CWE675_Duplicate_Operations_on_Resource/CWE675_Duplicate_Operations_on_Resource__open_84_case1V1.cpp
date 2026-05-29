/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__open_84_case1V1.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource__open.label.xml
Template File: sources-sinks-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source:  Open and close a file using open() and close()
 * Case1Source: Open a file using open()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE675_Duplicate_Operations_on_Resource__open_84.h"

namespace CWE675_Duplicate_Operations_on_Resource__open_84
{
CWE675_Duplicate_Operations_on_Resource__open_84_case1V1::CWE675_Duplicate_Operations_on_Resource__open_84_case1V1(int dataCopy)
{
    data = dataCopy;
    /* ALT: Open, but do not close the file in the source */
    data = OPEN("Case1Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
}

CWE675_Duplicate_Operations_on_Resource__open_84_case1V1::~CWE675_Duplicate_Operations_on_Resource__open_84_case1V1()
{
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    CLOSE(data);
}
}
#endif /* OMITCASE1 */
