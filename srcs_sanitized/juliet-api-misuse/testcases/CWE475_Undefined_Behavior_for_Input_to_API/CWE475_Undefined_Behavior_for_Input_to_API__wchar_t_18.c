/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE475_Undefined_Behavior_for_Input_to_API__wchar_t_18.c
Label Definition File: CWE475_Undefined_Behavior_for_Input_to_API.label.xml
Template File: point-note-18.tmpl.c
*/
/*
 * @description
 * CWE: 475 Undefined Behavior for Input to API
 * Sinks:
 *    Case1Sink: Copy overlapping memory regions using memmove()
 *    Case0Sink : Copy overlapping memory regions using memcpy()
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

void CWE475_Undefined_Behavior_for_Input_to_API__wchar_t_18_case0()
{
    goto sink;
sink:
    {
        wchar_t dataBuffer[100] = L"";
        wchar_t * data = dataBuffer;
        wcscpy(data, L"abcdefghijklmnopqrstuvwxyz");
        /* NOTE: Copy overlapping memory regions using memcpy() for which the result is undefined */
        memcpy(data + 6, data + 4, 10*sizeof(wchar_t));
        printWLine(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() reverses the blocks on the goto statement */
static void case11()
{
    goto sink;
sink:
    {
        wchar_t dataBuffer[100] = L"";
        wchar_t * data = dataBuffer;
        wcscpy(data, L"abcdefghijklmnopqrstuvwxyz");
        /* ALT: Copy overlapping memory regions using memmove() */
        memmove(data + 6, data + 4, 10*sizeof(wchar_t));
        printWLine(data);
    }
}

void CWE475_Undefined_Behavior_for_Input_to_API__wchar_t_18_case1()
{
    case11();
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
    CWE475_Undefined_Behavior_for_Input_to_API__wchar_t_18_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE475_Undefined_Behavior_for_Input_to_API__wchar_t_18_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
