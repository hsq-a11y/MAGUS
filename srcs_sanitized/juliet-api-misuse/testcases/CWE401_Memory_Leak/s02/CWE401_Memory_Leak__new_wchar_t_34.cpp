/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_wchar_t_34.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-34.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call delete on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_wchar_t_34
{

typedef union
{
    wchar_t * unionFirst;
    wchar_t * unionSecond;
} unionType;

#ifndef OMITCASE0

void case0()
{
    wchar_t * data;
    unionType myUnion;
    data = NULL;
    /* NOTE: Allocate memory on the heap */
    data = new wchar_t;
    /* Initialize and make use of data */
    *data = L'A';
    printHexCharLine((char)*data);
    myUnion.unionFirst = data;
    {
        wchar_t * data = myUnion.unionSecond;
        /* NOTE: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1()
{
    wchar_t * data;
    unionType myUnion;
    data = NULL;
    /* ALT: Use memory allocated on the stack */
    wchar_t dataCase1Buffer;
    data = &dataCase1Buffer;
    /* Initialize and make use of data */
    *data = L'A';
    printHexCharLine((char)*data);
    myUnion.unionFirst = data;
    {
        wchar_t * data = myUnion.unionSecond;
        /* NOTE: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

/* case1V2() uses the Case0Source with the Case1Sink */
static void case1V2()
{
    wchar_t * data;
    unionType myUnion;
    data = NULL;
    /* NOTE: Allocate memory on the heap */
    data = new wchar_t;
    /* Initialize and make use of data */
    *data = L'A';
    printHexCharLine((char)*data);
    myUnion.unionFirst = data;
    {
        wchar_t * data = myUnion.unionSecond;
        /* ALT: Deallocate memory */
        delete data;
    }
}

void case1()
{
    case1V1();
    case1V2();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__new_wchar_t_34; /* so that we can use case1 and case0 easily */

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
