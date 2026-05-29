/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_char_62b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__strdup_delete.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using strdup()
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_char_62
{

#ifndef OMITCASE0

void case0Source(char * &data)
{
    {
        char myString[] = "myString";
        /* NOTE: Allocate memory from the heap using a function that requires free() for deallocation */
        data = strdup(myString);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
void case1V1Source(char * &data)
{
    /* ALT: Allocate memory from the heap using new */
    data = new char;
}

/* case1V2() uses the Case0Source with the Case1Sink */
void case1V2Source(char * &data)
{
    {
        char myString[] = "myString";
        /* NOTE: Allocate memory from the heap using a function that requires free() for deallocation */
        data = strdup(myString);
    }
}

#endif /* OMITCASE1 */

} /* close namespace */
