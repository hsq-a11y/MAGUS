/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__char_alloca_ncpy_82.h
Label Definition File: CWE127_Buffer_Underread.stack.label.xml
Template File: sources-sink-82.tmpl.h
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 *    Case0Sink : Copy data to string using strncpy
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE127_Buffer_Underread__char_alloca_ncpy_82
{

class CWE127_Buffer_Underread__char_alloca_ncpy_82_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) = 0;
};

#ifndef OMITCASE0

class CWE127_Buffer_Underread__char_alloca_ncpy_82_case0 : public CWE127_Buffer_Underread__char_alloca_ncpy_82_base
{
public:
    void action(char * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE127_Buffer_Underread__char_alloca_ncpy_82_case1V1 : public CWE127_Buffer_Underread__char_alloca_ncpy_82_base
{
public:
    void action(char * data);
};

#endif /* OMITCASE1 */

}
