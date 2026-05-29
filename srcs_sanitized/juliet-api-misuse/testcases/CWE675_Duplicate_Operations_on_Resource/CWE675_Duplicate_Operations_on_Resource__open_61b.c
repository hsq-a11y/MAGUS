/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__open_61b.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource__open.label.xml
Template File: sources-sinks-61b.tmpl.c
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

int CWE675_Duplicate_Operations_on_Resource__open_61b_case0Source(int data)
{
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    /* NOTE: Close the file in the source */
    CLOSE(data);
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
int CWE675_Duplicate_Operations_on_Resource__open_61b_case1V1Source(int data)
{
    /* ALT: Open, but do not close the file in the source */
    data = OPEN("Case1Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    return data;
}

/* case1V2() uses the Case0Source with the Case1Sink */
int CWE675_Duplicate_Operations_on_Resource__open_61b_case1V2Source(int data)
{
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    /* NOTE: Close the file in the source */
    CLOSE(data);
    return data;
}

#endif /* OMITCASE1 */
