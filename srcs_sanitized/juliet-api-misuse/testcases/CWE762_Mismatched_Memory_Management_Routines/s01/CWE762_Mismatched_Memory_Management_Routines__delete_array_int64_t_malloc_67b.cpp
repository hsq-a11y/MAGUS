/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_malloc_67b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-67b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: malloc Allocate data using malloc()
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_malloc_67
{

typedef struct _structType
{
    int64_t * structFirst;
} structType;

#ifndef OMITCASE0

void case0Sink(structType myStruct)
{
    int64_t * data = myStruct.structFirst;
    /* NOTE: Deallocate memory using delete [] - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete [] data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(structType myStruct)
{
    int64_t * data = myStruct.structFirst;
    /* NOTE: Deallocate memory using delete [] - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete [] data;
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(structType myStruct)
{
    int64_t * data = myStruct.structFirst;
    /* ALT: Free memory using free() */
    free(data);
}

#endif /* OMITCASE1 */

} /* close namespace */
