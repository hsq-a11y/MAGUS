/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__new_wchar_t_memcpy_81.h
Label Definition File: CWE124_Buffer_Underwrite__new.label.xml
Template File: sources-sink-81.tmpl.h
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sinks: memcpy
 *    Case0Sink : Copy string to data using memcpy
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE124_Buffer_Underwrite__new_wchar_t_memcpy_81
{

class CWE124_Buffer_Underwrite__new_wchar_t_memcpy_81_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) const = 0;
};

#ifndef OMITCASE0

class CWE124_Buffer_Underwrite__new_wchar_t_memcpy_81_case0 : public CWE124_Buffer_Underwrite__new_wchar_t_memcpy_81_base
{
public:
    void action(wchar_t * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE124_Buffer_Underwrite__new_wchar_t_memcpy_81_case1V1 : public CWE124_Buffer_Underwrite__new_wchar_t_memcpy_81_base
{
public:
    void action(wchar_t * data) const;
};

#endif /* OMITCASE1 */

}
