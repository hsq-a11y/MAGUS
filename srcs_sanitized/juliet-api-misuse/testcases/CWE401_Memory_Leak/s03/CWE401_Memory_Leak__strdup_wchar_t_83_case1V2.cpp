/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_wchar_t_83_case1V2.cpp
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-83_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using wcsdup()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE401_Memory_Leak__strdup_wchar_t_83.h"

namespace CWE401_Memory_Leak__strdup_wchar_t_83
{
CWE401_Memory_Leak__strdup_wchar_t_83_case1V2::CWE401_Memory_Leak__strdup_wchar_t_83_case1V2(wchar_t * dataCopy)
{
    data = dataCopy;
    {
        wchar_t myString[] = L"myString";
        /* NOTE: Allocate memory from the heap using a function that requires free() for deallocation */
        data = wcsdup(myString);
        /* Use data */
        printWLine(data);
    }
}

CWE401_Memory_Leak__strdup_wchar_t_83_case1V2::~CWE401_Memory_Leak__strdup_wchar_t_83_case1V2()
{
    /* ALT: Deallocate memory initialized in the source */
    free(data);
}
}
#endif /* OMITCASE1 */
