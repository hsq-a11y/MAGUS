/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE135_81a.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-81a.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Void pointer to a wchar_t array
 * Case1Source: Void pointer to a char array
 * Sinks:
 *    Case1Sink: Allocate memory using wcslen() and copy data
 *    Case0Sink : Allocate memory using strlen() and copy data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__CWE135_81.h"

namespace CWE122_Heap_Based_Buffer_Overflow__CWE135_81
{

#ifndef OMITCASE0

void case0()
{
    void * data;
    data = NULL;
    {
        wchar_t * dataCase0Buffer = (wchar_t *)malloc(50*sizeof(wchar_t));
        if (dataCase0Buffer == NULL) {exit(-1);}
        wmemset(dataCase0Buffer, L'A', 50-1);
        dataCase0Buffer[50-1] = L'\0';
        /* NOTE: Set data to point to a wide string */
        data = (void *)dataCase0Buffer;
    }
    const CWE122_Heap_Based_Buffer_Overflow__CWE135_81_base& baseObject = CWE122_Heap_Based_Buffer_Overflow__CWE135_81_case0();
    baseObject.action(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    void * data;
    data = NULL;
    {
        char * dataCase1Buffer = (char *)malloc(50*sizeof(char));
        if (dataCase1Buffer == NULL) {exit(-1);}
        memset(dataCase1Buffer, 'A', 50-1);
        dataCase1Buffer[50-1] = '\0';
        /* ALT: Set data to point to a char string */
        data = (void *)dataCase1Buffer;
    }
    const CWE122_Heap_Based_Buffer_Overflow__CWE135_81_base& baseObject = CWE122_Heap_Based_Buffer_Overflow__CWE135_81_case1V1();
    baseObject.action(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
static void case1V2()
{
    void * data;
    data = NULL;
    {
        wchar_t * dataCase0Buffer = (wchar_t *)malloc(50*sizeof(wchar_t));
        if (dataCase0Buffer == NULL) {exit(-1);}
        wmemset(dataCase0Buffer, L'A', 50-1);
        dataCase0Buffer[50-1] = L'\0';
        /* NOTE: Set data to point to a wide string */
        data = (void *)dataCase0Buffer;
    }
    const CWE122_Heap_Based_Buffer_Overflow__CWE135_81_base& baseObject = CWE122_Heap_Based_Buffer_Overflow__CWE135_81_case1V2();
    baseObject.action(data);
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

using namespace CWE122_Heap_Based_Buffer_Overflow__CWE135_81; /* so that we can use case1 and case0 easily */

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
