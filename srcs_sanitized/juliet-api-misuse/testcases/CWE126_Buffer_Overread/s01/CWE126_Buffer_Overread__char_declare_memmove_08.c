/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__char_declare_memmove_08.c
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-08.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * Case0Source:  Set data pointer to a small buffer
 * Case1Source: Set data pointer to a large buffer
 * Sink: memmove
 *    Case0Sink : Copy data to string using memmove
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The two function below always return the same value, so a tool
 * should be able to identify that calls to the functions will always
 * return a fixed value.
 */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

#ifndef OMITCASE0

void CWE126_Buffer_Overread__char_declare_memmove_08_case0()
{
    char * data;
    char dataCase0Buffer[50];
    char dataCase1Buffer[100];
    memset(dataCase0Buffer, 'A', 50-1); /* fill with 'A's */
    dataCase0Buffer[50-1] = '\0'; /* null terminate */
    memset(dataCase1Buffer, 'A', 100-1); /* fill with 'A's */
    dataCase1Buffer[100-1] = '\0'; /* null terminate */
    if(staticReturnsTrue())
    {
        /* NOTE: Set data pointer to a small buffer */
        data = dataCase0Buffer;
    }
    {
        char dest[100];
        memset(dest, 'C', 100-1);
        dest[100-1] = '\0'; /* null terminate */
        /* NOTE: using memmove with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memmove(dest, data, strlen(dest)*sizeof(char));
        dest[100-1] = '\0';
        printLine(dest);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V11() - use case1source and case0sink by changing the staticReturnsTrue() to staticReturnsFalse() */
static void case1V11()
{
    char * data;
    char dataCase0Buffer[50];
    char dataCase1Buffer[100];
    memset(dataCase0Buffer, 'A', 50-1); /* fill with 'A's */
    dataCase0Buffer[50-1] = '\0'; /* null terminate */
    memset(dataCase1Buffer, 'A', 100-1); /* fill with 'A's */
    dataCase1Buffer[100-1] = '\0'; /* null terminate */
    if(staticReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Set data pointer to a large buffer */
        data = dataCase1Buffer;
    }
    {
        char dest[100];
        memset(dest, 'C', 100-1);
        dest[100-1] = '\0'; /* null terminate */
        /* NOTE: using memmove with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memmove(dest, data, strlen(dest)*sizeof(char));
        dest[100-1] = '\0';
        printLine(dest);
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if statement */
static void case1V12()
{
    char * data;
    char dataCase0Buffer[50];
    char dataCase1Buffer[100];
    memset(dataCase0Buffer, 'A', 50-1); /* fill with 'A's */
    dataCase0Buffer[50-1] = '\0'; /* null terminate */
    memset(dataCase1Buffer, 'A', 100-1); /* fill with 'A's */
    dataCase1Buffer[100-1] = '\0'; /* null terminate */
    if(staticReturnsTrue())
    {
        /* ALT: Set data pointer to a large buffer */
        data = dataCase1Buffer;
    }
    {
        char dest[100];
        memset(dest, 'C', 100-1);
        dest[100-1] = '\0'; /* null terminate */
        /* NOTE: using memmove with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memmove(dest, data, strlen(dest)*sizeof(char));
        dest[100-1] = '\0';
        printLine(dest);
    }
}

void CWE126_Buffer_Overread__char_declare_memmove_08_case1()
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
    CWE126_Buffer_Overread__char_declare_memmove_08_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE126_Buffer_Overread__char_declare_memmove_08_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
