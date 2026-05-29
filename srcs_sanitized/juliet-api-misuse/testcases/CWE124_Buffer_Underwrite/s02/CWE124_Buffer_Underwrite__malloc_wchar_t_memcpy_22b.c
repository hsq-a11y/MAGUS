/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__malloc_wchar_t_memcpy_22b.c
Label Definition File: CWE124_Buffer_Underwrite__malloc.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sink: memcpy
 *    Case0Sink : Copy string to data using memcpy
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
extern int CWE124_Buffer_Underwrite__malloc_wchar_t_memcpy_22_case0Global;

wchar_t * CWE124_Buffer_Underwrite__malloc_wchar_t_memcpy_22_case0Source(wchar_t * data)
{
    if(CWE124_Buffer_Underwrite__malloc_wchar_t_memcpy_22_case0Global)
    {
        {
            wchar_t * dataBuffer = (wchar_t *)malloc(100*sizeof(wchar_t));
            if (dataBuffer == NULL) {exit(-1);}
            wmemset(dataBuffer, L'A', 100-1);
            dataBuffer[100-1] = L'\0';
            /* NOTE: Set data pointer to before the allocated memory buffer */
            data = dataBuffer - 8;
        }
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE124_Buffer_Underwrite__malloc_wchar_t_memcpy_22_case1V11Global;
extern int CWE124_Buffer_Underwrite__malloc_wchar_t_memcpy_22_case1V12Global;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
wchar_t * CWE124_Buffer_Underwrite__malloc_wchar_t_memcpy_22_case1V11Source(wchar_t * data)
{
    if(CWE124_Buffer_Underwrite__malloc_wchar_t_memcpy_22_case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            wchar_t * dataBuffer = (wchar_t *)malloc(100*sizeof(wchar_t));
            if (dataBuffer == NULL) {exit(-1);}
            wmemset(dataBuffer, L'A', 100-1);
            dataBuffer[100-1] = L'\0';
            /* ALT: Set data pointer to the allocated memory buffer */
            data = dataBuffer;
        }
    }
    return data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
wchar_t * CWE124_Buffer_Underwrite__malloc_wchar_t_memcpy_22_case1V12Source(wchar_t * data)
{
    if(CWE124_Buffer_Underwrite__malloc_wchar_t_memcpy_22_case1V12Global)
    {
        {
            wchar_t * dataBuffer = (wchar_t *)malloc(100*sizeof(wchar_t));
            if (dataBuffer == NULL) {exit(-1);}
            wmemset(dataBuffer, L'A', 100-1);
            dataBuffer[100-1] = L'\0';
            /* ALT: Set data pointer to the allocated memory buffer */
            data = dataBuffer;
        }
    }
    return data;
}

#endif /* OMITCASE1 */
