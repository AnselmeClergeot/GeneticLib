#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <vector>
#include "gene.h"

enum GeneType
{
    Bit
};

class Chromosome
{
public:
    Chromosome(GeneType type, const unsigned int length);

    void set_mutate_probability(const double probability);

    Gene *get_gene_at(const unsigned int position);

    unsigned int get_length() const;

    void set_fitness(const double fitness);
    double get_fitness() const;

    void mutate();

private:
    unsigned int m_length;
    std::vector<Gene *> m_genes;

    double m_fitness;
};

#endif // CHROMOSOME_H
