/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_fscanf_83_case0.cpp
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Case0Source: fscanf Read data from the console using fscanf()
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE126_Buffer_Overread__CWE129_fscanf_83.h"

namespace CWE126_Buffer_Overread__CWE129_fscanf_83
{
CWE126_Buffer_Overread__CWE129_fscanf_83_case0::CWE126_Buffer_Overread__CWE129_fscanf_83_case0(int dataCopy)
{
    data = dataCopy;
    /* NOTE: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
}

CWE126_Buffer_Overread__CWE129_fscanf_83_case0::~CWE126_Buffer_Overread__CWE129_fscanf_83_case0()
{
    {
        int buffer[10] = { 0 };
        /* NOTE: Attempt to access an index of the array that is above the upper bound
         * This check does not check the upper bounds of the array index */
        if (data >= 0)
        {
            printIntLine(buffer[data]);
        }
        else
        {
            printLine("ERROR: Array index is negative");
        }
    }
}
}
#endif /* OMITCASE0 */
