/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_listen_socket_snprintf_22b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Copy a fixed string into data
 * Sinks: snprintf
 *    Case1Sink: snprintf with "%s" as the third argument and data as the fourth
 *    Case0Sink : snprintf with data as the third argument
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define SNPRINTF _snprintf
#else
#define SNPRINTF snprintf
#endif

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
extern int CWE134_Uncontrolled_Format_String__char_listen_socket_snprintf_22_case0Global;

void CWE134_Uncontrolled_Format_String__char_listen_socket_snprintf_22_case0Sink(char * data)
{
    if(CWE134_Uncontrolled_Format_String__char_listen_socket_snprintf_22_case0Global)
    {
        {
            char dest[100] = "";
            /* NOTE: Do not specify the format allowing a possible format string vulnerability */
            SNPRINTF(dest, 100-1, data);
            printLine(dest);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE134_Uncontrolled_Format_String__char_listen_socket_snprintf_22_case1V21Global;
extern int CWE134_Uncontrolled_Format_String__char_listen_socket_snprintf_22_case1V22Global;
extern int CWE134_Uncontrolled_Format_String__char_listen_socket_snprintf_22_case1V1Global;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE134_Uncontrolled_Format_String__char_listen_socket_snprintf_22_case1V21Sink(char * data)
{
    if(CWE134_Uncontrolled_Format_String__char_listen_socket_snprintf_22_case1V21Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            char dest[100] = "";
            /* ALT: Specify the format disallowing a format string vulnerability */
            SNPRINTF(dest, 100-1, "%s", data);
            printLine(dest);
        }
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE134_Uncontrolled_Format_String__char_listen_socket_snprintf_22_case1V22Sink(char * data)
{
    if(CWE134_Uncontrolled_Format_String__char_listen_socket_snprintf_22_case1V22Global)
    {
        {
            char dest[100] = "";
            /* ALT: Specify the format disallowing a format string vulnerability */
            SNPRINTF(dest, 100-1, "%s", data);
            printLine(dest);
        }
    }
}

/* case1V1() - use case1source and case0sink */
void CWE134_Uncontrolled_Format_String__char_listen_socket_snprintf_22_case1V1Sink(char * data)
{
    if(CWE134_Uncontrolled_Format_String__char_listen_socket_snprintf_22_case1V1Global)
    {
        {
            char dest[100] = "";
            /* NOTE: Do not specify the format allowing a possible format string vulnerability */
            SNPRINTF(dest, 100-1, data);
            printLine(dest);
        }
    }
}

#endif /* OMITCASE1 */
