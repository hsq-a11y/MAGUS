/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__new_wchar_t_loop_84_case1V1.cpp
Label Definition File: CWE126_Buffer_Overread__new.label.xml
Template File: sources-sink-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * Case0Source:  Use a small buffer
 * Case1Source: Use a large buffer
 * Sinks: loop
 *    Case0Sink : Copy data to string using a loop
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE126_Buffer_Overread__new_wchar_t_loop_84.h"

namespace CWE126_Buffer_Overread__new_wchar_t_loop_84
{
CWE126_Buffer_Overread__new_wchar_t_loop_84_case1V1::CWE126_Buffer_Overread__new_wchar_t_loop_84_case1V1(wchar_t * dataCopy)
{
    data = dataCopy;
    /* ALT: Use a large buffer */
    data = new wchar_t[100];
    wmemset(data, L'A', 100-1); /* fill with 'A's */
    data[100-1] = L'\0'; /* null terminate */
}

CWE126_Buffer_Overread__new_wchar_t_loop_84_case1V1::~CWE126_Buffer_Overread__new_wchar_t_loop_84_case1V1()
{
    {
        size_t i, destLen;
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        destLen = wcslen(dest);
        /* NOTE: using length of the dest where data
         * could be smaller than dest causing buffer overread */
        for (i = 0; i < destLen; i++)
        {
            dest[i] = data[i];
        }
        dest[100-1] = L'\0';
        printWLine(dest);
        delete [] data;
    }
}
}
#endif /* OMITCASE1 */
