/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__new_delete_array_long_16.cpp
Label Definition File: CWE416_Use_After_Free__new_delete_array.label.xml
Template File: sources-sinks-16.tmpl.cpp
*/
/*
 * @description
 * CWE: 416 Use After Free
 * Case0Source:  Allocate data using new, initialize memory block, and Deallocate data using delete
 * Case1Source: Allocate data using new and initialize memory block
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Use data after delete[]
 * Flow Variant: 16 Control flow: while(1)
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE416_Use_After_Free__new_delete_array_long_16
{

#ifndef OMITCASE0

void case0()
{
    long * data;
    /* Initialize data */
    data = NULL;
    while(1)
    {
        data = new long[100];
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5L;
            }
        }
        /* NOTE: Delete data in the source - the case0 sink attempts to use data */
        delete [] data;
        break;
    }
    while(1)
    {
        /* NOTE: Use of data that may have been deleted */
        printLongLine(data[0]);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        break;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() - use case0source and case1sink by changing the sinks in the second while statement */
static void case1V2()
{
    long * data;
    /* Initialize data */
    data = NULL;
    while(1)
    {
        data = new long[100];
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5L;
            }
        }
        /* NOTE: Delete data in the source - the case0 sink attempts to use data */
        delete [] data;
        break;
    }
    while(1)
    {
        /* ALT: Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
        break;
    }
}

/* case1V1() - use case1source and case0sink by changing the sources in the first while statement */
static void case1V1()
{
    long * data;
    /* Initialize data */
    data = NULL;
    while(1)
    {
        data = new long[100];
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5L;
            }
        }
        /* ALT: Do not delete data in the source */
        break;
    }
    while(1)
    {
        /* NOTE: Use of data that may have been deleted */
        printLongLine(data[0]);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        break;
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

using namespace CWE416_Use_After_Free__new_delete_array_long_16; /* so that we can use case1 and case0 easily */

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
