/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_file_open_84_case1V1.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * Case0Source: file Read input from a file
 * Case1Source: Full path and file name
 * Sinks: open
 *    Case0Sink : Open the file named in data using open()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE36_Absolute_Path_Traversal__char_file_open_84.h"

#ifdef _WIN32
#define OPEN _open
#define CLOSE _close
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#endif

namespace CWE36_Absolute_Path_Traversal__char_file_open_84
{
CWE36_Absolute_Path_Traversal__char_file_open_84_case1V1::CWE36_Absolute_Path_Traversal__char_file_open_84_case1V1(char * dataCopy)
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

CWE36_Absolute_Path_Traversal__char_file_open_84_case1V1::~CWE36_Absolute_Path_Traversal__char_file_open_84_case1V1()
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
