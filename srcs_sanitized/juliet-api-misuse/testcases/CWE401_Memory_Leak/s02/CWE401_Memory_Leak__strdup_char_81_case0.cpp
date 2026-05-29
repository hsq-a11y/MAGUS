/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_char_81_case0.cpp
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using strdup()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE401_Memory_Leak__strdup_char_81.h"

namespace CWE401_Memory_Leak__strdup_char_81
{

void CWE401_Memory_Leak__strdup_char_81_case0::action(char * data) const
{
    /* NOTE: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

}
#endif /* OMITCASE0 */
