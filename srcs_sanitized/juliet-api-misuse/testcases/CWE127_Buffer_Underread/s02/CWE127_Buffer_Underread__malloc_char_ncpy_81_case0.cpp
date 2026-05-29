/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__malloc_char_ncpy_81_case0.cpp
Label Definition File: CWE127_Buffer_Underread__malloc.label.xml
Template File: sources-sink-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sinks: ncpy
 *    Case0Sink : Copy data to string using strncpy
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE127_Buffer_Underread__malloc_char_ncpy_81.h"

namespace CWE127_Buffer_Underread__malloc_char_ncpy_81
{

void CWE127_Buffer_Underread__malloc_char_ncpy_81_case0::action(char * data) const
{
    {
        char dest[100];
        memset(dest, 'C', 100-1); /* fill with 'C's */
        dest[100-1] = '\0'; /* null terminate */
        /* NOTE: Possibly copy from a memory location located before the source buffer */
        strncpy(dest, data, strlen(dest));
        /* Ensure null termination */
        dest[100-1] = '\0';
        printLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by malloc() so can't safely call free() on it */
    }
}

}
#endif /* OMITCASE0 */
