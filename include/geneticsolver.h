#ifndef GENETICSOLVER_H
#define GENETICSOLVER_H
#include "chromosome.h"
#include <vector>

class GeneticSolver
{
public:
    GeneticSolver(const GeneType gene_type);

    void set_chromosome_length(const unsigned int length);
    unsigned int get_chromosome_length() const;

    void set_population_size(const unsigned int size);
    unsigned int get_population_size() const;

    void set_mutate_probability(const double probability);
    double get_mutate_probability() const;

    void set_mutated_gene_number(const unsigned int mutated_gene_number);
    unsigned int get_mutated_gene_number() const;

    void set_number_of_parents_selected(const unsigned int number_of_parents);
    unsigned int get_number_of_parents_selected() const;

    void set_fitness_function(double (*function)(Chromosome));

    void prepare_first_population();

    void go_to_next_generation();

    Chromosome get_best_solution();

    std::vector<Chromosome> get_all_solutions();

private:
    GeneType m_gene_type;
    unsigned int m_population_size, m_chromosome_length, m_number_of_parents;

    std::vector<Chromosome> m_population;
    std::vector<Chromosome> m_parents;
    std::vector<Chromosome> m_children;

    unsigned int m_mutated_gene_number;

    double m_mutate_probability;

    double (*m_fitness_function_pointer)(Chromosome);

    //FUNCTIONS


    void calculate_all_fitnesses();
    void order_solutions();
    void select_parents();
    void mate_parents();
    void insert_children();
    void do_mutations();
};

#endif // GENETICSOLVER_H
