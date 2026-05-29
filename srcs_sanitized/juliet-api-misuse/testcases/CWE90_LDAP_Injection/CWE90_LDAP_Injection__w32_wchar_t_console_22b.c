/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_wchar_t_console_22b.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * Case0Source: console Read input from the console
 * Case1Source: Use a fixed string
 * Sink:
 *    Case0Sink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
extern int CWE90_LDAP_Injection__w32_wchar_t_console_22_case0Global;

wchar_t * CWE90_LDAP_Injection__w32_wchar_t_console_22_case0Source(wchar_t * data)
{
    if(CWE90_LDAP_Injection__w32_wchar_t_console_22_case0Global)
    {
        {
            /* Read input from the console */
            size_t dataLen = wcslen(data);
            /* if there is room in data, read into it from the console */
            if (256-dataLen > 1)
            {
                /* NOTE: Read data from the console */
                if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL)
                {
                    /* The next few lines remove the carriage return from the string that is
                     * inserted by fgetws() */
                    dataLen = wcslen(data);
                    if (dataLen > 0 && data[dataLen-1] == L'\n')
                    {
                        data[dataLen-1] = L'\0';
                    }
                }
                else
                {
                    printLine("fgetws() failed");
                    /* Restore NUL terminator if fgetws fails */
                    data[dataLen] = L'\0';
                }
            }
        }
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE90_LDAP_Injection__w32_wchar_t_console_22_case1V11Global;
extern int CWE90_LDAP_Injection__w32_wchar_t_console_22_case1V12Global;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
wchar_t * CWE90_LDAP_Injection__w32_wchar_t_console_22_case1V11Source(wchar_t * data)
{
    if(CWE90_LDAP_Injection__w32_wchar_t_console_22_case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Use a fixed file name */
        wcscat(data, L"Doe, XXXXX");
    }
    return data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
wchar_t * CWE90_LDAP_Injection__w32_wchar_t_console_22_case1V12Source(wchar_t * data)
{
    if(CWE90_LDAP_Injection__w32_wchar_t_console_22_case1V12Global)
    {
        /* ALT: Use a fixed file name */
        wcscat(data, L"Doe, XXXXX");
    }
    return data;
}

#endif /* OMITCASE1 */
