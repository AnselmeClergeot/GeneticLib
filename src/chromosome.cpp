#include "chromosome.h"
#include "bitgene.h"
#include "randomgenerator.h"
#include <cassert>
#include <iostream>

Chromosome::Chromosome(GeneType type, const unsigned int length) :  m_length(length), m_genes(), m_fitness(0)
{
    for(unsigned int i {0}; i < length; i++)
    {
        switch(type)
        {
            case Bit :
                m_genes.push_back(new BitGene());
            break;
        }
    }
}

void Chromosome::set_mutate_probability(const double probability)
{
    for(Gene *gene : m_genes)
    {
        gene->set_mutate_probability(probability);
    }
}

Gene *Chromosome::get_gene_at(const unsigned int position)
{
    assert(position < m_length);
    return m_genes[position];
}

unsigned int Chromosome::get_length() const
{
    return m_length;
}

void Chromosome::set_fitness(const double fitness)
{
    m_fitness = fitness;
}

double Chromosome::get_fitness() const
{
    return m_fitness;
}

void Chromosome::mutate(const unsigned int number_of_gene)
{
    std::vector<Gene *> to_mutate {};

    std::vector<unsigned int> possible_positions {};

    for(unsigned int i {0}; i < m_length; i++)
        possible_positions.emplace_back(i);

    for(unsigned int i {0}; i < number_of_gene; i++)
    {
        int pos_in_array {static_cast<int>(RandomGenerator::get_random_real_between(0, possible_positions.size()))};

        to_mutate.push_back(m_genes[possible_positions[pos_in_array]]);

        possible_positions.erase(possible_positions.begin() + pos_in_array);
    }

    for(Gene *gene : to_mutate)
        gene->mutate();
}
