/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE170_char_loop_18.c
Label Definition File: CWE126_Buffer_Overread__CWE170.label.xml
Template File: point-note-18.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Sinks: loop
 *    Case1Sink: Copy a string using a loop with explicit null termination
 *    Case0Sink : Copy a string using a loop without explicit null termination
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

void CWE126_Buffer_Overread__CWE170_char_loop_18_case0()
{
    goto sink;
sink:
    {
        char src[150], dest[100];
        int i;
        /* Initialize src */
        memset(src, 'A', 149);
        src[149] = '\0';
        for(i=0; i < 99; i++)
        {
            dest[i] = src[i];
        }
        /* NOTE: do not explicitly null terminate dest after the loop */
        printLine(dest);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() reverses the blocks on the goto statement */
static void case11()
{
    goto sink;
sink:
    {
        char src[150], dest[100];
        int i;
        /* Initialize src */
        memset(src, 'A', 149);
        src[149] = '\0';
        for(i=0; i < 99; i++)
        {
            dest[i] = src[i];
        }
        dest[99] = '\0'; /* ALT: null terminate dest */
        printLine(dest);
    }
}

void CWE126_Buffer_Overread__CWE170_char_loop_18_case1()
{
    case11();
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
    CWE126_Buffer_Overread__CWE170_char_loop_18_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE126_Buffer_Overread__CWE170_char_loop_18_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
