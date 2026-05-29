/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_close_82_case0.cpp
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-82_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using CreateFile()
 * Sinks: close
 *    Case1Sink: Close the file using CloseHandle()
 *    Case0Sink : Close the file using close()
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE404_Improper_Resource_Shutdown__w32CreateFile_close_82.h"

namespace CWE404_Improper_Resource_Shutdown__w32CreateFile_close_82
{

void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_82_case0::action(HANDLE data)
{
    if (data != INVALID_HANDLE_VALUE)
    {
        /* NOTE: Attempt to close the file using close() instead of CloseHandle() */
        _close((int)data);
    }
}

}
#endif /* OMITCASE0 */
