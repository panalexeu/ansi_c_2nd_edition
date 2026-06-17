#include <stdio.h>

#define LIMIT 1000

void escape(char s[]);
void unescape(char s[]);

int main() {
	char s[LIMIT];
	
	escape(s);
	//unescape(s);
	printf("\n%s\n", s);
		
	return 0; 
}

void escape(char s[]) {
	int c, j; 
	c = j = 0;
	while ((c = getchar()) != EOF && j<LIMIT-1) {
		switch (c) {
			case '\n': 
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t': 
				s[j++] = '\\'; 
				s[j++] = 't';
				break; 
			default:
				s[j++] = c;
				break;
		}
	}

	s[j] = '\0';
}

void unescape(char s[]) {
	int c, c_temp, j; 
	c = c_temp = j = 0;
	while ((c = getchar()) != EOF && j<LIMIT-1) {
		switch (c_temp) {
			case '\\':
				switch(c) {
					case 'n': s[j-1] = '\n'; break;
					case 't': s[j-1] = '\t'; break;
					default: s[j++] = c; break; 
				}
				break;
			default: s[j++] = c; break; 
		}
		c_temp = c;
	}
	s[j] = '\0';
}
