/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_connect_socket_open_82_case1V1.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-82_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Full path and file name
 * Sinks: open
 *    Case0Sink : Open the file named in data using open()
 * Flow Variant: 82 Data flow: data passed in a parameter to a virtual method called via a pointer
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE36_Absolute_Path_Traversal__wchar_t_connect_socket_open_82.h"

#ifdef _WIN32
#define OPEN _wopen
#define CLOSE _close
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#endif

namespace CWE36_Absolute_Path_Traversal__wchar_t_connect_socket_open_82
{

void CWE36_Absolute_Path_Traversal__wchar_t_connect_socket_open_82_case1V1::action(wchar_t * data)
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
