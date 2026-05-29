/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_66a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE129.label.xml
Template File: sources-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source: fscanf Read data from the console using fscanf()
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_66b_case0Sink(int dataArray[]);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_66_case0()
{
    int data;
    int dataArray[5];
    /* Initialize data */
    data = -1;
    /* NOTE: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    /* put data in array */
    dataArray[2] = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_66b_case0Sink(dataArray);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_66b_case1V1Sink(int dataArray[]);

static void case1V1()
{
    int data;
    int dataArray[5];
    /* Initialize data */
    data = -1;
    /* ALT: Use a value greater than 0, but less than 10 to avoid attempting to
    * access an index of the array in the sink that is out-of-bounds */
    data = 7;
    dataArray[2] = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_66b_case1V1Sink(dataArray);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_66b_case1V2Sink(int dataArray[]);

static void case1V2()
{
    int data;
    int dataArray[5];
    /* Initialize data */
    data = -1;
    /* NOTE: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    dataArray[2] = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_66b_case1V2Sink(dataArray);
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_66_case1()
{
    case1V1();
    case1V2();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_66_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_66_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
