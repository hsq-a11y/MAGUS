/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__struct_twoIntsStruct_malloc_68b.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: malloc Allocate data using malloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern struct _twoIntsStruct * CWE401_Memory_Leak__struct_twoIntsStruct_malloc_68_case0Data;
extern struct _twoIntsStruct * CWE401_Memory_Leak__struct_twoIntsStruct_malloc_68_case1V1Data;
extern struct _twoIntsStruct * CWE401_Memory_Leak__struct_twoIntsStruct_malloc_68_case1V2Data;

#ifndef OMITCASE0

void CWE401_Memory_Leak__struct_twoIntsStruct_malloc_68b_case0Sink()
{
    struct _twoIntsStruct * data = CWE401_Memory_Leak__struct_twoIntsStruct_malloc_68_case0Data;
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE401_Memory_Leak__struct_twoIntsStruct_malloc_68b_case1V1Sink()
{
    struct _twoIntsStruct * data = CWE401_Memory_Leak__struct_twoIntsStruct_malloc_68_case1V1Data;
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE401_Memory_Leak__struct_twoIntsStruct_malloc_68b_case1V2Sink()
{
    struct _twoIntsStruct * data = CWE401_Memory_Leak__struct_twoIntsStruct_malloc_68_case1V2Data;
    /* ALT: Deallocate memory */
    free(data);
}

#endif /* OMITCASE1 */
