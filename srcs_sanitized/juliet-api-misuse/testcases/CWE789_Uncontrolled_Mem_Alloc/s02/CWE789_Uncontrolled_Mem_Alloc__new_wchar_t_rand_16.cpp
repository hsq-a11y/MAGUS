/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_16.cpp
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__new.label.xml
Template File: sources-sinks-16.tmpl.cpp
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Small number greater than zero
 * Sinks:
 *    Case1Sink: Allocate memory with new [] and check the size of the memory to be allocated
 *    Case0Sink : Allocate memory with new [], but incorrectly check the size of the memory to be allocated
 * Flow Variant: 16 Control flow: while(1)
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define HELLO_STRING L"hello"

namespace CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_16
{

#ifndef OMITCASE0

void case0()
{
    size_t data;
    /* Initialize data */
    data = 0;
    while(1)
    {
        /* NOTE: Set data to a random value */
        data = rand();
        break;
    }
    while(1)
    {
        {
            wchar_t * myString;
            /* NOTE: No MAXIMUM limitation for memory allocation, but ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL NOTE: The source could cause a type overrun in data or in the memory allocation */
            if (data > wcslen(HELLO_STRING))
            {
                myString = new wchar_t[data];
                /* Copy a small string into myString */
                wcscpy(myString, HELLO_STRING);
                printWLine(myString);
                delete [] myString;
            }
            else
            {
                printLine("Input is less than the length of the source string");
            }
        }
        break;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() - use case0source and case1sink by changing the sinks in the second while statement */
static void case1V2()
{
    size_t data;
    /* Initialize data */
    data = 0;
    while(1)
    {
        /* NOTE: Set data to a random value */
        data = rand();
        break;
    }
    while(1)
    {
        {
            wchar_t * myString;
            /* ALT: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL NOTE: The source could cause a type overrun in data or in the memory allocation */
            if (data > wcslen(HELLO_STRING) && data < 100)
            {
                myString = new wchar_t[data];
                /* Copy a small string into myString */
                wcscpy(myString, HELLO_STRING);
                printWLine(myString);
                delete [] myString;
            }
            else
            {
                printLine("Input is less than the length of the source string or too large");
            }
        }
        break;
    }
}

/* case1V1() - use case1source and case0sink by changing the sources in the first while statement */
static void case1V1()
{
    size_t data;
    /* Initialize data */
    data = 0;
    while(1)
    {
        /* ALT: Use a relatively small number for memory allocation */
        data = 20;
        break;
    }
    while(1)
    {
        {
            wchar_t * myString;
            /* NOTE: No MAXIMUM limitation for memory allocation, but ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL NOTE: The source could cause a type overrun in data or in the memory allocation */
            if (data > wcslen(HELLO_STRING))
            {
                myString = new wchar_t[data];
                /* Copy a small string into myString */
                wcscpy(myString, HELLO_STRING);
                printWLine(myString);
                delete [] myString;
            }
            else
            {
                printLine("Input is less than the length of the source string");
            }
        }
        break;
    }
}

void case1()
{
    case1V2();
    case1V1();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_16; /* so that we can use case1 and case0 easily */

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
