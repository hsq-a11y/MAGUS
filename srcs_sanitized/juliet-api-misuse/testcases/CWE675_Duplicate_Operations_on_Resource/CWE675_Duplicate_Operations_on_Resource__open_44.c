/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__open_44.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource__open.label.xml
Template File: sources-sinks-44.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source:  Open and close a file using open() and close()
 * Case1Source: Open a file using open()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
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

static void case0Sink(int data)
{
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    CLOSE(data);
}

void CWE675_Duplicate_Operations_on_Resource__open_44_case0()
{
    int data;
    /* define a function pointer */
    void (*funcPtr) (int) = case0Sink;
    data = -1; /* Initialize data */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    /* NOTE: Close the file in the source */
    CLOSE(data);
    /* use the function pointer */
    funcPtr(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1Sink(int data)
{
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    CLOSE(data);
}

static void case1V1()
{
    int data;
    void (*funcPtr) (int) = case1V1Sink;
    data = -1; /* Initialize data */
    /* ALT: Open, but do not close the file in the source */
    data = OPEN("Case1Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    funcPtr(data);
}

/* case1V2() uses the Case0Source with the Case1Sink */
static void case1V2Sink(int data)
{
    /* Do nothing */
    /* ALT: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}

static void case1V2()
{
    int data;
    void (*funcPtr) (int) = case1V2Sink;
    data = -1; /* Initialize data */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    /* NOTE: Close the file in the source */
    CLOSE(data);
    funcPtr(data);
}

void CWE675_Duplicate_Operations_on_Resource__open_44_case1()
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
    CWE675_Duplicate_Operations_on_Resource__open_44_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE675_Duplicate_Operations_on_Resource__open_44_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
