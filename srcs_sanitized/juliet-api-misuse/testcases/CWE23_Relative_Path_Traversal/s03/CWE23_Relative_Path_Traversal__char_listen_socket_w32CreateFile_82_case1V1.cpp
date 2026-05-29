/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_listen_socket_w32CreateFile_82_case1V1.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-82_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Use a fixed file name
 * Sinks: w32CreateFile
 *    Case0Sink : Open the file named in data using CreateFile()
 * Flow Variant: 82 Data flow: data passed in a parameter to a virtual method called via a pointer
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE23_Relative_Path_Traversal__char_listen_socket_w32CreateFile_82.h"

#include <windows.h>

namespace CWE23_Relative_Path_Traversal__char_listen_socket_w32CreateFile_82
{

void CWE23_Relative_Path_Traversal__char_listen_socket_w32CreateFile_82_case1V1::action(char * data)
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
#endif /* OMITCASE1 */
