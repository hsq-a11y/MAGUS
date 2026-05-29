/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_environment_snprintf_74b.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Copy a fixed string into data
 * Sinks: swprintf
 *    Case1Sink: snwprintf with "%s" as the third argument and data as the fourth
 *    Case0Sink : snwprintf with data as the third argument
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define SNPRINTF _snwprintf
#else
#define SNPRINTF swprintf
#endif

using namespace std;

namespace CWE134_Uncontrolled_Format_String__wchar_t_environment_snprintf_74
{

#ifndef OMITCASE0

void case0Sink(map<int, wchar_t *> dataMap)
{
    /* copy data out of dataMap */
    wchar_t * data = dataMap[2];
    {
        wchar_t dest[100] = L"";
        /* NOTE: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printWLine(dest);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(map<int, wchar_t *> dataMap)
{
    wchar_t * data = dataMap[2];
    {
        wchar_t dest[100] = L"";
        /* NOTE: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printWLine(dest);
    }
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(map<int, wchar_t *> dataMap)
{
    wchar_t * data = dataMap[2];
    {
        wchar_t dest[100] = L"";
        /* ALT: Specify the format disallowing a format string vulnerability */
        SNPRINTF(dest, 100-1, L"%s", data);
        printWLine(dest);
    }
}

#endif /* OMITCASE1 */

} /* close namespace */
