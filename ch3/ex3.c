#include <stdio.h>

#define LIMIT 1000 

void read_line(char []); 
void expand(char [], char []);

int main() {
	char s1[LIMIT];
	char s2[LIMIT];
	read_line(s1); 
	printf("%s", s1);
	expand(s1, s2); 
	printf("%s", s2); 
	return 0; 
}

void read_line(char s[]) {
	int c, i;
	i = 0; 
	while ((c = getchar()) != EOF && i < LIMIT - 1)
		s[i++] = c; 
	s[i] = '\0'; 
}

void expand(char s1[], char s2[]) {
	char l,r,c;
	int j = 0;

	for (int i=0; s1[i] != '\0'; ++i) {
		if (s1[i] == '-' && i > 0) {
			l = s1[i-1], r = s1[i+1], c = l+1; 
			if (l < r-1)
				for (; j < LIMIT-1 && c < r; c++, j++) s2[j] = c;		
			else 
				s2[j++] = s1[i]; 
		} else {
			s2[j++] = s1[i]; 
		}
	} 	
	s2[j] = '\0';
}
