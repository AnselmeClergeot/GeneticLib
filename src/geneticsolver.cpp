#include "geneticsolver.h"
#include "randomgenerator.h"
#include "chromosome.h"
#include "crossoverfunctions.h"
#include <algorithm>
#include <assert.h>

GeneticSolver::GeneticSolver(const GeneType gene_type) : m_gene_type(gene_type), m_population(), m_population_size(0), m_chromosome_length(0), m_mutated_gene_number(1), m_fitness_function_pointer(nullptr), m_number_of_parents(0), m_parents(), m_children()
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

void GeneticSolver::set_fitness_function(double (*function)(Chromosome))
{
    m_fitness_function_pointer = function;
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

void GeneticSolver::set_number_of_parents_selected(const unsigned int number_of_parents)
{
    m_number_of_parents = number_of_parents;
}

unsigned int GeneticSolver::get_number_of_parents_selected() const
{
    return m_number_of_parents;
}

void GeneticSolver::go_to_next_generation()
{
    calculate_all_fitnesses();
    order_solutions();
    select_parents();
    mate_parents();
    insert_children();
    do_mutations();
}

//PRIVATE METHODS

void GeneticSolver::calculate_all_fitnesses()
{
    for(Chromosome &c : m_population)
        c.set_fitness((*m_fitness_function_pointer)(c));
}

void GeneticSolver::order_solutions()
{
    std::sort(m_population.begin(), m_population.end(), SolutionFitnessCompare());
}

void GeneticSolver::select_parents()
{
    double sum_of_fitnesses {0};

    for(Chromosome c : m_population)
        sum_of_fitnesses += c.get_fitness();

    for(unsigned int i {0}; i < m_number_of_parents; i++)
    {
        double random_fitness = RandomGenerator::get_random_real_between(0, sum_of_fitnesses);

        unsigned int parent_index {0};
        double current_fitness_sum {m_population[0].get_fitness()};

        while(current_fitness_sum < random_fitness)
        {
            parent_index++;
            current_fitness_sum += m_population[parent_index].get_fitness();
        }

        m_parents.push_back(m_population[parent_index]);
    }

}

void GeneticSolver::mate_parents()
{
    for(unsigned int i {0}; i < m_number_of_parents; i++)
    {
        for(unsigned int j {i+1}; j < m_number_of_parents; j++)
        {
            std::vector<Chromosome> children(Crossovers::uniform_crossover(m_parents[i], m_parents[j]));

            for(Chromosome c : children)
                m_children.push_back(c);
        }
    }

    m_parents.clear();
}

void GeneticSolver::insert_children()
{
    for(unsigned int i {0}; i < m_children.size(); i++)
    {
        assert(m_population_size - i - 1 >= 0 && m_population_size - i - 1 < m_population_size);

        m_population[m_population_size - i - 1] = m_children[i];
    }

    m_children.clear();
}

Chromosome GeneticSolver::get_best_solution()
{
    order_solutions();
    return m_population[0];
}

std::vector<Chromosome> GeneticSolver::get_all_solutions()
{
    return m_population;
}
