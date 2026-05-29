/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_char_61b.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using new and Deallocae data using delete
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_array_char_61
{

#ifndef OMITCASE0

char * case0Source(char * data)
{
    data = new char[100];
    /* NOTE: delete the array data in the source - the case0 sink deletes the array data as well */
    delete [] data;
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
char * case1V1Source(char * data)
{
    data = new char[100];
    /* ALT: Do NOT delete the array data in the source - the case0 sink deletes the array data */
    return data;
}

/* case1V2() uses the Case0Source with the Case1Sink */
char * case1V2Source(char * data)
{
    data = new char[100];
    /* NOTE: delete the array data in the source - the case0 sink deletes the array data as well */
    delete [] data;
    return data;
}

#endif /* OMITCASE1 */

} /* close namespace */
