/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE170_char_strncpy_02.c
Label Definition File: CWE126_Buffer_Overread__CWE170.label.xml
Template File: point-note-02.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Sinks: strncpy
 *    Case1Sink: Copy a string using strncpy() with explicit null termination
 *    Case0Sink : Copy a string using strncpy() without explicit null termination
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

void CWE126_Buffer_Overread__CWE170_char_strncpy_02_case0()
{
    if(1)
    {
        {
            char data[150], dest[100];
            /* Initialize data */
            memset(data, 'A', 149);
            data[149] = '\0';
            /* strncpy() does not null terminate if the string in the src buffer is larger than
             * the number of characters being copied to the dest buffer */
            strncpy(dest, data, 99);
            /* NOTE: do not explicitly null terminate dest after the use of strncpy() */
            printLine(dest);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses if(0) instead of if(1) */
static void case11()
{
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            char data[150], dest[100];
            /* Initialize data */
            memset(data, 'A', 149);
            data[149] = '\0';
            /* strncpy() does not null terminate if the string in the src buffer is larger than
             * the number of characters being copied to the dest buffer */
            strncpy(dest, data, 99);
            dest[99] = '\0'; /* ALT: Explicitly null terminate dest after the use of strncpy() */
            printLine(dest);
        }
    }
}

/* case12() reverses the bodies in the if statement */
static void case12()
{
    if(1)
    {
        {
            char data[150], dest[100];
            /* Initialize data */
            memset(data, 'A', 149);
            data[149] = '\0';
            /* strncpy() does not null terminate if the string in the src buffer is larger than
             * the number of characters being copied to the dest buffer */
            strncpy(dest, data, 99);
            dest[99] = '\0'; /* ALT: Explicitly null terminate dest after the use of strncpy() */
            printLine(dest);
        }
    }
}

void CWE126_Buffer_Overread__CWE170_char_strncpy_02_case1()
{
    case11();
    case12();
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
    CWE126_Buffer_Overread__CWE170_char_strncpy_02_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE126_Buffer_Overread__CWE170_char_strncpy_02_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
