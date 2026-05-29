/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__CWE839_rand_31.c
Label Definition File: CWE127_Buffer_Underread__CWE839.label.xml
Template File: sources-sinks-31.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Underread
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking to see if the value is negative
 * Flow Variant: 31 Data flow using a copy of data within the same function
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

void CWE127_Buffer_Underread__CWE839_rand_31_case0()
{
    int data;
    /* Initialize data */
    data = -1;
    /* NOTE: Set data to a random value */
    data = RAND32();
    {
        int dataCopy = data;
        int data = dataCopy;
        {
            int buffer[10] = { 0 };
            /* NOTE: Attempt to access a negative index of the array
             * This check does not check to see if the array index is negative */
            if (data < 10)
            {
                printIntLine(buffer[data]);
            }
            else
            {
                printLine("ERROR: Array index is too big.");
            }
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1()
{
    int data;
    /* Initialize data */
    data = -1;
    /* ALT: Use a value greater than 0, but less than 10 to avoid attempting to
     * access an index of the array in the sink that is out-of-bounds */
    data = 7;
    {
        int dataCopy = data;
        int data = dataCopy;
        {
            int buffer[10] = { 0 };
            /* NOTE: Attempt to access a negative index of the array
             * This check does not check to see if the array index is negative */
            if (data < 10)
            {
                printIntLine(buffer[data]);
            }
            else
            {
                printLine("ERROR: Array index is too big.");
            }
        }
    }
}

/* case1V2() uses the Case0Source with the Case1Sink */
static void case1V2()
{
    int data;
    /* Initialize data */
    data = -1;
    /* NOTE: Set data to a random value */
    data = RAND32();
    {
        int dataCopy = data;
        int data = dataCopy;
        {
            int buffer[10] = { 0 };
            /* ALT: Properly validate the array index and prevent a buffer underread */
            if (data >= 0 && data < (10))
            {
                printIntLine(buffer[data]);
            }
            else
            {
                printLine("ERROR: Array index is out-of-bounds");
            }
        }
    }
}

void CWE127_Buffer_Underread__CWE839_rand_31_case1()
{
    case1V1();
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
    CWE127_Buffer_Underread__CWE839_rand_31_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE127_Buffer_Underread__CWE839_rand_31_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
