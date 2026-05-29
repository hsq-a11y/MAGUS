/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__char_declare_memcpy_63b.c
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-63b.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * Case0Source:  Set data pointer to a small buffer
 * Case1Source: Set data pointer to a large buffer
 * Sinks: memcpy
 *    Case0Sink : Copy data to string using memcpy
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

void CWE126_Buffer_Overread__char_declare_memcpy_63b_case0Sink(char * * dataPtr)
{
    char * data = *dataPtr;
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

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE126_Buffer_Overread__char_declare_memcpy_63b_case1V1Sink(char * * dataPtr)
{
    char * data = *dataPtr;
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

#endif /* OMITCASE1 */
