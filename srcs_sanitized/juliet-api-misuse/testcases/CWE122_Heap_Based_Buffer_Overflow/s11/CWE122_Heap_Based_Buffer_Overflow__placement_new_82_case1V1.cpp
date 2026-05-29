/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__placement_new_82_case1V1.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__placement_new.label.xml
Template File: sources-sinks-82_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize data to a small buffer
 * Case1Source: Initialize data to a buffer large enough to hold a TwoIntsClass
 * Sinks:
 *    Case1Sink: Allocate a new class using placement new and a buffer that is large enough to hold the class
 *    Case0Sink : Allocate a new class using placement new and a buffer that is too small
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__placement_new_82.h"

namespace CWE122_Heap_Based_Buffer_Overflow__placement_new_82
{

void CWE122_Heap_Based_Buffer_Overflow__placement_new_82_case1V1::action(char * data)
{
    {
        /* The Visual C++ compiler generates a warning if you initialize the class with ().
         * This will cause the compile to default-initialize the object.
         * See http://msdn.microsoft.com/en-us/library/wewb47ee%28v=VS.100%29.aspx
         */
        /* NOTE: data may not be large enough to hold a TwoIntsClass */
        TwoIntsClass * classTwo = new(data) TwoIntsClass;
        /* Initialize and make use of the class */
        classTwo->intOne = 5;
        classTwo->intTwo = 10; /* NOTE: If sizeof(data) < sizeof(TwoIntsClass) then this line will be a buffer overflow */
        printIntLine(classTwo->intOne);
        /* skip printing classTwo->intTwo since that could be a buffer overread */
        free(data);
    }
}

}
#endif /* OMITCASE1 */
