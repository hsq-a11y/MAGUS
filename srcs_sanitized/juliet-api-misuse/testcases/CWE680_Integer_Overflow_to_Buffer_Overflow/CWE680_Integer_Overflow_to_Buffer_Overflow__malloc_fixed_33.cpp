/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_33.cpp
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-33.tmpl.cpp
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * Case0Source: fixed Fixed value that will cause an integer overflow in the sink
 * Case1Source: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    Case0Sink : Attempt to allocate array using length value from source
 * Flow Variant: 33 Data flow: use of a C++ reference to data within the same function
 *
 * */

#include "std_testcase.h"

namespace CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_33
{

#ifndef OMITCASE0

void case0()
{
    int data;
    int &dataRef = data;
    /* Initialize data */
    data = -1;
    /* NOTE: Set data to a value that will cause an integer overflow in the call to malloc() in the sink */
    data = INT_MAX / 2 + 2; /* 1073741825 */
    /* NOTE: This value will cause the sink to only allocate 4 bytes of memory, however
     * the for loop will attempt to access indices 0-1073741824 */
    {
        int data = dataRef;
        {
            size_t i;
            int *intPointer;
            /* NOTE: if data * sizeof(int) > SIZE_MAX, overflows to a small value
             * so that the for loop doing the initialization causes a buffer overflow */
            intPointer = (int*)malloc(data * sizeof(int));
            if (intPointer == NULL) {exit(-1);}
            for (i = 0; i < (size_t)data; i++)
            {
                intPointer[i] = 0; /* Potentially writes beyond the boundary of intPointer */
            }
            printIntLine(intPointer[0]);
            free(intPointer);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1()
{
    int data;
    int &dataRef = data;
    /* Initialize data */
    data = -1;
    /* ALT: Set data to a relatively small number greater than zero */
    data = 20;
    {
        int data = dataRef;
        {
            size_t i;
            int *intPointer;
            /* NOTE: if data * sizeof(int) > SIZE_MAX, overflows to a small value
             * so that the for loop doing the initialization causes a buffer overflow */
            intPointer = (int*)malloc(data * sizeof(int));
            if (intPointer == NULL) {exit(-1);}
            for (i = 0; i < (size_t)data; i++)
            {
                intPointer[i] = 0; /* Potentially writes beyond the boundary of intPointer */
            }
            printIntLine(intPointer[0]);
            free(intPointer);
        }
    }
}

void case1()
{
    case1V1();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */
#ifdef INCLUDEMAIN

using namespace CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_33; /* so that we can use case1 and case0 easily */

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
