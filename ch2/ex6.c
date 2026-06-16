#include <stdio.h>

unsigned int getbits(unsigned int, int, int);  
unsigned int setbits(unsigned int, int, int, unsigned int);

int main() {
	unsigned int x, y, res;
	x = 67; 
	res = getbits(x , 6, 3); 
	printf("%d getbits %d \n", x, res);
	
	y = 255; 
	res = setbits(x, 6, 3, y);
	printf("%d setbits %d: %d \n", x, y, res); 
	return 0;
}

unsigned int getbits(unsigned int x, int p, int n) {
	return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {
	unsigned int right = y & ~(~0u << n); // get rightmost bits of y 
	right = right << p+1-n; // shit to position p
	return x | right; // set rightmost bits y at position p in x with or 
}
