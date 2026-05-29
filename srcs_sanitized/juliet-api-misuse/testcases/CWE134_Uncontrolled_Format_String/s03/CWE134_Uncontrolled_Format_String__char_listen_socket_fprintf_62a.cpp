/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_listen_socket_fprintf_62a.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-62a.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Copy a fixed string into data
 * Sinks: fprintf
 *    Case1Sink: fprintf with "%s" as the second argument and data as the third
 *    Case0Sink : fprintf with data as the second argument
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE134_Uncontrolled_Format_String__char_listen_socket_fprintf_62
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Source(char * &data);

void case0()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    case0Source(data);
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    fprintf(stdout, data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Source(char * &data);

static void case1V1()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    case1V1Source(data);
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    fprintf(stdout, data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Source(char * &data);

static void case1V2()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    case1V2Source(data);
    /* ALT: Specify the format disallowing a format string vulnerability */
    fprintf(stdout, "%s\n", data);
}

void case1()
{
    case1V1();
    case1V2();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE134_Uncontrolled_Format_String__char_listen_socket_fprintf_62; /* so that we can use case1 and case0 easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
