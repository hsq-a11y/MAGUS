/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__malloc_char_memcpy_82_case0.cpp
Label Definition File: CWE126_Buffer_Overread__malloc.label.xml
Template File: sources-sink-82_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * Case0Source:  Use a small buffer
 * Case1Source: Use a large buffer
 * Sinks: memcpy
 *    Case0Sink : Copy data to string using memcpy
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE126_Buffer_Overread__malloc_char_memcpy_82.h"

namespace CWE126_Buffer_Overread__malloc_char_memcpy_82
{

void CWE126_Buffer_Overread__malloc_char_memcpy_82_case0::action(char * data)
{
    {
        char dest[100];
        memset(dest, 'C', 100-1);
        dest[100-1] = '\0'; /* null terminate */
        /* NOTE: using memcpy with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memcpy(dest, data, strlen(dest)*sizeof(char));
        dest[100-1] = '\0';
        printLine(dest);
        free(data);
    }
}

}
#endif /* OMITCASE0 */
