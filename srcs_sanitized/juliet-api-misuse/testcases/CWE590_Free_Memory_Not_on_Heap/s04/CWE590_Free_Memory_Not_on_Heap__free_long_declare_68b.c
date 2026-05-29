/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_long_declare_68b.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: declare Data buffer is declared on the stack
 * Case1Source: Allocate memory on the heap
 * Sink:
 *    Case0Sink : Print then free data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern long * CWE590_Free_Memory_Not_on_Heap__free_long_declare_68_case0Data;
extern long * CWE590_Free_Memory_Not_on_Heap__free_long_declare_68_case1V1Data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

void CWE590_Free_Memory_Not_on_Heap__free_long_declare_68b_case0Sink()
{
    long * data = CWE590_Free_Memory_Not_on_Heap__free_long_declare_68_case0Data;
    printLongLine(data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE590_Free_Memory_Not_on_Heap__free_long_declare_68b_case1V1Sink()
{
    long * data = CWE590_Free_Memory_Not_on_Heap__free_long_declare_68_case1V1Data;
    printLongLine(data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITCASE1 */
