/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__wchar_t_alloca_memcpy_74a.cpp
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-74a.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * Case0Source:  Set data pointer to a small buffer
 * Case1Source: Set data pointer to a large buffer
 * Sinks: memcpy
 *    Case0Sink : Copy data to string using memcpy
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

#include <wchar.h>

using namespace std;

namespace CWE126_Buffer_Overread__wchar_t_alloca_memcpy_74
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink(map<int, wchar_t *> dataMap);

void case0()
{
    wchar_t * data;
    map<int, wchar_t *> dataMap;
    wchar_t * dataCase0Buffer = (wchar_t *)ALLOCA(50*sizeof(wchar_t));
    wchar_t * dataCase1Buffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    wmemset(dataCase0Buffer, L'A', 50-1); /* fill with 'A's */
    dataCase0Buffer[50-1] = L'\0'; /* null terminate */
    wmemset(dataCase1Buffer, L'A', 100-1); /* fill with 'A's */
    dataCase1Buffer[100-1] = L'\0'; /* null terminate */
    /* NOTE: Set data pointer to a small buffer */
    data = dataCase0Buffer;
    /* Put data in a map */
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    case0Sink(dataMap);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declarations */

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(map<int, wchar_t *> dataMap);

static void case1V1()
{
    wchar_t * data;
    map<int, wchar_t *> dataMap;
    wchar_t * dataCase0Buffer = (wchar_t *)ALLOCA(50*sizeof(wchar_t));
    wchar_t * dataCase1Buffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    wmemset(dataCase0Buffer, L'A', 50-1); /* fill with 'A's */
    dataCase0Buffer[50-1] = L'\0'; /* null terminate */
    wmemset(dataCase1Buffer, L'A', 100-1); /* fill with 'A's */
    dataCase1Buffer[100-1] = L'\0'; /* null terminate */
    /* ALT: Set data pointer to a large buffer */
    data = dataCase1Buffer;
    /* Put data in a map */
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    case1V1Sink(dataMap);
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

using namespace CWE126_Buffer_Overread__wchar_t_alloca_memcpy_74; /* so that we can use case1 and case0 easily */

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
