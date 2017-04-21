#ifndef BITGENE_H
#define BITGENE_H
#include "gene.h"

class BitGene : public Gene
{
public:
    BitGene();

    BitGene(const double mutate_probability);
    BitGene(const BitGene *other);

    bool get_value() const;

    virtual void mutate();

private:
    bool m_value;
};

#endif // BITGENE_H
