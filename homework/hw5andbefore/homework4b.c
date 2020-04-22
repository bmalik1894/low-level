#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
	// declare variables
	int seed, samp, bin;
	
	// grab & define input variables
	printf("seed: \n");
	if (scanf("%d", &seed) != 1) {
	printf("error\n");
	return 1;
	}
	printf("sample: \n");
	if (scanf("%d", &samp) != 1) {
	printf("error\n");
	return 1;
	}
	printf("bins: \n");
	if (scanf("%d", &bin) != 1) {
	printf("error\n");
	return 1;
	}
	
	srand(seed);	
	// initialize arrays
	int remainder[bin], quotient[bin];
	for(int reminit = 0; reminit < bin; reminit++) {remainder[reminit] = 0;}
	for(int quoinit = 0; quoinit < bin; quoinit++) {quotient[quoinit] = 0;}

	for(int i = 0; i < samp; i++) {
	int n = rand();
	// query and add to remainder bins
	remainder[n % bin] = remainder[n % bin] + 1;
	// query and add to quotient bins
	int tmp =  (n*bin)/RAND_MAX;
	int tmp2 = n/(RAND_MAX/bin);
	quotient[tmp2] = quotient[tmp2] + 1;
	}
	
	// display REMAINDER
	printf("Remainder Method:\n");
	for(int p = 0; p < bin; p++){
	printf("%d\n", remainder[p]);
	}
	// display QUOTIENT
	printf("Quotient Method:\n");
	for(int q = 0; q < bin; q++){
	printf("%d\n", quotient[q]);
	}
	return 0;
}
