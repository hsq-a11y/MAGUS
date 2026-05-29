/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__new_delete_array_char_08.cpp
Label Definition File: CWE416_Use_After_Free__new_delete_array.label.xml
Template File: sources-sinks-08.tmpl.cpp
*/
/*
 * @description
 * CWE: 416 Use After Free
 * Case0Source:  Allocate data using new, initialize memory block, and Deallocate data using delete
 * Case1Source: Allocate data using new and initialize memory block
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Use data after delete[]
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

namespace CWE416_Use_After_Free__new_delete_array_char_08
{

#ifndef OMITCASE0

void case0()
{
    char * data;
    /* Initialize data */
    data = NULL;
    if(staticReturnsTrue())
    {
        data = new char[100];
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        /* NOTE: Delete data in the source - the case0 sink attempts to use data */
        delete [] data;
    }
    if(staticReturnsTrue())
    {
        /* NOTE: Use of data that may have been deleted */
        printLine(data);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V21() - use case0source and case1sink by changing the second staticReturnsTrue() to staticReturnsFalse() */
static void case1V21()
{
    char * data;
    /* Initialize data */
    data = NULL;
    if(staticReturnsTrue())
    {
        data = new char[100];
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        /* NOTE: Delete data in the source - the case0 sink attempts to use data */
        delete [] data;
    }
    if(staticReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the second if */
static void case1V22()
{
    char * data;
    /* Initialize data */
    data = NULL;
    if(staticReturnsTrue())
    {
        data = new char[100];
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        /* NOTE: Delete data in the source - the case0 sink attempts to use data */
        delete [] data;
    }
    if(staticReturnsTrue())
    {
        /* ALT: Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}

/* case1V11() - use case1source and case0sink by changing the first staticReturnsTrue() to staticReturnsFalse() */
static void case1V11()
{
    char * data;
    /* Initialize data */
    data = NULL;
    if(staticReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        data = new char[100];
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        /* ALT: Do not delete data in the source */
    }
    if(staticReturnsTrue())
    {
        /* NOTE: Use of data that may have been deleted */
        printLine(data);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the first if */
static void case1V12()
{
    char * data;
    /* Initialize data */
    data = NULL;
    if(staticReturnsTrue())
    {
        data = new char[100];
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        /* ALT: Do not delete data in the source */
    }
    if(staticReturnsTrue())
    {
        /* NOTE: Use of data that may have been deleted */
        printLine(data);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
}

void case1()
{
    case1V21();
    case1V22();
    case1V11();
    case1V12();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE416_Use_After_Free__new_delete_array_char_08; /* so that we can use case1 and case0 easily */

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
