/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__CWE839_fgets_22a.c
Label Definition File: CWE124_Buffer_Underwrite__CWE839.label.xml
Template File: sources-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source: fgets Read data from the console using fgets()
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the lower bound
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
int CWE124_Buffer_Underwrite__CWE839_fgets_22_case0Global = 0;

void CWE124_Buffer_Underwrite__CWE839_fgets_22_case0Sink(int data);

void CWE124_Buffer_Underwrite__CWE839_fgets_22_case0()
{
    int data;
    /* Initialize data */
    data = -1;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        /* NOTE: Read data from the console using fgets() */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            /* Convert to int */
            data = atoi(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
    CWE124_Buffer_Underwrite__CWE839_fgets_22_case0Global = 1; /* true */
    CWE124_Buffer_Underwrite__CWE839_fgets_22_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
int CWE124_Buffer_Underwrite__CWE839_fgets_22_case1V21Global = 0;
int CWE124_Buffer_Underwrite__CWE839_fgets_22_case1V22Global = 0;
int CWE124_Buffer_Underwrite__CWE839_fgets_22_case1V1Global = 0;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE124_Buffer_Underwrite__CWE839_fgets_22_case1V21Sink(int data);

static void case1V21()
{
    int data;
    /* Initialize data */
    data = -1;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        /* NOTE: Read data from the console using fgets() */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            /* Convert to int */
            data = atoi(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
    CWE124_Buffer_Underwrite__CWE839_fgets_22_case1V21Global = 0; /* false */
    CWE124_Buffer_Underwrite__CWE839_fgets_22_case1V21Sink(data);
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE124_Buffer_Underwrite__CWE839_fgets_22_case1V22Sink(int data);

static void case1V22()
{
    int data;
    /* Initialize data */
    data = -1;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        /* NOTE: Read data from the console using fgets() */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            /* Convert to int */
            data = atoi(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
    CWE124_Buffer_Underwrite__CWE839_fgets_22_case1V22Global = 1; /* true */
    CWE124_Buffer_Underwrite__CWE839_fgets_22_case1V22Sink(data);
}

/* case1V1() - use case1source and case0sink */
void CWE124_Buffer_Underwrite__CWE839_fgets_22_case1V1Sink(int data);

static void case1V1()
{
    int data;
    /* Initialize data */
    data = -1;
    /* ALT: Use a value greater than 0, but less than 10 to avoid attempting to
    * access an index of the array in the sink that is out-of-bounds */
    data = 7;
    CWE124_Buffer_Underwrite__CWE839_fgets_22_case1V1Global = 1; /* true */
    CWE124_Buffer_Underwrite__CWE839_fgets_22_case1V1Sink(data);
}

void CWE124_Buffer_Underwrite__CWE839_fgets_22_case1()
{
    case1V21();
    case1V22();
    case1V1();
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
    CWE124_Buffer_Underwrite__CWE839_fgets_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE124_Buffer_Underwrite__CWE839_fgets_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
