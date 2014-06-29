#ifndef PROBLEM_19_H
#define PROBLEM_19_H

#include "ProblemBase.h"


namespace projectEuler
{

class Problem19 : public ProblemBase
{
    public:
        Problem19();
        ~Problem19();

        void Solve();

    private:
        bool LeapYear(int year);
};

}

#endif // PROBLEM_X_H
