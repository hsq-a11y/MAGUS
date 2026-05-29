/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__int64_t_realloc_83.h
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: realloc Allocate data using realloc()
 * Sinks:
 *    Case1Sink: Check to see if the data allocation failed and if not, use data
 *    Case0Sink : Don't check for NULL and use data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE690_NULL_Deref_From_Return__int64_t_realloc_83
{

#ifndef OMITCASE0

class CWE690_NULL_Deref_From_Return__int64_t_realloc_83_case0
{
public:
    CWE690_NULL_Deref_From_Return__int64_t_realloc_83_case0(int64_t * dataCopy);
    ~CWE690_NULL_Deref_From_Return__int64_t_realloc_83_case0();

private:
    int64_t * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE690_NULL_Deref_From_Return__int64_t_realloc_83_case1V2
{
public:
    CWE690_NULL_Deref_From_Return__int64_t_realloc_83_case1V2(int64_t * dataCopy);
    ~CWE690_NULL_Deref_From_Return__int64_t_realloc_83_case1V2();

private:
    int64_t * data;
};

#endif /* OMITCASE1 */

}
