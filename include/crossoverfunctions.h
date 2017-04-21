#ifndef CROSSOVERFUNCTIONS_H
#define CROSSOVERFUNCTIONS_H
#include "chromosome.h"
#include <vector>

namespace Crossovers
{
    std::vector<Chromosome> uniform_crossover(Chromosome lhs, Chromosome rhs);
}

#endif // CROSSOVERFUNCTIONS_H
