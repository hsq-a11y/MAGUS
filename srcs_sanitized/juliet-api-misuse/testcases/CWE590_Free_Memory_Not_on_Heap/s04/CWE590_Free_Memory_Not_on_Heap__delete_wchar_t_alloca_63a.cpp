/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_wchar_t_alloca_63a.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete.pointer.label.xml
Template File: sources-sink-63a.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: alloca Data buffer is allocated on the stack with alloca()
 * Case1Source: Allocate memory on the heap
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Memory_Not_on_Heap__delete_wchar_t_alloca_63
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink(wchar_t * * dataPtr);

void case0()
{
    wchar_t * data;
    data = NULL; /* Initialize data */
    {
        /* NOTE: data is allocated on the stack and deallocated in the Case0Sink */
        wchar_t * dataBuffer = (wchar_t *)ALLOCA(sizeof(wchar_t));
        *dataBuffer = L'A';
        data = dataBuffer;
    }
    case0Sink(&data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(wchar_t * * data);

static void case1V1()
{
    wchar_t * data;
    data = NULL; /* Initialize data */
    {
        /* ALT: data is allocated on the heap and deallocated in the Case0Sink */
        wchar_t * dataBuffer = new wchar_t;
        *dataBuffer = L'A';
        data = dataBuffer;
    }
    case1V1Sink(&data);
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

using namespace CWE590_Free_Memory_Not_on_Heap__delete_wchar_t_alloca_63; /* so that we can use case1 and case0 easily */

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
