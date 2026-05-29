/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_ncat_81a.cpp
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-81a.tmpl.cpp
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 * Sinks: ncat
 *    Case0Sink : Copy string to data using strncat
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE665_Improper_Initialization__char_ncat_81.h"

namespace CWE665_Improper_Initialization__char_ncat_81
{

#ifndef OMITCASE0

void case0()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    /* NOTE: Do not initialize data */
    ; /* empty statement needed for some flow variants */
    const CWE665_Improper_Initialization__char_ncat_81_base& baseObject = CWE665_Improper_Initialization__char_ncat_81_case0();
    baseObject.action(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    /* ALT: Properly initialize data */
    data[0] = '\0'; /* null terminate */
    const CWE665_Improper_Initialization__char_ncat_81_base& baseObject = CWE665_Improper_Initialization__char_ncat_81_case1V1();
    baseObject.action(data);
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

using namespace CWE665_Improper_Initialization__char_ncat_81; /* so that we can use case1 and case0 easily */

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
