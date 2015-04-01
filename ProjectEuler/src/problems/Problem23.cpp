#include "Problem23.h"

namespace projectEuler
{

// Constructor
Problem23::Problem23()
{
    
}


// Destructor
Problem23::~Problem23()
{

}


// Solver
void Problem23::Solve()
{
    // Very brute force solution, takes 60 seconds to solve!
    // it may be optimized in many ways!
    vector<int> all;
    vector<int> abundants;
    vector<int> sumAbundants;

    for(size_t i = 12; i < 28123 ; i++)
    {
        if(IsAbundant(i))
            abundants.push_back(i);
    }

    // Same elements are added twice to here, it can be optimized!
    for(size_t y = 0; y < abundants.size(); y++)
    {
        for(size_t x = 0; x < abundants.size(); x++)
        {
            sumAbundants.push_back(abundants[x] + abundants[y]);
        }
    }

    // Add to all list if it doesn't exist in sumAbundants vector
    for(size_t i = 1; i <= 28123; i++)
    {
        if(std::find(sumAbundants.begin(), sumAbundants.end(), i) == sumAbundants.end())
            all.push_back(i);
    }

    long sum = 0;
    for(size_t i = 0; i < all.size(); i++)
    {
        sum += all[i];
    }

    mAnswer << sum; 
    // Answer is: 4179871
}


bool Problem23::IsAbundant(int number)
{
    vector<long long> factors = Cebir::GetFactors(number, false);

    long long sum = 0;

    for(size_t i = 0; i < factors.size(); i++)
    {
        sum += factors[i];
    }

    return sum > number;
}

}
