/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_long_73a.cpp
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-73a.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using malloc() and Deallocate data using free()
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <wchar.h>

using namespace std;

namespace CWE415_Double_Free__malloc_free_long_73
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink(list<long *> dataList);

void case0()
{
    long * data;
    list<long *> dataList;
    /* Initialize data */
    data = NULL;
    data = (long *)malloc(100*sizeof(long));
    if (data == NULL) {exit(-1);}
    /* NOTE: Free data in the source - the case0 sink frees data as well */
    free(data);
    /* Put data in a list */
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    case0Sink(dataList);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(list<long *> dataList);

static void case1V1()
{
    long * data;
    list<long *> dataList;
    /* Initialize data */
    data = NULL;
    data = (long *)malloc(100*sizeof(long));
    if (data == NULL) {exit(-1);}
    /* ALT: Do NOT free data in the source - the case0 sink frees data */
    /* Put data in a list */
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    case1V1Sink(dataList);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(list<long *> dataList);

static void case1V2()
{
    long * data;
    list<long *> dataList;
    /* Initialize data */
    data = NULL;
    data = (long *)malloc(100*sizeof(long));
    if (data == NULL) {exit(-1);}
    /* NOTE: Free data in the source - the case0 sink frees data as well */
    free(data);
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    case1V2Sink(dataList);
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

using namespace CWE415_Double_Free__malloc_free_long_73; /* so that we can use case1 and case0 easily */

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
