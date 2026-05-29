/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_84.h
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-84.tmpl.h
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * Case0Source: environment Read input from an environment variable
 * Sinks:
 *    Case1Sink: free() memory correctly at the start of the buffer
 *    Case0Sink : free() memory not at the start of the buffer
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_84
{

#ifndef OMITCASE0

class CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_84_case0
{
public:
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_84_case0(wchar_t * dataCopy);
    ~CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_84_case0();

private:
    wchar_t * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_84_case1V2
{
public:
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_84_case1V2(wchar_t * dataCopy);
    ~CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_84_case1V2();

private:
    wchar_t * data;
};

#endif /* OMITCASE1 */

}
