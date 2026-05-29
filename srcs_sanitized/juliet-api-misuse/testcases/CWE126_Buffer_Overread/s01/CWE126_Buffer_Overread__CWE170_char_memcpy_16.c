/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE170_char_memcpy_16.c
Label Definition File: CWE126_Buffer_Overread__CWE170.label.xml
Template File: point-note-16.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Sinks: memcpy
 *    Case1Sink: Copy a string using memcpy with explicit null termination
 *    Case0Sink : Copy a string using memcpy without explicit null termination
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

void CWE126_Buffer_Overread__CWE170_char_memcpy_16_case0()
{
    while(1)
    {
        {
            char data[150], dest[100];
            /* Initialize data */
            memset(data, 'A', 149);
            data[149] = '\0';
            memcpy(dest, data, 99*sizeof(char));
            /* NOTE: do not explicitly null terminate dest after the use of memcpy */
            printLine(dest);
        }
        break;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses the Case1SinkBody in the while loop */
static void case11()
{
    while(1)
    {
        {
            char data[150], dest[100];
            /* Initialize data */
            memset(data, 'A', 149);
            data[149] = '\0';
            memcpy(dest, data, 99*sizeof(char));
            dest[99] = '\0'; /* ALT: null terminate dest */
            printLine(dest);
        }
        break;
    }
}

void CWE126_Buffer_Overread__CWE170_char_memcpy_16_case1()
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
    CWE126_Buffer_Overread__CWE170_char_memcpy_16_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE126_Buffer_Overread__CWE170_char_memcpy_16_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
