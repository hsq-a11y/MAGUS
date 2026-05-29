/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_connect_socket_w32CreateFile_81_case0.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Full path and file name
 * Sinks: w32CreateFile
 *    Case0Sink : Open the file named in data using CreateFile()
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE36_Absolute_Path_Traversal__char_connect_socket_w32CreateFile_81.h"

#include <windows.h>

namespace CWE36_Absolute_Path_Traversal__char_connect_socket_w32CreateFile_81
{

void CWE36_Absolute_Path_Traversal__char_connect_socket_w32CreateFile_81_case0::action(char * data) const
{
    {
        HANDLE hFile;
        /* NOTE: Possibly creating and opening a file without validating the file name or path */
        hFile = CreateFileA(data,
                            (GENERIC_WRITE|GENERIC_READ),
                            0,
                            NULL,
                            OPEN_ALWAYS,
                            FILE_ATTRIBUTE_NORMAL,
                            NULL);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            CloseHandle(hFile);
        }
    }
}

}
#endif /* OMITCASE0 */
