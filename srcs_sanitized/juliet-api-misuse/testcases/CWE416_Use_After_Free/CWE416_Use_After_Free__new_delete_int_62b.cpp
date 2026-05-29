/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__new_delete_int_62b.cpp
Label Definition File: CWE416_Use_After_Free__new_delete.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 416 Use After Free
 * Case0Source:  Allocate data using new, initialize memory block, and Deallocate data using delete
 * Case1Source: Allocate data using new and initialize memory block
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Use data after delete
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE416_Use_After_Free__new_delete_int_62
{

#ifndef OMITCASE0

void case0Source(int * &data)
{
    data = new int;
    *data = 5;
    /* NOTE: Delete data in the source - the case0 sink attempts to use data */
    delete data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
void case1V1Source(int * &data)
{
    data = new int;
    *data = 5;
    /* ALT: Do not delete data in the source */
}

/* case1V2() uses the Case0Source with the Case1Sink */
void case1V2Source(int * &data)
{
    data = new int;
    *data = 5;
    /* NOTE: Delete data in the source - the case0 sink attempts to use data */
    delete data;
}

#endif /* OMITCASE1 */

} /* close namespace */
