/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__int64_t_malloc_81_case0.cpp
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: malloc Allocate data using malloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE401_Memory_Leak__int64_t_malloc_81.h"

namespace CWE401_Memory_Leak__int64_t_malloc_81
{

void CWE401_Memory_Leak__int64_t_malloc_81_case0::action(int64_t * data) const
{
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

}
#endif /* OMITCASE0 */
