/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_fclose_04.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-04.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using open()
 * Sinks: fclose
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Close the file using fclose()
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define OPEN _open
#define CLOSE _close
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#endif

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */

#ifndef OMITCASE0

void CWE404_Improper_Resource_Shutdown__open_fclose_04_case0()
{
    int data;
    /* Initialize data */
    data = -1;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    if(STATIC_CONST_TRUE)
    {
        if (data != -1)
        {
            /* NOTE: Attempt to close the file using fclose() instead of close() */
            fclose((FILE *)data);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V21() - use case0source and case1sink by changing STATIC_CONST_TRUE to STATIC_CONST_FALSE */
static void case1V21()
{
    int data;
    /* Initialize data */
    data = -1;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    if(STATIC_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        if (data != -1)
        {
            /* ALT: Close the file using close() */
            CLOSE(data);
        }
    }
}

/* case1V22() - use case0source and case1sink by reversing statements in if  */
static void case1V22()
{
    int data;
    /* Initialize data */
    data = -1;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    if(STATIC_CONST_TRUE)
    {
        if (data != -1)
        {
            /* ALT: Close the file using close() */
            CLOSE(data);
        }
    }
}

void CWE404_Improper_Resource_Shutdown__open_fclose_04_case1()
{
    case1V21();
    case1V22();
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
    CWE404_Improper_Resource_Shutdown__open_fclose_04_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE404_Improper_Resource_Shutdown__open_fclose_04_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
