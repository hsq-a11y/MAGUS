/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_twoIntsStruct_74a.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-74a.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call delete on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

#ifndef _WIN32
#include <wchar.h>
#endif

using namespace std;

namespace CWE401_Memory_Leak__new_twoIntsStruct_74
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink(map<int, twoIntsStruct *> dataMap);

void case0()
{
    twoIntsStruct * data;
    map<int, twoIntsStruct *> dataMap;
    data = NULL;
    /* NOTE: Allocate memory on the heap */
    data = new twoIntsStruct;
    /* Initialize and make use of data */
    data->intOne = 0;
    data->intTwo = 0;
    printStructLine(data);
    /* Put data in a map */
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    case0Sink(dataMap);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(map<int, twoIntsStruct *> dataMap);

static void case1V1()
{
    twoIntsStruct * data;
    map<int, twoIntsStruct *> dataMap;
    data = NULL;
    /* ALT: Use memory allocated on the stack */
    twoIntsStruct dataCase1Buffer;
    data = &dataCase1Buffer;
    /* Initialize and make use of data */
    data->intOne = 0;
    data->intTwo = 0;
    printStructLine(data);
    /* Put data in a map */
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    case1V1Sink(dataMap);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(map<int, twoIntsStruct *> dataMap);

static void case1V2()
{
    twoIntsStruct * data;
    map<int, twoIntsStruct *> dataMap;
    data = NULL;
    /* NOTE: Allocate memory on the heap */
    data = new twoIntsStruct;
    /* Initialize and make use of data */
    data->intOne = 0;
    data->intTwo = 0;
    printStructLine(data);
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    case1V2Sink(dataMap);
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

using namespace CWE401_Memory_Leak__new_twoIntsStruct_74; /* so that we can use case1 and case0 easily */

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
