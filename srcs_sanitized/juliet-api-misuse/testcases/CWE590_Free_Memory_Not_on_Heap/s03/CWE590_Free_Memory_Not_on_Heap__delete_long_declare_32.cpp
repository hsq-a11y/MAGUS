/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_long_declare_32.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete.nonpointer.label.xml
Template File: sources-sink-32.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: declare Data buffer is declared on the stack
 * Case1Source: Allocate memory on the heap
 * Sink:
 *    Case0Sink : Print then free data
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Memory_Not_on_Heap__delete_long_declare_32
{

#ifndef OMITCASE0

void case0()
{
    long * data;
    long * *dataPtr1 = &data;
    long * *dataPtr2 = &data;
    data = NULL; /* Initialize data */
    {
        long * data = *dataPtr1;
        {
            /* NOTE: data is allocated on the stack and deallocated in the Case0Sink */
            long dataBuffer;
            dataBuffer = 5L;
            data = &dataBuffer;
        }
        *dataPtr1 = data;
    }
    {
        long * data = *dataPtr2;
        printLongLine(*data);
        /* NOTE: Possibly deallocating memory allocated on the stack */
        delete data;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1()
{
    long * data;
    long * *dataPtr1 = &data;
    long * *dataPtr2 = &data;
    data = NULL; /* Initialize data */
    {
        long * data = *dataPtr1;
        {
            /* ALT: data is allocated on the heap and deallocated in the Case0Sink */
            long * dataBuffer = new long;
            *dataBuffer = 5L;
            data = dataBuffer;
        }
        *dataPtr1 = data;
    }
    {
        long * data = *dataPtr2;
        printLongLine(*data);
        /* NOTE: Possibly deallocating memory allocated on the stack */
        delete data;
    }
}

void case1()
{
    case1V1();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

using namespace CWE590_Free_Memory_Not_on_Heap__delete_long_declare_32; /* so that we can use case1 and case0 easily */

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
