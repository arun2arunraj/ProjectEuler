#include "Problem25.h"

namespace projectEuler
{

// Constructor
Problem25::Problem25()
{
    
}


// Destructor
Problem25::~Problem25()
{

}


// Solver
void Problem25::Solve()
{
    InfiniteInteger a("1");
    InfiniteInteger b("1");
    InfiniteInteger c("0");
    long int i = 2;

    while(true)
    {
        c = a + b;
        a = b;
        b = c;
        i++;

        if(c.GetNumberStr().length() == 1000)
        {
            mAnswer << i;
            break;
        }
    }
}

}
