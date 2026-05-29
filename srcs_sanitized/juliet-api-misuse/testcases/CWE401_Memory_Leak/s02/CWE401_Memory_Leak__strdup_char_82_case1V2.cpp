/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_char_82_case1V2.cpp
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-82_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using strdup()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE401_Memory_Leak__strdup_char_82.h"

namespace CWE401_Memory_Leak__strdup_char_82
{

void CWE401_Memory_Leak__strdup_char_82_case1V2::action(char * data)
{
    /* ALT: Deallocate memory initialized in the source */
    free(data);
}

}
#endif /* OMITCASE1 */
