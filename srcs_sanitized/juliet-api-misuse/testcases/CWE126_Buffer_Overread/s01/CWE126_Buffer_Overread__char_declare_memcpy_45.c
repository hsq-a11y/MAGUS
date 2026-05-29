/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__char_declare_memcpy_45.c
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * Case0Source:  Set data pointer to a small buffer
 * Case1Source: Set data pointer to a large buffer
 * Sinks: memcpy
 *    Case0Sink : Copy data to string using memcpy
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

static char * CWE126_Buffer_Overread__char_declare_memcpy_45_case0Data;
static char * CWE126_Buffer_Overread__char_declare_memcpy_45_case1V1Data;

#ifndef OMITCASE0

static void case0Sink()
{
    char * data = CWE126_Buffer_Overread__char_declare_memcpy_45_case0Data;
    {
        char dest[100];
        memset(dest, 'C', 100-1);
        dest[100-1] = '\0'; /* null terminate */
        /* NOTE: using memcpy with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memcpy(dest, data, strlen(dest)*sizeof(char));
        dest[100-1] = '\0';
        printLine(dest);
    }
}

void CWE126_Buffer_Overread__char_declare_memcpy_45_case0()
{
    char * data;
    char dataCase0Buffer[50];
    char dataCase1Buffer[100];
    memset(dataCase0Buffer, 'A', 50-1); /* fill with 'A's */
    dataCase0Buffer[50-1] = '\0'; /* null terminate */
    memset(dataCase1Buffer, 'A', 100-1); /* fill with 'A's */
    dataCase1Buffer[100-1] = '\0'; /* null terminate */
    /* NOTE: Set data pointer to a small buffer */
    data = dataCase0Buffer;
    CWE126_Buffer_Overread__char_declare_memcpy_45_case0Data = data;
    case0Sink();
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1Sink()
{
    char * data = CWE126_Buffer_Overread__char_declare_memcpy_45_case1V1Data;
    {
        char dest[100];
        memset(dest, 'C', 100-1);
        dest[100-1] = '\0'; /* null terminate */
        /* NOTE: using memcpy with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memcpy(dest, data, strlen(dest)*sizeof(char));
        dest[100-1] = '\0';
        printLine(dest);
    }
}

static void case1V1()
{
    char * data;
    char dataCase0Buffer[50];
    char dataCase1Buffer[100];
    memset(dataCase0Buffer, 'A', 50-1); /* fill with 'A's */
    dataCase0Buffer[50-1] = '\0'; /* null terminate */
    memset(dataCase1Buffer, 'A', 100-1); /* fill with 'A's */
    dataCase1Buffer[100-1] = '\0'; /* null terminate */
    /* ALT: Set data pointer to a large buffer */
    data = dataCase1Buffer;
    CWE126_Buffer_Overread__char_declare_memcpy_45_case1V1Data = data;
    case1V1Sink();
}

void CWE126_Buffer_Overread__char_declare_memcpy_45_case1()
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
    CWE126_Buffer_Overread__char_declare_memcpy_45_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE126_Buffer_Overread__char_declare_memcpy_45_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
