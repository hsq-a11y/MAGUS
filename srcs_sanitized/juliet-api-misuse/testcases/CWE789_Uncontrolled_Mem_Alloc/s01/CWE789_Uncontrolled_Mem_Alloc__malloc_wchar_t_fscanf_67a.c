/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67a.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * Case0Source: fscanf Read data from the console using fscanf()
 * Case1Source: Small number greater than zero
 * Sinks:
 *    Case1Sink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    Case0Sink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define HELLO_STRING L"hello"

typedef struct _CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67_structType
{
    size_t structFirst;
} CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67_structType;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67b_case0Sink(CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67_structType myStruct);

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67_case0()
{
    size_t data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67_structType myStruct;
    /* Initialize data */
    data = 0;
    /* NOTE: Read data from the console using fscanf() */
    fscanf(stdin, "%zu", &data);
    myStruct.structFirst = data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67b_case0Sink(myStruct);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67b_case1V1Sink(CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67_structType myStruct);

static void case1V1()
{
    size_t data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67_structType myStruct;
    /* Initialize data */
    data = 0;
    /* ALT: Use a relatively small number for memory allocation */
    data = 20;
    myStruct.structFirst = data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67b_case1V1Sink(myStruct);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67b_case1V2Sink(CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67_structType myStruct);

static void case1V2()
{
    size_t data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67_structType myStruct;
    /* Initialize data */
    data = 0;
    /* NOTE: Read data from the console using fscanf() */
    fscanf(stdin, "%zu", &data);
    myStruct.structFirst = data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67b_case1V2Sink(myStruct);
}

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67_case1()
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
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_67_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
