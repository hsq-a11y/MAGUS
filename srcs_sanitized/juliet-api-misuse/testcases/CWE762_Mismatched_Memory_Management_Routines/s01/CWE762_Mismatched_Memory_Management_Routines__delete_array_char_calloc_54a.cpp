/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_char_calloc_54a.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-54a.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: calloc Allocate data using calloc()
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_char_calloc_54
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink_b(char * data);

void case0()
{
    char * data;
    /* Initialize data*/
    data = NULL;
    /* NOTE: Allocate memory with a function that requires free() to free the memory */
    data = (char *)calloc(100, sizeof(char));
    if (data == NULL) {exit(-1);}
    case0Sink_b(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink_b(char * data);

static void case1V1()
{
    char * data;
    /* Initialize data*/
    data = NULL;
    /* ALT: Allocate memory using new [] */
    data = new char[100];
    case1V1Sink_b(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink_b(char * data);

static void case1V2()
{
    char * data;
    /* Initialize data*/
    data = NULL;
    /* NOTE: Allocate memory with a function that requires free() to free the memory */
    data = (char *)calloc(100, sizeof(char));
    if (data == NULL) {exit(-1);}
    case1V2Sink_b(data);
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

using namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_char_calloc_54; /* so that we can use case1 and case0 easily */

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
