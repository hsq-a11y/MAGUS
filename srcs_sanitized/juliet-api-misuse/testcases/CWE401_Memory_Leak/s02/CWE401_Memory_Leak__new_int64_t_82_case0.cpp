/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_int64_t_82_case0.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-82_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call delete on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE401_Memory_Leak__new_int64_t_82.h"

namespace CWE401_Memory_Leak__new_int64_t_82
{

void CWE401_Memory_Leak__new_int64_t_82_case0::action(int64_t * data)
{
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

}
#endif /* OMITCASE0 */
