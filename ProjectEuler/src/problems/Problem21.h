#ifndef PROBLEM_21_H
#define PROBLEM_21_H

#include "ProblemBase.h"


namespace projectEuler
{

class Problem21 : public ProblemBase
{
    public:
        Problem21();
        ~Problem21();

        void Solve();

    private:
        bool AmicablePair(int input);

};

}

#endif // PROBLEM_21_H
