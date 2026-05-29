/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_file_execlp_83_case0.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: file Read input from a file
 * Case1Source: Fixed string
 * Sinks: execlp
 *    Case0Sink : execute command with wexeclp
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__wchar_t_file_execlp_83.h"

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#ifdef _WIN32
#include <process.h>
#define EXECLP _wexeclp
#else /* NOT _WIN32 */
#define EXECLP execlp
#endif

namespace CWE78_OS_Command_Injection__wchar_t_file_execlp_83
{
CWE78_OS_Command_Injection__wchar_t_file_execlp_83_case0::CWE78_OS_Command_Injection__wchar_t_file_execlp_83_case0(wchar_t * dataCopy)
{
    data = dataCopy;
    {
        /* Read input from a file */
        size_t dataLen = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (100-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* NOTE: Read data from a file */
                if (fgetws(data+dataLen, (int)(100-dataLen), pFile) == NULL)
                {
                    printLine("fgetws() failed");
                    /* Restore NUL terminator if fgetws fails */
                    data[dataLen] = L'\0';
                }
                fclose(pFile);
            }
        }
    }
}

CWE78_OS_Command_Injection__wchar_t_file_execlp_83_case0::~CWE78_OS_Command_Injection__wchar_t_file_execlp_83_case0()
{
    /* wexeclp - searches for the location of the command among
     * the directories specified by the PATH environment variable */
    /* NOTE: Execute command without validating input possibly leading to command injection */
    EXECLP(COMMAND_INT, COMMAND_INT, COMMAND_ARG1, COMMAND_ARG3, NULL);
}
}
#endif /* OMITCASE0 */
