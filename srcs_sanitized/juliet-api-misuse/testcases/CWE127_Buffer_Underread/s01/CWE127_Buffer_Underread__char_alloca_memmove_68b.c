/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__char_alloca_memmove_68b.c
Label Definition File: CWE127_Buffer_Underread.stack.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sink: memmove
 *    Case0Sink : Copy data to string using memmove
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern char * CWE127_Buffer_Underread__char_alloca_memmove_68_case0Data;
extern char * CWE127_Buffer_Underread__char_alloca_memmove_68_case1V1Data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

void CWE127_Buffer_Underread__char_alloca_memmove_68b_case0Sink()
{
    char * data = CWE127_Buffer_Underread__char_alloca_memmove_68_case0Data;
    {
        char dest[100];
        memset(dest, 'C', 100-1); /* fill with 'C's */
        dest[100-1] = '\0'; /* null terminate */
        /* NOTE: Possibly copy from a memory location located before the source buffer */
        memmove(dest, data, 100*sizeof(char));
        /* Ensure null termination */
        dest[100-1] = '\0';
        printLine(dest);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE127_Buffer_Underread__char_alloca_memmove_68b_case1V1Sink()
{
    char * data = CWE127_Buffer_Underread__char_alloca_memmove_68_case1V1Data;
    {
        char dest[100];
        memset(dest, 'C', 100-1); /* fill with 'C's */
        dest[100-1] = '\0'; /* null terminate */
        /* NOTE: Possibly copy from a memory location located before the source buffer */
        memmove(dest, data, 100*sizeof(char));
        /* Ensure null termination */
        dest[100-1] = '\0';
        printLine(dest);
    }
}

#endif /* OMITCASE1 */
