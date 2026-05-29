/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_fscanf_62b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source: fscanf Read data from the console using fscanf()
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_fscanf_62
{

#ifndef OMITCASE0

void case0Source(int &data)
{
    /* NOTE: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
void case1V1Source(int &data)
{
    /* ALT: Use a value greater than 0, but less than 10 to avoid attempting to
     * access an index of the array in the sink that is out-of-bounds */
    data = 7;
}

/* case1V2() uses the Case0Source with the Case1Sink */
void case1V2Source(int &data)
{
    /* NOTE: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
}

#endif /* OMITCASE1 */

} /* close namespace */
