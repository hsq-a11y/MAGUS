/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_connect_socket_84a.cpp
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-84a.tmpl.cpp
*/
/*
 * @description
 * CWE: 114 Process Control
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Hard code the full pathname to the library
 * Sinks:
 *    Case0Sink : Load a dynamic link library
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE114_Process_Control__w32_char_connect_socket_84.h"

namespace CWE114_Process_Control__w32_char_connect_socket_84
{

#ifndef OMITCASE0

void case0()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    CWE114_Process_Control__w32_char_connect_socket_84_case0 * case0Object = new CWE114_Process_Control__w32_char_connect_socket_84_case0(data);
    delete case0Object;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    CWE114_Process_Control__w32_char_connect_socket_84_case1V1 * case1V1Object =  new CWE114_Process_Control__w32_char_connect_socket_84_case1V1(data);
    delete case1V1Object;
}

void case1()
{
    case1V1();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE114_Process_Control__w32_char_connect_socket_84; /* so that we can use case1 and case0 easily */

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
