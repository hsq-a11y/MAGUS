/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_file_ifstream_84_case0.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-84_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * Case0Source: file Read input from a file
 * Case1Source: Full path and file name
 * Sinks: ifstream
 *    Case0Sink : Open the file named in data using ifstream::open()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE36_Absolute_Path_Traversal__wchar_t_file_ifstream_84.h"

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#include <fstream>
using namespace std;

namespace CWE36_Absolute_Path_Traversal__wchar_t_file_ifstream_84
{
CWE36_Absolute_Path_Traversal__wchar_t_file_ifstream_84_case0::CWE36_Absolute_Path_Traversal__wchar_t_file_ifstream_84_case0(wchar_t * dataCopy)
{
    data = dataCopy;
    {
        /* Read input from a file */
        size_t dataLen = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (FILENAME_MAX-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* NOTE: Read data from a file */
                if (fgetws(data+dataLen, (int)(FILENAME_MAX-dataLen), pFile) == NULL)
                {
                    printLine("fgetws() failed");
                    /* Restore NUL terminator if fgetws fails */
                    data[dataLen] = L'\0';
                }
                fclose(pFile);
            }
        }
    }
}

CWE36_Absolute_Path_Traversal__wchar_t_file_ifstream_84_case0::~CWE36_Absolute_Path_Traversal__wchar_t_file_ifstream_84_case0()
{
    {
        ifstream inputFile;
        /* NOTE: Possibly opening a file without validating the file name or path */
        inputFile.open((char *)data);
        inputFile.close();
    }
}
}
#endif /* OMITCASE0 */
