/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_class_realloc_81a.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-81a.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: realloc Allocate data using realloc()
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__delete_array_class_realloc_81.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_class_realloc_81
{

#ifndef OMITCASE0

void case0()
{
    TwoIntsClass * data;
    /* Initialize data*/
    data = NULL;
    data = NULL;
    /* NOTE: Allocate memory with a function that requires free() to free the memory */
    data = (TwoIntsClass *)realloc(data, 100*sizeof(TwoIntsClass));
    if (data == NULL) {exit(-1);}
    const CWE762_Mismatched_Memory_Management_Routines__delete_array_class_realloc_81_base& o = CWE762_Mismatched_Memory_Management_Routines__delete_array_class_realloc_81_case0();
    o.action(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    TwoIntsClass * data;
    /* Initialize data*/
    data = NULL;
    /* ALT: Allocate memory using new [] */
    data = new TwoIntsClass[100];
    const CWE762_Mismatched_Memory_Management_Routines__delete_array_class_realloc_81_base& baseObject = CWE762_Mismatched_Memory_Management_Routines__delete_array_class_realloc_81_case1V1();
    baseObject.action(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
static void case1V2()
{
    TwoIntsClass * data;
    /* Initialize data*/
    data = NULL;
    data = NULL;
    /* NOTE: Allocate memory with a function that requires free() to free the memory */
    data = (TwoIntsClass *)realloc(data, 100*sizeof(TwoIntsClass));
    if (data == NULL) {exit(-1);}
    const CWE762_Mismatched_Memory_Management_Routines__delete_array_class_realloc_81_base& baseObject = CWE762_Mismatched_Memory_Management_Routines__delete_array_class_realloc_81_case1V2();
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

using namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_class_realloc_81; /* so that we can use case1 and case0 easily */

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
