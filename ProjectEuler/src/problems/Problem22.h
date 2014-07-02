#ifndef PROBLEM_21_H
#define PROBLEM_21_H

#include <algorithm>    // std::sort

#include "ProblemBase.h"


namespace projectEuler
{

class Problem22 : public ProblemBase
{
    public:
        Problem22();
        ~Problem22();

        void Solve();

    private:
        vector<string> mNames;

        void FillNames();
        void SortNames();
        int AlphabeticValue(const string& name);
};

}

#endif // PROBLEM_21_H
