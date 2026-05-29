/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__placement_new_44.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__placement_new.label.xml
Template File: sources-sinks-44.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize data to a small buffer
 * Case1Source: Initialize data to a buffer large enough to hold a TwoIntsClass
 * Sinks:
 *    Case1Sink: Allocate a new class using placement new and a buffer that is large enough to hold the class
 *    Case0Sink : Allocate a new class using placement new and a buffer that is too small
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__placement_new_44
{

#ifndef OMITCASE0

static void case0Sink(char * data)
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

void case0()
{
    char * data;
    /* define a function pointer */
    void (*funcPtr) (char *) = case0Sink;
    char * dataCase0Buffer = (char *)malloc(sizeof(OneIntClass));
    if (dataCase0Buffer == NULL) {exit(-1);}
    char * dataCase1Buffer = (char *)malloc(sizeof(TwoIntsClass));
    if (dataCase1Buffer == NULL) {exit(-1);}
    /* NOTE: Initialize data to a buffer small than the sizeof(TwoIntsClass) */
    data = dataCase0Buffer;
    /* use the function pointer */
    funcPtr(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1Sink(char * data)
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

static void case1V1()
{
    char * data;
    void (*funcPtr) (char *) = case1V1Sink;
    char * dataCase0Buffer = (char *)malloc(sizeof(OneIntClass));
    if (dataCase0Buffer == NULL) {exit(-1);}
    char * dataCase1Buffer = (char *)malloc(sizeof(TwoIntsClass));
    if (dataCase1Buffer == NULL) {exit(-1);}
    /* ALT: Initialize to a buffer at least the sizeof(TwoIntsClass) */
    data = dataCase1Buffer;
    funcPtr(data);
}

/* case1V2() uses the Case0Source with the Case1Sink */
static void case1V2Sink(char * data)
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

static void case1V2()
{
    char * data;
    void (*funcPtr) (char *) = case1V2Sink;
    char * dataCase0Buffer = (char *)malloc(sizeof(OneIntClass));
    if (dataCase0Buffer == NULL) {exit(-1);}
    char * dataCase1Buffer = (char *)malloc(sizeof(TwoIntsClass));
    if (dataCase1Buffer == NULL) {exit(-1);}
    /* NOTE: Initialize data to a buffer small than the sizeof(TwoIntsClass) */
    data = dataCase0Buffer;
    funcPtr(data);
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

using namespace CWE122_Heap_Based_Buffer_Overflow__placement_new_44; /* so that we can use case1 and case0 easily */

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
