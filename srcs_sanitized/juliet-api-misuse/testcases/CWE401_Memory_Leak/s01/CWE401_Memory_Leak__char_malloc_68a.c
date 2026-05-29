/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__char_malloc_68a.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: malloc Allocate data using malloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

char * CWE401_Memory_Leak__char_malloc_68_case0Data;
char * CWE401_Memory_Leak__char_malloc_68_case1V1Data;
char * CWE401_Memory_Leak__char_malloc_68_case1V2Data;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE401_Memory_Leak__char_malloc_68b_case0Sink();

void CWE401_Memory_Leak__char_malloc_68_case0()
{
    char * data;
    data = NULL;
    /* NOTE: Allocate memory on the heap */
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    strcpy(data, "A String");
    printLine(data);
    CWE401_Memory_Leak__char_malloc_68_case0Data = data;
    CWE401_Memory_Leak__char_malloc_68b_case0Sink();
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declarations */
void CWE401_Memory_Leak__char_malloc_68b_case1V1Sink();
void CWE401_Memory_Leak__char_malloc_68b_case1V2Sink();

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    char * data;
    data = NULL;
    /* ALT: Use memory allocated on the stack with ALLOCA */
    data = (char *)ALLOCA(100*sizeof(char));
    /* Initialize and make use of data */
    strcpy(data, "A String");
    printLine(data);
    CWE401_Memory_Leak__char_malloc_68_case1V1Data = data;
    CWE401_Memory_Leak__char_malloc_68b_case1V1Sink();
}

/* case1V2 uses the Case0Source with the Case1Sink */
static void case1V2()
{
    char * data;
    data = NULL;
    /* NOTE: Allocate memory on the heap */
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    strcpy(data, "A String");
    printLine(data);
    CWE401_Memory_Leak__char_malloc_68_case1V2Data = data;
    CWE401_Memory_Leak__char_malloc_68b_case1V2Sink();
}

void CWE401_Memory_Leak__char_malloc_68_case1()
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
    CWE401_Memory_Leak__char_malloc_68_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE401_Memory_Leak__char_malloc_68_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
