/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84_case0.cpp
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-84_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using CreateFile()
 * Sinks: close
 *    Case1Sink: Close the file using CloseHandle()
 *    Case0Sink : Close the file using close()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84.h"

namespace CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84
{
CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84_case0::CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84_case0(HANDLE dataCopy)
{
    data = dataCopy;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = CreateFile("Case0Source_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
}

CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84_case0::~CWE404_Improper_Resource_Shutdown__w32CreateFile_close_84_case0()
{
    if (data != INVALID_HANDLE_VALUE)
    {
        /* NOTE: Attempt to close the file using close() instead of CloseHandle() */
        _close((int)data);
    }
}
}
#endif /* OMITCASE0 */
