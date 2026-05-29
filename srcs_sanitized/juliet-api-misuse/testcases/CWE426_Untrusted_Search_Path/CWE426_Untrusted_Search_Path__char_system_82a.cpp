/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__char_system_82a.cpp
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-82a.tmpl.cpp
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * Case0Source:  Don't specify the full path in the OS command
 * Case1Source: Specify the full path in the OS command
 * Sinks: system
 *    Case0Sink : Execute the system function
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE426_Untrusted_Search_Path__char_system_82.h"

namespace CWE426_Untrusted_Search_Path__char_system_82
{

#ifndef OMITCASE0

void case0()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* NOTE: the full path is not specified */
    strcpy(data, CASE0_OS_COMMAND);
    CWE426_Untrusted_Search_Path__char_system_82_base* baseObject = new CWE426_Untrusted_Search_Path__char_system_82_case0;
    baseObject->action(data);
    delete baseObject;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* ALT: full path is specified */
    strcpy(data, CASE1_OS_COMMAND);
    CWE426_Untrusted_Search_Path__char_system_82_base* baseObject = new CWE426_Untrusted_Search_Path__char_system_82_case1V1;
    baseObject->action(data);
    delete baseObject;
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

using namespace CWE426_Untrusted_Search_Path__char_system_82; /* so that we can use case1 and case0 easily */

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
