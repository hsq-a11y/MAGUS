/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__new_wchar_t_ncpy_84_case0.cpp
Label Definition File: CWE127_Buffer_Underread__new.label.xml
Template File: sources-sink-84_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sinks: ncpy
 *    Case0Sink : Copy data to string using wcsncpy
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE127_Buffer_Underread__new_wchar_t_ncpy_84.h"

namespace CWE127_Buffer_Underread__new_wchar_t_ncpy_84
{
CWE127_Buffer_Underread__new_wchar_t_ncpy_84_case0::CWE127_Buffer_Underread__new_wchar_t_ncpy_84_case0(wchar_t * dataCopy)
{
    data = dataCopy;
    {
        wchar_t * dataBuffer = new wchar_t[100];
        wmemset(dataBuffer, L'A', 100-1);
        dataBuffer[100-1] = L'\0';
        /* NOTE: Set data pointer to before the allocated memory buffer */
        data = dataBuffer - 8;
    }
}

CWE127_Buffer_Underread__new_wchar_t_ncpy_84_case0::~CWE127_Buffer_Underread__new_wchar_t_ncpy_84_case0()
{
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1); /* fill with 'C's */
        dest[100-1] = L'\0'; /* null terminate */
        /* NOTE: Possibly copy from a memory location located before the source buffer */
        wcsncpy(dest, data, wcslen(dest));
        /* Ensure null termination */
        dest[100-1] = L'\0';
        printWLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by new [] so can't safely call delete [] on it */
    }
}
}
#endif /* OMITCASE0 */
