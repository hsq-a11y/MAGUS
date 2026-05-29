/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__fopen_33.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-33.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: fopen Open data with fopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 33 Data flow: use of a C++ reference to data within the same function
 *
 * */

#include "std_testcase.h"

namespace CWE690_NULL_Deref_From_Return__fopen_33
{

#ifndef OMITCASE0

void case0()
{
    FILE * data;
    FILE * &dataRef = data;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file without checking the return value for NULL */
    data = fopen("file.txt", "w+");
    {
        FILE * data = dataRef;
        /* NOTE: if the fopen failed, data will be NULL here */
        fclose(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() uses the Case0Source with the Case1Sink */
static void case1V2()
{
    FILE * data;
    FILE * &dataRef = data;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file without checking the return value for NULL */
    data = fopen("file.txt", "w+");
    {
        FILE * data = dataRef;
        /* ALT: check the return value */
        if (data != NULL)
        {
            fclose(data);
        }
    }
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

using namespace CWE690_NULL_Deref_From_Return__fopen_33; /* so that we can use case1 and case0 easily */

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
