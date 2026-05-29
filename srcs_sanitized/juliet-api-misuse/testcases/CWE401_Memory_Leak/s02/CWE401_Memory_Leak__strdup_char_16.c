/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_char_16.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-16.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using strdup()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

void CWE401_Memory_Leak__strdup_char_16_case0()
{
    char * data;
    data = NULL;
    while(1)
    {
        {
            char myString[] = "myString";
            /* NOTE: Allocate memory from the heap using a function that requires free() for deallocation */
            data = strdup(myString);
            /* Use data */
            printLine(data);
        }
        break;
    }
    while(1)
    {
        /* NOTE: No deallocation of memory */
        /* no deallocation */
        ; /* empty statement needed for some flow variants */
        break;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() - use case0source and case1sink by changing the sinks in the second while statement */
static void case1V2()
{
    char * data;
    data = NULL;
    while(1)
    {
        {
            char myString[] = "myString";
            /* NOTE: Allocate memory from the heap using a function that requires free() for deallocation */
            data = strdup(myString);
            /* Use data */
            printLine(data);
        }
        break;
    }
    while(1)
    {
        /* ALT: Deallocate memory initialized in the source */
        free(data);
        break;
    }
}

/* case1V1() - use case1source and case0sink by changing the sources in the first while statement */
static void case1V1()
{
    char * data;
    data = NULL;
    while(1)
    {
        /* ALT: Use memory allocated on the stack with ALLOCA */
        data = (char *)ALLOCA(100*sizeof(char));
        /* Initialize then use data */
        strcpy(data, "a string");
        printLine(data);
        break;
    }
    while(1)
    {
        /* NOTE: No deallocation of memory */
        /* no deallocation */
        ; /* empty statement needed for some flow variants */
        break;
    }
}

void CWE401_Memory_Leak__strdup_char_16_case1()
{
    case1V2();
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
    CWE401_Memory_Leak__strdup_char_16_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE401_Memory_Leak__strdup_char_16_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
