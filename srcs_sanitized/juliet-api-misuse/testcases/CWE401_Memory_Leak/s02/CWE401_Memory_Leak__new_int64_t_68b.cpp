/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_int64_t_68b.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call delete on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_int64_t_68
{

extern int64_t * case0Data;
extern int64_t * case1V1Data;
extern int64_t * case1V2Data;

#ifndef OMITCASE0

void case0Sink()
{
    int64_t * data = case0Data;
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink()
{
    int64_t * data = case1V1Data;
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink()
{
    int64_t * data = case1V2Data;
    /* ALT: Deallocate memory */
    delete data;
}

#endif /* OMITCASE1 */

} /* close namespace */
