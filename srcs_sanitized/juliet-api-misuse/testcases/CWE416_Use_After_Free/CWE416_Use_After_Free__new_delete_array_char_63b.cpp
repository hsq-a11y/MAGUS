/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__new_delete_array_char_63b.cpp
Label Definition File: CWE416_Use_After_Free__new_delete_array.label.xml
Template File: sources-sinks-63b.tmpl.cpp
*/
/*
 * @description
 * CWE: 416 Use After Free
 * Case0Source:  Allocate data using new, initialize memory block, and Deallocate data using delete
 * Case1Source: Allocate data using new and initialize memory block
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Use data after delete[]
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE416_Use_After_Free__new_delete_array_char_63
{

#ifndef OMITCASE0

void case0Sink(char * * dataPtr)
{
    char * data = *dataPtr;
    /* NOTE: Use of data that may have been deleted */
    printLine(data);
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(char * * dataPtr)
{
    char * data = *dataPtr;
    /* NOTE: Use of data that may have been deleted */
    printLine(data);
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(char * * dataPtr)
{
    char * data = *dataPtr;
    /* ALT: Don't use data that may have been deleted already */
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    /* do nothing */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE1 */

} /* close namespace */
