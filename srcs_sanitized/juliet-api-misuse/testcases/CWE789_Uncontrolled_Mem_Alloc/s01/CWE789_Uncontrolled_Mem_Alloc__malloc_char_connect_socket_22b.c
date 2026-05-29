/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_char_connect_socket_22b.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Small number greater than zero
 * Sinks:
 *    Case1Sink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    Case0Sink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define HELLO_STRING "hello"

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
extern int CWE789_Uncontrolled_Mem_Alloc__malloc_char_connect_socket_22_case0Global;

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_connect_socket_22_case0Sink(size_t data)
{
    if(CWE789_Uncontrolled_Mem_Alloc__malloc_char_connect_socket_22_case0Global)
    {
        {
            char * myString;
            /* NOTE: No MAXIMUM limitation for memory allocation, but ensure data is large enough
             * for the strcpy() function to not cause a buffer overflow */
            /* INCIDENTAL NOTE: The source could cause a type overrun in data or in the memory allocation */
            if (data > strlen(HELLO_STRING))
            {
                myString = (char *)malloc(data*sizeof(char));
                if (myString == NULL) {exit(-1);}
                /* Copy a small string into myString */
                strcpy(myString, HELLO_STRING);
                printLine(myString);
                free(myString);
            }
            else
            {
                printLine("Input is less than the length of the source string");
            }
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE789_Uncontrolled_Mem_Alloc__malloc_char_connect_socket_22_case1V21Global;
extern int CWE789_Uncontrolled_Mem_Alloc__malloc_char_connect_socket_22_case1V22Global;
extern int CWE789_Uncontrolled_Mem_Alloc__malloc_char_connect_socket_22_case1V1Global;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_connect_socket_22_case1V21Sink(size_t data)
{
    if(CWE789_Uncontrolled_Mem_Alloc__malloc_char_connect_socket_22_case1V21Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            char * myString;
            /* ALT: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
             * for the strcpy() function to not cause a buffer overflow */
            /* INCIDENTAL NOTE: The source could cause a type overrun in data or in the memory allocation */
            if (data > strlen(HELLO_STRING) && data < 100)
            {
                myString = (char *)malloc(data*sizeof(char));
                if (myString == NULL) {exit(-1);}
                /* Copy a small string into myString */
                strcpy(myString, HELLO_STRING);
                printLine(myString);
                free(myString);
            }
            else
            {
                printLine("Input is less than the length of the source string or too large");
            }
        }
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_connect_socket_22_case1V22Sink(size_t data)
{
    if(CWE789_Uncontrolled_Mem_Alloc__malloc_char_connect_socket_22_case1V22Global)
    {
        {
            char * myString;
            /* ALT: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
             * for the strcpy() function to not cause a buffer overflow */
            /* INCIDENTAL NOTE: The source could cause a type overrun in data or in the memory allocation */
            if (data > strlen(HELLO_STRING) && data < 100)
            {
                myString = (char *)malloc(data*sizeof(char));
                if (myString == NULL) {exit(-1);}
                /* Copy a small string into myString */
                strcpy(myString, HELLO_STRING);
                printLine(myString);
                free(myString);
            }
            else
            {
                printLine("Input is less than the length of the source string or too large");
            }
        }
    }
}

/* case1V1() - use case1source and case0sink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_connect_socket_22_case1V1Sink(size_t data)
{
    if(CWE789_Uncontrolled_Mem_Alloc__malloc_char_connect_socket_22_case1V1Global)
    {
        {
            char * myString;
            /* NOTE: No MAXIMUM limitation for memory allocation, but ensure data is large enough
             * for the strcpy() function to not cause a buffer overflow */
            /* INCIDENTAL NOTE: The source could cause a type overrun in data or in the memory allocation */
            if (data > strlen(HELLO_STRING))
            {
                myString = (char *)malloc(data*sizeof(char));
                if (myString == NULL) {exit(-1);}
                /* Copy a small string into myString */
                strcpy(myString, HELLO_STRING);
                printLine(myString);
                free(myString);
            }
            else
            {
                printLine("Input is less than the length of the source string");
            }
        }
    }
}

#endif /* OMITCASE1 */
