#include "bitgene.h"
#include "randomgenerator.h"

BitGene::BitGene() : Gene()
{
}

BitGene::BitGene(const double mutate_probability) : Gene(mutate_probability)
{
}



void BitGene::mutate()
{
    if(RandomGenerator::get_random_real_between(0, 1) < m_mutate_probability)
    {
        m_value = !m_value;
    }
}
