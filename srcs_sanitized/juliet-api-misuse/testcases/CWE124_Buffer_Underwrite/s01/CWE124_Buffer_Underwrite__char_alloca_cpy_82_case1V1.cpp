/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__char_alloca_cpy_82_case1V1.cpp
Label Definition File: CWE124_Buffer_Underwrite.stack.label.xml
Template File: sources-sink-82_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sinks: cpy
 *    Case0Sink : Copy string to data using strcpy
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE124_Buffer_Underwrite__char_alloca_cpy_82.h"

namespace CWE124_Buffer_Underwrite__char_alloca_cpy_82
{

void CWE124_Buffer_Underwrite__char_alloca_cpy_82_case1V1::action(char * data)
{
    {
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        /* NOTE: Possibly copying data to memory before the destination buffer */
        strcpy(data, source);
        printLine(data);
    }
}

}
#endif /* OMITCASE1 */
