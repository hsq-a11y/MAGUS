/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_char_67b.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using strdup()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE401_Memory_Leak__strdup_char_67_structType
{
    char * structFirst;
} CWE401_Memory_Leak__strdup_char_67_structType;

#ifndef OMITCASE0

void CWE401_Memory_Leak__strdup_char_67b_case0Sink(CWE401_Memory_Leak__strdup_char_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    /* NOTE: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE401_Memory_Leak__strdup_char_67b_case1V1Sink(CWE401_Memory_Leak__strdup_char_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    /* NOTE: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE401_Memory_Leak__strdup_char_67b_case1V2Sink(CWE401_Memory_Leak__strdup_char_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    /* ALT: Deallocate memory initialized in the source */
    free(data);
}

#endif /* OMITCASE1 */
