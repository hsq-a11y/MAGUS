/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_console_52c.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-52c.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * Case0Source: console Read input from the console
 * Case1Source: Hard code the full pathname to the library
 * Sink:
 *    Case0Sink : Load a dynamic link library
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

void CWE114_Process_Control__w32_char_console_52c_case0Sink(char * data)
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

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE114_Process_Control__w32_char_console_52c_case1V1Sink(char * data)
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

#endif /* OMITCASE1 */
