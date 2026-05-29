/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__struct_twoIntsStruct_malloc_61b.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: malloc Allocate data using malloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

struct _twoIntsStruct * CWE401_Memory_Leak__struct_twoIntsStruct_malloc_61b_case0Source(struct _twoIntsStruct * data)
{

    /* NOTE: Allocate memory on the heap */
    data = (struct _twoIntsStruct *)malloc(100*sizeof(struct _twoIntsStruct));
    if (data == NULL) {exit(-1);}

    /* Initialize and make use of data */

    data[0].intOne = 0;
    data[0].intTwo = 0;

    printStructLine((twoIntsStruct *)&data[0]);

    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
struct _twoIntsStruct * CWE401_Memory_Leak__struct_twoIntsStruct_malloc_61b_case1V1Source(struct _twoIntsStruct * data)
{

    /* ALT: Use memory allocated on the stack with ALLOCA */
    data = (struct _twoIntsStruct *)ALLOCA(100*sizeof(struct _twoIntsStruct));

    /* Initialize and make use of data */

    data[0].intOne = 0;
    data[0].intTwo = 0;

    printStructLine((twoIntsStruct *)&data[0]);

    return data;
}

/* case1V2() uses the Case0Source with the Case1Sink */
struct _twoIntsStruct * CWE401_Memory_Leak__struct_twoIntsStruct_malloc_61b_case1V2Source(struct _twoIntsStruct * data)
{

    /* NOTE: Allocate memory on the heap */
    data = (struct _twoIntsStruct *)malloc(100*sizeof(struct _twoIntsStruct));
    if (data == NULL) {exit(-1);}

    /* Initialize and make use of data */

    data[0].intOne = 0;
    data[0].intTwo = 0;

    printStructLine((twoIntsStruct *)&data[0]);

    return data;
}

#endif /* OMITCASE1 */
