/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_int64_t_12.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-12.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call delete on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_int64_t_12
{

#ifndef OMITCASE0

void case0()
{
    int64_t * data;
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        /* NOTE: Allocate memory on the heap */
        data = new int64_t;
        /* Initialize and make use of data */
        *data = 5LL;
        printLongLongLine(*data);
    }
    else
    {
        /* ALT: Use memory allocated on the stack */
        int64_t dataCase1Buffer;
        data = &dataCase1Buffer;
        /* Initialize and make use of data */
        *data = 5LL;
        printLongLongLine(*data);
    }
    if(globalReturnsTrueOrFalse())
    {
        /* NOTE: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* ALT: Deallocate memory */
        delete data;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() - use case0source and case1sink by changing the first "if" so that
   both branches use the Case0Source and the second "if" so that both branches
   use the Case1Sink */
static void case1V2()
{
    int64_t * data;
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        /* NOTE: Allocate memory on the heap */
        data = new int64_t;
        /* Initialize and make use of data */
        *data = 5LL;
        printLongLongLine(*data);
    }
    else
    {
        /* NOTE: Allocate memory on the heap */
        data = new int64_t;
        /* Initialize and make use of data */
        *data = 5LL;
        printLongLongLine(*data);
    }
    if(globalReturnsTrueOrFalse())
    {
        /* ALT: Deallocate memory */
        delete data;
    }
    else
    {
        /* ALT: Deallocate memory */
        delete data;
    }
}

/* case1V1() - use case1source and case0sink by changing the first "if" so that
   both branches use the Case1Source and the second "if" so that both branches
   use the Case0Sink */
static void case1V1()
{
    int64_t * data;
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        /* ALT: Use memory allocated on the stack */
        int64_t dataCase1Buffer;
        data = &dataCase1Buffer;
        /* Initialize and make use of data */
        *data = 5LL;
        printLongLongLine(*data);
    }
    else
    {
        /* ALT: Use memory allocated on the stack */
        int64_t dataCase1Buffer;
        data = &dataCase1Buffer;
        /* Initialize and make use of data */
        *data = 5LL;
        printLongLongLine(*data);
    }
    if(globalReturnsTrueOrFalse())
    {
        /* NOTE: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
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

using namespace CWE401_Memory_Leak__new_int64_t_12; /* so that we can use case1 and case0 easily */

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
