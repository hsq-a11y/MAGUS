/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__char_file_22a.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * Case0Source: file Read input from a file
 * Case1Source: Use a hardcoded path
 * Sink:
 *    Case0Sink : Set the environment variable
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define NEW_PATH "%SystemRoot%\\system32"
#define PUTENV _putenv
#else
#define NEW_PATH "/bin"
#define PUTENV putenv
#endif

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
int CWE427_Uncontrolled_Search_Path_Element__char_file_22_case0Global = 0;

char * CWE427_Uncontrolled_Search_Path_Element__char_file_22_case0Source(char * data);

void CWE427_Uncontrolled_Search_Path_Element__char_file_22_case0()
{
    char * data;
    char dataBuffer[250] = "PATH=";
    data = dataBuffer;
    CWE427_Uncontrolled_Search_Path_Element__char_file_22_case0Global = 1; /* true */
    data = CWE427_Uncontrolled_Search_Path_Element__char_file_22_case0Source(data);
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
int CWE427_Uncontrolled_Search_Path_Element__char_file_22_case1V11Global = 0;
int CWE427_Uncontrolled_Search_Path_Element__char_file_22_case1V12Global = 0;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
char * CWE427_Uncontrolled_Search_Path_Element__char_file_22_case1V11Source(char * data);

static void case1V11()
{
    char * data;
    char dataBuffer[250] = "PATH=";
    data = dataBuffer;
    CWE427_Uncontrolled_Search_Path_Element__char_file_22_case1V11Global = 0; /* false */
    data = CWE427_Uncontrolled_Search_Path_Element__char_file_22_case1V11Source(data);
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
char * CWE427_Uncontrolled_Search_Path_Element__char_file_22_case1V12Source(char * data);

static void case1V12()
{
    char * data;
    char dataBuffer[250] = "PATH=";
    data = dataBuffer;
    CWE427_Uncontrolled_Search_Path_Element__char_file_22_case1V12Global = 1; /* true */
    data = CWE427_Uncontrolled_Search_Path_Element__char_file_22_case1V12Source(data);
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

void CWE427_Uncontrolled_Search_Path_Element__char_file_22_case1()
{
    case1V11();
    case1V12();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE427_Uncontrolled_Search_Path_Element__char_file_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE427_Uncontrolled_Search_Path_Element__char_file_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
