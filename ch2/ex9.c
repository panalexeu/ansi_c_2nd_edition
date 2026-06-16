// claude helped here: subtracting 1 flips every bit from the rightmost 1-bit down (that 1 becomes 0, the trailing 0s become 1s), so x & (x-1) clears the lowest set bit.

#include <stdio.h>

int bitcount(unsigned); 

int main() {
	unsigned num = 99;
	int res = bitcount(num);
	printf("%d bitcount %d\n", num, res);
	return 0; 
}

int bitcount(unsigned x) {
	int b; 

	for (b=0; x != 0; x &= (x-1)) 
		++b; 

	return b;
}


