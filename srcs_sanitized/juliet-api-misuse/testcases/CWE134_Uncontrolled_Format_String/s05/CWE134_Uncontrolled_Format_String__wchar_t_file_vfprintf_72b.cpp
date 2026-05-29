/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_file_vfprintf_72b.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: file Read input from a file
 * Case1Source: Copy a fixed string into data
 * Sinks: vfprintf
 *    Case1Sink: vfwprintf with a format string
 *    Case0Sink : vfwprintf without a format string
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */
#include <stdarg.h>
#include <vector>
#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

using namespace std;

namespace CWE134_Uncontrolled_Format_String__wchar_t_file_vfprintf_72
{

#ifndef OMITCASE0

static void case0VaSink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* NOTE: Do not specify the format allowing a possible format string vulnerability */
        vfwprintf(stdout, data, args);
        va_end(args);
    }
}

void case0Sink(vector<wchar_t *> dataVector)
{
    /* copy data out of dataVector */
    wchar_t * data = dataVector[2];
    case0VaSink(data, data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1VaSink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* NOTE: Do not specify the format allowing a possible format string vulnerability */
        vfwprintf(stdout, data, args);
        va_end(args);
    }
}

void case1V1Sink(vector<wchar_t *> dataVector)
{
    wchar_t * data = dataVector[2];
    case1V1VaSink(data, data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
static void case1V2VaSink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* ALT: Specify the format disallowing a format string vulnerability */
        vfwprintf(stdout, L"%s", args);
        va_end(args);
    }
}

void case1V2Sink(vector<wchar_t *> dataVector)
{
    wchar_t * data = dataVector[2];
    case1V2VaSink(data, data);
}

#endif /* OMITCASE1 */

} /* close namespace */
