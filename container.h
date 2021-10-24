#ifndef CONTAINER_H
#define CONTAINER_H
#define MAX_LEN 10000

#include "car.h"
#include "bus.h"
#include "truck.h"

class container {
private:
    int len; // Current length.
    transportation* arr[MAX_LEN];
public:
    container();
    // Clearing the container.
    void Clear();
    // Input all transportation from the file. If meets a mistake stops reading.
    void In(FILE *file);
    // Creating random transportation with given size.
    void InRnd(int size);
    // Outputs items in the container to the given file.
    void Out(FILE *file);
    // Counts total max distance.
    double MaxDistSum();
    // Returns true if len = 0, otherwise returns false.
    bool Empty();
    // Sorting all elements according to the task.
    void QuickSort();
    void QuickSort(transportation **mas, int size);
};

#endif // CONTAINER_H
