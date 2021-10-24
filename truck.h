#ifndef TRUCK_H
#define TRUCK_H

#include <cstdlib>
#include "transportation.h"

class truck: public transportation{
private:
    int load_capacity;
public:
    // Input truck parameters from the file.
    virtual bool In(FILE *file);
    // Output truck parameters.
    virtual void InRnd();
    // Creating random parameters for the truck.
    virtual void Out(FILE *file);
};

#endif // TRUCK_H
