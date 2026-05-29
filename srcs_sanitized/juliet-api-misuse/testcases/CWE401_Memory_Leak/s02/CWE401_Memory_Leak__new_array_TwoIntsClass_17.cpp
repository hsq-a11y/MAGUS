/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_TwoIntsClass_17.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-17.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using new[]
 * Case1Source: Point data to a stack buffer
 * Sinks:
 *    Case1Sink: call delete[] on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 17 Control flow: for loops
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_array_TwoIntsClass_17
{

#ifndef OMITCASE0

void case0()
{
    int i,j;
    TwoIntsClass * data;
    data = NULL;
    for(i = 0; i < 1; i++)
    {
        /* NOTE: Allocate memory on the heap */
        data = new TwoIntsClass[100];
        /* Initialize and make use of data */
        data[0].intOne = 0;
        data[0].intTwo = 0;
        printIntLine(data[0].intOne);
        printIntLine(data[0].intTwo);
    }
    for(j = 0; j < 1; j++)
    {
        /* NOTE: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() - use case0source and case1sink in the for statements */
static void case1V2()
{
    int i,k;
    TwoIntsClass * data;
    data = NULL;
    for(i = 0; i < 1; i++)
    {
        /* NOTE: Allocate memory on the heap */
        data = new TwoIntsClass[100];
        /* Initialize and make use of data */
        data[0].intOne = 0;
        data[0].intTwo = 0;
        printIntLine(data[0].intOne);
        printIntLine(data[0].intTwo);
    }
    for(k = 0; k < 1; k++)
    {
        /* ALT: Deallocate memory */
        delete[] data;
    }
}

/* case1V1() - use case1source and case0sink in the for statements */
static void case1V1()
{
    int h,j;
    TwoIntsClass * data;
    data = NULL;
    for(h = 0; h < 1; h++)
    {
        /* ALT: Use memory allocated on the stack */
        TwoIntsClass dataCase1Buffer[100];
        data = dataCase1Buffer;
        /* Initialize and make use of data */
        data[0].intOne = 0;
        data[0].intTwo = 0;
        printIntLine(data[0].intOne);
        printIntLine(data[0].intTwo);
    }
    for(j = 0; j < 1; j++)
    {
        /* NOTE: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

void case1()
{
    case1V2();
    case1V1();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__new_array_TwoIntsClass_17; /* so that we can use case1 and case0 easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
