/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_83.h
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * Case0Source: fixed_string Initialize data to be a fixed string
 * Sinks:
 *    Case1Sink: free() memory correctly at the start of the buffer
 *    Case0Sink : free() memory not at the start of the buffer
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_83
{

#ifndef OMITCASE0

class CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_83_case0
{
public:
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_83_case0(char * dataCopy);
    ~CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_83_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_83_case1V2
{
public:
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_83_case1V2(char * dataCopy);
    ~CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_83_case1V2();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
