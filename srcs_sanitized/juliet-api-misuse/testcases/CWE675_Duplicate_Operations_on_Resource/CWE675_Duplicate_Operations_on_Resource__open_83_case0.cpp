/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__open_83_case0.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource__open.label.xml
Template File: sources-sinks-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source:  Open and close a file using open() and close()
 * Case1Source: Open a file using open()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE675_Duplicate_Operations_on_Resource__open_83.h"

namespace CWE675_Duplicate_Operations_on_Resource__open_83
{
CWE675_Duplicate_Operations_on_Resource__open_83_case0::CWE675_Duplicate_Operations_on_Resource__open_83_case0(int dataCopy)
{
    data = dataCopy;
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    /* NOTE: Close the file in the source */
    CLOSE(data);
}

CWE675_Duplicate_Operations_on_Resource__open_83_case0::~CWE675_Duplicate_Operations_on_Resource__open_83_case0()
{
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    CLOSE(data);
}
}
#endif /* OMITCASE0 */
