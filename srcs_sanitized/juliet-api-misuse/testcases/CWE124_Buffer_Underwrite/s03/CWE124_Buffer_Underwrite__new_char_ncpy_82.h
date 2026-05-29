/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__new_char_ncpy_82.h
Label Definition File: CWE124_Buffer_Underwrite__new.label.xml
Template File: sources-sink-82.tmpl.h
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sinks: ncpy
 *    Case0Sink : Copy string to data using strncpy
 * Flow Variant: 82 Data flow: data passed in a parameter to a virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE124_Buffer_Underwrite__new_char_ncpy_82
{

class CWE124_Buffer_Underwrite__new_char_ncpy_82_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) = 0;
};

#ifndef OMITCASE0

class CWE124_Buffer_Underwrite__new_char_ncpy_82_case0 : public CWE124_Buffer_Underwrite__new_char_ncpy_82_base
{
public:
    void action(char * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE124_Buffer_Underwrite__new_char_ncpy_82_case1V1 : public CWE124_Buffer_Underwrite__new_char_ncpy_82_base
{
public:
    void action(char * data);
};

#endif /* OMITCASE1 */

}
