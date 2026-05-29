/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_char_65a.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-65a.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using new[]
 * Case1Source: Point data to a stack buffer
 * Sinks:
 *    Case1Sink: call delete[] on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_array_char_65
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink(char * data);

void case0()
{
    char * data;
    /* define a function pointer */
    void (*funcPtr) (char *) = case0Sink;
    data = NULL;
    /* NOTE: Allocate memory on the heap */
    data = new char[100];
    /* Initialize and make use of data */
    strcpy(data, "A String");
    printLine(data);
    /* use the function pointer */
    funcPtr(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(char * data);

static void case1V1()
{
    char * data;
    void (*funcPtr) (char *) = case1V1Sink;
    data = NULL;
    /* ALT: Use memory allocated on the stack */
    char dataCase1Buffer[100];
    data = dataCase1Buffer;
    /* Initialize and make use of data */
    strcpy(data, "A String");
    printLine(data);
    funcPtr(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(char * data);

static void case1V2()
{
    char * data;
    void (*funcPtr) (char *) = case1V2Sink;
    data = NULL;
    /* NOTE: Allocate memory on the heap */
    data = new char[100];
    /* Initialize and make use of data */
    strcpy(data, "A String");
    printLine(data);
    funcPtr(data);
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

using namespace CWE401_Memory_Leak__new_array_char_65; /* so that we can use case1 and case0 easily */

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
