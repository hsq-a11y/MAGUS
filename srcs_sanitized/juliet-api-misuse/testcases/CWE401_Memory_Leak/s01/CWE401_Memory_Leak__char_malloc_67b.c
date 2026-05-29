/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__char_malloc_67b.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: malloc Allocate data using malloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE401_Memory_Leak__char_malloc_67_structType
{
    char * structFirst;
} CWE401_Memory_Leak__char_malloc_67_structType;

#ifndef OMITCASE0

void CWE401_Memory_Leak__char_malloc_67b_case0Sink(CWE401_Memory_Leak__char_malloc_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE401_Memory_Leak__char_malloc_67b_case1V1Sink(CWE401_Memory_Leak__char_malloc_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE401_Memory_Leak__char_malloc_67b_case1V2Sink(CWE401_Memory_Leak__char_malloc_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    /* ALT: Deallocate memory */
    free(data);
}

#endif /* OMITCASE1 */
