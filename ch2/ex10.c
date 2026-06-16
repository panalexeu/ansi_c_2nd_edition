#include <stdio.h>

void lower(char []); 

int main() {
	char s[] = "HELLO, WORLD";
	printf("%s\n", s);
	lower(s); 
	printf("%s\n", s);
}

void lower(char s[]) {
	for (int i=0; s[i] != '\0'; ++i) 
		s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + 'a' - 'A' : s[i];
} 
