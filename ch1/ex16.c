#include <stdio.h>

#define MAXLINE 10 

int getline_(char[], int);
void copy(char[], char[]);

main() {
	int len; 
	int max; 
	char line[MAXLINE]; 
	char longest[MAXLINE]; 

	max = 0; 
	while ((len = getline_(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len; 
			copy(longest, line); 
		} 
	}
	if (max > 0) { 
		printf("%s \n", longest);
		printf("actual size: %d \n", max);
	} 

	return 0;
}

int getline_(char s[], int lim) {
	int c,i;
	
	i = 0; 
	while ((c = getchar()) != EOF && c != '\n') {
		if (i < lim-1)
			s[i] = c; 
		++i; 
	}		
	if (c == '\n' && i < lim-1) {
		s[i] = c;
		++i; 
	}
	s[lim-1] = '\0'; 
	
	return i; 
}

void copy(char to[], char from[]) {
	int i; 

	i = 0; 
	while ((to[i] = from[i]) != '\0')
		++i; 
} 
