/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_54c.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-54c.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * Case0Source: fgets Read data from the console using fgets()
 * Case1Source: Small number greater than zero
 * Sinks:
 *    Case1Sink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    Case0Sink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

#define HELLO_STRING L"hello"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_54d_case0Sink(size_t data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_54c_case0Sink(size_t data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_54d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_54d_case1V1Sink(size_t data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_54c_case1V1Sink(size_t data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_54d_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_54d_case1V2Sink(size_t data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_54c_case1V2Sink(size_t data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_54d_case1V2Sink(data);
}

#endif /* OMITCASE1 */
