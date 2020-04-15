#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char * argv[]) {
    char * end;
    int key = strtol(argv[1], &end, 10); // This could fail if argv[1] isn't a number
    char off = key % 26;
    int size = 100;                      // This does not work for passwords over 
    char answer[size];
    FILE * fpi = fopen(argv[2], "r");
    FILE * fpo = fopen(argv[3], "w");

    if (argc < 4 || argc > 4) {
        printf("Not the correct amount of arguments.");
        return -1;
    }

    /*
    if (key != 1) {
        printf("Enter an integer:");
        return -1;
    } */

    if (key < 0) {
        printf("Enter a valid ingeter:\n");
        return -1;
    }

    if(fpi == NULL) {
        printf("Input file not found.\n");
        return -1;
    }

    if(fpo == NULL) {
        printf("Output file not found.\n");
        return -1;
    }



    int index = 0;
    // encryption of FP input to a middle-array
    while (!feof(fpi)) {
        char c = fgetc(fpi);
        char cc = c;
        if(islower(c)) {
        cc = c + off;
        if (cc > 'z') cc -= 26;
        }   

        if(isupper(c)) {
        cc = c + off;
        if (cc > 'z') cc -= 26;
        }

        answer[index] = cc;
        index ++;
    }
    answer[index - 1] = '\0';

    // loading characters from array into FP output
    // this is done because fgetc put everything in backwards
    // ACTUALLY IGNORE THIS PART
    // while (answer[index2] != '\0') {
    //     char d = answer[index2];
    //     fprintf(fpo,"%s", );
    //     index2 ++;
    // }
    fprintf(fpo,"%s",answer); 
    fclose(fpi);
    fclose(fpo);
    return 0;
}