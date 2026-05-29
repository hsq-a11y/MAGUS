/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_memmove_66a.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193.label.xml
Template File: sources-sink-66a.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory for a string, but do not allocate space for NULL terminator
 * Case1Source: Allocate enough memory for a string and the NULL terminator
 * Sinks: memmove
 *    Case0Sink : Copy string to data using memmove()
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_memmove_66
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink(wchar_t * dataArray[]);

void case0()
{
    wchar_t * data;
    wchar_t * dataArray[5];
    data = NULL;
    /* NOTE: Did not leave space for a null terminator */
    data = new wchar_t[10];
    /* put data in array */
    dataArray[2] = data;
    case0Sink(dataArray);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declarations */

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(wchar_t * dataArray[]);

static void case1V1()
{
    wchar_t * data;
    wchar_t * dataArray[5];
    data = NULL;
    /* ALT: Allocate space for a null terminator */
    data = new wchar_t[10+1];
    dataArray[2] = data;
    case1V1Sink(dataArray);
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

using namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_memmove_66; /* so that we can use case1 and case0 easily */

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
