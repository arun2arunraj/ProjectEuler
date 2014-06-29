#include "Cebir.h"


namespace projectEuler
{

Cebir::Cebir()
{

}


Cebir::~Cebir()
{

}


bool Cebir::IsPrimeNumber(long long number)
{
    if(number < 2)
        return false;
    else if(number == 2 || number == 3)
        return true;

    for(long long i = 2; i <= sqrt(static_cast<long double>(number)) + 1; i++)
    {
        if(number % i == 0)
            return false;
    }

    return true;
}


vector<long long> Cebir::GetFactors(long long number)
{
    vector<long long> factors;
    factors.push_back(1); // 1 is factor of everyone
    const long long limit = number;
    
    for (long long i = 2; i < limit; i++)
    {
        if (number % i == 0)
            factors.push_back(i);
    }

    factors.push_back(number); // Number itself is always factor

    return factors; // Return copy of factors
}


int Cebir::FactorCount(long long number)
{
    if(IsPrimeNumber(number))
        return 2; // 1 and number

    map<long long, int> primePairs;

    for (long long i = 2; i <= number; i++)
    {
        if (IsPrimeNumber(i))
        {
            while(number % i == 0)
            {
                primePairs[i] = primePairs[i] + 1;
                number = number / i;
            }   
        }
    }

    int count = 1;

    for(map<long long, int>::iterator iterator = primePairs.begin(); iterator != primePairs.end(); ++iterator)
    {
        count = (iterator->second + 1) * count;
    }
    
    return count;
}


long Cebir::Combination(long total, long selection)
{
    long long divider = Factorial(selection);
    long long top = 1;

    while(selection > 0)
    {
        top *= total--;
        selection--;
    }

    return top / divider;
}


long long Cebir::Factorial(long number)
{
    long long factor = 1;

    while(number > 0)
        factor *= number--;

    return factor;
}


InfiniteInteger Cebir::Factorial(const InfiniteInteger& number)
{
    InfiniteInteger factor("1");
    InfiniteInteger counter("1"); // Since we don't have subtraction in InfiniteInteger yet :)

    while(counter != number)
        factor *= counter++;

    return factor;
}

}// namespace projectEuler
