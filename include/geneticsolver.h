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

    void prepare_first_population();

    void do_mutations();

private:
    GeneType m_gene_type;
    unsigned int m_population_size, m_chromosome_length;
    std::vector<Chromosome> m_population;

    unsigned int m_mutated_gene_number;

    double m_mutate_probability;
};

#endif // GENETICSOLVER_H
