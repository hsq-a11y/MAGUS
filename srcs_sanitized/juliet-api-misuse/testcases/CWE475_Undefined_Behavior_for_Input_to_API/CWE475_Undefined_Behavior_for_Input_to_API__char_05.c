/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE475_Undefined_Behavior_for_Input_to_API__char_05.c
Label Definition File: CWE475_Undefined_Behavior_for_Input_to_API.label.xml
Template File: point-note-05.tmpl.c
*/
/*
 * @description
 * CWE: 475 Undefined Behavior for Input to API
 * Sinks:
 *    Case1Sink: Copy overlapping memory regions using memmove()
 *    Case0Sink : Copy overlapping memory regions using memcpy()
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

#ifndef OMITCASE0

void CWE475_Undefined_Behavior_for_Input_to_API__char_05_case0()
{
    if(staticTrue)
    {
        {
            char dataBuffer[100] = "";
            char * data = dataBuffer;
            strcpy(data, "abcdefghijklmnopqrstuvwxyz");
            /* NOTE: Copy overlapping memory regions using memcpy() for which the result is undefined */
            memcpy(data + 6, data + 4, 10*sizeof(char));
            printLine(data);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses if(staticFalse) instead of if(staticTrue) */
static void case11()
{
    if(staticFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            char dataBuffer[100] = "";
            char * data = dataBuffer;
            strcpy(data, "abcdefghijklmnopqrstuvwxyz");
            /* ALT: Copy overlapping memory regions using memmove() */
            memmove(data + 6, data + 4, 10*sizeof(char));
            printLine(data);
        }
    }
}

/* case12() reverses the bodies in the if statement */
static void case12()
{
    if(staticTrue)
    {
        {
            char dataBuffer[100] = "";
            char * data = dataBuffer;
            strcpy(data, "abcdefghijklmnopqrstuvwxyz");
            /* ALT: Copy overlapping memory regions using memmove() */
            memmove(data + 6, data + 4, 10*sizeof(char));
            printLine(data);
        }
    }
}

void CWE475_Undefined_Behavior_for_Input_to_API__char_05_case1()
{
    case11();
    case12();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE475_Undefined_Behavior_for_Input_to_API__char_05_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE475_Undefined_Behavior_for_Input_to_API__char_05_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
