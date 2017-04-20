#ifndef BITGENE_H
#define BITGENE_H
#include "gene.h"

class BitGene : public Gene
{
public:
    BitGene();

    BitGene(const double mutate_probability);

    virtual void mutate();

private:
    bool m_value;
};

#endif // BITGENE_H
