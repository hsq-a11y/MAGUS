/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_66a.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * Case0Source: fscanf Read data from the console using fscanf()
 * Case1Source: Small number greater than zero
 * Sinks:
 *    Case1Sink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    Case0Sink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define HELLO_STRING L"hello"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_66b_case0Sink(size_t dataArray[]);

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_66_case0()
{
    size_t data;
    size_t dataArray[5];
    /* Initialize data */
    data = 0;
    /* NOTE: Read data from the console using fscanf() */
    fscanf(stdin, "%zu", &data);
    /* put data in array */
    dataArray[2] = data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_66b_case0Sink(dataArray);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_66b_case1V1Sink(size_t dataArray[]);

static void case1V1()
{
    size_t data;
    size_t dataArray[5];
    /* Initialize data */
    data = 0;
    /* ALT: Use a relatively small number for memory allocation */
    data = 20;
    dataArray[2] = data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_66b_case1V1Sink(dataArray);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_66b_case1V2Sink(size_t dataArray[]);

static void case1V2()
{
    size_t data;
    size_t dataArray[5];
    /* Initialize data */
    data = 0;
    /* NOTE: Read data from the console using fscanf() */
    fscanf(stdin, "%zu", &data);
    dataArray[2] = data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_66b_case1V2Sink(dataArray);
}

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_66_case1()
{
    case1V1();
    case1V2();
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
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_66_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_66_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
