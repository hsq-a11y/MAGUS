/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_long_84.h
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-84.tmpl.h
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using malloc() and Deallocate data using free()
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__malloc_free_long_84
{

#ifndef OMITCASE0

class CWE415_Double_Free__malloc_free_long_84_case0
{
public:
    CWE415_Double_Free__malloc_free_long_84_case0(long * dataCopy);
    ~CWE415_Double_Free__malloc_free_long_84_case0();

private:
    long * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE415_Double_Free__malloc_free_long_84_case1V1
{
public:
    CWE415_Double_Free__malloc_free_long_84_case1V1(long * dataCopy);
    ~CWE415_Double_Free__malloc_free_long_84_case1V1();

private:
    long * data;
};

class CWE415_Double_Free__malloc_free_long_84_case1V2
{
public:
    CWE415_Double_Free__malloc_free_long_84_case1V2(long * dataCopy);
    ~CWE415_Double_Free__malloc_free_long_84_case1V2();

private:
    long * data;
};

#endif /* OMITCASE1 */

}
