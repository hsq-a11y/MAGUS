/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_wchar_t_65b.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-65b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using wcsdup()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

void CWE401_Memory_Leak__strdup_wchar_t_65b_case0Sink(wchar_t * data)
{
    /* NOTE: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE401_Memory_Leak__strdup_wchar_t_65b_case1V1Sink(wchar_t * data)
{
    /* NOTE: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE401_Memory_Leak__strdup_wchar_t_65b_case1V2Sink(wchar_t * data)
{
    /* ALT: Deallocate memory initialized in the source */
    free(data);
}

#endif /* OMITCASE1 */
