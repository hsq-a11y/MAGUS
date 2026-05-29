/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__fopen_15.c
Label Definition File: CWE390_Error_Without_Action.label.xml
Template File: point-note-15.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: fopen
 *    Case1Sink: Check to see if fopen() failed and handle errors properly
 *    Case0Sink : Check to see if fopen() failed, but fail to handle errors
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

void CWE390_Error_Without_Action__fopen_15_case0()
{
    switch(6)
    {
    case 6:
    {
        FILE * fileDesc = NULL;
        fileDesc = fopen("file.txt", "w+");
        /* NOTE: Check to see if fopen failed, but do nothing about it */
        if (fileDesc == NULL)
        {
            /* do nothing */
        }
        fclose(fileDesc);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() changes the switch to switch(5) */
static void case11()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    default:
    {
        FILE * fileDesc = NULL;
        fileDesc = fopen("file.txt", "w+");
        /* ALT: Check to see if fopen failed and handle the error */
        if (fileDesc == NULL)
        {
            printLine("fopen() failed");
            exit(1);
        }
        fclose(fileDesc);
    }
    break;
    }
}

/* case12() reverses the blocks in the switch */
static void case12()
{
    switch(6)
    {
    case 6:
    {
        FILE * fileDesc = NULL;
        fileDesc = fopen("file.txt", "w+");
        /* ALT: Check to see if fopen failed and handle the error */
        if (fileDesc == NULL)
        {
            printLine("fopen() failed");
            exit(1);
        }
        fclose(fileDesc);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE390_Error_Without_Action__fopen_15_case1()
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
    CWE390_Error_Without_Action__fopen_15_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE390_Error_Without_Action__fopen_15_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
