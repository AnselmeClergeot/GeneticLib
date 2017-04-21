#include <cstdlib>
#include <time.h>

namespace RandomGenerator
{
    void initialize()
    {
        srand(time(nullptr));
    }

    double get_random_real_between(const double min, const double max)
    {
        return min + (rand()/(double)RAND_MAX) * (max - min);
    }
}
