/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__struct_calloc_82.h
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: calloc Allocate data using calloc()
 * Sinks:
 *    Case1Sink: Check to see if the data allocation failed and if not, use data
 *    Case0Sink : Don't check for NULL and use data
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE690_NULL_Deref_From_Return__struct_calloc_82
{

class CWE690_NULL_Deref_From_Return__struct_calloc_82_base
{
public:
    /* pure virtual function */
    virtual void action(twoIntsStruct * data) = 0;
};

#ifndef OMITCASE0

class CWE690_NULL_Deref_From_Return__struct_calloc_82_case0 : public CWE690_NULL_Deref_From_Return__struct_calloc_82_base
{
public:
    void action(twoIntsStruct * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE690_NULL_Deref_From_Return__struct_calloc_82_case1V2 : public CWE690_NULL_Deref_From_Return__struct_calloc_82_base
{
public:
    void action(twoIntsStruct * data);
};

#endif /* OMITCASE1 */

}
