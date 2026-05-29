/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_close_67b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using CreateFile()
 * Sinks: close
 *    Case1Sink: Close the file using CloseHandle()
 *    Case0Sink : Close the file using close()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

typedef struct _CWE404_Improper_Resource_Shutdown__w32CreateFile_close_67_structType
{
    HANDLE structFirst;
} CWE404_Improper_Resource_Shutdown__w32CreateFile_close_67_structType;

#ifndef OMITCASE0

void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_67b_case0Sink(CWE404_Improper_Resource_Shutdown__w32CreateFile_close_67_structType myStruct)
{
    HANDLE data = myStruct.structFirst;
    if (data != INVALID_HANDLE_VALUE)
    {
        /* NOTE: Attempt to close the file using close() instead of CloseHandle() */
        _close((int)data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_67b_case1V2Sink(CWE404_Improper_Resource_Shutdown__w32CreateFile_close_67_structType myStruct)
{
    HANDLE data = myStruct.structFirst;
    if (data != INVALID_HANDLE_VALUE)
    {
        /* ALT: Close the file using CloseHandle() */
        CloseHandle(data);
    }
}

#endif /* OMITCASE1 */
