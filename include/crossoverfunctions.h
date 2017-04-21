#ifndef CROSSOVERFUNCTIONS_H
#define CROSSOVERFUNCTIONS_H
#include "chromosome.h"
#include <vector>

namespace Crossovers
{
    std::vector<Chromosome> single_point_crossover(Chromosome lhs, Chromosome rhs);
    std::vector<Chromosome> two_points_crossover(Chromosome lhs, Chromosome rhs);
    std::vector<Chromosome> uniform_crossover(Chromosome lhs, Chromosome rhs);
}

#endif // CROSSOVERFUNCTIONS_H
