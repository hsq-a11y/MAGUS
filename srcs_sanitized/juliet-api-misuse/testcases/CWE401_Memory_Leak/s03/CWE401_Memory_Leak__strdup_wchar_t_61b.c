/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_wchar_t_61b.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using wcsdup()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

wchar_t * CWE401_Memory_Leak__strdup_wchar_t_61b_case0Source(wchar_t * data)
{
    {
        wchar_t myString[] = L"myString";
        /* NOTE: Allocate memory from the heap using a function that requires free() for deallocation */
        data = wcsdup(myString);
        /* Use data */
        printWLine(data);
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
wchar_t * CWE401_Memory_Leak__strdup_wchar_t_61b_case1V1Source(wchar_t * data)
{
    /* ALT: Use memory allocated on the stack with ALLOCA */
    data = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    /* Initialize then use data */
    wcscpy(data, L"a string");
    printWLine(data);
    return data;
}

/* case1V2() uses the Case0Source with the Case1Sink */
wchar_t * CWE401_Memory_Leak__strdup_wchar_t_61b_case1V2Source(wchar_t * data)
{
    {
        wchar_t myString[] = L"myString";
        /* NOTE: Allocate memory from the heap using a function that requires free() for deallocation */
        data = wcsdup(myString);
        /* Use data */
        printWLine(data);
    }
    return data;
}

#endif /* OMITCASE1 */
