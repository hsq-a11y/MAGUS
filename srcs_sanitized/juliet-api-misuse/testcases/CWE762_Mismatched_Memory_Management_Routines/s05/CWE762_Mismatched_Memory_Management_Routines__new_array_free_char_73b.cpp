/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_free_char_73b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_free.label.xml
Template File: sources-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new []
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: Deallocate data using delete []
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

using namespace std;

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_free_char_73
{

#ifndef OMITCASE0

void case0Sink(list<char *> dataList)
{
    /* copy data out of dataList */
    char * data = dataList.back();
    /* NOTE: Deallocate memory using free() - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(list<char *> dataList)
{
    char * data = dataList.back();
    /* NOTE: Deallocate memory using free() - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    free(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(list<char *> dataList)
{
    char * data = dataList.back();
    /* ALT: Deallocate the memory using delete [] */
    delete [] data;
}

#endif /* OMITCASE1 */

} /* close namespace */
