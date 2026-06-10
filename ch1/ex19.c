#include <stdio.h>

#define MAX_SIZE 10 

int main() {
	int c,i;
	char line[MAX_SIZE];
	// init line with dots 
	for (i=0;i<MAX_SIZE;i++)
		line[i] = '.';

	i = 0;
	while ((c = getchar()) != EOF && c != '\n' && i<MAX_SIZE-1) {
		line[MAX_SIZE-2-i] = c;
		++i; 	
	}
	line[MAX_SIZE-1] = '\0'; 

	printf("%s\n", line);

	return 0; 
}
