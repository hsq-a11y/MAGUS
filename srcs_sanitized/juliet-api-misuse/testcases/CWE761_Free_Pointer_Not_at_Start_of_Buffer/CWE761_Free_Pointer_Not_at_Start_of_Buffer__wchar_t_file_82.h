/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_file_82.h
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * Case0Source: file Read input from a file
 * Sinks:
 *    Case1Sink: free() memory correctly at the start of the buffer
 *    Case0Sink : free() memory not at the start of the buffer
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_file_82
{

class CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_file_82_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) = 0;
};

#ifndef OMITCASE0

class CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_file_82_case0 : public CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_file_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_file_82_case1V2 : public CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_file_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE1 */

}
