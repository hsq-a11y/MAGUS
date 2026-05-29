/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__malloc_char_loop_81.h
Label Definition File: CWE126_Buffer_Overread__malloc.label.xml
Template File: sources-sink-81.tmpl.h
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * Case0Source:  Use a small buffer
 * Case1Source: Use a large buffer
 * Sinks: loop
 *    Case0Sink : Copy data to string using a loop
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE126_Buffer_Overread__malloc_char_loop_81
{

class CWE126_Buffer_Overread__malloc_char_loop_81_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) const = 0;
};

#ifndef OMITCASE0

class CWE126_Buffer_Overread__malloc_char_loop_81_case0 : public CWE126_Buffer_Overread__malloc_char_loop_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE126_Buffer_Overread__malloc_char_loop_81_case1V1 : public CWE126_Buffer_Overread__malloc_char_loop_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE1 */

}
