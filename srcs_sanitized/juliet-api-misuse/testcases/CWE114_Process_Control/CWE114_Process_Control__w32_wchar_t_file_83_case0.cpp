/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_file_83_case0.cpp
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 114 Process Control
 * Case0Source: file Read input from a file
 * Case1Source: Hard code the full pathname to the library
 * Sinks:
 *    Case0Sink : Load a dynamic link library
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE114_Process_Control__w32_wchar_t_file_83.h"

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#include <windows.h>

namespace CWE114_Process_Control__w32_wchar_t_file_83
{
CWE114_Process_Control__w32_wchar_t_file_83_case0::CWE114_Process_Control__w32_wchar_t_file_83_case0(wchar_t * dataCopy)
{
    data = dataCopy;
    {
        /* Read input from a file */
        size_t dataLen = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (100-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* NOTE: Read data from a file */
                if (fgetws(data+dataLen, (int)(100-dataLen), pFile) == NULL)
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

CWE114_Process_Control__w32_wchar_t_file_83_case0::~CWE114_Process_Control__w32_wchar_t_file_83_case0()
{
    {
        HMODULE hModule;
        /* NOTE: If the path to the library is not specified, an attacker may be able to
         * replace his own file with the intended library */
        hModule = LoadLibraryW(data);
        if (hModule != NULL)
        {
            FreeLibrary(hModule);
            printLine("Library loaded and freed successfully");
        }
        else
        {
            printLine("Unable to load library");
        }
    }
}
}
#endif /* OMITCASE0 */
