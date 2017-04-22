#ifndef GENE_H
#define GENE_H
#include "enumerations.h"

class Gene
{
public:
    Gene(const double mutate_probability);
    Gene(const Gene *other);

    virtual void mutate() = 0;

     void update_mutate_probability(const double probability);



protected:
    double m_mutate_probability;
};

#endif // GENE_H
