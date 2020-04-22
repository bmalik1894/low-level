#include <stdio.h>

int main(void) {
	int a = 0, b = 0, c = 0, min = 0, mid = 0, max = 0;
	printf("Enter 3 numbers:\n");
	if (scanf("%d %d %d",&a,&b,&c) != 3) {
	printf("Error\n");
	return 1;
	}
if (a < b && a < c) {
	min = a;
	if (b < c) {
	mid = b;
	max = c;
	}
	else {
	mid = c;
	max = b;
	}
}
if (b < a && b < c) {
	min = b;
	if (a < c) {
	mid = a;
	max = c;
	}
	else {
	mid = c;
	max = a;
	}	
}
if (c < a && c < b) {
	min = c;
	if (a < b) {
	mid = a;
	max = b;
	}
	else {
	mid = b;
	max = a;
	}

}	
	printf("%d %d %d\n", min, mid, max);
	return 0;
}
