#include <iostream>
#include "geneticsolver.h"

int main()
{
    GeneticSolver solver(GeneType::Bit);

    solver.set_chromosome_length(8);
    solver.set_population_size(15);

    solver.prepare_first_population();

    solver.do_mutations();

    //Ready to do generations

    std::cout << "Population size : " << solver.get_population_size() << std::endl;

    return 0;
}
