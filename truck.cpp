#include "truck.h"

// Input truck parameters from the file.
bool truck::In(FILE *file)
{
    return fscanf(file, "%d %d %lf", &load_capacity,  &fuel_tank_capacity, &lit_per_100_km);
}

// Output truck parameters.
void truck::Out(FILE *file)
{
    fprintf(file, "%s %d","This is a truck: Load capacity = ", load_capacity);
    fprintf(file, "%s %d %s %f",". Fuel tank capacity = ", fuel_tank_capacity, "; Liters per 100 km needed ", lit_per_100_km);
    fprintf(file, "%s %f %c", ". Max distance can be covered = ", Max_dist(), '\n');
}

// Creating random parameters for the truck.
void truck::InRnd()
{
    load_capacity = rand()%28000;
    fuel_tank_capacity = 200 + rand()%1300;
    lit_per_100_km = 1.0 * (100 + rand()%(1000-100))/10;
}