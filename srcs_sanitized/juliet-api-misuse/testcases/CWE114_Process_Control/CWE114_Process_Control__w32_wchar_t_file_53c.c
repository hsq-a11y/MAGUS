/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_file_53c.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * Case0Source: file Read input from a file
 * Case1Source: Hard code the full pathname to the library
 * Sink:
 *    Case0Sink : Load a dynamic link library
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#include <windows.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE114_Process_Control__w32_wchar_t_file_53d_case0Sink(wchar_t * data);

void CWE114_Process_Control__w32_wchar_t_file_53c_case0Sink(wchar_t * data)
{
    CWE114_Process_Control__w32_wchar_t_file_53d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE114_Process_Control__w32_wchar_t_file_53d_case1V1Sink(wchar_t * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE114_Process_Control__w32_wchar_t_file_53c_case1V1Sink(wchar_t * data)
{
    CWE114_Process_Control__w32_wchar_t_file_53d_case1V1Sink(data);
}

#endif /* OMITCASE1 */
