#include "transportation.h"

// Counting the maximum distance for transportation.
double transportation::Max_dist()
{
    return  lit_per_100_km * 100.0 * fuel_tank_capacity;
}
