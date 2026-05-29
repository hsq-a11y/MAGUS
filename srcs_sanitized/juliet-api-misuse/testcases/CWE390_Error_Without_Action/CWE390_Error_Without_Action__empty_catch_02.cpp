/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__empty_catch_02.cpp
Label Definition File: CWE390_Error_Without_Action__empty_catch.label.xml
Template File: point-note-02.tmpl.cpp
*/
/*
 * @description
 * CWE: 390 Error Without Action
 * Sinks:
 *    Case1Sink: Catch and handle the exception if one occurs
 *    Case0Sink : Catch, but do not handle the possible exception
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#include <iostream>
#include <stdexcept>

using namespace std;

namespace CWE390_Error_Without_Action__empty_catch_02
{

#ifndef OMITCASE0

void case0()
{
    if(1)
    {
        {
            try
            {
                string stringHello = "hello";
                string stringSubstring = stringHello.substr(rand(), rand());
                printLine(stringSubstring.c_str());
            }
            catch (out_of_range &)
            {
                /* NOTE: Catch, but do not handle the out_of_range error */
            }
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses if(0) instead of if(1) */
static void case11()
{
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            try
            {
                string stringHello = "hello";
                string stringSubstring = stringHello.substr(rand(), rand());
                printLine(stringSubstring.c_str());
            }
            catch (out_of_range &)
            {
                /* ALT: catch the out_of_range error */
                printLine("Range specified was invalid");
                exit(1);
            }
        }
    }
}

/* case12() reverses the bodies in the if statement */
static void case12()
{
    if(1)
    {
        {
            try
            {
                string stringHello = "hello";
                string stringSubstring = stringHello.substr(rand(), rand());
                printLine(stringSubstring.c_str());
            }
            catch (out_of_range &)
            {
                /* ALT: catch the out_of_range error */
                printLine("Range specified was invalid");
                exit(1);
            }
        }
    }
}

void case1()
{
    case11();
    case12();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE390_Error_Without_Action__empty_catch_02; /* so that we can use case1 and case0 easily */

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
