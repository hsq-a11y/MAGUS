/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE391_Unchecked_Error_Condition__wcstombs_17.c
Label Definition File: CWE391_Unchecked_Error_Condition.label.xml
Template File: point-note-17.tmpl.c
*/
/*
 * @description
 * CWE: 391 Unchecked Error Condition
 * Sinks: wcstombs
 *    Case1Sink: Perform error checks and handling
 *    Case0Sink : Do not check if wcstombs() failed
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#include <errno.h>

#ifndef OMITCASE0

void CWE391_Unchecked_Error_Condition__wcstombs_17_case0()
{
    int j;
    for(j = 0; j < 1; j++)
    {
        {
            size_t bytesTranslated = 0;
            char charString[100];
            charString[0] = '\0';
            bytesTranslated = wcstombs((char *)&charString, L"\xffff", 100);
            /* NOTE: Do not check to see if wcstombs() failed */
            printUnsignedLine(bytesTranslated);
            printLine(charString);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses the Case1SinkBody in the for statements */
static void case11()
{
    int k;
    for(k = 0; k < 1; k++)
    {
        {
            size_t bytesTranslated = 0;
            char charString[100];
            charString[0] = '\0';
            errno = 0; /* set errno to zero before calling wcstombs(), which can change its value */
            bytesTranslated = wcstombs((char *)&charString, L"\xffff", 100);
            /* ALT: Check errno to see if wcstombs() failed */
            if (errno == EILSEQ)
            {
                printLine("wcstombs() failed");
                exit(1);
            }
            printUnsignedLine(bytesTranslated);
            printLine(charString);
        }
    }
}

void CWE391_Unchecked_Error_Condition__wcstombs_17_case1()
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
    CWE391_Unchecked_Error_Condition__wcstombs_17_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE391_Unchecked_Error_Condition__wcstombs_17_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
