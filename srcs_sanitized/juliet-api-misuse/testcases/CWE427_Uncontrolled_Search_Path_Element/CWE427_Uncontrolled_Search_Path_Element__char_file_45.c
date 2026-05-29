/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__char_file_45.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * Case0Source: file Read input from a file
 * Case1Source: Use a hardcoded path
 * Sinks:
 *    Case0Sink : Set the environment variable
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
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

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

static char * CWE427_Uncontrolled_Search_Path_Element__char_file_45_case0Data;
static char * CWE427_Uncontrolled_Search_Path_Element__char_file_45_case1V1Data;

#ifndef OMITCASE0

static void case0Sink()
{
    char * data = CWE427_Uncontrolled_Search_Path_Element__char_file_45_case0Data;
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

void CWE427_Uncontrolled_Search_Path_Element__char_file_45_case0()
{
    char * data;
    char dataBuffer[250] = "PATH=";
    data = dataBuffer;
    {
        /* Read input from a file */
        size_t dataLen = strlen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (250-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* NOTE: Read data from a file */
                if (fgets(data+dataLen, (int)(250-dataLen), pFile) == NULL)
                {
                    printLine("fgets() failed");
                    /* Restore NUL terminator if fgets fails */
                    data[dataLen] = '\0';
                }
                fclose(pFile);
            }
        }
    }
    CWE427_Uncontrolled_Search_Path_Element__char_file_45_case0Data = data;
    case0Sink();
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1Sink()
{
    char * data = CWE427_Uncontrolled_Search_Path_Element__char_file_45_case1V1Data;
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

static void case1V1()
{
    char * data;
    char dataBuffer[250] = "PATH=";
    data = dataBuffer;
    /* ALT: Set the path as the "system" path */
    strcat(data, NEW_PATH);
    CWE427_Uncontrolled_Search_Path_Element__char_file_45_case1V1Data = data;
    case1V1Sink();
}

void CWE427_Uncontrolled_Search_Path_Element__char_file_45_case1()
{
    case1V1();
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
    CWE427_Uncontrolled_Search_Path_Element__char_file_45_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE427_Uncontrolled_Search_Path_Element__char_file_45_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
