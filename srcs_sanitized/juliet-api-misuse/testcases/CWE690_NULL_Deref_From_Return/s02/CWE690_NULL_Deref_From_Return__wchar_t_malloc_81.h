/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__wchar_t_malloc_81.h
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: malloc Allocate data using malloc()
 * Sinks:
 *    Case1Sink: Check to see if the data allocation failed and if not, use data
 *    Case0Sink : Don't check for NULL and use data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE690_NULL_Deref_From_Return__wchar_t_malloc_81
{

class CWE690_NULL_Deref_From_Return__wchar_t_malloc_81_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) const = 0;
};

#ifndef OMITCASE0

class CWE690_NULL_Deref_From_Return__wchar_t_malloc_81_case0 : public CWE690_NULL_Deref_From_Return__wchar_t_malloc_81_base
{
public:
    void action(wchar_t * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE690_NULL_Deref_From_Return__wchar_t_malloc_81_case1V2 : public CWE690_NULL_Deref_From_Return__wchar_t_malloc_81_base
{
public:
    void action(wchar_t * data) const;
};

#endif /* OMITCASE1 */

}
