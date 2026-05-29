/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_wchar_t_82.h
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using wcsdup()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE401_Memory_Leak__strdup_wchar_t_82
{

class CWE401_Memory_Leak__strdup_wchar_t_82_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) = 0;
};

#ifndef OMITCASE0

class CWE401_Memory_Leak__strdup_wchar_t_82_case0 : public CWE401_Memory_Leak__strdup_wchar_t_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE401_Memory_Leak__strdup_wchar_t_82_case1V1 : public CWE401_Memory_Leak__strdup_wchar_t_82_base
{
public:
    void action(wchar_t * data);
};

class CWE401_Memory_Leak__strdup_wchar_t_82_case1V2 : public CWE401_Memory_Leak__strdup_wchar_t_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE1 */

}
