/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_74a.cpp
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-74a.tmpl.cpp
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: fopen Open a file using fopen()
 * Sinks: w32CloseHandle
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using CloseHandle
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

using namespace std;

namespace CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_74
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink(map<int, FILE *> dataMap);

void case0()
{
    FILE * data;
    map<int, FILE *> dataMap;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = fopen("Case0Source_fopen.txt", "w+");
    /* Put data in a map */
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    case0Sink(dataMap);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(map<int, FILE *> dataMap);

static void case1V2()
{
    FILE * data;
    map<int, FILE *> dataMap;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = fopen("Case0Source_fopen.txt", "w+");
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    case1V2Sink(dataMap);
}

void case1()
{
    case1V2();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_74; /* so that we can use case1 and case0 easily */

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
