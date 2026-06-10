#include <stdio.h>

#define OFFSET 33
#define ASCII_SIZE 128  

main() {
	int c, i, j, chars[ASCII_SIZE]; 

	for (i=0;i<ASCII_SIZE;++i)
		chars[i] = 0; 

	while ((c = getchar()) != EOF) {
		if (c >= OFFSET && c < ASCII_SIZE)
			++chars[c]; 
	} 

	for (i=OFFSET;i<ASCII_SIZE;++i) {
		putchar(i);
		putchar(' ');
		for (j=0;j<chars[i];++j) {
			putchar('#'); 
		}
		if (chars[i] == 0)
			putchar('.'); 
		putchar('\n'); 

	} 

}
