/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_fclose_34.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using open()
 * Sinks: fclose
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Close the file using fclose()
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define OPEN _open
#define CLOSE _close
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#endif

typedef union
{
    int unionFirst;
    int unionSecond;
} CWE404_Improper_Resource_Shutdown__open_fclose_34_unionType;

#ifndef OMITCASE0

void CWE404_Improper_Resource_Shutdown__open_fclose_34_case0()
{
    int data;
    CWE404_Improper_Resource_Shutdown__open_fclose_34_unionType myUnion;
    /* Initialize data */
    data = -1;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    myUnion.unionFirst = data;
    {
        int data = myUnion.unionSecond;
        if (data != -1)
        {
            /* NOTE: Attempt to close the file using fclose() instead of close() */
            fclose((FILE *)data);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() uses the Case0Source with the Case1Sink */
static void case1V2()
{
    int data;
    CWE404_Improper_Resource_Shutdown__open_fclose_34_unionType myUnion;
    /* Initialize data */
    data = -1;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    myUnion.unionFirst = data;
    {
        int data = myUnion.unionSecond;
        if (data != -1)
        {
            /* ALT: Close the file using close() */
            CLOSE(data);
        }
    }
}

void CWE404_Improper_Resource_Shutdown__open_fclose_34_case1()
{
    case1V2();
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
    CWE404_Improper_Resource_Shutdown__open_fclose_34_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE404_Improper_Resource_Shutdown__open_fclose_34_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
