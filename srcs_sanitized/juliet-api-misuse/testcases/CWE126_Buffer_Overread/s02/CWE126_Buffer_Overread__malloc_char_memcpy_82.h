/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__malloc_char_memcpy_82.h
Label Definition File: CWE126_Buffer_Overread__malloc.label.xml
Template File: sources-sink-82.tmpl.h
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * Case0Source:  Use a small buffer
 * Case1Source: Use a large buffer
 *    Case0Sink : Copy data to string using memcpy
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE126_Buffer_Overread__malloc_char_memcpy_82
{

class CWE126_Buffer_Overread__malloc_char_memcpy_82_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) = 0;
};

#ifndef OMITCASE0

class CWE126_Buffer_Overread__malloc_char_memcpy_82_case0 : public CWE126_Buffer_Overread__malloc_char_memcpy_82_base
{
public:
    void action(char * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE126_Buffer_Overread__malloc_char_memcpy_82_case1V1 : public CWE126_Buffer_Overread__malloc_char_memcpy_82_base
{
public:
    void action(char * data);
};

#endif /* OMITCASE1 */

}
