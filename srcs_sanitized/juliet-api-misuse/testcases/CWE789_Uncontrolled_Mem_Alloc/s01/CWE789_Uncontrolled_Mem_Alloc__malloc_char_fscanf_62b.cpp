/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_62b.cpp
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * Case0Source: fscanf Read data from the console using fscanf()
 * Case1Source: Small number greater than zero
 * Sinks:
 *    Case1Sink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    Case0Sink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_62
{

#ifndef OMITCASE0

void case0Source(size_t &data)
{
    /* NOTE: Read data from the console using fscanf() */
    fscanf(stdin, "%zu", &data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
void case1V1Source(size_t &data)
{
    /* ALT: Use a relatively small number for memory allocation */
    data = 20;
}

/* case1V2() uses the Case0Source with the Case1Sink */
void case1V2Source(size_t &data)
{
    /* NOTE: Read data from the console using fscanf() */
    fscanf(stdin, "%zu", &data);
}

#endif /* OMITCASE1 */

} /* close namespace */
