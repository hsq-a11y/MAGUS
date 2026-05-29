/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__int64_t_calloc_83_case1V2.cpp
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-83_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: calloc Allocate data using calloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE401_Memory_Leak__int64_t_calloc_83.h"

namespace CWE401_Memory_Leak__int64_t_calloc_83
{
CWE401_Memory_Leak__int64_t_calloc_83_case1V2::CWE401_Memory_Leak__int64_t_calloc_83_case1V2(int64_t * dataCopy)
{
    data = dataCopy;
    /* NOTE: Allocate memory on the heap */
    data = (int64_t *)calloc(100, sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    data[0] = 5LL;
    printLongLongLine(data[0]);
}

CWE401_Memory_Leak__int64_t_calloc_83_case1V2::~CWE401_Memory_Leak__int64_t_calloc_83_case1V2()
{
    /* ALT: Deallocate memory */
    free(data);
}
}
#endif /* OMITCASE1 */
