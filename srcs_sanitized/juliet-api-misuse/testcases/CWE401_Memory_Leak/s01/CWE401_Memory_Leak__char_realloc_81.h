/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__char_realloc_81.h
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: realloc Allocate data using realloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE401_Memory_Leak__char_realloc_81
{

class CWE401_Memory_Leak__char_realloc_81_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) const = 0;
};

#ifndef OMITCASE0

class CWE401_Memory_Leak__char_realloc_81_case0 : public CWE401_Memory_Leak__char_realloc_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE401_Memory_Leak__char_realloc_81_case1V1 : public CWE401_Memory_Leak__char_realloc_81_base
{
public:
    void action(char * data) const;
};

class CWE401_Memory_Leak__char_realloc_81_case1V2 : public CWE401_Memory_Leak__char_realloc_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE1 */

}
