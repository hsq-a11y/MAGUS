/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__wchar_t_fputc_01.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-note-01.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: fputc
 *    Case1Sink: Check if fputwc() fails
 *    Case0Sink : Do not check if fputwc() fails
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITCASE0

void CWE252_Unchecked_Return_Value__wchar_t_fputc_01_case0()
{
    /* NOTE: Do not check the return value */
    fputwc((wchar_t)L'A', stdout);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

static void case11()
{
    /* ALT: check the return value */
    if (fputwc((wchar_t)L'A', stdout) == WEOF)
    {
        printLine("fputwc failed!");
    }
}

void CWE252_Unchecked_Return_Value__wchar_t_fputc_01_case1()
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
    CWE252_Unchecked_Return_Value__wchar_t_fputc_01_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE252_Unchecked_Return_Value__wchar_t_fputc_01_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
