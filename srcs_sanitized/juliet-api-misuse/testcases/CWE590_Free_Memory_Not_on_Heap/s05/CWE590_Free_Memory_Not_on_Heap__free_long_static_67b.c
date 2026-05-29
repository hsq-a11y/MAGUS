/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_long_static_67b.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: static Data buffer is declared static on the stack
 * Case1Source: Allocate memory on the heap
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE590_Free_Memory_Not_on_Heap__free_long_static_67_structType
{
    long * structFirst;
} CWE590_Free_Memory_Not_on_Heap__free_long_static_67_structType;

#ifndef OMITCASE0

void CWE590_Free_Memory_Not_on_Heap__free_long_static_67b_case0Sink(CWE590_Free_Memory_Not_on_Heap__free_long_static_67_structType myStruct)
{
    long * data = myStruct.structFirst;
    printLongLine(data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE590_Free_Memory_Not_on_Heap__free_long_static_67b_case1V1Sink(CWE590_Free_Memory_Not_on_Heap__free_long_static_67_structType myStruct)
{
    long * data = myStruct.structFirst;
    printLongLine(data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITCASE1 */
