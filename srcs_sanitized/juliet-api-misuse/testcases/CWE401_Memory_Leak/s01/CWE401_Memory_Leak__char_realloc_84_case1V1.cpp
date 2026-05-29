/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__char_realloc_84_case1V1.cpp
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: realloc Allocate data using realloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE401_Memory_Leak__char_realloc_84.h"

namespace CWE401_Memory_Leak__char_realloc_84
{
CWE401_Memory_Leak__char_realloc_84_case1V1::CWE401_Memory_Leak__char_realloc_84_case1V1(char * dataCopy)
{
    data = dataCopy;
    /* ALT: Use memory allocated on the stack with ALLOCA */
    data = (char *)ALLOCA(100*sizeof(char));
    /* Initialize and make use of data */
    strcpy(data, "A String");
    printLine(data);
}

CWE401_Memory_Leak__char_realloc_84_case1V1::~CWE401_Memory_Leak__char_realloc_84_case1V1()
{
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}
}
#endif /* OMITCASE1 */
