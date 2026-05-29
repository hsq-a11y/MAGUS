/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_61b.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Small number greater than zero
 * Sinks:
 *    Case1Sink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    Case0Sink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define HELLO_STRING L"hello"

#ifndef OMITCASE0

size_t CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_61b_case0Source(size_t data)
{
    /* NOTE: Set data to a random value */
    data = rand();
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
size_t CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_61b_case1V1Source(size_t data)
{
    /* ALT: Use a relatively small number for memory allocation */
    data = 20;
    return data;
}

/* case1V2() uses the Case0Source with the Case1Sink */
size_t CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_61b_case1V2Source(size_t data)
{
    /* NOTE: Set data to a random value */
    data = rand();
    return data;
}

#endif /* OMITCASE1 */
