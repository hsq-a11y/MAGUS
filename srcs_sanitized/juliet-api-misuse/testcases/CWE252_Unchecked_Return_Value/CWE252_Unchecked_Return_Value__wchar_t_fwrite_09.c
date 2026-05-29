/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__wchar_t_fwrite_09.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-note-09.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: fwrite
 *    Case1Sink: Check if fwrite() fails
 *    Case0Sink : Do not check if fwrite() fails
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITCASE0

void CWE252_Unchecked_Return_Value__wchar_t_fwrite_09_case0()
{
    if(GLOBAL_CONST_TRUE)
    {
        /* NOTE: Do not check the return value */
        fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses if(GLOBAL_CONST_FALSE) instead of if(GLOBAL_CONST_TRUE) */
static void case11()
{
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: check the return value */
        if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) != wcslen(L"string"))
        {
            printLine("fwrite failed!");
        }
    }
}

/* case12() reverses the bodies in the if statement */
static void case12()
{
    if(GLOBAL_CONST_TRUE)
    {
        /* ALT: check the return value */
        if (fwrite((wchar_t *)L"string", sizeof(wchar_t), wcslen(L"string"), stdout) != wcslen(L"string"))
        {
            printLine("fwrite failed!");
        }
    }
}

void CWE252_Unchecked_Return_Value__wchar_t_fwrite_09_case1()
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
    CWE252_Unchecked_Return_Value__wchar_t_fwrite_09_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE252_Unchecked_Return_Value__wchar_t_fwrite_09_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
