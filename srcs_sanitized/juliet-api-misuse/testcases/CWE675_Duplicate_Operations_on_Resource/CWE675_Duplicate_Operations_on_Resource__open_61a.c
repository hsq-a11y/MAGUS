/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__open_61a.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource__open.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source:  Open and close a file using open() and close()
 * Case1Source: Open a file using open()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define OPEN _open
# define CLOSE _close
#else
#include <unistd.h>
# define OPEN open
# define CLOSE close
#endif

#ifndef OMITCASE0

/* case0 function declaration */
int CWE675_Duplicate_Operations_on_Resource__open_61b_case0Source(int data);

void CWE675_Duplicate_Operations_on_Resource__open_61_case0()
{
    int data;
    data = -1; /* Initialize data */
    data = CWE675_Duplicate_Operations_on_Resource__open_61b_case0Source(data);
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    CLOSE(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
int CWE675_Duplicate_Operations_on_Resource__open_61b_case1V1Source(int data);

static void case1V1()
{
    int data;
    data = -1; /* Initialize data */
    data = CWE675_Duplicate_Operations_on_Resource__open_61b_case1V1Source(data);
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    CLOSE(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
int CWE675_Duplicate_Operations_on_Resource__open_61b_case1V2Source(int data);

static void case1V2()
{
    int data;
    data = -1; /* Initialize data */
    data = CWE675_Duplicate_Operations_on_Resource__open_61b_case1V2Source(data);
    /* Do nothing */
    /* ALT: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}

void CWE675_Duplicate_Operations_on_Resource__open_61_case1()
{
    case1V1();
    case1V2();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE675_Duplicate_Operations_on_Resource__open_61_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE675_Duplicate_Operations_on_Resource__open_61_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
