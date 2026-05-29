/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_int_declare_64a.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-64a.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: declare Data buffer is declared on the stack
 * Case1Source: Allocate memory on the heap
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* case0 function declaration */
void CWE590_Free_Memory_Not_on_Heap__free_int_declare_64b_case0Sink(void * dataVoidPtr);

void CWE590_Free_Memory_Not_on_Heap__free_int_declare_64_case0()
{
    int * data;
    data = NULL; /* Initialize data */
    {
        /* NOTE: data is allocated on the stack and deallocated in the Case0Sink */
        int dataBuffer[100];
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                dataBuffer[i] = 5;
            }
        }
        data = dataBuffer;
    }
    CWE590_Free_Memory_Not_on_Heap__free_int_declare_64b_case0Sink(&data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE590_Free_Memory_Not_on_Heap__free_int_declare_64b_case1V1Sink(void * dataVoidPtr);

static void case1V1()
{
    int * data;
    data = NULL; /* Initialize data */
    {
        /* ALT: data is allocated on the heap and deallocated in the Case0Sink */
        int * dataBuffer = (int *)malloc(100*sizeof(int));
        if (dataBuffer == NULL)
        {
            printLine("malloc() failed");
            exit(1);
        }
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                dataBuffer[i] = 5;
            }
        }
        data = dataBuffer;
    }
    CWE590_Free_Memory_Not_on_Heap__free_int_declare_64b_case1V1Sink(&data);
}

void CWE590_Free_Memory_Not_on_Heap__free_int_declare_64_case1()
{
    case1V1();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE590_Free_Memory_Not_on_Heap__free_int_declare_64_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE590_Free_Memory_Not_on_Heap__free_int_declare_64_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
