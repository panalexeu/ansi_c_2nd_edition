#include <stdio.h>

unsigned rightrot(unsigned, unsigned);
int bit_size(unsigned); 


int main() {
	unsigned x = 74; 
	unsigned res = rightrot(x, 4);
	printf("rightrot %d - %d\n", x, res);
	return 0; 
}

int bit_size(unsigned x) {
	int n=0; 
	while (x > 0) { 
		x >>= 1; 
		++n; 
	}
	return n; 
}

unsigned rightrot(unsigned x, unsigned n) {
	int tmp, res = x;
	int bits = bit_size(x); 

	for (int i = 0; i<n; ++i) {
		tmp = res;
		res >>= 1;
		res = res | ((tmp << bits-1) & ~(~0u << bits));
	}

	return res;
}

