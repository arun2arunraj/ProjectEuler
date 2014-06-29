#ifndef PROBLEM_17_H
#define PROBLEM_17_H

#include "ProblemBase.h"


namespace projectEuler
{

class Problem17 : public ProblemBase
{
    public:
        Problem17();
        ~Problem17();

        void Solve();

    private:
        int LetterCountInNumber(int number); // Number of letters in British English pronunciation of given number

        map<int, string> numberMap;
};

}

#endif // PROBLEM_17_H
