/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__malloc_realloc_int64_t_01.c
Label Definition File: CWE401_Memory_Leak__malloc_realloc.label.xml
Template File: point-note-01.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Sinks:
 *    Case1Sink: Ensure the memory block pointed to by data is always freed
 *    Case0Sink : malloc() and use then realloc() and use data before free()
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITCASE0

void CWE401_Memory_Leak__malloc_realloc_int64_t_01_case0()
{
    {
        int64_t * data = (int64_t *)malloc(100*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
        /* Initialize and make use of data */
        data[0] = 5LL;
        printLongLongLine(data[0]);
        /* NOTE: If realloc() fails, the initial memory block will not be freed() */
        data = (int64_t *)realloc(data, (130000)*sizeof(int64_t));
        if (data != NULL)
        {
            /* Reinitialize and make use of data */
            data[0] = 10LL;
            printLongLongLine(data[0]);
            free(data);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

static void case11()
{
    {
        int64_t * data = (int64_t *)malloc(100*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
        int64_t * tmpData;
        /* Initialize and make use of data */
        data[0] = 5LL;
        printLongLongLine(data[0]);
        tmpData = (int64_t *)realloc(data, (130000)*sizeof(int64_t));
        /* ALT: Ensure realloc() was successful before assigning data to the memory block
        * allocated with realloc() */
        if (tmpData != NULL)
        {
            data = tmpData;
            /* Reinitialize and make use of data */
            data[0] = 10LL;
            printLongLongLine(data[0]);
        }
        free(data);
    }
}

void CWE401_Memory_Leak__malloc_realloc_int64_t_01_case1()
{
    case11();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE401_Memory_Leak__malloc_realloc_int64_t_01_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE401_Memory_Leak__malloc_realloc_int64_t_01_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
