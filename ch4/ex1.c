#include <stdio.h> 

#define MAXLINE 1000

int getline_(char [], int);
int strindex(char [], char []); 

char pattern[] = "ould"; 

int main() {
	char line[MAXLINE];
	int idx, found = 0;
	
	while (getline_(line, MAXLINE) > 0) {
		if ((idx = strindex(line, pattern)) >= 0) {
			printf("%s %d\n", line, idx); 
			found++; 
		}
	}

	return found; 
}

int getline_(char s[], int lim) {
	int c, i = 0; 
	while (--lim > 0 && ((c = getchar()) != EOF && c != '\n'))
		s[i++] = c; 
	s[i] = '\0'; 
	return i; 
}

int strindex(char s[], char t[]) {
	int i,j,k;
	int ridx = -1; 

	for (i=0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++) ; 
		if (k > 0 && t[k] == '\0') ridx = i;
	}
	return ridx;
}
