#include <stdio.h>
#include <string.h>
#include <ctype.h>

int lengthFinder(char *s) {
	char *i = s;
	while (*i != '\0') ++i;
	return i - s;
}

/*
int compare(char s[], char n[]);
*/
int main(void) {
	char line[128];
	printf("Enter  palindrome:\n");
	fgets(line, sizeof line, stdin);
	if(lengthFinder(line) > sizeof line) {
	printf("Line too long, sorry.");
	return 1;
	}
	printf("Palindrome: %s\n", line);
	printf("Length: %d\n", lengthFinder(line));

	char newS[128];
	int newIndex = 0;
	int i = 0;
	while (line[i] != '\0') {
		if(isdigit(line[i]) || isalnum(line[i])) {
		newS[newIndex] = line[i];
		newIndex++;	
		}
	i++;
	}
	newS[newIndex] = '\0';
	int loweri = 0;
	char filt[128];
	while (newS[loweri] != '\0') {
	filt[loweri] = tolower(newS[loweri]);
	loweri++;
	}
	filt[loweri] = '\0';
	printf("Filter: %s\n", filt);
	
	int endind = lengthFinder(filt)-1;
	for(int begind = 0; begind != lengthFinder(filt) - 1; begind++) {
	if (filt[begind] != filt[endind]) {
	printf("Not a palindrome.\n");
	return 0;
	} else{
	endind--;
	}
}
	printf("This is a Palindrome.\n");


	// printf("%s\n", enil);	
	
	return 0;

}
