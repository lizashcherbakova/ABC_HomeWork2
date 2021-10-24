#ifndef BUS_H
#define BUS_H

#include "transportation.h"
#include <stdlib.h>

class bus: public transportation{
private:
    unsigned short passenger_capacity;
public:
    // Input bus parameters from the file.
    virtual bool In(FILE *file);
    // Output bus parameters.
    virtual void InRnd();
    // Creating random parameters for the bus.
    virtual void Out(FILE *file);
};

#endif BUS_H
