/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__wchar_t_malloc_83_case1V1.cpp
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: malloc Allocate data using malloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE401_Memory_Leak__wchar_t_malloc_83.h"

namespace CWE401_Memory_Leak__wchar_t_malloc_83
{
CWE401_Memory_Leak__wchar_t_malloc_83_case1V1::CWE401_Memory_Leak__wchar_t_malloc_83_case1V1(wchar_t * dataCopy)
{
    data = dataCopy;
    /* ALT: Use memory allocated on the stack with ALLOCA */
    data = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    /* Initialize and make use of data */
    wcscpy(data, L"A String");
    printWLine(data);
}

CWE401_Memory_Leak__wchar_t_malloc_83_case1V1::~CWE401_Memory_Leak__wchar_t_malloc_83_case1V1()
{
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}
}
#endif /* OMITCASE1 */
