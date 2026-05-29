/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_listen_socket_open_83_case1V1.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Use a fixed file name
 * Sinks: open
 *    Case0Sink : Open the file named in data using open()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE23_Relative_Path_Traversal__char_listen_socket_open_83.h"

#ifdef _WIN32
#define OPEN _open
#define CLOSE _close
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#endif

namespace CWE23_Relative_Path_Traversal__char_listen_socket_open_83
{
CWE23_Relative_Path_Traversal__char_listen_socket_open_83_case1V1::CWE23_Relative_Path_Traversal__char_listen_socket_open_83_case1V1(char * dataCopy)
{
    data = dataCopy;
    /* ALT: Use a fixed file name */
    strcat(data, "file.txt");
}

CWE23_Relative_Path_Traversal__char_listen_socket_open_83_case1V1::~CWE23_Relative_Path_Traversal__char_listen_socket_open_83_case1V1()
{
    {
        int fileDesc;
        /* NOTE: Possibly opening a file without validating the file name or path */
        fileDesc = OPEN(data, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
        if (fileDesc != -1)
        {
            CLOSE(fileDesc);
        }
    }
}
}
#endif /* OMITCASE1 */
