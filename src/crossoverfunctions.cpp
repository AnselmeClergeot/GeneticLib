#include "crossoverfunctions.h"
#include "randomgenerator.h"
#include <iostream>

namespace Crossovers
{

std::vector<Chromosome> single_point_crossover(Chromosome lhs, Chromosome rhs)
{
    std::vector<Chromosome> children;
    children.emplace_back(Chromosome(lhs.get_gene_type(), lhs.get_length(), lhs.get_mutate_probability()));
    children.emplace_back(Chromosome(lhs.get_gene_type(), lhs.get_length(), lhs.get_mutate_probability()));

    unsigned int point { static_cast<unsigned int>(RandomGenerator::get_random_real_between(0, lhs.get_length()-1)) };

    for(unsigned int i {0}; i < lhs.get_length(); i++)
    {
        if(i <= point)
        {
            children[0].set_gene_at(i, lhs.get_gene_at(i));
            children[1].set_gene_at(i, rhs.get_gene_at(i));
        }
        else
        {
            children[0].set_gene_at(i, rhs.get_gene_at(i));
            children[1].set_gene_at(i, lhs.get_gene_at(i));
        }
    }
    return children;
}

std::vector<Chromosome> two_points_crossover(Chromosome lhs, Chromosome rhs)
{
    std::vector<Chromosome> children;
    children.emplace_back(Chromosome(lhs.get_gene_type(), lhs.get_length(), lhs.get_mutate_probability()));
    children.emplace_back(Chromosome(lhs.get_gene_type(), lhs.get_length(), lhs.get_mutate_probability()));

    unsigned int point_1 { static_cast<unsigned int>(RandomGenerator::get_random_real_between(0, lhs.get_length()-2)) };

    unsigned int point_2 { static_cast<unsigned int>(RandomGenerator::get_random_real_between(point_1+1, lhs.get_length()-1)) };

    for(unsigned int i {0}; i < lhs.get_length(); i++)
    {
        if(i <= point_1 || i > point_2)
        {
            children[0].set_gene_at(i, lhs.get_gene_at(i));
            children[1].set_gene_at(i, rhs.get_gene_at(i));
        }
        else
        {
            children[0].set_gene_at(i, rhs.get_gene_at(i));
            children[1].set_gene_at(i, lhs.get_gene_at(i));
        }
    }
    return children;
}

std::vector<Chromosome> uniform_crossover(Chromosome lhs, Chromosome rhs)
{
    std::vector<Chromosome> children;
    children.emplace_back(Chromosome(lhs.get_gene_type(), lhs.get_length(), lhs.get_mutate_probability()));
    children.emplace_back(Chromosome(lhs.get_gene_type(), lhs.get_length(), lhs.get_mutate_probability()));

    for(unsigned int i {0}; i < lhs.get_length(); i++)
    {
        unsigned int selected_parent {static_cast<unsigned int>(RandomGenerator::get_random_real_between(0, 2))};

        if(selected_parent == 0)
        {
            children[0].set_gene_at(i, lhs.get_gene_at(i));
            children[1].set_gene_at(i, rhs.get_gene_at(i));
        }
        else
        {
            children[0].set_gene_at(i, rhs.get_gene_at(i));
            children[1].set_gene_at(i, lhs.get_gene_at(i));
        }
    }

    return children;
}
}

