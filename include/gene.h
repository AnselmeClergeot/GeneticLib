#ifndef GENE_H
#define GENE_H
#include "enumerations.h"

class Gene
{
public:
    Gene();
    Gene(const double mutate_probability);

    virtual void mutate() = 0;

    void set_mutate_probability(const double probability);
    double get_mutate_probability() const;



protected:
    double m_mutate_probability;
};

#endif // GENE_H
