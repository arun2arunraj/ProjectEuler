#include "Problem21.h"

namespace projectEuler
{

// Constructor
Problem21::Problem21()
{
    
}


// Destructor
Problem21::~Problem21()
{

}


// Solver
void Problem21::Solve()
{
    int count = 0;
    
    for(int i = 0;  i < 10000; i++)
    {
        if(AmicablePair(i))
            count += i;
    }

    mAnswer << count; 
}


bool Problem21::AmicablePair(int input)
{
    vector<long long> factors = Cebir::GetFactors(input);
    int total = 0;

    for(vector<long long>::iterator it = factors.begin(); it != factors.end(); ++it)
    {
        total += *it;
    }

    total -= input;

    if(total == input)
        return false;

    vector<long long> factors2 = Cebir::GetFactors(total);
    int total2 = 0;

    for(vector<long long>::iterator it = factors2.begin(); it != factors2.end(); ++it)
    {
        total2 += *it;
    }

    total2 -= total;

    if(total2 == input)
        return true;
    else 
        return false;
}

}
