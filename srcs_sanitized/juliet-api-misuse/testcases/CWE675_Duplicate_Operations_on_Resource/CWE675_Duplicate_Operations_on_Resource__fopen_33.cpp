/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_33.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-33.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: fopen Open and close a file using fopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 33 Data flow: use of a C++ reference to data within the same function
 *
 * */

#include "std_testcase.h"

namespace CWE675_Duplicate_Operations_on_Resource__fopen_33
{

#ifndef OMITCASE0

void case0()
{
    FILE * data;
    FILE * &dataRef = data;
    data = NULL; /* Initialize data */
    data = fopen("Case0Source_fopen.txt", "w+");
    /* NOTE: Close the file in the source */
    fclose(data);
    {
        FILE * data = dataRef;
        /* NOTE: Close the file in the sink (it may have been closed in the Source) */
        fclose(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1()
{
    FILE * data;
    FILE * &dataRef = data;
    data = NULL; /* Initialize data */
    /* ALT: Open, but do not close the file in the source */
    data = fopen("Case1Source_fopen.txt", "w+");
    {
        FILE * data = dataRef;
        /* NOTE: Close the file in the sink (it may have been closed in the Source) */
        fclose(data);
    }
}

/* case1V2() uses the Case0Source with the Case1Sink */
static void case1V2()
{
    FILE * data;
    FILE * &dataRef = data;
    data = NULL; /* Initialize data */
    data = fopen("Case0Source_fopen.txt", "w+");
    /* NOTE: Close the file in the source */
    fclose(data);
    {
        FILE * data = dataRef;
        /* Do nothing */
        /* ALT: Don't close the file in the sink */
        ; /* empty statement needed for some flow variants */
    }
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

using namespace CWE675_Duplicate_Operations_on_Resource__fopen_33; /* so that we can use case1 and case0 easily */

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
