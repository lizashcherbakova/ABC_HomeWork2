#include "container.h"

// Initializing the container.
container::container()
{
    len = 0;
}

// Clearing the container.
void container::Clear()
{
    for(int i = 0;i<len;++i){
        delete arr[i];
    }
    len = 0;
}

// Input all transportation from the file. If meets a mistake stops reading.
void container::In(FILE *file)
{
    int key;
    while(fscanf(file, "%d", &(key)) != EOF){
        transportation* tr;
        switch(key) {
            case 0:
                tr = new car();
                break;
            case 1:
                tr = new bus();
                break;
            case 2:
                tr = new truck();
                break;
        }
        if(!tr->In(file)){
            delete tr;
            return;
        };
        arr[len] = tr;
        ++len;
    }
}

// Outputs items in the container to the given file.
void container::Out(FILE *file)
{
    fprintf(file, "%s %d %s", "Container cotains ", len, " elements.\n");
    for(int i = 0; i < len; i++) {
        fprintf(file, "%d %s", i, " : ");
        arr[i]->Out(file);
    }
}

// Creating random transportation with given size.
void container::InRnd(int size)
{
    while(len < size) {
        transportation* tr;
        int number = rand()%3;
        if(number == 0){
            tr = new car();
        }else if(number == 1){
            tr = new truck();
        }else{
            tr = new bus();
        }
        tr->InRnd();
        arr[len] = tr;
        ++len;
    }
}

// Counts total max distance.
double container::MaxDistSum()
{
    long long int sum = 0;
    for(int i = 0; i < len; i++) {
        sum += arr[i]->Max_dist();
    }
    return sum;
}

bool container::Empty() {
    return len == 0;
}

void container::QuickSort(){
    QuickSort(arr, len);
}
// the algorithm was taken from here http://mindhalls.ru/quick-sort-c-cpp/
void container::QuickSort(transportation **mas, int size) {
    // Pointers to the start and to the end of the array.
    int i = 0;
    int j = size - 1;
    // The middle element.
    double mid = mas[size / 2]->Max_dist();
    // Spliting the array.
    do {
        while(mas[i]->Max_dist() < mid) {
            i++;
        }
        while(mas[j]->Max_dist() > mid) {
            j--;
        }
        // Flipping elements.
        if (i <= j) {
            transportation* tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    // Checking if there is something left to sort.
    if(j > 0) {
        // Left half.
        QuickSort(mas, j + 1);
    }
    if (i < size) {
        // Right half.
        QuickSort(&mas[i], size - i);
    }
}