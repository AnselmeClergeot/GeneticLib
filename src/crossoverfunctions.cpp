#include "crossoverfunctions.h"
#include "randomgenerator.h"


namespace Crossovers
{
std::vector<Chromosome> uniform_crossover(Chromosome lhs, Chromosome rhs)
{
    std::vector<Chromosome> children;
    children.emplace_back(Chromosome(lhs.get_gene_type(), lhs.get_length()));
    children.emplace_back(Chromosome(lhs.get_gene_type(), lhs.get_length()));

    for(unsigned int i {0}; i < lhs.get_length(); i++)
    {
        unsigned int selected_parent {static_cast<int>(RandomGenerator::get_random_real_between(0, 2))};

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

