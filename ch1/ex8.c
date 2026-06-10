#include <stdio.h>

main() {
	int c, nl, tb, bl; 
	
	c = 0; 
	nl = 0;
	tb = 0; 
	bl = 0; 
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++nl;
		if (c == '\t')
			++tb;
		if (c == ' ')
			++bl; 
	} 

	printf("nl: %d tb: %d bl: %d\n", nl, tb, bl);
} 
