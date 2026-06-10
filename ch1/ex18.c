#include <stdio.h>

#define MAXLINE 100 

int getline_(char[], int);
int check_blank(char[], int); 


main() {
	char line[MAXLINE]; 

	while (getline_(line, MAXLINE)) {
		printf("%s", line);
	}

	return 0;
}

int getline_(char s[], int lim) {
	int c,i,trunc;
	
	i = 0; 
	while ((c = getchar()) != EOF && c != '\n' && i<lim-1) {
		s[i] = c; 
		++i; 
	}		
	if (c == '\n') 
		s[i] = c;
	trunc = check_blank(s, lim);
	s[trunc] = '\0';

	return i; 
}

int check_blank(char s[], int lim) {
	int i;
	int blank_count = 0; 

	for (i=0;i<lim;++i) {
		if (s[i] == ' ' || s[i] == '\t') 
			++blank_count; 
		else
			blank_count = 0; 
	}
	
	if (blank_count > 0)  
		return lim - blank_count; 
	else 
		return lim - 1; 
} 
