/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_relativePath_83_case0.cpp
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 114 Process Control
 * Case0Source: relativePath Hard code the relative pathname to the library
 * Case1Source: Hard code the full pathname to the library
 * Sinks:
 *    Case0Sink : Load a dynamic link library
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE114_Process_Control__w32_char_relativePath_83.h"

#include <windows.h>

namespace CWE114_Process_Control__w32_char_relativePath_83
{
CWE114_Process_Control__w32_char_relativePath_83_case0::CWE114_Process_Control__w32_char_relativePath_83_case0(char * dataCopy)
{
    data = dataCopy;
    /* NOTE: Specify just the file name for the library, not the full path */
    strcpy(data, "winsrv.dll");
}

CWE114_Process_Control__w32_char_relativePath_83_case0::~CWE114_Process_Control__w32_char_relativePath_83_case0()
{
    {
        HMODULE hModule;
        /* NOTE: If the path to the library is not specified, an attacker may be able to
         * replace his own file with the intended library */
        hModule = LoadLibraryA(data);
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
