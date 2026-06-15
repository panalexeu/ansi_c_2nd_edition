#include <stdio.h>

int main() {
	int c; 
	int lim = 1000;
	for (int i=0; i<lim-1; ++i) {
		c = getchar();
		if (c == '\n')
			break; 
		else if (c == EOF)
			break; 
		else 
			putchar(c);
	} 

} 
