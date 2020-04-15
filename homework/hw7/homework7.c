#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SQUARE(x) ((x) * (x))
void strBubbleSort(char ** a, int size);

int main(int argc, char * argv[]) {
    FILE * fpiIndex = fopen(argv[1], "r");
    FILE * fpo = fopen(argv[2], "w");
    int index = 0;
    int ncount = 0;

    // Error Catching
    if (argc < 3 || argc > 3) {
        printf("Not the correct amount of arguments.\n");
        return 1;
    }

    if(fpiIndex == NULL) {
        printf("Input file not found.\n");
        return 1;
    }

    if(fpo == NULL) {
        printf("Output file not found.\n");
        return 1;
    }

    // First iteration of Input file for index and find amount of lines
    while(!feof(fpiIndex)) {
        if (fgetc(fpiIndex) == '\n') ncount++; 
        index++;
    }
    ncount++; // account for first line

    fclose(fpiIndex);
    
    // check and apply index
    char * data = malloc(index * sizeof(data[0]));
    if(data == NULL || index < 1) {
        printf("Cannot allocate memory.\n");
        return 1;
    }

    // Second iteration to store data
    int index2 = 0;
    FILE * fpi = fopen(argv[1], "r");
    while(!feof(fpi)) {
        char c = fgetc(fpi);
        data[index2] = c;
        index2++;
    }
    fclose(fpi);

    // fix end character
    data[index2 - 1] = '\0';


    // Create mempory for storage of lines in string pointer to data
    char ** lines = malloc(sizeof(lines[0]) * ncount);
    int line = 0;
    lines[line] = &data[0];
    line++;
    for (int i = 0; i < index2-1; i++) {
        if (data[i] == '\n') {
        lines[line] = &data[i+1];
        data[i] = '\0';
        if (line < ncount) line++;
        }
    }
    line--; // fixing like iteration for line text

    // This just helps me for my own comprehension
    printf("\n\\n count = %d\n",ncount - 1);
    printf("Number of lines (including 0) in 'lines' = %d\n",line);
    printf("First line = %s\n", lines[0]);
    printf("Last line = %s\n\n", lines[line]);

    // Sort and write array to output file
    strBubbleSort(lines,ncount);
    for(int i = 0; i < ncount; i++) if (i < ncount-1) fprintf(fpo,"%s\n",lines[i]); else fprintf(fpo,"%s",lines[i]);
    
    // For continuity - and to check that it works without opening the output file
    printf("New first line = %s\n", lines[0]);
    printf("New last line = %s\n\n", lines[line]);

    free(data);
    free(lines);
    fclose(fpo);
    return 0;
}

void strBubbleSort(char ** a, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1 - i; j++) {
            if(strcmp(a[j],a[j+1]) > 0) {
                char * tmp;
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                }
        }
    }
    
}