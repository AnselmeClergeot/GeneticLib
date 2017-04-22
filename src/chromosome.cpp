#include "chromosome.h"
#include "bitgene.h"
#include "randomgenerator.h"
#include <cassert>
#include <iostream>

bool SolutionFitnessCompare::operator()(const Chromosome &lhs, const Chromosome &rhs) const
{
    return lhs.get_fitness() > rhs.get_fitness();
}

Chromosome::Chromosome(GeneType type, const unsigned int length, const double mutate_probability) :  m_length(length), m_genes(), m_fitness(0), m_gene_type(type)
{
    for(unsigned int i {0}; i < length; i++)
    {
        switch(type)
        {
            case Bit :
                m_genes.push_back(new BitGene(mutate_probability));
            break;
        }
    }
}

void Chromosome::set_gene_at(const unsigned int pos, Gene *gene)
{
    switch(m_gene_type)
    {
        case Bit:
            m_genes[pos] = new BitGene(dynamic_cast<BitGene *>(gene));
        break;
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
    std::vector<Gene *> to_mutate;

    std::vector<unsigned int> possible_positions;

    for(unsigned int i {0}; i < m_length; i++)
        possible_positions.emplace_back(i);

    for(unsigned int i {0}; i < number_of_gene; i++)
    {
        int pos_in_array {static_cast<int>(RandomGenerator::get_random_real_between(0, possible_positions.size()-1))};

        assert(pos_in_array < possible_positions.size());
        assert(possible_positions[pos_in_array] < m_genes.size());

        to_mutate.push_back(m_genes[possible_positions[pos_in_array]]);

        possible_positions.erase(possible_positions.begin() + pos_in_array);
    }

    for(Gene *gene : to_mutate)
        gene->mutate();
}

 GeneType Chromosome::get_gene_type() const
 {
     return m_gene_type;
 }

 void Chromosome::describe()
 {
     for(Gene *g : m_genes)
     {
         std::cout << dynamic_cast<BitGene *>(g)->get_value();
     }
 }

 double Chromosome::get_mutate_probability()
 {
     return m_mutate_probability;
 }
