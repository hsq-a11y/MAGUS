/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_int64_t_placement_new_13.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete.pointer.label.xml
Template File: sources-sink-13.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: placement_new Data buffer is declared on the stack
 * Case1Source: Allocate memory on the heap
 * Sink:
 *    Case0Sink : Print then free data
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Memory_Not_on_Heap__delete_int64_t_placement_new_13
{

#ifndef OMITCASE0

void case0()
{
    int64_t * data;
    data = NULL; /* Initialize data */
    if(GLOBAL_CONST_FIVE==5)
    {
        {
            /* NOTE: data is allocated on the stack and deallocated in the Case0Sink */
            char buffer[sizeof(int64_t)];
            int64_t * dataBuffer = new(buffer) int64_t;
            *dataBuffer = 5LL;
            data = dataBuffer;
        }
    }
    printLongLongLine(*data);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    delete data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V11() - use case1source and case0sink by changing the GLOBAL_CONST_FIVE==5 to GLOBAL_CONST_FIVE!=5 */
static void case1V11()
{
    int64_t * data;
    data = NULL; /* Initialize data */
    if(GLOBAL_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            /* ALT: data is allocated on the heap and deallocated in the Case0Sink */
            int64_t * dataBuffer = new int64_t;
            *dataBuffer = 5LL;
            data = dataBuffer;
        }
    }
    printLongLongLine(*data);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    delete data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if statement */
static void case1V12()
{
    int64_t * data;
    data = NULL; /* Initialize data */
    if(GLOBAL_CONST_FIVE==5)
    {
        {
            /* ALT: data is allocated on the heap and deallocated in the Case0Sink */
            int64_t * dataBuffer = new int64_t;
            *dataBuffer = 5LL;
            data = dataBuffer;
        }
    }
    printLongLongLine(*data);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    delete data;
}

void case1()
{
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

using namespace CWE590_Free_Memory_Not_on_Heap__delete_int64_t_placement_new_13; /* so that we can use case1 and case0 easily */

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
