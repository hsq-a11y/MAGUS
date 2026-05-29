/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__int_malloc_83_case1V1.cpp
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
#include "CWE401_Memory_Leak__int_malloc_83.h"

namespace CWE401_Memory_Leak__int_malloc_83
{
CWE401_Memory_Leak__int_malloc_83_case1V1::CWE401_Memory_Leak__int_malloc_83_case1V1(int * dataCopy)
{
    data = dataCopy;
    /* ALT: Use memory allocated on the stack with ALLOCA */
    data = (int *)ALLOCA(100*sizeof(int));
    /* Initialize and make use of data */
    data[0] = 5;
    printIntLine(data[0]);
}

CWE401_Memory_Leak__int_malloc_83_case1V1::~CWE401_Memory_Leak__int_malloc_83_case1V1()
{
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}
}
#endif /* OMITCASE1 */
