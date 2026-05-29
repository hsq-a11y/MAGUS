/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_environment_fprintf_68b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Copy a fixed string into data
 * Sinks: fprintf
 *    Case1Sink: fprintf with "%s" as the second argument and data as the third
 *    Case0Sink : fprintf with data as the second argument
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

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

extern char * CWE134_Uncontrolled_Format_String__char_environment_fprintf_68_case0Data;
extern char * CWE134_Uncontrolled_Format_String__char_environment_fprintf_68_case1V1Data;
extern char * CWE134_Uncontrolled_Format_String__char_environment_fprintf_68_case1V2Data;

#ifndef OMITCASE0

void CWE134_Uncontrolled_Format_String__char_environment_fprintf_68b_case0Sink()
{
    char * data = CWE134_Uncontrolled_Format_String__char_environment_fprintf_68_case0Data;
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    fprintf(stdout, data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE134_Uncontrolled_Format_String__char_environment_fprintf_68b_case1V1Sink()
{
    char * data = CWE134_Uncontrolled_Format_String__char_environment_fprintf_68_case1V1Data;
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    fprintf(stdout, data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE134_Uncontrolled_Format_String__char_environment_fprintf_68b_case1V2Sink()
{
    char * data = CWE134_Uncontrolled_Format_String__char_environment_fprintf_68_case1V2Data;
    /* ALT: Specify the format disallowing a format string vulnerability */
    fprintf(stdout, "%s\n", data);
}

#endif /* OMITCASE1 */
