#ifndef INFINITE_INTEGER_H
#define INFINITE_INTEGER_H

#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>

#include "Macros.h"

using std::vector;
using std::string;
using std::stringstream;
using std::atoi;
using std::cout;
using std::endl;


namespace projectEuler
{

//
// A basic class that makes possible to define infinitely long integer numbers
// Addition is supported (Subtract not yet supported)
// Negative numbers are not supported
//
class InfiniteInteger
{
    public:
        InfiniteInteger();  
        InfiniteInteger(const InfiniteInteger& input);
        InfiniteInteger(const string& input);
        ~InfiniteInteger(); 

        string GetNumberStr() const;
        size_t Size() const;
        
        int operator[](int i) const;
        bool operator==(const InfiniteInteger& input);
        bool operator!=(const InfiniteInteger& input);
        InfiniteInteger& operator++();
        InfiniteInteger operator+(const InfiniteInteger& input);
        InfiniteInteger& operator+=(const InfiniteInteger& input);
        InfiniteInteger operator*(const InfiniteInteger& input);
        InfiniteInteger& operator*=(const InfiniteInteger& input);
        InfiniteInteger& operator=(const InfiniteInteger& input);
        InfiniteInteger& operator=(const string& input);

        enum DefaultSizes { DEFAULT_SIZE = 500 }; // 500 digits

    private:
        void Add(const InfiniteInteger& input);
        void Multiply(const InfiniteInteger& input);
        void Copy(const InfiniteInteger& input);
        void StringToNumber(const string& input);

        vector<char> number;
};


inline size_t InfiniteInteger::Size() const 
{
    return number.size();
}


inline int InfiniteInteger::operator[](int i) const
{ 
    return number[i]; 
}


inline bool InfiniteInteger::operator==(const InfiniteInteger& input)
{
    return (this->GetNumberStr() == input.GetNumberStr());
}


inline bool InfiniteInteger::operator!=(const InfiniteInteger& input)
{
    return (this->GetNumberStr() != input.GetNumberStr());
}


inline InfiniteInteger& InfiniteInteger::operator++()
{
    InfiniteInteger one("1");
    Add(one);

    return *this;
}


inline InfiniteInteger InfiniteInteger::operator+(const InfiniteInteger& input)
{
    if (this == &input)
    {
        InfiniteInteger temp(input);
        Add(temp);
    }
    else
    {
        Add(input);
    }

    return *this;
}


inline InfiniteInteger& InfiniteInteger::operator+=(const InfiniteInteger& input)
{
    if (this == &input)
    {
        InfiniteInteger temp(input);
        Add(temp);
    }
    else
    {
        Add(input);
    }

    return *this;
}


inline InfiniteInteger InfiniteInteger::operator*(const InfiniteInteger& input)
{
    if (this == &input)
    {
        InfiniteInteger temp(input);
        Multiply(temp);
    }
    else
    {
        Multiply(input);
    }

    return *this;
}


inline InfiniteInteger& InfiniteInteger::operator*=(const InfiniteInteger& input)
{
    if (this == &input)
    {
        InfiniteInteger temp(input);
        Multiply(temp);
    }
    else
    {
        Multiply(input);
    }

    return *this;
}


inline InfiniteInteger& InfiniteInteger::operator=(const InfiniteInteger& input)
{
    Copy(input);
    return *this;
}


inline InfiniteInteger& InfiniteInteger::operator=(const string& input)
{
    StringToNumber(input);
    return *this;
}

}

#endif // INFINITE_INTEGER_H
