#include "gene.h"

Gene::Gene(const double mutate_probability) : m_mutate_probability(mutate_probability)
{

}

Gene::Gene(const Gene *other) : m_mutate_probability(other->m_mutate_probability)
{

}

 void Gene::update_mutate_probability(const double probability)
 {
     m_mutate_probability = probability;
 }
