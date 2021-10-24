#include "car.h"

// Input car parameters from the file.
bool car::In(FILE *file)
{
    return fscanf(file, "%hu %d %lf", &max_speed,  &fuel_tank_capacity, &lit_per_100_km);
}

// Output car parameters.
void car::Out(FILE *file)
{
    fprintf(file, "%s %d","This is a car: maximum speed = ", max_speed);
    fprintf(file, "%s %d %s %f",". Fuel tank capacity = ", fuel_tank_capacity, "; Liters per 100 km needed ", lit_per_100_km);
    fprintf(file, "%s %f %c", ". Max distance can be covered = ", Max_dist(), '\n');
}

// Creating random parameters for the car.
void car::InRnd()
{
    max_speed = rand()%256;
    fuel_tank_capacity = 45 + rand()%(100 - 45);
    lit_per_100_km = 1.0 * (50 + rand()%100)/10;
}
