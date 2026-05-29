/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__malloc_char_loop_68a.c
Label Definition File: CWE124_Buffer_Underwrite__malloc.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sink: loop
 *    Case0Sink : Copy string to data using a loop
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

char * CWE124_Buffer_Underwrite__malloc_char_loop_68_case0Data;
char * CWE124_Buffer_Underwrite__malloc_char_loop_68_case1V1Data;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE124_Buffer_Underwrite__malloc_char_loop_68b_case0Sink();

void CWE124_Buffer_Underwrite__malloc_char_loop_68_case0()
{
    char * data;
    data = NULL;
    {
        char * dataBuffer = (char *)malloc(100*sizeof(char));
        if (dataBuffer == NULL) {exit(-1);}
        memset(dataBuffer, 'A', 100-1);
        dataBuffer[100-1] = '\0';
        /* NOTE: Set data pointer to before the allocated memory buffer */
        data = dataBuffer - 8;
    }
    CWE124_Buffer_Underwrite__malloc_char_loop_68_case0Data = data;
    CWE124_Buffer_Underwrite__malloc_char_loop_68b_case0Sink();
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declarations */
void CWE124_Buffer_Underwrite__malloc_char_loop_68b_case1V1Sink();

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    char * data;
    data = NULL;
    {
        char * dataBuffer = (char *)malloc(100*sizeof(char));
        if (dataBuffer == NULL) {exit(-1);}
        memset(dataBuffer, 'A', 100-1);
        dataBuffer[100-1] = '\0';
        /* ALT: Set data pointer to the allocated memory buffer */
        data = dataBuffer;
    }
    CWE124_Buffer_Underwrite__malloc_char_loop_68_case1V1Data = data;
    CWE124_Buffer_Underwrite__malloc_char_loop_68b_case1V1Sink();
}

void CWE124_Buffer_Underwrite__malloc_char_loop_68_case1()
{
    case1V1();
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
    CWE124_Buffer_Underwrite__malloc_char_loop_68_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE124_Buffer_Underwrite__malloc_char_loop_68_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
