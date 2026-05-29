/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_relativePath_84_case1V1.cpp
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 114 Process Control
 * Case0Source: relativePath Hard code the relative pathname to the library
 * Case1Source: Hard code the full pathname to the library
 * Sinks:
 *    Case0Sink : Load a dynamic link library
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE114_Process_Control__w32_wchar_t_relativePath_84.h"

#include <windows.h>

namespace CWE114_Process_Control__w32_wchar_t_relativePath_84
{
CWE114_Process_Control__w32_wchar_t_relativePath_84_case1V1::CWE114_Process_Control__w32_wchar_t_relativePath_84_case1V1(wchar_t * dataCopy)
{
    data = dataCopy;
    /* ALT: Specify the full pathname for the library */
    wcscpy(data, L"C:\\Windows\\System32\\winsrv.dll");
}

CWE114_Process_Control__w32_wchar_t_relativePath_84_case1V1::~CWE114_Process_Control__w32_wchar_t_relativePath_84_case1V1()
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
#endif /* OMITCASE1 */
