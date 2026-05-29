/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__char_popen_84_case0.cpp
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-84_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * Case0Source:  Don't specify the full path in the OS command
 * Case1Source: Specify the full path in the OS command
 * Sinks: popen
 *    Case0Sink : Execute the popen function
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE426_Untrusted_Search_Path__char_popen_84.h"

#ifdef _WIN32
#define POPEN _popen
#define PCLOSE _pclose
#else /* NOT _WIN32 */
#define POPEN popen
#define PCLOSE pclose
#endif

namespace CWE426_Untrusted_Search_Path__char_popen_84
{
CWE426_Untrusted_Search_Path__char_popen_84_case0::CWE426_Untrusted_Search_Path__char_popen_84_case0(char * dataCopy)
{
    data = dataCopy;
    /* NOTE: the full path is not specified */
    strcpy(data, CASE0_OS_COMMAND);
}

CWE426_Untrusted_Search_Path__char_popen_84_case0::~CWE426_Untrusted_Search_Path__char_popen_84_case0()
{
    {
        FILE *pipe;
        /* NOTE: Executing the popen() function without specifying the full path to the executable
         * can allow an attacker to run their own program */
        pipe = POPEN(data, "wb");
        if (pipe != NULL)
        {
            PCLOSE(pipe);
        }
    }
}
}
#endif /* OMITCASE0 */
