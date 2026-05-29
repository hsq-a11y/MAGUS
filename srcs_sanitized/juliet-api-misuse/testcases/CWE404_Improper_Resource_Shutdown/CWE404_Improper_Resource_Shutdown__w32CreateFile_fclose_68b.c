/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using CreateFile()
 * Sinks: fclose
 *    Case1Sink: Close the file using CloseHandle()
 *    Case0Sink : Close the file using fclose()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

extern HANDLE CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68_case0DataForCase0Sink;

extern HANDLE CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68_case0DataForCase1Sink;

#ifndef OMITCASE0

void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68b_case0Sink()
{
    HANDLE data = CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68_case0DataForCase0Sink;
    if (data != INVALID_HANDLE_VALUE)
    {
        /* NOTE: Attempt to close the file using fclose() instead of CloseHandle() */
        fclose((FILE *)data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68b_case1V2Sink()
{
    HANDLE data = CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68_case0DataForCase1Sink;
    if (data != INVALID_HANDLE_VALUE)
    {
        /* ALT: Close the file using CloseHandle() */
        CloseHandle(data);
    }
}

#endif /* OMITCASE1 */
