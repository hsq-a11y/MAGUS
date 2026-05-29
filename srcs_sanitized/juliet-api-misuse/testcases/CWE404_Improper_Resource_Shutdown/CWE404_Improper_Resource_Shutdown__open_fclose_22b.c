/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_fclose_22b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using open()
 * Sinks: fclose
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Close the file using fclose()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
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

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
extern int CWE404_Improper_Resource_Shutdown__open_fclose_22_case0Global;

void CWE404_Improper_Resource_Shutdown__open_fclose_22_case0Sink(int data)
{
    if(CWE404_Improper_Resource_Shutdown__open_fclose_22_case0Global)
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

/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE404_Improper_Resource_Shutdown__open_fclose_22_case1V21Global;
extern int CWE404_Improper_Resource_Shutdown__open_fclose_22_case1V22Global;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE404_Improper_Resource_Shutdown__open_fclose_22_case1V21Sink(int data)
{
    if(CWE404_Improper_Resource_Shutdown__open_fclose_22_case1V21Global)
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

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE404_Improper_Resource_Shutdown__open_fclose_22_case1V22Sink(int data)
{
    if(CWE404_Improper_Resource_Shutdown__open_fclose_22_case1V22Global)
    {
        if (data != -1)
        {
            /* ALT: Close the file using close() */
            CLOSE(data);
        }
    }
}

#endif /* OMITCASE1 */
