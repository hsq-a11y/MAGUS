/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__new_char_memcpy_84_case0.cpp
Label Definition File: CWE124_Buffer_Underwrite__new.label.xml
Template File: sources-sink-84_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sinks: memcpy
 *    Case0Sink : Copy string to data using memcpy
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE124_Buffer_Underwrite__new_char_memcpy_84.h"

namespace CWE124_Buffer_Underwrite__new_char_memcpy_84
{
CWE124_Buffer_Underwrite__new_char_memcpy_84_case0::CWE124_Buffer_Underwrite__new_char_memcpy_84_case0(char * dataCopy)
{
    data = dataCopy;
    {
        char * dataBuffer = new char[100];
        memset(dataBuffer, 'A', 100-1);
        dataBuffer[100-1] = '\0';
        /* NOTE: Set data pointer to before the allocated memory buffer */
        data = dataBuffer - 8;
    }
}

CWE124_Buffer_Underwrite__new_char_memcpy_84_case0::~CWE124_Buffer_Underwrite__new_char_memcpy_84_case0()
{
    {
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        /* NOTE: Possibly copying data to memory before the destination buffer */
        memcpy(data, source, 100*sizeof(char));
        /* Ensure the destination buffer is null terminated */
        data[100-1] = '\0';
        printLine(data);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by new [] so can't safely call delete [] on it */
    }
}
}
#endif /* OMITCASE0 */
