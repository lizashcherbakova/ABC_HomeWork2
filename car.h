#ifndef CAR_H
#define CAR_H

#include <cstdlib>
#include "transportation.h"

class car: public transportation{
private:
    unsigned short max_speed;
public:
    // Input car parameters from the file.
    virtual bool In(FILE *file);
    // Output car parameters.
    virtual void InRnd();
    // Creating random parameters for the car.
    virtual void Out(FILE *file);
};

#endif // CAR_H