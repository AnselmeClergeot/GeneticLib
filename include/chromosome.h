#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <vector>

template <typename T>
class Chromosome
{
public:
    Chromosome(const int length);

    int get_length() const;
    T get_gene_at(const int pos);

private:
    int m_length;
    std::vector<T> m_genes;

};

#endif // CHROMOSOME_H
