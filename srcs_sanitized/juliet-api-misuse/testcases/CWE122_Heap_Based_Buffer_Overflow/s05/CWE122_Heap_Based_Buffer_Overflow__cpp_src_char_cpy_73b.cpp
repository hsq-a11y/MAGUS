/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_src_char_cpy_73b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_src.label.xml
Template File: sources-sink-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize data as a large string
 * Case1Source: Initialize data as a small string
 * Sinks: cpy
 *    Case0Sink : Copy data to string using strcpy
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <wchar.h>

using namespace std;

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_src_char_cpy_73
{

#ifndef OMITCASE0

void case0Sink(list<char *> dataList)
{
    /* copy data out of dataList */
    char * data = dataList.back();
    {
        char dest[50] = "";
        /* NOTE: Possible buffer overflow if data is larger than dest */
        strcpy(dest, data);
        printLine(data);
        delete [] data;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(list<char *> dataList)
{
    char * data = dataList.back();
    {
        char dest[50] = "";
        /* NOTE: Possible buffer overflow if data is larger than dest */
        strcpy(dest, data);
        printLine(data);
        delete [] data;
    }
}

#endif /* OMITCASE1 */

} /* close namespace */
