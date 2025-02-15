#include <stdlib.h>
#include <stdio.h>
#include <string.h>
    
#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL || fseek(file, 0, SEEK_END) != 0) {
        fprintf(stderr, "could not find file");
        fclose(file);
        return -1;
    }

    int size = ftell(file);
    if (size == -1) {
        fclose(file);
        return -1;
    }

    fclose(file);
    printf("\t%d\n", size);
    return 0;
}