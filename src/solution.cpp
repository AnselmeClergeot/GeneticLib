#include "solution.h"

template <typename T>
Solution<T>::Solution() : m_fitness(0)
{

}

template <typename T>
double Solution<T>::get_fitness() const
{
    return m_fitness;
}
