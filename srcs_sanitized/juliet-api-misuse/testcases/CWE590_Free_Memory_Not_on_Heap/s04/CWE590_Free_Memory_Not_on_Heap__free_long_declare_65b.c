/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_long_declare_65b.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-65b.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: declare Data buffer is declared on the stack
 * Case1Source: Allocate memory on the heap
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

void CWE590_Free_Memory_Not_on_Heap__free_long_declare_65b_case0Sink(long * data)
{
    printLongLine(data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE590_Free_Memory_Not_on_Heap__free_long_declare_65b_case1V1Sink(long * data)
{
    printLongLine(data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITCASE1 */
