/*
 * @description Incomplete initialization
 * 
 * */

#include "std_testcase.h"
#include <iostream>

using namespace std;

namespace CWE665_Improper_Initialization__class_01
{

#ifndef OMITCASE1

class Case1Class {
    public:
        Case1Class()
        {
            initialize();
        }

        void initialize()
        {
            initialized = false; /* ALT: correctly isInitialized to false */

            if (!initialized)
            {
                printLine("Initializing...");
                initialized = true;
            }
        }

        bool isInitialized()
        {
            return initialized;
        }

    private:
        bool initialized;
};

static void case11()
{
    Case1Class case1ClassObject = Case1Class();

    cout << "Initialized? ";
    if (case1ClassObject.isInitialized())
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    cout << endl;
}

void case1()
{
    case11();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on 
 * its own for testing or for building a binary to use in testing binary 
 * analysis tools. It is not used when compiling all the testcases as one 
 * application, which is how source code analysis tools are tested. 
 */ 

#ifdef INCLUDEMAIN

using namespace CWE665_Improper_Initialization__class_01; /* so that we can use case1 and case0 easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
    return 0;
}

#endif
