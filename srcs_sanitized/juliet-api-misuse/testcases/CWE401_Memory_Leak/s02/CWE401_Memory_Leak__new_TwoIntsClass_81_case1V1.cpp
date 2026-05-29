/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_TwoIntsClass_81_case1V1.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-81_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call delete on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE401_Memory_Leak__new_TwoIntsClass_81.h"

namespace CWE401_Memory_Leak__new_TwoIntsClass_81
{

void CWE401_Memory_Leak__new_TwoIntsClass_81_case1V1::action(TwoIntsClass * data) const
{
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

}
#endif /* OMITCASE1 */
