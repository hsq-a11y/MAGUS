/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_83_case0.cpp
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * Case0Source: console Read input from the console
 * Case1Source: Use a hardcoded path
 * Sinks:
 *    Case0Sink : Set the environment variable
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_83.h"

namespace CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_83
{
CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_83_case0::CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_83_case0(wchar_t * dataCopy)
{
    data = dataCopy;
    {
        /* Read input from the console */
        size_t dataLen = wcslen(data);
        /* if there is room in data, read into it from the console */
        if (250-dataLen > 1)
        {
            /* NOTE: Read data from the console */
            if (fgetws(data+dataLen, (int)(250-dataLen), stdin) != NULL)
            {
                /* The next few lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                dataLen = wcslen(data);
                if (dataLen > 0 && data[dataLen-1] == L'\n')
                {
                    data[dataLen-1] = L'\0';
                }
            }
            else
            {
                printLine("fgetws() failed");
                /* Restore NUL terminator if fgetws fails */
                data[dataLen] = L'\0';
            }
        }
    }
}

CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_83_case0::~CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_83_case0()
{
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}
}
#endif /* OMITCASE0 */
