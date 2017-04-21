#include "geneticsolver.h"
#include "randomgenerator.h"

GeneticSolver::GeneticSolver(const GeneType gene_type) : m_gene_type(gene_type), m_population(), m_population_size(0), m_chromosome_length(0), m_mutated_gene_number(1)
{
    RandomGenerator::initialize();
}

void GeneticSolver::set_chromosome_length(const unsigned int length)
{
    m_chromosome_length = length;
}

unsigned int GeneticSolver::get_chromosome_length() const
{
    return m_chromosome_length;
}

void GeneticSolver::set_population_size(const unsigned int size)
{
    m_population_size = size;
}

unsigned int GeneticSolver::get_population_size() const
{
    return m_population_size;
}

void GeneticSolver::prepare_first_population()
{
    for(unsigned int i {0}; i < m_population_size; i++)
    {
        m_population.emplace_back(Chromosome(m_gene_type, m_chromosome_length));
        m_population[i].set_mutate_probability(m_mutate_probability);
    }
}

void GeneticSolver::set_mutate_probability(const double probability)
{
    m_mutate_probability = probability;
}

double GeneticSolver::get_mutate_probability() const
{
    return m_mutate_probability;
}

void GeneticSolver::set_mutated_gene_number(const unsigned int mutated_gene_number)
{
    m_mutated_gene_number = mutated_gene_number;
}

unsigned int GeneticSolver::get_mutated_gene_number() const
{
    return m_mutated_gene_number;
}

void GeneticSolver::do_mutations()
{
    for(Chromosome c : m_population)
        c.mutate(m_mutated_gene_number);
}
