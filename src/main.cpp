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

    return 8-abs(sum - 8);
}

int main()
{
    GeneticSolver solver(GeneType::Bit);

    solver.set_chromosome_length(10);
    solver.set_population_size(20);
    solver.set_mutated_gene_number(2);
    solver.set_mutate_probability(0.05);
    solver.set_number_of_parents_selected(3);
    solver.set_fitness_function(get_fitness_of);
    solver.set_crossover_mode(TwoPoints);

    const unsigned int GENERATIONS_NUMBER { 300 };

    for(unsigned int i {0}; i < GENERATIONS_NUMBER; i++)
    {
        solver.go_to_next_generation();

        std::cout << (i/static_cast<double>(GENERATIONS_NUMBER)) * 100 << std::endl;
    }

    solver.get_best_solution().describe();

    return 0;
}
