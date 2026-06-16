#include <stdio.h>

unsigned revert(unsigned, unsigned, unsigned);

int main() {
	unsigned x = 67; 
	unsigned res = revert(x, 6, 3);
	printf("revert %d - %d\n", x, res);
	return 0; 
}

unsigned revert(unsigned x, unsigned p, unsigned n) {
	/* 
	so what we are trying to do here:
	it is known that xor with 1 gives inversion, while with 0 gives identity. 
	so we create an xor bit mask that is: from p down to p-n+1 equals 1, from p-n to 0 equals 0.
	e.g. if p is 6 (numeration from 0) and n is 3, the resulting mask will be: 
	111 0000
	654 3210
	*/
	return x ^ ((~0u << (p+1-n)) & ~(~0u <<p+1));  
}
