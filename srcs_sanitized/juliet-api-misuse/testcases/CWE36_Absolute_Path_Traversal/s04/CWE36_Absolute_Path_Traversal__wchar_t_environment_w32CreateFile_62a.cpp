/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_environment_w32CreateFile_62a.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-62a.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Full path and file name
 * Sinks: w32CreateFile
 *    Case0Sink : Open the file named in data using CreateFile()
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif

#include <windows.h>

namespace CWE36_Absolute_Path_Traversal__wchar_t_environment_w32CreateFile_62
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Source(wchar_t * &data);

void case0()
{
    wchar_t * data;
    wchar_t dataBuffer[FILENAME_MAX] = L"";
    data = dataBuffer;
    case0Source(data);
    {
        HANDLE hFile;
        /* NOTE: Possibly creating and opening a file without validating the file name or path */
        hFile = CreateFileW(data,
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

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Source(wchar_t * &data);

static void case1V1()
{
    wchar_t * data;
    wchar_t dataBuffer[FILENAME_MAX] = L"";
    data = dataBuffer;
    case1V1Source(data);
    {
        HANDLE hFile;
        /* NOTE: Possibly creating and opening a file without validating the file name or path */
        hFile = CreateFileW(data,
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

void case1()
{
    case1V1();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE36_Absolute_Path_Traversal__wchar_t_environment_w32CreateFile_62; /* so that we can use case1 and case0 easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
