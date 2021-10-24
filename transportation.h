#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

#include <stdio.h>

class transportation{
protected:
    int fuel_tank_capacity;
    double lit_per_100_km;
public:
    // Input general transportation from the file.
    virtual bool In(FILE *file) = 0;
    // Creating random parameters for general transportation.
    virtual void InRnd() = 0;
    // Outputs all parameters of transportation.
    virtual void Out(FILE *file) = 0;
    // Counting the maximum distance for general transportation.
    double Max_dist();
};
#endif // TRANSPORTATION_H
