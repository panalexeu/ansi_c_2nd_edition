#include <stdio.h>

main() {
	int c, flag;

	c = 0; 
	flag = 0; 
	while ((c = getchar()) != EOF) {
		if (c == ' ' && flag == 0) {
			flag = 1;
			putchar(c);
		}
		if (c == ' ' && flag == 1)
			;
		if (c != ' ') {
			flag = 0;
			putchar(c);
		}
	}
}
