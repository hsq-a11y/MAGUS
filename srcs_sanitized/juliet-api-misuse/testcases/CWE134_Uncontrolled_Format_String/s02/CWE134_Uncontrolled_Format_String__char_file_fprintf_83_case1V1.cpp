/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_file_fprintf_83_case1V1.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: file Read input from a file
 * Case1Source: Copy a fixed string into data
 * Sinks: fprintf
 *    Case1Sink: fprintf with "%s" as the second argument and data as the third
 *    Case0Sink : fprintf with data as the second argument
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE134_Uncontrolled_Format_String__char_file_fprintf_83.h"

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

namespace CWE134_Uncontrolled_Format_String__char_file_fprintf_83
{
CWE134_Uncontrolled_Format_String__char_file_fprintf_83_case1V1::CWE134_Uncontrolled_Format_String__char_file_fprintf_83_case1V1(char * dataCopy)
{
    data = dataCopy;
    /* ALT: Use a fixed string that does not contain a format specifier */
    strcpy(data, "fixedstringtest");
}

CWE134_Uncontrolled_Format_String__char_file_fprintf_83_case1V1::~CWE134_Uncontrolled_Format_String__char_file_fprintf_83_case1V1()
{
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    fprintf(stdout, data);
}
}
#endif /* OMITCASE1 */
