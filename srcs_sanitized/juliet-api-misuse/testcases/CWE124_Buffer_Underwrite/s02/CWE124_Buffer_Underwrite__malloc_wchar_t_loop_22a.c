/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__malloc_wchar_t_loop_22a.c
Label Definition File: CWE124_Buffer_Underwrite__malloc.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sink: loop
 *    Case0Sink : Copy string to data using a loop
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
int CWE124_Buffer_Underwrite__malloc_wchar_t_loop_22_case0Global = 0;

wchar_t * CWE124_Buffer_Underwrite__malloc_wchar_t_loop_22_case0Source(wchar_t * data);

void CWE124_Buffer_Underwrite__malloc_wchar_t_loop_22_case0()
{
    wchar_t * data;
    data = NULL;
    CWE124_Buffer_Underwrite__malloc_wchar_t_loop_22_case0Global = 1; /* true */
    data = CWE124_Buffer_Underwrite__malloc_wchar_t_loop_22_case0Source(data);
    {
        size_t i;
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with 'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* NOTE: Possibly copying data to memory before the destination buffer */
        for (i = 0; i < 100; i++)
        {
            data[i] = source[i];
        }
        /* Ensure the destination buffer is null terminated */
        data[100-1] = L'\0';
        printWLine(data);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by malloc() so can't safely call free() on it */
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
int CWE124_Buffer_Underwrite__malloc_wchar_t_loop_22_case1V11Global = 0;
int CWE124_Buffer_Underwrite__malloc_wchar_t_loop_22_case1V12Global = 0;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
wchar_t * CWE124_Buffer_Underwrite__malloc_wchar_t_loop_22_case1V11Source(wchar_t * data);

static void case1V11()
{
    wchar_t * data;
    data = NULL;
    CWE124_Buffer_Underwrite__malloc_wchar_t_loop_22_case1V11Global = 0; /* false */
    data = CWE124_Buffer_Underwrite__malloc_wchar_t_loop_22_case1V11Source(data);
    {
        size_t i;
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with 'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* NOTE: Possibly copying data to memory before the destination buffer */
        for (i = 0; i < 100; i++)
        {
            data[i] = source[i];
        }
        /* Ensure the destination buffer is null terminated */
        data[100-1] = L'\0';
        printWLine(data);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by malloc() so can't safely call free() on it */
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
wchar_t * CWE124_Buffer_Underwrite__malloc_wchar_t_loop_22_case1V12Source(wchar_t * data);

static void case1V12()
{
    wchar_t * data;
    data = NULL;
    CWE124_Buffer_Underwrite__malloc_wchar_t_loop_22_case1V12Global = 1; /* true */
    data = CWE124_Buffer_Underwrite__malloc_wchar_t_loop_22_case1V12Source(data);
    {
        size_t i;
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with 'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* NOTE: Possibly copying data to memory before the destination buffer */
        for (i = 0; i < 100; i++)
        {
            data[i] = source[i];
        }
        /* Ensure the destination buffer is null terminated */
        data[100-1] = L'\0';
        printWLine(data);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by malloc() so can't safely call free() on it */
    }
}

void CWE124_Buffer_Underwrite__malloc_wchar_t_loop_22_case1()
{
    case1V11();
    case1V12();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE124_Buffer_Underwrite__malloc_wchar_t_loop_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE124_Buffer_Underwrite__malloc_wchar_t_loop_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
