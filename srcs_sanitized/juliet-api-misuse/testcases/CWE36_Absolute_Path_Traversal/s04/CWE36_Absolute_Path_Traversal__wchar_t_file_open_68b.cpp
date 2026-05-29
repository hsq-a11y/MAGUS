/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_file_open_68b.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * Case0Source: file Read input from a file
 * Case1Source: Full path and file name
 * Sink: open
 *    Case0Sink : Open the file named in data using open()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#ifdef _WIN32
#define OPEN _wopen
#define CLOSE _close
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#endif

extern wchar_t * CWE36_Absolute_Path_Traversal__wchar_t_file_open_68_case0Data;
extern wchar_t * CWE36_Absolute_Path_Traversal__wchar_t_file_open_68_case1V1Data;

namespace CWE36_Absolute_Path_Traversal__wchar_t_file_open_68
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

void case0Sink()
{
    wchar_t * data = CWE36_Absolute_Path_Traversal__wchar_t_file_open_68_case0Data;
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

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink()
{
    wchar_t * data = CWE36_Absolute_Path_Traversal__wchar_t_file_open_68_case1V1Data;
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

#endif /* OMITCASE1 */

} /* close namespace */
