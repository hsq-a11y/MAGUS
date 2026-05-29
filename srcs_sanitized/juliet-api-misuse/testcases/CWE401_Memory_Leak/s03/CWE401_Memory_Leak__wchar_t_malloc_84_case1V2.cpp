/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__wchar_t_malloc_84_case1V2.cpp
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-84_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: malloc Allocate data using malloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE401_Memory_Leak__wchar_t_malloc_84.h"

namespace CWE401_Memory_Leak__wchar_t_malloc_84
{
CWE401_Memory_Leak__wchar_t_malloc_84_case1V2::CWE401_Memory_Leak__wchar_t_malloc_84_case1V2(wchar_t * dataCopy)
{
    data = dataCopy;
    /* NOTE: Allocate memory on the heap */
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    wcscpy(data, L"A String");
    printWLine(data);
}

CWE401_Memory_Leak__wchar_t_malloc_84_case1V2::~CWE401_Memory_Leak__wchar_t_malloc_84_case1V2()
{
    /* ALT: Deallocate memory */
    free(data);
}
}
#endif /* OMITCASE1 */
