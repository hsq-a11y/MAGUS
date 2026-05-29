/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using CreateFile()
 * Sinks: close
 *    Case1Sink: Close the file using CloseHandle()
 *    Case0Sink : Close the file using close()
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITCASE0

/* case0 function declaration */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53c_case0Sink(HANDLE data);

void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53b_case0Sink(HANDLE data)
{
    CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53c_case1V2Sink(HANDLE data);

void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53b_case1V2Sink(HANDLE data)
{
    CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
