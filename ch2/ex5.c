#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char s1[] = "bruh"; //"hello, world";
char s2[] = "oleksii"; 

int  any(char [], char []);

int main() {
	int res = any(s1, s2);
	printf("s1: %s\n", s1); 
	printf("s2: %s\n", s2); 
	printf("s1 any s2 char loc: %d %c \n", res, s1[res]);
	return 0;
}

int any(char s1[], char s2[]) {
	char c;

	for (int i=0; s1[i] != '\0'; ++i) {
		c = s1[i];
		for (int j=0; s2[j] != '\0'; ++j) {
			if (c == s2[j])
				return i; 
		}
	}

	return -1; 
}

