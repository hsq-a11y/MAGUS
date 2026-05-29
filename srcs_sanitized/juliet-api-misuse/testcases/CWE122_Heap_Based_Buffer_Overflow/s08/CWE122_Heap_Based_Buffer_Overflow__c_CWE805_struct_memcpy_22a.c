/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_22a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using malloc() and set data pointer to a small buffer
 * Case1Source: Allocate using malloc() and set data pointer to a large buffer
 * Sink: memcpy
 *    Case0Sink : Copy twoIntsStruct array to data using memcpy
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
int CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_22_case0Global = 0;

twoIntsStruct * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_22_case0Source(twoIntsStruct * data);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_22_case0()
{
    twoIntsStruct * data;
    data = NULL;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_22_case0Global = 1; /* true */
    data = CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_22_case0Source(data);
    {
        twoIntsStruct source[100];
        {
            size_t i;
            /* Initialize array */
            for (i = 0; i < 100; i++)
            {
                source[i].intOne = 0;
                source[i].intTwo = 0;
            }
        }
        /* NOTE: Possible buffer overflow if data < 100 */
        memcpy(data, source, 100*sizeof(twoIntsStruct));
        printStructLine(&data[0]);
        free(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
int CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_22_case1V11Global = 0;
int CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_22_case1V12Global = 0;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
twoIntsStruct * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_22_case1V11Source(twoIntsStruct * data);

static void case1V11()
{
    twoIntsStruct * data;
    data = NULL;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_22_case1V11Global = 0; /* false */
    data = CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_22_case1V11Source(data);
    {
        twoIntsStruct source[100];
        {
            size_t i;
            /* Initialize array */
            for (i = 0; i < 100; i++)
            {
                source[i].intOne = 0;
                source[i].intTwo = 0;
            }
        }
        /* NOTE: Possible buffer overflow if data < 100 */
        memcpy(data, source, 100*sizeof(twoIntsStruct));
        printStructLine(&data[0]);
        free(data);
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
twoIntsStruct * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_22_case1V12Source(twoIntsStruct * data);

static void case1V12()
{
    twoIntsStruct * data;
    data = NULL;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_22_case1V12Global = 1; /* true */
    data = CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_22_case1V12Source(data);
    {
        twoIntsStruct source[100];
        {
            size_t i;
            /* Initialize array */
            for (i = 0; i < 100; i++)
            {
                source[i].intOne = 0;
                source[i].intTwo = 0;
            }
        }
        /* NOTE: Possible buffer overflow if data < 100 */
        memcpy(data, source, 100*sizeof(twoIntsStruct));
        printStructLine(&data[0]);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_22_case1()
{
    case1V11();
    case1V12();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
