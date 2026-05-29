/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_struct_twoIntsStruct_82a.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-82a.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call delete on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE401_Memory_Leak__new_struct_twoIntsStruct_82.h"

namespace CWE401_Memory_Leak__new_struct_twoIntsStruct_82
{

#ifndef OMITCASE0

void case0()
{
    struct _twoIntsStruct * data;
    data = NULL;
    /* NOTE: Allocate memory on the heap */
    data = new struct _twoIntsStruct;
    /* Initialize and make use of data */
    data->intOne = 0;
    data->intTwo = 0;
    printStructLine((twoIntsStruct *)data);
    CWE401_Memory_Leak__new_struct_twoIntsStruct_82_base* baseObject = new CWE401_Memory_Leak__new_struct_twoIntsStruct_82_case0;
    baseObject->action(data);
    delete baseObject;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    struct _twoIntsStruct * data;
    data = NULL;
    /* ALT: Use memory allocated on the stack */
    struct _twoIntsStruct dataCase1Buffer;
    data = &dataCase1Buffer;
    /* Initialize and make use of data */
    data->intOne = 0;
    data->intTwo = 0;
    printStructLine((twoIntsStruct *)data);
    CWE401_Memory_Leak__new_struct_twoIntsStruct_82_base* baseObject = new CWE401_Memory_Leak__new_struct_twoIntsStruct_82_case1V1;
    baseObject->action(data);
    delete baseObject;
}

/* case1V2 uses the Case0Source with the Case1Sink */
static void case1V2()
{
    struct _twoIntsStruct * data;
    data = NULL;
    /* NOTE: Allocate memory on the heap */
    data = new struct _twoIntsStruct;
    /* Initialize and make use of data */
    data->intOne = 0;
    data->intTwo = 0;
    printStructLine((twoIntsStruct *)data);
    CWE401_Memory_Leak__new_struct_twoIntsStruct_82_base* baseObject = new CWE401_Memory_Leak__new_struct_twoIntsStruct_82_case1V2;
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

using namespace CWE401_Memory_Leak__new_struct_twoIntsStruct_82; /* so that we can use case1 and case0 easily */

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
