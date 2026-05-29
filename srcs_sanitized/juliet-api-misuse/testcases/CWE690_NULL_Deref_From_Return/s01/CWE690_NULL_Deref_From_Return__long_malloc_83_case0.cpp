/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__long_malloc_83_case0.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: malloc Allocate data using malloc()
 * Sinks:
 *    Case1Sink: Check to see if the data allocation failed and if not, use data
 *    Case0Sink : Don't check for NULL and use data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE690_NULL_Deref_From_Return__long_malloc_83.h"

namespace CWE690_NULL_Deref_From_Return__long_malloc_83
{
CWE690_NULL_Deref_From_Return__long_malloc_83_case0::CWE690_NULL_Deref_From_Return__long_malloc_83_case0(long * dataCopy)
{
    data = dataCopy;
    /* NOTE: Allocate memory without checking if the memory allocation function failed */
    data = (long *)malloc(1*sizeof(long));
}

CWE690_NULL_Deref_From_Return__long_malloc_83_case0::~CWE690_NULL_Deref_From_Return__long_malloc_83_case0()
{
    /* NOTE: Initialize memory buffer without checking to see if the memory allocation function failed */
    data[0] = 5L;
    printLongLine(data[0]);
    free(data);
}
}
#endif /* OMITCASE0 */
