#include "Problem9.h"

namespace projectEuler
{

// Constructor
Problem9::Problem9()
{
    
}


// Destructor
Problem9::~Problem9()
{

}


// Solver
void Problem9::Solve()
{
    for(int a = 3; a < 1000; a++)
    {
        for(int b = 4; b < 1000; b++)
        {
            int c = 1000 - a - b;
            
            if((a*a + b*b == c*c))
            {
                mAnswer << a*b*c;
                return;
            }
        }
    }
}

}
