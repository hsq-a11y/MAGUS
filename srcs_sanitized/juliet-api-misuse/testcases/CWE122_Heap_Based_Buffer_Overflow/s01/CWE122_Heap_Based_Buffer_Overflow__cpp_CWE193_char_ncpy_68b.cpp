/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_ncpy_68b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193.label.xml
Template File: sources-sink-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory for a string, but do not allocate space for NULL terminator
 * Case1Source: Allocate enough memory for a string and the NULL terminator
 * Sink: ncpy
 *    Case0Sink : Copy string to data using strncpy()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING "AAAAAAAAAA"

extern char * CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_ncpy_68_case0Data;
extern char * CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_ncpy_68_case1V1Data;

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_ncpy_68
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

void case0Sink()
{
    char * data = CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_ncpy_68_case0Data;
    {
        char source[10+1] = SRC_STRING;
        /* Copy length + 1 to include NUL terminator from source */
        /* NOTE: data may not have enough space to hold source */
        strncpy(data, source, strlen(source) + 1);
        printLine(data);
        delete [] data;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink()
{
    char * data = CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_ncpy_68_case1V1Data;
    {
        char source[10+1] = SRC_STRING;
        /* Copy length + 1 to include NUL terminator from source */
        /* NOTE: data may not have enough space to hold source */
        strncpy(data, source, strlen(source) + 1);
        printLine(data);
        delete [] data;
    }
}

#endif /* OMITCASE1 */

} /* close namespace */
