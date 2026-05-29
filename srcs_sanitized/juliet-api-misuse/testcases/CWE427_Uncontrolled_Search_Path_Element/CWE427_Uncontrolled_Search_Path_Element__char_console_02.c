/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__char_console_02.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-02.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * Case0Source: console Read input from the console
 * Case1Source: Use a hardcoded path
 * Sink:
 *    Case0Sink : Set the environment variable
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define NEW_PATH "%SystemRoot%\\system32"
#define PUTENV _putenv
#else
#define NEW_PATH "/bin"
#define PUTENV putenv
#endif

#ifndef OMITCASE0

void CWE427_Uncontrolled_Search_Path_Element__char_console_02_case0()
{
    char * data;
    char dataBuffer[250] = "PATH=";
    data = dataBuffer;
    if(1)
    {
        {
            /* Read input from the console */
            size_t dataLen = strlen(data);
            /* if there is room in data, read into it from the console */
            if (250-dataLen > 1)
            {
                /* NOTE: Read data from the console */
                if (fgets(data+dataLen, (int)(250-dataLen), stdin) != NULL)
                {
                    /* The next few lines remove the carriage return from the string that is
                     * inserted by fgets() */
                    dataLen = strlen(data);
                    if (dataLen > 0 && data[dataLen-1] == '\n')
                    {
                        data[dataLen-1] = '\0';
                    }
                }
                else
                {
                    printLine("fgets() failed");
                    /* Restore NUL terminator if fgets fails */
                    data[dataLen] = '\0';
                }
            }
        }
    }
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V11() - use case1source and case0sink by changing the 1 to 0 */
static void case1V11()
{
    char * data;
    char dataBuffer[250] = "PATH=";
    data = dataBuffer;
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Set the path as the "system" path */
        strcat(data, NEW_PATH);
    }
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if statement */
static void case1V12()
{
    char * data;
    char dataBuffer[250] = "PATH=";
    data = dataBuffer;
    if(1)
    {
        /* ALT: Set the path as the "system" path */
        strcat(data, NEW_PATH);
    }
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

void CWE427_Uncontrolled_Search_Path_Element__char_console_02_case1()
{
    case1V11();
    case1V12();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE427_Uncontrolled_Search_Path_Element__char_console_02_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE427_Uncontrolled_Search_Path_Element__char_console_02_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
