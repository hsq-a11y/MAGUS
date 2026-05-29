/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_array_int64_t_alloca_68b.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete_array.label.xml
Template File: sources-sink-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: alloca Data buffer is allocated on the stack with alloca()
 * Case1Source: Allocate memory on the heap
 * Sink:
 *    Case0Sink : Print then free data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern int64_t * CWE590_Free_Memory_Not_on_Heap__delete_array_int64_t_alloca_68_case0Data;
extern int64_t * CWE590_Free_Memory_Not_on_Heap__delete_array_int64_t_alloca_68_case1V1Data;

namespace CWE590_Free_Memory_Not_on_Heap__delete_array_int64_t_alloca_68
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

void case0Sink()
{
    int64_t * data = CWE590_Free_Memory_Not_on_Heap__delete_array_int64_t_alloca_68_case0Data;
    printLongLongLine(data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink()
{
    int64_t * data = CWE590_Free_Memory_Not_on_Heap__delete_array_int64_t_alloca_68_case1V1Data;
    printLongLongLine(data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

#endif /* OMITCASE1 */

} /* close namespace */
