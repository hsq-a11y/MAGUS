/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_long_82.h
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using new and Deallocae data using delete
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_array_long_82
{

class CWE415_Double_Free__new_delete_array_long_82_base
{
public:
    /* pure virtual function */
    virtual void action(long * data) = 0;
};

#ifndef OMITCASE0

class CWE415_Double_Free__new_delete_array_long_82_case0 : public CWE415_Double_Free__new_delete_array_long_82_base
{
public:
    void action(long * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE415_Double_Free__new_delete_array_long_82_case1V1 : public CWE415_Double_Free__new_delete_array_long_82_base
{
public:
    void action(long * data);
};

class CWE415_Double_Free__new_delete_array_long_82_case1V2 : public CWE415_Double_Free__new_delete_array_long_82_base
{
public:
    void action(long * data);
};

#endif /* OMITCASE1 */

}
