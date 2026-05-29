/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_console_fopen_83_case1V1.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * Case0Source: console Read input from the console
 * Case1Source: Full path and file name
 * Sinks: fopen
 *    Case0Sink : Open the file named in data using fopen()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE36_Absolute_Path_Traversal__char_console_fopen_83.h"

#ifdef _WIN32
#define FOPEN fopen
#else
#define FOPEN fopen
#endif

namespace CWE36_Absolute_Path_Traversal__char_console_fopen_83
{
CWE36_Absolute_Path_Traversal__char_console_fopen_83_case1V1::CWE36_Absolute_Path_Traversal__char_console_fopen_83_case1V1(char * dataCopy)
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

CWE36_Absolute_Path_Traversal__char_console_fopen_83_case1V1::~CWE36_Absolute_Path_Traversal__char_console_fopen_83_case1V1()
{
    {
        FILE *pFile = NULL;
        /* NOTE: Possibly opening a file without validating the file name or path */
        pFile = FOPEN(data, "wb+");
        if (pFile != NULL)
        {
            fclose(pFile);
        }
    }
}
}
#endif /* OMITCASE1 */
