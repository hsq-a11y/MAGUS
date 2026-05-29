/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_21.cpp
Label Definition File: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int.label.xml
Template File: sources-sinks-21.tmpl.cpp
*/
/*
 * @description
 * CWE: 672 Operation on Resource After Expiration or Release
 * Case0Source:  Add values to the list, including the number zero
 * Case1Source: Add value to the list that are not zero
 * Sinks:
 *    Case1Sink: Iterate through the list without attempting to clear its contents
 *    Case0Sink : Iterate through the list, but clear the list if it contains a zero
 * Flow Variant: 21 Control flow: Flow controlled by value of a static global variable. All functions contained in one file.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <list>
#include <iostream>

using namespace std;

namespace CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_21
{

#ifndef OMITCASE0

/* The static variable below is used to drive control flow in the sink function */
static int case0Static = 0;

static void case0Sink(list<int>  data)
{
    if(case0Static)
    {
        {
            list<int> ::iterator i;
            cout << "The list contains: ";
            for( i = data.begin(); i != data.end(); i++)
            {
                if (!*i)
                {
                    data.clear();
                }
                /* NOTE: Dereference the iterator, which may be invalid if data is cleared */
                cout << " " << *i;
            }
            cout << endl;
        }
    }
}

void case0()
{
    list<int>  data;
    /* NOTE: Insert a zero into the list */
    data.push_back(100);
    data.push_back(0);
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
static void case1V21Sink(list<int>  data)
{
    if(case1V21Static)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            list<int> ::iterator i;
            cout << "The list contains: ";
            for( i = data.begin(); i != data.end(); i++)
            {
                /* ALT: Do not make any attempt to clear the list */
                cout << " " << *i;
            }
            cout << endl;
        }
    }
}

static void case1V21()
{
    list<int>  data;
    /* NOTE: Insert a zero into the list */
    data.push_back(100);
    data.push_back(0);
    case1V21Static = 0; /* false */
    case1V21Sink(data);
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
static void case1V22Sink(list<int>  data)
{
    if(case1V22Static)
    {
        {
            list<int> ::iterator i;
            cout << "The list contains: ";
            for( i = data.begin(); i != data.end(); i++)
            {
                /* ALT: Do not make any attempt to clear the list */
                cout << " " << *i;
            }
            cout << endl;
        }
    }
}

static void case1V22()
{
    list<int>  data;
    /* NOTE: Insert a zero into the list */
    data.push_back(100);
    data.push_back(0);
    case1V22Static = 1; /* true */
    case1V22Sink(data);
}

/* case1V1() - use case1source and case0sink */
static void case1V1Sink(list<int>  data)
{
    if(case1G2bStatic)
    {
        {
            list<int> ::iterator i;
            cout << "The list contains: ";
            for( i = data.begin(); i != data.end(); i++)
            {
                if (!*i)
                {
                    data.clear();
                }
                /* NOTE: Dereference the iterator, which may be invalid if data is cleared */
                cout << " " << *i;
            }
            cout << endl;
        }
    }
}

static void case1V1()
{
    list<int>  data;
    /* ALT: Insert non-zero values into the list */
    data.push_back(100);
    data.push_back(200);
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

using namespace CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_21; /* so that we can use case1 and case0 easily */

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
