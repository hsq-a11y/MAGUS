/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_listen_socket_w32CreateFile_83_case1V1.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Full path and file name
 * Sinks: w32CreateFile
 *    Case0Sink : Open the file named in data using CreateFile()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE36_Absolute_Path_Traversal__char_listen_socket_w32CreateFile_83.h"

#include <windows.h>

namespace CWE36_Absolute_Path_Traversal__char_listen_socket_w32CreateFile_83
{
CWE36_Absolute_Path_Traversal__char_listen_socket_w32CreateFile_83_case1V1::CWE36_Absolute_Path_Traversal__char_listen_socket_w32CreateFile_83_case1V1(char * dataCopy)
{
    data = dataCopy;
#ifdef _WIN32
    /* ALT: Use a fixed, full path and file name */
    strcat(data, "c:\\temp\\file.txt");
#else
    /* ALT: Use a fixed, full path and file name */
    strcat(data, "/tmp/file.txt");
#endif
}

CWE36_Absolute_Path_Traversal__char_listen_socket_w32CreateFile_83_case1V1::~CWE36_Absolute_Path_Traversal__char_listen_socket_w32CreateFile_83_case1V1()
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
