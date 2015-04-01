#ifndef PROBLEM_X_H
#define PROBLEM_X_H

#include "ProblemBase.h"


namespace projectEuler
{

class Problem23 : public ProblemBase
{
    public:
        Problem23();
        ~Problem23();

        void Solve();

    private:

        bool IsAbundant(int number);

};

}

#endif // PROBLEM_X_H
