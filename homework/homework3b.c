#include <stdio.h>

int gcd(int a, int b);

int main(void) {

	int a, b;
	printf("Please enter 2 numbers\n");
	if (scanf("%d %d", &a, &b) != 2) {
	printf("Error\n");
	return 1;
	}
	if (a <= 0 || b <= 0 || b > a) {
	printf("Error\n");
	return 1;
	}
	printf("%d\n", gcd(a,b));
	return 0;
}

int gcd(int f, int s) {
	if (s == 0) return f;
	else gcd(s, f%s);


}
