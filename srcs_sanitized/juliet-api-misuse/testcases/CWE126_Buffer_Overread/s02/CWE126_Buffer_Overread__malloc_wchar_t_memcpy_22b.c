/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22b.c
Label Definition File: CWE126_Buffer_Overread__malloc.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * Case0Source:  Use a small buffer
 * Case1Source: Use a large buffer
 * Sink: memcpy
 *    Case0Sink : Copy data to string using memcpy
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
extern int CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case0Global;

wchar_t * CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case0Source(wchar_t * data)
{
    if(CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case0Global)
    {
        /* NOTE: Use a small buffer */
        data = (wchar_t *)malloc(50*sizeof(wchar_t));
        if (data == NULL) {exit(-1);}
        wmemset(data, L'A', 50-1); /* fill with 'A's */
        data[50-1] = L'\0'; /* null terminate */
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case1V11Global;
extern int CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case1V12Global;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
wchar_t * CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case1V11Source(wchar_t * data)
{
    if(CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Use a large buffer */
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        if (data == NULL) {exit(-1);}
        wmemset(data, L'A', 100-1); /* fill with 'A's */
        data[100-1] = L'\0'; /* null terminate */
    }
    return data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
wchar_t * CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case1V12Source(wchar_t * data)
{
    if(CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case1V12Global)
    {
        /* ALT: Use a large buffer */
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        if (data == NULL) {exit(-1);}
        wmemset(data, L'A', 100-1); /* fill with 'A's */
        data[100-1] = L'\0'; /* null terminate */
    }
    return data;
}

#endif /* OMITCASE1 */
