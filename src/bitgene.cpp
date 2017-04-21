#include "bitgene.h"
#include "randomgenerator.h"
#include <iostream>

BitGene::BitGene() : Gene()
{
    if(RandomGenerator::get_random_real_between(0, 1) < 0.5)
        m_value = true;
    else
        m_value = false;
}

BitGene::BitGene(const double mutate_probability) : Gene(mutate_probability)
{
    if(RandomGenerator::get_random_real_between(0, 1) < 0.5)
        m_value = true;
    else
        m_value = false;
}

BitGene::BitGene(const BitGene *other) : Gene(other), m_value(other->get_value())
{

}


void BitGene::mutate()
{
    if(RandomGenerator::get_random_real_between(0, 1) < m_mutate_probability)
    {
        m_value = !m_value;
    }
}

bool BitGene::get_value() const
{
    return m_value;
}
