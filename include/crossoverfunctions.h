#ifndef CROSSOVERFUNCTIONS_H
#define CROSSOVERFUNCTIONS_H
#include "chromosome.h"
#include <vector>

namespace Crossovers
{
    std::vector<Chromosome> single_point_crossover(const Chromosome &lhs, const Chromosome &rhs);
    std::vector<Chromosome> two_points_crossover(const Chromosome &lhs, const Chromosome &rhs);
    std::vector<Chromosome> uniform_crossover(const Chromosome &lhs, const Chromosome &rhs);
}

#endif // CROSSOVERFUNCTIONS_H
