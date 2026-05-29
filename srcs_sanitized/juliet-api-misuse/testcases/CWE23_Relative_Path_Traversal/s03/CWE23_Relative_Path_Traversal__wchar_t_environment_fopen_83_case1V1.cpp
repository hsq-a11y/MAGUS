/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_environment_fopen_83_case1V1.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Use a fixed file name
 * Sinks: fopen
 *    Case0Sink : Open the file named in data using fopen()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE23_Relative_Path_Traversal__wchar_t_environment_fopen_83.h"

#ifdef _WIN32
#define FOPEN _wfopen
#else
#define FOPEN fopen
#endif

namespace CWE23_Relative_Path_Traversal__wchar_t_environment_fopen_83
{
CWE23_Relative_Path_Traversal__wchar_t_environment_fopen_83_case1V1::CWE23_Relative_Path_Traversal__wchar_t_environment_fopen_83_case1V1(wchar_t * dataCopy)
{
    data = dataCopy;
    /* ALT: Use a fixed file name */
    wcscat(data, L"file.txt");
}

CWE23_Relative_Path_Traversal__wchar_t_environment_fopen_83_case1V1::~CWE23_Relative_Path_Traversal__wchar_t_environment_fopen_83_case1V1()
{
    {
        FILE *pFile = NULL;
        /* NOTE: Possibly opening a file without validating the file name or path */
        pFile = FOPEN(data, L"wb+");
        if (pFile != NULL)
        {
            fclose(pFile);
        }
    }
}
}
#endif /* OMITCASE1 */
