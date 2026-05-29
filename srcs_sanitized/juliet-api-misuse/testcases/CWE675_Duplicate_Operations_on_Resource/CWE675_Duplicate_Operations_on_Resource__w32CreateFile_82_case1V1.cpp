/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__w32CreateFile_82_case1V1.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource__w32CreateFile.label.xml
Template File: sources-sinks-82_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source:  Open and close a file using CreateFile() and CloseHandle()
 * Case1Source: Open a file using CreateFile()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE675_Duplicate_Operations_on_Resource__w32CreateFile_82.h"

namespace CWE675_Duplicate_Operations_on_Resource__w32CreateFile_82
{

void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_82_case1V1::action(HANDLE data)
{
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    CloseHandle(data);
}

}
#endif /* OMITCASE1 */
