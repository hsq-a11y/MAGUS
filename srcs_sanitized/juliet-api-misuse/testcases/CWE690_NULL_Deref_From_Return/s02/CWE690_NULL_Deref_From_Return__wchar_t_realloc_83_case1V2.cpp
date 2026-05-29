/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__wchar_t_realloc_83_case1V2.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-83_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: realloc Allocate data using realloc()
 * Sinks:
 *    Case1Sink: Check to see if the data allocation failed and if not, use data
 *    Case0Sink : Don't check for NULL and use data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE690_NULL_Deref_From_Return__wchar_t_realloc_83.h"

namespace CWE690_NULL_Deref_From_Return__wchar_t_realloc_83
{
CWE690_NULL_Deref_From_Return__wchar_t_realloc_83_case1V2::CWE690_NULL_Deref_From_Return__wchar_t_realloc_83_case1V2(wchar_t * dataCopy)
{
    data = dataCopy;
    /* NOTE: Allocate memory without checking if the memory allocation function failed */
    data = (wchar_t *)realloc(data, 20*sizeof(wchar_t));
}

CWE690_NULL_Deref_From_Return__wchar_t_realloc_83_case1V2::~CWE690_NULL_Deref_From_Return__wchar_t_realloc_83_case1V2()
{
    /* ALT: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        wcscpy(data, L"Initialize");
        printWLine(data);
        free(data);
    }
}
}
#endif /* OMITCASE1 */
