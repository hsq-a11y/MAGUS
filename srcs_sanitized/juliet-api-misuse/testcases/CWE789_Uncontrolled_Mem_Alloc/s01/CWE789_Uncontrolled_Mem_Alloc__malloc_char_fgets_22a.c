/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22a.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * Case0Source: fgets Read data from the console using fgets()
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

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
int CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case0Global = 0;

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case0Sink(size_t data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case0()
{
    size_t data;
    /* Initialize data */
    data = 0;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        /* NOTE: Read data from the console using fgets() */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            /* Convert to unsigned int */
            data = strtoul(inputBuffer, NULL, 0);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case0Global = 1; /* true */
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
int CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case1V21Global = 0;
int CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case1V22Global = 0;
int CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case1V1Global = 0;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case1V21Sink(size_t data);

static void case1V21()
{
    size_t data;
    /* Initialize data */
    data = 0;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        /* NOTE: Read data from the console using fgets() */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            /* Convert to unsigned int */
            data = strtoul(inputBuffer, NULL, 0);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case1V21Global = 0; /* false */
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case1V21Sink(data);
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case1V22Sink(size_t data);

static void case1V22()
{
    size_t data;
    /* Initialize data */
    data = 0;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        /* NOTE: Read data from the console using fgets() */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            /* Convert to unsigned int */
            data = strtoul(inputBuffer, NULL, 0);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case1V22Global = 1; /* true */
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case1V22Sink(data);
}

/* case1V1() - use case1source and case0sink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case1V1Sink(size_t data);

static void case1V1()
{
    size_t data;
    /* Initialize data */
    data = 0;
    /* ALT: Use a relatively small number for memory allocation */
    data = 20;
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case1V1Global = 1; /* true */
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case1V1Sink(data);
}

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case1()
{
    case1V21();
    case1V22();
    case1V1();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
