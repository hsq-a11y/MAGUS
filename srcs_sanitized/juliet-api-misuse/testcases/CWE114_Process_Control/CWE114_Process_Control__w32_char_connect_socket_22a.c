/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_connect_socket_22a.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Hard code the full pathname to the library
 * Sink:
 *    Case0Sink : Load a dynamic link library
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
int CWE114_Process_Control__w32_char_connect_socket_22_case0Global = 0;

char * CWE114_Process_Control__w32_char_connect_socket_22_case0Source(char * data);

void CWE114_Process_Control__w32_char_connect_socket_22_case0()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    CWE114_Process_Control__w32_char_connect_socket_22_case0Global = 1; /* true */
    data = CWE114_Process_Control__w32_char_connect_socket_22_case0Source(data);
    {
        HMODULE hModule;
        /* NOTE: If the path to the library is not specified, an attacker may be able to
         * replace his own file with the intended library */
        hModule = LoadLibraryA(data);
        if (hModule != NULL)
        {
            FreeLibrary(hModule);
            printLine("Library loaded and freed successfully");
        }
        else
        {
            printLine("Unable to load library");
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
int CWE114_Process_Control__w32_char_connect_socket_22_case1V11Global = 0;
int CWE114_Process_Control__w32_char_connect_socket_22_case1V12Global = 0;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
char * CWE114_Process_Control__w32_char_connect_socket_22_case1V11Source(char * data);

static void case1V11()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    CWE114_Process_Control__w32_char_connect_socket_22_case1V11Global = 0; /* false */
    data = CWE114_Process_Control__w32_char_connect_socket_22_case1V11Source(data);
    {
        HMODULE hModule;
        /* NOTE: If the path to the library is not specified, an attacker may be able to
         * replace his own file with the intended library */
        hModule = LoadLibraryA(data);
        if (hModule != NULL)
        {
            FreeLibrary(hModule);
            printLine("Library loaded and freed successfully");
        }
        else
        {
            printLine("Unable to load library");
        }
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
char * CWE114_Process_Control__w32_char_connect_socket_22_case1V12Source(char * data);

static void case1V12()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    CWE114_Process_Control__w32_char_connect_socket_22_case1V12Global = 1; /* true */
    data = CWE114_Process_Control__w32_char_connect_socket_22_case1V12Source(data);
    {
        HMODULE hModule;
        /* NOTE: If the path to the library is not specified, an attacker may be able to
         * replace his own file with the intended library */
        hModule = LoadLibraryA(data);
        if (hModule != NULL)
        {
            FreeLibrary(hModule);
            printLine("Library loaded and freed successfully");
        }
        else
        {
            printLine("Unable to load library");
        }
    }
}

void CWE114_Process_Control__w32_char_connect_socket_22_case1()
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
    CWE114_Process_Control__w32_char_connect_socket_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE114_Process_Control__w32_char_connect_socket_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
