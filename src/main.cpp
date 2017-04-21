#include <iostream>
#include "geneticsolver.h"

int main()
{
    GeneticSolver solver(GeneType::Bit);

    solver.set_chromosome_length(8);
    solver.set_population_size(15);
    solver.set_mutate_probability(0.05);
    solver.set_mutated_gene_number(solver.get_chromosome_length());

    solver.prepare_first_population();

    solver.do_mutations();

    //Ready to do generations

    std::cout << "Population size : " << solver.get_population_size() << std::endl;

    return 0;
}
