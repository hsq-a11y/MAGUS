/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__new_wchar_t_memcpy_81_case0.cpp
Label Definition File: CWE127_Buffer_Underread__new.label.xml
Template File: sources-sink-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sinks: memcpy
 *    Case0Sink : Copy data to string using memcpy
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE127_Buffer_Underread__new_wchar_t_memcpy_81.h"

namespace CWE127_Buffer_Underread__new_wchar_t_memcpy_81
{

void CWE127_Buffer_Underread__new_wchar_t_memcpy_81_case0::action(wchar_t * data) const
{
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1); /* fill with 'C's */
        dest[100-1] = L'\0'; /* null terminate */
        /* NOTE: Possibly copy from a memory location located before the source buffer */
        memcpy(dest, data, 100*sizeof(wchar_t));
        /* Ensure null termination */
        dest[100-1] = L'\0';
        printWLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by new [] so can't safely call delete [] on it */
    }
}

}
#endif /* OMITCASE0 */
