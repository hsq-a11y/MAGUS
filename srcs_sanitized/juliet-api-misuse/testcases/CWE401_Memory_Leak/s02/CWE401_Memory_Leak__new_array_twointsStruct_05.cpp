/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_twointsStruct_05.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-05.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using new[]
 * Case1Source: Point data to a stack buffer
 * Sinks:
 *    Case1Sink: call delete[] on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

namespace CWE401_Memory_Leak__new_array_twointsStruct_05
{

#ifndef OMITCASE0

void case0()
{
    twoIntsStruct * data;
    data = NULL;
    if(staticTrue)
    {
        /* NOTE: Allocate memory on the heap */
        data = new twoIntsStruct[100];
        /* Initialize and make use of data */
        data[0].intOne = 0;
        data[0].intTwo = 0;
        printStructLine(&data[0]);
    }
    if(staticTrue)
    {
        /* NOTE: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V21() - use case0source and case1sink by changing the second staticTrue to staticFalse */
static void case1V21()
{
    twoIntsStruct * data;
    data = NULL;
    if(staticTrue)
    {
        /* NOTE: Allocate memory on the heap */
        data = new twoIntsStruct[100];
        /* Initialize and make use of data */
        data[0].intOne = 0;
        data[0].intTwo = 0;
        printStructLine(&data[0]);
    }
    if(staticFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Deallocate memory */
        delete[] data;
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the second if */
static void case1V22()
{
    twoIntsStruct * data;
    data = NULL;
    if(staticTrue)
    {
        /* NOTE: Allocate memory on the heap */
        data = new twoIntsStruct[100];
        /* Initialize and make use of data */
        data[0].intOne = 0;
        data[0].intTwo = 0;
        printStructLine(&data[0]);
    }
    if(staticTrue)
    {
        /* ALT: Deallocate memory */
        delete[] data;
    }
}

/* case1V11() - use case1source and case0sink by changing the first staticTrue to staticFalse */
static void case1V11()
{
    twoIntsStruct * data;
    data = NULL;
    if(staticFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Use memory allocated on the stack */
        twoIntsStruct dataCase1Buffer[100];
        data = dataCase1Buffer;
        /* Initialize and make use of data */
        data[0].intOne = 0;
        data[0].intTwo = 0;
        printStructLine(&data[0]);
    }
    if(staticTrue)
    {
        /* NOTE: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the first if */
static void case1V12()
{
    twoIntsStruct * data;
    data = NULL;
    if(staticTrue)
    {
        /* ALT: Use memory allocated on the stack */
        twoIntsStruct dataCase1Buffer[100];
        data = dataCase1Buffer;
        /* Initialize and make use of data */
        data[0].intOne = 0;
        data[0].intTwo = 0;
        printStructLine(&data[0]);
    }
    if(staticTrue)
    {
        /* NOTE: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

void case1()
{
    case1V21();
    case1V22();
    case1V11();
    case1V12();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__new_array_twointsStruct_05; /* so that we can use case1 and case0 easily */

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
