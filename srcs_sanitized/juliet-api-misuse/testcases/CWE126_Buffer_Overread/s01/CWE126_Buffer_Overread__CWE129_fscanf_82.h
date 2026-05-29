/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_fscanf_82.h
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Case0Source: fscanf Read data from the console using fscanf()
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

namespace CWE126_Buffer_Overread__CWE129_fscanf_82
{

class CWE126_Buffer_Overread__CWE129_fscanf_82_base
{
public:
    /* pure virtual function */
    virtual void action(int data) = 0;
};

#ifndef OMITCASE0

class CWE126_Buffer_Overread__CWE129_fscanf_82_case0 : public CWE126_Buffer_Overread__CWE129_fscanf_82_base
{
public:
    void action(int data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE126_Buffer_Overread__CWE129_fscanf_82_case1V1 : public CWE126_Buffer_Overread__CWE129_fscanf_82_base
{
public:
    void action(int data);
};

class CWE126_Buffer_Overread__CWE129_fscanf_82_case1V2 : public CWE126_Buffer_Overread__CWE129_fscanf_82_base
{
public:
    void action(int data);
};

#endif /* OMITCASE1 */

}
