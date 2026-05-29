/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_console_54d.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-54d.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * Case0Source: console Read input from the console
 * Case1Source: Hard code the full pathname to the library
 * Sink:
 *    Case0Sink : Load a dynamic link library
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE114_Process_Control__w32_char_console_54e_case0Sink(char * data);

void CWE114_Process_Control__w32_char_console_54d_case0Sink(char * data)
{
    CWE114_Process_Control__w32_char_console_54e_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE114_Process_Control__w32_char_console_54e_case1V1Sink(char * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE114_Process_Control__w32_char_console_54d_case1V1Sink(char * data)
{
    CWE114_Process_Control__w32_char_console_54e_case1V1Sink(data);
}

#endif /* OMITCASE1 */
