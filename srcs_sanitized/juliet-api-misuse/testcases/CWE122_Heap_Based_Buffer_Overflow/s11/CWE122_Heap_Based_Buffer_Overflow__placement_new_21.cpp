/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__placement_new_21.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__placement_new.label.xml
Template File: sources-sinks-21.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize data to a small buffer
 * Case1Source: Initialize data to a buffer large enough to hold a TwoIntsClass
 * Sinks:
 *    Case1Sink: Allocate a new class using placement new and a buffer that is large enough to hold the class
 *    Case0Sink : Allocate a new class using placement new and a buffer that is too small
 * Flow Variant: 21 Control flow: Flow controlled by value of a static global variable. All functions contained in one file.
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__placement_new_21
{

#ifndef OMITCASE0

/* The static variable below is used to drive control flow in the sink function */
static int case0Static = 0;

static void case0Sink(char * data)
{
    if(case0Static)
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

void case0()
{
    char * data;
    char * dataCase0Buffer = (char *)malloc(sizeof(OneIntClass));
    if (dataCase0Buffer == NULL) {exit(-1);}
    char * dataCase1Buffer = (char *)malloc(sizeof(TwoIntsClass));
    if (dataCase1Buffer == NULL) {exit(-1);}
    /* NOTE: Initialize data to a buffer small than the sizeof(TwoIntsClass) */
    data = dataCase0Buffer;
    case0Static = 1; /* true */
    case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The static variables below are used to drive control flow in the sink functions. */
static int case1V21Static = 0;
static int case1V22Static = 0;
static int case1G2bStatic = 0;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
static void case1V21Sink(char * data)
{
    if(case1V21Static)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
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

static void case1V21()
{
    char * data;
    char * dataCase0Buffer = (char *)malloc(sizeof(OneIntClass));
    if (dataCase0Buffer == NULL) {exit(-1);}
    char * dataCase1Buffer = (char *)malloc(sizeof(TwoIntsClass));
    if (dataCase1Buffer == NULL) {exit(-1);}
    /* NOTE: Initialize data to a buffer small than the sizeof(TwoIntsClass) */
    data = dataCase0Buffer;
    case1V21Static = 0; /* false */
    case1V21Sink(data);
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
static void case1V22Sink(char * data)
{
    if(case1V22Static)
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

static void case1V22()
{
    char * data;
    char * dataCase0Buffer = (char *)malloc(sizeof(OneIntClass));
    if (dataCase0Buffer == NULL) {exit(-1);}
    char * dataCase1Buffer = (char *)malloc(sizeof(TwoIntsClass));
    if (dataCase1Buffer == NULL) {exit(-1);}
    /* NOTE: Initialize data to a buffer small than the sizeof(TwoIntsClass) */
    data = dataCase0Buffer;
    case1V22Static = 1; /* true */
    case1V22Sink(data);
}

/* case1V1() - use case1source and case0sink */
static void case1V1Sink(char * data)
{
    if(case1G2bStatic)
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

static void case1V1()
{
    char * data;
    char * dataCase0Buffer = (char *)malloc(sizeof(OneIntClass));
    if (dataCase0Buffer == NULL) {exit(-1);}
    char * dataCase1Buffer = (char *)malloc(sizeof(TwoIntsClass));
    if (dataCase1Buffer == NULL) {exit(-1);}
    /* ALT: Initialize to a buffer at least the sizeof(TwoIntsClass) */
    data = dataCase1Buffer;
    case1G2bStatic = 1; /* true */
    case1V1Sink(data);
}

void case1()
{
    case1V21();
    case1V22();
    case1V1();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE122_Heap_Based_Buffer_Overflow__placement_new_21; /* so that we can use case1 and case0 easily */

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
