/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_environment_vfprintf_54b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Copy a fixed string into data
 * Sinks: vfprintf
 *    Case1Sink: vfprintf with a format string
 *    Case0Sink : vfprintf without a format string
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

#ifndef OMITCASE0

/* case0 function declaration */
void CWE134_Uncontrolled_Format_String__char_environment_vfprintf_54c_case0Sink(char * data);

void CWE134_Uncontrolled_Format_String__char_environment_vfprintf_54b_case0Sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_environment_vfprintf_54c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE134_Uncontrolled_Format_String__char_environment_vfprintf_54c_case1V1Sink(char * data);

void CWE134_Uncontrolled_Format_String__char_environment_vfprintf_54b_case1V1Sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_environment_vfprintf_54c_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE134_Uncontrolled_Format_String__char_environment_vfprintf_54c_case1V2Sink(char * data);

void CWE134_Uncontrolled_Format_String__char_environment_vfprintf_54b_case1V2Sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_environment_vfprintf_54c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
