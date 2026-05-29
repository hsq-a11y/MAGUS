/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_int_static_53d.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-53d.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: static Data buffer is declared static on the stack
 * Case1Source: Allocate memory on the heap
 * Sink:
 *    Case0Sink : Print then free data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

void CWE590_Free_Memory_Not_on_Heap__free_int_static_53d_case0Sink(int * data)
{
    printIntLine(data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE590_Free_Memory_Not_on_Heap__free_int_static_53d_case1V1Sink(int * data)
{
    printIntLine(data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITCASE1 */
