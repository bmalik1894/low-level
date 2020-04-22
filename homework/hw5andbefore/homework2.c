#include <stdio.h>
int main(void) {
	int start, sec, min, hour, day, year;
	printf("Please enter a time in seconds:\n");
	scanf("%d", &start);
	sec = start % 60;
	min = (start / 60) % 60;
	hour = (start / 3600) % 24;
	day = (start / (3600 * 24)) % 365;
	year = start / (3600 * 24 * 365);
	printf("%d seconds, %d minutes, %d hours, %d days, %d years.\n", sec, min, hour, day, year);
	return 0;
}
