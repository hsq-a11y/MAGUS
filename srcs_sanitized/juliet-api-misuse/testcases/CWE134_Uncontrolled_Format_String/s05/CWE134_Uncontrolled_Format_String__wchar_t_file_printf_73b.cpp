/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_file_printf_73b.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: file Read input from a file
 * Case1Source: Copy a fixed string into data
 * Sinks: printf
 *    Case1Sink: wprintf with "%s" as the first argument and data as the second
 *    Case0Sink : wprintf with only data as an argument
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#ifndef _WIN32
#include <wchar.h>
#endif

using namespace std;

namespace CWE134_Uncontrolled_Format_String__wchar_t_file_printf_73
{

#ifndef OMITCASE0

void case0Sink(list<wchar_t *> dataList)
{
    /* copy data out of dataList */
    wchar_t * data = dataList.back();
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    wprintf(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(list<wchar_t *> dataList)
{
    wchar_t * data = dataList.back();
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    wprintf(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(list<wchar_t *> dataList)
{
    wchar_t * data = dataList.back();
    /* ALT: Specify the format disallowing a format string vulnerability */
    wprintf(L"%s\n", data);
}

#endif /* OMITCASE1 */

} /* close namespace */
