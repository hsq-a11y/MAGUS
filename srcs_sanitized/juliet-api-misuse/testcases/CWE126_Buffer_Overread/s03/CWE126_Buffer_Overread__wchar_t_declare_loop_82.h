/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__wchar_t_declare_loop_82.h
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-82.tmpl.h
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * Case0Source:  Set data pointer to a small buffer
 * Case1Source: Set data pointer to a large buffer
 *    Case0Sink : Copy data to string using a loop
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE126_Buffer_Overread__wchar_t_declare_loop_82
{

class CWE126_Buffer_Overread__wchar_t_declare_loop_82_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) = 0;
};

#ifndef OMITCASE0

class CWE126_Buffer_Overread__wchar_t_declare_loop_82_case0 : public CWE126_Buffer_Overread__wchar_t_declare_loop_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE126_Buffer_Overread__wchar_t_declare_loop_82_case1V1 : public CWE126_Buffer_Overread__wchar_t_declare_loop_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE1 */

}
