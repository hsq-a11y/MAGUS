/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_84.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE129.label.xml
Template File: sources-sinks-84.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source: fscanf Read data from the console using fscanf()
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_84
{

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_84_case0
{
public:
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_84_case0(int dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_84_case0();

private:
    int data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_84_case1V1
{
public:
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_84_case1V1(int dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_84_case1V1();

private:
    int data;
};

class CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_84_case1V2
{
public:
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_84_case1V2(int dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_84_case1V2();

private:
    int data;
};

#endif /* OMITCASE1 */

}
