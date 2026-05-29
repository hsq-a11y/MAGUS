/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_listen_socket_22b.c
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Sinks:
 *    Case1Sink: free() memory correctly at the start of the buffer
 *    Case0Sink : free() memory not at the start of the buffer
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SEARCH_CHAR L'S'

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
extern int CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_listen_socket_22_case0Global;

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_listen_socket_22_case0Sink(wchar_t * data)
{
    if(CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_listen_socket_22_case0Global)
    {
        /* NOTE: We are incrementing the pointer in the loop - this will cause us to free the
         * memory block not at the start of the buffer */
        for (; *data != L'\0'; data++)
        {
            if (*data == SEARCH_CHAR)
            {
                printLine("We have a match!");
                break;
            }
        }
        free(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_listen_socket_22_case1V21Global;
extern int CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_listen_socket_22_case1V22Global;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_listen_socket_22_case1V21Sink(wchar_t * data)
{
    if(CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_listen_socket_22_case1V21Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            size_t i;
            /* ALT: Use a loop variable to traverse through the string pointed to by data */
            for (i=0; i < wcslen(data); i++)
            {
                if (data[i] == SEARCH_CHAR)
                {
                    printLine("We have a match!");
                    break;
                }
            }
            free(data);
        }
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_listen_socket_22_case1V22Sink(wchar_t * data)
{
    if(CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_listen_socket_22_case1V22Global)
    {
        {
            size_t i;
            /* ALT: Use a loop variable to traverse through the string pointed to by data */
            for (i=0; i < wcslen(data); i++)
            {
                if (data[i] == SEARCH_CHAR)
                {
                    printLine("We have a match!");
                    break;
                }
            }
            free(data);
        }
    }
}

#endif /* OMITCASE1 */
