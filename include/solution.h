#ifndef SOLUTION_H
#define SOLUTION_H
#include "chromosome.h"

class Solution
{
public:
    Solution();

private:
    Chromosome m_chromosome;
    double m_fitness;

};

#endif // SOLUTION_H
