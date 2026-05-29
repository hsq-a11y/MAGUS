/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_wchar_t_81.h
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using malloc() and Deallocate data using free()
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__malloc_free_wchar_t_81
{

class CWE415_Double_Free__malloc_free_wchar_t_81_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) const = 0;
};

#ifndef OMITCASE0

class CWE415_Double_Free__malloc_free_wchar_t_81_case0 : public CWE415_Double_Free__malloc_free_wchar_t_81_base
{
public:
    void action(wchar_t * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE415_Double_Free__malloc_free_wchar_t_81_case1V1 : public CWE415_Double_Free__malloc_free_wchar_t_81_base
{
public:
    void action(wchar_t * data) const;
};

class CWE415_Double_Free__malloc_free_wchar_t_81_case1V2 : public CWE415_Double_Free__malloc_free_wchar_t_81_base
{
public:
    void action(wchar_t * data) const;
};

#endif /* OMITCASE1 */

}
