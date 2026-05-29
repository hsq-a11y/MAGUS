/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_84a.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE129.label.xml
Template File: sources-sinks-84a.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source: fgets Read data from the console using fgets()
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_84.h"

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_84
{

#ifndef OMITCASE0

void case0()
{
    int data;
    /* Initialize data */
    data = -1;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_84_case0 * case0Object = new CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_84_case0(data);
    delete case0Object;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    int data;
    /* Initialize data */
    data = -1;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_84_case1V1 * case1V1Object = new CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_84_case1V1(data);
    delete case1V1Object;
}

/* case1V1 uses the Case0Source with the Case1Sink */
static void case1V2()
{
    int data;
    /* Initialize data */
    data = -1;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_84_case1V2 * case1V2Object = new CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_84_case1V2(data);
    delete case1V2Object;
}

void case1()
{
    case1V1();
    case1V2();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_84; /* so that we can use case1 and case0 easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
