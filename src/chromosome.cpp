#include "chromosome.h"
#include "bitgene.h"
#include <cassert>

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

void Chromosome::mutate()
{
    for(Gene *gene : m_genes)
        gene->mutate();
}
