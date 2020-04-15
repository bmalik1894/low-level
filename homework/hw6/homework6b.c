/*
 * Program to test sort function: 
 * Generate a random sequence of N integers, sort them, and check
 * that the sort succeeded.  
 * This version prompts for N and a seed for generating the random
 * sequence but hardcodes a maximum for N.  Also, the sort function 
 * doesn't do anything, so will almost surely fail!
 */
#include <stdio.h>
#include <stdlib.h> /* has EXIT_SUCCESS, EXIT_FAILURE */
#include <string.h>
#include <ctype.h>

#define MAX_COUNT 100

/* function declarations -- see definitions (at end) for more comments */
void fill_with_random(int a[], int size);
void sort(int a[], int size);
void print(int a[], int size);
int find_out_of_order(int a[], int size);

/* main program */
int main(int argc, char * argv[]) {

	int data[MAX_COUNT];
	int count = 0;
	FILE * fpi = fopen(argv[1],"r");
	FILE * fpo = fopen(argv[2],"w");
	int temp;

	// argument line error checking
	if (argc < 3 || argc > 3) {
    	printf("Not the correct amount of arguments.");
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

	// reading in inputs
	while (fscanf(fpi,"%d", &temp) == 1) {	
    	data[count] = temp;
		count ++;
	}

	// input overflow error catching
	if (count > 99) {
		printf("Too many input values!");
		return -1;
	}
	

	// sort the actual data
	sort(data,count);

	/* uncomment if you want to print */
	// print(data, count, fpoint2) */
	int out_of_order = find_out_of_order(data, count);
	if (out_of_order < 0) {
		printf("sorted\n");
	}
	else {
		printf("not sorted\n");
		printf("first out-of-order element at index %d\n", out_of_order);
	}
	

 
	// outputting to file
	for(int i = 0; i < count; i++) {
		fprintf(fpo,"%d\n", data[i]);
	}

	// tying up loose ends
    fclose(fpi);
	fclose(fpo);
	return EXIT_SUCCESS;
}



/* 
 * check whether array is sorted:
 * returns index of first out-of-order element, or -1 if all are in order
 */
int find_out_of_order(int a[], int size) {
	for (int i = 0; i < size-1; ++i) {
		if (a[i] > a[i+1]) { 
			return i;
		}
	}
	return -1;
}

/* sort array */
void sort(int a[], int size) {
	    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1 - i; j++) {
            if(a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                }
        }
    }
}