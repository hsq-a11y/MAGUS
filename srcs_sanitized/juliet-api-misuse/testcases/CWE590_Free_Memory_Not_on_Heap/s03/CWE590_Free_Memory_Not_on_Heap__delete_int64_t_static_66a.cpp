/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_int64_t_static_66a.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete.nonpointer.label.xml
Template File: sources-sink-66a.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: static Data buffer is declared static on the stack
 * Case1Source: Allocate memory on the heap
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Memory_Not_on_Heap__delete_int64_t_static_66
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink(int64_t * dataArray[]);

void case0()
{
    int64_t * data;
    int64_t * dataArray[5];
    data = NULL; /* Initialize data */
    {
        /* NOTE: data is allocated on the stack and deallocated in the Case0Sink */
        static int64_t dataBuffer;
        dataBuffer = 5LL;
        data = &dataBuffer;
    }
    /* put data in array */
    dataArray[2] = data;
    case0Sink(dataArray);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declarations */

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(int64_t * dataArray[]);

static void case1V1()
{
    int64_t * data;
    int64_t * dataArray[5];
    data = NULL; /* Initialize data */
    {
        /* ALT: data is allocated on the heap and deallocated in the Case0Sink */
        int64_t * dataBuffer = new int64_t;
        *dataBuffer = 5LL;
        data = dataBuffer;
    }
    dataArray[2] = data;
    case1V1Sink(dataArray);
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

using namespace CWE590_Free_Memory_Not_on_Heap__delete_int64_t_static_66; /* so that we can use case1 and case0 easily */

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
