/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__placement_new_82_case1V2.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__placement_new.label.xml
Template File: sources-sinks-82_case1V2.tmpl.cpp
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

void CWE122_Heap_Based_Buffer_Overflow__placement_new_82_case1V2::action(char * data)
{
    {
        /* The Visual C++ compiler generates a warning if you initialize the class with ().
         * This will cause the compile to default-initialize the object.
         * See http://msdn.microsoft.com/en-us/library/wewb47ee%28v=VS.100%29.aspx
         */
        /* ALT: data will at least be the sizeof(OneIntClass) */
        OneIntClass * classOne = new(data) OneIntClass;
        /* Initialize and make use of the class */
        classOne->intOne = 5;
        printIntLine(classOne->intOne);
        free(data);
    }
}

}
#endif /* OMITCASE1 */
