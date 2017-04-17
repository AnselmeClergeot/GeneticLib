#include "chromosome.h"
#include <cassert>

template<typename T>
Chromosome<T>::Chromosome(const int length) : m_length {length}, m_genes {}
{

}

template<typename T>
int Chromosome<T>::get_length() const
{
    return m_length;
}

template<typename T>
T Chromosome<T>::get_gene_at(const int pos)
{
    assert(pos >= 0 && pos < m_length);
    return m_genes[pos];
}
