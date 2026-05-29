/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE170_wchar_t_memcpy_17.c
Label Definition File: CWE126_Buffer_Overread__CWE170.label.xml
Template File: point-note-17.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Sinks: memcpy
 *    Case1Sink: Copy a string using memcpy with explicit null termination
 *    Case0Sink : Copy a string using memcpy without explicit null termination
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

void CWE126_Buffer_Overread__CWE170_wchar_t_memcpy_17_case0()
{
    int j;
    for(j = 0; j < 1; j++)
    {
        {
            wchar_t data[150], dest[100];
            /* Initialize data */
            wmemset(data, L'A', 149);
            data[149] = L'\0';
            memcpy(dest, data, 99*sizeof(wchar_t));
            /* NOTE: do not explicitly null terminate dest after the use of memcpy */
            printWLine(dest);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses the Case1SinkBody in the for statements */
static void case11()
{
    int k;
    for(k = 0; k < 1; k++)
    {
        {
            wchar_t data[150], dest[100];
            /* Initialize data */
            wmemset(data, L'A', 149);
            data[149] = L'\0';
            memcpy(dest, data, 99*sizeof(wchar_t));
            dest[99] = L'\0'; /* ALT: null terminate dest */
            printWLine(dest);
        }
    }
}

void CWE126_Buffer_Overread__CWE170_wchar_t_memcpy_17_case1()
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
    CWE126_Buffer_Overread__CWE170_wchar_t_memcpy_17_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE126_Buffer_Overread__CWE170_wchar_t_memcpy_17_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
