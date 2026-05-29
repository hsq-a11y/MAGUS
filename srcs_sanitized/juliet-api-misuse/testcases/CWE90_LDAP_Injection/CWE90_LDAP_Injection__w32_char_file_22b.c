/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_char_file_22b.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * Case0Source: file Read input from a file
 * Case1Source: Use a fixed string
 * Sink:
 *    Case0Sink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
extern int CWE90_LDAP_Injection__w32_char_file_22_case0Global;

char * CWE90_LDAP_Injection__w32_char_file_22_case0Source(char * data)
{
    if(CWE90_LDAP_Injection__w32_char_file_22_case0Global)
    {
        {
            /* Read input from a file */
            size_t dataLen = strlen(data);
            FILE * pFile;
            /* if there is room in data, attempt to read the input from a file */
            if (256-dataLen > 1)
            {
                pFile = fopen(FILENAME, "r");
                if (pFile != NULL)
                {
                    /* NOTE: Read data from a file */
                    if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL)
                    {
                        printLine("fgets() failed");
                        /* Restore NUL terminator if fgets fails */
                        data[dataLen] = '\0';
                    }
                    fclose(pFile);
                }
            }
        }
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE90_LDAP_Injection__w32_char_file_22_case1V11Global;
extern int CWE90_LDAP_Injection__w32_char_file_22_case1V12Global;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
char * CWE90_LDAP_Injection__w32_char_file_22_case1V11Source(char * data)
{
    if(CWE90_LDAP_Injection__w32_char_file_22_case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Use a fixed file name */
        strcat(data, "Doe, XXXXX");
    }
    return data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
char * CWE90_LDAP_Injection__w32_char_file_22_case1V12Source(char * data)
{
    if(CWE90_LDAP_Injection__w32_char_file_22_case1V12Global)
    {
        /* ALT: Use a fixed file name */
        strcat(data, "Doe, XXXXX");
    }
    return data;
}

#endif /* OMITCASE1 */
