/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_52c.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-52c.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using CreateFile()
 * Sinks: fclose
 *    Case1Sink: Close the file using CloseHandle()
 *    Case0Sink : Close the file using fclose()
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITCASE0

void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_52c_case0Sink(HANDLE data)
{
    if (data != INVALID_HANDLE_VALUE)
    {
        /* NOTE: Attempt to close the file using fclose() instead of CloseHandle() */
        fclose((FILE *)data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_52c_case1V2Sink(HANDLE data)
{
    if (data != INVALID_HANDLE_VALUE)
    {
        /* ALT: Close the file using CloseHandle() */
        CloseHandle(data);
    }
}

#endif /* OMITCASE1 */
