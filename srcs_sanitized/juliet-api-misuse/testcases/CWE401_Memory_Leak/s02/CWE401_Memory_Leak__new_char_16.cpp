/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_char_16.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-16.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call delete on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 16 Control flow: while(1)
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_char_16
{

#ifndef OMITCASE0

void case0()
{
    char * data;
    data = NULL;
    while(1)
    {
        /* NOTE: Allocate memory on the heap */
        data = new char;
        /* Initialize and make use of data */
        *data = 'A';
        printHexCharLine(*data);
        break;
    }
    while(1)
    {
        /* NOTE: No deallocation */
        ; /* empty statement needed for some flow variants */
        break;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() - use case0source and case1sink by changing the sinks in the second while statement */
static void case1V2()
{
    char * data;
    data = NULL;
    while(1)
    {
        /* NOTE: Allocate memory on the heap */
        data = new char;
        /* Initialize and make use of data */
        *data = 'A';
        printHexCharLine(*data);
        break;
    }
    while(1)
    {
        /* ALT: Deallocate memory */
        delete data;
        break;
    }
}

/* case1V1() - use case1source and case0sink by changing the sources in the first while statement */
static void case1V1()
{
    char * data;
    data = NULL;
    while(1)
    {
        /* ALT: Use memory allocated on the stack */
        char dataCase1Buffer;
        data = &dataCase1Buffer;
        /* Initialize and make use of data */
        *data = 'A';
        printHexCharLine(*data);
        break;
    }
    while(1)
    {
        /* NOTE: No deallocation */
        ; /* empty statement needed for some flow variants */
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

using namespace CWE401_Memory_Leak__new_char_16; /* so that we can use case1 and case0 easily */

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
