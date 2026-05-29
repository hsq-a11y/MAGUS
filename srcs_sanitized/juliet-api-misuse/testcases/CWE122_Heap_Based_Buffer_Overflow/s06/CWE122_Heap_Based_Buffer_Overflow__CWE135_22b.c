/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE135_22b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Void pointer to a wchar_t array
 * Case1Source: Void pointer to a char array
 * Sinks:
 *    Case1Sink: Allocate memory using wcslen() and copy data
 *    Case0Sink : Allocate memory using strlen() and copy data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
extern int CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case0Global;

void CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case0Sink(void * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case0Global)
    {
        {
            /* NOTE: treating pointer as a char* when it may point to a wide string */
            size_t dataLen = strlen((char *)data);
            void * dest = (void *)calloc(dataLen+1, sizeof(wchar_t));
            if (dest == NULL) {exit(-1);}
            (void)wcscpy(dest, data);
            printLine((char *)dest);
            free(dest);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V21Global;
extern int CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V22Global;
extern int CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V1Global;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V21Sink(void * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V21Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            /* ALT: treating pointer like a wchar_t*  */
            size_t dataLen = wcslen((wchar_t *)data);
            void * dest = (void *)calloc(dataLen+1, sizeof(wchar_t));
            if (dest == NULL) {exit(-1);}
            (void)wcscpy(dest, data);
            printWLine((wchar_t *)dest);
            free(dest);
        }
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V22Sink(void * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V22Global)
    {
        {
            /* ALT: treating pointer like a wchar_t*  */
            size_t dataLen = wcslen((wchar_t *)data);
            void * dest = (void *)calloc(dataLen+1, sizeof(wchar_t));
            if (dest == NULL) {exit(-1);}
            (void)wcscpy(dest, data);
            printWLine((wchar_t *)dest);
            free(dest);
        }
    }
}

/* case1V1() - use case1source and case0sink */
void CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V1Sink(void * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V1Global)
    {
        {
            /* NOTE: treating pointer as a char* when it may point to a wide string */
            size_t dataLen = strlen((char *)data);
            void * dest = (void *)calloc(dataLen+1, 1);
            if (dest == NULL) {exit(-1);}
            (void)strcpy(dest, data);
            printLine((char *)dest);
            free(dest);
        }
    }
}

#endif /* OMITCASE1 */
