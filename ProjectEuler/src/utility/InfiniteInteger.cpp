#include "InfiniteInteger.h"


namespace projectEuler
{

InfiniteInteger::InfiniteInteger()
{
    // Default size
    number.resize(DEFAULT_SIZE, 0);
}


InfiniteInteger::InfiniteInteger(const InfiniteInteger& input)
{
    Copy(input);
}


InfiniteInteger::InfiniteInteger(const string& input)
{
    StringToNumber(input);
}


InfiniteInteger::~InfiniteInteger()
{
    number.clear();
}


string InfiniteInteger::GetNumberStr() const
{
    stringstream stream;
    bool stopClip = false;

    // Number is in reverse oder in memory - convert it to human readable form
    for (int i = static_cast<int>(number.size()-1); i >= 0; i--)
    {
        if(number[i] == 0 && !stopClip)
            stopClip = false;
        else
            stopClip = true;
            
        if(stopClip)
            stream << static_cast<int>(number[i]);
    }

    return stream.str();
}


void InfiniteInteger::Add(const InfiniteInteger& input)
{
    // Resize if its needed
    if (input.Size() > number.size())
        number.resize(input.Size(), 0);

    for (size_t i = 0; i < number.size(); i++)
    {
        int numVal   = (i < number.size()) ? number[i] : 0;
        int inputVal = (i < input.Size())  ? input[i]  : 0;
        int accumulator = numVal + inputVal;
        
        if (accumulator >= 10)
        {
            number[i] = accumulator - 10;

            // Resize again, if overflow
            if (i+1 >= static_cast<int>(number.size()))
                number.resize(i+2, 0);

            number[i+1] += 1;
        }
        else
        {
            number[i] = accumulator;
        }
    }
}


void InfiniteInteger::Multiply(const InfiniteInteger& input)
{
    InfiniteInteger counter("0");
    InfiniteInteger accumulator("0");

    while(counter != input)
    {
        accumulator += (*this);
        ++counter;
    }

    Copy(accumulator);
}


void InfiniteInteger::Copy(const InfiniteInteger& input)
{
    if (this == &input)
        return;
    
    number.clear();
    number.resize(input.Size(), 0);

    for (size_t i = 0; i < input.Size(); i++)
        number[i] = input[i];
}


void InfiniteInteger::StringToNumber(const string& input)
{
    // Default size
    number.resize(DEFAULT_SIZE, 0);

    // Resize if its needed
    if (input.length() > number.size())
        number.resize(input.length(), 0);

    const int lastIndex = input.size() - 1;

    // Convert from human value char to real value char, also reverse it
    for (int i = 0; i <= lastIndex; i++)
        number[i] = input[lastIndex - i] - '0'; 
}

}// namespace projectEuler
