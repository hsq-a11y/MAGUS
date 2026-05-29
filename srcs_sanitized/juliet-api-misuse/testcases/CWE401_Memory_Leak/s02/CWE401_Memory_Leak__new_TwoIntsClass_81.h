/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_TwoIntsClass_81.h
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call delete on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_TwoIntsClass_81
{

class CWE401_Memory_Leak__new_TwoIntsClass_81_base
{
public:
    /* pure virtual function */
    virtual void action(TwoIntsClass * data) const = 0;
};

#ifndef OMITCASE0

class CWE401_Memory_Leak__new_TwoIntsClass_81_case0 : public CWE401_Memory_Leak__new_TwoIntsClass_81_base
{
public:
    void action(TwoIntsClass * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE401_Memory_Leak__new_TwoIntsClass_81_case1V1 : public CWE401_Memory_Leak__new_TwoIntsClass_81_base
{
public:
    void action(TwoIntsClass * data) const;
};

class CWE401_Memory_Leak__new_TwoIntsClass_81_case1V2 : public CWE401_Memory_Leak__new_TwoIntsClass_81_base
{
public:
    void action(TwoIntsClass * data) const;
};

#endif /* OMITCASE1 */

}
