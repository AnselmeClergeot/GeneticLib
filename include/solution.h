#ifndef SOLUTION_H
#define SOLUTION_H
#include "chromosome.h"

template <typename T>
class Solution
{
public:
    Solution();

    double get_fitness() const;


private:
    Chromosome<T> m_chromosome;
    double m_fitness;
};

#endif // SOLUTION_H
