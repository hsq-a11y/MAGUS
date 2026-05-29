/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_relativePath_61b.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * Case0Source: relativePath Hard code the relative pathname to the library
 * Case1Source: Hard code the full pathname to the library
 * Sinks:
 *    Case0Sink : Load a dynamic link library
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>

#ifndef OMITCASE0

wchar_t * CWE114_Process_Control__w32_wchar_t_relativePath_61b_case0Source(wchar_t * data)
{
    /* NOTE: Specify just the file name for the library, not the full path */
    wcscpy(data, L"winsrv.dll");
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
wchar_t * CWE114_Process_Control__w32_wchar_t_relativePath_61b_case1V1Source(wchar_t * data)
{
    /* ALT: Specify the full pathname for the library */
    wcscpy(data, L"C:\\Windows\\System32\\winsrv.dll");
    return data;
}

#endif /* OMITCASE1 */
