/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_file_vprintf_62b.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: file Read input from a file
 * Case1Source: Copy a fixed string into data
 * Sinks: vprintf
 *    Case1Sink: vwprintf with a format string
 *    Case0Sink : vwprintf without a format string
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

namespace CWE134_Uncontrolled_Format_String__wchar_t_file_vprintf_62
{

#ifndef OMITCASE0

void case0Source(wchar_t * &data)
{
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

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
void case1V1Source(wchar_t * &data)
{
    /* ALT: Use a fixed string that does not contain a format specifier */
    wcscpy(data, L"fixedstringtest");
}

/* case1V2() uses the Case0Source with the Case1Sink */
void case1V2Source(wchar_t * &data)
{
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

#endif /* OMITCASE1 */

} /* close namespace */
