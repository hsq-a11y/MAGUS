/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__fgets_wchar_t_10.c
Label Definition File: CWE390_Error_Without_Action__fgets.label.xml
Template File: point-note-10.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks:
 *    Case1Sink: Check if fgetws() failed and handle errors properly
 *    Case0Sink : Check to see if fgetws() failed, but do nothing about it
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

void CWE390_Error_Without_Action__fgets_wchar_t_10_case0()
{
    if(globalTrue)
    {
        {
            /* By initializing dataBuffer, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) note for fgetws() */
            wchar_t dataBuffer[100] = L"";
            wchar_t * data = dataBuffer;
            printWLine(L"Please enter a string: ");
            /* NOTE: check the return value, but do nothing if there is an error */
            if (fgetws(data, 100, stdin) == NULL)
            {
                /* do nothing */
            }
            printWLine(data);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses if(globalFalse) instead of if(globalTrue) */
static void case11()
{
    if(globalFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            /* By initializing dataBuffer, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) note for fgetws() */
            wchar_t dataBuffer[100] = L"";
            wchar_t * data = dataBuffer;
            printWLine(L"Please enter a string: ");
            /* ALT: check the return value and handle errors properly */
            if (fgetws(data, 100, stdin) == NULL)
            {
                printWLine(L"fgetws failed!");
                exit(1);
            }
            printWLine(data);
        }
    }
}

/* case12() reverses the bodies in the if statement */
static void case12()
{
    if(globalTrue)
    {
        {
            /* By initializing dataBuffer, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) note for fgetws() */
            wchar_t dataBuffer[100] = L"";
            wchar_t * data = dataBuffer;
            printWLine(L"Please enter a string: ");
            /* ALT: check the return value and handle errors properly */
            if (fgetws(data, 100, stdin) == NULL)
            {
                printWLine(L"fgetws failed!");
                exit(1);
            }
            printWLine(data);
        }
    }
}

void CWE390_Error_Without_Action__fgets_wchar_t_10_case1()
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
    CWE390_Error_Without_Action__fgets_wchar_t_10_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE390_Error_Without_Action__fgets_wchar_t_10_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
