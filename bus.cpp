#include "bus.h"

// Input bus parameters from the file.
bool bus::In(FILE *file)
{
    return fscanf(file, "%hu %d %lf", &passenger_capacity,  &fuel_tank_capacity, &lit_per_100_km);
}

// Output bus parameters.
void bus::Out(FILE *file)
{
    fprintf(file, "%s %d","This is a bus: Passenger capacity = ", passenger_capacity);
    fprintf(file, "%s %d %s %f",". Fuel tank capacity = ", fuel_tank_capacity, "; Liters per 100 km needed ", lit_per_100_km);
    fprintf(file, "%s %f %c", ". Max distance can be covered = ", Max_dist(), '\n');
}

// Creating random parameters for the bus.
void bus::InRnd()
{
    passenger_capacity = rand()%256;
    fuel_tank_capacity = 200 + rand()%100;
    lit_per_100_km = 1.0 * (410 + rand()%(1000-410))/10;
}