/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__char_environment_22b.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Use a hardcoded path
 * Sink:
 *    Case0Sink : Set the environment variable
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define NEW_PATH "%SystemRoot%\\system32"
#define PUTENV _putenv
#else
#define NEW_PATH "/bin"
#define PUTENV putenv
#endif

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
extern int CWE427_Uncontrolled_Search_Path_Element__char_environment_22_case0Global;

char * CWE427_Uncontrolled_Search_Path_Element__char_environment_22_case0Source(char * data)
{
    if(CWE427_Uncontrolled_Search_Path_Element__char_environment_22_case0Global)
    {
        {
            /* Append input from an environment variable to data */
            size_t dataLen = strlen(data);
            char * environment = GETENV(ENV_VARIABLE);
            /* If there is data in the environment variable */
            if (environment != NULL)
            {
                /* NOTE: Read data from an environment variable */
                strncat(data+dataLen, environment, 250-dataLen-1);
            }
        }
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE427_Uncontrolled_Search_Path_Element__char_environment_22_case1V11Global;
extern int CWE427_Uncontrolled_Search_Path_Element__char_environment_22_case1V12Global;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
char * CWE427_Uncontrolled_Search_Path_Element__char_environment_22_case1V11Source(char * data)
{
    if(CWE427_Uncontrolled_Search_Path_Element__char_environment_22_case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Set the path as the "system" path */
        strcat(data, NEW_PATH);
    }
    return data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
char * CWE427_Uncontrolled_Search_Path_Element__char_environment_22_case1V12Source(char * data)
{
    if(CWE427_Uncontrolled_Search_Path_Element__char_environment_22_case1V12Global)
    {
        /* ALT: Set the path as the "system" path */
        strcat(data, NEW_PATH);
    }
    return data;
}

#endif /* OMITCASE1 */
