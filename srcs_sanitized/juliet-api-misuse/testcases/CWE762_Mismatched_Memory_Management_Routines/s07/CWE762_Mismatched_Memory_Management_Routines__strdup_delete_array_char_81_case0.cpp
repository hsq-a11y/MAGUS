/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_char_81_case0.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array.label.xml
Template File: sources-sinks-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using strdup()
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_char_81.h"

namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_char_81
{

void CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_char_81_case0::action(char * data) const
{
    /* NOTE: Deallocate memory using delete [] - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete [] data;
}

}
#endif /* OMITCASE0 */
