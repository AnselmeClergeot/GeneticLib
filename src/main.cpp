#include <iostream>
#include "crossoverfunctions.h"
#include "randomgenerator.h"

int main()
{
    RandomGenerator::initialize();

    Chromosome a(Bit, 8), b(Bit, 8);

    a.describe();
    std::cout << std::endl;
    b.describe();

    std::vector<Chromosome> children(Crossovers::uniform_crossover(a, b));

    std::cout << "Children : " << std::endl;

    for(Chromosome c : children)
    {
        c.describe();
        std::cout << std::endl;
    }

    return 0;
}
