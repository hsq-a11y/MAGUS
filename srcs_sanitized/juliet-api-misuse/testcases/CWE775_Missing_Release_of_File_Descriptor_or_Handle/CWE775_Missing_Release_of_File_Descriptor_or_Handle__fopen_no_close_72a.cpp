/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_72a.cpp
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close.label.xml
Template File: source-sinks-72a.tmpl.cpp
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using fopen()
 * Sinks:
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Do not close file
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

using namespace std;

namespace CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_72
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink(vector<FILE *> dataVector);

void case0()
{
    FILE * data;
    vector<FILE *> dataVector;
    data = NULL;
    /* NOTE: Open a file without closing it */
    data = fopen("Case0Source_fopen.txt", "w+");
    /* Put data in a vector */
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    case0Sink(dataVector);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(vector<FILE *> dataVector);

static void case1V2()
{
    FILE * data;
    vector<FILE *> dataVector;
    data = NULL;
    /* NOTE: Open a file without closing it */
    data = fopen("Case0Source_fopen.txt", "w+");
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    case1V2Sink(dataVector);
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

using namespace CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_72; /* so that we can use case1 and case0 easily */

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
