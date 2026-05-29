/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_char_61b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array.label.xml
Template File: sources-sinks-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using strdup()
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_char_61
{

#ifndef OMITCASE0

char * case0Source(char * data)
{
    {
        char myString[] = "myString";
        /* NOTE: Allocate memory with a function that requires free() to free the memory */
        data = strdup(myString);
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
char * case1V1Source(char * data)
{
    /* ALT: Allocate memory from the heap using new [] */
    data = new char[100];
    return data;
}

/* case1V2() uses the Case0Source with the Case1Sink */
char * case1V2Source(char * data)
{
    {
        char myString[] = "myString";
        /* NOTE: Allocate memory with a function that requires free() to free the memory */
        data = strdup(myString);
    }
    return data;
}

#endif /* OMITCASE1 */

} /* close namespace */
