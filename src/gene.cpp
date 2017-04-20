#include "gene.h"

Gene::Gene() : m_mutate_probability(0.05)
{

}

Gene::Gene(const double mutate_probability) : m_mutate_probability(mutate_probability)
{

}

void Gene::set_mutate_probability(const double probability)
{
    m_mutate_probability = probability;
}

double Gene::get_mutate_probability() const
{
    return m_mutate_probability;
}
