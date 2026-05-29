/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__CWE839_fscanf_84_case1V2.cpp
Label Definition File: CWE127_Buffer_Underread__CWE839.label.xml
Template File: sources-sinks-84_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 127 Buffer Underread
 * Case0Source: fscanf Read data from the console using fscanf()
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking to see if the value is negative
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE127_Buffer_Underread__CWE839_fscanf_84.h"

namespace CWE127_Buffer_Underread__CWE839_fscanf_84
{
CWE127_Buffer_Underread__CWE839_fscanf_84_case1V2::CWE127_Buffer_Underread__CWE839_fscanf_84_case1V2(int dataCopy)
{
    data = dataCopy;
    /* NOTE: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
}

CWE127_Buffer_Underread__CWE839_fscanf_84_case1V2::~CWE127_Buffer_Underread__CWE839_fscanf_84_case1V2()
{
    {
        int buffer[10] = { 0 };
        /* ALT: Properly validate the array index and prevent a buffer underread */
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
