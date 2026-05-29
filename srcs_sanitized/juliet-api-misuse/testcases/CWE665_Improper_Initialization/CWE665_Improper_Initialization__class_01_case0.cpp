/*
 * @description Incomplete initialization
 * 
 * */

#include "std_testcase.h"
#include <iostream>

using namespace std;

namespace CWE665_Improper_Initialization__class_01
{

#ifndef OMITCASE0

class Case0Class {
    public:
        Case0Class()
        {
            initialize();
        }

        void initialize()
        {
            initialized = true; /* NOTE: This should be false to avoid incomplete initalization */

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

void case0()
{
    Case0Class case0ClassObject = Case0Class();

    cout << "Initialized? ";
    if (case0ClassObject.isInitialized())
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    cout << endl;
}

#endif /* OMITCASE0 */

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
#ifndef OMITCASE0
    printLine("Calling case0()...");
    case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
