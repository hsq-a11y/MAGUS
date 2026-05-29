/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22a.c
Label Definition File: CWE126_Buffer_Overread__malloc.label.xml
Template File: sources-sink-22a.tmpl.c
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
int CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case0Global = 0;

wchar_t * CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case0Source(wchar_t * data);

void CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case0()
{
    wchar_t * data;
    data = NULL;
    CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case0Global = 1; /* true */
    data = CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case0Source(data);
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        /* NOTE: using memcpy with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memcpy(dest, data, wcslen(dest)*sizeof(wchar_t));
        dest[100-1] = L'\0';
        printWLine(dest);
        free(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
int CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case1V11Global = 0;
int CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case1V12Global = 0;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
wchar_t * CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case1V11Source(wchar_t * data);

static void case1V11()
{
    wchar_t * data;
    data = NULL;
    CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case1V11Global = 0; /* false */
    data = CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case1V11Source(data);
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        /* NOTE: using memcpy with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memcpy(dest, data, wcslen(dest)*sizeof(wchar_t));
        dest[100-1] = L'\0';
        printWLine(dest);
        free(data);
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
wchar_t * CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case1V12Source(wchar_t * data);

static void case1V12()
{
    wchar_t * data;
    data = NULL;
    CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case1V12Global = 1; /* true */
    data = CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case1V12Source(data);
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        /* NOTE: using memcpy with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memcpy(dest, data, wcslen(dest)*sizeof(wchar_t));
        dest[100-1] = L'\0';
        printWLine(dest);
        free(data);
    }
}

void CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case1()
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
    CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE126_Buffer_Overread__malloc_wchar_t_memcpy_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
