#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <vector>
#include "gene.h"

class Chromosome
{
public:
    Chromosome(GeneType type, const unsigned int length);

    void set_mutate_probability(const double probability);

    void set_gene_at(const unsigned int pos, Gene *gene);
    Gene *get_gene_at(const unsigned int position);

    unsigned int get_length() const;

    void set_fitness(const double fitness);
    double get_fitness() const;

    void mutate(const unsigned int number_of_gene);

    GeneType get_gene_type() const;

    void describe();


private:
    unsigned int m_length;
    std::vector<Gene *> m_genes;

    GeneType m_gene_type;

    double m_fitness;
};

#endif // CHROMOSOME_H
