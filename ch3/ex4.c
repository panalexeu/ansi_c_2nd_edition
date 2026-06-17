#include <stdio.h>
#include <string.h>

void itoa(int, char []);
void reverse(char s[]);

int main() {
	char s[512]; 
	int num = -2147483648; // largest negative num for int 32bit 	
	itoa(num, s);
	printf("%s\n", s);
	return 0; 
}

void itoa(int n, char s[]) {
	int i, sign, num; 
	long nl;
	// when flip here is done overflow happens: largest negative number is 1.000 while positive 0.1111
	// solution: store flipped value in long; if n is int based on function declaration from the book, should work 
	if ((sign = n) < 0) 
		nl = n;
		nl = -nl;
	i = 0; 
	do {
		s[i++] = nl % 10 + '0';
	} while ((nl /= 10) > 0);
	
	if (sign < 0) s[i++] = '-'; 
	
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) {
	int c,i,j; 
	for (i=0, j=strlen(s)-1; i<j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c; 
}
