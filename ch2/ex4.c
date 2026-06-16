#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char s1[] = "hello, world";
char s2[] = "oleksii"; 

void squeeze(char [], char []);

int main() {
	squeeze(s1, s2);
	return 0;
}

void squeeze(char s1[], char s2[]) {
	int k=0;
	char c;
	char buffer[strlen(s1)+1]; //+1 for \0 char
	bool match = false; 

	for (int i=0; s1[i] != '\0'; ++i) {
		c = s1[i];
		for (int j=0; s2[j] != '\0'; ++j) {
			if (c == s2[j])
				match = true; 
		}

		if (!match)
			buffer[k++] = c; 

		match = false; 
	}
		
	buffer[k] = '\0';

	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("res: %s\n", buffer);
}

