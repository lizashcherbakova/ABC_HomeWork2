#include <stdio.h>
#include <cstring>
#include "container.h"

void errMessage1() {
    printf("%s", "incorrect command line!\n"
                 "  Waited:\n"
                 "     command -f infile outfile01 outfile02\n"
                 "  Or:\n"
                 "     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("%s","incorrect qualifier value!\n"
                "  Waited:\n"
                "     command -f infile outfile01 outfile02\n"
                "  Or:\n"
                "     command -n number outfile01 outfile02\n");
}

// 1 - file or random
// 2 - the file or size of container
// 3 - name file for output
// 4 - name file for max distance output
// Here are examples.
// abc_hw -n 15 out1.txt out2.txt
// abc_hw -f in5.txt out1.txt out2.txt

int main(int argc, char** argv)
{
    argc = 5;
    argv = new char*[5];
    argv[0] = "abc_hw";
    argv[1] = "-f";
    argv[2] = "in6.txt";
    argv[3] = "out1.txt";
    argv[4]  = "out2.txt";


    if(argc != 5) {
        errMessage1();
        return 1;
    }

    printf("%s", "Start\n");
    container c;
    FILE * file;
    if(!strcmp(argv[1], "-f")) {
        file = fopen(argv[2],"r");
        if(file){
            c.In(file);
            fclose(file);
        }else{
            printf("%s", "Failed to open input file.\n");
            return 2;
        }
    }
    else if(!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            printf("%s %d %s","incorrect number of transport = ", size, ". Set 0 < number <= 10000\n" );
            return 3;
        }
        c.InRnd(size);
    }
    else {
        errMessage2();
        return 4;
    }
    if(!c.Empty())
        if(file = fopen(argv[3],"w")){
            c.QuickSort();
            c.Out(file);
            fclose(file);
        }else{
            printf("%s", "Failed to open the output file:(\n");
            return 5;
        }

    if(file = fopen(argv[4],"w")){
        fprintf(file, "%s %f %s","Total max distance = ", c.MaxDistSum(), "\n");
        fclose(file);
    }else{
        printf("%s", "Failed to open the output file for total distance:(\n");
        return 6;
    }
    c.Clear();
    printf("%s", "Stop\n");
    return 0;
}
