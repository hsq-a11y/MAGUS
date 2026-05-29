/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84a.cpp
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-84a.tmpl.cpp
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using CreateFile()
 * Sinks: fclose
 *    Case1Sink: Close the file using CloseHandle()
 *    Case0Sink : Close the file using fclose()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84.h"

namespace CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84
{

#ifndef OMITCASE0

void case0()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84_case0 * case0Object = new CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84_case0(data);
    delete case0Object;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
static void case1V2()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84_case1V2 * case1V2Object = new CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84_case1V2(data);
    delete case1V2Object;
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

using namespace CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84; /* so that we can use case1 and case0 easily */

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
