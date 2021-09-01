#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define RANDOM  0b00000001U



void help(char* name) {
    printf("rand by Yoshua-chan\n\n");
    printf("USAGE: %s [options] [arguments]\n\n", name);
    printf("OPTIONS:\n");
    printf("  --help\tshow this message and exit\n");
    printf("  --version\tshow the program version and exit\n");
    printf("  -r\t\tset the number range (default is max int)\n");
    printf("  -s\t\tset the array size\n");
    printf("  -n\t\tseparate the numbers with newline character (space is the default separator)\n");
    exit(0);
}

void version(void) {
    printf("pfff, i dunno, i don't number my programs versions :)\n");
    exit(0);
}

char parse(int argc, char* argv[], int* size, int* range) { //returns seperator character and writes size and range to the variables

    char c = ' ';

    *size = 0;
    *range = INT_MAX;
    for(int i = 0; i < argc; i++) {


        if(argc >= 2) {
          if(!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h"))
              help(argv[0]);
          else if(!strcmp(argv[1], "--version") || !strcmp(argv[1], "-v"))
              version();
        } else {
          help(argv[0]);
        }


        if(!strcmp(argv[i], "-r") || !strcmp(argv[i], "--range"))
            *range = atoi(argv[i + 1]);

        if(!strcmp(argv[i], "-s") || !strcmp(argv[i], "--size"))
            *size = atoi(argv[i + 1]);

        if(!strcmp(argv[i], "-n") || !strcmp(argv[i], "--newline"))
            c = '\n';

    }
    if(*size == 0)
        printf("error: you need to specify the size");
    

    return c;
}

int* generate(int number, int range, unsigned int FLAGS) {
    time_t now;
    srand((unsigned) time(&now));

    int* arr = malloc(number * sizeof(int));

    for(int i = 0; i < number; i++)
        arr[i] = rand() % range;

    return arr;
}

void printArray(int* arr, int size, char c) {
    for(int i = 0; i < size; i++)
        printf("%d%c", arr[i], c);
}

int main(int argc, char* argv[]) {
    int FLAGS = 0U;
    //int arr[5] = {2, 1, 3, 7, 9};
    int* arr;
    int number, range;
    char separator;


    separator = parse(argc, argv, &number, &range);
    arr = generate(number, range, RANDOM | FLAGS);

    printArray(arr, number, separator);
    
}
