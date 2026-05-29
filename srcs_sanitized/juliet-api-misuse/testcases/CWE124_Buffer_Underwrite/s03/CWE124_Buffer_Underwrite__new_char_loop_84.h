/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__new_char_loop_84.h
Label Definition File: CWE124_Buffer_Underwrite__new.label.xml
Template File: sources-sink-84.tmpl.h
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sinks: loop
 *    Case0Sink : Copy string to data using a loop
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE124_Buffer_Underwrite__new_char_loop_84
{

#ifndef OMITCASE0

class CWE124_Buffer_Underwrite__new_char_loop_84_case0
{
public:
    CWE124_Buffer_Underwrite__new_char_loop_84_case0(char * dataCopy);
    ~CWE124_Buffer_Underwrite__new_char_loop_84_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE124_Buffer_Underwrite__new_char_loop_84_case1V1
{
public:
    CWE124_Buffer_Underwrite__new_char_loop_84_case1V1(char * dataCopy);
    ~CWE124_Buffer_Underwrite__new_char_loop_84_case1V1();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
