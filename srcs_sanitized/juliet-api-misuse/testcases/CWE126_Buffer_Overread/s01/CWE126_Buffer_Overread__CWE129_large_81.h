/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_large_81.h
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Case0Source: large Large index value that is greater than 10-1
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

namespace CWE126_Buffer_Overread__CWE129_large_81
{

class CWE126_Buffer_Overread__CWE129_large_81_base
{
public:
    /* pure virtual function */
    virtual void action(int data) const = 0;
};

#ifndef OMITCASE0

class CWE126_Buffer_Overread__CWE129_large_81_case0 : public CWE126_Buffer_Overread__CWE129_large_81_base
{
public:
    void action(int data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE126_Buffer_Overread__CWE129_large_81_case1V1 : public CWE126_Buffer_Overread__CWE129_large_81_base
{
public:
    void action(int data) const;
};

class CWE126_Buffer_Overread__CWE129_large_81_case1V2 : public CWE126_Buffer_Overread__CWE129_large_81_base
{
public:
    void action(int data) const;
};

#endif /* OMITCASE1 */

}
