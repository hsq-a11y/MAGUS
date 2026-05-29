/*
 * @description Use After Free
 * 
 * */

#include "std_testcase.h"

namespace CWE416_Use_After_Free__operator_equals_01
{

#ifndef OMITCASE1

class Case1Class 
{
	public:
		Case1Class() 
        {
			name = NULL;
		}
		
		Case1Class(const char * name) 
        {
			if (name)
            {
                this->name = new char[strlen(name) + 1];
                strcpy(this->name, name);
            } 
            else 
            {
                this->name = new char[1];
                *(this->name) = '\0';
            }
		}

		~Case1Class() 
        {
			delete [] name;
		}

		/* copy constructor is only here to avoid double free incidentals */
		Case1Class(Case1Class &case1ClassObject)
        { 
			this->name = new char[strlen(case1ClassObject.name)+1]; 
			strcpy(this->name, case1ClassObject.name);
		}
		
		Case1Class& operator=(const Case1Class& case1ClassObject) 
        {
		    /* ALT - Check for self assignment and basically do nothing in that case */
			if (this != &case1ClassObject) 
            {
				delete [] this->name;
				this->name = new char[strlen(case1ClassObject.name)+1]; 
				strcpy(this->name, case1ClassObject.name);
			}
			return *this;
		}
		
		char * name;
};

static void case11()
{
    Case1Class case1ClassObject("Case1Class");
	case1ClassObject = case1ClassObject;
	printLine(case1ClassObject.name);
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

using namespace CWE416_Use_After_Free__operator_equals_01; /* so that we can use case1 and case0 easily */

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
