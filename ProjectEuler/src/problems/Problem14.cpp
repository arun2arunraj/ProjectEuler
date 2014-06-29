#include "Problem14.h"

namespace projectEuler
{

// Constructor
Problem14::Problem14()
{
    
}


// Destructor
Problem14::~Problem14()
{

}


// Solver
void Problem14::Solve()
{
    long maxChain = 0;
    unsigned long answer = 0;
    
    for (unsigned long i = 2; i < 1000000; i++)
    {
        long long tempRes = i;
        long chain = 1;

        while(tempRes != 1)
        {
            //cout << tempRes << endl;

            if(tempRes % 2 == 0)
                tempRes = tempRes >> 1;
            else
                tempRes = tempRes*3 + 1;

            chain++;
        }

        if(chain > maxChain)
        {
            maxChain = chain;
            answer = i;
        }

    }

    mAnswer << answer;
}

}
