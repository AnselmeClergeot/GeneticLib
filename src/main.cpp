#include <iostream>
#include "geneticsolver.h"
#include "chromosome.h"
#include "bitgene.h"

double get_fitness_of(Chromosome c)
{
    double sum {0};

    for(unsigned int i {0}; i < c.get_length(); i++)
    {
        sum+=dynamic_cast<BitGene *>(c.get_gene_at(i))->get_value();
    }

    return 130-abs(sum - 130);
}

int main()
{
    GeneticSolver solver(GeneType::Bit);

    solver.set_chromosome_length(300);
    solver.set_population_size(50);
    solver.set_mutated_gene_number(solver.get_chromosome_length()/10);
    solver.set_mutate_probability(0.05);
    solver.set_number_of_parents_selected(2);
    solver.set_fitness_function(get_fitness_of);
    solver.set_crossover_mode(TwoPoints);

    const unsigned int GENERATIONS_NUMBER { 500 };

    for(unsigned int i {0}; i < GENERATIONS_NUMBER; i++)
    {
        solver.go_to_next_generation();
    }

    solver.get_best_solution().describe();

    return 0;
}
