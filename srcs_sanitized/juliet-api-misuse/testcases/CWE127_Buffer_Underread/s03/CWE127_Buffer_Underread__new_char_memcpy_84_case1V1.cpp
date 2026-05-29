/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__new_char_memcpy_84_case1V1.cpp
Label Definition File: CWE127_Buffer_Underread__new.label.xml
Template File: sources-sink-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sinks: memcpy
 *    Case0Sink : Copy data to string using memcpy
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE127_Buffer_Underread__new_char_memcpy_84.h"

namespace CWE127_Buffer_Underread__new_char_memcpy_84
{
CWE127_Buffer_Underread__new_char_memcpy_84_case1V1::CWE127_Buffer_Underread__new_char_memcpy_84_case1V1(char * dataCopy)
{
    data = dataCopy;
    {
        char * dataBuffer = new char[100];
        memset(dataBuffer, 'A', 100-1);
        dataBuffer[100-1] = '\0';
        /* ALT: Set data pointer to the allocated memory buffer */
        data = dataBuffer;
    }
}

CWE127_Buffer_Underread__new_char_memcpy_84_case1V1::~CWE127_Buffer_Underread__new_char_memcpy_84_case1V1()
{
    {
        char dest[100];
        memset(dest, 'C', 100-1); /* fill with 'C's */
        dest[100-1] = '\0'; /* null terminate */
        /* NOTE: Possibly copy from a memory location located before the source buffer */
        memcpy(dest, data, 100*sizeof(char));
        /* Ensure null termination */
        dest[100-1] = '\0';
        printLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by new [] so can't safely call delete [] on it */
    }
}
}
#endif /* OMITCASE1 */
