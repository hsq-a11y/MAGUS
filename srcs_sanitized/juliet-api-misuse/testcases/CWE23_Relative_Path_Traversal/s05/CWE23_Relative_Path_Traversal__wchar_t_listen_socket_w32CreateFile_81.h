/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_listen_socket_w32CreateFile_81.h
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-81.tmpl.h
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Use a fixed file name
 * Sinks: w32CreateFile
 *    Case0Sink : Open the file named in data using CreateFile()
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH L"c:\\temp\\"
#else
#include <wchar.h>
#define BASEPATH L"/tmp/"
#endif

namespace CWE23_Relative_Path_Traversal__wchar_t_listen_socket_w32CreateFile_81
{

class CWE23_Relative_Path_Traversal__wchar_t_listen_socket_w32CreateFile_81_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) const = 0;
};

#ifndef OMITCASE0

class CWE23_Relative_Path_Traversal__wchar_t_listen_socket_w32CreateFile_81_case0 : public CWE23_Relative_Path_Traversal__wchar_t_listen_socket_w32CreateFile_81_base
{
public:
    void action(wchar_t * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE23_Relative_Path_Traversal__wchar_t_listen_socket_w32CreateFile_81_case1V1 : public CWE23_Relative_Path_Traversal__wchar_t_listen_socket_w32CreateFile_81_base
{
public:
    void action(wchar_t * data) const;
};

#endif /* OMITCASE1 */

}
