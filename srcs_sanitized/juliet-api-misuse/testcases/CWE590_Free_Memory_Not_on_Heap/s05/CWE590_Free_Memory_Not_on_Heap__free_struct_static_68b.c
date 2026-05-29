/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_struct_static_68b.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: static Data buffer is declared static on the stack
 * Case1Source: Allocate memory on the heap
 * Sink:
 *    Case0Sink : Print then free data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern twoIntsStruct * CWE590_Free_Memory_Not_on_Heap__free_struct_static_68_case0Data;
extern twoIntsStruct * CWE590_Free_Memory_Not_on_Heap__free_struct_static_68_case1V1Data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

void CWE590_Free_Memory_Not_on_Heap__free_struct_static_68b_case0Sink()
{
    twoIntsStruct * data = CWE590_Free_Memory_Not_on_Heap__free_struct_static_68_case0Data;
    printStructLine(&data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE590_Free_Memory_Not_on_Heap__free_struct_static_68b_case1V1Sink()
{
    twoIntsStruct * data = CWE590_Free_Memory_Not_on_Heap__free_struct_static_68_case1V1Data;
    printStructLine(&data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITCASE1 */
