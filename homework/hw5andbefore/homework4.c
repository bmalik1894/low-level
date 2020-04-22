#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*double newtroot(int x, double thresh, int n) {
	double r = (x+2/x)/2;
	int iteration = 1;
	double xrt = sqrt(x);
	while (iteration < n && abs(r - xrt) > thresh) {
	iteration++;
	r = (r+2/r)/2;
	}

	return r;
}*/

int main(void) {
	
	double thresh, compare;
	int x, n;
	printf("Please enter input, threshold, and maximum iteration:\n");
	if (scanf("%d %lf %d", &x, &thresh, &n) != 3 || x < 1) {
	printf("error");
	return 1;
	}
	
	double r = (x+2/x)/2;
	int iteration = 1;
	double xrt = sqrt(x);
	if(xrt < r) { compare = r - xrt;}
	if(xrt > r) { compare = xrt - r;}
	while (iteration < n && compare > thresh) {
	iteration++;
	r = (r + 2/r) / 2;
	if(xrt < r) { compare = r - xrt;}
	if(xrt > r) { compare = xrt - r;}
	}
	
	printf("Newtonian value: %lf\n", r);
	printf("Number of iterations: %d\n", iteration);
	printf("real sqrt value: %f\n", xrt); 
	return 0;
}
