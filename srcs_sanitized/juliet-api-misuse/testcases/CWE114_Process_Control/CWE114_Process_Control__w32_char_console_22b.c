/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_console_22b.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * Case0Source: console Read input from the console
 * Case1Source: Hard code the full pathname to the library
 * Sink:
 *    Case0Sink : Load a dynamic link library
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
extern int CWE114_Process_Control__w32_char_console_22_case0Global;

char * CWE114_Process_Control__w32_char_console_22_case0Source(char * data)
{
    if(CWE114_Process_Control__w32_char_console_22_case0Global)
    {
        {
            /* Read input from the console */
            size_t dataLen = strlen(data);
            /* if there is room in data, read into it from the console */
            if (100-dataLen > 1)
            {
                /* NOTE: Read data from the console */
                if (fgets(data+dataLen, (int)(100-dataLen), stdin) != NULL)
                {
                    /* The next few lines remove the carriage return from the string that is
                     * inserted by fgets() */
                    dataLen = strlen(data);
                    if (dataLen > 0 && data[dataLen-1] == '\n')
                    {
                        data[dataLen-1] = '\0';
                    }
                }
                else
                {
                    printLine("fgets() failed");
                    /* Restore NUL terminator if fgets fails */
                    data[dataLen] = '\0';
                }
            }
        }
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE114_Process_Control__w32_char_console_22_case1V11Global;
extern int CWE114_Process_Control__w32_char_console_22_case1V12Global;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
char * CWE114_Process_Control__w32_char_console_22_case1V11Source(char * data)
{
    if(CWE114_Process_Control__w32_char_console_22_case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Specify the full pathname for the library */
        strcpy(data, "C:\\Windows\\System32\\winsrv.dll");
    }
    return data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
char * CWE114_Process_Control__w32_char_console_22_case1V12Source(char * data)
{
    if(CWE114_Process_Control__w32_char_console_22_case1V12Global)
    {
        /* ALT: Specify the full pathname for the library */
        strcpy(data, "C:\\Windows\\System32\\winsrv.dll");
    }
    return data;
}

#endif /* OMITCASE1 */
