/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__malloc_char_ncpy_22a.c
Label Definition File: CWE127_Buffer_Underread__malloc.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sink: ncpy
 *    Case0Sink : Copy data to string using strncpy
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
int CWE127_Buffer_Underread__malloc_char_ncpy_22_case0Global = 0;

char * CWE127_Buffer_Underread__malloc_char_ncpy_22_case0Source(char * data);

void CWE127_Buffer_Underread__malloc_char_ncpy_22_case0()
{
    char * data;
    data = NULL;
    CWE127_Buffer_Underread__malloc_char_ncpy_22_case0Global = 1; /* true */
    data = CWE127_Buffer_Underread__malloc_char_ncpy_22_case0Source(data);
    {
        char dest[100];
        memset(dest, 'C', 100-1); /* fill with 'C's */
        dest[100-1] = '\0'; /* null terminate */
        /* NOTE: Possibly copy from a memory location located before the source buffer */
        strncpy(dest, data, strlen(dest));
        /* Ensure null termination */
        dest[100-1] = '\0';
        printLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by malloc() so can't safely call free() on it */
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
int CWE127_Buffer_Underread__malloc_char_ncpy_22_case1V11Global = 0;
int CWE127_Buffer_Underread__malloc_char_ncpy_22_case1V12Global = 0;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
char * CWE127_Buffer_Underread__malloc_char_ncpy_22_case1V11Source(char * data);

static void case1V11()
{
    char * data;
    data = NULL;
    CWE127_Buffer_Underread__malloc_char_ncpy_22_case1V11Global = 0; /* false */
    data = CWE127_Buffer_Underread__malloc_char_ncpy_22_case1V11Source(data);
    {
        char dest[100];
        memset(dest, 'C', 100-1); /* fill with 'C's */
        dest[100-1] = '\0'; /* null terminate */
        /* NOTE: Possibly copy from a memory location located before the source buffer */
        strncpy(dest, data, strlen(dest));
        /* Ensure null termination */
        dest[100-1] = '\0';
        printLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by malloc() so can't safely call free() on it */
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
char * CWE127_Buffer_Underread__malloc_char_ncpy_22_case1V12Source(char * data);

static void case1V12()
{
    char * data;
    data = NULL;
    CWE127_Buffer_Underread__malloc_char_ncpy_22_case1V12Global = 1; /* true */
    data = CWE127_Buffer_Underread__malloc_char_ncpy_22_case1V12Source(data);
    {
        char dest[100];
        memset(dest, 'C', 100-1); /* fill with 'C's */
        dest[100-1] = '\0'; /* null terminate */
        /* NOTE: Possibly copy from a memory location located before the source buffer */
        strncpy(dest, data, strlen(dest));
        /* Ensure null termination */
        dest[100-1] = '\0';
        printLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by malloc() so can't safely call free() on it */
    }
}

void CWE127_Buffer_Underread__malloc_char_ncpy_22_case1()
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
    CWE127_Buffer_Underread__malloc_char_ncpy_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE127_Buffer_Underread__malloc_char_ncpy_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
