/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__placement_new_54a.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__placement_new.label.xml
Template File: sources-sinks-54a.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize data to a small buffer
 * Case1Source: Initialize data to a buffer large enough to hold a TwoIntsClass
 * Sinks:
 *    Case1Sink: Allocate a new class using placement new and a buffer that is large enough to hold the class
 *    Case0Sink : Allocate a new class using placement new and a buffer that is too small
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__placement_new_54
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink_b(char * data);

void case0()
{
    char * data;
    char * dataCase0Buffer = (char *)malloc(sizeof(OneIntClass));
    if (dataCase0Buffer == NULL) {exit(-1);}
    char * dataCase1Buffer = (char *)malloc(sizeof(TwoIntsClass));
    if (dataCase1Buffer == NULL) {exit(-1);}
    /* NOTE: Initialize data to a buffer small than the sizeof(TwoIntsClass) */
    data = dataCase0Buffer;
    case0Sink_b(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink_b(char * data);

static void case1V1()
{
    char * data;
    char * dataCase0Buffer = (char *)malloc(sizeof(OneIntClass));
    if (dataCase0Buffer == NULL) {exit(-1);}
    char * dataCase1Buffer = (char *)malloc(sizeof(TwoIntsClass));
    if (dataCase1Buffer == NULL) {exit(-1);}
    /* ALT: Initialize to a buffer at least the sizeof(TwoIntsClass) */
    data = dataCase1Buffer;
    case1V1Sink_b(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink_b(char * data);

static void case1V2()
{
    char * data;
    char * dataCase0Buffer = (char *)malloc(sizeof(OneIntClass));
    if (dataCase0Buffer == NULL) {exit(-1);}
    char * dataCase1Buffer = (char *)malloc(sizeof(TwoIntsClass));
    if (dataCase1Buffer == NULL) {exit(-1);}
    /* NOTE: Initialize data to a buffer small than the sizeof(TwoIntsClass) */
    data = dataCase0Buffer;
    case1V2Sink_b(data);
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

using namespace CWE122_Heap_Based_Buffer_Overflow__placement_new_54; /* so that we can use case1 and case0 easily */

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
