/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE676_Use_of_Potentially_Dangerous_Function__basic_01.cpp
Label Definition File: CWE676_Use_of_Potentially_Dangerous_Function__basic.label.xml
Template File: point-note-01.tmpl.cpp
*/
/*
 * @description
 * CWE: 676 Use of Potentially Dangerous Function
 * Sinks:
 *    Case1Sink: Use cin after specifying the length of the input
 *    Case0Sink : Use cin without specifying the length of the input
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <iostream>

using namespace std;

#define CHAR_BUFFER_SIZE 10

namespace CWE676_Use_of_Potentially_Dangerous_Function__basic_01
{

#ifndef OMITCASE0

void case0()
{
    {
        char charBuffer[CHAR_BUFFER_SIZE];
        /* NOTE: using cin in an inherently dangerous fashion */
        /* INCIDENTAL CWE120 Buffer Overflow since cin extraction is unbounded. */
        cin >> charBuffer;
        charBuffer[CHAR_BUFFER_SIZE-1] = '\0';
        printLine(charBuffer);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

static void case11()
{
    {
        char charBuffer[CHAR_BUFFER_SIZE];
        /* ALT: Use cin after specifying the length of the input */
        cin.width(CHAR_BUFFER_SIZE);
        cin >> charBuffer;
        charBuffer[CHAR_BUFFER_SIZE-1] = '\0';
        printLine(charBuffer);
    }
}

void case1()
{
    case11();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE676_Use_of_Potentially_Dangerous_Function__basic_01; /* so that we can use case1 and case0 easily */

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
