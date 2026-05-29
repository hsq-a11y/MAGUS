/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__new_char_rand_82a.cpp
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__new.label.xml
Template File: sources-sinks-82a.tmpl.cpp
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Small number greater than zero
 * Sinks:
 *    Case1Sink: Allocate memory with new [] and check the size of the memory to be allocated
 *    Case0Sink : Allocate memory with new [], but incorrectly check the size of the memory to be allocated
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE789_Uncontrolled_Mem_Alloc__new_char_rand_82.h"

namespace CWE789_Uncontrolled_Mem_Alloc__new_char_rand_82
{

#ifndef OMITCASE0

void case0()
{
    size_t data;
    /* Initialize data */
    data = 0;
    /* NOTE: Set data to a random value */
    data = rand();
    CWE789_Uncontrolled_Mem_Alloc__new_char_rand_82_base* baseObject = new CWE789_Uncontrolled_Mem_Alloc__new_char_rand_82_case0;
    baseObject->action(data);
    delete baseObject;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    size_t data;
    /* Initialize data */
    data = 0;
    /* ALT: Use a relatively small number for memory allocation */
    data = 20;
    CWE789_Uncontrolled_Mem_Alloc__new_char_rand_82_base* baseObject = new CWE789_Uncontrolled_Mem_Alloc__new_char_rand_82_case1V1;
    baseObject->action(data);
    delete baseObject;
}

/* case1V2 uses the Case0Source with the Case1Sink */
static void case1V2()
{
    size_t data;
    /* Initialize data */
    data = 0;
    /* NOTE: Set data to a random value */
    data = rand();
    CWE789_Uncontrolled_Mem_Alloc__new_char_rand_82_base* baseObject = new CWE789_Uncontrolled_Mem_Alloc__new_char_rand_82_case1V2;
    baseObject->action(data);
    delete baseObject;
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

using namespace CWE789_Uncontrolled_Mem_Alloc__new_char_rand_82; /* so that we can use case1 and case0 easily */

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
