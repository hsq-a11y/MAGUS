/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_fscanf_84_case1V2.cpp
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-84_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Case0Source: fscanf Read data from the console using fscanf()
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE126_Buffer_Overread__CWE129_fscanf_84.h"

namespace CWE126_Buffer_Overread__CWE129_fscanf_84
{
CWE126_Buffer_Overread__CWE129_fscanf_84_case1V2::CWE126_Buffer_Overread__CWE129_fscanf_84_case1V2(int dataCopy)
{
    data = dataCopy;
    /* NOTE: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
}

CWE126_Buffer_Overread__CWE129_fscanf_84_case1V2::~CWE126_Buffer_Overread__CWE129_fscanf_84_case1V2()
{
    {
        int buffer[10] = { 0 };
        /* ALT: Properly validate the array index and prevent a buffer overread */
        if (data >= 0 && data < (10))
        {
            printIntLine(buffer[data]);
        }
        else
        {
            printLine("ERROR: Array index is out-of-bounds");
        }
    }
}
}
#endif /* OMITCASE1 */
