#ifndef PARAMETERS_DEFINITION_H
#define PARAMETERS_DEFINITION_H

public enum GeneType
{
    Int, Real, Bit, Char
};

public enum CrossoverMode
{
    SinglePoint, TwoPoints, Uniform
};

public enum SelectionMode
{
    FitnessProportionate, Tournament, StochasticUniversalSampling
};

#endif // PARAMETERS_DEFINITION_H
