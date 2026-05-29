/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__w32CreateFile_84_case1V1.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource__w32CreateFile.label.xml
Template File: sources-sinks-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source:  Open and close a file using CreateFile() and CloseHandle()
 * Case1Source: Open a file using CreateFile()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE675_Duplicate_Operations_on_Resource__w32CreateFile_84.h"

namespace CWE675_Duplicate_Operations_on_Resource__w32CreateFile_84
{
CWE675_Duplicate_Operations_on_Resource__w32CreateFile_84_case1V1::CWE675_Duplicate_Operations_on_Resource__w32CreateFile_84_case1V1(HANDLE dataCopy)
{
    data = dataCopy;
    /* ALT: Open, but do not close the file in the source */
    data = CreateFile("Case1Source_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
}

CWE675_Duplicate_Operations_on_Resource__w32CreateFile_84_case1V1::~CWE675_Duplicate_Operations_on_Resource__w32CreateFile_84_case1V1()
{
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    CloseHandle(data);
}
}
#endif /* OMITCASE1 */
