#ifndef CEBIR_H
#define CEBIR_H

#include <cmath>
#include <vector>
#include <map>

#include "InfiniteInteger.h"

using std::vector;
using std::map;


namespace projectEuler
{

//
// A basic helper class for known math problems
//
class Cebir
{
    public:
        static bool IsPrimeNumber(long long number);                                // Extremely bad prime number tester
        static vector<long long> GetFactors(long long number, bool addSelf = true); // Find factors of the given number
        static int FactorCount(long long number);                                   // Finds number of factors of the given number
        static long Combination(long total, long selection);                        // Calculates combination 
        static long long Factorial(long number);                                    // Calculates factorial of given number
        static InfiniteInteger Factorial(const InfiniteInteger& number);            // Calculates factorial of infinite long numbers!
        static vector<InfiniteInteger> Fibonacci(const unsigned long limit);        // Calculate Fibonacci of infinite long numbers!

    private:
        Cebir();  
        ~Cebir(); 
};

}

#endif // CEBIR_H
