/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_class_81.h
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using new and Deallocae data using delete
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_class_81
{

class CWE415_Double_Free__new_delete_class_81_base
{
public:
    /* pure virtual function */
    virtual void action(TwoIntsClass * data) const = 0;
};

#ifndef OMITCASE0

class CWE415_Double_Free__new_delete_class_81_case0 : public CWE415_Double_Free__new_delete_class_81_base
{
public:
    void action(TwoIntsClass * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE415_Double_Free__new_delete_class_81_case1V1 : public CWE415_Double_Free__new_delete_class_81_base
{
public:
    void action(TwoIntsClass * data) const;
};

class CWE415_Double_Free__new_delete_class_81_case1V2 : public CWE415_Double_Free__new_delete_class_81_base
{
public:
    void action(TwoIntsClass * data) const;
};

#endif /* OMITCASE1 */

}
