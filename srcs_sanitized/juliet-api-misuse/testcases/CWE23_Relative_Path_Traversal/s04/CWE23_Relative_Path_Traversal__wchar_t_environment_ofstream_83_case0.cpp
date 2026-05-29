/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_environment_ofstream_83_case0.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Use a fixed file name
 * Sinks: ofstream
 *    Case0Sink : Open the file named in data using ofstream::open()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE23_Relative_Path_Traversal__wchar_t_environment_ofstream_83.h"

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif

#include <fstream>
using namespace std;

namespace CWE23_Relative_Path_Traversal__wchar_t_environment_ofstream_83
{
CWE23_Relative_Path_Traversal__wchar_t_environment_ofstream_83_case0::CWE23_Relative_Path_Traversal__wchar_t_environment_ofstream_83_case0(wchar_t * dataCopy)
{
    data = dataCopy;
    {
        /* Append input from an environment variable to data */
        size_t dataLen = wcslen(data);
        wchar_t * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            /* NOTE: Read data from an environment variable */
            wcsncat(data+dataLen, environment, FILENAME_MAX-dataLen-1);
        }
    }
}

CWE23_Relative_Path_Traversal__wchar_t_environment_ofstream_83_case0::~CWE23_Relative_Path_Traversal__wchar_t_environment_ofstream_83_case0()
{
    {
        ofstream outputFile;
        /* NOTE: Possibly opening a file without validating the file name or path */
        outputFile.open((char *)data);
        outputFile.close();
    }
}
}
#endif /* OMITCASE0 */
